//
//  openFile.h
//  
//
//  Created by Aiman Atallah on 1/8/26.
//

#ifndef FILE_IO_H
#define FILE_IO_H
#include <cpr/cpr.h>



std::ifstream openFile();
void writeToFile(const cpr::Response& response, const std::string& path, const std::string& tickerName);
void createTickerFile(const std::vector<std::string>& fileName);


#endif // !FILE_IO_H
