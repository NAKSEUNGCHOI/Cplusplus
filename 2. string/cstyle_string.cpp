#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main(){
    char str[80];
    strcpy(str, "Hello ");
    strcat(str, "there");
    cout << strlen(str);
    strcmp(str, "Another");

    char first_name[20] {};
    char last_name[20] {};
    char full_name[50] {};
    char temp[50] {};

    // cout << "Enter your first name: ";
    // cin >> first_name;
    // cout << "Enter your last name: ";
    // cin >> last_name;

    // strcpy(full_name, first_name);
    // strcat(full_name, " ");
    // strcat(full_name, last_name);

    // cout << "Your name is " << full_name << ". Nice to meet you.";

    cout << "Enter your full name: ";
    cin.getline(full_name, 20);
    cout << "Nice to meet you, " << full_name << "." << endl;
    strcpy(temp, full_name);
    cout << temp << endl;
    if(strcmp(temp, full_name) == 0){
        cout << "Their names are same!" << endl;
    }

}