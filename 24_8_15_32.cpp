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


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1


//const int N = 3e5 + 10;
//int a[N], n;

//int mx[N<<2], mn[N<<2];
//int cmp(int i, int j) {
//	if(a[i] == a[j]) return min(i, j);
//	else if(a[i] > a[j]) return i;
//	else return j;
//}
//int cnp(int i, int j) {
//	if(a[i] == a[j]) return min(i, j);
//	else if(a[i] < a[j]) return i;
//	else return j;
//}
//void up(int id){
//	mx[id] = cmp(mx[ls], mx[rs]);
//	mn[id] = cnp(mn[ls], mn[rs]);
//}
//void build(int id, int l, int r){
//	if(l == r){
//		mx[id] = mn[id] = l;
//		return;
//	}
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//	up(id);
//}
//void change(int id, int l, int r, int x){
//	if(l == r){
//		mx[id] = 0;
//		mn[id] = n+1;
//		return;
//	}
//	int mid = l + r >> 1;
//	if(x <= mid) change(ls, l, mid, x);
//	else change(rs, mid + 1, r, x);
//	up(id);
//}
//int getmx(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return mx[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return getmx(ls, l, mid, ql, qr);
//	else if(ql > mid) return getmx(rs, mid + 1, r, ql, qr);
//	else return cmp(getmx(ls, l, mid, ql, qr), getmx(rs, mid + 1, r, ql, qr));
//}
//int getmn(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return mn[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return getmn(ls, l, mid, ql, qr);
//	else if(ql > mid) return getmn(rs, mid + 1, r, ql, qr);
//	else return cnp(getmn(ls, l, mid, ql, qr), getmn(rs, mid + 1, r, ql, qr));
//}

 
//void solve() {
//	cin >> n;
//	vector<int>las(n+5), vis(n+5);
//	vector<vector<int>>g(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		las[a[i]] = i;
//		g[a[i]].push_back(i);
//	}
//	a[0] = 0, a[n+1] = n+1;
//	build(1, 1, n);

//	vector<int>que;
//	for(int i = 1;i <= n;i++) if(las[i]) {
//		que.push_back(i);
//	}

//	sort(all(que), [&](int i, int j) -> int {
//		return las[i] < las[j];
//	});

//	vector<int>b;
//	int it = 0, l = 1;
//	while(it < que.size()){
//		int p;
//		if(b.size() % 2 == 0) p = getmx(1, 1, n, l, las[que[it]]);
//		else p = getmn(1, 1, n, l, las[que[it]]);
//		l = p+1;
//		b.push_back(a[p]);
//		for(auto pos : g[a[p]]) change(1, 1, n, pos);
//		vis[a[p]] = 1;
//		while(it < que.size() && vis[que[it]]) it++;
//	}

//	cout << b.size() << endl;
//	for(auto e : b) cout << e << ' ';
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


 
//void solve() {
//	int w, d, h, a, b, x, y;
//	cin >> w >> d >> h;
//	cin >> a >> b >> x >> y;
//	int ans = h + abs(a-x) + abs(b-y);
//	ans += min({x, w-x, y, d-y, a, b, w-a, d-b}) * 2;
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


//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n+5), pre(n+5), suf(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pre[a[i]]++;
//		suf[a[i]]++;
//	}
//	for(int i = 1;i <= n;i++) pre[i] += pre[i-1];
//	for(int i = n;i >= 1;i--) suf[i] += suf[i+1];

//	int ans = 0;
//	for(int i = 0;i <= n;i++) if((i-1 >= 0 ? pre[i-1] : 0ll) == i && suf[i+1] == n-i) ans++;
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


//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	vector<int>cnt(30);
//	for(auto c : s) cnt[c-'a']++;
//	vector<int>vec;
//	for(int i = 'a';i <= 'z';i++) if(cnt[i-'a']) vec.push_back(cnt[i-'a']);
//	sort(all(vec));

//	vector<int>d(n+5);
//	int mn = 1;
//	for(int i = 1;i <= min(26ll, n);i++) if(n % i == 0){
//		//cerr << i << " : \n";
//		for(auto e : vec){
//			d[i] += max(0ll, e-n/i);
//			//cerr << max(0ll, e-n/i) << " ";
//		}
//		//cerr << endl;
//		for(int j = 0;j+i < vec.size();j++) d[i] += vec[j];
//		//cerr << d[i] << endl;

//		if(d[i] < d[mn]) mn = i;
//	}

//	//cerr << mn << endl;
//	cout << d[mn] << endl;

//	vector<int>id(26), vis(26);
//	iota(all(id), 0);
//	sort(all(id), [&](int i, int j) -> int {
//		return cnt[i] > cnt[j];
//	});

//	stack<int>st;
//	for(int i = 0;i < mn;i++){
//		vis[id[i]] = 1;
//		for(int j = cnt[id[i]]+1;j <= n/mn;j++) st.push(id[i]);
//	}

//	for(auto &c : s){
//		if(!vis[c-'a'] || cnt[c-'a'] > n/mn) {
//			cnt[c-'a']--;
//			c = st.top()+'a';
//			st.pop();
//		}
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


//int issq(int x){
//	int sq = sqrt(x);
//	return x == (sq*sq);
//}

//int fun(int n, vector<int>a){

//	vector<int>d(n+5), suf(n+5);

//	for(int i = 1;i < n;i++){
//		d[i] = a[i+1] - a[i];
//		cerr << d[i] << " ";
//	}
//	cerr << endl;
//	for(int i = n;i >= 1;i--) suf[i] = suf[i+1] + d[i];

//	int ans = 1;

//	vector<int>c(1, 0);
//	auto check = [&]() -> void {
//		int s;
//		if(c[1] & 1){
//			s = c[1]/2;
//		}else{
//			s = (c[1]/2-1)/2;
//		}
//		s *= s;
//		if(s < a[1]) return;
//		int sum = 0;
//		sum += issq(s);
//		//cerr << s << ' ';
//		for(int i = 1;i < c.size();i++){
//			s += c[i];
//			sum += issq(s);
//			//cerr << s << ' ';
//			cerr << c[i] << " ";
//		}
//		cerr << "   sum=" << sum << endl;
//		ans = max(ans, sum);
//	};

