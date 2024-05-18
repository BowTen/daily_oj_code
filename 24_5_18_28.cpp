//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int x;
//	cin >> x;
//	cout << 69-x << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;
//using i128 = __int128_t; 

//i128 f(i128 x){
//	i128 ret = 0;
//	while(x){
//		ret += x;
//		x /= 10;
//	}
//	return ret;
//}

//void solve(){
//	int n;
//	cin >> n;
//	int l = 1, r = n;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(f(mid) <= n) l = mid + 1;
//		else r = mid - 1;
//	}

//	//cerr << r << endl;

//	int ans = n-r;
//	cout << ans << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;
//using i128 = __int128_t; 

//int lowbit(int x){
//	return x & -x;
//}

//void solve(){
//	int n, d;
//	cin >> n >> d;
//	int sum = 0, s = 0;
//	for(int i = 2;i <= n;i++){
//		sum += i;
//		s += (lowbit(i) == i);
//	}
//	while(d--){
//		int x;
//		cin >> x;
//		int ans = sum + s - x;
//		if(x == lowbit(x)) ans--;
//		cout << ans << endl;
//	}
//}

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;
//using i128 = __int128_t; 


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	int ans = 0;
//	for(int i = 2;i < n;i++) if(a[i-1] < a[i] && a[i] > a[i+1]){
//		ans++;
//		a[i+1] = max(a[i], a[i+2]);
//	}
//	cout << ans << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;
//using i128 = __int128_t; 


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), siz(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	auto dfs1 = [&](auto self, int u, int fa) -> void {
//		siz[u] = 1;
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//			siz[u] += siz[v];
//		}
//		sort(all(g[u]), [&](int i, int j) -> int {return siz[i] < siz[j];});
//	};
//	dfs1(dfs1, 1, 0);

//	auto dfs = [&](auto self, int u, int fa) -> void {
//		int s = a[u];
//		for(auto v : g[u]) if(v != fa){
//			a[v] = s;
//			self(self, v, u);
//			s += siz[v];
//		}
//	};

//	a[1] = 1;
//	for(auto v : g[1]){
//		a[v] = 1;
//		dfs(dfs, v, 1);
//	}

//	int mx = 0;
//	for(int i = 1;i <= n;i++) mx = max(mx, a[i]);

//	cout << mx << endl;
//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//	cout << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//using i128 = __int128_t; 
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;

//int qpow(int a, int b){
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>p(n+5), f(n+5), sw(n+5);
//	vector<vector<array<int,2>>>g(n+5);
//	for(int i = 1, u, v, w;i < n;i++) {
//		cin >> u >> v >> w;
//		g[u].push_back({v, w});
//		g[v].push_back({u, w});
//	}

//	p[1] = 1;
//	f[1] = 1;
//	auto dfs = [&](auto self, int u, int fa) -> void {
//		for(auto [v, w] : g[u]) if(v != fa) sw[u] = (sw[u] + w) % mod;
//		for(auto [v ,w] : g[u]) if(v != fa) {
//			p[v] = p[u] * (w * qpow(sw[u], mod-2) % mod) % mod;
//			f[v] = (f[u] + qpow(p[v], mod-2)) % mod;
//			self(self, v, u);
//		}
//	};

//	dfs(dfs, 1, 0);

//	for(int i = 1;i <= n;i++) cout << f[i] << ' ';
//	cout << endl;

//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//using i128 = __int128_t; 
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 5e5 + 10;

//int n;
//vector<int>g[N];
//int id[N], tot;
//int dep[N], par[N], top[N], siz[N], son[N];

//int mn[N<<2], tag[N<<2];
//void settag(int id, int v){
//	mn[id] = min(mn[id], v);
//	tag[id] = min(tag[id], v);
//}
//void up(int id){
//	mn[id] = min(mn[ls], mn[rs]);
//}
//void down(int id){
//	if(tag[id] == inf) return;
//    settag(ls, tag[id]);
//    settag(rs, tag[id]);
//    tag[id] = inf;
//}
//void build(int id, int l ,int r){
//	tag[id] = inf;
//    if(l == r){
//		mn[id] = inf;
//        return;
//    }
//    int mid = l + r >> 1;
//    build(ls, l, mid);
//    build(rs, mid + 1, r);
//    up(id);
//}
//void modify(int id, int l, int r, int ql, int qr, int x){
//	if(ql <= l && r <= qr){
//		settag(id, x);
//		return;
//	}
//	if(tag[id] != inf) down(id);
//	int mid = l + r >> 1;
//	if(qr <= mid) modify(ls, l, mid, ql, qr, x);
//	else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x);
//	else modify(ls, l, mid, ql, qr, x), modify(rs, mid + 1, r, ql, qr, x);
//	up(id);
//}
//int query(int id, int l, int r, int ql ,int qr){
//    if(ql <= l && r <= qr) return mn[id];
//    if(tag[id] != inf) down(id);
//    int mid = l + r >> 1;
//    if(qr <= mid) return query(ls, l, mid, ql, qr);
//    else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//    else return min(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//}


//void dfs(int u, int fa){
//    dep[u] = dep[fa] + 1;
//    par[u] = fa;
//    siz[u] = 1;
//    for(auto v : g[u]) if(v != fa) {
//        dfs(v, u);
//        siz[u] += siz[v];
//        if(siz[son[u]] < siz[v])
//            son[u] = v;
//    }
//}
//void dfs2(int u, int tp){
//    top[u] = tp;
//    id[u] = ++ tot;
//    if(son[u]) dfs2(son[u], tp);
//    else return;

//    for(auto v : g[u]) if(v != par[u] && v != son[u])
//        dfs2(v, v);
//}


//void line_modify(int u, int v, int w){
//    while(top[u] != top[v]){
//        if(dep[top[u]] < dep[top[v]]) swap(u, v);
//        modify(1, 1, n, id[top[u]], id[u], w);
//        u = par[top[u]];
//    }
//    if(dep[u] < dep[v]) swap(u, v);
//    if(id[v]+1 <= id[u]) modify(1, 1, n, id[v]+1, id[u], w);
//}

//void init(){
//	tot = 0;
//	for(int i = 1;i <= n;i++){
//		g[i].clear();
//		siz[i] = id[i] = son[i] = dep[i] = par[i] = top[i] = 0;
//	}
//}

//void solve(){
//	cin >> n;
//	vector<array<int,2>>E(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		E[i] = {u, v};
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	dfs(1, 0);
//	dfs2(1, 1);
//	build(1, 1, n);

//	line_modify(2, 3, 5);
//	line_modify(4, 5, 5);
//	for(int i = 1;i <= n;i++) cerr << query(1, 1, n, id[i], id[i]) << endl;

//	//for(int i = 1, x, y;i <= n/2;i++){
//	//	cin >> x >> y;
//	//	line_modify(x, y, i);
//	//}

//	//for(int i = 1;i < n;i++){
//	//	auto [u, v] = E[i];
//	//	if(dep[u] < dep[v]) swap(u, v);
//	//	cout << query(1, 1, n, id[u], id[u]) << ' ';
//	//}
//	//cout << endl;

//	init();
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin()+1, (x).begin()+1+n
#define ls id << 1
#define rs id << 1 | 1

using i128 = __int128_t; 
const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 10;

class Tree{
public:
	vector<int>mn, tag;
	Tree(int n) : mn(n*4+5, inf), tag(n*4+5, inf) {};

	void up(int id){
		mn[id] = min(mn[ls], mn[rs]);
	}
	void settag(int id, int x){
		mn[id] = min(mn[id], x);
		tag[id] = min(tag[id], x);
	}
	void down(int id){
		settag(ls, tag[id]);
		settag(rs, tag[id]);
		tag[id] = inf;
	}
	void modify(int id, int l, int r, int ql, int qr, int x) {
		if(ql <= l && r <= qr){
			settag(id, x);
			return;
		}
		if(tag[id] < inf) down(id);
		int mid = l + r >> 1;
		if(qr <= mid) modify(ls, l, mid, ql, qr, x);
		else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x);
		else modify(ls, l, mid, ql, qr, x), modify(rs, mid + 1, r, ql, qr, x);
		up(id);
	}
	int query(int id, int l, int r, int ql, int qr){
		if(ql <= l && r <= qr) return mn[id];
		if(tag[id] < inf) down(id);
		int mid = l + r >> 1;
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
		else return min(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
	}
};

void solve(){
	int n;
	cin >> n;
	Tree tr(n);
	vector<array<int,2>>E(n+5);
	vector<vector<int>>g(n+5);
	for(int i = 1, u, v;i < n;i++){
		cin >> u >> v;
		E[i] = {u, v};
		g[u].push_back(v);
		g[v].push_back(u);
	}


	int tot = 0;
	vector<int>son(n+5), siz(n+5), dep(n+5), id(n+5), top(n+5), par(n+5);

	auto dfs1 = [&](auto self, int u, int fa) -> void {
		par[u] = fa;
		dep[u] = dep[fa] + 1;
		siz[u] = 1;
		for(auto v : g[u]) if(v != fa){
			self(self, v, u);
			siz[u] += siz[v];
			if(siz[v] > siz[son[u]]) son[u] = v;
		}
	};
	auto dfs2 = [&](auto self, int u, int tp) -> void {
		top[u] = tp;
		id[u] = ++tot;
		if(son[u]) self(self, son[u], tp);
		else return;

		for(auto v : g[u]) if(v != par[u] && v != son[u]) self(self, v, v);
	};
	auto modify = [&](int u, int v, int w) -> void {
		while(top[u] != top[v]){
			if(dep[top[u]] < dep[top[v]]) swap(u, v);
			tr.modify(1, 1, n, id[top[u]], id[u], w);
			u = par[top[u]];
		}
		if(dep[u] < dep[v]) swap(u, v);
		if(id[v]+1 <= id[u]) tr.modify(1, 1, n, id[v]+1, id[u], w);
	};

	dfs1(dfs1, 1, 0);
	dfs2(dfs2, 1, 1);

	for(int i = 1,x, y;i <= n/2;i++){
		cin >> x >> y;
		modify(x, y, i);
	}

	for(int i = 1;i < n;i++){
		auto [u, v] = E[i];
		if(dep[u] < dep[v]) swap(u, v);
		int ret = tr.query(1, 1, n, id[u], id[u]);
		if(ret == inf) ret = -1;
		cout << ret << ' ';
	}
	cout << endl;
	
}

signed main(){

	IO;
	int t = 1;
	cin >> t;
	while(t--) solve();

	return 0;
}