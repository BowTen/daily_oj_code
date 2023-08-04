// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 5010;
// int n, a[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     for(int i = 1;i <= n;i++){
//         int bg = n - a[i];
//         int sm = a[i] - 1;
//         int d = abs(bg - sm) / 2;
//         int len = 0;
//         if(bg > sm)
//             for(int j = 1;j <= n;j++){
//                 if(a[j] > a[i]) len++;
//                 else if(a[j] < a[i]) len = max(0ll, len - 1);
//                 else {len = 0; continue;}
//                 if(len == 3){
//                     len = 1;
//                     d--;
//                 }
//             }
//         else if(sm > bg)
//             for(int j = 1;j <= n;j++){
//                 if(a[j] < a[i]) len++;
//                 else if(a[j] > a[i]) len = max(0ll, len - 1);
//                 else {len = 0; continue;}
//                 if(len == 3){
//                     len = 1;
//                     d--;
//                 }
//             }
//         if(d <= 0) cout << 1;
//         else cout << 0;
//     }

//     cout << '\n';
// }


// signed main(){

//     int t;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define lson id << 1 
// #define rson id << 1 | 1
// const int N = 1e5 + 10;
// const int MULT = 0;
// const int ADD = 1;
// int n, m, a[N], mod;

// //线段树
// struct val{
//     int sum, len;
//     val operator+(const val e2) const {
//         val ret = *this;
//         ret.sum += e2.sum;
//         ret.len += e2.len;
//         return ret; 
//     }
// };
// struct node{
//     int ad, mt;
//     val v;
// }tr[N<<2];
// void up(int id){
//     tr[id].v = tr[lson].v + tr[rson].v;
// }
// void settag(int id, int v, int op){
//     if(op == ADD){
//         tr[id].v.sum = (tr[id].v.sum + tr[id].v.len * v) % mod;
//         tr[id].ad += v;
//     }else{
//         tr[id].v.sum = (tr[id].v.sum * v) % mod;
//         tr[id].mt *= v;
//         tr[id].ad *= v;
//     }
// }
// void down(int id){
//     if(tr[id].mt){
//         settag(lson, tr[id].mt, MULT);
//         settag(rson, tr[id].mt, MULT);
//         tr[id].mt = 1;
//     }
//     if(tr[id].ad){
//         settag(lson, tr[id].ad, ADD);
//         settag(rson, tr[id].ad, ADD);
//         tr[id].ad = 0;
//     }
// }
// void build(int id, int l, int r){
//     tr[id].mt = 1;
//     if(l == r){
//         tr[id].v.sum = a[l];
//         tr[id].v.len = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// void modify(int id, int l, int r, int ql, int qr, int v, int op){
//     if(ql <= l && r <= qr){
//         settag(id, v, op);
//         return;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, v, op);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, v, op);
//     else modify(lson, l, mid, ql, qr, v, op), modify(rson, mid + 1, r, ql, qr, v, op);
//     up(id);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         return tr[id].v.sum;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr) % mod;
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr) % mod;
//     else return (query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr)) % mod;
// }


// int main(){

//     cin >> n >> m >> mod;
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     build(1, 1, n);

//     while(m--){
//         int op, x, y, z;
//         cin >> op >> x >> y;
//         if(op == 2){
//             cin >> z;
//             modify(1, 1, n, x, y, z, ADD);
//         }else if(op == 1){
//             cin >> z;
//             modify(1, 1, n, x, y, z, MULT);
//         }else{
//             cout << query(1, 1, n, x, y) << '\n';
//         }
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e5 + 10;
// const int ADD = 1;
// const int MULT = 0;
// int n, m, mod, a[N];

// //线段树
// struct node{
//     int len, mt, ad, sum;
// }tr[N<<2];
// void up(int id){
//     tr[id].sum = (tr[lson].sum + tr[rson].sum) % mod;
// }

// void settag(int id, int v, int op){
//     if(op == ADD){
//         tr[id].ad = (tr[id].ad + v) % mod;
//         tr[id].sum = (tr[id].sum + tr[id].len * v) % mod;
//     }else{
//         tr[id].ad = (tr[id].ad * v) % mod;
//         tr[id].mt = (tr[id].mt * v) % mod;
//         tr[id].sum = (tr[id].sum * v) % mod;
//     }
// }

