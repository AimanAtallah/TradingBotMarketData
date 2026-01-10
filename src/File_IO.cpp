//
//  openFile.cpp
//  
//
//  Created by Aiman Atallah on 1/8/26.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <cpr/cpr.h>
#include "File_IO.h"


std::ifstream openFile(){
    std::ifstream fileReader;
    
    fileReader.open("data/stocks.txt");
    
    if(!fileReader.is_open()){
        throw std::runtime_error("could not open file");
    }
    
    return fileReader;
}

void writeToFile(const cpr::Response& response, const std::string& path, const std::string& tickerName){
    std::istringstream iss;
    std::string line;
    std::ofstream data(path);
    
    iss.str(response.text);
    
    while(std::getline(iss, line)){
        data << tickerName << "," << line << "\n";
    }
    
    
}

void createTickerFile(const std::vector<std::string>& fileName){
    //take files
    //extract the lastest info line
    //then write them to a file named tickerFile
    
    std::ifstream fromFile;
    std::ofstream toTicker;
    std::string line;
    
    toTicker.open("data/tickerFile.txt");
    if (!toTicker.is_open()) {
        std::cerr << "Failed to open tickerFile.txt for writing\n";
        return;
    }
    std::cout<< "HELLO";
    for(int i = 0; i < fileName.size(); ++i){
        fromFile.open(fileName.at(i));
               if (!fromFile.is_open()) {
                   std::cerr << "Failed to open: " << fileName.at(i) << "\n";
                   continue;
               }
        std::getline(fromFile, line);
        
        for(int j = 0; j <= 0; ++j){
            std::getline(fromFile, line);
            
            toTicker << line << "\n";
        }
        fromFile.close();
    }
    toTicker.close();
}

