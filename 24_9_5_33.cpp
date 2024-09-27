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

//#include<bits/stdc++.h>
//using namespace std;
////#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//class Tree{
//private:
//	#define ls id << 1
//	#define rs id << 1 | 1
//public:
//	vector<int>mn, mx, a;
//	int n;
//	Tree(int _n, vector<int>_a) : n(_n), a(_a), mx(_n*4+5), mn(_n*4+5) {
//		build(1, 1, n);
//	}
//	void up(int id){
//		mx[id] = max(mx[ls], mx[rs]);
//		mn[id] = min(mn[ls], mn[rs]);
//	}
//	void build(int id, int l, int r){
//		if(l == r){
//			mn[id] = mx[id] = a[l];
//			return;
//		}
//		int mid = l + r >> 1;
//		build(ls, l, mid);
//		build(rs, mid + 1, r);
//		up(id);
//	}
//	void change(int id, int l, int r, int x, int v){
//		if(l == r) {
//			mx[id] = mn[id] = v;
//			return;
//		}
//		int mid = l + r >> 1;
//		if(x <= mid) change(ls, l, mid, x, v);
//		else change(rs, mid + 1, r, x, v);
//		up(id);
//	}
//	int getmx(int id, int l, int r, int ql, int qr){
//		if(ql <= l && r <= qr) return mx[id];
//		int mid = l + r >> 1;
//		if(qr <= mid) return getmx(ls, l, mid, ql, qr);
//		else if(ql > mid) return getmx(rs, mid + 1, r, ql, qr);
//		else return max(getmx(ls, l, mid, ql, qr), getmx(rs, mid + 1, r, ql, qr));
//	}
//	int getmn(int id, int l, int r, int ql, int qr){
//		if(ql <= l && r <= qr) return mn[id];
//		int mid = l + r >> 1;
//		if(qr <= mid) return getmn(ls, l, mid, ql, qr);
//		else if(ql > mid) return getmn(rs, mid + 1, r, ql, qr);
//		else return min(getmn(ls, l, mid, ql, qr), getmn(rs, mid + 1, r, ql, qr));
//	}
//	int getmx(int l, int r){ return getmx(1, 1, n, l, r); }
//	int getmn(int l, int r){ return getmn(1, 1, n, l, r); }
//	void change(int x, int v) { change(1, 1, n, x, v); }
//};


//void solve(){
//	int n, q;
//	cin >> n;
//	vector<int>a(n+5);
//	set<int>pos;
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	Tree tr(n, a);
//	a[n+1] = -1e9-1;
//	for(int i = 1;i <= n;i++){
//		if(a[i] > a[i+1]) pos.insert(i);
//	}


//	auto fun = [&]() -> void {
//		int L = *pos.begin();
//		if(L == n){
//			cout << "-1 -1\n";
//			return;
//		}
//		int l = 1, r = L;
//		while(l <= r){
//			int mid = l + r >> 1;
//			int mx = a[mid];
//			int mn = tr.getmn(mid+1, n);
//			if(mx <= mn) l = mid + 1;
//			else r = mid - 1;
//		}
//		L = r+1;
//		int R = *next(pos.rbegin())+1;
//		l = R, r = n;
//		while(l <= r){
//			int mid = l + r >> 1;
//			int mx = tr.getmx(1, mid-1);
//			int mn = a[mid];
//			if(mx <= mn) r = mid - 1;
//			else l = mid + 1;
//		}
//		R = l-1;
//		cout << L << ' ' << R << endl;
//	};

//	fun();
//	cin >> q;
//	int x, v;
//	while(q--){
//		cin >> x >> v;

//		tr.change(x, v);
//		a[x] = v;
//		if(a[x] <= a[x+1]) pos.erase(x);
//		else pos.insert(x);
//		if(x > 1){
//			if(a[x-1] <= a[x]) pos.erase(x-1);
//			else pos.insert(x-1);
//		}

//		fun();
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

//const int L = 0;
//const int R = 1;

