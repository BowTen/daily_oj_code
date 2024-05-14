//#include<bits/stdc++.h>
//using namespace std;
////#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int N = 22;
//vector<int>a[N];

//int sum(int n, int b){
//	vector<int>cnt(n+1);
//	for(int i = 0;i < n;i++) if((1<<i)&b){
//		int x = i+1;
//		while(x <= n){
//			cnt[x] ^= 1;
//			x += i+1;
//		}
//	}
//	int ret = 0;
//	for(int i = 1;i <= n;i++) ret += cnt[i];
//	return ret;
//}

//void pt(int x){
//	vector<int>ans;
//	for(int i = 1;x;i++, x>>=1){
//		if(x & 1) ans.push_back(i);
//	}
//	cout << ans.size() << endl;
//	for(auto e : ans) cout << e << ' ';
//	cout << endl;
//}

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//	}
//	if(n >= 20){
//		cout << n << endl;
//		for(int i = 1;i <= n;i++){
//			cout << i << ' ';
//		}
//		cout << endl;
//		return;
//	}
//	if(n < 5){
//		cout << -1 << endl;
//		return;
//	}

//	auto check = [&](int b) -> int {
//		for(int i = 1;i <= n;i++) if((1<<(i-1))&b) {
//			for(auto v : g[i]) {
//				if(((1<<(v-1)&b)) == 0) return 0;
//			}
//		}
//		return 1;
//	};

//	for(auto e : a[n]) if(check(e)){
//		pt(e);
//		return;
//	}
//	cout << -1 << endl;
//}

//signed main(){

//	IO;

//	for(int i = 5;i <= 19;i++){
//		int k = i/5;
//		for(int b = 1;b < (1<<i);b++){
//			if(sum(i, b) <= k) a[i].push_back(b);
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
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 0x3f3f3f3f3f3f3f3f;

//class Tree{
//public:
//	vector<int>mn;
//	Tree(int n) : mn(n*4+5, inf) {}

//	#define ls id << 1
//	#define rs id << 1 | 1

//	void up(int id){
//		mn[id] = min(mn[ls], mn[rs]);
//	}
//	void change(int id, int l, int r, int x, int v){
//		if(l == r){
//			mn[id] = v;
//			return;
//		}
//		int mid = l + r >> 1;
//		if(x <= mid) change(ls, l, mid, x, v);
//		else change(rs, mid + 1, r, x, v);
//		up(id);
//	}
//	int query(int id, int l, int r, int ql, int qr){
//		//if(ql > qr) return 0;
//		if(ql <= l && r <= qr) return mn[id];
//		int mid = l + r >> 1;
//		if(qr <= mid) return query(ls, l, mid, ql, qr);
//		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//		else return min(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//	}
//};


//void solve(){
//	int n, q;
//	cin >> n;
//	vector<int>a(n+5);
//	vector<vector<array<int,2>>>pre(n+5);
//	vector<vector<int>>qid(n+5);
//	vector<vector<int>>qid2(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pre[i].push_back({0, 0});
//	}

//	cin >> q;
//	Tree tr(q);
//	vector<array<int,3>>qur(q+5);
//	for(int i = 1; i <= q;i++){
//		cin >> qur[i][0] >> qur[i][1] >> qur[i][2];
//		if(qur[i][2] == 0) continue;
//		if(qur[i][2] > 0){
//			tr.change(1, 1, q, i, qur[i][0]);
//			qid2[qur[i][0]].push_back(i);
//		}else{
//			qid[qur[i][0]].push_back(i);
//		}
//		pre[qur[i][0]].push_back({i, qur[i][2]});
//	}

//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j < pre[i].size();j++){
//			pre[i][j][1] += pre[i][j-1][1];
//		}
//	}

//	int s = 0, zid = 0;
//	set<int>st;

//	auto check = [&](int i, int id) -> int {
//		array<int,2>r = {id, -inf};
//		array<int,2>l = {s+1, -inf};
//		int ps = (*lower_bound(all(pre[i]), r))[1] - (*prev(lower_bound(all(pre[i]), l)))[1];
//		if(ps > 0){
//			return 0;
//		}

//		int zid = s;
//		auto it = st.lower_bound(id);
//		if(it != st.begin()){
//			it = prev(it);
//			zid = *it;
//		}else{
//			zid = s;
//		}
//		if(zid+1 > id) zid = s;

//		int mn = tr.query(1, 1, q, zid+1, id);
//		if(mn < i) return 0;
//		if(ps == 0) {
//			//int rid = lower_bound(all(qid2[i]), zid) - qid2[i].begin();
//			//for(int j = rid;j < qid2[i].size() && qid2[i][j] < id;j++){
//			//	tr.change(1, 1, q, qid2[i][j], inf);
//			//}
//			//zid = max(zid, id);
//			//for(auto e : qid2[i]){
//			//	if(e > id) break;
//			//	tr.change(1, 1, q, e, inf);
//			//}
//			st.insert(id);
//			return 0;
//		}
//		return 1;
//	};


//	for(int i = 1;i <= n;i++){
//		for(auto id : qid[i]) if(id > s){
//			if(check(i, id)){
//				zid = s = id;
//				st.insert(s);
//			}
//		}
//	}

//	vector<int>spre(n+5);
//	for(int i = 1;i <= s;i++) {
//		auto [l, r, v] = qur[i];
//		spre[l] += v;
//		spre[r+1] -= v;
//	}

//	for(int i = 1;i <= n;i++){
//		spre[i] += spre[i-1];
//		a[i] += spre[i];
//		cout << a[i] << ' ';
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

//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int n, q;

//	cin >> n;
//	vector<int>a(n+5);
//	vector<vector<int>>qid(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
	
//	cin >> q;
//	vector<array<int,3>>qur(q+5);
//	for(int i = 1;i <= q;i++) {
//		cin >> qur[i][0] >> qur[i][1] >> qur[i][2];
//		if(qur[i][2] == 0) continue;
//		qid[qur[i][0]].push_back(i);
//	}

//	vector<array<int,3>>vec;
//	vec.push_back({0, 1, q});
//	for(int i = 1;i <= n;i++){
//		vector<array<int,3>>tmp;
//		for(auto [v, L, R] : vec){
//			//cerr << i << ' ' << v << ' ' << L << ' ' << R << endl;
//			int cur = 0, mn = 0, r = R;
//			int j = lower_bound(all(qid[i]), L) - qid[i].begin();
//			for(j;j < qid[i].size() && qid[i][j] <= R;j++){
//				int id = qid[i][j];
//				cur += qur[id][2];
//				if(cur < mn){
//					mn = cur;
//					L = id;
//					r = R;
//				}else if(cur == mn){
//					//tmp.push_back({mn, L, r});
//					L = id;
//					r = R;
//				}else{
//					r = min(r, id-1);
//				}
//			}
//			//cerr << mn << ' ' << L << ' ' << r << endl;
//			tmp.push_back({mn, L, r});
//		}
//		int mn = tmp[0][0];
//		for(auto [v, l, r] : tmp) mn = min(mn, v);
//		vec.clear();
//		for(auto [v, l, r] : tmp) if(v == mn){
//			vec.push_back({v, l, r});
//		}
//	}

//	int R = vec[0][2];
//	vector<int>pre(n+5);
//	for(int i = 1;i <= R;i++) {
//		auto [l, r, w] = qur[i];
//		pre[l] += w;
//		pre[r+1] -= w;
//	}
//	for(int i = 1;i <= n;i++){
//		pre[i] += pre[i-1];
//		a[i] += pre[i];
//		cout << a[i] << ' ';
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

//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int n, q;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	cin >> q;
//	vector<array<int,3>>qur(q+5);

//	int R = 0;
//	map<int,int>mp;
//	for(int i = 1;i <= q;i++) {
//		cin >> qur[i][0] >> qur[i][1] >> qur[i][2];
//		auto [l, r, w] = qur[i];
//		mp[l] += w;
//		if(mp[l] == 0) mp.erase(l);
//		mp[r+1] -= w;
//		if(mp[r+1] == 0) mp.erase(r+1);
//		if(mp.size() && mp.begin()->second < 0){
//			R = i;
//			mp.clear();
//		}
//	}

//	vector<int>pre(n+5);
//	for(int i = 1;i <= R;i++){
//		auto [l, r, w] = qur[i];
//		pre[l] += w;
//		pre[r+1] -= w;
//	}
//	for(int i = 1;i <= n;i++){
//		pre[i] += pre[i-1];
//		a[i] += pre[i];
//		cout << a[i] << ' ';
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
////#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int N = 110;
//vector<int>g[N];
//int n, m;
//int c[N], dep[N], fg[N];

//int df[2];
//void dfs(int u, int fa){
//	dep[u] = dep[fa] + 1;
//	if(g[u].size() == 1) df[dep[u]&1] = 1;
//	for(auto v : g[u]) dfs(v, u);
//}	

//void dfs2(int u){
//	for(auto v : g[u]){
//		c[v] = (c[u] % 3) + 1;
//		dfs2(v);
//	}
//}

//void dfs3(int u){
//	for(auto v : g[u]){
//		c[v] = (c[u] % 2) + 1;
//		dfs3(v);
//	}
//}

//void solve(){
//	cin >> n;
//	for(int i = 2;i <= n;i++){
//		int fa;
//		cin >> fa;
//		g[fa].push_back(i);
//	}

//	int f = 0;
//	for(auto v : g[1]){
//		df[0] = df[1] = 0;
//		dfs(v, 1);
//		if(df[0] && df[1]) {
//			f = 1;
//			break;
//		}
//		if(df[1]) fg[v] = 1;
//	}

//	int k = 0;
//	if(f){
//		c[1] = 1;
//		dfs2(1);
//		k = 3;
//	}else{
//		for(auto v : g[1]){
//			if(fg[v]) c[v] = 2;
//			else c[v] = 1;
//			dfs3(v);
//		}
//		for(int i = 2;i <= n;i++) k = max(k, c[i]);
//	}

//	cout << k << endl;
//	for(int i = 2;i <= n;i++) cout << c[i] << ' ';
//	cout << endl;

