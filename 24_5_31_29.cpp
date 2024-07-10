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
//	int n, k;
//	cin >> n >> k;
//	cout << (n-1)*k + 1 << endl;
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
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	int mx = 0, ans = 0, sum = 0;
//	for(int i = 1;i <= n;i++){
//		mx = max(mx, a[i]);
//		sum += max(0ll, mx-a[i]);
//		ans = max(ans, max(0ll, mx-a[i]));
//	}
//	cout << ans+sum << endl;
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
//	int n;
//	cin >> n;
//	vector<int>a(n+5), f(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	f[n] = a[n];
//	for(int i = n-1;i >= 1;i--){
//		f[i] = max(f[i+1]+1, a[i]);
//	}
//	cout << f[1] << endl;
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
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	map<int,int>mp;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		mp[a[i]]++;
//	}
//	int m = mp.size();
//	vector<int>f(m+5), gt(m+5);
//	int it = 1;
//	for(auto [k, v] : mp) {
//		f[it++] = v;
//	}

//	int ans = m;
//	for(int i = 1;i <= n;i++){
//		int p = 1;
//		for(int j = 1;j <= m;j = max(j+1, p+1)) {
//			if(gt[j]) {
//				p += f[j]+1;
//				continue;
//			}
//			if(f[j] == i && p+f[j] <= j){
//				int ok = 1;
//				int pp = p + f[j]+1;
//				for(int k = j+1;k <= m;k++){
//					if(gt[k]) {
//						if(pp + f[k] > k) {
//							ok = 0;
//							break;
//						}
//						pp += f[k] + 1;
//					}
//				}
//				if(ok){
//					//cerr << j << endl;
//					ans--;
//					gt[j] = 1;
//					p += f[j]+1;
//				}
//			}
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
//#define ls id << 1
//#define rs id << 1 | 1
//#define mk make_pair

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int mod = 1e9 + 7;
//const int N = 1e6 + 10;


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), d(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 2, p;i <= n;i++) {
//		cin >> p;
//		g[p].push_back(i);
//	}

//	int ans = 0;

//	auto dfs = [&](auto self, int u) -> void {
//		if(g[u].empty()){
//			d[u] = inf;
//			return;
//		}
//		d[u] = -a[u];
//		for(auto v : g[u]) {
//			self(self, v);
//			d[u] += a[v];
//		}
//		queue<array<int, 2>>que;
//		que.push({u, 0});
//		while(d[u] < 0){
//			auto [v, k] = que.front();
//			que.pop();
//			if(d[v] == inf){
//				int tmp = -d[u];
//				d[u] += tmp;
//				ans += tmp * k;
//				break;
//			}
//			if(d[v] > 0){
//				int tmp = min(d[v], -d[u]);
//				d[u] += tmp;
//				d[v] -= tmp;
//				ans += tmp * k;
//			}
//			for(auto vv : g[v]) que.push({vv, k+1});
//		}
//	};

//	dfs(dfs, 1);
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
//const int N = 1e6 + 10;


//void solve(){
//	int n, s1, s2;
//	cin >> n >> s1 >> s2;
//	vector<int>x(n+5), y(n+5), t(n+5), r(n+5), id(n+5);
//	for(int i = 1;i <= n;i++) cin >> x[i] >> t[i] >> y[i] >> r[i];

//	vector<vector<int>>f(s1+510, vector<int>(510, inf));
//	f[0][0] = 0;

//	iota(all(id), 0);
//	sort(all1(id), [&](int i, int j) -> int {return x[i] < x[j];});

//	int ans = inf;

//	for(int ii = 1, i = id[1];ii <= n;ii++, i = id[ii]){
//		for(int a = s1+500; a >= 0;a--){
//			for(int b = 500;b >= 0;b--){
//				if(b-y[i] >= 0) f[a][b] = min(f[a][b], f[a][b-y[i]]+r[i]);
//				if(a-x[i] >= 0 && a-x[i] < s1) f[a][b] = min(f[a][b], f[a-x[i]][b]+t[i]);
//				if(a >= s1 && a+b >= s1+s2) ans = min(ans, f[a][b]);
//			}
//		}
//	}

//	if(ans == inf) cout << -1 << endl;
//	else cout << ans << endl;
	
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

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, k, lc, lm, pc, pm, t, d;
//	cin >> n >> k >> lc >> pc >> lm >> pm >> t >> d;
//	vector<int>a(n+5), prec(n+5), prem(n+5), prep(n+5), ndc(n+5), ndm(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(a.begin()+1, a.begin()+1+n);

//	for(int i = 1;i <= n;i++){
//		prec[i] += prec[i-1];
//		if(a[i] < lc) prec[i] -= lc - a[i];
//		else prec[i] += min(d, a[i] - lc);

//		prem[i] += prem[i-1];
//		if(a[i] < lm) prem[i] -= lm - a[i];
//		else prem[i] += min(d, a[i] - lm);

//		prep[i] += prep[i-1];
//		prep[i] += min(d, a[i]-1);

//		ndc[i] += ndc[i-1];
//		if(a[i] < lc) ndc[i] += lc - a[i];

//		ndm[i] += ndm[i-1];
//		if(a[i] < lm) ndm[i] += lm - a[i];
//	}

//	int ans = inf;

//	a[n+1] = lc;
//	for(int i = 0;i <= n;i++){
//		int r = min(n-i, (k-1)*i), cl = n-i+1;
//		int ag = prep[r] + (prem[cl-1] - prem[r]) + (prec[n] - prec[cl-1]);
//		if(ag < 0 || (r+1 < cl && a[r+1]+d < lm) || a[cl]+d < lc) continue;

//		int nd = (ndm[cl-1] - ndm[r]) + (ndc[n] - ndc[cl-1]);

//		int ms = cl-1-r;
//		int tmp = nd*t + i*pc + ms*pm;

//		ans = min(ans, tmp);
//	}

//	if(ans == inf) cout << -1 << endl;
//	else cout << ans << endl;
	
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
//#define ls id << 1
//#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

//const int inf = 0x3f3f3f3f3f3f3f3f;

//struct node{
//	int val, llen, rlen, lc, rc, len;
//	node() : val(0), llen(1), rlen(1), lc(1), rc(1), len(1) {}
//};
//node operator+(const node&l, const node&r) {
//	node ret;
//	ret.val = l.val + r.val;
//	ret.len = l.len + r.len;
//	ret.lc = l.lc;
//	ret.rc = r.rc;
//	ret.llen = l.llen;
//	ret.rlen = r.rlen;
//	if(l.rc && l.rc + r.lc == 0){
//		ret.val -= l.rlen/2 + r.llen/2;
//		ret.val += (l.rlen + r.llen)/2;
//		if(l.llen == l.len) ret.llen += r.llen;
//		if(r.rlen == r.len) ret.rlen += l.rlen;
//	}
//	return ret;
//}
//class Tree{
//public:
//	vector<node> tr;
//	Tree(int n) : tr(n*4 + 5) {
//		build(1, 1, n);
//	}

//	void up(int id){
//		tr[id] = tr[ls] + tr[rs];
//	}
//	void build(int id, int l, int r){
//		if(l == r){
//			return;
//		}
//		int mid = l + r >> 1;
//		build(ls, l, mid);
//		build(rs, mid + 1, r);
//		up(id);
//	}

//	void change(int id, int l, int r, int x, int v) {
//		if(l == r){
//			tr[id].lc = tr[id].rc = v;
//			return;
//		}
//		int mid = l + r >> 1;
//		if(x <= mid) change(ls, l, mid, x, v);
//		else change(rs, mid + 1, r, x, v);
//		up(id);
//	}
//};

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n+5);
//	vector<vector<int>>pos(m+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pos[a[i]].push_back(i);
//	}
//	Tree tr(n);