//	auto dfs = [&](auto self, int st) -> void {
//		if(st > n-1) return;
//		int tmp = 0;
//		for(int i = st;i < n-1;i++){
//			tmp += d[i];
//			if(tmp > c.back()){
//				c.push_back(tmp);
//				self(self, i+1);
//				c.pop_back();
//			}
//		}
//		if(suf[st] > c.back()){
//			c.push_back(suf[st]);
//			check();
//			c.pop_back();
//		}else{
//			check();
//		}
//	};

//	dfs(dfs, 1);

//	return ans;
//}

//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n+5), d(n+5), suf(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(all1(a));

//	int ans = 1;
//	for(int i = n;i >= 1;i--){
//		ans = max(ans, fun(i, a));
//		for(int j = 1;j < i;j++) a[j] = a[j+1];
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
////#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int N = 2e5 + 10;
//const int mxn = 1000000000;

//class Tree{
//	#define ls lson[id]
//	#define rs rson[id]
//public:
//	vector<int>mn, tag, lson, rson;
//	int tot, rt;
//	Tree() : mn(N*30), tag(N*30), lson(N*30), rson(N*30), tot(0), rt(0) {}
//	void init(){
//		for(int i = 0;i <= tot;i++) {
//			mn[i] = tag[i] = lson[i] = rson[i] = 0;
//		}
//		tot = rt = 0;
//	}
//	void up(int id){
//		mn[id] = min(mn[ls], mn[rs]);
//	}
//	void settag(int id, int v){
//		mn[id] += v;
//		tag[id] += v;
//	}
//	void down(int id){
//		if(!ls) ls = ++tot;
//		if(!rs) rs = ++tot;
//		settag(ls, tag[id]);
//		settag(rs, tag[id]);
//		tag[id] = 0;
//	}
//	void modify(int &id, int l, int r, int ql, int qr, int v){
//		if(!id) id = ++tot;
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
//	int query(int id, int l, int r, int ql, int qr){
//		if(!id) return 0;
//		if(ql <= l && r <= qr) return mn[id];
//		if(tag[id]) down(id);
//		int mid = l + r >> 1;
//		if(qr <= mid) return query(ls, l, mid, ql, qr);
//		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//		else return min(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//	}
//	void modify(int l, int r, int v){
//		modify(rt, 1, mxn, l, r, v);
//	}
//	int query(int l, int r){
//		return query(rt, 1, mxn, l, r);
//	}
//}t[2];

//void solve() {
//	t[0].init();
//	t[1].init();
//	int n;
//	cin >> n;
//	vector<int>u(n+5), d(n+5), l(n+5), r(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> u[i] >> l[i] >> d[i] >> r[i];
//		if(u[i] == 1) t[0].modify(l[i], r[i], 1);
//		if(d[i] == 2) t[1].modify(l[i], r[i], 1);
//	}

//	for(int i = 1;i <= n;i++){
//		if(u[i] == d[i]){
//			if(t[u[i]-1].query(l[i], r[i]) > 1) {
//				t[u[i]-1].modify(l[i], r[i], -1);
//				l[i] = r[i] = u[i] = d[i] = 0;
//			}
//		}else{
//			if(t[0].query(l[i], r[i]) > 1 && t[1].query(l[i], r[i]) > 1) {
//				t[0].modify(l[i], r[i], -1);
//				t[1].modify(l[i], r[i], -1);
//				l[i] = r[i] = u[i] = d[i] = 0;
//			}
//		}
//	}

//	for(int i = 1;i <= n;i++) if(u[i] != d[i]) {
//		if(t[0].query(l[i], r[i]) > 1){
//			u[i] = 2;
//			t[0].modify(l[i], r[i], -1);
//		}else if(t[1].query(l[i], r[i]) > 1){
//			d[i] = 1;
//			t[1].modify(l[i], r[i], -1);
//		}
//	}

//	set<int>L[2], R[2];
//	for(int i = 1;i <= n;i++) if(u[i]) {
//		if(u[i] == 1){
//			L[0].insert(l[i]);
//			R[0].insert(r[i]);
//		}
//		if(d[i] == 2){
//			L[1].insert(l[i]);
//			R[1].insert(r[i]);
//		}
//	}

//	for(int i = 1;i <= n;i++) if(u[i] && u[i] == d[i]) {
//		int id = u[i]-1;
//		int fr = *R[id].lower_bound(l[i]);
//		if(fr < r[i]){
//			L[id].erase(l[i]);
//			l[i] = fr+1;
//			L[id].insert(l[i]);
//		}
//		int fl = *prev(L[id].upper_bound(r[i]));
//		if(fl > l[i]){
//			R[id].erase(r[i]);
//			r[i] = fl-1;
//			R[id].insert(r[i]);
//		}
//	}

//	set<int>sl, sr;
//	for(int i = 1;i <= n;i++) if(u[i] != d[i]) {
//		sl.insert(l[i]);
//		sr.insert(r[i]);
//	}

//	for(int i = 1;i <= n;i++) if(u[i] != d[i]) {
//		int fr = *sr.lower_bound(l[i]);
//		if(fr < r[i]){
//			sl.erase(l[i]);
//			l[i] = fr+1;
//			sl.insert(l[i]);
//		}
//		int fl = *prev(sl.upper_bound(r[i]));
//		if(fl > l[i]){
//			sr.erase(r[i]);
//			r[i] = fl-1;
//			sr.insert(r[i]);
//		}
//	}

//	int s = 0;
//	for(int i = 1;i <= n;i++) if(u[i]) {
//		if(u[i] == d[i]) s += r[i]-l[i]+1;
//		else s += (r[i]-l[i]+1) * 2;
//	}

