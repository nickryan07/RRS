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

//Fl_Double_Window* create_part();
using namespace std;
////////////////////////////////////////
string menu = R"(
------ Main Menu ------

//TODO

(1) Create new parts.
(2) Define new models.
(3) Browse existing models.
(4) Add a new Customer.
(5) Add a new Sales Associate.
(6) Create a new order.
(7) List current Customers.
(8) List current Sales Associates.
(0) Quit.
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
        void push_head() {Head *h = new Head(atof(power().c_str()), name(), atoi(part_num().c_str()), description(), atof(cost().c_str()));
            heads.push_back(*h);
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
            //b_torso->align(FL_ALIGN_LEFT);

            /*b_power = new Fl_Input(125, 175, 150, 25, "Available power: ");
            b_power->align(FL_ALIGN_LEFT);

            b_energy = new Fl_Input(125, 215, 150, 25, "Max Energy: ");
            b_energy->align(FL_ALIGN_LEFT);*/

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
        void push_model() {
            Robot_models *m = new Robot_models(name(), atoi(part_num().c_str()), atof(cost().c_str()),
                torsos[atoi(torso().c_str())], motors[atoi(motor().c_str())], arms[atoi(arm().c_str())],
                batteries[atoi(battery().c_str())], heads[atoi(head().c_str())]);
            models.push_back(*m);
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

/* MENU BAR */
Fl_Menu_Bar *menubar;
void AddHead(Fl_Widget* w, void* p);
void AddTorso(Fl_Widget* w, void* p);
void AddBattery(Fl_Widget* w, void* p);
void AddMotor(Fl_Widget* w, void* p);
void AddArm(Fl_Widget* w, void* p);
void AddModel(Fl_Widget* w, void* p);
void ListModel(Fl_Widget* w, void* p);
void Help(Fl_Widget* w, void* p);
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

            //m_command = new Fl_Input(100, 480, 270, 25, "Command: ");
            //m_command->align(FL_ALIGN_LEFT);

            //m_create = new Fl_Return_Button(255, 510, 80, 25, "Ok");
            //m_create->callback((Fl_Callback *)enter_command, 0);

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
                    s += ("(" + to_string(i) + ")\t" + "Name: " + models[i].get_name() + "\tCost: " + to_string(models[i].cost()) + "\n");
                }
                fl_message(s.c_str());
            }/* else if(a == 99) {
		library.easter_egg();
        }*/
	}
    private:
	Fl_Menu_Item menuitems[18] = {
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
 		{ "&List Models", 0, (Fl_Callback *)ListModel },
 		{ 0 },
		{ "&Other", 0, 0, 0, FL_SUBMENU },
		{ "&Help", 0, (Fl_Callback *)Help },
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
void Help(Fl_Widget* w, void* p) { lib->execute(9);}
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
