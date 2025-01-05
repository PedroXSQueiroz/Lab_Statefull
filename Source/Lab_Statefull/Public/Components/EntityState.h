// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EntityState.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LAB_STATEFULL_API UEntityState : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEntityState();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Params")
	FName EntityStateName;
	
	virtual bool Init(AActor* actor, bool first = false);

	virtual bool Exit(AActor* actor) PURE_VIRTUAL(TEXT("NOT IMPLEMENTED YET"), return false; );

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void StatefullTick(AActor* actor, float DeltaTime) PURE_VIRTUAL(TEXT("NOT IMPLEMENTED YET"););

	void ChangeTo(FName StateName);

	UPROPERTY()
	bool IsStateActive;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
