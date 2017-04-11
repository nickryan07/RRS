#ifndef _UTILS
#define _UTILS 17

#include <string>
#include <iostream>
#include <climits>

using namespace std;

void str_clear() {
    if (cin.fail()) {
        cin.clear();
    }
    cin.ignore(INT_MAX, '\n');
}

string get_full_line(string input) {
    string output;
    cout << input;
    getline(cin, output);
    return output;
}

int get_int(string input) {
    int output = 0;
    while (true) {
        cout << input;
        cin >> output;
        bool success = cin.good();
        str_clear();
        if (success) {
            return output;
        }
        cerr << "### Not an integer!" << endl;
    }
}

int get_int_range(string input, int min, int max) {
    int output = -1;
    while (true) {
        output = get_int(input);
        if (min <= output && output <= max) {
            return output;
        }
        cerr << "### Integer must be between " << min << " and " << max << "!\n";
    }
}

double get_double(string input) {
    double output = 0.0;
    while (true) {
        cout << input;
        cin >> output;
        bool success = cin.good();
        str_clear();
        if (success) {
            return output;
        }
        cerr << "### Not a number!" << endl;
    }
}
/* INPUT/OUTPUT STREAMING METHODS */
void str_clear(ifstream& is) {
    if (cin.fail()) {
        cin.clear();
    }
    cin.ignore(INT_MAX, '\n');
}

string get_full_line(ifstream& is) {
    string output = "";
    getline(is, output);
    return output;
}

int get_int(ifstream& is) {
    int output = 0;
    is >> output;
    str_clear(is);
    return output;
}

double get_double(ifstream& is) {
    double output = 0.0;
    is >> output;
    str_clear(is);
    return output;
}


#endif
