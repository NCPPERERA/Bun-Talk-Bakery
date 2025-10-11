#include <iostream>
#include <vector>
#include <iomanip>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include <ctime>
#include <sstream>

using namespace std;


string itemName;
string currentUser = "";
char loc[20];

// ========== STRUCTS & DATA ==========
struct StockItem {
    int code;      // item code
    string name;   // item name
    float price;   // price
    int qty;       // quantity
};

// ===== Functions to load/save stock =====
vector<StockItem> loadStock() {
    vector<StockItem> items;
    ifstream in("stock.txt");
    if (!in) return items;
    StockItem s;
    while (in >> s.code >> s.name >> s.price >> s.qty) {
        items.push_back(s);
    }
    return items;
}

void saveStock(const vector<StockItem>& items) {
    ofstream out("stock.txt");
    for (const auto &it : items) {
        out << it.code << " " << it.name << " "
            << it.price << " " << it.qty << "\n";
    }
}




char *date_time (); //set local date
void page();    //first page
void select();
void adminPanel();
void stockManagementMenu();
void userManagementMenu();
void adminLogin();
void resetPassword();
void exit();    //exit from program
void login();   //system login
void registr();
void forgot();
void help();
void item();    //baked goods
void gotoxy (int x, int y);
void frame ();			//frame for every tab
void flow(char *ch);
void flow_1(char *ch);
COORD coord = {0, 0};
class date;
class machine



{
    	private:

	int day,month,year,hour,min,sec;

};
class date		//class current date and time of system
{


	public:
		int aday,amonth,ayear,ahour,amin,asec;
	void date_times()
	{
		SYSTEMTIME t;		//pre defined in time.h header
 		GetLocalTime(&t);
		aday=t.wDay,amonth=t.wMonth,ayear=t.wYear,ahour=t.wHour,amin=t.wMinute,asec=t.wSecond;

	}
};
char *date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;	//returns local time and date
}
void gotoxy (int x, int y)	//defining/initializing to predefined objects
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// helper to get current timestamp
string getTimestamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buf[30];
    sprintf(buf, "%02d-%02d-%04d_%02d%02d%02d",
            ltm->tm_mday, ltm->tm_mon+1, 1900+ltm->tm_year,
            ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    return string(buf);
}
void frame()
{
	int i,j=79;
	for(i = 0;i<80,j>=0;i++,j--)
	{
		gotoxy(i,4);
		Sleep(10);
		cout<<"~";
		gotoxy(j,22);
		Sleep(10);
		cout<<"~";

	}
	gotoxy(56,1);
	char s[20];
    strcpy(s,date_time());      //every frame has date on the right top
	cout<<s;
}

