//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	cout << min(2ll, n) << ' ' << min(2ll, m) << '\n';
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), b(n+5);
//	for(int i = 1;i <= n;i++) cin >> b[i];
//	for(int i = 1;i <= n;i++){
//		a[i] = a[i-1] + b[i];
//		if(b[i] && a[i-1] - b[i] >= 0){
//			cout << "-1\n";
//			return;
//		}
//	}
//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//	cout << '\n';
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


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<vector<int>>g(n+5);
//	for(int i = 2, p;i <= n;i++){
//		cin >> p;
//		g[p].push_back(i);
//	}

//	auto check = [&](int d) -> int {
//		vector<int>len(n+5);
//		int cnt = 0;
//		auto dfs = [&](auto self, int u, int fa) -> void {
//			len[u] = 1;
//			for(auto v : g[u]){
//				self(self, v, u);
//				if(len[v] == d && u != 1){
//					len[v] = 0;
//					cnt++;
//				}else{
//					len[u] = max(len[u], len[v]+1);
//				}
//			}
//		};
//		dfs(dfs, 1, 0);
//		return cnt <= k;
//	};

//	int l = 1, r = n-1;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(check(mid)) r = mid-1;
//		else l = mid+1;
//	}
//	cout << l << '\n';

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

//const int mod = 998244353;
//const int N = 63;
//int fac[N], inv[N];
//int qpow(int a, int b){
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}
//void init(){
//	fac[0] = inv[0] = 1;
//	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//	inv[N-1] = qpow(fac[N-1], mod-2);
//	for(int i = N-2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
//}
//int C(int a, int b){
//	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
//}

//void solve(){
//	int n;
//	cin >> n;
//	int a = 0, b = C(n, n/2), c = 1;
//	//for(int i = 1;i*2 <= n;i++){
//	//	int s = n/2 - i-1;
//	//	if(s > 0) (a += C(n-i*2, s)) %= mod;
//	//	if(i & 1){
//	//		s = n/2 - i;
//	//		(a += C(n-i*2, s)) %= mod;
//	//	}
//	//}
//	for(int i=1;i<=n/2;i++) {
//		if(i&1) a=(a+C(n-2*i+1,n/2-i))%mod;
//		else a=(a+C(n-2*i,n/2-i-1))%mod;
//		//cerr<<a<<endl;
//	}
//	b -= a + c;
//	while(b < 0) b += mod;
//	cout << a << ' ' << b << ' ' << c << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	init();
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	int mx = 1;
//	for(int i = 1;i <= n;i++) {
//		cin >> a[i];
//		if(a[i] > a[mx]) mx = i;
//	}
//	cout << mx << '\n';
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	int p = 1;
//	for(int i = n-2;i >= 1;i--) a[p++] = i;
//	a[p++] = n-1;
//	a[p++] = n;
//	if(n&1){
//		swap(a[n-3], a[n-4]);
//	}
//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//	cout << '\n';
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

//int f(int x){
//	int ret = 0;
//	while(x){
//		ret++;
//		x /= 10;
//	}
//	return ret;
//}

//void solve(){
//	int n;
//	cin >> n;
//	map<int,int>ma, mb;
//	for(int i = 1;i <= n;i++){
//		int x;
//		cin >> x;
//		ma[x]++;
//	}
//	for(int i = 1;i <= n;i++){
//		int x;
//		cin >> x;
//		if(ma.count(x) && ma[x] > 0) ma[x]--;
//		else mb[x]++;
//	}

//	int ans = 0;
//	vector<int>ca(10), cb(10);
//	for(auto [k, v] : ma) {
//		if(k > 9){
//			ans += v;
//			ca[f(k)] += v;
//		}else{
//			ca[k] += v;
//		}
//	}
//	for(auto [k, v] : mb) {
//		if(k > 9){
//			ans += v;
//			cb[f(k)] += v;
//		}else{
//			cb[k] += v;
//		}
//	}
//	//cerr << ans << '\n';

