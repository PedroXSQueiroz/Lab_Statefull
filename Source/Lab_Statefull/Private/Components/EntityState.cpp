// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/EntityState.h"

// Sets default values for this component's properties
UEntityState::UEntityState()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool UEntityState::Init(AActor* actor, bool first)
{
	if (first) 
	{
		this->IsStateActive = true;
	}

	return true;
}


// Called when the game starts
void UEntityState::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEntityState::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (this->IsStateActive) 
	{
		this->StatefullTick(this->GetOwner(), DeltaTime);
	}
}

UEntityState* UEntityState::ChangeTo(FName StateName)
{
	AActor* owner = this->GetOwner();
	TSet<UActorComponent*> components = owner->GetComponents();

	for (UActorComponent* currentComponent : components) 
	{
		if (currentComponent->IsA(UEntityState::StaticClass())) 
		{
			UEntityState* currentState = Cast<UEntityState>(currentComponent);
			if (currentState->EntityStateName.IsEqual(StateName)) 
			{
				UE_LOG(LogTemp, Log, TEXT("Exiting state: %s"), *this->EntityStateName.ToString());
				bool exitSuccefull = this->Exit(owner);

				if (exitSuccefull) 
				{

					UE_LOG(LogTemp, Log, TEXT("Exited state: %s"), *this->EntityStateName.ToString());
					this->IsStateActive = false;
					bool initSuccessfull = currentState->Init(owner);
					UE_LOG(LogTemp, Log, TEXT("Initiating state: %s"), *currentState->EntityStateName.ToString());

					if (initSuccessfull) 
					{
						UE_LOG(LogTemp, Log, TEXT("Initiated state: %s"), *currentState->EntityStateName.ToString());
						currentState->IsStateActive = true;
						return currentState;
					}
					else 
					{
						UE_LOG(LogTemp, Log, TEXT("Not initiated state: %s"), *currentState->EntityStateName.ToString());
					}
				}
				else 
				{
					UE_LOG(LogTemp, Log, TEXT("Not exited state: %s"), *this->EntityStateName.ToString())
				}
			}
		}
	}
	
	return NULL;
}

bool UEntityState::GetIsStateActive()
{
	return this->IsStateActive;
}
