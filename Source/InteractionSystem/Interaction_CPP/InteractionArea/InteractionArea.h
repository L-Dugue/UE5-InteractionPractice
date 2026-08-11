// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "InteractionArea.generated.h"

UCLASS()
class INTERACTIONSYSTEM_API AInteractionArea : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractionArea();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere) UBoxComponent* boundingCollisionBox;
	bool focused;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void ToggleFocus(bool focused);
};
