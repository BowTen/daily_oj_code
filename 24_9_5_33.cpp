//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'

//struct node{
//	int x, y;
//	node(){}
//	node(int x, int y) : x(x), y(y) {}
//	int operator<(node e) {
//		if(x == e.x) return y < e.y;
//		return x < e.x;
//	}
//};

//int cross(node a, node b, node c) {
//	node x(b.x-a.x, b.y-a.y);
//	node y(c.x-a.x, c.y-a.y);
//	return (x.x * y.y) - (x.y * y.x);
//}

//int dis2(node a, node b){
//	int dx = a.x-b.x;
//	int dy = a.y-b.y;
//	return dx*dx + dy*dy;
//}

//void solve(){
//	int n, top = 0;
//	cin >> n;
//	vector<node>a(n+5), st(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
	
//	sort(a.begin()+1, a.begin()+1+n);
//	for(int i = 1;i <= n;i++){
//		while(top > 1 && cross(st[top-1], st[top], a[i]) <= 0) top--;
//		st[++top] = a[i];
//	}
//	int t = top;
//	for(int i = n-1;i >= 1;i--){
//		while(top > t && cross(st[top-1], st[top], a[i]) <= 0) top--;
//		st[++top] = a[i];
//	}

//	int m = top-1;
//	int len = 0;
//	// i,i+1 枚举一条边，j 枚举对踵点
//	for(int i = 1, j = 2;i <= m;i++){
//		while(cross(st[i], st[i+1], st[j]) < cross(st[i], st[i+1], st[j+1])) j = (j%m)+1;
//		len = max(len, dis2(st[i], st[j]));
//	}
//	cout << len << endl;
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


//void solve(){
//	int n, x = 0, y = 0;
//	cin >> n;
//	vector<int>a(n+5), b(n+5), c(n+5);
//	for(int i = 1;i <= n;i++) {cin >> a[i]; x ^= a[i];}
//	for(int i = 1;i <= n;i++) {cin >> b[i]; y ^= b[i];}
//	for(int i = 1;i <= n;i++) c[i] = (a[i] ^ b[i]);

//	vector<int>f(33);
//	auto insert = [&](int x) -> void {
//		for(int i = 31;i >= 0;i--) if((x >> i) & 1) {
//			if(!f[i]){
//				f[i] = x;
//				return;
//			}
//			x ^= f[i];
//		}
//	};

//	for(int i = 1;i <= n;i++) insert(c[i]);
//	for(int i = 31;i >= 0;i--) if(f[i]) {
//		if(((x>>i)&1) && ((y>>i)&1)){
//			x ^= f[i];
//			y ^= f[i];
//		}else if((x>>i)&1){
//			if(x > y){
//				x ^= f[i];
//				y ^= f[i];
//			}
//		}else if((y>>i)&1){
//			if(y > x){
//				x ^= f[i];
//				y ^= f[i];
//			}
//		}
//	}

//	cout << max(x, y) << endl;
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
//	int n, m;
//	cin >> n >> m;

//	int mx = 1, tmp = 26;
//	for(int i = 1;i <= m;i++){
//		(mx += min(n, tmp)) %= mod;
//		tmp *= 26;
//		if(tmp > n) tmp = n;
//	}

//	int ans = 1;
//	tmp = 26;
//	for(int i = 1;i <= m;i++){
//		int p = (tmp-1) * qpow(tmp, mod-2) % mod;
//		p = qpow(p, n);
//		p = (1 - p + mod) % mod;
//		(ans += tmp * p) %= mod;
//		(tmp *= 26) %= mod;
//	}

//	cout << mx << ' ' << ans << endl;
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
////#define endl '\n'


//void solve(){
//	int n, ret;
//	cin >> n;
//	vector<vector<int>>g(n+5), p(n+5);
//	vector<int>fa(n+5), dep(n+5), L(n+5), R(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}


//	int l = 1, r = 1, cnt = 0 , rt = 1, tot = 0;
//	auto dfs = [&](auto self, int u, int f) -> void {
//		L[u] = ++tot;
//		dep[u] = dep[f] + 1;
//		r = max(r, dep[u]);
//		p[dep[u]].push_back(u);
//		fa[u] = f;
//		for(auto v : g[u]) if(v != f) {
//			self(self, v, u);
//		}
//		R[u] = tot;
//	};
//	dfs(dfs, 1, 0);

