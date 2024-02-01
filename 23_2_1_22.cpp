// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 3e5 + 10;
// int n, m, q;

// class Tree{
// public:
//     vector<int>mn, tag, a;

//     void up(int id){
//         mn[id] = min(mn[ls], mn[rs]);
//     }
//     void settag(int id, int x){
//         tag[id] += x;
//         mn[id] += x;
//     }
//     void down(int id){
//         settag(ls, tag[id]);
//         settag(rs, tag[id]);
//         tag[id] = 0;
//     }
//     void build(int id, int l, int r){
//         if(l == r){
//             mn[id] = a[l];
//             return;
//         }
//         int mid = l + r >> 1;
//         build(ls, l, mid);
//         build(rs, mid + 1, r);
//         up(id);
//     }

//     Tree(vector<int>v, int sz) : a(v), mn(sz*4+10), tag(sz*4+10) {
//         build(1, 1, sz);
//     }

//     int getmn(int id, int l, int r, int ql, int qr){
//         if(ql <= l && r <= qr) return mn[id];
//         if(tag[id]) down(id);
//         int mid = l + r >> 1;
//         if(qr <= mid) return getmn(ls, l, mid, ql, qr);
//         else if(ql > mid) return getmn(rs, mid + 1, r, ql, qr);
//         else return min(getmn(ls, l, mid, ql, qr), getmn(rs, mid + 1, r, ql, qr));
//     }

//     void modify(int id, int l, int r, int ql, int qr, int x){
//         if(ql <= l && r <= qr) {
//             settag(id, x);
//             return;
//         }
//         if(tag[id]) down(id);
//         int mid = l + r >> 1;
//         if(qr <= mid) modify(ls, l, mid, ql, qr, x);
//         else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x);
//         else modify(ls, l, mid, ql, qr, x), modify(rs, mid + 1, r, ql, qr, x);
//         up(id);
//     }
// };


// void solve(){
//     cin >> n >> m;
//     vector<int>a(n+5), b(m+5), v(n+5), pre(n+5), c(N);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= m;i++) cin >> b[i], c[1]++, c[b[i]+1]--;
    
//     vector<int>oa(a);
//     sort(all1(a), greater<int>());
//     for(int i = 1;i <= n;i++){
//         pre[i] += pre[i-1] + a[i];
//         c[i] += c[i-1];
//     }

//     for(int i = 1;i <= n;i++){
//         c[i] += c[i-1];
//         v[i] = c[i] - pre[i];
//     }

//     Tree tr(v, n);

//     sort(all1(a));

//     cin >> q;
//     while(q--){
//         int op, x;
//         cin >> op >> x;
//         if(op == 1){
//             int id = upper_bound(all1(a), oa[x]) - a.begin() - 1;
//             a[id]++;
//             id = n-id+1;
//             oa[x]++;
//             tr.modify(1, 1, n, id, n, -1);
//         }else if(op == 2){
//             int id = lower_bound(all1(a), oa[x]) - a.begin();
//             a[id]--;
//             id = n-id+1;
//             oa[x]--;
//             tr.modify(1, 1, n, id, n, 1);
//         }else if(op == 3){
//             b[x]++;
//             if(b[x] <= n) tr.modify(1, 1, n, b[x], n, 1);
//         }else{
//             if(b[x] <= n) tr.modify(1, 1, n, b[x], n, -1);
//             b[x]--;
//         }
//         if(tr.mn[1] >= 0) cout << "1\n";
//         else cout << "0\n";
//     }
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).begin() + 1 + n
#define ls id << 1
#define rs id << 1 | 1
const int N = 3e5 + 10;
int n, m, q;

void solve(){

} 

signed main(){

	IO;
	int t = 1;
	// cin >> t;
	while(t--) solve();

	return 0;
}