// void down(int id){
//     if(tr[id].mt != 1){
//         settag(lson, tr[id].mt, MULT);
//         settag(rson, tr[id].mt, MULT);
//         tr[id].mt = 1;
//     }
//     if(tr[id].ad){
//         settag(lson, tr[id].ad, ADD);
//         settag(rson, tr[id].ad, ADD);
//         tr[id].ad = 0;
//     }
// }

// void build(int id, int l, int r){
//     tr[id].mt = 1;
//     if(l == r){
//         tr[id].sum = a[l];
//         tr[id].len = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
//     tr[id].len = tr[lson].len + tr[rson].len;
// }

// void modify(int id, int l, int r, int ql, int qr, int v, int op){
//     if(ql <= l && r <= qr){
//         settag(id, v, op);
//         return;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, v, op);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, v, op);
//     else modify(lson, l, mid, ql, qr, v, op), modify(rson, mid + 1, r, ql, qr, v, op);
//     up(id);
// }

// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         return tr[id].sum;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
// }


// signed main(){

//     cin >> n >> mod;
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     build(1, 1, n);

//     cin >> m;
//     while(m--){
//         int op, x, y, z;
//         cin >> op >> x >> y;
//         if(op == 1){
//             cin >> z;
//             modify(1, 1, n, x, y, z, MULT);
//         }else if(op == 2){
//             cin >> z;
//             modify(1, 1, n, x, y, z, ADD);
//         }else{
//             cout << query(1, 1, n, x, y) % mod << '\n';
//         }
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e4 + 10;
// int l, m;
// array<int, 2> a[N];


// signed main(){

//     cin >> l >> m;
//     l++;
//     for(int i = 1;i <= m;i++){
//         cin >> a[i][0] >> a[i][1];
//     }
//     sort(a + 1, a + 1 + m);
//     int len = -1, cur;
//     for(int i = 1;i <= m;i++){
//         cur = max(len + 1, a[i][0]);
//         len = max(len, a[i][1]);
//         l -= len - cur + 1;
//     }

//     cout << l;


//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e4 + 10;
// int n, m, loped;

// //线段树
// struct val{
//     int sum, ltr;
//     val operator+(const val e) const {
//         val ret = *this;
//         ret.sum += e.sum;
//         ret.ltr += e.ltr;
//         return ret;
//     }
// };
// struct node{
//     int tag, len;
//     val v;
// }tr[N<<2];
// void up(int id){
//     tr[id].v = tr[lson].v + tr[rson].v;
// }
// void lop(int id){
//     tr[id].v.sum = tr[id].v.ltr = 0;
//     tr[id].tag = -1;
// }
// void plat(int id){
//     // cout << "!\n";
//     tr[id].v.sum = tr[id].v.ltr = tr[id].len;
//     tr[id].tag = 1;
// }
// void down(int id){
//     if(tr[id].tag == 1){
//         plat(lson);
//         plat(rson);
//     }else{
//         lop(lson);
//         lop(rson);
//     }
//     tr[id].tag = 0;
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].v.sum = tr[id].len = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
//     tr[id].len = tr[lson].len + tr[rson].len;
// }
// void cut_tr(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         if(tr[id].v.sum == tr[id].len){
//             loped += tr[id].v.ltr;
//             lop(id);
//             return;
//         }
//         else if(tr[id].v.sum == 0)
//             return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) cut_tr(lson, l, mid, ql, qr);
//     else if(ql > mid) cut_tr(rson, mid + 1, r, ql, qr);
//     else cut_tr(lson, l, mid, ql, qr), cut_tr(rson, mid + 1, r, ql, qr);
//     up(id);
// }

// void plant(int id, int l, int r, int ql, int qr){
//     // cout << "!\n";
//     if(ql <= l && r <= qr){
//         if(tr[id].v.sum == 0){
//             plat(id);
//             return;
//         }
//         else if(tr[id].v.sum == tr[id].len)
//             return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) plant(lson, l, mid, ql, qr);
//     else if(ql > mid) plant(rson, mid + 1, r, ql, qr);
//     else plant(lson, l, mid, ql, qr), plant(rson, mid + 1, r, ql, qr);
//     up(id);
// }


// signed main(){

//     cin >> n >> m;
//     n++;
//     build(1, 1, n);
//     while(m--){
//         int op, x, y;
//         cin >> op >> x >> y;
//         x++, y++;
//         if(op == 0){
//             cut_tr(1, 1, n, x, y);
//         }else{
//             plant(1, 1, n, x, y);
//         }
//     }

