#include <stdio.h>
#include <math.h>

//helper fucntion defenitions
void trig(int left, int right);

void op1()//first option func
{
	int left, right;
	printf("Enter 2 numbers (left and right):\n");
	scanf("%d %d", &left, &right);
	if (left > right || left < 0 || right < 0)
		printf("Error input!\n");
	else
		trig(left, right);
}

void op2()//second option func
{
	unsigned long int id;
	int sum = 0, temp, ticker = 0;
	scanf("%u",&id);
	while (id!=0)
	{
		temp = id % 10;
		id = id / 10;
		temp *= (ticker + 1);
		if (temp >= 10)
			sum += (temp / 10) + (temp % 10);
		else
			sum += temp;
		ticker = !ticker;
	}
	if (sum % 10 == 0)
		printf("Valid ID number\n");
	else
		printf("Invalid ID number\n");
}

void op3()
{
	return;
}

void op4()
{
	return;
}

void trig(int left, int right)//calculate triangulat numbers between 2 numbers
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
	if (!found)
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
		case -1:
			break;
		default:
			printf("No such option!\n");
			break;
		}
	} while (a!=-1);
	system("pause");
	return 0;
}