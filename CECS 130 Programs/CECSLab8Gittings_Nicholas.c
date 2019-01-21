#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/*
Nick Gittings
CECS 130-1
Phonebook Application Writing to File
*/

FILE *file;

int counter = 0;
int n;

//Structure for Phone book addresses
struct Phonebook
{
	char *FirstName;
	char *LastName;
	char *PhoneNumber;
}Phonebook;


//Function Prototypes to add, remove, and display friends
void Add_Friend(struct Phonebook *Contacts);
void Remove_Friend(struct Phonebook *Contacts);
void DisplayContacts(struct Phonebook *Contacts);
void Alpha(struct Phonebook *Contacts, int n);
void Search(struct Phonebook *Contacts);
void Random(struct Phonebook *Contacts);
void DeleteAll(struct Phonebook *Contacts, int n);
void ReadContacts(struct Phonebook *Contacts);
void WriteContacts(struct Phonebook *Contacts, int n);

int main()
{	
	int input = 0;
	struct Phonebook *Contacts;

	printf("Do you have a file? 0 for no or 1 for yes\n");
	scanf("%d", &input);
	switch(input)
	{
		case 1:
			ReadContacts(Contacts);
			break;
	
		case 0:
			printf("How many contacts would you like? ");
			scanf("%d", &n);
				//Allocating Memory to Struct pointer
			Contacts = malloc(sizeof(struct Phonebook) * n);
			if(Contacts == NULL)
			{
				printf("Out of memory... Quitting\n");
				return 1;
			}
			break;
	}
	


	//Creating menu selection and boolean to keep menu running
	int Program_Type;
	int Running = 1;
	
	//Creating menu
	do
	{
		printf("Phonebook 3.0\n");
		printf("1. Add Friend\n2. Delete Friend\n3. Sort Alphabetically\n4. Search by Name\n5. Randomly Select a Friend\n6. Delete all Friends\n7. Show Phone book\n8. Save File\n9. Exit\n");
		scanf("%d", &Program_Type);
		
		switch(Program_Type)
		{
			
			case 1:
				printf("Add Friend:\n");
				Add_Friend(Contacts);
				printf("Record Added to Phone book\n");
				break;
			
			case 2:
				printf("Remove Friend:\n");
				Remove_Friend(Contacts);
				break;
				
			case 3:
				printf("Alphabetical Order by First Name\n");
				Alpha(Contacts, n);
				break;
			
			case 4:
				printf("Search for friend by First and Last Name\n");
				Search(Contacts);
				break;
				
			case 5:
				printf("Randomly Finding Friend...\n");
				Random(Contacts);
				break;
			
			case 6:
				DeleteAll(Contacts, n);
				free(Contacts);
				break;
				
			case 7:
				printf("Phone Book Enteries\n");
				DisplayContacts(Contacts);
				break;
					
			case 8:
				printf("Saving to file...");
				WriteContacts(Contacts, n);
			
			case 9:
				Running = 0;
				free(Contacts);
				break;
				
			default:
				printf("Invalid Input\n");
				break;
		}
		
	}while(Running == 1);
	
	
	return 0;
}

//Add friend function
void Add_Friend(struct Phonebook *Contacts)
{
	counter ++;
	int i;
	
	//Allocating memory
	for(i = counter; i < counter + 1; i++)
	{
		Contacts[i].FirstName = malloc(sizeof(char) * 100);
		Contacts[i].LastName = malloc(sizeof(char) * 100);
		Contacts[i].PhoneNumber = malloc(sizeof(char) * 100);
	}
	
	
	//Reading user input
	printf("First Name: ");
	scanf("%s", Contacts[counter].FirstName);
	
	printf("Last Name: ");
	scanf("%s", Contacts[counter].LastName);
	
	printf("Phone Number: ");
	scanf("%s", Contacts[counter].PhoneNumber);
	
}

//Remove friend function
void Remove_Friend(struct Phonebook *Contacts)
{
	if(counter ==0)
	{
		printf("You have no contacts!\n");
	}
	else
	{
		int i;
		printf("Input the contact number you want to delete: ");
		scanf("%d", &i);
	
		//Assigning NULL value to remove struct variables
		Contacts[i].FirstName = "\0";
		Contacts[i].LastName = "\0";
		Contacts[i].PhoneNumber = "\0";
	}
}

//Display contacts function
void DisplayContacts(struct Phonebook *Contacts)
{
	//For loop to print struct variables in struct array
	int i;
	
	if(counter == 0)
	{
		printf("You have no contacts!\n");
	}
	
	else
	{
		for(i = 1; i < counter + 1; i++)
		{
			if(Contacts[i].FirstName == "\0")
			{
			}
			else
			{
				printf("Contact#: %d\n", i);
				printf("First Name: %s\n", Contacts[i].FirstName);
				printf("Last Name: %s\n", Contacts[i].LastName);
				printf("Phone Number: %s\n", Contacts[i].PhoneNumber);
				printf("-----------------\n");
			}
		}
	}
}


