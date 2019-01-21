#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomizer(char *array[]); 

int main()
{
	int Running = 1, exit = 1;
	char var[4][25];
	char *word_list[5] = {"suck", "are the best", "don't win", "will throw the championship", "will win the championship"};
	char *word_list2[5] = {"ate you", "pooped on you", "became your friend", "ran away"};
	
	do
	{
		
		printf("%c", *word_list);
		
		printf("Enter your name, age, favorite sports team, and your favorite animal: ");
		scanf("%s %s %s %s", &var[0], &var[1], &var[2], &var[3]);
		printf("%s is %s and their favorite team is the %s and they ", var[0], var[1], var[2]);
		randomizer(word_list);
		printf(" and your favorite animal is a %s and it ", var[3]);
		randomizer(word_list2);
		printf(" and you lived happily ever after, the end.");
		printf("\nEnter 0 to exit or 1 for another story: ");
		scanf("%d", &exit);
		if(exit == 0)
		{
			break;
		}
		
	}while(Running = 1);

	return 0;
}

int randomizer(char *array[])
{
	int n;
	srand(time(NULL));
	n = rand() % 5;
	
	printf("%s", array[n]);
}
