#include "ClientData.h"
#include <iostream>
#include <string>
using namespace std;

ClientData::ClientData(int accountNumberValue, const string& lastName, const string& firstName, double balanceValue) : accountNumber(accountNumberValue), balance(balanceValue) {
	setLastName(lastName);
	setFirstName(firstName);
}

int ClientData::getAccountNumber() const {
	return accountNumber;
}


void ClientData::setAccountNumber(int accountNumberValue) {
	accountNumber = accountNumberValue;
}

string ClientData::getLastName() const {
	return lastName;
}

void ClientData::setLastName(const string& lastNameString) {
	int length = lastNameString.size();
	if (length < 15)
		length = length;
	else
		length = 14;
	lastNameString.copy(lastName, length);
	lastName[length] = '\0';
}

string ClientData::getFirstName() const{
	return firstName;
}

void ClientData::setFirstName(const string& firstNameString) {
	int length = firstNameString.size();
	if (length < 10)
		length = length;
	else
		length = 9;
	firstNameString.copy(firstName, length);
	firstName[length] = '\0';
}

double ClientData::getBalance() const {
	return balance;
}

void ClientData::setBalance(double balanceValue) {
	balance = balanceValue;
}
