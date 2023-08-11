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

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e4 + 10;
// int n, m, p;
// double q; //失败概率

// void init(){
//     q = 1.0 - (p / 10000.0);
// }

// double E(int k){
//     return (k * n + m) / (1.0 - pow(q, k));
// }

// void solve(){
//     cin >> n >> m >> p;
//     init();
//     if(p == 10000){
//         printf("%llf\n", (double)(n+m));
//         return;
//     }

//     int l = 2, r = 1e15;
//     while(l <= r){
//         int mid = l + r >> 1;
//         double me = E(mid);
//         double ne = E(mid + 1);
//         if(ne > me) r = mid - 1;
//         else l = mid + 1;
//     }
//     printf("%llf\n", min({E(l),E(l-1),E(l-2),E(l+1),E(l+2),E(1)}));
// }

// signed main(){

//     IO;
//     int t;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e4 + 10;
// int n, m, p;

// void solve(){
//     cout << "20 20\n";
//     // cout << "11011111011111011111\n";
//     // cout << "01100101100101100101\n";
//     // cout << "10110110110110110110\n";
//     // cout << "10011011011011011011\n";
//     // cout << "11101101101101101101\n";
//     // cout << "10110110110110110111\n";
//     // cout << "11011011011011011001\n";
//     // cout << "01101101101101101100\n";
//     // cout << "10110110110110110110\n";
//     // cout << "10011011011011011011\n";
//     // cout << "11101101101101101101\n";
//     // cout << "10110110110110110111\n";
//     // cout << "11011011011011011001\n";
//     // cout << "01101101101101101100\n";
//     // cout << "10110110110110110111\n";
//     // cout << "10011011011011011001\n";
//     // cout << "11101101101101101101\n";
//     // cout << "10110110110110110111\n";
//     // cout << "11011010011010011001\n";
//     // cout << "01101111101111101111\n";
//     string mp[] = {
//         "888888-88888-88888-8",
//         "8--8--88-8--88-8---8",
//         "8-88-88-88-88-88-888",
//         "-88-88-88-88-88-88-8",
//         "88-88-88-88-88-88-88",
//         "8-88-88-88-88-88-88-",
//         "888-88-88-88-88-88-8",
//         "-8-88-88-88-88-88--8",
//         "--88-88-88-88-88-888",
//         "-88-88-88-88-88-88-8",
//         "88-88-88-88-88-88-88",
//         "8-88-88-88-88-88-88-",
//         "888-88-88-88-88-88-8",
//         "-8-88-88-88-88-88--8",
//         "--88-88-88-88-88-888",
//         "-88-88-88-88-88-88-8",
//         "88-88-88-88-88-88-88",
//         "8-88-88-88-88-88-88-",
//         "8-8--8-88--8-88--8-8",
//         "888-8888-88888-88888",
//     };

//     for(int i = 0;i < 20;i++){
//         for(int j = 0;j < 20;j++)
//             cout << (char)(mp[i][j] == '8' ? '1' : '0');
//         cout << '\n';
//     }
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
// const int N = 2e3 + 10;
// int n, a[N], fa[N], son[N];
// vector<int>g[N];
// int dp[N][N][2];

// void dfs(int u, int f){
//     dp[u][0][0] = a[u];
//     for(auto v : g[u]){
//         dfs(v, u);
//         son[u] += a[v];
//         dp[u][0][0] += dp[v][0][0];
//     }
//     dp[u][0][0] += son[u];
//     for(int i = 1;i <= n;i++){
//         dp[u][i][1] +=
//     }
// }

// void solve(){
//     cin >> n;
//     for(int i = 2;i <= n;i++) {
//         cin >> fa[i];
//         g[fa[i]].push_back(i);
//     }
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     dfs(1, 0);
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
// int n;

// void solve(){
//     string s;
//     cin >> n >> s;
//     s = ' ' + s;
//     int pos = 0;
//     for(int i = 1;i <= n;i++) {
//         if(s[i] == '0'){
//             pos = i;
//             break;
//         }
//     }

//     if(pos){
//         if(pos <= (n / 2)) cout << pos << ' ' << n << ' ' << pos + 1 << ' ' << n << '\n';
//         else cout << 1 << ' ' << pos << ' ' << 1 << ' ' << pos - 1 << '\n';
//     }else{
//         cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
//     }
// }

// int main(){

//     int t;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// int n, b[N];

// void solve(){
//     cin >> n;
//     int m = n;
//     vector<array<int, 2>>a(n+1);
//     for(int i = 1;i <= n;i++) cin >> a[i][0], a[i][1] = i;
//     sort(a.begin() + 1, a.end(), [](array<int, 2> e1, array<int, 2> e2)->int {return e1[0] > e2[0];});
//     if(n & 1){
//         m -= 3;
//         int e1 = abs(a[n-2][0]), e2 = abs(a[n-1][0]), e3 = abs(a[n][0]);
//         int lcm = e1 * (e2 + e3);

//         b[a[n-2][1]] = lcm / a[n-2][0];
//         b[a[n-1][1]] = -lcm / (e2 + e3) * (a[n-1][0]/e2);
//         b[a[n][1]] = -lcm / (e2 + e3) * (a[n][0] / e3);
//         // cout << lcm << ' ';
//     }
//     for(int i = 2;i <= m;i += 2){
//         int e1 = abs(a[i-1][0]), e2 = abs(a[i][0]);
//         int lcm = (e1*e2) / __gcd(e1,e2);
//         b[a[i-1][1]] = lcm / a[i-1][0];
//         b[a[i][1]] = -lcm / a[i][0];
//     }

//     for(int i = 1;i <= n;i++) cout << b[i] << ' ';
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
// #define int long long
// const int N = 1e5 + 10;
// int n, b[N];

// void solve(){
//     cin >> n;
//     int m = n;
//     vector<array<int, 2>>a(n+1);
//     for(int i = 1;i <= n;i++) cin >> a[i][0], a[i][1] = i;
//     sort(a.begin() + 1, a.end(), [](array<int, 2> e1, array<int, 2> e2)->int {return e1[0] > e2[0];});
//     if(n & 1){
//         m -= 3;
//         int e1 = abs(a[n-2][0]), e2 = abs(a[n-1][0]), e3 = abs(a[n][0]);
//         int lcm = e1 * (e2 + e3);

//         b[a[n-2][1]] = lcm / a[n-2][0];
//         b[a[n-1][1]] = -lcm / (e2 + e3) * (a[n-1][0]/e2);
//         b[a[n][1]] = -lcm / (e2 + e3) * (a[n][0] / e3);
//         // cout << lcm << ' ';
//     }
//     for(int i = 2;i <= m;i += 2){
//         int e1 = abs(a[i-1][0]), e2 = abs(a[i][0]);
//         int lcm = (e1*e2) / __gcd(e1,e2);
//         b[a[i-1][1]] = lcm / a[i-1][0];
//         b[a[i][1]] = -lcm / a[i][0];
//     }