//	for(int i = 1;i <= m;i++){
//		if(pos[i].empty()){
//			cout << -1 << ' ';
//			continue;
//		}
//		for(auto p : pos[i]) tr.change(1, 1, n, p, 0);

//		node e = tr.tr[1];
//		if(e.lc && e.lc + e.rc == 0 && e.llen != n){
//			e.val -= e.llen/2 + e.rlen/2;
//			e.val += (e.llen + e.rlen)/2;
//		}
//		cout << e.val + (n-pos[i].size()) << ' ';

//		for(auto p : pos[i]) tr.change(1, 1, n, p, -1);
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
//#define ls id << 1
//#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int n;
//	cin >> n;
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	if(n & 1){
//		cout << "Alice\n";
//		return;
//	}

//	vector<int>f(n+5);
//	auto dfs = [&](auto self, int u, int fa) -> void {
//		int son = 0;
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//			son += f[v];
//		}
//		if(!son) f[u] = 1;
//		else f[u] = son - 1;
//	};

//	dfs(dfs, 1, 0);

//	if(f[1]) cout << "Alice\n";
//	else cout << "Bob\n";
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
////#define ls id << 1
////#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

//const int inf = 0x3f3f3f3f3f3f3f3f;

//const int N = 250010;
//const int M = N*80;

//int rt[N], tr[M], tot, ls[M], rs[M];
//void insert(int p, int &id, int l, int r, int x) {
//	id = ++tot;
//	tr[id] = tr[p] + 1;
//	ls[id] = ls[p];
//	rs[id] = rs[p];
//	if(l == r) return;
//	int mid = l + r >> 1;
//	if(x <= mid) insert(ls[p], ls[id], l, mid, x);
//	else insert(rs[p], rs[id], mid + 1, r, x);
//}
//int cnt(int u, int v, int f1, int f2) {
//	return tr[u] + tr[v] - tr[f1] - tr[f2];
//}
//int hf;
//int query(int u, int v, int f1, int f2, int l, int r, int k) {
//	if(l == r) {
//		if(cnt(u, v, f1, f2) >= hf) return l;
//		else return -1;
//	}
//	int mid = l + r >> 1;
//	int lsum = cnt(ls[u], ls[v], ls[f1], ls[f2]);
//	if(lsum >= k) return query(ls[u], ls[v], ls[f1], ls[f2], l, mid, k);
//	else return query(rs[u], rs[v], rs[f1], rs[f2], mid + 1, r, k-lsum);
//}

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	vector<array<int,20>>par(n+5);
//	vector<int>dep(n+5);
//	auto dfs = [&](auto self, int u, int fa) -> void {
//		insert(rt[fa], rt[u], 1, n, a[u]);
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
//			u = par[u][i], v = par[v][i];
//		}
//		return par[u][0];
//	};

//	int u, v, lc, lcf, len, ans;
//	while(q--){
//		cin >> u >> v;
//		lc = lca(u, v);
//		lcf = par[lc][0];
//		//cerr << u << ' ' << v << ' ' << lc << endl;
//		//if(lc != u && lc != v){
//			len = dep[u] + dep[v] - 2 * dep[lc] + 1;
//			hf = len / 2 + 1;
//			ans = query(rt[u], rt[v], rt[lc], rt[lcf], 1, n, hf);
//		//}
//		//else{
//		//	len = abs(dep[u] - dep[v]) + 1;
//		//	hf = len/2 + 1;
//		//	ans = query(rt[u], rt[0], rt[0], rt[lcf], 1, n, hf);
//		//}
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
////#define ls id << 1
////#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define rall(x) (x).rbegin(), (x).rend()


//const int inf = 0x3f3f3f3f3f3f3f3f;

//const int N = 250010;
//const int M = N*80;

//void fun(int n, vector<int>&dep, vector<int>&a){
//	vector<int>f(n+5), tail(n+5, inf);
//	vector<vector<int>>g(n+5);
//	vector<array<int,20>>par(n+5);

//	auto lca = [&](int u, int v) -> int {
//		if(dep[u] < dep[v]) swap(u, v);
//		for(int i = 19;i >= 0;i--) if(dep[par[u][i]] >= dep[v]) u = par[u][i];
//		if(u == v) return u;
//		for(int i = 19;i >= 0;i--) if(par[u][i] != par[v][i]) {
//			u = par[u][i], v = par[v][i];
//		}
//		return par[u][0];
//	};

//	tail[0] = 0;
//	for(int i = 1;i <= n;i++){
//		f[i] = upper_bound(all(tail), a[i]) - tail.begin();
//		tail[f[i]] = a[i];
//		g[f[i]].push_back(i);
//		if(f[i] == 1){
//			dep[i] = 1;
//			continue;
//		}

//		int pre = f[i]-1;
//		int u = g[pre].back();
//		int l = 0, r = g[pre].size()-1;
//		while(l <= r){
//			int mid = l + r >> 1;
//			if(a[i] > a[g[pre][mid]]) r = mid - 1;
//			else l = mid + 1;
//		} 
//		int v = g[pre][l];

//		int fa = lca(u, v);
//		dep[i] = dep[fa] + 1;
//		par[i][0] = fa;
//		for(int j = 1;j < 20;j++) par[i][j] = par[par[i][j-1]][j-1];
//	}
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), pre(n+5), suf(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];

//	fun(n, pre, a);
//	reverse(a.begin()+1, a.begin()+1+n);
//	for(int i = 1;i <= n;i++) a[i] = n-a[i] + 1; 
//	fun(n, suf, a);
//	reverse(suf.begin()+1, suf.begin()+1+n);