//	for(int i = 2;i <= 9;i++){
//		ans += abs(ca[i] - cb[i]);
//		//cerr << ca[i] << ' ' << cb[i] << '\n';
//	}

//	cout << ans << '\n';
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

//const int inf = 1e15;

//int exgcd(int a, int b, int &x, int &y){
//	if(b == 0){
//		x = 1, y = 0;
//		return a;
//	}
//	int x0, y0;
//	int d = exgcd(b, a%b, x0, y0);
//	x = y0;
//	y = x0 - (a/b)*y0;
//	return d;
//}

//void solve(){
//	int n, m;
//	cin >> n;
//	vector<int>a(n+5), b(n+5), c(n+5);
//	int sum = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i] >> b[i];
//		sum += a[i];
//		c[i] = b[i] - a[i];
//	}
//	sort(c.begin()+1, c.begin()+1+n, greater<int>());
//	for(int i = 1;i <= n;i++) c[i] += c[i-1];

//	cin >> m;
//	while(m--){
//		int x, y;
//		cin >> x >> y;
//		if(n % gcd(x, y)) {
//			cout << "-1\n";
//			continue;
//		}
//		int p1, p2;
//		int gc = exgcd(x, y, p1, p2);
//		p1 *= n/gc;
//		p2 *= n/gc;
//		int d1 = y/gc, d2 = x/gc;

//		int k = 0;
//		if(p2 < 0){
//			k = -(0-p2 + d2-1)/d2;
//		}else{
//			k = p2/d2;
//		}

//		p1 += d1*k;
//		p2 -= d2*k;
//		if(p1 < 0){
//			cout << "-1\n";
//			continue;
//		}

//		k = p1/d1;
//		int l = 0, r = k;
//		while(r-l > 2){
//			int mid = l + r >> 1;
//			int i1 = (mid*d2+p2)*y, i2 = ((mid+1)*d2+p2)*y;
//			if(c[i2] > c[i1]) l = mid+1;
//			else r = mid;
//		}
//		int ans = -inf;
//		for(int i = l;i <= r;i++){
//			ans = max(ans, c[(p2+i*d2)*y]);
//		}

//		cout << sum + ans << '\n';
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


//void solve(){
//	int n;
//	cin >> n;
//	int ans = (n+2)/3;
//	if(n == 1) ans = 2;
//	cout << ans << '\n';
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	iota(a.begin(), a.end(), 0);
//	cout << n << '\n';
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++) cout << a[j] << ' ';
//		cout << '\n';
//		swap(a[i], a[i+1]);
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

//const int inf = 1e15;

//void solve(){
//	int n;
//	cin >> n;
//	vector<vector<int>>a(3, vector<int>(n+5)), smx(3, vector<int>(n+5, -inf)), rsmx(3, vector<int>(n+5, -inf));
//	for(int i = 1;i <= 2;i++){
//		for(int j = 1;j <= n;j++){
//			cin >> a[i][j];
//			smx[i][j] = a[i][j] - j;
//			rsmx[i][j] = a[i][j] - (n-j+1) - n;
//		}
//		for(int j = n;j >= 1;j--) {
//			smx[i][j] = max(smx[i][j], smx[i][j+1]);
//			rsmx[i][j] = max(rsmx[i][j], rsmx[i][j+1]);
//		}
//	}

//	vector<int>f(n+5);
//	f[1] = max(1ll, a[2][1]+1);
//	for(int i = 2;i <= n;i++){
//		if(i & 1){
//			f[i] = max({f[i-1]+2, a[1][i]+2, a[2][i]+1});
//		}else{
//			f[i] = max({f[i-1]+2, a[2][i]+2, a[1][i]+1});
//		}
//	}
//	int ans = 2*n-1 + max({smx[1][2]+2, rsmx[2][1]+2, 0ll});
//	for(int i = 1;i <= n;i++){
//		int tmp = f[i];
//		int d;
//		if(i&1) d = max({smx[2][i+1]+i+1 - f[i], rsmx[1][i+1]+i+1 - f[i], 0ll});
//		else d = max({smx[1][i+1]+i+1 - f[i], rsmx[2][i+1]+i+1 - f[i], 0ll});
//		tmp += (n-i)*2 + d;
//		ans = min(ans, tmp);
//	}
//	cout << ans << '\n';
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