//     for(int i = 1;i <= n;i++) cout << b[i] << ' ';
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
// #define int long long
// const int N = 1e4 + 10;
// int n, k, a_b[N], a[N];

// signed main(){

//     cin >> n >> k;
//     int _and, _or;
//     for(int i = 1;i < n;i++){
//         cout << "and " << i << ' ' << i + 1 << '\n';
//         fflush(stdout);
//         cin >> _and;

//         cout << "or " << i << ' ' << i + 1 << '\n';
//         fflush(stdout);
//         cin >> _or;

//         a_b[i] = _and + _or;
//     }

//     cout << "and " << 1 << ' ' << 3 << '\n';
//     fflush(stdout);
//     cin >> _and;
//     cout << "or " << 1 << ' ' << 3 << '\n';
//     fflush(stdout);
//     cin >> _or;

//     int a_c = _and + _or;

//     int s1 = a_b[1], s2 = a_b[2], s3 = a_c;
//     a[1] = (s1 - s2 + s3) / 2;
//     a[3] = s3 - a[1];
//     a[2] = s2 - a[3];

//     for(int i = 4;i <= n;i++){
//         a[i] = a_b[i-1] - a[i-1];
//     }
//     sort(a+1, a + 1 + n);

//     // cout << a_c;
//     cout << "finish " << a[k] << '\n';
//     // for(int i = 1;i <= n;i++) cout << a[i] << ' ';

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n;

// void solve(){
//     cin >> n;
//     vector<int>a(n+1);
//     priority_queue<int>que;
//     int s = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         s += a[i];
//     }
//     sort(a.begin() + 1, a.end());
//     que.push(s);
//     while(que.size()){
//         int mx = que.top();
//         que.pop();
//         if(mx < a.back()){
//             cout << "NO\n";
//             return;
//         }
//         if(a.back() == mx){
//             a.pop_back();
//             continue;
//         }
//         if(mx & 1){
//             if(a.back() == (mx / 2) + 1){
//                 a.pop_back();
//             }else{
//                 que.push((mx / 2) + 1);
//             }

//             if(a.back() == mx / 2){
//                 a.pop_back();
//             }else{
//                 que.push(mx / 2);
//             }
//         }else{
//             if(a.back() == mx / 2){
//                 a.pop_back();
//                 if(a.back() == mx / 2){
//                     a.pop_back();
//                 }else{
//                     que.push(mx / 2);
//                 }
//             }else{
//                 que.push(mx / 2);
//                 que.push(mx / 2);
//             }
//         }
//     }
//     cout << "YES\n";
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
// #define int long long
// const int N = 110;
// int n, a[N], b[N], sufa[N], sufb[N];

// void solve(){
//     cin >> n ;
//     int ans = 0;
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         ans += (n - 1) * a[i] * a[i];
//     }
//     for(int i = 1;i <= n;i++) {
//         cin >> b[i];
//         ans += (n - 1) * b[i] * b[i];
//     }

//     // for(int i = 1;i <= n;i++){
//     //     if(i != n){
//     //         if(a[i] > b[i]) swap(a[i], b[i]);}
//     //     else{
//     //         if(a[i] < b[i]) swap(a[i], b[i]);}
//     //     // cout << a[i] << ' ' << b[i] << '\n';
//     // }

//     for(int x = 0;x < 8;x++){
//         for(int j = 1;j <= 4;j++){
//             if((1 << (j - 1)) & x) swap(a[j], b[j]);
//         }
//         int tmp = 0;
//         sufa[n] = a[n];
//         sufb[n] = b[n];
//         for(int i = n - 1;i >= 1;i--){
//             sufa[i] = a[i] + sufa[i + 1];
//             sufb[i] = b[i] + sufb[i + 1];
//             tmp += 2 * a[i] * sufa[i + 1];
//             tmp += 2 * b[i] * sufb[i + 1];
//         }
//         cout << x << ' ' << tmp + ans << '\n';
//         for(int j = 1;j <= 4;j++){
//             if((1 << (j - 1)) & x) swap(a[j], b[j]);
//         }
//     }

//     // cout << ans << '\n';
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
// #define int long long
// const int N = 1e5 + 10;
// int n, a[N];

// void solve(){
//     cin >> n ;
//     int mx = 0;
//     int cnt = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(mx < a[i]){
//             mx = a[i];
//             cnt = 1;
//         }else if(a[i] == mx){
//             cnt++;
//         }
//     }

//     if(a[1] == mx){
//         if(cnt == 1)
//     cout << 0 << '\n';
//         else cout << 1 << '\n';
//     }
//     else
//     cout << mx - a[1] + 1<< '\n';
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
// const int N = 1e5 + 10;
// int n, a[N], m;
// int g[N];
// int vis[N];

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= m;i++){
//         int u, v;
//         cin >> u >> v;
//         g[v]++;
//     }
//     int ans = 0;
//     for(int i = 1;i <= n;i++) {
//         if(g[i] == 0){
//             if(ans){
//                 cout << "-1\n";
//                 return;
//             }else{
//                 ans = i;
//             }
//         }
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
// const int N = 2e5 + 10;
// int n;
// int a[N], m, b[N];

// void solve(){
//     cin >> n;
//     double sum = 0;
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         sum += a[i];
//     }
//     if(n == 1) {
//         cout << "0\n";
//         return;
//     }
//     int mx = 0, mn = LONG_LONG_MAX;
//     for(int i = 1;i <= n;i++){
//         mx = max(mx, a[i]);
//         mn = min(mn, a[i]);
//     }
//     if(mx - mn <= 1){
//         cout << "0\n";
//         return;
//     }

//     int av = sum / n;
//     int mor = sum - (av * n);
//     for(int i = 1;i <= n;i++) b[i] = av;
//     for(int i = n;i > n - mor;i--) b[i]++;

//     sort(a+1, a+1+n);
//     int cnt = 0;
//     for(int i = 1;i <= n;i++) cnt += abs(a[i] - b[i]);

//     cout << cnt/2 << '\n';

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
// const int N = 2e5 + 10;
// int n;
// int a[N], m, b[N];

// void solve(){

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
// const int N = 2e5 + 10;
// int n;
// int a[N], m, b[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++ ) cin >> a[i];
//     int ans = 0;
//     for(int i = 1;i < n;i++){
//         if(a[i] > a[i+1]){
//             ans = max(ans, a[i]);
//         }
//     }

//     cout << ans << '\n';

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

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// int n;
// int a[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++ ) cin >> a[i];
//     if(n == 1){
//         cout << "NO\n";
//         return;
//     }

//     int sum = 0, one = 0;
//     for(int i = 1;i <= n;i++){
//         if(a[i] == 1) one ++;
//         else sum += a[i] - 1;
//     }

//     if(sum >= one)
//         cout << "YES\n";
//     else
//         cout << "NO\n";

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

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1010;
// int n, k;
// int a[N], dp[N];

// bool check(int i, int x){
//     if(x + a[i] > dp[i + 1] + 1) return false;
//     if(x + a[i] <= a[i + 1] + 1) return true;

//     int cnt = x;
//     int ne = a[i] + x - 1;
//     for(int j = i + 1;j <= n;j++, ne--){
//         if(ne <= a[j]) break;
//         if(j == n) return false;
//         cnt += ne - a[j];
//     }
//     // if(ne + 1 > a[n-1] && ne > a[n]) return false;
//     return cnt <= k;
// }

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++ ) cin >> a[i];

