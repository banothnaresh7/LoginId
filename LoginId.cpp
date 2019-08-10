#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool IslogIn();
void Register();

int main()
{
   int choice,a;
   cout<< "1:For Login\n"<<"2:For Register\n";
   cin>>choice;
   if(choice== 1)
   {
     bool status= IslogIn();
     if(!status)
     {
       cout<<"wrong password and username\n";
       main();
     }
     else
     {
	cout<<"\npress any key to continue..";
	cin>>a;
	return 0;
     }
   }
   else if(choice==2)
   {
     Register ();
     cout<<"successfully registered\n";
     main();
   }
}
    

bool IslogIn()
{
   string username,password,us ,psw;
   cout<<"enter the username:";
   cin>>us;
   cout<<"enter the password:";
   cin>>psw;	   
   ifstream read;
   read.open("login.txt");
   while(getline(read,username) && getline(read,password))
   {
     if(username==us && password ==psw)
     {
	read.close();
       return true;
     }
   }
	read.close();
	return false;
   
}


void Register ()
{
  string username, password;
  cout<<"enter the username:";
  cin>>username;
  cout<<"enter the password:";
  cin>>password;
  ofstream write;
  write.open("login.txt",ios::app);
  write<<endl<<username<<endl<<password;
  write.close();
  
}

   




  
