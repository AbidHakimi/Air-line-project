#include<iostream>
#include<iomanip> //for spaces that we are providing by setw etc
#include<string>
using namespace std;

//using structure:
struct passenger
{
	char f_name[20]; //FIRST NAME
	char l_name[20]; // LAST NAME
	char email[20]; // EMAIL
	char address[20];
	char password[20];
	int p_no; //passport number
	int ticketno;

};
//2D array of characters
char local[5][20] = { "ISLAMABAD", "KARACHI", "PESHAWAR", "QUETTA", "LAHORE" }; 
char international[8][20] = { "MAKKAH", "PARIS", "LONDON", "MUNICH", "DUBAI", "JEDDAH", "MUMBAI", "MADRID" };

//Function Prototyping:
void display();//Welcome message
void local_menu(); //choosing the airline for local flights
void inter_menu(); //choosing the airline for international flights
void data(); //takes name,email,passport no, password, address
void lsearch();//location searching or error handling for check
void dsearch();//destination searching or error handling for check
void locate();//your current location
void all();//having multiple fuctions and also a pattern for it
void destine();//flights available for destination
void seatselect();//Economy or Buisness Class? Which seat noo?
void time();//time preference for your flight
void displayTicket();//displaying your info entered and ticket booked
void passport();//asking for your 8-digit Passport number
void seatNo();//enter your seat no

//initializing values that will further be used
int ecseat[270]; //number of seats in economy class
int bzseat[30]; //number of seats in buisness class
char seat;
int f;
char ans[5];
double g;
int i = 0; //current passenger
int choice; //inputs main menu choice
int h = 0;
int seatno;
int achoice; //stores airline choosing data for both local & intl
char pass[20];
passenger x[300];
char location[20];
char destination[20];
int tt;
int ticket;
int ticketUpdate = 1000;
int chooseTime;

//Functions used:
int generateTicket() {
	return ticketUpdate++; //returns existing value, then updates
}

void bzSeatsInit()
{
	for (int i = 0; i < 30; i++) 
	{
		bzseat[i] = 1; //initializing available seats

	}
}
void ecoSeatsInit()
{
	for (int i = 0; i < 270; i++)
	{
		ecseat[i] = 1; //initializing available seats
	}
}
void bzSeatsUpdate(int seatno)
{
	bzseat[seatno - 1] = 0; //updating available seats & 0 means the seat is unavailable so it cannot be occupied again
}
void ecoSeatsUpdate(int seatno)
{
	bzseat[seatno - 1] = 0;//updating available seats
}
void destine()
{
	cout << "Only taking Flights to:\n";
	if (choice == 1)
	{
		cout << "\nISLAMABAD\nKARACHI\nPESHAWAR\nQUETTA\nLAHORE\n";
	}
	else
	{
		cout << "\nMAKKAH\nPARIS\nLONDON\nMUNICH\nDUBAI\nJEDDAH\nMUMBAI\nMADRID";
	}
	cout << endl << "Enter your destination city (in capital letters)  ";
	cin >> destination;
	dsearch(); //destination searching or error handling for check 
}
void locate()
{
	cout << "\nSelect your current location:\n";
	if (choice == 1) //local
	{
		cout << "\nISLAMABAD\nKARACHI\nPESHAWAR\nQUETTA\nLAHORE\n";
	}
	else //international
	{
		cout << "\nMAKKAH\nPARIS\nLONDON\nMUNICH\nDUBAI\nJEDDAH\nMUMBAI\nMADRID";
	}
	cout << endl << "Enter your city (in capital letters)  "; 
	cin >> location;
	lsearch(); //location searching or error handling for check
}
void lsearch() //location searching or error handling for check
{
	int found = 0;
	for (int i = 0; i <= 4; i++)
	{
		if (choice == 1) //local
		{
			if ((strcmp(location, local[i]) == 0))
				found++;
			else;
		}
		else;
	}
	for (int i = 0; i <= 7; i++) //intl
	{
		if (choice == 2)
		{
			if (strcmp(location, international[i]) == 0)
				found++;
			else;
		}
	}
	if (found == 0)
	{
		cout << "This city is not available. Please enter from the cities listed.\n";
		locate();
	}
	else;
}
void data() //takes name,email,passport no, password, address
{

	x[i].ticketno = generateTicket();
	//using pointers: stores the adress of data type
	int* p;
	p = &x[i].ticketno; //pass by reference, as we know and proved from function that x[i].ticketno = 1000
	tt = *p;

	cout << "Your ticket number is : " << tt << endl;
	cout << endl << "Enter first name :  ";
	cin >> x[i].f_name;
	cout << endl << "Enter last name : ";
	cin >> x[i].l_name;
	cout << endl << "Enter your email : ";
	cin >> x[i].email;
	cout << endl << "Set password: ";
	cin >> x[i].password;

	passport();
	while (x[i].p_no <10000000 || x[i].p_no > 99999999) //error handling for less than 8 digits or more than 8 digits
	{
		cout << "INVALID PASSPORT NUMBER.";
		passport();
	}
	cout << endl << "Enter full address ";
	cin >> x[i].address;
	locate();
	destine();

}
void passport()
{
	cout << endl << "Enter passport number (8 digits)  ";
	cin >> x[i].p_no;

}
void inter_menu() //choosing the airline for international flights
{
	cout << endl << "Choose the airline in which you want to travel\n";
	cout << "1) Qatar Airlines\n2) PIA\n3) Saudi Airlines\n4) Thai Airways\nEnter your choice ";
	cin >> achoice;
}
void local_menu() //choosing the airline for local flights
{
	cout << endl << "Choose the airline in which you want to travel\n";
	cout << "1) PIA\n2) Shaheen Airlines\n3) Serene Air\n4)Air Blue\nEnter your choice ";
	cin >> achoice;
}
void display() //Welcome message
{
	cout << "" << setw(79) << setfill('c') << "*" << endl << endl;
	cout << "\t\t\tWELCOME TO OUR AIRLINE RESERVATION SYSTEM\n\n"; //\t= 8 spaces
	cout << "" << setw(79) << setfill('c') << "*" << endl << endl;
}
void menu() //main menu for user
{

	cout << "\n1) Local Travelling\n2) International Travelling\n3) Check Your Ticket\n4) EXIT\n\n";
	cout << "ENTER YOUR CHOICE ";
	cin >> choice;
} //will go back to all()