//	while(l < r){
//		int mid = (l + r + 1) >> 1;
//		for(auto u : p[mid]) if(L[rt] <= L[u] && L[u] <= R[rt]) {
//			if(cnt == 160){
//				cout << "! 1" << endl;
//				return;
//			}
//			cout << "? " << u << endl;
//			cin >> ret;
//			cnt++;
//			if(ret){
//				l = mid;
//				rt = u;
//				break;
//			}
//			if(rt != 1){
//				if(cnt == 160){
//					cout << "! 1" << endl;
//					return;
//				}
//				cout << "? " << rt << endl;
//				cin >> ret;
//				cnt++;
//				if(!ret){
//					rt = fa[rt];
//					rt = fa[rt];
//					if(rt == 0) rt = 1;
//					cout << "! " << rt << endl;
//					return;
//				}
//			}
//		}
//		if(l != mid) r = mid - 1;
//	}

//	cout << "! " << rt << endl;
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

//const int N = 55;
//int f[N];
//void insert(int x){
//	for(int i = N-1;i >= 0;i--) if((x >> i) & 1) {
//		if(!f[i]){
//			f[i] = x;
//			return;
//		}
//		x ^= f[i];
//	}
//}
//void gauss(){
//	for(int i = N-1;i >= 0;i--) if(f[i]) {
//		for(int j = i+1;j < N;j++) if(f[j] & (1LL << i)) f[j] ^= f[i];
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
//	gauss();
//	int x = 0;
//	for(int i = 0;i < N;i++) x ^= f[i];
//	cout << x << endl;

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

//const double eps = 1e-8;
//const int N = 505;
//int mp[N][N], n, m, d[N];
//double a[N][N], f[N], e[N*N];
//array<int,2>E[N*N];

//bool gauss(int n){
//	for(int i = 1;i <= n;i++){
//		int r = i;
//		for(int j = i+1;j <= n;j++) if(fabs(a[j][i]) > fabs(a[r][i])) {
//			r = j;
//		}
//		if(i != r) swap(a[i], a[r]);
//		if(fabs(a[i][i] < eps)) return 0; // 无解
//		for(int r = 1;r <= n;r++) if(r != i){
//			double t = a[r][i]/a[i][i];
//			for(int j = n+1;j >= i;j--){
//				a[r][j] -= t*a[i][j];
//			}
//		}
//	}
//	for(int i = 1;i <= n;i++){
//		f[i] = a[i][n+1]/a[i][i];
//	}
//	return 1; // 存在唯一解
//}

//void solve(){
//	cin >> n >> m;
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		E[i] = {u, v};
//		mp[u][v] = mp[v][u] = 1;
//		d[u]++;
//		d[v]++;
//	}

//	a[1][n] = 1;
//	for(int i = 1;i < n;i++){
//		a[i][i] = 1;
//		for(int j = 1;j < n;j++) if(i != j && mp[i][j]) {
//			a[i][j] = -1.0/d[j];
//		}
//	}
//	gauss(n-1);

//	for(int i = 1;i <= m;i++){
//		auto [u, v] = E[i];
//		e[i] += f[u]/d[u];
//		e[i] += f[v]/d[v];
//	}

//	sort(e+1, e+1+m);
//	double ans = 0;
//	for(int i = 1, t = m;i <= m;i++, t--) ans += e[i] * t;
//	cout << fixed << setprecision(3);
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

//const double eps = 1e-8;
//const int N = 505;
//int mp[N][N], n, m, d[N];
//double a[N][N], f[N], e[N*N];
//array<int,2>E[N*N];

//bool gauss(int n){
//	for(int i = 1;i <= n;i++){
//		int r = i;
//		for(int j = i+1;j <= n;j++) if(fabs(a[j][i]) > fabs(a[r][i])) {
//			r = j;
//		}
//		if(i != r) swap(a[i], a[r]);
//		if(fabs(a[i][i] < eps)) return 0; // 无解
//		for(int r = 1;r <= n;r++) if(r != i){
//			double t = a[r][i]/a[i][i];
//			for(int j = n+1;j >= i;j--){
//				a[r][j] -= t*a[i][j];
//			}
//		}
//	}
//	for(int i = 1;i <= n;i++){
//		f[i] = a[i][n+1]/a[i][i];
//	}
//	return 1; // 存在唯一解
//}

