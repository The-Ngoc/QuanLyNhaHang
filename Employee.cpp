#include "Employee.h"
#include "EmployeeList.h"


Employee::Employee() {
	employeeID = "00000";
	name = "No name";
	position = "No position";
	shifts = "0h00p - 0h00p";
	salary = 0;
}

string Employee::getEmployeeID() {
	return this->employeeID;
}

string Employee::getName() {
	return this->name;
}

string Employee::getPosition() {
	return this->position;
}

string Employee::getShifts() {
	return this->shifts;
}

lld Employee::getSalary() {
	return this->salary;
}

bool Employee::isIDValid(const string& newID){
	EmployeeList el;
	el.readFromFile("Employeelist.txt");
	for(int i = 0 ; i < el.countE; i++){
		if(el.listE[i].employeeID == newID){
			return false;
		}
	}
	return true;
}

void listPosition(){
	cout << "Vi tri : " << endl;
	cout << "---------" << endl;
	cout << "1. Quan ly. " << endl;
	cout << "2. Le tan.  " << endl;
	cout << "3. Phuc vu. " << endl;
	cout << "4. Giam sat." << endl;
	cout << "5. Thu ngan." << endl;
	cout << "6. Bao ve.  " << endl;
}

void Employee::inputInfo() {
	bool res = true;
	cout << "Nhap thong tin Nhan Vien moi:  " << endl;
	cin.ignore();
	cout << "Nhap ID nhan vien: "; getline(cin, employeeID);
	if(isIDValid(employeeID)){
		cout << "Nhap Ten nhan vien: "; getline(cin, name);
	    cout << "Ca lam: "; getline(cin, shifts);
		int temp;
		do{
			listPosition();
			cout << "Vi tri cho nhan vien moi: " ; cin >> temp;
			switch (temp){
				case 1: 
					position = "Quan ly ";
					break;
				case 2:
					position = "Le tan  ";
					break;
				case 3:
					position = "Phuc vu ";
					break;
				case 4:
					position = "Giam sat";
					break;
				case 5:
				    position = "Thu ngan";
					break;
				case 6:
					position = "Bao ve  ";
					break;
				default:
				cout << "Lua chon khong hop le..." << endl;
				break;
			}
		}while( temp < 1 || temp > 6);
	    cout << "Luong co ban: "; cin >> salary;
	}
}

void Employee::showInfo() {
	cout << employeeID << "  " << name << "    " << "     " << position << "   " << shifts << "   " << salary << endl;
}
