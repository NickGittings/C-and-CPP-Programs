#include <stdio.h>

/*
Nicholas Gittings
CECS 130-01
Calculator
*/


int main(){
	
	// Declaring Variables
	int Running = 1;
	int Program_Type;
	float x, y;
	int i, j, Primenum;
	
	// Creating Menu and Creating Operations/Answers
	do {
		int test = 0;
		printf("Calculator 1.0\n 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Modulus\n 6. Test if prime\n 7. Exit \nPlease select an operation: ");
		scanf("%d", &Program_Type);
		switch(Program_Type){
			case 1:  
			printf("Addition\nInput a number: ");
			scanf("%f", &x);
			printf("Input another number: ");
			scanf("%f", &y);
			float AddSolved = x + y;
			printf("%f + %f = %f\n", x, y, AddSolved);
			break;
			
			case 2:
			printf("Subtraction\n");
			printf("Input a number: ");
			scanf("%f", &x);
			printf("Input another number: ");
			scanf("%f", &y);
			float SubSolved = x - y;
			printf("%f - %f = %f\n", x, y, SubSolved);
			break;
			
			case 3:
			printf("Multiplication\n");
			printf("Input a number: ");
			scanf("%f", &x);
			printf("Input another number: ");
			scanf("%f", &y);
			float MultSolved = x * y;
			printf("%f * %f = %f\n", x, y, MultSolved);
			break;
			
			case 4:
			printf("Division\n");
			printf("Input a number: ");
			scanf("%f", &x);
			printf("Input another number: ");
			scanf("%f", &y);
			float DivSolved = x / y;
			printf("%f / %f = %f\n", x, y, DivSolved);
			break;
			
			case 5:
			printf("Modulus\n");
			printf("Input a number: ");
			scanf("%d", &i);
			printf("Input another number: ");
			scanf("%d", &j);
			int ModSolved = i % j;
			printf("%d %% %d = %d\n", i, j, ModSolved);
			break;
			
			case 6:
			printf("Prime Test\n");
			printf("Input a positive number: ");
			scanf("%d", &Primenum);
				for(i = 2; i <= Primenum/2; ++i ){
					if (Primenum % i == 0){
						test = 1;
						break;
					}
				}
			if (test == 0){
				printf("%d is prime\n", Primenum);
			}
			else{
				printf("%d is not prime\n", Primenum);
			}
			break;
			
			case 7: 
			printf("Ending Program");
			Running = 0; 
		
		
		}
	} while(Running == 1);

	return 0;
}
