#ifndef STOCK_H
#define STOCK_H

#include <Wt/Dbo/Dbo>

#include <string>

class Stock
{
public:
    Stock();

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, stockCode, "stockcode");
        Wt::Dbo::field(a, lastSalePrice, "lastsaleprice");
    }

    std::string stockCode;
    double lastSalePrice;
};

#endif // STOCK_H
