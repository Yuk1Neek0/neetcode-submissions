struct Node{
vector<Node*> children = vector<Node*>(26,nullptr);
bool is_end = false;

};
class PrefixTree {
public:
Node * head = new Node();
    PrefixTree() {
        
    }
    
    void insert(string word) {
        Node* finger = head;
        for(int i = 0; i < word.length(); i ++){

            if(finger -> children[word[i] - 'a'] != nullptr){

                finger = finger -> children[word[i] - 'a'];

            }
            else{

                Node* node = new Node();
                finger -> children[word[i] - 'a'] = node;
                finger = finger -> children[word[i] - 'a'];
            }

            if(i == word.length() - 1) finger -> is_end = true;

        }
    }
    
    bool search(string word) {
        Node* finger = head;
        for(int i = 0; i < word.length(); i++){

            if(finger -> children[word[i] - 'a'] == nullptr) return false;
            finger = finger -> children[word[i] - 'a'];

            if(i == word.length() - 1)
                if(!finger -> is_end) return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* finger = head;
        for(int i = 0; i < prefix.length(); i++){

            if(finger -> children[prefix[i] - 'a'] == nullptr) return false;
            finger = finger -> children[prefix[i] - 'a'];

        }
        return true;
    }
};
