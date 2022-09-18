// FNtastic Turtle

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "InteractItem.generated.h"

UCLASS()
class EXERCISE2_API AInteractItem : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	AInteractItem();

protected:
	virtual void BeginPlay() override;
	virtual void Interact() override;
	UFUNCTION(BlueprintImplementableEvent, Category="Interact Logic")
		void InteractLogic();
public:	

};