void dsearch()
{
	int found = 0;
	for (int i = 0; i <= 4; i++)
	{
		if (choice == 1)
		{
			if ((strcmp(destination, local[i]) == 0))
				found++;
			else;
		}
		else;
	}
	for (int i = 0; i <= 7; i++)
	{
		if (choice == 2)
		{
			if (strcmp(destination, international[i]) == 0)
				found++;
			else;
		}
	}
	if (found == 0)
	{
		cout << "This city is not available. Please enter from the cities listed.\n";
		destine();
	}
	else;
}
void seatNo()
{
	cout << endl << "Enter your desired seat number:"; 
	cin >> seatno;
}
void seatselect()
{
	do
	{
		cout << "\t\t\tEnter B for buisiness class\n\t\t\tEnter E for economy class  " << endl;
		cin >> seat;
		if ((seat == 'b') || (seat == 'B'))
		{
			cout << endl << "These are the total avaiable seats in Buisiness class:" << endl;
			for (int i = 0; i < 30; i++) {
				if (bzseat[i] == 1) {
					cout << "Seats Number: " << i + 1 << endl;
				}
			}
			seatNo();
			if (seatno < 1 || seatno>30)
			{
				cout << "Enter VALID seat number!";
				seatNo();
			}
			bzSeatsUpdate(seatno);

		}
		else if ((seat == 'e') || (seat == 'E'))
		{
			cout << endl << "These are the total avaiable seats in Economy class:" << endl;
			for (int i = 0; i < 270; i++) {
				if (ecseat[i] == 1) {
					cout << "Seats Number: " << i + 1 << endl;
				}
			}
			seatNo();
			if (seatno < 1 || seatno>270) 
			{
				cout << "Enter VALID seat number!";
				seatNo();
			}
			ecoSeatsUpdate(seatno);
		}
		else
			cout << " ENTER VALID CHARACTER " << endl;
	} while ((seat != 'e') && (seat != 'E') && (seat != 'b') && (seat != 'B'));

}
void timeInput()
{

	cout << "\nON WHICH TIME YOU WANT TO TRAVEL" << endl;
	cout << "PRESS 1 FOR 11 AM" << endl;
	cout << "PRESS 2 FOR 10 AM" << endl;
	cout << "PRESS 3 FOR 9 AM" << endl;
	cin >> chooseTime;
	
}
void time()
{

	do {
		timeInput();

		if (chooseTime == 1)
		{
			cout << "|                                                                         " << endl;
			cout << "|Flight time 11 AM                                                        " << endl;
			cout << "|_________________________\n" << endl;
			cout << "                  GOOD BYE AND HAVE A SAFE JOURNEY                        " << endl;

		}
		else if (chooseTime == 2)
		{
			cout << "|                                                                         " << endl;
			cout << "|flight time 10 AM                                                        " << endl;
			cout << "|_________________________\n" << endl;
			cout << "                  GOOD BYE AND HAVE A SAFE JOURNEY                        " << endl;

		}
		else if (chooseTime == 3)
		{
			cout << "|                                                                         " << endl;
			cout << "|flight time 9 AM                                                        " << endl;
			cout << "|_________________________\n" << endl;
			cout << "                  GOOD BYE AND HAVE A SAFE JOURNEY                        " << endl;

		}
		else
		{
			cout << "Invalid Input\n";
			timeInput();
		}
	} while (!(chooseTime == 1 || chooseTime == 2 || chooseTime == 3));
}


