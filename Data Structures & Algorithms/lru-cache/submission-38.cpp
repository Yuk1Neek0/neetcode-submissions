struct Node{
    Node* prev;
    Node* next;
    int key,val;
    Node(){};
};
class LRUCache {
public:
int capacity;
Node* head = new Node();
Node* tail = new Node();
unordered_map<int,Node*> dict;

    LRUCache(int capacity) {
        this -> capacity = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(dict.contains(key)){

            Node* node = dict[key];
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;

            node -> next = head -> next;
            node -> next -> prev = node;
            node -> prev = head;
            head -> next = node;
            return node -> val;
        }
        else return -1;
        
    }
    
    void put(int key, int value) {
        if(!dict.contains(key)){

            Node* node = new Node();
            node -> key = key;
            node -> val = value;
            dict[key] = node;
            node -> next = head -> next;
            node -> next -> prev = node;
            node -> prev = head;
            head -> next = node;
            if(dict.size() > capacity){

                int erkey = tail -> prev -> key; 
                tail -> prev -> prev -> next = tail;
                tail -> prev = tail -> prev -> prev;
                dict.erase(erkey);

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
