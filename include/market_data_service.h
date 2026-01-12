//
//  market_data_service.h
//  
//
//  Created by Aiman Atallah on 1/9/26.
//

#ifndef MARKERT_DATA_SERVICE
#define MARKERT_DATA_SERVICE

#include <cpr/cpr.h>
#include <string>
#include <vector>

cpr::Response getMarketData(const std::string& ticker_symbol, const std::string& API_KEY);
std::vector<std::string> getStocks();
std::string getApiKey();
void setApiKey();


#endif // !MARKERT_DATA_SERVICE