//void solve(){
//	int n;
//	cin >> n;
//	vector<array<int,3>>a(n+5), evt, e;
//	for(int i = 1;i <= n;i++){
//		for(int j = 0;j < 3;j++) cin >> a[i][j];
//		auto [l, r, v] = a[i];
//		evt.push_back({l, L, i});
//		evt.push_back({r, R, i});
//	}

//	sort(all(evt));
//	set<array<int,2>>st;
//	for(auto [p, op, id] : evt) {
//		if(op == L){
//			if(st.size()){
//				auto it = st.lower_bound({a[id][2], 0});
//				if(it != st.end()) e.push_back({abs(a[id][2] - (*it)[0]), id, (*it)[1]});
//				if(it != st.begin()) {
//					it = prev(it);
//					e.push_back({abs(a[id][2] - (*it)[0]), id, (*it)[1]});
//				}
//			}
//			st.insert({a[id][2], id});
//		}else{
//			st.erase({a[id][2], id});
//		}
//	}

//	vector<int>fa(n+5);
//	iota(all(fa), 0);

//	auto find = [&](auto self, int x) -> int {
//		return fa[x] == x ? x : fa[x] = self(self, fa[x]);
//	};
//	auto merg = [&](int a, int b) -> void {
//		a = find(find, a);
//		b=  find(find, b);
//		fa[a] = b;
//	};

//	int ans = 0, cnt = 0;
//	sort(all(e));

//	//for(auto [w, u, v] : e){
//	//	cerr << w << ' ' << u << ' ' << v << endl;
//	//}

//	for(auto [w, u, v] : e) if(find(find, u) != find(find, v)) {
//		merg(u, v);
//		ans += w;
//		cnt++;
//	}
//	if(cnt != n-1) ans = -1;
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

//const int N = 55;
//char mp[N][N], mp2[N][N];
//int id[N][N], nd[N][N];
//int fa[N*N];
//int n, m;

//int op4[4][2] = {
//	-1, 0,
//	0, 1,
//	1, 0,
//	0, -1
//};

//int find(int x){
//	return x == fa[x] ? x : fa[x] = find(fa[x]);
//}
//void merg(int a, int b){
//	a = find(a);
//	b = find(b);
//	fa[a] = b;
//}

