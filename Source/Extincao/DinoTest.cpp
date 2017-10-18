// Fill out your copyright notice in the Description page of Project Settings.

#include "DinoTest.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"



// Sets default values
ADinoTest::ADinoTest()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>
		(TEXT("MeshComp"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> LoadMesh(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	if (LoadMesh.Succeeded()) {
		MeshComp->SetStaticMesh(LoadMesh.Object);
	}
	MeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	MeshComp->SetRelativeScale3D(FVector(1.5f, 1.0f, 1.75f));
	MeshComp->SetupAttachment(RootComponent);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>
		(TEXT("CameraBoom"));
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->SetWorldRotation(FRotator(0.0f, -90.0f,0.0f));
	CameraBoom->SetupAttachment(RootComponent);


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 2048.0f;
	Camera->SetupAttachment(CameraBoom);

	DirectionArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("DirectionArrow"));
	DirectionArrow->SetupAttachment(RootComponent);
	DirectionArrow->SetHiddenInGame(false);

	this->JumpMaxCount = 2;

	GetCharacterMovement()->AirControl = 1.0f;

	AutoPossessPlayer = EAutoReceiveInput::Player0;



}

// Called when the game starts or when spawned
void ADinoTest::BeginPlay()
{
	Super::BeginPlay();



}

// Called every frame
void ADinoTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADinoTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Walk", this, &ADinoTest::Walk);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ADinoTest::Jump);


}

void ADinoTest::Dash()
{

}

void ADinoTest::Walk(float Value) {


	if (Value > 0) {
		RootComponent->SetWorldRotation(FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (Value < 0) {
		RootComponent->SetWorldRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);

}