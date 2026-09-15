class LRUCache {
public:
    class Node{

        public: 
            int key, val;
            Node* prev, *next;
            Node(int k, int v, Node* p, Node* n): key(k),val(v),prev(p),next(n){}

    };
    void insert(Node *node){

        Node * temp = head . next;
        head . next = node;
        node -> prev = &head;
        node -> next = temp;
        temp -> prev = node;

   }
   void remove(Node *node){

    Node* temp = node -> next;
    node -> prev -> next = temp;
    temp -> prev = node -> prev;

   }

    int capacity;
    int size;
    unordered_map<int,Node*> m;
    Node head = Node(0,0,nullptr,nullptr), tail = Node(0,0,nullptr,nullptr);
    LRUCache(int capacity) {
        
        size = 0;
        this -> capacity = capacity;
        head . next = &tail;
        tail . next = &head;
        
    }
    
    int get(int key) {
        
        if(!m.contains(key)) return -1;
        else{

            Node* node = m[key];
            remove(node);
            insert(node);
            return node->val;    
        }

    }
    
    void put(int key, int value) {
        
        if(m.contains(key)){

            Node* node = m[key];
            m[key] -> val = value;
            remove(node);
            insert(node);

        }else{

            if(size < capacity){

                Node* node = new Node(key,value,nullptr,nullptr);
                m[key] = node;
                insert(node);
                size++;

            }
            else{
                
                m.erase(tail.prev -> key);
                remove(tail . prev);
                Node* node = new Node(key,value,nullptr,nullptr);
                m[key] = node;
                insert(node);

            }

        }

    }
};
