#include <iostream>
#include <string>

using namespace std;

class Deep{
    private:
        int *data;
    public:
        //Default parameter
        void set_Data_value(int d) { *data = d; }
        int get_data_value() { return *data; }

        // constructor
        Deep(int d);

        // Copy constructor
        Deep(const Deep &source);

        // Destructor
        ~Deep();
};
Deep::Deep(int d) {
    data = new int;
    *data = d;
}
// copy constructor
Deep::Deep(const Deep &source) 
    : Deep {*source.data} {
    cout << "Copy constructor - deep copy " << endl;
}
Deep::~Deep() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

// Copy
void display_deep(Deep s){
    cout << s.get_data_value() << endl;
}

int main(){

    Deep obj1 {100};
    display_deep(obj1);

    Deep obj2 {obj1};
    obj2.set_Data_value(1000);

    //0x61c60
    //61960
    return 0;

}