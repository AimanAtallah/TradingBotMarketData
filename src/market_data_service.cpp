//
//  market_data_service.cpp
//  
//
//  Created by Aiman Atallah on 1/9/26.
//
#include <cpr/cpr.h>
#include <iostream>
#include <string>



//call stock data from
cpr::Response getMarketData(const std::string& ticker_symbol, const std::string& API_KEY){

    auto response = cpr::Get(cpr::Url("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol="
                           +ticker_symbol+"&apikey="
                           +API_KEY+"&datatype=csv"));
    
    
    return response;
}
