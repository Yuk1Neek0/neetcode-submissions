struct Node{
public:
Node* next, *prev;
int key,val;
Node(){};
Node(int key, int val){

this -> key = key;
this -> val = val;

}
};
class LRUCache {
public:
Node* head = new Node();
Node* tail = new Node();
int capacity;
unordered_map<int,Node*> dict;
    LRUCache(int capacity) {
        head -> prev = nullptr;
        tail -> next = nullptr;
        head -> next = tail;
        tail -> prev = head;
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(!dict.contains(key)) return -1;
        Node* node = dict[key];

        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        
        node -> next = head -> next;
        node -> next -> prev = node;
        node -> prev = head;
        head -> next = node;
        return node -> val;
    }
    
    void put(int key, int value) {
        if(!dict.contains(key)){

            Node* node = new Node(key,value);
            dict[key] = node;
            node -> next = head -> next;
            node -> next -> prev = node;
            node -> prev = head;
            head -> next = node;

            if(dict.size() > capacity){
                Node * lru = tail -> prev;
                tail -> prev -> prev -> next = tail;
                tail -> prev = tail -> prev -> prev;
                dict.erase(lru -> key);

            }

        }
        else{

            Node* node = dict[key];
            node -> val = value;
            node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        
        node -> next = head -> next;
        node -> next -> prev = node;
        node -> prev = head;
        head -> next = node;

        }
    }
};
