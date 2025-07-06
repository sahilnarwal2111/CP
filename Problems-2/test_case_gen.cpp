#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("output.txt", "w", stdout); 
    int sz = 10000;
    // vector<int> v(sz);
    vector<int> v(sz, 0);
    // freopen("output.txt", "w", stdout); 
    // Cr te a random number generator between 0 to 100
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 25);

    // Initialize vector elements with random values
    // for (int i = 0; i < sz; ++i){
    //     while(!v[i]) v[i] = dis(gen);
    // }
    // for(auto i : v){
    //     cout << i << " ";
    // }
    string tmp = "";
    for(int i = 0; i < sz; i++){
        tmp += (char)('a' + dis(gen));
    }
    cout << tmp << endl;
    return 0;
}
