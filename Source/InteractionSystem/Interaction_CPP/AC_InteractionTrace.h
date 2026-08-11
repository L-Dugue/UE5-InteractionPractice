// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionArea/InteractionArea.h"
#include "AC_InteractionTrace.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INTERACTIONSYSTEM_API UAC_InteractionTrace : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAC_InteractionTrace();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	AActor* focusedActor;
	bool isTracingInteractionArea;
	AInteractionArea* focusedInteractionArea;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
public:
	void Trace();
	void TraceInteractionArea(bool trace);
	UFUNCTION(BlueprintCallable) void TryToInteract(bool interacted);
	UFUNCTION(Server, Reliable) void InteractOnServer(AInteractionArea*  interactionArea);
	
private:
	float _interactionDuration;
};
