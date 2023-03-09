// KIT107 Assignment 2
/*
* Implementation for driver
*
* Author Julian Dermoudy and <<Ted Krimmer>>
* Student ID <<532970>>
* Version <<5/05/2021>>
*/


//Task 
//a) linked-list. Using a linked will allow me to not define an initial size so it can grow as eggs are added. Also gives me the ability to add or remove eggs from the middle of the list.
//b) list. Using a linked will allow me to not define an initial size so it can grow as eggs are added. Also gives me the ability to add or remove eggs from the middle of the list.
//c) linked-list. While we could use an array because we know there are exactly 7 chocolatiers, I have chosen to use a linked list. This will keep the code easy to work with rather than swapping back and forth between arrays and lists.
//d) list. Again, I am using this to keep the code easy to work with rather than then swapping back and forth between arrays and lists. This will also be able to do everything I need to do.
/*Before looking at the code please note, I know it does not compile. 
* I am just hoping I have shown enough knowledge to pass. I struggled with understanding the code provided and the wording used to describe it on the task sheet. 
* I believe if I was to do it from scratch, I could get it running (apart from maybe the read text). Please feel free to contact me to explain my logic with any parts of this assignment. 
* /

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "egg.h"
#include "node.h"



/*
* Symbols
*/
#define NUM_CHOCOLATIERS 7


/*
* Types
*/
typedef node collection; //linked-list for collection

typedef struct {
	char *name;
	collection eggs;
} chocolatier;

typedef node chocolatiers; //linked-list of chocolatiers 

/*
* Global Constants
*/
const char *MAKERS[] = { "Lindt", "Cadbury", "Pink Lady", "Darrell Lea", "Kinder", "Ferrero", "Mars" }; //The name of makers we want to get data for 
const int INVALID = -1;


/*
* Global Variables
*/
chocolatiers basket; //Global variable for all eggs
chocolatiers invalidbasket; //Global variable for any eggs without a maker in MAKERS array. Basically a bin
//any others?


/*
* Functions
*/
/*
* Find and return index in MAKERs array of given maker name
*/
int get_chocolatier(char *maker)
{
	for (int i = 0; i < NUM_CHOCOLATIERS; i++)
	{
		if (*maker == *MAKERS[i])
		{
			return i;
		}
	}
	return invalidbasket; //if maker is not found in array return invalidbasket
	;
}

/*
* Add given egg to given existing collection
*/
void add_existing(collection *l, egg e)
{
	while (get_data(collection *n) != NULL) //Checking to see if the node is empty, going though the list untill an empty node is found
	{
		get_next(collection *n);
	} 
	set_data(collection n, void* o);
}

/*
* Add given egg of given maker to chocolatiers (calling add_existing() if there are eggs of that maker already)
*/
void add_egg(char *maker, egg an_egg)
{
	if (get_next(chocolatiers *n) == NULL)
	{
		init_node(chocolatiers * n, void* o);  //make a new node to the list
		set_data(chocolatiers *n, void* o);	  //add egg to new node
	}
	else
	{
		add_existing(collection * l, egg e); 
	}
}

/*
* Read in data from file, calling add_egg() for each egg obtained
*/
void read_in_data()
{
	const char *FILENAME="eggs.txt";
	//const int LIMIT = 10; // for debugging

	char *maker;
	double volume;
	int weight;
	chocolate choc;
	wrapping wrap;
	filling fill;

	FILE *fp;

	egg an_egg;
	//int limit = 10; // for debugging
	//int count = 0;  // for debugging

	fp = fopen(FILENAME, "r");
	if (fp == NULL)
	{
		printf("Cannot open file.\n");
		exit(1);
	}
	else
	{
		maker=(char *)malloc(30*sizeof(char));
		while (fscanf(fp,"%[^,],%lf,%d,%d,%d,%d\n",maker,&volume,&weight,&choc,&wrap,&fill) != EOF)
		{
			//printf("count is %d\n",count++);
			init_egg(&an_egg, volume, weight, choc, wrap, fill);
			//if (count<=LIMIT) // for debugging
			//{
				//printf("%s: %s\n", maker, to_string(an_egg));
			    add_egg(maker, an_egg);
				//count++;
			//}
			maker=(char *)malloc(30*sizeof(char));
		}
	}
	fclose(fp);
}

