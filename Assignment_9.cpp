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
string hex_to_binary(const string&);
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
//
//lets set up the parse input function to determine if the input is hex or decimal
//
bool parse_input(const string& input) {
    bool is_hex = false;
    string lowered = input;
    transform(lowered.begin(), lowered.end(), lowered.begin(), 
                [](unsigned char c){ return tolower(c); });
    if (lowered.find("0x") == 0) 
        is_hex = true;
    return is_hex;
}
//
//function to convert hex to binary
//
string hex_to_binary(const string& hex) {
    string newhex = hex;
    if (newhex.find("0x") == 0 || newhex.find("0X") == 0) 
        newhex = newhex.substr(2);
    long long decimal = stoll(newhex, nullptr, 16);
    string binary = decimal_to_binary(to_string(decimal));
    cout << "Your hex number " << hex << " in binary is: " << binary << endl;
    return binary;
}
//
//function to convert decimal to binary
//
string decimal_to_binary(const string& decimal_str) {
    long long decimal = stoll(decimal_str);
    if (decimal == 0) return "0";
    string binary = "";
    while (decimal > 0) 
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    return binary;
}
//
//conversion to binary for both hex and decimal
//
string convert_to_binary(const string& input) {
    if (is_hex) 
        return hex_to_binary(input);
    else 
        return decimal_to_binary(input);    
}
//
//testing function... please work 
//
// ...existing code...
void test(){
    while (true) {
        cout << "Your input: " << user_input << '\n';
        cout << "Your number in Hex: " << (is_hex ? "Yes" : "No") << '\n';
        cout << "Your number in Binary is: " << final_output << '\n';
        cout << "Would you like to run another test? (y/n): ";
        string go_again;
        getline(cin, go_again);
        if (go_again == "y" || go_again == "Y") {
            run();
            continue;
        }
        cout << "Thank you for using the converter. Goodbye!" << endl;
        break;
    }
}
//
//Its the end of the line... main function
//
int main() {
    run();
    test();
    return 0;
}