//const int mod = 998244353;

//void solve(){
//	int n, k, m = 0;
//	cin >> n >> k;
//	for(int i = k, d = k;d <= n;++i, d += i) m++;

//	vector<vector<int>>pre(m+2);
//	for(int i = 0;i <= m;i++){
//		int d = i+k;
//		pre[i].resize(d+2);
//	}
//	pre[0][0] = 1;
//	for(int i = 1;i <= n;i++){
//		int sum = 0;

//		int l = 0, r = m;
//		while(l <= r){
//			int mid = l + r >> 1;
//			if(i >= k*(mid+1) + (mid*(mid+1))/2) l = mid+1;
//			else r = mid-1;
//		}

//		for(int j = r;j >= 0;j--){
//			(sum += pre[j][i % (j+k)]) %= mod;
//			if(j < m) (pre[j+1][i % (k+j+1)] += pre[j][i % (j+k)]) %= mod;
//		}
//		cout << sum << ' ';
//	}
//	cout << '\n';
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


//void solve(){
//	int n;
//	cin >> n;
//	map<int,int>mp;
//	int mx = 0;
//	for(int i = 1;i <= n;i++){
//		int x;
//		cin >> x;
//		mp[x]++;
//		mx = max(mx, mp[x]);
//	}
//	cout << n-mx << '\n';
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i < n;i++) if(a[i]-a[i+1] == 1) swap(a[i], a[i+1]);
//	for(int i = 1;i <= n;i++) if(a[i] != i) {
//		cout << "NO\n";
//		return;
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>pre(n+5, -1);
//	pre[0] = 0;
//	for(int i = 1;i <= n;i++){
//		for(int j = 2;2*j*j <= i;j++) if(pre[i-2*j*j] != -1) {
//			pre[i] = i-2*j*j;
//			break;
//		}
//		cerr << pre[i] << ' ';
//	}
//	cerr << '\n';
//	if(pre[n] == -1) {
//		cout << "-1\n";
//		return;
//	}


//	int tot = 1;
//	vector<int>a(n+5);
//	int p = n;
//	while(p){
//		int d = (p - pre[p]) / 2;
//		for(int i = p;i-d > pre[p];i--) a[i] = a[i-d] = tot++;
//		p = pre[p];
//	}

//	//for(int i = 1;i <= n;i++){
//	//	cerr << pre[i] << ' ';
//	//}
//	//cerr << '\n';

//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//	cout << '\n';
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
//#define ls id << 1
//#define rs id << 1 | 1


//struct Tree{
//	vector<int>mx;
//	int n;
//	Tree(int _n) : n(_n), mx(_n*4+5) {}
//	void up(int id){
//		mx[id] = max(mx[ls], mx[rs]);
//	}
//	void modify(int id, int l, int r, int x, int v){
//		if(l == r){
//			mx[id] = max(mx[id], v);
//			return;
//		}
//		int mid = l + r >> 1;
//		if(x <= mid) modify(ls, l, mid, x, v);
//		else modify(rs, mid + 1, r, x, v);
//		up(id);
//	}
//	int query(int id, int l, int r, int ql, int qr){
//		if(ql <= l && r <= qr) return mx[id];
//		int mid = l + r >> 1;
//		if(qr <= mid) return query(ls, l, mid, ql, qr);
//		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//		else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//	}
//	void modify(int x, int v){
//		modify(1, 1, n, x, v);
//	}
//	int query(int l, int r){
//		if(l > r) return 0;
//		return query(1, 1, n, l, r);
//	}
//};


//void solve(){
//	int n;
//	cin >> n;
//	Tree tr(n);
//	vector<int>a(n+5), pmx(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		if(a[i] >= a[pmx[i-1]]) pmx[i] = i;
//		else pmx[i] = pmx[i-1];
//		//cerr << pmx[i] << ' ';
//	}
//	//cerr << '\n';