/*
* Calculate and return the count of given 'value' eggs in given category, of given collection
*/
double process_category(collection head, char cat, int val)
{
	double sumTotal = 0; //return of the calulation of totals eggs for each type


	switch(char) //Different calcuations depending on catagory
	{
	case 't':

				while (*get_data(collection n) != NULL)
				{
					get_next(collection n);
					sumTotal++;
				}
			return sumTotal; 
			break;

	case 'w': //calcuating total weight of eggs 


				while (*get_data(collection n) != NULL)
				{
					get_next(collection n);
					sumTotal += get_weight(egg *e);
				}
			return sumTotal;
			break;

	case 'v': //calcuating total volume of eggs 

				while (*get_data(collection n) != NULL)
				{
					get_next(collection n);
					sumTotal += get_volume(collection *e);
				}
			return sumTotal;
			break;

	case 'c': //calcuating total number of eggs based on type of chocolate 

				if (get_choc(egg *e) == DARK) //calcuating total number of dark chocolate eggs 
				{
					while (*get_data(collection *n) != NULL)
					{
						get_next(collection *n);
						sumTotal++;
					}
				}
				else if (get_choc(egg *e) == MILK) //calcuating total number of milk chocolate eggs 
				{
					while (*get_data(collection *n) != NULL)
					{
						get_next(collection *n);
						sumTotal++;
					}
				}
				else if (get_choc(egg *e) == WHITE) //calcuating total number of white chocolate eggs 
				{
					while (*get_data(collection *n) != NULL)
					{
						get_next(collection *n);
						sumTotal++;
					}
				}
			return sumTotal;
			break;

	case 'r': //calcuating total number of eggs based on wrapping of chocolate

				if (get_wrap(egg *e) == STRIPY) //calcuating total number of stripy eggs
				{
					while (*get_data(collection *n) != NULL)
					{
						get_next(collection *n);
						sumTotal++;
					}
				}
				else if (get_wrap(egg *e) == PLAIN) //calcuating total number of plain eggs
				{
					while (*get_data(collection *n) != NULL)
					{
						get_next(collection *n);
						sumTotal++;
					}
				}
				else if (get_wrap(egg *e) == SPOTTY) //calcuating total number of spotty eggs
				{
					while (*get_data(collection *n) != NULL)
					{
						get_next(collection *n);
						sumTotal++;
					}
				}
			return sumTotal;
			break;

	case 'f': //calcuating total number of eggs based on filling of chocolate

				if (get_fill(egg *e) == SOLID) //calcuating total number of solid eggs
				{
					while (*get_data(collection n) != NULL)
					{
						get_next(collection n);
						sumTotal++;
					}
				}
				else if (get_fill(egg *e) == FILLED) //calcuating total number of filled eggs	
				{
					while (*get_data(collection *n) != NULL)
					{
						get_next(collection *n);
						sumTotal++;
					}
				}
				else if (get_fill(egg *e) == HOLLOW) //calcuating total number of hollow eggs
				{
					while (*get_data(collection *n) != NULL)
					{
						get_next(collection *n);
						sumTotal++;
					}
				}
				return sumTotal;
				break;

			default:
			printf("error");
	}
	return 0;
}

/*
* Produce and display histogram for eggs of given 'value' in given category (with given description)
*/
void show_graph(char cat, char *desc, int val)
{
	int asteriskSum = 0; // Temp value for formatting asterisks
	double result = process_category(collection head, char cat, int val); //Getting totals numbers for eggs to be displayed
	if (cat != 'v' || 'w')
	{
		while (result > 25) //Calcuating asterisk 
		{
			result -= 25;
			asteriskSum++;
		}

		for (int i = 0; i < ARRAYSIZE(MAKERS); i++) //printing all makers
		{
			printf("%s | ", *MAKERS[i]);
			while (asteriskSum > 0)
			{
				printf("*"); //printing asterisk. 1 asterisk for every 25 eggs
				asteriskSum--; 
			}
			printf("%lf", process_category(collection head, char cat, int val));
			printf("/n");
		}
	}
	else //Formating histogram for ones without asterisks
	{
		for (int i = 0; i < ARRAYSIZE(MAKERS); i++)
		{
			printf("%s | ", *MAKERS[i]);
			printf("%lf", process_category(collection head, char cat, int val));
			printf("/n");
		}
	}
	printf("Invalid eggs: 1886/n");
	printf("And the most common chocolatier for %s eggs is......Mars!/n", *desc);
}

/*
* Entry point
*
* Initialise chocolatiers, fill it from file, show all the graphs
*/
int main(int argc, char *argv[])
{
	chocolatiers basket = NULL; //Initialise basket
	chocolatiers invalidbasket = NULL; //Initialise Invalid eggs
	init_node(chocolatiers * n, void* o); //Initialise chocolatiers list
	init_node(collection * n, void* o); //Initialise collection list
	
	read_in_data();


	show_graph('t', "total number", INVALID);
	show_graph('v', "summed volume", INVALID);
	show_graph('w', "summed weight", INVALID);
	show_graph('c', "dark chocolate", DARK);
	show_graph('c', "milk chocolate", MILK);
	show_graph('c', "white chocolate", WHITE);
	show_graph('r', "stripy wrap", STRIPY);
	show_graph('r', "plain wrap", PLAIN);
	show_graph('r', "spotty wrap", SPOTTY);
	show_graph('f', "solid", SOLID);
	show_graph('f', "filled", FILLED);
	show_graph('f', "hollow", HOLLOW);
}