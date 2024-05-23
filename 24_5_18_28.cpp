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


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
////#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 4e5 + 200;


//void solve(){
//	int n, k, mx = 0, ct = 0, ret;
//	cin >> n >> k;
//	for(int i = 1;i <= n;i++){
//		ct++;
//		cout << "? 1 " << n*i << endl;
//		cin >> ret;
//		if(ret == n){
//			mx = i;
//			break;
//		}
//	}

//	for(int i = mx;ct < 2*n;i += mx){
//		int tmp = 0, p = 1;
//		while(tmp < k && ct < 2*n && p <= n){
//			ct++;
//			tmp++;
//			cout << "? " << p << ' ' << i << endl;
//			cin >> ret;
//			p = ret+1;
//		}
//		if(p == n+1 && tmp == k){
//			cout << "! " << i << endl;
//			cin >> ret;
//			return;
//		}
//	}

//	cout << "! -1" << endl;
//	cin >> ret;
	
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
//const int N = 4e5 + 200;


//void solve(){
//	int n;
//	cin >> n;
//	if(n % 3 == 1){
//		cout << "-1\n";
//		return;
//	}

//	cout << ((2*n+1)*(2*n+1) - 1 - 2*n*(n+1))/3 << endl;
//	for(int i = n;i >= 2;i -= 3){
//		int m = i-1, x = n+1, y = 1+n-i;
//		while(m--){
//			cout << x << ' ' << y << ' ' << x << ' ' << y+1 << ' ' << x+1 << ' ' << y+1 << endl;
//			x--, y++;
//		}
//	}
//	for(int i = n;i >= 2;i -= 3){
//		int m = i-1, x = 1+n-i, y = n+1;
//		while(m--){
//			cout << x << ' ' << y << ' ' << x+1 << ' ' << y << ' ' << x+1 << ' ' << y-1 << endl;
//			x++, y++;
//		}
//	}
//	for(int i = n;i >= 2;i -= 3){
//		int m = i-1, x = n+1, y = 2*n-(n-i)+1;
//		while(m--){
//			cout << x << ' ' << y << ' ' << x << ' ' << y-1 << ' ' << x-1 << ' ' << y-1 << endl;
//			x++, y--;
//		}
//	}
//	for(int i = n;i >= 2;i -= 3){
//		int m = i-1, x = 2*n-(n-i)+1, y = n+1;
//		while(m--){
//			cout << x << ' ' << y << ' ' << x-1 << ' ' << y << ' ' << x-1 << ' ' << y+1 << endl;
//			x--, y--;
//		}
//	}
	
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

//class Tree{
//public:
//	vector<int>tr, tag;
//	Tree(int n) : tr(n*4+5), tag(n*4+5, -1) {};

//	void settag(int id, int x){
//		tr[id] = x;
//		tag[id] = x;
//	}
//	void down(int id){
//		settag(ls, tag[id]);
//		settag(rs, tag[id]);
//		tag[id] = -1;
//	}
//	void modify(int id, int l, int r, int ql, int qr, int x) {
//		if(ql <= l && r <= qr){
//			settag(id, x);
//			return;
//		}
//		if(~tag[id]) down(id);
//		int mid = l + r >> 1;
//		if(qr <= mid) modify(ls, l, mid, ql, qr, x);
//		else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x);
//		else modify(ls, l, mid, ql, qr, x), modify(rs, mid + 1, r, ql, qr, x);
//	}
//	int query(int id, int l, int r, int x) {
//		if(l == r) return tr[id];
//		if(~tag[id]) down(id);
//		int mid = l + r >> 1;
//		if(x <= mid) return query(ls, l, mid, x);
//		else return query(rs, mid + 1, r, x);
//	}
//};

////void solve(int n, vector<int>&a, vector<int>&b){
////	int tot = 0;
////	Tree tr(n);
////	vector<int>vis(n+5), dfn(n+5), L(n+5), R(n+5);
////	vector<vector<int>>g(n+5);
////	for(int i = 1;i <= n;i++) g[a[i]].push_back(i);

////	auto dfs = [&](auto self, int u, int fa, int s) -> void {
////		L[u] = dfn[u] = ++tot;
////		for(auto v : g[u]) if(v != fa){
////			self(self, v, u, s);
////		}
////		R[u] = tot;
////	};


////	for(int i = 1;i <= n;i++) if(!a[i]){
////		dfs(dfs, i, 0, i);
////	}

