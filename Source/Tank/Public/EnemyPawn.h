// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.h"
#include "EnemyPawn.generated.h"

UCLASS()
class TANK_API AEnemyPawn : public APawnBase
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	
	UPROPERTY(EditAnywhere, Category="Properties")
	float MaxDistance = 1000;
	
	UPROPERTY(EditAnywhere, Category="Properties")
	float FireRate = 2;
	float FireTimer = 0;
	
	AActor* PlayerPawn = nullptr;
};
