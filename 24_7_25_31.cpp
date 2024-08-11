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



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e5 + 5;
//int fa[N], d[N];

//int find(int x){
//	if(x != fa[x]){
//		int f = find(fa[x]);
//		d[x] ^= d[fa[x]];
//		fa[x] = f;
//	}
//	return fa[x];
//}
//void merg(int a, int b, int x){
//	fa[a] = fa[b];
//	d[fa[a]] = d[b] ^ x ^ d[a];
//}

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<string>op(m+5);
//	vector<int>l(m+5), r(m+5), idx;
//	for(int i = 1;i <= m;i++){
//		cin >> l[i] >> r[i] >> op[i];
//		idx.push_back(l[i]);
//		idx.push_back(r[i]);
//	}

//	sort(all(idx));
//	idx.erase(unique(all(idx)), idx.end());

//	for(int i = 1;i < N;i++) fa[i] = i;
//	for(int i = 1;i <= m;i++){
//		l[i] = lower_bound(all(idx), l[i]) - idx.begin() + 1;
//		r[i] = lower_bound(all(idx), r[i]) - idx.begin() + 2;
//	}
//	for(int i = 1;i <= m;i++){
//		int x = 0;
//		if(op[i][0] == 'o') x = 1;
//		if(find(l[i]) == find(r[i])) {
//			if((d[l[i]] ^ d[r[i]]) != x) {
//				cout << i-1 << endl;
//				return;
//			}
//		} else{
//			merg(l[i], r[i], x);
//		}
//	}
//	cout << m << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 2e5 + 10;
//const int M = N*40;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//int n, c[N], w[N];
//vector<int>g[N];

//int f[N], sum[N];
//int rt[N], mx[M], ls[M], rs[M], tot, tag[M];

//void insert(int &id, int l, int r, int x, int v) {
//	if(!id) id = ++tot;
//	if(l == r) {
//		mx[id] = v;
//		return;
//	}
//	int mid = l + r >> 1;
//	if(x <= mid) insert(ls[id], l, mid, x, v);
//	else insert(rs[id], mid + 1, r, x, v);
//}
//void settag(int id, int x){
//	tag[id] += x;
//}
//void down(int id){
//	if(ls[id]) settag(ls[id], tag[id]);
//	if(rs[id]) settag(rs[id], tag[id]);
//	tag[id] = 0;
//}
//int merg(int &a, int b, int l, int r) {
//	if(!a || !b) {
//		a |= b;
//		return 0;
//	}
//	if(l == r){
//		mx[a] += tag[a];
//		mx[b] += tag[b];
//		tag[a] = tag[b] = 0;
//		int ret = mx[a] + mx[b];
//		mx[a] = max(mx[a], mx[b]);
//		return ret;
//	}
//	if(tag[a]) down(a);
//	if(tag[b]) down(b);
//	int mid = l + r >> 1;
//	return max(merg(ls[a], ls[b], l, mid), merg(rs[a], rs[b], mid + 1, r));
//}
//void dfs(int u, int fa) {
//	for(auto v : g[u]) if(v != fa){
//		dfs(v, u);
//		sum[u] += f[v];
//		int ret = merg(rt[u], rt[v], 1, n);
//		f[u] = max(f[u], ret);
//	}
//	f[u] += sum[u];
//	settag(rt[u], sum[u] - f[u]);
//}

//void init(){
//	for(int i = 1;i <= n;i++) {
//		g[i].clear();
//		rt[i] = f[i] = sum[i] = 0;
//	}
//	for(int i = 0;i <= tot;i++) {
//		tag[i] = ls[i] = rs[i] = mx[i] = 0;
//	}
//	tot = 0;
//}

//void solve(){
//	cin >> n;
//	for(int i = 1;i <= n;i++) cin >> c[i];
//	for(int i = 1;i <= n;i++){
//		cin >> w[i];
//		insert(rt[i], 1, n, c[i], w[i]);
//	}
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	dfs(1, 0);
//	cout << f[1] << endl;

//	init();
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, m;
//	map<int,int>mp;
//	mp[0] = 1;
//	cin >> n >> m;

//	int bd = 0;
//	int op, p, t, mn = 0, fp = 1, ft = inf;
//	while(m--){
//		cin >> op;
//		if(op == 0){

//			cin >> p >> t;
//			if(bd) continue;
//			if(mp.count(t) && mp[t] != p) bd = 1;
			
//			if(p > 1) {
//				if(t < ft) ft = t, fp = p;
//				if(t <= mn) bd = 1;
//			}else {
//				if(t <= mn) continue;
//			}

//			auto it = mp.upper_bound(t);
//			if(it != mp.end()) {
//				int np = it->second;
//				int nt = it->first;
//				int dd = abs(np - p);
//				int dt = nt - t;
//				if(dd > dt) { bd = 1; continue; }
//				if((dt-dd) & 1) {
//					if(t < ft) mn = max(mn, t+1);
//					else { bd = 1; continue; }
//				}
//			}
//			if(it != mp.begin()) {
//				it = prev(it);
//				int pp = it->second;
//				int pt = it->first;
//				int dd = abs(pp - p);
//				int dt = t - pt;
//				if(dd > dt) { bd = 1; continue; }
//				if((dt-dd) & 1) {
//					if(pt < ft) mn = max(mn, pt+1);
//					else { bd = 1; continue; }
//				}
//			}
//			mp[t] = p;


//		}else if(op == 1){

//			if(bd) {cout << "bad\n"; continue;}
//			cout << mn << endl;

//		}else if(op == 2){

//			if(bd) {cout << "bad\n"; continue;}
//			if(fp == 1) cout << "inf\n";
//			else cout << ft-fp+1 << endl;

//		}
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 5;
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

//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	euler();
//	cout << cnt << endl;

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 1e5 + 10;
//const int M = N*30;
//const int mxn = 1e9;

//array<int,5>tr[M];
//int ls[M], rs[M], tot, cnt[M], rt;

//void up(int id){
//	cnt[id] = (cnt[ls[id]] + cnt[rs[id]]) % 5;
//	for(int i = 0;i < 5;i++) tr[id][i] = tr[ls[id]][i] + tr[rs[id]][(i-cnt[ls[id]]+5)%5];
//}
//void add(int &id, int l, int r, int x, int v){
//	if(!id) id = ++tot;
//	if(l == r){
//		tr[id][1] += v*x;
//		cnt[id] += v;
//		return;
//	}
//	int mid = l + r >> 1;
//	if(x <= mid) add(ls[id], l, mid, x, v);
//	else add(rs[id], mid + 1, r, x, v);
//	up(id);
//}

//void solve(){
//	int n;
//	cin >> n;
//	string op;
//	int x;
//	while(n--){
//		cin >> op;
//		if(op[0] == 'a'){
//			cin >> x;
//			add(rt, 1, mxn, x, 1);
//		}else if(op[0] == 'd'){
//			cin >> x;
//			add(rt, 1, mxn, x, -1);
//		}else{
//			cout << tr[rt][3] << endl;
//		}
//	}
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const double eps = 1e-7;

//struct P{
//	int x, y;
//	P() {}
//	P(int x, int y) : x(x), y(y) {}
//	P operator-(const P &e) const { return P(x-e.x, y-e.y); }
//	P operator+(const P &e) const { return P(x+e.x, y+e.y); }
//	P operator*(double k) const { return P(x*k, y*k); }
//	int operator*(const P &e) const { return x*e.y - y*e.x; }

//};
//struct Line{
//	P s, e;
//	Line() {}
//	Line(P s, P e) : s(s), e(e) {}

//	double angle() const {
//		return atan2(e.y-s.y, e.x-s.x);
//	}

//	int operator<(const Line& b) const {
//		double A = angle(), B = b.angle();
//		return fabs(A-B) > eps ? A<B : (e-s)*(b.e-s) < 0;
//	}

//	P cross(Line b) {
//	    P u = s - b.s, v = e - s, w = b.e - b.s;
//	    double t = u * w / (w * v);
//	    return s + v * t;
//	}
//	bool right(P p) {
//		return (e-s) * (p-s) < 0;
//	}
//};

//vector<P> half_plane(vector<Line> L) {
//	int n = L.size();
//	sort(all(L));
//	vector<Line>q(n+1);
//	int h = 0, t = 0; q[0] = L[0];
//	for(int i = 1;i < n;i++){
//		if(L[i].angle() - L[i-1].angle() < eps) continue;
//		while(t>h && L[i].right(q[t].cross(q[t-1]))) t--;
//		while(t>h && L[i].right(q[h].cross(q[h+1]))) h++;
//		q[++t] = L[i];
//	}
//	while(t>h && q[h].right(q[t].cross(q[t-1]))) t--;
//	q[++t] = q[h];
//	vector<P>ret;
//	for(int i = h;i < t;i++) ret.push_back(q[i].cross(q[i+1]));
//	return ret;
//}

//double area(vector<P> p){
//	double res = 0;
//	int n = p.size();
//	for(int i = 1;i < n;i++) res += (p[i]-p[1]) * (p[i+1]-p[1]);
//	return res/2;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<Line>L;
//	for(int i = 1, m;i <= n;i++){
//		cin >> m;
//		vector<P>p(m);
//		for(int j = 0;j < m;j++) cin >> p[j].x >> p[j].y;
//		for(int j = 0;j < m;j++) L.push_back(Line(p[j], p[(j+1)%m]));
//	}

//	cout << area(half_plane(L)) << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	int mx = 0;
//	for(int i = 1, x;i <= n;i++){
//		cin >> x;
//		if(i & 1) 
//			mx = max(mx, x);
//	}
//	cout << mx << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>b(n+5), a(n+5);
//	for(int i = 1;i < n;i++){
//		cin >> b[i];
//		a[i] |= b[i];
//		a[i+1] |= b[i];
//	}
//	for(int i = 1;i < n;i++) {
//		if((a[i] & a[i+1]) != b[i]) {
//			cout << "-1\n";
//			return;
//		}
//	}
//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//	cout << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	int ev = 0, od = 0;
//	for(int i = 0;i < n;i++){
//		cin >> a[i];	
//		if(a[i] & 1) od = 1;
//		else ev = 1;
//	}
//	if(od && ev) {
//		cout << -1 << endl;
//		return;
//	}

