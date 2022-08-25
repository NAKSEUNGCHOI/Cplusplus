#include <iostream>

using namespace std;

void print_array(const int arr[], size_t size);
void set_array(int arr[], size_t size, int value = 5);

int main(){
    int test_scores[] {100, 95, 97, 92, 87};
    int size = sizeof(test_scores)/sizeof(int);
    cout << "===================================" << endl;
    print_array(test_scores, size);
    set_array(test_scores, size);
    cout << "===================================" << endl;
    print_array(test_scores, size);

}

void print_array(const int arr[], size_t size){
    for(size_t i {0}; i < size; i++) cout << arr[i] << endl;
}
void set_array(int arr[], size_t size, int value){
    for(size_t i {0}; i < size; i++) arr[i] = value;
}