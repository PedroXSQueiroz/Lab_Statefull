// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/StatefullCharacter.h"

// Sets default values
AStatefullCharacter::AStatefullCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

UActionStatefullBinding* AStatefullCharacter::GetBinding(FName bindingName)
{
	if (this->Bindings.Contains(bindingName)) 
	{
		return this->Bindings[bindingName];
	}
	
	return NULL;
}

// Called when the game starts or when spawned
void AStatefullCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStatefullCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

void AStatefullCharacter::CleanBindings()
{
	TArray<FName> bindingNames;

	this->Bindings.GetKeys(bindingNames);

	for (FName bindingName: bindingNames)
	{
		this->Bindings[bindingName]->InputBindingTrigger.Clear();
	}
}

// Called to bind functionality to input
void AStatefullCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

