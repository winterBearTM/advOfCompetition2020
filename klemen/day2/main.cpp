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
      int horizontalPos = 0;
      int depth = 0;
      string row;
      vector<string> lines;
      while(getline(newfile, row)){ //read data from file object and put it into string.
         lines.push_back(row);
      }

      for(int i = 0; i < lines.size(); ++i){
         if(lines[i][0]=='f'){ //8
            horizontalPos = horizontalPos + int(lines[i].at(8));
            cout << "down for" << int(lines[i].at(8)) << endl;
         }
         if(lines[i][0]=='u'){
            depth = depth - int(lines[i].at(3));
            cout << "up for" << int(lines[i].at(3)) << endl;
         }
         if(lines[i][0]=='d'){
            depth = depth + int(lines[i].at(5));
            cout << "down for" << int(lines[i].at(5)) << endl;
         }
      }
      

      cout << "horizontal position: "<< horizontalPos << ", depth:" << depth << " mul:" << depth*horizontalPos << endl;

      newfile.close(); //close the file object.
   }else{
      cout << "file was not opened." << "\n";
   }

   auto stop = chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
   cout << "time elapsed: "<< duration.count() << "us" << endl;
}