#include<iostream>
using namespace std;
int main(){
    int a = 0, b =0, c = 1;
    int n = 16;
    while(n--){
        int temp = a + b + c ;
        a = b;
        b = c;
        c = temp;

    }
    cout<<c<<endl;
    return 0;
}