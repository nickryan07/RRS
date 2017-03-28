#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Robot_parts {

protected:
    string name;
    int model_num;
    string image_path;
    string description;
    double cost;

};

class Head : public Robot_parts {

private:
    double power;
};

int main() {
    return 0;
}
