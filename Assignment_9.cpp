#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;
//
// lets set up the global variables we will use boolean to determine if the input was hex or not
//globals
string user_input;
string final_output;
bool is_hex;
//
//Lets set up our functions
//main function to collect the user input
string main_input();
string decimal_to_binary(const string&);
string hex_to_decimal(const string&);
string convert_to_binary(const string&);
void   run();
void   test();
bool   parse_input(const string&);
//
//alignment of function definitions
//
void run() {
    user_input = main_input();
    final_output = convert_to_binary(user_input);
    is_hex = parse_input(user_input);
    }
//
//time to set up our main function
//
string main_input() {
    string input;
    cout << "Please enter a number (decimal or hex with 0x prefix): ";
    getline(cin, input);
    return input;
}