//     int ans = dp[n-1] = max({min(a[n-1] + k, a[n] + 1), a[n-1], a[n]});

//     for(int i = n - 2;i >= 1;i--){
//         dp[i] = max(a[i], min(a[i] + k, a[i+1] + 1));
//         ans = max(ans, dp[i]);
//         if(a[i] + k <= a[i+1] + 1 || dp[i] >= dp[i+1] + 1) continue;
//         int l = 1, r = k;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(check(i, mid)) l = mid + 1;
//             else r = mid - 1;
//         }
//         if(check(i, l)) l++;
//         dp[i] = max(dp[i], a[i] + l - 1);
//         ans = max(ans, dp[i]);
//     }

//     // for(int i = 1;i <= n;i++) cout << dp[i] << ' ';
//     // cout << '\n';
//     cout << ans << '\n';
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

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 5010;
// int n, dp[N], siz[N];
// vector<int>g[N];

// void dfs(int u, int fa){
//     siz[u] = 1;
//     bitset<N>bt;
//     bt.set(0);
//     for(auto v : g[u]) if(v != fa){
//         dfs(v, u);
//         siz[u] += siz[v];
//         dp[u] += dp[v];
//         bt |= (bt << siz[v]);
//     }
//     int tmp = 0;
//     for(int s = 1;s <= n / 2;s++){
//         if(bt[s])
//             tmp = max(tmp, s * (siz[u] - 1 - s));
//     }
//     dp[u] += tmp;
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n;
//     for(int i = 2;i <= n;i++){
//         int p;
//         cin >> p;
//         g[i].push_back(p);
//         g[p].push_back(i);
//     }

//     dfs(1, 0);

//     cout << dp[1] << '\n';

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int n, ret;

// void ask(int l, int r){
//     if(l >= r){
//         ret = 0;
//         return;
//     }
//     cout << "? " << l << ' ' << r << '\n';
//     fflush(stdout);
//     cin >> ret;
// }

// void solve(){
//     cin >> n;
//     queue<int>q;
//     for(int i = 1;i <= n;i++) q.push(i);
//     while(q.size() > 1){
//         int l = q.front();
//         q.pop();
//         int r = q.front();
//         q.pop();

//         if(l > r){
//             q.push(l);
//             l = r;
//             r = q.front();
//             q.pop();
//         }

//         ask(l, r);
//         if(ret == -1) return;
//         int s1 = ret;
//         ask(l, r - 1);
//         int s2 = ret;

//         if(s1 == s2){    //右端点大
//             q.push(r);
//         }else{
//             q.push(l);
//         }
//     }
//     cout << "! " << q.front() << '\n';
// }

// int main(){

//     int t;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1010;
// int n, k;
// int a[N];

// bool check(int i, int x){
//     int cnt = x, ne = a[i] + x - 1;
//     for(int j = i + 1;j <= n;j++, ne--){
//         if(a[j] >= ne) break;
//         if(j == n) return false;
//         cnt += ne - a[j];
//     }
//     return cnt <= k;
// }

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++ ) cin >> a[i];

//     int ans = a[n];
//     for(int i = 1;i < n;i++){
//         int l = 1, r = k;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(check(i, mid)) l = mid + 1;
//             else r = mid - 1;
//         }
//         ans = max(ans, a[i] + l - 1);
//     }

//     cout << ans << '\n';
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

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 5e5 + 10;
// int n, m, R[N], x[N];

// void solve()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> x[i];
//     int sum = 0;
//     unordered_map<int,int> mp;
//     for (int i = 1; i <= n; i++)
//         cin >> R[i], sum += R[i] * R[i], mp[R[i]]++;
//     if(n == 1){cout << R[1]; return;}

//     int tmp = 0;
//     int a = n, b = 0, c = -sum;
//     for(int i = 2;i <= n;i++){
//         tmp = x[i] - x[i-1] - tmp;
//         c += tmp * tmp;
//         b += ((i % 2 == 0) ? -1 : 1) * 2 * tmp;
//         // cout << tmp << '\n';
//     }

//     // cout << a << ' ' << b << ' ' << c << '\n';

//     int r1 = 0, r2 = 0;
//     for(int i = 1;i <= n;i++) {
//         if(a * R[i] * R[i] + b * R[i] + c == 0){
//             r1 = R[i];
//             break;
//         }
//     }
//     for(int i = r2 - 2;i <= r2 + 2;i++) if(R[i] != r1){
//         if(a * R[i] * R[i] + b * R[i] + c == 0){
//             r2 = i;
//             break;
//         }
//     }

//     int head = r1;
//     bool ok = true;
//     if(r2){
//         int last = r1;
//         mp[last]--;
//         if(mp[last] < 0) ok = false;
//         for(int i = 2;i <= n && ok;i++){
//             int cur = x[i] - x[i-1] - last;
//             mp[cur]--;
//             if(mp[cur] < 0){
//                 ok = false;
//                 break;
//             }
//             last = cur;
//         }
//         if(!ok) head = r2;
//     }

//     cout << head << ' ';
//     for(int i = 2;i <= n;i++){
//         int cur = x[i] - x[i-1] - head;
//         head = cur;
//         cout << cur << ' ';
//     }
// }
// signed main()
// {
//     IOS;
//     int T = 1;
//     // cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 1000 + 10;
// int n, m, mp[N][N], mx[N];

// void solve()
// {
//     cin >> n;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= n;j++){
//             cin >> mp[i][j];
//             if(mp[i][mx[i]] < mp[i][j]) mx[i] = j;
//         }
//         if(i < n)
//             ans += mp[i][mx[i]];
//     }

//     cout << ans << '\n';
//     for(int i = n - 1;i >= 1;i--){
//         cout << i << ' ' << min(mx[i], i + 1) << '\n';
//     }
// }
// signed main()
// {
//     IOS;
//     int T = 1;
//     // cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 1e5 + 10;
// int n, a[N];

// void solve(){
//     cin >> n;
//     bool od = false;
//     bool ev = false;
//     int sum = 0;
//     for(int i = 1;i <= n;i ++ ) {
//         cin >> a[i];
//         sum += a[i];
//         if(a[i] & 1) od = true;
//         else ev = true;
//     }
//     for(int i = 1;i <= n;i++){
//         if((a[i] & 1) == ((sum - a[i]) & 1)){
//             cout << "YES\n";
//             return;
//         }
//     }
//     cout << "NO\n";
//     // cout << sum << '\n';

// }

// signed main(){
//     IOS;
//     int T = 1;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 1e5 + 10;
// int n, a[N];

