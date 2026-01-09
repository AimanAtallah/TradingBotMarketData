//
//  ticker_view.h
//  
//
//  Created by Aiman Atallah on 1/3/26.
//
#ifndef TICKER_VIEW
#define TICKER_VIEW

void clearScreen();
void renderTicker(const std::vector<stockClass>& stocks);
std::vector<string> fillSource(const std::vector<stockClass>& stocks);



#endif // !TICKER_VIEW
