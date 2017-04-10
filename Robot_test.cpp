#include <iostream>
#include "Robot_parts.h"
#include "Utils.h"
#include "Customer.h"

using namespace std;

int main() {
    string type, name, description;
    int part_num, command;
    double cost;
    vector<Torso> torsos;
    vector<Motor> motors;
    vector<Arm> arms;
    vector<Head> heads;
    vector<Battery> batteries;
    vector<Robot_models> models;
    vector<Customer> customers;
    //TODO : vector<SALES_ASSOCIATES> associates;
    while(true) {
	    cout << "------ Main Menu ------ " << endl;
	    cout << "(1) Create new parts." << endl;
	    cout << "(2) Define new models." << endl;
        cout << "(3) Browse existing models." << endl;
        cout << "(4) Add a new Customer." << endl;
        cout << "(5) Add a new Sales Associate." << endl;
        cout << "(0) Quit." << endl;
        command = get_int("Enter command: ");
        if (command > 5 || command < 0)
            continue;
        if (command == 1) {
      	    cout << "---- Creating a robot part ----" << endl;
            name = get_full_line("Enter a part name: ");
            part_num = get_int("Enter a part number (int): ");
            cost = get_double("Enter the part's cost (double): ");
            description = get_full_line("Enter a part description: ");
            type = get_full_line("Specify part type (Head, Arm, Torso, Battery, Motor): ");
      	    if(type == "Torso" || type == "torso") {
            	Torso *t = new Torso(
                    get_int_range("Enter number of battery slots (1 to 3): ", 1, 3),
                    get_int_range("Enter number of arms (0 to 2): ", 0, 2),
                    name, part_num, description, cost);
                torsos.push_back(*t);
            	cout << "Created new torso part named "<< name << endl;
    	    } else if(type == "Head" || type == "head") {
        		Head *h = new Head(
                    get_double("Enter the head's power: "),
                    name, part_num, description, cost);
                heads.push_back(*h);
        		cout << "Created new head part named "<< name << endl;
    	    } else if(type == "Arm" || type == "arm") {
        		Arm *a = new Arm(
                    get_double("Enter max arm power: "),
                    name, part_num, description, cost);
                arms.push_back(*a);
        		cout << "Created new arm part named "<< name << endl;
    	    } else if(type == "Motor" || type == "motor") {
        		Motor *m = new Motor(
                    get_double("Enter the max power: "),
                    name, part_num, description, cost);
                motors.push_back(*m);
        		cout << "Created new motor part named "<< name << endl;
    	    } else if(type == "Battery" || type == "battery") {
        		Battery *b = new Battery(
                    get_double("Enter available power: "),
                    get_double("Enter max energy: "),
                    name, part_num, description, cost);
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
            cout << "\n------ Creating a Robot Model ------\n\n" << endl;
            Robot_models *mod = new Robot_models(
                get_full_line("Enter a model name: "),
                get_int("Enter a model number (int): "),
                get_double("Enter the model's price (double): "),
                torsos[get_int("Enter the index number of the torso you wish to use (int): ")],
                motors[get_int("Enter the index number of the motor you wish to use (int): ")],
                arms[get_int("Enter the index number of the arm(s) you wish to use (int): ")],
                batteries[get_int("Enter the index number of the battery you wish to use (int): ")],
                heads[get_int("Enter the index number of the head you wish to use (int): ")]
            );
            models.push_back(*mod);
        } else if (command == 3) {
            cout << "\n--------- MODELS ---------\n" << endl;
            for(int i = 0; i < models.size(); i++) {
               cout << "(" << i << ")\t" << "Name: " << models[i].get_name() << "\tPrice: " << models[i].cost() << endl;
            }
            cout << "\n--------- MODELS ---------\n" << endl;
        } else if (command == 4) {
            cout << "\n------ Adding a new Customer ------\n\n" << endl;
            Customer *customer = new Customer(
                get_full_line("Enter the customer's name: "),
                get_full_line("Enter the customer's phone number: "),
                get_full_line("Enter the customer's email address: "),
                get_int("Enter the customer number: ")
            );
            customers.push_back(*customer);
        } else if (command == 5) {
            //TODO
            break;
        } else if (command == 0) {
            break;
        }
    }

    return 0;
}
