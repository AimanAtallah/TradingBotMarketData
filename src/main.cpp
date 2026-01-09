#include "market_data_service.h"
#include <iostream>
#include <string>
#include <cpr/cpr.h>





 int main(){
// 1. make the menu interface
// 2. connect it to live market data
// 3. possibly add trading interface
         
     
     std::string ticker;
     std::cout << "enter a ticker: ";
     std::cin >> ticker;
     
    auto response = getMarketData(ticker);
     
    
     std::cout << response.text << std::endl;
     
    

    return 0;
}
