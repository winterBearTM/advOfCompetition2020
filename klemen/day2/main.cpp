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
      int f = 0;
      int u = 0;
      int d = 0;
      string line;
      string row;
      vector<string> lines;
      while(getline(newfile, row)){ //read data from file object and put it into string.
         lines.push_back(row);
      }

      for(int i = 0; i < lines.size(); i++){
         line = lines[i];
         if(line.at(0) == 'f'){ //8
            cout << line.at(8) - '0' << endl;
            horizontalPos = horizontalPos + (line.at(8) - '0');
            f++;
         }else if(line.at(0) == 'u'){
            depth = depth - (line.at(3) - '0');
            u++;
         }else if(line.at(0) == 'd'){
            depth = depth + (line.at(5) - '0');
            d++;
         }else{
            cout << "unparseable line: " << lines[i] << endl;
         }
      }
      cout << f << " " << u << " " << d << " " << endl;
      cout << "horizontal position: "<< horizontalPos << ", depth: " << depth << " mul: " << depth*horizontalPos << endl;

      newfile.close(); //close the file object.
   }else{
      cout << "file was not opened." << "\n";
   }

   auto stop = chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
   cout << "time elapsed: "<< duration.count() << "us" << endl;
}