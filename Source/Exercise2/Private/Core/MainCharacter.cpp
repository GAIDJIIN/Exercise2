// FNtastic Turtle


#include "Core/MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "InteractInterface.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	Camera->bUsePawnControlRotation = true;
	Camera->SetupAttachment(GetRootComponent());
}


void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FindInteractableActor();
}


void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Actions
	PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&AMainCharacter::Jump);
	PlayerInputComponent->BindAction("Jump",IE_Released,this,&AMainCharacter::StopJumping);
	PlayerInputComponent->BindAction("Interact",IE_Pressed,this,&AMainCharacter::TryInteract);
	// Axis
	PlayerInputComponent->BindAxis("MoveFB",this,&AMainCharacter::MoveFB);
	PlayerInputComponent->BindAxis("MoveLR",this,&AMainCharacter::MoveLR);
	PlayerInputComponent->BindAxis("LookUD",this,&AMainCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookAround",this,&AMainCharacter::AddControllerYawInput);
}


// Axis Logic
void AMainCharacter::MoveFB(float axis)
{
	if(axis == 0.0f) return;
	AddMovementInput(GetActorForwardVector(),axis);
}

void AMainCharacter::MoveLR(float axis)
{
	if(axis == 0.0f) return;
	AddMovementInput(GetActorRightVector(),axis);
}

// Interact Logic
void AMainCharacter::FindInteractableActor()
{
	if(!GetWorld()) return;
	FVector StartTrace;
	FRotator ViewRotation;
	GetActorEyesViewPoint(StartTrace,ViewRotation);
	const FVector EndTrace = StartTrace + ViewRotation.Vector()*150.0f;
	FHitResult LocalHitResult;
	GetWorld()->LineTraceSingleByChannel(LocalHitResult,StartTrace,EndTrace,ECC_Visibility);
	if(LocalHitResult.bBlockingHit && LocalHitResult.GetActor())
	{
		const auto LocalInterface = Cast<IInteractInterface>(LocalHitResult.GetActor());
		InteractableActor = LocalInterface ? LocalInterface : nullptr;
	}
	else{ InteractableActor = nullptr;}
}

void AMainCharacter::TryInteract()
{
	if(!InteractableActor) return;
	InteractableActor->Interact();
}