//	vector<int>ans;
//	while(a.size() > 1) {
//		sort(all(a));
//		vector<int>b(a);
//		int mid = b[0] + b.back() >> 1;
//		ans.push_back(mid);
//		for(auto &e : b) e = abs(e-mid);
//		sort(all(b));
//		b.erase(unique(all(b)), b.end());
//		a = b;
//	}
//	if(a[0] != 0) ans.push_back(a[0]);

//	cout << ans.size() << endl;
//	for(auto e : ans) cout << e << ' ';
//	cout << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>c(n+5);
//	int mx = 0;
//	for(int i = 1;i <= n;i++){
//		c[i] = ((i-1)%4)+1;
//		mx = max(mx, c[i]);
//	}

//	if(n == 1){
//		cout << "1\n1" << endl;
//		return;
//	}else if(n == 2){
//		cout << "2\n1 2" << endl;
//		return;
//	}else if(n == 3){
//		cout << "2\n1 2 2" << endl;
//		return;
//	}else if(n == 4){
//		cout << "3\n1 2 2 3" << endl;
//		return;
//	}else if(n == 5){
//		cout << "3\n1 2 2 3 3" << endl;
//		return;
//	}

//	cout << mx << endl;
//	for(int i = 1;i <= n;i++) cout << c[i] << ' ';
//	cout << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
////#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>c(n+5, -1);
//	vector<vector<int>>g(n+5);
//	vector<stack<int>>st(3);
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	int cyc = 0;
//	auto dfs = [&](auto self, int u) -> void {
//		st[c[u]].push(u);
//		for(auto v : g[u]) {
//			if(c[v] != -1){
//				if(c[v] == c[u]) {
//					cyc = 1;
//					return;
//				}
//			}else{
//				c[v] = c[u] ^ 1;
//				self(self, v);
//			}
//		}
//	};

//	c[1] = 0;
//	dfs(dfs, 1);

//	int a, b;
//	if(cyc) {
//		cout << "Alice" << endl;
//		while(n--){
//			cout << 1 << ' ' << 2 << endl;
//			cin >> a >> b;
//		}
//	}else {
//		cout << "Bob" << endl;
//		while(n--){
//			cin >> a >> b;
//			a--;
//			b--;
//			if(a > b) swap(a, b);

//			if(st[a].size()) {
//				cout << st[a].top() << ' ' << a+1 << endl;
//				st[a].pop();
//				continue;
//			}
//			if(st[b].size()) {
//				cout << st[b].top() << ' ' << b+1 << endl;
//				st[b].pop();
//				continue;
//			}

//			if(st[0].size()) {cout << st[0].top() << " "; st[0].pop();}
//			if(st[1].size()) {cout << st[1].top() << " "; st[1].pop();}
//			cout << 3 << endl;
//		}
//	}
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//class Tree {
//	int n;
//public:
//	vector<int>mx;
//	Tree(int n) : mx(n*4+10), n(n) {}
//	#define ls id << 1
//	#define rs id << 1 | 1
//	void init(){
//		for(int i = 0;i < mx.size();i++) mx[i] = 0;
//	}
//	void up(int id){
//		mx[id] = max(mx[ls], mx[rs]);
//	}
//	void change(int id, int l, int r, int x, int v){
//		if(l == r) {
//			mx[id] = max(mx[id], v);
//			return;
//		}
//		int mid = l + r >> 1;
//		if(x <= mid) change(ls, l, mid, x, v);
//		else change(rs, mid + 1, r, x, v);
//		up(id);
//	}
//	int query(int id, int l, int r, int ql, int qr) {
//		if(ql <= l && r <= qr) return mx[id];
//		int mid = l + r >> 1;
//		if(qr <= mid) return query(ls, l, mid, ql, qr);
//		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//		else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//	}
//	void change(int x, int v){
//		change(1, 1, n, x, v);
//	}
//	int query(int l, int r){
//		if(l < 1 || r > n || l > r) return 0;
//		return query(1, 1, n, l, r);
//	}
//};	

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>p(n+5), v(n+5), f(n+5), g(n+5), h(n+5);
//	vector<int>x1(m+5), x2(m+5), y1(m+5), y2(m+5);
//	for(int i = 1;i <= n;i++) cin >> p[i] >> v[i];
//	for(int i = 1;i <= m;i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

//	Tree t1(n), t2(n);
//	for(int i = 1;i <= n;i++){
//		f[i] = t1.query(1, p[i]) + v[i];
//		t1.change(p[i], f[i]);
//	}
//	for(int i = n;i >= 1;i--){
//		g[i] = t2.query(p[i], n) + v[i];
//		t2.change(p[i], g[i]);
//	}
//	for(int i = 1;i <= n;i++){
//		h[i] = f[i] + g[i] - v[i];
//	}

//	vector<int>f1(m+5), f2(m+5), hh(m+5), g1(m+5), g2(m+5);
//	vector<vector<int>>qur(n+5);

//	for(int i = 1;i <= m;i++){
//		qur[x1[i]].push_back(i);
//		qur[x2[i]+1].push_back(i);
//	}
//	t1.init();
//	t2.init();
//	for(int i = 1;i <= n+1;i++){
//		for(auto id : qur[i])  {
//			if(i == x1[id]){
//				f1[id] = max(f1[id], t1.query(1, y2[id])); 
//				hh[id] = max(hh[id], t2.query(y2[id]+1, n));
//			}
//			if(i == x2[id]+1){
//				f2[id] = max(f2[id], t1.query(1, y1[id]-1));
//			}
//		}
//		qur[i].clear();
//		t1.change(p[i], f[i]);
//		t2.change(p[i], h[i]);
//	}

//	for(int i = 1;i <= m;i++){
//		qur[x1[i]-1].push_back(i);
//		qur[x2[i]].push_back(i);
//	}
//	t1.init();
//	t2.init();
//	for(int i = n;i >= 0;i--){
//		for(auto id : qur[i])  {
//			if(i == x1[id]-1){
//				g1[id] = max(g1[id], t1.query(y2[id]+1, n));
//			}
//			if(i == x2[id]){
//				hh[id] = max(hh[id], t2.query(1, y1[id]-1));
//				g2[id] = max(g2[id], t1.query(y1[id], n));
//			}
//		}
//		t1.change(p[i], g[i]);
//		t2.change(p[i], h[i]);
//	}

//	for(int i = 1;i <= m;i++){
//		cout << max({hh[i], f1[i]+g1[i], f2[i]+g2[i]}) << endl;
//	}
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];

//	vector<vector<int>>idx, idx2;
//	vector<int>cur;
//	auto dfs = [&](auto self, int x, int st) -> void {
//		if(x == 3) {
//			idx.push_back(cur);
//			return;
//		}
//		for(int i = st;6-i >= 3-x;i++) {
//			cur.push_back(i);
//			self(self, x+1, i+1);
//			cur.pop_back();
//		}
//	};
//	dfs(dfs, 0, 0);
	
//	for(auto id : idx) {
//		vector<int>vis(6);
//		for(auto e : id) vis[e] = 1;
//		vector<int>tmp;
//		for(int i = 0;i < 6;i++) if(!vis[i]) tmp.push_back(i);
//		idx2.push_back(tmp);
//	}

//	auto check = [&](vector<int>a) -> int {
//		for(int i = 0;i < 20;i++){
//			if(a[idx[i][0]]+a[idx[i][1]] > a[idx[i][2]] && a[idx2[i][0]]+a[idx2[i][1]] > a[idx2[i][2]]) return 1;
//		}
//		return 0;
//	};

//	while(q--){
//		int l, r;
//		cin >> l >> r;
//		if(r-l+1 >= 48){
//			cout << "YES\n";
//			continue;
//		}
//		vector<int>b;
//		for(int i = l;i <= r;i++) b.push_back(a[i]);
//		sort(all(b));

//		int p = 0, cnt = 0;
//		for(int i = b.size()-3;i >= 0;i--){
//			if(b[i]+b[i+1] > b[i+2]){
//				p = i;
//				cnt++;
//				i -= 2;
//			}
//		}
//		if(cnt >= 2){
//			cout << "YES\n";
//			continue;
//		}
//		if(p >= 3){
//			vector<int>tmp;
//			for(int i = p-3;i < p+3;i++) tmp.push_back(b[i]);
//			if(check(tmp)) {
//				cout << "YES\n";
//				continue;
//			}
//		}
//		cout << "NO\n";
//	}
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	string s;
//	cin >> s;

//	int f = 0;
//	for(int i = 0;i < s.size();i++){
//		cout << s[i];
//		if(!f && i+1 < s.size() && s[i+1] == s[i]){
//			char c = 'a';
//			if(c == s[i]) c++;
//			cout << c;
//			f = 1;
//		}
//	}
//	char c = 'a';
//	if(c == s.back()) c++;
//	if(!f) cout << c;
//	cout << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	string s[2];
//	cin >> s[0] >> s[1];
//	s[0] = ' ' + s[0] + ' ';
//	s[1] = ' ' + s[1] + ' ';

//	int ans = 0;
//	for(int i = 0;i < 2;i++){
//		for(int j = 1;j <= n;j++) if(s[i][j] == '.' && s[i][j-1] == 'x' && s[i][j+1] == 'x') {
//			if(s[i^1][j] == '.' && s[i^1][j-1] == '.' && s[i^1][j+1] == '.') ans++;
//		}
//	}
//	cout << ans << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = ' ' + s;
//	stack<int>st;
//	int ans = 0;
//	for(int i = 1;i <= n;i++){
//		if(i & 1){
//			if(st.empty()) st.push(i);
//			else {
//				ans += i-st.top();
//				st.pop();
//			}
//		}else{
//			if(s[i] == '(') st.push(i);
//			else {
//				ans += i-st.top();
//				st.pop();
//			}
//		}
//	}
//	cout << ans << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 2, p;i <= n;i++){
//		cin >> p;
//		g[p].push_back(i);
//	}