void flow(char *ch)	//flow of instructions
{
	char *str=ch;
	for(int i=0;i<strlen(str);i++)
	{
		Sleep(25);
		cout<<str[i];
	}

}
void flow_1(char *ch)	//flow of loading....
{
	char *str=ch;
	for(int i=0;i<strlen(str);i++)
	{
		Sleep(500);
		cout<<str[i];
	}

}
void scroll_note()	//welcome note
{
    system("color E0");
	int j,i,x,y;
	for(i=0;i<27;i++)
	{
		gotoxy(i,13);cout<<" ";
		cout<<"BUN TALK BAKERY SERVICES";
		Sleep(30);
	}

	for(int j=78;j>=0;j--)
	{
		gotoxy(j,22);cout<<"*";
		gotoxy(j,4);cout<<"*";
		Sleep(25);
	}
	gotoxy(2,23);cout<<"Chandima   st20286812";
	Sleep(2000);
	page();


}

 void page()        //this is the home page of the program.
{
    system("COLOR B0");
    system("cls");
    frame();

    int choice;
    gotoxy(32,3);
    cout<<"WELCOME TO LOGIN PAGE";
    gotoxy(38,7);
    cout<<"1.LOGIN"<<endl;
    gotoxy(37,10);
    cout<<"2.REGISTER"<<endl;




    gotoxy(29,13);
    cout<<"3.FORGOT PASSWORD / USERNAME"<<endl;
    gotoxy(39,16);
    cout<<"4.HELP"<<endl;
    gotoxy(70,20);
    cout<<"6.EXIT"<<endl;
    gotoxy(35,19);
    cout << "5.ADMIN LOGIN"<<endl;


    gotoxy(2,23);
    cout<<"ENTER:- ";
    cin>>choice;

    cout<<endl;
    switch(choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:
        help();
        break;

    case 5:
        adminLogin();
        break;
    case 6://exit
        exit();
        break;



    default:
        system("cls");
        for(int i=0;i<25;i++)
	{
		gotoxy(4,i);
		cout<<"|";
		gotoxy(80,i);
		cout<<"|";
	}
        gotoxy(30,3);
        flow("PLEASE ENTER VALIED NUMBER");
        gotoxy(35,6);
        flow("TRY AGAIN...");
        cin.get();
        getch();
        page();

    }while (choice != 5);

}
void login() {
    system("COLOR 90");
    system("cls");
    frame();
    int count = 0;
    string user, pass, u, p;

    gotoxy(35,3);
    cout << "SIGN IN" << endl;
    gotoxy(8,7);
    cout << "USERNAME :";
    cin >> user;
    gotoxy(8,10);
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("database.txt");
    while (input >> u >> p) {
        if (u == user && p == pass) {
            count = 1;
            currentUser = user;   // store logged-in user globally
            system("cls");
        }
    }
    input.close();

    if (count == 1) {
        system("cls");
        for (int i = 0; i < 25; i++) {
            gotoxy(4, i);
            cout << "|";
            gotoxy(80, i);
            cout << "|";
        }
        gotoxy(35,10);
        cout << "Loading";
        gotoxy(42,10);
        flow_1("......!");
        gotoxy(36,13);
        cout << "Hello " << currentUser;
        gotoxy(33,14);
        cout << "LOGIN SUCCESSFUL";
        cin.get();
        getch();
        select();   // go to main menu
    }
    else {
        system("cls");
        for (int i = 0; i < 25; i++) {
            gotoxy(4, i);
            cout << "|";
            gotoxy(80, i);
            cout << "|";
        }
        gotoxy(35,10);
        cout << "Loading";
        gotoxy(42,10);
        flow_1("......!");

        gotoxy(6,12);
        cout << "ERROR !";
        gotoxy(6,13);
        cout << "YOUR USERNAME OR PASSWORD IS INVALID";
        cin.get();
        getch();
        page();
    }
}

 void registr()		//create account for log to bun talk bakery service
{
    system("COLOR C0");
    system("cls");
	string reguser,regpass,ru,rp;
     	for(int i=0;i<25;i++)
	{
		gotoxy(4,i);
		cout<<"|";
		gotoxy(80,i);
		cout<<"|";
	}
     gotoxy(29,2);
     cout<<"APLICATION FORM";
     gotoxy(5,6);
     cout<<"ENTER THE FIRST NAME :";
     cin>>reguser;
     gotoxy(5,8);
     cout<<"ENTER THE PASSWORD :";
     cin>>regpass;

     ofstream reg("database.txt",ios::app);
     reg<<reguser<<' '<<regpass<<endl;
     system("cls");

        gotoxy(35,10);
        cout<<"Loading";
        gotoxy(42,10);
        flow_1("......!");

     gotoxy(30,14);
     cout<<"REGISTRATION SUCCESSFUL\n";
     cin.get();
     getch();
     page();

}
void forgot()
 {  system("COLOR A0");
    system("cls");
    int ch;
    system("cls");
    for(int i=0;i<25;i++)
    {
		gotoxy(4,i);
		cout<<"|";
		gotoxy(80,i);
		cout<<"|";
	}
	gotoxy(25,4);
    cout<<"FORGOTEN ? WE'ER HERE FOR HELP!";
    gotoxy(7,8);
    cout<<"1.FIND YOUR PASSWORD BY USERNAME";
    gotoxy(7,10);
    cout<<"2.FIND YOUR USERNAME BY PASSWORD";
    gotoxy(7,12);
    cout<<"3.BACK";
    gotoxy(5,16);
    cout<<"ENTER YOUR CHOICE : ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        {
            system("cls");
            for(int i=0;i<25;i++)
    {
		gotoxy(4,i);
		cout<<"|";
		gotoxy(80,i);
		cout<<"|";
	}
            int count=0;
            string searchuser,su,sp;
            gotoxy(8,5);
            cout<<"ENTER YOUR REMEMBER USERNAME :";
            cin>>searchuser;

            ifstream searchu("database.txt");
            while(searchu>>su>>sp)
            {
                if(su==searchuser)
                {
                    count=1;

                }
            }
            searchu.close();
            if(count==1)

            {
                system("cls");
                        for(int i=0;i<25;i++)
                        {
                            gotoxy(4,i);
                            cout<<"|";
                            gotoxy(80,i);
                            cout<<"|";
                        }
        gotoxy(35,10);
        cout<<"Loading";
        gotoxy(42,10);
        flow_1("......!");
                gotoxy(8,12);
                cout<<"YOUR ACCOUNT FOUND";
                gotoxy(8,14);
                cout<<"YOUR PASSWORD IS:- "<<sp;
                cin.get();
                cin.get();
                gotoxy(35,4);
                system("cls");
                page();

            }
            else
            {
                system("cls");
                        for(int i=0;i<25;i++)
                        {
                            gotoxy(4,i);
                            cout<<"|";
                            gotoxy(80,i);
                            cout<<"|";
                        }
                gotoxy(35,10);
                cout<<"Loading";
                gotoxy(42,10);
                flow_1("......!");

                gotoxy(5,12);
                cout<<"SORRY, YOUR USERID IS NOT FOUNND IN OUR DATABASE";
                gotoxy(5,14);
                cout<<"PLEASE KINDLY CONTACT OUR SYSTEM ADMINISTRATORFOR MORE DETAILS";
                cin.get();
                cin.get();
                system("cls");
                page();

            }
            break;
        }
    case 2:
        {
            system("cls");
            for(int i=0;i<25;i++)
                {
                    gotoxy(4,i);
                    cout<<"|";
                    gotoxy(80,i);
                    cout<<"|";
                }
            int count=0;
            string searchpass,su2,sp2;
            gotoxy(8,5);
            cout<<"ENTER THE REMEMBERED PASSWORD :";
            cin>>searchpass;

            ifstream searchp("database.txt");
            while(searchp>>su2>>sp2)
            {
                if(sp2==searchpass)
                {
                    count=1;
                }
            }
            searchp.close();
            if(count==1)
            {
                system("cls");
                        for(int i=0;i<25;i++)
                        {
                            gotoxy(4,i);
                            cout<<"|";
                            gotoxy(80,i);
                            cout<<"|";
                        }
                gotoxy(35,10);
                cout<<"Loading";
                gotoxy(42,10);
                flow_1("......!");

                gotoxy(8,12);
                cout<<"YOUR ACCOUNT FOUND";
                 gotoxy(8,14);
                cout<<"YOUR USERNAME IS:- "<<su2;
                getch();
                page();
            }
            else
            {
                system("cls");
                        for(int i=0;i<25;i++)
                        {
                            gotoxy(4,i);
                            cout<<"|";
                            gotoxy(80,i);
                            cout<<"|";
                        }
                gotoxy(5,5);
                cout<<"SORRY, YOUR PASSWORD IS NOT FOUNND IN OUR DATABASE";
                gotoxy(5,7);
                cout<<"PLEASE KINDLY CONTACT OUR SYSTEM ADMINISTRATORFOR MORE DETAILS";
                cin.get();
                cin.get();
                system("cls");
                page();
            }
            break;
        }
    case 3: //back to login page
        {
            cin.get();
            page();

        }
    default:
        system("cls");
                        for(int i=0;i<25;i++)
                        {
                            gotoxy(4,i);
                            cout<<"|";
                            gotoxy(80,i);
                            cout<<"|";
                        }
        gotoxy(5,5);
        cout<<"ERROR! PLEASE ENTER VALIED NUMBER. KINDLY TRY AGAIN"<<endl;
        getch();
        forgot();
    }
 }