void checkTicket()
{
	bool flag = true;
	cout << "Enter Ticket Number : ";
	cin >> ticket;
	//error handling
	for (int j = 0; j <= i; j++)
	{
		if (ticket == x[j].ticketno)
		{
			cout << "VALID\n";
			flag = false;
		}

	}
	if (flag)
	{
		cout << endl << "Invalid Ticket" << endl;
		all();
	}

	cout << "Enter your password: ";
	cin >> pass;
	flag = true;
	for (int j = 0; j <= i; j++)
	{
		if (strcmp(pass, x[j].password) == 0)
		{
			flag = false;
			cout << "VALID\n";

			cout << endl << "Your E-Ticket is :" << endl;

			cout << endl << "                           AIRLINE TICKET                                 " << endl;
			cout << "|Ticket No." << x[j].ticketno << endl;
			cout << "|_________________________" << endl;
			cout << "|PASSPORT No. :" << x[j].p_no << "                                     " << endl;
			cout << "|__________________________" << endl;
			cout << "|Passenger Information                                                  " << endl;
			cout << "|Name :" << x[j].l_name << "/" << x[i].f_name << "                                     " << endl;
			cout << "|Email :" << x[j].email << "                                                             " << endl;
			cout << "|Address :" << x[j].address << "                                                   " << endl;
			cout << "|_________________________" << endl;
			cout << "|Flight Information :                                                     " << endl;
			cout << "|30 MAY 2022                                                              " << endl;
			cout << "|BOEING 747                                                                " << endl;
			cout << "|_________________________" << endl;
			cout << "|*BAGGAGE allowed 44 Kilos                                                " << endl;
			cout << "|*contact Airline to confirm baggage allowance                            " << endl;
			cout << "|_________________________" << endl;

		}
		
	}
	if (flag)
	{
		cout << endl << "Invalid Password" << endl;
		all();
	}

}


void displayTicket()
{

	cout << setw(40) << "Your E-Ticket is :" << endl;

	cout << endl << "                           AIRLINE TICKET                                 " << endl;
	cout << "|Ticket No." << x[i].ticketno << endl;
	cout << "|_________________________" << endl;
	cout << "|PASSPORT No. :" << x[i].p_no << "                                     " << endl;
	cout << "|__________________________" << endl;
	cout << "|Passenger Information                                                  " << endl;
	cout << "|Name :" << x[i].l_name << "/" << x[i].f_name << "                                     " << endl;
	cout << "|Email :" << x[i].email << "                                                             " << endl;
	cout << "|Address :" << x[i].address << "                                                   " << endl;
	cout << "|_________________________" << endl;
	cout << "|Flight Information :                                                     " << endl;
	cout << "|30 May 2022                                                              " << endl;
	cout << "|BOEING 747                                                                " << endl;
	cout << "|_________________________" << endl;
	cout << "|*BAGGAGE allowed 44 Kilos                                                " << endl;
	cout << "|*contact Airline to confirm baggage allowance                            " << endl;
	cout << "|_________________________" << endl;

}

void all()

{
	do
	{
		menu();    //choose from menu
		while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4))
		{
			cout << endl << "Enter the RIGHT choice please\n";
			menu(); 
		}		

		if (choice == 1)
			local_menu(); //local flight
		else if (choice == 2)
			inter_menu(); //international flight
		else if (choice == 3) //checking ticket
			checkTicket();
		else
		{
			cout << "Thank you for using our AIRLINE RESERVATION SYSTEM";
			exit(100); //terminating the whole program

		}

		while ((achoice != 1) && (achoice != 2) && (achoice != 3) && (achoice != 4))
		{
			cout << endl << "Please enter a VALID airline.\n";
			if (choice == 1) //checking whether user selected local menu
				local_menu();
			else if (choice == 2)
				inter_menu();
			else;
		};
				
		//taking data from passenger
		cout << endl << endl << "\t\tENTER PASSENGER DATA\n\n";
		data(); //takes name,email,passport no, password, address
		cout << endl << endl << "Flight is available for this route\n\n";
		seatselect(); //shows seats and allows passenger to select one
		time(); //flight time choice
		displayTicket();
		cout << "Do you want to go back to the MENU?" << endl << "YES" << endl << "NO";
		cout << "\nIf Yes type YES\tIf No type NO\n";
		cin >> ans;
		i++; //passenger no
	} while (strcmp(ans, "NO") != 0);
	cout << "Thank you for using our AIRLINE RESERVATION SYSTEM\n\n";
}

int main()
{
	bzSeatsInit(); //initializing seats buisness class
	ecoSeatsInit(); //initializing seats economical class

	display(); //welcome
	all();

	system("pause");
	return 0;
}