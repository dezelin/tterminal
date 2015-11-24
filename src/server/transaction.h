#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <Wt/Dbo/Dbo>
#include <Wt/WDateTime>

#include <string>

class Transaction
{
public:
    Transaction();

    enum Status {
        EXECUTED = 0,
        PENDING
    };

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, userName, "username");
        Wt::Dbo::field(a, stockCode, "stockcode");
        Wt::Dbo::field(a, quantity, "quantity");
        Wt::Dbo::field(a, dateTime, "datetime");
        Wt::Dbo::field(a, status, "status");
    }

    std::string userName;
    std::string stockCode;
    double quantity;
    Wt::WDateTime dateTime;
    Status status;
};

#endif // TRANSACTION_H
