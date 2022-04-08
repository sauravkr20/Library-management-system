#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<filesystem>

using namespace std;


void read_record()
{
  
    // File pointer
    fstream fin;
    fin.open("books.csv", ios::in);

    vector<string> row;
    string line, word;
  
    while (!fin.eof()) {
      row.clear();
      getline(fin, line);
      stringstream s(line);
      
      while (getline(s, word, ',')) {
        row.push_back(word);
      }
      cout<<"Title: "<<row[0]<<"\nAuthor: "<<row[1]<<"\nISBN: "<<row[2]<<"\nPublication: "<<row[3]<<"\nIssued to: "<<row[4]<<endl<<endl;

    }
    cout<<"finished\n";
    fin.close();
}