//int hefa(){
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++) if(mp[i][j] != 'X') {
//			for(int k = 0;k < 4;k++) {
//				int x = i + op4[k][0];
//				int y = j + op4[k][1];
//				if(mp[x][y] != 'X') merg(id[i][j], id[x][y]);
//			}
//		}
//	}

//	int id1, id2;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++) {
//			if(mp[i][j] == '*') id1 = id[i][j];
//			if(mp2[i][j] == '*') id2 = id[i][j];
//		}
//	}
//	if(find(id1) == find(id2)) return 1;
//	else return 0;
//}

//void init(){
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++) if(mp2[i][j] == '*') {
//			nd[i][j] = 1;
//		}
//	}
//}

//void solve(){
//	cin >> n >> m;
//	int tot = 0;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			id[i][j] = ++tot;
//			fa[tot] = tot;
//		}
//	}
//	vector<string>s(n+5), s2(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> s[i];
//		s[i] = 'X' + s[i] + 'X';
//	}
//	s[0] = s[n+1] = string(m+5, 'X');
//	for(int i = 0;i <= n+1;i++){
//		for(int j = 0;j <= m+1;j++) mp[i][j] = s[i][j];
//	}

//	for(int i = 1;i <= n;i++){
//		cin >> s2[i];
//		s2[i] = 'X' + s2[i] + 'X';
//	}
//	s2[0] = s2[n+1] = string(m+5, 'X');
//	for(int i = 0;i <= n+1;i++){
//		for(int j = 0;j <= m+1;j++) mp2[i][j] = s2[i][j];
//	}

//	if(!hefa()){
//		cout << "NO\n";
//		return;
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

//const int N = 4e5 + 10;
//int Log[N];
//struct ST{
//	vector<array<int,20>>f;
//	ST(int n, vector<int>a) : f(n+5) {
//		for(int i = 1;i <= n;i++) f[i][0] = a[i];
//		for(int j = 1;j < 20;j++){
//			for(int i = 1;i <= n && i+(1<<j)-1 <= n;i++){
//				f[i][j] = f[i][j-1] & f[i+(1<<(j-1))][j-1];
//			}
//		}
//	}
//	int query(int l, int r){
//		int s = Log[r-l+1];
//		return (f[l][s] & f[r-(1<<s)+1][s]);
//	}
//};

//void solve(){
//	int n, x, ad = (1ll << 20) - 1, mx = 0;
//	cin >> n >> x;
//	vector<int>a(n+5), bit(20);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		mx = max(mx, a[i]);
//		ad &= a[i];
//		for(int j = 0;j < 20;j++) {
//			bit[j] += (((a[i] >> j) & 1)^1);
//		}
//	}
//	(1<<19);
//	ST st(n, a);

//	map<int,int>mp, bd;
//	for(int i = 1;i <= n;i++) {
//		mp[a[i]]++;
//		for(int j = 0;j < 20;j++) if(((a[i] >> j) & 1) ^ 1) {
//			if(bit[j] <= 2) {
//				bd[a[i]] = 1;
//				break;
//			}
//		}
//	}

//	for(int i = ad + x + 1;i <= mx;i++){
//		vector<int>num;
//		for(int j = i;j <= mx;j += i) if(mp.count(j) && !bd[j]) {
//			while(mp[j] && num.size() < 2){
//				num.push_back(j);
//				mp[j]--;
//			}
//		}
//		if(num.size() == 2){
//			int gc = gcd(num[0], num[1]), w = (1<<20)-1;
//			cout << "YES\n";
//			cout << "2 " << num[0] << ' ' << num[1] << endl;
//			cout << n-2 << ' ';
//			for(auto [v, cnt] : mp){
//				if(cnt > 0) w &= v;
//				while(cnt--) cout << v << ' ';
//			}
//			assert(gc > w+x);
//			cout << endl;
//			return;
//		}
//		for(auto e : num) mp[e]++;
//	}


//	for(int i = 1;i <= n;i++) if(bd[a[i]]) {
//		for(int j = 1;j <= n;j++) if(i != j) {
//			int gc = gcd(a[i], a[j]);
//			int l = min(i, j), r = max(i, j);
//			int w = (1<<20)-1;
//			//for(int k = 1;k <= n;k++) if(k != i && k != j) w &= a[k];
//			if(l > 1) w &= st.query(1, l-1);
//			if(l+1 != r) w &= st.query(l+1, r-1);
//			if(r < n) w &= st.query(r+1, n);
//			w += x;
//			if(gc > w){
//				int gc = gcd(a[i], a[j]);
//				cout << "YES\n";
//				cout << "2 " << a[i] << ' ' << a[j] << endl;
//				cout << n-2 << ' ';
//				int w = (1<<20)-1;
//				for(int k = 1;k <= n;k++) if(k != i && k != j) w &= a[k];
//				assert(gc > w+x);
//				for(int k = 1;k <= n;k++) if(k != i && k != j) cout << a[k] << ' ';
//				cout << endl;
//				return;
//			}
//		}
//	}
//	cout << "NO\n";
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	for(int i = 2;i < N;i++) Log[i] = Log[i/2] + 1;
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

//const int N = 10010;
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

//int fac[N], inv[N];
//void init(){
//	fac[0] = inv[0] = 1;
//	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//	inv[N-1] = qpow(fac[N-1], mod-2);
//	for(int i = N-2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
//}
//int C(int a, int b){
//	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
//}

////int nd[N], cnt[N];
//vector<int>nd(N,0), cnt(N,0);

//void solve(){
//	int n;
//	cin >> n;
//	for(int i = 0;i <= n*2;i++) nd[i] = 0;
//	//vector<int>nd(n*2+10);
//	vector<int>p(n+5);
//	nd[0 + n]++;
//	for(int i = 1;i <= n;i++){
//		cin >> p[i];
//		assert(p[i] + n >= 0 && p[i] + n < N);
//		nd[p[i] + n]++;
//	}

//	int ans = 0;
//	for(int s = p[1];s <= p[n];s++){
//		for(int i = 0;i <= n*2;i++) cnt[i] = 0;
//		//vector<int>cnt(n*2+10);
//		int cur = 0, len = 0;
//		cnt[cur+n]++;
//		while(cur < p[n]){
//			assert(cur+1+n >= 0 && cur+1+n < N);
//			cnt[(++cur) + n]++, len++;
//		}
//		while(cur > s){
//			assert(cur-1+n >= 0 && cur-1+n < N);
//			cnt[(--cur) + n]++, len++;
//		}

//		int tmp = 1;
//		for(int i = p[n];i >= p[1];i--){
//			assert(i+n >= 0 && i+n < N);
//			if(cnt[i + n] && cnt[i + n] < nd[i + n]) {
//				int d = nd[i + n] - cnt[i + n];
//				(tmp *= C(d + cnt[i + n] - 1, d)) %= mod;
//				len += 2 * d;
//				cnt[i + n] += d;
//				cnt[i-1 + n] += d;
//			}
//		}

//		int ok = (len == n);
//		for(int i = 0;i < n*2;i++) if(cnt[i] != nd[i]) {
//			ok = 0;
//			break;
//		}
//		//cerr << s << ' ' << ok << endl;
//		if(!ok) continue;
//		(ans += tmp) %= mod;
//	}
//	//cerr << ans << endl;
//	cout << ans << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	for(int i = 0;i < N;i++) nd[i] = cnt[i] = 0;
//	init();
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) {
//		//cerr << i << endl;
//		solve();
//	}

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
//	string a, b;
//	cin >> a >> b;
//	a = ' ' + a;
//	b = ' ' + b;
//	vector<int>pa(n+5), pb(n+5);
//	int ca = 0, cb = 0;
//	for(int i = 1;i <= n;i++){
//		pa[i] = pa[i-1] ^ (a[i]-'0');
//		pb[i] = pb[i-1] ^ (b[i]-'0');
//		ca += pa[i];
//		cb += pb[i];
//	}

//	if(ca == cb || (n-ca+1) == cb) cout << "YES\n";
//	else cout << "NO\n";
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) {
//		solve();
//	}

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//struct Tree{
//	#define ls id << 1
//	#define rs id << 1 | 1
//	vector<int>sum, tag, a, len;
//	int n;
//	Tree(int _n, vector<int>_a) : a(_a), n(_n), len(_n*4+5), sum(_n*4+5), tag(_n*4+5) {
//		build(1, 1, n);
//	}

//	void up(int id) {
//		sum[id] = sum[ls] + sum[rs];
//	}
//	void build(int id, int l, int r) {
//		if(l == r){
//			sum[id] = a[l];
//			len[id] = 1;
//			return;
//		}
//		int mid = l + r >> 1;
//		build(ls, l, mid);
//		build(rs, mid + 1, r);
//		len[id] = len[ls] + len[rs];
//		up(id);
//	}
//	void settag(int id, int x){
//		tag[id] = x;
//		sum[id] = x * len[id];
//	}
//	void down(int id){
//		settag(ls, tag[id]);
//		settag(rs, tag[id]);
//		tag[id] = 0;
//	}
//	void modify(int id, int l, int r, int ql, int qr, int v){
//		if(ql <= l && r <= qr) {
//			settag(id, v);
//			return;
//		}
//		if(tag[id]) down(id);
//		int mid = l + r >> 1;
//		if(qr <= mid) modify(ls, l, mid, ql, qr, v);
//		else if(ql > mid) modify(rs, mid + 1, r, ql, qr, v);
//		else modify(ls, l, mid, ql, qr, v), modify(rs, mid + 1, r, ql, qr, v);
//		up(id);
//	}
//	int getsum(int id, int l, int r, int ql, int qr){
//		if(ql <= l && r <= qr) return sum[id];
//		if(tag[id]) down(id);
//		int mid = l + r >> 1;
//		if(qr <= mid) return getsum(ls, l, mid, ql, qr);
//		else if(ql > mid) return getsum(rs, mid + 1, r, ql, qr);
//		else return getsum(ls, l, mid, ql, qr) + getsum(rs, mid + 1, r, ql, qr);
//	}
//	int getsum(int l, int r){
//		if(r < 1) return 0;
//		return getsum(1, 1, n, l, r);
//	}
//};

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	Tree tr(n, a);

//	for(int i = 2;i <= n;i++) if(a[i] < tr.getsum(i-1, i-1)) {
//		int l = 1, r = i-1;
//		while(l <= r){
//			int mid = l + r >> 1;
//			if(tr.getsum(mid, mid) > a[i]) r = mid - 1;
//			else l = mid + 1;
//		}
//		r = i-1;
//		while(l <= r){
//			int mid = l + r >> 1;
//			int m = i-mid+1, s = tr.getsum(mid, i), ps = tr.getsum(mid-1, mid-1);
//			s = s / m;
//			if(s >= ps) l = mid + 1;
//			else r = mid - 1;
//		}		
//		int mid = r;
//		int m = i-mid+1, s = tr.getsum(mid, i);
//		int av = s/m;
//		tr.modify(1, 1, n, mid, i, av);
//		if(s % m){
//			s %= m;
//			mid = i-s+1;
//			tr.modify(1, 1, n, mid, i, av+1);
//		}
//	}

//	cout << tr.getsum(n,n) - tr.getsum(1,1) << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) {
//		solve();
//	}

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//int lowbit(int x){
//	return x & -x;
//}

//struct BIT{
//	vector<int>tr;
//	int n;
//	BIT(int _n) : n(_n), tr(_n+5) {}
//	void add(int x){
//		while(x <= n){
//			tr[x]++;
//			x += lowbit(x);
//		}
//	}
//	int getsum(int x){
//		int ret = 0;
//		while(x){
//			ret += tr[x];
//			x -= lowbit(x);
//		}
//		return ret;
//	}
//	int query(int l, int r){
//		if(l > r) return 0;
//		return getsum(r) - getsum(l-1);
//	}
//};

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];

