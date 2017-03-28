#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Robot_parts {
public:
    Robot_parts(string name, int model_num, string description, double cost)
     : name{name}, model_num{model_num}, description{description}, cost{cost} { };
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

class Arm : public Robot_parts {

private:
    double arm_power;
};

class Torso : public Robot_parts {

public:
    Torso(int _battery_slots, int _num_arms, string name, int model_num, string description, double cost)
    : Robot_parts(name, model_num, description, cost)
    {
        battery_slots = _battery_slots;
        num_arms = _num_arms;
    }

private:
    int battery_slots;
    int num_arms;
};

class Battery : public Robot_parts {

public:
    Battery(double _power_available, double _max_energy, string name, int model_num, string description, double cost)
    : Robot_parts(name, model_num, description, cost)
    {
        power_available = _power_available;
        max_energy = _max_energy;
    }

private:
    double power_available;
    double max_energy;
};

class Motor : public Robot_parts {

public:
    Motor(double _max_power, string name, int model_num, string description, double cost)
    : Robot_parts(name, model_num, description, cost)
    {
        max_power = _max_power;
    }

private:
    double max_power;
};



int main() {
    string type, name, description;
    int part_num;
    double cost;
    cout << "---- Creating a robot part ----" << endl;
    cout << "Enter a part name: ";
    cin >> name;
    cout << "Enter a part num: ";
    cin >> part_num;
    cout << "Enter the part's cost: ";
    cin >> cost;
    cout << "Enter a part description: ";
    cin >> description;
    cout << "Specify type (Head, Arm, Torso, Battery, Motor): ";
    cin >> type;

    
    return 0;
}











