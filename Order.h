#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Order {

public:
    Order(int order_num, int _status, string _date,
            Customer _customer, Sales_associate associate, Robot_models model)
        : name{_name}, phone_number{phone_num}, email_address{email},
        customer_number{customer_num} { };

    double robot_cost() {
        //TODO
    }

    double extended_price() {
        //TODO
    }

private:
    int status;
    int order_number;
    string date;
    Customer customer;
    Sales_associate sales_associate;
    Robot_models robot_models;
};
