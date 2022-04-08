#include<iostream>
#include<fstream>
#include<string>

using namespace std;



bool IsLoggedIN(int user_type){
  string username;
  string password;
  string un, pw,ut;
  cout<<"Enter the username: ";
  cin>>username;
  cout<<"Enter the password: ";
  cin>>password;


  ifstream read("users/"+username + ".txt");
  getline(read, un);
  getline(read, pw);
  getline(read, ut);



  if(un== username && pw==password && ut==to_string(user_type) ){
    return true ;
  }
  else {
    return false ;

  }
}

int Login(){
  int user_type;
  cout<<"1.Student\n2.Professor\n3.Librarian\nEnter the login Type: ";
  cin>> user_type;
  if(user_type==3){
    string username, password,u_t;
    cout<<"select a username: ";cin>>username;
    cout<<"select a password: "; cin>>password;
    if(username=="admin" && password=="admin"){
      cout<<"Successfully logged in \n";
      return 3;
    }
  }
  int choice;
  cout<< "1. Register\n2: Login\nYour Choice: ";
  cin>>choice;
  if(choice == 1){
    string username, password,u_t;
    cout<<"select a username: ";cin>>username;
    cout<<"select a password: "; cin>>password;
    ofstream file;
    file.open("users/"+ username + ".txt");

    file<<username<<endl<<password<<endl<<user_type;

    file.close();
    
    Login();
    return 0;


  }else if(choice ==2){
    bool status = IsLoggedIN(user_type);
    if(!status){
      cout<<"False Login!"<<endl;
      system("PAUSE");
      Login();
    }
    else {
      cout<<"Successfully logged In!"<<endl;
      system("PAUSE");
      return user_type;
    }
  }
}