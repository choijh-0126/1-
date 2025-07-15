// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocation(FVector::ZeroVector);
	const FVector CurrentLocation = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("Start Location: %.2f, %.2f"), CurrentLocation.X, CurrentLocation.Y);
}

void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);
	MoveTimer += DeltaTime;
	if (MoveTimer >= 0.0167f)
	{
		UE_LOG(LogTemp, Warning, TEXT("MoveTimer: %f"), MoveTimer);
		Move();	
		MoveTimer = 0.f;
	}
}

double AMyActor2::Step() const
{
	return FMath::RandBool() ? 1.0 : 0.0;
}

void AMyActor2::Move()
{
	FVector PreviousLocation = GetActorLocation();
	AddActorLocalOffset(FVector(Step(), Step(), 0));
	const FVector CurrentLocation = GetActorLocation();

	double StepDistance = FVector::Dist2D(PreviousLocation, CurrentLocation);
	UE_LOG(LogTemp, Warning, TEXT("Step Distance: %f"), StepDistance);
	TotalDistance += StepDistance;

	if (CreateEvent(50))
		++TotalEvent;

	++MoveCount;
	if (MoveCount >= 10)
	{
		UE_LOG(LogTemp, Warning, TEXT("--------------------------------"));
		UE_LOG(LogTemp, Warning, TEXT("Total Distance: %f"), TotalDistance);
		UE_LOG(LogTemp, Warning, TEXT("Total Event: %d"), TotalEvent);

		MoveCount = 0;
		TotalDistance = 0;
		TotalEvent = 0;

		UE_LOG(LogTemp, Warning, TEXT("--------------------------------"));

	}
}

bool AMyActor2::CreateEvent(int32 Probaility) const
{
	if (FMath::RandRange(0, 100) <= Probaility)
	{
		UE_LOG(LogTemp, Warning, TEXT("Event Triggered!"));
		return true;
	}

	UE_LOG(LogTemp, Warning, TEXT("Event Not Triggered!"));
	return false;
}