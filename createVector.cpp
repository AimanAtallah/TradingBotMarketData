 #include <iostream>
 #include <thread>
 #include <chrono>
 #include <fstream>
 #include <string>
 #include <fstream>
 #include <sstream>
 #include <vector>
 #include "stockClass.h"

vector<stockClass> createVector(ifstream& fileReader){
    vector<stockClass> stocks;
    stringstream ss;
    string line;
    
    while(getline(fileReader, line)){
       stockClass tempStock;
        string tempTick;
        string tempName;
        string tempPrice;
        string tempMovement;
        ss.clear();
        ss.str(line);
        
        getline(ss, tempTick, '|');
        getline(ss, tempName, '|');
        getline(ss, tempPrice, '|');
        getline(ss,tempMovement, '|');
        
        tempStock.setName(tempName);
        tempStock.setPrice(stod(tempPrice));
        tempStock.setMovement(stod(tempMovement));
        tempStock.setTicker(tempTick);
        
        stocks.push_back(tempStock);
    }
    
    return stocks;
    
}