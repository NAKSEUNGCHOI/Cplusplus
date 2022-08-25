#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> temperature (3, 100);
    vector <int> test_scores {100, 200, 300, 400, 90};
    for(int i = 0; i < int(test_scores.size()); i++) cout << "Test scores: " << test_scores.at(i) << "." << endl;
    test_scores.push_back(100);
    for(int i = 0; i < int(test_scores.size()); i++) cout << "Test scores: " << test_scores.at(i) << "." << endl;
    for(int i = 0; i < int(temperature.size()); i++) cout << "Temperature: " << temperature.at(i) << "." << endl;
    vector <vector<int>> movie_ratings{
        {1, 2, 3, 4},
        {1, 2, 3, 5},
        {1, 3, 4, 5}
    };

    vector <int> vector1;
    vector <int> vector2;
    vector1.push_back(10);
    vector1.push_back(20);
    vector2.push_back(100);
    vector2.push_back(200);

    vector <vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

    vector1.at(0) = 1000;
    cout << vector1.at(0) << endl; 

    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

    for(auto test_score: test_scores){
        cout << test_score << " ";
        cout << sizeof(test_score) << " " << test_scores.size() << endl;
        
    }
    int i {1};
    cout << "====================================================" << endl;
    while(i<=5){
        cout << ++i << endl;
    }

}