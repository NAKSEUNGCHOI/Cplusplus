#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_ref1(int &num);
void pass_by_ref2(string &s);
void pass_by_ref3(vector <string> &v);
void print_vector(const vector <string> &v);

int main(){
    int num {10};
    int another_num {20};

    cout << "Before: " << num << endl;
    pass_by_ref1(num);
    cout << "After: " << num << endl;

    string name {"Nakseung"};
    
    cout << "Before: " << name << endl;
    pass_by_ref2(name);
    cout << "After: " << name << endl;

    vector <string> hey = {"Larry", "Moe", "Boogie"};
    print_vector(hey);
    pass_by_ref3(hey);
    print_vector(hey);

    return 0;
}

void pass_by_ref1(int &num){
    num = 1000;
}
void pass_by_ref2(string &s){
    s = "Changed";
}
void pass_by_ref3(vector <string> &v){
    v.clear();
    v.push_back("Hey");
}
void print_vector(const vector <string> &v){
    for(auto s: v) cout << s << endl;
}
