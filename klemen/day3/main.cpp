#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <chrono>

using namespace std;



string returnMostCommon(int inputs[], int size, char searched, int pos){
   vector<string> result;
   int ones = 0;
   int zeros = 0;
   for(int i = 0; i < size; i++){
      if(inputs[i] == '0'){
         ones++;
      }else if(inputs[i] == '1'){
         zeros++;
      }else{
         cout << "error" << endl;
      }
   }
   if(ones > zeros){
      for(int i = 0; i < size; i++){
         if(inputs[i][pos] == '1'){
            result.push_back(inputs[i]);
         }
      }

   }else if(zeros > ones){
      for(int i = 0; i < size; i++){
         if(inputs[i][pos] == '0'){
            result.push_back(inputs[i]);
         }
      }
   }else{
      cout << "error" << endl;
   }


   for(int i = 0; i < result.size(); i++){
      cout << result[i] << endl;
   }
}


int main(){
   auto start = chrono::high_resolution_clock::now();
   cout << "starting..." << "\n";

   fstream newfile;
   newfile.open("input.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open

      // Declarations
      vector<string> lines;
      string row;
      string line;

      // method : sum and invert

      int ones[12]={0,0,0,0,0,0,0,0,0,0,0,0};
      int zeros[12]={0,0,0,0,0,0,0,0,0,0,0,0};
      int gamma[12]={0,0,0,0,0,0,0,0,0,0,0,0};
      int epsilon[12]={0,0,0,0,0,0,0,0,0,0,0,0};

  
      // Load input into memory
      while(getline(newfile, row)){ //read data from file object and put it into string.
         lines.push_back(row);
      }

      // // Operations

      // Turn to int array

      for(int i = 0; i < lines.size(); i++){
         line = lines[i];
         //cout << line << endl;

         // Sum with ones
         for (int j = 0; j < line.length(); j++) {
            ones[j] = ones[j] + (line.at(j) - '0');
         }
         
         // Invert
         string invline = "000000000000";

         for (int j = 0; j < line.length(); j++) {

            if(line[j] == '0'){
               invline[j] = '1';
            }else if(line[j] == '1'){
               invline[j] = '0';
            }else{
               cout << "error" << endl;
            }
         }

         // Sum with zeros
         for (int j = 0; j < invline.length(); j++) {
            zeros[j] = zeros[j] + (invline.at(j) - '0');
         }  
         //ones = ones + arr;

         //

      }
         // Get max number from both arrays at index

      for (int j = 0; j < 12; j++) {
         cout << ones[j] << " | " << zeros[j] << endl;

         if(ones[j] > zeros[j]){
            gamma[j] = 1;
            epsilon[j] = 0;
         }else if(ones[j] < zeros[j]){
            gamma[j] = 0;
            epsilon[j] = 1;
         }
      }  

      string strgamma = "";
      string strepsilon = "";

      for (int j = 0; j < 12; j++) {
         strgamma.push_back(gamma[j] + '0');
         strepsilon.push_back(epsilon[j] + '0');
      }

      cout << "gamma: " << strgamma << endl;
      cout << "epsilon: "<< strepsilon << endl;

      newfile.close(); //close the file object.
   }else{
      cout << "file was not opened." << "\n";
   }

   auto stop = chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
   cout << "time elapsed: "<< duration.count() << "us" << endl;
}