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

using namespace std;

char loc[20];
char *date_time (); //set local date
void page();    //first page
void select();
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
    cout<<"5.EXIT"<<endl;
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
    case 5://exit
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
void login(){
    system("COLOR 90");
    system("cls");
    frame();
    int count;
    string user,pass,u,p;

     gotoxy(35,3);
     cout<<"SIGN IN"<<endl;
     gotoxy(8,7);
     cout<<"USERNAME :";
     cin>>user;
     gotoxy(8,10);
     cout<<"PASSWORD :";
     cin>>pass;

     ifstream input ("database.txt");
     while(input>>u>>p)
     {
         if(u==user && p==pass)
         {
             count=1;
             system("cls");
         }
     }
     input.close();
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
         gotoxy(36,13);
         cout<<"Hello "<<user;
         gotoxy(33,14);
         cout<<"LOGIN SUCCSESSFUL";
         cin.get();
         getch();
         select();

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

        gotoxy(6,12);
        cout<<"ERROR !";
        gotoxy(6,13);
        cout<<"YOUR USERNAME OR PASSWORD IS INVALIED";
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

void select()
 {
    system("COLOR A0");
    system("cls");
    frame();
    int ab;
    gotoxy(30,3);
    cout<<"WELCOME TO BUN TALK BAKERY!" << endl;
    gotoxy(36,7);
    cout << "1. SHOW MENU" << endl;
    gotoxy(37,10);
    cout << "2. LOGOUT" << endl;
    gotoxy(38,13);
    cout << "3. EXIT" << endl;
    gotoxy(2,23);
    cout << "Enter your choice: ";

    cin >> ab;
    switch(ab)
    {
    case 1 :
        {
            item();
            break;
        }
    case 2 :
        {
            page();
            break;
        }

    case 3:{
            exit();
            break;
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
        gotoxy(6,3);
        flow("PLEASE ENTER VALIED NUMBER");
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

void item() //if user login success then show this menu
            //display the menu and get user's item choice
{
    system("COLOR 1E");
    system("cls");
    int code,qty;
    float price,amt,totalAmt, cash, change;
    char addAnother;

    do {
            system("cls");
            gotoxy(40,1);
            printf("MENU");
            gotoxy(12,4);
            printf("BAKED GOODS");
            gotoxy(3,6);
            printf("CODE\t  ITEM\t\t    PRICE");
            gotoxy(4,7);
            printf("1.\tBURGER \t\t    RS. 250.00");
            gotoxy(4,8);
            printf("2.\tCHICKEN ROLLS \t    RS. 120.00\n" );
            gotoxy(4,9);
            printf("3.\tFISH BUN \t    RS.  80.00");
            gotoxy(4,10);
            printf("4.\tEGG BUN \t    RS. 120.00");
            gotoxy(4,11);
            printf("5.\tBREADS \t\t    RS. 130.00");
            gotoxy(4,12);
            printf("6.\tEGG PASTRY \t    RS.  90.00");
            gotoxy(4,13);
            printf("7.\tFISH PASTRY \t    RS. 110.00");
            gotoxy(4,14);
            printf("8.\tCHICKEN PASTRY \t    RS. 130.00");
            gotoxy(4,15);
            printf("9.\tBUTTER CAKE 1Kg     RS. 930.00");
            gotoxy(4,16);
            printf("10.\tCHOCOLATE CAKE 1Kg  RS.1100.00");

            gotoxy(65,4);
            printf("BEVERAGES");
            gotoxy(50,6);
            printf("CODE\t  ITEM\t\t\t    PRICE");
            gotoxy(51,7);
            printf("11.\tCHOCOLATE MILK SHAKE \t RS. 350.00");
            gotoxy(51,8);
            printf("12.\tLATTE \t\t\t RS. 600.00");
            gotoxy(51,9);
            printf("13.\tAMERICANO \t\t RS. 500.00");
            gotoxy(51,10);
            printf("14.\tICE KIT KAT \t\t RS. 900.00");
            gotoxy(51,11);
            printf("15.\tBLACK TEA \t\t RS. 350.00");
            gotoxy(51,12);
            printf("16.\tCAPPUCCINO \t\t RS. 600.00\n");

    printf("\n\n\n\n\n\tENTER CODE\t: ");
    scanf ("%d", &code);

    printf("\n\tENTER QUANTITY\t:");
    scanf("%d",&qty);

    switch (code){
    case 1: price = 250.00;
    break;
    case 2: price = 120.00;
    break;
    case 3: price = 80.00;
    break;
    case 4: price = 120.00;
    break;
    case 5: price = 130.00;
    break;
    case 6: price = 90.00;
    break;
    case 7: price = 110.00;
    break;
    case 8: price = 130.00;
    break;
    case 9: price = 930.00;
    break;
    case 10: price = 1100.00;
    break;
    case 11: price = 350.00;
    break;
    case 12: price = 600.00;
    break;
    case 13: price = 500.00;
    break;
    case 14: price = 900.00;
    break;
    case 15: price = 350.00;
    break;
    case 16: price = 600.00;
    break;

    }
    amt = price * qty;
    gotoxy(3,21);
    printf("\n\tAMOUNT\t\t: %.2f",amt);

    totalAmt = totalAmt + amt;
    gotoxy(3,22);
    printf("\n\tTOTAL AMOUNT\t: %.2f", totalAmt);
    gotoxy(3,23);
    printf("\n\tADD ANOTHER ORDER(Y/N)? :");
    addAnother = getch();

    }while (addAnother == 'y'|| addAnother == 'Y');

            do {
                printf("\n\tCASH\t: ");
                scanf("%f", &cash);
                }
            while(cash < totalAmt);

            change = cash - totalAmt;
            printf("\n\tCHANGE\t: %.2f",change);
            cin.get();
            getch();
            select();
}

int main()
{
	scroll_note();//welcome note
	page();
	return 0;
}//END OF THE CODE




