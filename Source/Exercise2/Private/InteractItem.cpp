// FNtastic Turtle


#include "InteractItem.h"


AInteractItem::AInteractItem()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AInteractItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInteractItem::Interact()
{
	InteractLogic();
}

