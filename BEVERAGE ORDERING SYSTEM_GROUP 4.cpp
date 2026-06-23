#include <iostream>	// Declare the basic c++ streams i/o routines
#include <iomanip>	// Declare setiosflags(ios::fixed), setprecision, setw, setfill
#include <string.h>	// Combine first name and last name of a string
#include <fstream>	// Contain information for performing file i/o operations
#include <cmath>	// Use ceil function to round up the number

float total(float sum, float disc, float delcharge); // Prototype declaration to calculate total

using namespace std;

struct detailPhone	// A collection of phone number
{
	int phoneNum;	// Declare phone number as integer datatype
};

int main()
{
	char myText ;	// Declare myText as char datatype
	// Declare and open text file (Schedule Cafe)
	ifstream MyReadFile;
	MyReadFile.open("storeCafe.txt");

	while (!MyReadFile.eof())	// Do until the end of file
	{
		//Get every char in input file (myInput) and store in myText
		MyReadFile.get(myText);	// Get character from file
		cout << myText;	// Display the character on screen
	};
	
	cout << "\n\n";	// Create newline
	
	int cupNum, i=1, x;	// Declare number of cup
	char cupSize, drinkType, coffeeType, teaType, milkType, drinkTemp, member, delivery, name1[20], name2[20];
	float cupPrice, drinkPrice, totalPrice, disc, sum=0, tempCharge, delCharge, totalPurchase;
	string greet[7] = {"H", "E", "L", "L", "O", " ", "!"};
	
	cout << "\n\t\t";
	for(x=0; x<7; x++)
	{
		cout << greet[x];	// Display greeting using 1D array
	}
	cout << endl;
	cout << "\nWelcome to The Diamond Beverage Ordering System" << endl; //Customer Greeting
	cout << "\nEnter your first name: ";
	cin.getline(name1,20);	// To enter user's first name 
	cout << "Enter your last name: ";
	cin.getline(name2,20);	// To enter user's second name 
	strcat(name1, name2);	// Combine user's first name and last name of a string
	
	detailPhone *ptr, d;
	ptr = &d;
	cout << "Enter phone number: ";
	cin >> (*ptr).phoneNum;	// To enter user's phone number
	
	cout << "\nEnter your number of order: ";
	cin >> cupNum;	// To enter the number of cup that insert by user
	
	while(i <= cupNum)	// It will repeat based on number of cup that insert by user if it greater than or equal to i
	{
		do
		{
		cout << "\nOrder " << i << endl;
		cout << "-------" << endl;
		// User choose size of cup
		cout << "\nChoose your cup size: " << endl;
		cout << "S: Small (RM 0.50)" << endl;
		cout << "M: Medium (RM 1.00)" << endl;
		cout << "L: Large (RM 1.50)" << endl;
		cin >> cupSize;
	
		switch(cupSize)	// Use switch to determine the details of different price size of cup
		{
			case 'S' :
			case 's' : 
				cupPrice = 0.50;
				break;
			case 'M' :
			case 'm' : 
				cupPrice = 1.00;
				break;
			case 'L' :
			case 'l' : 
				cupPrice = 1.50;
				break;
			default :
				cout << "\nInvalid Cup Size!" << endl;	// Display invalid message if user enter the wrong code. It will ask user to enter the code again until true code
				cout << "Please insert valid cup size" << endl;
				cout << setw(29) << setfill('-') << " " << endl;	// Display - for decoration
		}
		}
		while(cupSize != 'S' && cupSize != 's' && cupSize != 'M' && cupSize != 'm' && cupSize != 'L' && cupSize != 'l');

		
		do{
		cout << "\nChoose your type of drink: " << endl;	// User choose type of drink
		cout << "M : Milk" << endl;
		cout << "C : Coffee" << endl;
		cout << "T : Tea" << endl;
		cin >> drinkType;
	
		if(drinkType == 'C' || drinkType == 'c')
		{
			do{
			cout << "\nChoose your coffee type: " << endl;	// User choose type of coffee
			cout << "L : Latte (RM 3.20)" << endl;
			cout << "C : Cappucino (RM 3.50)" << endl;
			cout << "A : Americano (RM 3.80)" << endl;
			cin >> coffeeType;
		
			switch (coffeeType)
			{
				case 'L' :
				case 'l' :
					drinkPrice = 3.20;
					break;
				case 'C' :
				case 'c' :
					drinkPrice = 3.50;
					break;
				case 'A' :
				case 'a' :
					drinkPrice = 3.80;
					break;
				default :
					cout << "\nInvalid Coffee Type!" << endl;
					cout << "Please insert valid coffee type" << endl;
					cout << setw(32) << setfill('-') << " " << endl;
			}
			}
			while(coffeeType != 'L' && coffeeType != 'l' && coffeeType != 'c' && coffeeType != 'C' && coffeeType != 'A' && coffeeType != 'a');
		}
	
		else if (drinkType == 'T' || drinkType == 't')
		{
			do{
			cout << "\nChoose your tea type: " << endl;	// User choose type of tea
			cout << "L : Lemon Tea (RM 2.50)" << endl;
			cout << "T : Tea (RM 2.00)" << endl;
			cout << "M : Milk Tea (RM 2.30)" << endl;
			cin >> teaType;
		
			switch (teaType)
			{
				case 'L' :
				case 'l' :
					drinkPrice = 2.50;
					break;
				case 'T' :
				case 't' :
					drinkPrice = 2.00;
					break;
				case 'm' :
				case 'M' :
					drinkPrice = 2.30;
					break;
				default :
					cout << "\nInvalid Tea Type!" << endl;
					cout << "Please insert valid tea type" << endl;
					cout << setw(29) << setfill('-') << " " << endl;
			}
			}
			while(teaType != 'L' && teaType != 'l' && teaType != 'T' && teaType != 't' && teaType != 'M' && teaType != 'm');
		}
	
		else if (drinkType == 'M' || drinkType == 'm')
		{
			do{
			cout << "\nChoose your milk type: " << endl;	// User choose type of milk
			cout << "C : Chocolate (RM 2.70)" << endl;
			cout << "B : Banana (RM 3.20)" << endl;
			cout << "S : Strawberry (RM 3.50)" << endl;
			cin >> milkType;
		
			switch (milkType)
			{
				case 'C' :
				case 'c' :
					drinkPrice = 2.70;
					break;
				case 'B' :
				case 'b' :
					drinkPrice = 3.20;
					break;
				case 'S' :
				case 's' :
					drinkPrice = 3.50;
					break;
				default :
					cout << "\nInvalid Milk Type!" << endl;
					cout << "Please insert valid milk type" << endl;
					cout << setw(30) << setfill('-') << " " << endl;
			}
			}
			while(milkType != 'C' && milkType != 'c' && milkType != 'B' && milkType != 'b' && milkType != 'S' && milkType != 's');
		}
	
		else
		{
			cout << "\nInvalid type of drink!" << endl;
			cout << "Please insert valid drink type" << endl;
					cout << setw(31) << setfill('-') << " " << endl;
		}
		}
		while(drinkType != 'M' && drinkType != 'm' && drinkType != 'c' && drinkType != 'C' && drinkType != 'T' && drinkType != 't');
	
		do{
		cout << "\nChoose your drink temperature: " << endl; // User choose temperature of drink
		cout << "H : Hot (RM 0.50)" << endl;
		cout << "N : Normal (RM 0.80)" << endl;
		cout << "C : Cold (RM 1.00)" << endl;
		cin >> drinkTemp;
	
		if(drinkTemp == 'H' | drinkTemp == 'h')
		{
			tempCharge = 0.50;
		}
		else if(drinkTemp == 'N' | drinkTemp == 'n')
		{
			tempCharge = 0.80;
		}
		else if(drinkTemp == 'C' | drinkTemp == 'c')
		{
			tempCharge = 1.00;
		}
		else
		{
			cout << "\nInvalid drink temprerature" << endl;
			cout << "Please insert valid drink temperature" << endl;
			cout << setw(38) << setfill('-') << " " << endl;
		}
		}
		while(drinkTemp != 'H' && drinkTemp != 'h' && drinkTemp != 'c' && drinkTemp != 'C' && drinkTemp != 'N' && drinkTemp != 'n');
		
		// Display all the details of each cup
		cout << "\nCup Number: " << i << endl;
		cout << "Cup size: " << cupSize << endl;
		cout << "Drink Type: " << drinkType << endl;
		cout << "Drink Temperature: " << drinkTemp << endl;
		totalPrice = cupPrice + drinkPrice + tempCharge;	// Calculate the price of each cup before discount
		sum = sum + totalPrice;	// Add the total price of all cup that insert by user
		++i;
	}
	
	do{
	cout << "\nAre you a membership ? Y=Yes / N=No" << endl;
	cin >> member;	// User insert whether they are a membership or not
	// User insert code Y if they are membership
	if(member=='Y' || member=='y')
	{
		disc = sum*0.12;	// Discount will be provided if user is a member
	}
	// User insert code N if they are not membership
	else if (member=='N' || member=='n')
	{
		disc = sum*0.0;	// Discount will not be provided if user is not a member
	}
	else
	{
		cout << "\nInvalid input code!" << endl;
		cout << "Please insert valid code" << endl;
		cout << setw(25) << setfill('-') << " " << endl;
	}
	}
	while(member != 'Y' && member != 'y' && member != 'N' && member != 'n');
	
	do{
	cout << "\nDo you want to pick up or cod? Pick up=P / Cod=C" << endl; //User choose type of delivery
	cout << "Pick up = Free" << endl;
	cout << "Cod = RM 5" << endl;
	cin >> delivery;	// User enter the code type of delivery
	// User insert code P if they want to pick up and no additional charge provided
	if(delivery=='p'|| delivery=='P')
	{
		delCharge = 0.0;
	}
	// User insert code C if they want to COD and additional charge provided
	else if(delivery=='C' || delivery=='c')
	{
		delCharge = 5.0;
	}
	else
	{
		cout << "\nInvalid input code!" << endl;
		cout << "Please insert valid code" << endl;
		cout << setw(25) << setfill('-') << " " << endl;
	}
	}
	while(delivery != 'P' && delivery != 'p' && delivery != 'C' && delivery != 'c');
	
	system("cls");	// Clear the previous screen
	// Generate bill for customer
	system("color 3");	// Change the text color to blue
	{
		cout << "\n\t\t" << setw(60) << setfill('*') << " " << endl;
	}
	cout << "\n\t\t" << setw(60) << setfill('-') << " " << endl;
	cout << "\n\t\t\t\tDIAMOND BEVERAGE ORDERING SYSTEM" << endl;
	cout << "\n\t\t" << setw(60) << setfill('-') << " " << endl;
	cout << "\n\t\t\tHello " << name1 << endl;
	cout << "\n\t\t\tPhone number = " << (*ptr).phoneNum << endl;
	cout << "\t\t\tThe Quantity of Your Order: " << cupNum << endl;
	cout << "\t\t\tYour Delivery Chosen [Pick Up (P) / COD (C)]: " << delivery << endl;
	// Function call
	cout << "\t\t\tTotal Price of Your Order: RM " << setiosflags(ios::fixed) << setprecision(2) << ceil(total(sum, disc, delCharge)) << endl;	// Round up the number
	
	cout << "\n\t\t\t";
	string cGreet[13][15] = {"T","H","A","N","K"," ","Y","O","U"," ","F","O","R"," ","O","R","D","E","R","I","N","G","!"};	// Display closing greeting using 2D array
	for(int a=0; a<13; a++)
	{
		for(int b=0; b<15; b++)
		{
			cout << cGreet[a][b];
		}
	}
	
	cout << endl;
	cout << "\t\t\tPLEASE COME AGAIN LATER :)" << endl;
	
	cout << "\n\t\t" << setw(60) << setfill('*') << " " << endl;
	cout << "\n\n\n\n\n\n\n\n";
	
	return 0;
}

float total(float sum, float disc, float delCharge)	// Function Definition: Funtion to calculate total order after discount
{
	float totalPurchase;
	totalPurchase = sum - disc + delCharge;
	return totalPurchase;		
}
