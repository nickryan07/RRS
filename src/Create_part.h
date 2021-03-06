#ifndef Create_part_h
#define Create_part_h
#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <Fl/Fl_Text_Display.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/fl_ask.H>

using namespace std;
////////////////////////////////////////
string menu = R"(
------------------------- Main Menu -------------------------

- You may use the menu bar to create new parts
and define new robot models.



- Customers may view a list of defined models.


NOTE: Please see the instruction manual
for more detail.

)";
vector<Torso> torsos;
vector<Motor> motors;
vector<Arm> arms;
vector<Head> heads;
vector<Battery> batteries;
vector<Robot_models> models;
vector<Customer> customers;
vector<Sales_associate> associates;
vector<Order> orders;


////////////////////////////////////////
void enter_arm(Fl_Widget* w, void* p);
void cancel_arm(Fl_Widget* w, void* p);
class Add_arm {
    public:
        Add_arm() {
            dialog_b = new Fl_Window(450,350, "Add Arm");
            b_name = new Fl_Input(125, 15, 150, 25, "Name: ");
            b_name->align(FL_ALIGN_LEFT);

            b_part_num = new Fl_Input(125, 55, 150, 25, "Part Number: ");
            b_part_num->align(FL_ALIGN_LEFT);

            b_cost = new Fl_Input(125, 95, 150, 25, "Cost: ");
            b_cost->align(FL_ALIGN_LEFT);

            b_desc = new Fl_Input(125, 135, 150, 25, "Description: ");
            b_desc->align(FL_ALIGN_LEFT);

            b_power = new Fl_Input(125, 175, 150, 25, "Arm Power: ");
            b_power->align(FL_ALIGN_LEFT);

            b_add = new Fl_Return_Button(305, 310, 80, 25, "Add");
            b_add->callback((Fl_Callback *)enter_arm, 0);

            cancel_b = new Fl_Button(385, 310, 60, 25, "Cancel");
            cancel_b->callback((Fl_Callback *)cancel_arm, 0);
            dialog_b->end();
            dialog_b->set_non_modal();
        }
        void show() {dialog_b->show();}
        void hide() {dialog_b->hide();}
        string name() {return b_name->value();}
        string part_num() {return b_part_num->value();}
        string cost() {return b_cost->value();}
        string description() {return b_desc->value();}
        string power() {return b_power->value();}
        void push_arm() {
            Arm *a = new Arm(atof(power().c_str()), name(), atoi(part_num().c_str()), description(), atof(cost().c_str()));
            arms.push_back(*a);
            a->save();
        }
    private:
        Fl_Window *dialog_b;
        Fl_Input *b_name;
        Fl_Input *b_part_num;
        Fl_Input *b_cost;
        Fl_Input *b_desc;
	    Fl_Input *b_power;
        Fl_Return_Button *b_add;
        Fl_Button *cancel_b;
        Fl_Text_Buffer *m1_buffer;
        Fl_Text_Display *m1_text;
	    Fl_Text_Buffer *m2_buffer;
        Fl_Text_Display *m2_text;
        Fl_Text_Buffer *m3_buffer;
        Fl_Text_Display *m3_text;
};
Add_arm *add_arm = new Add_arm;
void enter_arm(Fl_Widget* w, void* p) {
        add_arm->push_arm();
        add_arm->hide();
}
void cancel_arm(Fl_Widget* w, void* p) {
    add_arm->hide();
}
////////////////////////////////////////


