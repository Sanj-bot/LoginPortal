#include<iostream>
#include<fstream>// work on files
#include<sstream>// templates and types 
#include<string> 
using namespace std;
int main()
{
	int a,i=0;
	string text, old, password1,password2,pass,name,password0,age,user,word,word1;
	string creds[2],cp[2];// string array
	// display interface
	
	
	cout<<"      Login Portal"<<endl;
	cout<<"______________________________"<<endl<<endl;
	cout<<"|		1. Register          |"<<endl;
	cout<<"|		2. Login             |"<<endl;
	cout<<"|		3. Change Password   |"<<endl;
	cout<<"|________4. End Program_______|"<<endl;
	cout<<endl;
	do{
		cout<<endl<<endl;
		cout<<"Enter your choice:-";
		cin>>a;
		switch(a)
		{
			
			case 1:{
				cout<<"______________________________"<<endl<<endl;
				cout<<"- - - - - -Register- - - - - - "<<endl;
				cout<<"|_____________________________"<<endl<<endl;
				cout<<"Please Enter username:-";
				cin>>name;
				cout<<"Please Enter the password:-";
				cin>>password0;
				cout<<"Please enter your age:-";
				cin>>age;
				// saving these details in a file
				
				ofstream of1; // of1 is object of ofstream class
				// for writing purpose
				of1.open("file.txt");
				if(of1.is_open()){
					of1<<name<<"\n";
					of1<<password0;
					cout<<"Registration successfull"<<endl;
				}
				break;
			}
			case 2:{
				i=0;
				cout<<"_____________________________"<<endl<<endl;
				cout<<"|- - - - - Login-------------|"<<endl;
				cout<<"|____________________________|"<<endl<<endl;
				
				// ifstream class
				ifstream of2;
				of2.open("file.txt");
				cout<<"Please Enter the username:-";
				cin>>user;
				cout<<"Please enter the password:-";
				cin>>pass;
				if(of2.is_open())
				{
					while(!of2.eof())
					{
						while(getline(of2,text))// read file linee by line
						{
							istringstream iss(text);// stream string and store using extraction operatior
							iss>>word;
							creds[i]=word;
							i++;
						}
						if(user==creds[0] && pass==creds[1])
						{
							cout<<"--- Login successfull---";
							cout<<endl<<endl;
							cout<<"Details:"<<endl;
							
							cout<<"username:"+name<<endl;
							cout<<"Password: "+pass<<endl;
							cout<<"Age: "+age<<endl;
						}
						else
						{
							cout<<endl<<endl;
							cout<<"Incorrect Credentials"<<endl;
							cout<<"|     1. Press 2 to login     |"<<endl;
							cout<<"|     2. Press 3 to change it |"<<endl;
							break;
						}
					}
				}
				
				break;
			}
			
			case 3:{
				i=0;
				cout<<"-----------Change Password----------"<<endl;
				ifstream of0;
				of0.open("file.txt");
				cout<<"Enter the old password:-";
				cin>>old;
				if(of0.is_open())
				{
					while(of0.eof())
					{
						while(getline(of0,text)){
							istringstream iss(text);
							iss>>word1;
							cp[i]=word1;
							i++;
						}
						if(old==cp[1])
						{
							of0.close();
							ofstream of1;
							if(of1.is_open())
							{
								cout<<"Enter your new password:-";
								cin>>password1;
								cout<<"Enter your password again:- ";
								cin>>password2;
								
								if(password1==password2)
								{
									of1<<cp[0]<<"\n";
									of1<<password1;
									cout<<"Password changed successfully"<<endl;
								}
								else
								{
									of1<<cp[0]<<"\n";
									of1<<old;
									cout<<"Password do not match"<<endl;
								}
							}
							
						}
						else
						{
							cout<<"Please enter a valid password"<<endl;
							break;
						}
					}
					
				}
				break;
			}
			case 4:
				{
					cout<<"___________ThankYou!____________";
					break;
				}
				default:
					cout<<"Enter a valid choice";
			
			
		}
	}
	while(a!=4);
return 0;
}