//void solve(){
//	cin >> n >> m;
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		E[i] = {u, v};
//		mp[u][v] = mp[v][u] = 1;
//		d[u]++;
//		d[v]++;
//	}

//	a[1][n] = 1;
//	for(int i = 1;i < n;i++){
//		a[i][i] = 1;
//		for(int j = 1;j < n;j++) if(i != j && mp[i][j]) {
//			a[i][j] = -1.0/d[j];
//		}
//	}
//	gauss(n-1);

//	for(int i = 1;i <= m;i++){
//		auto [u, v] = E[i];
//		e[i] += f[u]/d[u];
//		e[i] += f[v]/d[v];
//	}

//	sort(e+1, e+1+m);
//	double ans = 0;
//	for(int i = 1, t = m;i <= m;i++, t--) ans += e[i] * t;
//	cout << fixed << setprecision(3);
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

//const double eps = 1e-6;
//const int N = 505;
//int n, m;
//struct node{
//	double w[N];
//	int c;
//	int operator<(node e){
//		return c < e.c;
//	}
//};

//int ok[N];
//node f[N];
//bool insert(node x){
//	for(int i = 1;i <= m;i++) if(fabs(x.w[i]) > eps) {
//		if(!ok[i]) {
//			ok[i] = 1;
//			f[i] = x;
//			return 1;
//		}
//		double t = x.w[i]/f[i].w[i];
//		for(int j = i;j <= m;j++) x.w[j] -= t*f[i].w[j];
//	}
//	return 0;
//}

//void solve(){
//	cin >> n >> m;
//	vector<node>a(n);
//	for(auto &e : a) for(int i = 1;i <= m;i++) cin >> e.w[i];
//	for(auto &e : a) cin >> e.c;
//	sort(all(a));

//	int sum = 0, cnt = 0;
//	for(auto e : a){
//		if(insert(e)) {
//			cnt++;
//			sum += e.c;
//		}
//	}
//	cout << cnt << ' ' << sum << endl;
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

//const int N = 5e5 + 10;
//int last, sum, tot = 1;
//string s;
//struct node{
//	int siz, len, ne[26], fail;
//	node(int _len = 0){
//		len = _len;
//		fail = siz = 0;
//		memset(ne, 0, sizeof(ne));
//	}
//}tr[N];

//void init(){
//	tr[1] = node(-1);
//	tr[0].fail = 1;
//}

//int getfa(int x, int p){
//	while(s[p-tr[x].len-1] != s[p]){
//		x = tr[x].fail;
//	}
//	return x;
//}
//void insert(int c, int p){
//	int fa = getfa(last, p);
//	int cur = tr[fa].ne[c];
//	if(!cur){
//		cur = ++tot;
//		tr[cur] = node(tr[fa].len+2);
//		tr[cur].fail = tr[getfa(tr[fa].fail, p)].ne[c];
//		tr[cur].siz = tr[tr[cur].fail].siz + 1;
//		tr[fa].ne[c] = cur;
//	}
//	sum += tr[cur].siz;
//	last = cur;
//}

//void solve(){
//	cin >> s;
//	s = ' ' + s;
//	for(int i = 1;i <  s.size();i++){
//		s[i] = ((s[i]-97+tr[last].siz) % 26) + 97;
//		insert(s[i]-'a', i);
//		cout << tr[last].siz << ' ';
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	init();
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

//const int N = 2e6 + 10;
//int ne[N][26], fail[N], tot, ed[N], cnt[N];

//int insert(string s){
//	int p = 0;
//	for(int i = 0;i < s.size();i++){
//		int c = s[i] - 'a';
//		if(!ne[p][c]) ne[p][c] = ++tot;
//		p = ne[p][c];
//	}
//	return p;
//}
//void build(){
//	queue<int>que;
//	for(int i = 0;i < 26;i++) if(ne[0][i]) que.push(ne[0][i]);
//	while(que.size()){
//		int u = que.front();
//		que.pop();
//		for(int i = 0;i < 26;i++) {
//			if(!ne[u][i]) ne[u][i] = ne[fail[u]][i];
//			else{
//				fail[ne[u][i]] = ne[fail[u]][i];
//				que.push(ne[u][i]);
//			}
//		}
//	}
//}
//void query(string s){
//	int p = 0;
//	for(int i = 0;i < s.size();i++){
//		int c = s[i] - 'a';
//		p = ne[p][c];
//		cnt[p]++;
//	}
//	vector<vector<int>>g(tot+5);
//	for(int i = 1;i <= tot;i++) g[fail[i]].push_back(i);
//	auto dfs = [&](auto self, int u) -> void {
//		for(auto v : g[u]) {
//			self(self, v);
//			cnt[u] += cnt[v];
//		}
//	};
//	dfs(dfs, 0);
//}