//	cout << s << endl;
//	for(int i = 1;i <= n;i++){
//		cout << u[i] << ' ' << l[i] << ' ' << d[i] << ' ' << r[i] << endl;
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



//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = ' ' + s;
//	int q = (n+1)/2;
//	int p = (n+1)/2+2;
//	if(n & 1) p--;
//	int ans = 0;
//	while(q >= 1 && p <= n){
//		if(s[q] != s[p]) break;
//		ans += 2;
//		q--;
//		p++;
//	}
//	if(n & 1) ans++;
//	else ans += 2;
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



//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	for(auto &e : a) cin >> e;
//	int ans = (1ll<<20)-1;
//	for(int i = 0;i < n;i++) if(a[i] != i) ans &= i;
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



//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	map<int,int>mp;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		mp[a[i]]++;
//	}

//	int cnt = 0, ans = 0;
//	for(auto [k, v] : mp){
//		if(v == 1) cnt++;
//		else ans++;
//	}
//	ans += (cnt+1)/2;
	
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
//#define pre(x) (x+n-2)%n+1

//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = ' ' + s;
//	int cnt = 0;
//	for(auto c : s) cnt += (c == '1');
//	if(cnt == 0 || (cnt & 1)){
//		cout << "NO\n";
//		return;
//	}

//	int p = 1;
//	for(int i = 1;i <= n;i++) if(s[i] == '0') {
//		p = i;
//		break;
//	}
//	while(s[pre(p)] == '0') p = pre(p);

//	vector<array<int,2>>g;
//	int ls = p;
//	for(int i = (p%n)+1;i != p;i = (i%n)+1){
//		g.push_back({ls, i});
//		if(s[i] == '1'){
//			ls = p;
//		}else{
//			ls = i;
//		}
//	}

//	cout << "YES\n";
//	for(auto [u, v] : g) cout << u << ' ' << v << endl;

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
//#define pre(x) (x+n-2)%n+1

//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	map<int,int>mp;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		mp[a[i]]++;
//	}

//	if(mp.count(0)){
//		cout << n-mp[0] << endl;
//	}else{
//		if(mp.size() == n) cout << 2+n-1 << endl;
//		else cout << 1+n-1 << endl;
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
//#define pre(x) (x+n-2)%n+1

//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	vector<int>a;

//	int len = 0, ls = s[0];
//	for(auto c : s){
//		if(c == ls) len++;
//		else{
//			a.push_back(len);
//			len = 1;
//			ls = c;
//		}
//	}
//	a.push_back(len);


//	int ans = 0, sum = a.size();
//	int S[2] = {0};
//	ls = -1;
//	for(int i = 0;i < a.size();i++){
//		if(a[i] & 1){
//			if(ls == -1){
//				ls = i;
//			}else{
//				int tmp = i-ls;
//				ans += tmp;

//				if(tmp >= min(S[0], S[1])){
//					int k = 2;
//					if((ls&1) == (i&1)) k = 1;
//					if(min(a[ls], a[i]) == 1 && tmp >= min(S[0], S[1])+1) k = 1;
//					sum -= (i-ls+1) - k;
//				}else{
//					sum -= (a[ls] == 1);
//					sum -= (a[i] == 1);
//				}

//				ls = -1;
//				S[0] = S[1] = 0;
//			}
//		}else{
//			if(ls != -1) S[i&1] += a[i];
//		}
//	}
//	cout << ans << ' ' << sum << endl;
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
//#define pre(x) (x+n-2)%n+1

//const int N = 5005;
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

//void solve() {
//	int n;
//	cin >> n;
//	vector<int>p(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> p[i];
//	}
//	for(int i = 3;i <= n;i++) add(p[i], 1);
	
//	int ans = 0;
//	vector<int>s(n+5);
//	for(int c = 3;c < n;c++){
//		add(p[c], -1);
//		for(int i = c-1;i >= 1;i--) s[i] = getsum(p[i]-1) + s[i+1];
//		for(int a = 1;a+1 < c;a++) if(p[a] < p[c]) {
//			ans += s[a+1];
//		}
//	}
//	add(p[n], -1);

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

//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	int ans = 0, sum = 0, ls = -1;
//	for(int i = 1;i < n;i += 2){
//		if(s[i] != s[i-1]){
//			ans++;
//		}else{
//			sum += (ls != (s[i]-'0'));
//			ls = s[i]-'0';
//		}
//	}
//	cout << ans << " " << max(1ll, sum) << endl;
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
//	string s;
//	cin >> s;
//	s = ' ' + s;

//	vector<vector<int>>r1(n+5, vector<int>(m+5)), row(n+5, vector<int>(m+5));
//	int sum = 0;
//	for(int i = 1, j = 1;i <= n*m;i++){
//		sum += s[i]-'0';
//		if(i-j == m) sum -= s[j++]-'0';
//		r1[(i+m-1)/m][(i-1)%m+1] = (sum > 0);
//	}


//	for(int i = 1;i <= n;i++){
//		row[i] = row[i-1];
//		for(int j = 1;j <= m;j++) row[i][j] += r1[i][j];
//	}
//	//for(int i = 1;i <= n;i++){
//	//	for(int j = 1;j <= m;j++) cerr << r1[i][j] << ' ';
//	//	cerr << endl;
//	//}
//	//cerr << endl;

//	//for(int i = 1;i <= n;i++){
//	//	for(int j = 1;j <= m;j++) cerr << row[i][j] << ' ';
//	//	cerr << endl;
//	//}

//	vector<int>fc(m+5, n*m+1);
//	vector<int>ans(n*m+10);
//	for(int i = 1;i <= m;i++){
//		for(int j = 0;j < n;j++){
//			if(s[i+j*m] == '1') {
//				fc[i] = i+j*m;
//				ans[i+j*m]++;
//				break;
//			}
//		}
//	}

//	for(int i = 1;i <= n*m;i++){
//		ans[i] += ans[i-1];
//		//cerr << ans[i] << ' ';
//	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			int id = (i-1)*m + j;
//			//cerr << id << ' ';
//			ans[id] += row[i][j];
//			cout << ans[id] << ' ';
//		}
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

