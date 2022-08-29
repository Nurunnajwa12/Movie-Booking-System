// Group 6 : Movie Booking System 
// Oon Yee Sem (A21EC122)
// Mohamad Azri Hadif bin Mohammad Rizal (A21EC0054)
// Nurunnajwa binti Zulkifli (A21EC0121)
// Nur Shuhada Safiah binti Ayob (A21EC0114)

#include <iostream>
#include<string>
#include<cmath>
#include <ctime>
#include<ios>
#include<limits>
#include <fstream>
#include <string>
#define SIZE 9
using namespace std;

//Show the first and last name
class Name
{
	private:
		string firstName;
		string lastName;
	public:
		Name(string f="",string l="")
		{
			firstName = f;
			lastName = l;
		}   	
		
		void setFirstName(string f){firstName = f;}
		
		void setLastName(string l){lastName= l;}
		
		string getName() const{return firstName + " " + lastName;}

		virtual void display(){ cout << ""; }
};

//Enter admin information
class Admin :public Name
{
	private:
		string password;
	public:
		Admin(){};
		void display()
		{
			string l;
			cout << "+++Welcome Admin+++\n\n";
			cout << "Please enter first name,last name and password to proceed\n";
			cout << "First name : ";
			cin.ignore();
			getline(cin,l);
			setFirstName(l);
			cout << "Last name  : ";
			getline(cin,l);
			setLastName(l);
			
			cout << "Password   : ";
			cin >> password;
				while(password != "1234")
				{
					cout << endl;
					cout << "*Wrong Password*" << endl;
					cout << "Please enter again" << endl;
					cout << "Password   : ";
					cin >> password;
				}
		} 		  
		
		string getPassword() const{return password;}
};

//Display and calculate the food information
class Food : public Admin
{
	protected:
		string foodName;
		string foodTypes;
		int numFood;
	public:
		Food(string t,int n)
		{
			foodTypes = t;
			numFood = n;
		}
		
		void display()
		{
			cout << "\nTypes of sneak : ";
			if(foodTypes == "1")
			{
				foodName = "Popcorn";	
			}
			
			else if(foodTypes == "2")
			{
				foodName = "Fried chicken";
			}
			
			else if(foodTypes == "3")
			{
				foodName = "Pizza";
			}
			
			else if(foodTypes == "4")
			{
				foodName == "French Fries";
			}   
		
			cout << foodName << endl;
			cout << "Number of " << foodName << " : " << numFood << endl;
		}
		
		friend ostream& operator<<(Food &right,ostream &co)
		{
			char option;
			int numCollect;
			
			co << "Do you want to collect food (Y/N) : " << endl;
			co << "Option : ";
			cin >> option;
			option = toupper(option);
			while(option != 'Y' && option != 'N' ){
			co << endl;
			co << "Sorry,we could not found your selection in the list" << endl;
			co << "Please enter again" << endl;
			co << "Option : ";
			cin >> option;	
			}
			if(option == 'Y')
			{
				if(right.numFood == 0)
				{
					co << endl;
					co << right.foodName << "is out of stock" << endl;
					co << "You have no " << right.foodName << "to collect" << endl;
				}
				else
				{
					co << endl;
					co << "Enter number of food that you want to collect : ";
					cin >> numCollect;
					
					while(numCollect > right.numFood)
					{
						co << endl;
						co << "Your input is out of range" << endl;
						co << "Please enter the number of selected food lesser or equal to " << right.numFood << endl;
						co << "Option : ";
						cin >> numCollect; 
					}
					
					right.numFood -= numCollect;
					co << endl;
					co << "Number of " << right.foodName << " left : " << right.numFood << endl; 
				}
			} 
		return co;
		}
};

//Display and calculate the beverage information
class Beverage : public Admin
{
	protected:
		string beverageType;
		string beverageName;
		int numBeverage;
	public:
		Beverage(string t,int n)
		{
			beverageType = t;
			numBeverage = n;
		}   	
		
		void display()
		{   //Until here
			cout << endl;
			cout << "Types of beverage : ";
			
			if(beverageType == "1")
			{
			beverageName = "Cola-cola";	
			}
			
			else if(beverageType == "2")
			{
				beverageName = "Pepsi ";
			}
			
			else if(beverageType == "3")
			{
			beverageName = "100 Plus";
			}
			
			else if(beverageType == "4")
			{
			beverageName== "Mineral water";
			}   
		
		cout << beverageName << endl;
		cout << "Number of " << beverageName << " : " << numBeverage << endl;
		}
		
