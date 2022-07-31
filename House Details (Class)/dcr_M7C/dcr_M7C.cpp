#include <iostream>

using namespace std;

class House
{
public:

	int getPrice(), getBedNum(), getBathNum(), getStorNum();
	void setPrice(int _price), setBedNum(int _bedNum);
	void setBathNum(int _bathNum), setStorNum(int _storNum);
	void display();
private:

	int price, bedNum, bathNum, storNum;
};

void printHouseArray(House array[], int size);
int averageHousePrice(House array[], int size);

int main()
{
	int house_1[5] = { 150000,1,1,1 };
	int house_2[5] = { 300000,3,2,1 };
	int house_3[5] = { 450000,5,3,2 };

	House houseArray[3];

	houseArray[0].setPrice(house_1[0]);
	houseArray[0].setBedNum(house_1[1]);
	houseArray[0].setBathNum(house_1[2]);
	houseArray[0].setStorNum(house_1[3]);

	houseArray[1].setPrice(house_2[0]);
	houseArray[1].setBedNum(house_2[1]);
	houseArray[1].setBathNum(house_2[2]);
	houseArray[1].setStorNum(house_2[3]);

	houseArray[2].setPrice(house_3[0]);
	houseArray[2].setBedNum(house_3[1]);
	houseArray[2].setBathNum(house_3[2]);
	houseArray[2].setStorNum(house_3[3]);

	printHouseArray(houseArray, 3);
	cout << "The average house price is $" << averageHousePrice(houseArray, 3);
	cout << endl;
}

void printHouseArray(House array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << " House " << i + 1 << endl;
		array[i].display();
		cout << endl;
	}
}
int averageHousePrice(House array[], int size) {
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += array[i].getPrice();
	}
	return sum / 3;
}

int House::getPrice() {
	return price;
}
int House::getBedNum() {
	return bedNum;
}
int House::getBathNum() {
	return bathNum;
}
int House::getStorNum() {
	return storNum;
}

void House::setPrice(int _price) {
	price = _price;
}
void House::setBedNum(int _bedNum) {
	bedNum = _bedNum;
}
void House::setBathNum(int _bathNum) {
	bathNum = _bathNum;
}
void House::setStorNum(int _storNum) {
	storNum = _storNum;
}

void House::display() {
	cout << " Price: $" << price << endl;
	cout << " Num Bedrooms: " << bedNum << endl;
	cout << " Num Bathrooms: " << bathNum << endl;
	cout << " Num Stories: " << storNum << endl;
}