////	for(int i = 1;i <= n;i++) if(!vis[i]){
////		stack<int>st;
////		int u = i;
////		while(u){
////			vis[u] = 1;
////			st.push(u);
////			u = b[u];
////		}
////		while(st.size()){
////			u = st.top();
////			st.pop();
////			if(tr.query(1, 1, n, L[u])){
////				cout << u-1 << endl;
////				return;
////			}
////			tr.modify(1, 1, n, L[u], R[u], 1);
////		}
////		tr.tag[1] = tr.tr[1] = 0;
////	}

////	cout << -1 << endl;
////}

//void solve(int n, vector<int>a, vector<int>b)
//{
//	for(int i = 0;i < n;i++){
//		a[i] = a[i+1]-1;
//		b[i] = b[i+1]-1;
//	}
//        for(int i=0;i<n;i++)
//        {
//                if(a[i]==-1||b[i]==-1) continue;
//                else
//                {
//                        int k1=i;
//                        int k2=i;
//                        while(a[k1]!=-1&&b[k2]!=-1)
//                        {
//                                if(a[k1]==b[k2])
//                                {
//                                        cout<<i;
//                                        return;
//                                }
//                                k1=a[k1];
//                                k2=b[k2];
//                        }
//                }
//        }
//        cout<<-1;
//}

//signed main(){

//	IO;
//	int t = 1;
	
//	int n = 5000005;
//	vector<int>a(n+10), b(n+10);
//	for(int i = 1;i < n;i++) {
//		if(i&1) a[i] = i+1;
//	}
//	for(int i = 1;i < n;i++){
//		if(i&1) b[i] = i+2;
//		else b[i] = i+1;
//	}
//	n += 2;
//	a[n-1] = n;
//	b[n-1] = n;
	
//	while(t--) solve(n, a, b);

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

//void solve(){
//	int n, c;
//	cin >> n >> c;
//	vector<int>a(n+5), pre(n+5), suf(n+5);
//	unordered_map<int,vector<int>>pos;
//	for(int i = 1;i <= n;i++) cin >> a[i], pos[a[i]].push_back(i);
//	for(int i = 1;i <= n;i++) pre[i] = pre[i-1] + (a[i] == c);
//	for(int i = n;i >= 1;i--) suf[i] = suf[i+1] + (a[i] == c);

//	int ans = pre[n];

//	for(auto &[v, p] : pos){
//		int m = p.size();
//		vector<int>L(m), R(m);
//		for(int i = 0;i < m;i++) L[i] = pre[p[i]-1], R[i] = suf[p[i]+1];
//		int mx = 0;
//		for(int i = 0;i < m;i++){
//			mx = max(mx, L[i]-i+1);
//			ans = max(ans, i+R[i]+mx);
//		}
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

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>fa(n*2+5);
//	iota(all(fa), 0);
//	vector<vector<int>>mp(n+5, vector<int>(n+5));
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++) cin >> mp[i][j];
//	}

//	auto find = [&](auto self, int x) -> int {
//		return x == fa[x] ? x : fa[x] = self(self,  fa[x]);
//	};
//	auto merg = [&](int a, int b) {
//		a = find(find, a);
//		b = find(find, b);
//		fa[a] = b;
//	};

//	for(int i = 1;i <= n;i++){
//		for(int j = 1+i;j <= n;j++) {
//			if(mp[i][j] == mp[j][i]) continue;
//			if(mp[i][j] > mp[j][i]) {
//				if(find(find, i) != find(find, j) && find(find, i+n) != find(find, j+n)) {
//					merg(i, j+n);
//					merg(i+n, j);
//					swap(mp[i][j], mp[j][i]);
//				} 
//			}else{
//				if(find(find, i) != find(find, j+n) && find(find, i+n) != find(find, j)){
//					merg(i, j);
//					merg(i+n, j+n);
//				}else{
//					swap(mp[i][j], mp[j][i]);
//				}
//			}
//		}
//	}

//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			cout << mp[i][j] << ' ';
//		}
//		cout << endl;
//	}

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

//void solve(){
//	int f, a, n;
//	cin >> f >> a >> n;
//	if(a == 1){
//		cout << "AMBOS\n";
//		return;
//	}
//	if((n % a) > 1){
//		cout << ":(\n";
//		return;
//	}
//	int r = (n+a-1)/a;
//	if(n % a){
//		if(r & 1) cout << "VENTANA\n";
//		else cout << "PASILLO\n";
//	}else{
//		if(r%2 == 0) cout << "VENTANA\n";
//		else cout << "PASILLO\n";
//	}
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

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(all1(a));
//	int mn = a[1], ans = 0;
//	while(1){
//		int cnt = 0;
//		for(int i = 1;i <= n;i++){
//			while(a[i] > mn){
//				a[i] >>= 1;
//				cnt++;
//				ans++;
//			}
//			mn = min(a[i], mn);
//		}
//		if(!cnt) break;
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

