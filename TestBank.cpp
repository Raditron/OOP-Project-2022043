#include <iostream>
#include <map>
#include <string>
#include <memory> // For shared_ptr
#include "CheckingAccount.cpp"

using namespace std;

class TestBank
{

public:
  static void runTests()
  {
    int accNum;
    string accHolder;
    double accBalance;

    try
    {
      // Initialize 2 persons information
      // First person information
      cout << "Enter first person's name  ";
      cin >> accHolder;

      cout << "Enter " << accHolder << "'s account number ";
      cin >> accNum;
      cout << "Enter " << accHolder << "'s account balance ";
      cin >> accBalance;

      Account firstPersonAccount = Account(accNum, accHolder, accBalance);

      cout << "Enter " << accHolder << "'s checking account number ";
      cin >> accNum;
      cout << "Enter " << accHolder << "'s checking account balance ";
      cin >> accBalance;

      CheckingAccount firstPersonCheckingAccount = CheckingAccount(accNum, accHolder, accBalance);
      cout << endl;

      // Second person information
      cout << "Enter second person's name  ";
      cin >> accHolder;

      cout << "Enter " << accHolder << "'s account number ";
      cin >> accNum;
      cout << "Enter " << accHolder << "'s account balance ";
      cin >> accBalance;

      Account secondPersonAccount = Account(accNum, accHolder, accBalance);

      cout << "Enter " << accHolder << "'s checking account number ";
      cin >> accNum;
      cout << "Enter " << accHolder << "'s checking account balance ";
      cin >> accBalance;

      CheckingAccount secondPersonCheckingAccount = CheckingAccount(accNum, accHolder, accBalance);
      cout << endl;

      // Print information for each person
      firstPersonAccount.printAccountInfo();
      firstPersonCheckingAccount.printAccountInfo();
      secondPersonAccount.printAccountInfo();
      secondPersonCheckingAccount.printAccountInfo();
      cout << "********** Starting bank operations..." << endl;

      // Withdraw 350 from each checking account and deposit it to account
      firstPersonAccount.deposit(firstPersonCheckingAccount.withdraw(350));
      secondPersonAccount.deposit(secondPersonCheckingAccount.withdraw(350));
      cout << "********** Finishing bank operations..." << endl;

      // Print information for each person
      firstPersonAccount.printAccountInfo();
      firstPersonCheckingAccount.printAccountInfo();
      secondPersonAccount.printAccountInfo();
      secondPersonCheckingAccount.printAccountInfo();
    }
    catch (const exception &e)
    {
      cout << "Wrong Input Type! ";
    }
  }
};
