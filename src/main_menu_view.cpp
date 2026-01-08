//
//  main_menu_view.cpp
//  
//
//  Created by Aiman Atallah on 1/8/26.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <stdexcept>
#include <functional>
#include "createVector.h"
#include "ticker_view.h"
#include "openFile.h"
#include "sideMenu.h"

void mainMenu(){
    std::vector<stockClass> myVec;
    
    try{
        std::ifstream file = openFile();
        myVec = createVector(file);
    }catch(const std::runtime_error& e){
        std::cerr << e.what() << std::endl;
        return;
    }
    
    
    std::thread renderThread(renderTicker, std::cref(myVec));
    renderThread.detach();
    
    std::cout << std::endl;
    
    sideMenu();
    sideMenu();
    

}
