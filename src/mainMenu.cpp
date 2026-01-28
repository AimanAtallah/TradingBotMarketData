//
//  mainMenu.cpp
//  
//
//  Created by Aiman Atallah on 1/12/26.
//
#include <iostream>
#include <iomanip>
#include "main_menu.h"


void printMainMenu(){
    std::cout << "\033[32m";
    std::cout << std::setw(50) << std::setfill('-') << "\n";
    std::cout << std::setw(50) << std::setfill('-') << "\n";
    std::cout << std::setw(50) << std::setfill('-') << "\n";
    std::cout << "\033[33m";
    std::cout << "\033[6;15H\033[33m\033[1;4mWelcome!!!\033[0m";
    std::cout << "\033[0m" <<"\n\n\n";
    std::cout << "\033[34m" << "\033[4m";
    std::cout << "[T]" << std::left << " 📈 Look up stock price\n";
    std::cout << "[S]" << std::left << " 💰 Buy or Sell stock\n";
    std::cout << "[C]" << std::left << "\033[33m" << " ฿ " << "\033[34m" << "Buy or Sell crypto\n";
    std::cout << "[B]" << std::left << " 🤖 Trading Bot\n";
    std::cout << "\033[91m[Q]" << std::left << "\033[91m Quit"  <<  std::endl;
    
    std::cout << "\033[0m" <<"\n\n\n";
    std::cout << "\033[32m";
    std::cout << std::setw(50) << std::setfill('-') << "-\n";
    std::cout << std::setw(50) << std::setfill('-') << "-\n";
    std::cout << std::setw(50) << std::setfill('-') << "-\n";
}
//todo: finish the menu views
void buySellStocksMenu(){};
void priceLookUpMenu(){};
void buySellCrypto(){};
void tradingBotMenu(){};

