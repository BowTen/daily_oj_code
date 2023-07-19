// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int a, b, c;
//     cin >> a >> b;
//     cout << "1| " << a << '\n'
//          << "2| " << b << '\n';
//     for (int i = 3; 1; i++)
//     {
//         c = abs(a - b);
//         cout << i << "| " << c << '\n';
//         a = b;
//         b = c;
//         if (!b)
//             break;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 5e5 + 10;
// int n, m, a[N], pre[N];

// signed main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         pre[i] = pre[i - 1] + a[i];
//         // cout << pre[i] << ' ';
//     }
//     if (pre[n] % 3)
//     {
//         cout << 0;
//         return 0;
//     }
//     int l = pre[n] / 3;
//     int r = l * 2;
//     int ls = 0;
//     int ans = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if (pre[i] == r)
//         {
//             ans += ls;
//             // cout << "ans += ls\n";
//         }
//         if (pre[i] == l)
//         {
//             ls++;
//             // cout << "ls++\n";
//         }
//     }
//     cout << ans;
//     // cout << l << ' ' << r << ' ' << ls;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, m, a[N];

// void solve()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     if (a[1] == a[n])
//     {
//         m = 1;
//         for (int i = 2; i <= n; i++)
//             if (a[i] > a[i - 1])
//                 m++;
//             else
//                 break;
//         if (m & 1)
//         {
//             cout << "Alice";
//             return;
//         }

//         m = 1;
//         for (int i = n - 1; i >= 1; i--)
//             if (a[i] > a[i + 1])
//                 m++;
//             else
//                 break;
//         if (m & 1)
//         {
//             cout << "Alice";
//             return;
//         }
//         else
//         {
//             cout << "Bob";
//             return;
//         }
//     }
//     else if (a[1] > a[n])
//     {
//         m = 1;
//         for (int i = 2; i <= n; i++)
//             if (a[i] > a[i - 1])
//                 m++;
//             else
//                 break;
//         if (m & 1)
//         {
//             cout << "Alice";
//             return;
//         }

//         int cnt = 1;
//         for (int i = n - 1; i >= 1; i--)
//             if (a[i] > a[i + 1])
//                 cnt++;
//             else
//                 break;

//         if (cnt & 1)
//         {
//             cout << "Alice";
//             return;
//         }
//         else
//         {
//             cout << "Bob";
//             return;
//         }
//     }
//     else if (a[1] < a[n])
//     {
//         m = 1;
//         for (int i = n - 1; i >= 1; i--)
//             if (a[i] > a[i + 1])
//                 m++;
//             else
//                 break;
//         if (m & 1)
//         {
//             cout << "Alice";
//             return;
//         }

//         int cnt = 1;
//         for (int i = 2; i <= n; i++)
//             if (a[i] > a[i - 1])
//                 cnt++;
//             else
//                 break;

//         if (cnt & 1)
//         {
//             cout << "Alice";
//             return;
//         }
//         else
//         {
//             cout << "Bob";
//             return;
//         }
//     }
// }

// signed main()
// {
//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// int n, q;
// string s;

// typedef array<int, 27> chas;

// chas tr[N << 2];
// chas operator+(const chas a1, const chas a2)
// {
//     chas ret = a1;
//     for (int i = 0; i < 27; i++)
//         ret[i] += a2[i];
//     return ret;
// }
// void up(int id)
// {
//     tr[id] = tr[lson] + tr[rson];
// }
// void build(int id, int l, int r)
// {
//     if (l == r)
//     {
//         tr[id][s[l] - 'a' + 1] = 1;
//         // cout << "tr[" << l << "][" << (int)(s[l] - 'a' + 1) << "] " << l << ' ' << s[l] - 'a' + 1 << '\n';
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// void change(int id, int l, int r, int x, char c)
// {
//     if (l == r)
//     {
//         tr[id][s[x] - 'a' + 1] = 0;
//         s[x] = c;
//         tr[id][s[x] - 'a' + 1] = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     if (x <= mid)
//         change(lson, l, mid, x, c);
//     else
//         change(rson, mid + 1, r, x, c);
//     up(id);
// }
// chas query(int id, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//         return tr[id];
//     int mid = l + r >> 1;
//     if (qr <= mid)
//         return query(lson, l, mid, ql, qr);
//     else if (ql > mid)
//         return query(rson, mid + 1, r, ql, qr);
//     else
//         return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
// }

// int fac[N];
// int inv[N];

// int qpow(int a, int b, int p)
// {
//     int res = 1;
//     while (b)
//     {
//         if (b & 1)
//             res = res * a % p;
//         b >>= 1;
//         a = a * a % p;
//     }
//     return res % p;
// }

// void init()
// {
//     fac[0] = 1;
//     inv[0] = 1;
//     for (int i = 1; i < N; i++)
//     {
//         fac[i] = (fac[i - 1] * i) % mod;
//         inv[i] = inv[i - 1] * qpow(i, mod - 2, mod) % mod;
//         // inv[i] = qpow(fac[i], mod - 2, mod);
//     }
// }

