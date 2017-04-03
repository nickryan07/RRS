#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Robot_models {

public:
    double cost()
    {
    }
    double max_speed()
    {
    }
    double battery_life()
    {
    }

};

class Robot_parts : public Robot_models {

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

public:
    Head(double _power, string name, int model_num, string description, double cost)
    : Robot_parts(name, model_num, description, cost)
    {
        power = _power;
    }

private:
    double power;
};

class Arm : public Robot_parts {

public:
    Arm(double _arm_power, string name, int model_num, string description, double cost)
    : Robot_parts(name, model_num, description, cost)
    {
        arm_power = _arm_power;
    }
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
    cout << "Enter a part name (one word): ";
    cin >> name;
    cout << "Enter a part num (int): ";
    cin >> part_num;
    cout << "Enter the part's cost (double): ";
    cin >> cost;
    cout << "Enter a part description (one word): ";
    cin >> description;
    cout << "Specify type (Head, Arm, Torso, Battery, Motor): ";
    cin >> type;
    if(type == "Torso" || type == "torso") {
        int slots, arms;
        cout << "Enter num battery slots: ";
        cin >> slots;
        cout << "Enter num of arms: ";
        cin >> arms;
        Torso *t = new Torso(slots, arms, name, part_num, description, cost);
        cout << "Created new torso part named "<< name << endl;
    } else if(type == "Head" || type == "head") {
        double power;
        cout << "Enter power: ";
        cin >> power;
        Head *h = new Head(power, name, part_num, description, cost);
        cout << "Created new head part named "<< name << endl;
    } else if(type == "Arm" || type == "arm") {
        double arm_power;
        cout << "Enter arm power: ";
        cin >> arm_power;
        Arm *a = new Arm(arm_power, name, part_num, description, cost);
        cout << "Created new arm part named "<< name << endl;
    } else if(type == "Motor" || type == "motor") {
        double max_power;
        cout << "Enter power: ";
        cin >> max_power;
        Motor *m = new Motor(max_power, name, part_num, description, cost);
        cout << "Created new motor part named "<< name << endl;
    } else if(type == "Battery" || type == "battery") {
        double power_ava, max_energy;
        cout << "Enter available power: ";
        cin >> power_ava;
        cout << "Enter max energy: ";
        cin >> max_energy;
        Battery *b = new Battery(power_ava, max_energy, name, part_num, description, cost);
        cout << "Created new battery part named "<< name << endl;
    }
    
    return 0;
}











