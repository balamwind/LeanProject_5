// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CActor.generated.h"

UCLASS()
class PROBLEM_5_API ACActor : public AActor
{
	GENERATED_BODY()

private:
	FVector originalLocation;
	
public:	
	// Sets default values for this actor's properties
	ACActor();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void Move();
	void Log(FString str, FColor color = FColor::Blue);
	void CreateEvent();
	
	int Step() const;
	double Distance(const FVector& first,const FVector& second) const;
};
