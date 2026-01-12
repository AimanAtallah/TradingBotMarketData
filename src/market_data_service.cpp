//
//  market_data_service.cpp
//  
//
//  Created by Aiman Atallah on 1/9/26.
//
#include <cpr/cpr.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <fstream>
#include "File_IO.h"
//---------------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------------------//
cpr::Response getMarketData(const std::string& ticker_symbol, const std::string& API_KEY){

    auto response = cpr::Get(cpr::Url("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol="
                           +ticker_symbol+"&apikey="
                           +API_KEY+"&datatype=csv"));
    return response;
}

//---------------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------------------//
void setApiKey(){
    std::string apiKey;
    std::ofstream apiKeyWriter;
    
    apiKeyWriter.open("userData/apiKey.txt");
    if(!apiKeyWriter){
        std::cerr << "Could not save API KEY";
        return;
    }
    
    std::cout << "Enter API key: ";
    std::getline(std::cin >> std::ws, apiKey);
    
    apiKeyWriter << apiKey << "\n";
    
    apiKeyWriter.close();
}


//---------------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------------------//

std::string getApiKey(){
    bool gotKey = false;
    std::string api_Key;
    int counter = 0;
    
    while(counter <= 5 && !gotKey){
        std::ifstream getKey("userData/apiKey.txt");
        counter++;
        
        if(!getKey){
            std::cerr << "Could not retrieve api key \n";
            setApiKey();
            continue;
        }
        
        getline(getKey, api_Key);
        
        if(api_Key.empty()){
            setApiKey();
            getKey.close();
            continue;
        }
        
        gotKey = true;
        getKey.close();
    }
    if(!gotKey){
        throw std::runtime_error("Failes to obtain API Key after 5 tries\n");
    }
    
    return api_Key;
}


//---------------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------------------//

std::vector<std::string> getStocks(){
    std::vector<std::string> fileNames;
    std::string ticker = "";
    std::string path;
    std::string API_KEY;
    
    try{
       API_KEY = getApiKey();
    }catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
        return fileNames;
    }


    while(ticker != "q" ){
    
        std::cout << "enter a ticker: ";
        std::getline(std::cin >> std::ws, ticker);
        
        if(ticker != "q"){
            auto response = getMarketData(ticker, API_KEY);
            path ="data/" + ticker + ".txt";
            fileNames.push_back(path);
            
            writeToFile(response, path, ticker);
        }
        
    }
    return fileNames;
}
//---------------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------------------//
