#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool bounded(int i, int j, int n, int m){
    return( i >=0 && j >=0 && i < n && j < m);
}
bool findWord(int i, int j, int k, vector<vector<char> > & board, string & word, vector<vector<int> > &vis){
    if(word[k] != board[i][j]) return false;
    if(k == word.size()-1) return true;
    vis[i][j] = 1;
    for(int l = 0; i < 4 ; l++){
        int x = i + dx[l], y = j + dy[l];
        if(bounded(x,y,board.size(), board[0].size()) && !vis[x][y]){
            if(findWord(x,y,k+1,board,word,vis) ) return true;
        }
    }
    vis[i][j] = 0;
    return false;
}
bool exist(vector<vector<char> > & board, string word){
    for(int i = 0 ; i < board.size(); i++){
        for(int j = 0 ; j < board[0].size(); j++){
            vector<vector<int> > vis(board.size(), vector<int>(board[0].size(), 0));
            if(findWord(i,j,0,board, word, vis)) return true;
        }
    }
    return false;
}
int main(){
    
    return 0;
}