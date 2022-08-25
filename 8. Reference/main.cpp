#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int num {100};
    int &ref {num};

    std::cout << "===================================" << std::endl;
    std::cout << "num: " << num << std::endl;
    std::cout << "&ref: " << ref << std::endl;

    std::cout << "===================================" << std::endl;
    num = 200;
    std::cout << "num: " << num << std::endl;
    std::cout << "&ref: " << ref << std::endl;

    std::cout << "===================================" << std::endl;
    ref = 300;
    std::cout << "num: " << num << std::endl;
    std::cout << "&ref: " << ref << std::endl;

    std::cout << "===================================" << std::endl;
    vector <string> stooges {"Larry", "Nakseung", "Choi"};
    for(auto val: stooges){
        val = "Funny";
    }
    for(auto const val: stooges){
        cout << val << " "; 
    }
    std::cout << "\n===================================" << std::endl;
    for(auto &val: stooges){
        val = "Funny";
    }
    for(auto const val: stooges){
        cout << val << " "; 
    }
    std::cout << "\n===================================" << std::endl;
    

    return 0;
}