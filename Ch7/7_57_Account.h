#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <string>
#include <iostream>

class Account
{
public:
	Account() = default;
	Account(double n) : amount(n) { }
	Account(const std::string& s) : owner(s) { }
	Account(const std::string &s, double amt) :
		owner(s), amount(amt) { }

	std::istream& initamount(std::istream&, Account&);
	double balance() { return amount; }
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);

private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate(){ return .0225; }
};

std::istream& Account::initamount(std::istream& is, Account& a)
{
	is >> a.amount;
	return is;
}

double Account::interestRate = initRate();

void Account::rate(double newRate)
{
	interestRate = newRate;
}
#endif //_ACOUNT_H