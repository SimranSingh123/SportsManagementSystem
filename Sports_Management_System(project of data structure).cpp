#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct player
{
    long ID;
	string firstname;
	string lastname;
	int age;
	char blood[5];
	char gender;
    player *next;
};
class linkedqueue
{
	player *head,*last;
	public:
	linkedqueue() //constructor
	{
		head=NULL;
		last=NULL;
	}
    player input();
    void insertatend();
    void insertatbeg();
    void getplayerout();
    void listofplayers();
    int search(int);
    char departmentname[50];
};

int linkedqueue :: search(int item)
{
	 if(head==NULL)
     {
     return false;
     }
     else
     {
     int flag=0;
     player*p=new player();
     p=head;

     while( p->next!=NULL && p->ID!=item )
     {
        p=p->next;
     }
     if(p->ID==item)
     {
	 	flag=1;
	 	return true;
     }
     if(flag==0)
     {
     return false;
     }
     }
}

int readnumber()
{
   char b[20];
   cin.getline(b, sizeof(b));
   return atoi(b);
}

player linkedqueue :: input()
{
    int flag=0;
   player *p=new player();
   cout << "\n\tPlease enter data for player\n";
   cout<<"\n\tFirst name      : ";
   getline(cin,p->firstname);
   cout << "\tLast name       : ";
   getline(cin,p->lastname);
   again :
   cout << "\tBlood Group     : ";
   cin>>p->blood;
   if((strcmp(p->blood,"A+")==0)||(strcmp(p->blood,"a+")==0)||(strcmp(p->blood,"A-")==0)||(strcmp(p->blood,"a-")==0)||
      (strcmp(p->blood,"B+")==0)||(strcmp(p->blood,"b+")==0)||(strcmp(p->blood,"B-")==0)||(strcmp(p->blood,"b-")==0)||
      (strcmp(p->blood,"O+")==0)||(strcmp(p->blood,"o+")==0)||(strcmp(p->blood,"O-")==0)||(strcmp(p->blood,"o-")==0)||
      (strcmp(p->blood,"AB+")==0)||(strcmp(p->blood,"ab+")==0)||(strcmp(p->blood,"AB-")==0)||(strcmp(p->blood,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\nWrong Entry...Enter a valid Blood Group..Try Again..";
        goto again;

    }
   cout<<"\tGender(m/f)     : ";
   cin>>p->gender;
   cout<<"\tAge             : ";
   cin>>p->age;
   cout<<"\tMobile number   : ";
   cin>>p->ID;


	if(search(p->ID))
	{
		p->ID=0;
		cout << "\n\tData not valid. Operation cancelled.";
	}
	return *p;
}

void output(player *p)
{
        cout<<"\n****************************************\n";
		cout<<"\nFirst Name       : "<<p->firstname;
		cout<<"\nLast Name        : "<<p->lastname;
		cout<<"\nGender           : "<<p->gender;
        cout<<"\nAge              : "<<p->age;
        cout<<"\nBlood Group      : "<<p->blood;
		cout<<"\nMobile Number    : "<<p->ID;
		cout<<"\n\n****************************************\n";
}
void linkedqueue :: insertatbeg()
{
     player *p=new player ();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)

     {
         head=p;
         last=p;
         p->next=NULL;
     }
     else
     {
        p->next=head;
        head=p;
     }
     system("cls");
     cout << "\n\tPlayer added:";
     output(p);
}
void linkedqueue:: insertatend()
{
     player*p=new player();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)
     {
     	head=p;
        last=p;
        p->next=NULL;
     }
     else
     {
     	p->next=NULL;
        last->next=p;
        last=p;
     }
     system("cls");
     cout << "\n\tPlayer added:";
     output(p);
}
void linkedqueue :: getplayerout()
{
	 system("cls");
     if(head==NULL)
     {
     	cout<<"\n\tNo Player to Trainer";
     }
     else
     {
     	player*p=new player();
     	p=head;
     	head=head->next;
 	    cout << "\n\tPlayer to constructor:";
        output(p);
 	 }
}

