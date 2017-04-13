#include "SF.h"
#include "SFGameModeBase.h"

ASFGameModeBase::ASFGameModeBase()
{
	//HJTest = CreateDefaultSubobject<UHJTest>(TEXT("SF_HJTest"));
	//RLTest = CreateDefaultSubobject<URLTest>(TEXT("SF_RLTest"));

	ConstructorHelpers::FClassFinder<APawn>FP_Pawn(TEXT("/Game/Blueprints/CPP/BP_SFCharacter"));
	DefaultPawnClass = FP_Pawn.Class;
}

void ASFGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	HJTest = NewObject<UHJTest>(this);
	RLTest = NewObject<URLTest>(this);
	UE_LOG(LogClass, Error, TEXT("=========================================="));
	HJTest->SetValue1(7);	
	UE_LOG(LogClass, Error, TEXT("HJTest->GetValue()=%d"), HJTest->GetValue1());
	RLTest->SetValue1(3);
	UE_LOG(LogClass, Error, TEXT("RLTest->GetValue()=%d"), RLTest->GetValue1());
	UE_LOG(LogClass, Error, TEXT("=========================================="));

}
