#include <iostream>
#include<iomanip>
using namespace std;

class Employee
{
private:
	string name;
	double salary;
	
public:
	Employee();
	Employee(string _name, double _salary);
	string getName() const;
	double getSalary()const;
};

class Company
{
private:
	int maxEmployees, currentEmployees;
	Employee* EmployeeP;
public:
	Company(int _maxEmployees);
	~Company();
	void addEmployee(Employee newEmployee);
	double averageSalary() const;
};

int main()
{
	int userChoice = 1;
	Company c1(3);
	
	while (userChoice != 3) {
		cout << " Main Menu" << endl;
		cout << " 1. Add employee" << endl;
		cout << " 2. Print average salary" << endl;
		cout << " 3. Quit" << endl;
		cout << " Choose an option: ";
		cin >> userChoice;

		if (userChoice == 3) {
			cout << " Thank you for using this program. Goodbye!";
			break;
		}

		else if (userChoice == 1) {
			string tempName;
			double tempSalary;
			cout << " Enter employee name and salary, separated by a space: ";
			cin >> tempName >> tempSalary;
			Employee tempEmp(tempName, tempSalary);
			c1.addEmployee(tempEmp);
			cout << endl;
		}

		else if (userChoice == 2) {
			cout << fixed << setprecision(2) << " Average salary: " << c1.averageSalary();
			cout << endl << endl;
		}
	}
	return 0;
}

Employee::Employee()
	:name("unnamed"), salary(0.0) {}

Employee::Employee(string _name, double _salary)
	: name(_name), salary(_salary) {}

string Employee::getName()const {
	return name;
}

double Employee::getSalary()const {
	return salary;
}

Company::Company(int _maxEmployees)
	:maxEmployees(_maxEmployees),currentEmployees(0)
{
	cout << " Number of employees in the company: " << maxEmployees << endl;
	EmployeeP = new Employee [maxEmployees];
}

Company::~Company()
{
	delete[] EmployeeP;
}

void Company::addEmployee(Employee newEmployee) {
	
	EmployeeP[currentEmployees] = newEmployee;
	currentEmployees++;
}

double Company::averageSalary() const {
	double sum = 0;

	for (int i = 0; i < currentEmployees; i++) {
		sum += EmployeeP[i].getSalary();
	}

	return sum / currentEmployees;
}