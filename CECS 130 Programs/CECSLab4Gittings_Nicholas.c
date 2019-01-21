#include <stdio.h>

/*
Nick Gittings
CECS 130-1
Calculator With Functions
*/

// Declaring Functions
float Addition(float x, float y);
float Subtraction(float x, float y);
float Multiplication(float x, float y);
float Division(float x, float y);
int Modulus(int i, int j);
int Prime_Test(int i);
int Factorial(int i);
int Power(int i, int j);
int My_Function();


int main()
{
	int Running = 1;
	int Program_Type;
	float x, y, answer;
	int i, j, output;
	// Creating Menu
	do 
	{
		printf("Calculator 2.0\n 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Modulus\n 6. Test if prime\n 7. Factorial\n 8. Power\n 9. My function\n 0. Exit \nPlease select an operation: ");
		scanf("%d", &Program_Type);
		switch(Program_Type){
			case 1: 
			printf("Addition\n"); 
			printf("Input two numbers: ");
			scanf("%f %f", &x, &y);
			answer = Addition(x,y);
			printf("%f + %f = %f\n", x, y, answer);
			break;
			
			case 2:
			printf("Subtraction\n");	
			printf("Input two numbers: ");
			scanf("%f %f", &x, &y);
			answer = Subtraction(x,y);
			printf("%f - %f = %f\n", x, y, answer);
			break;
			
			case 3:
			printf("Multiplication\n");	
			printf("Input two numbers: ");
			scanf("%f %f", &x, &y);
			answer = Multiplication(x,y);
			printf("%f * %f = %f\n", x, y, answer);
			break;
			
			case 4:
			printf("Division\n");
			printf("Input two numbers: ");
			scanf("%f %f", &x, &y);
			answer = Division(x,y);
			printf("%f / %f = %f\n", x, y, answer);
			break;
			
			case 5:
			printf("Modulus\n");
			printf("Input two numbers: ");
			scanf("%d %d", &i, &j);
			output = Modulus(i,j);
			printf("%d %% %d = %d\n", i, j, output);
			break;
			
			case 6:
			printf("Prime Test\n");
			printf("Input a number: ");
			scanf("%d", &i);
			output = Primetest(i);
			if(output == 0)
			{
				printf("%d is prime\n", i);
			}
			if(output == 1)
			{
				printf("%d is not prime\n", i);
			}
			break;
			
			case 7:
			printf("Factorial\n");
			printf("Input a integer: ");
			scanf("%d", &i);
			Factorial(i);
			break;
			
			case 8:
			printf("Power\n");
			printf("Input a base: ");
			scanf("%d", &i);
			printf("Input a power: ");
			scanf("%d", &j);
			Power(i,j);
			break;
			
			case 9:
			printf("My function\n");
			My_Function();
			break;
							
			case 0: 
			printf("Ending Program");
			Running = 0; 
			
			default:
			printf("Invalid Input");
		
		
		}
	} while(Running == 1);
	
	return 0;
}

//Defining Functions
float Addition(float x, float y)
{
	float sum;
	sum = x + y;
	return sum;
}
float Subtraction(float x, float y)
{
	float answer;
	answer = x - y;
	return answer;
}
float Multiplication(float x, float y)
{
	float answer;
	answer = x * y;
	return answer;
}
float Division(float x, float y)
{
	float answer;
	answer = x / y;
	return answer;
}
int Modulus(int i, int j)
{
	int answer;
	answer = i % j;
	return answer;
}
int Primetest(int Primenum)
{
	int i;
	int test = 0;
	for(i = 2; i <= Primenum/2; ++i )
	{
		if (Primenum % i == 0)
		{	
			test = 1;
			break;
		}
	}
	if (test == 0) //prime
	{
		return 0;
	}
	else //not prime
	{
		return 1;
	}
}
int Factorial(int i)
{
	int j, output = 1;
	for(j = 1; j <= i; j++ )
	{
		output = output * j;
	}
	printf("The factorial of %d is %d\n", i, output); 
}
int Power(int i, int j)
{
	int e, output = 1;
	for(e = 1; e <= j; e++)
	{
		output = output * i; 	
	}
	printf("%d to the %d power is %d\n", i, j, output);
}
int My_Function()
{
	int i, terms;
	int array[1000];
	array[0] = 0;
	array[1] = 1;
	printf("How many Fibonacci terms to be shown?: ");
	scanf("%d", &terms);
	for(i = 2; i < terms + 1; i++)
	{
		array[i] = array[i - 1] + array[i - 2];
	}
	printf("The first %d of the Fibonacci sequence are:\n", terms);
	for(i = 0; i < terms; i++)
	{
		printf("%d\n", array[i]);
	}
}
