struct Node{

    public:
        Node* children[26] = {};
        bool is_end;

        Node(){

            is_end = false;

        }

};
class PrefixTree {
public:

    Node *head = new Node();
    PrefixTree() {
    }
    
    void insert(string word) {
        Node* finger = head;

        for(int i = 0; i < word.length(); i ++){
            
            char c = word[i];
            if(finger -> children[c - 'a']) finger = finger -> children[c - 'a'];
            else{

                Node* node = new Node();
                finger -> children[c - 'a'] = node;
                finger = node;

            }

            if(i == word.length() - 1) finger -> is_end = true;
        }
    }
    
    bool search(string word) {
        
        Node* finger = head;
        for(int i = 0; i < word.length(); i ++){

            char c = word[i];
            if(! finger -> children[c - 'a']) return false;

            if(i == word.length() - 1) return finger -> children[c - 'a'] -> is_end;

            finger = finger->children[c - 'a'];

        }

    }
    
    bool startsWith(string prefix) {
        
        Node* finger = head;
        for(int i = 0; i < prefix.length(); i ++){

            char c = prefix[i];
            if(! finger -> children[c - 'a']) return false;
            finger = finger->children[c - 'a'];

        }

        return true;    

    }
};