//	if(is_sorted(a.begin()+1, a.begin()+1+n)){
//		cout << n-2 << endl;
//		return;
//	}

//	BIT pt(n), st(n);
//	map<array<int,2>, int>mp;
//	vector<int>pre(n+5, -1), suf(n+5, -1);
//	int ans = 0;
//	for(int i = 1;i <= n;i++){
//		int tmp = (i-1) - pt.getsum(i-1);
//		if(tmp == 0){
//			pre[i] = 0;
//		}else if(tmp == 1){
//			int l = 1, r = i-1;
//			while(l <= r){
//				int mid = l + r >> 1;
//				if(pt.getsum(mid) == mid) l = mid + 1;
//				else r = mid - 1;
//			}
//			pre[i] = r+1;
//		}else{
//			pre[i] = -1;
//		}
//		pt.add(a[i]);
//		//cerr << pre[i] << ' ';
//	}
//	//cerr << endl;
//	for(int i = n;i >= 1;i--){
//		int tmp = (n-i) - st.query(i+1, n);
//		if(tmp == 0){
//			suf[i] = 0;
//		}else if(tmp == 1){
//			int l = i+1, r = n;
//			while(l <= r){
//				int mid = l + r >> 1;
//				if(st.query(mid, n) == n-mid+1) r = mid - 1;
//				else l = mid + 1;
//			}
//			suf[i] = l-1;
//		}else{
//			suf[i] = -1;
//		}
//		st.add(a[i]);
//		//cerr << suf[i] << ' ';
//	}
//	//cerr << endl;

