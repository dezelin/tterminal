#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <Wt/Dbo/Dbo>

#include <string>

class Portfolio
{
public:
    Portfolio();

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, userName, "username");
        Wt::Dbo::field(a, stockCode, "stockcode");
        Wt::Dbo::field(a, quantity, "quantity");
        Wt::Dbo::field(a, totalCost, "totalcost");
    }

    std::string userName;
    std::string stockCode;
    unsigned int quantity;
    double totalCost;
};

#endif // PORTFOLIO_H
