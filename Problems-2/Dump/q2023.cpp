#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n , k;
        cin>>n>>k;
        vector<int> b;
        for(int i = 0 ; i < n ; i++){
            int temp ;
            cin>>temp;
            b.push_back(temp);
        }
        bool flag = 0;
        for(int i = 0 ; i < n ; i++) {
            if(2023%b[i]!=0) {
                flag = 1;
                cout<<"NO"<<endl;
            }
        }
        if(flag){
            continue;
        }
        else{
            int pro = 1;
            for(int i = 0 ; i < n ; i++){
                pro*=b[i];
            }
            // k and num
            //output will be 1 7 17 17 2023
            if(pro == 1){
                if(k == 1){
                    cout<<2023<<" ";
                }else if( k == 2){
                    cout<<7<<" "<<17<<" "<<289<<endl;
                }else if(k == 3){
                    // cout<<
                }
                
            }
        }
    }
    return 0;
}