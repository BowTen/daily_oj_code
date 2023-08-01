#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5010;
int n, a[N];


void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++){
        int bg = n - a[i];
        int sm = a[i] - 1;
        int d = abs(bg - sm) / 2;
        int len = 0;
        if(bg > sm)
            for(int j = 1;j <= n;j++){
                if(a[j] > a[i]) len++;
                else if(a[j] < a[i]) len = max(0ll, len - 1);
                else {len = 0; continue;}
                if(len == 3){
                    len = 1;
                    d--;
                }
            }
        else if(sm > bg)
            for(int j = 1;j <= n;j++){
                if(a[j] < a[i]) len++;
                else if(a[j] > a[i]) len = max(0ll, len - 1);
                else {len = 0; continue;}
                if(len == 3){
                    len = 1;
                    d--;
                }
            }
        if(d <= 0) cout << 1;
        else cout << 0;
    }

    cout << '\n';
}


signed main(){

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}