////////////////////////////////////////
void enter_motor(Fl_Widget* w, void* p);
void cancel_motor(Fl_Widget* w, void* p);
class Add_motor {
    public:
        Add_motor() {
            dialog_b = new Fl_Window(450,350, "Add Motor");
            b_name = new Fl_Input(125, 15, 150, 25, "Name: ");
            b_name->align(FL_ALIGN_LEFT);

            b_part_num = new Fl_Input(125, 55, 150, 25, "Part Number: ");
            b_part_num->align(FL_ALIGN_LEFT);

            b_cost = new Fl_Input(125, 95, 150, 25, "Cost: ");
            b_cost->align(FL_ALIGN_LEFT);

            b_desc = new Fl_Input(125, 135, 150, 25, "Description: ");
            b_desc->align(FL_ALIGN_LEFT);

            b_power = new Fl_Input(125, 175, 150, 25, "Max Power: ");
            b_power->align(FL_ALIGN_LEFT);

            b_add = new Fl_Return_Button(305, 310, 80, 25, "Add");
            b_add->callback((Fl_Callback *)enter_motor, 0);

            cancel_b = new Fl_Button(385, 310, 60, 25, "Cancel");
            cancel_b->callback((Fl_Callback *)cancel_motor, 0);
            dialog_b->end();
            dialog_b->set_non_modal();
        }
        void show() {dialog_b->show();}
        void hide() {dialog_b->hide();}
        string name() {return b_name->value();}
        string part_num() {return b_part_num->value();}
        string cost() {return b_cost->value();}
        string description() {return b_desc->value();}
        string power() {return b_power->value();}
        void push_motor() {
            Motor *m = new Motor(atof(power().c_str()), name(), atoi(part_num().c_str()), description(), atof(cost().c_str()));
            motors.push_back(*m);
            m->save();
        }
    private:
        Fl_Window *dialog_b;
        Fl_Input *b_name;
        Fl_Input *b_part_num;
        Fl_Input *b_cost;
        Fl_Input *b_desc;
	    Fl_Input *b_power;
        Fl_Return_Button *b_add;
        Fl_Button *cancel_b;
        Fl_Text_Buffer *m1_buffer;
        Fl_Text_Display *m1_text;
	    Fl_Text_Buffer *m2_buffer;
        Fl_Text_Display *m2_text;
        Fl_Text_Buffer *m3_buffer;
        Fl_Text_Display *m3_text;
};
Add_motor *add_motor = new Add_motor;
void enter_motor(Fl_Widget* w, void* p) {
        add_motor->push_motor();
        add_motor->hide();
}
void cancel_motor(Fl_Widget* w, void* p) {
    add_motor->hide();
}
////////////////////////////////////////

////////////////////////////////////////
void enter_customer(Fl_Widget* w, void* p);
void cancel_customer(Fl_Widget* w, void* p);
class Add_customer {
    public:
        Add_customer() {
            dialog_b = new Fl_Window(450,350, "Add Customer");
            b_name = new Fl_Input(125, 15, 150, 25, "Name: ");
            b_name->align(FL_ALIGN_LEFT);

            b_part_num = new Fl_Input(125, 55, 150, 25, "Phone Number: ");
            b_part_num->align(FL_ALIGN_LEFT);

            b_cost = new Fl_Input(125, 95, 150, 25, "Email: ");
            b_cost->align(FL_ALIGN_LEFT);

            b_desc = new Fl_Input(125, 135, 150, 25, "Customer #: ");
            b_desc->align(FL_ALIGN_LEFT);

            b_add = new Fl_Return_Button(305, 310, 80, 25, "Add");
            b_add->callback((Fl_Callback *)enter_customer, 0);

            cancel_b = new Fl_Button(385, 310, 60, 25, "Cancel");
            cancel_b->callback((Fl_Callback *)cancel_customer, 0);
            dialog_b->end();
            dialog_b->set_non_modal();
        }
        void show() {dialog_b->show();}
        void hide() {dialog_b->hide();}
        string name() {return b_name->value();}
        string phone_num() {return b_part_num->value();}
        string email() {return b_cost->value();}
        string customer_num() {return b_desc->value();}
        void push_motor() {
            Customer *c = new Customer(name(), phone_num(), email(), atoi(customer_num().c_str()));
            customers.push_back(*c);
            c->save();
        }
    private:
        Fl_Window *dialog_b;
        Fl_Input *b_name;
        Fl_Input *b_part_num;
        Fl_Input *b_cost;
        Fl_Input *b_desc;
        Fl_Return_Button *b_add;
        Fl_Button *cancel_b;
        Fl_Text_Buffer *m1_buffer;
        Fl_Text_Display *m1_text;
	    Fl_Text_Buffer *m2_buffer;
        Fl_Text_Display *m2_text;
        Fl_Text_Buffer *m3_buffer;
        Fl_Text_Display *m3_text;
};
Add_customer *add_customer = new Add_customer;
void enter_customer(Fl_Widget* w, void* p) {
        add_customer->push_motor();
        add_customer->hide();
}
void cancel_customer(Fl_Widget* w, void* p) {
    add_customer->hide();
}
////////////////////////////////////////

