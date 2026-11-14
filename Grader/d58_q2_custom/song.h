#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

    bool operator < (const Song&o) const {
      if(artist != o.artist) return artist > o.artist;
      if(title != o.title) return title > o.title;
      return count > o.count;
    }
    
    bool operator > (const Song&o) const{
      if(count != o.count) return count < o.count;
      if(artist != o.artist) return artist > o.artist;
      return title > o.title;
    }

};

struct Comparator {
    bool operator()(Song a, Song b) const
    {
      return a>b;
    }
};


//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2
CP::priority_queue<Song> pq1;
CP::priority_queue<Song,Comparator> pq2;

#endif
