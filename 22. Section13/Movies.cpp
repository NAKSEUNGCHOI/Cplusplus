#include "Movies.h"
#include "iostream"

// constructor
Movies::Movies(){

}
// deconstructor
Movies::~Movies(){

}
bool Movies::add_movie(string name, string rating, int watched){
    for(const Movie &movie: movies){
        if(movie.get_name() == name){
            cout << "The Movie has already been added: " << name << endl;
            return false;
        }
    }
    Movie temp {name, rating, watched};
    movies.push_back(temp);
    return true;
}
bool Movies::increment_watched(string name){
    for(Movie &movie: movies){
        if(movie.get_name() == name){
            movie.increment_watched();
            return true;
        }
    }
    cout << "The Movie is not on the list: " << name << endl;
    return false;
}
void Movies::display() const {
    if(movies.size() == 0){
        cout << "Sorry, no movies to display\n" << endl;
    }else{
        cout << "============================================" << endl;
        for(const Movie &movie: movies){
            movie.display_movie();
        }
        cout << "============================================" << endl;
    }
}