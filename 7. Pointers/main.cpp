#include <iostream>
#include <string>
#include <vector>

using namespace std;

int *create_array(size_t, int);
void print_array(const int *const array, size_t size);

int main(){
    int scores[] {100, 98, 89};
    int *score_ptr {scores};
    cout << "Value of scores: " << scores << endl; // address of the first array element.
    cout << "Value of deferencing scores: " << *scores << endl;

    cout << "value of score_ptr: " << score_ptr << endl;
    cout << "value of deferenced score_ptr: " << *score_ptr << endl;

    cout << *score_ptr << endl;
    cout << *(score_ptr + 1) << endl;
    cout << *(score_ptr + 2) << endl;
    cout << "=======================================" << endl;
    while(*score_ptr != 89){
        cout << *score_ptr++ << endl;
    }

    cout << "=======================================" << endl;
    int *my_array {nullptr};
    size_t size {};
    int init_value {};

    cout << "How many integers would you like to allocate? " << endl;
    cin >> size;
    cout << "Enter an initial value: " << endl;
    cin >> init_value;

    my_array = create_array(size, init_value);

    print_array(my_array, size);
    delete [] my_array;
    cout << "my_array freed up!" << endl;
    print_array(my_array, size);
    cout << "=======================================" << endl;
    vector <string> stooges {"Larry", "Choi", "Frank", "Kristal"};
    for(auto const str: stooges) cout << str << " ";
    cout << endl;
    for(auto &str: stooges) str = "Choi"; // How to change vector using range-based for loop. 
    for(auto const str: stooges) cout << str << " ";
    cout << endl;

    return 0;
}
void print_array(const int *const array, size_t size){
    for(size_t i {0}; i < size; i++) cout << *(array + 1) << " ";
    cout << endl;
}
int *create_array(size_t size, int init_value = 0){
    int *new_storage {nullptr};
    new_storage = new int[size];
    for(size_t i {0}; i < size; i++) *(new_storage + i) = init_value;
    return new_storage;
}