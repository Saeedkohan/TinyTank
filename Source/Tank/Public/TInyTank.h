// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "GameFramework/Pawn.h"
#include "TInyTank.generated.h"

UCLASS()
class TANK_API ATInyTank : public APawnBase
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATInyTank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnRight(float Value);
	void TurnUp(float Value);


	UPROPERTY(EditAnywhere, Category="Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, Category="Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category="Components")
	class UFloatingPawnMovement* PawnMovement;
	UPROPERTY(EditAnywhere, Category="Properties")
	float BodyRotationSpeed = 60;

};