//	int ret;
//	while(1){
//		cin >> ret;
//		if(ret) return;
//		vector<int>cnt(k+1);
//		int sum = 0;
//		for(int i = 1;i <= k;i++){
//			cin >> cnt[i];
//			sum += cnt[i];
//		}
//		if(k == 1){
//			cout << 1 << endl;
//			continue;
//		}
//		if(sum > 2 || sum == 1){
//			for(int i = 1;i <= k;i++) if(cnt[i] == 1){
//				cout << i << endl;
//				break;
//			}
//		}else{
//			if(k==3){
//				if(cnt[1] && cnt[2]){
//					cout << 1 << endl;
//				}else if(cnt[2] && cnt[3]){
//					cout << 2 << endl;
//				}else{
//					cout << 3 << endl;
//				}
//			}else{
//				cout << 2 << endl;
//			}
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 4e5 + 10;
//vector<int>g[N];
//int f[N], mxf = 390625, vis[N];

//int toi(vector<int>v){
//	int ret = 0, pw = 1;
//	for(int i = 0;i < 8;i++){
//		ret += pw * v[i];
//		pw *= 5;
//	}
//	return ret;
//}

//struct num5{
//	vector<int>v;
//	num5(int x) : v(8) {
//		for(int i = 0; i < 8;i++){
//			v[i] = x % 5;
//			x /= 5;
//		}
//	}
//	int ok(){
//		for(int i = 0;i < 8;i++) if(v[i] != 4){
//			if((i>>1) != v[i]) return 0;
//		}
//		return 1;
//	}
//	int op(int x){
//		vector<int>r(v);
//		vector<array<int,2>>q;
//		if(x == 1){
//			q.push_back({4,0});
//			q.push_back({5,1});
//		}else if(x == 2){
//			q.push_back({2,6});
//			q.push_back({3,7});
//		}else if(x == 3){
//			q.push_back({4,6});
//			q.push_back({5,7});
//		}else{
//			q.push_back({1,3});
//			q.push_back({5,7});
//		}
//		for(auto [a, b] : q){
//			if(x >= 3){
//				swap(r[a], r[b]);
//				continue;
//			}
//			if(r[a] != 4){
//				if(r[b] == 4 || r[b] == r[a]){
//					r[b] = r[a];
//					r[a] = 4;
//				}else return -1;
//			}
//		}
//		return toi(r);
//	}
//};

//void solve(){
//	int a, b, c, d, m;
//	cin >> a >> b >> c >> d >> m;
//	vector<int>v(8,4);
//	for(int i = 0; i <= 30;i++) {
//		int ai = ((a>>i)&1);
//		int bi = ((b>>i)&1);
//		int mi = ((m>>i)&1);
//		int ci = ((c>>i)&1);
//		int di = ((d>>i)&1);
//		int bit = (ai<<2) + (bi<<1) + mi;
//		int val = (ci<<1) + di;
//		if(v[bit] == 4 || v[bit] == val) v[bit] = val;
//		else {
//			cout << -1 << endl;
//			return;
//		}
//	}
//	int bit = toi(v);
//	cout << (f[bit] == inf ? -1 : f[bit]) << endl;
//}

//signed main(){

//	IO;

//	queue<int>que;
//	for(int i = 0;i < mxf;i++){
//		f[i] = inf;
//		num5 a(i);
//		if(a.ok()){
//			f[i] = 0;
//			que.push(i);
//			vis[i] = 1;
//			continue;
//		}
//		for(int j = 1;j <= 4;j++){
//			int v = a.op(j);
//			if(v > 0 && v != i) g[v].push_back(i);
//		}
//	}

//	while(que.size()){
//		int u = que.front();
//		que.pop();
//		for(auto v : g[u]) if(!vis[v]){
//			vis[v] = 1;
//			f[v] = f[u] + 1;
//			que.push(v);
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
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//using ll = long long;
//using ar = array<int,140>;

//const int N = 140;
//const int mod = 998244353;
//int qpow(int a, int b){
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = a * ret % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}
//int f[N];
//int n, m;

//ar cnt[N], sum[N];

//ar merg(ar &a, ar &b){
//	ar ret = {0};
//	ret[1] = 1;
//	for(int i = 1;i < N;i++){
//		for(int j = 1;j < N;j++){
//			if(i+j+1 >= N) break;
//			(ret[i+j+1] += a[i]*b[j]%mod) %= mod;
//		}
//	}
//	for(int i = 2;i < N;i++) {
//		(ret[i] += ((a[i-1] + b[i-1])%mod)) %= mod;
//	}
//	return ret;
//}
//void init(){
//	for(int i = 1;i < N;i++){
//		int pw = 1;
//		for(int j = 1;j <= i;j++, pw *= 2, pw %= mod){
//			cnt[i][j] = pw;
//		}
//	}
//	sum[1][1] = 1;
//	for(int i = 2;i < N;i++){
//		sum[i] = merg(cnt[i-1], cnt[i-1]);
//		for(int j = 1;j < N;j++) (sum[i][j] += sum[i-1][j]*2%mod) %= mod;
//	}
//}
//ar carr(int id){
//	if(id > n){
//		ar ret = {0};
//		return ret;
//	}
//	int r = id * 2 + 1;
//	int l = id * 2;
//	int len = 1;
//	while(r <= n) {
//		len++;
//		l = l * 2;
//		r = r * 2 + 1;
//	}
//	ar ret = cnt[len];
//	(ret[len+1] += n-l+1) %= mod;
//	return ret;
//}
//int full(int id){
//	if(id > n) return 0;
//	int l = id * 2;
//	int r = id * 2 + 1;
//	int len = 1;
//	while(r <= n){
//		l = l * 2;
//		r = r * 2 + 1;
//		len++;
//	}
//	return l > n ? len : 0;
//}

//void solve(){
//	cin >> n >> m;
//	for(int i = 1;i < N;i++){
//		f[i] = m*qpow(m, i) % mod;
//		for(int j = 1;j < m;j++) (f[i] -= qpow(j, i)-mod) %= mod;
//	}

//	auto dfs = [&](auto self, int u) -> ar {
//		if(u > n){
//			ar ret = {0};
//			return ret;
//		}
//		int len = full(u);
//		if(len) return sum[len];
//		ar ls, rs, lc, rc, ret;
//		int lid = u << 1;
//		int rid = u << 1 | 1;
//		int llen = full(lid);
//		int rlen = full(rid);
//		if(llen){
//			ls = sum[llen];
//			lc = cnt[llen];
//		}else{
//			ls = self(self, lid);
//			lc = carr(lid);
//		}
//		if(rlen){
//			rs = sum[rlen];
//			rc = cnt[rlen];
//		}else{
//			rs = self(self, rid);
//			rc = carr(rid);
//		}
//		ret = merg(lc, rc);
//		for(int i = 1;i < N;i++) (ret[i] += ls[i] + rs[i]) %= mod;
//		return ret;
//	};

//	auto E = dfs(dfs, 1);

//	E[1] = n % mod;
//	E[2] = (n-1) % mod;
//	ll ans = 0;
//	for(int i = 1;i < N && i <= n;i++){
//		(ans += (f[i]*E[i]%mod)*qpow(m,n-i)%mod) %= mod;
//	}

//	cout << ans << endl;
//}

//signed main(){

//	IO;
//	init();
//	ll t = 1;
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

//const int M = 26*26+5;
//const int N = 5e4 + M;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//int n;

//int h(char a, char b){
//	return (a-'a')*26 + (b-'a') + 1 + n;
//}

//vector<array<int,2>>g[N];

//void solve(){
//	string s;
//	cin >> s;
//	n = s.size()-1;
//	s = ' ' + s;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) a[i] = h(s[i], s[i+1]);

//	int q;
//	cin >> q;
//	vector<array<int,2>>qur(q+5);
//	vector<int>ans(q+5);
//	for(int i = 1;i <= q;i++){
//		cin >> qur[i][0] >> qur[i][1];
//		ans[i] = abs(qur[i][0] - qur[i][1]);
//	}

//	for(int i = 1;i <= n;i++){
//		if(i+1 <= n){
//			g[i].push_back({i+1, 1});
//			g[i+1].push_back({i, 1});
//		}
//		g[i].push_back({a[i], 1});
//		g[a[i]].push_back({i, 0});
//	}

//	int lp = h('a','a'), rp = h('z','z');
//	for(int i = lp;i <= rp;i++) if(g[i].size()){
//		vector<int>dis(rp+5, inf);
//		deque<int>que;
//		dis[i] = 0;
//		que.push_back(i);
//		while(que.size()){
//			int u = que.front();
//			que.pop_front();
//			for(auto [v, w] : g[u]) if(w + dis[u] < dis[v]){
//				dis[v] = dis[u] + w;
//				if(w){
//					que.push_back(v);
//				}else{
//					que.push_front(v);
//				}
//			}
//		}
//		for(int j = 1;j <= q;j++){
//			auto [l, r] = qur[j];
//			ans[j] = min(ans[j], dis[l] + dis[r] + 1);
//		}
//	}