//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	int cnt = 0;
//	for(auto &e : a) {
//		cin >> e;
//		cnt += (e < 0);
//		e = abs(e);
//	}
//	for(int i = 0;i < cnt;i++) a[i] = -a[i];
//	if(is_sorted(all(a))) cout << "YES\n";
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

//void solve() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	int k;
//	cin >> k;
//	set<char>st;
//	while(k--){
//		char c;
//		cin >> c;
//		st.insert(c);
//	}

//	int ls = 0, mx = 0;
//	for(int i = 0;i < n;i++) if(st.count(s[i])){
//		mx = max(mx, i-ls);
//		ls = i;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

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

//int fa[N], vis[N], n, a[N], b[N], c[N], p[N];
//int find(int x){
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//void merg(int a, int b){
//	a = find(a);
//	b = find(b);
//	fa[a] = b;
//	vis[b] |= vis[a];
//}
//void init(){
//	for(int i = 0;i <= n;i++) {
//		fa[i] = i;
//		vis[i] = 0;
//	}
//}

//void solve() {
//	cin >> n;
//	init();
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++){
//		cin >> b[i];
//		p[b[i]] = i;
//	}
//	for(int i = 1;i <= n;i++){
//		cin >> c[i];
//		if(c[i]) vis[i] = 1;
//	}

//	for(int i = 1;i <= n;i++){
//		if(a[i] == b[i]) vis[i] = 1;
//		merg(i, p[a[i]]);
//	}

//	int cnt = 0;
//	for(int i = 1;i <= n;i++){
//		int f = find(i);
//		//cerr << f << ' ' << vis[f] << endl;
//		if(f == i && vis[i] == 0) cnt++;
//	}

//	cout << qpow(2, cnt) << endl;
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
//	if(x <= 1) return 0;
//	if(x == 2) return 2;
//	int a = x/3, b = x/3, c = x/3;
//	if(x % 3 >= 1) a++;
//	if(x % 3 == 2) b++;
//	return (a*b + a*c + b*c) * 2; 
//}

//void solve() {
//	int n;
//	cin >> n;
//	int l = 2, r = 1e9;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(val(mid) >= n) r = mid - 1;
//		else l = mid + 1;
//	}
//	cout << l << endl;
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
//	int n, p;
//	cin >> p;
//	n = (1<<p);
//	vector<vector<array<int,2>>>g(n+5);
//	vector<int>pw(n+5), ew(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back({v, i});
//		g[v].push_back({u, i});
//	}

//	auto dfs = [&](auto self, int u, int fa, int ad) -> void {
//		pw[u] = u-1 + n*ad;
//		for(auto [v, id] : g[u]) if(v != fa){
//			ew[id] = v-1 + n*ad;
//			self(self, v, u, ad^1);
//		}
//	};
//	dfs(dfs, 1, 0, 1);

//	cout << 1 << endl;
//	for(int i = 1;i <= n;i++) cout << pw[i] << ' ';
//	cout << endl;
//	for(int i = 1;i < n;i++) cout << ew[i] << ' ';
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


//void solve() {
//	string s;
//	cin >> s;
//	if(s.size() < 3 || s[2] == '0'){
//		cout << "NO\n";
//		return;
//	}
//	int a = atoll(s.substr(0, 2).c_str());
//	int b = atoll(s.substr(2).c_str());
//	if(a != 10 || b < 2) cout << "NO\n";
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


//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n+5), vis(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	vis[a[1]] = 1;
//	for(int i = 2;i <= n;i++){
//		if(!vis[a[i]+1] && !vis[a[i]-1]) {
//			cout << "NO\n";
//			return;
//		}
//		vis[a[i]] = 1;
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
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	int m;
//	cin >> m;
//	while(m--){
//		string s;
//		cin >> s;
//		if(s.size() != n){
//			cout << "NO\n";
//			continue;
//		}
//		s = ' ' + s;

//		map<int,int>mp, mp2;
//		int f = 1;
//		for(int i = 1;i <= n;i++){
//			if(!mp.count(s[i])) mp[s[i]] = a[i];
//			else if(mp[s[i]] != a[i]){
//				f = 0;
//				break;
//			}
//			if(!mp2.count(a[i])) mp2[a[i]] = s[i];
//			else if(mp2[a[i]] != s[i]){
//				f = 0;
//				break;
//			}
//		}
//		if(!f) cout << "NO\n";
//		else cout << "YES\n";
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


//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		a[i] += a[i-1];
//	}
//	string s;
//	cin >> s;
//	s = ' ' + s;

//	int l = 1, r = n, ans = 0;
//	while(l < r){
//		while(l < r && s[l] != 'L') l++;
//		while(l < r && s[r] != 'R') r--;
//		if(l < r) ans += a[r] - a[l-1];
//		l++;
//		r--;
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


//void solve() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<vector<int>>pre(n+5, vector<int>(m+5));
//	for(int i = 1;i+k-1 <= n;i++){
//		for(int j = 1;j+k-1 <= m;j++){
//			pre[i][j]++;
//			pre[i+k][j]--;
//			pre[i][j+k]--;
//			pre[i+k][j+k]++;
//		}
//	}

//	vector<int>a;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
//			a.push_back(pre[i][j]);
//		}
//	}

//	int w;
//	cin >> w;
//	vector<int>b(w); 
//	for(auto &e : b) cin >> e;
	
//	sort(all(a), greater<int>());
//	sort(all(b), greater<int>());
//	int ans = 0;
//	for(int i = 0;i < w;i++) ans += a[i] * b[i];

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

//const int inf = 1e15;

//void solve() {
//	int n, k;
//	cin >> n >> k;
//	vector<array<int,2>>a(n+5);
//	vector<vector<int>>val(n+5);
//	int sum = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i][0] >> a[i][1];
//		sum += a[i][0] + a[i][1];
//		if(a[i][0] > a[i][1]) swap(a[i][0], a[i][1]);
		
//		val[i].resize(a[i][0]+a[i][1]+5);
//		auto [x, y] = a[i];
//		int s = x+y;
//		for(int j = 1;j <= s;j++){
//			val[i][j] += val[i][j-1] + x;
//			y--;
//			if(x > y) swap(x, y);
//		}
//	}	

//	if(k > sum){
//		cout << -1 << endl;
//		return;
//	}

//	vector<vector<int>>f(n+5, vector<int>(k+5, inf));
//	f[0][0] = 0;
//	for(int i = 1;i <= n;i++){
//		auto [x, y] = a[i];
//		for(int j = 0;j <= min(k, x+y);j++){
//			int w = val[i][j];
//			for(int z = j;z <= k;z++){
//				f[i][z] = min(f[i][z], f[i-1][z-j] + w);
//			}
//		}
//	}

//	cout << f[n][k] << endl;
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

//const int inf = 1e15;

//void solve() {
//	int n, m, t, t1, t2;
//	cin >> n >> m >> t >> t1 >> t2;
//	vector<vector<array<int,3>>>g(n+5);
//	for(int i = 1, u, v, l1, l2;i <= m;i++){
//		cin >> u >> v >> l1 >> l2;
//		g[u].push_back({v, l1, l2});
//		g[v].push_back({u, l1, l2});
//	}

//	t2 = t-t2;
//	t1 = t-t1;

//	vector<int>dis(n+5, inf);
//	dis[n] = 0;
//	priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>>que;
//	que.push({0, n});
//	while(que.size()){
//		auto [d, u] = que.top();
//		que.pop();
//		if(d > dis[u]) continue;
//		for(auto [v, l1, l2] : g[u]) {
//			int w;
//			if(d+l1 <= t2 || d >= t1) w = l1;
//			else w = min(l2, t1-d+l1);
//			if(d+w < dis[v]){
//				dis[v] = d+w;
//				que.push({dis[v], v});
//			}
//		}
//	}

//	if(dis[1] <= t) cout << t-dis[1] << endl;
//	else cout << -1 << endl;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 1e9;
//const int N = 4e6 + 5;
//const int mxn = 4e6+3;

//int mn[N<<2];
//void up(int id){
//	mn[id] = min(mn[ls], mn[rs]);
//}
//void change(int id, int l, int r, int x, int v){
//	if(l == r){
//		mn[id] = v;
//		return;
//	}
//	int mid = l + r >> 1;
//	if(x <= mid) change(ls, l, mid, x, v);
//	else change(rs, mid + 1, r, x, v);
//	up(id);
//}
//int query(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return mn[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls, l, mid, ql, qr);
//	else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//	else return min(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//}

//set<int>pos[N];
//set<int>st;
//void insert(int x){
//	st.insert(x);
//	int q = *prev(st.lower_bound(x));
//	int p = *next(st.lower_bound(x));
//	int d = p - q - 1;
//	pos[d].erase(q+1);
//	change(1, 1, mxn, d, *pos[d].begin());
//	d = x - q - 1;
//	if(d){
//		pos[d].insert(q+1);
//		change(1, 1, mxn, d, *pos[d].begin());
//	}
//	d = p - x - 1;
//	if(d){
//		pos[d].insert(x+1);
//		change(1, 1, mxn, d, *pos[d].begin());
//	}
//}
//void remov(int x){
//	int q = *prev(st.lower_bound(x));
//	int p = *next(st.lower_bound(x));
//	st.erase(x);
//	int d = x - q - 1;
//	if(d){
//		pos[d].erase(q+1);
//		change(1, 1, mxn, d, *pos[d].begin());
//	}
//	d = p - x - 1;
//	if(d){
//		pos[d].erase(x+1);
//		change(1, 1, mxn, d, *pos[d].begin());
//	}
//	d = p - q - 1;
//	pos[d].insert(q+1);
//	change(1, 1, mxn, d, *pos[d].begin());
//}


//void solve() {
//	int n, m;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		insert(a[i]);
//	}

//	cin >> m;
//	char op;
//	int x;
//	while(m--){
//		cin >> op >> x;
//		if(op == '+'){
//			insert(x);
//		}else if(op == '-'){
//			remov(x);
//		}else{
//			cout << query(1, 1, mxn, x, mxn) << ' ';
//		}	
//	}
//	cout << endl;

//	vector<int>b;
//	for(auto e : st) if(e && e != 4e6+1) b.push_back(e);
//	for(auto e : b) remov(e);
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

//	for(int i = 0;i < (N<<2);i++) mn[i] = inf;
//	for(int i = 1;i < N;i++) pos[i].insert(inf);
//	st.insert(0);
//	st.insert(4e6+1);
//	pos[4000000].insert(1);
//	change(1, 1, mxn, 4000000, 1);

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
//	string s;
//	cin >> s;
//	if(s.front() !=	s.back()) cout << "YES\n";
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


//void solve() {
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(all1(a));
//	cout << a[(n+2)/2] << endl;
	
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
//	string s, a;
//	cin >> s;
//	unordered_map<int,int>mp;
//	for(auto c : s) mp[c]++;

//	while(1){
//		int f = 0;
//		for(auto &[k, v] : mp) if(v){
//			f = 1;
//			a.push_back(k);
//			v--;
//		}
//		if(!f) break;
//	}

//	cout << a << endl;
	
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

//int mex(vector<int>a){
//	set<int>st;
//	for(auto e : a) st.insert(e);
//	int f = 2;
//	for(int i = 0;;i++){
//		if(st.count(i) == 0) f--;
//		if(f == 0) return i;
//	}
//}

//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>a(n+5);
//	int mx = 0;
//	for(int i = 1, l;i <= n;i++){
//		cin >> l;
//		a[i].resize(l);
//		for(auto &e : a[i]) cin >> e;
//		mx = max(mx, mex(a[i]));
//	}

//	int ans = 0;
//	if(m > mx){	
//		ans += mx*mx;
//		n = m-mx;
//		int a1 = mx+1, an = m;
//		ans += n*(a1+an) / 2;
//	}else{
//		ans = mx * m;
//	}
	
//	cout << ans+mx << endl;
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

//array<int,2> mex(vector<int>a){
//	set<int>st;
//	for(auto e : a) st.insert(e);
//	int f = 0;
//	array<int,2>ret;
//	for(int i = 0;;i++){
//		if(st.count(i) == 0) ret[f++] = i;
//		if(f == 2) return ret;
//	}
//}

//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>a(n+5), g;
//	vector<array<int,2>>me(n+5);
//	int mx = 0;
//	for(int i = 1, l;i <= n;i++){
//		cin >> l;
//		a[i].resize(l);
//		for(auto &e : a[i]) cin >> e;
//		me[i] = mex(a[i]);
//		mx = max(mx, me[i][1]);
//	}

//	g.resize(mx + 5);
//	for(int i = 1;i <= n;i++){
//		g[me[i][0]].push_back(me[i][1]);
//	}

//	vector<int>f(mx+5);
//	auto dfs = [&](auto self, int u) -> void {
//		f[u] = u;
//		for(auto v : g[u]) {
//			if(!f[v]) self(self, v);
//			f[u] = max(f[u], f[v]);
//		}
//	};
//	for(int i = 0;i <= mx;i++) if(!f[i]) dfs(dfs, i);
//	int cm = 0;
//	for(int i = 0;i <= mx;i++) if(g[i].size() > 1) cm = max(cm, f[i]);
//	for(int i = 1;i <= n;i++) cm = max(cm, me[i][0]);

//	int ans = 0;
//	if(m > mx){	
//		for(int i = 0;i <= mx;i++) ans += max(cm, f[i]);
//		n = m-mx;
//		int a1 = mx+1, an = m;
//		ans += n*(a1+an) / 2;
//	}else{
//		for(int i = 0;i <= m;i++) ans += max(cm, f[i]);
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

//int n, k, mod;
//int qpow(int a, int b){
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}

