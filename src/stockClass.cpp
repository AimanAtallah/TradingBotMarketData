#include "stockClass.h"
#include <iostream>

stockClass::stockClass(){
    this->ticker = "none";
    this->date   = "none";
    this->open   = 0.0;
    this->high   = 0.0;
    this->low    = 0.0;
    this->close  = 0.0;
    this->volume = 0;
}

stockClass::stockClass(const std::string& ticker,
                       const std::string& date,
                       double open,
                       double high,
                       double low,
                       double close,
                       long long volume)
    : ticker(ticker),
      date(date),
      open(open),
      high(high),
      low(low),
      close(close),
      volume(volume)
{}

// -------- getters --------
const std::string& stockClass::getTicker() const{
    return this->ticker;
}

const std::string& stockClass::getDate() const{
    return this->date;
}

double stockClass::getOpen() const{
    return this->open;
}

double stockClass::getHigh() const{
    return this->high;
}

double stockClass::getLow() const{
    return this->low;
}

double stockClass::getClose() const{
    return this->close;
}

long long stockClass::getVolume() const{
    return this->volume;
}

// -------- setters --------
void stockClass::setTicker(const std::string& ticker){
    this->ticker = ticker;
}

void stockClass::setDate(const std::string& date){
    this->date = date;
}

void stockClass::setOpen(double open){
    this->open = open;
}

void stockClass::setHigh(double high){
    this->high = high;
}

void stockClass::setLow(double low){
    this->low = low;
}

void stockClass::setClose(double close){
    this->close = close;
}

void stockClass::setVolume(long long volume){
    this->volume = volume;
}

// -------- print --------
void stockClass::printData() const{
    std::cout << this->ticker << " "
              << this->date   << " "
              << this->open   << " "
              << this->high   << " "
              << this->low    << " "
              << this->close  << " "
              << this->volume
              << std::endl;
}

