#include "ClientData.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

void outputLine(ostream&, const ClientData&);

int main() {
	fstream file("client_data.dat", ios::in | ios::out | ios::binary);

	if (!file) {
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	int idx = 0;
	cin >> idx;

	file.seekg(idx * sizeof(ClientData), ios::beg);
	ClientData client;

	if (!file.read(reinterpret_cast<char*>(&client), sizeof(ClientData))) {
		cerr << "out of index" << endl;
		exit(EXIT_FAILURE);
	}

	cout << left << setw(10) << "Account" << setw(16) << "Last Name"
		<< setw(11) << "First Name" << left << setw(10) << right
		<< "Balance" << endl;

	if (client.getAccountNumber() != 0) {
		outputLine(cout, client);
		client.setBalance(client.getBalance() * 2);

		file.seekp(idx * sizeof(ClientData), ios::beg);
		file.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));
		file.flush();
	}

	return 0;
}

void outputLine(ostream& output, const ClientData& record)
{
	output << left << setw(10) << record.getAccountNumber()
		<< setw(16) << record.getLastName()
		<< setw(11) << record.getFirstName()
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << record.getBalance() << endl;
}