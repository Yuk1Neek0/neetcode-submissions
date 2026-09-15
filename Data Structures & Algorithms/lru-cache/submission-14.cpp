struct Node {
    int key, val;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    void remove(Node* node){

    node -> next -> prev = node -> prev;
    node -> prev -> next = node -> next;

}
void insert(Node* node){

    head . next -> prev = node;
    node -> next = head . next;
    node -> prev = &head;
    head . next = node;

}
    int capacity , size = 0;
    Node head = Node(0,0);
    Node tail = Node(0,0);
    unordered_map<int, Node*> mapping;

    LRUCache(int capacity) {
        this -> capacity = capacity;
        head.next = &tail;
        tail.prev = &head;
    }
    
    int get(int key) {
        
        if(mapping.contains(key)){

            remove(mapping[key]);
            insert(mapping[key]);
            return mapping[key] -> val;

        }
        else return -1;

    }
    
    void put(int key, int value) {
        if(mapping.contains(key)){
   
            remove(mapping[key]);
            insert(mapping[key]);
            mapping[key] -> val = value;        

        }else{
            Node* node = new Node(key,value);
            if(size < capacity){

                insert(node);
                mapping[key] = node;
                size++;

            }
            else{

                mapping.erase(tail.prev -> key);
                remove(tail.prev);
                insert(node);
                mapping[key] = node;

            }

        }

    }
};
