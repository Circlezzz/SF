#pragma once
#include "UObject/NoExportTypes.h"
#include "HJTest.generated.h"

UCLASS()
class HJ_API UHJTest : public UObject
{
	GENERATED_BODY()
	
public:
	UHJTest();
	UPROPERTY()	int s1;
	UFUNCTION()	void SetValue1(int s);
	UFUNCTION()	int  GetValue1();
};

