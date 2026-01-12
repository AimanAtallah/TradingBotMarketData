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


//---------------------------------------------------------------------------------------------------------------------------------//
void clearScreen(){
    std::cout << "\033[2J\033[H\033[3J" << std::flush;
}

//---------------------------------------------------------------------------------------------------------------------------------//
std::vector<std::string> fillSource(const std::vector<stockClass>& stocks){
    std::vector<std::string> source;
    source.reserve(stocks.size() * 6);
    
    
    for(const auto& stock : stocks){
        std::ostringstream oss;
                

        // Ticker
        oss << std::left << std::setw(7) << " | " << stock.getTicker();
        source.push_back(oss.str());
        oss.str(""); oss.clear();

        // Open
        oss << " Open: " << std::right << stock.getOpen();
        source.push_back(oss.str());
        oss.str(""); oss.clear();

        // High
        oss << " High: " << std::right << stock.getHigh();
        source.push_back(oss.str());
        oss.str(""); oss.clear();

        // Low
        oss << " Low: " << std::right << stock.getLow();
        source.push_back(oss.str());
        oss.str(""); oss.clear();

        // Close
        oss << " Close: " << std::right << stock.getClose();
        source.push_back(oss.str());
        oss.str(""); oss.clear();

        // Volume
        oss << " Volume: " << stock.getVolume();
        source.push_back(oss.str());
        oss.str(""); oss.clear();
    }
    
    return source;
}

//---------------------------------------------------------------------------------------------------------------------------------//