//void solve(){
//	int n;
//	cin >> n;
//	string s;
//	for(int i = 1;i <= n;i++){
//		cin >> s;
//		ed[i] = insert(s);
//	}
//	build();
//	cin >> s;
//	query(s);

//	for(int i = 1;i <= n;i++) cout << cnt[ed[i]] << endl;
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


//struct KMP{
//	vector<int>ne;
//	string s;
//	int m;
//	KMP() = default;
//	KMP(string _s, int _m) : ne(_m+5), s(_s), m(_m) {
//		for(int i = 2, j = 0;i <= m;i++){
//		    while(j && s[i] != s[j+1]) j = ne[j];
//		    if(s[i] == s[j+1]) j++;
//		    ne[i] = j;
//		}
//	}
//	vector<int> getpos(string a, int n){
//		vector<int>pos;
//		for(int i = 1, j = 0; i <= n; i++){
//		    while(j && a[i] != s[j+1]) j = ne[j];
//		    if(a[i] == s[j + 1]) j++;
//		    if(j == m){
//		        //匹配成功
//		        j = ne[j];
//				pos.push_back(i);
//		    }
//		}
//		return pos;
//	}
//};

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<KMP>kmp(n+5);
//	string s;
//	for(int i = 1;i <= n;i++){
//		cin >> s;
//		s = ' ' + s;
//		kmp[i] = KMP(s, s.size()-1);
//	}

//	for(int i = 1;i <= m;i++){
//		cin >> s;
//		int len = s.size();
//		s = ' ' + s;
//		vector<vector<int>>g(len+5);
//		vector<int>vis(len+5);
//		for(int j = 1;j <= n;j++){
//			auto pos = kmp[j].getpos(s, len);
//			for(auto p : pos){
//				g[p-kmp[j].m].push_back(p);
//			}
//		}
//		int mx = 0;
//		queue<int>que;
//		que.push(0);
//		vis[0] = 1;
//		while(que.size()){
//			int u = que.front();
//			que.pop();
//			mx = max(mx, u);
//			for(auto v : g[u]) if(!vis[v]) {
//				vis[v] = 1;
//				que.push(v);
//			}
//		}
//		cout << mx << endl;
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
//	int n;
//	cin >> n;
//	vector<int>a(n+5), pre(n+5);
//	unordered_map<int,int>mp;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pre[i] = pre[i-1] + a[i];
//	}

//	int ans = 0;
//	for(int i = 1;i <= n;i++){
//		for(int j = i;j <= n;j++){
//			ans += j - i + 1;
//			mp[pre[j] - pre[i-1]]++;
//		}
//	}
//	for(int i = 1;i <= n;i++){
//		for(int j = i;j <= n;j++){
//			ans -= mp[pre[j] - pre[i-1]]--;
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
//	int n, k;
//	string tmp;
//	cin >> n >> k;
//	vector<vector<int>>b(n+5, vector<int>(k+5));
//	vector<int>s(k+5);
//	cin >> tmp;
//	reverse(all(tmp));
//	for(int i = 0;i < k;i++) s[i+1] = tmp[i]-'0'; 
//	for(int i = 1;i <= n;i++){
//		cin >> tmp;
//		reverse(all(tmp));
//		for(int j = 0;j < k;j++) b[i][j+1] = tmp[j]-'0';
//	}

//	vector<array<int,2>>a(k+5);
//	for(int j = 1;j <= k;j++){
//		for(int i = 1;i <= n;i++) a[j][0] += b[i][j];
//		a[j][1] = n-a[j][0];
//		//cerr << a[j][0] << ' ' << a[j][1] << endl;
//	}

