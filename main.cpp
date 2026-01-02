 #include <iostream>
 #include <fstream>
 
 using namespace std;
 
 int main(){
// 1. make the menu interface
// 2. connect it to live market data
// 3. possibly add trading interface

     
    
    ifstream fileReader;
    
     
    fileReader.open("stocks.txt");
    
    if(!fileReader.is_open()){
        std::cerr << "could not open file";
        return 1;
    }
    
    
    

    return 0;
}
