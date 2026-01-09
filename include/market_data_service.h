//
//  market_data_service.h
//  
//
//  Created by Aiman Atallah on 1/9/26.
//

#ifndef MARKERT_DATA_SERVICE
#define MARKERT_DATA_SERVICE


#include <cpr/cpr.h>

cpr::Response getMarketData(const std::string& ticker_symbol);


#endif // !MARKERT_DATA_SERVICE

