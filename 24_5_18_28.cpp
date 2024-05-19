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

//class Tree{
//public:
//	vector<int>mn, tag;
//	Tree(int n) : mn(n*4+5, inf), tag(n*4+5, inf) {};

//	void up(int id){
//		mn[id] = min(mn[ls], mn[rs]);
//	}
//	void settag(int id, int x){
//		mn[id] = min(mn[id], x);
//		tag[id] = min(tag[id], x);
//	}
//	void down(int id){
//		settag(ls, tag[id]);
//		settag(rs, tag[id]);
//		tag[id] = inf;
//	}
//	void modify(int id, int l, int r, int ql, int qr, int x) {
//		if(ql <= l && r <= qr){
//			settag(id, x);
//			return;
//		}
//		if(tag[id] < inf) down(id);
//		int mid = l + r >> 1;
//		if(qr <= mid) modify(ls, l, mid, ql, qr, x);
//		else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x);
//		else modify(ls, l, mid, ql, qr, x), modify(rs, mid + 1, r, ql, qr, x);
//		up(id);
//	}
//	int query(int id, int l, int r, int ql, int qr){
//		if(ql <= l && r <= qr) return mn[id];
//		if(tag[id] < inf) down(id);
//		int mid = l + r >> 1;
//		if(qr <= mid) return query(ls, l, mid, ql, qr);
//		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//		else return min(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//	}
//};

//void solve(){
//	int n;
//	cin >> n;
//	Tree tr(n);
//	vector<array<int,2>>E(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		E[i] = {u, v};
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}


//	int tot = 0;
//	vector<int>son(n+5), siz(n+5), dep(n+5), id(n+5), top(n+5), par(n+5);

//	auto dfs1 = [&](auto self, int u, int fa) -> void {
//		par[u] = fa;
//		dep[u] = dep[fa] + 1;
//		siz[u] = 1;
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//			siz[u] += siz[v];
//			if(siz[v] > siz[son[u]]) son[u] = v;
//		}
//	};
//	auto dfs2 = [&](auto self, int u, int tp) -> void {
//		top[u] = tp;
//		id[u] = ++tot;
//		if(son[u]) self(self, son[u], tp);
//		else return;

//		for(auto v : g[u]) if(v != par[u] && v != son[u]) self(self, v, v);
//	};
//	auto modify = [&](int u, int v, int w) -> void {
//		while(top[u] != top[v]){
//			if(dep[top[u]] < dep[top[v]]) swap(u, v);
//			tr.modify(1, 1, n, id[top[u]], id[u], w);
//			u = par[top[u]];
//		}
//		if(dep[u] < dep[v]) swap(u, v);
//		if(id[v]+1 <= id[u]) tr.modify(1, 1, n, id[v]+1, id[u], w);
//	};

//	dfs1(dfs1, 1, 0);
//	dfs2(dfs2, 1, 1);

//	for(int i = 1,x, y;i <= n/2;i++){
//		cin >> x >> y;
//		modify(x, y, i);
//	}

//	for(int i = 1;i < n;i++){
//		auto [u, v] = E[i];
//		if(dep[u] < dep[v]) swap(u, v);
//		int ret = tr.query(1, 1, n, id[u], id[u]);
//		if(ret == inf) ret = -1;
//		cout << ret << ' ';
//	}
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


//void solve(){
//	int n;
//	cin >> n;
//	double s = 180;
//	s /= n+1;
//	printf("%.8lf\n", s);
	
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

//void solve(){
//	int n;
//	cin >> n;
//	vector<string>s(n+5);
//	string S;
//	for(int i = 1;i <= n;i++){
//		cin >> s[i];
//		s[i] = ' ' + s[i] + ' ';
//	}	

//	auto dfs = [&](auto self, int rl, int rr, int cl, int cr) -> void {
//		if(rl == rr) {
//			S += s[rl][cl];
//			return;
//		}
//		int rmid = rl + rr >> 1;
//		int cmid = cl + cr >> 1;
//		self(self, rl, rmid, cl, cmid);
//		self(self, rl, rmid, cmid+1, cr);
//		self(self, rmid+1, rr, cl, cmid);
//		self(self, rmid+1, rr, cmid+1, cr);
//	};

//	dfs(dfs, 1, n, 1, n);

//	cout << S << endl;
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

//using i128 = __int128_t; 
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 5e5 + 10;

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>w(n+5), v(n+5), f(n*100+10, inf);
//	for(int i = 1;i <= n;i++) cin >> w[i] >> v[i];
	
//	f[0] = 0;
//	int sum = 0;
//	for(int i = 1;i <= n;i++){
//		for(int j = sum;j >= 0;j--) if(f[j] < inf){
//			f[j+v[i]] = min(f[j+v[i]], f[j]+w[i]);
//		}
//		sum += v[i];
//	}
//	int mn = inf;
//	for(int i = n*100+5;i >= 0;i--){
//		f[i] = min(mn, f[i]);
//		mn = min(mn, f[i]);
//	}

//	while(m--){
//		int x;
//		cin >> x;
//		cout << (upper_bound(all(f), x) - f.begin() - 1) << endl;
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
////#define ls id << 1
////#define rs id << 1 | 1

//using i128 = __int128_t; 
//using ll = long long;
//using i32 = int_fast32_t;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 2e5 + 10;
//const int M = N*100;
//const int delt = 1e15+5;
//const int mxn = 2e15+10;
//int n, l, r;

