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


//void solve(){
//	int l, r;
//	cin >> l >> r;
//	int ans = 0;
//	while(r > 1){
//		ans++;
//		r >>= 1;
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


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	int l = max(0ll, n-m), r = n+m;
//	int x = r;
//	int f = 0;
//	for(int i = 40;i >= 0;i--) if((r>>i)&1 && !((l>>i)&1)){
//		x |= (1ll<<(i+1))-1;
//		break;
//	}
//	cout << x << endl;
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
////#define ls id << 1
////#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 10;
//const int mxn = 1000000000;

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	int ls = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		if(a[i] != -1 && !ls) ls = i;
//	}

//	if(!ls){
//		for(int i = 1;i <= n;i++){
//			if(i&1) cout << 1 << ' ';
//			else cout << 2 << ' ';
//		}
//		cout << endl;
//		return;
//	}

//	for(int i = ls-1;i >= 1;i--) {
//		if(a[i+1]/2) a[i] = a[i+1]/2;
//		else a[i] = a[i+1]*2;
//	}

//	for(int i = ls+1;i <= n;i++) if(a[i] != -1){
//		int l = ls, r = i;
//		while(r-l > 1 && a[l] != a[r]){
//			int x = min(a[l], a[r]), y = max(a[l], a[r]);
//			if(y/2 == x){
//				if(a[l] == x){
//					a[++l] = y;
//				}else{
//					a[--r] = y;
//				}
//				break;
//			}
//			if(a[l] > a[r]){
//				if(a[l] == 1) a[l+1] = 2;
//				else a[l+1] = a[l]/2;
//				l++;
//			}else{
//				if(a[r] == 1) a[r-1] = 2;
//				else a[r-1] = a[r]/2;
//				r--;
//			}
//		}
//		for(int j = l+1;j < r;j++){
//			a[j] = a[j-1];
//			if(a[j] >= a[r] && a[j]/2) a[j] /= 2;
//			else{
//				a[j] *= 2;
//				if(a[j] < a[r]) a[j]++;
//			}
//		}

//		ls = i;
//	}

//	for(int i = ls+1;i <= n;i++) {
//		if(a[i-1]/2) a[i] = a[i-1]/2;
//		else a[i] = a[i-1]*2;
//	}

//	for(int i = 1;i < n;i++){
//		int x = max(a[i], a[i+1]);
//		int y = min(a[i], a[i+1]);
//		if(x/2 != y){
//			cout << -1 << endl;
//			return;
//		}
//		//if(a[i] < 1 || a[i] > mxn) {while(1){;}}
//	}
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;

//class Tree {
//	vector<int>c, s, tag, fg;
//	vector<int>&f;
//public:
//	Tree(int n, vector<int>&f) : c(n*4+5), s(n*4+5), f(f), tag(n*4+5), fg(n*4+5) {
//		build(1, 1, n);
//	}

//	void up(int id){
//		c[id] = c[ls] == c[rs] ? c[ls] : 0;
//	}
//	void build(int id, int l, int r){
//		if(l == r){
//			c[id] = 1;
//			return;
//		}
//		int mid = l + r >> 1;
//		build(ls, l, mid);
//		build(rs, mid + 1, r);
//		up(id);
//	}
//	void settag(int id, int x, int y) {
//		s[id] += x;
//		tag[id] += x;
//		c[id] = y;
//		fg[id] = 1;
//	}
//	void down(int id){
//		settag(ls, tag[id], c[id]);
//		settag(rs, tag[id], c[id]);
//		tag[id] = fg[id] = 0;
//	}
//	void modify(int id, int l, int r, int ql, int qr, int x, int y) {
//		if(ql <= l && r <= qr && c[id]) {
//			int d = f[c[id]];
//			c[id] = x;
//			d -= f[c[id]];
//			settag(id, d, c[id]);
//			return;
//		}
//		if(fg[id]) down(id);
//		int mid = l + r >> 1;
//		if(qr <= mid) modify(ls, l, mid, ql, qr, x, y);
//		else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x, y);
//		else modify(ls, l, mid, ql, qr, x, y), modify(rs, mid + 1, r, ql, qr, x, y);
//		up(id);
//	}
//	int query(int id, int l, int r, int x){
//		if(l == r){
//			return s[id] + f[c[id]];
//		}
//		if(fg[id]) down(id);
//		int mid = l + r >> 1;
//		if(x <= mid) return query(ls, l, mid, x);
//		else return query(rs, mid + 1, r, x);
//		up(id);
//	}
//};

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	vector<int>f(n+5);
//	Tree tr(n, f);
	
//	string s;
//	int l, r, c, x;
//	for(int i = 1;i <= q;i++){
//		cin >> s;
//		if(s[0] == 'C'){
//			cin >> l >> r >> c;
//			tr.modify(1, 1, n, l, r, c, i);
//		}else if(s[0] == 'A'){
//			cin >> c >> x;
//			f[c] += x;
//		}else{
//			cin >> x;
//			cout << tr.query(1, 1, n, x) << endl;
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

//const int inf = 0x3f3f3f3f;

//void prime(int n, vector<vector<array<int,2>>>&g){
//	int sum = 0;
//	vector<array<int,3>>e;
//	vector<int>dis(n+1, inf);
//	priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>>que;
//	que.push({0, 1, 0});
//	while(que.size()){
//		auto [d, u, pre] = que.top();
//		que.pop();
//		if(!dis[u]) continue;
//		dis[u] = 0;
//		if(u != 1) e.push_back({pre, u, d});
//		sum += d;
//		for(auto [v, w] : g[u]) if(w < dis[v]) {
//			dis[v] = w;
//			que.push({w, v, u});
//		}
//	}
//	cout << "Prime:\n";
//	cout << "sum = " << sum << endl;
//	cout << "Edges:\n";
//	for(auto [u, v, w] : e) {
//		cout << char(u+'a'-1) << " ---" << w << "--- " << char(v+'a'-1) << endl;
//	}
//	cout << endl;
//}

//class DSU{
//	vector<int>fa;
//public:
//	DSU(int n) : fa(n+1) {
//		iota(fa.begin(), fa.end(), 0);
//	}
//	int find(int x){
//		return x == fa[x] ? x : fa[x] = find(fa[x]);
//	}
//	void merg(int a, int b){
//		a = find(a);
//		b = find(b);
//		fa[a] = b;
//	}
//};