		friend ostream& operator<<(Beverage &right,ostream& co){
			char option;
			int numCollect;
			
			co << "Do you want to collect food (Y/N) : " << endl;
			co << "Option : ";
			cin >> option;
			option = toupper(option);
			while(option != 'Y' && option != 'N' ){
			co << endl;
			co << "Sorry,we could not found your selection in the list" << endl;
			co << "Please enter again" << endl;
			co << "Option : ";
			cin >> option;	
			}
			if(option == 'Y')
			{
				if(right.numBeverage == 0)
				{
					co << endl;
					co << right.beverageName << "is out of stock" << endl;
					co << "You have no " << right.beverageName << "to collect" << endl;
				}
				else
				{
					co << endl;
					co << "Enter number of food that you want to collect : ";
					cin >> numCollect;
					
					while(numCollect > right.numBeverage){
						co << endl;
						co << "Your input is out of range" << endl;
						co << "Please enter the number of selected food lesser or equal to " << right.numBeverage << endl;
						co << "Option : ";
						cin >> numCollect; 
					}
					
					right.numBeverage -= numCollect;
					co << endl;
					co << "Number of " << right.beverageName << " left : " << right.numBeverage << endl; 
				}
			} 
		return co;
		}
};

//Display the time slot
class Times
{
    protected:
        int slot;
        string myText;

    public:
        void setSlot(int s) 
        { 
            slot = s;
        }

        int getSlot() {return slot;}

        void displayMasa()
        {
            ifstream ReadFile("masa.txt");

            for (int i = 0; i < SIZE; i++)
                {
                while (getline (ReadFile, myText))
                    cout <<  myText << endl;
                }
            
            ReadFile.close();
        }
};

//Enter customer information
class Customer
{
    protected:
		string firstName;
		string lastName;
		Name *name;  //aggregation
		int type;
		int movies;
		int seat;
		int snack;
		
    public:
		Customer(string f="", string l="", int t=0, int m=0,int e=0, int k=0)
		{
			name=new Name(f,l);
			type=t;
			movies=m;
			seat=e;
			snack=k;
		}
		
		void setName(string firstName, string lastName)
		{
			name= new Name(firstName,lastName);
		}

		void setType(int t)
		{
			type=t;
		}
		
		void setMovie(int m)
		{
			movies=m;
		}

		void setSeat(int e )
		{
			seat=e;
		}

		 void setSnack(int k)
		{
			snack=k;
		}
		
		int getSeat(){return seat;}
		
		int getMovie(){return movies;}

		int getSnack(){return snack;}

		string getName(){return name->getName();}

		int getType(){return type;}

		void displayMovie()
		{
			string movieText;
			ifstream ReadFile("moviename.txt");

				for (int i = 0; i < SIZE; i++)
					{
					while (getline (ReadFile, movieText))
						cout << movieText<< endl;
					}
				ReadFile.close();
		}

		void displaySeat()
		{
			string movieSeat;
			ifstream ReadFile("seat.txt");

				for (int i = 0; i < SIZE; i++)
					{
					while (getline (ReadFile, movieSeat))
						cout << movieSeat<< endl;
					}
				ReadFile.close();
		}

		void displaySnack()
		{
			string movieSnack;
			ifstream ReadFile("snack.txt");

				for (int i = 0; i < SIZE; i++)
					{
					while (getline (ReadFile, movieSnack))
						cout << movieSnack<< endl;
					}
				ReadFile.close();
		}
};

//Display customer infomation
class Resit : public Customer// display resit
{
	protected:
		int grandTotal;
        Times times; //composition
   
    public:
		Resit(int g=0){grandTotal = g;}

