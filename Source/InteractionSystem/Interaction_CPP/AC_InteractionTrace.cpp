// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_InteractionTrace.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UAC_InteractionTrace::UAC_InteractionTrace()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.03;
	
}


// Called when the game starts
void UAC_InteractionTrace::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UAC_InteractionTrace::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Trace();
	// ...
}

void UAC_InteractionTrace::Trace()
{
	// Declaring and Initializing vars
	FVector startPos = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetCameraLocation();
	FVector endPos = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetCameraRotation().Vector();
	FCollisionQueryParams TraceParams(FName(TEXT("")), true, GetOwner());
	
	// HitResults
	FHitResult hitResult;
	
	// Calculations needed for endPos
	endPos = (endPos * 500) + startPos;
	
	
	DrawDebugLine(GetWorld(), startPos, endPos, FColor::Red, false, 1.0f, 0, 0.5);
	
	// Collision Logic
	if (GetWorld()->LineTraceSingleByChannel(hitResult, startPos, endPos, ECC_Visibility, TraceParams))
	{
		// Check if we are hitting the same actor that we did previously
		
		if (focusedActor != hitResult.GetActor())
		{
			focusedActor = hitResult.GetActor();
			TraceInteractionArea(focusedActor->IsA(AInteractionArea::StaticClass()));
		}
	}
}

void UAC_InteractionTrace::TraceInteractionArea(bool trace)
{
	if (trace)
	{
		
		if (isTracingInteractionArea)
		{
			focusedInteractionArea->ToggleFocus(false);
		}
		else
		{
			focusedInteractionArea = Cast<AInteractionArea>(focusedActor);
			if (focusedInteractionArea != nullptr)
			{
				focusedInteractionArea->ToggleFocus(true);
				isTracingInteractionArea = true;
			}
		}
	}
	else
	{
		if (isTracingInteractionArea)
		{
			isTracingInteractionArea = false;
			focusedInteractionArea->ToggleFocus(false);
			focusedActor = nullptr;
			focusedInteractionArea = nullptr;
		}
	}
}

