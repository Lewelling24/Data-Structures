#include <iostream>
#include "CheckingAccount.h"

using namespace std;


struct Name {
    string firstName;
    string lastName;

    bool operator == (const Name &n2) const{
    if (firstName == n2.firstName && lastName == n2.lastName) return true;
    return false;
    }
};

ostream & operator << (ostream & os, const Name & n)
{
    os << n.firstName << " " << n.lastName;
    return os;
}


int main() {
    CheckingAccount<string> rachelAccount(1001, "Rachel", 500);
    CheckingAccount<string> bobAccount(1002, "Bob", 600);
    rachelAccount.deposit(200);
    bobAccount.deposit(1500);

    //cout << rachelAccount.getBalance() << endl;
    //cout << rachelAccount << endl;
    //cout << (rachelAccount < bobAccount) << endl;

    Name n;
    n.firstName = "Marcus";
    n.lastName = "Smith";
    CheckingAccount<Name> marcusAccount(210,n, 500);
    //cout << marcusAccount << endl;

    n.firstName = "Lindsey"; n.lastName = "Miller";
    CheckingAccount<Name> lindseyAccount(209, n, 20);
    //cout << lindseyAccount << endl;

    n.firstName = "Noah"; n.lastName = "Abrigo";
    CheckingAccount<Name> noahAccount(309, n, 1200);
    //cout << noahAccount << endl;

    n.firstName = "Cole"; n.lastName = "Anderson";
    CheckingAccount<Name> coleAccount(219, n, 1);
    //cout << coleAccount << endl;

    n.firstName = "Murali"; n.lastName = "Mani";
    CheckingAccount<Name> muraliAccount(137, n, 200);
    //cout << muraliAccount << endl;

    //cout << (lindseyAccount < marcusAccount) << endl;

    CheckingAccount<Name> arrAccount[5];
    arrAccount[0] = marcusAccount;
    arrAccount[1] = lindseyAccount;
    arrAccount[2] = noahAccount;
    arrAccount[3] = coleAccount;
    arrAccount[4] = muraliAccount;

    for(int i = 0; i < 5; i++)
    {
        cout << arrAccount[i] << endl;

    }
    cout << endl;
    // Remove an element
    n.firstName = "Noah"; n.lastName = "Abrigo";
    CheckingAccount<Name> removeAccount(309, n, 1200);

    int index = -1;
    for(int i = 0; i < 5; i++)
    {
        if(arrAccount[i] == removeAccount){index = i; break;}
    }
    if (index >= 0)
    {
        for(int i = index; i < 4; i++) {
            arrAccount[i] = arrAccount[i + 1];
        }
    }

    for(int i = 0; i < 4; i++)
    {
        cout << arrAccount[i] << endl;
    }
    return 0;
}