//	for(int i = 1;i <= q;i++) cout << ans[i] << endl;
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

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5), f(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		a[i] %= k;
//	}
//	f[1] = a[1];
//	priority_queue<int,vector<int>,greater<int>>que;
//	for(int i = 2;i <= n;i++){
//		if(a[i] <= a[i-1]) f[i] = f[i-1];
//		else f[i] = f[i-1] + a[i]-a[i-1];
//		if(que.size() && f[i-1]+que.top() < f[i]){
//			f[i] = f[i-1]+que.top();
//			que.pop();
//			que.push(a[i]-a[i-1]);
//		}		
//		else if(a[i] < a[i-1]) que.push(a[i]+k-a[i-1]);
//	}
//	cout << f[n] << endl;
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


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		a[i] %= k;
//	}
//	for(int i = n;i >= 1;i--) a[i] -= a[i-1];
//	priority_queue<int,vector<int>,greater<int>>que;
//	int ans = 0;
//	for(int i = 1;i <= n;i++){
//		if(a[i] >= 0) {
//			if(que.size() && que.top()+k < a[i]) {
//				ans += que.top()+k;
//				que.pop();
//				a[i] -= k;
//			}else{
//				ans += a[i];
//				continue;
//			}
//		}
//		que.push(a[i]);
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

//struct node{
//	int x, y, d;
//};
//const int R = 2;
//const int L = 3;

//vector<array<int,2>>op({
//	{-1, -1},
//	{-1, 0},
//	{-1, 1},
//	{0, 1},
//	{1, 1},
//	{1, 0},
//	{1, -1}, 
//	{0, -1} 
//});
//vector<vector<int>>fg({
//	{5},
//	{5,7},
//	{7},
//	{7,1},
//	{1},
//	{1,3},
//	{3},
//	{5,3}
//});

//void solve(){
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<vector<int>>mp(n+5, vector<int>(m+5));
//	mp[n] = mp[0] = vector<int>(m+5, -1);
//	for(int i = 1;i <= n;i++) mp[i][0] = mp[i][m] = -1;

//	vector<node>qur(k+5);
//	for(int i = 1, x1,x2,y1,y2;i <= k;i++){
//		cin >> x1 >> y1 >> x2 >> y2;
//		qur[i] = {x1, min(y1,y2), y1<y2?R:L};
//	}

//	auto check = [&](int x, int y, int id) -> int {
//		for(auto i : fg[id]){
//			int c[3], ok = 1;
//			for(int j = 0;j < 3;j++){
//				int nx = x + op[(i-j+8)%8][0];
//				int ny = y + op[(i-j+8)%8][1];
//				c[j] = mp[nx][ny];
//				if(c[j] <= 0) {
//					ok = 0;
//					break;
//				}
//			}
//			if(!ok) continue;
//			if(c[0] == c[1]) return c[2];
//			else return c[2]^1;
//		}
//		return 0;
//	};

//	auto dfs = [&](auto self, int x, int y, int v) -> void {
//		mp[x][y] = v;
//		for(int i = 0;i < 8;i++){
//			auto [nx, ny] = op[i];
//			nx += x, ny += y;
//			if(mp[nx][ny] != 0) continue;
//			int d = check(nx, ny, i);
//			if(d) self(self, nx, ny, d);
//		}
//	};

//	for(int i = 1;i <= k;i++){
//		auto [x, y, d] = qur[i];
//		if(mp[x][y] && mp[x][y] != d){
//			cout << "NO\n";
//			return;
//		}
//		dfs(dfs, x, y, d);
//	}

//	for(int i = 1;i < n;i++){
//		for(int j = 1;j < m;j++) cerr << mp[i][j] << ' ';
//		cerr << endl;
//	}
//	cout << "YES\n";
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

//struct node{
//	int x, y, d;
//};
//const int R = 2;
//const int L = 3;


//void solve(){
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<vector<int>>mp(n+5, vector<int>(m+5));

//	vector<node>qur(k+5);
//	for(int i = 1, x1,x2,y1,y2;i <= k;i++){
//		cin >> x1 >> y1 >> x2 >> y2;
//		qur[i] = {x1, min(y1,y2), y1<y2?R:L};
//	}

//	for(int i = 1;i <= k;i++){
//		auto [x, y, d] = qur[i];
//		if(mp[x][y] && mp[x][y] != d){
//			cout << "NO\n";
//			return;
//		}
//		mp[x][y] = d;
//	}

//	//for(int i = 1;i < n;i++){
//	//	for(int j = 1;j < m;j++) cerr << mp[i][j] << ' ';
//	//	cerr << endl;
//	//}

//	deque<int>que;
//	vector<set<int>>st(m+5);
//	vector<int>vis(n+5);
//	for(int i = 2;i < n;i++) que.push_back(i);
//	vector<int>cur(mp[1]);
//	while(que.size()){
//		int i = que.front();
//		que.pop_front();
//		int f = -1;
//		for(int j = 1;j < m;j++) if(cur[j] && mp[i][j]){
//			if(f == -1){
//				f = (cur[j] == mp[i][j]);
//				continue;
//			}
//			if(f != (cur[j] == mp[i][j])){
//				cout << "NO\n";
//				return;
//			}
//		}
//		if(f == -1){
//			for(int j = 1;j < m;j++) if(mp[i][j]){
//				st[j].insert(i);
//			}
//			continue;
//		}
//		for(int j = 1;j < m;j++) if(!cur[j] && mp[i][j]){
//			auto it = st[j].begin();
//			while(it != st[j].end()){
//				if(!vis[*it]){
//					que.push_front(*it);
//					vis[*it] = 1;
//				}
//				it = st[j].erase(it);
//			}
//			if(f) cur[j] = mp[i][j];
//			else cur[j] = mp[i][j] ^ 1;	
//		}
//	}

//	st = vector<set<int>>(n+5);
//	vis = vector<int>(m+5);
//	cur = vector<int>(n+5);
//	for(int j = 2;j < m;j++) que.push_back(j);
//	for(int i = 1;i < n;i++) cur[i] = mp[i][1];
//	while(que.size()){
//		int j = que.front();
//		que.pop_front();
//		int f = -1;
//		for(int i = 1;i < n;i++) if(cur[i] && mp[i][j]){
//			if(f == -1){
//				f = (cur[i] == mp[i][j]);
//				continue;
//			}
//			if(f != (cur[i] == mp[i][j])){
//				cout << "NO\n";
//				return;
//			}
//		}
//		if(f == -1){
//			for(int i = 1;i < n;i++) if(mp[i][j]){
//				st[i].insert(j);
//			}
//			continue;
//		}
//		for(int i = 1;i < n;i++)if(!cur[i] && mp[i][j]){
//			auto it = st[i].begin();
//			while(it != st[i].end()){
//				if(!vis[*it]){
//					que.push_front(*it);
//					vis[*it] = 1;
//				}
//				it = st[i].erase(it);
//			}
//			if(f) cur[i] = mp[i][j];
//			else cur[i] = mp[i][j] ^ 1;
//		}
//	}

//	cout << "YES\n";
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


//void solve(){
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<vector<array<int,2>>>g(n+m);
//	vector<int>c(n+m);
//	for(int i = 1, x1,x2,y1,y2,x,y,d;i <= k;i++){
//		cin >> x1 >> y1 >> x2 >> y2;
//		x = x1, y = min(y1,y2);
//		d = y1==y;
//		g[x].push_back({y+n-1,d});
//		g[y+n-1].push_back({x,d});
//	}
//	auto dfs = [&](auto self, int u) -> int {
//		for(auto [v, w] : g[u]) {
//			int nc = (c[u] ^ w);
//			if(c[v]){
//				if(c[v] != nc) return 0;
//			}else{
//				c[v] = nc;
//				if(!self(self, v)) return 0;
//			}
//		}
//		return 1;
//	};
//	for(int i = 1;i <= n+m-2;i++) if(!c[i]){
//		c[i] = 2;
//		if(!dfs(dfs, i)){
//			cout << "NO\n";
//			return;
//		}
//	}
//	cout << "YES\n";
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

//const int N = 305;
//int f[N][N*N];

//void solve(){
//	int n, sum = 0;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		sum += a[i];
//	}

//	set<int>st, st2;
//	if(sum % 2 == 0){
//		int hf = sum / 2;
//		f[0][0] = -1;
//		for(int i = 1;i <= n;i++){
//			for(int j = 0;j <= hf;j++) if(f[i-1][j]){
//				f[i][j] = max(f[i][j], f[i-1][j]);
//				if(j+a[i] <= hf) f[i][j+a[i]] = i;
//			}
//		}
//		if(f[n][hf]){
//			int p = f[n][hf];
//			while(p > 0){
//				//if(a[p]) st.insert(p);
//				st.insert(p);
//				hf -= a[p];
//				p = f[p-1][hf];
//			}
//		}
//	}

//	int ret, j;
//	if(st.size()){
//		for(int i = 1;i <= n;i++) if(a[i] && st.count(i)==0){
//			st2.insert(i);
//		}
//		cout << "Second" << endl;
//		while(1){
//			while(st.size() && a[*st.begin()] == 0) st.erase(st.begin());
//			while(st2.size() && a[*st2.begin()] == 0) st2.erase(st2.begin());
//			cin >> ret;
//			if(ret <= 0) return;
//			if(st.count(ret)){
//				j = *st2.begin();
//			}else{
//				j = *st.begin();
//			}
//			cout << j << endl;
//			int d = min(a[ret], a[j]);
//			a[ret] -= d;
//			a[j] -= d;
//		}
//	}else{
//		cout << "First" << endl;
//		while(1){
//			for(int i = 1;i <= n;i++) if(a[i]){
//				j = i;
//				break;
//			}
//			cout << j << endl;
//			cin >> ret;
//			if(ret <= 0) return;
//			int d = min(a[ret], a[j]);
//			a[ret] -= d;
//			a[j] -= d;
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 0x3f3f3f3f3f3f3f3f;

//class Tree {
//public:
//	#define ls id << 1
//	#define rs id << 1 | 1

//	vector<int>cnt, sum, a;
//	Tree(int n, vector<int>&a) : a(a), cnt(n*4+5), sum(n*4+5) {}

//	void up(int id){
//		sum[id] = sum[ls] + sum[rs];
//		cnt[id] = cnt[ls] + cnt[rs];
//	}
//	void add(int id, int l, int r, int x, int v){
//		if(l == r){
//			cnt[id] += v;
//			sum[id] = cnt[id] * a[l];
//			return;
//		}
//		int mid = l + r >> 1;
//		if(x <= mid) add(ls, l, mid, x, v);
//		else add(rs, mid + 1, r, x, v);
//		up(id);
//	}
//	int query(int id, int l, int r, int k){
//		if(l == r) return a[l] * k;
//		int mid = l + r >> 1;
//		if(k <= cnt[ls]) return query(ls, l, mid, k);
//		else return sum[ls] + query(rs, mid + 1, r, k-cnt[ls]);
//	}
//};

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5), b(1);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		b.push_back(a[i]);
//	}
//	sort(all1(b));
//	b.erase(unique(all1(b)), b.end());
//	int m = b.size()-1;
//	Tree ptr(m, b), str(m, b);
//	unordered_map<int,int>pos;
//	for(int i = 1;i <= m;i++) pos[b[i]] = i;
//	for(int i = 1;i <= n;i++){
//		str.add(1, 1, m, pos[a[i]], 1);
//	}

//	auto val = [&](int l, int r) -> int {
//		return max(ptr.query(1, 1, m, l), str.query(1, 1, m, r));
//	};