//const int N = 1e6 + 10;
//bool isprime[N];
//int prime[N];
//int cnt;

//void euler(){
//    memset(isprime, true, sizeof(isprime));
//    isprime[1] = false;
//    for(int i = 2;i < N;i++){
//        if(isprime[i]) prime[++cnt] = i;
//        for(int j = 1; j <= cnt && prime[j] * i < N;j++){
//            isprime[prime[j]*i] = false;
//            if(i % prime[j] == 0) break;
//        }
//    }
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), pre(n+5);
//	a[1] = pre[1] = 1;
//	for(int i = 2;i <= n;i++){
//		a[i] = a[i-1] + 2;
//		pre[i] = pre[i-1] + a[i];
//	}

//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//	cout << endl;

//	//for(int i = 1;i < n;i++){
//	//	for(int j = i+1;j <= n;j++){
//	//		if(isprime[(pre[j]-pre[i-1])]){
//	//			cout << i << ' ' << j << ' ' << pre[j]-pre[i-1] << endl;
//	//			return;
//	//		}
//	//	}
//	//}
//}

//signed main(){

//	IO;
//	//euler();
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
////#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;
//int t = 1;

//void solve(){
//	int n;
//	char c;
//	cin >> n;
	
//	cout << "? 1" << endl;
//	cin >> c;
//	if(c == '-' && t) while(1);
//	if(c == '='){
//		cout << "! 1" << endl;
//		cin >> c;
//	if(c == '-' && t) while(1);
//		if(c == '-') exit(0);
//		else return;
//	}
	
//	int l = 2, r = n;
//	while(l <= r){
//		int mid = l + r >> 1;
//		cout << "? " << mid << endl;
//		cin >> c;
//		if(c == '-' && t) while(1);

//		if(c == '<') l = mid + 1;
//		else r = mid - 1;

//		cout << "? 1" << endl;
//		cin >> c;
//		if(c == '-' && t) while(1);	
// 	}

//	cout << "! " << r << endl;
//	cin >> c;
//	//if(c == '-' && t) while(1);
//	if(c == '-') exit(0);
//}

//signed main(){

//	//IO;
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
//const int mod = 1e9 + 7;

//int dv(int a, int b){
//	int ret = a-b;
//	while(ret < 0) ret += mod;
//	return ret;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), ples(n+5), sles(n+5), pgt(n+5), sgt(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	stack<int>lesst, gtst;
//	for(int i = 1;i <= n;i++){
//		while(lesst.size() && a[lesst.top()] > a[i]) lesst.pop();
//		if(lesst.empty()) ples[i] = 0;
//		else ples[i] = lesst.top();
//		while(gtst.size() && a[gtst.top()] < a[i]) gtst.pop();
//		if(gtst.empty()) pgt[i] = 0;
//		else pgt[i] = gtst.top();
//		lesst.push(i);
//		gtst.push(i);
//	}
//	while(lesst.size()) lesst.pop();
//	while(gtst.size()) gtst.pop();
//	for(int i = n;i >= 1;i--){
//		while(lesst.size() && a[lesst.top()] >= a[i]) lesst.pop();
//		if(lesst.empty()) sles[i] = n+1;
//		else sles[i] = lesst.top();
//		while(gtst.size() && a[gtst.top()] <= a[i]) gtst.pop();
//		if(gtst.empty()) sgt[i] = n+1;
//		else sgt[i] = gtst.top();
//		lesst.push(i);
//		gtst.push(i);
//	}

//	vector<int>R(n+5), L(n+5);
//	for(int i = 1, w;i <= n;i++){
//		w = a[i] * (i-ples[i]) % mod;
//		(R[i] += w) %= mod;
//		R[sles[i]] = dv(R[sles[i]], w);
//		w = a[i] * (sgt[i]-i) % mod;
//		(L[pgt[i]+1] += w) %= mod;
//		L[i+1] = dv(L[i+1], w);
//	}

//	int ans = 0, pre = 0;
//	for(int i = 1;i <= n;i++){
//		(L[i] += L[i-1]) %= mod;
//		(R[i] += R[i-1]) %= mod;
//		(pre += R[i-1]) %= mod;
//		if(i > 1) (ans += pre * L[i] % mod) %= mod;
//	}

