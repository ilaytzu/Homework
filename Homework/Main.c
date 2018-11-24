#include <stdio.h>
#include <math.h>

//helper fucntion defenitions
void trig(int left, int right);
void rug1(int width);
void rug2(int width);
void rug3(int width);


//first option func
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

//second option func
void op2()
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

//third option func
void op3()
{
	int width;
	scanf("%d",&width);
	if (width >= 2 && width <= 10)
	{
		rug1(width);
		rug2(width);
		if (width % 2 == 0)
			rug3(width);
	}
	else
		printf("Error input!\n");
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

//rug pattern 1
void rug1(int width)
{
	int i, j;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < width; j++)
		{
			if ((i % 2 == 0 && j % 2 == 0) || (!(i % 2 == 0) && !(j % 2 == 0)))
				printf("X");
			else
				printf("O");
		}
		printf("\n");
	}
	printf("\n");
	return;
}

//rug pattern 2
void rug2(int width)
{
	int i,j;
	for (i = 0; i <= width; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("O");
		}
		for (j = 0; j < width-i; j++)
		{
			printf("X");
		}
		printf("\n");
	}
	printf("\n");
	return;
}

//rug pattern 3
void rug3(int width)
{
	int i, j;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < width; j++)
		{
			if ((i >= width / 2 || j >= width / 2) && !(i >= width / 2 && j >= width / 2))
				printf("O");
			else
				printf("X");
		}
		printf("\n");
	}
	printf("\n");
	return;
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