//	vector<int>f(n+5);
//	auto dfs = [&](auto self, int u) -> void {
//		f[u] = a[u];
//		int mn = 1e10;
//		for(auto v : g[u]) {
//			self(self, v);
//			mn = min(mn, f[v]);
//		}
//		if(mn == 1e10) return;
//		if(mn > f[u]) f[u] = f[u] + mn >> 1;
//		else f[u] = mn;
//	};
//	dfs(dfs, 1);

//	int mn = 1e10;
//	for(auto v : g[1]) {
//		mn = min(mn, f[v]);
//	}
//	cout << a[1] + mn << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
////#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 2e5 + 5;
//const int M = N*20;
//const int mxn = 2e5;

//int rt[N], tr[M], ls[M], rs[M], tot;
//void insert(int pre, int &id, int l, int r, int x){
//	id = ++tot;
//	ls[id] = ls[pre], rs[id] = rs[pre];
//	tr[id] = tr[pre] + 1;
//	if(l == r) return;
//	int mid = l + r >> 1;
//	if(x <= mid) insert(ls[pre], ls[id], l, mid, x);
//	else insert(rs[pre], rs[id], mid + 1, r, x);
//}
//int query(int L, int R, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return tr[R] - tr[L];
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls[L], ls[R], l, mid, ql, qr);
//	else if(ql > mid) return query(rs[L], rs[R], mid + 1, r, ql, qr);
//	else return query(ls[L], ls[R], l, mid, ql, qr) + query(rs[L], rs[R], mid + 1, r, ql, qr);
//}

//const int B = 450;

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		insert(rt[i-1], rt[i], 1, mxn, a[i]);
//	}

//	vector<vector<array<int,2>>>qur(n+5);
//	for(int i = 1;i <= q;i++) {
//		int id, x;
//		cin >> id >> x;
//		qur[x].push_back({id, i});
//	}
//	vector<int>ans(q+5);

//	vector<vector<int>>g(n+5);
//	int R = min(n, B);
//	for(int i = 1;i <= R;i++) if(qur[i].size()) {
//		sort(all(qur[i]));
//		int it = 0;

//		int lv = 1, cnt = 0;
//		for(int j = 1;j <= n;j++){
//			while(j == qur[i][it][0]) {
//				ans[qur[i][it][1]] = (a[j] >= lv);
//				if(++it == qur[i].size()) break;
//			}
//			if(it >= qur[i].size()) break;
//			if(a[j] >= lv) {
//				if(++cnt == i) {
//					lv++;
//					cnt = 0;
//					//g[i].push_back(j);
//				}
//			}
//		}
//		//g[i].push_back(N);
//	}

//	for(int i = R+1;i <= n;i++) if(qur[i].size()) {
//		sort(all(qur[i]));
//		int lsp = qur[i].back()[0];
//		int lv = 1, p = 1;
//		while(p <= lsp){
//			int l = p+i-1, r = n;
//			while(l <= r){
//				int mid = l + r >> 1;
//				if(query(rt[p-1], rt[mid], 1, mxn, lv, mxn) >= i) r = mid - 1;
//				else l = mid + 1;
//			}
//			lv++;
//			if(l <= n)
//			g[i].push_back(l);
//			p = l+1;
//		}
//		g[i].push_back(N);


//		for(auto [pos, id] : qur[i]) {
//			auto it = lower_bound(all(g[i]), pos);
//			if(*it == pos || a[pos] >= (it-g[i].begin() + 1)) ans[id] = 1;
//		}
//	}

//	for(int i = 1;i <= q;i++) {
//		if(ans[i]) cout << "YES\n";
//		else cout << "NO\n";
//	}

//	//for(int i = 1;i <= n;i++){
//	//	cout << i << " : ";
//	//	for(auto p : g[i]) cout << p << ' ';
//	//	cout << endl;
//	//}

//	//int i, x;
//	//while(q--){
//	//	cin >> i >> x;
//	//	auto it = lower_bound(all(g[x]), i);
//	//	if(*it == i || a[i] >= (it-g[x].begin() + 1)) cout << "YES\n";
//	//	else cout << "NO\n";
//	//}

//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
////#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 2e5 + 5;
//const int M = N*20;
//const int mxn = 2e5;

//int rt[N], tr[M], ls[M], rs[M], tot;
//void insert(int pre, int &id, int l, int r, int x){
//	id = ++tot;
//	ls[id] = ls[pre], rs[id] = rs[pre];
//	tr[id] = tr[pre] + 1;
//	if(l == r) return;
//	int mid = l + r >> 1;
//	if(x <= mid) insert(ls[pre], ls[id], l, mid, x);
//	else insert(rs[pre], rs[id], mid + 1, r, x);
//}
//int query(int L, int R, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return tr[R] - tr[L];
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls[L], ls[R], l, mid, ql, qr);
//	else if(ql > mid) return query(rs[L], rs[R], mid + 1, r, ql, qr);
//	else return query(ls[L], ls[R], l, mid, ql, qr) + query(rs[L], rs[R], mid + 1, r, ql, qr);
//}

//const int B = 450;

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		insert(rt[i-1], rt[i], 1, mxn, a[i]);
//	}

//	vector<vector<array<int,2>>>qur(n+5);
//	for(int i = 1;i <= q;i++) {
//		int id, x;
//		cin >> id >> x;
//		qur[x].push_back({id, i});
//	}
//	vector<int>ans(q+5);


//	vector<vector<int>>g(n+5);
//	int R = min(n, B);
//	for(int i = 1;i <= R;i++) if(qur[i].size()) {
//		int lv = 1, cnt = 0;
//		for(int j = 1;j <= n;j++) if(a[j] >= lv) {
//			if(++cnt == i) {
//				lv++;
//				cnt = 0;
//				g[i].push_back(j);
//			}
//		}
//		g[i].push_back(N);
//	}

//	for(int i = R+1;i <= n;i++) if(qur[i].size()) {
//		int lv = 1, p = 1;
//		while(p <= n){
//			int l = p+i-1, r = n;
//			while(l <= r){
//				int mid = l + r >> 1;
//				if(query(rt[p-1], rt[mid], 1, mxn, lv, mxn) >= i) r = mid - 1;
//				else l = mid + 1;
//			}
//			lv++;
//			if(l <= n)
//			g[i].push_back(l);
//			p = l+1;
//		}
//		g[i].push_back(N);
//	}

//	for(int j = 1;j <= n;j++) if(qur[j].size()){
//		for(auto [i, id] : qur[j]) {
//			auto it = lower_bound(all(g[j]), i);
//			if(*it == i || a[i] >= (it-g[j].begin() + 1)) ans[id] = 1;
//		}
//	}
//	for(int i = 1;i <= q;i++) {
//		if(ans[i]) cout << "YES\n";
//		else cout << "NO\n";
//	}

//	//int i, x;
//	//while(q--){
//	//	cin >> i >> x;
//		//auto it = lower_bound(all(g[x]), i);
//		//if(*it == i || a[i] >= (it-g[x].begin() + 1)) cout << "YES\n";
//		//else cout << "NO\n";
//	//}

//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
////#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 1010;
//int vis[N][N];


//void solve(){
//	int s, k;
//	cin >> s >> k;
//	for(int i = 1;i <= k;i++) {
//		cerr << i << ' ' << s << endl;
//		for(int i = 1;i < N;i++) if(!vis[s][i]) {
//			vis[s][i] = 1;
//			s ^= (1<<(i-1));
//			vis[s][i] = 1;
//			break;
//		}
//	}
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//using i32 = signed;
//const int N = 2e6 + 10;
//i32 cnt[N], tot = 1, np = 1;
//i32 fa[N], ch[N][26], len[N];

//void insert(int c){
//	int p = np; np = ++tot;
//	len[np] = len[p] + 1; cnt[np] = 1;
//	for(;p && !ch[p][c];p = fa[p]) ch[p][c] = np;

//	if(p == 0){
//		fa[np] = 1;
//	}else{
//		int q = ch[p][c];
//		if(len[q] == len[p]+1) fa[np] = q;
//		else{
//			int nq = ++tot;
//			len[nq] = len[p] + 1;
//			fa[nq] = fa[q]; fa[q] = nq; fa[np] = nq;
//			for(;p && ch[p][c] == q;p = fa[p]) ch[p][c] = nq;
//			memcpy(ch[nq], ch[q], sizeof(ch[q])); 
//		}
//	}
//}

//void solve(){
//	string s;
//	cin >> s;
//	for(auto c : s) insert(c-'a');
//	vector<vector<int>>g(tot+5);
//	for(int i = 2;i <= tot;i++) g[fa[i]].push_back(i);

//	int mx = 0;
//	auto dfs = [&](auto self, int u) -> void {
//		for(auto v : g[u]) {
//			self(self, v);
//			cnt[u] += cnt[v];
//		}
//		if(cnt[u] > 1) mx = max(mx, 1ll* cnt[u] * len[u]);
//	};
//	dfs(dfs, 1);

