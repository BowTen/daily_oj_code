//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n



//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	if(n == 1){
//		cout << "YES\n";
//		return;
//	}
//	if(n > 2){
//		cout << "NO\n";
//		return;
//	}
//	if(a[1] + 1 < a[2]) cout << "YES\n";
//	else cout << "NO\n";

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
//	int l, r, L, R;
//	cin >> l >> r >> L >> R;
//	int ll = max(l, L);
//	int rr = min(r, R);
//	if(ll > rr) {
//		cout << 1 << endl;
//		return;
//	}

//	int ans = rr-ll;
//	if(min(l, L) < ll) ans++;
//	if(max(r, R) > rr) ans++;
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



//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(all1(a));
//	for(int i = n-1;i >= 1;i -= 2){
//		int d = min(k, a[i+1]-a[i]);
//		k -= d;
//		a[i] += d;
//	}

//	int s = 0;
//	for(int i = n;i >= 1;i--){
//		if((i&1) == (n&1)) s += a[i];
//		else s -= a[i];
//	}
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//map<string,int>mp;
//const int inf = 1e15;

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n+5);
//	vector<string>s(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> s[i];
//		a[i] = mp[s[i]];
//	}
//	vector<array<int,7>>pre(n+5), ne(n+5);
//	vector<int>ls(7, 0);
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= 6;j++) pre[i][j] = ls[j];
//		ls[a[i]] = i;
//	}
//	ls = vector<int>(7,0);
//	for(int i = n;i >= 1;i--){
//		for(int j = 1;j <= 6;j++) ne[i][j] = ls[j];
//		ls[a[i]] = i;
//	}

//	auto lk = [&](int i, int j) -> int {
//		return (s[i][0] == s[j][0] || s[i][0] == s[j][1] || s[i][1] == s[j][0] || s[i][1] == s[j][1]);
//	};

//	int x, y;
//	while(q--){
//		cin >> x >> y;
//		if(lk(x, y)){
//			cout << abs(x-y) << endl;
//			continue;
//		}

//		int ans = inf;
//		if(x > y) swap(x, y);
//		for(int i = 1;i <= 6;i++) if(i != a[x] && i != a[y]) {
//			if(pre[x][i]) ans = min(ans, abs(x-pre[x][i]) + abs(y-pre[x][i]));
//			if(ne[x][i]) ans = min(ans, abs(x-ne[x][i]) + abs(y-ne[x][i]));
//		}

//		if(ans == inf) ans = -1;
//		cout << ans << endl;
//	}
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	mp["BG"] = 1;
//	mp["BR"] = 2;
//	mp["BY"] = 3;
//	mp["GR"] = 4;
//	mp["GY"] = 5;
//	mp["RY"] = 6;
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

//int sg[N];
//void getsg(){
//	sg[1] = 1;
//	for(int i = 1;i <= cnt;i++){
//		for(int j = prime[i];j < N;j += prime[i]) if((j & 1) && !sg[j]) {
//			sg[j] = i;
//		}
//	}
//}

//void solve(){
//	int n;
//	cin >> n;
//	int x = 0;
//	for(int i = 1;i <= n;i++){
//		int a;
//		cin >> a;
//		x ^= sg[a];
//	}
//	if(x) cout << "Alice\n";
//	else cout << "Bob\n";
//}	

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	euler();
//	getsg();
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


//int bit(int x){
//	int ret = 0;
//	while(x){
//		ret += (x & 1);
//		x >>= 1;
//	}
//	return ret;
//}
//int lowbit(int x){
//	return x & -x;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	vector<vector<int>>g(n+5);
//	int cnt = 0;
//	int mxb = 0;
//	for(int i = 1;i <= n;i++) {
//		cin >> a[i];
//		if(!a[i]) {
//			a[i]++;
//			cnt++;
//		}
//		mxb = max(mxb, lowbit(a[i]));
//	}
//	vector<int>it;
//	for(int i = 1;i <= n;i++) if(lowbit(a[i]) == mxb) it.push_back(i);
//	auto pt = [&]() {
//		cout << cnt << endl;
//		for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//		cout << endl;
//	};


//	vector<int>fa(n+5);
//	iota(all(fa), 0);
//	auto find = [&](auto self, int x) -> int {
//		return fa[x] == x ? x : fa[x] = self(self, fa[x]);
//	};
//	auto merg = [&](int a, int b) -> void {
//		a = find(find, a);
//		b = find(find, b);
//		fa[a] = b;
//	};