//	for(int i = 1;i <= n;i++) if(pre[i] != -1 && suf[i] != -1) {
//		if(pre[i] == 0 && suf[i] == 0){
//			ans++;
//			continue;
//		}
//		if(pre[i] == 0){
//			mp[{i, suf[i]}]++;
//			continue;
//		}
//		if(suf[i] == 0){
//			mp[{pre[i], i}]++;
//			continue;
//		}
//		if(i == a[i] && pre[i] != -1 && suf[i] != -1){
//			mp[{pre[i], suf[i]}]++;
//			continue;
//		}
//	}

//	int mx = 0;
//	for(auto [k, v] : mp){
//		//cerr << k[0] << ' ' << k[1] << " : " << v << endl;
//		mx = max(mx, v);
//	}
//	cout << ans+mx << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) {
//		solve();
//	}

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 1e15;
//int op[4][2] = {
//	-1, 0,
//	1, 0,
//	0, -1,
//	0, 1
//};

//void solve(){
//	int n, m, tot = 0, sx, sy, sum = 0;
//	cin >> n >> m;
//	vector<string>s(n+5);
//	vector id(n+5, vector<int>(m+5)), g(n*m+5, vector<int>(0));
//	vector<int>ex(n*m+5);
//	for(int i = 1;i <= n;i++) {
//		cin >> s[i];
//		s[i] = '#' + s[i] + '#';
//		for(int j = 1;j <= m;j++){
//			sum += (s[i][j] != '#');
//			if(s[i][j] == 'V') sx = i, sy = j;
//			id[i][j] = ++tot;
//			if(s[i][j] != '#' && (min(i, j) == 1 || i == n || j == m)) ex[tot] = 1;
//		}
//		//cerr << sum << endl;
//		//cerr << s[i] << endl;
//	}
//	s[0] = s[n+1] = string(m+5, '#');

