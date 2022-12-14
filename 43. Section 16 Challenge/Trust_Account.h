#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

class Trust_Account: public Savings_Account{
    
    private:
        static constexpr const char *def_name = "Unnamed savings Account";
        static constexpr double def_balance = 0.0;
        static constexpr double def_int_rate = 0.0;
        static constexpr int max_limit = 3;
        static constexpr double withdraw_limit = 0.2;
        static constexpr double bonus = 50.0;
        static constexpr double bonus_threshold = 5000.0;
    protected:
        int num_withdrawals;
    public:
        Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

        virtual bool deposit(double amount) override;
        virtual bool withdraw(double amount) override;
        virtual void print(std::ostream &os) const override;
        virtual ~Trust_Account() = default;
};


#endif // _TRUST_ACCOUNT_H_