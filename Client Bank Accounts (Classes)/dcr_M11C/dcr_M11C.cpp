#include <iostream>
using namespace std;

class Client
{
public:
	Client();
	Client(double _checkings, double _savings);
	void showData();
private:
	double checkings, savings;
};

class Bank
{
public:
	Bank();
	~Bank();
	void addClient(Client newClient);
	void showData();
private:
	int numClients;
	Client* arrClients;
};

int main()
{
	Client c1(2010.71, 9876.33);
	Client c2(13.71, 0.00);
	Client c3(500.00, 600.00);
	Client c4(9622.00, 20000.00);

	Bank b1;

	b1.addClient(c1);
	cout << " After adding client 1: " << endl;
	b1.showData();

	b1.addClient(c2);
	cout << " After adding client 2: " << endl;
	b1.showData();

	b1.addClient(c3);
	cout << " After adding client 3: " << endl;
	b1.showData();

	b1.addClient(c4);
	cout << " After adding client 4: " << endl;
	b1.showData();


}

Client::Client()
	:checkings(0.00), savings(0.00)
{}

Client::Client(double _checkings, double _savings)
	: checkings(_checkings), savings(_savings)
{}

void Client::showData() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << " Checking Balance: " << checkings << endl;
	cout << " Savings Balance: " << savings << endl << endl;
}

Bank::Bank()
	:numClients(0)
{
	arrClients = new Client[1];
}

Bank::~Bank()
{
	delete[] arrClients, arrClients = nullptr;
}

void Bank::addClient(Client newClient) {
	Client* temp = new Client[numClients];
	for (int i = 0; i < numClients; i++) {
		temp[i] = arrClients[i];
	}
	delete[] arrClients;

	arrClients = new Client[numClients + 1];

	for (int i = 0; i < numClients; i++) {
		arrClients[i] = temp[i];
	}
	arrClients[numClients] = newClient;
	numClients++;
	delete[] temp;
}

void Bank::showData() {
	for (int i = 0; i < numClients; i++) {
		cout << " Client " << i + 1 << ':' << endl;
		arrClients[i].showData();
	}
}