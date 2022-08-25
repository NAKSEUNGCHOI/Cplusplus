#ifndef _MOVIES_H_
#define _MOVIES_H_

using namespace std;

#include <string>
#include <vector>
#include "Movie.h"

class Movies{
    private:
        vector <Movie> movies;
    public:
        // constructor
        Movies();
        // deconstructor
        ~Movies();

        // methods
        bool add_movie(string name, string rating, int watched);
        bool increment_watched(string name);
        void display() const;
};

#endif //_MOVIE_H_ 