#include <iostream>
#include <fstream>
#include <vector>
#include "createVector.h"
#include "ticker_view.h"
 using namespace std;
 
 int main(){
// 1. make the menu interface
// 2. connect it to live market data
// 3. possibly add trading interface

     
    
    ifstream fileReader;
     vector<stockClass> myVec;
     
    fileReader.open("data/stocks.txt");
    
    if(!fileReader.is_open()){
        std::cerr << "could not open file";
        return 1;
    }
    
     myVec = createVector(fileReader);
     
     renderTicker(myVec);
    

    return 0;
}
