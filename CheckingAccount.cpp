#include <iostream>
#include <vector>
#include <string>
#include "Account.cpp"

using namespace std;

class CheckingAccount : public Account
{
private:
  int monthlyTransactions;

public:
  CheckingAccount(int accNum, string accHolder, double balance) : Account(accNum, accHolder, balance)
  {
    this->monthlyTransactions = 0;
  }

  bool deposit(double amount) override
  {
    bool result = Account::deposit(amount);
    if (result)
    {
      monthlyTransactions++;
    }
    return result;
  }

  double withdraw(double amount) override
  {
    double result = Account::withdraw(amount);
    if (result > 0)
    {
      monthlyTransactions++;
    }
    return result;
  }

  int getMonthlyTransactions()
  {
    return this->monthlyTransactions;
  }

  void printAccountInfo() override
  {
    Account::printAccountInfo();
    cout << "Monthly Transactions: " << this->getMonthlyTransactions() << endl;
  }

  ~CheckingAccount() {};
};