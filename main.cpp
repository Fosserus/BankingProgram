#include "Account.h"
#include <iostream>

// initial user account 
Account *user = new Account();

   void welcomeScreen() {
       std::cout << "==========================" << std::endl;
       std::cout << "  Welcome to Kawa Bank!!  " << std::endl;
       std::cout << "==========================" << std::endl;
       } 

   void showMenu() {
       std::cout << "\nChoose an option: " << std::endl;
       std::cout << "\n[C]reate an account " << std::endl;
       std::cout << "[D]eposit funds" << std::endl;
       std::cout << "[W]ithdraw funds " << std::endl;
       std::cout << "[B]alance inquiry " << std::endl;
       std::cout << "[A]ccount info " << std::endl;
       std::cout << "[Q]uit " << std::endl;
       }
       
   void createAccount(Account *created) {
       std::string userName;
       system("CLS");
       std::cout << "Enter your name: ";
       std::getline(std::cin, userName);
       created->setName(userName);
       created->setAccountNum(created->generateAccountNum());
       created->setDefaultFlag(false); // setting flag for account info and balance inq
       std::cout << "\nYour account has been created!" << std::endl;
       std::cout << "Your account number is " << created->getAccountNum() << std::endl;
       std::cout << std::endl;
       system("PAUSE");
       }
       
   void depositFunds() {
       system("CLS");
       if (user->getDefaultFlag() == true) { // don't allow if user doesnt have account
           std::cout << "You need an account to do that." << std::endl;
           std::cout << std::endl;
            system("PAUSE");
           } else {
                double amount;
                double currentBalance {user->getBalance()};
                std::cout << "Amount to deposit (exclude commas): ";
                std::cin >> amount;
                if (amount < 1) {
                    std::cout << "Invalid amount." << std::endl;
                    std::cout << std::endl;
                     system("PAUSE");
                    } else {
                        user->setBalance(currentBalance += amount);
                        std::cout << "Your new balance is now $" << user->getBalance() << std::endl;
                        std::cout << std::endl;
                         system("PAUSE");
                    }
                }
       }
       
   void withdrawFunds() {
       system("CLS");
       if (user->getDefaultFlag() == true) { 
           std::cout << "You need an account to do that." << std::endl;
           std::cout << std::endl;
           system("PAUSE");
           } else {
               double amount;
               double currentBalance {user->getBalance()};
               std::cout << "Amount to withdraw (exclude commas): ";
               std::cin >> amount;
               if ((currentBalance - amount) < 0) {
                    std::cout << "Insufficient funds." << std::endl;
                    std::cout << std::endl;
                    system("PAUSE");
                } else if (amount < 0) {
                    std::cout << "Invalid value." << std::endl;
                    std::cout << std::endl;
                     system("PAUSE");
               } else {
                    user->setBalance(currentBalance -= amount);
                    std::cout << "Your new balance is now $" << user->getBalance() << std::endl;
                    std::cout << std::endl;
                     system("PAUSE");
                    }  
               }
       }
       
   void showBalance() {
           system("CLS");
            if (user->getDefaultFlag() == true) {
           std::cout << "You need an account to do that." << std::endl;
           std::cout << std::endl;
           system("PAUSE");
           } else {
              std::cout << "Your current balance is: $" << user->getBalance() << std::endl; 
              std::cout << std::endl;
               system("PAUSE");
              }
           }
           
   void showAccountInfo() {
            system("CLS");
            if (user->getDefaultFlag() == true) {
           std::cout << "You need an account to do that." << std::endl;
           std::cout << std::endl;
            system("PAUSE");
           } else {
               std::cout << "Name on account: " << user->getName();
               std::cout << "\nAccount number: " << user->getAccountNum();
               std::cout << "\nCurrent balance: $" << user->getBalance();
               std::cout << std::endl;
               system("PAUSE");
               }
           }
   
   int main(){
   
    char userChoice {' '};
    welcomeScreen();
    std::cout << std::endl;
    system("PAUSE");
    
   // main loop 
   while(true) {
        system("CLS");
        showMenu();
        std::cin >> userChoice;
        std::cin.ignore(); // fix to avoid skipping over input 
            switch(tolower(userChoice)) {
                case 'c':
                    createAccount(user);
                    break;
                case 'd':
                    depositFunds();
                    break;
                case 'w':
                    withdrawFunds();
                    break;
                case 'b':
                    showBalance();
                    break;
                case 'a':
                    showAccountInfo();
                    break;
                case 'q':
                    system("CLS");
                    std::cout << "Thank you for choosing Kawa Bank! \nHave a great day!" << std::endl;
                    std::cout << std::endl;
                   system("PAUSE");
                    return 0;
                default:
                    system("CLS");
                    std::cout << "Invalid choice, please try again." << std::endl;
                    std::cout << std::endl;
                    system("PAUSE");
                }
   }

    delete user; // good ol c++ memory management i suppose ???? (hope this is right)
    return 0;
    }