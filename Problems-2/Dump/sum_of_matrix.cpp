#include<iostream>
using namespace std;


int main(){
    int r, c;
    cin>>r>>c;
    vector<vector<int>> a(r, vector<int>(c, 0));
    
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < c ; j++){
            int tmp;
            cin>>tmp;
            a[i][j] =tmp ;
        }
    
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < c ; j++){
            int tmp;
            cin>>tmp;
            a[i][j]+=tmp;
        }
    return 0;
}