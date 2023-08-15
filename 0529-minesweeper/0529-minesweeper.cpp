class Solution {
    bool isPossible(int i, int j, int n, int m){
        return (i<0 || j<0 || i>=n ||j>=m) ? false : true;
    }
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m){
        if(!isPossible(i, j, n, m))return;
        if(board[i][j] == 'B')return;
        if(board[i][j] >'0' && board[i][j] < '9')return;
        int cnt=0;
        int di[8]={-1,-1,-1,0,0,1,1,1};
        int dj[8]={-1,0,1,-1,1,-1,0,1};
        for(int k=0;k<8;k++){
            if(isPossible(i+di[k], j+dj[k], n, m)){
                if(board[i+di[k]][j+dj[k]] == 'M') cnt++;
            }
        }
        if(cnt != 0){
            board[i][j] = cnt+'0';
            return;
        }
        else{
            board[i][j] = 'B';
        }
        for(int k=0;k<8;k++){
            dfs(board,i+di[k], j+dj[k], n, m);
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i=click[0], j=click[1];
        if(board[i][j] == 'M'){
            board[i][j] = 'X';
        }else{
            dfs(board, i, j, board.size(), board[0].size());
        }
        return board;
    }
};