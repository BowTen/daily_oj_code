//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'

//const int N = 3e4+5;
//const int p = 1e7+19;
//const int mod = 1e9+7;

//int pw[N];

//int n, k, q;
//int v[N<<1], w[N<<1];

//vector<int>tr[N<<2];
//#define ls id << 1
//#define rs id << 1 | 1
//void insert(int id, int l, int r, int ql, int qr, int x) {
//	if(ql <= l && r <= qr) {
//		tr[id].push_back(x);
//		return;
//	}
//	int mid = l + r >> 1;
//	if(qr <= mid) insert(ls, l, mid, ql, qr, x);
//	else if(ql > mid) insert(rs, mid + 1, r, ql, qr, x);
//	else insert(ls, l, mid, ql, qr, x), insert(rs, mid + 1, r, ql, qr, x);
//}
//void dfs(int id, int fa, int l, int r, int *g){
//	int f[k+1];
//	for(int i = 0;i <= k;i++) f[i] = g[i];
//	for(auto p : tr[id]) {
//		for(int i = k;i >= w[p];i--) f[i] = max(f[i], f[i-w[p]]+v[p]);
//	}
//	if(l == r){
//		int ans = 0;
//		for(int i = 1;i <= k;i++) (ans += f[i] * pw[i-1] % mod) %= mod;
//		cout << ans << endl;
//	}else{
//		int mid = l + r >> 1;
//		dfs(ls, id, l, mid, f);
//		dfs(rs, id, mid + 1, r, f);
//	}
//}
//int f[1001] = {0};

//void solve(){
//	cin >> n >> k;
//	for(int i = 1;i <= n;i++){
//		cin >> v[i] >> w[i];
//	}
//	cin >> q;
//	vector<int>l(q+n+5, 1), r(q+n+5, -1);
//	int m = 0, op, a, b;
//	for(int i = 1;i <= q;i++){
//		cin >> op;
//		if(op == 1){
//			cin >> a >> b;
//			++n;
//			v[n] = a;
//			w[n] = b;
//			l[n] = m+1;
//		}else if(op == 2){
//			cin >> a;
//			r[a] = m;
//		}else{
//			m++;
//		}
//	}
//	for(int i = 1;i <= n;i++) if(l[i] <= r[i] || (r[i] == -1 && l[i] <= m)) {
//		if(r[i] == -1) r[i] = m;
//		insert(1, 1, m, l[i], r[i], i);
//	}
//	dfs(1, 0, 1, m, f);
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	pw[0] = 1;
//	for(int i = 1;i <= 1000;i++) pw[i] = pw[i-1]*p % mod;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, m, x;
//	cin >> n >> m >> x;
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	if(g[n].size() == 1) {
//		cout << "Boring Game\n";
//		return;
//	}

//	vector<int>dis(n+5, inf), vis(n+5);
//	queue<int>que;
//	dis[x] = 0;
//	que.push(x);
//	vis[x] = 1;
//	while(que.size()){
//		int u = que.front();
//		que.pop();
//		for(auto v : g[u]) if(!vis[v] && v != 1) {
//			vis[v] = 1;
//			dis[v] = dis[u] + 1;
//			que.push(v);
//		}
//	}

//	vector<vector<int>>ds(3, vector<int>(n+5, inf));
//	ds[2] = vector<int>(n+5, 0);
//	vector<int>p(n+5);
//	priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>>pque;
//	for(auto v : g[1]) if(dis[v] != inf) {
//		ds[p[v]][v] = dis[v];
//		pque.push({ds[p[v]][v], 1, v});
//		p[v]++;
//		//cerr << v << ' ' << dis[v] << endl;
//	}

//	while(pque.size()){
//		auto [d, pre, u] = pque.top();
//		pque.pop();
//		if(d > ds[p[u]-1][u]) continue;
//		for(auto v : g[u]) if(v != pre && d+1 < ds[p[v]][v]) {
//			ds[p[v]][v] = d+1;
//			pque.push({d+1, u, v});
//			p[v]++;
//		}
//	}
//	int ans = min(ds[0][n], ds[1][n]);
//	if(ans == inf) cout << "Boring Game\n";
//	else cout << "Vegetable fallleaves\n" << ans+1 << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 5;
int fa[N], d[N];

int find(int x){
	if(x != fa[x]){
		int f = find(fa[x]);
		d[x] ^= d[fa[x]];
		fa[x] = f;
	}
	return fa[x];
}
void merg(int a, int b, int x){
	fa[a] = fa[b];
	d[fa[a]] = d[b] ^ x ^ d[a];
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string>op(m+5);
	vector<int>l(m+5), r(m+5), idx;
	for(int i = 1;i <= m;i++){
		cin >> l[i] >> r[i] >> op[i];
		idx.push_back(l[i]);
		idx.push_back(r[i]);
	}

	sort(all(idx));
	idx.erase(unique(all(idx)), idx.end());

	for(int i = 1;i < N;i++) fa[i] = i;
	for(int i = 1;i <= m;i++){
		l[i] = lower_bound(all(idx), l[i]) - idx.begin() + 1;
		r[i] = lower_bound(all(idx), r[i]) - idx.begin() + 2;
	}
	for(int i = 1;i <= m;i++){
		int x = 0;
		if(op[i][0] == 'o') x = 1;
		if(find(l[i]) == find(r[i])) {
			if((d[l[i]] ^ d[r[i]]) != x) {
				cout << i-1 << endl;
				return;
			}
		} else{
			merg(l[i], r[i], x);
		}
	}
	cout << m << endl;
}

signed main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) solve();

	return 0;
}