void resetPassword() {
    system("cls");
    string oldPass, newPass, u, p;
    int found = 0;

    gotoxy(10,5);
    cout << "Enter old password: ";
    cin >> oldPass;

    fstream file("database.txt");
    vector<pair<string,string>> records;
    while (file >> u >> p) {
        if (u == currentUser && p == oldPass) {
            found = 1;
            gotoxy(10,7);
            cout << "Enter new password: ";
            cin >> newPass;
            records.push_back({u, newPass});
        } else {
            records.push_back({u, p});
        }
    }
    file.close();

    if (found) {
        ofstream out("database.txt");
        for (auto &rec : records) {
            out << rec.first << " " << rec.second << "\n";
        }
        out.close();
        gotoxy(10,9);
        cout << "Password changed successfully!";
    } else {
        gotoxy(10,9);
        cout << "Old password incorrect!";
    }
    getch();
    select();
}





 void help()
 {
     {
	system("cls");
	system("COLOR 70");
		for(int i=0;i<28;i++)
	{
		gotoxy(4,i);
		cout<<"|";
		gotoxy(80,i);
		cout<<"|";
	}
	gotoxy(35,0);
	cout<<"HELP PAGE";
	gotoxy(5,2);
	cout<<"BUN TALK BAKERY SERVICE";

	gotoxy(5,25);
	cout<<"FOR MORE INFORMATION, CONTACT:";
	gotoxy(5,26);
	cout<<"CALL OUR HELPLINE - 0112 255 555";
	gotoxy(5,27);
	cout<<"EMAIL: pererachandima068@gmail.com";

	gotoxy(5,5);
	flow("YOU MIGHT HAVE ALREADY CREATE AN ACCOUNT PREVIUSLY.");
	gotoxy(5,8);
	flow("CREATE ACCOUNT : * Go to register page and enter your first name & password");
	gotoxy(5,10);
	flow("FORGET USER NAME OR PASSWORD : * First select your forgot uname or password");
	gotoxy(35,12);
	flow(" * enter your remember uname or password");
	gotoxy(5,15);
	flow("HOW TO ORDER : * You have to login first");
	gotoxy(19,17);
	flow(" * Then go to show menu");
	gotoxy(19,19);
	flow(" * Enter the Item code & enter the quantity how much you want");
	gotoxy(19,21);
	flow(" * If you want more items press 'y'/ Not press 'n'");
	gotoxy(19,23);
	flow(" * If your orders finish then print the bill & pay amount");

	getch();
	page();
}
}

