// Fill out your copyright notice in the Description page of Project Settings.


#include "CActor.h"

// Sets default values
ACActor::ACActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACActor::BeginPlay()
{
	Super::BeginPlay();

	originalLocation = GetActorLocation();
	Move();
}

// Called every frame
void ACActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACActor::Move()
{
	int eventNumber = 0;
	FVector moveVec;
	for (int i = 0; i < 10; i++)
	{
		FVector move = FVector(Step(), Step(), 0);
		moveVec += move;
		SetActorLocation(originalLocation + moveVec);
		Log("Move to " + moveVec.ToString());
		Log("Distance between original location is " + FString::SanitizeFloat(Distance(originalLocation, originalLocation + moveVec)), FColor::Orange);
		
		if (FMath::FRand() > 0.5f)
		{
			eventNumber++;
			CreateEvent();
		}
	}

	Log("All distance is " + FString::SanitizeFloat(Distance(originalLocation, originalLocation + moveVec)) +
			", number of events occurs is  " + FString::FromInt(eventNumber) + " times.", FColor::Green);
}

void ACActor::Log(FString str, FColor color)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	GEngine->AddOnScreenDebugMessage(-1, 5, color, str);
}

void ACActor::CreateEvent()
{
	Log("Event!", FColor::Yellow);
}

int ACActor::Step() const { return FMath::RandRange(0, 1); }

double ACActor::Distance(const FVector& first, const FVector& second) const
{
	double x = first.X - second.X;
	double y = first.Y - second.Y;
	double z = first.Z - second.Z;
	return FMath::Sqrt(x * x + y * y + z * z);
}
