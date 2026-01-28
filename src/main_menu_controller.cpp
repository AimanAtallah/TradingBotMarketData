#include "main_menu_controller.h"
#include "menu_select.h"
#include "main_menu.h"
#include <iostream>


void handleMenuSelect() {
    printMainMenu();

    char userMenuSelect;
    std::cin >> userMenuSelect;

    MenuSelect menu;

    switch (userMenuSelect) {
        case 'T': case 't':
            menu = MenuSelect::PriceLookUp;
            break;

        case 'S': case 's':
            menu = MenuSelect::BuySellStocks;
            break;

        case 'C': case 'c':
            menu = MenuSelect::BuySellCrypto;
            break;

        case 'B': case 'b':
            menu = MenuSelect::TradingBot;
            break;

        case 'Q': case 'q':
            menu = MenuSelect::Quit;
            break;

        default:
            return;
    }

    switch (menu) {
        case MenuSelect::BuySellStocks:
            buySellStocksMenu();
            break;
        case MenuSelect::PriceLookUp:
            priceLookUpMenu();
            break;
        case MenuSelect::BuySellCrypto:
            buySellCrypto();
            break;
        case MenuSelect::Quit:
            break;
        case MenuSelect::TradingBot:
            tradingBotMenu();
            break;
    }
}