// void solve(){
//     string s;
//     cin >> s;
//     for(int i = s.size() - 1;i >= 0;i--){
//         if(s[i] > '9'){
//             if(i - 1 >= 0){
//                 s[i-1] += s[i] - '9';

//             }else{
//                 s = '1' + s;
//                 i++;
//             }
//             s[i] = 'x';
//         }else if(s[i] >= '5'){
//             if(i - 1 >= 0){
//                 s[i-1]++;
//             }else{
//                 s = '1' + s;
//                 i++;
//             }
//             s[i] = 'x';
//         }
//     }

//     bool f = false;
//     for(int i = 0;i < s.size();i++){
//         if(s[i] == 'x') f = true;
//         if(f) cout << '0';
//         else cout << s[i];
//     }
//     cout << '\n';
// }

// signed main(){
//     IOS;
//     int T = 1;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 1e6 + 10;
// int n, m, b[N], a[N];

// void solve(){
//     cin >> n;
//     m = (n * (n - 1)) / 2;

//     map<int,int>mp;
//     for(int i = 1;i <= m;i++) cin >> b[i], mp[b[i]]++;

//     int pos = 1;
//     for(auto &[s, cnt] : mp){
//         while(cnt > 0){
//             a[pos] = s;
//             cnt -= (n - pos);
//             pos++;
//         }
//     }
//     while(pos <= n) a[pos++] = prev(mp.end())->first;
//     for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//     cout << '\n';
// }

// signed main(){
//     IOS;
//     int T = 1;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 2e5 + 10;
// int n, m, b[N];

// void solve(){
//     cin >> n;
//     vector<array<int, 2>>a(n+1);
//     for(int i = 1;i <= n;i++) cin >> a[i][0], a[i][1] = i;
//     for(int i = 1;i <= n;i++) cin >> b[i], a[i][0] -= b[i];

//     sort(a.begin() + 1, a.end());
//     int cnt = 0;
//     for(int i = n;i >= 1;i--){
//         if(a[i][0] == a[n][0]) cnt++;
//         else break;
//     }
//     cout << cnt << '\n';
//     for(int i = n -  cnt + 1;i <= n;i++) cout << a[i][1] << ' ';
//     cout << '\n';
// }

// signed main(){
//     IOS;
//     int T = 1;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 2e5 + 10;
// int n, m, ans[N];

// void solve(){
//     cin >> n;
//     vector<array<int, 2>>x(n+1);
//     for(int i = 1;i <= n;i++ ) cin >> x[i][0], x[i][1] = i;
//     sort(x.begin() + 1, x.end());
//     ans[x[1][1]] = 0;
//     for(int i = 1;i <= n;i++){
//         ans[x[1][1]] += x[i][0] - x[1][0] + 1;
//     }
//     for(int i = 2;i <= n;i++){
//         int id = x[i][1];
//         int pid = x[i-1][1];
//         if(x[i][0] == x[i-1][0]) {
//             ans[id] = ans[pid];
//             continue;
//         }
//         int pre = (i - 1) * (x[i][0] - x[i-1][0]);
//         int suf = (n - i + 1) * (x[i][0] - x[i-1][0]);
//         ans[id] = ans[pid] + pre - suf;
//     }

//     for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
//     cout << '\n';

// }

// signed main(){

//     IOS;
//     int T = 1;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 2e5 + 10;
// int q, n, m, a[N];

// void solve(){
//     cin >> n;
//     unordered_map<int, int>mp;
//     for(int i = 1;i <= n;i++) cin >> a[i], mp[a[i]]++;
//     cin >> q;
//     while(q--){
//         int x, y;
//         cin >> x >> y;
//         if(sqrt(x*x - 4 * y) < 0) {
//             cout << "0 ";
//             continue;
//         }
//         int e1 = (x + sqrt(x*x - 4 * y)) / 2;
//         int e2 = (x - sqrt(x*x - 4 * y)) / 2;
//         // cout << e1 << ' ' << e2 << '\n';
//         int f1 = x - e1;
//         int f2 = x - e2;

//         int ans = 0;
//         if(e1 == e2){
//             ans += (mp[e1] * (mp[f1]-1)) / 2;

//         }else{
//             if(e1 * f1 == y)
//             ans += mp[e1] * mp[f1];
//             if(e1 != e2 && e1 != f2)
//             if(e2 * f2 == y)
//                 ans += mp[e2] * mp[f2];
//         }
//         cout << ans << ' ';
//     }
//     cout << '\n';
// }

// signed main(){

//     IOS;
//     int T = 1;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 2e5 + 10;
// int q, n, m, a[N];

// int _sqrt(int x){
//     int ret = sqrtl(x);
//     while((ret + 1) * (ret + 1) <= x) ret++;
//     while(ret * ret > x) ret--;
//     return ret;
// }

// void solve(){
//     cin >> n;
//     unordered_map<int, int>mp;
//     for(int i = 1;i <= n;i++) cin >> a[i], mp[a[i]]++;
//     cin >> q;
//     while(q--){
//         int x, y;
//         cin >> x >> y;
//         int delt = sqrtl(x * x - 4 * y);
//         if(delt < 0) {
//             cout << "0 ";
//             continue;
//         }
//         int e1 = (x + delt) / 2;
//         int e2 = (x - delt) / 2;
//         int f1 = x - e1;
//         int f2 = x - e2;
//         for(int i = e1 - 3;i <= e1 + 3;i++){
//             if(i * (x - i) == y){
//                 e1 = i;
//                 break;
//             }
//         }
//         for(int i = e2 - 3;i <= e2 + 3;i++) if(i != e1 && i != f1){
//             if(i * (x - i) == y){
//                 e2 = i;
//                 break;
//             }
//         }
//         f1 = x - e1;
//         f2 = x - e2;

//         int ans = 0;
//         if(e1 == e2 || e1 == f2){
//             if(e1 * f1 == y){
//                 if(e1 == f1) ans += (mp[e1] * (mp[f1] - 1)) / 2;
//                 else ans += mp[e1] * mp[f1];
//             }
//         }else{
//             if(e1 * f1 == y){
//                 if(e1 == f1) ans += (mp[e1] * (mp[f1] - 1)) / 2;
//                 else ans += mp[e1] * mp[f1];
//             }
//             if(e2 * f2 == y){
//                 if(e2 == f2) ans += (mp[e2] * (mp[f2] - 1)) / 2;
//                 else ans += mp[e2] * mp[f2];
//             }
//         }
//         cout << ans << ' ';
//     }
//     cout << '\n';
// }

// signed main(){

//     IOS;
//     int T = 1;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 1000 + 10;
// int n, m, mp[N][N], mx[N], fa[N];

// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// void solve()
// {
//     cin >> n;
//     for(int i = 1;i <= n;i++) fa[i] = i;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= n;j++){
//             cin >> mp[i][j];
//             if(mp[i][mx[i]] < mp[i][j]) mx[i] = j;
//         }
//         if(i < n)
//             ans += mp[i][mx[i]];
//     }

