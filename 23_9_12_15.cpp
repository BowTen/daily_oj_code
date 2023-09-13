// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, k, a[N];

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     if(k == 1){
//         for(int i = 1;i <= n;i++) if(a[i] != i){
//             cout << "NO\n";
//             return;
//         }
//         cout << "YES\n";
//         return;
//     }

//     vector<int>vis(n + 1);
//     for(int i = 1;i <= n;i++) if(!vis[i]){
//         int cur = i;
//         vector<int>cyc;
//         while(!vis[cur]){
//             vis[cur] = 1;
//             cyc.push_back(cur);
//             cur = a[cur];
//         }
//         int siz = 0;
//         for(auto it = cyc.begin();it != cyc.end();it++){
//             if(*it == cur){
//                 siz = cyc.end() - it;
//                 break;
//             }
//         }
//         if(siz != k && siz){
//             cout << "NO\n";
//             return;
//         }
//     }
//     cout << "YES\n";
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, a[N];

// int tr[1<<9][2], tot;

// void init(){
//     tot = 0;
//     memset(tr, 0, sizeof(tr));
// }

// void insert(int x){
//     int p = 0;
//     for(int i = 7;i >= 0;i--){
//         int ne = (1 << i) & x;
//         if(!tr[p][ne]) tr[p][ne] = ++tot;
//         p = tr[p][ne];
//     }
// }

// int query(int x){
//     int ret = 0, p = 0;
//     for(int i = 7;i >= 0;i--){
//         ret <<= 1;
//         int ne = (1 << i) & x;
//         if(tr[p][!ne]){
//             ret++;
//             p = tr[p][!ne];
//         }else p = tr[p][ne];
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     init();
//     int ans = 0;
//     insert(0);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         a[i] ^= a[i-1];
//         ans = max(ans, query(a[i]));
//         insert(a[i]);
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, a[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     if(n & 1){
//         cout << 4 << '\n';
//         cout << 1 << ' ' << n << '\n' << 1 << ' ' << n - 1 << '\n' << n-1 << ' ' << n << '\n' << n-1 << ' ' << n << '\n';
//     }else{
//         cout << 2 << '\n';
//         cout << 1 << ' ' << n << '\n' << 1 << ' ' << n << '\n';
//     }
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, k, a, b, x[N], y[N];


// void solve(){
//     cin >> n >> k >> a >> b;
//     for(int i = 1;i <= n;i++) cin >> x[i] >> y[i];

//     int mntob = LLONG_MAX;
//     for(int i = 1;i <= k;i++){
//         mntob = min(mntob, abs(x[b] - x[i]) + abs(y[b] - y[i]));
//     }
//     int mntoa = LLONG_MAX;
//     for(int i = 1;i <= k;i++){
//         mntoa = min(mntoa, abs(x[a] - x[i]) + abs(y[a] - y[i]));
//     }
//     if(k == 0) cout << abs(x[a] - x[b]) + abs(y[a] - y[b]) << '\n';
//     else cout << min(mntoa + mntob, abs(x[a] - x[b]) + abs(y[a] - y[b])) << '\n';
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m;


// void solve(){
//     cin >> n >> m;
//     if(m == 1){
//         for(int i = 0;i <= n;i++) cout << 0 << '\n';
//         return;
//     }
//     if(n >= m - 1) cout << m << '\n';
//     else cout << m - (m - 1 - n) << '\n';
//     for(int i = 1, k = m - 1;i <= n;i++){
//         int id = i % (m-1);
//         if(id == 0) id = m - 1;
//         k = m - id;
//         for(int j = 1;j <= m;j++, k = (k + 1) % m){
//             cout << k << ' ';
//         }
//         cout << '\n';
//     }
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m, a[N];

// int lowbit(int x){
//     return x & -x;
// }

// bool check(int x){
//     bool fs = false;
//     for(int i = 0;(1 << i) <= x;i++){
//         if((1 << i) & x){
//             fs = true;
//         }else{
//             if(fs) return false;
//         }
//     }
//     return true;
// }

// void solve(){
//     cin >> n;
//     int sum = 0;
//     for(int i = 1;i <= n;i++) cin >> a[i], sum += a[i];
//     if(sum % n){
//         cout << "NO\n";
//         return;
//     }
//     sum /= n;
//     map<int,int>mp;
//     for(int i = 1;i <= n;i++){
//         int d = abs(a[i] - sum);
//         if(!check(d)){
//             cout << "NO\n";
//             return;
//         }else if(d){
//             if(a[i] > sum){
//                 mp[lowbit(d)]++;
//                 mp[lowbit(d) + d]--;
//             }else{
//                 mp[lowbit(d)]--;
//                 mp[lowbit(d) + d]++;
//             }
//         }
//     }
//     for(auto [k, v] : mp) if(v){
//         cout << "NO\n";
//         return;
//     }
//     cout << "YES\n";
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m, a[N], age[N], ans[N];

// vector<int>g[N];
// vector<int>tag[N];
// int par[N][20];

// void dfs(int u, int fa){
//     par[u][0] = fa;
//     for(int i = 1;i < 20;i++)
//         par[u][i] = par[par[u][i-1]][i-1];
//     for(auto v : g[u]) dfs(v, u);
// }

// void add(int o, int l, int r){
//     int tp = o;
//     for(int i = 19;i >= 0;i--) if(age[par[tp][i]] <= r)
//         tp = par[tp][i];
//     tag[tp].push_back(l);
// }

// int tr[N];

// int lowbit(int x){
//     return x & -x;
// }

// void add(int x, int v){
//     while(x < N){
//         tr[x] += v;
//         x += lowbit(x);
//     }
// }   

// int getsum(int x){
//     int ret = 0;
//     while(x > 0){
//         ret += tr[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void dfs2(int u){
//     for(auto v : tag[u]) add(v, 1);
//     ans[u] += getsum(age[u]);
//     for(auto v : g[u]) dfs2(v);
//     for(auto v : tag[u]) add(v, -1);
// }

// void solve(){
//     age[0] = INT_MAX;
//     cin >> n >> m;
//     int t;
//     cin >> age[1] >> t;
//     for(int i = 2;i <= n;i++){
//         cin >> age[i] >> t;
//         g[t].push_back(i);
//     }

//     dfs(1, 0);

//     for(int i = 1, o, l, r;i <= m;i++){
//         cin >> o >> l >> r;
//         add(o, l, r);
//     }

//     dfs2(1);


//     for(int i = 1;i <= n;i++) cout << ans[i] << ' ';

// }

// signed main(){

//     IO;

//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m;

// struct node{
//     int l, v, id; 
//     node(int l = 0, int v = 0, int id = 0) : l(l), v(v), id(id) {}   
// };
// vector<node>tim[88000];

// int f[88000][1030];

// void solve(){
//     cin >> n;
//     for(int i = 1, s;i <= n;i++){
//         cin >> s;
//         for(int j = 1, l, r, v;j <= s;j++){
//             cin >> l >> r >> v;
//             tim[r].push_back({l, v, i});
//         }
//     }

//     int all = (1 << n) - 1;
//     for(int i = 1;i <= 87000;i++){
//         for(int k = 0;k <= all;k++){
//             f[i][k] = f[i-1][k];
//             for(auto [l, v, id] : tim[i]) {
//                 if(((1 << (id - 1)) & k)&&(f[l][k]>0))f[i][k] = max(f[i][k], f[l][k] + v);
//                 if(f[l][k^(1<<(id-1))]>0||(k^(1<<(id-1)))==0)  f[i][k] = max(f[i][k], f[l][k ^ (1 << (id - 1))] + v);
//             }
//         }
//     }
//     // for(int i = 1;i <= 87000;i++){
//     //     for(auto [l, v, id] : tim[i]){
//     //         for(int k = 0;k <= all;k++) if((1 << (id - 1)) & k){
//     //         f[i][k] = f[i-1][k];
//     //             f[i][k] = max(f[i][k], f[l][k] + v);
//     //             if(f[l][k^(1<<(id-1))]>0||(k^(1<<(id-1)))==0)  f[i][k] = max(f[i][k], f[l][k ^ (1 << (id - 1))] + v);
//     //         }
//     //     }
//     // }

//     int ans = 0;
//     for(int i = 1;i <= 87000;i++)
//         ans = max(ans, f[i][all]);

//     cout << (ans ? ans : -1);
// }

// signed main(){

//     IO;

//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
#define all(x) x.begin(), x.end()
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int as = 5782344;
int n, q;

struct node{
    int l, r, id;
    node(int l = 0, int r = 0, int id = 0) : l(l), r(r), id(id) {}
    int operator<(const node& e) const {
        return l < e.l;
    }
    int operator>(const node& e) const {
        return l > e.l;
    }
}pt[N];

int qpow(int a, int x){
    int ret = 1;
    while(x){
        if(x & 1) ret = ret * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ret;
}

//树状数组
vector<node>tr[N];
int lowbit(int x){
    return x & -x;
}
void add(int x, const node& e){
    while(x < N){
        tr[x].push_back(e);
        x += lowbit(x);
    }
}
vector<node> getvec(int x, int L){
    vector<node>ret;
    while(x > 0){
        ret.insert(ret.end(), lower_bound(all(tr[x]), node(L, 0, 0)), tr[x].end());
        x -= lowbit(x);
    }
    return ret;
}

void solve(){
    cin >> n >> q;
    vector<int>idx;
    idx.reserve(2 * n + 1);
    for(int i = 1, x, y;i <= n;i++){
        cin >> x >> y;
        pt[i] = {y - x, y + x, i};
        idx.push_back(y - x);
        idx.push_back(y + x);
    }
    sort(idx.begin(), idx.end());
    for(int i = 1;i <= n;i++){
        pt[i].l = lower_bound(all(idx), pt[i].l) - idx.begin() + 1;
        pt[i].r = lower_bound(all(idx), pt[i].r) - idx.begin() + 1;
    }
    sort(pt + 1, pt + 1 + n, [](const node& e1, const node& e2)->int {return e1.r < e2.r;});

    for(int i = 1;i <= n;i++){
        add(pt[i].l, pt[i]);
    }


    for(int i = 1, a, b, xm, ym, p = 0, L, R;i <= q;i++){
        cin >> a >> b;
        xm = -1 - ((p + a) % mod);
        ym = (p + b) % mod;
        L = ym - xm;
        R = ym + xm;
        L = lower_bound(all(idx), L) - idx.begin() + 1;
        R = lower_bound(all(idx), R) - idx.begin() + 1;

        vector<node>res = getvec(R, L);
        cout << res.size() << ' ';
        sort(all(res), [](const node& e1, const node& e2)->int {return e1.id < e2.id;});
        for(int j = 0, len = res.size(); j < len;j++){
            p = (p + res[j].id * qpow(as, j)) % mod;
        }
        cout << p << '\n';
    }
}

signed main(){

    IO;

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}