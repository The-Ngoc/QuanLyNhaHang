#include <iostream>
#include "Employeelist.h"

using namespace std;

void func(){
    cout << "Chon cac chuc nang sau : (0 -> 6)" << endl;
    cout << "---------------------------------" << endl;
    cout << "1. Danh sach thuc don. " << endl;
    cout << "2. Quan ly nhan vien. " << endl;
    cout << "3. Quan Ly ban. " << endl;
    cout << "4. Quan ly khach hang. " << endl;
    cout << "5. Tao hoa don. " << endl;
    cout << "0. Thoat " << endl;
}

void funcEmployee(){
    cout << "Cac chuc nang quan ly nhan vien: " << endl;
    cout << "---------------------------------" << endl;
    cout << "1. Them nhan vien moi." << endl;
    cout << "2. Xoa nhan vien. " << endl;
    cout << "3. Hien thi danh sach nhan vien. " << endl;
    cout << "0. Quay lai trang truoc. " << endl;
}

int main(){
    EmployeeList listE;
    int res;
    do{
        func();
        cout << "Nhap chuc nang: " ; cin >> res;
        switch (res)
        {
        case 1:
            break;
        case 2:
        int res2;
        do{
            funcEmployee();
            cout << "Nhap chuc nang: "; cin >> res2;
            switch (res2)
            {
            case 1:
                listE.addEmployee();
                break;
            case 2:
                listE.deleteEmployee();
                break;
            case 3:
                listE.showlist();
                break;
            case 0:
                cout << "Dang quay lai trang truoc... " << endl;
                break;
            default:
            cout << "Chuc nang khong hop le!!! Hay nhap lai...." << endl;
                break;
            }
        }while(res2 !=0 );
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;    
        case 0:
            cout << "Da thoat..." << endl;
            break;
        default:
            cout << "Chuc nang khong lop le . Nhap lai !!! " << endl; 
            break;
        }
    }while (res != 0);
}