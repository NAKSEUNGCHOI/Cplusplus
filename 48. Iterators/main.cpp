#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

void display(const std::vector<int> &vec){
    std::cout <<"[";
    for(auto const &i: vec){
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\n=======================================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};
    auto it = nums1.begin();                            // point to 1
    std::cout << *it << std::endl;

    it++;                                               // point to 2
    std::cout << *it << std::endl;

    it += 2;                                            // point to 4
    std::cout << *it << std::endl;

    it -= 2;                                            // point to 2
    std::cout << *it << std::endl;

    it = nums1.end() - 1;                               // pointer to 5
    std::cout << *it << std::endl;
}

void test2() {
    std::cout << "\n=======================================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};
    std::vector<int>::iterator it = nums1.begin();                           // point to 1
    while(it != nums1.end()){
        std::cout << *it << std::endl;
        it++; 
    }
    it = nums1.begin();
    while(it != nums1.end()){
        *it = 0;
        it++;
    }
    display(nums1);
}

void test3() {
    std::cout << "\n=======================================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};
    std::vector<int>::const_iterator it = nums1.begin();                           // point to 1
    //auto it = nums.cbegin(); // this is equivalent to the line right above.
    while(it != nums1.end()){
        std::cout << *it << std::endl;
        it++; 
    }
    it = nums1.begin();
    while(it != nums1.end()){
        //*it = 0;
        it++;
    }
    display(nums1);
}

void test4() {
    std::cout << "\n=======================================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};
    auto it = nums1.rbegin();
    while(it != nums1.rend()){
        std::cout << *it << std::endl;
        it++; 
    }
    std::cout << "\n=======================================" << std::endl;
    std::list<std::string> names {"Choi", "Kristal", "James"};
    auto it1 = names.crbegin();
    std::cout << *it1 << std::endl;
    it1++;
    std::cout << *it1 << std::endl;
    it1++;
    std::cout << *it1 << std::endl;
    it1 = names.crbegin();
    std::cout << *it1 << std::endl;

    std::cout << "\n=======================================" << std::endl;
    std::map<std::string, std::string> favorites {
        {"Choi", "C++"},
        {"Kristal", "Education"},
        {"James", "Tutorial"}
    };
    auto it3 = favorites.begin();
    while(it3 != favorites.end()){
        std::cout << it3->first << " " << it3->second << std::endl;
        it3++;
    }
    
}

void test5() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto start = vec.begin() + 2;
    auto finish = vec.end() - 3;
    while(start != finish){
        std::cout << *start << std::endl;
        start++;
    }
    
}

int main(){
    //test1();
    //test2();
    //test3();
    //test4();
    test5();

    return 0;
}