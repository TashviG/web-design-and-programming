#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


//define global variables
char jobIdLookup[30];
char jobNameLookup[256];
char mealIdLookup[30];
char mealNameLookup[256];

char fname[30];
char lname[30];
char job[30];
char meal[30];
int servings;
int table;

int jobId;
int mealId;

float cost;
float Gross;
float Tcost;
float discount;
float Tax=0.08;
float Vat;

//Job Info
void jobmenu()
{
	if (strcmp(job, "A") == 0)
	{
		strcpy_s(jobIdLookup, 30, job);
		strcpy_s(jobNameLookup, 256, "Astronaut");
		jobId = 1;
	}

	if (strcmp(job, "S") == 0)
	{
		strcpy_s(jobIdLookup, 30, job);
		strcpy_s(jobNameLookup, 256, "Science");
		jobId = 2;
	}

	if (strcmp(job, "P") == 0)
	{
		strcpy_s(jobIdLookup, 30, job);
		strcpy_s(jobNameLookup, 256, "Public Relations");
		jobId = 3;
	}


}

//meal info
void mealmenu()
{

	if (strcmp(meal, "D") == 0)
	{
		strcpy_s(mealIdLookup, 30, meal);
		strcpy_s(mealNameLookup, 256, "Date cake");

	}

	if (strcmp(meal, "B") == 0)
	{
		strcpy_s(mealIdLookup, 30, meal);
		strcpy_s(mealNameLookup, 256, "Beef sandwich");

	}

	if (strcmp(meal, "C") == 0)
	{
		strcpy_s(mealIdLookup, 30, meal);
		strcpy_s(mealNameLookup, 256, "Cheese sandwich");

	}

	if (strcmp(meal, "S") == 0)
	{
		strcpy_s(mealIdLookup, 30, meal);
		strcpy_s(mealNameLookup, 256, "Strawberry dessert");

	}

}

void MAY() {
	if ((strcmp(fname, "RUBENS") == 0) && (strcmp(lname, "MAY") == 0) && (strcmp(job, "S") == 0) && (strcmp(meal, "D") == 0)) {
		jobId = 4;
		discount = 0;
		Tax = 0;
		Tcost = 0;
	}
}

//printing table
void Table() 
{
	printf_s("---------------------------------\n");
	printf_s("\nName     : %s", lname);
	printf_s("\nJob Section     : %s", jobNameLookup);
	printf_s("\nMeal     : %s", mealNameLookup);
	printf_s("\nServings: %d", servings);
	printf_s("\nTable number: %d", table);
}

//Input Job
void jobenquiry() {
	printf_s("Job section\n");
	printf_s("A- Astronaut\n");
	printf_s("S- Science\n");
	printf_s("P-Public Relations\n");
	printf_s("E-Exit program\n");
	do{
	printf_s("Enter a selection:\n");
	fseek(stdin, 0, SEEK_END);
	scanf_s("%c", &job);
	strupr(job);
	if (strcmp(job, "E") == 0)
	{
		exit(0);
	}

	if ((strcmp(job, "E") != 0) && (strcmp(job, "A") != 0) && (strcmp(job, "S") != 0) && (strcmp(job, "P") != 0)) {
		printf("\nError - must be one of E,A,S,P\n\n");
	}
	}

	while ((strcmp(job, "E") != 0) && (strcmp(job, "A") != 0) && (strcmp(job, "S") != 0) && (strcmp(job, "P") != 0));
}

//Input meal
void mealenquiry() {
	printf_s("Input the meal you want from the following menu: \n");
	printf_s("D- Date cake\n");
	printf_s("B- Beef sandwich\n");
	printf_s("C- Cheese sandwich\n");
	printf_s("S- Strawberry desert\n");
	printf_s("E- Exit program\n");
	do {
		printf_s("Enter selection: \n");
		fseek(stdin, 0, SEEK_END);
		scanf_s("%c", &meal);
		strupr(meal);


		if (strcmp(meal, "E") == 0)
		{
			exit(0);
		}

		if ((strcmp(meal, "E") != 0) && (strcmp(meal, "D") != 0) && (strcmp(meal, "S") != 0) && (strcmp(meal, "B") != 0) && (strcmp(meal, "C") != 0)) {
			printf("\nError - must be one of E.D.S.B.C\n\n");
		}
	}

	while ((strcmp(meal, "E") != 0) && (strcmp(meal, "D") != 0) && (strcmp(meal, "S") != 0) && (strcmp(meal, "B") != 0) && (strcmp(meal, "C") != 0));

	//Jane Tully
	if ((strcmp(fname, "JANE") == 0) && (strcmp(lname, "TULLY") == 0) && (strcmp(meal, "S") == 0)) {
		printf("\nError %s that's not in your diet ", fname);
		printf("\nEnding Now");
		mealenquiry();
	}
	
	

}