//void solve() {
//	cin >> n >> k >> mod;
//	vector<vector<int>>f(n+5, vector<int>(k+5));
//	vector<vector<int>>dp(n+5, vector<int>(k+5));
//	for(int i = 1;i <= n;i++) dp[i][0] = f[i][0] = 1;

//	for(int j = 1;j <= k;j++) dp[1][j] = 1;
//	for(int i = 2;i <= n;i++){
//		dp[i][1] = (qpow(2, i)-1+mod) % mod;
//		for(int j = 2;j <= k;j++){
//			for(int z = 0;z <= j;z++){
//				int tmp = dp[i-1][z] * dp[i-1][j-z] % mod;
//				(dp[i][j] += tmp) %= mod;
//			}
//			(dp[i][j] += dp[i][j-1]) %= mod;
//		}
//	}
//	for(int j = 1;j <= k;j++) f[1][j] = 1;
//	for(int i = 2;i <= n;i++){
//		f[i][1] = qpow(2, i-1);
//		for(int j = 2;j <= k;j++){
//			for(int z = j;z*2 > j;z--){
//				int tmp = f[i-1][z] * 2 % mod;
//				(tmp *= dp[i-1][j-z]) %= mod; 
//				(f[i][j] += tmp) %= mod;
//			}
//			(f[i][j] += f[i][j-1]) %= mod;
//		}
//	}

