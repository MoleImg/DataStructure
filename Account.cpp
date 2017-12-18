//Account.cpp
//C7-1 Declaration and implementation of the Account class
#include <iostream>
#include <string>
using namespace std;


class Account{
private:
	string userName;
public:
	Account();
	Account(string name);
	~Account();
	void printUserName();

};

class CreditAccount : public Account{
private:
	int credit;
public:
	CreditAccount(string userName, int credit);
	// ~CreditAccount();
	void PrintInfo();
};

//Implementation
Account::Account(string name):userName(name){cout<<userName<<" account constructed."<<endl;}
Account::~Account(){cout<<userName<<" account destructed."<<endl;}
void Account::printUserName(){
	cout<<userName<<endl;
}

CreditAccount::CreditAccount(string userName, int credit):
Account(userName),credit(credit){
	cout<<userName<<" credit account constructed."<<endl;
}
CreditAccount::~CreditAccount(){cout<<"credit account destructed."<<endl;}
void CreditAccount::PrintInfo(){
	Account::printUserName();
}

int main(int argc, char const *argv[])
{
	CreditAccount a("I Love CPP", 10000);
	a.PrintInfo();
	return 0;
}
