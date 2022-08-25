#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Move{
    private:
        int *data;
    public:
        //Default parameter
        void set_Data_value(int d) { *data = d; }
        int get_data_value() { return *data; }

        // constructor
        Move(int d);

        // Copy constructor
        Move(const Move &source);

        // Move constructor
        Move(Move &&source);

        // Destructor
        ~Move();
};
Move::Move(int d) {
    data = new int;
    *data = d;
}
// copy constructor
Move::Move(const Move &source) 
    : Move{*source.data} {
    cout << "Copy constructor - deep copy " << endl;
}
Move::Move(Move &&source)
    : data{source.data} {
        source.data = nullptr;
}
Move::~Move() {
    if(data != nullptr)
        cout << "Destructor freeing data: " << *data << endl;
    else
        cout << "Destructor freeing data for nullptr" << endl;
    delete data;
}

// Copy
void display_deep(Move s){
    cout << s.get_data_value() << endl;
}

int main(){

    vector<Move> vec;
    vec.push_back(Move{10});
    vec.push_back(Move{20});
    
    return 0;

}