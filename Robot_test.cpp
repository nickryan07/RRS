#include <iostream>
#include <fstream>

#include "Robot_parts.h"
#include "Utils.h"
#include "Customer.h"
#include "Sales_associate.h"
#include "Order.h"
#include "Create_part.h"

#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <Fl/Fl_Text_Display.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>

using namespace std;

void load_data() {
    string type, name, description;
    int part_num, command;
    double cost;
    //TODO : Introduce Shop class; Move vector locations -> model class, shop class
    string path = "data.txt";
    ifstream file;
    file.open(path, ios::in);
    string s1;
    if(file.is_open() != true) {
        cerr << "### Error opening input file:" << path << "..exiting\n";
    }
    while(!file.eof()) {
        getline(file, s1);
        //cout << s1 << endl; Helpful to visualize each input block
        if(s1 == "#Head") {
            double pow;
            getline(file, name);
            file >> part_num;
            file.ignore();
            getline(file, description);
            file >> cost;
            file.ignore();
            file >> pow;
            file.ignore();
            Head *h = new Head(
                pow, name, part_num, description, cost);
            heads.push_back(*h);
        } else if(s1 == "#Arm") {
            double apow;
            getline(file, name);
            file >> part_num;
            file.ignore();
            getline(file, description);
            file >> cost;
            file.ignore();
            file >> apow;
            file.ignore();
            Arm *a = new Arm(
                apow, name, part_num, description, cost);
            arms.push_back(*a);
        } else if(s1 == "#Torso") {
            int slots, arms;
            getline(file, name);
            file >> part_num;
            file.ignore();
            getline(file, description);
            file >> cost;
            file.ignore();
            file >> slots;
            file.ignore();
            file >> arms;
            file.ignore();
            Torso *t = new Torso(
                slots, arms, name, part_num, description, cost);
            torsos.push_back(*t);
        } else if(s1 == "#Battery") {
            double avpow, maxe;
            getline(file, name);
            file >> part_num;
            file.ignore();
            getline(file, description);
            file >> cost;
            file.ignore();
            file >> avpow;
            file.ignore();
            file >> maxe;
            file.ignore();
            Battery *b = new Battery(
                avpow, maxe, name, part_num, description, cost);
            batteries.push_back(*b);
        } else if(s1 == "#Motor") {
            double maxpow;
            getline(file, name);
            file >> part_num;
            file.ignore();
            getline(file, description);
            file >> cost;
            file.ignore();
            file >> maxpow;
            file.ignore();
            Motor *m = new Motor(
                maxpow, name, part_num, description, cost);
            motors.push_back(*m);
        } else if(s1 == "#Customer") {
            int cnum;
            string nm, email, phone;
            getline(file, nm);
            getline(file, phone);
            getline(file, email);
            file >> cnum;
            file.ignore();
            Customer *c = new Customer(
                nm, phone, email, cnum);
            customers.push_back(*c);
        } else if(s1 == "#Associate") {
            int employee_num;
            string nm;
            getline(file, nm);
            file >> employee_num;
            file.ignore();
            Sales_associate *s = new Sales_associate(
                nm, employee_num);
            associates.push_back(*s);
        } else if(s1 == "#Model") {
            int mod_num, t, h, a, m, b;
            double cost;
            string name;
            getline(file, name);
            file >> mod_num;
            file.ignore();
            file >> cost;
            file.ignore();
            file >> t;
            file.ignore();
            file >> m;
            file.ignore();
            file >> a;
            file.ignore();
            file >> b;
            file.ignore();
            file >> h;
            file.ignore();
            Robot_models *mod = new Robot_models(name, mod_num, cost,
                torsos[t], motors[m], arms[a],
                batteries[b], heads[h]);
            models.push_back(*mod);
        } else if(s1 == "#Order") {
            int order_num, status, customer, associate, model;
            string date;
            file >> order_num;
            file.ignore();
            file >> status;
            file.ignore();
            getline(file, date);
            file >> customer;
            file.ignore();
            file >> associate;
            file.ignore();
            file >> model;
            file.ignore();
            Order *o = new Order(
                order_num, status, date, customers[customer], associates[associate], models[model]);
            orders.push_back(*o);
        }
    }
}

int main() {
    load_data();
    lib->show();

    return Fl::run();
}


// ORIGINAL MAIN


