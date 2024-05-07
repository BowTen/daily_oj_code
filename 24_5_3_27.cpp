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