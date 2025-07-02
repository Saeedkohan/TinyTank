// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

UCLASS()
class TANK_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void LookAtTarget(FVector TargetLocation);
	void Fire();


	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent* BodyMesh;
	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent* BarrelMesh;

	UPROPERTY(EditAnywhere, Category="Properties")
	float TurretRotationSpeed = 2;

	UPROPERTY(EditAnywhere, Category="Properties")
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category="Properties")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category="Properties")
	class UHealthComponent* HealthComponent;


};