////////////////////////////////////////
void enter_associate(Fl_Widget* w, void* p);
void cancel_associate(Fl_Widget* w, void* p);
class Add_associate {
    public:
        Add_associate() {
            dialog_b = new Fl_Window(450,150, "Add Associate");
            b_name = new Fl_Input(125, 15, 150, 25, "Name: ");
            b_name->align(FL_ALIGN_LEFT);

            b_part_num = new Fl_Input(125, 55, 150, 25, "Employee #: ");
            b_part_num->align(FL_ALIGN_LEFT);

            b_add = new Fl_Return_Button(305, 110, 80, 25, "Add");
            b_add->callback((Fl_Callback *)enter_associate, 0);

            cancel_b = new Fl_Button(385, 110, 60, 25, "Cancel");
            cancel_b->callback((Fl_Callback *)cancel_associate, 0);
            dialog_b->end();
            dialog_b->set_non_modal();
        }
        void show() {dialog_b->show();}
        void hide() {dialog_b->hide();}
        string name() {return b_name->value();}
        string associate_num() {return b_part_num->value();}
        void push_motor() {
            Sales_associate *assoc = new Sales_associate(name(), atoi(associate_num().c_str()));
            associates.push_back(*assoc);
            assoc->save();
        }
    private:
        Fl_Window *dialog_b;
        Fl_Input *b_name;
        Fl_Input *b_part_num;
        Fl_Return_Button *b_add;
        Fl_Button *cancel_b;
        Fl_Text_Buffer *m1_buffer;
        Fl_Text_Display *m1_text;
	    Fl_Text_Buffer *m2_buffer;
        Fl_Text_Display *m2_text;
        Fl_Text_Buffer *m3_buffer;
        Fl_Text_Display *m3_text;
};
Add_associate *add_associate = new Add_associate;
void enter_associate(Fl_Widget* w, void* p) {
        add_associate->push_motor();
        add_associate->hide();
}
void cancel_associate(Fl_Widget* w, void* p) {
    add_associate->hide();
}
////////////////////////////////////////


////////////////////////////////////////
void enter_battery(Fl_Widget* w, void* p);
void cancel_battery(Fl_Widget* w, void* p);
class Add_battery {
    public:
        Add_battery() {
            dialog_b = new Fl_Window(450,350, "Add Battery");
            b_name = new Fl_Input(125, 15, 150, 25, "Name: ");
            b_name->align(FL_ALIGN_LEFT);

            b_part_num = new Fl_Input(125, 55, 150, 25, "Part Number: ");
            b_part_num->align(FL_ALIGN_LEFT);

            b_cost = new Fl_Input(125, 95, 150, 25, "Cost: ");
            b_cost->align(FL_ALIGN_LEFT);

            b_desc = new Fl_Input(125, 135, 150, 25, "Description: ");
            b_desc->align(FL_ALIGN_LEFT);

            b_power = new Fl_Input(125, 175, 150, 25, "Available power: ");
            b_power->align(FL_ALIGN_LEFT);

            b_energy = new Fl_Input(125, 215, 150, 25, "Max Energy: ");
            b_energy->align(FL_ALIGN_LEFT);

            b_add = new Fl_Return_Button(305, 310, 80, 25, "Add");
            b_add->callback((Fl_Callback *)enter_battery, 0);

            cancel_b = new Fl_Button(385, 310, 60, 25, "Cancel");
            cancel_b->callback((Fl_Callback *)cancel_battery, 0);
            dialog_b->end();
            dialog_b->set_non_modal();
        }
        void show() {dialog_b->show();}
        void hide() {dialog_b->hide();}
        string name() {return b_name->value();}
        string part_num() {return b_part_num->value();}
        string cost() {return b_cost->value();}
        string description() {return b_desc->value();}
        string power() {return b_power->value();}
        string energy() {return b_energy->value();}
        void push_battery() {
            Battery *b = new Battery(atoi(power().c_str()), atoi(energy().c_str()), name(), atoi(part_num().c_str()), description(), atof(cost().c_str()));
            batteries.push_back(*b);
            b->save();
        }
    private:
        Fl_Window *dialog_b;
        Fl_Input *b_name;
        Fl_Input *b_part_num;
        Fl_Input *b_cost;
        Fl_Input *b_desc;
	    Fl_Input *b_power;
        Fl_Input *b_energy;
        Fl_Return_Button *b_add;
        Fl_Button *cancel_b;
        Fl_Text_Buffer *m1_buffer;
        Fl_Text_Display *m1_text;
	    Fl_Text_Buffer *m2_buffer;
        Fl_Text_Display *m2_text;
        Fl_Text_Buffer *m3_buffer;
        Fl_Text_Display *m3_text;
};
Add_battery *add_battery = new Add_battery;
void enter_battery(Fl_Widget* w, void* p) {
        add_battery->push_battery();
        add_battery->hide();
}
void cancel_battery(Fl_Widget* w, void* p) {
    add_battery->hide();
}
////////////////////////////////////////