//	for(int i = n;i >= 1;i--){
//		if(pmx[i] == i){
//			int r = tr.query(1, a[i]-1);
//			if(a[pmx[r]] > a[i]) g[i].push_back(pmx[r]);
//		}else{
//			g[i].push_back(pmx[i]);
//		}
//		tr.modify(a[i], i);
//	}

//	vector<int>ans(n+5);
//	auto f = [&](auto self, int i) -> int {
//		if(ans[i]) return ans[i];
//		ans[i] = a[i];
//		for(auto v : g[i]){
//			ans[i] = max(ans[i], self(self, v));
//		}
//		return ans[i];
//	};

//	for(int i = 1;i <= n;i++) cout << f(f, i) << ' ';
//	cout << '\n';
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
//#define ls id << 1
//#define rs id << 1 | 1


//void solve(){
//	int n;
//	cin >> n;
//	vector<vector<int>>g(n+5);
//	for(int i = 2, p;i <= n;i++){
//		cin >> p;
//		g[p].push_back(i);
//	}

//	vector<int>f(n+5);
//	auto dfs = [&](auto self, int u) -> void {
//		priority_queue<int, vector<int>, greater<int>>que;
//		for(auto v : g[u]) {
//			self(self, v);
//			que.push(f[v]);
//		}
//		if(que.size() < 2) que.push(0);
//		while(que.size() > 1){
//			int u = que.top();
//			que.pop();
//			int v = que.top();
//			que.pop();
//			que.push(v+1);
//		}
//		f[u] = que.top();
//	};
//	dfs(dfs, 1);

//	//for(int i = 1;i <= n;i++) cerr << f[i] << ' ';

//	cout << f[1] << '\n';
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>pre(n+5, -1);
//	pre[0] = 0;
//	for(int i = 1;i <= n;i++){
//		for(int j = 2;2*j*j <= i;j++) if(pre[i-2*j*j] != -1) {
//			pre[i] = i-2*j*j;
//			break;
//		}
//		cerr << pre[i] << ' ';
//	}
//	cerr << '\n';
//	if(pre[n] == -1) {
//		cout << "-1\n";
//		return;
//	}


//	int tot = 1;
//	vector<int>a(n+5);
//	int p = n;
//	while(p){
//		int d = (p - pre[p]) / 2;
//		for(int i = p;i-d > pre[p];i--) a[i] = a[i-d] = tot++;
//		p = pre[p];
//	}

//	//for(int i = 1;i <= n;i++){
//	//	cerr << pre[i] << ' ';
//	//}
//	//cerr << '\n';

//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//	cout << '\n';
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	if(n%2 == 1 && n < 27){
//		cout << -1 << '\n';
//		return;
//	}

//	int tot = 0;
//	if(n&1){
//		a[1] = a[17] = a[26] = ++tot;
//		a[2] = a[27] = ++tot;
//	}

//	for(int i = 1;i <= n;){
//		if(a[i]) i++;
//		else{
//			a[i] = a[i+1] = ++tot;
//			i += 2;
//		}
//	}

//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//	cout << '\n';
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), pre(n+5);
//	int mx = 1;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pre[i] = pre[i-1] + a[i];
//		if(a[i] < a[mx]) mx = i;
//	}

//	double ans = 0;
//	for(int i = mx-1;i >= 1;i--){
//		ans = max(ans, (1.0 * pre[mx+1] - pre[i-1]) / (mx+1-(i-1)));
//		ans = max(ans, (1.0 * pre[n] - pre[i-1]) / (n-(i-1)));
//	}	
//	for(int i = mx+1;i <= n;i++){
//		ans = max(ans, (1.0 * pre[i] - pre[mx-2]) / (i-(mx-2)));
//		ans = max(ans, (1.0 * pre[i]) / i);
//	}

