#include <iostream>
#include <string>
#include <vector>

class Robot_parts {

protected:
    string name;
    int model_num;
    string image_path;
    string description
    double cost;

};

class Head : public Robot_parts {

private:
    double power;
};

