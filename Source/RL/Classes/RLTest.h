#pragma once

#include "UObject/NoExportTypes.h"
#include "RLTest.generated.h"


UCLASS()
class RL_API URLTest : public UObject
{
	GENERATED_BODY()
	
public:
	URLTest();
	UPROPERTY()	int s1;
	UFUNCTION()	void SetValue1(int s);
	UFUNCTION()	int  GetValue1();
};