//	cout << fixed << setprecision(20);
//	cout << ans << '\n';
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a;
//	a.push_back(1);
//	for(int i = 0;i < n-1;i++){
//		if((i % 4) <= 1){
//			a.push_back(2);
//			a.push_back(-1);
//		}else{
//			a.push_back(-2);
//			a.push_back(1);
//		}
//	}
//	if(((a.size()-1)/2-1) % 4 <= 1) a.push_back(1);
//	else a.push_back(-1);
//	//a.push_back(1);
//	for(auto e : a) cout << e << ' ';
//	cout << '\n';


//	int s1 = 0;
//	for(int i = 0;i+1 < a.size();i += 2){
//		s1 += a[i] * a[i+1];
//		//cerr << a[i] * a[i+1] << ' ';
//	}
//	//cerr << '\n';
//	int s2 = a.front()*a.back();
//	for(int i = 1;i+1 < a.size();i += 2){
//		s2 *= a[i] + a[i+1];
//		//cerr << a[i]+a[i+1] << ' ';
//	}
//	//cerr << '\n';
//	if(s1 != s2) cerr << n << ' ' << s1 << ' ' << s2 << '\n';
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


//void solve(){
//	int n, ret;
//	cin >> n;

//	auto ask = [&](int u, int v){
//		assert(u != v);
//		cout << "? " << u << ' ' << v << endl;
//		cout.flush();
//		cin >> ret;
//	};
//	auto ans = [&](int i){
//		cout << "! " << i << endl;
//		cout.flush();
//	};

//	set<int>st;
//	for(int i = 1;i <= n;i++) st.insert(i);
//	for(int i = 1;i <= n;i += 2){
//		if(i == n){
//			int tmp = 0;
//			for(int j = 1;j <= 3;j++) {
//				ask(j, n);
//				tmp += ret;
//			}
//			if(tmp == 3) ans(2);
//			else ans(1);

//			return;
//		}
//		ask(i, i+1);
//		if(ret){
//			st.erase(i);
//			st.erase(i+1);
			
//			int u = 0;
//			ask(*st.begin(), i);
//			if(ret){
//				u = i;
//				st.erase(st.begin());
//			}
//			if(u == 0){
//				ask(*st.begin(), i+1);
//				if(ret){
//					u = i+1;
//					st.erase(st.begin());
//				}
//			}
			
//			if(u){
//				ask(*st.begin(), u);
//				if(!ret) u = 0;
//			}
//			if(u) ans(2);
//			else ans(1);

//			return;
//		}
//	}
//	ans(1);
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

//const int mod = 1e9 + 7;
//const int N = 5e5 + 10;
//int fac[N], inv[N];
//int qpow(int a, int b){
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}
//void init(){
//	fac[0] = inv[0] = 1;
//	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//	inv[N-1] = qpow(fac[N-1], mod-2);
//	for(int i = N-2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
//}
//int C(int a, int b){
//	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
//}
//int A(int a, int b){
//	return fac[a] * inv[a-b] % mod;
//}
//int jian(int a, int b){
//	a -= b;
//	while(a < 0) a += mod;
//	return a;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), b(n+5), w(n+5), g(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++) cin >> b[i];
//	for(int i = 1;i <= n;i++) cin >> w[i];

//	for(int i = 1;i <= n;i++){
//		if(a[i] < a[b[i]]){
//			g[i] = 0;
//		}else if(a[i] < a[b[i]] + w[b[i]]){
//			g[i] = b[i];
//		}else g[i] = n+1;
//		//cerr << g[i] << ' ';
//	}
//	//cerr << "\n";

//	vector<vector<int>>e(n+5);
//	for(int i = 1;i <= n;i++) e[g[i]].push_back(i);

//	vector<int>dep(n+5);
//	auto dfs = [&](auto self, int u, int fa) -> void {
//		dep[u] = dep[fa] + 1;
//		for(auto v : e[u]){
//			self(self, v, u);
//		}
//	};
//	dep[0] = -1;
//	dfs(dfs, 0, 0);

