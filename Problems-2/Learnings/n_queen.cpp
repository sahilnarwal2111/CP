#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
void print(vector<string> board){
    for(int i = 0 ; i < board.size(); i++){
        for(int j = 0 ; j < board[0].size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"---------------SOLUTION COMPLETED--------------"<<endl;
}

bool isSafe(vector<string> board, int row, int col){
    //vertical up
    for(int i = row-1; i>=0; i--) {
        if(board[i][col] == 'Q') 
            return false;
        }
    //diagonal up
    for(int i = row-1, j = col-1; i>=0 && j>=0 ; i--,j--) {
        if(board[i][j] == 'Q') 
            return false;
    }
    //right diag up
    for(int i = row-1, j = col+1; i>=0 && j<board.size() ; i--,j++) {
        if(board[i][j] == 'Q') 
            return false;
    }
    
    return true;
}

void n_queen(vector<string> & board, int row){
    if(row == board.size()){
        print(board);
        return;
    }
    //column loop
    for(int j = 0 ; j < board.size(); j++){
        if(isSafe(board,row,j)){
            board[row][j] = 'Q';
            n_queen(board,row+1);
            board[row][j] = 'P';
        }
    }
}

int main(){

    vector<string> board;
    board.push_back("PPPPP");
    board.push_back("PPPPP");
    board.push_back("PPPPP");
    board.push_back("PPPPP");
    board.push_back("PPPPP");
    // print(board);
    n_queen(board,0);
    return 0;
}