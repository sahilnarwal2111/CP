#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;

void solve(){
    int h,w,xa,ya,xb,yb;
    cin>>h>>w>>xa>>ya>>xb>>yb;
    if(xa >= xb){ // Draw
        cout<<"Draw"<<endl;
    } 
    else if((xb-xa) & 1){ // alice winning
        while(xb>=xa){
            //alice will do
            if(ya == yb ){
                xa++;
            }else if(ya < yb && ya << w){
                xa++, ya++;
            }else if( ya > 1) {
                xa++, ya--;
            }else{
                xa++;
            }
            if(xa == xb && ya == yb) {
                cout<<"Alice"<<endl;
                return;
            }
            //bob will do
            if(ya >= yb && yb < w){
                xb--, yb++;
            }else if(yb < w) {
                xb--, yb++;
            }else{
                xb--;
            }
            // cout<<"Coordinates "<<xa<<" "<<ya<<" ; "<<xb<<" "<<yb<<endl;
        }
        cout<<"Draw"<<endl;
    } else {// bob winning
        while(xb>=xa){
            // Alice will do
            if(ya >= yb && ya > 1 && ya < w){
                xa++, ya++;
            }
            else if(ya > 1 && ya < w){
                xa++, ya--;
            }
            else{
                xa++;
            }
            
            //BOb will do
            if(ya == yb && xb>1){
                xb--;
            }else if(yb > ya && xb >1 && yb >1){
                xb--, yb--;
            }else if(yb<w){
                xb--,yb++;
            }else{
                xb--;
            }
            
            if(xa == xb && ya == yb){
                cout<<"Bob"<<endl;
                return;
            }
            // cout<<"Coordinates "<<xa<<" "<<ya<<" ; "<<xb<<" "<<yb<<endl;
        }
        cout<<"Draw"<<endl;
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}