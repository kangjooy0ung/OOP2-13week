#pragma once
#include <string>

using namespace std;

class ClientData{
public:
	int accountNumber;
	char lastName[15];
	char firstName[10];
	double balance;

public:
	ClientData(int = 0, const string & ="", const string & ="", double = 0.0);

	void setAccountNumber(int accountNumberValue);
	int getAccountNumber() const;

	void setLastName(const string& lastNameString);
	string getLastName() const;

	void setFirstName(const string& firstnameString);
	string getFirstName() const;

	void setBalance(double balanceValue);
	double getBalance()const;
};