//     cout << ans << '\n';
//     for(int i = n;i > 1;i--){
//         int e = min(find(mx[i]), i - 1);
//         cout << i << ' ' << e << '\n';
//         merg(i, e);
//     }
// }
// signed main()
// {
//     IOS;
//     int T = 1;
//     // cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int mod = 998244353;
// const int N = 5005;
// int n;

// int inv[N * N], fac[N * N];
// int qpow(int a, int q){
//     int ret = 1;
//     while(q){
//         if(q & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         q >>= 1;
//     }
//     return ret;
// }
// void init(){
//     fac[0] = 1;
//     for (int i = 1; i <= 5000 * 5000; ++i)
//         fac[i] = fac[i - 1] * i % mod;
//     inv[5000 * 5000] = qpow(fac[5000 * 5000], mod - 2);
//     for (int i = 5000 * 5000 - 1; i >= 0; --i)
//     {
//         inv[i] = inv[i + 1] * (i + 1) % mod;
//         inv[i] %= mod;
//     }
// }
// int C(int a, int b){
//     // if(!a || !b) return 1;
//     return (fac[a] * inv[b] % mod * inv[a - b] % mod);
// }

// void solve(){
//     cin >> n;
//     int ans = 0;
//     int nn = n * n;
//     for(int i = 1;i <= n;i++){
//         ans = (ans + C(nn - i, n - 1)) % mod;
//     }
//     ans = ((ans * n % mod) * fac[n] % mod) * fac[nn - n] % mod;
//     cout << ans << '\n';
// }

// signed main(){

//     IO;
//     init();
//     int T;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e5 + 10;
// const int mod = 998244353;
// int n, m, a[N];

// struct node{
//     int sum, tag;
//     bool flag;
// }tr[N<<2];
// int lowbit(int x){
//     return x & -x;
// }
// void up(int id){
//     tr[id].sum = (tr[lson].sum + tr[rson].sum) % mod;
//     tr[id].flag = (tr[lson].flag && tr[rson].flag);
// }
// void settag(int id, int x){
//     tr[id].sum *= x;
//     tr[id].sum %= mod;
//     tr[id].tag *= x;
//     tr[id].tag %= mod;
// }
// void down(int id){
//     if(tr[id].tag == 1) return;
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag = 1;
// }
// void build(int id, int l, int r){
//     tr[id].tag = 1;
//     if(l == r){
//         tr[id].sum = a[l];
//         if(lowbit(a[l]) == a[l]) tr[id].flag = true;
//         else tr[id].flag = false;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// void modify(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         if(tr[id].flag){
//             settag(id, 2);
//             return;
//         }else if(l == r){
//             tr[id].sum += lowbit(tr[id].sum);
//             // tr[id].sum %= mod;
//             if(tr[id].sum == lowbit(tr[id].sum)) tr[id].flag = true;
//             return;
//         }
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr);
//     else modify(lson, l, mid, ql, qr), modify(rson, mid + 1, r, ql, qr);
//     up(id);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].sum % mod;
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr) % mod;
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr) % mod;
//     else return (query(lson, l, mid, ql ,qr) + query(rson, mid + 1, r, ql, qr)) % mod;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);
//     cin >> m;
//     for(int i = 1;i <= m;i++){
//         int op, x, y;
//         cin >> op >> x >> y;
//         if(op == 1){
//             modify(1, 1, n, x, y);
//         }else{
//             cout << query(1, 1, n, x, y) % mod << '\n';
//         }
//     }
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
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int mod = 998244353;
// int n, dp[N][3];
// vector<int>g[N];

// void dfs(int u, int f){
//     dp[u][0] = dp[u][1] = 1;
//     dp[u][2] = 0;
//     int d2 = 1;
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         dp[u][0] *= dp[v][0] + dp[v][2];
//         dp[u][0] %= mod;
//         dp[u][1] *= dp[v][0];
//         dp[u][1] %= mod;
//         d2 *= dp[v][0] + dp[v][1] + dp[v][2];
//         d2 %= mod;
//     }
//     dp[u][2] = ((d2 + mod) - dp[u][1]) % mod;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) g[i].clear();
//     for(int i = 1;i < n;i++){
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);
//     int ans = (dp[1][0] + dp[1][2]) % mod;

//     cout << ans << '\n';
// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 1000 + 10;
// int n, m, mp[N][N], way[N], fa[N];

// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     if(a < b) swap(a, b);
//     fa[a] = b;
// }

// void solve()
// {
//     cin >> n;
//     for(int i = 1;i <= n;i++) fa[i] = i;
//     vector<array<int, 3>>g;
//     for(int i = 1;i <= n;i++)
//         for(int j = 1;j <= n;j++){
//             cin >> mp[i][j];
//             g.push_back({mp[i][j], i, j});
//         }

//     int ans = 0;
//     vector<array<int, 2>>way;
//     sort(g.begin(), g.end(), greater<array<int, 3>>());
//     for(auto [s, u, v] : g){
//         u = find(u);
//         v = find(v);
//         if(u == v) continue;
//         ans += s;
//         way.push_back({u, v});
//         merg(u, v);
//     }

//     cout << ans << '\n';
//     for(auto [u, v] : way) cout << u << ' ' << v << '\n';
// }
// signed main()
// {
//     IOS;
//     int T = 1;
//     // cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// using namespace std;
// const int N = 2e5 + 10;
// int n, a[N];

// void solve(){
//     cin >> n;
//     int sum = 0;
//     int ans = INT_MAX;
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         sum += a[i];
//         int tmp = 0;
//         int x = a[i] & 1;
//         while((a[i] & 1) == x){
//             tmp++;
//             a[i] /= 2;
//         }
//         ans = min(tmp, ans);
//     }

//     if(sum % 2 == 0) ans = 0;
//     cout << ans << '\n';
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// using namespace std;
// const int N = 1e5 + 10;
// int n, a[N];

// void solve(){
//     cin >> n;
//     vector<array<int, 2>>ans;
//     vector<array<int, 2>>a(n+1);
//     for(int i = 1;i <= n;i++) cin >> a[i][0], a[i][1] = i;
//     sort(a.begin()+1, a.end());

//     int cur = a[1][0];
//     for(int i = 2;i <= n;i++){
//         auto &[v, id] = a[i];
//         while(cur <= v) cur *= 2;
//         ans.push_back({id, cur - v});
//     }

//     cout << ans.size() << '\n';
//     for(auto [id, x] : ans) cout << id << ' ' << x << '\n';
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// using namespace std;
// const int N = 2e5 + 10;
// const int mod = 998244353;
// int n, a[N], pre1[N], pre0[N];

// int tree0[N], treei0[N];
// int lowbit(int x){
//   return x & -x;
// }
// void add0(int x, int v){
//   int vi = x * v;
//   while(x <= n){
//     tree0[x] += v;
//     treei0[x] += vi;
//     x += lowbit(x);
//   }
// }
// int getsum0(int x){
//   int s1 = 0, s2 = 0, r = x;
//   while(x){
//     s1 += tree0[x];
//     s2 += treei0[x];
//     x -= lowbit(x);
//   }
//   return (r + 1) * s1 - s2;
// }

