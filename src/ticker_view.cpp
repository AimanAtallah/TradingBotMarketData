//
//  ticker_view.cpp
//  
//
//  Created by Aiman Atallah on 1/3/26.
//
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include <iomanip>
#include "stockClass.h"
#include "ticker_view.h"



void clearScreen(){
    std::cout << "\033[2J\033[H";
}


void renderTicker(const std::vector<stockClass>& stocks){
    const int FRAMES_PER_SECOND = 1;
    const int FIRST_ELEMENT = 0;
    const int  OFFSET = 1;
    int num_of_stocks = stocks.size();
    int counter = 0;
    int DISPLAY_LIMIT;
    
    
    if(num_of_stocks == 0) return;//safety check
    
    std::vector<string> source(num_of_stocks);
    std::vector<string> tickerData(num_of_stocks);
    
    if(num_of_stocks <= 6 && num_of_stocks > 0){
        DISPLAY_LIMIT = num_of_stocks - 1;
    }else{
        DISPLAY_LIMIT = 6;
    }
    
   
    
    
    for(const auto& stock : stocks){
        std::string tempLine;
        std::ostringstream oss;
        
        oss << std::left
            << stock.getTicker()<<" "
            << stock.getName()  <<" "
            << stock.getPrice() <<" "
            << stock.getMovement();
        
        tempLine = oss.str();
        
        
        source.at(counter) = tempLine;
        
        counter++;

    }
    counter = 0;
    
    while(true){
        
        tickerData.at(0) = source.at(counter);
        
        counter = (counter + 1) % num_of_stocks;
        
        clearScreen();
        
        //Load Stocks
        for(int i = num_of_stocks - 1; i > FIRST_ELEMENT; --i){
            tickerData.at(i) = tickerData.at(i - OFFSET);
        }

        //Display Stocks
        for(int i = DISPLAY_LIMIT; i > FIRST_ELEMENT; --i){
            std::cout << tickerData.at(i) << " | ";
        }
    
        std::cout << std::flush;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1200/FRAMES_PER_SECOND ));
        
        
    }
    
    
}
