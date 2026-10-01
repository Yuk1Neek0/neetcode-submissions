struct Node{
public:
    Node* child[27] = {};
    bool is_end = false;
    Node(){}
};
class WordDictionary {
public:
    Node* head = new Node();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        
        Node* finger = head;
        for(int i = 0; i < word.length(); i ++){

            char c = word[i];
                if(!finger -> child[c - 'a']){

                    Node * node = new Node();
                    finger -> child[c - 'a'] = node;

                }
                finger = finger -> child[c - 'a'];

            
            if(i == word.length() - 1) finger -> is_end = true;

        }

    }
    
    bool search(string word) {
        return dfs(word,head,0);
    }
    bool dfs(string word,Node* node, int n){

        if(n == word.length()) return node -> is_end;
        char c = word[n];

        if(c == '.'){
            bool res = false;
            for(int i = 0; i < 26; i++){

                if(node -> child[i]) res = res || dfs(word,node -> child[i], n + 1);

            }
            return res;

        }
        if(! node -> child[c - 'a']) return false;
        node = node -> child[c - 'a'];
        return dfs(word,node,n + 1); 

    }
};
