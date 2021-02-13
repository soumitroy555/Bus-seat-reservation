//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<windows.h>
using namespace std;
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
class passenger
{
   private:
     char name[10];
     int seat;
     int am;
     char des[10];
     char dat[10];
     char t[10];
     char o[10];
     char k[10];
     char bu[10];

   public:
     void get(void);
     void display(void);
     int retseat();

};

class bus:public passenger
{
    char nm[10];
    char dv[10];
    char dp[10];
    char fr[10];
    char to[10];
public:
    void buschedule(void);
    void disschedule(void);
};
void passenger::get()
{
   cout<<"\nName of the passenger:                   \n";
   cin>>name;
   cout<<"\nEnter bus number:                          \n";
   cin>>bu;
   cout<<"\nWhat's your seat choice?\nSeat Choice( enter number):    \n";
   cin>>seat;
   cout<<"\nDestination:                              \n";
   cin>>des;
   cout<<"\nPhone Number         :                  \n";
   cin>>o;
   cout<<"\nDate:                                     \n";
   cin>>dat;
   cout<<"\nTime:                                      \n";
   cin>>t;
   cout<<"amount:                                      \n";
   cin>>am;
   }
void passenger::display()
{
   cout<<"\n********************************************\n";
   cout<<"*    Name of Customer:"<<name<<"                   \n";
   cout<<"*    Bus number      :"<<bu<<"                   \n";
   cout<<"*    Seat Choice     :"<<seat<<"                   \n";
   cout<<"*    Destination     :"<<des<<"                   \n";
   cout<<"*    Date            :"<<dat<<"                   \n";
   cout<<"*    Time            :"<<t<<"                   \n";
   cout<<"*    Phone number    :"<<o<<"                     \n";
   cout<<"*For"<<" "<<des<<" "<<"amount is :"<<am;
   cout<<"\n********************************************\n";

}
int passenger::retseat()
{
    return seat;
}

void bus::buschedule()
{
   cout<<"\nEnter Bus Number:                   \n";
   cin>>nm;
   cout<<"\nEnter drivers Name:                          \n";
   cin>>dv;
   cout<<"\nEnter Bus departure time:    \n";
   cin>>dp;
   cout<<"\nFrom :                              \n";
   cin>>fr;
   cout<<"\nTo:                                     \n";
   cin>>to;
   }
  void bus::disschedule()
  {
   cout<<"\n********************************************\n";
   cout<<"*    Bus Number      :"<<nm<<"                   \n";
   cout<<"*    Drivers Name    :"<<dv<<"                   \n";
   cout<<"*    Departure Time  :"<<dp<<"                   \n";
   cout<<"*    From            :"<<fr<<"                   \n";
   cout<<"*    To              :"<<to<<"                   \n";
   cout<<"\n********************************************\n";

  }



//***************************************************************
//    	function declaration
//****************************************************************

void write_pas();
void display_all();
void display_sp(int);
void withdraw(int);
void schedule();
void scdis();
void office();

int main()
{
    passenger st;
   string password1="1234";
   string password,id;
   string id1="a112";
   int m,num;
   cout<<"\n******************** Welcome to Yellow line Paribahan ***************** \n";
   cout<<"\n                           Phone-017234545                                 \n";
   cout<<"                                (Login)                                      \n\n";
   cout<<"Enter ID:                                                                     \n";
   cin>>id;
   cout<<"Enter Password:                                                                \n";
   cin>>password;
   if(password==password1&&id==id1){
      do{
       cout<<"  ------------------------------------------------"<<endl;
       cout<<"\n1.Install Bus schedule."
       <<"\n2.Check Bus schedule."
       <<"\n3.Seat Reservation."
       <<"\n4.Display passengers."
       <<"\n5.Search passengers."
       <<"\n6.Withdraw."
       <<"\n7.Counters info."
       <<"\n8.Quit."
       <<"\nWhat is your option?\n ";
   cout<<"--------------------------------------------------"<<endl;

    cin>>m;
    switch(m)
    {
    case 1:
          cout<<"Bus Schedule"<<endl;
          schedule();
          break;

     case 2:
         cout<<"\nBus schedule.\n"<<endl;
          scdis();
          break;

    case 3:
         cout<<"\nName,seat no & amount of seat of passenger of "<<endl;
         write_pas();
         break;

    case 4:

        cout<<"Passengers Information"<<endl;
        display_all();
        break;

   case 5:

        cout<<"Enter seat no:"<<endl;
        cin>>num;
        display_sp(num);
        break;

   case 6:
       cout<<"\nTo Withdraw enter seat no:\n"<<endl;
        cin>>num;
        withdraw(num);
         break;


   case 7:
       cout<<"\nCounters information:\n"<<endl;
        office();
        break;

   case 8:
     break;

   default:
     cout<<"\nError please Try Again.\n";
   }

}while(m!=8);
   }
return 0;
}
//***************************************************************
//    	function to write in file
//****************************************************************
void write_pas()
{
	passenger st;
	ofstream outFile;
	outFile.open("passenger.txt",ios::binary|ios::app);
	st.get();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(passenger));
	outFile.close();
    cout<<"\n\npassengers record Has Been Created ";
	cin.ignore();
	cin.get();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************
void display_all()
{
	passenger st;
	ifstream inFile;
	inFile.open("passenger.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(passenger)))
	{
		st.display();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}
//***************************************************************
//    	function to read specific record from file
//****************************************************************
void display_sp(int n)
{
	passenger st;
	ifstream inFile;
	inFile.open("passenger.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(passenger)))
	{
		if(st.retseat()==n)
		{
	  		 st.display();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}
//***************************************************************
//    	function to delete record of file
//****************************************************************
void withdraw(int n)
{
    passenger st;
	ifstream inFile;
	inFile.open("passenger.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.txt",ios::out);
	inFile.seekg(0);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(passenger)))
	{
		if(st.retseat()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(passenger));
		}
	}
	outFile.close();
	inFile.close();
	remove("passenger.txt");
	rename("Temp.txt","passenger.txt");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}
//***************************************************************
//    	function to write schedule
//****************************************************************
void schedule()
{
	bus qt;
	ofstream outFile;
	outFile.open("schedule.txt",ios::binary|ios::app);
	qt.buschedule();
	outFile.write(reinterpret_cast<char *> (&qt), sizeof(bus));
	outFile.close();
    cout<<"\n\Bus record Has Been Created ";
	cin.ignore();
	cin.get();


}
//***************************************************************
//    	function to read all schedule from file
//****************************************************************

void scdis()
{
     bus qt;
	ifstream inFile;
	inFile.open("schedule.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&qt), sizeof(bus)))
	{
		qt.disschedule();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();

}


void office()
{
    FILE *f2;
    char ch;

        f2=fopen("office.txt","r");
        if(f2==NULL){
            printf("u");
            }
            else{
                while(!feof(f2)){
                    ch=fgetc(f2);
                    printf("%c",ch);
                }
                fclose(f2);

                }

    }
//***************************************************************
//    			END OF PROJECT
//***************************************************************
