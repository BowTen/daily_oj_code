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
//const int mod = 998244353;

//int A(int a, int b){
//	if(b > a) return 0;
//	int ret = 1;
//	for(int i = a-b+1;i <= a;i++) ret = ret * i % mod;
//	return ret;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<array<int,2>>a(n+5);
//	vector<vector<int>>mp(n+5, vector<int>(n+5));
//	vector<int>mn(n+5, inf), vis(n+5);
//	int cnt[5] = {0};
//	for(int i = 1;i <= n;i++) cin >> a[i][0] >> a[i][1];
//	for(int i = 1;i <= n;i++){
//		auto [x, y] = a[i];
//		for(int j = 1;j <= n;j++){
//			mp[i][j] = abs(x-a[j][0]) + abs(y-a[j][1]);
//			if(i != j) mn[i] = min(mn[i], mp[i][j]);
//		}
//		//cerr << mn[i] << endl;
//	}

//	for(int i = 1;i <= n;i++) if(!vis[i]){
//		vis[i] = 1;
//		unordered_set<int>p;
//		p.insert(i);	
//		for(int j = 1;j <= n;j++) if(j != i){
//			if(mp[i][j] == mn[i] && mn[j] == mn[i]) {
//				p.insert(j);
//				vis[j] = 1;
//			}
//		}
//		if(p.size() <= 4 && p.size() >= 2) {
//			int ok = 1;
//			for(auto e : p){
//				for(int j = 1;j <= n;j++) if(j != e){
//					if(mp[e][j] <= mn[i] && !p.count(j)){
//						ok = 0;
//						break;
//					}
//				}
//				for(auto v : p) if(v != e){
//					if(mp[e][v] != mn[i]) {
//						ok = 0;
//						break;
//					}
//				}
//			}
//			if(ok) cnt[p.size()-1]++;
//			//if(ok){
//			//	cerr << mn[i] << " : ";
//			//	for(auto e : p) cerr << e << ' ';
//			//	cerr << endl;
//			//}
//		}
//	}

//	vector<int>f(n+5);
//	f[n] = 1;
//	for(int i = 1;i <= 3;i++){
//		//cerr << cnt[i] << endl;
//		while(cnt[i]--){
//			for(int j = 1;j+i <= n;j++){
//				(f[j] += f[j+i]) %= mod;
//			}
//		}
//	}

