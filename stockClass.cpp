#include "stockClass.h"

using namespace std;

        stockClass::stockClass(){
            this->price = 0.0;
            this->movement = 0.0;
            this->name = "none";
            this->ticker = "none";
        };
        stockClass::stockClass(double price,
                               double movement,
                               string name,
                               string ticker):
        
        price(price),
        movement(movement),
        name(name),
        ticker(ticker)
        {};
        
        const string& stockClass::getName() const{
            return this->name;
        }
        void stockClass::setName(const string& name){
            this->name = name;
        }
        const string& stockClass::getTicker() const{
            return this->ticker;
        }
        void stockClass::setTicker(const string& ticker){
            this-> ticker = ticker;
        }
        double stockClass::getPrice() const{
            return this->price;
        }
        void stockClass::setPrice(double price){
            this->price = price;
        }
        double stockClass::getMovement() const{
            return this->movement;
        }
        void stockClass::setMovement(double movement){
            this->movement = movement;
        }
        
        
        
        
        
        
        
        
        