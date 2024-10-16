#include <iostream>
#include <vector>
#include <format>
#include <cmath>
using namespace std;

class Account
{
private:
  int accNum;
  string accHolder;
  double balance;

  bool checkBalance(double bal)
  {
    if (bal < 0)
    {
      cout << "Balance cannot be less than 0. Value: " << bal << endl;
      return false;
    }

    return true;
  }
 
 
  bool checkAccount(int accNum)
  {
    int size = trunc(log10(accNum)) + 1;
    if (size == 5)
    {
      return true;
    }
    else
    {
      cout << "Invalid account number. It should consists of 5 digits." << endl;
      return false;
    }
  }

public:
  Account(int accNum, string accHolder, double balance)
  {

    if (this->checkAccount(accNum))
    {
      this->accNum = accNum;
    }
    else
    {
      throw invalid_argument("Invalid account number. It should consists of 5 digits.");
    }

    this->accHolder = accHolder;

    if (this->checkBalance(balance))
    {
      this->balance = balance;
    }
    else
    {
      throw invalid_argument("Invalid balance: Balance cannot be negative.");
    }
  }
 int getAccountNum(){
  return accNum;
}

  virtual bool deposit(double depositAmount)
  {
    if (depositAmount >= 0)
    {
      balance += depositAmount;
      return true;
    }
    else
    {
      cout << "Deposit cannot be less than 0. Value: " << depositAmount << endl;
      return false;
    }
  };

  virtual double withdraw(double withdrawAmount)
  {
    if (balance >= withdrawAmount)
    {
      balance -= withdrawAmount;
      return withdrawAmount;
    }
    else
    {
      cout << "Insufficient Funds" << endl;
      return 0;
    }
  }
  string getHolderName()
  {
    return accHolder;
  }
  double getBalance()
  {
    return balance;
  }

  bool setBalance(double bal)
  {
    if (this->checkBalance(balance))
    {
      this->balance = bal;
      return true;
    }

    return false;
  }

  virtual void printAccountInfo()
  {
    cout << "Holder Name: " << this->accHolder << endl;
    cout << "Account Number: "<< this->accNum << endl;
    cout << "Account Balance: " << this->balance << endl;
  }

  ~Account() {};
};