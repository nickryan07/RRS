#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Order {

public:
    Order(int order_num, int _status, string _date,
            Customer _customer, Sales_associate associate, Robot_models model)
        : order_number{order_num}, status{_status}, date{_date},
        customer{_customer}, sales_associate{associate}, robot_model{model} { };

    double robot_cost() {
        //TODO
    }

    double extended_price() {
        //TODO
    }

    int get_number() {
        return order_number;
    }

    int get_status() {
        return status;
    }

    string get_date() {
        return date;
    }

    string get_name() {
        return customer.get_name();
    }

private:
    int status;
    int order_number;
    string date;
    Customer customer;
    Sales_associate sales_associate;
    Robot_models robot_model;
};