//	for(int i = 1;i <= n;i++) {
//		for(int j = 1;j <= m;j++) if(s[i][j] != '#') {
//			for(int k = 0;k < 4;k++){
//				int x = i + op[k][0], y = j + op[k][1];
//				if(s[x][y] == '#') continue;
//				g[id[i][j]].push_back(id[x][y]);
//			}
//		}
//	}

//	vector<int>dis(tot+5, inf);
//	queue<int>que;
//	vector<int>vec;
//	dis[id[sx][sy]] = 1;
//	que.push(id[sx][sy]);
//	while(que.size()){
//		int u = que.front();
//		if(ex[u]) vec.push_back(u);
//		que.pop();
//		for(auto v : g[u]) if(dis[u] + 1 < dis[v]) {
//			dis[v] = dis[u] + 1;
//			que.push(v);
//		}
//	}

//	if(vec.empty()){
//		cout << sum-1 << endl;
//		return;
//	}
//	if(vec.size() == 1){
//		cout << sum - dis[vec[0]] << endl;
//		return;
//	}

//	vector<array<int,2>>dis2(tot+5, {inf,inf});
//	vector<int>cnt(tot+5), las(tot+5);
//	queue<array<int,3>>q;
//	for(auto v : vec){
//		dis2[v][cnt[v]] = 1;
//		las[v] = v;
//		q.push({v, dis2[v][cnt[v]++], las[v]});
//	}
//	while(q.size()){
//		auto [u, d, r] = q.front();
//		q.pop();
//		for(auto v : g[u]) if(cnt[v] <= 1 && las[v] != r && d+1 < dis2[v][cnt[v]]) {
//			dis2[v][cnt[v]] = d+1;
//			las[v] = r;
//			q.push({v, dis2[v][cnt[v]++], las[v]});
//		}
//	}

//	int mn = inf;
//	for(int i = 1;i <= tot;i++){
//		mn = min(mn, dis[i] + dis2[i][0] + dis2[i][1] - 2);
//	}
//	cout << sum-mn << endl;
//	//cerr << sum << ' ' << mn << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) {
//		solve();
//	}

//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//int bcnt(int x){
//	int ret = 0;
//	while(x){
//		ret += (x & 1);
//		x >>= 1;
//	}
//	return ret;
//}
//int bit(int x, int p){
//	return ((x>>p)&1);
//}

//void solve(){
//	vector<int>val(20);
//	vector<array<int,3>>g;
//	for(int i = 0;i < 19;i++) cin >> val[i];
//	g.push_back({1, 0, 2});
//	g.push_back({3, 0, 7});
//	g.push_back({4, 0, 9});
//	g.push_back({4, 1, 8});
//	g.push_back({4, 5, 3});
//	g.push_back({5, 1, 10});
//	g.push_back({5, 2, 9});
//	g.push_back({5, 6, 4});
//	g.push_back({6, 2, 11});
//	g.push_back({8, 3, 13});
//	g.push_back({8, 4, 12});
//	g.push_back({8, 9, 7});
//	g.push_back({9, 4, 14});
//	g.push_back({9, 5, 13});
//	g.push_back({9, 10, 8});
//	g.push_back({10, 5, 15});
//	g.push_back({10, 6, 14});
//	g.push_back({10, 11, 9});
//	g.push_back({12, 7, 16});
//	g.push_back({13, 8, 17});
//	g.push_back({13, 9, 16});
//	g.push_back({13, 14, 12});
//	g.push_back({14, 9, 18});
//	g.push_back({14, 10, 17});
//	g.push_back({14, 15, 13});
//	g.push_back({15, 11, 18});
//	g.push_back({17, 18, 16});