//	int ans = inf;
//	for(int i = 1;i <= n;i++){
//		int l = max(0ll, i-(n-k+1)), r = min(i-1, k);
//		while(r-l >= 6){
//			int d = (r-l)/3;
//			int m1 = l+d;
//			int m2 = l+d*2;
//			if(val(m1, k-m1) > val(m2, k-m2)) l = m1 + 1;
//			else r = m2 - 1;
//		}
//		for(int j = l;j <= r;j++) {
//			ans = min(ans, val(j, k-j));
//		}
//		if(i <= n){
//			ptr.add(1, 1, m, pos[a[i]], 1);
//			str.add(1, 1, m, pos[a[i]], -1);
//		}
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


//void pt(vector<int>&v){
//	for(auto e : v) cerr << e << ' ';
//	cerr << endl;
//}

//void solve(){
//	int n, q, k;
//	cin >> n >> q;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(all1(a));
//	int an = a[n];

//	a[n+1] = a[n] + 1e10;
//	vector<int>MN(n+5);
//	int pmn = a[1];
//	for(int i = 1;i <= n;i++){
//		pmn++;
//		MN[i] = min(pmn, a[i+1]);
//		pmn = min(pmn, a[i+1]);
//	}
//	//cerr << MN[n] << endl;

//	for(int i = 1;i <= n;i++) a[i] -= i-1;
	
//	sort(a.begin()+1, a.begin()+n);
//	//pt(a);
//	int sum2 = 0, mn2 = a[1];
//	for(int i = 1;i < n;i++) sum2 += a[i] - mn2;
//	//cerr << sum2 << endl;
	
//	sort(all1(a));
//	int sum1 = 0, mn1 = a[1];
//	for(int i = 1;i <= n;i++) sum1 += a[i] - mn1;

//	while(q--){
//		cin >> k;
//		if(k <= n){
//			cout << MN[k] << ' ';
//		}else{	
//			int mn, sum, d;
//			if((k-n) % 2 == 0){
//				d = (k-n)/2;
//				mn = mn1 + k;
//				sum = sum1;
//			}else{
//				d = (k-n+1)/2;
//				if(an <= mn2+k){
//					mn = an;
//					sum = sum2 + (mn2+k-an)*(n-1);
//				}else{
//					mn = mn2+k;
//					sum = sum2 + an - mn;
//				}
//			}
//			if(d <= sum) cout << mn << ' ';
//			else cout << mn - (d-sum+n-1)/n << ' ';
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//mt19937 rd(time(0));
//const int mod = 998244353;
//const int N  = 3e5 + 10;
//int H[N];

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
//void getinv(){
//	fac[0] = inv[0] = 1;
//	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//	inv[N-1] = qpow(fac[N-1], mod-2);
//	for(int i = N-2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
//}
//int C(int a, int b){
//	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
//}
//int dv(int a, int b){
//	return (a - b + mod) % mod;
//}

//void init(){
//	for(int i = 1;i < N;i++) H[i] = dv(C(2*i, i), C(2*i, i-1));
//}

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>p(n+5);
//	for(int i = 1, l, r, v;i <= k;i++){
//		cin >> l >> r;
//		v = rd();
//		p[l] ^= v;
//		p[r+1] ^= v;
//	}
//	for(int i = 2;i <= n;i++){
//		p[i] ^= p[i-1];
//	}
//	unordered_map<int,int>mp;
//	for(int i = 1;i <= n;i++) mp[p[i]]++;

//	int ans = 1;
//	for(auto [k, v] : mp){
//		if(v & 1) {
//			ans = 0;
//			break;
//		}else{
//			(ans *= H[v/2]) %= mod;
//		}
//	}
//	cout << ans << endl;
//}	

//signed main(){

//	IO;
//	getinv();
//	init();
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

//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), pb(n+5), sb(n+5);
//	vector<vector<int>>suf(n+5, vector<int>(20));
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		suf[i-1][0] = a[i];
//	}
//	for(int j = 1;j < 20;j++){
//		for(int i = 1;i <= n && i+(1<<(j-1)) <= n;i++){
//			suf[i][j] = min(suf[i][j-1], suf[i+(1<<(j-1))][j-1]);
//		}
//	}

//	stack<int>st;
//	a[0] = a[n+1] = inf;
//	st.push(0);
//	for(int i = 1;i <= n;i++){
//		while(a[i] > a[st.top()]) st.pop();
//		pb[i] = st.top();
//		st.push(i);
//	}
//	while(st.size()) st.pop();
//	st.push(n+1);
//	for(int i = n;i >= 1;i--){
//		while(a[i] > a[st.top()]) st.pop();
//		sb[i] = st.top();
//		st.push(i);
//	}

//	int ans = 0;
//	for(int i = 2;i <= n;i++){
//		ans += (i-1) * (n-i+1);
//	}

//	for(int i = 1;i <= n;i++) if(sb[i] <= n){
//		int p = sb[i];
//		for(int j = 19;j >= 0;j--){
//			if(suf[p][j] > a[i]){
//				p += (1<<j);
//			}
//		}
//		p++;
//		ans -= (i-pb[i]) * (p-sb[i]);
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

//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int n;
//	cin >> n;
//	if(n <= 3){
//		cout << n << endl;
//		return;
//	}
//	int l = 1, r = min(5000000ll, n);
//	auto val = [&](int n) -> int {
//		return n*(n+1)/2 + n*(n-1)/2;
//	};
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(val(mid) <= n) l = mid + 1;
//		else r = mid - 1;
//	}

//	int h = r;
//	int sum = val(h), ans = 2*h-1;
//	for(int i = h;i >= 1;){
//		int d = n-sum;
//		int c = d/i;
//		ans += c;
//		sum += c * i;
//		i = min(h,n-sum);
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

//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int r, c, k;
//	cin >> r >> c >> k;
//	map<int,int>mp;
//	for(int i = 1;i <= c;i++){
//		int x;
//		cin >> x;
//		mp[x]++;
//	}
//	vector<int>a;
//	for(auto [k, v] : mp) a.push_back(v);
//	sort(all(a));
//	int ans = 0;
//	for(int i = a.size()-1;i >= 0 && k;i--, k--){
//		ans += a[i];
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

//const int inf = 0x3f3f3f3f3f3f3f3f;

//int val(int x){
//	return x*x;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a;
//	for(int i = 2;1;i++){
//		if(val(i)-val(i-1) > n) break;
//		int j2 = val(i)-n;
//		int j = sqrt(j2);
//		if(j > 0 && val(j) == j2) a.push_back(i);
//	}
//	cout << a.size() << endl;
//	for(int i = 0;i < a.size();i++){
//		cout << a[i];
//		if(i+1 < a.size()) cout << ' ';
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

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 10;
//int mn[N];

//int ne(int x){
//	int ret = 0;
//	while(x){
//		int d = x % 10;
//		ret += d*d;
//		x /= 10;
//	}
//	return ret;
//}

//void solve(){
//	int a, b, ans = 0;
//	cin >> a >> b;
//	for(int i = a;i <= b;i++){
//		ans += mn[i];
//	}
//	cout << ans << endl;
//}	

//int dfs(int u){
//	if(mn[u]) return mn[u];
//	mn[u] = u;
//	return mn[u] = min(mn[u], dfs(ne(u)));
//}

//void init(){
//	for(int i = 1;i < N;i++) if(!mn[i]){
//		mn[i] = dfs(i);
//	}
//}

//signed main(){

//	IO;
//	init();
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

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 10;


//int ne(int x){
//	int ret = 0;
//	while(x){
//		int d = x % 10;
//		ret += d*d;
//		x /= 10;
//	}
//	return ret;
//}

//void solve(){
//	int x;
//	cin >> x;
//	map<int,int>mp;
//	while(1){
//		cerr << x << ' ';
//		if(mp[x]) break;
//		mp[x] = 1;
//		x = ne(x);
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

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 10;


//void solve(){
//	int n, k, m;
//	cin >> n >> k >> m;
//	map<char, int>bad;
//	string s, bs;
//	cin >> s >> bs;
//	for(auto c : bs) bad[c] = 1;
//	for(auto &c : s) c = bad[c];
//	s = (char)1 + s + (char)1;

//	int ans = 0;
//	queue<int>que;
//	for(int i = 0;i < n+2;i++)if(s[i]){
//		if(que.size() == k+1){
//			int l = que.front();
//			que.pop();
//			ans += (que.front()-l) * (i-que.back());
//		}
//		que.push(i);
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

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 10;
//int tr[N];
//int lowbit(int x){
//	return x & -x;
//}
//void add(int x, int v){
//	while(x < N){
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


//void solve(){
//	int n, m, q;
//	cin >> n >> m >> q;
//	vector<int>c(n+5), a(n+5);
//	for(int i = 1;i <= n;i++) cin >> c[i];
//	vector<array<int,2>>mod(m+5);
//	for(int i = 1;i <= m;i++){
//		cin >> mod[i][0] >> mod[i][1];
//	}
//	vector<vector<array<int,3>>>qur(m+5);
//	for(int i = 1;i <= q;i++){
//		int d, l, r;
//		cin >> d >> l >> r;
//		qur[d].push_back({i, l, r});
//	}
//	vector<int>ans(q+5);

//	for(int i = 1;i <= m;i++){	
//		auto [bas, cnt] = mod[i];
//		cnt = min(cnt, c[bas] - a[bas]);
//		a[bas] += cnt;
//		add(bas, cnt);
//		for(auto [id, l, r] : qur[i]){
//			ans[id] = getsum(r) - getsum(l-1);
//		}
//	}

//	for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
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

//const int inf = 0x3f3f3f3f3f3f3f3f;

//int bitc(int x){
//	int ret = 0;
//	while(x){
//		ret += (x & 1ll);
//		x >>= 1;
//	}
//	return ret;
//}

//void solve(){
//	int n, k, f;
//	cin >> n >> k >> f;
//	vector<int>fb(f+5, (1ll<<n)-1);
//	for(int i = 1;i <= f;i++){
//		int c;
//		cin >> c;
//		while(c--){
//			int x;
//			cin >> x;	
//			fb[i] ^= (1ll<<(x-1));
//		}
//	}

//	auto check = [&](int x) -> int {
//		int fd = (1ll<<n)-1;
//		for(int i = 1;i <= f;i++) if((1ll<<(i-1)) & x){
//			fd &= fb[i];
//		}
//		return bitc(fd) >= k;
//	};

