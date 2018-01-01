// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemsGrabber.h"
#include "GameFramework/Actor.h"

#define OUT


// Sets default values for this component's properties
UItemsGrabber::UItemsGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UItemsGrabber::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Grabber loaded"));
}


// Called every frame
void UItemsGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player view point this tick
	
	FVector PlayerViewpointLocation;
	FRotator PlayerViewpointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewpointLocation, OUT PlayerViewpointRotation);

	/*UE_LOG(LogTemp, Warning, TEXT("ViewpointLocation: %s, PlayerViewpointRotation: %s"), 
		*PlayerViewpointLocation.ToString(), 
		*PlayerViewpointRotation.ToString()
	);*/

	FVector LineTraceEnd = PlayerViewpointLocation + (PlayerViewpointRotation.Vector() * Reach);
	
	const FColor LineTraceColor = FColor(255, 0, 0, 255);
	DrawDebugLine(GetWorld(), PlayerViewpointLocation, LineTraceEnd, LineTraceColor, false, 0.0f, 0, 5.0f);
}

