#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

int main(){
    // examples
    string s1;
    string s2 {"Nakseung"};
    string s3 {s2};
    string s4 {"Nakseung", 3};
    string s5 {s3, 0 , 2};  // 0 <= s3 < 2
    string s6 (3, 'X');

    string part1 {"C++"};
    string part2 {"is a powerful"};

    string sentence;

    sentence = part1 + " " + part2 + " language.";
    cout << sentence << endl;
    sentence.at(0) = 'B';
    cout << sentence[0];
    cout << sentence.at(1);
    cout << sentence.at(2) << endl;
    cout << sentence.substr(0, 4) << endl; // starting 0, include 4 characters.
    cout << sentence.find("B++") << endl;
    cout << sentence.erase(0, 4) << endl;
    sentence += " C++";
    cout << sentence << endl;

    cout << "Enter your name: " << endl;
    getline(cin, sentence);
    cout << "Your name is " << sentence << endl;

    s1 = "The secret word is Boo";
    string word {};
    cout << "Enter the word to find: ";
    cin >> word;

    size_t position = s1.find(word);
    if(position != string::npos){
        cout << "Found! " << word << " at position: " << position << endl;
    }else{
        cout << "Sorry, " << word << " not found" << endl;
    }

    return 0;
}