//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++) if(i != j && (a[i] & a[j])) {
//			merg(i, j);
//			g[i].push_back(j);
//		}
//	}

//	int tmp = 0;
//	for(int i = 1;i <= n;i++) tmp += find(find, i) == i;
//	if(tmp == 1){
//		pt();
//		return;
//	}
//	if(it.size() == 1){
//		cnt++;
//		a[it[0]]--;
//		pt();
//		return;
//	}

//	vector<int>vis(n+5);
//	auto check = [&](int x) -> int {
//		queue<int>que;
//		int f = find(find, x);
//		vis[x] = 1;
//		for(int i = 1;i <= n;i++) if(i != x && f == find(find, i)) {
//			if(a[i]&a[x]){
//				vis[i] = 1;				
//				que.push(i);
//			}
//		}
//		while(que.size()){
//			int u = que.front();
//			que.pop();
//			for(auto v : g[u]) if(!vis[v]){
//				que.push(v);
//				vis[v] = 1;
//			}
//		}
//		int bd = 0;
//		for(int i = 1;i <= n;i++) if(find(find, i) == f) {
//			if(!vis[i]) bd = 1;
//			vis[i] = 0;
//		}
//		if(bd) return 0;

//		set<int>st;
//		for(int i = 1;i <= n;i++){
//			if(a[x] & a[i]) st.insert(find(find, i));
//		}
//		if(st.size() == tmp){
//			pt();
//			return 1;
//		}
//		return 0;
//	};

//	cnt++;
//	for(int i = 1;i <= n;i++){
//		a[i]++;
//		if(check(i)) return ;
//		a[i] -= 2;
//		if(check(i)) return ;
//		a[i]++;
//	}

//	cnt++;
//	a[it[0]]++;
//	a[it[1]]--;
//	pt();
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

//int lowbit(int x){
//	return x & -x;
//}

//void solve(){
//	int x;
//	cin >> x;
//	int y = lowbit(x);

//	if((y^x) == 0){
//		for(int i = 0;;i++) if((1ll<<i)^x){
//			y += (1ll<<i);
//			break;
//		}
//	}
//	cout << y << endl;
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

//int val(int x){
//	int ret = 0;
//	while((x & 1) == 0) {
//		ret++;
//		x >>= 1;
//	}
//	return ret;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a;
//	for(int i = 1, x;i <= n;i++){
//		cin >> x;
//		if(x % 2 == 0){
//			a.push_back(val(x));
//		}
//	}
//	if(a.empty()) {
//		cout << 0 << endl;
//		return;
//	}


//	sort(all(a));
//	int ans = a[0]+a.size()-1;
//	int d = n-a.size();
//	if(d){
//		ans = a.size();
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<string>a(2*n+5);
//	vector<int>cnt(30);
//	for(int i = 1;i <= 2*n;i++){
//		cin >> a[i];
//		for(auto c : a[i]) cnt[c-'a']++; 
//	}
//	string s;
//	cin >> s;
//	for(auto c : s) cnt[c-'a']++; 
//	for(int i = 'a';i <= 'z';i++) if(cnt[i-'a'] & 1) {
//		cout << (char)i << endl;
//		return;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//int S(int a1, int an){
//	int n = an-a1+1;
//	return n*(a1+an)/2;
//}

//void solve(){
//	int n, k, s = 0;
//	cin >> n >> k;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];

//	if(k > n){
//		for(int i = 1;i <= n;i++) s += a[i];
//		s += S(k-n, k-1);
//		cout << s << endl;
//		return;
//	}

//	int cur = 0;
//	for(int i = 1, j = 1;i <= n;i++){
//		cur += a[i];
//		if(i-j == k) cur -= a[j++];
//		s = max(s, cur);
//	} 
//	s += S(1, k-1);
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
////#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	string s(m, '0');
//	vector<int>w(m+5);
//	for(int i = 1;i <= m;i++){
//		s[i-1]++;
//		cout << "? " << s << endl;
//		cin >> w[i];
//		s[i-1]--;
//	}

//	vector<int>idx(m+5);
//	iota(all(idx), 0);
//	sort(idx.begin()+1, idx.begin()+1+m, [&](int i, int j) -> int {
//		return w[i] < w[j];
//	});

