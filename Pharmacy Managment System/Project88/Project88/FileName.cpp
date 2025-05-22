#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include <chrono>
#include <thread>
#include<algorithm>
#include<fstream>
#include<conio.h>
#include <Windows.h>
#define size_medicine 11
#define size_custmer 10
using namespace std;
int const Max_selected = 10;
int current_index = 0;
char choice;
int n;
int i = 4;
int l01 = 0, index01 = 0;
string name01;
bool x01;
char c01;
int complaintscounter = 0;
char c02;
char c03;
int option = 0;
short bb = 0;
int arr0x[10][3];
int pre[10] = {};
int ind[10];
fstream m_file;
fstream f_cust;
struct user
{
	string user_name;
	string email;
	string password[2];
	string address;
	string phone;
	int id;
	int ways_of_payement = 3;
	int counter = 0;
	int usercancel = 0;
	string complaint[2];
};
struct date {
	int year;
	int month;
	int day;
}date[Max_selected];
struct medicine {
	int id;
	string name;
	string category;
	string description;
	float price;
	int quantity_in_stock;
};
struct orders
{
	int id;
	string name;
	string category;
	string description;
	float price;
	int quantity_ordered;
	float total_price = 0;
	float total;
	int datey, datem, dated, shipy, shipm, shipd, timeh, timem, times;
	string m;

}list_of_medcines_IDs[Max_selected][10];
medicine med[size_medicine]/*{
{15432,"aspirin", "pain reliever", "Used to relieve pain, fever, and inflammation", 40.50, 80},
{28726,"ibuprofen", "anti-inflammatory", "Used to relieve pain, fever, and inflammation", 70.25, 120},
{39173,"acetaminophen", "pain reliever", "Used to relieve mild to moderate pain and reduce fever", 60.00, 90},
{42652,"naproxen", "anti-inflammatory", "Used to relieve pain, inflammation, and stiffness caused by arthritis", 80.20, 70},
{52134,"diphenhydramine", "antihistamine", "Used to relieve symptoms of allergies, hay fever, and the common cold", 90.80, 60},
{63454,"loratadine", "antihistamine", "Used to relieve symptoms of allergies, hay fever, and the common cold", 70.50, 85},
{73423,"omeprazole", "proton pump inhibitor", "Used to reduce stomach acid and treat conditions such as heartburn, gastroesophageal reflux disease (GERD), and stomach ulcers", 12.30, 45},
{84355,"simvastatin", "statins", "Used to lower cholesterol levels and reduce the risk of heart disease",10.50, 55},
{94555,"metformin", "antidiabetic", "Used to treat type 2 diabetes by controlling blood sugar levels", 80.75, 70},
{10234,"levothyroxine", "thyroid hormone", "Used to treat an underactive thyroid (hypothyroidism)", 60.90, 80},
{11234 ,"paracetamol", "pain reliever", "Used to relieve pain and fever", 50.75, 100 }
}*/;//menu intialized
user clinet[size_custmer]
{
	{"admin","admin@gmail.com","admin123","admin123","232es","01208450123",10000},
	{ "yousef","yousef@gmail.com","yousef123","yousef123","Qwd123mm","01101936639",10001 },
	{"ahmed","ahmed@gmail.com","ahmed123","ahmed123","dsksdc","0120845023",10002},
	{"doha","doha@gmail.com","doha1234","doha1234","efsfds","01101936639",10003}
};
string covert_to_lowercase(string text);
bool checkphone(string);
bool find_email(string email);
bool find_account(string email, string pass);
void sign_up();           //function of sign_up
void edit_information();
bool log_in();
void adding_new_medicine();
void search_for_medicine();
void orderdate();
void ordertime();
void ship_date();
void editing_quantity_of_medicine();
void editing_price_of_medicine();
void editing_name_of_medicine();
void editing_description_of_medicine();
void editing_category_of_medicine();
void editing_id_of_medicine();
void deleting_medicine();
void deleting_user();
void adding_users();
void editing_information_about_user();
void VisaPayment();
void cashpayment();
void pickUp_at_pharmacy();
void paymentMethod();
void editorder(char choice, float& total_price, int select);
void cancelorder(char choice, float& total_price, int& i);
void show_order_receipt(char choice, float total_price, int select);
void AddNewOrder();
void displayMenu();
void managing_ways_of_payment();
void displaying_ways_of_payement_for_user();
void previous();
void user_profile();
void admin_cancel_order();
void admin_edit_order();
void displayUsers();
void pre_order();
void reports();
void complaints();
void alerts();
void write_f_m();
void read_m();
int page_1();
int page__2();
int page_2();
void page1_user();
void page1_admin();
void signpage();
void adminManageOrders();
int main() {
	//cout << "\033[1;34m";
	//cout << "ok";
	read_m();
	signpage();
	if (clinet[current_index].user_name.find("admin") != -1)                      // All function for Admin
	{
		alerts();
		page1_admin();
	}
	else
	{
		page1_user();
	}
}                                                 //Definition of all function
string covert_to_lowercase(string text)
{
	transform(text.begin(), text.end(), text.begin(), tolower);
	return text;
}
bool checkphone(string phone) {
	for (char c : phone)
	{
		if (!isdigit(c))
			return true;

	}
	return false;
}
bool find_email(string email)
{

	for (int i = 0; i < size_custmer; i++)
	{
		if (email == clinet[i].email)
		{
			return true;
		}
	}
	return false;
}
bool find_account(string email, string pass)
{
	for (int i = 0; i < size_custmer; i++)
	{
		if (email == clinet[i].email && pass == clinet[i].password[0])
		{
			current_index = i;
			return true;
		}
	}
	return false;

}
void orderdate() {
	time_t curtm = time(NULL);
	tm* time = localtime(&curtm);
	cout << "order date is :  \t";
	cout << (time->tm_year + 1900) << ":";
	cout << (time->tm_mon + 1) << ":";
	cout << (time->tm_mday) << endl;
	list_of_medcines_IDs[current_index][clinet[current_index].counter].datey = time->tm_year + 1900;
	list_of_medcines_IDs[current_index][clinet[current_index].counter].datem = time->tm_mon + 1;
	list_of_medcines_IDs[current_index][clinet[current_index].counter].dated = time->tm_mday;
}
void ordertime() {
	time_t curtm = time(NULL);
	tm* time = localtime(&curtm);
	int hour = time->tm_hour;
	if (hour == 00)
		hour = 12;
	else if (hour > 12)
		hour -= 12;
	cout << "order time is :  \t";
	cout << (hour) << ":";
	cout << (time->tm_min) << ":";
	cout << (time->tm_sec) << "  ";
	if (hour < 12) {
		cout << "pm";
		list_of_medcines_IDs[current_index][clinet[current_index].counter].m = "pm";
	}
	else {
		cout << "am";
		list_of_medcines_IDs[current_index][clinet[current_index].counter].m = "am";
	}
	list_of_medcines_IDs[current_index][clinet[current_index].counter].timeh = hour;  //previous
	list_of_medcines_IDs[current_index][clinet[current_index].counter].timem = time->tm_min;
	list_of_medcines_IDs[current_index][clinet[current_index].counter].times = time->tm_sec;
}
void ship_date() {
	time_t curtm = time(NULL);
	tm* time = localtime(&curtm);
	int i = 0;
	date[i].year = time->tm_year + 1900;
	date[i].month = time->tm_mon + 1;
	date[i].day = time->tm_mday;
	cout << "\n Ship date is : \t";
	cout << "  " << date[i].year << "/";
	cout << date[i].month << "/";
	cout << date[i].day << endl;
	list_of_medcines_IDs[current_index][clinet[current_index].counter].shipy = time->tm_year + 1900; //previous
	list_of_medcines_IDs[current_index][clinet[current_index].counter].shipm = time->tm_mon + 1;
	list_of_medcines_IDs[current_index][clinet[current_index].counter].shipd = time->tm_mday;
	i++;
}
void sign_up()              //function of sign_up
{
	cout<<"\033[1;33m";
	string phone;
	cout << "#---------------------------------------------> WELCOME To The SignUp Page <-------------------------------------------#\n\n";
	cout << "\033[1;32m";
	cout << "enter your name\n";
	cout << "\033[1;0m";
	getline(cin, clinet[i].user_name);
	
	while (true)
	{

		string email;
		cout << "\033[1;32m";
		cout << "enter your email\n";
		cout << "\033[1;0m";
		cin >> email;
		if (email.find("@gmail.com") == -1) {                        //check that the email is vaild
			cout << "\033[1;31m";
			cout << "invalid email. eamil should have ( @gmail.com ) please write again\n";
			cout << "\033[1;0m";
			continue;
		}
		if (find_email(email))
		{
			cout << "\033[1;31m";
			cout << "This Email Already Exist please try again\n";
			cout << "\033[1;0m";
		}
		else
		{
			clinet[i].email = email;
			break;
		}
	}
	cout << "\033[1;32m";
	cout << "enter your adress\n";
	cout << "\033[1;0m";
	cin >> clinet[i].address;
	while (true)
	{
		cout << "\033[1;32m";
		cout << "enter your phone number\n";
		cout << "\033[1;0m";
		cin >> phone;

		if (phone.size() != 11) {   //check that phone number is 11 number
			cout << "\033[1;31m";
			cout << "invalid number phone. should 11 number \n";
			cout << "\033[1;0m";
			continue;
		}

		if (checkphone(phone))
		{
			cout << "\033[1;31m";
			cout << "phone Number should be Numbers Only\n";
			cout << "\033[1;0m";

		}
		else
			break;




	}
	clinet[i].phone = phone;


	clinet[i].id = rand() % 100000;
	while (true)
	{
		//system("cls");
		cout << "\033[1;32m";
		cout << "enter your password\n";
		cout << "\033[1;0m";
		char ch;
		string password;
		while ((ch = _getch()) != '\r') {  // Keep reading until Enter (carriage return) is pressed
			if (ch == '\b') {  // Handle backspace
				if (!password.empty()) {
					password.pop_back();
					cout << "\b \b";  // Move cursor back, print space to erase, then move back again
				}
			}
			else {
				password.push_back(ch);
				cout << '*';  // Echo '' instead of the actual character
			}
			clinet[i].password[0] = password;
		}
		cout << "\n";
		if (clinet[i].password[0].size() < 8)              //check that the password not weak
		{
			cout << "\033[1;31m";
			cout << "the password must have at least 8 digits\n";
			cout << "\033[1;0m";
			continue;
		}
		cout << "\033[1;32m";
		cout << "rewrite your password again\n";
		cout << "\033[1;0m";
		string password01;
		while ((ch = _getch()) != '\r') {  // Keep reading until Enter (carriage return) is pressed
			if (ch == '\b') {  // Handle backspace
				if (!password01.empty()) {
					password01.pop_back();
					cout << "\b \b";  // Move cursor back, print space to erase, then move back again
				}
			}
			else {
				password01.push_back(ch);
				cout << '*';  // Echo '' instead of the actual character
			}
			clinet[i].password[1] = password01;
		}
		cout << "\n";

		if (clinet[i].password[0] == clinet[i].password[1])
		{
			for (int i = 0;i < 3;i++)
			{
				cout << "\033[1;32m";
				cout << "Loading ";
				for (int j = 0;j < 5;j++)
				{
					cout << "." << " ";
					Sleep(200);
				}
				cout << "\r\r"<<flush;
			}
			cout << "\r\r" << flush;
			cout << "\033[1;0m";
			cout << "-------------------------> You Created account succsseflly.\n";
			Sleep(2500);
			system("cls");
			break;
		}
		else
		{
			cout << "\033[1;31m";
			cout << "not the same password enter your password again\n";
			cout << "\033[1;0m";
		}
		//system("cls");
	}


	i++;
	
}
bool log_in()
{
	cout << "#---------------------------------------------> WELCOME To The login Page <-------------------------------------------#\n\n";
	string email, password;
	cout << "\033[1;32m";
	cout << "Enter Your Email\n";
	cout << "\033[1;0m";
	cin >> email;
	cout << "\033[1;32m";
	cout << "Enter Your Password \n";
	cout << "\033[1;0m";
	char ch;
	while ((ch = _getch()) != '\r') {  // Keep reading until Enter (carriage return) is pressed
		if (ch == '\b') {  // Handle backspace
			if (!password.empty()) {
				password.pop_back();
				cout << "\b \b";  // Move cursor back, print space to erase, then move back again
			}
		}
		else {
			password.push_back(ch);
			cout << '*';  // Echo '' instead of the actual character
		}
	}
	cout << "\n";
	if (find_account(email, password))
	{

		return true;
	}
	else
		//system("cls");
	{
		cout << "\033[1;31m";
		cout << "This email not exist plz try again \n";
		cout << "\033[1;0m";
		Sleep(3000);
		system("cls");
		log_in();
	}

}
void VisaPayment() {
	string cardNumber, expirationDate;
	cout << "Enter Visa card number: \n";
	cin >> cardNumber;
	cout << " \n Enter expiration date : \n";
	cin.ignore();
	getline(cin, expirationDate);
	for (int i = 0;i < 3;i++)
	{
		cout << "Loading ";
		for (int j = 0;j < 5;j++)
		{
			cout << "." << " ";
			Sleep(200);
		}
		cout << "\r";
	}
	cout << "\r\r"<<flush;
	this_thread::sleep_for(chrono::seconds(5)); // Display the next sentence after 5 sec   
	cout << " Payment successful.." << endl;
}
void cashpayment() {
	cout << " please pay in cash . \n";
	this_thread::sleep_for(chrono::seconds(3)); // Display the next sentence after 3 sec    
	cout << " Thanks for you payment . \n ";
}
void pickUp_at_pharmacy() {
	cout << " Your order is being prepared .\n";
	cout << " please come to the pharmacy to recieve your order . \n";
}
void edit_information()
{
	string pass[2];
	do {
		system("cls");
		cout << "1. Change your name\n";
		cout << "2. Change your password\n";
		cout << "3. Change your email\n";
		cout << " Please,Enter your choice number\n";
		choice = _getch();
		if (choice == '1')
		{
			cout << "#------------------> Changing Name <-----------------------#\n\n";

			cout << "Enter the New name\n";
			cin >> clinet[current_index].user_name;
		}
		else if (choice == '2')
		{
			cout << "#------------------> Changing Password <-----------------------#\n\n";

			while (true)
			{
				cout << "#----> Enter the old password        :";
				cin >> pass[0];
				if (pass[0] != clinet[current_index].password[1])
				{
					cout << "The old Password Wrong Plz Rewrite again\n";
					continue;
				}
				while (true) {
					cout << "\n#----> Enter the new pass          :";
					cin >> pass[0];
					if (pass[0].size() < 8)              //check that the password not weak
					{
						cout << "\n#-------> The Password can't be less than 8 characters.\n";
						continue;
					}
					else
						break;
				}
				cout << "#----> Enter the new pass again         :\n";
				cin >> pass[1];

				if (pass[0] == pass[1])
				{
					cout << "#--------------------------------------------------------------#\n";
					cout << "\n#----> The password is succsseflly changed.\n";
					Sleep(3000);

					break;
				}
				else
				{
					cout << "#--------------------------------------------------------------#\n";
					cout << "\a";
					cout << "\n#------> The password is in correct \n";
					cout << "\n#------> Please Try again\n";
				}

			}
			clinet[current_index].password[0] = pass[0];
			clinet[current_index].password[1] = pass[1];
		}
		else if (choice == '3')
		{
			cout << "#------------------> Changing Email <-----------------------#\n\n";

			while (true)
			{
				cout << "Enter The New Email\n";
				cin >> clinet[current_index].email;
				if (clinet[current_index].email.find("@gmail.com") == -1)
					cout << "Invalid email . eamil should have ( @gmail.com ) please rewrite again\n";
				else
					break;



			}

		}
		else
		{
			edit_information();
		}
		cout << "do you wanna change another information (y / n)\n ";
		cin >> choice;
		while (true)
		{
			if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
			{
				cout << "Invalid choice please try again\n";
				cin >> choice;
			}
			else
				break;

		}

	} while (choice == 'y' || choice == 'Y');
}
void adding_new_medicine()
{
	for (int i = 0; i < size_medicine; i++)
	{

		med[i].id = rand() % 100000;
		cout << "Enter name of medicin\n";
		cin.ignore();
		getline(cin, med[i].name);
		cout << "Enter category of medicin\n";
		cin.ignore();
		getline(cin, med[i].category);
		cout << "Enter description of medicin\n";
		cin.ignore();
		getline(cin, med[i].description);
		cout << "Enter price of medicin\n";
		cin >> med[i].price;
		cout << "Enter quantity of medicin\n";
		cin >> med[i].quantity_in_stock;

	}
}//
void search_for_medicine()
{
	system("cls");
	cout << "#---------------------------------------------> WELCOME To The Search Page <-------------------------------------------#\n\n";
	string name;
	bool x = false, t = false;
	int m = 0;
	int n = 1;
	int id_ch[11];
	cout << "Select an option\n";
	cout << "\033[1;31m" << 1 << "\033[1;0m" << ". name :\n";
	cout << "\033[1;31m" << 2 << "\033[1;0m" << ". category :\n";
	choice = _getch();
	if (choice != '1' && choice != '2')
	{
		search_for_medicine();
	}
	//Sleep(500);
	if (choice == '1')
	{
		cout << "Enter the name of the medicine.\n";
		cin >> name;
		name = covert_to_lowercase(name);
		for (int i = 0; i < size_medicine; i++)
		{
			if (med[i].name == name)
			{
				cout << "-------------------------------------------------------------------\n";
				cout << " Name :                " << med[i].name << endl;
				cout << "Price :               " << med[i].price << endl;
				cout << "Category :             " << med[i].category << endl;
				cout << "Description :          " << med[i].description << endl;
				cout << " Quantity availble :  " << med[i].quantity_in_stock << endl;
				cout << " ID :                  " << med[i].id << endl;
				cout << "-------------------------------------------------------------------\n";
				x = true;
				break;
			}
		}
		if (x == false)
		{
			bool a = false;
			while (true)
			{
				int arr[size_medicine];
				for (int j = 0; j < size_medicine; j++)
				{
					if (med[j].name.find(name) != -1)
					{
						cout << "Do You maen \n";
						a = true;
						break;
					}

				}

				for (int j = 0; j < size_medicine; j++)
				{
					if (med[j].name.find(name) != -1)
					{
						cout<<"\033[1;31m" << n  << "\033[1;0m" << ". " << med[j].name << endl;
						t = true;
						id_ch[n - 1] = med[j].id;
						arr[j] = med[j].id;
						n++;
					}
				}
				if (a) {
					do {
						cout << "Do you Mean this medicines " << '(' << "\033[1;32m" << "Y / N" << "\033[1;0m" << ") ?" << endl;
						 choice=_getch();
					} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
				}
				if (choice == 'n' || choice == 'N')
				{
					break;
				}

				if (t) {
					while (true) {
						bool n = false;
						cout << "Select The medicine\n";
						cin >> m;
						m = id_ch[m - 1];
						for (int i = 0; i < size_medicine; i++)
						{
							if (m == arr[i]) {
								n = true;
								break;
							}
						}
						if (n)
						{
							break;
						}
						else
						{
							cout << "\033[1;31m";
							cout << "Invalid choice Please Try again\n";
							cout << "\033[1;0m";
						}
					}
				}
				for (int i = 0; i < size_medicine; i++)
				{
					if (med[i].id == m)
					{
						cout << "-------------------------------------------------------------------\n";
						cout << " Name :                " << med[i].name << endl;
						cout << "Price :               " << med[i].price << endl;
						cout << "Category :             " << med[i].category << endl;
						cout << "Description :          " << med[i].description << endl;
						cout << " Quantity availble :  " << med[i].quantity_in_stock << endl;
						cout << " ID :                  " << med[i].id << endl;
						cout << "-------------------------------------------------------------------\n";
						x = true;
					}
				}
				break;
			}
		}
		if (x == false) {
			cout << "\033[1;31m";
			cout << "INVALIAD NAME!!!!\n";
			cout << "Sorry, This medicine name is not available.\n";
			cout << "\033[1;0m";
		}

	}
	if (choice == '2')
	{
		cout << "Enter the category of the medicine.\n";
		cin.ignore();
		getline(cin, name);
		name = covert_to_lowercase(name);
		for (int i = 0; i < size_medicine; i++)
		{
			if (med[i].category == name)
			{
				cout << "-------------------------------------------------------------------\n";
				cout << " Name :                " << med[i].name << endl;
				cout << "Price :                " << med[i].price << endl;
				cout << "Category :             " << med[i].category << endl;
				cout << "Description :          " << med[i].description << endl;
				cout << " Quantity availble :   " << med[i].quantity_in_stock << endl;
				cout << " ID :                  " << med[i].id << endl;
				cout << "-------------------------------------------------------------------\n";
				x = true;
				break;
			}
		}
		if (x == false)
		{
			bool a = false;
			while (true)
			{
				int arr[size_medicine];
				for (int j = 0; j < size_medicine; j++)
				{
					if (med[j].category.find(name) != -1)
					{
						cout << "Do You Mean this medicine in category of "<< med[j].category<<endl;
						a = true;
						break;
					}

				}

				for (int j = 0; j < size_medicine; j++)
				{
					if (med[j].category.find(name) != -1)
					{
						cout<<"\033[1;31m" << n << "\033[1;0m" << ". " << med[j].name << endl;
						id_ch[n - 1] = med[j].id;
						t = true;
						arr[j] = med[j].id;
						n++;
						
					}
				}
				if (a) {
					do {
						cout << "Do you Mean this medicine "  << '(' << "\033[1;32m" << "Y / N" << "\033[1;0m" << ") ?" << endl;
						 choice=_getch();
					} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
				}
				if (choice == 'n' || choice == 'N')
				{
					break;
				}
				if (t) {
					while (true) {
						bool n = false;
						cout << "\033[1;32m";
						cout << "Select The medicine\n";
						cout << "\033[1;0m";
						cin>>m;
						m = id_ch[m - 1];
						for (int i = 0; i < size_medicine; i++)
						{
							if (m == arr[i]) {
								n = true;
								break;
							}
						}
						if (n)
						{
							break;
						}
						else
						{
							cout << "\033[1;31m";
							cout << "Invalid choice Please Try again\n";
							cout << "\033[1;0m";
						}
					}
				}
				for (int i = 0; i < size_medicine; i++)
				{
					if (med[i].id == m)
					{
						cout << "-------------------------------------------------------------------\n";
						cout << " Name :                " << med[i].name << endl;
						cout << "Price :               " << med[i].price << endl;
						cout << "Category :             " << med[i].category << endl;
						cout << "Description :          " << med[i].description << endl;
						cout << " Quantity availble :  " << med[i].quantity_in_stock << endl;
						cout << " ID :                  " << med[i].id << endl;
						cout << "-------------------------------------------------------------------\n";
						x = true;
					}
				}
				break;
			}
		}
		if (x == false) {
			cout << "\033[1;31m";
			cout << "INVALIAD CATEGORY!!!!\n";
			cout << "Sorry, This medicine category is not available.\n";
			cout << "\033[1;0m";
		}

	}
	cout << "Do you want to search for another medicine " << '(' << "\033[1;32m" << "Y / N" << "\033[1;0m" << ") ?" << endl;
	cin >> choice;
	while (true)
	{
		if (choice != 'n' && choice != 'y' && choice != 'Y' && choice != 'N')//if enter correct choice
		{
			cout << "INVALIAD CHOICE!!!!\n";
			cout << "Do you want to search for another medicine " << '(' << "\033[1;32m" << "Y / N" << "\033[1;0m" << ") ?"<<endl;
			cin >> choice;
			continue;
		}
		else
			break;
	}
	if (choice == 'y' || choice == 'Y')//if enter correct choice
	{
		search_for_medicine();


	}


}
void editing_description_of_medicine()
{
	string description00;
	do {
		cout << "enter the name : ";
		cin >> name01;
		for (int i = 0; i < size_medicine; i++)
		{
			if (name01 == med[i].name)
			{
				x01 = true;
				index01 = i;
			}
		}
		if (x01)
		{
			cout << "change description : \n";
			cin >> description00;
			if (description00 == med[index01].description)
			{
				cout << "no change happened !!!!!!!!!\n";
				cout << "______________ \n";
			}
			else
			{
				med[index01].description = description00;
			}
		}
		else
		{
			cout << "not found \n";
		}
		cout << "do you wanna edit another descriotion ? \n";
		cout << "1.yes \n";
		cout << "2.no \n";
		cout << "______________ \n";
		cin >> l01;
		cout << "______________ \n";
	} while (l01 == 1);
}
void editing_quantity_of_medicine()
{
	int  quantity_in_stock = 0;
	do {
		cout << "enter the name of medicine : ";
		cin >> name01;
		for (int i = 0; i < size_medicine; i++)
		{
			if (name01 == med[i].name)
			{
				x01 = true;
				index01 = i;
			}
		}
		if (x01)
		{
			cout << "change quantity in stock: \n";
			cin >> quantity_in_stock;
			if (quantity_in_stock == med[index01].quantity_in_stock)
			{
				cout << "no change happened !!!!!!!!!!!!!!! \n";
				cout << "______________ \n";
			}
			else
			{
				med[index01].quantity_in_stock = quantity_in_stock;
			}

		}
		else
		{
			cout << "not found \n";
		}
		cout << "do you wanna edit another quantity? \n";
		cout << "1.yes \n";
		cout << "2.no \n";
		cout << "______________ \n";
		cin >> l01;
		cout << "______________ \n";
	} while (l01 == 1);
}
void editing_price_of_medicine()
{
	float price00 = 0;
	do {
		cout << "enter the name of medicine : ";
		cin >> name01;
		for (int i = 0; i < size_medicine; i++)
		{
			if (name01 == med[i].name)
			{
				x01 = true;
				index01 = i;
			}
		}
		if (x01)
		{
			cout << "change description : \n";
			cin >> price00;
			if (price00 == med[index01].price)
			{
				cout << "no change happened !!!!!!!!!!!!!!! \n";
				cout << "______________ \n";
			}
			else
			{
				med[index01].price = price00;
			}
		}
		else
		{
			cout << "not found \n";
		}

		cout << "do you wanna edit another price? \n";
		cout << "1.yes \n";
		cout << "2.no \n";
		cout << "______________ \n";
		cin >> l01;
		cout << "______________ \n";
	} while (l01 == 1);
}
void editing_name_of_medicine()
{
	string  new_name;
	do {
		cout << "enter the name : ";
		cin >> name01;
		for (int i = 0; i < size_medicine; i++)
		{
			if (name01 == med[i].name)
			{
				x01 = true;
				index01 = i;
			}
		}
		if (x01)
		{
			cout << "change name : \n";
			cin >> new_name;
			if (new_name == med[index01].name)
			{
				cout << "no change happened !!!!!!!!!!!!!!!! \n";
				cout << "______________ \n";
			}
			else
			{
				med[index01].name = new_name;
			}
		}
		else
		{
			cout << "not found \n";
		}
		cout << "do you wanna edit another name ? \n";
		cout << "1.yes \n";
		cout << "2.no \n";
		cout << "______________ \n";
		cin >> l01;
		cout << "______________ \n";
	} while (l01 == 1);
}
void editing_category_of_medicine()
{
	string  newcategory;
	do {
		cout << "enter the name of medicine : ";
		cin >> name01;
		for (int i = 0; i < size_medicine; i++)
		{
			if (name01 == med[i].name)
			{
				x01 = true;
				index01 = i;
			}
		}
		if (x01)
		{
			cout << "change category : \n";
			cin >> newcategory;
			if (newcategory == med[index01].category)
			{
				cout << "no change happened !!!!!!!!!!!!!!!! \n";
				cout << "______________ \n";
			}
			else
			{
				med[index01].category = newcategory;
			}
		}
		else
		{
			cout << "not found \n";
		}

		cout << "do you wanna edit another category? \n";
		cout << "1.yes \n";
		cout << "2.no \n";
		cout << "______________ \n";
		cin >> l01;
		cout << "______________ \n";
	} while (l01 == 1);
}
void displaying_ways_of_payement_for_user()  //Ayat
{
	cout << "\033[1;36m";
	if (arr0x[current_index][0] == 1 && arr0x[current_index][1] == 0 && arr0x[current_index][2] == 0)
	{
		VisaPayment();
	}
	else if (arr0x[current_index][0] == 0 && arr0x[current_index][1] == 1 && arr0x[current_index][2] == 0)
	{
		cashpayment();
	}
	else if (arr0x[current_index][0] == 0 && arr0x[current_index][1] == 0 && arr0x[current_index][2] == 1)
	{
		pickUp_at_pharmacy();
	}
	else if (arr0x[current_index][0] == 1 && arr0x[current_index][1] == 1 && arr0x[current_index][2] == 0)
	{


		cout << "choose way of the following options : \n";
		cout << "1.visa payment \n";
		cout << "2.cash payment \n";
		cout << "______________________ \n ";
		choice = _getch();
		if (choice == '1')
		{

			VisaPayment();

		}
		else if (choice == '2')
		{

			cashpayment();

		}
		else
		{
			cout << "not valid !!!! \n";
			displaying_ways_of_payement_for_user();
		}

	}
	else if (arr0x[current_index][0] == 1 && arr0x[current_index][1] == 0 && arr0x[current_index][2] == 1)
	{

		cout << "choose way of the following options : \n";
		cout << "1.visa payment \n";
		cout << "2.pickup at pharmacy \n";
		cout << "______________________ \n";
		choice = _getch();
		if (choice == '1')
		{
			VisaPayment();

		}
		else if (choice == '2')
		{
			pickUp_at_pharmacy();

		}
		else
		{
			cout << "not valid !!!! \n";
			displaying_ways_of_payement_for_user();
		}

	}
	else if (arr0x[current_index][0] == 0 && arr0x[current_index][1] == 1 && arr0x[current_index][2] == 1)
	{

		cout << "choose way of the following options : \n";
		cout << "1.cash payment \n";
		cout << "2.pickup at pharmacy \n";
		cout << "______________________ \n";
		choice = _getch();
		if (choice == '1')
		{
			cashpayment();

		}
		else if (choice == '2')
		{
			pickUp_at_pharmacy();

		}
		else
		{
			cout << "not valid !!!! \n";
			displaying_ways_of_payement_for_user();
		}

	}
	else
	{
		paymentMethod();
	}
}
void editing_id_of_medicine()
{
	int  id00 = 0;
	do {
		cout << "enter the name of medicine : ";
		cin >> name01;
		for (int i = 0; i < size_medicine; i++)
		{
			if (name01 == med[i].name)
			{
				x01 = true;
				index01 = i;
			}
		}
		if (x01)
		{
			int l04 = 0;
			cout << "change id: \n";
			cin >> id00;
			for (int i = 0; i < size_medicine; i++)
			{
				if (id00 == med[i].id)
					l04 = 1;
			}
			if (id00 == med[index01].id)
			{
				cout << "no change happened !!!!!!!!!!!!!!! \n";
				cout << "______________ \n";
			}
			else if (l04)
			{
				cout << "this id is already exist , change it \n";
			}
			else
			{
				med[index01].id = id00;
			}
		}
		else
		{
			cout << "not found \n";
		}

		cout << "do you wanna edit another id? \n";
		cout << "1.yes \n";
		cout << "2.no \n";
		cout << "______________ \n";
		cin >> l01;
		cout << "______________ \n";
	} while (l01 == 1);
}
void admin_edit_order() {
	bool find = false, findmed = false;
	int x = 0;
	int id, medid, quantity;
	cout << "-------------> Enter The ID of the user you want to edit his order\n";
	cin >> id;
	for (int j = 0; j < i;j++) {
		if (clinet[j].id == id)
		{
			find = true;
			x = j;
			break;
		}

	}
	if (find == false)
	{
		cout << "-------------> This User Does Not exist Please try again\n";
		admin_edit_order();
	}

	if (find == true)
	{
		if (clinet[x].counter <= 0)
		{
			cout << "-------------> there is no any orders done by this user\n\n";
			do {
				cout << "-------------> do you want to edit other order? ( Y / N ) " << endl;
				choice = _getch();
				if (choice == 'n' || choice == 'N') { page1_admin(); }
				else if (choice == 'Y' || choice == 'y')admin_edit_order();
				else cout << "------------->INVALID CHOICE please Enter ( Y / N )";
			} while (true);
		}
		else
		{
			int y = 0;
			for (int i = 0;i < size_medicine;i++)
			{
				if (list_of_medcines_IDs[x][clinet[x].counter].id == med[i].id)
					y = i;

			}
			med[y].quantity_in_stock += list_of_medcines_IDs[x][clinet[x].counter].quantity_ordered;
			cout << "Enter the new medcine id";
			cin >> medid;
			int z = 0;
			for (; z < size_medicine;z++)
			{
				if (medid == med[z].id)
				{
					findmed = true;
					break;
				}
			}
			if (findmed == true)
			{
				cout << "Enter the new medicine quantity : ";
				cin >> quantity;
				if (quantity > med[z].quantity_in_stock)
				{

					cout << "SORRY\n This amount is not available in the stock ,now.\n the available amount is:" << med[z].quantity_in_stock << "\ntry again and Enter the quantity again" << endl;

					cin >> quantity;
				}
				else if (quantity <= 0)
				{
					cout << "Sorry, invaliad quantity .\nYou must determine the quantity.\n";
					cout << "Enter the quantity you need.\n";
					cin >> quantity;
				}
				else {
					list_of_medcines_IDs[x][clinet[x].counter].name = med[z].name;
					list_of_medcines_IDs[x][clinet[x].counter].price = med[z].price;
					list_of_medcines_IDs[x][clinet[x].counter].category = med[z].category;
					list_of_medcines_IDs[x][clinet[x].counter].description = med[z].description;
					list_of_medcines_IDs[x][clinet[x].counter].id = med[z].id;
					list_of_medcines_IDs[x][clinet[x].counter].quantity_ordered = quantity;
					med[z].quantity_in_stock -= quantity;
					list_of_medcines_IDs[x][clinet[x].counter].total_price = med[z].price * quantity;
					list_of_medcines_IDs[x][clinet[x].counter].total = med[z].price * quantity; ///////previous}
					cout << "----------->the order has been edited successfully!";
				}
			}
		}

	}
	cout << "-------------> do you want to edit another order? ( Y / N )" << endl;
	while (true)
	{
		choice = _getch();
		if (choice == 'n' || choice == 'N') page1_admin();
		else if (choice == 'y' || choice == 'Y') admin_edit_order();
		else cout << "-------------> Invalid choice please Enter ( Y / N )" << endl;
	}
}
void admin_cancel_order() {

	bool find = false;
	int  id, x = 0;
	cout << "Enter The ID of the user you want to cancel his order\n";
	cin >> id;
	for (int j = 0; j < i;j++) {
		if (clinet[j].id == id)
		{
			find = true;
			id = j;
			break;
		}

	}
	if (find == false)
	{
		cout << " This User Does Not exist Please try again\n";
		admin_cancel_order();
	}

	if (find == true) {


		if (clinet[id].counter <= 0)
		{
			cout << "there is no any orders done by this user\n";
			do {
				cout << "--------------> do you want to cancel other order?( Y / N ) " << endl;
				choice = _getch();
				if (choice == 'n' || choice == 'N') { page1_admin(); }
				else if (choice == 'Y' || choice == 'y')admin_cancel_order();
				else cout << "-----------------> INVALID CHOICE please Enter( Y / N )";
			} while (true);
		}
		else
		{
			do {
				cout << "Press 1 to cancel " << clinet[id].user_name << "'s order" << endl;
				choice = _getch();
				if (choice == '1') {

					list_of_medcines_IDs[id][clinet[id].counter].id = x;
					for (int i = 0;i < size_medicine;i++)
					{
						if (x == med[i].id)
							x = i;

					}

					list_of_medcines_IDs[id][clinet[id].counter] = { };
					med[x].quantity_in_stock += list_of_medcines_IDs[id][clinet[id].counter].quantity_ordered;
					clinet[id].usercancel++;
					clinet[id].counter--;
					Sleep(3000);
					cout << "the order has been successfully canceld!" << endl;
					break;
				}
				else cout << "INVALID CHOICE please try again" << endl;
			} while (true);
		}
		/*else if (clinet[i].counter >= 2)
		{
			int ord;
			cout << "This user has " << clinet[i].counter << "orders, Enter which one do you want to edit : ";
			cin >> ord;
			if (ord > clinet[i].counter || ord <= 0)
			{
				while (true) {
					cout << "Invalid number please try again ";
					cin >> ord;
					if (ord <= clinet[i].counter)break;
				}
			}
		}*/

		cout << "do you want to cancel another order? ( Y / N )" << endl;
		while (true)
		{
			cin >> choice;
			if (choice == 'n' || choice == 'N') page1_admin();
			else if (choice == 'y' || choice == 'Y') admin_cancel_order();
			else cout << "Invalid choice please Enter ( Y / N )";
		}
	}
}
void adminManageOrders()
{
	system("cls");
	cout << "#-----------------------------------------------------------> Page Manage Orders <-------------------------------------------------------#\n";
	cout << "select an option: " << endl;
	cout << "1. Edit order" << endl;
	cout << "2. Cancel order" << endl;

	choice = _getch();
	if (choice == '1') {
		admin_edit_order();

	}
	else if (choice == '2')
	{
		admin_cancel_order();

	}
	else
	{
		adminManageOrders();
	}

}
void deleting_medicine()
{
	do {
		cout << "enter the name of medicine : ";
		cin >> name01;
		for (int i = 0; i < size_medicine; i++)
		{
			if (clinet[i].user_name == name01)
			{
				index01 = i;
				x01 = true;
			}
			else
				x01 = false;
		}
		if (x01)
		{
			clinet[index01] = {};
		}
		else
		{
			cout << "not found \n";
		}
		cout << "do you wanna delete another medicine? \n";
		cout << "1.yes \n";
		cout << "2.no \n";
		cout << "______________ \n";
		cin >> l01;
		cout << "______________ \n";
	} while (l01 == 1);
}
void deleting_user()
{
	system("cls");
	string name02, email;
	bool find = false;
	cout << "enter the name of the user : ";
	cin >> name02;
	cout << endl;
	cout << "enter the email of the user : ";
	cin >> email;
	for (int i = 0; i < size_custmer; i++)
	{
		if (clinet[i].user_name == name02 && clinet[i].email == email)
		{
			clinet[i] = {};
			find = true;
			cout << "find\n";
		}

	}

	if (find == false)
	{
		cout << "user not found \n";
	}
	cout << "do you wanna delete another user ? \n";
	cout << "1.yes \n";
	cout << "2.no \n";
	cout << "______________ \n";
	choice = _getch();
	cout << "______________ \n";
	if (choice == '1')
		deleting_user();
	else if (choice == '2')
		page_1();
	else
		deleting_user();
}
void adding_users()
{
	int choice0x = 0;

	cout << "enter username\n";
	cin >> clinet[i].user_name;
	while (true)
	{

		string email;
		cout << "enter email of user\n";
		cin >> email;
		if (email.find("@gmail.com") == -1) {                        //check that the email is vaild
			cout << "invalid email. eamil should have ( @gmail.com ) please write again\n";
			continue;
		}
		if (find_email(email))
		{
			cout << "This Email Already Exist please try again\n";
		}
		else
		{
			clinet[i].email = email;
			break;
		}

	}

	cout << "enter adress of user\n";
	cin >> clinet[i].address;
	while (true)
	{
		cout << "enter phone number of user\n";
		cin >> clinet[i].phone;
		if (clinet[i].phone.size() != 11)            //check that phone number is 11 number
			cout << "invalid number phone. should 11 number \n";
		else
			break;
	}
	clinet[i].id = i + 1;
	while (true)
	{
		cout << "enter your password\n";
		cin >> clinet[i].password[0];
		if (clinet[i].password[0].size() < 8)              //check that the password not weak
		{
			cout << "the password must have at least 8 digits\n";
			continue;
		}
		cout << "rewrite your password again\n";
		cin >> clinet[i].password[1];

		if (clinet[i].password[0] == clinet[i].password[1])
		{
			break;
		}
		else
		{
			cout << "not the same password enter your password again\n";

		}

	}

	i++;
	cout << "do you wanna add another user? \n";
	cout << "1.yes \n";
	cout << "2.no \n";
	cout << "______________ \n";
	cin >> l01;
	cout << "______________ \n";
	if (l01 == 1)
		adding_users();
}
void editing_information_about_user()
{
	cout << "#------------------------------------------> Changing InFormation For Users <-----------------------------------#\n\n";

	bool find = false;
	int id;
	cout << "---------------->Enter The ID of the users\n";
	cin >> id;
	for (int j = 0;j < i;j++)
	{
		if (clinet[j].id == id)
		{
			find == true;
			id = i;
		}


	}

	if (find == false)
	{
		system("cls");
		cout << " This User Not exist Plz try again\n\n";
		editing_information_about_user();
	}

	else {
		cout << "1. Change The name of the user\n";
		cout << "2. Change The password of the user\n";
		cout << "3. Change The email of the user\n";
		cout << " Please,Enter your choice number\n";
		cin >> choice;
		if (choice == '1')
		{
			cout << "Enter the New name \n";
			cin >> clinet[id].user_name;
		}
		else if (choice == '2')
		{
			while (true)
			{
				cout << "Enter the current Password\n";
				cin >> clinet[id].password[0];
				if (clinet[id].password[0] != clinet[id].password[1])
				{
					cout << "The current Password Wrong Plz Rewrite again\n";
					continue;
				}

				cout << "Enter The New Password\n";
				cin >> clinet[id].password[0];
				if (clinet[id].password[0].size() < 8)              //check that the password not weak
				{
					cout << "------>the password must have at least 8 character\n";
					continue;
				}
				cout << "------>Rewrite Your Password again\n";
				cin >> clinet[id].password[1];

				if (clinet[id].password[0] == clinet[id].password[1])
					break;
				else
				{
					cout << "Not the same password enter your password again\n";
					cout << "Plz try again\n";
				}

			}
		}
		else if (choice == '3')
		{
			while (true)
			{
				cout << "Enter The New Email\n";
				cin >> clinet[id].email;
				if (clinet[id].email.find("@gmail.com") == -1)
					cout << "Invalid email . eamil should have ( @gmail.com ) please rewrite again\n";
				else
					break;



			}

		}
		else
		{
			cout << "Invalid Choice plz Select choice again\n";
			edit_information();
		}
	}
}
void editorder(char choice, float& total_price, int select) {
	if (choice == '1')
	{
		bool found = false;
		do {
			int quantity;
			int orderID;
			cout << " Enter the ID of the medicine you want to edit \n";
			cin >> orderID;

			for (int i = 0; i <= select; i++) {
				if (list_of_medcines_IDs[current_index][i].id == orderID)
				{
					found = true;
					cout << " Order Details:" << endl;
					cout << " Medicine ID: " << list_of_medcines_IDs[current_index][i].id << endl;
					cout << " Medicine Name: " << list_of_medcines_IDs[current_index][i].name << endl;
					cout << " Medicine quantity ordered: " << list_of_medcines_IDs[current_index][i].quantity_ordered << endl;
					cout << " Medicine Price :" << list_of_medcines_IDs[current_index][i].price << endl;
					cout << "Do you want to edit this order? (y/n) \n";
					cin >> choice;
					if (choice == 'Y' || choice == 'y')
					{
						cout << " Enter the new quantity: ";
						cin >> quantity;
						total_price = total_price - list_of_medcines_IDs[current_index][i].quantity_ordered * list_of_medcines_IDs[current_index][i].price;
						total_price += quantity * list_of_medcines_IDs[current_index][i].price;
						med[i].quantity_in_stock = list_of_medcines_IDs[current_index][i].quantity_ordered + med[i].quantity_in_stock;
						med[i].quantity_in_stock -= quantity;
						//med[i] = list_of_medcines_IDs[i];
						cout << " Order is edited successfully.." << endl;
						break;
					}
					else if (choice == 'y' || choice == 'Y') {
						cout << "Fine." << endl;
					}
					else {
						cout << "INVALID CHOICE\n";
					}
					break;

				}
			}
			if (found == false)
			{
				cout << " Sorry , \n This order is not exsist .. \n ";
			}
			cout << "Do you want to edit another order? (y/n) \n";
			cin >> choice;
			if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
				while (true)//loop for repeat choicesif if user enter wrong choice 
				{
					cout << " INVALIAD CHOICE..\n";
					cout << " Do you want to edit another medicine ? (Y / N) \n";
					cin >> choice;
					if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
						break;
				}
			}
		} while ((choice == 'y' || choice == 'Y'));
	}
}
void cancelorder(char choice, float& total_price, int& i) {            //function to cancel order by user
	if (choice == '2') {
		//i = i-1;
		do {
			cout << "Order Details:" << endl;
			cout << "Medicine ID: " << list_of_medcines_IDs[current_index][i - 1].id << endl;
			cout << "Medicine ID: " << list_of_medcines_IDs[current_index][i].id << endl;
			cout << "Medicine ID: " << list_of_medcines_IDs[current_index][i + 1].id << endl;
			cout << "Medicine Name: " << list_of_medcines_IDs[current_index][i].name << endl;
			cout << "Medicine Price: " << list_of_medcines_IDs[current_index][i].price << endl;
			cout << "Medicine quantity: " << list_of_medcines_IDs[current_index][i].quantity_ordered << endl;
			cout << "Do you want to cancel this order? (y/n) \n";
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				list_of_medcines_IDs[current_index][i].total_price = total_price - list_of_medcines_IDs[current_index][i].quantity_ordered * list_of_medcines_IDs[current_index][i].price;
				med[i].quantity_in_stock = list_of_medcines_IDs[current_index][i].quantity_ordered + med[i].quantity_in_stock;
				//med[i] = list_of_medcines_IDs[current_index][i];
				list_of_medcines_IDs[current_index][i] = { 0 };
				cout << "Order cancelled successfully." << endl;
				i--;
				break;
			}
			else if (choice == 'N' || choice == 'n')
			{
				cout << "Fine." << endl;
				break;
			}
			else {
				cout << "INVALID CHOICE\n";
				cout << "Please try again\n";
			}
		} while (choice == 'N' || choice == 'n' || choice == 'y' || choice == 'Y');

	}
}
void show_order_receipt(char choice, float total_price, int select) {
	cout << "\033[1;34m";
	//system("cls");
	if (choice == '3' && list_of_medcines_IDs[current_index][select].total_price != 0)
	{


		cout << " List of selected medicines  \n";
		cout << " Medicine " << i + 1 << " ID :  \t" << list_of_medcines_IDs[current_index][select].id << endl;
		cout << " Medicine " << i + 1 << " Name :    " << list_of_medcines_IDs[current_index][select].name << endl; //out << "Medicine " << select + 1 << "Price :\t" << list_of_medcines_IDs[i].price << endl; 
		cout << " Medicine " << i + 1 << " Price :  \t" << list_of_medcines_IDs[current_index][select].price << endl;
		cout << " Medicine " << i + 1 << " Quantity :\t" << list_of_medcines_IDs[current_index][select].quantity_ordered << endl;
		orderdate();
		ordertime();
		ship_date();
		cout << "\n--------------------------------------------------------------------- \n\n";
		cout << " The Total price : " << list_of_medcines_IDs[current_index][select].total_price << " pound.\n\n";
		displaying_ways_of_payement_for_user();


	}

	if (choice != '1' && choice != '2' && choice != '3')
	{
		cout << " INVALIAD NUMBER..\n please,try again.\n";
	}
}
void AddNewOrder() {
	bool find = false;
	int id;/////////////////////////////////////////////////////
	int quantity;
	string iid;
	medicine selectedMedicine;
	int select = 0;
	do {



		cout << "Enter the ID of the medicine you need .\n";
		cin >> iid;
		id = stoi(iid);
		bool ids;
		do {
			ids = false;
			for (int i = 0; i < 11; i++)
			{
				if (med[i].id == id) {
					ids = true;
					break;
				}

			}
			if (ids == false)
			{
				cout << "\033[1;31m";
				cout << "Invaliad ID . \n Try again . \n";
				cout << "\033[1;0m";
				cout << "Enter the ID of the medicine you need .\n";
				cin >> id;

			}

		} while (ids == false);

		cout << "Enter the quantity you need.\n";
		cin >> quantity;
		while (quantity <= 0)//while loop to check the rong quantity and display invaliad if it is wrong
		{
			cout << "\033[1;31m";
			cout << "Sorry, invaliad quantity .\nYou must determine the quantity.\n";
			cout << "\033[1;0m";
			cout << "Enter the quantity you need.\n";
			cin >> quantity;


		}
		for (int i = 0; i < size_medicine; i++) {
			if (med[i].id == id)
			{

				while (true)
				{
					while (quantity > med[i].quantity_in_stock)
					{
						cout << "\033[1;31m";
						cout << "SORRY\n This amount is not available in the stock ,now.\n the available amount is:" << med[i].quantity_in_stock << "\ntry again and Enter the quantity again" << endl;
						cout << "\033[1;0m";
						cin >> quantity;

					}
					while (quantity <= 0)

					{
						if (quantity <= 0) {
							cout << "\033[1;31m";
							cout << "Sorry, invaliad quantity .\nYou must determine the quantity.\n";
							cout << "\033[1;0m";
							cout << "Enter the quantity you need.\n";
							cin >> quantity;
						}
						if (quantity > med[i].quantity_in_stock)
						{
							cout << "\033[1;31m";
							cout << "SORRY\n This amount is not available in the stock ,now.\n the available amount is:" << med[i].quantity_in_stock << "\ntry again and Enter the quantity again" << endl;
							cout << "\033[1;0m";
							cin >> quantity;
						}
					}

					break;

				}
				list_of_medcines_IDs[current_index][select].name = med[i].name;
				list_of_medcines_IDs[current_index][select].price = med[i].price;
				list_of_medcines_IDs[current_index][select].category = med[i].category;
				list_of_medcines_IDs[current_index][select].description = med[i].description;
				list_of_medcines_IDs[current_index][select].id = med[i].id;
				list_of_medcines_IDs[current_index][select].quantity_ordered = quantity;
				med[i].quantity_in_stock -= quantity;
				list_of_medcines_IDs[current_index][select].total_price = med[i].price * quantity;
				find = true;
				break;

			}


		}



		if (!find)//if for invaliad id
		{
			cout << "\033[1;31m";
			cout << "INVALIAD ID!!!!!  Please try again \n";
			cout << "\033[1;0m";
			AddNewOrder();
		}


		cout << " Thanks for using our pharmacy ." << endl;
		do {
			cout << " press " << "\033[1;31m" << 1 <<  "\033[1;0m" << "to edit the order .\n";
			cout << " press " << "\033[1;31m" << 2 << "\033[1;0m" << "to cancel the order .\n";
			cout << " press " << "\033[1;31m" << 3 << "\033[1;0m" << "to confirm the order. \n";
			cin >> choice;
			if (choice == '1') 
			{
				editorder(choice, list_of_medcines_IDs[current_index][select].total_price, select);
			}
			if (choice == '2') 
			{
				cancelorder(choice, list_of_medcines_IDs[current_index][select].total_price, select);
			}
			if (choice == '3') 
			{
				show_order_receipt(choice, list_of_medcines_IDs[current_index][select].total_price, select);
				break;
			}
		} while (choice != '3');//loop for check and display invaliad if user enter wrong number 
		select = select + 1;
		clinet[current_index].counter = select;
		cout << "Do you want to add another medicine" << '(' << "\033[1;32m" << "Y / N" <<" \033[1;0m "<< ") ? " << endl;
		cin >> choice;
		if (choice == 'n' || choice == 'y' || choice == 'Y' || choice == 'N')//if enter correct choice
		{
			cout << "Okay\n";
			//if (choice == 'n' || choice == 'N')break;

		}
		else //else for print invaliad to wrong choice
		{

			while (true)//loop for repeat choicesif if user enter wrong choice
			{
				cout << "\033[1;31m";
				cout << "INVALIAD CHOICE!!!!\n";
				cout << "\033[1;0m";
				cout << "Do you want to add another medicine" << '(' << "\033[1;32m" << "Y / N" << " \033[1;0m " << ") ? " << endl;
				cin >> choice;
				if (choice == 'n' || choice == 'N' || choice == 'y' || choice == 'Y')
				{
					break;
				}
				else
				{
					choice = 'y';
				}
			}
		}

	} while (choice != 'n' && choice != 'N');//loop for repeat choice
}
//void AddNewOrder() {
//	bool find = false;
//	int id;
//	int quantity;
//	int select = pre[current_index];
//	medicine selectedMedicine;
//	do {
//
//
//
//		cout << "Enter the ID of the medicine you need .\n";
//		cin >> id;
//		bool ids;
//		do {
//			ids = false;
//			for (int i = 0; i < 11; i++)
//			{
//				if (med[i].id == id) {
//					ids = true;
//					break;
//				}
//
//			}
//			if (ids == false)
//			{
//				cout << "Invaliad ID . \n Try again . \n";
//				cout << "Enter the ID of the medicine you need .\n";
//				cin >> id;
//
//			}
//
//		} while (ids == false);
//
//		cout << "Enter the quantity you need.\n";
//		cin >> quantity;
//		while (quantity <= 0)//while loop to check the rong quantity and display invaliad if it is wrong
//		{
//
//			cout << "Sorry, invaliad quantity .\nYou must determine the quantity.\n";
//			cout << "Enter the quantity you need.\n";
//			cin >> quantity;
//
//
//		}
//		for (int i = 0;i < size_medicine;i++) {
//			if (med[i].id == id)
//			{
//
//				while (true)
//				{
//					if (quantity > med[i].quantity_in_stock)
//					{
//
//						cout << "SORRY\n This amount is not available in the stock ,now.\n the available amount is:" << med[i].quantity_in_stock << "\ntry again and Enter the quantity again" << endl;
//
//						cin >> quantity;
//					}
//					if (quantity <= 0)
//					{
//						cout << "Sorry, invaliad quantity .\nYou must determine the quantity.\n";
//						cout << "Enter the quantity you need.\n";
//						cin >> quantity;
//					}
//					else
//						break;
//
//				}
//				list_of_medcines_IDs[current_index][select].name = med[i].name;
//				list_of_medcines_IDs[current_index][select].price = med[i].price;
//				list_of_medcines_IDs[current_index][select].category = med[i].category;
//				list_of_medcines_IDs[current_index][select].description = med[i].description;
//				list_of_medcines_IDs[current_index][select].id = med[i].id;
//				list_of_medcines_IDs[current_index][select].quantity_ordered = quantity;
//				med[i].quantity_in_stock -= quantity;
//
//
//				list_of_medcines_IDs[current_index][select].total_price = med[i].price * quantity;
//				list_of_medcines_IDs[current_index][select].total = med[i].price * quantity;
//				find = true;
//				break;
//
//			}
//
//
//		}
//
//
//
//		if (!find)//if for invaliad id
//		{
//			cout << "INVALIAD ID!!!!!  Please try again \n";
//			AddNewOrder();
//		}
//
//
//		cout << " Thanks for using our pharmacy ." << endl;
//		do {
//			cout << " press 1 to edit the order .\n";
//			cout << " press 2 to cancel the order .\n";
//			cout << " press 3 to confirm the order. \n";
//			cin >> choice;
//			editorder(choice, list_of_medcines_IDs[current_index][select].total_price, select);
//			cancelorder(choice, list_of_medcines_IDs[current_index][select].total_price, select);
//			show_order_receipt(choice, list_of_medcines_IDs[current_index][select].total_price, select);
//		} while (choice != '3');//loop for check and display invaliad if user enter wrong number 
//		select = select + 1;
//		pre[current_index] = select;
//		clinet[current_index].counter += 1;
//		cout << "Do you want to add another medicine ? (Y / N) \n";
//		cin >> choice;
//		if (choice == 'n' || choice == 'y' || choice == 'Y' || choice == 'N')//if enter correct choice
//		{
//			cout << "Okay\n";
//
//		}
//		else //else for print invaliad to wrong choice
//		{
//
//			while (true)//loop for repeat choicesif if user enter wrong choice
//			{
//				cout << "INVALIAD CHOICE!!!!\n";
//				cout << "Do you want to add another medicine ? (Y / N) \n";
//				cin >> choice;
//				if (choice == 'n' || choice == 'N' || choice == 'y' || choice == 'Y')
//				{
//
//					break;
//				}
//				else
//				{
//					choice = 'y';
//				}
//			}
//		}
//
//	} while (choice != 'n' && choice != 'N');//loop for repeat choice
//
//}
void previous() {
	system("cls");
	cout << "#---------------------------------------------> WELCOME To Previous orders Page <-------------------------------------------#\n\n";

	if (clinet[current_index].counter == 0) {
		cout << "there is no any previous orders" << endl;
		do {
			cout << "1.main menu" << endl;
			cin >> choice;
			if (choice == '1') { page1_user(); }
			else cout << "Invalid choice pleaese enter your choice again " << endl;
		} while (choice != '1');
	}
	//else if (clinet[current_index].usercancel >= select) {
		//cout << "your orders has been canceld";
	//}
	else {
		for (int i = 0; i < clinet[current_index].counter;i++) {
			cout << " List of previous order  \n";
			cout << " Medicine " << i + 1 << " ID :  \t" << list_of_medcines_IDs[current_index][i].id << endl;
			cout << " Medicine " << i + 1 << " Name :  \t" << list_of_medcines_IDs[current_index][i].name << endl; //out << "Medicine " << select + 1 << "Price :\t" << list_of_medcines_IDs[i].price << endl; 
			cout << " Medicine " << i + 1 << " Price :  \t" << list_of_medcines_IDs[current_index][i].price << endl;
			cout << " Medicine " << i + 1 << " Quantity :\t" << list_of_medcines_IDs[current_index][i].quantity_ordered << endl;
			cout << " order date is " << list_of_medcines_IDs[current_index][i].datey << "/" << list_of_medcines_IDs[current_index][i].datem << "/" << list_of_medcines_IDs[current_index][i].dated << endl;
			cout << " order time is " << list_of_medcines_IDs[current_index][i].timeh << ":" << list_of_medcines_IDs[current_index][i].timem << ":" << list_of_medcines_IDs[current_index][i].times << " " << list_of_medcines_IDs[current_index][i].m << endl;
			cout << " ship date is " << list_of_medcines_IDs[current_index][i].shipy << "/" << list_of_medcines_IDs[current_index][i].shipm << "/" << list_of_medcines_IDs[current_index][i].shipd << endl;
			cout << "\n--------------------------------------------------------------------- \n\n";
			cout << " The Total price : " << list_of_medcines_IDs[current_index][i].total_price << " pound.\n";
			cout << "\n--------------------------------------------------------------------- \n\n";
		}

	}
	system("pause");
}
void displayMenu() {                      //function display all element in the menue





	for (int i = 0; i < size_medicine; i++)//loop for display menu
	{
		cout << " Medicine " << i + 1 << ": \n";
		cout << " Name : " << med[i].name << " .\n";
		cout << " Category : " << med[i].category << ".\n";
		cout << " Description : " << med[i].description << ".\n";
		cout << " Price : " << med[i].price << ".\n";
		cout << " ID :  " << med[i].id << ".\n";
		cout << " Quantity in the stock : " << med[i].quantity_in_stock << ".\n\n";
		cout << "--------------------------------------------------------------------- \n\n";
	}
	cout << "Do you Want order"<< '(' << "\033[1;32m" << "Y / N" << "\033[1;0m" << ") ?" << endl;
	choice = _getch();
	if (choice == 'y' || choice == 'Y')
	{
		AddNewOrder();
	}
	else if (choice == 'n' || choice == 'N')
	{
		page1_user();
	}
	else
	{
		system("cls");
		displayMenu();
	}

}
void managing_ways_of_payment() //Ayat
{
	c01 = '0';
	c02 = '0';
	c03 = '0';
	system("cls");
	cout << "enter the name of user  :\n";
	cin >> name01;
	for (int i = 0; i < size_custmer; i++)
	{
		if (name01 == clinet[i].user_name)
		{
			index01 = i;
			x01 = true;
		}
	}
	if (x01)
	{
		system("cls");
		cout << "how many ways will be available for this user ? (maximum number of ways = 3) \n ";
		char cx;
		cin >> cx;
		cout << "______________________ \n";
		if (cx == '1')
		{
			while (true) {
				system("cls");
				clinet[index01].ways_of_payement = 1;
				cout << "choose 1 way of the following options : \n";
				cout << "1.visa payment \n";
				cout << "2.cash payment \n";
				cout << "3.pickup at pharmacy \n";
				cout << "______________________ \n\n";
				c01 = _getch();
				if (c01 == '1')
				{
					arr0x[index01][0] = 1;
					cout << "the process is successfully done \n ";
					break;
				}
				else if (c01 == '2')
				{
					arr0x[index01][1] = 1;
					

					cout << "the process is successfully done \n ";
					break;
				}
				else if (c01 == '3')
				{
					arr0x[index01][2] = 1;
					cout << "the process is successfully done \n ";
					break;
				}
				else
				{
					cout << "not valid !!! \n";
				}
			}
		}
		else if (cx == '2')
		{
			system("cls ");
			clinet[index01].ways_of_payement = 2;
			cout << "choose 2 way of the following options : \n";
			cout << "1.visa payment \n";
			cout << "2.cash payment \n";
			cout << "3.pickup at pharmacy \n";
			cout << "______________________ \n";
			cin >> c02;
			cin >> c03;
			if ((c02 == '1' || c02 == '2') && (c03 == '1' || c03 == '2'))
			{
				arr0x[index01][0] = 1;
				arr0x[index01][1] = 1;
				cout << "the process is successfully done \n ";
			}
			else if ((c02 == '1' || c02 == '3') && (c03 == '1' || c03 == '3'))
			{
				arr0x[index01][0] = 1;
				arr0x[index01][2] = 1;
				cout << "the process is successfully done \n ";
			}
			else if ((c02 == '2' || c02 == '3') && (c03 == '2' || c03 == '3'))
			{
				arr0x[index01][1] = 1;
				arr0x[index01][2] = 1;
				cout << "the process is successfully done \n ";
			}
			else
			{
				cout << "not valid !!!! \n";
			}
		}
		else if (cx == '3')
		{
			system("cls");
			clinet[index01].ways_of_payement = 3;
			for (int i = 0; i < 3; i++)
			{
				arr0x[index01][i] = 1;
			}
			cout << "the process is successfully done \n ";
		}
		else
		{
			cout << "not valid !!! \n";
		}
	}
	else
	{
		cout << "user not found \n ";
	}
}
void paymentMethod() {
	int choice;
	cout << "Choose payment method:" << endl;
	cout << " Press 1 Add Visa" << endl;
	cout << " Press 2 to pay in cash" << endl;
	cout << " press 3 to Pick at pharmacy" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << " pay in visa :: " << endl;
		VisaPayment();
		break;
	case 2:
		cout << " pay with cash." << endl;
		cashpayment();
		break;
	case 3:
		cout << " pick up at the pharmacy." << endl;
		pickUp_at_pharmacy();
		break;
	default:
		cout << " Invalid choice. \n Please try again." << endl;
	}
}
void displayUsers()
{
	string ch;

	system("cls");
	cout << "#-------------------------------------------------> Your Profile <--------------------------------------------------------#\n\n";
	for (int j = 0;j < i;j++)
	{

		if (clinet[j].email.find("admin") != -1)continue;

		cout << "#Name               : " << clinet[j].user_name << "\n";
		cout << "#ID                 : " << clinet[j].id << "\n";
		cout << "#Phone Number       : " << clinet[j].phone << "\n";
		cout << "#Email              : " << clinet[j].email << "\n";
		cout << "#Password           : " << clinet[j].password[0] << "\n\n";
		cout << "#-------------------------------------------------------------------------------#\n\n";



	}

	cout << "\n#-----> Enter anything to Exit : ";
	ch = getch();

}
void pre_order()
{
	system("cls");

	cout << "#--------------------------------------> Previous orders Page <---------------------------------------------------#\n";
	int m = pre[current_index];
	if (m == 0)
	{

		cout << "-------------> There are No Previous Orders\n";
	}

	for (int i = 0;i < m;i++)
	{
		cout << " List of selected medicines  \n";
		cout << " Medicine " << i + 1 << " ID :  \t" << list_of_medcines_IDs[current_index][i].id << endl;
		cout << " Medicine " << i + 1 << " Name :    " << list_of_medcines_IDs[current_index][i].name << endl;
		cout << " Medicine " << i + 1 << " Price :  \t" << list_of_medcines_IDs[current_index][i].price << endl;
		cout << " Medicine " << i + 1 << " Quantity :\t" << list_of_medcines_IDs[current_index][i].quantity_ordered << endl;
		cout << "\n--------------------------------------------------------------------- \n\n";
		cout << " The Total price : " << list_of_medcines_IDs[current_index][i].total_price << " pound.\n\n";
		cout << "....................................................................................................................\n";

	}
	cout << "Enter anything to back\n";
	choice = _getch();


}
void alerts() {
	bool item = false;
	for (int i = 0;i < size_medicine;i++) {
		if (med[i].quantity_in_stock <= 1) {
			cout << med[i].name << " : have only less than or equal 1 item left!!.." << endl;
			item = true;
		}
	}
	if (item == true)
	{
		while (true) {
			if (item == true) {
				cout << "-------------> do you want to add items "<< '(' << "\033[1;32m" << "Y / N" << "\033[1;0m" << ") ?" << endl;
				choice = _getch();
				if (choice == 'y' || choice == 'Y')
				{
					editing_quantity_of_medicine();break;
				}
				else if (choice == 'n' || choice == 'N')break;
				else {
					cout << "Invalid choice please try again";
				}
			}
		}
	}
}
void reports()
{
	if (complaintscounter == 0)
		cout << "---------------------> there is no any complaints \n";
	for (int j = 0;j < complaintscounter;j++)
	{
		cout << clinet[ind[j]].complaint[0] << " : " << clinet[ind[j]].complaint[1] << endl;
	}


}
void user_profile()
{
	string ch;
	system("cls");
	cout << "#--------------------> Your Profile <-------------------#\n\n";
	cout << "#Name               : " << clinet[current_index].user_name << "\n";
	cout << "#ID                 : " << clinet[current_index].id << "\n";
	cout << "#Phone Number       : " << clinet[current_index].phone << "\n";
	cout << "#Email              : " << clinet[current_index].email << "\n";
	cout << "#Password           : " << clinet[current_index].password[0] << "\n\n";
	cout << "\n#-----> Enter anything to Exit : ";
	ch = getch();


}
void complaints()
{

	cout << "do you want to make complaint ?"<< '(' << "\033[1;32m" << "Y / N" << "\033[1;0m" << ") " << endl;
	while (true) {
		choice = _getch();
		if (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y')
			page1_user();
		else
		{
			if (choice == 'y' || choice == 'Y')
			{
				cout << "-------------> Enter your Report\n";
				clinet[current_index].complaint[0] = clinet[current_index].user_name;
				ind[bb] = current_index;
				cin.ignore();
				getline(cin, clinet[current_index].complaint[1]);
				bb++;
				complaintscounter++;
				break;
			}
			else
			{
				break;
			}

		}


	}

	cout << "Enter anything to continue............\n";
	choice = _getch();
	system("cls");
}
void write_f_m()
{
	m_file.open("medicine.txt", ios::out);
	for (int i = 0;i < size_medicine;i++)
	{
		m_file << med[i].id << "#" << med[i].name << "#" << med[i].category
			<< "#" << med[i].description << "#" << med[i].price << "#"
			<< med[i].quantity_in_stock << "\n";


	}
	m_file.close();



}
void read_m()
{
	string line;
	m_file.open("medicine.txt", ios::in);
	for (int i = 0;i < size_medicine;i++)
	{
		getline(m_file, line, '#');med[i].id = stoi(line);
		getline(m_file, med[i].name, '#');
		getline(m_file, med[i].category, '#');
		getline(m_file, med[i].description, '#');
		getline(m_file, line, '#');med[i].price = stof(line);
		getline(m_file, line);med[i].quantity_in_stock = stoi(line);

	}

	m_file.close();
}
int page_1()
{


	system("cls");
	cout << "select an option : \n";
	cout << "1. edit user \n";
	cout << "2. delete user  \n";
	cout << "3. add user \n";
	cout << "4. back \n";
	cout << "______________ \n";
	choice = _getch();
	cout << "______________ \n";
	if (choice == '1') //editing information about user 
	{
		system("cls");
		editing_information_about_user();

	}
	else if (choice == '2') //deleting user 
	{
		system("cls");
		deleting_user();

	}
	else if (choice == '3') //adding new user 
	{
		system("cls");
		adding_users();
	}
	else if (choice == '4')
	{
		system("cls");
		return 0;
	}
	else
	{

		page_1();

	}

	page_1();

}
int page__2()
{


	system("cls");
	cout << "select an option : \n";
	cout << "1.edit name \n";
	cout << "2.edit description \n";
	cout << "3.edit category \n";
	cout << "4.edit price \n";
	cout << "5.edit id \n";
	cout << "6.edit quantity in stock \n";
	cout << "7.back \n";
	cout << "______________ \n";
	choice = _getch();
	cout << "______________ \n";
	if (choice == '1') //editing name of medicine 
	{
		system("cls");
		editing_name_of_medicine();
	}
	else if (choice == '2') //editing description of medicine 
	{
		system("cls");
		editing_description_of_medicine();
	}
	else if (choice == '3')  //editing category of medicine 
	{
		system("cls");
		editing_category_of_medicine();
	}
	else if (choice == '4') //editing price of medicine 
	{
		system("cls");
		editing_price_of_medicine();
	}
	else if (choice == '5') //editing id of medicine 
	{
		system("cls");
		editing_id_of_medicine();
	}
	else if (choice == '6') //editing quantity of medicine 
	{
		system("cls");
		editing_quantity_of_medicine();
	}
	else if (choice == '7')
	{
		return 0;
	}
	else
	{
		page__2();

	}

	page__2();
}
int page_2()
{


	system("cls");
	cout << "select an option : \n";
	cout << "1. edit medicine \n";
	cout << "2. delete medicine  \n";
	cout << "3. add medicine \n";
	cout << "4. back  \n";
	cout << "______________ \n";
	choice = _getch();
	cout << "______________ \n";
	if (choice == '1') //editing information about medicine 
	{
		page__2();
	}
	else if (choice == '2') //deleting medicine 
	{
		system("cls");
		deleting_medicine();
	}
	else if (choice == '3') //adding medicine 
	{
		system("cls");
		adding_new_medicine();
	}
	else if (choice == '4')
	{
		system("cls");
		return 0;
	}
	else
	{
		page_2();

	}
	page_2();
}
void page1_admin()
{
	cout<<"\033[1;33m";
	system("cls");
	cout << "#------------------------------------------->  WELCOME To Admin Department <------------------------------------------# \n\n";
	cout << "Select an option:\n";
	cout << "\033[1;31m" << 1 << "\033[1;0m" << ". manage users \n";
	cout << "\033[1;31m" << 2 << "\033[1;0m" << ". manage medicines \n";
	cout << "\033[1;31m" << 3 << "\033[1;0m" << ". manage orders \n";
	cout << "\033[1;31m" << 4 << "\033[1;0m" << ". manage payment \n";
	cout << "\033[1;31m" << 5 << "\033[1;0m" << ". display all customers profiles \n";
	cout << "\033[1;31m" << 6 << "\033[1;0m" << ". display complaints \n";
	cout << "\033[1;31m" << 7 << "\033[1;0m" << ". back to login page \n";
	cout << "\033[1;31m" << 8 << "\033[1;0m" << ". Exit\n";
	cout << "______________ \n";
	choice = _getch();
	cout << "______________ \n";
	if (choice == '1') //managing users
	{
		page_1();
	}

	else if (choice == '2') //managing medicines
	{
		page_2();
	}

	else if (choice == '3') //managing orders   ///////////////////////////////////////////////////////////////////////////////////////////
	{
		adminManageOrders();

	}
	else if (choice == '4') //managing payement/////////////////////////////////////////////////////////////////////////////////////
	{
		do {
			managing_ways_of_payment();
			cout << "do you wanna continue managing payement ? \n";
			cout << "1.yes \n";
			cout << "2.no \n";

			choice = _getch();
		} while (choice == '1');

	}
	else if (choice == '5') //diplaying profiles////////////////////////////////////////////////////////////////////////////////
	{
		displayUsers();
		do {
			cout << "do you wanna continue diplaying reports ? \n";
			cout << "1.yes \n";
			cout << "2.no \n";
			cout << "_\n";
			l01 = _getch();
		} while (l01 == 1);
	}

	else if (choice == '6') //diplaying reports////////////////////////////////////////////////////////////////////////////////
	{
		system("cls");
		cout << "#--------------------------------------------------> Page Of Complaints <-----------------------------------------#\n";
		reports();

		do {
			cout << "do you wanna continue diplaying complaints ? \n";
			cout << "1.yes \n";
			cout << "2.no \n";
			cout << "_\n";
			l01 = _getch();
		} while (l01 == 1);
	}
	else if (choice == '7')
	{

		system("cls");
		main();
	}
	else if (choice == '8')
	{

		write_f_m();
		cout << "#-----------------------------------------------> Thank You <-----------------------------------------------------#\n\n";
		Sleep(3000);
		exit(0);
	}
	else
	{
		system("cls");
		page1_admin();
	}
	page1_admin();
}
void signpage()
{
	cout << "\033[1;33m";
	cout << "#----------------------------------------------> welcome to the program <----------------------------------------------#\n\n";
	// loop for return to sign_up and log_in
	cout << "Select an option:\n";
	cout << "\033[1;31m" << 1 << "\033[1;0m" << ". Sign up\n";
	cout << "\033[1;31m" << 2 << "\033[1;0m" << ". Log in\n";
	cout << "Enter your choice number:\n";
	choice = getch();
	//system("cls");
	switch (choice)
	{
	case'1':
		system("cls");
		sign_up();
		main();
		system("cls");
		break;

	case'2':
		system("cls");
		log_in();
		break;

	default:
		system("cls");
		signpage();
	}
}
void page1_user()
{
	cout << "\033[1;33m";
	system("cls");
	if (clinet[current_index].usercancel != 0)
	{
		cout << "#-------------------------------------------> WELCOME To User Department <--------------------------------------------#\n\n";
		cout << "NOTICE  ::  Your last order Has been Canceled  <-------------#\n\n";
		complaints();
	}
	cout << "#-------------------------------------------> WELCOME To User Department <--------------------------------------------#\n\n";
	cout << "Please, Enter your choice number:\n";
	cout << "\033[1;31m" << 1<<"\033[1;0m"<<". Display Menu \n";
	cout << "\033[1;31m" << 2 << "\033[1;0m" << ". Search For Medicine\n";
	cout << "\033[1;31m" << 3 << "\033[1;0m" << ". Add New Order\n";
	cout << "\033[1;31m" << 4 << "\033[1;0m" << ". Edit Information\n";
	cout << "\033[1;31m" << 5 << "\033[1;0m" << ". Show Your Profile\n";
	cout << "\033[1;31m" << 6 << "\033[1;0m" << ". show orders recipet\n";
	cout << "\033[1;31m" << 7 << "\033[1;0m" << ". complaints\n";
	cout << "\033[1;31m" << 8 << "\033[1;0m" << ". log out\n";
	cout << "\033[1;31m" << 9 << "\033[1;0m" << ". Exit\n";
	choice = _getch();
	if (choice == '1')
	{
		displayMenu();

	}
	else if (choice == '2')
	{

		search_for_medicine();
	}
	else if (choice == '3')
	{
		AddNewOrder();
	}

	else if (choice == '4') {
		edit_information();
	}
	else if (choice == '5')
	{
		user_profile();
	}
	else if (choice == '6')
	{
		previous();
	}
	else if (choice == '7')
	{
		complaints();
	}

	else if (choice == '8')
	{

		current_index = 0;
		system("cls");
		main();
	}
	else if (choice == '9')
	{
		write_f_m();
		cout << "#--------------------------------------------------> Thank You <-----------------------------------------------------#\n\n";
		Sleep(3000);
		exit(0);
	}

	else
	{
		system("cls");
		page1_user();
	}

	page1_user();

}