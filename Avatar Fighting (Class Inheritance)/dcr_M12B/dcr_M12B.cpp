#include <iostream>
using namespace std;

class Avatar
{
public:
	Avatar(string _name, int _XP, int _HP);
	void print()const;
	void damage(int _damage);
	string getName() const;
private:
	string name;
	int XP, HP;

};

class Fighter :public Avatar
{
public:
	Fighter(string _name, int _XP, int _HP, int _attackPower);
	void attack(Avatar& target);
	void print() const;
private:
	int attackPower;
};

int main()
{
	cout << " Displaying Original Objacts" << endl;

	Avatar G("George", 30, 50);
	G.print();
	Fighter B("Billy", 24, 70,10);
	B.print();

	cout << endl;

	cout << " Test attack() function" << endl;
	B.attack(G);
	G.print();
	cout << endl;
	
	cout << " Test attack() function" << endl;
	B.attack(B);
	B.print();

	return 0;
}


Avatar::Avatar(string _name, int _XP, int _HP)
	: name(_name), XP(_XP), HP(_HP) {}

void Avatar::print()const {
	cout << ' ' << name << " is level " << XP << " with " << HP << " HP" << endl;
}

void Avatar::damage(int _damage) {
	HP -= _damage;
}

string Avatar::getName() const {
	return name;
}

Fighter::Fighter(string _name, int _XP, int _HP, int _attackPower)
	:Avatar(_name, _XP, _HP), attackPower(_attackPower) {}

void Fighter::attack(Avatar& target) {
	target.damage(attackPower);

	cout << ' ' << getName() << " attacks " << target.getName() << " and deals " << attackPower << " damage!" << endl;
	cout << " Result of attack:" << endl;
}

void Fighter::print()const {
	Avatar::print();
	cout << ' ' << getName() << " has an attack power of " << attackPower << endl;
}
