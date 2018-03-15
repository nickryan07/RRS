#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {

public:
    Customer(string _name, string phone_num, string email, int customer_num)
        : name{_name}, phone_number{phone_num}, email_address{email},
        customer_number{customer_num} { };


    string get_name() {
        return name;
    }
    
    void save() {
        filebuf f;
        f.open("data.txt", ios::app);
        ostream ost(&f);
        ost << "#Customer" << endl;
        ost << name << endl;
        ost << phone_number << endl;
        ost << email_address << endl;
        ost << customer_number << endl;
        f.close();
    }

private:
    int customer_number;
    string phone_number;
    string email_address;
    string name;
};
