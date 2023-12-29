#include <iostream>
#include <vector>

using namespace std;

int rec(vector<vector<int> > mat, int i, int j){
    if( i==mat.size() || j == mat[0].size()  ) return 0;
    int ans1 = rec(mat,i+1,j);
    int ans2 = rec(mat,i,j+1);
    return mat[i][j] + max(ans1,ans2);
}

int main(){
    int n,m;
    vector<vector<int> > mat(n, vector<int>(m));
    for(int i = 0 ; i< n;i++)
        for(int j = 0 ; j < m ; j++)
            cin>>mat[i][j];
     cout<<rec(mat,0,0)<<endl;

    return 0;
}