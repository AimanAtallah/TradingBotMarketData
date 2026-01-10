#ifndef STOCKCLASS_H
#define STOCKCLASS_H

#include <string>


class stockClass {
public:
    stockClass();
    stockClass(const std::string& ticker,
               const std::string& date,
               double open,
               double high,
               double low,
               double close,
               long long volume);

    // setters
    void setTicker(const std::string& ticker);
    void setDate(const std::string& date);
    void setOpen(double open);
    void setHigh(double high);
    void setLow(double low);
    void setClose(double close);
    void setVolume(long long volume);

    // getters
    const std::string& getTicker() const;
    const std::string& getDate() const;
    double getOpen() const;
    double getHigh() const;
    double getLow() const;
    double getClose() const;
    long long getVolume() const;

    void printData() const;

private:
    std::string ticker;
    std::string date;
    double open{};
    double high{};
    double low{};
    double close{};
    long long volume{};
};


#endif // STOCKCLASS_H