void Alpha(struct Phonebook *Contacts, int n)
{
	struct Phonebook *AlphaContacts;
	AlphaContacts = malloc(sizeof(struct Phonebook));
	int i, j;
	if(counter == 0)
	{
		printf("You have no contacts!\n");
	}
	
	else
	{
		//Allocating memory
		for(i = counter; i < counter + 1; i++)
		{
			AlphaContacts[i].FirstName = malloc(sizeof(char) * 100);
			AlphaContacts[i].LastName = malloc(sizeof(char) * 100);
			AlphaContacts[i].PhoneNumber = malloc(sizeof(char) * 100);
		}
		for(i = 1; i < counter + 1; i++)
		{
			for(j = i + 1; j < counter + 1; j++)
			{
				if(strcmp(Contacts[i].FirstName, Contacts[j].FirstName) > 0)
				{
					AlphaContacts[i].FirstName = Contacts[i].FirstName;
					AlphaContacts[i].LastName = Contacts[i].LastName;
					AlphaContacts[i].PhoneNumber = Contacts[i].PhoneNumber;
				}
			}
		}
	
		for(i = 1; i < counter + 1; i++)
		{
			printf("Contact#: %d\n", i);
			printf("First Name: %s\n", AlphaContacts[i].FirstName);
			printf("Last Name: %s\n", AlphaContacts[i].LastName);
			printf("Phone Number: %s\n", AlphaContacts[i].PhoneNumber);
			printf("-----------------\n");
		}
		// Free AlphaContacts memory
		free(AlphaContacts);
	}
}

void Search(struct Phonebook *Contacts)
{
	int i;
	char FirstName_Search[26];
	char LastName_Search[26];
	if(counter == 0)
	{
		printf("You have no contacts\n");
	}
	
	else
	{
		printf("Enter first name: ");
		scanf("%s", FirstName_Search);
		printf("Enter last name: ");
		scanf("%s", LastName_Search);

		for(i = 1; i < counter + 1; i++)
		{
			if(strcmp(FirstName_Search, Contacts[i].FirstName) == 0 && strcmp(LastName_Search, Contacts[i].LastName) == 0)
			{
				printf("Phone Number: %s\n", Contacts[i].PhoneNumber);
				break;
			}
		}
	}
}

void Random(struct Phonebook *Contacts)
{
	if(counter == 0)
	{
		printf("You have no contacts!\n");
	}
	else
	{
		int i;
		srand(time(NULL));
		i = rand() % counter + 1;
		if(counter == 0)
		{
			printf("You have no contacts!\n");
		}
		else
		{
			printf("Contact#: %d\n", i);
			printf("First Name: %s\n", Contacts[i].FirstName);
			printf("Last Name: %s\n", Contacts[i].LastName);
			printf("Phone Number: %s\n", Contacts[i].PhoneNumber);
		}
	}
}

void DeleteAll(struct Phonebook *Contacts, int n)
{
	int i;
	
	if(counter == 0)
	{
		printf("You have no contacts!\n");
	}
	
	else
	{
		printf("Deleteing all friends... Done\n");
		for(i = 1; i < counter + 1; i++)
		{
			Contacts[i].FirstName = "\0";
			Contacts[i].LastName = "\0";
			Contacts[i].PhoneNumber = "\0";
		}
		counter = 0;
		free(Contacts);
		Contacts = malloc(sizeof(struct Phonebook) * n);
		
	}
}

void ReadContacts(struct Phonebook *Contacts)
{
	
	int linenum = 0;
	int i = 1, j;
	char tempstr[100];
	char str[100];
	char name[100];
	
	//Recieving file name from user input
	printf("Enter name of file: ");
	scanf("%s", name);
	
	//Opening file and reading/storing data	
	file = fopen(name, "r");
	while(fgets(str, 100, file)!= NULL)
	{
		if(linenum == 1)
		{
			fscanf(file, "%s", tempstr);
			counter = atoi(tempstr);
		}		
		
		if(linenum == 2)
		{
			fscanf(file, "%s", tempstr);
			n = atoi(tempstr);
			Contacts = malloc(sizeof(struct Phonebook) * n);
			for(j = 1; j < counter + 1; j++)
			{
				Contacts[j].FirstName = malloc(sizeof(char) * 100);
				Contacts[j].LastName = malloc(sizeof(char) * 100);
				Contacts[j].PhoneNumber = malloc(sizeof(char) * 100);
			}
		}
		
		if(linenum == 3)
		{
			fscanf(file, "%s", tempstr);
			Contacts[i].FirstName = tempstr;
		}
			
		if(linenum == 4)
		{
			fscanf(file, "%s", tempstr);
			Contacts[i].LastName = tempstr;
		}
			
		if(linenum == 5)
		{
			fscanf(file, "%s", tempstr);
			Contacts[i].PhoneNumber = tempstr;
			linenum = 3;
		}
		i++;	
		linenum++;
		
	}
	fclose(file);

}

void WriteContacts(struct Phonebook *Contacts, int n)
{
	int i;
	char name[100];
	printf("Enter name of file: ");
	scanf("%s", &name);
	
	//Opens file and writes contacts to it
	file = fopen(name, "w");
	
	char temp[100];
	sscanf(temp, "%d", counter);
	fprintf(file, "%s\n", temp);
	sscanf(temp, "%d", n);
	fprintf(file, "%s\n", temp);
	
	for(i = 1; i < counter + 1; i++)
	{
		fprintf(file, "%s\n", Contacts[i].FirstName);
		fprintf(file, "%s\n", Contacts[i].LastName);
		fprintf(file, "%s\n", Contacts[i].PhoneNumber);
	}
	fclose(file);
}