//	for(int i = 1;i <= n;i++){
//		//cerr << dep[i] << ' ';
//		int p;
//		if(dep[i]) p = A(n, n-dep[i]) * inv[n] % mod;
//		else p = 0;
//		(a[i] += w[i] * p % mod) %= mod;
//		cout << a[i] << ' ';
//	}
//	cout << '\n';
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	init();
//	//cerr << A(4, 3) << '\n';
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//const int mxn = 250000;

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	vector<int>x(n+5), c(n+5), id(mxn+5), ne(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> x[i] >> c[i];
//		id[x[i]] = i;
//	}

//	int ls = 0;
//	for(int i = mxn;i >= 1;i--) if(id[i]) {
//		if(!ls){
//			ne[id[i]] = mxn+1;
//		}else{
//			ne[id[i]] = ls-i;
//			if(c[id[ls]] == c[id[i]]) ne[id[i]] += ne[id[ls]];
//		}
//		ls = i;
//	}

//	for(int i = 1;i <= n;i++) cerr << ne[i] << ' ';
//	cerr << '\n';

//	vector<int>pmn(mxn+5);
//	for(int i = n;i >= 1;i--) pmn[ne[i]] = i;

//	while(q--){
//		int d;
//		cin >> d;
//		cout << pmn[d] << '\n';
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(2*n+5);
//	for(int i = 2;i < 2*n;i += 2) {
//		a[i] = 2;
//		a[i+1] = -1;
//	}
//	a[2*n] = 1;
//	for(int i = 3;i <= 2*n;i += 2) a[1] -= a[i] * a[i+1];
//	for(int i = 1;i <= 2*n;i++) cout << a[i] << ' ';
//	cout << '\n';

//	//int s1 = 0;
//	//for(int i = 1;i+1 <= 2*n;i += 2) s1 += a[i] * a[i+1];
//	//int s2 = a[1] * a[n*2];
//	//for(int i = 2;i+1 <= 2*n;i += 2) s2 *= a[i] + a[i+1];
//	//if(s1 != s2) cerr << s1 << ' ' << s2 << '\n';
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


//void solve(){
//	string s;
//	cin >> s;
//	s.push_back(' ');
//	char ls = ' ';
//	int len = 0;
//	for(auto c : s){
//		if(c == ls){
//			len++;
//		}else{
//			if(len == 1){
//				cout << "NO\n";
//				return;
//			}
//			len = 1;
//			ls = c;
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	int d = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		if(i > 1) d += a[i] - a[i-1] - 1;
//	}
//	if(d > 2) cout << "NO\n";
//	else cout << "YES\n";
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, x;
//	cin >> n >> x;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(all1(a));
//	for(int i = 1;i <= n;i++) a[i] += a[i-1];

//	int d = 0, s = 0;
//	for(int i = n;i >= 1;i--){
//		int l = 1, r = x;
//		while(l <= r){
//			int mid = l + r >> 1;
//			if(x >= a[i] + (d+mid-1)*i) l = mid+1;
//			else r = mid-1;
//		}
//		s += i * r;
//		d += r;
//	}	
//	cout << s << '\n';
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, mx = 0, mn = 1e9, x;
//	cin >> n >> x;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		mx = max(mx, a[i]);
//		mn = min(mn, a[i]);
//	}
//	int s = 0;
//	for(int i = 2;i <= n;i++) s += abs(a[i] - a[i-1]);

//	s += min({a[1]-1, a[n]-1, (mn-1)*2});
//	if(x > mx) s += min({x-a[1], x-a[n], (x-mx)*2});

//	cout << s << '\n';
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls (id << 1)
//#define rs (id << 1 | 1)

//const int mod = 998244353;
//mt19937_64 rnd(time(0));

//void solve(){
//	int n, m;
//	cin >> n;
//	m = (1<<n)-1;
//	int val[2] = {rnd()%mod, rnd()%mod};

//	string a;
//	cin >> a;
//	a = ' ' + a;

//	vector<int>h(m+5), f(m+5);
//	auto dfs = [&](auto self, int id) -> void {
//		if(ls > m){
//			f[id] = 1;
//			h[id] = val[a[id]-'A'];
//			(h[id] *= h[id]) %= mod;
//			return;
//		}
//		self(self, ls);
//		self(self, rs);
//		f[id] = f[ls] * f[rs] % mod;
//		if(h[ls] != h[rs]) (f[id] *= 2) %= mod;
//		h[id] = ((h[ls] * h[rs] % mod) + val[a[id]-'A']) % mod;
//		(h[id] *= h[id]) %= mod;
//	};

//	dfs(dfs, 1);

//	cout << f[1] << '\n';
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	cout << "1 1 2 3 5";
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n;
//	cin >> n;
//	vector<vector<int>>a(n+5, vector<int>(n+5));
//	int x = 1, y = 1, tx, ty;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			cin >> a[i][j];
//			if(a[i][j] == -1){
//				tx = i;
//				ty = j;
//				continue;
//			}
//			if(a[i][j] < a[x][y] || a[x][y] == -1) x = i, y = j;
//		}
//	}
//	int mn = a[x][y];
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			a[i][j] -= mn;
//		}
//	}

//	vector<int>r(n+5), c(n+5);
//	if(x == tx){
//		for(int i = 1;i <= n;i++) r[i] = a[i][y];
//		int row = 1;
//		if(row == tx) row++;
//		for(int i = 1;i <= n;i++) c[i] = a[row][i] - r[row];
//	}else{
//		for(int i = 1;i <= n;i++) c[i] = a[x][i];
//		int clo = 1;
//		if(clo == ty) clo++;
//		for(int i = 1;i <= n;i++) r[i] = a[i][clo] - c[clo];
//	}

//	cout << r[tx] + c[ty] + mn;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1


//struct Tree{
//	vector<int>mx, tag;
//	int n;
//	Tree(int _n) : n(_n), mx(_n*4+5), tag(_n*4+5) {}
//	void settag(int id, int x){
//		tag[id] += x;
//		mx[id] += x;
//	}
//	void down(int id){
//		settag(ls, tag[id]);
//		settag(rs, tag[id]);
//		tag[id] = 0;
//	}
//	void up(int id){
//		mx[id] = max(mx[ls], mx[rs]);
//	}
//	void add(int id, int l, int r, int ql, int qr){
//		if(ql <= l && r <= qr) {
//			settag(id, 1);
//			return;
//		}
//		if(tag[id]) down(id);
//		int mid = l + r >> 1;
//		if(qr <= mid) add(ls, l, mid, ql, qr);
//		else if(ql > mid) add(rs, mid + 1, r, ql, qr);
//		else add(ls, l, mid, ql, qr), add(rs, mid + 1, r, ql, qr);
//		up(id);
//	}
//	int query(int id, int l, int r, int ql, int qr){
//		if(ql <= l && r <= qr) return mx[id];
//		if(tag[id]) down(id);
//		int mid = l + r >> 1;
//		if(qr <= mid) return query(ls, l, mid, ql, qr);
//		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//		else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//	}
//	void add(int l, int r){
//		add(1, 1, n, l, r);
//	}
//	int query(int l, int r){
//		return query(1, 1, n, l, r);
//	}
//};

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	vector<Tree>tr(4, Tree(n));
//	vector<int>id(10);
//	id[2] = 0, id[3] = 1, id[5] = 2, id[7] = 3;

//	string op;
//	int l, r, x;
//	int pre = 0;
//	while(q--){
//		cin >> op >> l >> r;
//		if(op[1] == 'U'){
//			cin >> x;
//			for(int i = 2;i <= x;i++){
//				while(x % i == 0){
//					tr[id[i]].add(l, r);
//					x /= i;
//				}
//			}
//		}else{
//			int mx = 0;
//			for(int i = 0;i < 4;i++) mx = max(mx, tr[i].query(l, r));
//			if(pre) cout << '\n';
//			cout << "ANSWER " << mx;
//			pre = 1;
//			//cout << "ANSWER " << mx << '\n';
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//const int mod = 998244353;
//const int mxn = 1e6;
//int ps[mxn+5];

//int qpow(int a, int b){
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}
//const int rv2 = qpow(2, mod-2);

