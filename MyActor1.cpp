// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"

// Sets default values
AMyActor1::AMyActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	start = FVector2D(0, 0);
}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Actor Spawned at Start Location (0, 0)"));

	move();
}

// Called every frame
void AMyActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AMyActor1::step()
{
    return UKismetMathLibrary::RandomIntegerInRange(0, 1);
}

void AMyActor1::move()
{
    for (int32 i = 0; i < 10; ++i)
    {
        int32 dx = step();
        int32 dy = step();

       
        if (FMath::Abs(dx) >= 2 || FMath::Abs(dy) >= 2)
        {
            continue;
        }

        start.X += dx;
        start.Y += dy;

        UE_LOG(LogTemp, Warning, TEXT("Moved to: (%f, %f)"), start.X, start.Y);
    }
}