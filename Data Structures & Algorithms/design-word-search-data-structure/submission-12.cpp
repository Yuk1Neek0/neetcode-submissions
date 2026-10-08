struct Node{
public: 
    Node* child[26] = {};
    bool is_end = false;

};
class WordDictionary {
public:

    Node* head = new Node();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* finger = head;
        for(int i = 0; i < word.length(); i++){

            char c = word[i];

            if(!finger -> child[c - 'a']){

                Node* node = new Node();
                finger -> child[c - 'a'] = node;

            }
            finger = finger -> child[c - 'a'];

            if(i == word.length() - 1) finger -> is_end = true;

        }
    }
    
    bool search(string word) {
        
        return dfs(word,head,0);

    }
    bool dfs(string word, Node* node, int n){

        if(n >= word.length()) return node -> is_end;

        if(word[n] == '.'){
            
            for(auto const& child : node -> child){

                if(child && dfs(word,child,n + 1)) return true;

            }
            return false;

        }
        else{

            if(!node -> child[word[n] - 'a']) return false;
            return dfs(word,node -> child[word[n] - 'a'], n + 1);

        }

    }
};