//	cout << mx << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>a(n+5, vector<int>(m+5)), f(n+5, vector<int>(m+5, -inf)), sum(n+5, vector<int>(m+5));
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++) {
//			cin >> a[i][j];
//			sum[i][j] = sum[i][j-1] + a[i][j];
//		}
//	}

//	f[0] = vector<int>(m+5, 0);
//	for(int i = 1;i <= n;i++){
//		vector<int>pre(m+5), suf(m+5);
//		for(int j = 1;j <= m;j++) pre[j] = max(0ll, pre[j-1]+a[i][j]);
//		for(int j = m;j >= 1;j--) suf[j] = max(0ll, suf[j+1]+a[i][j]);
//		int mx = -inf;
//		for(int j = 1;j <= m;j++){
//			mx = max(mx, f[i-1][j] - sum[i][j-1] + pre[j-1]);
//			f[i][j] = max(f[i][j], mx + sum[i][j] + suf[j+1]);
//		}
//		mx = -inf;
//		for(int j = m;j >= 1;j--){
//			mx = max(mx, f[i-1][j] + sum[i][j] + suf[j+1]);
//			f[i][j] = max(f[i][j], mx - sum[i][j-1] + pre[j-1]);
//		}
//	}
	
//	int ans = -inf;
//	for(int j = 1;j <= m;j++) ans = max(ans, f[n][j]);
//	cout << ans << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5), vis(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		vis[a[i]] = 1;
//	}

//	if(n == 2) {
//		if(a[1] == a[2]) {
//			cout << 1 << endl;
//			cout << "2 1 2\n";
//		}else{
//			cout << -1 << endl;
//		}
//		return;
//	}
//	int x = 0;
//	for(int i = 2;i <= k;i++) if(!vis[i]) {
//		x = i;
//		break;
//	}
//	if(!x) {
//		cout << -1 << endl;
//		return;
//	}

//	list<int>ls;
//	for(int i = 1;i <= n;i++) ls.push_back(i);
//	int y = ((n-1) % (x-1)) + 1;
//	vector<vector<int>>op;
//	int id = 1;
//	if(y > 1){
//		int sm = 0;
//		for(int i = 1;i <= n;i++) sm += a[i] == y;
//		op.push_back({});
//		if(sm >= y){
//			auto it = ls.begin();
//			while(op.back().size() < y) {
//				if(a[*it] == y) {
//					op.back().push_back(*it);
//					it = ls.erase(it);
//				}else {
//					it++;
//				}
//			}
//			ls.push_back(n+id*2-1);
//			id++;
//		}else{
//			auto it = ls.begin();
//			while(op.back().size() < y) {
//				if(a[*it] != y) {
//					op.back().push_back(*it);
//					it = ls.erase(it);
//				}else {
//					it++;
//				}
//			}
//			ls.push_back(n+id*2);
//			id++;
//		}
//	}

//	while(ls.size() > 1) {
//		op.push_back({});
//		while(op.back().size() < x) {
//			op.back().push_back(ls.back());
//			ls.pop_back();
//		}		
//		ls.push_back(n+id*2);
//		id++;
//	}
//	cout << op.size() << endl;
//	for(auto v : op) {
//		cout << v.size() << " ";
//		for(auto e : v) cout << e << ' ';
//		cout << endl;
//	}

//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	for(int i = 0;i < n;i++) cin >> a[i];
//	int i = 0, j = 1, k = 0;
//	while(1){
//		if(a[(i+k)%n] == a[(j+k)%n]) {
//			k++;
//			if(k == n) break;
//		} else {
//			if(a[(i+k)%n] > a[(j+k)%n]) i += k+1;
//			else j += k+1;
//			k = 0;
//			if(i == j) j++;
//			if(max(i, j) >= n) break;
//		}
//	}
//	int p = min(i, j);
//	i = min(i, j);
//	while(1){
//		cout << a[p] << ' ';
//		(p += 1) %= n;
//		if(p == i) break;
//	}
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 6e5 + 10;
//int cnt[N], tot = 1, np = 1;
//int fa[N], len[N];
//map<int,int>ch[N];

//void insert(int c){
//	int p = np; np = ++tot;
//	len[np] = len[p] + 1; cnt[np] = 1;
//	for(;p && !ch[p][c];p = fa[p]) ch[p][c] = np;

//	if(p == 0){
//		fa[np] = 1;
//	}else{
//		int q = ch[p][c];
//		if(len[q] == len[p]+1) fa[np] = q;
//		else{
//			int nq = ++tot;
//			len[nq] = len[p] + 1;
//			fa[nq] = fa[q]; fa[q] = nq; fa[np] = nq;
//			for(;p && ch[p][c] == q;p = fa[p]) ch[p][c] = nq;
//			ch[nq] = ch[q];
//		}
//	}
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		insert(a[i]);
//	}
//	for(int i = 1;i <= n;i++) insert(a[i]);

//	int it = 1;
//	for(int i = 1;i <= n;i++) if(ch[it].size()) {
//		cout << ch[it].begin()->first << ' ';
//		it = ch[it].begin()->second;
//	}
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 1e6 + 10;
//int fa[N];
//int find(int x){
//	return x == fa[x] ? x : fa[x] = find(fa[x]);
//}


//void solve(){
//	int n;
//	cin >> n;
//	for(int i = 1;i <= n;i++) fa[i] = i;
//	vector<vector<int>>g(n+5);
//	vector<int>par(n+5), ans(n+5), dep(n+5);
//	vector<array<int,2>>e;
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		e.push_back({u, v});
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	auto dfs = [&](auto self, int u, int fa) -> void {
//		par[u] = fa;
//		dep[u] = dep[fa] + 1;
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//		}
//	};
//	dfs(dfs, 1, 0);

//	for(int i = n/2;i >= 1;i--){
//		for(int j = i+i;j <= n;j += i){
//			int u = find(i), v = find(j);
//			while(u != v){
//				if(dep[u] < dep[v]) swap(u, v);
//				ans[u] = i;
//				fa[u] = find(par[u]);
//				u = fa[u];
//			}
//		}
//	}	

//	for(auto [u, v] : e) {
//		if(dep[u] < dep[v]) swap(u, v);
//		cout << ans[u] << ' ';
//	}
//	cout << endl;

//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
////#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//using ll = long long;


//const int N = 1e5 + 10;
//const int M = 1000000 * 20;
//const int mxn = 1e5;
//vector<array<int,3>>pr;
//vector<int>facs[N];

//int tr[M], rt[N], ls[M], rs[M], tot;
//void up(int id){
//	tr[id] = tr[ls[id]] + tr[rs[id]];
//}
//void insert(int &id, int l, int r, int x, int v){
//	if(!id) id = ++tot;
//	if(l == r){
//		tr[id] += v;
//		return;
//	}
//	int mid = l + r >> 1;
//	if(x <= mid) insert(ls[id], l, mid, x, v);
//	else insert(rs[id], mid + 1, r, x, v);
//	up(id);
//}
//void merg(int &a, int b, int l, int r){
//	if(!a || !b) {
//		a |= b;
//		return;
//	}
//	if(l == r){
//		tr[a] += tr[b];
//		return;
//	}else{
//		int mid = l + r >> 1;
//		merg(ls[a], ls[b], l, mid);
//		merg(rs[a], rs[b], mid + 1, r);
//	}
//	up(a);
//}
//int query(int id, int l, int r, int x){
//	if(l == r) return tr[id];
//	int mid = l + r >> 1;
//	if(x < mid) return query(ls[id], l, mid, x);
//	else if(x == mid) return tr[ls[id]];
//	else return query(rs[id], mid + 1, r, x) + tr[ls[id]];
//}

//void init(int n){
//	for(int i = 0;i <= tot;i++){
//		tr[i] = ls[i] = rs[i] = 0;
//	}
//	for(int i = 0;i <= n;i++) rt[i] = 0; 	
//	tot = 0;
//}

//void solve(){
//	int n;
//	cin >> n;
//	init(n);
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	vector<int>dep(n+5);
//	vector<array<int,20>>par(n+5);
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
//		for(int i = 19;i >= 0;i--) if(par[u][i] != par[v][i]) {
//			u = par[u][i];
//			v = par[v][i];
//		}
//		return par[u][0];
//	};

//	for(auto [u, v, lcm] : pr) if(v <= n) {
//		if(u != v) insert(rt[lca(u, v)], 1, mxn, lcm, 2);
//		else insert(rt[lca(u, v)], 1, mxn, lcm, 1);
//	}

//	int q;
//	cin >> q;
//	vector<vector<array<int,2>>>qur(n+5);
//	vector<int>ans(q+5);
//	for(int i = 1, r, x;i <= q;i++){
//		cin >> r >> x;
//		qur[r].push_back({x, i});
//	}

//	auto df = [&](auto self, int u, int fa) -> void {
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//			merg(rt[u], rt[v], 1, mxn);
//		}
//		for(auto [x, id] : qur[u]) {
//			ans[id] = query(rt[u], 1, mxn, x);
//		}
//	};
//	df(df, 1, 0);

//	for(int i = 1;i <= q;i++) cout << ans[i] << ' ';
//	cout << endl;


//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int n = mxn;
//	for(int i = 1;i <= n;i++){
//		for(int j = i;j <= n;j += i){
//			facs[j].push_back(i);
//		}
//	}
//	for(int i = 1;i <= n;i++){
//		for(auto a : facs[i]){
//			for(auto b : facs[i]) if(b >= a) {
//				int lcm = a * (b / gcd(a, b));
//				if(lcm == i) pr.push_back({a, b, lcm});
//			}
//		}
//	}
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
////#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//using ll = long long;


//const int N = 1e5 + 10;
//const int mxn = 1e5;
//vector<array<int,3>>pr;
//vector<int>facs[N];

//int n;
//int tr[N];
//int lowbit(int x){
//	return x & -x;
//}
//void add(int x, int v){
//	while(x <= n) {
//		tr[x] += v;
//		x += lowbit(x);
//	}
//}
//int getsum(int x){
//	int ret = 0;
//	while(x){
//		ret += tr[x];
//		x -= lowbit(x);
//	}
//	return ret;
//}
//int query(int l, int r){
//	return getsum(r) - getsum(l-1);
//}

//void init(){
//	for(int i = 0;i <= n;i++) tr[i] = 0;
//}

//void solve(){
//	cin >> n;
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	int tid = 0;
//	vector<int>dep(n+5), L(n+5), R(n+5);
//	vector<array<int,20>>par(n+5);
//	auto dfs = [&](auto self, int u, int fa) -> void {
//		L[u] = ++tid;
//		dep[u] = dep[fa] + 1;
//		par[u][0] = fa;
//		for(int i = 1;i < 20;i++) par[u][i] = par[par[u][i-1]][i-1];
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//		}
//		R[u] = tid;
//	};
//	dfs(dfs, 1, 0);
//	auto lca = [&](int u, int v) -> int {
//		if(dep[u] < dep[v]) swap(u, v);
//		for(int i = 19;i >= 0;i--) if(dep[par[u][i]] >= dep[v]) u = par[u][i];
//		if(u == v) return u;
//		for(int i = 19;i >= 0;i--) if(par[u][i] != par[v][i]) {
//			u = par[u][i];
//			v = par[v][i];
//		}
//		return par[u][0];
//	};


//	int q;
//	cin >> q;
//	vector<array<int,3>>qur;
//	vector<int>ans(q+5);
//	for(int i = 1, r, x;i <= q;i++){
//		cin >> r >> x;
//		qur.push_back({x, r, i});
//	}

//	sort(qur.begin(), qur.end());
//	int it = 0;
//	for(auto [x, r, i] : qur) {
//		while(it < pr.size() && pr[it][2] <= x){
//			auto [u, v, lcm] = pr[it];
//			if(v <= n){
//				if(u == v) add(L[lca(u, v)], 1);
//				else add(L[lca(u, v)], 2);
//			}
//			it++;
//		}
//		ans[i] = query(L[r], R[r]);
//	}

//	for(int i = 1;i <= q;i++) cout << ans[i] << ' ';
//	cout << endl;

//	init();
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int n = mxn;
//	for(int i = 1;i <= n;i++){
//		for(int j = i;j <= n;j += i){
//			facs[j].push_back(i);
//		}
//	}
//	for(int i = 1;i <= n;i++){
//		for(auto a : facs[i]){
//			for(auto b : facs[i]) if(b >= a) {
//				int lcm = a * (b / gcd(a, b));
//				if(lcm == i) pr.push_back({a, b, lcm});
//			}
//		}
//	}
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//using ll = long long;



//void solve(){
//	int n;
//	cin >>n;
//	string s;
//	cin >> s;
//	map<int,int>mp;
//	for(auto c : s) mp[c]++;
//	int ans = 0;
//	for(auto [k, v] : mp) if(k != '?') ans += min(n, v);
//	cout << ans << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//using ll = long long;



//void solve(){
//	int n;
//	cin >>n;
//	vector<int>a(n+5);
//	int s = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		s += (a[i] & 1);
//	}
//	sort(a.begin()+1, a.begin()+1+n);
//	if(s == 0 || s == n) {
//		cout << 0 << endl;
//		return;
//	}
//	int fs = 0, p = 0;
//	for(int i = n;i >= 1;i--) {
//		if(a[i] & 1){
//			if(!fs) fs = a[i];
//			if(!p) p = i;
//		}else if(fs){
//			fs += a[i];
//		}
//	}
//	int bg = 1;
//	for(int i = p+1;i <= n;i++){
//		if(fs < a[i]) {
//			bg = 0;
//			break;
//		}
//		fs += a[i];
//	}
//	//cerr << bg << endl;
//	s = n-s;
//	if(a[n] % 2 == 0 && !bg) s++;
//	cout << s << endl; 
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//using ll = long long;



//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(a.begin()+1, a.begin()+1+n);
//	for(int i = 1;i < n;i++){
//		int d = a[n] - a[i];
//		int m = d / (2 * k);
//		if(d % (2 * k) > k) m++;
//		a[i] += 2*k*m;
//	}
//	sort(a.begin()+1, a.begin()+1+n);
//	if(a[n] >= a[1] + k) cout << -1 << endl;
//	else cout << a[n] << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//using ll = long long;

//const int inf = 1e16;

//void solve(){
//	int n, k, m;
//	cin >> n >> k;
//	m = n % k;
//	if(m == 0) m = k;
//	vector<int>a(n+5), idx;
//	idx.push_back(0);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		idx.push_back(a[i]);
//	}

//	if(m == n){
//		sort(a.begin()+1, a.begin()+1+n);
//		cout << a[(n+1)/2] << endl;
//		return;
//	}

//	sort(all(idx));

//	auto check = [&](int x) -> int {
//		vector<int>f(n+5, -inf), mx(min(n, k)+5, -inf), smn(n+5, inf);
//		for(int i = n;i >= 1;i--) smn[i] = min(smn[i+1], a[i]);
//		mx[0] = 0;
//		int mxv = 0;
//		for(int i = 1;i <= n;i++) if(a[i] >= x) {
//			f[i] = max(f[i], mx[(i-1)%k]) + 1;
//			if(i+k > n){
//				if(smn[i] < x) f[i] = 0;
//			}
//			mx[i%k] = max(mx[i%k], f[i]);
//			mxv = max(mxv, f[i]);
//		}
//		return mxv*2 > m;
//	};

//	int l = 1, r = idx.size()-1;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(check(idx[mid])) l = mid + 1;
//		else r = mid - 1;
//	}

//	//for(auto e : idx) cerr << e << ' ' << check(e) << endl;
//	cout << idx[r] << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//using ll = long long;

//const int inf = 1e16;

//void solve(){
//	int n, k, m;
//	cin >> n >> k;
//	m = n % k;
//	if(m == 0) m = k;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];

//	if(m == n){
//		sort(a.begin()+1, a.begin()+1+n);
//		cout << a[(n+1)/2] << endl;
//		return;
//	}

//	auto check = [&](int x) -> int {
//		vector<int>f(m+1, -inf);
//		f[0] = 0;
//		for(int i = 1;i <= n;i++){
//			int id = (i-1) % k + 1;
//			if(id <= m) {
//				f[id] = max(f[id], f[id-1] + (a[i] >= x ? 1 : -1));
//			}
//		}
//		return f[m] > 0;
//	};

//	int l = 1, r = 1e9;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(check(mid)) l = mid + 1;
//		else r = mid - 1;
//	}

//	cout << r << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 2e5 + 10;
//int cnt[N], tot = 1, np = 1;
//int fa[N], ch[N][26], len[N];

//void insert(int c){
//	int p = np; np = ++tot;
//	len[np] = len[p] + 1; cnt[np] = 1;
//	for(;p && !ch[p][c];p = fa[p]) ch[p][c] = np;

//	if(p == 0){
//		fa[np] = 1;
//	}else{
//		int q = ch[p][c];
//		if(len[q] == len[p]+1) fa[np] = q;
//		else{
//			int nq = ++tot;
//			len[nq] = len[p] + 1;
//			fa[nq] = fa[q]; fa[q] = nq; fa[np] = nq;
//			for(;p && ch[p][c] == q;p = fa[p]) ch[p][c] = nq;
//			memcpy(ch[nq], ch[q], sizeof(ch[q])); 
//		}
//	}
//}

//void solve(){
//	int n;
//	string s;
//	cin >> n >> s;
//	for(auto c : s) insert(c - 'a');

//	int ans = 0;
//	for(int i = 2;i <= tot;i++) ans += len[i] - len[fa[i]];
//	cout << ans << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//#define ls id << 1 
//#define rs id << 1 | 1

//const int N = 2e5 + 10;
//struct node{
//	int mx, cnt;
//}tr[N<<2];
//int tag[N<<2];
//node operator+(node l, node r) {
//	node ret;
//	ret.mx = max(l.mx, r.mx);
//	if(l.mx == r.mx) {
//		ret.cnt = l.cnt + r.cnt;
//	}else if(l.mx > r.mx) {
//		ret.cnt = l.cnt;
//	}else {
//		ret.cnt = r.cnt;
//	}
//	return ret;
//}
//void up(int id){
//	tr[id] = tr[ls] + tr[rs];
//}
//void build(int id, int l, int r) {
//	tag[id] = 0;
//	if(l == r){
//		tr[id] = {0, 1};
//		return;
//	}
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//	up(id);
//}
//void settag(int id, int x) {
//	tr[id].mx += x;
//	tag[id] += x;
//}
//void down(int id){
//	settag(ls, tag[id]);
//	settag(rs, tag[id]);
//	tag[id] = 0;
//}
//void modify(int id, int l, int r, int ql, int qr, int v) {
//	if(ql <= l && r <= qr) {
//		settag(id, v);
//		return;
//	}
//	if(tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(qr <= mid) modify(ls, l, mid, ql, qr, v);
//	else if(ql > mid) modify(rs, mid + 1, r, ql, qr, v);
//	else modify(ls, l, mid, ql, qr, v), modify(rs, mid + 1, r, ql, qr, v);
//	up(id);
//}
//node query(int id, int l, int r, int ql, int qr) {
//	if(ql <= l && r <= qr) return tr[id];
//	if(tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls, l, mid, ql, qr);
//	else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//	else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
//}


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	build(1, 1, n);
//	vector<int>a(n+5);
//	unordered_map<int, vector<int>>pos;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pos[a[i]].push_back(i);
//	}


//	vector<int>L(n+5), R(n+5);
//	for(auto [key, vec] : pos) if(vec.size() >= k) {
//		L[vec[k-1]] = 1;
//		R[vec[k-1]] = vec[0];
//		for(int i = k;i < vec.size();i++){
//			L[vec[i]] = vec[i-k]+1;
//			R[vec[i]] = vec[i-k+1];
//		}
//	}
//	unordered_map<int,int>las;

//	int ans = 0, kd = 0;
//	for(int i = 1;i <= n;i++){
//		if(las[a[i]]){
//			int p = las[a[i]];
//			modify(1, 1, n, p+1, n, -1);
//			if(L[p] > 0) modify(1, 1, n, L[p], R[p], -1);
//		}else kd++;
//		if(i < n) modify(1, 1, n, i+1, n, 1);
//		if(L[i] > 0) modify(1, 1, n, L[i], R[i], 1);
//		las[a[i]] = i;

//		node ret = query(1, 1, n, 1, i);
//		if(ret.mx == kd) ans += ret.cnt;	
//	}
//	cout << ans << endl;

//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//using i128 = long long;

//const int mod = 1e9 + 7;
//const int M = 1e9+7;
//const int base = 131;
//const int N = 1e6 + 10;
//i128 pw[N];

//void gethash(string &s, vector<i128>&h){
//	int n = s.size()-1;
//	for(int i = 1;i <= n;i++)
//		h[i] = ((h[i-1]*base%M) + s[i]) % M;
//}
//i128 gethash(vector<i128>&h, int l, int r){
//	return (h[r] - (h[l-1] * pw[r-l+1] % M) + M) % M;
//}
//using ll = long long;

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	string s, t, t2;
//	cin >> s >> t;
//	t2 = t;
//	reverse(t2.begin(), t2.end());
//	s = ' ' + s;
//	t = ' ' + t;
//	t2 = ' ' + t2;

//	auto count = [&](int l, int r){
//		ll cnt[30], ans = 0;
//		for (int i = 0; i < 26; i++)
//			cnt[i] = 1;
//		for (int i = l; i <= r; i++){
//			ll tp = cnt[s[i] - 'a'];
//			ans += tp;
//			ans %= mod;
//			cnt[s[i] - 'a'] = 0;
//			for (int j = 0; j < 26; j++){
//				(cnt[j] += tp) %= mod;
//			}
//		}
//		return ans;
//	};

//	vector<i128>h1(m+1), h2(m+1);
//	gethash(t, h1);
//	gethash(t2, h2);

//	vector<vector<int>>ne(n+2, vector<int>(26, n+1)), pr(n+2, vector<int>(26, 0));
//	vector<int>las;

//	las = vector<int>(26, n+1);
//	for(int i = n;i >= 0;i--){
//		for(int j = 0;j < 26;j++) ne[i][j] = las[j];
//		if(i > 0) las[s[i]-'a'] = i;
//	}
//	las = vector<int>(26, 0);
//	for(int i = 1;i <= n+1;i++){
//		for(int j = 0;j < 26;j++) pr[i][j] = las[j];
//		if(i <= n) las[s[i]-'a'] = i;
//	}

//	int p1 = 0, p2 = n+1;
//	for(int i = 1;i <= m;i++) p1 = ne[p1][t[i]-'a'];
//	int mx = 0;
//	for(int i = 1;i <= m;i++){
//		p2 = pr[p2][t[i]-'a'];
//		if(p2 > p1) mx = i;
//	}
//	if(p1 > n) {
//		cout << 0 << endl;
//		return;
//	}

//	int ans = 0;
//	if(p1 < p2) ans++;
//	if(p1+1 < p2) {
//		(ans += count(p1+1, p2-1)) %= mod;
//		//int l = p1+1, r = p2-1;
//		//vector<int>f(r-l+2), las(26);
//		//for(int i = l;i <= r;i++){
//		//	int id = i-l+1;
//		//	f[id] = (2*f[id-1]+1 - f[las[s[i]-'a']] + mod) % mod;
//		//	las[s[i]-'a'] = id;
//		//}
//		//(ans += f[r-l+1]) %= mod;
//	}
//	//cerr << p1 << ' ' << p2 << endl;
//	//cerr << mx << endl;

//	//cerr << ans << endl;
//	for(int i = min(m, mx+1);i >= 1;i--) {
//		(ans += gethash(h1, i, m) == gethash(h2, 1, m-i+1)) %= mod;
//	}

//	cout << ans << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	pw[0] = 1;
//	for(int i = 1;i < N;i++) pw[i] = pw[i-1] * base % M;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//unordered_map<char, array<int,2>>op;

//void solve(){
//	int n, k, w, h;
//	cin >> n >> k >> w >> h;
//	string s;
//	cin >> s;
//	w *= 2;
//	h *= 2;

//	unordered_map<int, unordered_map<int,int>>mp;
//	int x = 0, y = 0;
//	for(auto c : s) {
//		(x += op[c][0] + w) %= w;
//		(y += op[c][1] + h) %= h;
//		mp[x][y]++;
//	}
//	int ex = x, ey = y;

//	int tx = 0, ty = 0;
//	int ans = 0;
//	for(int i = 1;i <= k;i++){
//		ans += mp[tx][ty];
//		tx = (w - x) % w;
//		ty = (h - y) % h;
//		(x += ex) %= w;
//		(y += ey) %= h;
//	}
//	cout << ans << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

//	op['U'] = {0, 1};
//	op['D'] = {0, -1};
//	op['L'] = {-1, 0};
//	op['R'] = {1, 0};

//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const double eps = 1e-7;

//struct P{
//	double x, y;
//	P() {}
//	P(double x, double y) : x(x), y(y) {}
//	P operator-(const P &e) const { return P(x-e.x, y-e.y); }
//	P operator+(const P &e) const { return P(x+e.x, y+e.y); }
//	P operator*(double k) const { return P(x*k, y*k); }
//	double operator*(const P &e) const { return x*e.y - y*e.x; }
//};
//struct Line{
//	P s, e;
//	Line() {}
//	Line(P s, P e) : s(s), e(e) {}

//	double angle() const {
//		return atan2(e.y-s.y, e.x-s.x);
//	}

//	int operator<(const Line& b) const {
//		double A = angle(), B = b.angle();
//		return fabs(A-B) > eps ? A<B : (e-s)*(b.e-s) < 0; //先比较斜率，再比较截距，靠内的更小
//	}

//	P cross(Line b) { //求两直线交点
//	    P u = s - b.s, v = e - s, w = b.e - b.s;
//	    double t = (u * w) / (w * v);
//	    return s + (v * t);
//	}
//	bool right(P p) { //判断点是否在直线右边
//		return (e-s) * (p-s) < 0;
//	}
//};

//vector<P> half_plane(vector<Line> L) {
//	int n = L.size();
//	sort(all(L));
//	vector<Line>q(n+5);
//	int h = 0, t = 0; q[0] = L[0];
//	for(int i = 1;i < n;i++){
//		if(fabs(L[i].angle() - L[i-1].angle()) < eps) continue;
//		while(t>h && L[i].right(q[t].cross(q[t-1]))) t--;
//		while(t>h && L[i].right(q[h].cross(q[h+1]))) h++;
//		q[++t] = L[i];
//	}
//	while(t>h && q[h].right(q[t].cross(q[t-1]))) t--;
//	q[++t] = q[h];
//	vector<P>ret;
//	for(int i = h;i < t;i++) ret.push_back(q[i].cross(q[i+1]));
//	return ret;
//}

//double area(vector<P> p){
//	double res = 0;
//	int n = p.size();
//	for(int i = 1;i + 1 < n;i++) res += (p[i]-p[0]) * (p[i+1]-p[0]);
//	return res/2.0;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<Line>L;
//	for(int i = 1, m;i <= n;i++){
//		cin >> m;
//		vector<P>p(m);
//		for(int j = 0;j < m;j++) cin >> p[j].x >> p[j].y;
//		for(int j = 0;j < m;j++) L.push_back(Line(p[j], p[(j+1)%m]));
//	}

//	cout << fixed << setprecision(3) << area(half_plane(L)) << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 1e15;


//void solve(){
//	int n, m, tot = 0;
//	cin >> n;
//	vector<int>dfn(n+5), dep(n+5);
//	vector<vector<int>>par(n+5, vector<int>(20)), mn(n+5, vector<int>(20, inf));
//	vector<vector<array<int,2>>>g(n+5), G(n+5);
//	for(int i = 1, u, v, w;i < n;i++){
//		cin >> u >> v >> w;
//		g[u].push_back({v, w});
//		g[v].push_back({u, w});
//	}

//	auto dfs1 = [&](auto self, int u, int fa, int d) -> void {
//		dfn[u] = ++tot;
//		dep[u] = dep[fa] + 1;
//		par[u][0] = fa;
//		mn[u][0] = d;
//		for(int i = 1;i < 20;i++){
//			par[u][i] = par[par[u][i-1]][i-1];
//			mn[u][i] = min(mn[u][i-1], mn[par[u][i-1]][i-1]);
//		}
//		for(auto [v, w] : g[u]) if(v != fa) {
//			self(self, v, u, w);
//		}
//	};
//	dfs1(dfs1, 1, 0, 0);

//	auto lca = [&](int u, int v) -> int {
//		if(dep[u] < dep[v]) swap(u, v);
//		for(int i = 19;i >= 0;i--) if(dep[par[u][i]] >= dep[v]) u = par[u][i];
//		if(u == v) return u;
//		for(int i = 19;i >= 0;i--) if(par[u][i] != par[v][i]) {
//			u = par[u][i];
//			v = par[v][i];
//		}
//		return par[u][0];
//	};

//	auto dis = [&](int u, int v) -> int {
//		if(dep[u] < dep[v]) swap(u, v);
//		int ret = mn[u][0];
//		for(int i = 19;i >= 0;i--) if(dep[par[u][i]] >= dep[v]) {
//			ret = min(ret, mn[u][i]);
//			u = par[u][i];
//		}
//		return ret;
//	};

//	vector<int>isq(n+5);
//	auto dfs = [&](auto self, int u, int d) -> int {
//		int s = 0;
//		for(auto [v, w] : G[u]) {
//			s += self(self, v, w);
//		}
//		G[u].clear();
//		if(isq[u]) return d;
//		return min(s, d);
//	};	

//	cin >> m;
//	while(m--){
//		int k, top = 0;
//		cin >> k;
//		vector<int>p(k), st(k*2+5);
//		for(int i = 0;i < k;i++){
//			cin >> p[i];
//			isq[p[i]] = 1;
//		}
//		sort(all(p), [&](int i, int j) -> int {
//			return dfn[i] < dfn[j];
//		});

//		st[++top] = 1;
//		for(auto u : p) {
//			int lc = lca(u, st[top]);
//			if(lc == st[top]) {
//				st[++top] = u;
//				continue;
//			}
//			while(dep[st[top-1]] >= dep[lc]){
//				G[st[top-1]].push_back({st[top], dis(st[top], st[top-1])});
//				top--;
//			}
//			if(st[top] == lc) {
//				st[++top] = u;
//				continue;
//			}
//			G[lc].push_back({st[top], dis(st[top], lc)});
//			top--;
//			st[++top] = lc;
//			st[++top] = u;
//		}
//		while(top > 1) {
//			G[st[top-1]].push_back({st[top], dis(st[top], st[top-1])});
//			top--;
//		}

//		cout << dfs(dfs, 1, inf) << endl;
//		for(auto u : p) isq[u] = 0;
//	}
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 1e15;


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>d(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		d[u]++;
//		d[v]++;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	int ans = 0, mx = 0;
//	for(int i = 1;i <= n;i++) ans += d[i] == 1;

//	vector<int>siz(n+5);
//	auto dfs = [&](auto self, int u, int fa) -> void {
//		siz[u] = 1;
//		for(auto v : g[u]) if(v != fa) {
//			self(self, v, u);
//			siz[u] += siz[v];
//		}
//	};
//	auto dfs2 = [&](auto self, int u, int fa) -> void {
//		int cnt = 0;
//		if(d[fa] == 2 && n-siz[u] > 2) cnt++;
//		for(auto v : g[u]) if(v != fa) {
//			self(self, v, u);
//			cnt += d[v] == 1 && siz[v] > 2;
//		}
//		mx = max(mx, cnt);
//	};
//	dfs(dfs, 1, 0);
//	dfs2(dfs2, 1, 0);

//	cout << ans + mx << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 1e15;


//void solve(){
//	int n;
//	cin >> n;
//	vector<array<array<int,2>,2>>f(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	if(n == 2) {
//		cout << 2 << endl;
//		return;
//	}

//	auto dfs = [&](auto self, int u, int fa) -> void {
//		if(g[u].size() == 1 && fa) {
//			f[u][0][0] = 0;
//			f[u][1][0] = 0;
//			f[u][1][1] = 1;
//			f[u][0][1] = 0;
//			return;
//		}
//		int d0 = inf, d1 = inf;
//		for(auto v : g[u]) if(v != fa) {
//			self(self, v, u);
//			f[u][0][1] += max(f[v][0][1], f[v][1][1]);
//			f[u][1][1] += f[v][0][1];
//			if(max(f[v][0][1], f[v][1][1]) > max(f[v][0][0], f[v][1][0])){
//				f[u][0][0] += max(f[v][0][1], f[v][1][1]);
//				d0 = min(d0, max(f[v][0][1], f[v][1][1]) - max(f[v][0][0], f[v][1][0]));
//			}else{
//				f[u][0][0] += max(f[v][0][0], f[v][1][0]);
//				d0 = 0;
//			}
//			if(f[v][0][1] > f[v][0][0]){
//				f[u][1][0] += f[v][0][1];
//				d1 = min(d1, f[v][0][1] - f[v][0][0]);
//			}else{
//				f[u][1][0] += f[v][0][0];
//				d1 = 0;
//			}
//		}
//		f[u][0][0] -= d0;
//		f[u][1][0] -= d1;
//		f[u][1][0]++;
//		f[u][1][1]++;
//	};

//	int ans = 0;
//	for(int u = 1;u <= n;u++) if(g[u].size() > 1){
//		dfs(dfs, u, 0);
//		f[u][0][0]++;
//		f[u][1][0]++;
//		for(int i = 0;i < 2;i++){
//			for(int j = 0;j < 2;j++){
//				ans = max(ans, f[u][i][j]);
//				//cerr << f[1][i][j] << ' ';
//			}
//			//cerr << endl;
//		}
//		break;
//	}

//	cout << ans << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>dot(n+5), din(n+5), it(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		dot[u]++;
//		din[v]++;
//		g[u].push_back(v);
//	}

//	int fin = 0, fot = 0;
//	for(int i = 1;i <= n;i++){
//		if(din[i] > dot[i]) fin += din[i] - dot[i];
//		else if(dot[i] > din[i]) fot += dot[i] - din[i];
//		sort(all(g[i]));
//	}

//	if(fin != fot || fin > 1) {
//		cout << "No\n";
//		return;
//	}

//	vector<int>ans;
//	auto dfs = [&](auto self, int u) -> void {
//		while(it[u] < g[u].size()){
//			self(self, g[u][it[u]++]);
//		}
//		ans.push_back(u);
//	};

//	if(fin == 0) dfs(dfs, 1);
//	else{
//		for(int i = 1;i <= n;i++) if(dot[i]-1 == din[i]) {
//			dfs(dfs, i);
//			break;
//		}
//	}

//	reverse(all(ans));
//	for(auto u : ans) cout << u << ' ';
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

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

//int val(int x){
//	int ret = (x * (x-1)) / 2;
//	if(x % 2 == 0) ret -= x/2 - 1;
//	return ret + x;
//}

//void solve(){
//	int n;
//	cin >> n;

//	int l = 1, r = 2000;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(val(mid) + 1 >= n) r = mid - 1;
//		else l = mid + 1;
//	}

//	//cerr << m << endl;
//	int m = l, tot = 0;
//	vector<int>it(m+5);
//	vector<vector<array<int,2>>>g(m+5);
//	for(int i = 1;i <= m;i++){
//		g[i].push_back({i, ++tot});
//		int j = i+1;
//		if(m % 2 == 0 && i > 1 && (i & 1)) j++;
//		for(j;j <= m;j++) {
//			++tot;
//			g[i].push_back({j, tot});
//			g[j].push_back({i, tot});
//		} 
//	}

//	vector<int>vis(tot+5);
//	vector<int>ans;
//	auto dfs = [&](auto self, int u) -> void {
//		while(it[u] < g[u].size()){
//			auto [v, t] = g[u][it[u]++];
//			if(vis[t]++) continue;
//			self(self, v);
//		}
//		ans.push_back(u);
//	};
//	dfs(dfs, 1);
//	reverse(all(ans));

//	for(int i = 0;i < n;i++) cout << prime[ans[i]] << " ";
//	cout << endl;

//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	euler();
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int x, y, k;
//	cin >> x >> y >> k;
//	if(k == 1){
//		cout << x << ' ' << y << endl;
//		return;
//	}
//	vector<array<int,2>>a;
//	int sy = 0;
//	for(int i = 1;i < k-1;i++){
//		a.push_back({x, i});
//		sy += i;
//	}
//	a.push_back({x, 10000});
//	sy += 10000;
//	int d = y*k - sy;
//	a.push_back({x, d});
//	sy += d;
//	//cerr << sy/k << endl;

//	for(auto [x, y] : a) cout << x << ' ' << y << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		cout << (a[i]%n)+1 << ' ';
//	}
//	cout << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5), b(n+5), id(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	int mx = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> b[i];
//		if(!b[i]) {
//			if(a[i] >= a[mx]) mx = i;
//		}
//	}

//	int ans = 0;
//	if(mx){
//		vector<int>id;
//		for(int i = 1;i <= n;i++) if(i != mx) id.push_back(i);
//		sort(all(id), [&](int i, int j) -> int {
//			return a[i] < a[j];
//		});

//		auto check = [&](int x) -> int {
//			int cnt = 0, s = k;
//			for(int i = id.size()-1;i >= 0;i--){
//				if(a[id[i]] >= x) {
//					cnt++;
//					continue;
//				}
//				if(b[id[i]]) {
//					if(s >= x - a[id[i]]) {
//						cnt++;
//						s -= x-a[id[i]];
//					}
//					else break;
//				}
//			}
//			return cnt * 2 > n-1;
//		};

//		int l = 1, r = 1e9;
//		while(l <= r){
//			int mid = l + r >> 1;
//			if(check(mid)) l = mid + 1;
//			else r = mid - 1;
//		}
//		int h = r;

//		ans = max(ans, h + a[mx]);
//	}

//	iota(all1(id), 1);
//	sort(all1(id), [&](int i, int j) -> int {
//		return a[i] < a[j];
//	});

//	int mid = n/2;
//	for(int i = 1;i <= n;i++) if(b[id[i]]) {
//		int md = mid;
//		if(i <= mid) md++;
//		ans = max(ans, a[id[i]] + k + a[id[md]]);
//	}
//	cout << ans << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 1e9;

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>g(n+5);
//	vector<int>far(n+5);
//	for(int i = 1;i < n;i++){
//		g[i].push_back(i+1);
//		far[i] = i+1;
//	}
//	for(int i = 1, u, v;i <= m;i++) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		far[u] = max(far[u], v);
//	}

//	vector<int>dis(n+5, inf);
//	dis[1] = 0;
//	queue<int>que;
//	que.push(1);
//	while(que.size()){
//		int u = que.front();
//		que.pop();
//		for(auto v : g[u]) if(dis[u] + 1 < dis[v]) {
//			dis[v] = dis[u] + 1;
//			que.push(v);
//		}
//	}

//	vector<int>pre(n+5);
//	for(int i = 1;i <= n;i++){
//		int l = i+1;
//		int r = far[i] - dis[i] - 1 - 1;
//		if(l <= r) {
//			pre[l]++;
//			pre[r+1]--;
//		}
//	}

//	for(int i = 1;i < n;i++){
//		pre[i] += pre[i-1];
//		if(pre[i] == 0) cout << 1;
//		else cout << 0;
//	}
//	cout << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 1e9;
//const int N = 2e5 + 10;

//int n, a[N];

//struct node{
//	int sum, sl, sr;
//}tr[N<<2];
//#define ls id << 1
//#define rs id << 1 | 1

//node operator+(node l, node r) {
//	node ret;
//	ret.sum = l.sum + r.sum;
//	ret.sl = l.sl + max(0ll, r.sl - l.sum);
//	ret.sr = r.sr + max(0ll, l.sr - r.sum);
//	return ret;
//}

//void up(int id){
//	tr[id] = tr[ls] + tr[rs];
//}
//void build(int id, int l, int r){
//	if(l == r){
//		tr[id] = {a[l], a[l], a[l]};
//		return;
//	}
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//	up(id);
//}
//node query(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return tr[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls, l, mid, ql, qr);
//	else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//	else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
//}
//int searchl(int id, int l, int r, int p, int &v){
//	if(l == r){
//		if(v >= tr[id].sum) {
//			v += tr[id].sum;
//			return l;
//		}
//		return l+1;
//	}
//	int mid = l + r >> 1;
//	if(p <= mid) return searchl(ls, l, mid, p, v);
//	else{
//		if(p >= r){
//			if(v >= tr[rs].sr) {
//				v += tr[rs].sum;
//				return searchl(ls, l, mid, p, v);
//			}else return searchl(rs, mid + 1, r, p, v);
//		}else{
//			int L = searchl(rs, mid + 1, r, p, v);
//			if(L == mid + 1) return searchl(ls, l, mid, p, v);
//			return L;
//		}
//	}
//}	
//int searchr(int id, int l, int r, int p, int &v){
//	if(l == r){
//		if(v >= tr[id].sum){
//			v += tr[id].sum;
//			return l;
//		}
//		return l-1;
//	}
//	int mid = l + r >> 1;
//	if(p > mid) return searchr(rs, mid+1, r, p, v);
//	else {
//		if(p <= l){
//			if(v >= tr[ls].sl) {
//				v += tr[ls].sum;
//				return searchr(rs, mid + 1, r, p, v);
//			}else return searchr(ls, l, mid, p, v);
//		}else{
//			int R = searchr(ls, l, mid, p, v);
//			if(R == mid) return searchr(rs, mid + 1, r, p, v);
//			return R;
//		}
//	}
//}

//void solve(){
//	int sum = 0, k;
//	cin >> n >> k;
//	vector<int>pre(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pre[i] = pre[i-1] + a[i];
//		sum += a[i];
//	}
//	build(1, 1, n);

//	int ans = 0;
//	for(int i = 1;i <= n;i++){
//		int q = i, p = i, s = a[i];

//		while(1){
//			int l, r, fg = 0;
//			if(q > 1 && s >= a[q-1]){
//				q = searchl(1, 1, n, q-1, s);
//				fg = 1;
//			}
//			if(p < n && s >= a[p+1]){
//				p = searchr(1, 1, n, p+1, s);
//				fg = 1;
//			}
//			if(!fg) break;
//		}

//		ans += s == sum;

//	}

//	cout << ans << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1
 
//const int inf = 1e9;
//const int N = 2e5 + 10;
 
//int n, a[N], k;
 
//struct node{
//	int sum, sl, sr;
//}tr[N<<2];
 
//node operator+(node l, node r) {
//	node ret;
//	ret.sum = l.sum + r.sum;
//	ret.sl = l.sl + max(0ll, r.sl - (l.sum + l.sl));
//	ret.sr = r.sr + max(0ll, l.sr - (r.sum + r.sr));
//	return ret;
//}
 
//void up(int id){
//	tr[id] = tr[ls] + tr[rs];
//}
//void build(int id, int l, int r){
//	if(l == r){
//		tr[id] = {a[l], a[l], a[l]};
//		return;
//	}
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//	up(id);
//}
//int searchl(int id, int l, int r, int p, int &v){
//	if(l == r){
//		if(v >= tr[id].sum) {
//			v += tr[id].sum;
//			return l;
//		}
//		return l+1;
//	}
//	int mid = l + r >> 1;
//	if(p <= mid) return searchl(ls, l, mid, p, v);
//	else{
//		if(p >= r){
//			if(v >= tr[rs].sr) {
//				v += tr[rs].sum;
//				return searchl(ls, l, mid, p, v);
//			}else return searchl(rs, mid + 1, r, p, v);
//		}else{
//			int L = searchl(rs, mid + 1, r, p, v);
//			if(L == mid + 1) return searchl(ls, l, mid, p, v);
//			return L;
//		}
//	}
//}	
//int searchr(int id, int l, int r, int p, int &v){
//	if(l == r){
//		if(v >= tr[id].sum){
//			v += tr[id].sum;
//			return l;
//		}
//		return l-1;
//	}
//	int mid = l + r >> 1;
//	if(p > mid) return searchr(rs, mid+1, r, p, v);
//	else {
//		if(p <= l){
//			if(v >= tr[ls].sl) {
//				v += tr[ls].sum;
//				return searchr(rs, mid + 1, r, p, v);
//			}else return searchr(ls, l, mid, p, v);
//		}else{
//			int R = searchr(ls, l, mid, p, v);
//			if(R == mid) return searchr(rs, mid + 1, r, p, v);
//			return R;
//		}
//	}
//}

//void solve(){
//	cin >> n >> k;
//	vector<int>pre(n+5), ans(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pre[i] = pre[i-1] + a[i];
//	}
//	build(1, 1, n);

//	for(int i = 1;i <= n;i++){
//		int L = i, R = i, tmp;

//		if(L > 1)
//		while(1){
//			tmp = pre[R] - pre[L-1];
//			L = searchl(1, 1, n, L-1, tmp);
//			if(L == 1) break;
//			if(R < n){
//				int l = R, r = n, pos = R;
//				while(l <= r){
//					int mid = l + r >> 1;
//					if(pre[mid] - pre[L-1] >= a[L-1]) pos = mid, r = mid - 1;
//					else l = mid + 1;
//				}
//				l = pos;
//				if(pre[l] - pre[L-1] < a[L-1]) break;
//				tmp = pre[R] - pre[L-1];
//				int mxr = searchr(1, 1, n, R+1, tmp);
//				if(mxr < l) break;
//				R = l;
//			}else break;
//		}

//		if(L == 1){
//			tmp = pre[R];
//			int p = (R < n ? searchr(1, 1, n, R+1, tmp) : R);
//			ans[R]++;
//			ans[p+1]--;
//		}
//	}

//	for(int i = 1;i <= n;i++) {
//		ans[i] += ans[i-1];
//		if(i >= k) cout << ans[i] << ' ';
//	}
//	cout << endl;
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1
 


//void solve(){
//	int n, m, k;
//	cin >> n >> m >> k;
//	if(m > n) swap(n, m);
//	cout << min(k, n) * min(k, m) << endl;	
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1
 


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), b(n+5), ap(n+5), bp(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		ap[a[i]] = i;
//	}
//	for(int i = 1;i <= n;i++){
//		cin >> b[i];
//		bp[b[i]] = i;
//	}

//	for(int i = 1;i <= n;i++){
//		set<int>st;
//		st.insert(a[ap[i]+1]);
//		st.insert(a[ap[i]-1]);
//		if(st.count(b[bp[i]+1]) == 0 || st.count(b[bp[i]-1]) == 0) {
//			cout << "Alice\n";
//			return;
//		}
//	}
//	cout << "Bob\n";
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1
 
//int dis2(int x, int y, int x2, int y2) {
//	int dx = x - x2;
//	int dy = y - y2;
//	return dx*dx + dy*dy;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<array<int,2>>a(n);
//	for(auto &[x, y] : a) cin >> x >> y;
//	int xs, ys, xt, yt;
//	cin >> xs >> ys >> xt >> yt;

//	int d = dis2(xs, ys, xt, yt);
//	for(auto [x, y] : a) {
//		if(dis2(x, y, xt, yt) <= d) {
//			//cerr << x << ' ' << y << endl;
//			cout << "NO\n";
//			return;
//		}
//	}
//	cout << "YES\n";
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1


//void solve(){
//	int n, q, wa = 0, tot = 0;
//	cin >> n >> q;
//	vector<int>id(n+5), dfn(n+5), pid(n+5);

//	auto dfs = [&](auto self, int u) -> void {
//		if(u > n) return;
//		dfn[u] = ++tot;
//		pid[tot] = u;
//		self(self, u << 1);
//		self(self, u << 1 | 1);
//	};
//	dfs(dfs, 1);

//	for(int i = 2, u;i <= n;i++) cin >> u;
//	for(int df = 1, u;df <= n;df++){
//		cin >> u;
//		int i = pid[df];
//		id[i] = u;
//		wa += (id[i/2] != id[i]/2);
//	}

//	auto check0 = [&](int i) -> void {
//		if(i > n) return;
//		if(id[i/2] == id[i]/2) wa++;
//	};
//	auto check = [&](int i) -> void {
//		if(i > n) return;
//		if(id[i/2] == id[i]/2) wa--;
//	};

//	int x, y;
//	while(q--){
//		cin >> x >> y;
//		x = pid[x];
//		y = pid[y];
//		set<int>ck;
//		ck.insert(x);
//		ck.insert(y);
//		ck.insert(x<<1);
//		ck.insert(x<<1|1);
//		ck.insert(y<<1);
//		ck.insert(y<<1|1);
//		for(auto u : ck) check0(u);
//		swap(id[x], id[y]);
//		for(auto u : ck) check(u);

//		if(wa == 0) cout << "YES\n";
//		else cout << "NO\n";
//	}
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
#define all1(x) (x).begin()+1, (x).begin()+1+n
#define ls id << 1
#define rs id << 1 | 1

const int N = 3e5 + 10;
int mx[N<<2];
void up(int id){
	mx[id] = max(mx[ls], mx[rs]);
}
void build(int id, int l, int r){
	if(l == r){
		mx[id] = 0;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	up(id);
}
void insert(int id, int l, int r, int x, int v){
	if(l == r){
		mx[id] = max(mx[id], v);
		return;
	}
	int mid = l + r >> 1;
	if(x <= mid) insert(ls, l, mid, x, v);
	else insert(rs, mid + 1, r, x, v);
	up(id); 
}
int query(int id, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return mx[id];
	int mid = l + r >> 1;
	if(qr <= mid) return query(ls, l, mid, ql, qr);
	else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
	else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
}

void solve(){
	int n;
	cin >> n;
	build(1, 1, n);
	vector<int>a(n+5), b(n+5), las(n+5), t(n+5);
	for(int i = 1;i <= n;i++) cin >> a[i] >> b[i];

	int ans = 0;
	for(int i = 1;i <= n;i++){
		t[i] = a[i];
		int f = 1;
		if(las[b[i]]) {
			int l = las[b[i]]+1, r = i-1;
			int ret = query(1, 1, n, l, r);
			if(t[i] >= ret) t[i] += max(0ll, t[las[b[i]]] - ret);
			else f = 0;
		}
		insert(1, 1, n, i, t[i]);
		if(f){
			las[b[i]] = i;
		}
		ans = max(ans, t[i]);
		cout << ans << ' ';
	}
	cout << endl;
}	

signed main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();

	return 0;
}