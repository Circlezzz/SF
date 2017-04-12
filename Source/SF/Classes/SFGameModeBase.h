#pragma once

#include "GameFramework/GameModeBase.h"
#include "HJTest.h"
#include "RLTest.h"
#include "SFGameModeBase.generated.h"

UCLASS()
class SF_API ASFGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ASFGameModeBase();
	virtual void BeginPlay() override;

	UPROPERTY()	class UHJTest* HJTest;
	UPROPERTY()	class URLTest* RLTest;


};