void linkedqueue :: listofplayers()
{
     if(head==NULL)
     {
     	cout<<"\n\tNo player";
 	 }
     player*p=new player;
     p=head;
        cout<<"\n                           ***************************************";
        cout<<"\n\n                                      Player data:";
        cout<<"\n\n                          ***************************************";
        cout<<"\n----------------------------------------------------------------------------------------------------------------------";
        cout<<"\n| First Name\t|\tLast Name\t|\tGender\t|\tAge\t|\tBlood Group\t|\tMobile Number  |";
        cout<<"\n----------------------------------------------------------------------------------------------------------------------";

     while(p!=NULL)
     {
         cout<<"\n"<<p->firstname<<"\t\t\t"<<p->lastname<<"\t\t\t"<<p->gender<<"\t\t"<<p->age<<"\t\t"<<p->blood<<"\t  \t  "<<p->ID<<"\t\t|";
        cout<<"\n----------------------------------------------------------------------------------------------------------------------";
        p=p->next;
     }
     cout<<"\n";
}


void departmentmenu (linkedqueue * q)
{
    int choice = 0, success;
    player p;
    while (choice != 5)
	{
    system("cls");
	cout<<"\n\n\tWelcome To Department : " << q->departmentname;
	cout<<"\n\t\t[1] Add zonal player\n";
	cout<<"\t\t[2] Add state player\n";
	cout<<"\t\t[3] Take player to Trainer\n";
	cout<<"\t\t[4] Display list\n";
	cout<<"\t\t[5] Change department or exit\n";
	cout<<"\n\tPlease enter your choice : ";
	choice=readnumber();

    switch (choice)
	{
	  case 1:	q->insertatend();
				cout << "\n\tPress any key";
	    		getch();
	 			break;

      case 2:	q->insertatbeg();
	    		cout << "\n\tPress any key";
	    		getch();
				break;

      case 3:	q->getplayerout();
	 			cout<<"\n\tPress any key";
     			getch();
	      		break;

      case 4:	system("cls");
	 			q->listofplayers();
	 			cout<<"\n\tPress any key";
	 			getch();
				break;
	 }
    }
}

int main ()
{
    int i, choice = 0;
	linkedqueue departments[4];
	cout<<"\n\n\n!!!!!!--------->>>>>>>>>>>>DATA STRUCTURES AND ALGORITHM PROJECT>>>>>>>>>>>>>------------!!!!!!";
	cout<<"\n\n\n                    TEAM MEMBERS :- SIMRAN (06501172020)";
	cout<<"\n                                    SIMRAN SINGH (03301172020)";
	cout<<"\n\n                       GUIDED BY :- Mrs.SHWETA SINGHAL";
	cout<<"\n\n\n!!!!!!--------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>------------!!!!!!";
	cout<<"\n\n\n\n\npress any key to continue ";
	getch();

	while(choice!=5)
	{
		strcpy(departments[0].departmentname,"Basketball\n");
		strcpy(departments[1].departmentname,"Football\n");
		strcpy(departments[2].departmentname,"Volleyball\n");
		strcpy(departments[3].departmentname,"Badminton\n");
		system("cls");
		cout<<"\n\t            !------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>-------!";
		cout<<"\n\t                           SPORTS MANAGEMENT SYSTEM\t";
		cout<<"\n\t            !------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>-------!\n\n";
		for (i = 0; i < 4; i++)
		{
			cout<<"\t"<<(i+1)<<": "<<departments[i].departmentname;
		}
		cout<<"\t5: Exit";
		cout<<"\n\n\tPlease enter your choice : ";
		choice=readnumber();
		if(choice>=1 && choice<=4)
		{
			departmentmenu(&departments[choice-1]);
		}

	}
	if(choice==5)
	cout<<"\n\t\tThank you! \n";
	exit(0);
}
