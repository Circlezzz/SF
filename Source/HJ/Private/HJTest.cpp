#include "HJ.h"
#include "HJTest.h"

UHJTest::UHJTest()
{
	
}

void UHJTest::SetValue1(int s)
{
	s1 = s+1;
	UE_LOG(LogClass, Error, TEXT("HJTest::SetValue1(int s)=%d"), s1);
}
int UHJTest::GetValue1()
{
	UE_LOG(LogClass, Error, TEXT("%s"), TEXT("HJTest::GetValue()"));
	return s1;
}

