struct Node{
public:
    pair<int,int> val;
    Node* next;
    Node* prev;

    Node(){next = nullptr; prev = nullptr;};
};
class LRUCache {
public:
    Node head,tail;
    int capacity, size;
    unordered_map<int,Node*> dict;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head.next = &tail;
        head.prev = nullptr;
        tail.next = nullptr;
        tail.prev = &head;
        size = 0;
    }
    
    int get(int key) {
        if(!dict.contains(key)) return -1;

        Node* node = dict[key];
        
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        node -> next = head.next;
        head. next -> prev = node;
        head.next = node;
        node -> prev = &head;
        return node -> val.second;
         
    }
    
    void put(int key, int value) {
        if(!dict.contains(key)){

            Node* node = new Node();
            node -> val = {key,value};

            dict[key] = node;
            node -> next = head.next;
        head. next -> prev = node;
        head.next = node;
        node -> prev = &head;
            size ++;
            if(size > capacity){

                dict.erase(tail .prev -> val.first);
                tail.prev -> prev -> next = &tail;
                tail.prev = tail.prev -> prev;
                size--;

            }

        }
        else{

            Node* node = dict[key];
            node -> val.second = value;
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;
            node -> next = head.next;
        head. next -> prev = node;
        head.next = node;
        node -> prev = &head;

        }
    }
};
