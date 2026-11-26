struct Node{
Node* next, *prev;
int key,val;
Node(){};
Node(int key, int val){this -> key = key; this -> val = val;};

};
void removeNode(Node * node){

    node -> prev -> next = node -> next;
    node -> next -> prev = node -> prev;

}
void addHead(Node* head,Node* node){

    node -> next = head -> next;
    node -> prev = head;
    node -> next -> prev = node;
    head -> next = node;

}
class LRUCache {
public:
Node* head = new Node();
Node* tail = new Node();
int capacity;
unordered_map<int,Node*> dict;
    LRUCache(int capacity) {
        head -> next = tail;
        head -> prev = nullptr;
        tail -> next = nullptr;
        tail -> prev = head;
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(!dict.contains(key)) return -1;
        Node *node = dict[key];
        removeNode(node);
        addHead(head,node);
        return node -> val;

    }
    
    void put(int key, int value) {
        
        if(!dict.contains(key)){

            Node* node = new Node(key,value);
            dict[key] = node;
            addHead(head,node);
            if(dict.size() > capacity){
                
                key = tail -> prev -> key;
                removeNode(tail -> prev);
                dict.erase(key);

            } 

        }
        else{

            Node* node = dict[key];
            node -> val = value;
            removeNode(node);
            addHead(head,node);

        }

    }
};
