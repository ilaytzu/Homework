#include <stdio.h>
#include <math.h>

void trig(int left, int right);

void op1()
{
	int left, right;
	printf("Enter 2 numbers (left and right):\n");
	scanf("%d %d", &left, &right);
	if (left > right || left < 0 || right < 0)
		printf("Error input!\n");
	else
		trig(left, right);
}

void op2()
{
	return;
}

void op3()
{
	return;
}

void op4()
{
	return;
}

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
	int a;
	do
	{
		printf("Choose 1 for triangle, 2 for ID, 3 for carpets, 4 for equation, -1 for exit\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			op1();
			break;
		case 2:
			op2();
			break;
		case 3:
			op3();
			break;
		case 4:
			op4();
			break;
		default:
			break;
		}
	} while (a!=-1);
	system("pause");
	return 0;
}