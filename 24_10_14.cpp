//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'

//int mxn(int x){
//	int mx = 0;
//	while(x){
//		mx = max(mx, (x%10));
//		x /= 10;
//	}
//	return mx;
//}

//void solve(){
//	int l1, l2, r1, r2;
//	cin >> l1 >> r1 >> l2 >> r2;
//	r1 = min(r1, l1+12);
//	r2 = min(r2, l2+12);
//	int mx = 0;
//	for(int i = l1;i <= r1;i++){
//		for(int j = l2;j <= r2;j++){
//			mx = max(mx, mxn(i+j));
//		}
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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), p(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		p[a[i]] = i;
//	}

//	vector<array<int,2>>e;

//	auto mov = [&](int l, int r) -> void {
//		e.push_back({l, r});
//		sort(a.begin()+l, a.begin()+r+1);
//		for(int i = l;i <= r;i++) p[a[i]] = i;
//	};

//	for(int i = 1;i <= n;i++){
//		for(int j = n;j > i;j--) if(a[j] < a[i]) {
//			mov(i, j);
//			break;
//		}
//	}

//	cout << e.size() << endl;
//	for(auto [l, r] : e) cout << l << ' ' << r << endl;
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


//void solve(){
//	string s;
//	cin >> s;
//	int n = s.size();
//	s = ' ' + s;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) if(s[i] == '[' || s[i] == ']') a[i] = 1;
//	stack<int>st;
//	map<int,vector<int>>mp;
//	for(int i = 1;i <= n;i++){
//		if(st.empty()){
//			st.push(a[i]);
//		}else{
//			if(st.top() == a[i]){
//				st.pop();
//				mp[st.size()].push_back(a[i]);
//			}
//			else st.push(a[i]);
//		}
//	}
//	if(st.size()){
//		cout << "No\n";
//		return;
//	}
//	int ok = 0;
//	for(auto [k, v] : mp) if(v.size() >= 2) {
//		if(v.size() == 2){
//			if(v[0] == v[1]){
//				ok = 1;
//				break;
//			}
//		}else{
//			ok = 1;
//			break;
//		}
//	}
//	if(ok) cout << "No\n";
//	else cout << "Yes\n";
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

//const int mod = 1e9 + 7;

//void solve(){
//	int n, m, sum = 0;
//	cin >> n >> m;
//	vector<string>s(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> s[i];
//		for(auto c : s[i]) sum += (c == '1');
//	}
//	if(sum > m){
//		cout << 0 << endl;
//		return;
//	}

//	vector<int>v(m);

//	auto zhuang = [&](string s) -> int {
//		int ret = 0;
//		for(int i = 0;i < m;i++) if(s[i] == '1' && v[i]) {
//			ret++;
//			break;
//		}
//		reverse(all(s));
//		for(int i = 0;i < m;i++) if(s[i] == '1' && v[i]) {
//			ret++;
//			break;
//		}
//		return ret;
//	};

//	int cnt = 0, ans = 1;
//	for(int i = 1;i <= n;i++){
//		int tmp = zhuang(s[i]);
//		if(tmp == 2){
//			cout << 0 << endl;
//			return;
//		}else if(tmp == 0){
//			(ans *= 2) %= mod;
//		}
//		for(int j = 0;j < m;j++) if(s[i][j] == '1' && v[j]) {
//			reverse(all(s[i]));
//			break;
//		}

//		for(int j = 0;j < m;j++) v[j] += s[i][j] - '0';
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

//const int mod = 1e9 + 7;

//void solve(){
//	int n, m, sum = 0;
//	cin >> n >> m;
//	vector<string>mp(n);
//	for(auto &s : mp){
//		cin >> s;
//		for(auto c : s) sum += (c == '1');
//	}
//	if(sum > m){
//		cout << 0 << endl;
//		return;
//	}

//	int ans = 1;
//	vector<int>cnt(m);
//	for(auto s : mp){
//		int tmp = 0;
//		for(int j = 0;j < m;j++) if(s[j] == '1' && cnt[j]) {
//			tmp++;
//			break;
//		}
//		reverse(all(s));
//		for(int j = 0;j < m;j++) if(s[j] == '1' && cnt[j]) {
//			tmp++;
//			break;
//		}
//		if(tmp == 2){
//			cout << 0 << endl;
//			return;
//		}else if(tmp == 1){

//		}else{
//			(ans *= 2) %= mod;
//		}
//		for(int j = 0;j < m;j++) if(s[j] == '1' && cnt[j]) {
//			reverse(all(s));
//			break;
//		}
//		for(int i = 0;i < m;i++) cnt[i] += (s[i] - '0');
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

//void solve(int ti){
//	int n, m;
//	cin >> n >> m;
//	vector<string>s(n+5);
//	vector<int>fa(n+m+5);
//	vector<int>du(m+5);
//	iota(all(fa), 0);

//	auto find = [&](auto self, int x) -> int {
//		return x == fa[x] ? x : fa[x] = self(self, fa[x]);
//	};
//	auto merg = [&](int a, int b) -> void {
//		a = find(find, a);
//		b = find(find, b);
//		fa[a] = b;
//	};

//	int sum = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> s[i];
//		for(auto c : s[i]) sum += (c == '1');
//		s[i] = ' ' + s[i];
//		for(int j = 1;j <= m;j++) if(s[i][j] == '1') {
//			int id = min(j, m-j+1);
//			du[id]++;
//			merg(i, n+id);
//		}
//	}
//	if(sum > m){
//		cout << 0 << endl;
//		return;
//	}
//	for(int i = 1;i <= (m+1)/2;i++) if(du[i] > 2) {
//		cout << "0\n";
//		return;
//	}
//	if((m&1) && du[(m+1)/2] > 1){
//		cout << "0\n";
//		return;
//	}

	
//	vector<int>vis(n+5);
//	int bd = 0;
//	auto dfs = [&](auto self, int u) -> void {
//		//cerr << u << endl;
//		vis[u] = 1;
//		for(int j = 1;j <= m;j++) if(s[u][j] == '1') {
//			int op = min(j, m-j+1);
//			if(op == j) op = m-op+1;
//			for(int k = 1;k <= n;k++) if(k != u && (s[k][j] == '1' || s[k][op] == '1')) {
//				if(s[k][j] == '1'){
//					if(vis[k]){
//						bd = 1;
//						return;
//					}
//					reverse(s[k].begin()+1, s[k].begin()+1+m);
//				}
//				if(!vis[k]) self(self, k);
//			}
//		}
//	};

//	for(int i = 1;i <= n;i++) if(!vis[i]) {
//		dfs(dfs, i);
//		if(bd){
//			//if(ti == 1761) cout << 10;
//			cout << 0 << endl;
//			return;
//		}
//	}

//	set<int>st;
//	for(int i = 1;i <= n;i++) st.insert(find(find, i));
//	cout << qpow(2, st.size()) << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve(i);

//	return 0;
//}