////////////////////////////////////////
void enter_torso(Fl_Widget* w, void* p);
void cancel_torso(Fl_Widget* w, void* p);
class Add_torso {
    public:
        Add_torso() {
            dialog_b = new Fl_Window(450,350, "Add Torso");
            b_name = new Fl_Input(125, 15, 150, 25, "Name: ");
            b_name->align(FL_ALIGN_LEFT);

            b_part_num = new Fl_Input(125, 55, 150, 25, "Part Number: ");
            b_part_num->align(FL_ALIGN_LEFT);

            b_cost = new Fl_Input(125, 95, 150, 25, "Cost: ");
            b_cost->align(FL_ALIGN_LEFT);

            b_desc = new Fl_Input(125, 135, 150, 25, "Description: ");
            b_desc->align(FL_ALIGN_LEFT);

            b_slots = new Fl_Input(125, 175, 150, 25, "# Batteries(1-3): ");
            b_slots->align(FL_ALIGN_LEFT);

            b_arms = new Fl_Input(125, 215, 150, 25, "# Arms(0-2): ");
            b_arms->align(FL_ALIGN_LEFT);

            b_add = new Fl_Return_Button(305, 310, 80, 25, "Add");
            b_add->callback((Fl_Callback *)enter_torso, 0);

            cancel_b = new Fl_Button(385, 310, 60, 25, "Cancel");
            cancel_b->callback((Fl_Callback *)cancel_torso, 0);
            dialog_b->end();
            dialog_b->set_non_modal();
        }
        void show() {dialog_b->show();}
        void hide() {dialog_b->hide();}
        string name() {return b_name->value();}
        string part_num() {return b_part_num->value();}
        string cost() {return b_cost->value();}
        string description() {return b_desc->value();}
        string slots() {return b_slots->value();}
        string arms() {return b_arms->value();}
        void push_torso() {
            Torso *t = new Torso(atoi(slots().c_str()), atoi(arms().c_str()), name(), atoi(part_num().c_str()), description(), atof(cost().c_str()));
            torsos.push_back(*t);
            t->save();
        }
    private:
        Fl_Window *dialog_b;
        Fl_Input *b_name;
        Fl_Input *b_part_num;
        Fl_Input *b_cost;
        Fl_Input *b_desc;
	    Fl_Input *b_slots;
        Fl_Input *b_arms;
        Fl_Return_Button *b_add;
        Fl_Button *cancel_b;
        Fl_Text_Buffer *m1_buffer;
        Fl_Text_Display *m1_text;
	    Fl_Text_Buffer *m2_buffer;
        Fl_Text_Display *m2_text;
        Fl_Text_Buffer *m3_buffer;
        Fl_Text_Display *m3_text;
};
Add_torso *add_torso = new Add_torso;
void enter_torso(Fl_Widget* w, void* p) {
        add_torso->push_torso();
        add_torso->hide();
}
void cancel_torso(Fl_Widget* w, void* p) {
    add_torso->hide();
}
////////////////////////////////////////


////////////////////////////////////////
void enter_head(Fl_Widget* w, void* p);
void cancel_head(Fl_Widget* w, void* p);
class Add_head {
    public:
        Add_head() {
            dialog_b = new Fl_Window(450,350, "Add Head");
            b_name = new Fl_Input(125, 15, 150, 25, "Name: ");
            b_name->align(FL_ALIGN_LEFT);

            b_part_num = new Fl_Input(125, 55, 150, 25, "Part Number: ");
            b_part_num->align(FL_ALIGN_LEFT);

            b_cost = new Fl_Input(125, 95, 150, 25, "Cost: ");
            b_cost->align(FL_ALIGN_LEFT);

            b_desc = new Fl_Input(125, 135, 150, 25, "Description: ");
            b_desc->align(FL_ALIGN_LEFT);

            b_power = new Fl_Input(125, 175, 150, 25, "Power: ");
            b_power->align(FL_ALIGN_LEFT);

            b_add = new Fl_Return_Button(305, 310, 80, 25, "Add");
            b_add->callback((Fl_Callback *)enter_head, 0);

            cancel_b = new Fl_Button(385, 310, 60, 25, "Cancel");
            cancel_b->callback((Fl_Callback *)cancel_head, 0);
            dialog_b->end();
            dialog_b->set_non_modal();
        }
        void show() {dialog_b->show();}
        void hide() {dialog_b->hide();}
        string name() {return b_name->value();}
        string part_num() {return b_part_num->value();}
        string cost() {return b_cost->value();}
        string description() {return b_desc->value();}
        string power() {return b_power->value();}
        void push_head() {
            Head *h = new Head(atof(power().c_str()), name(), atoi(part_num().c_str()), description(), atof(cost().c_str()));
            heads.push_back(*h);
            h->save();
        }
    private:
        Fl_Window *dialog_b;
        Fl_Input *b_name;
        Fl_Input *b_part_num;
        Fl_Input *b_cost;
        Fl_Input *b_desc;
	    Fl_Input *b_power;
        Fl_Return_Button *b_add;
        Fl_Button *cancel_b;
        Fl_Text_Buffer *m1_buffer;
        Fl_Text_Display *m1_text;
	    Fl_Text_Buffer *m2_buffer;
        Fl_Text_Display *m2_text;
        Fl_Text_Buffer *m3_buffer;
        Fl_Text_Display *m3_text;
};
Add_head *add_head = new Add_head;
void enter_head(Fl_Widget* w, void* p) {
        add_head->push_head();
        add_head->hide();
}
void cancel_head(Fl_Widget* w, void* p) {
    add_head->hide();
}
////////////////////////////////////////

