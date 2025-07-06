#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<char> > mat;
        int r,c ;
        for(int i = 0 ; i < 3; i++){
            for(int j = 0 ; j< 3; j++){
                cin>>mat[i][j];
                if(mat[i][j]=='?') {
                    r = i;
                    c = j;
                }
            }
        }
        int c1 = mat[r][(c+1)%3];
        int c2 = mat[r][(c+2)%3];
        if(c1 == 'A' && c2 =='B' || c1 == 'B' && c2 =='A') cout<<'C'<<endl;
        if(c1 == 'B' && c2 =='C' || c1 == 'C' && c2 =='B') cout<<'A'<<endl;
        if(c1 == 'C' && c2 =='A' || c1 == 'A' && c2 =='C') cout<<'B'<<endl;
    }
    return 0;
}