//     cout << tr[1].v.ltr << '\n' << loped;

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, m, a[N];

// //线段树
// struct node{
//     int mx;
// }tr[N<<2];
// void up(int id){
//     tr[id].mx = max(tr[lson].mx, tr[rson].mx);
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].mx = a[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id].mx = max(tr[id].mx, v);
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(lson, l, mid, x, v);
//     else change(rson, mid + 1, r, x, v);
//     up(id);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         return tr[id].mx;
//     }
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return max(query(lson, l, mid, ql, qr), query(rson, mid + 1, r, ql, qr));
// }


// signed main(){

//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     build(1, 1, n);

//     while(m--){
//         char op;
//         int a, b;
//         cin >> op >> a >> b;
//         if(op == 'U'){
//             change(1, 1, n, a, b);
//         }else{
//             cout << query(1, 1, n, a, b) << '\n';
//         }
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1 
// #define rson id << 1 | 1
// const int N = 1e5 + 10;
// int n, m;

// //线段树
// bool tag[N<<2];
// void settag(int id, bool v){
//     tag[id] ^= v;
// }
// void down(int id){
//     settag(lson, true);
//     settag(rson, true);
//     tag[id] = false;
// }
// void modify(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         settag(id, true);
//         return;
//     }
//     if(tag[id]) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr);
//     else modify(lson, l, mid, ql, qr), modify(rson, mid + 1, r, ql ,qr);
// }
// int query(int id, int l, int r, int x){
//     if(l == r) return tag[id];
//     if(tag[id]) down(id);
//     int mid = l + r >> 1;
//     if(x <= mid) return query(lson, l, mid, x);
//     else return query(rson, mid + 1, r, x);
// }   

// signed main(){

//     cin >> n >> m;
//     while(m--){
//         int op, a, b;
//         cin >> op >> a;
//         if(op == 1){
//             cin >> b;
//             modify(1, 1, n, a, b);
//         }else{
//             cout << query(1, 1, n, a) << '\n';
//         }
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e5 + 10;
// int n, m;

// //线段树
// int tr[N<<2];
// void up(int id){
//     tr[id] = tr[lson] * tr[rson] % m;
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id] = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id] = v;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(lson, l, mid, x, v);
//     else change(rson, mid + 1, r, x, v);
//     up(id);
// }



// void solve(){
//     cin >> n >> m;
//     build(1, 1, n);

//     for(int i = 1;i <= n;i++){
//         int op, a;
//         cin >> op >> a;
//         if(op == 1){
//             change(1, 1, n, i, a);
//         }else{
//             change(1, 1, n, a, 1);
//         }
//         cout << tr[1] << '\n';
//     }
// }

// signed main(){

//     int t;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e6 + 10;
// const int mxn = 1e9 + 10;
// int n, m, a[N];

// //线段树
// int tr[N<<2], tot, rt, ls[N<<2], rs[N<<2];
// void up(int id){
//     tr[id] = tr[ls[id]] + tr[rs[id]];
// }
// void add(int &rt, int l, int r, int x, int v){
//     if(!rt) rt = ++tot;
//     if(l == r){
//         tr[rt] += v;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) add(ls[rt], l, mid, x, v);
//     else add(rs[rt], mid + 1, r, x, v);
//     up(rt);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(qr < ql) return 0;
//     if(ql <= l && r <= qr){
//         return tr[id];
//     }
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls[id], l, mid, ql, qr);
//     else if(ql > mid) return query(rs[id], mid + 1, r, ql, qr);
//     else return query(ls[id], l, mid, ql, qr) + query(rs[id], mid + 1, r, ql, qr);
// }

// void solve(){
//     cin >> n;
//     int ans = 0;
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         add(rt, 1, mxn, a[i], 1);
//         ans += query(rt, 1, mxn, a[i] + 1, mxn);
//     }
//     cout << ans << '\n';
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e6 + 10;
// const int mxn = 1e9 + 10;
// int n, m, a[N];

// //线段树
// int tr[N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x){
//     while(x <= n){
//         tr[x] ++;
//         x += lowbit(x);
//     }
// }
// int getsum(int x){
//     int ret = 0;
//     while(x){
//         ret += tr[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     vector<int> idx;
//     for(int i = 1;i <= n;i++ ) {
//         cin >> a[i];
//         idx.push_back(a[i]);
//     }
//     sort(idx.begin(), idx.end());
//     idx.erase(unique(idx.begin(), idx.end()), idx.end());
//     for(int i = 1;i <= n;i++){
//         a[i] = (lower_bound(idx.begin(), idx.end(), a[i]) - idx.begin()) + 1;
//     }