// signed main()
// {
//     init();
//     cin >> n >> q >> s;
//     s = ' ' + s;
//     build(1, 1, n);

//     while (q--)
//     {
//         int op, x, l, r;
//         char y;
//         cin >> op;
//         if (op == 1)
//         {
//             cin >> x >> y;
//             x++;
//             change(1, 1, n, x, y);
//         }
//         else
//         {
//             cin >> l >> r;
//             l++;
//             r++;
//             chas ans = query(1, 1, n, l, r);
//             int cnt = 0, len = r - l + 1;
//             for (int i = 1; i <= 26; i++)
//             {
//                 if (ans[i] & 1)
//                     cnt++;
//                 ans[i] /= 2;
//             }
//             if (cnt != (len & 1))
//             {
//                 cout << "0\n";
//                 continue;
//             }
//             len /= 2;
//             int ret = fac[len] % mod;
//             for (int i = 1; i <= 26; i++)
//                 if (ans[i])
//                     ret = (ret * inv[ans[i]]) % mod;
//             cout << ret << '\n';
//         }
//     }
//     // chas ans = query(1, 1, n, 1, 5);
//     // for (int i = 1; i <= n; i++)
//     // {
//     //     cout << (char)('a' + i - 1) << ' ' << ans[i] << '\n';
//     // }
//     // cout << n << ' ' << q << ' ' << s;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// int n, q;
// string s;

// typedef array<int, 27> chas;

// int fac[N];
// void init()
// {
//     fac[1] = 1;
//     for (int i = 2; i < N; i++)
//     {
//         fac[i] = (fac[i - 1] * i) % mod;
//     }
// }

// signed main()
// {
//     init();
//     cin >> n >> q >> s;
//     s = ' ' + s;

//     while (q--)
//     {
//         int op, x, l, r;
//         char y;
//         cin >> op;
//         if (op == 1)
//         {
//             cin >> x >> y;
//             x++;
//             change(1, 1, n, x, y);
//         }
//         else
//         {
//             cin >> l >> r;
//             l++;
//             r++;
//             chas ans = query(1, 1, n, l, r);
//             int cnt = 0, len = r - l + 1;
//             for (int i = 1; i <= 26; i++)
//             {
//                 if (ans[i] & 1)
//                     cnt++;
//                 ans[i] /= 2;
//             }
//             if (cnt != (len & 1))
//             {
//                 cout << "0\n";
//                 continue;
//             }
//             len /= 2;
//             int ret = fac[len] % mod;
//             for (int i = 1; i <= 26; i++)
//                 if (ans[i])
//                     ret = (ret / fac[ans[i]]) % mod;
//             cout << ret << '\n';
//         }
//     }
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// int n, q;
// string s;

// //快速幂
// int qpow(int a, int k, int p){
//     int ret = 1;
//     while(k){
//         if(k & 1) ret = a * ret % p;
//         a = a * a % p;
//         k >>= 1;
//     }
//     return ret;
// }

// //阶乘、逆元
// int fac[N], inv[N];
// void get_inv(){
//     inv[0] = fac[0] = 1;
//     for(int i = 1;i < N;i++){
//         fac[i] = fac[i-1] * i % mod;
//         inv[i] = inv[i-1] * qpow(i, mod - 2, mod) % mod;
//     }
// }


// //树状数组
// int tr[27][N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int c, int x, int v){
//     if(!x) return;
//     c = c - 'a' + 1;
//     while(x <= n){
//         tr[c][x] += v;
//         x += lowbit(x);
//     }
// }
// int getans(int l, int r){
//     int len = r - l + 1;
//     int cnt[27] = {0};
//     for(int i = 1;i <= 26;i++){
//         int x = r;
//         while(x > 0){
//             cnt[i] += tr[i][x];
//             x -= lowbit(x);
//         }
//     }
//     for(int i = 1;i <= 26;i++){
//         int x = l-1;
//         while(x > 0){
//             cnt[i] -= tr[i][x];
//             x -= lowbit(x);
//         }
//     }
//     int f = 0;
//     for(int i = 1;i <= 26;i++){
//         if(cnt[i] & 1) f ++;
//         cnt[i] /= 2;
//     }
//     if(f != (len & 1)) return 0;
//     len /= 2;
//     int ret = fac[len];
//     for(int i = 1;i <= 26;i++)if(cnt[i]){
//         ret = ret * inv[cnt[i]] % mod;
//     }
//     return ret;

// }

// signed main(){

//     get_inv();

//     cin >> n >> q >> s;
//     s = ' ' + s;
//     for(int i = 1;i <= n;i++)
//         add(s[i], i, 1);

//     while(q--){
//         int op, l, r, x;
//         char y;
//         cin >> op;
//         if(op == 1){
//             cin >> x >> y;
//             x++;
//             add(s[x], x, -1);
//             s[x] = y;
//             add(s[x], x, 1);
//         }else{
//             cin >> l >> r;
//             l ++;
//             r ++;
//             cout << getans(l, r) << '\n';
//         }
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 5;
// int n,m, a[N], b[N];

