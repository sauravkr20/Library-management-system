#include<fstream>
#include<iostream>
#include<string>
#include<sstream>


using namespace std;

int main(){
  ofstream file;
  string user= "abc";
  file.open("users/"+user+".txt");
}