void select() {
    system("COLOR A0");
    system("cls");
    frame();
    int ab;
    gotoxy(30,3);
    cout << "WELCOME TO BUN TALK BAKERY, " << currentUser << "!" << endl;
    gotoxy(36,7);
    cout << "1. SHOW MENU" << endl;
    gotoxy(36,10);
    cout << "2. RESET PASSWORD" << endl;
    gotoxy(36,13);
    cout << "3. LOGOUT" << endl;
    gotoxy(36,16);
    cout << "4. EXIT" << endl;
    gotoxy(2,23);
    cout << "Enter your choice: ";
    cin >> ab;

    switch (ab) {
        case 1:
            item();
            break;
        case 2:
            resetPassword();
            break;
        case 3:
            page();
            break;
        case 4:
            exit();
            break;
        default:
            system("cls");
            for (int i = 0; i < 25; i++) {
                gotoxy(4, i);
                cout << "|";
                gotoxy(80, i);
                cout << "|";
            }
            gotoxy(6,3);
            flow("PLEASE ENTER VALID NUMBER");
            gotoxy(6,6);
            flow("TRY AGAIN...");
            cin.get();
            getch();
            select();
    }
}

void exit()
{
    system("COLOR 40");
        system("cls");
        for(int i=0;i<25;i++)
                        {
                            gotoxy(4,i);
                            cout<<"|";
                            gotoxy(80,i);
                            cout<<"|";
                        }

        gotoxy(25,3);
        flow("THANKS FOR USING THIS PROGRAM");
        gotoxy(15,6);
        flow("THIS PROGRAM IS CREATED FOR THE PROGRAMMING MODULE");
        gotoxy(16,24);
        flow("NAWAGAMUWAGE CHANDIMA PASAN PERERA - st20286812\n");
        cin.get();
        getch();
        exit(0);
}
struct OrderItem {
    string name;  // item name
    int qty;      // quantity
    float amt;    // total amount for this item (price * qty)
};


