#include <iostream>
#include "Movie.h"

// constructor
Movie::Movie(string name, string rating, int watched)
    : name(name), rating(rating), watched(watched) {
}
// copy constructor
Movie::Movie(const Movie &source)
    : Movie{source.name, source.rating, source.watched} {
}
// deconstructor
Movie::~Movie(){
}
// display function
void Movie::display_movie() const {
    cout << name << ", " << rating << ", " << watched << endl;
}