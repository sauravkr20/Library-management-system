#include<iostream>
#include<string.h>
#include<stdlib.h>


#include "show_all_books.h"
#include "Login_Logout.h"
#include "Book_database.h"

#include "Users.h"


using namespace std;




int main(){

  // cout<<username<<" user";


  Librarian libr;
  Student stu;
  Professor prf;
  int user_type=Program_begin();

  // books.Search();


  if(user_type==1){
    stu.Cli();
  }
  else if(user_type==2){
    prf.Cli();
  }
  else if(user_type==3){
    libr.Cli();
  }
  
}