// int get_pos(int x, int y){
//     int z = abs(x-y);
//     int mn = y, cnt = 0, ret = 1;
//     while(z){
//         x = y;
//         y = z;
//         z = abs(x-y);
//         ret++;
//         if(mn == z) cnt++;
//         else if(z < mn) mn = z, cnt = 0;
//         if(cnt >= 3){
//             int tmp = y / (2*mn);
//             y -= tmp*2*mn;
//             x -= tmp*2*mn;
//             cnt = 0;
//         }
//     }
//     return ret % 3;
// }


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];


//     int fis_pos;
//     int i = 1;
//     for(i = 1;i <= n;i++){
//         if(a[i] || b[i]){
//             fis_pos = get_pos(a[i], b[i]);
//             break;
//         }
//     }

//     for(;i <= n;i++){
//         if((a[i] || b[i]) && get_pos(a[i], b[i]) != fis_pos){
//             cout << "NO\n";
//             return;
//         }
//     }

//     cout << "YES\n";
// }

// signed main(){
//     int t = 1;
//     cin >> t;
//     while(t--)solve();
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int s, k, mod;
// int b[5] = {0,2,4,8,6,};
// int preb[5] = {0,2,6,14,20,};

// int get_res(int x){
//     if(!x) return k*s;
//     if(x >= k || x < 0) return 0;

//     int xx = x, ss = s;
//     while(xx > 0 && ss % 10 != 2){
//         ss += ss%10;
//         xx--;
//     }
    
//     return (k-x) * (ss + preb[4] * (xx/4) + preb[xx%4]);
// }

// void solve(){
//     cin >> s >> k;
//     mod = s % 10;

//     if(!mod){//特判 0,5
//         cout << s*k << '\n';
//         return;
//     }else if(mod == 5){
//         cout << max((s+5)*(k-1), s*k) << '\n';
//         return;
//     }

//     int ans = 0;
//     if(k > 40){
//         int x = ((20*k-4*s) / 160)*4;
//         ans = max(get_res(0), get_res(k-1));
//         for(int i = x - 5;i <= x + 5;i++) ans = max(ans, get_res(i));
//         for(int i = 0;i <= 5;i++) ans = max(ans, get_res(i));

//     }else{
//         for(int i = 0;i < k;i++) ans = max(ans, get_res(i));
//     }
//     cout << ans << '\n';

// }

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
#define lson id << 1
#define rson id << 1 | 1
const int N = 3e5 + 10;
const int BLOW = 0;
const int TOP = 1;
const int sz = 3e5 + 5;
int n;
vector<array<int, 5>>evt;

//线段树
struct info{
    int mx;
};
struct node{
    int tag;
    info val;   
}tr[N << 2];
void settag(int id, int v){
    tr[id].tag += v;
    tr[id].val.mx += v;
}
void up(int id){
    tr[id].val.mx = max(tr[lson].val.mx, tr[rson].val.mx);
}
void down(int id){
    settag(lson, tr[id].tag);
    settag(rson, tr[id].tag);
    tr[id].tag = 0;
}
void modify(int id, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        settag(id, v);
        return;
    }
    down(id);
    int mid = l + r >> 1;
    if(qr <= mid)
        modify(lson, l, mid, ql, qr, v);
    else if(ql > mid)
        modify(rson, mid+1, r, ql, qr, v);
    else{
        modify(lson, l, mid, ql, qr, v);
        modify(rson, mid+1, r, ql, qr, v);
    } 
    up(id);
}

int get_mx_x(int id, int l, int r, int mx){
    if(l == r) return l;
    down(id);
    int mid = l + r >> 1;
    int lv = tr[lson].val.mx;
    if(lv == mx) return get_mx_x(lson, l, mid, mx);
    return get_mx_x(rson, mid + 1, r, mx);
}


signed main(){

    cin >> n;
    evt.reserve(n*2);
    for(int i = 1, l, v, r;i <= n;i++){
        cin >> l >> v >> r;
        evt.push_back({v, BLOW, l, v, i});
        evt.push_back({r, TOP, l, v, i});
    }
    sort(all(evt));

    int mx = 0, py, px;
    for(auto [y, op, l, r, id] : evt) if (op == BLOW){
        modify(1, 1, sz, l, r, 1);
        if(tr[1].val.mx > mx){
            mx = tr[1].val.mx;
            px = get_mx_x(1, 1, sz, mx);
            py = y;
        }
    }else{
        modify(1, 1, sz, l, r, -1);
    }

    vector<int>ans;
    for(auto [y, op, l, r, id] : evt) if (op && l <= px && px <= r && r <= py && py <= y) ans.push_back(id);

    cout << ans.size() << '\n';
    for(auto e : ans) cout << e << ' ';

    return 0;
}