// int tree1[N], treei1[N];
// void add1(int x, int v){
//   int vi = x * v;
//   while(x <= n){
//     tree1[x] += v;
//     treei1[x] += vi;
//     x += lowbit(x);
//   }
// }
// int getsum1(int x){
//   int s1 = 0, s2 = 0, r = x;
//   while(x){
//     s1 += tree1[x];
//     s2 += treei1[x];
//     x -= lowbit(x);
//   }
//   return (r + 1) * s1 - s2;
// }

// void solve(){
//     string s;
//     cin >> n;
//     cin >> s;
//     s = ' ' + s;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         if(s[i] == '1') pre1[i] = pre1[i-1] + 1, pre0[i] = pre0[i-1];
//         else pre0[i] = pre0[i-1] + 1, pre1[i] = pre1[i-1];
//     }

//     memset(tree0, 0, sizeof(tree0));
//     memset(tree1, 0, sizeof(tree1));
//     memset(treei0, 0, sizeof(treei0));
//     memset(treei1, 0, sizeof(treei1));

//     for(int i = 2;i <= n;i++)
//         if(s[i] == '1'){
//             //放1
//             ans = (ans + getsum1(i) - getsum1(i - pre1[i] - 2)) % mod;
//             add1(i - pre1[i], 1);
//             add1(i + 2, -1);
//             //放0
//             ans = (ans + getsum1(i) - getsum1(i - pre1[i] - 1)) % mod;
//             add1(i - pre1[i] + 1, 1);
//             add1(i + 2, -1);
//         }else{
//             //放0
//             ans = (ans + getsum0(i) - getsum0(i - pre0[i] - 2)) % mod;
//             add0(i - pre0[i], 1);
//             add0(i + 2, -1);
//             //放1
//             ans = (ans + getsum0(i) - getsum0(i - pre0[i] - 1)) % mod;
//             add0(i - pre1[i] + 1, 1);
//             add0(i + 2, -1);
//         }

//     cout << ans % mod << '\n';
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// using namespace std;
// const int N = 2e5 + 10;
// const int mod = 998244353;
// int n, a[N], pre1[N], pre0[N];

// struct node{
//     int sum, tag, len;
// };
// node tr1[N<<2];
// void settag1(int id, int v){
//     tr1[id].sum += v * tr1[id].len;
//     tr1[id].tag += v;
// }
// void up1(int id){
//     tr1[id].sum = tr1[lson].sum + tr1[rson].sum;
// }
// void down1(int id){
//     if(!tr1[id].tag) return;
//     settag1(lson, tr1[id].tag);
//     settag1(rson, tr1[id].tag);
//     tr1[id].tag = 0;
// }
// void modify1(int id, int l, int r, int ql, int qr, int v = 1){
//     if(ql <= l && r <= qr){
//         settag1(id, v);
//         return;
//     }
//     down1(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify1(lson, l, mid, ql, qr, v);
//     else if(ql > mid) modify1(rson, mid + 1, r, ql, qr, v);
//     else modify1(lson, l, mid, ql, qr, v), modify1(rson, mid + 1, r, ql, qr, v);
//     up1(id);
// }
// int query1(int id, int l, int r, int ql ,int qr){
//     if(ql <= l && r <= qr){
//         return tr1[id].sum % mod;
//     }
//     down1(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query1(lson, l, mid, ql, qr) % mod;
//     else if(ql > mid) return query1(rson, mid + 1, r, ql, qr) % mod;
//     else return (query1(lson, l, mid, ql, qr) + query1(rson, mid + 1, r, ql, qr)) % mod;
// }
// void build1(int id, int l ,int r){
//     if(l == r){
//         tr1[id].len = 1;
//         tr1[id].sum = 0;
//         return;
//     }
//     int mid = l + r >> 1;
//     build1(lson, l, mid);
//     build1(rson, mid + 1, r);
//     up1(id);
//     tr1[id].len = tr1[lson].len + tr1[rson].len;
// }
// //线段树
// node tr[N << 2];
// void settag(int id, int v){
//     tr[id].sum += v * tr[id].len;
//     tr[id].tag += v;
// }
// void up(int id){
//     tr[id].sum = tr[lson].sum + tr[rson].sum;
// }
// void down(int id){
//     if(!tr[id].tag) return;
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag = 0;
// }
// void modify(int id, int l, int r, int ql, int qr, int v = 1){
//     if(ql <= l && r <= qr){
//         settag(id, v);
//         return;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, v);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, v);
//     else modify(lson, l, mid, ql, qr, v), modify(rson, mid + 1, r, ql, qr, v);
//     up(id);
// }
// int query(int id, int l, int r, int ql ,int qr){
//     if(ql <= l && r <= qr){
//         return tr[id].sum % mod;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr) % mod;
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr) % mod;
//     else return (query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr)) % mod;
// }
// void build(int id, int l ,int r){
//     if(l == r){
//         tr[id].len = 1;
//         tr[id].sum = 0;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
//     tr[id].len = tr[lson].len + tr[rson].len;
// }

// void solve(){
//     string s;
//     cin >> n;
//     cin >> s;
//     s = ' ' + s;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         if(s[i] == '1') pre1[i] = pre1[i-1] + 1, pre0[i] = pre0[i-1];
//         else pre0[i] = pre0[i-1] + 1, pre1[i] = pre1[i-1];
//     }

//     build1(1, 1, n);
//     build(1, 1, n);
//     modify(1, 1, n, 1, 1, 1);
//     modify1(1, 1, n, 1, 1, 1);
//     // cout << query1(1, 1, n, 1, 1) << '\n';

//     for(int i = 2;i <= n;i++)
//         if(s[i] == '1'){
//             //放1
//             ans = (ans + query1(1, 1, n, i - pre1[i] - 1 + 1, i + 1)) % mod;
//             modify1(1, 1, n, i - pre1[i] + 1, i + 1 + 1);
//             modify1(1, 1, n, i - pre1[i] - 1 + 1, i + 1, -1);
//             //放0
//             ans = (ans + query1(1, 1, n, i - pre1[i] + 1, i + 1)) % mod;
//             modify1(1, 1, n, i - pre1[i] + 1 + 1, i + 1 + 1);
//             modify1(1, 1, n, i - pre1[i] + 1, i + 1, -1);
//         }else{
//             //放0
//             ans = (ans + query(1, 1, n, i - pre0[i] - 1 + 1, i + 1)) % mod;
//             modify(1, 1, n, i - pre0[i] + 1, i + 1 + 1);
//             modify(1, 1, n, i - pre0[i] - 1 + 1, i + 1, -1);
//             //放1
//             ans = (ans + query(1, 1, n, i - pre0[i] + 1, i + 1)) % mod;
//             modify(1, 1, n, i - pre0[i] + 1 + 1, i + 1 + 1);
//             modify(1, 1, n, i - pre0[i] + 1, i + 1, -1);
//         }