//	int ans = 0, tmp;
//	for(int i = 1;i <= m;i++){
//		s[idx[i]-1]++;
//		cout << "? " << s << endl;
//		cin >> tmp;
//		if(tmp-ans && tmp-ans != w[idx[i]]) {
//			s[idx[i]-1]--;
//			continue;
//		}
//		ans = tmp;
//	}
//	cout << "! " << ans << endl;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, s = 0;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		s += a[i];
//	}
//	for(int i = 1;i <= n;i++) if(a[i] * n == s) {
//		cout << "YES\n";
//		return;
//	}
//	cout << "NO\n";
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
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	int ans = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		if(a[i] < a[i-1]){
//			ans++;
//			a[i] = 0;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];

//	if(n & 1){
//		cout << "NO\n";
//		return;
//	}

//	sort(all1(a));
//	for(int i = 1;i <= n/2;i++){
//		if(i < n/2){
//			if(a[i+n/2] <= a[i+1]){
//				cout << "NO\n";
//				return;
//			}
//		}else{
//			if(a[i+n/2] <= a[i]){
//				cout << "NO\n";
//				return;
//			}
//		}
//	}
//	cout << "YES\n";
//	for(int i = 1;i <= n/2;i++){
//		cout << a[i] << ' ' << a[i+n/2] << ' ';
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

//int id(char l, char r){
//	return (l-'A')*2 + (r-'A');
//}

//void solve(){
//	map<int,int>cnt;
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	string s;
//	cin >> s;
//	for(auto c : s) cnt[c]++;
//	if(cnt['A'] != a+c+d || cnt['B'] != b+c+d) {
//		cout << "NO\n";
//		return;
//	}

//	int n = s.size();
//	s = s.front() + s + s.back();

//	vector<vector<int>>len(4);
//	for(int i = 1, j = 1;i <= n+1;i++){
//		if(s[i] == s[i-1]){
//			if(i-1 > j) len[id(s[j], s[i-1])].push_back(i-j);
//			j = i;
//		}
//	}

//	//for(auto &vec : len){
//	//	for(auto le : vec) cerr << le << ' ';
//	//	cerr << endl;
//	//}

//	int dt;
//	sort(all(len[id('A', 'B')]));
//	for(auto &le : len[id('A', 'B')]) {
//		dt = min(c, le/2);
//		c -= dt;
//		le -= dt*2;
//	}
//	for(auto &le : len[id('A', 'A')]) {
//		dt = min(c, le/2);
//		c -= dt;
//		le -= dt*2;
//	}
//	for(auto &le : len[id('B', 'B')]) {
//		dt = min(c, le/2);
//		c -= dt;
//		le -= dt*2;
//	}
//	sort(all(len[id('B', 'A')]), greater<int>());
//	for(auto &le : len[id('B', 'A')]) {
//		dt = min(c, le/2-1);
//		c -= dt;
//		if(dt) le -= (dt+1)*2;
//	}

//	for(int i = 0;i < 4;i++) {
//		for(auto &le : len[i]) if(le >= 2) {
//			int tmp = le/2;
//			if(i == id('A', 'B')) tmp--;
//			dt = min(d, tmp);
//			d -= dt;
//			if(dt) le -= (dt+1)*2;
//		}
//	}

//	if(c > 0 || d > 0) cout << "NO\n";
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int N = 2e5 + 10;

//int a[N];
//int sum[N], rsum[N];
//int n;
//string s;

//bool check() {
//	for(int i = 1 ; i <= n ; i ++){
//		sum[i] = sum[i - 1] + a[i];
//		if(sum[i] < 0) return false;
//	}
//	return true;
//}
 
//void solve() {
	
//	cin >> n;
//	cin >> s;
//	s = ' ' + s;
//	n *= 2;
//	for(int i = 1 ; i <= n ; i ++){
//		if(s[i] == '(') a[i] = 1;
//		else a[i] = -1;
//		sum[i] = sum[i - 1] + a[i];
//	}
//	for(int i = n ; i >= 1 ; i --)
//		rsum[i] = rsum[i + 1] + a[i];
	
	
//	if(check()) {
//		cout << "0\n";
//		return;
//	}
	
//	int minv = n + 1, maxv = 0, pos = 1;
//	for(int i = 1 ; i <= n ; i ++) {
//		if(sum[i] < 0) {
//			minv = min(minv, i);
//			maxv = max(maxv, i);
//		}
//		if(sum[pos] < sum[i]) pos = i;
//	}
	
//	int l = minv, r = maxv;
//	for(int i = maxv + 1 ; i <= n ; i ++)
//		if(sum[r] < sum[i]) r = i;
//	for(int i = minv - 1 ; i >= 1 ; i --)
//		if(rsum[l] > rsum[i]) l = i;
	
//	reverse(a + l, a + r + 1);
//	if(check()) {
//		cout << 1 << "\n";
//		cout << l << " " << r << "\n";
//		return;
//	}
//	cout << 2 << "\n";
//	cout << 1 << " " << pos << "\n";
//	cout << pos + 1 << " " << n << "\n";
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

 
//void solve() {
//	int n;
//	cin >> n;
//	n *= 2;
//	string s;
//	cin >> s;
//	s = ' ' + s + ' ';
//	vector<int>pre(n+5), suf(n+5);
//	int pos = 1, l = n+1, r = 0;
//	for(int i = 1;i <= n;i++){
//		pre[i] = pre[i-1];
//		if(s[i] == '(') pre[i]++;
//		else pre[i]--;
//		if(pre[i] > pre[pos]) pos = i;
//		if(pre[i] < 0){
//			l = min(l, i);
//			r = max(r, i);
//		}
//	}
//	for(int i = n;i >= 1;i--) {
//		suf[i] = suf[i+1];
//		if(s[i] == '(') suf[i]++;
//		else suf[i]--;
//	}

//	if(l == n+1){
//		cout << 0 << endl;
//		return;
//	}

//	auto check = [&]() -> int {
//		int sum = 0;
//		for(int i = 1;i <= n;i++){
//			if(s[i] == '(') sum++;
//			else sum--;
//			if(sum < 0) return 0;
//		}
//		if(sum) return 0;
//		return 1;
//	};

//	for(int i = l-1;i >= 1;i--) if(suf[i] < suf[l]) l = i;
//	for(int i = r+1;i <= n;i++) if(pre[i] > pre[r]) r = i;
//	reverse(s.begin()+l, s.begin()+1+r);
//	if(check()){
//		cout << "1\n" << l << ' ' << r << endl;
//		return;
//	}

//	vector<array<int,2>>ans;
//	if(pos > 1) ans.push_back({1, pos});
//	if(pos+1 < n) ans.push_back({pos+1, n});
//	cout << ans.size() << endl;
//	for(auto [l, r] : ans) cout << l << ' ' << r << endl;

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

 
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n+5), b(n+5), d(n+5), pre(n+5), id(n+1), deg(m+5, 2);
//	iota(all(id), 0);
//	vector<array<int,2>>seg(m+5);
//	vector<vector<int>>qur(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++) cin >> b[i];
//	for(int i = 1;i <= n;i++) d[i] = a[i] - b[i];
//	for(int i = 1;i <= n;i++) pre[i] = pre[i-1] + d[i];
//	for(int i = 1;i <= m;i++){
//		auto &[l, r] = seg[i];
//		cin >> l >> r;
//		qur[l-1].push_back(i);
//		qur[r].push_back(i);
//	}

