#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "createVector.h"
#include "ticker_view.h"
 

using namespace std;


 int main(){
// 1. make the menu interface
// 2. connect it to live market data
// 3. possibly add trading interface
     
    // place this into its own file openFile()
    ifstream fileReader;
    fileReader.open("data/stocks.txt");
    
    if(!fileReader.is_open()){
        std::cerr << "could not open file";
        return 1;
    }
    
     vector<stockClass> myVec;
     try{
         myVec = createVector(fileReader);
     }catch(const runtime_error& e){
         cerr << e.what() << endl;
     }
     
     renderTicker(myVec);
    

    return 0;
}