//	for(int i = 1;i <= n;i++){
//		cout << pre[i] + suf[i] - 2 << ' ';
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
////#define ls id << 1
////#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define rall(x) (x).rbegin(), (x).rend()


//const int inf = 0x3f3f3f3f3f3f3f3f;

//const int N = 1e6+10;
//const int M = N*80;

//int rt[N], tot, ls[M], rs[M], tr[M], a[N];
//void build(int &id, int l, int r){
//	id = ++tot;
//	if(l == r){
//		tr[id] = a[l];
//		return; 
//	}
//	int mid = l + r >> 1;
//	build(ls[id], l, mid);
//	build(rs[id], mid + 1, r);
//}
//void modify(int &id, int l, int r, int x, int v){
//	++tot;
//	ls[tot] = ls[id];
//	rs[tot] = rs[id];
//	id = tot;
//	if(l == r){
//		tr[id] = v;
//		return;
//	}
//	int mid = l + r >> 1;
//	if(x <= mid) modify(ls[id], l, mid, x, v);
//	else modify(rs[id], mid + 1, r, x, v);
//}
//int query(int id, int l, int r, int x){
//	if(l == r) return tr[id];
//	int mid = l + r >> 1;
//	if(x <= mid) return query(ls[id], l, mid, x);
//	else return query(rs[id], mid + 1, r, x);
//}


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	build(rt[0], 1, n);

//	int v, op, p, val;
//	for(int i = 1;i <= m;i++){
//		cin >> v >> op >> p;
//		if(op == 1){
//			cin >> val;
//			rt[i] = rt[v];
//			modify(rt[i], 1, n, p, val);
//		}else{
//			rt[i] = rt[v];
//			cout << query(rt[i], 1, n, p) << endl;
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
////#define ls id << 1
////#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define rall(x) (x).rbegin(), (x).rend()


//const int inf = 0x3f3f3f3f3f3f3f3f;