//	int ans = 0;
//	for(int i = 1;i <= n;i++) {
//		//cerr << i << ' ' << f[i] << endl;
//		(ans += f[i] * A(n, i) % mod) %= mod;
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
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5), pre(n+5), cnt(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pre[i] = a[i] + pre[i-1];
//		cnt[i] = cnt[i-1] + (a[i] == 0);
//	}

//	if(k*cnt[n] < abs(pre[n])) {
//		cout << "-1\n";
//		return;
//	}

//	int nd = -pre[n];

//	int ans = 0;

//	for(int i = 1;i <= n;i++){
//		for(int j = i;j <= n;j++){
//			int ct1 = cnt[j] - cnt[i-1];
//			int ct2 = cnt[n] - ct1;
//			int sum = pre[j] - pre[i-1];
//			int mx = min(nd+k*ct2, k*ct1);
//			int mn = max(nd-k*ct2, -k*ct1);
//			ans = max(ans, abs(sum + mx) + 1);
//			ans = max(ans, abs(sum + mn) + 1);
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
//	int n, ans = 0;
//	cin >> n;
//	for(int i = 1, x;i <= n;i++) {
//		cin >> x;
//		ans = max(ans, x);
//	}

//	vector<int>a;
//	int n1, n2, n3;
//	cin >> n1;
//	for(int i = 1, x;i <= n1;i++) {
//		cin >> x;
//		a.push_back(x);
//	}
//	cin >> n2;
//	for(int i = 1, x;i <= n2;i++) {
//		cin >> x;
//		a.push_back(x);
//	}
//	cin >> n3;
//	for(int i = 1, x;i <= n3;i++) {
//		cin >> x;
//		a.push_back(x);
//	}
//	vector<int>id(a.size());
//	iota(all(id), 0);
//	sort(all(id), [&](int i, int j) -> int {
//		if(a[i] == a[j]) return i < j;
//		return a[i] > a[j];
//	});

//	int p1 = 0, p2 = 0, p3 = 0;

//	for(int i = 0;i < 10;i++){
//		ans += a[id[i]];
//		if(id[i] < n1) p1++;
//		else if(id[i] < n2+n1) p2++;
//		else p3++;
//	}

//	cout << ans << ' ' << p1 << '-' << p2 << '-' << p3 << endl;

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
//	int a, b;
//	cin >> a >> b;
//	if(a < b) swap(a, b);
//	if(a%2 && b%2) cout << a-b << endl;
//	else cout << a+b << endl;
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
//	vector<int>a(n+5), preu(n+5), pred(n+5), sufu(n+5), sufd(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++){
//		preu[i] = preu[i-1] + (a[i] < a[i+1]);
//		pred[i] = pred[i-1] + (a[i] > a[i+1]);
//	}
//	for(int i = n-1;i >= 1;i--){
//		sufu[i] = sufu[i+1] + (a[i] < a[i+1]);
//		sufd[i] = sufd[i+1] + (a[i] > a[i+1]);
//	}

//	int ans = inf;
//	for(int i = 1;i <= n;i++){
//		ans = min(ans, preu[i-1] + sufd[i]);
//		ans = min(ans, pred[i-1] + sufu[i]);
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

//int op[8][2] = {
//	-1, -1,
//	-1, 0,
//	-1, 1,
//	0, -1,
//	0, 1,
//	1, -1,
//	1, 0,
//	1, 1
//};
//int op4[4][2] = {
//	-1, 0,
//	1, 0,
//	0, -1, 
//	0, 1
//};

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>a(n+5, vector<int>(m+5)), vis(n+5, vector<int>(m+5));
//	vis[0] = vis[n+1] = vector<int>(m+5, 1);
//	a[0] = a[n+1] = vector<int>(m+5, 2);
//	for(int i = 0;i <= n+1;i++){
//		vis[i][0] = vis[i][m+1] = 1;
//		a[i][0] = a[i][m+1] = 2;
//	}
//	for(int i = 1;i <= n;i++) {
//		for(int j = 1;j <= m;j++) cin >> a[i][j];
//	}
//	if(n*m == 1) {cout << 0 << endl; return;}

//	queue<array<int,2>>que;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++) if(a[i][j] != 2){
//			vis[i][j] = 1;
//			que.push({i, j});
//			break;
//		}
//		if(que.size()) break;
//	}

//	if(que.empty()){
//		cout << 0 << endl;
//		return;
//	}

//	while(que.size()){
//		auto [x, y] = que.front();
//		que.pop();
//		for(int i = 0;i < 8;i++){
//			int nx = x + op[i][0];
//			int ny = y + op[i][1];
//			if(a[nx][ny] == 2 || vis[nx][ny]) continue;
//			vis[nx][ny] = 1;
//			que.push({nx, ny});
//		}
//	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++) if(a[i][j] != 2 && !vis[i][j]){
//			cout << -1 << endl;
//			return;
//		}
//	}

//	auto check = [&](vector<vector<int>>a) -> int {
//		vector<vector<int>>vis(a.size(), vector<int>(a[0].size()));
//		queue<array<int,2>>que;
//		for(int i = 1;i <= n && que.empty();i++) for(int j = 1;j <= m;j++) if(a[i][j] != 2) {
//			que.push({i, j}); vis[i][j] = 1; break;
//		}
//		while(que.size()){
//			auto [x, y] = que.front(); que.pop();
//			for(int i = 0;i < 4;i++) {
//				int nx = x + op4[i][0], ny = y + op4[i][1];
//				if(vis[nx][ny] || a[nx][ny] != (a[x][y] ^ 1)) continue;
//				vis[nx][ny] = 1; que.push({nx, ny});
//			}
//			if(a[x][y] == 0) {
//				if(a[x-1][y-1] == a[x][y] && !vis[x-1][y-1]) {vis[x-1][y-1] = 1; que.push({x-1, y-1});}
//				if(a[x+1][y+1] == a[x][y] && !vis[x+1][y+1]) {vis[x+1][y+1] = 1; que.push({x+1, y+1});}
//			}else {
//				if(a[x-1][y+1] == a[x][y] && !vis[x-1][y+1]) {vis[x-1][y+1] = 1; que.push({x-1, y+1});}
//				if(a[x+1][y-1] == a[x][y] && !vis[x+1][y-1]) {vis[x+1][y-1] = 1; que.push({x+1, y-1});}
//			}
//		}
//		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(a[i][j] != 2 && !vis[i][j]) return 0;
//		return 1;
//	};

//	vector<vector<int>>a1(a), a2(a);
//	int c1 = 0, c2 = 0;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++) if(a[i][j] != 2){
//			a1[i][j] = ((j&1) ^ (i&1));
//			c1 += a1[i][j] != a[i][j];
//		}
//	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++) if(a[i][j] != 2){
//			a2[i][j] = !((j&1) ^ (i&1));
//			c2 += a2[i][j] != a[i][j];
//		}
//	}

//	int ans = inf;
//	if(check(a1)) ans = min(ans, c1);
//	if(check(a2)) ans = min(ans, c2); 

//	if(ans == inf) cout << -1 << endl;
//	else cout << ans << endl;
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
////#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int n;
//	char ret;
//	cin >> n;
//	auto query = [&](vector<int>&a) -> void {
//		cout << "? ";
//		for(int i = 1;i <= n;i++) {
//			if(a[i]) cout << "1 ";
//			else cout << "2 ";
//		}
//		cout << endl;
//	};
//	vector<int>a(n+5), p;
//	p.push_back(1), p.push_back(n);

//	while(1){
//		vector<int>tmp;
//		tmp.push_back(p[0]);
//		for(int i = 1;i < p.size();i++){
//			int mid = p[i] + p[i-1] >> 1;
//			tmp.push_back(mid), tmp.push_back(p[i]);
//			for(int j = mid+1;j <= p[i];j++) a[j] ^= 1;
//		}
//		query(a);
//		cin >> ret;
//		if(ret == 'e') exit(0);
//		if(ret == 'd') break;
//		p = tmp;
//	}
//	//for(auto e:  p) cout << e << ' ';
//	//cout << endl;

//	int l = 1, r = p.size()-1;
//	while(l <= r){
//		int mid = l + r >> 1;
//		vector<int>b(a);
//		for(int i = 1;i <= p[mid];i++) b[i] = 0;
//		query(b);
//		cin >> ret;
//		if(ret == 'm') r = mid - 1;
//		else l = mid + 1;
//	}

//	int L = p[l-1], R = p[l];
//	if(L + 1 == R) {
//		cout << "! " << L << ' ' << R << endl;
//		return;
//	}
//	//cout << L << " " << R << endl;

//	for(int i = L;i <= R;i++) a[i] = 0;
//	l = L, r = L+R>>1;
//	while(l <= r){
//		int mid = l + r >> 1;
//		vector<int>b(a);
//		for(int i = L;i <= mid;i++) b[i] = 1;
//		query(b);
//		cin >> ret;
//		if(ret == 'd') r = mid - 1;
//		else l = mid + 1;
//	}
//	int p1 = l;
//	l = L+R>>1, r = R;
//	while(l <= r){
//		int mid = l + r >> 1;
//		vector<int>b(a);
//		for(int i = L;i <= mid;i++) b[i] = 1;
//		query(b);
//		cin >> ret;
//		if(ret == 'm') r = mid - 1;
//		else l = mid + 1;
//	}
//	int p2 = l;

//	cout << "! " << p1 << ' ' << p2 << endl;
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
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	int cnt = 0;
//	for(int i = 2;i <= n;i++){
//		if(a[i] < a[i-1]){
//			cnt++;
//		}
//	}

//	if(cnt > 1){
//		cout << "No\n";
//		return;
//	}
//	if(cnt == 0){
//		cout << "Yes\n";
//		return;
//	}

//	if(a[n] <= a[1]) cout << "Yes\n";
//	else cout << "No\n";


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
//	vector<int>a(n);
//	for(int i = 0;i < n;i++) cin >> a[i];
//	sort(all(a));
//	a.erase(unique(all(a)), a.end());
//	int b = 1;
//	for(int i = 1;i < a.size();i++){
//		if(a[i] % a[0]){
//			b = a[i];
//			break;
//		}
//	}
//	for(int i = 1;i < a.size();i++){
//		if(a[i] % a[0] && a[i] % b){
//			cout << "No\n";
//			return;
//		}
//	}
//	cout << "Yes\n";

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
//	int n, ans = 0;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i < n;i++) ans = max(ans, min(a[i], a[i+1]));

//	vector<int>b(3);
//	b[0] = a[1], b[1] = a[2], b[2] = a[3];
//	sort(all(b));
//	if(n >= 3) ans = max(ans, b[1]);
//	for(int i = 4;i <= n;i++){
//		for(int j = 0;j < 3;j++) if(b[j] == a[i-3]){
//			b[j] = a[i];
//			break;
//		}
//		sort(all(b));
//		ans = max(ans, b[1]);
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

//void solve(){
//	int a, b, n;
//	cin >> n >> a >> b;
//	vector<int>vis(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	vector<int>st(n+5);
//	int tp = 0;
//	int fd = 0;
//	auto dfs = [&](auto self, int u) -> void {
//		vis[u] = 1;
//		st[++tp] = u;
//		if(u == a) {
//			fd = 1;
//			return;
//		}
//		for(auto v : g[u]) if(!vis[v]) {
//			self(self, v);
//			if(fd) return;
//		}
//		tp--;
//	};
//	dfs(dfs, b);
//	int rt = st[tp/2+1];
//	int ans = tp/2;

//	int mx = 0;
//	vector<int>dep(n+5);
//	auto dfs2 = [&](auto self, int u, int fa) -> void {
//		dep[u] = dep[fa] + 1;
//		mx = max(mx, dep[u]);
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//		}
//	};
//	dfs2(dfs2, rt, 0);

//	ans += n * 2 - 1 - mx;

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

//class Tree{
//	vector<int>tr;
//public:
//	Tree(int n) : tr(n*4+5) {};
//	void up(int id){
//		tr[id] = tr[ls] + tr[rs];
//	}
//	void modify(int id, int l, int r, int x, int v) {
//		if(l == r) {
//			tr[id] += v;
//			return;
//		}
//		int mid = l + r >> 1;
//		if(x <= mid) modify(ls, l, mid, x, v);
//		else modify(rs, mid + 1, r, x, v);
//		up(id);
//	}
//	int query(int id, int l, int r, int ql, int qr) {
//		if(ql <= l && r <= qr) return tr[id];
//		int mid = l + r >> 1;
//		if(qr <= mid) return query(ls, l, mid, ql, qr);
//		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//		else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
//	}
//};

//void solve(){
//	int n, q, tot = 0;
//	cin >> n >> q;
//	vector<int>c(n+5);
//	vector<vector<int>>g(n+5);
//	set<pair<int,int>>st, st1, st2;
//	for(int i = 1;i <= n;i++) cin >> c[i];
//	for(int i = 1, u, v;i < n;i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	vector<int>dep(n+5), dfn(n+5), son(n+5), top(n+5), siz(n+5), par(n+5);
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
//		dfn[u] = ++tot;
//		if(son[u]) self(self, son[u], tp);
//		else return;

//		for(auto v : g[u]) if(v != son[u] && v != par[u]) {
//			self(self, v, v);
//		}
//	};
//	dfs1(dfs1, 1, 0);
//	dfs2(dfs2, 1, 1);

//	Tree tr(n);
//	auto query = [&](int u, int v) -> int {
//		int ret = 0, tmp = 0;
//		while(top[u] != top[v]) {
//			if(dep[top[u]] < dep[top[v]]) swap(u, v);
//			tmp = tr.query(1, 1, n, dfn[top[u]], dfn[u]);
//			if(tmp != dfn[u] - dfn[top[u]] + 1) return -1;
//			ret += tmp;
//			u = par[top[u]];
//		}
//		if(dep[u] < dep[v]) swap(u, v);
//		tmp = tr.query(1, 1, n, dfn[v], dfn[u]);
//		if(tmp != dfn[u] - dfn[v] + 1) return -1;
//		ret += tmp;
//		return ret;
//	};
//	auto lca = [&](int u, int v) -> int {
//		while(top[u] != top[v]) {
//			if(dep[top[u]] < dep[top[v]]) swap(u, v);
//			u = par[top[u]];
//		}
//		if(dep[u] < dep[v]) swap(u, v);
//		return v;
//	};

//	int p, p1, p2, p4, p3, sum;
//	for(int i = 1;i <= n;i++) if(c[i]) {
//		p = i;
//		if(st.empty()) p1 = p;
//		else p1 = st.rbegin()->second;
//		st.insert({dep[i], i});
//		tr.modify(1, 1, n, dfn[i], 1);
		
//		if(st1.empty() && st2.empty()) st1.insert({dep[p], p});
//		else if(st1.size()){
//			int lc = lca(p, st1.rbegin()->second);
//			if(lc == p || lc == st1.rbegin()->second) st2.insert({dep[p], p});
//			else st1.insert({dep[p], p});
//		}else{
//			int lc = lca(p, st2.rbegin()->second);
//			if(lc == p || lc == st2.rbegin()->second) st1.insert({dep[p], p});
//			else st2.insert({dep[p], p});
//		}
//		//cerr << p << ' ' << p1 << endl;
//		//int lc = lca(p1, p);
//		//int sm = 0;
//		//if(lc == p1 || lc == p) sm = 1;
//		//if(st1.count({dep[p1],p1})) {
//		//	if(sm) {st1.insert({dep[p],p});}
//		//	else st2.insert({dep[p],p});
//		//}else{
//		//	if(sm) st2.insert({dep[p],p});
//		//	else {st1.insert({dep[p],p});}
//		//}
//	}

//	while(q--){
//		cin >> p;
//		c[p] ^= 1;
//		if(c[p]){
//			if(st.empty()) p1 = p;
//			else p1 = st.rbegin()->second;
//			st.insert({dep[p], p});
//			tr.modify(1, 1, n, dfn[p], 1);

//			if(st1.empty() && st2.empty()) st1.insert({dep[p], p});
//			else if(st1.size()){
//				int lc = lca(p, st1.rbegin()->second);
//				if(lc == p || lc == st1.rbegin()->second) st2.insert({dep[p], p});
//				else st1.insert({dep[p], p});
//			}else{
//				int lc = lca(p, st2.rbegin()->second);
//				if(lc == p || lc == st2.rbegin()->second) st1.insert({dep[p], p});
//				else st2.insert({dep[p], p});
//			}
			
//			//int lc = lca(p1, p);
//			//int sm = 0;
//			//if(lc == p1 || lc == p) sm = 1;
//			//if(st1.count({dep[p1],p1})) {
//			//	if(sm) st1.insert({dep[p],p});
//			//	else st2.insert({dep[p],p});
//			//}else{
//			//	if(sm) st2.insert({dep[p],p});
//			//	else st1.insert({dep[p],p});
//			//}
//		}else{
//			st.erase({dep[p], p});
//			st1.erase({dep[p], p});
//			st2.erase({dep[p], p});
//			tr.modify(1, 1, n, dfn[p], -1);
//		}

//		if(st.empty()) {
//			cout << "No\n";
//			continue;
//		}
//		if(st.size() == 1) {
//			cout << "Yes\n";
//			continue;
//		}
//		//p1 = st.rbegin()->second;
//		p3 = st.begin()->second;
//		if(st1.empty()) p1 = p3;
//		else p1 = st1.rbegin()->second;
//		if(st2.empty()) p2 = p3;
//		else p2 = st2.rbegin()->second;
//		//if(st1.count({dep[p1],p1})){
//		//	if(st2.empty()) p2 = p1;
//		//	else p2 = st2.rbegin()->second;
//		//}else{
//		//	if(st1.empty()) p2 = p1;
//		//	else p2 = st1.rbegin()->second;
//		//}
//		sum = max(query(p1, p2), query(p1, p3));
//		//auto it = next(st.rbegin());
//		//p2 = it->second;
//		//sum = max(sum, query(p1, p2));
		
//		//it = next(it);
//		//if(it != st.rend() && it->first == dep[p2]){
//		//	p4 = it->second;
//		//	sum = max(sum, query(p1, p4));
//		//}

//		//cerr << query(p1, p2) << ' ' << query(p1, p3) << endl;
//		cerr << p1 << ' ' << p2 << ' ' << p3 << ' ' << sum << endl;
//		if(sum == st.size()) cout << "Yes\n";
//		else cout << "No\n";
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
//	int n, sum = 0;
//	cin >> n;
//	for(int i = 1, x;i <= n;i++){
//		cin >> x;
//		sum += x;
//	}
//	sum = abs(sum);
//	if(sum & 1) cout << 0 << endl;
//	else cout << n << endl;
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
//	int l, r;
//	cin >> l >> r;
//	int ans = 0;
//	for(int i = 1;i <= 100000;i++) {
//		if(i*i >= l && i*i <= r) ans++;
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
//	vector<int>a(n+5);
//	unordered_map<int,int>mp;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		if(isprime[a[i]]) {
//			mp[a[i]] = max(mp[a[i]], 1ll);
//			continue;
//		}
//		unordered_map<int,int>tmp;
//		for(int j = 1; j <= cnt && prime[j] <= a[i];j++){
//			while(a[i] % prime[j] == 0) {
//				tmp[prime[j]]++;
//				a[i] /= prime[j];
//			}
//		}
//		for(auto [k, v] : tmp) mp[k] = max(mp[k], v);
//	}

//	int sum = 0;
//	for(auto [k, v] : mp) sum += v;

//	if(sum & 1) cout << "Alice\n";
//	else cout << "Bob\n";
//}

//signed main(){

//	IO;
//	euler();
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
////#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e7 + 10;
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
//	if(n < 4) {
//		cout << n-2 << endl;
//		return;
//	}
//	int R = upper_bound(prime+1, prime+cnt+1, n) - prime - 1;
//	int l = 1, r = R;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(2*prime[mid] <= n) l = mid + 1;
//		else r = mid - 1;
//	}
//	cout << R-r << endl;
//}

//signed main(){

//	IO;
//	euler();
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
//int lowbit(int x){
//	return x & -x;
//}

//void solve(){
//	int a, b;
//	cin >> a >> b;
//	if(a == 0 && b == 0){
//		cout << "1\n0\n";
//		return;
//	}
//	if((a|b) != a) {
//		cout << -1 << endl;
//		return;
//	}
//	if(a == lowbit(a)){
//		if(b == 0){
//			cout << -1 << endl;
//		}else{
//			cout << "2\n0 " << a << endl;
//		}
//		return;
//	}
//	vector<int>num;
//	num.push_back(0);
//	for(int i = 1;i <= a;i++) if(i != b) {
//		if((a|i) == a) num.push_back(i);
//	}

//	int x = 0;
//	for(auto e : num) x ^= e;
//	if(x != b) {
//		while(1);
//		//cout << -1 << endl;
//		//return;
//	}

//	cout << num.size() << endl;
//	for(auto e : num) cout << e << ' ';
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

//const int inf = 0x3f3f3f3f3f3f3f3f;

//int fun(string a, string b) {
//	string s;
//	s.push_back(b[0]);
//	for(auto c : b)	if(c != s.back()) s.push_back(c);
//	int p = 0;
//	for(auto c : a){
//		if(c == s[p]) p++;
//		if(p == s.size()) return 1;
//	}
//	return 0;
//}

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	string s, t;
//	cin >> s >> t;
//	vector<string>a, b;
//	for(int i = 0;i < k;i++){
//		a.push_back("");
//		b.push_back("");
//		for(int j = i;j < n;j += k){
//			a.back().push_back(s[j]);
//			b.back().push_back(t[j]);
//		}
//	}

//	int ans = 1;
//	for(int i = 0;i < a.size();i++) ans &= fun(a[i], b[i]);
//	if(ans) cout << "Yes\n";
//	else cout << "No\n";
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
//	int n, q;
//	cin >> n >> q;
//	vector<int>c(n+5);
//	for(int i = 1;i <= n;i++) cin >> c[i];
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	vector<int>d(4), par(n+5), deg(n+5);
//	auto dfs = [&](auto self, int u, int fa) -> void {
//		par[u] = fa;
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//		}
//	};
//	dfs(dfs, 1, 0);

//	int sum = 0, faw = 0, tw;
//	set<int>st;

//	auto ad = [&](int x) {
//		sum++;
//		if(deg[x] == 2) st.insert(x);
//		d[min(3ll, deg[x])]++;
//		if(deg[x] == 2) tw = x;
//		if(!c[par[x]]) faw++;
//		faw -= deg[x];

//		deg[par[x]]++;
//		if(c[par[x]]){
//			if(deg[par[x]] == 2) st.insert(par[x]);
//			if(deg[par[x]] == 3) st.erase(par[x]);
//			if(deg[par[x]] == 2) tw = par[x];
//			d[min(3ll, deg[par[x]])]++;
//			d[min(3ll, deg[par[x]]-1)]--;
//		}
//	};
//	auto dv = [&](int x) {
//		sum--;
//		if(deg[x] == 2) st.erase(x);
//		d[min(3ll, deg[x])]--;
//		if(!c[par[x]]) faw--;
//		faw += deg[x];

//		deg[par[x]]--;
//		if(c[par[x]]){
//			if(deg[par[x]] == 2) st.insert(par[x]);
//			if(deg[par[x]] == 1) st.erase(par[x]);
//			if(deg[par[x]] == 2) tw = par[x];
//			d[min(3ll, deg[par[x]])]++;
//			d[min(3ll, deg[par[x]]+1)]--;
//		}
//	};

//	for(int i = 1;i <= n;i++) if(c[i]) deg[par[i]]++;
//	for(int i = 1;i <= n;i++){
//		if(c[i]){
//			sum++;
//			if(!c[par[i]]) faw++;
//			if(deg[i] == 2) st.insert(i);
//			d[min(3ll, deg[i])]++;
//		}
//	}

//	int p;
//	while(q--){
//		cin >> p;
//		c[p] ^= 1;
//		if(c[p]) ad(p);
//		else dv(p);

//		//for(int i = 0;i <= 3;i++) cerr << d[i] << ' ';
//		//cerr << endl;

//		int ok = 1;
//		if(sum == 0) ok = 0;
//		//if(d[0] == 0 || d[0] > 2) ok = 0;
//		if(d[2] > 1) ok = 0;
//		if(d[2] == 1){
//			tw = *st.begin();
//		}
//		if(d[2] == 1 && c[par[tw]]) ok = 0;
//		if(faw != 1) ok = 0;
//		if(d[3]) ok = 0;
//		if(ok) cout << "Yes\n";
//		else cout << "No\n";
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
//	int n, m;
//	cin >> n >> m;
//	if(m > n) {
//		cout << "No\n";
//		return;
//	}
//	int d = n-m;
//	if(d % 2 == 0) cout << "Yes\n";
//	else cout << "No\n";
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
//	int x;
//	cin >> x;
//	vector<int>a;
//	while(x){
//		a.push_back(x&1);
//		x >>= 1;
//	}
//	a.push_back(0);
//	//a.push_back(0);
//	int f = 0;
//	for(int i = 0;i < a.size();i++){
//		if(f){
//			if(a[i]){
//				a[i] = 0;
//			}else{
//				a[i] = 1;
//				f = 0;
//			}
//		}
//		if(i < a.size()-1 && a[i] && a[i+1]){
//			a[i] = -1;
//			f = 1;
//		}
//	}
//	cout << a.size() << endl;
//	for(auto e : a) cout << e<< ' ';
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

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void pt(int x){
//	cerr << x << " : \n";
//	map<int,int>mp;
//	for(int i = 2;i*i <= x;i++){
//		while(x % i == 0){
//			mp[i]++;
//			x /= i;
//		}
//	}
//	if(x) mp[x]++;
//	for(auto [k,v] : mp) cerr << k << ' ' << v << endl;
//	cerr << endl;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	for(auto &e : a) cin >> e;

//	vector<int>b(a);
//	sort(all(b));
//	b.erase(unique(all(b)), b.end());
//	vector<int>c(b);
//	set<int>st;
//	for(auto e : b){
//		st.insert(e);
//		pt(e);
//	}

//	for(int i = 1;i < c.size();i++){
//		c[i] = (c[i] * c[i-1]) / gcd(c[i], c[i-1]);
//	}
	
//	int p = -1;
//	for(int i = c.size()-1;i >= 0;i--){
//		//cerr << c[i] << endl;
//		if(!st.count(c[i])){
//			p = b[i];
//			break;
//		}
//	}

//	//cerr << p << endl;

//	int ans = 0;
//	for(auto e : a) ans += (e <= p);
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
//const int N = 3e5 + 5;

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	int ni = n;
//	vector<bitset<N>>mp(m);
//	vector<string>S(n), S2(m);
//	for(int i = 0;i < n;i++){
//		cin >> S[i];
//	}
//	for(int j = 0;j < m;j++){
//		for(int i = 0;i < n;i++){
//			S2[j] += S[i][j];
//		}
//	}

//	unordered_map<bitset<N>,int>cnt;
//	for(int i = 0;i < m;i++){
//		mp[i] = bitset<N>(S2[i]);
//		cnt[mp[i]]++;
//	}
//	sort(all(mp));
//	mp.erase(unique(all(mp)), mp.end());
	
//	n = mp.size(); //n列
//	vector<int>val(n);
//	for(int i = 0;i < n;i++) val[i] = cnt[mp[i]];

//	int ans = 0;
//	bitset<N>mst;
//	for(int i = 0;i < n;i++){
//		vector<vector<int>>vec(ni+5);
//		for(int j = 0;j < n;j++) if(j != i){
//			auto tmp = mp[i]^mp[j];
//			if(tmp.count()==2){
//				int fs = tmp._Find_first();
//				vec[fs].push_back(val[j]);
//				vec[tmp._Find_next(fs+1)].push_back(val[j]);
//			}
//		}
//		int it = 0;
//		for(auto &v : vec) {
//			sort(all(v));
//			int sum = val[i];
//			for(int k = v.size()-1;k >= v.size()-2;k--) sum += v[k];
//			if(sum > ans){
//				ans = sum;
//				mst = mp[i];
//				mst[it] = mst[it] ^ 1;
//			}
//			it++;
//		}
//	}

//	cout << ans << endl;
//	for(int i = 0;i < ni;i++) cout << mst[i];
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

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	set<int>st;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		st.insert(a[i]);
//	}
//	int m = 1;
//	for(int i = 1;i <= n && m <= 1e9;i++) m = m*a[i] / gcd(m, a[i]);
//	if(m > 1e9){
//		cout << n << endl;
//		return;
//	}

//	vector<int>num;
//	for(int i = 1;i * i <= m;i++) if(m % i == 0){
//		num.push_back(i);
//		num.push_back(m/i);
//	}

//	int ans = 0;
//	for(auto e : num) if(!st.count(e)){
//		int tmp = 0, g = 1;
//		for(int i = 1;i <= n;i++) if(e % a[i] == 0){
//			tmp++;
//			g = g*a[i] / gcd(g, a[i]);
//		}
//		if(g == e) ans = max(ans, tmp);
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
//const int mod = 998244353;

//int qpow(int a, int b) {
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}
//int bit(int x){
//	int ret = 0;
//	while(x) {
//		ret += x & 1;
//		x >>= 1;
//	}
//	return ret;
//}

//void solve(){
//	int n, q, tot = 0;
//	cin >> n;
//	string s, t;
//	cin >> s;
//	for(auto c : s) tot += (c == '?');

//	vector<array<int,18>>a(1<<17);
//	vector<int>f(1<<17);
//	auto calc = [&](int l, int r) {
//		int x = 0, d = 0;
//		while(l >= 0 && r < n){
//			if(s[l] == '?' && s[r] == '?'){
//				if(l != r) d++;
//			}else if(s[l] == '?' || s[r] == '?'){
//				d++;
//				char c = s[l] != '?' ? s[l] : s[r];
//				if(((x>>(c-'a'))&1) == 0) x |= 1<<(c-'a');
//			}else if(s[l] != s[r]) break;
//			for(int i = 1;i <= 17;i++) (a[x][i] += qpow(i, tot-d)) %= mod;
//			l--, r++;
//		}	
//	};

//	for(int i = 0;i < n;i++){
//		calc(i, i);
//		calc(i, i+1);
//	}

//	for(int i = 0;i < (1<<17);i++){
//		int len = bit(i);
//		for(int j = i;1;j = (j-1)&i){
//			(f[i] += a[j][len]) %= mod;
//			if(!j) break;
//		}
//	}

//	cin >> q;
//	while(q--){
//		cin >> t;
//		int x = 0;
//		for(auto c : t) x |= 1<<(c-'a');
//		cout << f[x] << endl;
//	}
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