//	set<int>s(all(id));

//	queue<int> que;
//	for(int i = 0;i <= n;i++) if(!pre[i]) que.push(i), s.erase(i);

//	while(que.size()){
//		auto u = que.front();
//		que.pop();
//		pre[u] = 0;
//		for(auto i : qur[u]) if(!--deg[i]) {
//			auto [l, r] = seg[i];
//			auto lt = s.lower_bound(l), rt = s.upper_bound(r);
//			for(auto it = lt;it != rt;it++) que.push(*it);
//			s.erase(lt, rt);
//		}
//	}

//	for(int i = 1;i <= n;i++) if(pre[i]) {
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

 
//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	map<int,int>mp;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		mp[a[i]]++;
//	}
//	int mx = 0;
//	for(auto [k, v] : mp) mx = max(mx, v);
//	cout << n-mx << endl;
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

 
//void solve() {
//	int n;
//	cin >> n;
//	if(n % 2 == 0) {
//		cout << -1 << endl;
//		return;
//	}
//	vector<int>a(n+5);
//	int mid = (n+1)/2;
//	a[mid] = 1;
//	for(int i = mid+1, j = 2;i <= n;i++, j += 2) a[i] = j;
//	for(int i = mid-1, j = 3;i >= 1;i--, j += 2) a[i] = j;
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
////#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

 
//void solve() {
//	int n;
//	cin >> n;
//	vector<vector<int>>g(n+5);