//     int ans = 0;
//     for(int i = n;i >= 1;i--){
//         add(a[i]);
//         ans += getsum(a[i] - 1);
//     }

//     cout << ans << '\n';


// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e5 + 10;
// const int mxn = 1e5 + 5;
// int n, m, a[N];

// //线段树
// int tr[N], tr2[N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x, int v){
//     while(x < mxn){
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
// void add2(int x, int v){
//     while(x < mxn){
//         tr2[x] += v;
//         x += lowbit(x);
//     }
// }
// int getsum2(int x){
//     int ret = 0;
//     while(x > 0){
//         ret += tr2[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
    
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         add2(a[i], 1);
//     }

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         ans += getsum(a[i]-1) * (getsum2(mxn) - getsum2(a[i]));
//         add(a[i], 1);
//         add2(a[i], -1);
//     }

//     cout << ans << '\n';
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
// const int inf = 1e9;
// int n, k, fa[N], c[N], tot = 1, siz[N], l[N], r[N];

// void dfs(int u, int f, int s){
//     fa[u] = f;
//     if(s == 2){
//         c[u] = siz[u] = 1;
//         c[++tot] = 1;
//         fa[tot] = u;
//         return;
//     }else if(s == 1){
//         c[u] = siz[u] = 1;
//         return;
//     }

//     bool odd = false;
//     if(s & 1){
//         odd = true;
//         s--;
//     }else{
//         c[u] = inf;
//     }
    
//     l[u] = ++tot;
//     dfs(tot, u, 2);
//     r[u] = ++tot;
//     dfs(tot, u, s / 2);

//     siz[u] = siz[l[u]] + siz[r[u]];
//     if(odd) c[u] = siz[u];
// }

// int main(){

//     cin >> k;

//     if(k == 1){
//         cout << "2\n1\n2 1";
//         return 0;
//     }

//     if(k < 1e5){
//         cout << k << '\n';
//         for(int i = 1;i < k;i++) cout << i << ' ';
//         cout << '\n';
//         for(int i = 1;i <= k;i++) cout << 1 << ' ';
//         return 0;
//     }

//     dfs(1, 0, k);

//     cout << tot << '\n';
//     for(int i = 2;i <= tot;i++) cout << fa[i] << ' ';
//     cout << '\n';
//     for(int i = 1;i <= tot;i++) cout << c[i] << ' ';

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// int n, a[N], dp[N], t[N], no_son[N];
// vector<int>g[N];


// void dfs(int u, int f){
//     int mx = 0;
//     int mxns = 0;
//     int tmp = a[u]; 
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         tmp += dp[v] - a[v];
//         mx = max(mx, a[v]);
//         if(mxns == 0 || no_son[v] - dp[v] + a[v] > no_son[mxns] - dp[mxns] + a[mxns])
//             mxns = v;
//     }
//     int mxns3 = 0;
//     for(auto v : g[u]) if(v != f && v != mxns){
//         if(mxns3 == 0 || no_son[v] - dp[v] + a[v] > no_son[mxns3] - dp[mxns3] + a[mxns3])
//             mxns3 = v;
//     }

//     no_son[u] = tmp;
//     dp[u] = tmp + mx;
//     if(mxns){
//         tmp += no_son[mxns] - dp[mxns] + a[mxns];
//         for(auto v : g[u]) if(v != f && v != mxns && t[v] == 3){
//             dp[u] = max(dp[u], tmp + a[v]);
//         }
//         tmp -= no_son[mxns] - dp[mxns] + a[mxns];
//     }
//     if(mxns3){
//         tmp += no_son[mxns3] - dp[mxns3] + a[mxns3];
//         for(auto v : g[u]) if(v != f && v != mxns3 && t[v] == 3){
//             dp[u] = max(dp[u], tmp + a[v]);
//         }
//     }
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) g[i].clear();
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> t[i];
//     for(int i = 1;i < n;i++) {
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);

//     cout << dp[1] << '\n';
// }


// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// const int N = 2e6 + 100;
// int n, k, a[N];
// int delt[N], num[N], ans[N];