//     cout << (ans + 1) % mod << '\n';
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
// int n;

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n;
//     cout << ((n / 3) * ((n % 3) + n - 3)) / 2 + ((n / 3) * (2 + (n / 3 - 1)));

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1010;
// int n, m;
// string a[N];
// string a2[N];
// string b[N];

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) cin >> a[i], a[i] = ' ' + a[i] + ' ', a2[i] = a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i], b[i] = ' ' + b[i] + ' ';

//     int as = 0;
//     for(int i = 1;i <= n;i++)
//         for(int j = 1;j <= m;j++)
//             if(a[i][j] == 'X')
//             for(int x = i - 1;x <= i + 1;x++)
//                 for(int y = j - 1;y <= j + 1;y++)
//                     if(a[x][y] == '.') as++;

//     int bs = 0;
//     for(int i = 1;i <= n;i++)
//         for(int j = 1;j <= m;j++)
//             if(b[i][j] == 'X')
//             for(int x = i - 1;x <= i + 1;x++)
//                 for(int y = j - 1;y <= j + 1;y++)
//                     if(b[x][y] == '.') bs++;

//     bool ans = true;
//     if(a != b){
//         for(int i = 1;i <= n;i++)
//             for(int j = 1;j <= m;j++)
//                 a2[i][j] = (a[i][j] == '.' ? 'X' : '.');

//         int c1 = 0, c2 = 0;
//         for(int i = 1;i <= n;i++)
//             for(int j = 1;j <= m;j++)
//                 c1 += (a[i][j] != b[i][j]), c2 += (a2[i][j] != b[i][j]);

//         // cout << c1 << ' ' << c2 << '\n';
//         if(min(c1, c2) <= (n * m) / 2){
//         if(c1 < c2)
//             for(int i = 1;i <= n;i++) b[i] = a[i];
//         else
//             for(int i = 1;i <= n;i++) b[i] = a2[i];
//         }else{
//             ans = false;
//         }

//     }

//     if(!ans){
//         cout << -1;
//         return 0;
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             cout << b[i][j];
//         }
//         cout << '\n';
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1010;
// int n, m;
// struct node{
//     int del = 0;
//     bool all = false;
//     bool ignore = false;
//     string s;
//     list<node*> ne;

//     node(string s, bool ig) : s(s), ignore(ig) {}
// };

// list<node*>heads;

// node* get(list<node*> &ls, const string &s, bool ig){
//     node* ret = nullptr;
//     for(auto p : ls)
//         if(p->s == s){
//             ret = p;
//             break;
//         }
//     if(ret == nullptr){
//         ret = new node(s, ig);
//         ls.push_back(ret);
//     }
//     return ret;
// }

// void init(){
//     heads.clear();
// }

