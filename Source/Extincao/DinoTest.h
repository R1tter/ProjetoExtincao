// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DinoTest.generated.h"

UCLASS()
class EXTINCAO_API ADinoTest : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADinoTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private: 

	UPROPERTY(EditAnywhere, Category = "Mesh")
		class UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Direction")
		class UArrowComponent* DirectionArrow;

	UPROPERTY(EditAnywhere, Category = "Camera")
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Camera")
		class USpringArmComponent* CameraBoom;

	
	

	void Dash();
	void Walk(float Value);
};