       void read()
       {
        cout<<"WELCOME TO CINEMA BOOKING"<<endl;
        cout<<"Please enter your details as below.\n"<<endl;

        cout<<"First name: ";
        cin >> firstName;
        cin.ignore();
        cout<<"Last name: ";
        getline(cin, lastName);
        setName(firstName,lastName);

        //Type
		 cout<<"\nType of customer\n"
        <<"1 Member\n"
        <<"2 Non-member\n";
        cout<<"Type: ";
        cin>>type;
        setType(type);

        //Time
        int slots;
		cout<<"\nChoose your time:\n";
        times.displayMasa();
        cout<<"Time slot: ";
        cin >> slots;
         while(slots<1 || slots>7)
            {
                cout << "\nWrong Time Slot.\nPlease enter again... ";
			    cin >> slots; 
            }
        times.setSlot(slots);
        cout<<endl;

        displayMovie();
        cout<<"Choose your movie: ";
        cin >> movies;
        while(movies<1||movies>5)
        {
                cout << "\nWrong Movie.Please enter again=> ";
			    cin >> movies; 
        }
        setMovie(movies);

        //seat 
        cout<<endl;
        displaySeat();
        cout<<"Choose your seat: ";
        cin >> seat;
        while(seat<1 || seat>32)
            {
                cout << "\nWrong Seats.Please enter again=> ";
			    cin >> seat;
            }
        setSeat(seat);

        //snack 
        cout<<endl;
        displaySnack();
        cout<<"Choose your snack: ";
        cin >> snack;
         while(snack<1 || snack>3)
            {
                cout << "\nWrong Snack.Please enter again=>";
			    cin >> snack;
            }
        setSnack(snack);

       }

		void setPrice(int g)
		{
			grandTotal=g;
		}

		int getPrice() const
		{
		return grandTotal;
		}

        void displayResit()
        {
            cout << "Name \t\t\t: " << getName()<< endl;
			cout << "Status \t\t\t: ";
			if (getType() == 1)
				cout << "Member" << endl;
			else
				cout << "Non-Member" << endl;
            
			cout << "Chosen Seat \t\t: " << getSeat()<< endl;
            
			cout << "Time Slot \t\t: ";
			if (times.getSlot()==1)
				cout << "10:00 - 12:00" << endl;
			else if (times.getSlot()==2)
				cout << "12:15 - 14:15" << endl;
			else if (times.getSlot()==3)
				cout << "14:30 - 16:30" << endl;
			else if (times.getSlot()==4)
				cout << "16:45 - 18:45" << endl;
            else if (times.getSlot()==5)
				cout << "20:00 - 22:00" << endl;
			else if (times.getSlot()==6)
				cout << "22:15 - 00:15" << endl;
			else if (times.getSlot()==7)
				cout << "00:30 - 02:30" << endl;

			cout << "Movie Selections \t: ";
			if (getMovie()==1)
				cout<<"KKN di Desa Penari"<<endl;
			else if (getMovie()==2)
				cout<<"Sonic The Hedgehog"<<endl;
			else if (getMovie()==3)
				cout<<"Mat Kilau: Kebangkitan Pahlawan"<<endl;
			else if (getMovie()==4)
				cout<<"Boboiboy The Movie"<<endl;
			else
				cout<<"The Assistant"<<endl;

            cout << "Selected snack \t\t: ";
			if(getSnack()==1)
				cout<<"Combo 1 => Chicken Popcorn and Pepsi"<<endl;	
			else if (getSnack()==2)
				cout<<"Combo 2 => Popcorn and Coca-cola"<<endl;
			else
				cout<<"Combo 3 => Pizza and 100 Plus"<<endl;
            
			cout << "\tGrand Total  = \t";
			if(type==1)
				cout<<"RM 24.00"<<endl;
			else
				cout<<"RM 27.00"<<endl;

            // display current time
            time_t tt;
            tm * ti;
            time (&tt);
            ti = localtime(&tt);//Convert time_t to tm as local time
            cout << "\t" << asctime(ti) << endl; //convert time to string

			
        }
};


