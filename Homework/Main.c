#include <stdio.h>
#include <math.h>

void trig(int left, int right)
{
	int n = 1, found = 0, Tn;
	do
	{
		Tn = (n * (n + 1)) / 2;
		if (left <= Tn && Tn <= right)
		{
			found = 1;
			printf("%d\n", Tn);
		}
		n++;
	} while (!(Tn > right));
	if (found == 0)
	{
		printf("None\n");
	}
}

int main()
{
	int left, right;
	printf("Enter 2 numbers (left and right):\n");
	scanf("%d %d",&left,&right);
	trig(left,right);
	system("pause");
	return 0;
}