//const int N = 1e6+10;
//const int M = N*80;
//int a[N];


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<vector<array<int,2>>>g(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		g[i].push_back({0, a[i]});
//	}

//	int v, op, p, val;
//	for(int i = 1;i <= m;i++){
//		cin >> v >> op >> p;
//		if(op == 1){
//			cin >> val;
//			g[p].push_back({i, val});
//		}else{
//			int l = 0, r = g[p].size()-1;
//			while(l <= r){
//				int mid = l + r >> 1;
//				if(g[p][mid][0] <= v) l = mid + 1;
//				else r = mid - 1;
//			}
//			cout << g[p][r][1] << endl;
//			g[p].push_back({i, g[p][r][1]});
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
////#define ls id << 1
////#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define rall(x) (x).rbegin(), (x).rend()

//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int n, m;
//	string s;
//	cin >> s;
//	n = s.size();
//	s = ' ' + s;
	
//	vector<int>sum(n+5), si(n+5);
//	for(int i = 1; i <= n;i++){
//		sum[i] = sum[i-1] + (s[i] == '1');
//		si[i] = i-2*sum[i];
//	}

	
//	cin >> m;
//	while(m--){
//		int k, ans = 0;
//		cin >> k;
//		deque<int>que;
//		que.push_back(0);
//		for(int i = 1, j = 1;i <= n;i++){
//			while(sum[j-1] < sum[i]-k) j++;
//			while(que.size() && que.front() < j-1) que.pop_front();
//			while(que.size() && si[i] <= si[que.back()]) que.pop_back();
//			que.push_back(i);
//			ans = max(ans, k+si[i]-si[que.front()]);
//		}
//		cout << min(ans, n-sum[n]) << endl;
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
////#define ls id << 1
////#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define rall(x) (x).rbegin(), (x).rend()

//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(a.begin()+1, a.begin()+1+n);
//	a[n+1] = inf;

//	priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>>que;
//	que.push({a[1], 1});
//	while(--k){
//		auto [d, id] = que.top();
//		que.pop();
//		que.push({d-a[id]+a[id+1], id+1});
//		que.push({d+a[id+1], id+1});
//	}

//	cout << que.top()[0] << endl;
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
////#define ls id << 1
////#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define rall(x) (x).rbegin(), (x).rend()

//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), len(n+5, inf), f(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];

//	int mx = 0;
//	len[0] = 0;
//	g[0].push_back(0);
//	for(int i = 1;i <= n;i++){
//		f[i] = upper_bound(all(len), a[i]) - len.begin();
//		len[f[i]] = a[i];
//		g[f[i]].push_back(i);
//		mx = max(mx, f[i]);
//	}

//	vector<int>vis(n+5);
//	int p = g[mx].front();
//	while(p){
//		vis[p] = 1;
//		int pre = f[p] - 1;
//		int l = 0, r = g[pre].size()-1;
//		while(l <= r){
//			int mid = l + r >> 1;
//			if(a[p] > a[g[pre][mid]]) r = mid - 1;
//			else l = mid + 1;
//		}
//		p = g[pre][l];
//	}

//	vector<int>op;
//	for(int i = 1, l = 1;i <= n;i++) if(vis[i]) {
//		while(l < i){
//			if(!vis[l] && a[l] > a[i]) op.push_back(l);
//			l++;
//		}
//	}

//	cout << mx << ' ' << op.size() << endl;
//	for(auto e : op) cout << e << ' ';
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
////#define ls id << 1
////#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define rall(x) (x).rbegin(), (x).rend()

//const int inf = 0x3f3f3f3f3f3f3f3f;

//int lowbit(int x){
//	return x & -x;
//}
//int neb(int x){
//	if(lowbit(x) == x) return x;
//	while(lowbit(x) != x) x -= lowbit(x);
//	return x << 1;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n);

//	auto f = [&](auto self, int n) -> void {
//		if(n <= 3){
//			if(n == 1) a[0] = 0;
//			else if(n == 2) { a[0] = 1; a[1] = 0; }
//			else { a[0] = 0; a[1] = 2; a[2] = 1; }
//			return;
//		}
//		if(lowbit(n) == n) {
//			for(int i = 0;i < n;i++) a[i] = n-1-i;
//			return;
//		}
//		int m = neb(n);
//		for(int i = m-n;i < n;i++) a[i] = m-1-i;
//		self(self, m-n);
//	};	

//	f(f, n);

//	for(auto e : a) cout << e << ' ';
//	cout << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();
//	//cerr << neb(5);

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long 
////#define ls id << 1
////#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define rall(x) (x).rbegin(), (x).rend()

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 5e5;

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<vector<int>>a(n+5);

//	int i = 1;
//	for(int j = 1;i <= n && j+k-1 <= N;i++, j += k) {
//		for(int x = j;x < j+k;x++) a[i].push_back(x);
//	}

//	int st = 1, d = 0;
//	while(i <= n){
//		for(int j = st;j < st+k;j++) a[i].push_back(a[j][d]);
//		if(++d == k) {
//			d = 0;
//			st += k;
//		}
//		i++;
//	}

//	for(int i = 1;i <= n;i++) {
//		for(auto e : a[i]) cout << e << ' ';
//		cout << endl;
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
////#define ls id << 1
////#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define rall(x) (x).rbegin(), (x).rend()

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 5e5;

//int op[4][2] = {
//	0, 1,
//	0, -1,
//	1, 0,
//	-1, 0
//};

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	int sum = 0, ze = 0;
//	vector<string>mp(n+5);
//	vector<vector<int>>vis(n+5, vector<int>(m+5));
//	for(int i = 1;i <= n;i++){
//		cin >> mp[i];
//		for(auto c : mp[i]){
//			sum += (c != 'X');
//			ze += (c == '0');
//		}
//		mp[i] = 'X' + mp[i] + 'X';
//	}
//	mp[0] = mp[n+1] = string(m+5, 'X');

//	if(ze % 2 == 0) {
//		cout << "No\n";
//		return;
//	}

//	queue<array<int, 2>>que;
//	for(int i = 1;i <= n && que.empty();i++){
//		for(int j = 1;j <= m;j++) if(mp[i][j] != 'X') {
//			que.push({i, j});
//			vis[i][j] = 1;
//			break;
//		}
//	}
//	while(que.size()){
//		auto [x, y] = que.front();
//		que.pop();
//		sum--;
//		for(int i = 0;i < 4;i++){
//			int nx = x + op[i][0];
//			int ny = y + op[i][1];
//			if(mp[nx][ny] == 'X' || vis[nx][ny]) continue;
//			que.push({nx, ny});
//			vis[nx][ny] = 1;
//		}
//	}

//	if(sum == 0) cout << "Yes\n";
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
////#define ls id << 1
////#define rs id << 1 | 1
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define rall(x) (x).rbegin(), (x).rend()

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 10;
//const int mod = 1e9 + 7;

//int fac[N];

//void solve(){
//	int n, tot = 0, top = 0, cnt = 0;
//	cin >> n;
//	vector<int>a(n+5), low(n+5), dfn(n+5), scc(n+5), st(n+5), sp(n+5), siz(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];

//	auto tarjan = [&](auto self, int u) -> void {
//		dfn[u] = low[u] = ++tot;
//		st[++top] = u;
//		if(!dfn[a[u]]) {
//			self(self, a[u]);
//			low[u] = min(low[u], low[a[u]]);
//		}else if(!scc[a[u]]) 
//			low[u] = min(low[u], low[a[u]]);
//		if(low[u] == dfn[u]) {
//			scc[u] = ++cnt;
//			siz[cnt] = 1;
//			sp[cnt] = u;
//			while(st[top] != u) {
//				scc[st[top--]] = cnt;
//				siz[cnt]++;
//			}
//			top--;
//		}
//	};
//	for(int i = 1;i <= n;i++){
//		if(!dfn[i]) tarjan(tarjan, i);
//	}

//	//for(int i = 1;i <= n;i++) cerr << scc[i] << endl;

//	vector<vector<int>>g(n+5);
//	vector<int>d(n+5), f(n+5);
//	for(int i = 1;i <= n;i++) if(scc[i] != scc[a[i]]) {
//		g[scc[a[i]]].push_back(scc[i]);
//		d[scc[i]]++;
//	}

//	int leaf = 0;
//	auto dfs = [&](auto self, int u) -> void {
//		f[u] = 1;
//		if(g[u].empty()){
//			leaf++;
//			return;
//		}
//		for(auto v : g[u]) {
//			self(self, v);
//			(f[u] *= f[v]) %= mod;
//		}
//		(f[u] *= g[u].size()) %= mod;
//	};

//	int ans = 1;
//	for(int i = 1;i <= cnt;i++) if(!d[i]) {
//		dfs(dfs, i);
//		if(g[i].empty()){
//			(ans *= siz[i]) %= mod;
//			continue;
//		}
// 		unordered_map<int,  vector<int>>mp;
//		for(auto v : g[i]) mp[a[sp[v]]].push_back(v);
//		int tmp = 1, dv = 1; 
//		for(auto [k, vec] : mp) {
//			for(auto v : vec){
//				(tmp *= f[v]) %= mod;
//				(dv *= f[v]) %= mod;
//			}
//			(tmp *= vec.size() + 1) %= mod;
//		}
//		tmp -= dv;
//		(tmp += mod) %= mod;
//		cerr << tmp << endl;
//		(ans *= tmp) %= mod;
//	}
//	(ans *= fac[leaf]) %= mod;

//	cout << n-leaf << ' ' << ans << endl;
//}

//signed main(){

//	IO;
//	fac[0] = 1;
//	for(int i = 1;i < N;i++) fac[i] = (fac[i-1] * i) % mod;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long 
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int N = 1e6 + 10;

//void solve(){
//	int n, k, mx = 0;
//	cin >> n >> k;
//	vector<int>a(n+5);
//	set<int>st;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		st.insert(a[i]);
//		k -= a[i];
//		mx = max(mx, a[i]);
//	}

//	if(mx == 0){
//		while(n--) cout << 0 << ' ';
//		cout << endl;
//		return;
//	}

//	cout << mx << ' ';
//	n--;
//	while(k >= mx){
//		cout << mx << ' ';
//		k -= mx;
//		n--;
//	}
//	if(k > 0){
//		cout << k << ' ';
//		n--;
//		if(st.count(k)){
// 			cout << k << ' ';
//			n--;
//		}
//	}
//	while(n--) cout << 0 << ' ';
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int N = 1e6 + 10;

//void solve(){
//	int n;
//	cin >> n;
//	if(n == 2){
//		cout << -1 << endl;
//		return;
//	}
//	vector<vector<int>>a(n+5, vector<int>(n+5));
//	int f = 0;
//	if(n % 2 == 0) {
//		n--;
//		f = 1;
//	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			a[i][j] = ((i-1+j-1) % n) + 1;
//		}
//	}

//	if(f){
//		for(int i = 1;i <= n;i++) a[i][n+1] = a[i][((n-1+i-1)%n)+1];
//		for(int i = 1;i <= n;i++) {a[n+1][i] = a[(i%n)+1][i]; a[(i%n)+1][i]=n+1;}
//		a[n+1][n+1] = n+1;
//		n++;
//	}

//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++) cout << a[i][j] << ' ';
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int N = 1e6 + 10;

//void solve(){
//	int n, m, ze = 0;
//	cin >> n >> m;
//	vector<string>s(n+5);
//	int fx = 0, fy = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> s[i];
//		for(auto c : s[i]) ze += (c == '0');
//		s[i] = ' ' + s[i] + ' ';
//		for(int j = 1;!fx && j <= m;j++) if(s[i][j] == '0') fx = i, fy = j;
//	}
//	if(!fx) {
//		cout << "No\n";
//		return;
//	}
//	if(n == 1 || m == 1){
//		if(ze & 1){
//			cout << "Yes\n";
//			vector<array<int,2>>ans;
//			for(int i = 1;i <= n;i++) 
//				for(int j = 1;j <= m;j++) ans.push_back({i, j});
//				ans.pop_back();
//			for(auto [x, y] : ans) cout << x << ' ' << y << endl;
//		}else{
//			cout << "No\n";
//		}
//		return;
//	}
//	cout << "Yes\n";

//	int rx = 0, ry = 0;
//	if(fx == n) {
//		rx = 1;
//		fx = 1;
//		for(int i = 1, j = n;i < j;i++, j--) swap(s[i], s[j]);
//	}
//	if(fy == m){
//		ry = 1;
//		fy = 1;
//		for(int i = 1, j = m;i < j;i++, j--) {
//			for(int k = 1;k <= n;k++) swap(s[k][i], s[k][j]);
//		}
//	}
//	vector<vector<int>>vis(n+5, vector<int>(m+5));
//	vector<array<int,2>>ans;
//	auto push = [&](int x, int y) {
//		if(vis[x][y] % 2 == 0) {
//			vis[x+1][y]++;
//			vis[x-1][y]++;
//			vis[x][y+1]++;
//			vis[x][y-1]++;
//		}
//		if(rx) x = n-x+1;
//		if(ry) y = m-y+1;
//		ans.push_back({x, y});
//	};
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++) vis[i][j] = s[i][j] - '0';
//	}