// 	cout << ans << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();
//	//while(t--) sv();

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

//template<class T>
//void ckmx(T &A,T B){
//	A<B?A=B:B;
//}
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 2e5 + 10;
//int a[N], b[N];

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= m;i++) cin >> b[i];
//	int va=a[1],vb=b[1];
//	std::sort(a+1,a+n+1);
//	std::sort(b+1,b+m+1);
//	int l=a[1]+b[1],r=va+vb;
//	va=std::lower_bound(a+1,a+n+1,va)-a;
//	vb=std::lower_bound(b+1,b+m+1,vb)-b;

//	auto check = [&](int x) -> int {
//		int d1 = 0, d2 = 0, sm = 0;
//		vector<int>c(m+5), r(n+5);

//		for(int j=m,i=0;j>=1;--j){
//			while(i<n&&a[i+1]+b[j]<=x)
//				++i;
//			c[j]=i;
//			sm+=c[j];
//		}
//		for(int i=n,j=0;i>=1;--i){
//			while(j<m&&a[i]+b[j+1]<=x)
//				++j;
//			r[i]=j;
//		}
//		d1=d2=sm;

//		for(int i=n,j=m;i>=1;--i){
//			sm-=min(j,r[i]);
//			sm+=m-max(j,r[i]);
//			d1 = max(sm, d1);
//			d2 = max(d2, sm-(i<=va&&j<vb));
//			while(j&&min(c[j],i-1)<=n-max(c[j],i-1)){
//				sm-=min(c[j],i-1);
//				sm+=n-max(c[j],i-1);
//				--j;
//				d1 = max(sm, d1);
//				d2 = max(d2, sm-(i<=va&&j<vb));
//			}
//		}

//		return d1 == d2;
//	};

//	while(l<r){
//		int mid=(l+r)>>1;
//		if(check(mid))
//			r=mid;
//		else 
//			l=mid+1;
//	}cout<<l<<"\n";
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

//void solve(){
//	int n, m, X, Y;
//	cin >> n >> m;
//	vector<int>a(n+5), b(m+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= m;i++) cin >> b[i];
//	int a1 = a[1], b1 = b[1];
//	sort(a.begin()+1, a.begin()+1+n);
//	sort(b.begin()+1, b.begin()+1+m);
//	for(int i = 1;i <= n;i++) if(a1 == a[i]) X = i;
//	for(int i = 1;i <= m;i++) if(b1 == b[i]) Y = i;

//	auto check = [&](int x) -> int {
//		int d1 = 0, d2 = 0;
//		vector<int>c(m+5), r(n+5), sufr(n+5), prec(m+5);

//		c[0] = n;
//		for(int i = 1;i <= m;i++){
//			c[i] = c[i-1];
//			while(c[i] && a[c[i]] + b[i] > x) c[i]--;
//			prec[i] = prec[i-1] + c[i];
//		}
//		r[0] = m;
//		for(int i = 1;i <= n;i++){
//			r[i] = r[i-1];
//			while(r[i] && a[i] + b[r[i]] > x) r[i]--;
//		}
//		for(int i = n;i >= 1;i--) sufr[i] = sufr[i+1] + r[i];

//		d1=d2=prec[m];

//		for(int i = 1;i <= n;i++){
//			int L = 1, R = m;
//			while(L <= R){
//				int mid = L + R >> 1;
//				if(i+c[mid]-n >= 0) L = mid + 1;
//				else R = mid - 1;
//			}
//			int tmp = m*(n-i)-sufr[i+1];
//			tmp += prec[R] + R*i - R*n;
//			d1 = max(d1, tmp);
//			d2 = max(d2, tmp-(i<X&&R<Y));
//		}

//		return d1 == d2;
//	};

//	int l = 1, r = a1 + b1 - 1;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(check(mid)) r = mid - 1;
//		else l = mid + 1;
//	}

//	cout << l << endl;
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

