#include "util.h"

class LRUCache {
    using Node = pair<int, int>;
    using List = list<Node>;
    using ListPtr = typename List::iterator;

    using Map = unordered_map<int, ListPtr>;
    using MapPtr = Map::iterator;

public:
    LRUCache(int capacity):sizeLimit(capacity) {

    }
    
    int get(int key) {
        if(keyMap_.count(key)) {
            moveFront(key);
            return keyMap_[key]->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (keyMap_.count(key)) {
            moveFront(key);
            valList_.front().second = value;
        }
        else {
            resize();
            // insert new key
            valList_.push_front({key, value});
            keyMap_[key] = valList_.begin();
        }
    }
private:
    void resize() {
        if(valList_.size() == sizeLimit) {
            auto back = valList_.back();
            valList_.pop_back();
            keyMap_.erase(back.first);
        }
    }

    void moveFront(int key) {
        auto it = keyMap_[key];
        auto val = it->second;
        valList_.erase(it);
        keyMap_.erase(key);
        put(key, val);
    }
    const int sizeLimit;
    Map keyMap_;
    List valList_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */