// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionArea.h"

#include "InteractionSystem/Interaction_CPP/InteractionInterfaces/Interactable.h"


// Sets default values
AInteractionArea::AInteractionArea()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	
	boundingCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoundingCollisionBox"));
	
	
}

// Called when the game starts or when spawned
void AInteractionArea::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractionArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractionArea::ToggleFocus(bool bfocused)
{
	AInteractionArea::focused = bfocused;
	IInteractable::Execute_ToggleFocus(GetParentActor(), bfocused);
}

