#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <chrono>

using namespace std;

int main(){
   auto start = chrono::high_resolution_clock::now();
   cout << "starting..." << "\n";

   fstream newfile;
   newfile.open("input.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      int increments = 0;
      string row;
      vector<int> lines;
      while(getline(newfile, row)){ //read data from file object and put it into string.
         lines.push_back(stoi(row));
      }
      for(int i = 0; i < lines.size(); ++i){
         if(lines[i] < lines[i+1]){
         increments++;
         }
      }
      cout << increments << "\n";
      newfile.close(); //close the file object.
   }else{
      cout << "file was not opened." << "\n";
   }
   auto stop = chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
   cout << "time elapsed: "<< duration.count() << "us" << endl;
}