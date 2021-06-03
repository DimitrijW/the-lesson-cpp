#include "pch.h"

TEST(TestCaseName, TestName) 
{
	int frameSize = 0;
	int error[3];
	int a = 0;
	for (int i = 0; i < 10; i++)
	{

		for (int j = 1; j <= 10; j++)
		{
			frameSize += j;
			printf("i %i\n", i);
			printf("j %i\n", j);
			printf("frame size %i\n", frameSize);
			if (frameSize > 5)
			{
				error[a] = frameSize;
				printf("Error %i\n", i);
				a++;
				break;
			}	 
		}
		if(a > 2)
		{
			break;
		}
	}
	printf("firt error %i\n", error[0]);
	printf("second error %i\n", error[1]);
	printf("third error %i\n", error[2]);
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}