#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstring>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
   auto start = chrono::high_resolution_clock::now();
   cout << "starting..." << "\n";

   fstream newfile;
   newfile.open("input.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open

      // Declarations
      vector<int> crabs;
      
      string row;
      // Load input into memory
      while(getline(newfile, row)){ //read data from file object and put it into string.
         char* copy = strdup(row.c_str());
         char *ptr; // declare a ptr pointer  
         ptr = strtok(copy, ","); // use strtok() function to separate string using comma (,) delimiter.  
         // use while loop to check ptr is not null  
         while (ptr != NULL)  
            {  
               crabs.push_back(stoi(ptr));

               ptr = strtok (NULL, ",");  
            }  
         free(copy);
      }
      cout << "array size is " << crabs.size() << endl;

      // // Operations

      auto max = max_element(crabs.begin(), crabs.end());
      cout << "biggest element is " << *max << endl;

      vector<int> fuelUsed(*max, 0);

      for(int i = 0; i < *max; i++){
         for(int j = 0; j < crabs.size(); j++){
            fuelUsed[i] = fuelUsed[i] + abs((i+1)-crabs[j]); 
         }
      }

      auto min = min_element(fuelUsed.begin(), fuelUsed.end());
      cout << "lowest consumption is " << *min << endl;

      // get number of crabs
      // get min and max
      // for every int between min and max
      // iterate over array of crabs and sum differences between value and int
      newfile.close(); //close the file object.

   }else{
      cout << "file was not opened." << "\n";
   }

   auto stop = chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
   cout << "time elapsed: "<< duration.count() << "us" << endl;
}