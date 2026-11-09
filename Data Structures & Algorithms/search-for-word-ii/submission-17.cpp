struct Node{
public:
    bool is_end = false;
    vector<Node*> next = vector<Node*>(26,nullptr);

};
void insert(Node* head, string word){

    Node* finger = head;
    for(char c : word){

        if(!finger -> next[c - 'a']){

            Node* node = new Node();
            finger -> next[c - 'a'] = node;
        }
        finger = finger -> next[c - 'a'];

    }
    finger -> is_end = true;

}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* head = new Node();
        for(string word: words) insert(head,word);
        vector<string> res;
        for(int i = 0; i < board.size(); i ++)
            for(int j = 0 ;j < board[0].size(); j++){

                if(head -> next[board[i][j] - 'a']) dfs(head,"",board,i,j,0,res);

            }

        return res;

    }
    void dfs(Node* node, string word, vector<vector<char>>& board, int x, int y, int n, vector<string> & res){
      
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
        if(board[x][y] == '#') return;
        if(!node -> next[board[x][y] - 'a']) return;
        word.push_back(board[x][y]);
        char c = board[x][y];
        board[x][y] = '#';
        if(node -> next[c - 'a'] -> is_end){
            res.push_back(word);
            node -> next[c - 'a']->is_end = false;
        }
        dfs(node -> next[c - 'a'],word,board,x + 1,y,n + 1,res);
        dfs(node -> next[c - 'a'],word,board,x,y + 1,n + 1,res);
        dfs(node -> next[c - 'a'],word,board,x - 1,y,n + 1,res);
        dfs(node -> next[c - 'a'],word,board,x,y - 1,n + 1,res);
        word.pop_back();
        board[x][y] = c;

    }
};
