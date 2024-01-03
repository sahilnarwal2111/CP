#include<iostream>
#include <vector>
using namespace std;

void print(vector<int> arr){
    for(auto &i : arr) cout<<i<<" ";
}

void changeArr(vector<int> & arr, int i , int val){
    if(i == arr.size()) {
        print(arr);
        return;
    }
    arr[i] = i;
    changeArr(arr,i+1,val);
    arr[i] = val - 2;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    changeArr(arr,0,2);
    cout<<'\n';
    print(arr);
    return 0;
}