// void solve(){
//     init();
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++){
//         string s;
//         cin >> s;
//         vector<int>_pos;
//         for(int i = 0, len = s.length();i < len;i++){
//             if(s[i] == '/') s.push_back(i);
//         }
//         s.push_back(s.length());
//         string headstr(s.begin(), s.begin() + _pos.front());

//         node* cur = get(heads, headstr, true);

//         for(int i = 1, len = _pos.size();i < len;i++){
//             string fil(s.begin() + _pos[i-1] + 1, s.begin() + _pos[i]);
//             cur = get(cur->ne, fil, true);
//         }
//     }

//     for(int i = 1;i <= m;i++){
//         string s;
//         cin >> s;
//         vector<int>_pos;
//         for(int i = 0, len = s.length();i < len;i++){
//             if(s[i] == '/') s.push_back(i);
//         }
//         s.push_back(s.length());
//         string headstr(s.begin(), s.begin() + _pos.front());

//         node* cur = get(heads, headstr, false);

//         for(int i = 1, len = _pos.size();i < len;i++){
//             string fil(s.begin() + _pos[i-1] + 1, s.begin() + _pos[i]);
//             cur = get(cur->ne, fil, false);
//         }
//     }

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

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
// const int N = 1e6 + 10;
// int n, q, a[N];
// int B;
// int k, bid[N], preAns, ans[N], num[N], cnt[N];

// struct Query
// {
//     int ql, qr, ID;
//     int operator<(const Query &e) const
//     {
//         if (bid[ql] == bid[e.ql])
//             if (bid[ql] & 1)
//                 return qr < e.qr;
//             else
//                 return qr > e.qr;
//         return bid[ql] < bid[e.ql];
//     }
// };
// Query qry[N];

// void build()
// {
//     for (int i = 1; i <= n; i++)
//         bid[i] = (i - 1) / B + 1;
// }

// void add(int v)
// {
//     num[cnt[v]]--;
//     num[++cnt[v]]++;
//     preAns = max(preAns, num[cnt[v]]);
// }

// void del(int v)
// {
//     num[cnt[v]]--;
//     num[--cnt[v]]++;
//     if(cnt[v] + 1 == preAns && num[preAns] == 0)
//         preAns--;
// }

// void init(){
//     memset(num, 0, sizeof(num));
//     memset(cnt, 0, sizeof(cnt));
//     preAns = 0;
// }

// void solve(){
//     cin >> n >> q;
//     init();
//     B = sqrt(n);
//     vector<vector<int>>yz(n + 1);
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         for(int j = 2, sq = sqrt(a[i]);j <= sq;j++){
//             if(a[i] % j == 0){
//                 yz[i].push_back(j);
//                 while(a[i] % j == 0) a[i] /= j;
//             }
//         }
//         if(a[i] > 0) yz[i].push_back(a[i]);
//     }

//     build();

//     for(int i = 1;i <= q;i++){
//         cin >> qry[i].ql >> qry[i].qr;
//         qry[i].ID = i;
//     }
//     sort(qry + 1, qry + 1 + q);

//     for (int i = 1, l = 1, r = 0; i <= q; i++)
//     {
//         while (l < qry[i].ql){
//             for(auto ad : yz[l])
//                 del(ad);
//             l++;
//         }
//         while (r < qry[i].qr){
//             ++r;
//             for(auto ad : yz[r])
//                 add(a[++r]);
//         }
//         while (l > qry[i].ql){
//             --l;
//             for(auto ad : yz[l])
//                 add(ad);
//         }
//         while (r > qry[i].qr){
//             for(auto ad : yz[r])
//                 del(ad);
//             r--;
//         }
//         ans[qry[i].ID] = preAns;
//     }

//     for(int i = 1;i <= q;i++) cout << ans[i] << '\n';

// }

// signed main(){

//     IO;

//     int t;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define int long long
// using namespace std;
// const int N = 505;
// const int M = 1005;
// const int mod = 998244353;
// int n, m, p, q, mp[N][N];
// int dp[2][N][1005];

// signed main()
// {
//     IO;

//     cin >> n >> m >> p >> q;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             cin >> mp[i][j];

//     if(mp[1][1]) dp[1][1][0] = 1;
//     else dp[1][1][1] = 1;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//         {
//             if(i == 1 && j == 1) continue;
//             int cur = i & 1;
//             int last = 1 ^ cur;
//             if (mp[i][j])
//             {
//                 for (int k = 0; k <= 1002; k++){
//                     dp[cur][j][k] = 0;
//                     if(j - 1 >= 1)
//                         dp[cur][j][k] += dp[cur][j - 1][k];
//                     if(i - 1 >= 1)
//                         dp[cur][j][k] += dp[last][j][k];
//                     dp[cur][j][k] %= mod;
//                 }
//             }
//             else
//             {
//                 dp[cur][j][0] = 0;
//                 for (int k = 1; k <= 1002; k++){
//                     dp[cur][j][k] = 0;
//                     if(j - 1 >= 1)
//                         dp[cur][j][k] += dp[cur][j - 1][k - 1];
//                     if(i - 1 >= 1)
//                         dp[cur][j][k] += dp[last][j][k - 1];
//                     dp[cur][j][k] %= mod;
//                 }
//             }
// 		}

//     int cur = n & 1;
//     int ans = 0;
//     for (int i = p; i <= n + m - 1 - q; i++)
//     {
//         ans += dp[cur][m][i];
//         ans %= mod;
//     }

//     cout << ans;

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
// const int N = 1e6 + 10;
// int n, q, a[N];
// int B;
// int k, bid[N], preAns, ans[N], num[N], cnt[N];

// struct Query
// {
//     int ql, qr, ID;
//     int operator<(const Query &e) const
//     {
//         if (bid[ql] == bid[e.ql])
//             if (bid[ql] & 1)
//                 return qr < e.qr;
//             else
//                 return qr > e.qr;
//         return bid[ql] < bid[e.ql];
//     }
// };
// Query qry[N];

// void build()
// {
//     for (int i = 1; i <= n; i++)
//         bid[i] = (i - 1) / B + 1;
// }

// void add(int v)
// {
//     num[cnt[v]]--;
//     num[++cnt[v]]++;
//     preAns = max(preAns, cnt[v]);
// }

// void del(int v)
// {
//     num[cnt[v]]--;
//     num[--cnt[v]]++;
//     if(cnt[v] + 1 == preAns && num[preAns] == 0)
//         preAns--;
// }

// void init(){
//     memset(num, 0, sizeof(num));
//     memset(cnt, 0, sizeof(cnt));
//     preAns = 0;
// }

// void solve(){
//     cin >> n >> q;
//     init();
//     B = sqrt(n);
//     vector<vector<int>>yz(n + 1);
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         for(int j = 2, sq = sqrt(a[i]);j <= sq;j++){
//             if(a[i] % j == 0){
//                 yz[i].push_back(j);
//                 while(a[i] % j == 0) a[i] /= j;
//             }
//         }
//         if(a[i] > 0) yz[i].push_back(a[i]);
//     }

//     build();

//     for(int i = 1;i <= q;i++){
//         cin >> qry[i].ql >> qry[i].qr;
//         qry[i].ID = i;
//     }
//     sort(qry + 1, qry + 1 + q);

//     for (int i = 1, l = 1, r = 0; i <= q; i++)
//     {
//         while (l < qry[i].ql){
//             for(auto ad : yz[l])
//                 del(ad);
//             l++;
//         }
//         while (r < qry[i].qr){
//             ++r;
//             for(auto ad : yz[r])
//                 add(a[++r]);
//         }
//         while (l > qry[i].ql){
//             --l;
//             for(auto ad : yz[l])
//                 add(ad);
//         }
//         while (r > qry[i].qr){
//             for(auto ad : yz[r])
//                 del(ad);
//             r--;
//         }
//         ans[qry[i].ID] = preAns;
//     }

//     for(int i = 1;i <= q;i++) cout << ans[i] << '\n';

// }

// signed main(){

//     IO;

//     int t;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 1e3 + 10;
// int n, m, ans = 0;
// char mp[N][N];
// bool vis[N][N];
// int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// int xdir[4][2] = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

// bool check(int x, int y, int dx, int dy){
//     int nx = x + dx;
//     int ny = y + dy;
//     if(nx < 1 || nx > n || ny < 1 || ny > m) return false;
//     if(dx == dy && mp[x + dx][y] == '/' && mp[x][y + dy] == '/') return false;
//     if(dx != dy && mp[x + dx][y] == '\\' && mp[x][y + dy] == '\\') return false;

//     return true;
// }

// void bfs(int x, int y){
//     bool ot = false;
//     queue<array<int, 2>>que;
//     que.push({x, y});
//     while(que.size()){
//         auto [x, y] = que.front();
//         que.pop();
//         vis[x][y] = 1;
//         if(x == 1 || x == n || y == 1 || y == m) ot = true;
//         for(int i = 0;i < 4;i++){
//             int nx = x + dir[i][0];
//             int ny = y + dir[i][1];
//             if(mp[nx][ny] == '.' && vis[nx][ny] == 0) que.push({nx, ny});
//         }
//         for(int i = 0;i < 4;i++){
//             int nx = x + xdir[i][0];
//             int ny = y + xdir[i][1];
//             if(mp[nx][ny] == '.' && vis[nx][ny] == 0 && check(x, y, xdir[i][0], xdir[i][1])) que.push({nx, ny});
//         }
//     }

//     if(ot) ans--;
// }

// void solve()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//         {
//             cin >> mp[i][j];
//         }
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//         {
//             if (mp[i][j] == '.' && !vis[i][j])
//             {
//                 ans++;
//                 bfs(i, j);
//             }
//         }

//     for(int i = 1;i < n;i++){
//         for(int j = 1;j < m;j++){
//             if(mp[i][j] == '/' && mp[i][j+1] == '\\' && mp[i+1][j] == '\\' && mp[i+1][j+1] == '/') ans++, j++;
//         }
//     }

//     cout << ans;
// }

// signed main()
// {
//     // IOS;
//     int T = 1;
//     // cin >> T;
//     while (T--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 2e5 + 10;
// int n, k, a[N], fis[N], vis[N], pt[N];

// void solve()
// {
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         fis[a[i]] = i;
//     }

//     stack<int> st;
//     for (int i = 1; i <= n; i++) if(!vis[a[i]])
//     {   
//         while(st.size() && a[i] < st.top() && fis[st.top()] > i){
//             vis[st.top()] = 0;
//             st.pop();
//         }
//         st.push(a[i]);
//         vis[a[i]] = 1;
//     }

//     vector<int>ans;
//     while (st.size())
//     {
//         ans.push_back(st.top());
//         st.pop();
//     }

//     for(int i = ans.size() - 1;i >= 0;i--) cout << ans[i] << ' ';
// }

// signed main()
// {
//     IOS;
//     int T = 1;
//     // cin >> T;
//     while (T--)
//         solve();
//     return 0;
// }