////////////////////////////////////////
void enter_model(Fl_Widget* w, void* p);
void cancel_model(Fl_Widget* w, void* p);
void list_torsos(Fl_Widget* w, void* p);
void list_heads(Fl_Widget* w, void* p);
void list_arms(Fl_Widget* w, void* p);
void list_batteries(Fl_Widget* w, void* p);
void list_motors(Fl_Widget* w, void* p);
class Add_model {
    public:
        Add_model() {
            dialog_b = new Fl_Window(450,355, "Define a model");
            b_name = new Fl_Input(125, 15, 150, 25, "Name: ");
            b_name->align(FL_ALIGN_LEFT);

            b_part_num = new Fl_Input(125, 55, 150, 25, "Model Number: ");
            b_part_num->align(FL_ALIGN_LEFT);

            b_cost = new Fl_Input(125, 95, 150, 25, "Price: ");
            b_cost->align(FL_ALIGN_LEFT);

            b_torso = new Fl_Input(125,135,150,25,"Torso Number: ");
            b_torso->align(FL_ALIGN_LEFT);

            list_torso = new Fl_Button(295, 135, 100, 25, "List Torsos");
            list_torso->callback((Fl_Callback *)list_torsos, 0);

            b_head = new Fl_Input(125,175,150,25,"Head Number: ");
            b_head->align(FL_ALIGN_LEFT);

            list_head = new Fl_Button(295, 175, 100, 25, "List Heads");
            list_head->callback((Fl_Callback *)list_heads, 0);

            b_arm = new Fl_Input(125,215,150,25,"Arm Number: ");
            b_arm->align(FL_ALIGN_LEFT);

            list_arm = new Fl_Button(295, 215, 100, 25, "List Arms");
            list_arm->callback((Fl_Callback *)list_arms, 0);

            b_battery = new Fl_Input(125,255,150,25,"Battery Number: ");
            b_battery->align(FL_ALIGN_LEFT);

            list_battery = new Fl_Button(295, 255, 100, 25, "List Batteries");
            list_battery->callback((Fl_Callback *)list_batteries, 0);

            b_motor = new Fl_Input(125,295,150,25,"Motor Number: ");
            b_motor->align(FL_ALIGN_LEFT);

            list_motor = new Fl_Button(295, 295, 100, 25, "List Motors");
            list_motor->callback((Fl_Callback *)list_motors, 0);

            b_add = new Fl_Return_Button(305, 325, 80, 25, "Add");
            b_add->callback((Fl_Callback *)enter_model, 0);

            cancel_b = new Fl_Button(385, 325, 60, 25, "Cancel");
            cancel_b->callback((Fl_Callback *)cancel_model, 0);
            dialog_b->end();
            dialog_b->set_non_modal();
        }
        void show() {dialog_b->show();}
        void hide() {dialog_b->hide();}

