#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;

struct Item{
    int num;
    string str;
};

bool comparator(Item &a, Item &b){
    return a.num < b.num;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    const int SIZE = 4;
    Item array[SIZE];
    array[0].num = 1, array[0].str = 'B';
    array[3].num = 4, array[3].str = 'A';
    array[1].num = 3, array[1].str = 'C';
    array[2].num = 2, array[2].str = 'D';
    cout<<"Before Sorting"<<endl;
    for(int i = 0 ; i < 4; i++){
        cout<<array[i].num<<" "<<array[i].str<<endl;
    }
    sort(&array[0],&array[SIZE],comparator);
    cout<<"After Sorting"<<endl;
    for(int i = 0 ; i < 4; i++){
        cout<<array[i].num<<" "<<array[i].str<<endl;
    }


    return 0;
}