//void init(){
//	for(int i = 1;i <= mxn;i++){
//		ps[i] = (ps[i-1] + (i*i % mod)) % mod;
//	}
//}
//int getS(int a1, int an, int n){
//	a1 %= mod;
//	an %= mod;
//	n %= mod;
//	return (n*((a1+an)%mod)%mod)*rv2%mod;
//}
//int geti2(int l, int r){
//	int s = 0;
//	while(l <= r){
//		int p = min(r, l+mxn);
//		int n = p-l+1;
//		(s += ((l%mod)*(l%mod)%mod) * n % mod) %= mod;
//		int a1 = 0, an = ((n-1)*2*(l%mod)) % mod;
//		(s += getS(a1, an, n)) %= mod;
//		(s += ps[n-1]) %= mod;
//		l = p+1;
//	}
//	return s;
//}
//int getfs(int l, int r){
//	int c = 1, x = l, s = 0;
//	while(l <= r){
//		int p = min(r, l*x-1);
//		(s += (p-l+1)*c%mod) %= mod;
//		l = p+1;
//		c++;
//	}
//	return s;
//}

//int jian(int a, int b){
//	a -= b;
//	while(a < 0) a += mod;
//	return a;
//}

//void solve(){
//	int n;
//	cin >> n;
//	int s = 0;

