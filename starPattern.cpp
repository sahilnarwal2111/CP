#include<iostream>
using namespace std;
int n;

void rec(int x){
    if( x <=0 ) return;

    rec(x-1);
    cout<<string(x,'*')<<endl;

}

int main(){
    cin>>n;
    rec(n);
    return 0;
}