//	vector<int>f(1<<19, -1);
//	f[0] = 0;
//	auto dfs = [&](auto self, int u) -> int {
//		if(f[u] != -1) return f[u];
//		for(int j = 0;j < 19;j++) if(bit(u, j)) f[u] = max(f[u], self(self, u - (1<<j)));
//		for(auto [p, l, r] : g) if(bit(u, p)) {
//			if(bit(u, l) && !bit(u, r)) f[u] = max(f[u], self(self, (u - (1<<p) - (1<<l)) + (1<<r)) + val[p]);
//			if(bit(u, r) && !bit(u, l)) f[u] = max(f[u], self(self, (u - (1<<p) - (1<<r)) + (1<<l)) + val[p]);
//		}
//		return f[u];
//	};

//	int n;
//	cin >> n;
//	while(n--){
//		char c;
//		int s = 0;
//		for(int i = 0;i < 19;i++){
//			cin >> c;
//			if(c == '#') s += (1<<i);
//		}
//		cout << dfs(dfs, s) << endl;
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) {
//		solve();
//	}

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5), pr(n+5);
//	vector g(n+5, vector<int>());
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1, x, y;i <= k;i++){
//		cin >> x >> y;
//		pr[y] = 1;
//		g[x].push_back(y);
//	}

//	vector<int>st(n+5), ed(n+5), scc(n+5), dep(n+5);
//	int tot = 0, cyc = 0;
//	auto dfs = [&](auto self, int u) -> void {
//		scc[u] = tot;
//		ed[tot] = u;
//		for(auto v : g[u]){
//			if(scc[v]){
//				cyc = 1;
//				return;
//			}
//			dep[v] = dep[u] + 1;
//			self(self, v);
//		}
//	};
//	for(int i = 1;i <= n;i++) if(!scc[i] && !pr[i]) {
//		tot++;
//		st[tot] = i;
//		dfs(dfs, i);
//		if(cyc){
//			cout << "0\n";
//			return;
//		}
//	}
//	for(int i = 1;i <= n;i++) if(!scc[i]) {
//		cout << "0\n";
//		return;
//	}

//	int rt;
//	for(int i = 1;i <= n;i++)
//		if(a[i]){
//			if(scc[a[i]] == scc[i]){
//				if(dep[i] <= dep[a[i]]){
//					cout << "0\n";
//					return;
//				}
//			}else g[ed[scc[a[i]]]].push_back(st[scc[i]]);
//		}
//		else rt = i;
//	vector<int>deg(n+5), vis(n+5);
//	for(int i = 1;i <= n;i++) {
//		sort(all(g[i]));
//		g[i].erase(unique(all(g[i])), g[i].end());
//		//cerr << "g[" << i << "] : ";
//		for(auto v : g[i]){
//			deg[v]++;
//			//cerr << v << ' ';
//		}
//		//cerr << endl;
//	}
//	//cerr << "DEDE\n";
	
//	vector<int>ans;
//	auto dfs2 = [&](auto self, int u) -> void {
//		vis[u] = 1;
//		ans.push_back(u);
//		for(auto v : g[u]) if(--deg[v] == 0) {
//			if(vis[v]){
//				cyc = 1;
//				return;
//			}
//			self(self, v);
//		}
//	};
//	dfs2(dfs2, rt);
//	if(cyc || ans.size() != n){
//		cout << "0\n";
//		return;
//	}
//	for(auto e : ans) cout << e << ' ';
//	cout << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) {
//		solve();
//	}

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//using i128 = __int128_t;

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5), b(k+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= k;i++) cin >> b[i];
//	sort(a.begin()+1, a.begin()+1+n);

