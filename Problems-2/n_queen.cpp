#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

vector<vector<int> > res;


void print(vector<vector<int> > &board){
    vector<int> temp;
    for(int i = 0 ; i < board.size(); i++){
        for(int j = 0 ; j < board[0].size(); j++){
            if(board[i][j] == 1){
                temp.push_back(j+1);
            }
        }
    }
    res.push_back(temp);
}

bool isSafe(vector<vector<int> > &board, int row, int col){
    //vertical up
        for(int i = row-1; i>=0; i--) {
            if(board[i][col] == 1) 
                return false;
            }
        //diagonal up
        for(int i = row-1, j = col-1; i>=0 && j>=0 ; i--,j--) {
            if(board[i][j] == 1) 
                return false;
        }
        //right diag up
        for(int i = row-1, j = col+1; i>=0 && j<board.size() ; i--,j++) {
            if(board[i][j] == 1) 
                return false;
        }
        
        return true;
    }
    
    void n_queen(vector<vector<int> > &board, int row){
        if(row == board.size()){
            print(board);
            return;
        }
        //column loop
        for(int j = 0 ; j < board.size(); j++){
            if(isSafe(board,row,j)){
                board[row][j] = 1;
                n_queen(board,row+1);
                board[row][j] = 0;
            }
        }
    }
        

int main(){

    
    // print(board);
    int n = 2;
    vector<vector<int> > board (n, vector<int>(n,0));
    n_queen(board,0);

    for(int i = 0 ; i < res.size(); i++){
        for(int j = 0 ; j < res[i].size(); j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}