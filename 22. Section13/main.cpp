#include <iostream>
#include <string>
#include "Movies.h"
#include "Movies.cpp"
#include "Movie.h"
#include "Movie.cpp"

using namespace std;

//function prototypes
void add_movie(Movies &movies, string name, string rating, int watched);
void increment_watched(Movies &movies, string name);

int main(){

    Movies my_movies;

    my_movies.display();

    add_movie(my_movies, "Big", "PG-13", 2);
    add_movie(my_movies, "Star Wars", "PG", 5);
    add_movie(my_movies, "Cinderella", "PG", 7);

    my_movies.display();

    add_movie(my_movies, "Cinderella", "PG", 7);
    add_movie(my_movies, "Ice Age", "PG", 12);

    my_movies.display();

    increment_watched(my_movies, "XXX");


    return 0;
}

void add_movie(Movies &movies, string name, string rating, int watched){
    if(movies.add_movie(name, rating, watched)){
        cout << name << " added." << endl;
    }else{
        cout << name << " already exist" << endl;
    }
}
void increment_watched(Movies &movies, string name){
    if(movies.increment_watched(name)){
        cout << name << " watch incremented." << endl;
    }else{
        cout << name << " not found." << endl;
    }
}