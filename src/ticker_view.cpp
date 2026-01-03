//
//  ticker_view.cpp
//  
//
//  Created by Aiman Atallah on 1/3/26.
//
#include <vector>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "stockClass.h"


void renderTicker(const std::vector<stockClass>& stocks){
    int num_of_stocks = stocks.size();
    int vector_Data_Size = (num_of_stocks * 4) - num_of_stocks;
    const int FRAMES_PER_SECOND = 1;
    const int DISPLAY_LIMIT = 8;
    const int FIRST_ELEMENT = 0;
    
    std::vector<string> source(vector_Data_Size);
    std::vector<string> tickerName(num_of_stocks, " ");
    std::vector<string> tickerNameSource(num_of_stocks);
    std::vector<string> tickerData(vector_Data_Size, " ");
    std::string tempLine;
    
    int counter = 0;
    int name_Counter = 0;
    
    for(const auto& stock : stocks){
        
        tickerNameSource.at(name_Counter) = stock.getTicker();
        name_Counter++;
    
        
        source.at(counter) = stock.getName();
        counter++;
        
        tempLine = std::to_string(stock.getPrice());
        source.at(counter) = tempLine;
        counter++;
        
        tempLine = std::to_string(stock.getMovement());
        source.at(counter) = tempLine;
        counter++;
    }
    counter = 0;
    name_Counter = 0;
    
    while(true){
        
        tickerData.at(0) = source.at(counter);
        tickerName.at(0) = tickerNameSource.at(name_Counter);
        
        name_Counter = (name_Counter + 1) % num_of_stocks;
        counter = (counter + 1) % vector_Data_Size;
        
        std::cout << "\033[2J\033[H";
        
        //Load Stocks
        for(int i = vector_Data_Size - 1; i > FIRST_ELEMENT; --i){
            tickerData.at(i) = tickerData.at(i - 1);
        }
        for(int i = num_of_stocks - 1; i > FIRST_ELEMENT; --i){
            tickerName.at(i) = tickerName.at(i - 1);
        }
        
        
        //Display stocks
        for(int i = num_of_stocks - 1; i >= FIRST_ELEMENT; --i){
            std::cout << tickerName.at(i);
        }
        
        std::cout << "\n";
        
        for(int i = DISPLAY_LIMIT; i >= FIRST_ELEMENT; --i){
            std::cout << tickerData.at(i) << " | ";
        }
        
        std::cout << std::flush;
        
        
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/FRAMES_PER_SECOND));
        
        
    }
    
    
}