//	int ans = 0;
//	for(int i = 0;i < (1ll<<f);i++){
//		if(check(i)) ans = max(ans, bitc(i));
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

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 1e9 + 7;
//int n, d, k, s;

//struct Mat{
//	int m[102][102];
//	int r, c;
//	Mat(int r, int c) : r(r), c(c) {
//		for(int i = 1;i <= r;i++)
//			for(int j = 1;j <= c;j++) m[i][j] = 0;
//	};
//	void init(){
//		for(int i = 1;i <= r;i++) m[i][i] = 1;
//	}
//	int* operator[](int r){
//		return m[r];
//	}
//	Mat operator*(Mat &e) {
//		Mat ret(r,c);
//		for(int i = 1;i <= r;i++)
//			for(int j = 1;j <= c;j++) 
//				for(int k = 1;k <= r;k++){
//					(ret[i][j] += m[i][k] * (e[k][j]) % mod) %= mod;
//				}
//		return ret;
//	}
//	void pt(){
//		for(int i = 1;i <= r;i++){
//			for(int j = 1;j <= c;j++) cerr << m[i][j] << ' ';
//			cerr << endl;
//		}
//		cerr << endl;
//	}
//};
//struct Pt{
//	int m[102];
//	int r;
//	Pt(int r) : r(r) {
//		for(int i = 1;i <= r;i++) m[i] = 0;
//	}
//	int& operator[](int i){
//		return m[i];
//	}
//	Pt operator*(Mat &mt) {
//		Pt ret(r);
//		for(int i = 1;i <= r;i++){
//			for(int k = 1;k <= r;k++){
//				(ret[i] += m[k] * mt[k][i] % mod) %= mod;
//			}
//		}
//		return ret;
//	}
//	void pt(){
//		for(int i = 1;i <= r;i++) cerr << m[i] << ' ';
//		cerr << endl;
//		cerr << endl;
//	}
//};

//Mat qpow(Mat a, int b){
//	Mat ret(n+1,n+1);
//	ret.init();
//	while(b){
//		if(b & 1) ret = ret * a;
//		a = a * a;
//		b >>= 1; 
//	}
//	return ret;
//}

//void solve(){
//	cin >> n >> d >> k >> s;
//	if(k == 1){
//		cout << 1 << endl;
//		return;
//	}
//	Pt f1(n+1);
//	f1[1] = 1;
//	f1[n+1] = 1;

//	d = min(n, d*2+1);
//	Mat X(n+1,n+1);
//	X[n+1][1] = X[n+1][n+1] = 1;
//	//for(int i = 1;i <= n;i++)
//	//	for(int j = 1;j <= n;j++) X[i][j] = 1;
//	for(int c = 1;c <= n;c++){
//		int r = c;
//		for(int j = 1;j <= d;j++){
//			//cerr << r << ' ';
//			X[r][c]++;
//			r++;
//			if(r > n) r = 1;
//		}
//		//cerr << endl;
//	}
//	//X.pt();
//	X = qpow(X, k-1);
//	//X.pt();

//	f1 = f1 * X;
//	//f1.pt();
//	int ans = 0;
//	for(int i = 1;i <= n;i++) {
//		(ans += f1[i]) %= mod;
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

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 1e9 + 7;
//int n, d, k, s;
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
//	cin >> n >> d >> k >> s;
//	if(k == 1){
//		cout << 1 << endl;
//		return;
//	}
//	if(d == 0){
//		cout << k << endl;
//		return;
//	}
//	d = min(n, d*2 + 1);
//	cout << ((qpow(d, k)-1+mod)%mod) * qpow(d-1,mod-2) % mod;

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

//void solve(){
//	int c, n, m;
//	cin >> c >> n >> m;
//	vector<int>a(n+5), f(60), ans(60);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		if(a[i]){
//			for(int j = 1;1;j++){
//				if(a[i] * (1<<j) > c){
//					f[j-1]++;
//					break;
//				}
//			}
//		}
//	}
//	int sum = 0;
//	for(int i = 0;i <= 54;i++){
//		ans[i] = n + sum;
//		n -= f[i];
//		sum += f[i];
//		sum <<= 1;
//	}

//	while(m--){
//		int x;
//		cin >> x;
//		cout << ans[x] << endl;
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

//const int N = 2000;
//const int M = N*N;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//int s, t;
//int n, m;
//int r, c, d;

//int id(int x, int y){
//	return (x-1)*c + y;
//}

//int tot = 1, h[N];  //正边 ^ 1 == 反边， 所以编号从2开始
//struct edge{
//    int v, c, ne;
//}e[M<<1];  //需要建反边，边数开两倍空间
//void add(int u, int v, int c){
//    e[++tot] = {v, c, h[u]};
//    h[u] = tot;
//    e[++tot] = {u, 0, h[v]};
//    h[v] = tot;
//}

//int dep[N], cur[N];

//bool bfs(){  //先对点分层，减小dfs深度
//    for(int i = 1;i <= n;i++) dep[i] = 0;
//    dep[s] = 1;
//    queue<int>q;
//    q.push(s);
//    while(q.size()){
//        int u = q.front();
//        q.pop();
//        for(int i = h[u];i;i = e[i].ne){
//            int v = e[i].v;
//            if(dep[v] == 0 && e[i].c){
//                dep[v] = dep[u] + 1;
//                q.push(v);
//                if(v == t) return true;
//            }
//        }
//    }
//    return false;
//} 

//int dfs(int u, int mf){  //多路增广
//    if(u == t) return mf;
//    int sum = 0;
//    for(int i = cur[u];i;i = e[i].ne){
//        cur[u] = i;  //当前弧优化
//        int v = e[i].v;
//        if(dep[v] == dep[u] + 1 && e[i].c){
//            int f = dfs(v, min(mf, e[i].c));
//            e[i].c -= f;   //更新残留网
//            e[i^1].c += f;
//            sum += f;
//            mf -= f;
//            if(mf == 0) break;
//        }
//    }
//    if(sum == 0) dep[u] = 0;  //残枝优化
//    return sum;
//}

//int Dinic(){  //累加可行流
//    int flow = 0;
//    while(bfs()){
//        for(int i = 1;i <= n;i++) cur[i] = h[i];
//        flow += dfs(s, inf);
//    }
//    return flow;
//}

//int op[4][2] = {
//	0, 1,
//	0, -1,
//	1, 0,
//	-1, 0
//};

//void solve(){
//	cin >> r >> c >> d;
//	s = id(r,c)+1;
//	t = s+1;
//	n = t + id(r,c);
//	vector<string>mp(r+5);
//	vector<vector<array<int,2>>>P(4);
//	for(int i = 1;i <= r;i++){
//		cin >> mp[i];
//		mp[i] = '#' + mp[i] + '#';
//		for(int j = 1;j <= c;j++){
//			if(mp[i][j] == 'S'){
//				P[1].push_back({i, j});
//			}else if(mp[i][j] == 'H'){
//				P[2].push_back({i, j});
//			}else if(mp[i][j] == 'P'){
//				P[3].push_back({i, j});
//			}
//		}
//	}

//	vector<vector<int>>vis(r+5, vector<int>(c+5));
//	queue<array<int,3>>que;
//	for(auto [cx, cy] : P[2]){
//		for(int i = 1;i <= r;i++){
//			for(int j = 1;j <= c;j++) vis[i][j] = 0;
//		}
//		que.push({cx, cy, 0});
//		vis[cx][cy] = 1;
//		while(que.size()){
//			auto [x, y, ds] = que.front();
//			que.pop();
//			if(ds >= d) continue;
//			for(int i = 0; i < 4;i++){
//				int nx = x + op[i][0];
//				int ny = y + op[i][1];
//				if(vis[nx][ny]) continue;
//				vis[nx][ny] = 1;
//				if(mp[nx][ny] == '.'){
//					que.push({nx, ny, ds+1});
//				}else if(mp[nx][ny] == 'S'){
//					add(id(nx,ny), id(cx, cy)+t, 1);
//				}else if(mp[nx][ny] == 'P'){
//					add(id(cx, cy), id(nx, ny)+t, 1);
//				}
//			}
//		}
//	}

//	for(auto [x, y] : P[1]) add(s, id(x,y), 1);
//	for(auto [x, y] : P[2]) add(id(x,y)+t, id(x,y), 1);
//	for(auto [x, y] : P[3]) add(id(x,y)+t, id(x,y), 1), add(id(x,y), t, 1);

//	cout << Dinic();

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


//void solve(){
//	int m, n;
//	cin >> m >> n;
//	vector<int>a(n+5);
//	vector<bitset<5005>>b(n+5);
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++) b[i][j] = 1;
//	}
	
