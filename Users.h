#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdio>
#include<filesystem>
#include<vector>
#include<stdio.h>



using namespace std;


int Program_begin(){
  cout<<"\nwelcome to LMS: \n";
  int user_type;
  user_type=Login();
  return user_type;
}

class User{
  public:
  string Name;
  string ID;
  string Password;
};


class Professor: public User{
  public:
  int Fine_amount=5;
  int number_of_Books;
  int day_limit=60;
  int book_limit=10000;
  void Cli(){
    int choice;
    cout<<"1.See All Books You own\n2.See the Books In Library\n3.Logout\n";
    cin>>choice;
    if(choice==1){
      List_Books();
      Cli();
    }
    else if(choice==2 ){
      read_record();
      Cli();
    }
    else if(choice==3){
      cout<<"you logged out succesfully";
      Program_begin();
    }
  }
  void List_Books()
  {
  
    // File pointer
    fstream fin;
    string username;

    
    vector<string> row;
    string line, word;
    cout<<"\nenter the username: ";
    cin>>username;
    fin.open("users/"+ username +"db.csv", ios::in);
  
    while (!fin.eof()) {
      row.clear();
      getline(fin, line);
      stringstream s(line);
      
      while (getline(s, word, ',')) {
        row.push_back(word);
      }
      cout<<"Title: "<<row[0]<<"\nAuthor: "<<row[1]<<"\nISBN: "<<row[2]<<"\nPublication: "<<row[3]<<"\nIssued to: "<<row[4]<<endl<<endl;
    }
    cout<<"task finished\n";
    fin.close();
  }
};

class Student: public User{
  public:
  int Fine_amount=2;
  int number_of_Books;
  int day_limit=30;
  int book_limit=5;
  void Cli(){
    int choice;
    cout<<"1.See All Books You own\n2.See the Books In Library\n3.Logout\n";
    cin>>choice;
    if(choice==1){
      List_Books();
      Cli();
    }
    else if(choice==2 ){
      read_record();
      Cli();
    }
    else if(choice==3){
      cout<<"\nyou logged out succesfully\n";
      Program_begin();
    }
  }
  void List_Books()
  {
    // File pointer
    fstream fin;
    string username;

    
    vector<string> row;
    string line, word;
    cout<<"\nenter the username: ";
    cin>>username;
    fin.open("users/"+ username +"db.csv", ios::in);
  
    while (!fin.eof()) {
      row.clear();
      getline(fin, line);
      stringstream s(line);
      
      while (getline(s, word, ',')) {
        row.push_back(word);
      }
      cout<<"Title: "<<row[0]<<"\nAuthor: "<<row[1]<<"\nISBN: "<<row[2]<<"\nPublication: "<<row[3]<<"\nIssued to: "<<row[4]<<endl<<endl;
    }
    cout<<"task finished\n";
    fin.close();
  }
};

class Librarian: public User{
  public:
  void Add_User(){
    int user_type;
    cout<<"1.Student\n2.Professor\n3.Librarian\nEnter the login Type: ";
    cin>> user_type;
    int choice;
    cout<< "1. Register\n2: Login\nYour Choice: ";
    cin>>choice;
    if(choice == 1){
      string username, password,u_t;
      cout<<"select a username: ";cin>>username;
      cout<<"select a password: "; cin>>password;
      ofstream file;
      string filename="users/"+username + ".csv";
      file.open(filename.c_str());

      file<<username<<" ,"<<password<<","<<user_type<<endl;

      file.close();
    }
  }
  void Cli(){
    Book_database books;
    int choice1;
    cout<<"make changes to:\n1.Book_data\n2.User_data\n3.Issue_Book\n4.recieve_book"<<endl;
    cin>>choice1;

    if(choice1==1){
      int choice2;
      cout<<"1.Show_all_books\n2.Add_Book\n3.Delete_Book\n4.Search_Book\nEnter your Choice: ";
      cin>>choice2;
      switch(choice2){
        case 1:
          read_record();
          break;
        case 2:
          books.Add();
          break;
        case 3:
          books.Delete();
          break;
        case 4:
          books.Search();
          break;
        default:
          cout<<"\nwrong input\n";

      }
      
    }
    else if(choice1==2){
      int choice2;
      cout<<"1.Search_User\n2.Add_User\n3.Update_User\n4.Delete_User\nEnter your choice: ";
      cin>>choice2;
      switch(choice2){
        case 1:
          Search_User();
          break;
        case 2:
          Add_User();
          break;
        case 3:
          Update_User();
          break;
        case 4:
          Delete_User();
          break;
        default:
          cout<<"invalid input";
      }
    }
    else if(choice1==3){
      string book_name;
      string username;
    
      cout<<"Enter the name of book to be searched: ";
      cin>>book_name;

      if(!books.Search()){
        cout<<"Book named "+ book_name +" Note found";
      }
      else{
        cout<<"Enter the UserName: ";
        cin>>username;
        int date;
        int month;
        cout<<"enter day: ";
        cin>>date;
        cout<<"enter month: ";
        cin>>month;
        fstream booksdb;
        string filename="users/"+username+"db.txt";
        booksdb.open(filename.c_str(),ios::app);
        booksdb<<book_name<<","<<date<<","<<month<<endl;

      }
      
      
    }
    else if(choice1==4){
      string bookname;
      string username;
    
      cout<<"Enter the name of book to be recieved: ";
      cin>>bookname;

      if(!books.Search()){
        cout<<"Book named "+ bookname +" Note found";
      }

      else{
        cout<<"Enter the UserName: ";
        cin>>username;
        int date;
        int month;
        cout<<"enter day recieved: ";
        cin>>date;
        cout<<"enter month recieved: ";
        cin>>month;


        int count=0;
        fstream fin, fout;
        string filename="users/"+username+"db.txt";
        fin.open(filename.c_str(), ios::in);
        fout.open("books.csv", ios::out);
        string name;
        cout<<"Enter the name of book to be deleted: ";
        cin>>name;
        string line, word;
        vector<string> row;

        while(!fin.eof()){
          row.clear();
          getline(fin, line);
          stringstream s(line);

          while(getline(s,word,',')){
            row.push_back(word);

          }
          int row_size= row.size();
          if(row[0]!=name){
            if(!fin.eof()){
              for(int i=0;i<row_size-1; i++){
                fout<<row[i]<<",";
              }
              fout<<row[row_size-1]<<"\n";
            }
          }
          else{
            count = 1;
          }

          if( fin.eof()) break;
        }
        if(count==1) cout<<"book recieved\n";
        else cout<<"book record not found";

        fin.close();
        fout.close();

      }

    }
  }

  void Update_User(){
    Delete_User();
    Add_User();
  }

  void Delete_User(){
    string uname;
    cout<<"enter the uname: ";
    cin>>uname;
    string filename="users/"+uname+".txt";
    if(remove(filename.c_str())==0)
      cout<<"removed user";
    else cout<<"no user found";
  }

  void Search_User(){
    string uname;
    cout<<"enter the username: "; 
    cin>>uname;
    fstream fin;
  
    // Open an existing record
    fin.open("user/"+ uname +".csv", ios::in);
    if(!fin.eof()) cout<<"\nuser exist\n";
  };
};