        string name() {return b_name->value();}
        string part_num() {return b_part_num->value();}
        string cost() {return b_cost->value();}
        string torso() {return b_torso->value();}
        string head() {return b_head->value();}
        string arm() {return b_arm->value();}
        string battery() {return b_battery->value();}
        string motor() {return b_motor->value();}
        void save() {
            filebuf f;
            f.open("data.txt", ios::app);
            ostream ost(&f);
            ost << "#Model" << endl;
            ost << name() << endl;
            ost << atoi(part_num().c_str()) << endl;
            ost << atof(cost().c_str()) << endl;
            ost << atoi(torso().c_str()) << endl;
            ost << atoi(motor().c_str()) << endl;
            ost << atoi(arm().c_str()) << endl;
            ost << atoi(battery().c_str()) << endl;
            ost << atoi(head().c_str()) << endl;
            f.close();
        }
        void push_model() {
            Robot_models *m = new Robot_models(name(), atoi(part_num().c_str()), atof(cost().c_str()),
                torsos[atoi(torso().c_str())], motors[atoi(motor().c_str())], arms[atoi(arm().c_str())],
                batteries[atoi(battery().c_str())], heads[atoi(head().c_str())]);
            models.push_back(*m);
            save();
        }
    private:
        Fl_Window *dialog_b;
        Fl_Input *b_name;
        Fl_Input *b_part_num;
        Fl_Input *b_cost;
        Fl_Input *b_torso;
	    Fl_Input *b_head;
        Fl_Input *b_arm;
        Fl_Input *b_motor;
        Fl_Input *b_battery;
        Fl_Return_Button *b_add;
        Fl_Button *cancel_b;
        Fl_Button *list_torso;
        Fl_Button *list_head;
        Fl_Button *list_arm;
        Fl_Button *list_battery;
        Fl_Button *list_motor;
        Fl_Text_Buffer *m1_buffer;
        Fl_Text_Display *m1_text;
	    Fl_Text_Buffer *m2_buffer;
        Fl_Text_Display *m2_text;
        Fl_Text_Buffer *m3_buffer;
        Fl_Text_Display *m3_text;
};
Add_model *add_model = new Add_model;
void enter_model(Fl_Widget* w, void* p) {
        add_model->push_model();
        add_model->hide();
}
void cancel_model(Fl_Widget* w, void* p) {
    add_model->hide();
}
void list_torsos(Fl_Widget* w, void* p) {
    string s = "";
    for(int i = 0; i < torsos.size(); i++) {
        s += ("(" + to_string(i) + ")\t" + "Name: " + torsos[i].get_name() + "\tCost: " + to_string(torsos[i].get_cost()) + "\n");
    }
    fl_message(s.c_str());
}
void list_heads(Fl_Widget* w, void* p) {
    string s = "";
    for(int i = 0; i < heads.size(); i++) {
        s += ("(" + to_string(i) + ")\t" + "Name: " + heads[i].get_name() + "\tCost: " + to_string(heads[i].get_cost()) + "\n");
    }
    fl_message(s.c_str());
}
void list_arms(Fl_Widget* w, void* p) {
    string s = "";
    for(int i = 0; i < arms.size(); i++) {
        s += ("(" + to_string(i) + ")\t" + "Name: " + arms[i].get_name() + "\tCost: " + to_string(arms[i].get_cost()) + "\n");
    }
    fl_message(s.c_str());
}
void list_batteries(Fl_Widget* w, void* p) {
    string s = "";
    for(int i = 0; i < batteries.size(); i++) {
        s += ("(" + to_string(i) + ")\t" + "Name: " + batteries[i].get_name() + "\tCost: " + to_string(batteries[i].get_cost()) + "\n");
    }
    fl_message(s.c_str());
}
void list_motors(Fl_Widget* w, void* p) {
    string s = "";
    for(int i = 0; i < motors.size(); i++) {
        s += ("(" + to_string(i) + ")\t" + "Name: " + motors[i].get_name() + "\tCost: " + to_string(motors[i].get_cost()) + "\n");
    }
    fl_message(s.c_str());
}
////////////////////////////////////////

