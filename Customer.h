#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {

public:
    Customer(string _name, string phone_num, string email, int customer_num)
        : name{_name}, phone_number{phone_num}, email_address{email},
        customer_number{customer_num} { };

private:
    int customer_number;
    string phone_number;
    string email_address;
    string name;
};
