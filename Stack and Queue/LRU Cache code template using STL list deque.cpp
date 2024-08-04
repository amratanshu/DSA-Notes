class LRUCache {
public:
    int sz;
    map<int , pair<int, list<int>::iterator>> mp;
    list<int> deque;



    LRUCache(int capacity) {
        sz = capacity;
    }
    
    //if key is present return the value and put it infront of the deque/cache
    int get(int key) {

       
        if(mp.find(key) != mp.end()){

            auto it = mp[key].second;
            int value = mp[key].first;

            deque.erase(it);
            deque.push_front(key);
            mp[key].second = deque.begin();
            return value;
        }
        return -1;
        
    }
    
    // if key is present -> update the value and put it  infront of deque/cache
    // if key is not present -> if capacity == size -> remove last element from cache
    //                       -> if capacity < size -> add the element and put it infront of cache
    void put(int key, int value) {

        if(mp.find(key) != mp.end()){

           
            auto it = mp[key].second;          
            deque.erase(it);
            deque.push_front(key);
            mp[key].second = deque.begin();
            mp[key].first = value;

        }
        else{

            if(deque.size() == sz){
            
                int lru = deque.back();
                mp.erase(lru);
                deque.pop_back();           
                deque.push_front(key); 
                mp[key].first = value;
               mp[key].second = deque.begin();
            }
            else{
          
                deque.push_front(key);
                mp[key].first = value;
                mp[key].second = deque.begin();

            }


        }
       

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */