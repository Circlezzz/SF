#include "RL.h"
#include "RLTest.h"

URLTest::URLTest()
{
}

void URLTest::SetValue1(int s)
{
	s1 = s + 1;
	UE_LOG(LogClass, Error, TEXT("RLTest::SetValue1(int s)=%d"), s1);
}

int URLTest::GetValue1()
{
	UE_LOG(LogClass, Error, TEXT("%s"), TEXT("RLTest::GetValue1()"));
	return s1;
}
