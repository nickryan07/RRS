#include <iostream>
#include "Robot_parts.h"
#include "Utils.h"

using namespace std;

//TODO : Refactor using utils methods

int main() {
    string type, name, description;
    int part_num, command;
    vector<Torso> torsos;
    vector<Motor> motors;
    vector<Arm> arms;
    vector<Head> heads;
    vector<Battery> batteries;
    vector<Robot_models> models;
    double cost;
    string model_name;
    int model_number;
    double price;
    while(true) {
	    cout << "------ Main Menu ------ " << endl;
	    cout << "(1) Create new parts." << endl;
	    cout << "(2) Define new models." << endl;
        cout << "(3) Browse existing models." << endl;
        cout << "(0) Quit." << endl;
        cout << "Enter command: ";
	    cin >> command;
        if (command != 1 && command != 2 && command != 3 && command != 0)
            continue;
        if (command == 1) {
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
                torsos.push_back(*t);
            	cout << "Created new torso part named "<< name << endl;
    	    } else if(type == "Head" || type == "head") {
        		double power;
        		cout << "Enter power: ";
        		cin >> power;
        		Head *h = new Head(power, name, part_num, description, cost);
                heads.push_back(*h);
        		cout << "Created new head part named "<< name << endl;
    	    } else if(type == "Arm" || type == "arm") {
        		double arm_power;
        		cout << "Enter arm power: ";
        		cin >> arm_power;
        		Arm *a = new Arm(arm_power, name, part_num, description, cost);
                arms.push_back(*a);
        		cout << "Created new arm part named "<< name << endl;
    	    } else if(type == "Motor" || type == "motor") {
        		double max_power;
        		cout << "Enter power: ";
        		cin >> max_power;
        		Motor *m = new Motor(max_power, name, part_num, description, cost);
                motors.push_back(*m);
        		cout << "Created new motor part named "<< name << endl;
    	    } else if(type == "Battery" || type == "battery") {
        		double power_ava, max_energy;
        		cout << "Enter available power: ";
        		cin >> power_ava;
        		cout << "Enter max energy: ";
        		cin >> max_energy;
        		Battery *b = new Battery(power_ava, max_energy, name, part_num, description, cost);
                batteries.push_back(*b);
        		cout << "Created new battery part named "<< name << endl;
    	    }
        } else if (command == 2) {
            cout << "------ LIST OF PARTS ------" << endl;
            cout << "\n--- Torsos ---" << endl;
            for(int i = 0; i < torsos.size(); i++) {
                cout << "(" << i << ")\t" << "Name: " << torsos[i].get_name() << "\tCost: " << torsos[i].get_cost() << endl;
            }
            cout << "\n--- Heads ---" << endl;
            for(int i = 0; i < heads.size(); i++) {
                cout << "(" << i << ")\t" << "Name: " << heads[i].get_name() << "\tCost: " << heads[i].get_cost() << endl;
            }
            cout << "\n--- Arms ---" << endl;
            for(int i = 0; i < arms.size(); i++) {
                cout << "(" << i << ")\t" << "Name: " << arms[i].get_name() << "\tCost: " << arms[i].get_cost() << endl;
            }
            cout << "\n--- Motors ---" << endl;
            for(int i = 0; i < motors.size(); i++) {
                cout << "(" << i << ")\t" << "Name: " << motors[i].get_name() << "\tCost: " << motors[i].get_cost() << endl;
            }
            cout << "\n--- Batteries ---" << endl;
            for(int i = 0; i < batteries.size(); i++) {
                cout << "(" << i << ")\t" << "Name: " << batteries[i].get_name() << "\tCost: " << batteries[i].get_cost() << endl;
            }
            int t,h,b,m,a; //torso head battery motor arm
            cout << "\n------ Creating a Robot Model ------\n\n" << endl;
      	    cout << "Enter a model name (one word): ";
      	    cin >> name;
      	    cout << "Enter a part num (int): ";
      	    cin >> model_number;
      	    cout << "Enter the model's price (double): ";
      	    cin >> price;
            cout << "Enter the index number of the torso you wish to use (int): ";
            cin >> t;
            cout << "Enter the index number of the head you wish to use (int): ";
            cin >> h;
            cout << "Enter the index number of the battery you wish to use (int): ";
            cin >> b;
            cout << "Enter the index number of the motor you wish to use (int): ";
            cin >> m;
            cout << "Enter the index number of the arms you wish to use (int): ";
            cin >> a;
            Robot_models *mod = new Robot_models(model_name, model_number, price, torsos[t],
                motors[m], arms[a], batteries[b], heads[h]);
            models.push_back(*mod);
        } else if (command == 3) {
            cout << "\n--------- MODELS ---------\n" << endl;
            for(int i = 0; i < models.size(); i++) {
               cout << "(" << i << ")\t" << "Name: " << models[i].get_name() << "\tPrice: " << models[i].cost() << endl;
            }
            cout << "\n--------- MODELS ---------\n" << endl;
        } else if (command == 0) {
            break;
        }
    }

    return 0;
}
