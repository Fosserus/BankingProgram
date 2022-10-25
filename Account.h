#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>
#include <cstdlib>
#include <ctime>

class Account
{
public:
    std::string name;
    int accountNumber;
    double balance;
    bool isDefault; // flag for managing if user has account or not
    std::string getName() {return name;}
    void setName(std::string n) {name = n;}
    int getAccountNum(){return accountNumber;}
    void setAccountNum(int n){accountNumber = n;}
    double getBalance(){return balance;}
    void setBalance(double bal){balance = bal;}
    void setDefaultFlag(bool flag){isDefault = flag;}
    bool getDefaultFlag() {return isDefault;}
    int generateAccountNum();
    Account() {
        name = "John Doe";
        accountNumber = 12345;
        balance = 0.00;
        isDefault = true; // constructor sets flag to true, later being set to false on user account creation
        }
};

#endif // _ACCOUNT_H_