//	for(int i = 1;i < fx;i++)
//		for(int j = 1;j <= m;j++) push(i, j);
//	for(int j = 1;j < fy;j++) push(fx, j);
//	for(int j = m;j > fy+1;j--) push(fx, j);

//	for(int i = n;i >= fx+2;i--)
//		for(int j = 1;j <= m;j++) push(i, j);
//	for(int j = 1;j < fy;j++) push(fx+1, j);
//	for(int j = m;j > fy+1;j--) push(fx+1, j);

//	int tmp = 0;
//	tmp += vis[fx][fy];
//	tmp += vis[fx+1][fy];
//	tmp += vis[fx+1][fy+1];
//	tmp += vis[fx][fy+1];
	
//	if(tmp & 1){
//		if(vis[fx+1][fy+1] & 1){
//			push(fx+1, fy+1);
//			push(fx+1, fy);
//			push(fx, fy+1);
//		}else if(vis[fx+1][fy] & 1){
//			push(fx+1, fy);
//			push(fx+1, fy+1);
//			push(fx, fy+1);
//		}else if(vis[fx][fy+1] & 1){
//			push(fx, fy+1);
//			push(fx+1, fy+1);
//			push(fx+1, fy);
//		}
//	}else{
//		push(fx, fy);
//		push(fx, fy+1);
//		push(fx+1, fy);
//	}

//	for(auto [x, y] : ans) cout << x << ' ' << y << endl;

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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int N = 1e6 + 10;

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5, 1);
//	for(int i = 1;i <= n;i++){
//		for(int j = i;j <= n;j += i) if(a[j] % i) a[j] *= i;
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int N = 1e6 + 10;

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<string>sa(n+5), sb(n+5);
//	vector<vector<int>>a(n+5, vector<int>(m+5)), b(n+5, vector<int>(m+5)), s(n+5, vector<int>(m+5));
//	for(int i = 1;i <= n;i++){
//		cin >> sa[i];
//		sa[i] = ' ' + sa[i];
//	}
//	for(int i = 1;i <= n;i++){
//		cin >> sb[i];
//		sb[i] = ' ' + sb[i];
//	}

//	for(int i = 1;i <= n;i++){
//		int tmp = 0;
//		for(int j = 1;j <= m;j++) {
//			a[i][j] = sa[i][j] - '0';
//			b[i][j] = sb[i][j] - '0';
//			s[i][j] = (b[i][j] - a[i][j] + 3) % 3;
//			tmp += s[i][j];
//		}
//		if(tmp % 3) {
//			cout << "NO\n";
//			return;
//		}
//	}
//	for(int j = 1;j <= m;j++){
//		int tmp = 0;
//		for(int i = 1;i <= n;i++){
//			tmp += s[i][j];
//		}
//		if(tmp % 3) {
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
//	while(t--){
//		solve();
//	}

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long 
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int N = 1e6 + 10;

//void solve(){
//	int n;
//	cin >> n;
//	vector<vector<int>>a(3, vector<int>(n+5)), pre(3, vector<int>(n+5));
//	vector<int>p(3), s(3);
//	for(int i = 0;i < 3;i++) {
//		for(int j = 1;j <= n;j++){
//			cin >> a[i][j];
//			pre[i][j] = pre[i][j-1] + a[i][j];
//			//cerr << a[i][j] << ' ';
//		}
//		//cerr << endl;
//	}
//	int av = (pre[0][n] + 2) / 3;

//	//cerr << av << endl;

//	for(int i = 0;i < 3;i++) {
//		int tmp = 0;
//		for(int j = 1;j <= n;j++) {
//			tmp += a[i][j];
//			if(tmp >= av) {
//				p[i] = j;
//				break;
//			}
//		}
//		tmp = 0;
//		for(int j = n;j >= 1;j--) {
//			tmp += a[i][j];
//			if(tmp >= av) {
//				s[i] = j;
//				break;
//			}
//		}
//	}
//	//for(int i = 0;i < 3;i++){
//	//	cerr << p[i] << ' ' << s[i] << endl;
//	//}

//	vector<array<int,2>>ans(3);
//	for(int i = 0;i < 3;i++){
//		for(int j = 0;j < 3;j++) if(i != j && p[i] < s[j]) {
//			int l = p[i]+1, r = s[j]-1;
//			int k;
//			for(k = 0;k == i || k == j;k++);
//			//cerr << i << ' ' << j << ' ' << k << ' ' << l << ' ' << r << endl;
//			if(l <= r && pre[k][r] - pre[k][l-1] >= av){
//				ans[i] = {1, p[i]};
//				ans[j] = {s[j], n};
//				ans[k] = {l, r};
//				for(auto [x, y] : ans) cout << x << ' ' << y << ' ';
//				cout << endl;
//				return;
//			}
//		}
//	}

