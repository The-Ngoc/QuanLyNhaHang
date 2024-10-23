#include "Employee.h"


class EmployeeList{
    private:
    Employee listE[50];
    public:
    static int countE;
    void readFromFile(const string&);
    void addEmployee();
    void deleteEmployee();
    void findEmployee();
    bool fileIsEmpty(const string&);
    void showlist();
    friend class Employee;
};