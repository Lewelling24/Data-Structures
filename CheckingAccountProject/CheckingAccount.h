#ifndef CHECKINGACCOUNT_H_INCLUDED
#define CHECKINGACCOUNT_H_INCLUDED

#include <string.h>
#include <iostream>

using namespace std;


template <class T>
class CheckingAccount {
private:
	int accountNumber;
	T accountOwnerName;
	float balance = 0.0;
	string socialSecurityNumber;
	float lastChecks[5];
	int howManyChecks;
	int lastIndex;

public:
    CheckingAccount();
	void deposit(float amtDeposit); // { balance += amtDeposit;	}
	bool withdraw(float amtWithdraw);
	bool writeCheck(float amtWithdraw);
	float getBalance() const { return balance; }
    CheckingAccount(int acNum, T owner, float initBalance);
    int getAccountNumber() const {return accountNumber;}
    T getAccountOwner () const {return accountOwnerName;}
    bool operator < (const CheckingAccount<T> & acct2) const
    {
        return balance < acct2.balance;
    }
    bool operator == (const CheckingAccount<T> & acct2) const {
        if(accountNumber == acct2.accountNumber && accountOwnerName == acct2.accountOwnerName) return true;
        return false;
    }
};


template<class T>
CheckingAccount<T>::CheckingAccount()
{

}
template <class T>
void CheckingAccount<T>::deposit (float amtDeposit) {
	balance += amtDeposit;
}

template <class T>
bool CheckingAccount<T>::withdraw(float amtWithdraw) {
    if (balance < amtWithdraw) return false;
    balance -= amtWithdraw;
    return true;
}

template <class T>
ostream & operator << (ostream &os, const CheckingAccount<T> & acct)
{
    os << "Account Number " << acct.getAccountNumber() << " : " << acct.getAccountOwner() << " with initial balance of :" << acct.getBalance()<< endl;
    os << "\nLast 5 (or fewer)checks: ";
    int currentIndex = acct.lastIndex;
    for(int i = 0; i < acct.howManyChecks; i++){
        os << acct.lastChecks[currentIndex] << ", ";
        currentIndex--;
        if(currentIndex == -1) currentIndex = 4;
    }
    return os;
}

/*bool operator < (const CheckingAccount& acct1, const CheckingAccount& acct2)
{
    return acct1.getBalance() < acct2.getBalance();
}*/

template<class T>
CheckingAccount<T>::CheckingAccount(int acNum, T owner, float initBalance): accountNumber(acNum),balance(initBalance), accountOwnerName(owner),howManyChecks(0),lastIndex(-1){
	    /*accountNumber = acNum;
	    accountOwnerName = owner;
	    balance = initBalance;*/
	}

template <class T>
bool CheckingAccount<T>::writeCheck(float amtCheck) {
    if (balance < amtCheck) return false;
    balance -= amtCheck;
    lastIndex++;
    if(lastIndex == 5) lastIndex = 0;
    lastChecks[lastIndex] = amtCheck;
    return true;
}

#endif // CHECKINGACCOUNT_H_INCLUDED
