//
//  tiker_view_model.cpp
//  
//
//  Created by Aiman Atallah on 1/9/26.
//

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "stockClass.h"
#include "ticker_view_model.h"



void clearScreen(){
    std::cout << "\033[2J\033[H\033[3J" << std::flush;
}


std::vector<std::string> fillSource(const std::vector<stockClass>& stocks){
    std::vector<std::string> source(stocks.size());
    int counter = 0;
    
    for(const auto& stock : stocks){
        std::string tempLine;
        std::ostringstream oss;
        
        oss << std::left
        << stock.getTicker()
        << stock.getOpen()
        << stock.getHigh()
        << stock.getLow()
        << stock.getClose()
        << stock.getVolume();
        
        tempLine = oss.str();
        
        
        source.at(counter) = tempLine;
        
        counter++;
        
    }
    
    return source;
}

