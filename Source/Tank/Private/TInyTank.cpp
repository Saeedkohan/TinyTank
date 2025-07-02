// Fill out your copyright notice in the Description page of Project Settings.


#include "TInyTank.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATInyTank::ATInyTank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BodyMesh);


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
}

// Called when the game starts or when spawned
void ATInyTank::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATInyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UWorld* World = GetWorld();
	APlayerController* PlayerController = World->GetFirstPlayerController();
	PlayerController->bShowMouseCursor = true;

	FHitResult HitResult;
	PlayerController->GetHitResultUnderCursor(ECC_Visibility, true, HitResult);
	FVector MouseLocation = HitResult.ImpactPoint;

	LookAtTarget(MouseLocation);
}

// Called to bind functionality to input
void ATInyTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ATInyTank::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATInyTank::MoveRight);
	PlayerInputComponent->BindAxis("TurnRight", this, &ATInyTank::TurnRight);
	
	PlayerInputComponent->BindAction("Fire", IE_Pressed,this, &ATInyTank::Fire);
	
}	

void ATInyTank::MoveForward(float Value)
{
	this->AddMovementInput(GetActorForwardVector(), Value);
}

void ATInyTank::MoveRight(float Value)
{
	// this->AddMovementInput(GetActorRightVector(), Value);
	BodyMesh->AddRelativeRotation(FRotator(0, Value * BodyRotationSpeed * GetWorld()->GetDeltaSeconds(), 0));
}

void ATInyTank::TurnRight(float Value)
{
	// this->AddControllerYawInput(Value);
	TurretMesh->AddRelativeRotation(FRotator(0, Value * TurretRotationSpeed * GetWorld()->GetDeltaSeconds(), 0));
}

