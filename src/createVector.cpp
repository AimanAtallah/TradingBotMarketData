 #include <iostream>
 #include <fstream>
 #include <string>
 #include <fstream>
 #include <sstream>
 #include <vector>
 #include "stockClass.h"


stockClass parse_data(const string& line){
    stockClass tempStock;
        string tempTick;
        string tempName;
        string tempPrice;
        string tempMovement;
        stringstream ss;
    
        ss.str(line);
        
        getline(ss, tempTick, '|');
        getline(ss, tempName, '|');
        getline(ss, tempPrice, '|');
        getline(ss,tempMovement, '|');
        
        tempStock.setName(tempName);
        tempStock.setPrice(stod(tempPrice));
        tempStock.setMovement(stod(tempMovement));
        tempStock.setTicker(tempTick);

    
    
    return tempStock;
}



vector<stockClass> createVector(ifstream& fileReader){
    vector<stockClass> stocks;
    stringstream ss;
    string line;
    
    
    
    while(getline(fileReader, line)){
        stringstream ss;
        ss.str(line);
        
        if (line.empty()) continue;

        stocks.push_back(parse_data(line));
        
    }
    
    return stocks;
    
}
