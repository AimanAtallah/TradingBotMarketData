//
//  openFile.cpp
//  
//
//  Created by Aiman Atallah on 1/8/26.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "openFile.h"


std::ifstream openFile(){
    std::ifstream fileReader;
    
    fileReader.open("data/stocks.txt");
    
    if(!fileReader.is_open()){
        throw std::runtime_error("could not open file");
    }
    
    return fileReader;
}
