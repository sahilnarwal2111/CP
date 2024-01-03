#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

void calSubset(vector<int> array, vector<int>& subset,  vector<vector<int> > &res, int index){
    
    res.push_back(subset);

    for(int i = index; i<array.size(); i++){
        subset.push_back(array[i]);
        calSubset(array, subset, res, i +1);
        subset.pop_back();
    }
}

vector<vector<int> > subset(vector<int> & array){
    vector<int> subset;
    vector<vector<int> > res ;
    int index = 0;
    calSubset(array, subset, res, index);
    return res;
}

int main(){
    vector<int> array ;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    vector<vector<int> > res = subset(array);
    for(int i = 0 ; i < res.size(); i++){
        for(int j = 0 ; j < res[i].size(); j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}