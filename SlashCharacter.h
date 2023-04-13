// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterType.h"
#include "SlashCharacter.generated.h"



class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class AItems;
class UAnimMontage;



UCLASS()
class SPLASH_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASlashCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*
		Callbacks for input
	*/
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void EKeyPressed();
	void Attack();

	/*
		Play Montage Function
	*/
	void playAttackMontage();

	UFUNCTION(BlueprintCallable)
	void AttackEnd();
	bool CanAttack();

private:
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;  

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere, Category = Hair)
		UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere, Category = Hair)
		UGroomComponent* Eyebrows;
	
	UPROPERTY(VisibleInstanceOnly)
		AItems* OverlappingItem;

	/*
			Animation Montages
	*/
	UPROPERTY(EditDefaultsOnly, Category = Montages)
		UAnimMontage* AttackMontage;


public:
	FORCEINLINE void SetOverlappingItem(AItems* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const{ return CharacterState; }
};
