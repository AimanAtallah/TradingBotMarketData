#ifndef STOCKCLASS_H
#define STOCKCLASS_H


#include <string>


using namespace std;

class stockClass{
    public:
        stockClass();
        stockClass(double price,double movement,string name,string ticker);
        const string& getName() const;
        void setName(const string& name);
        const string& getTicker() const;
        void setTicker(const string& ticker);
        double getPrice() const;
        void setPrice(double price);
        double getMovement() const;
        void setMovement(double movement);
    private:
        double price;
        double movement;
        string name;
        string ticker;
};



#endif // !STOCKCLASS_H
