#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Nick Gittings
CECS 130-1
Phonebook Application
*/

int counter = 0;

//Structure for Phone book addresses
struct Phonebook
{
	char* FirstName;
	char* LastName;
	char* PhoneNumber;
}Phonebook;

struct Phonebook Contacts[100];


//Function Prototypes to add, remove, and display friends
void Add_Friend();
void Remove_Friend(struct Phonebook Contacts[]);
void DisplayContacts(struct Phonebook Contacts[]);

int main()
{	 
	//Creating menu selection and boolean to keep menu running
	int Program_Type;
	int Running = 1;
	
	//Creating menu
	do
	{
		printf("Phonebook 1.0\n");
		printf("1. Add Friend\n2. Delete Friend\n3. Show Phone book\n4. Exit\n");
		scanf("%d", &Program_Type);
		
		switch(Program_Type)
		{
			
			case 1:
				printf("Add Friend:\n");
				Add_Friend();
				printf("Record Added to Phone book\n");
				break;
			
			case 2:
				printf("Remove Friend:\n");
				Remove_Friend(Contacts);
				break;
				
			case 3:
				printf("Phone Book Enteries\n");
				DisplayContacts(Contacts);
				break;
			
			case 4:
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
void Add_Friend()
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
	
	//Assigning user input to struct variables
	for(i = counter; i < counter + 1; i++)
	{
		Contacts[i].FirstName = malloc(sizeof(Phonebook.FirstName));
		Contacts[i].LastName = malloc(sizeof(Phonebook.LastName));
		Contacts[i].PhoneNumber = malloc(sizeof(Phonebook.PhoneNumber));
	}
	
	for(i = counter; i < counter + 1; i++)
	{
		strcpy(Contacts[i].FirstName, firstname);
		strcpy(Contacts[i].LastName, lastname);
		strcpy(Contacts[i].PhoneNumber, phonenum);
	}

}

//Remove friend function
void Remove_Friend(struct Phonebook Contacts[])
{
	int i;
	printf("Input the contact number you want to delete: ");
	scanf("%d", &i);
	
	//Assigning NULL value to remove struct variables
	Contacts[i].FirstName = "\0";
	Contacts[i].LastName = "\0";
	Contacts[i].PhoneNumber = "\0";
	
}

//Display contacts function
void DisplayContacts(struct Phonebook Contacts[])
{
	//For loop to print struct variables in struct array
	int i = 0;
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
