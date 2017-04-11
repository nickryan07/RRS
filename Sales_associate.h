#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_associate {

public:
    Sales_associate(string _name, int employee_num)
        : name{_name}, employee_number{employee_num} { };

    int get_employee_number() {
        return employee_number;
    }

    string get_name() {
        return name;
    }

    void save() {
        filebuf f;
        f.open("data.txt", ios::app);
        ostream ost(&f);
        ost << "#Associate" << endl;
        ost << name << endl;
        ost << employee_number << endl;
        f.close();
    }
private:
    int employee_number;
    string name;
};