//	cout << f[n][k] << endl;
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

//const int N = 2e5 + 10;
//int mn[N<<2], cnt[N<<2], tag[N<<2];
//void up(int id){
//	mn[id] = min(mn[ls], mn[rs]);
//	cnt[id] = 0;
//	if(mn[ls] == mn[id]) cnt[id] += cnt[ls];
//	if(mn[rs] == mn[id]) cnt[id] += cnt[rs];
//} 
//void build(int id, int l, int r){
//	tag[id] = 0;
//	if(l == r){
//		mn[id] = 0;
//		cnt[id] = 1;
//		return;
//	}
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//	up(id);
//}
//void settag(int id, int x){
//	mn[id] += x;
//	tag[id] += x;
//}
//void down(int id){
//	settag(ls, tag[id]);
//	settag(rs, tag[id]);
//	tag[id] = 0;
//}
//void modify(int id, int l, int r, int ql, int qr, int v){
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

//void solve() {
//	int n, m;
//	cin >> n >> m;
//	build(1, 1, n);
//	vector<array<int,2>>e(m+5);
//	vector<vector<int>>L(n+5), R(n+5);
//	for(int i = 1;i <= m;i++) {
//		cin >> e[i][0] >> e[i][1];
//		L[e[i][0]].push_back(i);
//		R[e[i][1]].push_back(i);
//		modify(1, 1, n, e[i][0], e[i][1]-1, 1);
//	}

//	int ans = n;
//	for(int i = 1;i <= n;i++){
//		for(auto id : L[i]){
//			auto [l, r] = e[id];
//			modify(1, 1, n, l, r-1, -1);
//			if(l > 1) modify(1, 1, n, 1, l-1, 1);
//			modify(1, 1, n, r, n, 1);
//		}
//		for(auto id : R[i]){
//			auto [l, r] = e[id];
//			modify(1, 1, n, l, r-1, 1);
//			if(l > 1) modify(1, 1, n, 1, l-1, -1);
//			modify(1, 1, n, r, n, -1);
//		}
//		if(mn[1] == 0) ans = min(ans, n-cnt[1]);
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



//void solve() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>d(n+5), it(n+5);
//	vector<int>del(m+5), vis(n+5);
//	vector<array<int,2>>e(m+5);
//	vector<vector<int>>g(n+5), G(n+5);
//	for(int i = 1, u, v, c;i <= m;i++){
//		cin >> u >> v >> c;
//		d[u] ++;
//		d[v] ++;
//		e[i] = {u, v};
//		g[u].push_back(i);
//		g[v].push_back(i);
//		if(!c){
//			G[u].push_back(i);
//			G[v].push_back(i);
//		}
//	}