// int main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> k;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         a[i] += 1e6+5;
//         ans[a[i]]++;
//     }

//     if(k)
//         for(int i = 1;i <= n;i++){
//             num[a[i]] = max(0, num[a[i]] - 1);
//             if(a[i]+k <= 2e6+10 && a[i] + k >= 0){
//                 num[a[i]+k]++;
//                 delt[a[i]+k] = max(delt[a[i] + k], num[a[i] + k]);
//             }
//         }

//     int mx = 0;
//     for(int i = 1;i <= n;i++){
//         mx = max(mx, delt[a[i]] + ans[a[i]]);
//     }

//     cout << mx;

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// vector<int>fac;


// void solve(){
//     int a, b;
//     cin >> a >> b;
//     if(a > b) swap(a, b);
//     int d = b - a;

//     for(int i = 2;;i++){

//     }

// }


// int main(){

//     int t;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define Acode ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// #define int long long
// const int N = 1e6 + 7;
// int a, b, ans;

// unordered_map<int, bool>vis;
// vector<int> vec;
// void dfs(int a, int b, int s)
// {
//     if(vis[a*1358486+b]) {
//         if(a == 1)
//             ans = min(ans, s);
//         return;
//     }
//     vis[a*1358486+b] = true;
//     // cout << a << ' ' << b << ' ' << s << '\n';
//     // if (a > b) swap(a, b);
//     if (s >= ans) return;
//     if (a == 1) {
//         ans = min(s, ans);
//         return;
//     }

//     int d = b - a;
//     if (d == 1){
//         s += a - 1;
//         ans = min(ans, s);
//         return;
//     }else{
//         for (auto fac : vec) if(d % fac == 0){
//             int aa, bb, ss;
//             if (a % fac == 0){
//                 aa = a, bb = b, ss = s;
//                 dfs(aa / fac, bb / fac, ss + 1);
//             }
//             else{
//                 int ad = (a / fac + 1) * fac - a;
//                 aa = a + ad, bb = b + ad, ss = s + ad;
//                 if (aa / fac < a)
//                     dfs(aa / fac, bb / fac, ss + 1);
//                 if (a > fac)
//                 {
//                     int sb = a % fac;
//                     aa = a - sb, bb = b - sb, ss = s + sb;
//                     dfs(aa / fac, bb / fac, ss + 1);
//                 }
//             }
//         }
//     }
// }

// void solve()
// {
//     vec.clear();
//     vis.clear();
//     cin >> a >> b;
//     if (a > b) swap(a, b);
//     ans = a - 1;
//     if (b - a == 1){
//         cout << ans << '\n';
//         return;
//     }

//     int t = b - a;
//     for (int i = 2; i <= t / i; ++i){
//         while (t % i == 0){
//             t /= i;
//             vec.push_back(i);
//         }
//     }
//     if (t > 1) vec.push_back(t);
//     vec.erase(unique(vec.begin(), vec.end()), vec.end());


//     dfs(a, b, 0);

//     cout << ans << '\n';
// }

// signed main()
// {
//     Acode;
//     int T = 1;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// vector<int>fac;
// unordered_map<int,int>mp;

// void init(){
//     fac.clear();
//     mp.clear();
// }

// int H(int a, int b){
//     return a * 10000007 + b;
// }

// int dfs(int a, int b){
//     if(a == 0) return INT_MAX;
//     int hs = H(a, b);
//     if(mp[hs]) return mp[hs];

//     int ret = a - 1;
//     int d = b - a;
//     if(a == 1) return 0;
//     if(d == 1) return mp[hs] = ret;
//     for(auto f : fac) if(d % f == 0){
//         if(a % f == 0)
//             ret = min(ret, dfs(a / f, b / f) + 1);
//         else{
//             int mod = a % f;
//             ret = min({ret, mod + 1 + dfs(a / f, b / f), f - mod + 1 + dfs(a / f + 1, b / f + 1)});
//         }
//     }

//     return mp[hs] = ret;
// }

// void solve(){
//     init();

//     int a, b;
//     cin >> a >> b;
//     if(a > b) swap(a, b);
//     int d = b - a;
//     for(int i = 2;i <= d / i;i++){
//         if(d % i == 0){
//             fac.push_back(i);
//             while(d % i == 0) d /= i;
//         }
//     }
//     if(d > 1) fac.push_back(d);

//     cout << dfs(a, b) << '\n';
// }


// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

