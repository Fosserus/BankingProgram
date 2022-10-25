#include "Account.h"

// generates a random 5 digit number to serve as an account number
int Account::generateAccountNum() {
    srand(time(0));
    return 10000 + (rand() % 99999);
    
    }
