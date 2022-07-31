#include <iostream>
using namespace std;

class Item
{
protected:
	string name;
	double price;
	int quantity;
public:
	Item();
	Item(string _name, double _price, int _quantity);
	virtual void printInfo() const = 0;
};

class Food :public Item
{
private:
	int calories;
public:
	Food();
	Food(string _name, double _price, int _quantity,int _calories);
	void printInfo() const override;
};

class Perishable :public Food
{
private:
	int expTime;
public:
	Perishable();
	Perishable(string _name, double _price, int _quantity, int _calories, int _expTime);
	void printInfo() const override;
};

int main()
{
	Item* itemP;

	cout << " Using an Item pointer..." << endl;
	itemP = new Food("Beans", 3.99, 12, 70);
	itemP->printInfo();
	cout << endl;

	itemP = new Perishable("Bread", 2.99, 9, 130, 12);
	itemP->printInfo();
	cout << endl;

	Food* foodP;

	cout << " Using a Food pointer..." << endl;
	foodP = new Food("Chips", 1.99, 24, 220);
	foodP->printInfo();
	cout << endl;

	foodP = new Perishable("Apple", 2.49, 12, 90, 9);
	foodP->printInfo();

	return 0;
}

Item::Item()
	:name(" "), price(0.00),quantity(0){}

Item::Item(string _name, double _price, int _quantity)
	: name(_name), price(_price), quantity(_quantity){}



Food::Food()
	:calories(0) {}

Food::Food(string _name, double _price, int _quantity, int _calories)
	:Item(_name,_price,_quantity),calories(_calories) {}

void Food::printInfo() const {
	cout << " Name: " << name << endl;
	cout << " Price: $" << price << endl;
	cout << " Quantity: " << quantity << endl;
	cout << " Calories: " << calories << endl;
}

Perishable::Perishable()
	:expTime(0){}

Perishable::Perishable(string _name, double _price, int _quantity, int _calories, int _expTime)
	: Food(_name,_price,_quantity,_calories), expTime(_expTime){}

void Perishable::printInfo() const{
	Food::printInfo();
	cout << " Expires in " << expTime << " days" << endl;
}