//void kruskal(int n, vector<array<int,3>>&E){
//	int sum = 0;
//	DSU dsu(n);
//	sort(E.begin(), E.end());
//	vector<array<int,3>>e;

//	for(auto [w, u, v] : E) if(dsu.find(u) != dsu.find(v)) {
//		e.push_back({u, v, w});
//		sum += w;
//		dsu.merg(u, v);
//	}

//	cout << "Kruskal:\n";
//	cout << "sum = " << sum << endl;
//	cout << "Edges:\n";
//	for(auto [u, v, w] : e) {
//		cout << char(u+'a'-1) << " ---" << w << "--- " << char(v+'a'-1) << endl;
//	}
//	cout << endl;
//}

//int main(){

//	int n, m;          //点数和边数
//	cin >> n >> m;
//	vector<vector<array<int,2>>>g(n+1);
//	vector<array<int,3>>E;
//	for(int i = 1, u, v, w;i <= m;i++){
//		cin >> u >> v >> w;
//		E.push_back({w, u, v});
//		g[u].push_back({v, w});
//		g[v].push_back({u, w});
//	}

//	prime(n, g);
//	kruskal(n, E);

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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), pre(n+5), suf(n+5), p(n*2+5);
//	set<int>st;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		if(a[i] != i){
//			pre[i]++;
//			suf[i]++;
//		}
//	}
//	for(int i = 1;i <= n;i++) if(a[i] != i){
//		st.insert(a[i] + a[a[i]]);
//	}
//	for(int i = 1;i <= n;i++) pre[i] += pre[i-1];
//	for(int i = n;i >= 1;i--) suf[i] += suf[i+1];

//	for(int i = 2;i <= n+1;i++) if(!suf[i]){
//		p[i] = i-1;
//	}
//	for(int i = n+2;i <= 2*n;i++) if(!pre[i-n-2]){
//		p[i] = i-1;
//	}

//	if(st.size()==1){
//		p[*st.begin()] = *st.begin();
//	}else if(st.size()==0){
//		cout << n+2*n*n << endl;
//		return;
//	}

//	int ans = 0, l = 0;
//	for(int i = 1;i <= 2*n;i++){
//		l = max(l, p[i]);
//		ans += l;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	for(auto &e : a) cin >> e;
//	if(n == 2){
//		while(a[0] && a[1])
//		for(int i = 0;i < n;i++) a[(i+1)%n] = max(0ll, a[(i+1)%n] - a[i]);
//		vector<int>p;
//		for(int i = 0;i < n;i++) if(a[i]) p.push_back(i);
//		cout << p.size() << endl;
//		for(auto e : p) cout << e + 1 << ' ';
//		cout << endl;
//		return;
//	}

//	auto check = [&]() {
//		for(int i = 0;i < n;i++){
//			if(a[i] && a[(i+1)%n] && a[(i+2)%n]) return true;
//		}
//		return false;
//	};

//	while(check()){
//		for(int i = 0;i < n;i++) a[(i+1)%n] = max(0ll, a[(i+1)%n] - a[i]);
//	}

//	vector<int>p;
//	for(int i = 0;i < n;i++){
//		if(!a[(i-1+n)%n] && a[i]) p.push_back(i);
//	}
//	cout << p.size() << endl;
//	for(auto e : p) cout << e + 1 << ' ';
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
////#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	for(auto &e : a) cin >> e;
//	if(n == 2){
//		while(a[0] && a[1])
//		for(int i = 0;i < n;i++) a[(i+1)%n] = max(0, a[(i+1)%n] - a[i]);
//		vector<int>p;
//		for(int i = 0;i < n;i++) if(a[i]) p.push_back(i);
//		cout << p.size() << endl;
//		for(auto e : p) cout << e + 1 << ' ';
//		cout << endl;
//		return;
//	}

//	int cnt = 2200;
//	while(cnt--){
//		for(int i = 0;i < n;i++) a[(i+1)%n] = max(0, a[(i+1)%n] - a[i]);
//	}

//	//for(int i = 0;i < n;i++) cerr << a[i] << ' ';
//	//cerr << endl;

//	int it = 0;
//	for(int i = 0;i < n;i++) if(!a[i]) {
//		it = i;
//		break;
//	}
//	vector<array<int,2>>seg;
//	int l = -1, s = 0;
//	for(int i = it+1;i != it;i = (i+1)%n){
//		if(a[i]) {
//			s++;
//			if(l == -1) l = i;
//			if(s == 3) seg.push_back({l, i});
//			if(s > 3) while(1);
//		}else{
//			s = 0;
//			l = -1;
//		}
//	}

//	for(auto [l, r] : seg) {
//		//cerr << l << ' ' << r << endl;
//		int mid = (l + 1) % n;
//		int a1 = max(0, a[mid] - a[l]);
//		if(l == n-1) a1 = a[mid];
//		int an = min(a1, a[mid] % a[l]);
//		int x = (a1 - an) / a[l] + 1;
//		a[r] = max(0ll, a[r] - 1ll*x*(1ll*a1+an)/2);
//		a[mid] = 0;
//	}

//	vector<int>p;
//	for(int i = 0;i < n;i++){
//		if(!a[(i-1+n)%n] && a[i]) p.push_back(i);
//	}
//	cout << p.size() << endl;
//	for(auto e : p) cout << e + 1 << ' ';
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;