//	cout << -1 << endl;
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int N = 1e5 + 10;

//int n;

//int tr[N];
//int lowbit(int x){
//	return x & -x;
//}
//void add(int x){
//	while(x <= n){
//		tr[x]++;
//		x += lowbit(x);
//	}
//}
//int getsum(int x){
//	int ret = 0;
//	while(x > 0){
//		ret += tr[x];
//		x -= lowbit(x);
//	}
//	return ret;
//}
//void init(){
//	for(int i = 0;i <= n;i++) tr[i] = 0;
//}

//void solve(){
//	int mcnt = 0;
//	cin >> n;
//	vector<int>a(n+5), b(n+5);
//	unordered_map<int,int>mp, pa, pb;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pa[a[i]] = i;
//		mp[a[i]]++;
//		mcnt = max(mcnt, mp[a[i]]);
//	}
//	for(int i = 1;i <= n;i++){
//		cin >> b[i];
//		pb[b[i]] = i;
//	}
//	sort(all1(a));
//	sort(all1(b));
//	for(int i = 1;i <= n;i++) if(a[i] != b[i]) {
//		cout << "NO\n";
//		return;
//	}
//	if(mcnt > 1) {
//		cout << "YES\n";
//		return;
//	}

//	vector<int>ia(a), ib(b);
//	for(int i = 1;i <= n;i++){
//		ia[pa[a[i]]] = i;
//		ib[pb[b[i]]] = i;
//	}
//	int as = 0, bs = 0;
//	for(int i = 1;i <= n;i++) {
//		//cerr << ia[i] << ' ';
//		as += getsum(n) - getsum(ia[i]);
//		add(ia[i]);
//	}
//	//cerr << endl;
//	init();
//	for(int i = 1;i <= n;i++) {
//		//cerr << ib[i] << ' ';
//		bs += getsum(n) - getsum(ib[i]);
//		add(ib[i]);
//	}
//	//cerr << endl;
//	init();

//	if(abs(as - bs) % 2 == 0) cout << "YES\n";
//	else cout << "NO\n";

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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int N = 5e5 + 10;
//const int mod = 1e9 + 7;

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
//void get_inv(){
//	fac[0] = inv[0] = 1;
//	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//	inv[N-1] = qpow(fac[N-1], mod-2);
//	for(int i = N-2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
//}


//void solve(){
//	int n, k, a = 0, b = 0;
//	cin >> n >> k;
//	vector<int>v(n+5);
//	for(int i = 1;i <= n;i++) cin >> v[i];
//	for(int i = 1;i <= k;i++) a += v[i];
//	for(int i = k+1;i <= n;i++) b += v[i];
//	a %= mod;
//	b %= mod;
//	(a *= inv[k]) %= mod;
//	(b *= inv[n-k]) %= mod;

//	vector<int>p(n+5);
//	vector<array<int,2>>g(n+5), f(n+5);
//	p[1] = k;
//	g[1] = {1, 0};

//	for(int i = 2;i <= n;i++){
//		p[i] = (p[i-1] - (p[i-1] * inv[n] % mod) + mod) % mod;
//		g[i][0] = (g[i-1][0] * (p[i-1] * inv[n] % mod) % mod) + (g[i-1][1] * (((n-p[i-1]+mod)%mod) * inv[n] % mod) % mod);
//		g[i][1] = (g[i-1][1] * (p[i-1] * inv[n] % mod) % mod) + (g[i-1][0] * (((n-p[i-1]+mod)%mod) * inv[n] % mod) % mod);
//	}

//	for(int i = 1;i <= n;i++){
//		int d = (((p[i] * inv[n] % mod) * a % mod) + (((n-p[i]+mod)%mod) * b % mod) % mod);
//		f[i][0] = (f[i-1][0] + (g[i][0] * d % mod)) % mod;
//		f[i][1] = (f[i-1][1] + (g[i][1] * d % mod)) % mod;
//	}

//	cout << f[n][0] << ' ' << f[n][1] << endl;
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int N = 5e5 + 10;
//const int mod = 1e9 + 7;


//void solve(){
//	int n;
//	cin >> n;
//	vector<vector<int>>a;

//	if(n & 1){
//		a.push_back({});	
//		for(int i = 1;i <= n;i++) a.back().push_back(i);

//		int m1 = n/2+1, m2 = n+m1;
//		a.push_back({});	
//		a.back().push_back(1);
//		for(int i = n+1;i < 2*n;i++) a.back().push_back(i);
//		a.push_back({});	
//		for(int i = m2;i <= 2*n;i++) a.back().push_back(i);
//		for(int i = m1+1;i <= n;i++) a.back().push_back(i);

//		a.push_back({});	
//		for(int i = m2;i <= 2*n;i++) a.back().push_back(i);
//		for(int i = 2;i <= m1;i++) a.back().push_back(i);
		
//		a.push_back({});	
//		a.back().push_back(1);
//		for(int i = n+1;i < m2;i++) a.back().push_back(i);
//		a.back().push_back(2*n);
//		for(int i = m1+1;i < n;i++) a.back().push_back(i);
		
//		a.push_back({});	
//		a.back().push_back(n);
//		for(int i = n+1;i < m2;i++) a.back().push_back(i);
//		for(int i = 2;i <= m1;i++) a.back().push_back(i);
//	}else{
//		a.push_back({});	
//		for(int i = 1;i <= n;i++) a.back().push_back(i);
//		a.push_back({});	
//		for(int i = n+1;i <= 2*n;i++) a.back().push_back(i);
		
//		int m1 = n/2, m2 = n+n/2;
//		a.push_back({});
//		for(int i = 1;i <= m1;i++) a.back().push_back(i);
//		for(int i = n+1;i <= m2;i++) a.back().push_back(i);
//		a.push_back({});
//		for(int i = 1;i <= m1;i++) a.back().push_back(i);
//		for(int i = m2+1;i <= 2*n;i++) a.back().push_back(i);
//		a.push_back({});
//		for(int i = m1+1;i <= n;i++) a.back().push_back(i);
//		for(int i = n+1;i <= m2;i++) a.back().push_back(i);
//		a.push_back({});
//		for(int i = m1+1;i <= n;i++) a.back().push_back(i);
//		for(int i = m2+1;i <= 2*n;i++) a.back().push_back(i);
//	}
	
//	//set<pair<int,int>>st;
//	//for(auto &vec : a){
//	//	sort(all(vec));
//	//	if(vec.size() != n){
//	//		cerr << "NONO\n";
//	//		return;
//	//	}
//	//	for(int i = 0;i < n;i++){
//	//		for(int j = i+1;j < n;j++) st.insert({vec[i], vec[j]});
//	//	}
//	//}
//	//for(int i = 1;i <= 2*n;i++){
//	//	for(int j = i+1;j <= 2*n;j++){
//	//		if(st.count({i, j}) == 0) {
//	//			cerr << i << ' ' << j << endl;
//	//		}
//	//	}
//	//}

//	cout << a.size() << endl;
//	for(auto vec : a) {
//		for(auto e : vec) cout << e << ' ';
//		cout << endl;
//	}
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int N = 51;
//const int mod = 1e9 + 7;
//const int inf = 0x3f3f3f3f3f3f3f3f;

//int f[N][N][N][N], v[N];

//void solve(){
//	int n, m1, m2;
//	cin >> n >> m1 >> m2;
//	for(int i = 1;i <= n;i++) cin >> v[i];
//	sort(v+1, v+1+n);
//	//reverse(v+1, v+1+n);

//	for(int i = 1;i <= n;i++){
//		for(int b = 0;b <= m2;b++){
//			for(int j = 0;j <= b;j++){
//				for(int a = 0;a <= m1;a++){
//					if(a) f[i][b][j][a] = f[i][b][j][a-1];
//					for(int k = 0;k <= b-j;k++){
//						if(a-j >= 0) f[i][b][j][a] = max(f[i][b][j][a], f[i-1][b-j][k][a-j]+v[i]);
//						f[i][b][j][a] = max(f[i][b][j][a], f[i-1][b-j][k][a]);
//					}
//				}
//			}
//		}
//	}

//	int ans = inf;
//	for(int j = 0;j <= m2;j++) ans = min(ans, f[n][m2][j][m1]);
//	cout << ans << endl;
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int N = 5e5 + 10;
//const int mod = 1e9 + 7;


//void solve(){
//	string s;
//	cin >> s;
//	s = 'y' + s;
//	int ans = 0;
//	for(int i = 2;i < s.size();i++) if(s[i] == 'y' && s[i-1] == 'x') {
//		if(s[i-2] == 'y'){
//			s[i] = 'x';
//			ans++;
//		}
//	}
//	cout << ans << endl;
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int mod = 1e9 + 7;
//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, m1, m2;
//	cin >> n >> m1 >> m2;
//	vector<int>a(n+5), v(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(all1(a), greater<int>());

//	int ans = inf;
//	auto dfs = [&](auto self, int i, int s, int mn) -> void {
//		if(s == 0){
//			vector<int>f(m1+5);
//			for(int i = 1;i <= n;i++){
//				for(int j = m1;j >= v[i];j--) f[j] = max(f[j], f[j-v[i]]+a[i]);
//			}
//			ans = min(ans, f[m1]);
//			return;
//		}
//		if(i == n){
//			v[i] = s;
//			self(self, i+1, 0, s);
//			v[i] = 0;
//			return;
//		}
//		for(int j = min(mn, s);j >= 1;j--) {
//			if(s-j > n-i) break;
//			v[i] = j;
//			self(self, i+1, s-j, j);
//			v[i] = 0;
//		}
//	};

//	dfs(dfs, 1, m2, m2);

//	cout << ans << endl;

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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int mod = 1e9 + 7;
//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+1), b(n+1);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++) cin >> b[i];
//	sort(all1(a));
//	sort(all1(b));
//	double s = 0;
//	for(int i = 1;i <= n;i++){
//		int gt = b.end() - upper_bound(all1(b), a[i]);
//		int ls = prev(lower_bound(all1(b), a[i])) - b.begin();
//		//cerr << ls << ' ' << gt << endl;
//		s += (1.0 * (ls - gt)) / n;
//	}
//	printf("%.6lf\n", s);

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
//using i32 = signed;
//#define int long long 
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int mod = 1e9 + 7;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 25*1e6;
//const int mxn = 1e9;

//i32 tot, cnt[N], rt, ls[N], rs[N];
//int sum[N];

//void add(i32 &id, int l, int r, int x) {
//	if(!id) id = ++tot;
//	cnt[id]++;
//	sum[id] += x;
//	if(l == r) return;
//	int mid = l + r >> 1;
//	if(x <= mid) add(ls[id], l, mid, x);
//	else add(rs[id], mid + 1, r, x);
//}
//int getsum(int id, int l, int r, int ql, int qr) {
//	if(ql > qr) return 0;
//	if(ql <= l && r <= qr) return sum[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return getsum(ls[id], l, mid, ql, qr);
//	else if(ql > mid) return getsum(rs[id], mid + 1, r, ql, qr);
//	else return getsum(ls[id], l, mid, ql, qr) + getsum(rs[id], mid + 1, r, ql, qr);
//}
//int getcnt(int id, int l, int r, int ql, int qr) {
//	if(ql > qr) return 0;
//	if(ql <= l && r <= qr) return cnt[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return getcnt(ls[id], l, mid, ql, qr);
//	else if(ql > mid) return getcnt(rs[id], mid + 1, r, ql, qr);
//	else return getcnt(ls[id], l, mid, ql, qr) + getcnt(rs[id], mid + 1, r, ql, qr);
//}
//int query(int id, int l, int r, int d, int sm, int ct) {
//	if(l == r) return l;
//	int mid = l + r >> 1;
//	sm += sum[ls[id]];
//	ct += cnt[rs[id]];
//	if(ct*(mid+1) + sm >= (mid+1)*d){
//		return query(rs[id], mid + 1, r, d, sm, ct-cnt[rs[id]]);
//	}else{
//		return query(ls[id], l, mid, d, sm-sum[ls[id]], ct);
//	}
//}

//using i128 = __int128_t;

//void solve(){
//	int n, op, x, sz = 0; 
//	cin >> n;
//	while(n--){
//		cin >> op >> x;
//		if(op == 1){
//			add(rt, 1, mxn, x);
//			sz++;
//		}else{
//			if(x > sz) cout << 0 << endl; 
//			else {
//				//cout << query(rt, 1, mxn, x, 0, 0) << endl;
//				int l = 1, r = sum[rt]/x;
//				while(l <= r){
//					int mid = l + r >> 1;
//					int ct = getcnt(rt, 1, mxn, min(mid+1, mxn+1), mxn);
//					int sm = getsum(rt, 1, mxn, 1, min(mid, mxn));
//					if(ct*mid + sm >= mid*x) l = mid + 1;
//					else r = mid - 1;
//				}
//				cout << (int)r << endl;
//			}
//		}
//	}
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
////using i32 = signed;
//#define int long long 
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()
//#define ls id << 1
//#define rs id << 1 | 1

//const int mod = 1e9 + 7;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 5;

//int cnt[N<<2], sum[N<<2];
//void add(int id, int l, int r, int x, int v) {
//	cnt[id]++;
//	sum[id] += v;
//	if(l == r) return;
//	int mid = l + r >> 1;
//	if(x <= mid) add(ls, l, mid, x, v);
//	else add(rs, mid + 1, r, x, v);
//}
//int getsum(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return sum[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return getsum(ls, l, mid, ql, qr);
//	else if(ql > mid) return getsum(rs, mid + 1, r, ql, qr);
//	else return getsum(ls, l, mid, ql, qr) + getsum(rs, mid + 1, r, ql, qr);
//}
//int getcnt(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return cnt[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return getcnt(ls, l, mid, ql, qr);
//	else if(ql > mid) return getcnt(rs, mid + 1, r, ql, qr);
//	else return getcnt(ls, l, mid, ql, qr) + getcnt(rs, mid + 1, r, ql, qr);
//}
//using i128 = __int128_t;

//void solve(){
//	int n, op, x, sz = 0;
//	vector<array<int,2>>qur;
//	vector<int>idx;
//	cin >> n;
//	for(int i = 1;i <= n;i++){
//		cin >> op >> x;
//		qur.push_back({op, x});
//		if(op == 1) idx.push_back(x); 
//	}
//	sort(all(idx));
//	idx.erase(unique(all(idx)), idx.end());
//	unordered_map<int,int>pos;
//	int m = idx.size();
//	for(int i = 0;i < idx.size();i++) pos[idx[i]] = i+1;

//	int mx = 0;
//	for(auto [op, x] : qur){
//		if(op == 1){
//			add(1, 1, m, pos[x], x);
//			mx = max(mx, x);
//			sz++;
//		}else{
//			if(x > sz) {
//				cout << 0 << endl;
//			}else{
//				int l = 1, r = max(sum[1]/x, 1000000000ll);
//				while(l <= r){
//					int mid = l + r >> 1;
//					int ct = 0;
//					int tmp = upper_bound(all(idx), mid) - idx.begin() + 1;
//					if(tmp <= m) ct = getcnt(1, 1, m, tmp, m);
//					int sm = 0;
//					tmp--;
//					if(tmp >= 1) sm = getsum(1, 1, m, 1, tmp);
					
//					if(ct*mid+sm >= mid*x) l = mid + 1;
//					else r = mid - 1;
//				}
//				int tmp = sum[1]/x;
//				if(tmp >= mx) r = max(r, tmp);
//				cout << r << endl;
//			}
//		}
//	}
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int mod = 1e9 + 7;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 25*1e6;
//const int mxn = 1e9;

//signed tot, cnt[N], rt, ls[N], rs[N];
//int sum[N];

//void add(signed &id, int l, int r, int x) {
//	if(!id) id = ++tot;
//	cnt[id]++;
//	sum[id] += x;
//	if(l == r) return;
//	int mid = l + r >> 1;
//	if(x <= mid) add(ls[id], l, mid, x);
//	else add(rs[id], mid + 1, r, x);
//}
//int query(int id, int l, int r, int d, int sm, int ct) {
//	if(l == r) return l;
//	int mid = l + r >> 1;
//	sm += sum[ls[id]];
//	ct += cnt[rs[id]];
//	if(ct*(mid+1) + sm >= (mid+1)*d){
//		return query(rs[id], mid + 1, r, d, sm, ct-cnt[rs[id]]);
//	}else{
//		return query(ls[id], l, mid, d, sm-sum[ls[id]], ct);
//	}
//}

//void solve(){
//	int n, op, x, sz = 0, mx = 0; 
//	cin >> n;
//	while(n--){
//		cin >> op >> x;
//		if(op == 1){
//			add(rt, 1, mxn, x);
//			mx = max(mx, x);
//			sz++;
//		}else{
//			if(x > sz) cout << 0 << endl; 
//			else{
//				int ans = query(rt, 1, mxn, x, 0, 0);
//				int tmp = sum[rt]/x;
//				if(tmp >= mx) ans = max(tmp, ans);
//				cout << ans << endl;
//			}
//		}
//	}
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int mod = 1e9 + 7;
//const int inf = 0x3f3f3f3f3f3f3f3f;


//void solve(){
//	int n, hd, bk;
//	cin >> n;
//	vector<int>e(n+5), f(n+5), que(n+5);
//	for(int i = 1;i <= n;i++) cin >> e[i];

//	//auto K = [&](int p1, int p2) -> double {
//	//	double x1 = p1, y1 = f[p1] + (p1*p1+p1)/2.0;
//	//	double x2 = p2, y2 = f[p2] + (p2*p2+p2)/2.0;
//	//	return (y2-y1) / (x2-x1);
//	//};
//	auto les = [&](int p1, int p2, int p3, int p4) -> int {
//		int x1 = p1, y1 = f[p1] + (p1*p1+p1)/2;
//		int x2 = p2, y2 = f[p2] + (p2*p2+p2)/2;
//		int x3 = p3, y3 = f[p3] + (p3*p3+p3)/2;
//		int x4 = p4, y4 = f[p4] + (p4*p4+p4)/2;
//		return (y2-y1)*(x4-x3) <= (y4-y3)*(x2-x1);
//	};
//	auto gt = [&](int k, int p1, int p2) -> int {
//		int x1 = p1, y1 = f[p1] + (p1*p1+p1)/2;
//		int x2 = p2, y2 = f[p2] + (p2*p2+p2)/2;
//		return k*(x2-x1) >= (y2-y1);
//	};

//	auto dfs = [&](auto self, int l, int r) -> void {
//		if(l == r) return;
//		int mid = l + r >> 1;
//		self(self, l, mid);

//		hd = 0, bk = -1;
//		for(int i = r, j = mid;i > mid;i--){
//			while(j >= l && 2*e[j+1]*e[j+1] > e[i]*e[i]) {
//				//while(bk-hd+1 >= 2 && K(j, que[bk]) <= K(que[bk], que[bk-1])) bk--;
//				while(bk-hd+1 >= 2 && les(j, que[bk], que[bk], que[bk-1])) bk--;
//				que[++bk] = j--;
//			}
//			//while(bk-hd+1 >= 2 && i >= K(que[hd+1], que[hd])) hd++;
//			while(bk-hd+1 >= 2 && gt(i, que[hd+1], que[hd])) hd++;
//			if(hd <= bk){
//				int d = f[que[hd]] + (que[hd]*que[hd]+que[hd])/2 - i*que[hd];
//				f[i] = max(f[i], d - (i-i*i)/2);
//			}
//		}

//		self(self, mid+1, r);
//	};

//	dfs(dfs, 0, n);

//	cout << f[n] << endl;
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