//	for(int i = 2;;i++){
//		if(i*i > n){
//			int a1, an;
//			int m = n-i+1;

//			//ni
//			a1 = (n%mod)*i%mod, an = (n%mod)*(n%mod)%mod;
//			(s += getS(a1, an, m)) %= mod;
//			//i
//			a1 = i, an = n%mod;
//			(s += getS(a1, an, m)) %= mod;

//			//-i2
//			s = jian(s, geti2(i, n));

//			//cerr << i << '\n';

//			break;
//		}else{
//			(s += getfs(i, n)*i % mod) %= mod;
//		}	
//	}

//	cout << s << '\n';
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n;
//	cin >> n;
//	vector<array<int,3>>p(n);
//	vector<vector<array<int,2>>>a(3);
//	for(auto &[x, y, z] : p ){
//		cin >> x >> y >> z;
//		a[0].push_back({y, z});
//		a[1].push_back({x, z});
//		a[2].push_back({x, y});
//	}

//	int mx = 0;
//	for(int i = 0;i < 3;i++){
//		sort(all(a[i]));
//		a[i].erase(unique(all(a[i])), a[i].end());
//		if(a[i].size() > a[mx].size()) mx = i;
//	}
//	cout << (char)(mx+'X') << '\n';
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

////n s w e
//int op[4][2] = {
//	-1, 0,
//	1, 0,
//	0, -1,
//	0, 1
//};

//void solve(){
//	int n, m;
//	cin >> n;
//	m = n*n;
//	vector<vector<int>>g(m+5, vector<int>(4));
//	int st;
//	for(int i = 1;i <= m;i++){
//		for(int j = 0;j < 4;j++) cin >> g[i][j];
//		if(g[i][0] == -1 && g[i][2] == -1) st = i;
//	}

//	vector<vector<int>>mp(n+5, vector<int>(n+5));

//	queue<array<int,2>>que;
//	mp[1][1] = st;
//	que.push({1, 1});
//	while(que.size()){
//		auto [x, y] = que.front();
//		que.pop();
//		for(int i = 0;i < 4;i++){
//			int nx = x + op[i][0];
//			int ny = y + op[i][1];
//			if(mp[nx][ny] || g[mp[x][y]][i] == -1) continue;
//			mp[nx][ny] = g[mp[x][y]][i];
//			que.push({nx, ny});
//		}
//	}

//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			cout << mp[i][j];
//			if(j < n) cout << ' ';
//		}
//		if(i < n) cout << '\n';
//	}
//}		

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin()+1, (x).begin()+1+n



void solve(){
	
}		

signed main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) solve();

	return 0;
}