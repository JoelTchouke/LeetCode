class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator>  cache;
    list<pair<int, int>> history;
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }

    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            auto it = cache[key];
            history.splice(history.begin(), history, it);
            return it -> second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            auto it = cache[key];
            it->second = value,
            history.splice(history.begin(), history, it);
            return;
        }

        if(cache.size() >= capacity)
        {
            int keyToRemove = history.back().first;
            cache.erase(keyToRemove);
            history.pop_back();
        }

        history.push_front({key, value});
        cache[key] = history.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */