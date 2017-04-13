// Fill out your copyright notice in the Description page of Project Settings.

#include "SF.h"
#include "SF_Character.h"


// Sets default values
ASF_Character::ASF_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	FP_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FP_Camera"));
	FP_Camera->SetupAttachment(GetCapsuleComponent());
	//FP_Camera->AttachTo(GetCapsuleComponent());
	FP_Camera->RelativeLocation = FVector(0, 0, 64.0f);
	FP_Camera->bUsePawnControlRotation = true;

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FP_Camera);
	//Mesh1P->AttachTo(FP_Camera);
	Mesh1P->CastShadow = false;

	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetupAttachment(Mesh1P);
	//FP_Gun->AttachTo(RootComponent);
	FP_Gun->CastShadow = false;
	FP_Gun->SetOnlyOwnerSee(true);

	FP_FireLocation = CreateDefaultSubobject<USceneComponent>(TEXT("FP_FireLocation"));
	FP_FireLocation->SetupAttachment(FP_Gun);

	fire = false;
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	GetCharacterMovement()->CrouchedSpeedMultiplier_DEPRECATED = 0.5f;
	//GetCharacterMovement()->CrouchedHalfHeight = 20.0f;

	Fire_Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire_Particle"));
	Fire_Particle->SetupAttachment(FP_FireLocation);
	Fire_Particle->SetAutoActivate(false);

	Ammo = 30;
	Shoot_Timer = 1.0f;
}

// Called when the game starts or when spawned
void ASF_Character::BeginPlay()
{
	Super::BeginPlay();
	
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
}

// Called every frame
void ASF_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (fire)
	{
		//OnFire();
		if (Shoot_Timer > 0.1f)
		{
			OnFire();
			Shoot_Timer = 0;
		}
		Shoot_Timer += DeltaTime;
	}
}

// Called to bind functionality to input
void ASF_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASF_Character::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ASF_Character::StopFire);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ASF_Character::Reload);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ASF_Character::BeginCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ASF_Character::EndCrouch);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("MoveForward", this, &ASF_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASF_Character::MoveRight);
}

void ASF_Character::StartFire()
{
	fire = true;
}

void ASF_Character::StopFire()
{
	fire = false;
	Shoot_Timer = 1.0f;
}

void ASF_Character::OnFire()
{
	FRotator Fire_Ro = FRotator(0, 0, 90.0f);
	AProjectile* Bullet = GetWorld()->SpawnActor<AProjectile>(Projectile_BP, FP_FireLocation->GetComponentLocation(), FP_FireLocation->GetComponentRotation());
	UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
	if (AnimInstance != NULL)
	{
		AnimInstance->Montage_Play(FireAnimation, 1.f);
	}
	if (FireSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}
	if (Fire_Particle)
	{
		Fire_Particle->ActivateSystem();
	}
}

void ASF_Character::MoveForward(float value)
{
	if (value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}

void ASF_Character::MoveRight(float value)
{
	if (value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

void ASF_Character::Reload()
{
	Ammo = 30;
}

void ASF_Character::BeginCrouch()
{
	//CrouchedEyeHeight = BaseEyeHeight/4;
	//RecalculateBaseEyeHeight();
	Crouch();
}

void ASF_Character::EndCrouch()
{
	//RecalculateBaseEyeHeight();
	UnCrouch();
}