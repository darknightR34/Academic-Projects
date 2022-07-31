#include <iostream>
using namespace std;

class System
{
public:
	System();
	System(int _CLKfreq, int _driveSize, double _transisNum);
	int getCLKfreq() const, getdriveSize() const, gettransisNum() const;
	void setCLKfreq(int _CLKfreq), setdriveSize(int _driveSize), settransisNum(double _transisNum);
	void GetInfo() const;
	static int GetNetworkSize();
private:
	int CLKfreq, driveSize;
	double transisNum;
	static int networkSize;
};

int System::networkSize = 0;

int main()
{
	System pc1;
	cout << " Created a default System object" << endl;
	pc1.GetInfo();

	System pc2((14 * pow(10, 8)), 250, 3e9);
	cout << " Created a custom System object" << endl;
	pc2.GetInfo();
	pc2.setdriveSize(1000);
	cout << " After upgrading the second System" << endl;
	pc2.GetInfo();


	return 0;
}

System::System()
	:CLKfreq(2 * pow(10, 9)), driveSize(500), transisNum(1e10)
{
	networkSize++;
}
System::System(int _CLKfreq, int _driveSize, double _transisNum)
	: CLKfreq(_CLKfreq), driveSize(_driveSize), transisNum(_transisNum)
{
	networkSize++;
}

int System::getCLKfreq() const {
	return CLKfreq;
}
int System::getdriveSize() const {
	return driveSize;
}
int System::gettransisNum() const {
	return transisNum;
}

void System::setCLKfreq(int _CLKfreq) {
	CLKfreq = _CLKfreq;
}
void System::setdriveSize(int _driveSize) {
	driveSize = _driveSize;
}
void System::settransisNum(double _transisNum) {
	transisNum = _transisNum;
}

void System::GetInfo() const {
	cout << " System CLK: " << CLKfreq << " Hz" << endl;
	cout << " Hard Drive Size: " << driveSize << " GB" << endl;
	cout << " Transistor Count: " << transisNum << endl;
	cout << " Network Size: " << GetNetworkSize() << endl << endl;
}

int System::GetNetworkSize() {
	return networkSize;
}