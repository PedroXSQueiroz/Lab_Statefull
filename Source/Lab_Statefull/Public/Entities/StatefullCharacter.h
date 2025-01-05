// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputAction.h"
#include "InputActionValue.h"

#include "StatefullCharacter.generated.h"

//#define STATEFULL_INPUT(InputName)	UPROPERTY(BlueprintReadWrite, EditAnywhere)	\
//									UInputAction* InputName##Input;				

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInputTrigger, const FInputActionValue&, actionValue);

UCLASS(BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class LAB_STATEFULL_API UActionStatefullBinding : public UObject
{
	GENERATED_BODY()

public:

	int Calls{0};

	void OnInputTrigger(const FInputActionValue& actionValue) 
	{
		this->InputBindingTrigger.Broadcast(actionValue);
	}

	FOnInputTrigger InputBindingTrigger;


};

UCLASS()
class LAB_STATEFULL_API AStatefullCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AStatefullCharacter();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FName, UInputAction*> Actions;

	UActionStatefullBinding* GetBinding(FName bindingName);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY()
	TMap<FName, UActionStatefullBinding*> Bindings;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CleanBindings();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