//	vector<vector<int>>r(m+5, vector<int>(n+5));
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= m;i++){
//		for(int j = 1;j <= n;j++){
//			cin >> r[i][j];
//		}
//		vector<int>idx(n);
//		iota(all(idx), 1);
//		sort(all(idx), [&](int x, int y) -> int {return r[i][x] < r[i][y];});
//		bitset<5005>st;
//		int ls = r[i][idx[0]];
//		stack<int>sk;
//		for(auto cur : idx){
//			while(sk.size() && r[i][cur] > r[i][sk.top()]){
//				st[sk.top()] = 1;
//				sk.pop();
//			}
//			sk.push(cur);
//			b[cur] &= st;
//		}
//	}

//	vector<int>idx(n+5);
//	iota(all1(idx), 1);
//	sort(all1(idx), [&](int i, int j) -> int {return r[1][i] < r[1][j];});

//	int ans = 0;
//	vector<int>f(n+5);
//	for(int i = 1;i <= n;i++){
//		int id = idx[i];
//		f[id] = a[id];
//		for(int j = 1;j <= n;j++) if(j != id && b[id][j]){
//			f[id] = max(f[id], f[j] + a[id]);
//		}
//		ans = max(ans, f[id]);
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

//mt19937 rd(time(0));

//void solve(){
//	int n, rt = 1;
//	cin >> n;
//	//if(n == 200000) rt = 153;
//	//rt = (rd() % n) + 1;
//	vector<vector<int>>g(n+5);
//	vector<int>siz(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	for(int i = 1;i <= n;i++){
//		if(g[i].size() > 1) {
//			rt = i;
//			break;
//		}
//	}
//	auto dfs = [&](auto self, int u, int fa) -> void {
//		siz[u] = 1;
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//			siz[u] += siz[v];
//		}
//		for(int i = 0;i < g[u].size();i++) if(g[u][i] == fa){
//			g[u].erase(g[u].begin()+i);
//			return;
//		}
//	};
//	auto pt = [&]() -> void {
//		for(int i = 1;i <= n;i++){
//			cerr << i << " : ";
//			for(auto e : g[i]) cerr << e << ' ';
//			cerr << endl;
//		}
//		cerr << endl;
//	};
//	dfs(dfs, rt, 0);
//	for(int i = 1;i <= n;i++){
//		sort(all(g[i]), [&](int i, int j) -> int {return siz[i] > siz[j];});
//		if(i == rt){
//			if(g[i].size() >= 3 && siz[g[i][2]] > 1){
//				cout << "No\n";
//				return;
//			}
//		}else{
//			if(g[i].size() >= 2 && siz[g[i][1]] > 1){
//				cout << "No\n";
//				return;
//			}
//		}
//	}

//	vector<int>ans;
//	auto dfs2 = [&](auto self, int u, int fa, int f) -> void {
//		if(f){
//			reverse(all(g[u]));
//			for(auto v : g[u]) if(v != fa){
//				ans.push_back(v);
//			}
//			if(g[u].size()) self(self, g[u].back(), u, f^1);
//		}else{
//			if(g[u].size()) self(self, g[u].front(), u, f^1);
//			for(auto v : g[u]) if(v != fa){
//				ans.push_back(v);
//			}
//		}
//	};

//	cout << "Yes\n";
//	ans.push_back(rt);

//	dfs2(dfs2, g[rt][0], rt, 1);
//	ans.push_back(g[rt][0]);

//	for(int i = 2;i < g[rt].size();i++) ans.push_back(g[rt][i]);

//	if(g[rt].size() > 1) {
//		ans.push_back(g[rt][1]);
//		dfs2(dfs2, g[rt][1], rt, 0);
//	}

//	for(auto e : ans) cout << e << ' ';

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


//void solve(){
//	int n, a, b, mnid = 0, mxid = 0, mx = 0, mn = 0;
//	cin >> n >> a >> b;
//	vector<int>v(n+5), pre(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> v[i];
//		pre[i] = v[i] + pre[i-1];
//		if(pre[i] > mx) mxid = i;
//		if(pre[i] < mn) mnid = i;
//		mx = max(pre[i], mx);
//		mn = min(pre[i], mn);
//	}
//	//cerr << pre[n] << endl;
//	//cerr << mx << ' ' << mxid << endl;
//	//cerr << mn << ' ' << mnid << endl;

//	auto op = [&](int &x, int &y, int it) -> void {
//		for(it;it <= n;it++){
//			int w = v[it];
//			if(w > 0){
//				int d = min({w, x, b-y});
//				x -= d;
//				y += d;
//			}else{
//				int d = min({-w, y, a-x});
//				x += d;
//				y -= d;
//			}
//		}
//	};

//	vector<array<int,2>>s(a+b+5);
//	for(int i = 1;i <= a+b;i++){
//		int y = min(i, b), x = i-y;
//		op(x, y, mxid+1);
//		s[i][0] = x;
//		x = min(i, a), y = i-x;
//		op(x, y, mnid+1);
//		s[i][1] = x;
//	}

//	for(int i = 0;i <= a;i++){
//		for(int j = 0;j <= b;j++){
//			int ans;
//			if(mx >= min(i, b-j)) ans = s[i+j][0];
//			else if(-mn >= min(j, a-i)) ans = s[i+j][1];
//			else ans = i-pre[n];
//			cout << ans << ' ';
//		}
//		cout << endl;
//	}
//	//for(int i = 0;i <= a;i++){
//	//	for(int j = 0;j <= b;j++){
//	//		char c;
//	//		if(mx >= min(i, b-j)) c = 'D';
//	//		else if(-mn >= min(j, a-i)) c = 'X';
//	//		else c = '.';
//	//		cerr << c << ' ';
//	//	}
//	//	cerr << endl;
//	//}
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

//int n, k;
//struct node{
//	int l, r, sum, all, on;
//	node operator+(const node& e) {
//		node ret;
//		ret.l = l;
//		if(all) ret.l += e.l;
//		ret.all = all && e.all;
//		ret.r = e.r;
//		ret.sum = sum + e.sum;
//		int d = min(e.l, r);
//		ret.sum -= d*2;
//		if(e.on){
//			ret.sum -= r-d;
//		}else{
//			ret.r = r-d;
//		}
//		ret.on = on || e.on;
//		return ret;
//	}
//	void pt(){
//		cerr << l << ' ' << r << ' ' << sum << ' ' << all << endl << endl;
//	}
//};
//class Tree{
//public:
//	vector<int>&a, &b;
//	vector<node>tr;
//	Tree(int n, vector<int>&a, vector<int>&b) : a(a), b(b), tr(n*4+5) {
//		build(1, 1, n);
//	}

//	#define ls id << 1
//	#define rs id << 1 | 1

//	void up(int id){
//		tr[id] = tr[ls] + tr[rs];
//	}
//	void build(int id, int l, int r){
//		if(l == r){
//			if(b[l] == 1){
//				tr[id] = {0, k-a[l], k, 0, 1};
//			}else{
//				tr[id] = {a[l], 0, a[l]*2, 1, 0};
//			}
//			return;
//		}
//		int mid = l + r >> 1;
//		build(ls, l, mid);
//		build(rs, mid + 1, r);
//		up(id);
//	}
//	node query(int id, int l, int r, int ql, int qr) {
//		if(ql <= l && r <= qr) return tr[id];
//		int mid = l + r >> 1;
//		if(qr <= mid) return query(ls, l, mid, ql, qr);
//		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//		else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
//	}
//};


//void solve(){
//	cin >> n >> k;
//	vector<int>a(n+5), b(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++) cin >> b[i];
//	Tree tr(n, a, b);

//	node tmp = tr.query(1, 1, n, 1, n);
//	cout << tmp.sum - tmp.r << ' ';
//	for(int i = 2;i <= n;i++){
//		tmp = tr.query(1, 1, n, i, n) + tr.query(1, 1, n, 1, i-1);
//		cout << tmp.sum - tmp.r << ' ';
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


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>fa(n+5), vis(n+5), a(n+5);
//	vector<vector<int>>g(n+5), mp(n+5, vector<int>(n+5));
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//		mp[u][v] = mp[v][u] = 1;
//	}
//	for(int i = 1;i <= n;i++) mp[i][i] = 1;

//	auto find = [&](auto self, int x) -> int {
//		return x == fa[x] ? x : fa[x] = self(self, fa[x]);
//	};
//	auto merg = [&](int a, int b) -> void {
//		a = find(find, a);
//		b = find(find, b);
//		fa[a] = b;
//	};

//	for(int i = 1;i <= n;i++){
//		if(g[i].size() == 1){
//			a[i] = g[i][0];
//		}else{
//			vector<int>nd(n+5);
//			for(auto v : g[i]) {
//				for(auto vv : g[v]) {
//					if(!mp[i][vv]){
//						nd[v] = 1;
//						break;
//					}
//				}
//			}

//			vis = vector<int>(n+5);
//			iota(all1(fa), 1);
//			queue<int>que;
//			vis[i] = 1;
//			for(auto v : g[i]) {
//				que.push(v);
//				vis[v] = 1;
//			}
//			while(que.size()){
//				auto u = que.front();
//				que.pop();
//				for(auto v : g[u]) if(v != i){
//					merg(u, v);
//					if(!vis[v]){
//						vis[v] = 1;
//						que.push(v);
//					}
//				}
//			}
//			int f = 0;
//			for(auto v : g[i]) if(nd[v]){
//				//cerr << i << ' ' << v << endl;
//				if(!f){
//					f = find(find, v);
//					a[i] = v;
//				} else {
//					if(find(find, v) != f){
//						//cerr << i << ' ' << v << endl;
//						cout << "No\n";
//						return;
//					}
//				}
//			}
//			if(!a[i]) a[i] = g[i][0];
//		}
//	}

//	cout << "Yes\n";
//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
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

//int n, m;
//int lowbit(int x){
//	return x & -x;
//}
//int lowct(int x){
//	int ret = 0;
//	while(x){
//		ret++;
//		if(x & 1) return ret;
//		x >>= 1;
//	}
//	return 0;
//}
//void pt(int x){
//	for(int i = n-1;i >= 0;i--) {
//		cerr << ((x>>i)&1);
//	}
//	cerr << ' ';
//}
//int hav(int x, int p){
//	return ((1<<(p-1)) & x);
//}
////int bitc(int x){
////	int ret = 0;
////	while(x){
////		if(x&1) ret++;
////		x >>= 1;
////	}
////	return ret;
////}

//void solve(){
//	cin >> n >> m;
//	vector<int>g(n+5), a(n+5), f((1<<n)+5);
//	vector<vector<int>>mp(n+5, vector<int>(n+5));
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v; 
//		mp[u][v] = mp[v][u] = 1;
//		g[u] |= (1<<(v-1));
//		g[v] |= (1<<(u-1));
//	}

//	auto check = [&](int x) -> int {
//		for(int i = 1;i <= n;i++) {
//			if(hav(x, i)) continue;
//			int f = (g[i] & x);
//			if(!f) return 0;
//		}
//		return 1;
//	};


//	for(int i = 1;i < (1<<n);i++) {
//		if(lowbit(i) == i){
//			f[i] = i;
//			continue;
//		}
//		for(int j = 1;j <= n;j++) if(hav(i, j) && j != lowct(i)){
//			int p = i-(1<<(j-1));
//			if(f[p] & g[j]){
//				f[i] |= (1<<(j-1));
//			}
//		}
//	}

//	int b = 0, t = 0;
//	for(int i = 1;i < (1<<n) && !b;i++) if(f[i] && check(i)){
//		int s = lowct(i);
//		for(int j = n;j >= 1;j--) if(hav(f[i], j)){
//			if(mp[s][j]){
//				b = i;
//				t = j;
//				break;
//			}
//		}
//	}
//	int s = lowct(b);

//	//cerr << b << ' ' << s << ' ' << t << endl;

//	if(!b){
//		cout << "No\n";
//		return;
//	}

//	auto dfs = [&](auto self, int b, int t) -> void {
//		if(lowbit(b) == b) return;
//		int p = b - (1<<(t-1));
//		for(int i = n;i >= 1;i--) if(mp[i][t] && hav(f[p], i)){
//			a[t] = i;
//			self(self, p, i);
//			return;
//		}
//	};

//	dfs(dfs, b, t);
//	if(s != t) a[s] = t;

//	cout << "Yes\n";
//	for(int i = 1;i <= n;i++){
//		if(!a[i]){
//			for(int j = 1;j <= n;j++) if(mp[i][j]){
//				a[i] = j;
//				break;
//			}
//		}
//		cout << a[i] << ' ';
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

//int n, m;

//int lowct(int x){
//	int ret = 0;
//	while(x){
//		ret++;
//		if(x & 1) return ret;
//		x >>= 1;
//	}
//	return 0;
//}
//int hav(int x, int p){
//	return x>>p-1 & 1;
//}
//int lowbit(int x){
//	return x & -x;
//}


//void solve(){
//	cin >> n >> m;
//	vector<int>g(n+5), f((1<<n)+5), a(n+5);
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		g[u] |= 1<<v-1;
//		g[v] |= 1<<u-1;
//	}

//	for(int i = 1;i <= n;i++) f[1<<i-1] = 1<<i-1;
//	for(int s = 0;s < (1<<n);s++){
//		if(__builtin_popcount(s) < 2) continue;
//		for (int i = 1; i <= n; i++) {
//			if (s >> i - 1 & 1) {
//				if ((1 << i - 1) == lowbit(s)) continue;
//				if (f[s ^ (1 << i - 1)] & g[i]) f[s] |= (1 << i - 1);
//			}
//		}
//	}

//	auto check = [&](int s) -> int {
//		for(int i = 1;i <= n;i++) if(!hav(s, i)){
//			if(!(s & g[i])) return 0;
//		}
//		return 1;
//	};

//	for(int s = 0;s < (1<<n);s++) {
//		int x = lowct(s);
//		if(!(g[x] & f[s])) continue;
//		int ok = 1;
//		for (int i = 1; i <= n; i++) {
//			if (s >> i - 1 & 1) continue;
//			if (!(g[i] & s)) { ok = 0; break; }
//		}
//		if (!ok) continue;
//		for (int i = 1; i <= n; i++) if (!(s >> i - 1 & 1)) a[i] = __lg(lowbit(s & g[i])) + 1;
//		int t = s;
//		while (t) {
//			for (int i = 1; i <= n; i++) if ((f[t] >> i - 1 & 1) && (g[x] >> i - 1 & 1)) {
//				a[x] = i, t ^= (1 << i - 1), x = i;
//				break;
//			}
//		}
//		break;
//	}

//	if(!a[1]){
//		cout << "No\n";
//		return;
//	}

//	cout << "Yes\n";
//	for(int i = 1;i <= n;i++){
//		cout << a[i] << ' ';
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

//int n, m;
//int hav(int x, int p){
//	return x>>p-1 & 1;
//}
//int lowct(int x){
//	int ret = 0;
//	while(x){
//		ret++;
//		if(x & 1) return ret;
//		x >>= 1;
//	}
//	return 0;
//}


//void solve(){
//	cin >> n >> m;
//	vector<int>a(n+5);
//	vector<vector<int>>mp(n+5, vector<int>(n+5)), f((1<<n)+5, vector<int>(n+5));
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		mp[u][v] = mp[v][u] = 1;
//	}
//	for(int i = 1;i <= n;i++) f[1<<i-1][i] = 1;
//	for(int s = 1;s < 1<<n;s++){
//		for(int j = n;j > lowct(s);j--) if(hav(s, j)){
//			int p = s - (1<<j-1);
//			int ok = 0;
//			for(int k = n;k >= 1;k--) if(f[p][k]){
//				if(mp[k][j]){
//					ok = 1;
//					break;
//				}
//			}
//			f[s][j] = ok;
//		}
//	}

//	auto check = [&](int x) -> int {
//		for(int i = 1;i <= n;i++) if(!hav(x, i)){
//			int ok = 0;
//			for(int j = 1;j <= n;j++) if(mp[i][j]){
//				if(hav(x, j)) {
//					ok = 1;
//					break;
//				}
//			}
//			if(!ok) return 0;
//		}
//		return 1;
//	};

//	int b = 0, st, ed;
//	for(int s = 1;s < 1<<n;s++) if(check(s)){
//		st = lowct(s);
//		for(int i = n;i > st;i--) if(f[s][i]){
//			if(mp[i][st]){
//				b = s;
//				ed = i;
//				break;
//			}
//		}
//		if(b) break;
//	}

//	if(!b){
//		cout << "No\n";
//		return;
//	}

//	a[st] = ed;
//	while(ed != st){
//		int p = b - (1<<ed-1);
//		for(int i = n;i >= 1;i--) if(f[p][i] && mp[ed][i]){
//			a[ed] = i;
//			break;
//		}
//		ed = a[ed];
//		b = p;
//	}

//	cout << "Yes\n";
//	for(int i = 1;i <= n;i++){
//		if(!a[i]){
//			for(int j = 1;j <= n;j++) if(mp[i][j]){
//				a[i] = j;
//				break;
//			}
//		}
//		cout << a[i] << ' ';
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


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	if(k > n*n) {
//		cout << "NO\n";
//		return;
//	}
//	if(n & 1){
//		if((k-1)%4 == 0 || k%4 == 0) cout << "YES\n";
//		else cout << "NO\n";
//	}else{
//		if(k % 4 == 0) cout << "YES\n";
//		else cout << "NO\n";
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	set<int>st;
//	int sum = 0;
//	for(int i = 1;i <= n;i++) {
//		cin >> a[i];
//		if(a[i] == i) sum++;
//		st.insert(a[i]);
//	}
//	if(st.size() == 1 && sum > 0) {
//		cout << "-1\n";
//		return;
//	}
//	cout << (sum+1) / 2 << endl;
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


//void solve(){
//	int n, m, f = 0;
//	cin >> n >> m;
//	if(n%2 == 0 && m%2 == 0){
//		cout << "-1\n";
//		return;
//	}
//	if(n%2 == 0){
//		f = 1;
//		swap(n, m);
//	}

//	vector<array<int,2>>p;

//	for(int i = 1;i <= n;i++) p.push_back({i, 1});
//	for(int j = 2;j <= m;j++){
//		for(int i = 1;i <= n;i += 2) p.push_back({i, j});
//		for(int i = 2;i <= n;i += 2) p.push_back({i, j});
//	}

//	for(auto [x, y] : p){
//		if(f) swap(x, y);
//		cout << x << ' ' << y << endl;
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

//const int inf = 0x3f3f3f3f3f3f3f3f;
//int lowbit(int x){
//	return x & -x;
//}
//int k(int x){
//	if(lowbit(x) == x) return inf;
//	int pw = 1;
//	while(1){
//		if(x % pw == 0 && (x/pw)%2==1) return pw;
//		pw <<= 1;
//	}
//}
//int lowct(int x){
//	int ret = 0;
//	while(x){
//		ret++;
//		if(x&1) return ret;
//		x >>= 1;
//	}
//	return 0;
//}

//void solve(){
//	int x, y;
//	cin >> x >> y;
//	int xk = k(x), yk = k(y);
//	if(xk != yk){
//		if(yk > xk) cout << "inf\n";
//		else cout << "-inf\n";
//		return;
//	}
//	if(xk == inf){
//		x = lowct(x);
//		y = lowct(y);
//		cout << x-y << endl;
//		return;
//	}
//	x /= xk;
//	y /= yk;
//	cout << (y-x) / 2 << endl;
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

//struct node {
//	int x, y, f;
//};
//int op[4][2] = {
//	0, 1,
//	1, 0,
//	0, -1,
//	-1, 0
//};

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	unordered_map<int, int>r, c;
//	vector<vector<array<int,2>>>p(m+5);
//	for(int i = 1, x, y, t;i <= n;i++){
//		cin >> x >> y >> t;
//		p[t].push_back({x, y});
//	}

//	vector<node>a;
//	for(int i = 0;i < m;i++){
//		for(auto [x, y] : p[i]){
//			a.push_back({x, y, 0});
//			r[y]++;
//			c[x]++;
//		}
//		vector<array<int,3>>tmp;
//		for(auto &[x, y, f] : a){
//			tmp.push_back({0, y, -1});
//			tmp.push_back({1, x, -1});
//			if(f & 1){
//				if((c[x]-1)&1) (f += 1) %= 4;
//			}else{
//				if((r[y]-1)&1) (f += 1) %= 4;
//			}
//			x += op[f][0];
//			y += op[f][1];
//			tmp.push_back({0, y, 1});
//			tmp.push_back({1, x, 1});
//		}
//		for(auto [clo, z, w] : tmp){
//			if(clo) c[z] += w;
//			else r[z] += w;
//		}
//	}

//	for(auto [x, y, f] : a) cout << x << ' ' << y << endl;
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

//const int N = 3e5 + 10;
//int a[N], n, m, ans;
//vector<int>g[N];


//int del[N];
//int sz[N], dep[N];
//int upv[N], dov[N];

//int fun(int a, int b){
//	return max(a,b) + (int)sqrt(min(a,b));
//}

//void calc(int u){
//	int mx[2] = {0};
//	auto dfs1 = [&](auto self, int u, int fa) -> void {
//		int tmx = 0;
//		for(auto v : g[u]) if(v != fa && !del[v]){
//			self(self, v, u);
//			tmx = max(tmx, upv[v]);
//		}
//		upv[u] = fun(a[u], tmx);
//	};
//	for(auto v : g[u]) if(!del[v]){
//		dfs1(dfs1, v, u);
//		mx[1] = max(mx[1], upv[v]);
//		if(mx[1] > mx[0]) swap(mx[0], mx[1]);
//	}

//	auto dfs2 = [&](auto self, int u, int fa, int w) -> void {
//		dov[u] = fun(a[u], w);
//		ans = max(ans, dov[u]);
//		for(auto v : g[u]) if(v != fa && !del[v]){
//			self(self, v, u, dov[u]);
//		}
//	};

//	for(auto v : g[u]) if(!del[v]){
//		int w = mx[0];
//		if(mx[0] == upv[v]) w = mx[1];
//		w = fun(w, a[u]);
//		dfs2(dfs2, v, u, w);
//	}
//	ans = max(ans, fun(mx[1], a[u]));
//}

//void dfs(int u, int s){
//    int ms = s + 1, root = -1;
//    auto getroot = [&](auto self, int u, int f) -> void {
//        sz[u] = 1;
//        int mx = 0;
//        for(auto v : g[u]) if(!del[v] && v != f){
//            self(self, v, u);
//            sz[u] += sz[v];
//            mx = max(mx, sz[v]);
//        }   
//        mx = max(mx, s - sz[u]);
//        if(mx < ms) ms = mx, root = u;
//    };
//    getroot(getroot, u, 0);

//    calc(root);
//    del[root] = 1;
//    for(auto v : g[root]) if(!del[v]){
//        dfs(v, sz[v]);
//    }
//}   


//void solve(){
//	cin >> n;
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	dfs(1, n);

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


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	if(k < n-1){
//		cout << "-1\n";
//		return;
//	}
//	vector<array<int,2>>ans;
//	vector<int>fa(n+5);
//	iota(all(fa), 0);

//	auto find = [&](auto self, int x) -> int {
//		return x == fa[x] ? x : fa[x] = self(self, fa[x]);
//	};
//	auto merg = [&](int a, int b) -> void {
//		a = find(find, a);
//		b = find(find, b);
//		fa[a] = b;
//	};

//	k -= n-1;
//	for(int i = n/2;i >= 1;i--){
//		for(int j = (n/i)*i;j > i && i-1 <= k;j -= i){
//			if(find(find, i) != find(find, j)) {
//				k -= i-1;
//				merg(i, j);
//				ans.push_back({i, j});
//			}
//		}
//	}

//	if(k > 0) {
//		cout << "-1\n";
//		return;
//	}

//	for(auto [a, b] : ans) cout << a << " " << b << endl;
//}	

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--){
//		solve();
//		cout << endl;
//	}

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n+5), b(m+5);
//	map<vector<int>,int>f[2], vis[2];
//	map<int,int>mp;
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= m;i++){
//		cin >> b[i];
//		mp[b[i]]++;
//	}
//	m = mp.size();
//	vector<int>cnt(m+1), val(m+1);
//	int i = 1;
//	for(auto [k, v] : mp){
//		val[i] = k;
//		cnt[i] = v;
//		i++;
//	}

//	queue<pair<vector<int>, int>>que;
//	vector<int>tmp(m+1);
//	for(int i = 1;i <= m;i++){
//		tmp[i]++;
//		que.push({tmp,0});
//		que.push({tmp,1});
//		vis[0][tmp] = vis[1][tmp] = 1;
//		tmp[i]--;
//	}
//	while(que.size()){
//		auto [cur, s] = que.front();
//		que.pop();
//		int len = 0;
//		for(int i = 1;i <= m;i++) len += cur[i]*val[i];
//		int mn = inf;
//		for(int i = 1;i <= m;i++) if(cur[i]){
//			cur[i]--;
//			int r = len, l = len - val[i], d = 0;
//			for(int j = l+1;j <= r;j++) d += (a[j] != s);
//			mn = min(mn, f[s^1][cur]+d);
//			cur[i]++;
//		}
//		f[s][cur] = mn;
//		for(int i = 1;i <= m;i++) if(cur[i]+1 <= cnt[i]){
//			cur[i]++;
//			if(!vis[s][cur]++) que.push({cur, s});
//			if(!vis[s^1][cur]++) que.push({cur, s^1});
//			cur[i]--;
//		}
//	}

//	cout << min(f[0][cnt], f[1][cnt]) << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
//	while(t--){
//		solve();
//	}

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, k;
//	cin >> n;
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	cin >> k;
//	vector<int>a(k+5), bk(n+5), obk;
//	for(int i = 1;i <= k;i++){
//		cin >> a[i];
//		bk[a[i]] = 1;
//	}
//	obk = bk;

//	vector<int>val(n+5), nul(n+5);

//	auto dfs = [&](auto self, int u, int fa) -> int {
//		int pt = val[u];
//		int mx = 0;
//		for(auto v : g[u]) if(v != fa){
//			if(!self(self, v, u)) return 0;
//			if(nul[v] < 0){
//				if(pt || bk[u]) return 0;
//				bk[u] = 1;
//				pt = -nul[v] - 1;
//				continue;
//			}
//			mx = max(mx, nul[v]);
//		}
//		if(pt){
//			if(mx < pt) nul[u] = -pt;
//			else nul[u] = 0;
//		}else{
//			nul[u] = 1+mx;
//		}
//		if(nul[u] > 0 && bk[u]) nul[u] = 0;
//		//cerr << u << ' ' << nul[u] << endl;
//		return 1;
//	};

//	auto check = [&](int x) -> int {
//		bk = obk;
//		val = nul = vector<int>(n+5);
//		int y = x / k;
//		for(int i = 1;i <= k;i++) val[a[i]] = y;
//		int m = x % k;
//		for(int i = 1;i <= m;i++) val[a[i]]++;
//		//for(int i = 1;i <= n;i++){
//		//	cerr << val[i] << ' ' << nul[i] << endl;
//		//}

//		return dfs(dfs, 1, 0) && nul[1] >= 0;
//	};

//	//cerr << check(3) << endl;

//	int l = 0, r = n-k;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(check(mid)) l = mid + 1;
//		else r = mid - 1;
//		//cerr << l << ' ' << r << endl;
//	}
//	cout << r << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--){
//		solve();
//	}

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//using i128 = __int128_t;

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const i128 mod = 212370440130137ll;
//const i128 base = 300009;

//i128 dv(i128 a, i128 b){
//	return (a - b + mod) % mod;
//}


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), b(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1;i < n;i++) {
//		cin >> a[i];
//		b[a[i]]++;
//	}
//	set<int>st;
//	i128 pw = 1, t = 0;
//	for(int i = 0;i < n;i++){
//		st.insert(pw);
//		(t += pw * b[i] % mod) %= mod;
//		(pw *= base) %= mod;
//	}
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	vector<i128>h(n+5);
//	vector<int>ans;
	
//	auto dfs1 = [&](auto self, int u, int fa) -> void {
//		h[u] = 1;
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//			(h[u] += h[v] * base % mod) %= mod;
//		}
//	};

//	auto dfs2 = [&](auto self, int u, int fa) -> void {
//		if(st.count((h[u]-t+mod)%mod)) ans.push_back(u);
//		for(auto v : g[u]) if(v != fa){
//			int tmp = dv(h[u], h[v]*base%mod) * base % mod;
//			(h[v] += tmp) %= mod;
//			self(self, v, u);
//		}
//	};

//	dfs1(dfs1, 1, 0);
//	dfs2(dfs2, 1, 0);

//	sort(all(ans));
//	cout << ans.size() << endl;
//	for(auto e : ans) cout << e << ' ';
//}

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
//	while(t--){
//		solve();
//	}

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, a, b;
//	cin >> n >> a >> b;
//	vector<int>af, bf, fac;
//	for(int i = 1;i*i <= a;i++) if(a % i == 0){
//		af.push_back(i);
//		af.push_back(a/i);
//	}
//	for(int i = 1;i*i <= b;i++) if(b % i == 0){
//		bf.push_back(i);
//		bf.push_back(b/i);
//	}

//	for(int i = 0;i < af.size();i++){
//		for(int j = 0;j < bf.size();j++){
//			fac.push_back(af[i] * bf[j]);
//		}
//	}
//	sort(all(fac));
//	fac.erase(unique(all(fac)), fac.end());

//	int ans = 0, cnt = 0;
//	for(auto e : fac){
//		if(e <= n){
//			cnt++;
//			ans ^= 1;
//			continue;
//		}
//		int f = 0;
//		int p = lower_bound(all(fac), e/n) - fac.begin();
//		for(int i = p;fac[i] <= n;i++)if(e % fac[i] == 0 && e/fac[i] <= n){
//			f = fac[i];
//			break;
//		}
//		if(f) cnt++;
//		ans ^= f;
//	}

//	cout << cnt << ' ' << ans << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--){
//		solve();
//	}

//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//#define int long long

//signed main()
//{
//    int n, L, R, ans = 0;
//    cin >> n;
//    for (L = 1; L <= n; L = R + 1)
//    {
//        R = n / (n / L);
//        ans += (n / L) * (R - L + 1);
//        cout << L << '~' << R << ':' << n / L << '\n';
//    }
//    cout << ans;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int l, r;
//	cin >> l >> r;
//	int ans = max(0ll, (r/2) - l + 1);

//	int L, R, n = l-1;
//	for(L = 1;L <= n;L = R+1){
//		int m = n / L;
//		R = n / m;
//		if(R * (m+2) <= r) {
//			ans += R - L + 1;
//			continue;
//		}
//		int k = min(R, r/(m+2));
//		ans += max(0ll, k - L + 1);
//	}

//	cout << ans << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--){
//		solve();
//	}

//	return 0;
//}




#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin()+1, (x).begin()+1+n

int n, ret, rt;
void pt(vector<int>& a){
	for(int i = 1;i <= n;i++) cout << a[i];
}
void query(vector<int>& a){
	cout << "? ";
	pt(a);
	cout << endl;
}

void solve(){
	cin >> n;
	vector<int>bd(n+5), gd(n+5), nul(n+5), f(n+5);
	for(int i = 1;i <= n;i++){
		auto s = vector<int>(n+5, 1);
		s[i] = 0;
		query(s);
		cin >> ret;
		if(ret == n-1){
			gd[i] = 1;
		}else if(ret == 0){
			bd[i] = 1;
		}else{
			rt = i;
			break;
		}
	}

	for(int i = 1;i <= n;i++) if(i != rt){
		if(bd[i]){
			f[i] = 1;
			continue;
		}else if(gd[i]){
			f[i] = 0;
			continue;
		}
		auto s = nul;
		s[i] = 1;
		query(s);
		cin >> ret;
		f[i] = ret;
	}
}

signed main(){

	IO;
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
