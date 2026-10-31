struct Node {
    Node* next[26] = {};
    string word= "";
};
void insert(Node* root, const string& w){

    Node* cur = root;
    for(char c : w){

        int i = c - 'a';
        if(!cur -> next[i]){

            Node* node = new Node();
            cur -> next[i] = node;

        }
        cur = cur -> next[i];

    }
    cur -> word = w;


}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node * head = new Node();
        Node* finger = head;
        for(string w : words) insert(head,w);
        vector<string> res;
        for(int i = 0; i < board.size(); i ++)
            for(int j = 0; j < board[0].size(); j ++)
                dfs(board,res,i,j,head);
        return res;

    }
    void dfs(vector<vector<char>>& board, vector<string> &res, int x,int y, Node* node){

        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return;
        if(!node -> next[board[x][y] - 'a']) return;
        if(board[x][y] == '#') return;
        node = node -> next[board[x][y] - 'a'];
        if(!node -> word.empty()){

            res.push_back(node -> word);
            node -> word = "";

        }
        char c = board[x][y];
        board[x][y] = '#';
        dfs(board,res,x + 1,y,node);
        dfs(board,res,x,y + 1,node);
        dfs(board,res,x - 1,y,node);
        dfs(board,res,x,y - 1,node);
        board[x][y] = c;
    }
};