void item() {
    system("COLOR 1E");
    system("cls");

    int code, qty;
    float amt, totalAmt = 0, cash, change;
    char addAnother;
    vector<OrderItem> orderItems;

    // ⭐ Load stock once at start
    vector<StockItem> stock = loadStock();

    do {
        system("cls");
        gotoxy(40,1);
        cout << "MENU\n";

        // Print stock
        gotoxy(3,4);
        cout << left << setw(10) << "CODE"
             << setw(25) << "ITEM"
             << setw(10) << "PRICE"
             << setw(10) << "QTY\n";
        cout << "---------------------------------------------------\n";


       for (auto &s : stock) {
    cout << left
         << setw(10) << s.code
         << setw(25) << s.name
         << setw(12) << ("Rs. " + to_string((int)s.price))  // extra width for spacing
         << setw(10) << s.qty
         << endl;
}


        // Customer selects item
        gotoxy(3,23);
        cout << "ENTER CODE: ";
        cin >> code;
        gotoxy(3,24);
        cout << "ENTER QUANTITY: ";
        cin >> qty;

        // Find item in stock
        string itemName = "";
        float price = 0;
        bool found = false;

        for (auto &s : stock) {
            if (s.code == code) {
                found = true;
                itemName = s.name;
                price = s.price;

                if (s.qty >= qty) {
                    // ⭐ Reduce stock
                    s.qty -= qty;

                    amt = price * qty;
                    totalAmt += amt;
                    orderItems.push_back({itemName, qty, amt});

                    gotoxy(3,23);
                    cout << "Added " << qty << " x " << itemName
                         << " = Rs. " << amt;
                } else {
                    gotoxy(3,23);
                    cout << "Not enough stock! Only " << s.qty << " left.";
                }
                break;
            }
        }

        if (!found) {
            gotoxy(3,23);
            cout << "Invalid code! Try again.";
            getch();
        }

        gotoxy(3,24);
        cout << "ADD ANOTHER ORDER (Y/N)? : ";
        addAnother = getch();

    } while(addAnother == 'y' || addAnother == 'Y');

    // ⭐ Save updated stock back to file
    saveStock(stock);

    // Show receipt
    system("cls");
    cout << "\n\n\n";
    cout << "-------------------------------------------\n";
    cout << "             ORDER SUMMARY\n";
    cout << "-------------------------------------------\n";
    cout << left << setw(20) << "ITEM"
         << setw(10) << "QTY"
         << setw(10) << "AMOUNT\n\n";
    cout << "--------------------------------------\n";
    for (auto &it : orderItems) {
        cout << left << setw(20) << it.name
             << setw(10) << it.qty
             << "Rs. " << fixed << setprecision(2) << it.amt << "\n";
    }
    cout << "--------------------------------------\n";
    cout << "TOTAL AMOUNT: Rs. " << totalAmt << "\n";

    // Accept cash
    do {
        cout << "CASH: Rs. ";
        cin >> cash;
        if (cash < totalAmt) {
            cout << "Insufficient cash! Please enter again.\n";
        }
    } while(cash < totalAmt);

    change = cash - totalAmt;

    // Save digital receipt
    string filename = "receipt_" + currentUser + "_" + getTimestamp() + ".txt";
    ofstream receipt(filename);
    receipt << "--------------------------------------------\n";
    receipt << "             BUN TALK BAKERY\n";
    receipt << "--------------------------------------------\n";
    receipt << "Date: " << getTimestamp() << "\n";
    receipt << "Customer: " << currentUser << "\n\n";
    receipt << left << setw(20) << "Item"
            << setw(10) << "Qty"
            << setw(10) << "Amount\n\n";
    receipt << "------------------------------------------\n";
    for (auto &it : orderItems) {
        receipt << left << setw(20) << it.name
                << setw(10) << it.qty
                << "Rs. " << fixed << setprecision(2) << it.amt << "\n";
    }
    receipt << "--------------------------------------------\n";
    receipt << "                    TOTAL   : Rs. " << totalAmt << "\n";
    receipt << "                    CASH    : Rs. " << cash << "\n";
    receipt << "                    CHANGE  : Rs.- " << change << "\n";
    receipt << "--------------------------------------------\n";
    receipt << "               WELCOME AGAIN\n";
    receipt << "     Thank you for shopping with us!\n";
    receipt << "--------------------------------------------\n";
    receipt.close();

    // Print receipt on screen
    system("cls");
    cout << "Receipt saved as: " << filename << "\n";
    ifstream bill(filename);
    string line;
    while(getline(bill, line)) cout << line << endl;
    bill.close();

    getch();
    select(); // Return to main menu
}




