#pragma once

#include<unordered_set>

template<typename T>
class Bag{
    public:
        set<T> vertices;
        int id;

        bool operator<(const Bag& o)const{
            return vertices == o.vertices ? id < o.id : vertices < o.vertices;
        }
        //unordered_set<T> vertices;
        Bag():vertices(), id(-1){}

        Bag(set<T> V, int id):vertices(V), id(id){}

        bool operator!=(const Bag<T> w) const {
            return (id != w.id) || (vertices != w.vertices) ;
        }

        bool operator==(const Bag<T> w) const{
            return (id == w.id) && (vertices == w.vertices);
        }

        bool contains(T v) const{
            return vertices.find(v) != vertices.end();
        }

        bool containsAll(set<T> &s){
            if((int)vertices.size() < (int)s.size()) return 0;
            for(auto &v : s)
                if(vertices.find(v) == vertices.end()) return 0;
            return 1;
        }

        bool isEmpty(){
            return vertices.empty();
        }

        int compareTo(Bag<T> o) {
            return id - o.id;
        }
};


// testing code

// unordered_set<int> s;
// s.insert(1);
// s.insert(2);
// s.insert(3);

// unordered_set<int> a;
// a.insert(1);
// a.insert(5);

// Bag<int> test = Bag<int>(s, 2);
// cout << test.containsAll(a) << ' ' << test.containsAll(s) << endl;