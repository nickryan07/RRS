#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_associate {

public:
    Sales_associate(string _name, int employee_num)
        : name{_name}, employee_number{employee_num} { };

private:
    int employee_number;
    string name;
};
