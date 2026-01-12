#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <stdexcept>
#include "stockClass.h"
#include "createVector.h"

stockClass parse_data(const std::string& line){
    stockClass tempStock;

    std::string tempTick;
    std::string tempOpen;
    std::string tempVolume;
    std::string tempHigh;
    std::string tempLow;
    std::string tempDateTrash;
    std::string tempClose;

    std::stringstream ss(line);
    
    std::getline(ss, tempTick, ',');
    std::getline(ss, tempDateTrash, ',');
    std::getline(ss, tempOpen, ',');
    std::getline(ss, tempHigh, ',');
    std::getline(ss, tempLow, ',');
    std::getline(ss, tempClose, ',');
    std::getline(ss, tempVolume, ',');

    for(auto& c : tempTick){
        c = std::toupper(c);
    }
    
    tempStock.setTicker(tempTick);
    try{
        tempStock.setOpen(std::stod(tempOpen));
        tempStock.setHigh(std::stod(tempHigh));
        tempStock.setLow(std::stod(tempLow));
        tempStock.setClose(std::stod(tempClose));
        tempStock.setVolume(std::stoll(tempVolume));
    }catch(const std::invalid_argument&){
       throw std::runtime_error("failed to convert");
    }catch(const std::out_of_range&){
        throw std::runtime_error("failed to convert");
    }
    
    //test case tempStock.printData();

    return tempStock;
}


std::vector<stockClass> createVector(std::ifstream& fileReader){
    std::vector<stockClass> stocks;
    std::string line;
    int count = 0;
    
    while (std::getline(fileReader, line)) {
        if (line.empty()) continue;
        try {
            stocks.push_back(parse_data(line));
            count++;
        } catch (const std::exception& e) {
            std::cerr << "PARSE ERROR on line:\n" << line << "\n";
            std::cerr << e.what() << "\n";
        }
    }
    //test case std::cout << "This funtion should run 6 times it ran: " << count << std::endl;
    
    return stocks;
}