////////////////////////////////////////
void enter_order(Fl_Widget* w, void* p);
void cancel_order(Fl_Widget* w, void* p);
void list_customers(Fl_Widget* w, void* p);
void list_associates(Fl_Widget* w, void* p);
void list_models(Fl_Widget* w, void* p);
class Add_order {
    public:
        Add_order() {
            dialog_b = new Fl_Window(450,350, "New Order");
            b_name = new Fl_Input(125, 15, 150, 25, "Order Number: ");
            b_name->align(FL_ALIGN_LEFT);

            b_part_num = new Fl_Input(125, 55, 150, 25, "Order Status: ");
            b_part_num->align(FL_ALIGN_LEFT);

            b_cost = new Fl_Input(125, 95, 150, 25, "Order Date: ");
            b_cost->align(FL_ALIGN_LEFT);

            b_desc = new Fl_Input(125, 135, 150, 25, "Customer #: ");
            b_desc->align(FL_ALIGN_LEFT);

            b_slots = new Fl_Input(125, 175, 150, 25, "Associate #: ");
            b_slots->align(FL_ALIGN_LEFT);

            b_arms = new Fl_Input(125, 215, 150, 25, "Model #: ");
            b_arms->align(FL_ALIGN_LEFT);

            list_c = new Fl_Button(295, 135, 100, 25, "Customer List");
            list_c->callback((Fl_Callback *)list_customers, 0);

            list_a = new Fl_Button(295, 175, 100, 25, "Associate List");
            list_a->callback((Fl_Callback *)list_associates, 0);

            list_m = new Fl_Button(295, 215, 100, 25, "Model List");
            list_m->callback((Fl_Callback *)list_models, 0);

            b_add = new Fl_Return_Button(305, 310, 80, 25, "Add");
            b_add->callback((Fl_Callback *)enter_order, 0);

            cancel_b = new Fl_Button(385, 310, 60, 25, "Cancel");
            cancel_b->callback((Fl_Callback *)cancel_order, 0);
            dialog_b->end();
            dialog_b->set_non_modal();
        }
        void show() {dialog_b->show();}
        void hide() {dialog_b->hide();}
        string order_num() {return b_name->value();}
        string order_state() {return b_part_num->value();}
        string order_date() {return b_cost->value();}
        string customer_num() {return b_desc->value();}
        string associate_num() {return b_slots->value();}
        string model_num() {return b_arms->value();}
        void save() {
            filebuf f;
            f.open("data.txt", ios::app);
            ostream ost(&f);
            ost << "#Order" << endl;
            ost << atoi(order_num().c_str()) << endl;
            ost << atoi(order_state().c_str()) << endl;
            ost << order_date() << endl;
            ost << atoi(customer_num().c_str()) << endl;
            ost << atoi(associate_num().c_str()) << endl;
            ost << atoi(model_num().c_str()) << endl;
            f.close();
        }
        void push_order() {
            Order *o = new Order(atoi(order_num().c_str()), atoi(order_state().c_str()), order_date(),
                                 customers[atoi(customer_num().c_str())], associates[atoi(associate_num().c_str())], models[atoi(model_num().c_str())]);
            orders.push_back(*o);
            save();
        }
    private:
        Fl_Window *dialog_b;
        Fl_Input *b_name;
        Fl_Input *b_part_num;
        Fl_Input *b_cost;
        Fl_Input *b_desc;
	    Fl_Input *b_slots;
        Fl_Input *b_arms;
        Fl_Button *list_c;
        Fl_Button *list_a;
        Fl_Button *list_m;
        Fl_Return_Button *b_add;
        Fl_Button *cancel_b;
        Fl_Text_Buffer *m1_buffer;
        Fl_Text_Display *m1_text;
	    Fl_Text_Buffer *m2_buffer;
        Fl_Text_Display *m2_text;
        Fl_Text_Buffer *m3_buffer;
        Fl_Text_Display *m3_text;
};
Add_order *add_order = new Add_order;
void enter_order(Fl_Widget* w, void* p) {
        add_order->push_order();
        add_order->hide();
}
void cancel_order(Fl_Widget* w, void* p) {
    add_order->hide();
}
void list_customers(Fl_Widget* w, void* p) {
    string s = "";
    for(int i = 0; i < customers.size(); i++) {
        s += ("(" + to_string(i) + ")\t" + "Name: " + customers[i].get_name() + "\n");
    }
    fl_message(s.c_str());
}
void list_associates(Fl_Widget* w, void* p) {
    string s = "";
    for(int i = 0; i < associates.size(); i++) {
        s += ("(" + to_string(i) + ")\t" + "Name: " + associates[i].get_name() + "\n");
    }
    fl_message(s.c_str());
}
void list_models(Fl_Widget* w, void* p) {
    string s = "";
    for(int i = 0; i < models.size(); i++) {
        s += ("(" + to_string(i) + ")\t" + "Name: " + models[i].get_name() + "\n");
    }
    fl_message(s.c_str());
}
////////////////////////////////////////

