#include <fstream>
#include <sstream>
#include "EmployeeList.h"

int EmployeeList::countE = 0;

void EmployeeList::readFromFile(const string& fileName){
    countE = 0;
    ifstream inFile(fileName, ios::in);
        if(inFile.is_open()){
            string line;
            while(getline(inFile,line)){
                istringstream text(line);
                Employee e;
                string res;
                getline(text, e.employeeID,',');
                getline(text , e.name,',');
                getline(text, e.position , ',');
                getline(text, e.shifts, ',');
                getline(text,  res, ',');
                e.salary = stoll(res);
                listE[countE++] = e;
            }
            inFile.close();
        }else{
            cerr << "Khong the mo tep!!! " << endl;
    }
}

void EmployeeList::addEmployee(){
    Employee newE;
    newE.inputInfo();
    ofstream outFile("Employeelist.txt", ios::app);
    if(outFile.is_open()){
        if(Employee::isIDValid(newE.employeeID)){
        outFile << newE.employeeID <<","<< newE.name <<","
                << newE.position <<","<< newE.shifts <<","
                << newE.salary << endl;
                cout << "Da them nhan vien moi!!! " << endl;
        outFile.close();
        }else{
            cout << "ID da ton tai...." << endl;
        }
    }else{
        cerr << "Khong The Mo Tep!!! " << endl;
    }
}

void EmployeeList::deleteEmployee(){
    string ID;
    bool res = true;
    cout << "Nhap ID nhan vien can xoa: " ; cin >> ID;
    readFromFile("Employeelist.txt");
        for(int i = 0; i < countE ; i++ ){
            if (ID == listE[i].employeeID){
                for(int j = i;j < countE ; j++){
                    listE[j] = listE[j+1];
                }
                res = false;
                countE--;
                break;
            }
        }
        if(res){
            cout << "Khong tim thay nhan vien co ID; " << ID << endl;
            return;
        }
        ofstream outFile("EmployeeList.txt",ios::trunc);
        if(outFile.is_open()){
            for(int i = 0 ; i < countE ; i++){
                outFile << listE[i].employeeID <<","<< listE[i].name <<","
                << listE[i].position <<","<< listE[i].shifts <<","
                << listE[i].salary << endl;
            }
            outFile.close();
        }else{
            cerr << "Khong the mo tep!!" << endl;
        }
}

bool EmployeeList::fileIsEmpty(const string& fileName){
    ifstream inFile(fileName , ios::app);
    if(inFile.is_open()){
        inFile.seekg(0 ,ios::end);
        return inFile.tellg() == 0;
    }
    return false;
}

void EmployeeList::showlist(){
    if(fileIsEmpty("Employeelist.txt")){
        cout << "Chua co nhan vien nao duoc them!!!" << endl;
    }else{
        readFromFile("Employeelist.txt");
        for(int i= 0; i < countE ; i++){
            listE[i].showInfo();
        }
    }
}

