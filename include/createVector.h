//
//  createVector.h
//  
//
//  Created by Aiman Atallah on 1/2/26.
//
#ifndef CREATEVECTOR_H
#define CREATEVECTOR_H
#include <string>
#include <vector>
#include <fstream>
#include "stockClass.h"


stockClass parse_data(const std::string& line);
std::vector<stockClass> createVector(std::ifstream& fileReader);


#endif // !CREATEVECTOR_H
