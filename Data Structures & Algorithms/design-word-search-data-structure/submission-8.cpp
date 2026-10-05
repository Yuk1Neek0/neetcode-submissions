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
        Node *finger = head;

        for(int i = 0; i < word.size(); i ++){

            char c = word[i];

            if(!finger -> child[c - 'a']){

                Node* node = new Node();
                finger -> child[c - 'a'] = node;

            }

            finger = finger -> child[c - 'a'];
            if(i == word.size() - 1) finger -> is_end = true;
        
        }
    }
    
    bool search(string word) {

        return dfs(word,head,0);

    }

    bool dfs(string word, Node *node, int n){

        if(n == word.size()){

            if(node -> is_end) return true;
            else return false;

        }
        if(word[n] == '.'){

            bool is_find = false;
            for(int i = 0; i < 26; i ++){

                if(node -> child[i]) is_find = is_find || dfs(word,node -> child[i],n + 1); 

            }

            return is_find;

        }
        else{

            if(!node -> child[word[n] - 'a']) return false;
            else return dfs(word,node -> child[word[n] - 'a'],n + 1);

        }

    }
};