//int tr[M];
//i32 ls[M], rs[M], tot, rt;
//void up(int id){
//	tr[id] = tr[ls[id]] + tr[rs[id]];
//}
//void modify(i32& id, int l, int r, int x) {
//	if(!id) id = ++tot;
//	if(l == r) {
//		tr[id]++;
//		return;
//	}
//	int mid = l + r >> 1;
//	if(x <= mid) modify(ls[id], l, mid, x);
//	else modify(rs[id], mid + 1, r, x);
//	up(id);
//}
//int query(i32 id, int l, int r, int ql, int qr){
//	if(!id) return 0;
//	if(ql <= l && r <= qr) return tr[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls[id], l, mid, ql, qr);
//	else if(ql > mid) return query(rs[id], mid + 1, r, ql, qr);
//	else return query(ls[id], l, mid, ql, qr) + query(rs[id], mid + 1, r, ql, qr);
//}

//void add(int x){
//	x += delt;
//	modify(rt, 1, mxn, x);
//}
//int cnt(int l, int r){
//	l += delt, r += delt;
//	return query(rt, 1, mxn, l, r);
//}

//void solve(){
//	cin >> n >> l >> r;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];

//	int sum = 0, ans = 0;
//	for(int i = 1;i <= n;i++){
//		add(sum);
//		sum += a[i];
//		int L = -(r-sum);
//		int R = sum-l;
//		ans += cnt(L, R);
//	}	

//	cout << ans << endl;
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

//using i128 = __int128_t; 
//using ll = long long;
//using i32 = int_fast32_t;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 2e5 + 10;


//void solve(){
//	int n, a, b, ans = 0;
//	cin >> n >> a >> b;
//	vector<int>w(n+5), k(n+5), f(n+5);
//	for(int i = 1;i <= n;i++) cin >> w[i];
//	for(int i = 1;i <= n;i++) cin >> k[i];

//	int l = 0, mx = 0;
//	for(int i = 1;i <= n;i++){
//		f[i] = f[i-1];
//		if(k[i] == 2) continue;
//		while(l+a < i){
//			mx = max(mx, f[l++]);
//		}
//		f[i] = max(f[i], mx+w[i]);
//	}
//	ans += f[n];

//	l = 0, mx = 0;
//	f = vector<int>(n+5);
//	for(int i = 1;i <= n;i++){
//		f[i] = f[i-1];
//		if(k[i] == 1) continue;
//		while(l+b < i){
//			mx = max(mx, f[l++]);
//		}
//		f[i] = max(f[i], mx+w[i]);
//	}
//	ans += f[n];

//	cout << ans << endl;
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
////#define ls id << 1
////#define rs id << 1 | 1

//using i128 = __int128_t; 
//using ll = long long;
//using i32 = int_fast32_t;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 4e5 + 200;
//const int M = N*100;
//const int delt = 1e9+5;
//const int mxn = 2e9+10;

//i32 tr[M], tag[M], ls[M], rs[M], tot, rt;
//void settag(i32& id, int x){
//	if(!id) id = ++tot;
//	tag[id] += x;
//	tr[id] += x;
//}
//void down(i32 id){
//	settag(ls[id], tag[id]);
//	settag(rs[id], tag[id]);
//	tag[id] = 0;
//}
//void up(int id){
//	tr[id] = tr[ls[id]] + tr[rs[id]];
//}
//void modify(i32& id, int l, int r, int ql, int qr, int v){
//	if(!id) id = ++tot;
//	if(ql <= l && r <= qr) {
//		settag(id, v);
//		return;
//	}
//	if(tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(qr <= mid) modify(ls[id], l, mid, ql, qr, v);
//	else if(ql > mid) modify(rs[id], mid + 1, r, ql, qr, v);
//	else modify(ls[id], l, mid, ql, qr, v), modify(rs[id], mid + 1, r, ql, qr, v);
//	up(id);
//}
//int query(i32 id, int l, int r, int x){
//	if(!id) return 0;
//	if(l == r) return tr[id];
//	if(tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(x <= mid) return query(ls[id], l, mid, x);
//	else return query(rs[id], mid + 1, r, x);
//}

//struct sqr{
//	int x, y, w, h;
//}sq[N];

//int n, m, lx, ly;

//double X(double x1, double y1, double x2, double y2){
//	return (y2*(x1-x2))/(y2-y1) + x2;
//}
//void opt(int id, int ad){
//	int L, R;
//	auto [x, y, w, h] = sq[id];
//	if(lx >= x){
//		L = ceil(X(lx, ly, x, y+h));
//	}else{
//		L = ceil(X(lx, ly, x, y));
//	}

//	if(lx <= x+w){
//		R = floor(X(lx, ly, x+w, y+h));
//	}else{
//		R = floor(X(lx, ly, x+w, y));
//	}

//	L += delt;
//	R += delt;
//	L = max(1ll, L);
//	R = min(mxn, R);
//	modify(rt, 1, mxn, L, R, (ad ? 1 : -1));
//}
//int qur(int p){
//	p += delt;
//	return query(rt, 1, mxn, p);
//}


//void solve(){
//	cin >> n >> m >> lx >> ly;
//	int id, x, y, w, h;
//	for(int i = 1;i <= n;i++){
//		cin >> id >> x >> y >> w >> h;
//		sq[id] = {x, y, w, h};
//		opt(id, 1);
//	}

//	int op, p;
//	while(m--){
//		cin >> op;
//		if(op == 1){
//			cin >> id >> x >> y >> w >> h;
//			sq[id] = {x, y, w, h};
//			opt(id, 1);
//		}else if(op == 2){
//			cin >> id;
//			opt(id, 0);
//		}else{
//			cin >> p;
//			if(qur(p)) cout << "YES\n";
//			else cout << "NO\n";
//		}
//	}
//}

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}