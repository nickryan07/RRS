#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Robot_parts {

public:
     Robot_parts(string name, int model_num, string description, double cost)
     : name{name}, model_num{model_num}, description{description}, cost{cost} { };

     string get_name() {
         return name;
     }
     double get_cost() {
         return cost;
     }
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
        this_cost = cost;
    }

    double cost() {
        return this_cost;
    }

private:
    int this_cost;
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

class Robot_models {

public:
    Robot_models(string name, int model_num, double price, Robot_parts torso, Robot_parts motor,
     Robot_parts arm, Robot_parts battery, Robot_parts head)
    : name{name}, model_num{model_num}, price{price}, torso{torso}, motor{motor},
     arm{arm}, battery{battery}, head{head} { }

    double cost()
    {
        return price;//TODO
    }
    string get_name() {
        return name;
    }
    double max_speed()
    {
        //TODO
    }
    double battery_life()
    {
        //TODO
    }
private:
    string name;
    int model_num;
    double price;
    Robot_parts torso;
    Robot_parts motor;
    Robot_parts arm;
    Robot_parts battery;
    Robot_parts head;

};
