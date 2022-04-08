#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <sstream>

using namespace std;

class Book{
  public:
  string Title;
  string Author;
  string ISBN;
  string Publication;
  string Issued_To;
  void Book_Request();
  void Show_duedate();
};


class Book_database:Book{
  public:
  
  void skip_line(int n){
    fstream books;
    // read
    books.open("books.csv",ios::app);
    while(n--){
      getline(books,Title,',');
      getline(books,Author,',');
      getline(books,ISBN,',');
      getline(books,Publication,',');
    }
  }
  void display_book(){
    fstream books;
    books.open("books.csv", ios::app);

    books<<Title<<","<<Author<<","<<ISBN<<","<<Publication<<"\n";
  }
  void Add(){
    cout<<"enter the title: ";
    cin>>Title;
    cout<<"Enter the Author: ";
    cin>>Author;
    cout<<"Enter the ISBN: ";
    cin>>ISBN;
    cout<<"Enter the Publication: ";
    cin>>Publication;
    fstream books;
    books.open("books.csv",ios::app);
    books<<Title<<","<<Author<<","<<ISBN<<","<<Publication<<",NULL"<<"\n";
  }
  void Delete(){
    int count=0;
    fstream fin, fout;
    fin.open("books.csv", ios::in);
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
    if(count==1) cout<<"Record deleted\n";
    else cout<<"Record not found";

    fin.close();
    fout.close();
  }
  bool Search(){
    int count=0;
    fstream fin;
    fin.open("books.csv", ios::in);
    string name;
    cout<<"Enter the name of book to be searched: ";
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
      if(row[0]==name){
        cout<<"Title: "<<row[0]<<"\nAuthor: "<<row[1]<<"\nISBN: "<<row[2]<<"\nPublication: "<<row[3]<<"\nIssued to: "<<row[4];
        count=1;
        return true;
      }
      if( fin.eof()) break;
      return false;
    }

    if(count==1) cout<<"\nRecord found\n";
    else cout<<"\nRecord not found\n";

    fin.close();
    fin.close();
  }

};