//	set<int>s1,s2;
//	s1.insert(1);
//	for(int i = 2;i <= n;i++) s2.insert(i);

//	for(int i = 2;i <= n;i++){
//		int u = 1, v = *s2.begin();
//		while(1){
//			cout << "? " << u << ' ' << v << endl;
//			int x;
//			cin >> x;
//			if(x == u){
//				g[u].push_back(v);
//				g[v].push_back(u);
//				s1.insert(v);
//				s2.erase(v);
//				break;
//			}
//			if(s1.count(x)) u = x;
//			else v = x;
//		}
//	}
 
//	for(int i = 1;i <= n;i++) {
//		sort(all(g[i]));
//		g[i].erase(unique(all(g[i])), g[i].end());
//	}

//	vector<array<int,2>>ans;
//	auto dfs2 = [&](auto self, int u, int fa) -> void {
//		for(auto v : g[u]) if(v != fa) {
//			ans.push_back({u, v});
//			self(self, v, u);
//		}
//	};
//	dfs2(dfs2, 1, 0);
//	cout << "! ";
//	for(auto [x, y] : ans) cout << x << ' ' << y << ' ';
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
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin()+1, (x).begin()+1+n
#define ls id << 1
#define rs id << 1 | 1


const int N = 3e5 + 10;
int a[N], n;

int mx[N<<2], mn[N<<2];
int cmp(int i, int j) {
	if(a[i] == a[j]) return min(i, j);
	else if(a[i] > a[j]) return i;
	else return j;
}
int cnp(int i, int j) {
	if(a[i] == a[j]) return min(i, j);
	else if(a[i] < a[j]) return i;
	else return j;
}
void up(int id){
	mx[id] = cmp(mx[ls], mx[rs]);
	mn[id] = cnp(mn[ls], mn[rs]);
}
void build(int id, int l, int r){
	if(l == r){
		mx[id] = mn[id] = l;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	up(id);
}
void change(int id, int l, int r, int x){
	if(l == r){
		mx[id] = 0;
		mn[id] = n+1;
		return;
	}
	int mid = l + r >> 1;
	if(x <= mid) change(ls, l, mid, x);
	else change(rs, mid + 1, r, x);
	up(id);
}
int getmx(int id, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return mx[id];
	int mid = l + r >> 1;
	if(qr <= mid) return getmx(ls, l, mid, ql, qr);
	else if(ql > mid) return getmx(rs, mid + 1, r, ql, qr);
	else return cmp(getmx(ls, l, mid, ql, qr), getmx(rs, mid + 1, r, ql, qr));
}
int getmn(int id, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return mn[id];
	int mid = l + r >> 1;
	if(qr <= mid) return getmn(ls, l, mid, ql, qr);
	else if(ql > mid) return getmn(rs, mid + 1, r, ql, qr);
	else return cnp(getmn(ls, l, mid, ql, qr), getmn(rs, mid + 1, r, ql, qr));
}

 
void solve() {
	cin >> n;
	vector<int>las(n+5), vis(n+5);
	vector<vector<int>>g(n+5);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		las[a[i]] = i;
		g[a[i]].push_back(i);
	}
	a[0] = 0, a[n+1] = n+1;
	build(1, 1, n);

	vector<int>que;
	for(int i = 1;i <= n;i++) if(las[i]) {
		que.push_back(i);
	}

	sort(all(que), [&](int i, int j) -> int {
		return las[i] < las[j];
	});

	vector<int>b;
	int it = 0, l = 1;
	while(it < que.size()){
		int p;
		if(b.size() % 2 == 0) p = getmx(1, 1, n, l, las[que[it]]);
		else p = getmn(1, 1, n, l, las[que[it]]);
		l = p+1;
		b.push_back(a[p]);
		for(auto pos : g[a[p]]) change(1, 1, n, pos);
		vis[a[p]] = 1;
		while(it < que.size() && vis[que[it]]) it++;
	}

	cout << b.size() << endl;
	for(auto e : b) cout << e << ' ';
	cout << endl;
}

signed main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();

	return 0;
}