void adminLogin() {
    system("cls");
    system("COLOR 0A");
    frame();

    string adminUser, adminPass;
    string correctUser = "admin";   // You can set/change
    string correctPass = "1234";    // You can set/change

    gotoxy(35,3);
    cout << "ADMIN LOGIN";
    gotoxy(10,7);
    cout << "Username: ";
    cin >> adminUser;
    gotoxy(10,10);
    cout << "Password: ";
    cin >> adminPass;

    if (adminUser == correctUser && adminPass == correctPass) {
        gotoxy(25,15);
        cout << "Login Successful!";
        Sleep(1200);
        adminPanel();
    } else {
        gotoxy(20,15);
        cout << "Invalid Admin Credentials!";
        getch();
        page(); // go back to main menu
    }
}

void viewUsers() {
    system("cls");
    frame();
    ifstream in("database.txt");
    string u, p;
    gotoxy(32,3);
    cout << "USER LIST\n\n"<<endl;
    while (in >> u >> p) {
        cout << "       Username: " << u << "      |     Password: " << p << endl;
    }
    in.close();
    gotoxy(2,23);
    cout<<"PRESS ENTER TO RETURN";
    getch();
    userManagementMenu();
}

void addUser() {
    system("cls");
    frame();
    string u, p;
    gotoxy(10,7);
    cout << "Enter new username: ";
    cin >> u;
    gotoxy (10,9);
    cout << "Enter password: ";
    cin >> p;

    ofstream out("database.txt", ios::app);
    out << u << " " << p << endl;
    out.close();

    gotoxy (25,13);
    cout << "User added successfully!\n";
    getch();
    userManagementMenu();
}

void editUser() {
    system("cls");
    string searchUser, u, p;
    vector<pair<string,string>> users;
    bool found = false;

    gotoxy(10,7);
    cout << "Enter username to edit: ";
    cin >> searchUser;

    ifstream in("database.txt");
    while (in >> u >> p) {
        if (u == searchUser) {
            found = true;
             gotoxy(13,11);
            cout << "Enter new username: ";
            cin >> u;
             gotoxy(13,13);
            cout << "Enter new password: ";
            cin >> p;
        }
        users.push_back({u,p});
    }
    in.close();

    if (found) {
        ofstream out("database.txt");
        for (auto &usr : users) {
            out << usr.first << " " << usr.second << endl;
        }
        out.close();
         gotoxy(25,15);
        cout << "User updated successfully!\n";
    } else {
         gotoxy(25,15);
        cout << "User not found!\n";
    }

    getch();
    userManagementMenu();
}

