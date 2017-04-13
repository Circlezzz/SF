// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Projectile.h"
#include "SF_Character.generated.h"

UCLASS()
class SF_API ASF_Character : public ACharacter
{
	GENERATED_BODY()

		UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Mesh1P;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FP_Gun;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FP_Camera;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* FP_FireLocation;

	UPROPERTY(VisibleDefaultsOnly, Category = Particle)
		UParticleSystemComponent* Fire_Particle;


	bool fire;

	int Ammo;

	float Shoot_Timer;


public:
	// Sets default values for this character's properties
	ASF_Character();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
		TSubclassOf<AProjectile>Projectile_BP;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		class USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		class UAnimMontage* FireAnimation;

protected:
	void StartFire();
	void StopFire();
	void OnFire();
	void MoveForward(float value);
	void MoveRight(float value);
	void Reload();
	void BeginCrouch();
	void EndCrouch();
	
};
