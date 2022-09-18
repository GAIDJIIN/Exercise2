// FNtastic Turtle

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class UCameraComponent;
UCLASS()
class EXERCISE2_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();

protected:
	virtual void BeginPlay() override;
	// Variables
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "CameraComponent")
		UCameraComponent* Camera;
public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Functions for Axis
	void MoveFB(float axis);
	void MoveLR(float axis);

	// Action Logic
	void TryInteract();
};