//const int N = 1e6 + 10;
//int fac[N], inv[N];
//int qpow(int a, int b) {
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}
//void get_inv(){
//	fac[0] = inv[0] = 1;
//	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//	inv[N-1] = qpow(fac[N-1], mod-2);
//	for(int i = N-2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
//}
//int C(int a, int b){
//	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
//}

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n+5), b(n+5), prea(n+5), preb(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		prea[i] = prea[i-1] + a[i];
//	}
//	for(int i = 1;i <= n;i++){
//		cin >> b[i];
//		preb[i] = preb[i-1] + b[i];
//	}
//	int suma = prea[n], sumb = preb[n];

//	vector<int>suf(sumb+5);
//	for(int i = sumb;i >= 0;i--){
//		suf[i] = (suf[i+1] + C(sumb, i)) % mod;
//	}
//	int iv = qpow(qpow(2, sumb), mod-2);

//	while(q--){
//		int l, r;
//		cin >> l >> r;
//		int outa = suma - (prea[r] - prea[l-1]);
//		int outb = sumb - (preb[r] - preb[l-1]);
//		int y = outa + outb - (prea[r] - prea[l-1]);

//		int ans;
//		if(y+1 > sumb) {
//			ans = 0;
//		}else{
//			ans = suf[max(y+1, 0ll)] * iv % mod;
//		}

//		cout << ans << ' ';
//	}

//}

//signed main(){

//	IO;

//	get_inv();

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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;

//const int N = 1e6 + 10;
//bool isprime[N];
//int prime[N], pre[N];
//int cnt, n, k, op;

//void euler(){
//    memset(isprime, true, sizeof(isprime));
//    isprime[1] = false;
//    for(int i = 2;i < N;i++){
//        if(isprime[i]) prime[++cnt] = i;
//        for(int j = 1; j <= cnt && prime[j] * i < N;j++){
//            isprime[prime[j]*i] = false;
//            if(i % prime[j] == 0) break;
//        }
//    }prime[0] = 1;
//	isprime[1] = 1;
//	for(int i = 1;i < N;i++){
//		pre[i] = pre[i-1];
//		if(isprime[i]) pre[i]++;
//	}
//}

//int dfs1(int n, int k) {
//	if(k <= pre[n]) return k == 1 ? 1 : prime[k-1];
//	int x = dfs1(n-pre[n], k-pre[n]);
//	int l = 1, r = n;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(mid - pre[mid] >= x) r = mid - 1;
//		else l = mid + 1;
//	}
//	return l;
//}
//int dfs2(int n, int k) {
//	if(isprime[k]) return pre[k];
//	int x = dfs2(n-pre[n], k-pre[k]);
//	return x + pre[n];
//}

//int d2(int n, int k) {
//	vector<int>v(n);
//	iota(all(v),1);
//	int id = 0;
//	while(1){
//		vector<int>tmp;
//		for(int i = 0;i < v.size();i++) {
//			if(isprime[i+1]){
//				++id;
//				if(k == v[i]) return id;
//			}else{
//				tmp.push_back(v[i]);
//			}
//		}
//		v = tmp;
//	}
//}

//void solve(){
//	cin >> op >> n >> k;
//	if(op == 2) cout << dfs1(n, k) << endl;
//	else cout << dfs2(n, k) << endl;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;



//void solve(){
//	int n;
//	cin >> n;
//	if(n == 1){
//		cout << 1 << endl;
//		return;
//	}
//	cout << 2 << ' ';
//	for(int i = 2;i < n;i++) cout << i+1 << ' ';
//	cout << 1 << endl;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n+5), d(n+5);
//	vector<array<int,2>>E;
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		d[u]++; d[v]++;
//		E.push_back({u, v});
//	}
//	if(m % 2 == 0) {
//		cout << 0 << endl;
//		return;
//	}

//	int ans = inf;
//	for(int i = 1;i <= n;i++) if(d[i] & 1) {
//		ans = min(ans, a[i]);
//	}
//	for(auto [u, v] : E) if(d[u]%2 == 0 && d[v]%2 == 0){
//		ans = min(ans, a[u]+a[v]);
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;


//void solve(){
//	int n, m, k, f = 0;
//	cin >> n >> m >> k;
//	vector<int>a(k+5), c, r;
//	for(int i = 1;i <= k;i++) {
//		cin >> a[i];
//		if(a[i]/n > 1){
//			c.push_back(a[i]/n);
//			if(c.back() >= m) f = 1;
//		}
//		if(a[i]/m > 1){
//			r.push_back(a[i]/m);
//			if(r.back() >= n) f = 1;
//		}
//	}
//	sort(all(c));
//	sort(all(r));
//	if(f){
//		cout << "Yes\n";
//		return;
//	}

//	int s = 0;
//	if(c.size())
//	for(int i = 0;i < c.size()-1;i++){
//		s += c[i];
//		if(s+1 == m) {
//			s--;
//			if(c[i] == 2) s--;
//		}
//		if(s + c.back() >= m) {
//			cout << "Yes\n";
//			return;
//		}
//	}
//	s = 0;
//	if(r.size())
//	for(int i = 0;i < r.size()-1;i++){
//		s += r[i];
//		if(s+1 == n) {
//			s--;
//			if(r[i] == 2) s--;
//		}
//		if(s + r.back() >= n){
//			cout << "Yes\n";
//			return;
//		}
//	}
//	cout << "No\n";

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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	int mn = inf;
//	for(int i = 1;i < n;i++) {
//		mn = min(mn, max(a[i], a[i+1]));
//	}
//	cout << mn - 1 << endl;

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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;

//int lowbit(int x){
//	return x & -x;
//}

//void solve(){
//	int x, y;
//	cin >> x >> y;
//	cout << lowbit(x^y) << endl;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;


//void solve(){
//	int n, m = 1;
//	cin >> n;
//	vector<int>k(n+5), z(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> k[i];
//		m = (m*k[i]) / gcd(m, k[i]);
//	}
//	int sum = 0;
//	for(int i = 1;i <= n;i++){
//		z[i] = m / k[i];
//		sum += z[i];
//	}
//	if(sum >= m){
//		cout << "-1\n";
//		return;
//	}
//	for(int i = 1;i <= n;i++) cout << z[i] << ' ';
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	string s;
//	cin >> s;
//	s = ' ' + s;

//	vector<int>nxt(n+5);
//	int las[2] = {n+1, n+1};
//	for(int i = n;i >= 1;i--){
//		nxt[i] = las[(s[i]-'0')^1];
//		las[s[i]-'0'] = i;
//	}
//	vector<int>seg;
//	for(int i = 1;i <= n;i = nxt[i]){
//		seg.push_back(nxt[i]-i);
//	}

//	if(seg.back() > k){
//		cout << -1 << endl;
//		return;
//	}

//	int tmp = 0, it=0;
//	for(int i = 0;i+1 < seg.size();i++){
//		tmp += (seg[i] != k);
//		if(seg[i] != k) it = i;
//	}

//	if(tmp > 1) {
//		cout << -1 << endl;
//		return;
//	}

//	if(tmp == 0){
//		if(seg.back() == k) cout << n << endl;
//		else cout << -1 << endl;
//		return;
//	}

//	if(seg[it] == 2*k){
//		if(seg.back() == k && (it&1) != ((seg.size()-1)&1)) cout << k*it+k << endl;
//		else cout << -1 << endl;
//		return;
//	}else{
//		if(seg[it] < k){
//			if(seg.back()+seg[it] == k && (it&1) == ((seg.size()-1)&1)) cout << k*it+seg[it] << endl;
//			else cout << -1 << endl;
//		}else{
//			if(seg.back()+seg[it] == 2*k && (it&1) == ((seg.size()-1)&1)) cout << k*it+seg[it]-k << endl;
//			else cout << -1 << endl;
//		}
//		return;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 1e6 + 10;
//int n, q;

//int tr[N];
//int lowbit(int x){
//	return x & -x;
//}
//void add(int x, int v){
//	while(x <= n){
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
//	cin >> n >> q;
//	vector<int>a(n+5), pos(n+5);
//	vector<vector<array<int,2>>>qur(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pos[a[i]] = i;
//	}
//	for(int i = 1, l, r;i <= q;i++){
//		cin >> l >> r;
//		qur[l].push_back({r, i});
//	}

//	vector<int>f(n+5, 0), ans(q+5);
//	for(int i = n;i >= 1;i--){
//		f[a[i]] = 1;
//		for(int j = a[i];j <= n;j += a[i]) if(pos[j] >= i) {
//			for(int k = j*2;k <= n;k += j) if(pos[k] > pos[j]) {
//				f[k] += f[j];
//			}
//		}
//		for(int j = a[i];j <= n;j += a[i]) {
//			add(pos[j], f[j]);
//			f[j] = 0;
//		}
//		for(auto [r, id] : qur[i]) {
//			ans[id] = getsum(r);
//		}
//	}
//	for(int i = 0;i <= n;i++) tr[i] = 0;

//	for(int i = 1;i <= q;i++) cout << ans[i] << ' ';
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;


//void solve(){
//	int n, S;
//	cin >> n >> S;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];

//	auto check = [&](int x) -> int {
//		vector<int>v;
//		for(int i = 1;i <= n;i++) v.push_back(x * i + a[i]);
//		sort(all(v));
//		int tmp = 0;
//		for(int i = 0;i < x;i++) tmp += v[i];
//		return tmp <= S;
//	};

//	int l = 0, r = n;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(check(mid)) l = mid + 1;
//		else r = mid - 1;
//	}

//	int k = r, s = 0;
//	for(int i = 1;i <= n;i++) a[i] += i * k;
//	sort(all1(a));
//	for(int i = 1;i <= k;i++) s += a[i];
	
//	cout << k << ' ' << s << endl;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;


//void solve(){
//	int n, d;
//	cin >> n >> d;
//	vector<int>k(n+5), s(n+5), t(n+5), vis(n+5);
//	for(int i = 1;i <= n;i++) cin >> k[i] >> s[i];
//	vector<int>ok(k);
//	for(int i = n-1;i >= 1;i--) k[i] = max(k[i], k[i+1]);

//	if(d < n){
//		cout << -1 << endl;
//		return;
//	}

//	priority_queue<int, vector<int>, function<bool(int,int)>> que([&](const int i, const int j) -> bool {
//		if(k[i] == k[j]) {
//			if(t[i] == t[j]) return s[j] < s[i];
//			return t[j] < t[i];
//		}
//		return k[j] > k[i];
//	});
//	vector<vector<int>>vec(d+5);

//	int it = 1;

//	for(int i = 1;i <= d;i++){
//		if(it <= n && !vis[it]){
//			vis[it] = 1;
//			que.push(it);
//		}
//		for(auto u : vec[i]) que.push(u);
//		int u = que.top();
//		que.pop();
//		k[u] = ok[u];
//		it = max(it, u+1);
//		if(u == n) {
//			cout << i << endl;
//			return;
//		}
//		if(i+s[u]+1 <= d){
//			t[u] = i+s[u]+1;
//			vec[i+s[u]+1].push_back(u);
//		}
//	}

//	cout << -1 << endl;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2e5 + 10;
//int n, k;
//vector<int>g[N];

//int dep[N], mxd[N], last, ldep, val[N];

//void dfs(int u, int fa){
//	mxd[u] = dep[u] = dep[fa] + 1;
//	for(auto v : g[u]) {
//		dfs(v, u);
//		mxd[u] = max(mxd[u], mxd[v]);
//	}
//	sort(all(g[u]), [&](int i, int j) -> int {
//		return mxd[i] < mxd[j];
//	});
//}
//void dfs2(int u){
//	if(g[u].empty()){
//		val[last] = dep[last] + 1 - 2*ldep;
//		ldep = dep[u];
//		last = u;
//	}
//	for(auto v : g[u]) {
//		dfs2(v);
//		ldep = min(ldep, dep[u]);
//	}
//}


//void solve(){
//	cin >> n >> k;
//	for(int i = 2, f;i <= n;i++){
//		cin >> f;
//		g[f].push_back(i);
//	}

//	dfs(1, 0);
//	dfs2(1);
//	val[last] = dep[last] + 1 - 2*ldep;

//	sort(val+1, val+1+n, greater<int>());

//	k = min(k+1, n);
//	int ans = 2*(n-1);
//	for(int i = 1;i <= k;i++){
//		ans -= max(0ll, val[i]);
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
////#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1
//#define mk make_pair

//const int inf = 0x3f3f3f3f;
//const int mod = 998244353;
//const int N = 105;
//int f[N][N][N], g[N][N][N];


//void solve(){
//	int n, x;
//	cin >> n >> x;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];

//	//for(int i = 1;i <= n;i++){
//	//	for(int j = i;j <= n;j++){
//	//		for(int k = 1;k <= x;k++){
//	//			f[i][j][k] = g[i][j][k] = inf;
//	//		}
//	//	}
//	//}

//	for(int s = 1;s <= n;s++){
//		for(int l = 1, r = s;r <= n;l++, r++){
//			int mn = inf;
//			for(int k = 1;k <= x;k++){
//				g[l][r][k] = 0;
//				for(int i = l;i <= r;i++) if(a[i] == k){
//					g[l][r][k] = inf;
//					break;
//				}
//				for(int mid = l;mid < r;mid++){
//					g[l][r][k] = min(g[l][r][k], g[l][mid][k]+g[mid+1][r][k]);
//				}
//				mn = min(mn, g[l][r][k]+1);
//			}
//			for(int k = 1;k <= x;k++){
//				g[l][r][k] = min(mn, g[l][r][k]);
//			}
//		}
//	}
//	for(int s = 1;s <= n;s++){
//		for(int l = 1, r = s;r <= n;l++, r++){
//			for(int k = 1;k <= x;k++){
//				int ok = 1;
//				for(int i = l;i <= r;i++) if(a[i] != k){
//					ok = 0; break;
//				}
//				if(ok){
//					f[l][r][k] = 0;
//					continue;
//				}
//				f[l][r][k] = g[l][r][k]+1;
//				for(int mid = l;mid < r;mid++){
//					f[l][r][k] = min(f[l][r][k], f[l][mid][k]+f[mid+1][r][k]);
//				}
//			}
//		}
//	}

//	//cerr << f[1][1][1] << endl;
//	//cerr << f[2][2][1] << endl;
//	//cerr << f[3][3][1] << endl;

//	int ans = inf;
//	for(int k = 1;k <= x;k++){
//		ans = min(ans, f[1][n][k]);
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2005;


//void solve(){
//	int n, d;
//	cin >> n >> d;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//	}
//	sort(all1(a));

//	if(a[n]+a[n-1] > d){
//		cout << "No\n";
//		return;
//	}

//	vector<vector<int>>dp(n+5, vector<int>(d+5));
//	dp[0][0] = 1;
//	for(int i = 1;i <= n;i++){
//		dp[i] = dp[i-1];
//		for(int j = a[i];j <= d;j++) dp[i][j] |= dp[i-1][j-a[i]];
//	}
//	if(dp[n][d] && dp[n-1][d-a[n]]){
//		cout << "Yes\n";
//		return;
//	}

//	vector<bitset<N>>f(d+5);
//	f[0][0] = 1;

//	for(int i = 1;i <= n;i++){
//		for(int j = d;j >= 0;j--){
//			f[j] |= (f[j] << a[i]);
//			if(j-a[i] >= 0) f[j] |= f[j-a[i]];
//		}
//	}

//	//for(int i = 1;i <= d;i++){
//	//	for(int j = 1;j <= d;j++){
//	//		cerr << f[i][j] << ' ';
//	//	}
//	//	cerr << endl;
//	//}

//	for(int i = a[n];i <= d/2;i++) if(f[i][d-i] || f[d-i][i]){
//		cout << "Yes\n";
//		return;
//	}
//	cout << "No\n";

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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2005;


//void solve(){
//	int n, d;
//	cin >> n >> d;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//	}
//	sort(all1(a));

//	if(a[n]+a[n-1] > d){
//		cout << "No\n";
//		return;
//	}

//	vector<vector<int>>dp(n+5, vector<int>(d+5));
//	dp[0][0] = 1;
//	for(int i = 1;i <= n;i++){
//		dp[i] = dp[i-1];
//		for(int j = a[i];j <= d;j++) dp[i][j] |= dp[i-1][j-a[i]];
//	}
//	if(dp[n][d] && dp[n-1][d-a[n]]){
//		cout << "Yes\n";
//		return;
//	}

//	vector<bitset<N>>f(d+5);
//	f[0][0] = 1;

//	for(int i = 1;i <= n;i++){
//		for(int j = d;j >= 0;j--){
//			f[j] |= (f[j] << a[i]);
//			if(j-a[i] >= 0) f[j] |= f[j-a[i]];
//		}
//	}

//	//for(int i = 1;i <= d;i++){
//	//	for(int j = 1;j <= d;j++){
//	//		cerr << f[i][j] << ' ';
//	//	}
//	//	cerr << endl;
//	//}

//	for(int i = a[n];i <= d/2;i++) if(f[i][d-i] || f[d-i][i]){
//		cout << "Yes\n";
//		return;
//	}
//	cout << "No\n";

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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	if(k & 1){
//		cout << "No\n";
//		return;
//	}

//	if(k == 2){
//		if(n == 2){
//			cout << "Yes\n";
//			cout << "1 0\n0 1\n";
//		}else{
//			cout << "No\n";
//		}
//		return;
//	}

//	vector<vector<int>>f(n+5, vector<int>(n+5));

//	if(k % 4 == 0){
//		for(int i = 1;i <= n && k;i += 2){
//			for(int j = 1;j <= n && k;j += 2, k -= 4){
//				f[i][j] = f[i+1][j+1] = f[i+1][j] = f[i][j+1] = 1;
//			}
//		}
//	}else{
//		if(k > n*n-6){
//			cout << "No\n";
//			return;
//		}
//		if(k == n*n-6){
//			f[2][2] = f[2][4] = f[4][2] = f[4][4] = 1;
//			k -= 4;
//		}
//		f[1][1] = f[1][2] = f[2][1] = f[2][3] = f[3][2] = f[3][3] = 1;
//		k -= 6;
//		for(int i = 1;i <= 3 && k;i += 2){
//			for(int j = 5;j <= n && k;j += 2, k -= 4){
//				f[i][j] = f[i+1][j] = f[i][j+1] = f[i+1][j+1] = 1;
//			}
//		}
//		for(int i = 5;i <= n && k;i += 2){
//			for(int j = 1;j <= n && k;j += 2, k -= 4){
//				f[i][j] = f[i+1][j] = f[i][j+1] = f[i+1][j+1] = 1;
//			}
//		}
//	}

//	cout << "Yes\n";
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			cout << f[i][j] << ' ';
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;

//void solve(){
//	string s;
//	cin >> s;
//	int n = s.size();
//	s = ' ' + s;
//	int ans = 1, L = 0, R = 0;
//	for(int l = 1;l <= n;l++){
//		for(int r = l+1;r <= n;r++){
//			int f = 1;
//			int q = l, p = r;
//			while(q <= p){
//				if(s[q] != s[p]) {f = 0; break;}
//				q++, p--;
//			}
//			if(f && r-l+1 > ans) {
//				ans = r-l+1;
//				L = l, R = r;
//			}
//		}
//	}

//	cout << ans << endl;
//	cout << L << ' ' << R << endl;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2e5 + 10;

//int n, q, dep[N], L[N], R[N], tot, par[N][20], tr_data[N];
//vector<int>g[N];

//void dfs(int u, int fa){
//	par[u][0] = fa;
//	for(int i = 1;i < 20;i++) par[u][i] = par[par[u][i-1]][i-1];
//	L[u] = ++tot;
//	dep[u] = dep[fa] + 1;
//	tr_data[L[u]] = dep[u];
//	for(auto v : g[u]) if(v != fa){	
//		dfs(v, u);
//	}
//	R[u] = tot;
//}

//int tr[N<<2], tag[N<<2];

//void up(int id){
//	tr[id] = max(tr[ls], tr[rs]);
//}
//void build(int id, int l, int r){
//	if(l == r){
//		tr[id] = tr_data[l];
//		return;
//	}
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//	up(id);
//}
//void settag(int id, int x){
//	tr[id] += x;
//	tag[id] += x;
//}
//void down(int id){
//	settag(ls, tag[id]);
//	settag(rs, tag[id]);
//	tag[id] = 0;
//}
//void modify(int id, int l, int r, int ql, int qr, int x){
//	if(ql <= l && r <= qr) {
//		settag(id, x);
//		return;
//	}
//	if(tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(qr <= mid) modify(ls, l, mid, ql, qr, x);
//	else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x);
//	else modify(ls, l, mid, ql, qr, x), modify(rs, mid + 1, r, ql, qr, x);
//	up(id);
//}

//int query(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return tr[id];
//	if(tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls, l, mid, ql, qr);
//	else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//	else return max(query(ls, l, mid, ql, qr), query(rs, mid+1, r, ql, qr));
//}

//int lca(int u, int v){
//	if(dep[u] < dep[v]) swap(u, v);
//	for(int i = 19;i >= 0;i--) if(dep[par[u][i]] >= dep[v]) u = par[u][i];
//	if(u == v) return u;
//	for(int i = 19;i >= 0;i--) if(par[u][i] != par[v][i]) {
//		u = par[u][i]; v = par[v][i];
//	}
//	return par[u][0];
//}

//void add(int u, int v, int x){
//	int lc = lca(u, v);
//	if(lc == v){
//		for(int i = 19;i >= 0;i--) if(dep[par[u][i]] > dep[v]) u = par[u][i];
//		modify(1, 1, n, 1, n, n*x);
//		modify(1, 1, n, L[u], R[u], -n*x);
//	}else{
//		modify(1, 1, n, L[v], R[v], n*x);
//	}
//}


//void solve(){
//	cin >> n >> q;
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

	
//	dep[0] = -1;
//	dfs(1, 0);
//	build(1, 1, n);

//	vector<int>x(q+5), ans(q+5);
//	vector<vector<pair<int, vector<int>>>>qur(n+5);
//	for(int i = 1, k, a;i <= q;i++){
//		cin >> x[i] >> k;
//		qur[x[i]].push_back({i, vector<int>()});
//		while(k--){
//			cin >> a;
//			qur[x[i]].back().second.push_back(a);
//		}
//	}
//	//cerr << "DEBUG\n";

//	auto calc = [&](auto self, int u, int fa) -> void {
//		for(auto [id, vec] : qur[u]){
//			for(auto e : vec) add(u, e, -1);
//			ans[id] = tr[1];
//			for(auto e : vec) add(u, e, 1);
//		}

//		for(auto v : g[u]) if(v != fa){
//			modify(1, 1, n, 1, n, 1);
//			modify(1, 1, n, L[v], R[v], -2);
//			self(self, v, u);
//			modify(1, 1, n, 1, n, -1);
//			modify(1, 1, n, L[v], R[v], 2);
//		}
//	};
	
//	calc(calc, 1, 0);

//	//for(int i = 1;i <= n;i++){
//	//	cerr << L[i] << ' ' << R[i] << ' ' << dep[i] << endl;
//	//}

//	//cerr << query(1, 1, n, L[7], R[7]) << endl;
//	//modify(1, 1, n, 1, n, 1);
//	//modify(1, 1, n, L[2], R[2], -2);
//	//cerr << query(1, 1, n, L[7], R[7]) << endl;

//	for(int i = 1;i <= q;i++) cout << ans[i] << endl;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2e5 + 10;


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	int ans = a[n];
//	sort(all1(a));
//	if(ans == a[n]) ans += a[n-1];
//	else ans += a[n];

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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2e5 + 10;


//void solve(){
//	int n, a, b;
//	cin >> n >> a >> b;
//	if(b <= a){
//		cout << a*n << endl;
//	}else{
//		int d = min(b-a, n);
//		int ans = d*(b-(d-1) +b)/2;
//		ans += (n-d) * a;
//		cout << ans << endl;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2e5 + 10;


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	if((k & 1) || k > n*n/2){
//		cout << "No\n";
//		return;
//	}

//	vector<int>a(n+5);
//	iota(all(a), 0);

//	int l = 1, r = n;
//	while(k){
//		while(2*(r-l) > k) r--;
//		swap(a[l], a[r]);
//		k -= 2*(r-l);
//		l++, r--;
//	}

//	cout << "Yes\n";
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2e5 + 10;


//void solve(){
//	int n, c;
//	cin >> n >> c;
//	vector<int>a(n+5), suf(n+5), pre(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		if(i == 1) a[1] += c;
//		pre[i] = pre[i-1] + a[i];
//	}
//	suf[n] = a[n];
//	for(int i = n-1;i >= 1;i--) suf[i] = max(a[i], suf[i+1]);

//	vector<int>ans(n+5);
//	int mx = -1;
//	for(int i = 1;i <= n;i++){
//		if(suf[i+1] > a[i]){
//			ans[i] += i-1;
//			if(suf[i+1] > a[i]+pre[i-1]) ans[i]++;
//		}else if(mx >= a[i]){
//			ans[i] += i-1;
//		}
//		mx = max(mx, a[i]);
//	}

//	for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2e5 + 10;


//void solve(){
//	int n;
//	cin >> n;
//	string s, t;
//	cin >> s >> t;
//	s = ' ' + s;
//	t = ' ' + t;
//	string a(s), b(t);
//	vector<int>l(n+5), r(n+5), L(n+5), R(n+5);
//	iota(all(l), 0);
//	iota(all(r), 0);
//	iota(all(L), 0);
//	iota(all(R), 0);


//	for(int i = 1;i+2 <= n;i++) if(a[i] == a[i+2] && a[i] == '0' && b[i+1] == '0') {
//		b[i+1] = '1';
//		l[i+1] = i; r[i+1] = i+2;
//	}	
//	for(int i = 1;i+2 <= n;i++) if(b[i] == b[i+2] && b[i] == '1' && a[i+1] == '0') {
//		a[i+1] = '1';
//		L[i+1] = l[i]; R[i+1] = r[i+2];
//	}

//	vector<int>pre(n+5);
//	for(int i = 1;i <= n;i++){
//		pre[i] = pre[i-1] + (a[i] == '1');
//	}

//	int q;
//	cin >> q;
//	while(q--){
//		int l, r;
//		cin >> l >> r;
//		int ans = pre[r] - pre[l-1];
//		for(int i = l;i <= min(l+2, r);i++) {
//			if(L[i] < l || R[i] > r) ans--;
//		}
//		for(int i = r;i >= max(l+3, r-2);i--) {
//			if(L[i] < l || R[i] > r) ans--;
//		}
//		cout << ans << endl;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2e5 + 10;


//void solve(){
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	if(a < b){
//		if(c < d) cout << "YES\n";
//		else cout << "NO\n";
//	}else{
//		if(c > d) cout << "YES\n";
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
//#define ls id << 1
//#define rs id << 1 | 1
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2e5 + 10;


//void solve(){
//	int n, l, r;
//	cin >> n >> l >> r;
//	vector<int>a(n+5), f(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		a[i] += a[i-1];	
//	}
//	priority_queue<pair<int,int>>que;
//	int L = 0, R =  0;
//	for(int i = 1;i <= n;i++){
//		f[i] = f[i-1];
//		while(a[i] - a[R] >= l) que.push({f[R], R++});
//		while(a[i] - a[L] > r) L++;
//		while(que.size() && que.top().second < L) que.pop();
//		if(que.size()) f[i] = max(f[i], que.top().first+1);
//		//cerr << f[i] << endl;
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
//#define ls id << 1
//#define rs id << 1 | 1
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2e5 + 10;

////int f(int x, int y, int k){

////}


//void solve(){
//	int x, y, k;
//	cin >> x >> y >> k;
//	while(k){
//		if(x < y) {
//			k %= y-1;
//			//cerr << x << ' ' << y << ' ' << k << endl;
//			//cout << f(x, y, k%(y-1)) << endl;
//			//return;
//		}
//		int d = min(k, y-(x%y));
//		k -= d;
//		x += d;
//		while(x % y == 0) x /= y;
//	}
//	cout << x << endl;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 998244353;
//const int N = 2e5 + 10;


//void solve(){
//	int n, m, k, s = 0;
//	cin >> n >> m >> k;
//	vector<vector<int>>a(n+5, vector<int>(m+5)), pre(n+5, vector<int>(m+5)), b(n+5, vector<int>(m+5));
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			cin >> a[i][j];
//		}
//	}
//	vector<string>mp(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> mp[i];
//		mp[i] = ' ' + mp[i];
//		for(int j = 1;j <= m;j++){
//			b[i][j] = (mp[i][j] == '1' ? 1 : -1);
//			s += b[i][j] * a[i][j];
//			pre[i][j] = b[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
//		}
//	}

//	if(s == 0){
//		cout << "YES\n";
//		return;
//	}

//	vector<int>num;
//	for(int i = k;i <= n;i++){
//		for(int j = k;j <= m;j++){
//			num.push_back(pre[i][j] - pre[i-k][j] - pre[i][j-k] + pre[i-k][j-k]);
//			//cerr << i << ' ' << j << endl;
//		}
//	}

//	sort(all(num));
//	num.erase(unique(all(num)), num.end());
//	int g = abs(num.front());
//	if(g == 0) g = abs(num.back());
//	if(g == 0){
//		cout << "NO\n";
//		return;
//	}
//	for(auto e : num) if(e) g = gcd(g, abs(e));
//	//cerr << "DEBUG\n";

//	s = abs(s);
//	if(s % g == 0) cout << "YES\n";
//	else cout << "NO\n";
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 1e9 + 7;
//const int N = 2e5 + 10;


//void solve(){
//	int x, y;
//	cin >> x >> y;
//	y -= abs(x) - 1;
//	if(y < -abs(x)) cout << "NO\n";
//	else cout << "YES\n";

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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 1e9 + 7;
//const int N = 2e5 + 10;


//void solve(){
//	string a, b;
//	cin >> a >> b;
//	int n = a.size(), m = b.size();
//	a = ' ' + a;
//	b = ' ' + b;
//	int ans = inf;
//	for(int i = 1;i <= m;i++){
//		int p = i;
//		for(int j = 1;j <= n && p <= m;j++){
//			if(a[j] == b[p]) p++;
//		}
//		ans = min(ans, n + i-1 + m-p+1);
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 1e9 + 7;
//const int N = 2e5 + 10;


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), b(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++) cin >> b[i];

//	int ad = 0, s1 = 0, s2 = 0, dv = 0;
//	for(int i = 1;i <= n;i++) {
//		if(a[i] == b[i]){
//			if(a[i] == 1) ad++;
//			else if(a[i] == -1) dv++;
//		}else{
//			if(a[i] > b[i]) s1 += a[i];
//			else s2 += b[i];
//		}
//	}

//	while(ad--){
//		if(s1 < s2) s1++;
//		else s2++;
//	}
//	while(dv--){
//		if(s1 > s2) s1--;
//		else s2--;
//	}

//	cout << min(s1, s2) << endl;
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
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 1e9 + 7;
//const int N = 1e6 + 10;


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n+5), b(n+5), c(m+5), d(N, inf);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++) cin >> b[i];
//	for(int i = 1;i <= m;i++) cin >> c[i];

//	for(int i = 1;i <= n;i++){
//		int tmp = a[i] - b[i];
//		d[tmp] = min(d[tmp], a[i]);
//	}

//	vector<int>k, dt;
//	for(int i = 1;i < N;i++) if(d[i] != inf){
//		if(k.empty() || d[i] < k.back()){
//			dt.push_back(i);
//			k.push_back(d[i]);
//		}
//	}

//	//for(auto e : k) cerr << e << ' ';
//	//cerr << endl;
//	//for(auto e : dt) cerr << e << ' ';
//	//cerr << endl;

	

//	vector<int>f(N);
//	int p = k.size()-1;
//	for(int i = k.back();i < N;i++){
//		while(p && k[p-1] <= i) p--;
//		int tmp = (i-k[p]+dt[p]) / dt[p];
//		f[i] = f[i-tmp*dt[p]] + tmp;
//	}

//	//for(int i = 1;i <= 10;i++) cerr << f[i] << ' ';
//	//cerr << endl;

//	int sum = 0;
//	for(int i = 1;i <= m;i++){
//		if(c[i] < N){
//			sum += f[c[i]];
//		}else{
//			int tmp = (c[i] - k[0] + dt[0]) / dt[0];
//			int ans = tmp + f[c[i] - tmp*dt[0]];
//			sum += ans;
//		}
//	}
//	cout << sum*2 << endl;
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
////#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 1e9 + 7;
//const int N = 1e6 + 10;


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>g(n*2+5);
//	for(int i = 1, a, af, b, bf;i <= m;i++){
//		cin >> a >> af >> b >> bf;
//		g[a + (af^1)*n].push_back(b+bf*n);
//		g[b + (bf^1)*n].push_back(a+af*n);
//	}

//	vector<int>scc(n*2+5), dfn(n*2+5), st(n*2+5), low(n*2+5);
//	int top = 0, tot = 0, cnt = 0;

//	auto tarjan = [&](auto self, int u) -> void {
//		low[u] = dfn[u] = ++tot;
//		st[++top] = u;
//		for(auto v : g[u]) {
//			if(!dfn[v]){
//				self(self, v);
//				low[u] = min(low[v], low[u]);
//			}else if(!scc[v])
//				low[u] = min(low[v], low[u]);
//		}
//		if(low[u] == dfn[u]){
//			cnt++;
//			while(st[top] != u){
//				scc[st[top--]] = cnt;
//			}
//			scc[st[top--]] = cnt;
//		}
//	};

//	for(int i = 1;i <= 2*n;i++) if(!dfn[i]) tarjan(tarjan, i);


//	vector<int>d(cnt+5), dep(cnt+5);
//	vector<vector<int>>scg(cnt+5);
//	for(int i = 1;i <= 2*n;i++){
//		for(auto v : g[i]) if(scc[i] != scc[v]) {
//			scg[scc[i]].push_back(scc[v]);
//			d[scc[v]]++;
//		}
//	}

//	auto dfs = [&](auto self, int u, int fa) -> void {
//		dep[u] = dep[fa] + 1;
//		for(auto v : scg[u]) if(dep[u]+1 > dep[v]) {
//			self(self, v, u);
//		}
//	};

//	for(int i = 1;i <= cnt;i++) if(!d[i]){
//		dfs(dfs, i, 0);
//	}

//	vector<int>ans;

//	for(int i = 1;i <= n;i++){
//		if(scc[i] == scc[i+n]){
//			cout << "IMPOSSIBLE\n";
//			return;
//		}
//		if(dep[scc[i]] > dep[scc[i+n]]) ans.push_back(0);
//		else ans.push_back(1);
//	}

//	cout << "POSSIBLE\n";
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
////#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 1e9 + 7;
//const int N = 1e6 + 10;

//class TMap{
//	vector<int>it;
//	vector<vector<int>>&g;
//	int &tot;
//public:
//	TMap(int n, int &tot, vector<vector<int>> &g) : tot(tot), g(g), it(n*4+5) {
//		build(1, 1, n);
//	}

//	void up(int id){
//		g[it[id]].push_back(it[ls]);
//		g[it[id]].push_back(it[rs]);
//	}

//	void build(int id, int l, int r){
//		if(l == r){
//			it[id] = l;
//			return;
//		}
//		it[id] = ++tot;
//		int mid = l + r >> 1;
//		build(ls, l, mid);
//		build(rs, mid + 1, r);
//		up(id);
//	}

//	void add(int id, int l, int r, int x, int ql, int qr) {
//		if(ql <= l && r <= qr){
//			g[x].push_back(it[id]);
//			return;
//		}
//		int mid = l + r >> 1;
//		if(qr <= mid) add(ls, l, mid, x, ql, qr);
//		else if(ql > mid) add(rs, mid + 1, r, x, ql, qr);
//		else add(ls, l, mid, x, ql, qr), add(rs, mid + 1, r, x, ql, qr);
//	}
//};

//int check(int n, int d, vector<array<int,2>>&E){
//	int tot = 2*n;
//	vector<vector<int>>g(n*8+5);
//	TMap tr(n*2, tot, g);

//	for(auto [u, v] : E){
//		g[u].push_back(v+n);
//		g[v].push_back(u+n);
		
//		int l = max(1, u-d+1), r = u-1;
//		if(l <= r) tr.add(1, 1, n*2, u+n, l, r);
//		l = u+1, r = min(n, u+d-1);
//		if(l <= r) tr.add(1, 1, n*2, u+n, l, r);

//		l = max(1, v-d+1), r = v-1;
//		if(l <= r) tr.add(1, 1, n*2, v+n, l, r);
//		l = v+1, r = min(n, v+d-1);
//		if(l <= r) tr.add(1, 1, n*2, v+n, l, r);
//	}

//	vector<int>scc(tot+5), dfn(tot+5), low(tot+5), st(tot+5);
//	int cnt = 0, pid = 0, top = 0;
//	auto tarjan = [&](auto self, int u) -> void {
//		dfn[u] = low[u] = ++pid;
//		st[++top] = u;
//		for(auto v : g[u]) {
//			if(!dfn[v]){
//				self(self, v);
//				low[u] = min(low[u], low[v]);
//			}else if(!scc[v])
//				low[u] = min(low[u], low[v]);
//		}
//		if(low[u] == dfn[u]){
//			++cnt;
//			while(st[top] != u){
//				scc[st[top--]] = cnt;
//			}
//			scc[st[top--]] = cnt;

//		}
//	};

//	for(int i = 1;i <= tot;i++) if(!dfn[i]) tarjan(tarjan, i);

//	for(int i = 1;i <= n;i++) if(scc[i] == scc[i+n]) {
//		return 0;
//	}

//	return 1;
//}

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<array<int,2>>E;
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		E.push_back({u, v});
//	}

//	int l = 1, r = n;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(check(n, mid, E)) l = mid + 1;
//		else r = mid - 1;
//	}

//	cout << r << endl;
//}	

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}