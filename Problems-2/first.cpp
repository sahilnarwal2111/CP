// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<cmath>
// #include<set>
// #include <map>
// #include <queue>
// #include <stack>
// #include <cstdlib>
// #define mod (ll)(1e9+7)
// #define int long long
// #define endl '\n'
// using namespace std;
// void solve(){
//     int n, m; cin>>n>>m;
//     vector<int> arr(n,0) ;
//     for(int i = 0 ; i < n ; i++) cin>>arr[i];

//     for(int i = 0 ; i < arr.size(); i++){
//         if(arr[i] < m){
//             if(i + 1 < arr.size()){
//                 arr[i+1]+=arr[i];
//                 arr.erase(arr.begin() + i);
//                 i--; 
//             }
//         }
//     }
//     while(arr.size()>1 && arr[arr.size()-1] < m){
//         arr[arr.size()-2]+=arr[arr.size()-1];
//         arr.pop_back();
//     }
//     cout<<arr.size()<<endl;
// }
// signed main(){
//     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     int t; cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }

#include<iostream>
#include<vector>
#define int long long
using namespace std;

void solve(){
    int n, m; 
    cin >> n >> m;
    vector<int> arr(n, 0);

    for(int i = 0 ; i < n ; i++) 
        cin >> arr[i];

    int result = 0;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] >= m) {
            result++;
            continue;
        }
        currentSum = arr[i];
        int j = i + 1;
        while(j < n && currentSum < m) {
            currentSum += arr[j++];
        }
        if(currentSum >= m) {
            result++;
            i = j - 1;
        }
    }

    cout << result << endl;
}
struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[1] < b[1];
    }
};
int numberOfPairs(vector<vector<int> >& points) {
    sort(points.begin(), points.end(), Compare());
    int cnt = 0;
    if(points.size() == 2){
        // 0 as C
        int xc = points[0][0];
        int yc = points[0][1];

        int xt = points[1][0];
        int yt = points[1][1];

        if(xc <= xt && yc >= yt){
            cnt++;
        }
        
        // 1 as C
        xt = points[0][0];
        yt = points[0][1];

        xc = points[1][0];
        yc = points[1][1];

        if(xc <= xt && yc >= yt){
            cnt++;
        }

        return cnt;
    }
    for(int i = 0 ; i < points.size(); i++){
        //taking cur as Chisato
        int xc = points[i][0];
        int yc = points[i][1];
        for(int j = 0; j < points.size() && j != i; j++){
            //selecting Takina
            int xt = points[j][0];
            int yt = points[j][1];

            if(xc <= xt && yc >= yt){
                //selection successful
                cout<<"c-> "<<xc<<" "<<yc<<endl;
                cout<<"t-> "<<xt<<" "<<yt<<endl;
                bool flag = true;
                for(int k = 0 ; k < points.size() ; k++){
                    if(k != i && k != j){
                        int x = points[k][0];
                        int y = points[k][1];
                        if((x <= xt && x >= xc) && (y >= yt && y <= yc)){
                            flag = false;
                            break;
                        }
                        if(xc == xt){
                            if(x == xc && y <= yc && y>=yt){
                                flag = false;
                                break;
                            }
                        }
                        if(yc == yt){
                            if(y == yc && x >= xc && x <= xt){

                                flag = false;
                                break;
                            }
                        }
                    }
                }

                if(flag) cnt++;
            }
        }

    }
    return cnt;

}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // std::vector<std::vector<int> > matrix(3,vector<int>(2,0));
    // for(int i = 0 ; i < 3; i++){
    //     cin>>matrix[i][0]>>matrix[i][1];
    // }
    // for(int i = 0 ; i < 3; i++){
    //     cout<<matrix[i][0]<<" "<<matrix[i][1]<<endl;
    // }
    // cout<<numberOfPairs(matrix);
    unordered_map<char,int> um;
    um['a'] = 1;
    um['b'] = 1;
    // for(auto it = um.begin(); it!=um.end();it++){

    // }
    cout<<um['c']<<endl;
    return 0;
}