//	auto check = [&](int x) -> int {
//		vector<i128>c(n+5), b2(k+5);
//		for(int i = 1;i <= k;i++) b2[i] = b[i];
//		for(int i = 1;i <= n;i++) {
//			c[i] = a[i];
//			c[i] *= x;
//		}

//		for(int i = k;i >= 1 && c[n] > 0;i--){
//			for(int j = n;j >= 1;j--){
//				i128 tmp = c[j] / (1<<(i-1));
//				tmp = min(tmp, b2[i]);
//				c[j] -= tmp * (1<<(i-1));
//				b2[i] -= tmp;
//			}
//			sort(c.begin()+1, c.begin()+1+n);
//			if(b2[i]){
//				for(int j = n;j >= 1 && b2[i] > 0;j--) {
//					c[j] = 0;
//					b2[i]--;
//				}
//				sort(c.begin()+1, c.begin()+1+n);
//			}
//		}
//		return c[n] <= 0;
//	};

//	int l = 0, r = 1e16;
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
//	for(int i = 1;i <= t;i++) {
//		solve();
//	}

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//using i128 = __int128_t;

//const int inf = 1e12;

//array<int,2> fun(int k, int x){
//	int s = k*(k+1)/2;
//	if(s > x) return {1, 0};
//	int l = 1, r = k;
//	int tmp = (x - s) / k;
//	s += tmp * k;
//	l += tmp, r += tmp;
//	if(s < x) r++;
//	return {l, r};
//}
//string tos(i128 x){
//	string s;
//	if(x == 0) s = "0";
//	while(x){
//		s.push_back('0' + x % 10);
//		x /= 10;
//	}
//	reverse(all(s));
//	return s;
//}

//void solve(){
//	int n, bd = 0;
//	cin >> n;
//	vector<array<int,2>>a1, a2;
//	for(int i = 1, t, k, x;i <= n;i++){
//		cin >> t >> k >> x;
//		auto p = fun(k, x);
//		if(p[0] <= p[1]){ 
//			if(t == 1) a1.push_back(p);
//			else a2.push_back(p);
//		}else{
//			if(t == 1) bd = 1;
//		}
//	}
//	if(bd){
//		cout << 0 << endl;
//		return;
//	}

//	int L = inf, R = -inf;
//	for(auto [l, r] : a1){
//		L = min(L, l);
//		R = max(R, r);
//	}

//	int rr = inf, ll = 0;
//	vector<array<int,2>>e;
//	for(auto [l, r] : a2){
//		if(L <= l && r <= R) {
//			bd = 1;
//			continue;
//		}
//		if(l < L && r > R){
//			continue;
//		}
//		if(r > R) rr = min(rr, r);
//		if(l < L) ll = max(ll, l);
//	}
//	if(bd){
//		cout << 0 << endl;
//		return;
//	}
//	if(rr == inf){
//		cout << -1 << endl;
//		return;
//	}

//	for(auto [l, r] : a2) if(l < L && r > R && l > ll && r < rr) e.push_back({l, r});
//	e.push_back({ll, rr});
//	sort(all(e), [&](array<int,2>a, array<int,2>b) -> int {
//		if(a[0] == b[0]) return a[1] < b[1];
//		return a[0] > b[0];
//	});

//	int ans = 0;
//	int las = L;
//	for(auto [l, r] : e){
//		ans += (rr - R) * (las - l);
//		las = l;
//		rr = min(rr, r);
//	}
//	cout << ans << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) {
//		solve();
//	}

//	return 0;
//}



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin()+1, (x).end()+1+n

void solve(){
	int n, k, mx = 0, s = 0;
	cin >> n >> k;
	vector<int>a(n+5);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s += a[i];
		mx = max(mx, a[i]);
	}
	if(s % mx == 0 || k >= (mx - (s % mx))){
		cout << min(n, (s + k) / mx) << endl;
		return;
	}
	for(int i = s/mx;i >= 1;i--){
		int nd = i - (s % i);
		if(k >= nd){
			cout << i << endl;
			return;
		}
	}
	cout << 1 << endl;
}

signed main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	for(int i = 1;i <= t;i++) {
		solve();
	}

	return 0;
}