/*int main() {
    string type, name, description;
    int part_num, command;
    double cost;
    //TODO : Introduce Shop class; Move vector locations -> model class, shop class
    string path = "data.txt";
    ifstream file;
    file.open(path, ios::in);
    string s1;
    if(file.is_open() != true) {
        cerr << "### Error opening input file:" << path << "..exiting\n";
        return 0;
    }
    while(!file.eof()) {
        getline(file, s1);
        //cout << s1 << endl; Helpful to visualize each input block
        if(s1 == "#Head") {
            double pow;
            getline(file, name);
            file >> part_num;
            file.ignore();
            getline(file, description);
            file >> cost;
            file.ignore();
            file >> pow;
            file.ignore();
            Head *h = new Head(
                pow, name, part_num, description, cost);
            heads.push_back(*h);
        } else if(s1 == "#Arm") {
            double apow;
            getline(file, name);
            file >> part_num;
            file.ignore();
            getline(file, description);
            file >> cost;
            file.ignore();
            file >> apow;
            file.ignore();
            Arm *a = new Arm(
                apow, name, part_num, description, cost);
            arms.push_back(*a);
        } else if(s1 == "#Torso") {
            int slots, arms;
            getline(file, name);
            file >> part_num;
            file.ignore();
            getline(file, description);
            file >> cost;
            file.ignore();
            file >> slots;
            file.ignore();
            file >> arms;
            file.ignore();
            Torso *t = new Torso(
                slots, arms, name, part_num, description, cost);
            torsos.push_back(*t);
        } else if(s1 == "#Battery") {
            double avpow, maxe;
            getline(file, name);
            file >> part_num;
            file.ignore();
            getline(file, description);
            file >> cost;
            file.ignore();
            file >> avpow;
            file.ignore();
            file >> maxe;
            file.ignore();
            Battery *b = new Battery(
                avpow, maxe, name, part_num, description, cost);
            batteries.push_back(*b);
        } else if(s1 == "#Motor") {
            double maxpow;
            getline(file, name);
            file >> part_num;
            file.ignore();
            getline(file, description);
            file >> cost;
            file.ignore();
            file >> maxpow;
            file.ignore();
            Motor *m = new Motor(
                maxpow, name, part_num, description, cost);
            motors.push_back(*m);
        } else if(s1 == "#Customer") {
            int cnum;
            string nm, email, phone;
            getline(file, nm);
            getline(file, phone);
            getline(file, email);
            file >> cnum;
            file.ignore();
            Customer *c = new Customer(
                nm, phone, email, cnum);
            customers.push_back(*c);
        } else if(s1 == "#Associate") {
            int employee_num;
            string nm;
            getline(file, nm);
            file >> employee_num;
            file.ignore();
            Sales_associate *s = new Sales_associate(
                nm, employee_num);
            associates.push_back(*s);
        } else if(s1 == "#Model") {
            int mod_num, t, h, a, m, b;
            double cost;
            string name;
            getline(file, name);
            file >> mod_num;
            file.ignore();
            file >> cost;
            file.ignore();
            file >> t;
            file.ignore();
            file >> m;
            file.ignore();
            file >> a;
            file.ignore();
            file >> b;
            file.ignore();
            file >> h;
            file.ignore();
            Robot_models *mod = new Robot_models(name, mod_num, cost,
                torsos[t], motors[m], arms[a],
                batteries[b], heads[h]);
            models.push_back(*mod);
        }
    }*/
    /*while(true) {
	    cout << "------ Main Menu ------ " << endl;
	    cout << "(1) Create new parts." << endl;
	    cout << "(2) Define new models." << endl;
        cout << "(3) Browse existing models." << endl;
        cout << "(4) Add a new Customer." << endl;
        cout << "(5) Add a new Sales Associate." << endl;
        cout << "(6) Create a new order." << endl;
        cout << "(7) List current Customers." << endl;
        cout << "(8) List current Sales Associates." << endl;
        cout << "(0) Quit." << endl;
        command = get_int("Enter command: ");
        if (command > 8 || command < 0)
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
                t->save();
            	cout << "Created new torso part named "<< name << endl;
    	    } else if(type == "Head" || type == "head") {
        		Head *h = new Head(
                    get_double("Enter the head's power: "),
                    name, part_num, description, cost);
                heads.push_back(*h);
                h->save();
        		cout << "Created new head part named "<< name << endl;
    	    } else if(type == "Arm" || type == "arm") {
        		Arm *a = new Arm(
                    get_double("Enter max arm power: "),
                    name, part_num, description, cost);
                arms.push_back(*a);
                a->save();
        		cout << "Created new arm part named "<< name << endl;
    	    } else if(type == "Motor" || type == "motor") {
        		Motor *m = new Motor(
                    get_double("Enter the max power: "),
                    name, part_num, description, cost);
                motors.push_back(*m);
                m->save();
        		cout << "Created new motor part named "<< name << endl;
    	    } else if(type == "Battery" || type == "battery") {
        		Battery *b = new Battery(
                    get_double("Enter available power: "),
                    get_double("Enter max energy: "),
                    name, part_num, description, cost);
                batteries.push_back(*b);
                b->save();
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
            customer->save();
            cout << "------ Successfully created a new Customer ------\n\n" << endl;
        } else if (command == 5) {
            cout << "\n------ Adding a new Sales Associate ------\n\n" << endl;
            Sales_associate *associate = new Sales_associate(
                get_full_line("Enter the employee's name: "),
                get_int("Enter the employee number: ")
            );
            associates.push_back(*associate);
            associate->save();
            cout << "------ Successfully created a new Sales Associate ------\n\n" << endl;
        } else if (command == 6) {
            cout << "\n------ Creating a new Order ------\n\n" << endl;
            Order *order = new Order(
                get_int("Enter the Order number: "),
                get_int("Enter the Order Status: "),
                get_full_line("Enter the Order date: "),
                customers[get_int("Enter the index number of the customer: ")],
                associates[get_int("Enter the index number of the sales associate: ")],
                models[get_int("Enter the index number of the model: ")]
            );
            orders.push_back(*order);
            cout << "------ Successfully created a new Order ------\n\n" << endl;
        } else if (command == 7) {
            cout << "\n--------- CUSTOMERS ---------\n" << endl;
            for(int i = 0; i < customers.size(); i++) {
               cout << "(" << i << ")\t" << "Name: " << customers[i].get_name() << endl;
            }
            cout << "\n--------- CUSTOMERS ---------\n" << endl;
        } else if (command == 8) {
            cout << "\n--------- SALES ASSOCIATES ---------\n" << endl;
            for(int i = 0; i < associates.size(); i++) {
               cout << "(" << i << ")\t" << "Name: " << associates[i].get_name() << "\tEmployee Number: " << associates[i].get_employee_number() << endl;
            }
            cout << "\n--------- SALES ASSOCIATES ---------\n" << endl;
        } else if (command == 0) {
            break;
        }
    }*/
    //Fl_Double_Window* w = create_part();
    //w->show();
    //create_part()->show();
    //w->show();
    //w->show();
    //create->show();
    //Main_menu *menu = new Main_menu;
//    lib->show();
    //add_head->show();

    //return Fl::run();
//}
