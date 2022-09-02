#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person{
    std::string name;
    int age;
    public:
        Person() = default;                                             //no-args constructor
        Person(std::string name, int age)                               //two-args constructor
            : name{name}, age{age} {
            
        }
        bool operator<(const Person &rhs) const{                        // overloaded operator <
            return this->age < rhs.age;
        }
        bool operator==(const Person &rhs) const{                       // overloaded operator ==
            return (this->name == rhs.name && this->age == rhs.age);
        }
};

void find_test(){
    std::cout << "\n=====================================================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5};

    auto loc = std::find(std::begin(vec), std::end(vec), 3);
    if(loc != std::end(vec))
        std::cout << "Found the number: " << *loc << std::endl;
    else
        std::cout << "Couldn't find the number" << std::endl;

    std::list<Person> players{
        {"Choi", 33},
        {"Kristal", 28},
        {"Vikram", 32}
    };
    auto loc1 = std::find(players.begin(), players.end(), Person{"Choi", 33});
    if(loc1 != players.end())
        std::cout << "Found Choi" << std::endl;
    else
        std::cout << "Couldn't find Choi" << std::endl;

}
void count_test(){
    std::cout << "\n=====================================================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1};

    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurences found" << std::endl;
}
void count_if_test(){           // count if the number condition matches.
    std::cout << "\n=====================================================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1, 100};

    int num = std::count_if(vec.begin(), vec.end(), [](int x){ return x % 2 == 0; });
    std::cout << num << " even numbers found" << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [](int x){ return x % 2 != 0; });
    std::cout << num << " even numbers found" << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [](int x){ return x >= 5; });
    std::cout << num << " numbers are greater than 5" << std::endl;
}
void replace_test(){                        // replace 1 to 100.
    std::cout << "\n=====================================================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1};

    for(auto i: vec)
        std::cout << i << " ";
    std::cout << std::endl;
    
    std::replace(vec.begin(), vec.end(), 1, 100);
    for(auto i: vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

void all_of_test(){
    std::cout << "\n=====================================================" << std::endl;
    std::vector<int> vec {1, 3, 5, 7, 9, 1, 3, 13, 19, 5};
    if(std::all_of(vec.begin(), vec.end(), [](int x) { return x > 10; }))
        std::cout << "All the elements are > 10" << std::endl;
    else
        std::cout << "Not all the elemets are > 10" << std::endl;
    
    if(std::all_of(vec.begin(), vec.end(), [](int x) { return x < 20; } ))
        std::cout << "All the elements are < 20" << std::endl;
    else
        std::cout << "Not all the elemets are < 20" << std::endl;
}
void string_transform_test(){
    std::cout << "\n=====================================================" << std::endl;

    std::string str1 {"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;

    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper); //:: means global scope; using toupper in global scope.
    std::cout << "After transform: " << str1 << std::endl;
}

int main(){
    //find_test();
    //count_test();
    //count_if_test();
    //replace_test();
    //all_of_test();
    string_transform_test();

    return 0;
}