int main()
{    
    Resit r[100];
    Resit s;
    string firstname, lastname, adname, password; //Admin password: 1234
    Admin admin;
	Times Ts;
	Customer c;
	string fname,lname;
	int time, numCustomer=-1;
    int m=0;
	
	char name[30];
	int routeId, choiceBook, type;
	char option;
    Food p("1",100);Food chicken("2",50); Food pizza("3",32); Food f("4",120);
	Beverage cola("1",100);	Beverage pepsi("2",200);Beverage plus("3",150);Beverage water("4",300);
	bool flag = true, polyflag = true;

	cout << "++++++++++++++++++++++++++++++++++++++++++" << endl; 
	cout << "          WELCOME TO UTM CINEMA           " << endl;           
	cout << "++++++++++++++++++++++++++++++++++++++++++" << endl; 
	cout << endl;
	
	string i;
	cout << "LOGIN PAGE" << endl;
	cout << "-----------" << endl;
	cout << "Please enter a selection to proceed " << endl;
	cout << "1.Go to main page" << endl;
	cout << "2.Quit" << endl;
	cout << "Option : ";
	cin >> i;
	
	while(i != "1" && i !="2")
	{
		cout << endl;
		cout << "Sorry,your selection are NOT in the list" << endl;
		cout << "Please enter a selection to proceed" << endl;
		cout << "1.Go to main page" << endl;
		cout << "2.Quit" << endl;
		cout << "Option : ";
		cin >> i;
	}
	
	if(i == "1")
	{
		system("CLS");
		cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	    cout << "          WELCOME TO UTM CINEMA           " << endl;
	    cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	    
	    int choice;
	    cout << "You have entered main page" << endl << endl;
	    cout << "Main page" << endl;
	    cout << "-----------" << endl;
	    cout << "1.Tickets" << endl;
	    cout << "2.Admin" << endl;
	    cout << "Option : ";
	    cin >> choice;
	     
	    while(choice != 1 && choice !=2 )
		{
	    	cout << "\nSorry, we could not find your selection in the list" << endl;
			cout << "Please enter again" << endl;
			cout << "Option : ";
			cin >> choice;
		}
		cin.ignore();

	    if(choice == 1)
		{
	           system("CLS");
	           cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	           cout << "          WELCOME TO UTM CINEMA           " << endl;
	           cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	           cout << "You have entered the ticket booking system" << endl;

			   do
			   {
					cout << endl;
					cout << "Ticket Booking System" << endl;
					cout << "----------------------" << endl;
					cout << "1.Make a booking" << endl;
					cout << "2.Display booking" << endl;
					cout << "3.Delete booking" << endl;
					cout << "4.Quit" << endl;
					cout << "Option : ";
					cin >> choiceBook;
	       
					while(choiceBook != 1 && choiceBook !=2 && choiceBook !=3 && choiceBook !=4)
					{
						cout << endl;	
						cout << "Sorry, we could not find your selection in the list" << endl;
						cout << "Please enter again" << endl;
						cout << "Option : ";
						cin >> choiceBook;
					}

					if(choiceBook ==1)
					{
						system("CLS");
                        r[m].read();
                        m++;
						
					}

					else if(choiceBook == 2)
					{
						system("CLS");

						cout << "\t\tReceipt" << endl;
						cout << "Still Life Theatre" << "\tUniversiti Teknologi Malaysia" << endl << endl;
						cout << "-------------------------------------------------------"<< endl;

							for (int i=0; i<m; i++)
							{
								r[i].displayResit();
							}
							cout<<"\t\tThank you"<<endl;
						
					}
					else if (choiceBook == 3)
					{
						system("CLS");
						if (m>=0)
						{
							bool flag1=false;
							cout<<"Please enter your detail information."<<endl;

							//Name 
							cout<<"First Name: ";
							cin >> firstname;
							cin.ignore();
							cout<<"Last Name: ";
							getline(cin,lastname);
							s.setName(firstname,lastname);

							//Cancellation of booking
							for(int i=0; i<m; i++)
							{
								if(s.getName()==r[i].getName())
								{
									for(int j=i; j<=(m-1); j++)
									{
										r[j]=r[j+1];
									}
									i--;
									m--;
									cout<<"Dear "<<s.getName()<<", we has cancel your booking."<<endl;
									cout<<"Thank you."<<endl;
									goto jump;

								}
							}
							if (m=-1)
							{
								cout<<"\n\n...No booking...."<<endl;
							}
						}
					}
					else if (choiceBook == 4)
					{
						system("CLS");
						cout << "\nThanks for using our system.\nHope to see you again!\n"<<endl;
						exit(0);
					}
					jump:
						cout << "\n Do you want to continue? (Y|N)=> ";
						cin >> option;
						cin.ignore();
						while(isdigit(option))
						{
							cout<<" Please enter Y or N only (Y|N)=> "<<endl;
							cin >> option;
						}
						option = toupper(option);
						system("CLS");

					while (option != 'Y' && option != 'N')
					{
						cout << "Please enter Y or N only (Y|N)=> " << endl;
						cin >> option;
						option = toupper(option);
					}

					if(option == 'Y')
					{
						flag = true;
						system("CLS");
					}

					else if(option == 'N')
					{
						cout<<"Thank you for using our system. Have a nice day."<<endl;
						flag = false;
					}
				}
				while(flag);
    		}
	
		//choice = Admin
		else if(choice==2){
				string menu;
				system("CLS");
				admin.display();
				
				system("CLS");
				cout << "Welcome Admin " << admin.getName() << endl;
				cout << endl;
				cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "          WELCOME TO UTM CINEMA           " << endl;
				cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "You have entered admin system" << endl;
			
				do{
				//display menu
				cout << "**Menu**"
				<< "\n1. Food"
				<< "\n2. Beverage"
				<< "\n3. Exit"
				<< "\n\nEnter choice : ";
				cin >> menu;
				
				while(menu<"1"||menu>"4")
				{
					cout << "\nWrong choice.\nPlease enter again... ";
					cin >> menu;
				}
				
				if (menu=="1")
				{   
					system("CLS");
					string c;
					cout << "***Welcome Admin " << admin.getName() << " ***" << endl; //ADMIN FOOD
					cout << endl;
					cout << "    Food's Storage" << endl;
					cout << "----------------------" << endl;
					cout << " 1.Popcorn" << endl;
					cout << " 2.Fried Chicken" << endl;
					cout << " 3.Pizza" << endl;
					cout << " 4.French Fries" << endl;
					cout << " 5.EXIT" << endl;
					cout << "Option : ";
					cin >> c;
				
					while(c != "1" && c != "2" && c !="2" && c !="3" && c !="4"&& c != "5")
					{
						cout <<"\nWrong choice.\nPlease enter again... ";
						cin >> c;
					}				
					if(c=="1") //choice 1: Popcorn
					{
					p.display();
					operator << (p, cout);
					}
					else if(c == "2") //choice 2: Fried Chicken
					{
						chicken.display();
						operator << (chicken, cout);
					}
					else if(c == "3") //choice 3: Pizza
					{
						pizza.display();
						operator << (pizza, cout);					
					}
					else if(c == "4")
					{
						f.display();
						operator << (f, cout);						
					}
					else
					{  
						system("CLS");
						polyflag = false;				
					}
				}

				else if (menu=="2")
				{  system("CLS");
					string d;
					cout << "***Welcome Admin " << admin.getName() << " ***" << endl;
					cout << endl;
					cout << "    Beverage's Storage" << endl;
					cout << "-------------------------" << endl;
					cout << " 1.Cola-cola" << endl;
					cout << " 2.Pepsi" << endl;
					cout << " 3.100 Plus" << endl;
					cout << " 4.Mineral water" << endl;
					cout << " 5.EXIT" << endl;
					cout << " Option : ";
					cin >> d;
				
					while(d != "1" && d !="2"&& d !="2"&& d !="3"&& d !="4"&& d !="5")
					{
						cout << "\nWrong choice.\nPlease enter again... ";
						cin >> choice;
					}
				
					if (d == "1") //choice 1: Coca cola
					{
						cola.display();
						operator << (cola, cout);
					}
					else if (d == "2") //choice 2: Pepsi
					{
						pepsi.display();
						operator << (pepsi, cout);
					}
					else if (d == "3") //choice 3: 100 plus
					{
						plus.display();
						operator << (plus, cout);
					}
					else if (d == "4") //choice 4: Water
					{
					water.display();
					operator << (water, cout);
					}

					else if(d == "5") //choice 5:
					{
						system("CLS");
						polyflag = false;
					}

					
				}	

					else if(menu == "3")

				{
					system("CLS");
					cout<<"Thank you for using Admin system."<<endl;
				}


				cout<<"\nDo you want to continue? (Y|N)"<<endl;
				cin >> option;
				while(isdigit(option))
				{
					cout<<"Please enter Y or N only (Y|N)=>";
					cin >> option;

				}
				option=toupper(option);
				system("CLS");

				while(option != 'Y' && option != 'N')
				{
					cout<<"Please enter Y or N only (Y|N)=> ";
					cin >> option;
					option=toupper(option);
				}

				if(option == 'Y')
				{
					polyflag = true;
					system("CLS");
				}
				else if(option == 'N')
				{

					cout<<"Thank you for using our system.\nHave a nice day."<<endl;
					polyflag = false;
					
				}			
					
			} while(polyflag);
		}

	}

		else if(i=="2"){
			system("CLS");
			cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "          EXIT FROM UTM CINEMA           " << endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
			
			cout << endl;
			
			cout << "Thank you." << endl;
			cout << "Please come again!" << endl;
			exit(0);
		}
		

		return 0;
}