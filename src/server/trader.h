#ifndef TRADER_H
#define TRADER_H

#include <Wt/Dbo/Dbo>

#include <string>

class Trader
{
public:
    Trader();

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, userName, "username");
        Wt::Dbo::field(a, password, "password");
        Wt::Dbo::field(a, balanceCache, "balancecache");
    }

    std::string userName;
    std::string password;
    double balanceCache;
};

#endif // TRADER_H
