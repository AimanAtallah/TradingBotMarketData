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
#include <filesystem>
#include "File_IO.h"

//---------------------------------------------------------------------------------------------------------------------------------//
std::ifstream openFile(){
    std::ifstream fileReader;
    
    fileReader.open("data/stocks.txt");
    
    if(!fileReader.is_open()){
        throw std::runtime_error("could not open file");
    }
    
    return fileReader;
}

//---------------------------------------------------------------------------------------------------------------------------------//

void writeToFile(const cpr::Response& response, const std::string& path, const std::string& tickerName){
    std::istringstream iss;
    std::string line;
    std::ofstream data(path);
    if(!data.is_open()){
        std::cerr << "Could not save ticker data due to file error: " << path << "\n";
        return;
    }
    if(response.status_code != 200){
        std::cerr << "Could not retrieve market data " << tickerName << "\n";
        return;
    }
    
    if(response.status_code == 200){
        iss.str(response.text);
        while(std::getline(iss, line)){
            data << tickerName << "," << line << "\n";
        }
    }
    
}

//---------------------------------------------------------------------------------------------------------------------------------//

void createTickerFile(const std::vector<std::string>& fileFolder){
    std::ifstream fromFile; //reads from file
    std::ofstream toTicker; //writes to file
    
    toTicker.open("data/tickerFile.txt");
    if (!toTicker.is_open()) {
        std::cerr << "Failed to open tickerFile.txt for writing\n";
        return;
    }
    
    for(const auto& file : fileFolder){
        if(file == "data/tickerFile.txt"){
            continue;
        }
        fromFile.open(file);
        std::string line; // stores lastet data from each file
        
        if(!fromFile.is_open()){
            std::cerr << "Failed to open: " << file << "\n";
            continue;
        }
        if(!std::getline(fromFile, line)){
            std::cerr << "File " << file << " is empty.\n";  //checks for empty file and removes header
            fromFile.close();
            fromFile.clear();
            continue;
        }
      

        std::getline(fromFile, line);
        
        if(!line.empty()){
            toTicker << line << "\n";
        }
        
        fromFile.close();
        fromFile.clear();
    }
    
    toTicker.close();
}

//---------------------------------------------------------------------------------------------------------------------------------//
