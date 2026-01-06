 #include <iostream>
 #include <fstream>
 #include <string>
 #include <fstream>
 #include <sstream>
 #include <vector>
 #include <cctype>
 #include <stdexcept>
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
    tempStock.setTicker(tempTick);
    
    //this is need incase file is incorecctly formatted and stod fails
    try {
        tempStock.setPrice(std::stod(tempPrice));
        tempStock.setMovement(std::stod(tempMovement));
    }
    catch (const std::invalid_argument&) {
        throw std::runtime_error("file incorrectly formatted");
    }
    catch (const std::out_of_range&) {
        throw std::runtime_error("file incorrectly formatted");
    }


    
    
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