//void solve(){
//	int n, ans = 0;
//	cin >> n;
//	vector<int>a(n+5), d(n+5);
//	vector<vector<int>>g(n+5);
//	vector<unordered_set<int>>st(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//	}
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	auto dfs = [&](auto self, int u, int fa) -> void {
//		d[u] = d[fa] ^ a[u];
//		st[u].insert(d[u]);
//		int f = 0;
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//			if(st[v].size() > st[u].size()) swap(st[u], st[v]);
//			for(auto e : st[v])
//				if(st[u].count(e^a[u])) {
//					f = 1;
//					break;
//				}
//			for(auto e : st[v])
//				st[u].insert(e);
//		}
//		if(f) {
//			ans++;
//			st[u].clear();
//		}
//	};

//	dfs(dfs, 1, 0);

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

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, ans = 0;
//	cin >> n;
//	vector<int>a(n+5);
//	vector<vector<int>>g(n+5);
//	vector<unordered_set<int>*>st(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		st[i] = new unordered_set<int>;
//	}
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	auto dfs = [&](auto self, int u, int fa) -> void {
//		int son = 0;
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//			if(st[v]->size()) son++;
//		}
//		if(!son) {
//			if(!a[u]){
//				ans++;
//				cerr << u << endl;
//				return;
//			}
//			st[u]->insert(a[u]);
//			a[u] = 0;
//			return;
//		}
//		sort(all(g[u]), [&](int i, int j) -> int {return st[i]->size() < st[j]->size();});
//		int mxv = g[u].back();
//		st[u] = st[mxv];
//		a[u] ^= a[mxv];
//		int f = 0;
//		for(auto v : g[u]) if(v != fa && v != mxv && st[v]->size()){
//			for(auto x : *st[v]){
//				if(st[u]->count(x^a[u])){
//					f = 1;
//					break;
//				}
//			}
//			for(auto x : *st[v])
//				st[u]->insert(x^a[mxv]);
//			if(f) break;
//		}
//		if(f || st[u]->count(a[u])){
//			st[u]->clear();
//			ans++;
//			return;
//		}
//		st[u]->insert(a[mxv]);
//	};

//	dfs(dfs, 1, 0);

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

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>fa(n+5), vis(m+5);
//	iota(all(fa), 0);
//	vector<vector<int>>g(n+5);
//	vector<array<int,2>>E(m+5);
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		E[i] = {u, v};
//	}

//	auto find = [&](auto self, int x) -> int {
//		return x == fa[x] ? x : fa[x] = self(self, fa[x]);
//	};
//	auto merg = [&](int a, int b) -> void {
//		a = find(find, a);
//		b = find(find, b);
//		fa[a] = b;
//	};

//	for(int i = 1;i <= m;i++){
//		auto [u, v] = E[i];
//		if(find(find, u) != find(find, v)){
//			vis[i] = 1;
//			merg(u, v);
//			//cerr << u << ' ' << v << ' ' << i << endl;
//			g[u].push_back(v);
//			g[v].push_back(u);
//		}
//	}

//	vector<array<int,20>>par(n+5);
//	vector<int>dep(n+5);

//	auto dfs = [&](auto self, int u, int fa) -> void {
//		dep[u] = dep[fa] + 1;
//		par[u][0] = fa;
//		for(int i = 1;i < 20;i++) par[u][i] = par[par[u][i-1]][i-1];
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//		}
//	};
//	dfs(dfs, 1, 0);
//	auto lca = [&](int u, int v) -> int {
//		if(dep[u] < dep[v]) swap(u, v);
//		for(int i = 19;i >= 0;i--) if(dep[par[u][i]] >= dep[v]) u = par[u][i];
//		if(u == v) return u;
//		for(int i = 19;i >= 0;i--) if(par[u][i] != par[v][i]) 
//			u = par[u][i], v = par[v][i];
//		return par[u][0];
//	};

//	vector<int>d(n+5);
//	for(int i = 1;i <= m;i++) if(!vis[i]){
//		auto [u, v] = E[i];
//		if(dep[u] < dep[v]) swap(u, v);
//		if(lca(u, v) == v) {
//			d[u]--;
//			for(int i = 19;i >= 0;i--) if(dep[par[u][i]] > dep[v]) u = par[u][i];
//			d[u]++;
//		}else{
//			d[1]++;
//			d[u]--;
//			d[v]--;
//		}
//	}

//	auto dfs2 = [&](auto self, int u, int fa) -> void {
//		for(auto v : g[u]) if(v != fa){
//			d[v] += d[u];
//			self(self, v, u);
//		}
//	};
//	dfs2(dfs2, 1, 0);

//	for(int i = 1;i <= n;i++) {
//		if(d[i]) cout << 0;
//		else cout << 1;
//	}
//	cout << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
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

const int inf = 0x3f3f3f3f3f3f3f3f;

void solve(){

}

signed main(){

	IO;
	int t = 1;
	//cin >> t;
	while(t--) solve();

	return 0;
}