//processing order
void order() {
	do {
		printf_s("Enter the number of servings(1 to 12):\n");
		fseek(stdin, 0, SEEK_END);
		scanf_s("%d", &servings);

		if (servings <= 0) {
			exit(0);
		}

		if (servings > 12) {
			printf("***Error Invalid amount***");
		}
	}

	while (servings < 1 || servings > 12);
}

//input table number
void tableNo() {
	do {
		printf_s("Which table are you at(1 to 32):\n");
		fseek(stdin, 0, SEEK_END);
		scanf_s("%d", &table);

		if (table <= 0) {
			exit(0);
		}

		if (table > 32) {
			printf("***Error Invalid amount***");
		}
	}

	while (table < 1 || table > 32);
}

//Invoice
void invoice() {
	//Job
	if (strcmp(job, "A") == 0) {
		strcpy_s(job, 30, "Astronaut");
		jobId = 1;
		if (strcmp(meal, "D") == 0) {
			cost = 1.0;
		}
		else if (strcmp(meal, "S") == 0) {
			cost = 1.0;
		}
		else if (strcmp(meal, "B") == 0) {
			cost = 0.0;
		}
		else if (strcmp(meal, "C") == 0) {
			cost = 0.0;
		}
	}

	if (strcmp(job, "S") == 0) {
		strcpy_s(job, 30, "Science");
		jobId = 2;
		if (strcmp(meal, "D") == 0) {
			cost = 5.0;
		}
		else if (strcmp(meal, "S") == 0) {
			cost = 7.41;
		}
		else if (strcmp(meal, "B") == 0) {
			cost = 5.50;
		}
		else if (strcmp(meal, "C") == 0) {
			cost = 4.90;
		}
	}

	if (strcmp(job, "P") == 0) {
		strcpy_s(job, 30, "Public Relations");
		jobId = 3;
		if (strcmp(meal, "D") == 0) {
			cost = 6.0;
		}
		else if (strcmp(meal, "S") == 0) {
			cost = 7.50;
		}
		else if (strcmp(meal, "B") == 0) {
			cost = 6.5;
		}
		else if (strcmp(meal, "C") == 0) {
			cost = 7.0;
		}
	}

	

//getting info from meal info
mealmenu();

//astronaut
if (jobId == 1) {
	Gross = cost*servings;
	Tax = 0;
	if (servings >= 3) {
		discount = Gross*0.05;
		Tcost = Gross - discount;
	}
	else {
		discount = 0;
		Tcost = Gross;
	}

}

//science
if (jobId == 2) {
	Gross = cost*servings;
	Tax = 0;

	if (servings >= 3) {
		discount = Gross*0.05;
		Tcost = Gross - discount;
	}
	else {
		discount = 0;
		Tcost = Gross;
	}
}

//public relations
if (jobId == 3) {
	Gross = cost*servings;
	if (servings >= 3) {
		discount = (Gross*0.05);
		Tax = (Gross - discount)*0.08;
		Tcost = Gross - discount + Tax;
	}
	else {
		discount = 0;
		Tax = Gross*0.08;
		Tcost = Gross + Tax;
	}
}

if (jobId=4){
	void MAY();
}





//table 
printf_s("----------------------------------------------------\n");
printf_s("\nName            : %s%5s", fname,lname);
printf_s("\nJob Section     : %s", job);
printf_s("\nMeal            : %s", mealNameLookup);
printf_s("\nServings        : %d", servings);
printf_s("\nTable number    : %d", table);

//printf_s("\nProduct Cost: %d", &servings);


printf_s("\nProduct Cost   : %.2f", cost);
printf_s("\nGross Cost     : %.2f", Gross);
printf_s("\nDiscount       : %.2f", discount);
printf_s("\nTax            : %.2f", Tax);
printf_s("\nTotal Cost     : %.2f\n", Tcost);
printf_s("----------------------------------------------------\n");

if (strcmp(job, "Astronaut") == 0)
{
	printf_s("----------------------------------------------------\n");
	printf("%s %5s Enjoy the good tucker\n", fname, lname);
	printf_s("----------------------------------------------------\n");
}

else if (strcmp(job, "Science") == 0)
{
	printf_s("----------------------------------------------------\n");
}
else if (strcmp(job, "Public Relations") == 0)
{
	printf_s("----------------------------------------------------\n");
}
printf("\n");
}

int main() {
	do {
		printf("\nWelcome to the Bake-off food system\n");
		printf("\nPlease input your name: ");
		fseek(stdin, 0, SEEK_END);
		scanf_s("%s %5s", fname, 30, lname, 30);
		strupr(fname);
		strupr(lname);
        jobenquiry();
		jobmenu();
		mealenquiry();
		mealmenu();
		order();
		tableNo();
		invoice();
		

		
	}
//}

 while (strcmp(meal,"E")!=0 ); 

_getch();
return 0;
}