void deleteUser() {
    system("cls");
    string searchUser, u, p;
    vector<pair<string,string>> users;
    bool found = false;

     gotoxy(10,7);
    cout << "Enter username to delete: ";
    cin >> searchUser;

    ifstream in("database.txt");
    while (in >> u >> p) {
        if (u == searchUser) {
            found = true;
            continue; // skip this user
        }
        users.push_back({u,p});
    }
    in.close();

    if (found) {
        ofstream out("database.txt");
        for (auto &usr : users) {
            out << usr.first << " " << usr.second << endl;
        }
        out.close();
         gotoxy(25,13);
        cout << "User deleted successfully!\n";
    } else {
         gotoxy(25,15);
        cout << "User not found!\n";
    }

    getch();
    userManagementMenu();
}



// ====== USER MANAGEMENT MENU ======
void userManagementMenu() {
    system("cls");
    frame();
    int choice;
    gotoxy(32,3);
    cout<<"USER MANAGEMENT";
    gotoxy(38,7);  cout << "1. VIEW USERS"<<endl;
    gotoxy(38,10); cout << "2. ADD USER"<<endl;
    gotoxy(38,13); cout << "3. EDIT USER"<<endl;
    gotoxy(38,16); cout << "4. DELETE USER"<<endl;
    gotoxy(38,19); cout << "5. BACK"<<endl;
    gotoxy(2,23);
    cout<<"ENTER:- ";
    cin >> choice;

    switch(choice) {
        case 1: viewUsers(); break;
        case 2: addUser(); break;
        case 3: editUser(); break;
        case 4: deleteUser(); break;
        case 5: adminPanel(); break;
        default: cout<<"Invalid choice!"; getch(); userManagementMenu();
    }
}

// ====== STOCK MANAGEMENT FUNCTIONS ======
void viewStock() {
    system("cls");
    //frame();
    ifstream in("stock.txt");
    StockItem s;
    gotoxy(28,3);
    cout << "STOCK LIST\n\n";
    cout << left << setw(10) << "Code"
         << setw(20) << "Item"
         << setw(12) << "Price"
         << setw(10) << "Qty\n";
    gotoxy(0,5);
    cout << "----------------------------------------------------------\n";
    while (in >> s.code >> s.name >> s.price >> s.qty) {
        cout << left
             << setw(10) << s.code
             << setw(20) << s.name
             << setw(12) << ("Rs. " + to_string((int)s.price))  // price with spacing
             << setw(10) << s.qty  // quantity column properly spaced
             << "\n";
    }
    in.close();
    getch();
    stockManagementMenu();
}

void addStock() {
    system("cls");
    frame();

    char choice;
    gotoxy(10,8);
    cout << "[A] Add New Item";
    gotoxy(50,8);
    cout << "[B] Back";

    gotoxy(10,12);
    cout << "Choose Option (A/B): ";
    cin >> choice;

    if (choice == 'b' || choice == 'B') {
        stockManagementMenu(); // Go back without adding
        return;
    }

    // Continue to add new item
    StockItem s;
    gotoxy(10,10); cout << "Enter item code: "; cin >> s.code;
    gotoxy(10,12); cout << "Enter item name: "; cin >> s.name;
    gotoxy(10,14); cout << "Enter price: "; cin >> s.price;
    gotoxy(10,16); cout << "Enter quantity: "; cin >> s.qty;

    ofstream out("stock.txt", ios::app);
    out << s.code << " " << s.name << " " << s.price << " " << s.qty << endl;
    out.close();

    gotoxy(25,18);
    cout << "Item added successfully!\n";
    gotoxy(25,20);
    cout << "Press any key to return...";
    getch();

    stockManagementMenu(); // Return to stock menu
}


