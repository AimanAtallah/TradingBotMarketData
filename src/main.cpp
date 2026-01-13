#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <vector>
#include <fstream>
#include <filesystem>
#include "File_IO.h"
#include "market_data_service.h"
#include "stockClass.h"
#include "ticker_view.h"
#include "createVector.h"
#include "main_menu.h"


 int main(){
     std::vector<std::string> fileNames;

     for(auto& entry : std::filesystem::directory_iterator("data")){
         fileNames.push_back(entry.path().string());
     }
    
     createTickerFile(fileNames);
     
     std::ifstream file("data/tickerFile.txt");

     if (!file) {
         std::cerr << "FAILED to open tickerFile.txt\n";
         return 1;
     }
     
     auto stocks = createVector(file);
     
     
     renderTicker(stocks);
     


    return 0;
}
