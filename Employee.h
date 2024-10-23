#pragma once
#include <iostream>
#include <string>

using namespace std;
typedef long long int lld;

class Employee                                                             
{
private:
	string employeeID;
	string name;
	string position;
	string shifts;
	lld salary;
public:
	Employee();
	string getEmployeeID();
	string getName();
	string getPosition();
	string getShifts();
	lld getSalary();
	static bool isIDValid(const string&);
	void inputInfo();
	void showInfo();
	friend class EmployeeList;
};

