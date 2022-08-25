#ifndef _MOVIE_H_
#define _MOVIE_H_

using namespace std;

#include <string>

class Movie{
    private:
        string name;
        string rating;
        int watched;
    public:
        string get_name() const { 
            return name; 
        }
        void set_name(string name) { 
            this->name = name; 
        }
        string get_rating() const { 
            return rating; 
        }
        void set_rating(string rating) { 
            this->rating = rating; 
        }
        int get_watched() const { 
            return watched; 
        }
        void set_watched(int watched) { 
            this->watched = watched; 
        }
        void increment_watched(){
            ++watched;
        }
        void display_movie() const;

        // constructor
        Movie(string name, string rating, int watched);

        // copy constructor
        Movie(const Movie &source);

        // deconstructor
        ~Movie();

};

#endif //_MOVIE_H_ 