void editStock() {
    system("cls");
    frame();

    char choice;
    gotoxy(10,6);
    cout << "[E] Edit Item";
    gotoxy(30,6);
    cout << "[B] Back ";

    gotoxy(10,8);
    cout << "Choose Option (E/B): ";
    cin >> choice;

    if (choice == 'b' || choice == 'B') {
        stockManagementMenu(); // Back to stock menu
        return;
    }

    // Continue with editing
    int searchCode;
    gotoxy(10,10); cout << "Enter item code to edit: "; cin >> searchCode;

    ifstream in("stock.txt");
    vector<StockItem> items;
    StockItem s;
    bool found = false;
    while (in >> s.code >> s.name >> s.price >> s.qty) {
        if (s.code == searchCode) {
            found = true;
            gotoxy(10,12); cout << "Enter new name: "; cin >> s.name;
            gotoxy(10,14); cout << "Enter new price: "; cin >> s.price;
            gotoxy(10,16); cout << "Enter new quantity: "; cin >> s.qty;
        }
        items.push_back(s);
    }
    in.close();

    if (found) {
        ofstream out("stock.txt");
        for (auto &it : items)
            out << it.code << " " << it.name << " "
                << it.price << " " << it.qty << endl;
        out.close();
        gotoxy(25,18); cout << "Item updated successfully!\n";
    } else {
        gotoxy(25,18); cout << "Item not found!\n";
    }

    gotoxy(25,20);
    cout << "Press any key to return...";
    getch();
    stockManagementMenu();
}


void deleteStock() {
    system("cls");
    frame();
    int searchCode;
    gotoxy(10,7); cout << "Enter item code to delete: "; cin >> searchCode;

    ifstream in("stock.txt");
    vector<StockItem> items;
    StockItem s;
    bool found = false;
    while (in >> s.code >> s.name >> s.price >> s.qty) {
        if (s.code == searchCode) {
            found = true;
            continue; // skip this item
        }
        items.push_back(s);
    }
    in.close();

    if (found) {
        ofstream out("stock.txt");
        for (auto &it : items)
            out << it.code << " " << it.name << " "
                << it.price << " " << it.qty << endl;
        out.close();
        gotoxy(25,13); cout << "Stock deleted!\n";
    } else {
        gotoxy(25,13); cout << "Item not found!\n";
    }

    getch();
    stockManagementMenu();
}


// ====== STOCK MANAGEMENT MENU ======
void stockManagementMenu() {
    system("cls");
    frame();
    int choice;
    gotoxy(32,3);
    cout<<"STOCK MANAGEMENT";
    gotoxy(38,7);  cout << "1. VIEW STOCK"<<endl;
    gotoxy(38,10); cout << "2. ADD STOCK"<<endl;
    gotoxy(38,13); cout << "3. EDIT STOCK"<<endl;
    gotoxy(38,16); cout << "4. DELETE STOCK"<<endl;
    gotoxy(38,19); cout << "5. BACK"<<endl;
    gotoxy(2,23);
    cout<<"ENTER:- ";
    cin >> choice;

    switch(choice) {
        case 1: viewStock(); break;
        case 2: addStock(); break;
        case 3: editStock(); break;
        case 4: deleteStock(); break;
        case 5: adminPanel(); break;
        default: cout<<"Invalid choice!"; getch(); stockManagementMenu();
    }
}

// ====== ADMIN PROFILE ======
void adminProfile() {
    system("cls");
    frame();
    gotoxy(32,3);
    cout<<"ADMIN PROFILE";
    gotoxy(10,7);
    cout<<"Username: admin";
    gotoxy(10,9);
    cout<<"Email: admin@buntalk.com";
    gotoxy(10,11);
    cout<<"(Future: add change password here)";
    getch();
    adminPanel();
}

void adminPanel() {
    system("cls");
    frame();
    int choice;
    gotoxy(32,3);
    cout<<"WELCOME TO ADMIN HOME";
    gotoxy(35,7);  cout << "1. USER MANAGEMENT"<<endl;
    gotoxy(35,10); cout << "2. STOCK MANAGEMENT"<<endl;
    gotoxy(35,13); cout << "3. ADMIN PROFILE"<<endl;
    gotoxy(35,16); cout << "4. LOGOUT"<<endl;
    gotoxy(2,23);
    cout<<"ENTER:- ";
    cin >> choice;

    switch(choice) {
        case 1: userManagementMenu(); break;
        case 2: stockManagementMenu(); break;
        case 3: adminProfile(); break;
        case 4: page(); break;
        default: cout<<"Invalid choice!"; getch(); adminPanel();
    }
}


int main()
{
	scroll_note();//welcome note
	page();
	return 0;
}//END OF THE CODE




