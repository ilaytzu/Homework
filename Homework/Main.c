#include <stdio.h>
#include <math.h>

//helper fucntion defenitions
void trig(int left, int right);
void rug1(int width);
void rug2(int width);
void rug3(int width);
void quad(float a, float b, float c);
void solveeq(float a, float b, float c);

float max(float a, float b)
{
	if (a > b)
		return a;
	return b;
}

float min(float a, float b)
{
	if (a > b)
		return b;
	return a;
}

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
		{
			rug3(width);
		}
	}
	else
		printf("Error input!\n");
	return;
}

//forth option func
void op4()
{
	int a, b, c;
	printf("Enter three numbers:\n");
	scanf("%d %d %d",&a,&b,&c);
	//a
	if (a == 1)
		printf("x^2");
	else if (a == -1)
		printf("-x^2");
	else if (a == 0)
		printf("");
	else
		printf("%dx^2", a);
	//b
	if (b == 1 && a != 0)
		printf("+x");
	else if (b == 1 && a == 0)
		printf("x");
	else if (b == -1)
		printf("-x");
	else if (b == 0)
		printf("");
	else if (b > 0 && a != 0)
		printf("+%dx", b);
	else if (b > 0 && a == 0)
		printf("%dx", b);
	else
		printf("-%dx", -b);
	//c
	if (a != 0 || b != 0)
	{
		if (c == 0)
			printf("");
		else if (c > 0)
			printf("+%d", c);
		else
			printf("%d", c);
	}
	else
	{
		printf("%d", c);
	}
	printf(" = 0\n");
	solveeq(a, b, c);
	return;
}

void trig(int left, int right)//calculate triangulat numbers between 2 numbers
{
	int n = 1, found = 0, Tn = 1;
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
	return;
}

//rug pattern 3
void rug3(int width)
{
	printf("\n");
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
	return;
}

//quadratic function
void quad(float a, float b, float c)
{
	int bi = b;
	float x1, x2, re, im;
	float delta = b * b - 4 * a*c;
	if (delta == 0)
	{
		x1 = -b / (2 * a);
		printf("x1 = %.2f\n", x1);
	}
	else if (delta > 0)
	{
		x1 = (-b + sqrtf(delta)) / (2 * a);
		x2 = (-b - sqrtf(delta)) / (2 * a);
		printf("x1 = %.2f\n", min(x1, x2));
		printf("x2 = %.2f\n", max(x1, x2));
	}
	else
	{
		re = -b;
		re /= (2 * a);
		im = (sqrtf(-delta)) / (2 * a);
		if (bi != 0) 
		{
			printf("x1 = %.2f - %.2fi\n", re, im);
			printf("x2 = %.2f + %.2fi\n", re, im);
		}
		else
		{
			printf("x1 = -%.2fi\n", im);
			printf("x2 = %.2fi\n", im);
		}
	}
}

void solveeq(float a, float b, float c)
{
	if (a == 0 && b == 0 && c == 0)
	{
		printf("Infinite solutions!\n");
		return;
	}
	else if (a == 0 & b == 0 && c != 0)
	{
		printf("No solution!\n");
		return;
	}
	else if (a == 0 && b != 0)
	{
		if (c == 0)
			printf("x1 = %.2f\n", 0);
		else
			printf("x1 = %.2f\n", -c / b);
		return;
	}
	else
	{
		quad(a, b, c);
		return;
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
	} while (a != -1);
	return 0;
}