//	vector<vector<int>>f(k+5, vector<int>(n+5));
//	f[0][0] = 1;
//	for(int i = 0;i < k;i++){
//		for(int j = 0;j <= n;j++) if(f[i][j]) {
//			for(int z = 0;z < 2;z++) if((j + a[i+1][z]) % 2 == s[i+1]) {
//				f[i+1][(j + a[i+1][z]) / 2] = 1;
//			}
//		}
//	}

//	if(!f[k][0]) {
//		cout << -1 << endl;
//		return;
//	}

//	auto dfs = [&](auto self, int i, int j) -> void {
//		if(i == 0) return;
//		for(int z = 0;z < 2;z++) if(j*2+s[i]-a[i][z] >= 0 && j*2+s[i]-a[i][z] <= n && f[i-1][j*2+s[i]-a[i][z]]) {
//			cout << z;
//			self(self, i-1, j*2+s[i]-a[i][z]);
//			return;
//		}
//	};
//	dfs(dfs, k, 0);
//	cout << endl;
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
//#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


class Tree{
private:
	#define ls id << 1
	#define rs id << 1 | 1
public:
	vector<int>mn, mx, a;
	int n;
	Tree(int _n, vector<int>_a) : n(_n), a(_a), mx(_n*4+5), mn(_n*4+5) {
		build(1, 1, n);
	}
	void up(int id){
		mx[id] = max(mx[ls], mx[rs]);
		mn[id] = min(mn[ls], mn[rs]);
	}
	void build(int id, int l, int r){
		if(l == r){
			mn[id] = mx[id] = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		up(id);
	}
	void change(int id, int l, int r, int x, int v){
		if(l == r) {
			mx[id] = mn[id] = v;
			return;
		}
		int mid = l + r >> 1;
		if(x <= mid) change(ls, l, mid, x, v);
		else change(rs, mid + 1, r, x, v);
		up(id);
	}
	int getmx(int id, int l, int r, int ql, int qr){
		if(ql <= l && r <= qr) return mx[id];
		int mid = l + r >> 1;
		if(qr <= mid) return getmx(ls, l, mid, ql, qr);
		else if(ql > mid) return getmx(rs, mid + 1, r, ql, qr);
		else return max(getmx(ls, l, mid, ql, qr), getmx(rs, mid + 1, r, ql, qr));
	}
	int getmn(int id, int l, int r, int ql, int qr){
		if(ql <= l && r <= qr) return mn[id];
		int mid = l + r >> 1;
		if(qr <= mid) return getmn(ls, l, mid, ql, qr);
		else if(ql > mid) return getmn(rs, mid + 1, r, ql, qr);
		else return min(getmn(ls, l, mid, ql, qr), getmn(rs, mid + 1, r, ql, qr));
	}
	int getmx(int l, int r){ return getmx(1, 1, n, l, r); }
	int getmn(int l, int r){ return getmn(1, 1, n, l, r); }
	void change(int x, int v) { change(1, 1, n, x, v); }
};


void solve(){
	int n, q;
	cin >> n;
	vector<int>a(n+5);
	set<int>pos;
	for(int i = 1;i <= n;i++) cin >> a[i];
	Tree tr(n, a);
	a[n+1] = -1e9-1;
	for(int i = 1;i <= n;i++){
		if(a[i] > a[i+1]) pos.insert(i);
	}


	auto fun = [&]() -> void {
		int L = *pos.begin();
		if(L == n){
			cout << "-1 -1\n";
			return;
		}
		int l = 1, r = L;
		while(l <= r){
			int mid = l + r >> 1;
			int mx = a[mid];
			int mn = tr.getmn(mid+1, n);
			if(mx <= mn) l = mid + 1;
			else r = mid - 1;
		}
		L = r+1;
		int R = *next(pos.rbegin())+1;
		l = R, r = n;
		while(l <= r){
			int mid = l + r >> 1;
			int mx = tr.getmx(1, mid-1);
			int mn = a[mid];
			if(mx <= mn) r = mid - 1;
			else l = mid + 1;
		}
		R = l-1;
		cout << L << ' ' << R << endl;
	};

	fun();
	cin >> q;
	int x, v;
	while(q--){
		cin >> x >> v;

		tr.change(x, v);
		a[x] = v;
		if(a[x] <= a[x+1]) pos.erase(x);
		else pos.insert(x);
		if(x > 1){
			if(a[x-1] <= a[x]) pos.erase(x-1);
			else pos.insert(x-1);
		}

		fun();
	}
}

signed main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();

	return 0;
}