//	auto dfs = [&](auto self, int u, int fa, int id) -> void {
//		vis[u] = 1;
//		for(auto id : G[u]) {
//			auto [x, y] = e[id];
//			if(x != u) swap(x, y);
//			if(vis[y]) continue;
//			self(self, y, u, id);
//		}
//		if((d[u] & 1) && fa){
//			d[u]--;
//			d[fa]--;
//			del[id] = 1;
//		}
//	};

//	for(int i = 1;i <= n;i++) if(!vis[i]) {
//		dfs(dfs, i, 0, 0);
//		if(d[i] & 1){
//			cout << "NO\n";
//			return;
//		}
//	}

//	vector<int>ans;
//	auto df = [&](auto self, int u) -> void {
//		while(it[u] < g[u].size()){
//			int id = g[u][it[u]++];
//			if(del[id]) continue;
//			del[id] = 1;
//			int v = e[id][0];
//			if(v == u) v = e[id][1];
//			self(self, v);
//		}
//		ans.push_back(u);
//	};
//	df(df, 1);

//	cout << "YES\n";
//	cout << ans.size()-1 << endl;
//	for(auto u : ans) cout << u << ' ';
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


//void solve() {
//	int n, m;
//	cin >> n;
//	vector<int>a(n);
//	for(auto &e : a) cin >> e;
//	sort(all(a));
//	cin >> m;
//	vector<int>b(m);
//	for(auto &e : b) cin >> e;
//	sort(all(b));

//	if(a.back() >= b.back()) cout << "Alice\n";
//	else cout << "Bob\n";
//	if(b.back() >= a.back()) cout << "Bob\n";
//	else cout << "Alice\n";
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
//	int n, m, t = 0;
//	cin >> n;
//	vector<int>a(n);
//	for(auto &e : a) cin >> e;
//	cin >> m;
//	while(m--){
//		int x;
//		cin >> x;
//		t += x;
//	}
//	t %= n;
//	cout << a[t] << endl;
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

//int isst(vector<array<int,2>>a){
//	int mx = 0;
//	for(auto [x, y] : a){
//		if(y < mx) return 0;
//		mx = y;
//	}
//	return 1;
//}

//void solve() {
//	int n;
//	cin >> n;
//	vector<array<int,2>>a(n);
//	for(auto &e : a) cin >> e[0];
//	for(auto &e : a) cin >> e[1];
//	auto b = a;

//	vector<array<int,2>>op;
//	for(int i = 1;i <= n;i++){
//		for(int j = 0;j+1 < n;j++){
//			if(a[j] > a[j+1]){
//				op.push_back({j+1, j+2});
//				swap(a[j], a[j+1]);
//			}
//		}
//	}
//	if(!isst(a)){
//		a = b;
//		for(auto &[x, y] : a) swap(x, y);
//		op.clear();
//		for(int i = 1;i <= n;i++){
//			for(int j = 0;j+1 < n;j++){
//				if(a[j] > a[j+1]){
//					op.push_back({j+1, j+2});
//					swap(a[j], a[j+1]);
//				}
//			}
//		}
//	}
//	if(!isst(a)) cout << -1 << endl;
//	else{
//		cout << op.size() << endl;
//		for(auto [x, y] : op) cout << x << ' ' << y << endl;
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

//int bit(int x){
//	int ret = 0;
//	while(x){
//		ret++;
//		x /= 10;
//	}
//	return ret;
//}
//const int inf = 1e9;

//void solve() {
//	int n, x;
//	cin >> n >> x;
//	map<int,int>mp;

//	auto dfs = [&](auto self, int x) -> void {
//		if(mp.count(x)) return;
//		if(bit(x) == n) {
//			mp[x] = 0;
//			return;
//		}
//		mp[x] = inf;
//		int tmp = x;
//		while(tmp){
//			if(tmp%10 > 1){
//				self(self, x*(tmp%10));
//				mp[x] = min(mp[x], mp[x*(tmp%10)]+1);
//			}
//			tmp /= 10;
//		}
//	};
//	dfs(dfs, x);
//	if(mp[x] == inf) mp[x] = -1;

//	cout << mp[x] << endl;
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


//void solve() {
//	int n;
//	cin >> n;
//	vector<vector<int>>es(n+5);
//	vector<array<int,2>>e(n+5);
//	vector<vector<int>>g(n+5);
//	vector<unordered_map<int,int>>ew(n+5);
//	for(int i = 1, u, v, x;i < n;i++){
//		cin >> u >> v >> x;
//		e[i] = {u, v};
//		es[x].push_back(i);
//		g[u].push_back(v);
//		g[v].push_back(u);
//		ew[u][v] = x;
//		ew[v][u] = x;
//	}


//	int tot = 0;
//	vector<int>dfn(n+5), dep(n+5), siz(n+5);
//	vector<array<int,20>>par(n+5);
//	auto dfs = [&](auto self, int u, int fa) -> void {
//		dfn[u] = ++tot;
//		dep[u] = dep[fa] + 1;
//		par[u][0] = fa;
//		siz[u] = 1;
//		for(int i = 1;i < 20;i++) par[u][i] = par[par[u][i-1]][i-1];
//		for(auto v : g[u]) if(v != fa) {
//			self(self, v, u);
//			siz[u] += siz[v];
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

//	int ans = 0, top = 0;
//	vector<vector<array<int,2>>>G(n+5);
//	vector<int>st(n+5), w(n+5), uw(n+5);
//	for(int i = 1;i <= n;i++) {
//		vector<int>p;
//		for(auto eid : es[i]){
//			p.push_back(e[eid][0]);
//			p.push_back(e[eid][1]);
//		}
//		sort(all(p), [&](int u, int v) -> int { return dfn[u] < dfn[v]; });
//		p.erase(unique(all(p)), p.end());

