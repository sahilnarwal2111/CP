#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
bool bounded(int i, int j, int n){
    return ( i >= 0 && i < n && j < n && j >= 0);
}
void print(vector<vector<int> > &board){
    for(auto &v : board){
        for(auto &el : v)
            cout<<el<<" ";
        cout<<endl;
    }
    cout<<"--------------------"<<endl;
}
void func(vector<vector<int> > &board, int i, int j , int n, int count){
    if(count == ((n*n)-1)){
        board[i][j] = n*n;
        print(board);
        board[i][j] = -1;
        return;
    }
    board[i][j] = count;
    // 8 moves of knight
    int x, y;
    x = i - 2, y = j+1;
    if(bounded(x,y,n) && board[x][y]==-1){
        func(board, x,y, n, count+1);
    }
    x = i - 1, y = j + 2;
    if(bounded(x,y,n) && board[x][y]==-1){
        func(board, x,y, n, count+1);
    }
    x = i + 1, y = j + 2;
    if(bounded(x,y,n) && board[x][y]==-1){
        func(board, x,y, n, count+1);
    }
    x = i + 2, y = j+1;
    if(bounded(x,y,n) && board[x][y]==-1){
        func(board, x,y, n, count+1);
    }
    x = i + 1, y = j - 2;
    if(bounded(x,y,n) && board[x][y]==-1){
        func(board, x,y, n, count+1);
    }
    x = i + 2, y = j-1;
    if(bounded(x,y,n) && board[x][y]==-1){
        func(board, x,y, n, count+1);
    }
    x = i - 1, y = j - 2;
    if(bounded(x,y,n) && board[x][y]==-1){
        func(board, x,y, n, count+1);
    }
    x = i - 2, y = j-1;
    if(bounded(x,y,n) && board[x][y]==-1){
        func(board, x,y, n, count+1);
    }
    board[i][j] = -1;
}
int main(){
    int n; cin>>n;
    vector<vector<int> > board (n, vector<int> (n,-1));
    int count = 0;
    func(board,0,0,n,count);
    return 0;
}