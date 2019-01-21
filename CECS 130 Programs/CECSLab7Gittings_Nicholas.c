#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Nick Gittings
CECS 130-1
Phonebook Application with New Functions
*/

int counter = 0;

//Structure for Phone book addresses
struct Phonebook
{
	char* FirstName;
	char* LastName;
	char* PhoneNumber;
}Phonebook;


//Function Prototypes to add, remove, and display friends
void Add_Friend(struct Phonebook *Contacts);
void Remove_Friend(struct Phonebook *Contacts);
void DisplayContacts(struct Phonebook *Contacts);
void FreeMem(struct Phonebook *Contacts);
void Alpha(struct Phonebook *Contacts);
void Search(struct Phonebook *Contacts);
void Random(struct Phonebook *Contacts);
void DeleteAll(struct Phonebook *Contacts);

int main()
{	 
	struct Phonebook *Contacts = malloc(sizeof(Phonebook));
	if(Contacts == NULL)
	{
		printf("Out of memory... Quitting\n");
		return 1;
	}

	//Creating menu selection and boolean to keep menu running
	int Program_Type;
	int Running = 1;
	
	//Creating menu
	do
	{
		printf("Phonebook 1.0\n");
		printf("1. Add Friend\n2. Delete Friend\n3. Sort Alphabetically\n4. Search by Name\n5. Randomly Select a Friend\n6. Delete all Friends\n7. Show Phone book\n8. Exit\n");
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
				Alpha(Contacts);
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
				DeleteAll(Contacts);
				break;
				
			case 7:
				printf("Phone Book Enteries\n");
				DisplayContacts(Contacts);
				break;
					
			
			case 8:
				FreeMem(Contacts);
				Running = 0;
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
	char firstname[26];
	char lastname[26];
	char phonenum[15];
	
	//Reading user input
	printf("First Name: ");
	scanf("%s", firstname);
	
	printf("Last Name: ");
	scanf("%s", lastname);
	
	printf("Phone Number: ");
	scanf("%s", phonenum);
	
	//Allocating memory
	for(i = counter; i < counter + 1; i++)
	{
		Contacts[i].FirstName = malloc(sizeof(Phonebook.FirstName));
		Contacts[i].LastName = malloc(sizeof(Phonebook.LastName));
		Contacts[i].PhoneNumber = malloc(sizeof(Phonebook.PhoneNumber));
	}
	//Assigning user input to struct variables
	for(i = counter; i < counter + 1; i++)
	{
		strcpy(Contacts[i].FirstName, firstname);
		strcpy(Contacts[i].LastName, lastname);
		strcpy(Contacts[i].PhoneNumber, phonenum);
	}

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

void FreeMem(struct Phonebook *Contacts)
{
	int i;
	for(i = 1; i < counter + 1; i++)
	{
		free(Contacts[i].FirstName);
		free(Contacts[i].LastName);
		free(Contacts[i].PhoneNumber);
	}
	free(Contacts);
}

void Alpha(struct Phonebook Contacts[])
{
	struct Phonebook *AlphaContacts = malloc(sizeof(Phonebook));
	int i, j;
	char* temp;
	if(counter == 0)
	{
		printf("You have no contacts!\n");
	}
	
	else
	{
		for(i = 1; i < counter + 1; i++)
		{
			AlphaContacts[i].FirstName = malloc(sizeof(Phonebook.FirstName));
			AlphaContacts[i].LastName = malloc(sizeof(Phonebook.LastName));
			AlphaContacts[i].PhoneNumber = malloc(sizeof(Phonebook.PhoneNumber));
		}
		for(i = 1; i < counter - 1; i++)
		{
			for(j = i + 1; j < counter; j++)
			{
				if(strcmp(Contacts[i].FirstName, Contacts[j].FirstName) > 0)
				{
					strcpy(AlphaContacts[i].FirstName, Contacts[i].FirstName);
					strcpy(AlphaContacts[i].LastName, Contacts[i].LastName);
					strcpy(AlphaContacts[i].PhoneNumber, Contacts[i].PhoneNumber);
				}
			}
		}
	}
	
	for(i = 1; i < counter + 1; i++)
	{
		if(AlphaContacts[i].FirstName == "\0")
		{
		}
		else
		{
		printf("Contact#: %d\n", i);
		printf("First Name: %s\n", AlphaContacts[i].FirstName);
		printf("Last Name: %s\n", AlphaContacts[i].LastName);
		printf("Phone Number: %s\n", AlphaContacts[i].PhoneNumber);
		printf("-----------------\n");
		}
	}
}

void Search(struct Phonebook Contacts[])
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

void Random(struct Phonebook Contacts[])
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
		if(Contacts[i].FirstName == NULL)
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

void DeleteAll(struct Phonebook Contacts[])
{
	int i;
	
	if(counter == 0)
	{
		printf("You have no contacts!\n");
	}
	
	else
	{
		printf("Deleteing all friends...\nDone");
		for(i = 1; i < counter + 1; i++)
		{
			Contacts[i].FirstName = "\0";
			Contacts[i].LastName = "\0";
			Contacts[i].PhoneNumber = "\0";
		}
		counter = 0;
	}
}
