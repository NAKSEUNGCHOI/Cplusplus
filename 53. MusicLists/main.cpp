#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song{
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
    public:
        Song() = default;
        Song(std::string name, std::string artist, int rating) : name{name}, artist{artist}, rating{rating} {}
        std::string get_name() const {
            return this->name;
        }
        std::string get_artist() const {
            return this->artist;
        }
        int get_rating() const {
            return this->rating;
        }
        bool operator<(const Song &rhs) const{
            return this->name < rhs.name;
        }
        bool operator==(const Song &rhs) const{
            return this->name == rhs.name;
        }
};

std::ostream &operator<<(std::ostream &os, const Song &s){
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu(){
    std::cout << "\nF - Play First Song";
    std::cout << "\nN - Play Next Song";
    std::cout << "\nP - Play Previous Song";
    std::cout << "\nA - Add and play a new Song at current location";
    std::cout << "\nL - List the current Playlist";
    std::cout << "\n=====================================================================";
    std::cout << "\nEnter a selection (Q to quit): ";
}
void play_current_song(const Song &song){
    std::cout << "Playing: " << std::endl;
    std::cout << song << std::endl;
}
void display_playlist(const std::list<Song> &playlist, const Song &current_song){
    for(const Song &song: playlist){
        std::cout << song << std::endl;
    }
    std::cout << "Current song: " << std::endl;
    std::cout << current_song << std::endl;
}

int main(){
    std::list<Song> playlist{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroon 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}
    };

    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    char input {};
    do{
        display_menu();
        std::cin >> input;
        input = std::toupper(input);
        if(input == 'F' || input == 'f'){
            std::cout << "Playing first song" << std::endl;
            current_song = playlist.begin();
            play_current_song(*current_song);
        }else if(input == 'N' || input == 'n'){
            std::cout << "Playing next song" << std::endl;
            current_song++;
            if(current_song == playlist.end()){
                std::cout << "Wrapping to start of playlist" << std::endl;
                current_song = playlist.begin();
            }
            play_current_song(*current_song);
        }else if(input == 'P' || input == 'p'){
            std::cout << "Playing previous song" << std::endl;
            if(current_song == playlist.begin()){
                std::cout << "Wrapping to end of playlist" << std::endl;
                current_song = playlist.end();
            }
            current_song--;
            play_current_song(*current_song);
        }else if(input == 'A' || input == 'a'){
            std::string name, artist;
            int rating;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Enter the name of the song: ";
            getline(std::cin, name);
            std::cout << "Enter the name of the artist: ";
            getline(std::cin, artist);
            std::cout << "Enter your rating: (1-5)";
            std::cin >> rating;
            playlist.insert(current_song, Song{name, artist, rating});
            current_song--;
            play_current_song(*current_song);
        }else if(input == 'L' || input == 'l'){
            for(const auto &s: playlist){
                std::cout << s << std::endl;
            }
        }
    }while(input != 'Q');
    std::cout << "Thanks for listening!" << std::endl;

    return 0;
}