/* MENU BAR */
Fl_Menu_Bar *menubar;
void AddHead(Fl_Widget* w, void* p);
void AddTorso(Fl_Widget* w, void* p);
void AddBattery(Fl_Widget* w, void* p);
void AddMotor(Fl_Widget* w, void* p);
void AddArm(Fl_Widget* w, void* p);
void AddModel(Fl_Widget* w, void* p);
void ListModel(Fl_Widget* w, void* p);
void AddOrder(Fl_Widget* w, void* p);
void ListOrder(Fl_Widget* w, void* p);
void ManageOrder(Fl_Widget* w, void* p);
void AddCustomer(Fl_Widget* w, void* p);
void AddAssociate(Fl_Widget* w, void* p);
void EE(Fl_Widget* w, void* p);
/* MENU BAR */
void enter_command(Fl_Widget* w, void* p);
void cancel_command(Fl_Widget* w, void* p);
class Main_menu {
    public:
        Main_menu() {
            dialog = new Fl_Window(400,550, "Menu");
	    menubar = new Fl_Menu_Bar(0, 0, 400, 30);
 	    menubar->menu(menuitems);

	    string s = menu;
            m_buffer = new Fl_Text_Buffer();
            m_text = new Fl_Text_Display(10, 45, 380, 450);
            m_text->buffer(m_buffer);
            m_buffer->text(s.c_str());

            m_cancel = new Fl_Button(335, 510, 60, 25, "Close");
            m_cancel->callback((Fl_Callback *)cancel_command, 0);
            dialog->end();
            dialog->set_non_modal();
        }
        void show() {dialog->show();}
        void hide() {dialog->hide();}
        string command() {return m_command->value();}
        void execute(int a) {
            if(a == 0) {
                hide();
            } else if(a == 1) {
                add_head->show();
    	    } else if(a == 2) {
                add_torso->show();
            } else if(a == 3) {
	            add_battery->show();
	        } else if(a == 4) {
                add_motor->show();
            } else if(a == 5) {
                add_arm->show();
            } else if(a == 6) {
        	    add_model->show();
            } else if(a == 7) {
                string s = "";
                for(int i = 0; i < models.size(); i++) {
                    s += ("(" + to_string(i) + ")\t" + "Name: " + models[i].get_name() + "\tCost: " + to_string(models[i].cost()) + "\n\n");
                }
                fl_message(s.c_str());
            } else if(a == 8) {
		        add_order->show();
            } else if(a == 9) {
                string s = "";
                for(int i = 0; i < orders.size(); i++) {
                    s += ("(" + to_string(i) + ")\t" + "Order #: " + to_string(orders[i].get_number()) + "\tCustomer: " + orders[i].get_name() + "\tStatus: " + to_string(orders[i].get_status()) + "\tDate: " + orders[i].get_date() + "\n\n");
                }
                fl_message(s.c_str());
            } else if(a == 11) {
		        add_customer->show();
            } else if(a == 12) {
		        add_associate->show();
            }
	}
    private:
	Fl_Menu_Item menuitems[24] = {
		{ "&File", 0, 0, 0, FL_SUBMENU },
 		{ "&Quit", FL_ALT + 'q', (Fl_Callback *)cancel_command },
 		{ 0 },
 		{ "&Add Parts", 0, 0, 0, FL_SUBMENU },
 		{ "&Head", 0, (Fl_Callback *)AddHead },
 		{ "&Torso", 0, (Fl_Callback *)AddTorso },
 		{ "&Battery", 0, (Fl_Callback *)AddBattery },
 		{ "&Motor", 0, (Fl_Callback *)AddMotor },
        { "&Arm", 0, (Fl_Callback *)AddArm },
 		{ 0 },
		{ "&Models", 0, 0, 0, FL_SUBMENU },
 		{ "&Define Model", 0, (Fl_Callback *)AddModel },
 		{ "&Browse Models", 0, (Fl_Callback *)ListModel },
 		{ 0 },
		{ "&Orders", 0, 0, 0, FL_SUBMENU },
		{ "&New Order", 0, (Fl_Callback *)AddOrder },
        { "&List Orders", 0, (Fl_Callback *)ListOrder },
        { "&Manage Order", 0, (Fl_Callback *)ManageOrder },
 		{ 0 },
        { "&Users", 0, 0, 0, FL_SUBMENU },
		{ "&New Customer", 0, (Fl_Callback *)AddCustomer },
        { "&New Associate", 0, (Fl_Callback *)AddAssociate },
 		{ 0 }
	};
        Fl_Window *dialog;
        Fl_Input *m_command;
        Fl_Return_Button *m_create;
        Fl_Button *m_cancel;
        Fl_Text_Buffer *m_buffer;
        Fl_Text_Display *m_text;
};
Main_menu *lib = new Main_menu;

void AddHead(Fl_Widget* w, void* p) { lib->execute(1);}
void AddTorso(Fl_Widget* w, void* p) { lib->execute(2);}
void AddBattery(Fl_Widget* w, void* p) { lib->execute(3);}
void AddMotor(Fl_Widget* w, void* p) { lib->execute(4);}
void AddArm(Fl_Widget* w, void* p) { lib->execute(5);}
void AddModel(Fl_Widget* w, void* p) { lib->execute(6);}
void ListModel(Fl_Widget* w, void* p) { lib->execute(7);}
void AddOrder(Fl_Widget* w, void* p) { lib->execute(8);}
void ListOrder(Fl_Widget* w, void* p) { lib->execute(9);}
void ManageOrder(Fl_Widget* w, void* p) { lib->execute(10);}
void AddCustomer(Fl_Widget* w, void* p) { lib->execute(11);}
void AddAssociate(Fl_Widget* w, void* p) { lib->execute(12);}
void EE(Fl_Widget* w, void* p) { }
void enter_command(Fl_Widget* w, void* p) {
    try {
        int c = stoi(lib->command());
        lib->execute(stoi(lib->command()));
    } catch (std::invalid_argument e) {
        fl_message("Invalid input, please try again.");
    }
}
void cancel_command(Fl_Widget* w, void* p) {
    lib->hide();
}
////////////////////////////////////////

#endif