//		auto add = [&](int u, int v) -> void {
//			if(ew[u].count(v) && ew[u][v] == i){
//				G[u].push_back({v, 1});
//			}else{
//				G[u].push_back({v, 0});
//			}
//		};

//		st[++top] = 1;
//		for(auto u : p) if(u != 1) {
//			int lc = lca(u, st[top]);
//			if(lc == st[top]){
//				st[++top] = u;
//				continue;
//			}
//			while(dep[st[top-1]] >= dep[lc]){
//				add(st[top-1], st[top]);
//				top--;
//			}
//			if(st[top] == lc){
//				st[++top] = u;
//				continue;
//			}
//			add(lc, st[top]);
//			top--;
//			st[++top] = lc;
//			st[++top] = u;
//		}
//		while(top > 1){
//			add(st[top-1], st[top]);
//			top--;
//		}

//		vector<int>tmp;
//		auto dfs = [&](auto self, int u) -> void {
//			w[u] = 1;
//			int sz = 1;
//			tmp.push_back(u);
//			for(auto [v, f] : G[u]) {
//				self(self, v);
//				sz += siz[v];
//				if(!f) w[u] += w[v];
//			}
//			w[u] += siz[u] - sz;
//		};
//		auto dfs2 = [&](auto self, int u, int fw) -> void {
//			uw[u] = fw;
//			for(auto [v, f] : G[u]){
//				if(f) self(self, v, 0);
//				else self(self, v, w[u] - w[v] + fw);
//			}
//		};
//		dfs(dfs, 1);
//		dfs2(dfs2, 1, 0);

//		for(auto eid : es[i]){
//			auto [u, v] = e[eid];
//			if(dep[u] < dep[v]) swap(u, v);
//			ans += w[u] * (uw[v] + w[v]);
//		}

//		for(auto e : tmp){
//			G[e].clear();
//			w[e] = uw[e] = 0;
//		}
//		tmp.clear();
//		top = 0;
//	}

//	cout << ans << endl;
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
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin()+1, (x).begin()+1+n

const int inf = 1e15;
using ll = long long;

void solve() {
	int n, m;
	cin >> n;
	vector<vector<array<int,2>>>p(n+5, vector<array<int,2>>(2));
	for(int i = 1;i < n;i++){
		for(int j = 0;j < 2;j++) cin >> p[i][j][0] >> p[i][j][1];
	}

	vector<array<array<array<int,2>,2>,20>>dis(n+5);

	auto mov = [&](int x, int y, int u, int v) -> int {
		return abs(x-u) + abs(y-v);
	};
	auto nxt = [&](int f1, int id, int x, int y) -> int {
		auto [u, v] = p[f1][id];
		if(id == 0) u++;
		else v++;
		int ret = mov(u, v, x, y) + 1;
		if(id == 0) u--;
		else v--;
		
		auto [uu, vv] = p[f1][id^1];
		int tmp = mov(u, v, uu, vv);
		if(id == 0) vv++;
		else uu++;
		ret = min(ret, tmp+1+mov(uu, vv, x, y));

		return ret;
	};
	auto jump = [&](auto self, int f1, int f2, int id) -> int {
	//auto jump = [&](auto self, int s, int g, int k1, int k2) -> int {
		if(f1 == f2) return 0;
		for(int i = 19;i >= 0;i--) if(f1+(1<<i) <= f2) {
			int ne = f1+(1<<i);
			return self(self, ne, f2, id) + dis[f1][i][id][id];
			//int d[2] = {self(self, ne, f2, 0, y), self(self, ne, f2, 1, y)};
			//return min(dis[f1][i][x][0]+d[0], dis[f1][i][x][1]+d[1]);
		}
		//assert(0);
		//ll dp[2][2];
		//dp[0][k1]=0;
		//dp[0][k1^1]=mov(p[s][k1][0],p[s][k1][1],p[s][k1^1][0],p[s][k1^1][1]);
		//int cur=s,pre=0,now=1;
		//for(int i=19;i>=0;i--)//分解成多个区间
		//	if (cur+(1<<i)<=g)
		//	{
		//		for(int k=0;k<2;k++)
		//			dp[now][k]=min(dp[pre][0]+dis[cur][i][0][k],dp[pre][1]+dis[cur][i][1][k]);
		//		cur += (1<<i);
		//		swap(pre,now);
		//	}
		//return dp[pre][k2];
	};
	auto dist = [&](int x, int y, int u, int v) -> int {
		int f1 = max(x, y), f2 = max(u, v);
		if(f1 == f2) return mov(x, y, u, v);
		if(f1 > f2){
			swap(f1, f2);
			swap(x, u);
			swap(y, v);
		}
		if(f1 + 1 == f2) {
			return min(mov(x, y, p[f1][0][0], p[f1][0][1]) + nxt(f1, 0, u, v),
			 			mov(x, y, p[f1][1][0], p[f1][1][1]) + nxt(f1, 1, u, v));
		}

		f2--;
		int mn = inf;
		for(int i = 0;i < 2;i++){
			int tmp = mov(x, y, p[f1][i][0], p[f1][i][1]) + jump(jump, f1, f2, i) + nxt(f2, i, u, v);
			mn = min(mn, tmp);
		}

		return mn;
	};

	for(int i = 1;i < n;i++){
		for(int x = 0;x < 2;x++){
			for(int y = 0;y < 2;y++){
				dis[i][0][x][y] = nxt(i, x, p[i+1][y][0], p[i+1][y][1]);
			}
		}
	}
	
	for(int j = 1;j < 20;j++){
		for(int i = 1;i <= n;i++){
			for(int x = 0;x < 2;x++){
				for(int y = 0;y < 2;y++) if(i+(1<<j) <= n) {
					int ne = i+(1<<j);
					dis[i][j][x][y] = dist(p[i][x][0],p[i][x][1],p[ne][y][0],p[ne][y][1]);
				}
			}
		}
	}

	cin >> m;
	while(m--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dist(x1, y1, x2, y2) << endl;
	}
}

signed main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) solve();

	return 0;
}