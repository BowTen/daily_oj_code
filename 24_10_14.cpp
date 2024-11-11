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



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const double PI = 3.14159265358979323846;

//struct node{
//	double x, y;
//	int operator<(node e){
//		return x == e.x ? y < e.y : x < e.x;
//	}
//};
//double cross(node p1, node p2, node p3){
//	p2.x -= p1.x, p2.y -= p1.y;
//	p3.x -= p1.x, p3.y -= p1.y;
//	return p2.x * p3.y - p2.y * p3.x;
//}
//double jijiao(double x, double y){
//	double ret = atan2(y, x);
//	return ret;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<node>p(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> p[i].x >> p[i].y;
//	}

//	int top = 0;
//	vector<int>pid(n+5), s(n+5);
//	iota(all(pid), 0);
//	sort(all1(pid), [&](int i, int j) -> int {
//		return p[i] < p[j];
//	});
//	for(int i = 1;i <= n;i++){
//		while(top > 1 && cross(p[s[top-1]], p[s[top]], p[pid[i]]) <= 0) top--;
//		s[++top] = pid[i];
//	}
//	int t = top;
//	for(int i = n-1;i >= 1;i--){
//		while(top > t && cross(p[s[top-1]], p[s[top]], p[pid[i]]) <= 0) top--;
//		s[++top] = pid[i];
//	}

//	vector<int>vis(n+5);
//	for(int i = 1;i <= top;i++){
//		vis[s[i]] = 1;
//	}
//	int ans = 1;
//	for(int i = 1;i <= n;i++) if(!vis[i]) {
//		int tmp = ans;
//		set<double>st;
//		auto [x, y] = p[i];
//		for(int j = 1;j <= n;j++) if(!vis[j] && j != i)
//			st.insert(jijiao(p[j].x - x, p[j].y - y));

//		for(int j = 1;j < top;j++){
//			double j1 = jijiao(p[s[j]].x - x, p[s[j]].y - y);
//			double j2 = jijiao(p[s[j+1]].x-x, p[s[j+1]].y-y);
//			st.insert(j2);
//			auto it1 = st.upper_bound(j1);
//			auto it2 = st.find(j2);
//			if(it1 == it2 || (it1 == st.end() && it2 == st.begin())){
//				ans++;
//			}
//			st.erase(j2);
//		}
//	}
//	cout << ans << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	string a, b;
//	cin >> a >> b;
//	int mx = min(a.size(), b.size());
//	for(int i = 0;i < min(a.size(), b.size());i++) if(a[i] != b[i]) {
//		mx = i;
//		break;
//	}
//	int ans = a.size() + b.size();
//	//cerr << mx << endl;
//	if(mx){
//		ans -= mx;
//		ans += 1;
//	}
//	cout << ans << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

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


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), b(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++) cin >> b[i];
//	for(int i = 1;i <= n;i++) cout << qpow(2, b[i]) << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n+5);
//	map<int,int>mp;
//	for(int i = 1;i <= n;i++) {
//		cin >> a[i];
//		mp[a[i]]++;
//	}

//	queue<array<int,2>>que;
//	int ne = mp.begin()->first, cur = 0, mx = 0;

//	auto add = [&](int k, int v){
//		que.push({k, v});
//		cur += v;
//		mx = max(mx, cur);
//	};
//	auto del = [&](){
//		cur -= que.front()[1];
//		que.pop();
//	};

//	for(auto [k, v] : mp){
//		if(k != ne){
//			while(que.size()) del();
//		}
//		if(que.size() == m) del();
//		add(k, v);
//		ne = k + 1;
//	}
//	cout << mx << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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


//const int N = 5005;
//int mx[N<<2], tag[N<<2];
//void up(int id){
//	mx[id] = max(mx[ls], mx[rs]);
//}
//void settag(int id, int x){
//	mx[id] += x;
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
//int query(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return mx[id];
//	if(tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls, l, mid, ql, qr);
//	else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//	else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//}

//void solve(){
//	int n, m, s = 0;
//	cin >> n >> m;
//	for(int i = 1, x;i <= n;i++){
//		cin >> x;
//		if(x == 0){
//			s++;
//			for(int j = s;j >= 1;j--){
//				int tmp = query(1, 1, m+1, j, j);
//				tmp = max(0, tmp-query(1, 1, m+1, j+1, j+1));
//				if(tmp > 0) modify(1, 1, m+1, j+1, j+1, tmp);
//			}
//		}else if(x > 0){
//			int l = x, r = s;
//			l++, r++;
//			if(l <= r) modify(1, 1, m+1, l, r, 1);
//		}else{
//			x = -x;
//			int l = 0, r = s-x;
//			l++, r++;
//			if(l <= r) modify(1, 1, m+1, l, r, 1);
//		}
//	}
//	cout << mx[1] << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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


//void solve(){
//	int n, m, s = 0;
//	cin >> n >> m;
//	vector<int>pre(m+5);
//	auto add = [&](int l, int r){
//		pre[l]++;
//		pre[r+1]--;
//	};
//	for(int i = 1, x;i <= n;i++){
//		cin >> x;
//		if(x == 0){
//			s++;
//		}else if(x > 0){
//			int l = x, r = s;
//			if(l <= r) add(l, r);
//		}else{
//			x = -x;
//			int l = 0, r = s-x;
//			if(l <= r) add(l, r);
//		}
//	}
//	int mx = pre[0];
//	for(int i = 1;i <= m;i++) {
//		pre[i] += pre[i-1];
//		mx = max(mx, pre[i]);
//	}
//	cout << mx << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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


//const int N = 5005;
//int mx[N<<2], tag[N<<2];
//void up(int id){
//	mx[id] = max(mx[ls], mx[rs]);
//}
//void settag(int id, int x){
//	mx[id] += x;
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
//int query(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return mx[id];
//	if(tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls, l, mid, ql, qr);
//	else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//	else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//}

//void solve(){
//	int n, m, s = 0;
//	cin >> n >> m;
//	for(int i = 1, x;i <= n;i++){
//		cin >> x;
//		if(x == 0){
//			s++;
//			for(int j = s;j >= 1;j--){
//				int tmp = query(1, 1, m+1, j, j);
//				tmp = max(0, tmp-query(1, 1, m+1, j+1, j+1));
//				if(tmp > 0) modify(1, 1, m+1, j+1, j+1, tmp);
//			}
//		}else if(x > 0){
//			int l = x, r = s;
//			l++, r++;
//			if(l <= r) modify(1, 1, m+1, l, r, 1);
//		}else{
//			x = -x;
//			int l = 0, r = s-x;
//			l++, r++;
//			if(l <= r) modify(1, 1, m+1, l, r, 1);
//		}
//	}
//	cout << mx[1] << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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


////void solve(){
////	int n, m, s = 0;
////	cin >> n >> m;
////	vector<int>pre(m+5), f(m+5);
////	for(int i = 1, x;i <= n;i++){
////		cin >> x;
////		if(x == 0){
////			s++;
////			for(int j = 1;j <= s;j++) {
////				pre[j] += pre[j-1];
////				f[j] += pre[j];
////			}
////			pre = vector<int>(m+5);
////			for(int j = s;j >= 1;j--){
////				f[j] = max(f[j], f[j-1]);
////			}
////		}else if(x > 0){
////			int l = x, r = s;
////			l++, r++;
////			if(l <= r) pre[l]++, pre[r+1]--; 
////		}else{
////			x = -x;
////			int l = 0, r = s-x;
////			l++, r++;
////			if(l <= r) pre[l++], pre[r+1]--;
////		}
////	}
////	int mx = 0;
////	for(int i = 0;i <= m+1;i++) mx = max(mx, f[i]);
////	cout << mx << endl;
////}

////signed main(){

////	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
////	int t = 1;
////	//cin >> t;
////	for(int i = 1;i <= t;i++) solve();

////	return 0;
////}


//void solve(){
//	int n, m, s = 0;
//	cin >> n >> m;
//	vector<int>pre(m+5), f(m+5);
//	auto add = [&](int l, int r){
//		pre[l]++;
//		pre[r+1]--;
//	};
//	for(int i = 1, x;i <= n;i++){
//		cin >> x;
//		if(x == 0){
//			s++;
//			f[0] += pre[0];
//			for(int i = 1;i <= s;i++){
//				pre[i] += pre[i-1];
//				f[i] += pre[i];
//			}
//			for(int i = s;i >= 1;i--){
//				f[i] = max(f[i], f[i-1]);
//			}
//			pre = vector<int>(m+5);
//			//for(int i = 0;i <= s;i++) cerr << f[i] << ' ';
//			//cerr << endl;
//		}else if(x > 0){
//			int l = x, r = s;
//			if(l <= r) add(l, r);
//		}else{
//			x = -x;
//			int l = 0, r = s-x;
//			if(l <= r) add(l, r);
//		}
//	}
//	f[0] += pre[0];
//	for(int i = 1;i <= s;i++){
//		pre[i] += pre[i-1];
//		f[i] += pre[i];
//	}
//	for(int i = s;i >= 1;i--){
//		f[i] = max(f[i], f[i-1]);
//	}
//	int mx = 0;
//	for(int i = 0;i <= m;i++) mx = max(mx, f[i]);
//	cout << mx << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//struct node{
//	multiset<int>st;
//	int sum;
//	int size(){
//		return st.size();
//	}
//	int sum(){
//		return sum;
//	}
//};

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		a[i] -= i;
//	}

//	node lst, rst;
//	int mid, r = 1, ans = 1;
//	for(int i = 1;i < n;i++){
//		if()
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int mod = 998244353;


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>g(m+5, vector<int>(m+5));
//	g[0][0] = 1;
//	for(int i = 1;i <= m;i++){
//		for(int j = 0;j <= m;j++){
//			if(j-1 >= 0) (g[i][j] += g[i-1][j-1]) %= mod;
//			(g[i][j] += g[i-1][j+1]) %= mod;
//		}
//	}

//	vector<vector<int>>f(n+5, vector<int>(m+5));
//	for(int j = 0;j <= m;j++) f[1][j] = g[m][j];
//	for(int i = 2;i <= n;i++){
//		for(int j = 0;j <= m;j++) if(j % 2 == 0) {
//			for(int k = j;k <= m;k += 2){
//				int d = k-j;
//				(f[i][j] += f[i-1][k] * g[m][d] % mod) %= mod;
//			}
//		}
//	}

//	cout << f[n][0] << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//string tp = " aeiou";

//void solve(){
//	int n;
//	cin >> n;
//	if(n <= 5){
//		for(int i = 1;i <= n;i++) cout << tp[i];
//		cout << endl;
//		return;
//	}
//	vector<int>cnt(6, n/5);
//	for(int i = 1;i <= n%5;i++) cnt[i]++;
//	for(int i = 1;i <= 5;i++) {
//		while(cnt[i]--) cout << tp[i];
//	}
//	cout << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, m, q;
//	cin >> m >> n >> q;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(all1(a));
//	while(q--){
//		int p;
//		cin >> p;
//		if(p < a[1]){
//			cout << a[1]-1 << endl;
//		}else if(p > a[n]){
//			cout << m-a[n] << endl;
//		}else{
//			int l = *prev(upper_bound(all1(a), p));
//			int r = *upper_bound(all1(a), p);
//			int mid = (l+r)>>1;
//			cout << mid-l << endl;
//		}	
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 1e9;

//string tp = " narek";
//int vis[300];

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<string>s(n+5);
//	for(int i = 1;i <= n;i++) cin >> s[i];


//	vector<vector<int>>f(n+5, vector<int>(6, -inf));
//	f[0][5] = 0;

//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= 5;j++){
//			f[i][j] = max(f[i][j], f[i-1][j]);
//			int pre = j;
//			int val = f[i-1][j];
//			for(int k = 0;k < m;k++) if(vis[s[i][k]]) {
//				val--;
//				if(s[i][k] == tp[(pre%5)+1]){
//					pre = (pre%5)+1;
//					if(pre == 5) val += 10;
//				}
//			}
//			f[i][pre] = max(f[i][pre], val);
//		}
//	}

//	int mx = 0;
//	for(int i = 1;i <= 5;i++) mx = max(mx, f[n][i]);
//	cout << mx << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	for(int i = 1;i <= 5;i++) vis[tp[i]] = 1;
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 1e9;

//void solve(){
//	int l, n, m;
//	cin >> l >> n >> m;
//	vector<int>a(l+5);
//	vector<vector<int>>mp(n+5, vector<int>(m+5));
//	for(int i = 1;i <= l;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			cin >> mp[i][j];
//		}
//	}

//	vector<vector<int>>pre(n+5, vector<int>(m+5));
//	for(int i = n;i >= 1;i--){
//		for(int j = m;j >= 1;j--){
//			if(mp[i][j] == a[l]) pre[i][j] = 1;
//			pre[i][j] |= (pre[i+1][j] | pre[i][j+1]);
//		}
//	}
//	for(int k = l-1;k >= 1;k--){
//		vector<vector<int>>tmp(n+5, vector<int>(m+5));
//		for(int i = n;i >= 1;i--){
//			for(int j = m;j >= 1;j--){
//				if(mp[i][j] == a[k]) tmp[i][j] = (pre[i+1][j+1] ^ 1);
//				tmp[i][j] |= (tmp[i+1][j] | tmp[i][j+1]);
//			}
//		}
//		pre = tmp;
//	}
//	cout << (pre[1][1] ? "T" : "N") << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 1e9;

//void solve(){
//	int n, x, y;
//	cin >> n >> x >> y;
//	if(y <= x) cout << (n+y-1)/y << endl;
//	else cout << (n+x-1)/x << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 1e9;

//void solve(){
//	int n;
//	cin >> n;
//	int s = 0;
//	int x;
//	for(int i = 1;i <= n-2;i++){
//		cin >> x;
//		s += x;
//	}
//	cin >> x;
//	s -= x;
//	cin >> x;
//	s += x;
//	cout << s << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
////#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 1e9;

//void solve(){
//	int n;
//	cin >> n;
//	int p = 0, ret;
//	string s;
//	cout << "? 0" << endl;
//	cin >> ret;
//	if(ret) s = "0";
//	else s = "1";
//	while(s.size() < n){
//		s.push_back('0');
//		cout << "? " << s << endl;
//		cin >> ret;
//		if(!ret){
//			s[s.size()-1] = '1';
//			cout << "? " << s << endl;
//			cin >> ret;
//			if(!ret){
//				s.pop_back();
//				break;
//			}
//		}
//	}	
//	while(s.size() < n){
//		s = '0' + s;
//		cout << "? " << s << endl;
//		cin >> ret;
//		if(!ret) s[0] = '1';
//	}
//	cout << "! " << s << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//const int N=1e2+10;
//const int inf = 1e9;

//void solve()
//{
//	int x;
//	cin>>x;
//	if(x==-1) {
//		cout<<"1 2 1\n";
//		cout<<"2 1 1\n";
//		cout<<"1 1 1\n";
//		return;
//	}
//	cout<<"1 "<<x+1<<" "<<1<<endl;
//	cout<<"1 1 1\n";
//	cout<<"2 1 1\n";
//}
//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//const int N=1e2+10;
//const int inf = 1e9;

//struct node{
//	int r=0, e=0, d=0, re=0, ed=0, red=0;
//	void pt(){
//		cerr << "r="<<r << " e="<<e << " d="<<d << " re="<<re << " ed="<<ed << " red="<<red << endl;
//	}
//};
//node operator+(node a, node b){
//	node c;
//	c.r = a.r + b.r;
//	c.e = a.e + b.e;
//	c.d = a.d + b.d;
//	c.re = a.re + b.re + a.r * b.e;
//	c.ed = a.ed + b.ed + a.e * b.d;
//	c. red = a.red + b.red + a.r*b.ed + a.re * b.d;
//	return c;
//}
//node operator-(node r, node l){
//	node c;
//	c.r = r.r - l.r;
//	c.e = r.e - l.e;
//	c.d = r.d - l.d;
//	c.re = r.re - l.re - l.r*c.e;
//	c.ed = r.ed - l.ed - l.e*c.d;
//	c.red = r.red - l.red - l.r*c.ed - l.re*c.d;
//	return c;
//}


//void solve()
//{
//	int n, q;
//	cin >> n >> q;
//	string s, rs;
//	cin >> s;
//	rs = s;
//	reverse(all(rs));
//	s = ' ' + s;
//	rs = ' ' + rs;

//	vector<node>pre(n+5), suf(n+5), pre2(n+5);
//	for(int i = 1;i <= n;i++){
//		pre[i] = pre[i-1];
//		if(s[i] == 'r'){
//			pre[i].r++;
//		}else if(s[i] == 'e'){
//			pre[i].e++;
//			pre[i].re += pre[i].r;
//		}else if(s[i] == 'd'){
//			pre[i].d++;
//			pre[i].ed += pre[i].e;
//			pre[i].red += pre[i].re;
//		}
//		pre2[i] = pre2[i-1];
//		if(rs[i] == 'r'){
//			pre2[i].r++;
//		}else if(rs[i] == 'e'){
//			pre2[i].e++;
//			pre2[i].re += pre2[i].r;
//		}else if(rs[i] == 'd'){
//			pre2[i].d++;
//			pre2[i].ed += pre2[i].e;
//			pre2[i].red += pre2[i].re;
//		}
//	}

//	for(int i = n;i >= 1;i--){
//		suf[i] = suf[i+1];
//		if(s[i] == 'r'){
//			suf[i].r++;
//			suf[i].re += suf[i].e;
//			suf[i].red += suf[i].ed;
//		}else if(s[i] == 'e'){
//			suf[i].e++;
//			suf[i].ed += suf[i].d;
//		}else if(s[i] == 'd'){
//			suf[i].d++;
//		}
//	}
	
//	//pre[n].pt();
//	//pre2[n].pt();

//	while(q--){
//		int l, r;
//		cin >> l >> r;
//		int l2 = n-r+1, r2 = n-l+1;
//		node lr = pre2[r2] - pre2[l2-1];
//		node b = lr + suf[r+1];
//		node a = pre[l-1];
//		node ans = a+b;
//		//cerr << l2 << ' ' << r2 << endl;
//		//lr.pt();
//		//a.pt();
//		//b.pt();
//		cout << ans.red << endl;	
//	}
//}
//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int a, b, x;
//	cin >> a >> b >> x;
//	if(min(a, b) + x > max(a, b)) cout << "YES\n";
//	else cout << "NO\n";

//}
//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int a[5];
//	for(int i = 1;i <= 3;i++) cin >> a[i];
//	sort(a+1, a+4);
//	int ans = a[1];
//	for(int i = 2;i <= 3;i++) ans = max(ans+a[i], ans*a[i]);
//	cout << ans << endl;
//}
//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//int f(vector<int>a){
//	int ans = a[1];
//	for(int i = 2;i <= 3;i++) ans = max(ans+a[i], ans*a[i]);
//	return ans;
//}

//void solve(){
//	int n = 3;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	int ans = f(a);
//	reverse(all1(a));
//	ans = max(ans, f(a));
//	cout << ans << endl;
//}
//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//vector<array<int,2>> fac(int x){
//	vector<array<int,2>>f;
//	for(int i = 1;i <= abs(x);i++) if(x%i == 0){
//		f.push_back({i, x/i});
//	}
//	vector<array<int,2>>ff;
//	for(auto [a, b] : f) ff.push_back({-a, -b});
//	for(auto a : ff) f.push_back(a);
//	return f;
//}

//void solve(){
//	int a, b, c;
//	cin >> a >> b >> c;
//	auto fa = fac(a);
//	auto fc = fac(c);
//	for(int i = 0;i < fa.size();i++){
//		for(int j = 0;j < fc.size();j++){
//			auto [a1, a2] = fa[i];
//			auto [b1, b2] = fc[j];
//			if(a1*b2 + a2*b1 == b){
//				cout << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << endl;
//				return;
//			}
//			swap(b1, b2);
//			if(a1*b2 + a2*b1 == b){
//				cout << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << endl;
//				return;
//			}
//		}
//	}
//	cout << "NO\n";
//}
//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

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
//int chu(int a, int b){
//	return a * qpow(b, mod-2) % mod;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}

//	vector<int>sum(n+5), lf(n+5), dep(n+5);
//	auto dfs = [&](auto self, int u, int fa) -> void {
//		dep[u] = dep[fa] + 1;
//		int son = 0;
//		for(auto v : g[u]) if(v != fa) {
//			self(self, v, u);
//			son++;
//		}
//		sum[dep[u]]++;
//		if(son == 0) lf[dep[u]]++;
//	};
//	dfs(dfs, 1, 0);

//	int P = 1;
//	int ans = 0;
//	for(int i = 2;i <= n;i++) if(sum[i]) {
//		(ans += (i-1) * (P * chu(lf[i], sum[i]) % mod) % mod) %= mod;
//		(P *= chu(sum[i]-lf[i], sum[i])) %= mod;
//	}
//	cout << ans << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//int check(int x){
//	int sq = sqrt(x);
//	return sq*sq == x;
//}

//void solve(){
//	int n;
//	cin >> n;
//	int cnt = 0;
//	for(int i = 1;i*i <= n;i++){
//		int y = n-i*i;
//		if(check(y)) cnt++;
//	}	
//	if(cnt == 0) cout << "inf\n";
//	else if(cnt == 1) cout << n << endl;
//	else cout << 1 << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int m;
//	cin >> m;
//	cout << (m+1)/2 << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//int f(string s){
//	int ret = 0;
//	for(auto c : s) ret += c-'0';
//	return ret;
//}

//void solve(){
//	int n;
//	cin >> n;
//	int sum = 0;
//	while(n--){
//		string s;
//		cin >> s;
//		sum += f(s);
//	}
//	if(sum % 3 == 0) cout << "YES\n";
//	else cout << "NO\n";
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	double x, y, t, a, b, c;
//	cin >> x >> y >> t >> a >> b >> c;
//	double s = 0;
//	if(x <= t){
//		s = (100-x)/c;
//	}else{
//		s = min((100-x)/b, (x-t)/y + (100-t)/c);
//	}
//	cout << fixed << setprecision(9);
//	cout << s << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	string a;
//	int b;
//	cin >> a >> b;
//	int s = 0;
//	for(auto c : a){
//		s = s*10 + c-'0';
//		s %= b;
//	}
//	cout << gcd(s, b) << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()

//int op[4][2] = {
//	-1, 0, 
//	1, 0,
//	0, -1, 
//	0, 1
//};

//void solve(){
//	int n;
//	cin >> n;
//	vector<vector<int>>a(n+5, vector<int>(n+5)), id(n+5, vector<int>(n+5));
//	int tot = 0;
//	map<int,vector<array<int,2>>>mp;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			cin >> a[i][j];
//			mp[a[i][j]].push_back({i, j});
//			id[i][j] = ++tot;
//		}
//	}

//	vector<int>fa(n*n+10);
//	iota(all(fa), 0);

//	auto find = [&](auto self, int x) -> int {
//		return x == fa[x] ? x : fa[x] = self(self, fa[x]);
//	};
//	auto merg = [&](int a, int b) -> void {
//		a = find(find, a);
//		b = find(find, b);
//		if(a == b) return;
//		fa[a] = b;
//	};

//	for(auto [k, vec] : mp) {
//		for(auto [i, j] : vec){
//			for(int z = 0;z < 4;z++){
//				int x = i+op[z][0], y = j+op[z][1];
//				if(id[x][y] && a[x][y] <= k) merg(id[i][j], id[x][y]);
//			}
//		}
//		if(find(find, id[1][1]) == find(find, id[n][n])){
//			cout << k << '\n';
//			return;
//		}
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()

//const int N = 5e5 + 10;
//int Log[N];
//void init(){
//	for(int i = 2;i < N;i++) Log[i] = Log[i/2] + 1;
//}

//void solve(){
//	init();
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	vector<array<int,20>>mx(n+5), mn(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		a[i] += a[i-1];
//		//cerr << a[i] << ' ';
//		mx[i][0] = a[i];
//		mn[i][0] = a[i];
//	}
//	//cerr << endl;

//	for(int j = 1;j < 20;j++){
//		for(int i = 0;i <= n && i+(1<<j)-1 <= n;i++){
//			mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
//			mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
//		}
//	}

//	auto getmx = [&](int l, int r) -> int {
//		int s = Log[r-l+1];
//		return max(mx[l][s], mx[r-(1<<s)+1][s]);
//	};
//	auto getmn = [&](int l, int r) -> int {
//		int s = Log[r-l+1];
//		return min(mn[l][s], mn[r-(1<<s)+1][s]);
//	};

//	int q;
//	cin >> q;
//	while(q--){
//		int l, r;
//		cin >> l >> r;
//		l--;
//		int a = getmx(l, r);
//		int b = getmn(l, r);
//		cout << a-b << '\n';
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int x;
//	cin >> x;
//	if(x <= 2) cout << "NO\n";
//	else cout << "YES\n" << 1 << ' ' << x-1 << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int a, b, n;
//	cin >> a >> b >> n;
//	b /= 2;
//	int d = min(n/3, b);
//	n -= d*3;
//	b -= d;
//	if(n & 1) a--, n--;
//	a -= n;
//	if(a < 0) cout << "NO\n";
//	else cout << "YES\n";
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	int f = 0;
//	map<int,int>mp;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		if(a[i] < 0) f++;
//		else mp[a[i]]++;
//	}
//	int s = 0;
//	for(auto [k, v] : mp){
//		s += v % 2;
//	}
//	int d = min(s, f);
//	s -= d;
//	f -= d;
//	if(s > 0) cout << s << '\n';
//	else cout << f%2 << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()

//void pop(string &s){
//	for(int i = 0;i+1 < s.size();i++) s[i] = s[i+1];
//	s.pop_back();
//}

//void solve(){
//	int n;
//	cin >> n;
//	string ans;
//	vector<string>a(n+5);
//	priority_queue<pair<int, string>>que;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		int c = a[i].front();
//		pop(a[i]);
//		que.push({c, a[i]});
//	}

//	while(que.size()){
//		auto [c, s] = que.top();
//		que.pop();
//		ans.push_back(c);
//		if(s.size()){
//			int c = s.front();
//			pop(s);
//			que.push({c, s});
//		}
//	}

//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()



//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>fa(n+5), mx(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> mx[i];
//		fa[i] = i;
//	}

//	auto find = [&](auto self, int x) -> int {
//		return x == fa[x] ? x : fa[x] = self(self, fa[x]);
//	};
//	auto merg = [&](int a, int b) -> void {
//		a = find(find, a);
//		b = find(find, b);
//		if(a == b) return;
//		fa[a] = b;
//		mx[b] = max(mx[b], mx[a]);
//	};

//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		merg(u, v);
//	}

//	vector<int>v;
//	for(int i = 1;i <= n;i++) if(mx[find(find, i)]) {
//		v.push_back(mx[find(find, i)]);
//		mx[find(find, i)] = 0;
//	}

//	sort(all(v));
//	int ans = 0;
//	for(int i = 1;i < v.size();i++) ans += v[i];
//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
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
//int C(int a, int b){
//	int x = 1;
//	for(int i = a-b+1;i <= a;i++) (x *= i) %= mod;
//	int c = 1;
//	for(int i = 1;i <= b;i++) (c *= i) %= mod;
//	return x * qpow(c, mod-2) % mod;
//}

//void solve(){
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	if(n & 1) {
//		cout << 0 << endl;
//		return;
//	}
//	int wh = 0, l = n/2;
//	for(auto c : s){
//		wh += (c == '?');
//		l -= (c == '(');
//	}
//	cout << C(wh, l) << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	map<string, int>mp;
//	string s;
//	int mx = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> s;
//		mx = max(mx, ++mp[s]);
//	}
//	int cnt = 0;
//	for(auto [k, v] : mp) if(v == mx) {
//		s = k;
//		cnt++;
//	}
//	if(mx*2 > n) cout << s << '\n';
//	else cout << "uh-oh\n";
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>a(n+5, vector<int>(m+5));
//	map<int, vector<array<int,2>>>mp;
//	for(int i = 1;i <= n;i++) {
//		for(int j = 1;j <= m;j++){
//			cin >> a[i][j];
//			mp[a[i][j]].push_back({i, j});
//		}
//	}

//	int ans = 0, sum = 0;
//	for(auto [k, vec] : mp) {
//		sort(all(vec), [&](array<int,2>a, array<int,2>b) -> int {
//			return a[0] < b[0];
//		});
//		for(int i = 0;i+1 < vec.size();i++){
//			int d = vec[i+1][0] - vec[i][0];
//			ans += d * (i+1) * (vec.size() - (i+1)) * 2;
//		}
//		sort(all(vec), [&](array<int,2>a, array<int,2>b) -> int {
//			return a[1] < b[1];
//		});
//		for(int i = 0;i+1 < vec.size();i++){
//			int d = vec[i+1][1] - vec[i][1];
//			ans += d * (i+1) * (vec.size() - (i+1)) * 2;
//		}

//		//for(auto [x, y] : vec){
//		//	for(auto [xx, yy] : vec){
//		//		sum += abs(x-xx);
//		//		sum += abs(y-yy);
//		//	}
//		//}

//		//cerr << ans << ' ' << sum << '\n';
//	}

//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define fd(x) find(find, (x))

//const int inf = 2e9;

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<vector<array<int,2>>>g(n+5);
//	vector<array<int,3>>e;
//	for(int i = 1, u, v, w;i <= m;i++){
//		cin >> u >> v >> w;
//		e.push_back({u, v, w});
//		g[u].push_back({v, w});
//		g[v].push_back({u, w});
//	}

//	auto dij = [&](int st) -> vector<int> {
//		vector<int>dis(n+5, inf);
//		dis[st] = 0;
//		priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>>que;
//		que.push({0, st});
//		while(que.size()){
//			auto [d, u] = que.top();
//			que.pop();
//			if(d > dis[u]) continue;
//			for(auto [v, w] : g[u]) if(max(d, w) < dis[v]) {
//				dis[v] = max(w, d);
//				que.push({dis[v], v});
//			}
//		}
//		return dis;
//	};

//	auto d1 = dij(1);
//	auto dn = dij(n);

//	//for(int i = 1;i <= n;i++) cerr << d1[i] << ' ';
//	//cerr << '\n';
//	//for(int i = 1;i <= n;i++) cerr << dn[i] << ' ';
//	//cerr << '\n';

//	int ans = inf;
//	for(auto [u, v, w] : e) {
//		//ans = min({ans, w + d1[u] + dn[v], w + d1[v] + dn[u]});
//		if(w >= d1[u] && w >= dn[v]) ans = min(ans, w + max(d1[u], dn[v]));
//		if(w >= d1[v] && w >= dn[u]) ans = min(ans, w + max(d1[v], dn[u]));
//		//cerr << u << ' ' << v << ' ' << w << ' ' << ans << '\n';
//	}
//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()

//const int mod = 998244353;
//const int N = 3e6 + 10;

//struct node{
//	int siz, len, ne[26], fail;
//	node(int _len = 0){
//		len = _len;
//		fail = siz = 0;
//		memset(ne, 0, sizeof(ne));
//	}
//	void pt(){
//		cerr << len << ' ' << fail << ' ' << siz << '\n';
//	}
//};
//struct Tree{
//	int last, sum, tot = 1;
//	node tr[N];
//	string s;

//	void init(string _s){
//		s = " " + _s;
//		for(int i = 1;i < s.size();i++) insert(s[i]-'0', i);
//		//dfs();
//	}

//	void dfs(){
//		for(int i = tot;i >= 2;i--) tr[tr[i].fail].siz += tr[i].siz;
//	}

//	Tree(){
//		tr[1] = node(-1);
//		tr[0].fail = 1;
//	}

//	int getfa(int x, int p){
//		while(s[p-tr[x].len-1] != s[p]){
//			x = tr[x].fail;
//		}
//		return x;
//	}
//	void insert(int c, int p){
//		int fa = getfa(last, p);
//		int cur = tr[fa].ne[c];
//		if(!cur){
//			cur = ++tot;
//			tr[cur] = node(tr[fa].len+2);
//			tr[cur].fail = tr[getfa(tr[fa].fail, p)].ne[c];
//			tr[cur].siz = tr[tr[cur].fail].siz + 1;
//			tr[fa].ne[c] = cur;
//		}
//		sum += tr[cur].siz;
//		last = cur;
//	}
//}tr1, tr2;

//int jian(int a, int b){
//	a -= b;
//	while(a < 0) a += mod;
//	return a;
//}

//void solve(){
//	string s;
//	int n;
//	cin >> n >> s;
//	tr1.init(s);
//	s += s;
//	tr2.init(s);


//	int ans = 0;
//	for(int i = 1;i <= tr2.tot;i++) {
//		auto nd = tr2.tr[i];
//		if(nd.len > n || nd.len < 1) continue;
//		(ans += nd.len * (nd.siz * nd.siz % mod)) %= mod;
//	}
//	for(int i = 1;i <= tr1.tot;i++) {
//		auto nd = tr1.tr[i];
//		if(nd.len > n || nd.len < 1) continue;
//		cerr << nd.len << ' ' << nd.siz << '\n';
//		ans = jian(ans, nd.len * (4 * nd.siz * nd.siz % mod) % mod);
//		(ans += nd.len * (nd.siz * nd.siz % mod)) %= mod;
//	}

//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define fd(x) find(find, (x))

//const int mod = 998244353;
//const int N = 3e6 + 10;

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
//	last = sum = 0;
//	tot = 1;
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

//void dfs(){
//	for(int i = tot;i >= 2;i--) tr[tr[i].fail].siz += tr[i].siz;
//}

//int jian(int a, int b){
//	a -= b;
//	while(a < 0) a += mod;
//	return a;
//}

//void solve(){
//	string s;
//	int n, ans = 0;
//	cin >> n >> s;
//	s = ' ' + s + s;

//	init();
//	for(int i = 1;i <= n;i++) insert(s[i]-'0', i);
//	dfs();
//	for(int i = 2;i <= tot;i++)if(tr[i].len <= n){
//		ans = jian(ans, tr[i].len * ((tr[i].siz*2) * (tr[i].siz*2) % mod) % mod);
//		(ans += tr[i].len * (tr[i].siz * tr[i].siz % mod) % mod) %= mod;
//	}
//	init();
//	for(int i = 1;i <= n*2;i++) insert(s[i]-'0', i);
//	dfs();
//	for(int i = 2;i <= tot;i++){
// 		(ans += tr[i].len * (tr[i].siz * tr[i].siz % mod) % mod) %= mod;
//	}

//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	int s = 0;
//	for(int i = 1, x;i <= n*2;i++){
//		cin >> x;
//		s += x;
//	}
//	if(s > n) s = 2*n-s;
//	cout << (s%2) << ' ' << s << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	if(k == (n+1)/2){
//		cout << "1\n1\n";
//	}else{
//		if(k == 1 || k == n){
//			cout << "-1\n";
//		}else{
//			int l = k, r = k+1;
//			if(l & 1) {l--; r++;}
//			if(l <= 1 || r > n) cout << "-1\n";
//			else cout << "3\n" << 1 << ' ' << l << ' ' << r << '\n';
//		}
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(all1(a));
//	//for(int i = 1;i <= n;i++) cerr << a[i] << ' ';
//	//cerr << '\n';

//	int ans = n;
//	for(int i = 0, r = 1;i < n;i++){
//		while(r <= n && a[i+1] + a[i+2] > a[r]) r++;
//		ans = min(ans, i + (n-r+1));
//	}
//	for(int i = n+1, l = n-1;i > 1;i--){
//		while(l >= 1 && a[l] + a[l+1] > a[i-1]) l--;
//		ans = min(ans, (n-i+1) + l);
//	}
//	cout << ans << '\n';

//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, r;
//	cin >> n;
//	vector<int>p(n);

//	auto ask = [&](int a, int b) -> void {
//		cout << "? " << a << ' ' << b << endl;
//		cin >> r;
//	};

//	ask(1, 2);
//	if(r == 0){
//		cout << "! ";
//		for(int i = 1;i < n;i++) cout << i-1 << ' ';
//		cout << endl;
//		return;
//	}
//	set<int>st;
//	int i = 3;
//	for(;;i++){
//		ask(1, i);
//		if(!r){
//			p[i] = 1;
//			for(int j = 2;j <= i;j++) st.insert(j);
//			i++;
//			break;
//		}
//	}

//	for(;i < n;i++){
//		if(st.size() == 1){
//			p[i] = *st.begin();
//			st.erase(st.begin());
//			st.insert(i);
//			continue;
//		}
//		while(1){
//			ask(*st.begin(), i);
//			if(r){
//				st.erase(st.begin());
//				continue;
//			}
//			p[i] = *st.begin();
//			st.erase(st.begin());
//			st.insert(i);
//			break;
//		}
//	}

//	cout << "! ";
//	for(int i = 1;i < n;i++) cout << p[i] << ' ';
//	cout << endl;
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int x, y, k;
//	cin >> x >> y >> k;
//	int m = min(x, y);
//	cout << "0 0 " << m << ' ' << m << '\n';
//	cout << 0 << ' ' << m << ' ' << m << ' ' << 0 << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	if(n % 2 == 0){
//		int mn = 1;
//		for(int i = 2;i <= n;i += 2) mn = max(mn, a[i]-a[i-1]);
//		cout << mn << '\n';
//	}else{
//		int ans = 1e18;
//		for(int i = 1;i <= n;i += 2){
//			int mn = 1;
//			for(int j = 2;j < i;j += 2) mn = max(mn, a[j]-a[j-1]);
//			for(int j = i+2;j <= n;j += 2) mn = max(mn, a[j]-a[j-1]);
//			ans = min(ans, mn);
//		}
//		cout << ans << '\n';
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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
//	string s;
//	cin >> s;
//	s = ' ' + s;
//	int ans = n*(n+1)/2;

//	deque<int>q1, q0;
//	for(int i = 1;i <= n;i++){
//		if(s[i] == '1') q1.push_back(i);
//		else q0.push_back(i);
//	}

//	while(q1.size()){
//		int u = q1.back();
//		q1.pop_back();
//		while(q0.size() && q0.back() > u) q0.pop_back();
//		if(q0.size()){
//			q0.pop_back();
//			ans -= u;
//			continue;
//		}
//		if(q1.size()){
//			q1.pop_front();
//			ans -= u;
//			continue;
//		}
//	}

//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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
//	vector<int>a(n+5), sum(n+5), L(n+5), R(n+5), psum(n+5), pa(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = n;i >= 1;i--){
//		sum[i] = sum[i+1] + (n-i+1) * a[i];
//		//cerr << i <<  ' '  << sum[i] << '\n';
//	}
//	for(int i = 1;i <= n;i++){
//		psum[i] = psum[i-1] + sum[i];
//		pa[i] = pa[i-1] + a[i];
//		L[i] = R[i-1] + 1;
//		R[i] = L[i] + (n-i);
//	}

//	auto pre = [&](int id, int x) -> int {
//		int r = id + x;
//		int ret = sum[id];
//		ret -= sum[r];
//		ret -= (pa[id+x-1] - pa[id-1]) * (n-r+1);
//		return ret;
//	};
//	auto suf = [&](int id, int x) -> int {
//		return sum[id] - pre(id, (n-id+1)-x);
//	};	

//	int q;
//	cin >> q;
//	while(q--){
//		int l, r;
//		cin >> l >> r;
//		//cerr << l << ' ' << r<< '\n';
//		int lid = lower_bound(all1(R), l) - R.begin();
//		int rid = lower_bound(all1(R), r) - R.begin();
//		//cerr << lid << ' ' << rid << '\n';

//		int ans = 0;
//		ans += psum[rid] - psum[lid-1];
//		//cerr << ans << '\n';
//		ans -= pre(lid, l-L[lid]);
//		//cerr << ans << '\n';
//		ans -= suf(rid, R[rid]-r);
//		//cerr << ans << '\n';

//		cout << ans << '\n';
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//int bit(int x){
//	int ret = 0;
//	while(x) {
//		ret += (x & 1);
//		x >>= 1;
//	}
//	return ret;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), f(n+5, -1000), b(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(all1(a), [&](int i, int j) -> int {
//		return bit(i) < bit(j);
//	});

//	int ans = 0;
//	f[0] = 0;
//	for(int i = 1;i <= n;i++){
//		for(int j = 0;j < i;j++){
//			int nb = (b[j] | a[i]);
//			int d = bit(nb) - bit(b[j]);
//			int tmp = f[j]+1-d;
//			//cerr << tmp << '\n';
//			if(tmp == f[i]){
//				if(bit(nb) > bit(b[i])){
//					b[i] = nb;
//				}
//			}else if(tmp > f[i]){
//				f[i] = tmp;
//				b[i] = nb;
//			}
//		}
//		ans = max(ans, f[i]);
//	}
//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//int mod;
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
//	int a, b;
//	cin >> a >> b >> mod;
//	for(int i = 1;i <= b;i++) a = qpow(a, i);
//	cout << a << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>w(n+5), h(n+5);
//	int m1 = 0, m2 = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> w[i] >> h[i];
//		m1 = max(m1, w[i]);
//		m2 = max(m2, h[i]);
//	}
//	cout << (m1+m2)*2 << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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
//	int ans = n;
//	for(int i = 1;i <= n;i++){
//		int s = i-1;
//		for(int j = i+1;j <= n;j++) s += (a[j] > a[i]);
//		ans = min(ans, s);
//	}
//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	map<int, vector<int>>g;
//	map<int,int>f;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		int u = i + a[i] - 1;
//		g[u].push_back(u + i-1);
//	}
//	auto it = g.end();
//	while(it != g.begin()){
//		it = prev(it);
//		auto [p, vec] = *it;
//		f[p] = p;
//		//cerr << p << " : ";
//		for(auto v : vec){
//			f[p] = max({f[v], f[p], v});
//			//cerr << v << ' ';
//		}
//		//cerr << '\n';
//	}
//	cout << max(n, f[n]) << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//const int inf = 2e9;
//const int mod = 1e9 + 7;

//int jian(int a, int b){
//	a -= b;
//	while(a < 0) a += mod;
//	return a;
//}

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n+5), b(m+5), pa(n+5);
//	vector<vector<int>>lp(n+5, vector<int>(m+5));
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pa[i] = pa[i-1] + a[i];
//	}
//	for(int i = 1;i <= m;i++) cin >> b[i];
//	for(int i = 1;i <= n;i++){
//		if(a[i] > b[1]){
//			cout << -1 << '\n';
//			return;
//		}
//		for(int j = 1;j <= m;j++){
//			int l = 1, r = i;
//			while(l <= r){
//				int mid = l + r >> 1;
//				if(b[j] >= pa[i] - pa[mid-1]) r = mid - 1;
//				else l = mid + 1;
//			}
//			lp[i][j] = l;
//		}
//	}

//	vector<vector<int>>f(n+5, vector<int>(m+5, inf)), pmnf(n+5, vector<int>(m+5, inf));
//	vector<vector<int>>g(n+5, vector<int>(m+5)), psmg(n+5, vector<int>(m+5)), ppg(n+5, vector<int>(m+5));
//	f[0] = pmnf[0] = vector<int>(m+5);
//	for(int j = 1;j <= m;j++){
//		g[0][j] = 1;
//		ppg[0][j] = psmg[0][j] = 1;
//	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			if(a[i] > b[j]){
//				f[i][j] = inf;
//				pmnf[i][j] = min(f[i][j], pmnf[i][j-1]);
//				g[i][j] = 0;
//				psmg[i][j] = psmg[i][j-1];
//				continue;
//			}

//			int l = lp[i][j]-1;
//			f[i][j] = pmnf[l][j] + (m-j);

//			int L = l, R = i-1;
//			while(L <= R){
//				int mid = L + R >> 1;
//				if(pmnf[mid][j] == pmnf[l][j]) L = mid + 1;
//				else R = mid - 1;
//			}
//			g[i][j] = jian(ppg[R][j], (l == 0 ? 0 : ppg[l-1][j]));
//			//cerr << l << ' ' << R << ' ' << i << ' ' << j << '\n';
//			//g[i][j] = psmg[l][j];

//			if(f[i][j] < pmnf[i][j-1]){
//				//cerr << i << ' ' << j << '\n';
//				psmg[i][j] = g[i][j];
//			}else if(f[i][j] == pmnf[i][j-1]){
//				psmg[i][j] = (psmg[i][j-1] + g[i][j]) % mod;
//			}else{
//				psmg[i][j] = psmg[i][j-1];
//			}
//			pmnf[i][j] = min(f[i][j], pmnf[i][j-1]);
//		}
//		for(int j = 1;j <= m;j++){
//			ppg[i][j] = (ppg[i-1][j] + psmg[i][j]) % mod;
//		}
//	}

//	//for(int i = 1;i <= n;i++){
//	//	cerr << i << " : ";
//	//	for(int j = 1;j <= m;j++){
//	//		cerr << f[i][j] << ' ';
//	//	}
//	//	cerr << '\n';
//	//}
//	//cerr << '\n';
//	//for(int i = 1;i <= n;i++){
//	//	cerr << i << " : ";
//	//	for(int j = 1;j <= m;j++){
//	//		cerr << g[i][j] << ' ';
//	//	}
//	//	cerr << '\n';
//	//}

//	cout << pmnf[n][m] << ' ' << psmg[n][m] << '\n';
//	//cerr << pmnf[n][m] << ' ' << psmg[n][m] << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long



//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	int mx = 0, mn = 10000;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		mx = max(mx, a[i]);
//		mn = min(mn, a[i]);
//	}
//	cout << (mx-mn) * (n-1) << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long



//void solve(){
//	int n;
//	cin >> n;
//	cout << 1;
//	for(int i = 1;i < n;i++) cout << 0;
//	cout << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//void solve(){
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	int ok = 0;
//	for(int i = 1;i < n;i++){
//		if(s[i] == '1' && s[i-1] == '1') ok = 1;
//	}
//	if(s[0] == '1' || s[n-1] == '1' || ok) cout << "YES\n";
//	else cout << "NO\n";
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//int lowbit(int x){
//	return x & -x;
//}

//struct Tree{
//	vector<int>tr;
//	int n;
//	Tree(int _n) : n(_n), tr(_n+10) {}
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
//		return getsum(r) - getsum(l-1);
//	}
//};

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	Tree tr(n);
//	vector<int>a(n+5), b(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		tr.add(a[i]);
//		if(i+1 <= n) b[i] = tr.query(i+1, n);
//	}
//	string s;
//	cin >> s;
//	for(auto &c : s) {
//		if(c == 'L') c = '<';
//		else c = '>';
//	}
//	s = ' ' + s + ' ';

//	int sum = 0;
//	for(int i = 1;i < n;i++) if(s[i] == '<' && s[i+1] == '>') {
//		sum += b[i];
//	}

//	auto del = [&](int i) -> void {
//		if(s[i] == '<' && s[i+1] == '>') sum -= b[i];
//	};
//	auto add = [&](int i) -> void {
//		if(s[i] == '<' && s[i+1] == '>') sum += b[i];
//	};

//	while(q--){
//		int p;
//		cin >> p;
//		del(p-1);
//		del(p);
//		if(s[p] == '<') s[p] = '>';
//		else s[p] = '<';
//		add(p-1);
//		add(p);
//		if(sum == 0) cout << "YES\n";
//		else cout << "NO\n";
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//const int mod = 998244353;
//const int N = 2e5 + 10;
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
//int C(int a, int b) {
//	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
//}

//int jian(int a, int b){
//	a -= b;
//	while(a < 0) a += mod;
//	return a;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), c(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		c[a[i]]++;
//	}

//	int me = 0;
//	while(c[me]) me++;

//	vector<vector<int>>f(me+5), g(me+5), pf(me+5), pg(me+5);
//	for(int i = 0;i <= me;i++){
//		f[i].resize(c[i]+1);
//		pf[i].resize(c[i]+1);
//		g[i].resize(c[i]+1);
//		pg[i].resize(c[i]+1);
//	}
//	pg[me][0] = g[me][0] = 1;

//	for(int i = me-1;i >= 0;i--){
//		for(int j = 0;j <= c[i];j++){
//			int j2 = min(j, c[i+1]);
//			f[i][j] = (pf[i+1][j2] + pg[i+1][j2]*j % mod) % mod;
//			if(c[i+1] > j){
//				int dpg = jian(pg[i+1][c[i+1]], pg[i+1][j]);
//				(f[i][j] += (dpg*f[i+1][j]%mod + dpg*j%mod) % mod) %= mod;
//			}
//			g[i][j] = pg[i+1][j2];
//			(f[i][j] *= C(c[i], j)) %= mod;
//			(g[i][j] *= C(c[i], j)) %= mod;
//		}
//		pf[i][0] = f[i][0];
//		pg[i][0] = g[i][0];
//		for(int j = 1;j <= c[i];j++){
//			pf[i][j] = (pf[i][j-1] + f[i][j]) % mod;
//			pg[i][j] = (pg[i][j-1] + g[i][j]) % mod;
//		}
//	}

//	for(int i = me-1;i >= 0;i--){
//		cerr << i << " : ";
//		for(int j = 0;j <= c[i];j++) cerr << f[i][j] << ' ';
//		cerr << '\n';
//	}
//	for(int i = me-1;i >= 0;i--){
//		cerr << i << " : ";
//		for(int j = 0;j <= c[i];j++) cerr << pf[i][j] << ' ';
//		cerr << '\n';
//	}
//	for(int i = me-1;i >= 0;i--){
//		cerr << i << " : ";
//		for(int j = 0;j <= c[i];j++) cerr << g[i][j] << ' ';
//		cerr << '\n';
//	}
//	for(int i = me-1;i >= 0;i--){
//		cerr << i << " : ";
//		for(int j = 0;j <= c[i];j++) cerr << pg[i][j] << ' ';
//		cerr << '\n';
//	}

//	int ans = pf[0][c[0]];
//	int k = 0;
//	for(int i = me;i <= n;i++) k += c[i];
//	(ans *= qpow(2, k)) %= mod;

//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	init();
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//} 



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//const int mod = 998244353;
//const int N = 2e5 + 10;
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
//int C(int a, int b) {
//	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
//}

//int jian(int a, int b){
//	a -= b;
//	while(a < 0) a += mod;
//	return a;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), c(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		c[a[i]]++;
//	}

//	int me = 0;
//	while(c[me]) me++;

//	vector<vector<int>>f(me+5), g(me+5), pf(me+5), pg(me+5);
//	for(int i = 0;i <= me;i++){
//		f[i].resize(c[i]+1);
//		pf[i].resize(c[i]+1);
//		g[i].resize(c[i]+1);
//		pg[i].resize(c[i]+1);
//	}

//	for(int j = 0;j <= c[0];j++){
//		f[0][j] = j * C(c[0], j) % mod;
//		g[0][j] = C(c[0], j);
//		pf[0][j] = f[0][j];
//		pg[0][j] = g[0][j];
//	}
//	for(int j = 1;j <= c[0];j++){
//		(pf[0][j] += pf[0][j-1]) %= mod;
//		(pg[0][j] += pg[0][j-1]) %= mod;
//	}

//	for(int i = 1;i < me;i++){
//		for(int j = 0;j <= min(c[i], c[i-1]);j++){
//			f[i][j] = jian(pf[i-1][c[i-1]], j == 0 ? 0 : pf[i-1][j-1]);
//			(f[i][j] += jian(pg[i-1][c[i-1]], j == 0 ? 0 : pg[i-1][j-1]) * j % mod) %= mod;
//			g[i][j] = jian(pg[i-1][c[i-1]], j == 0 ? 0 : pg[i-1][j-1]);
//			(f[i][j] *= C(c[i], j)) %= mod;
//			(g[i][j] *= C(c[i], j)) %= mod;
//		}
//		pf[i][0] = f[i][0];
//		pg[i][0] = g[i][0];
//		for(int j = 1;j <= c[i];j++) {
//			pf[i][j] = (pf[i][j-1] + f[i][j]) % mod;
//			pg[i][j] = (pg[i][j-1] + g[i][j]) % mod;
//		}
//	}

//	for(int i = 0;i < me;i++){
//		cerr << i << " : ";
//		for(int j = 0;j <= c[i];j++){
//			cerr << f[i][j] << ' ';
//		}
//		cerr << '\n';
//	}

//	int ans = pf[me-1][c[me-1]];
//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	init();
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n, r;
//	cin >> n >> r;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	int ans = 0, s = 0;
//	for(int i = 1;i <= n;i++){
//		r -= a[i]/2;
//		if(a[i] & 1){
//			s++;
//			a[i]--;
//		}
//		ans += a[i];
//	}
//	ans += s;
//	if(s > r){
//		int d = s-r;
//		ans -= d*2;
//	}
//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n, x;
//	cin >> n >> x;
//	vector<int>a(n+5);
//	multiset<int>st;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//	}
//	sort(a.begin()+1, a.begin()+1+n);
//	for(int i = n;i >= n-x+1 && i >= 1;i--) st.insert(a[i]);
//	for(int i = n-x;i >= 1;i--){
//		auto u = *st.begin();
//		st.erase(st.begin());
//		u += a[i];
//		st.insert(u);
//	}
//	cout << *st.rbegin() << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n, x;
//	cin >> n >> x;
//	vector<int>a(n+5);
//	int mx = 0, sum = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		sum += a[i];
//		mx = max(mx, a[i]);
//	}

//	int l = mx, r = 1e17;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if((sum+mid-1)/mid <= x) r = mid-1;
//		else l = mid+1;
//	}
//	cout << l << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//int op[6][6] = {
//	0, 0, 1, 0, 1, 1,
//	0, 0, 0, 1, 1, 0,
//	0, 0, 0, 1, 1, 1,
//	0, 1, 1, 0, 1, 1,
//	0, 0, 0, 1, 0, 2,
//	1, 0, 1, 1, 1, 2,
//};

//void solve(){
//	int n;
//	cin >> n;
//	vector<string>s(3);
//	cin >> s[1] >> s[2];
//	s[1] = " " + s[1] + "    ";
//	s[2] = " " + s[2] + "    ";

//	auto val = [&](int c, int id) -> int {
//		int x = 1, y = c;
//		int ret = 0;
//		for(int i = 0;i < 6;i += 2){
//			int nx = x + op[id][i];
//			int ny = y + op[id][i+1];
//			ret += (s[nx][ny] == 'A');
//		}
//		return (ret >= 2);
//	};

//	vector<vector<int>>f(n+10, vector<int>(7));
//	for(int i = 0;i <= n;i++){
//		f[i+1][4] = max(f[i+1][4], f[i][3] + val(i+1, 0));
//		f[i+2][2] = max(f[i+2][2], f[i][3] + val(i+1, 1));
//		f[i+2][3] = max(f[i+2][2], f[i][4] + val(i+1, 2));
//		if(i >= 1) f[i+1][3] = max(f[i+1][3], f[i][2] + val(i, 3));
		
//		for(int k = 0;k <= 3;k++){
//			int j = k+3;
//			f[i+3][j-3] = max(f[i+3][j-3], f[i][j] + val(i+1, 4));
//		}
//		for(int k = -3;k <= 0;k++){
//			int j = k+3;
//			if(i+k+1 >= 1) f[i][j+3] = max(f[i][j+3], f[i][j] + val(i+k+1, 5));
//		}

//		f[i+1][4] = max(f[i+1][4], f[i][3] + val(i+1, 0));
//		f[i+2][2] = max(f[i+2][2], f[i][3] + val(i+1, 1));
//		f[i+2][3] = max(f[i+2][2], f[i][4] + val(i+1, 2));
//		if(i >= 1) f[i+1][3] = max(f[i+1][3], f[i][2] + val(i, 3));
		
//		for(int k = 0;k <= 3;k++){
//			int j = k+3;
//			f[i+3][j-3] = max(f[i+3][j-3], f[i][j] + val(i+1, 4));
//		}
//		for(int k = -3;k <= 0;k++){
//			int j = k+3;
//			if(i+k+1 >= 1) f[i][j+3] = max(f[i][j+3], f[i][j] + val(i+k+1, 5));
//		}

//		//for(int j = 0;j < 7;j++) cerr << f[i][j] << ' ';
//		//cerr << '\n';
//	}

//	//cerr << val(2, 2) << '\n';
//	//cerr << val(2, 3) << '\n';

//	cout << f[n][3] << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	if(k == 1){
//		cout << n << '\n';
//		return;
//	}
//	int s = 0;
//	while(n){
//		s += n%k;
//		n /= k;
//	}
//	cout << s << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int k;
//	cin >> k;
//	int l = 1, r = 2e18;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(mid-(int)sqrt(mid) >= k) r = mid-1;
//		else l = mid+1;
//	}
//	cout << l << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int b, c, d, a;
//	cin >> b >> c >> d;
//	a = (b|d) - (b&d);
//	if((a|b) - (a&c) != d) a = -1;
//	cout << a << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<array<int,3>>qur(m+5);
//	for(int i = 1;i <= m;i++){
//		cin >> qur[i][0] >> qur[i][1] >> qur[i][2];
//	}

//	vector<int>fa(n+5);
//	iota(fa.begin(), fa.end(), 0);

//	auto find = [&](auto self, int x) -> int {
//		return fa[x] == x ? x : fa[x] = self(self, fa[x]);
//	};
//	auto merg = [&](int a, int b) -> void {
//		a = find(find, a);
//		b = find(find, b);
//		if(a == b) return;
//		fa[a] = b;
//	};

//	for(int d = 1;d <= 10;d++){
//		vector<vector<int>>vis(d, vector<int>(n/d + 5));
//		for(int j = 1;j <= m;j++) if(qur[j][1] == d && qur[j][2]) {
//			auto [a, d, k] = qur[j];
//			int m = a%d, st = a/d;
//			vis[m][st]++;
//			vis[m][st+k+1]--;
//		}
//		vector<int>f(n+5);
//		for(int i = 1;i <= n;i++){
//			int k = i/d, dt = i%d;
//			if(k > 0){
//				vis[dt][k] += vis[dt][k-1];
//			}
//			f[i] = vis[dt][k];
//			if(f[i] && i-d >= 1 && f[i-d]) merg(i-d, i);
//		}
//	}

//	int ans = 0;
//	for(int i = 1;i <= n;i++) ans += (find(find, i) == i);
//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<array<int,3>>qur(m+5);
//	vector<vector<vector<array<int,2>>>>vec(11, vector<vector<array<int,2>>>(11));
//	for(int i = 1;i <= m;i++){
//		auto &[a, d, k] = qur[i];
//		cin >> a >> d >> k;
//		int l = a/d, r = l+k;
//		vec[d][a%d].push_back({l, r});
//	}

//	vector<int>fa(n+5);
//	iota(fa.begin(), fa.end(), 0);

//	auto find = [&](auto self, int x) -> int {
//		return fa[x] == x ? x : fa[x] = self(self, fa[x]);
//	};
//	auto merg = [&](int a, int b) -> void {
//		a = find(find, a);
//		b = find(find, b);
//		if(a == b) return;
//		fa[a] = b;
//	};

//	for(int d = 1;d <= 10;d++){
//		for(int dt = 0;dt < d;dt++) if(vec[d][dt].size()) {
//			sort(all(vec[d][dt]));
//			auto [L, R] = vec[d][dt][0];
//			for(auto [l, r] : vec[d][dt]){
//				if(l > R){
//					for(int i = L+1;i <= R;i++){
//						merg(i*d+dt, (i-1)*d+dt);
//					}
//					L = l;
//				}
//				R = max(R, r);
//			}
//			for(int i = L+1;i <= R;i++){
//				merg(i*d+dt, (i-1)*d+dt);
//			}
//		}
//	}

//	int ans = 0;
//	for(int i = 1;i <= n;i++) ans += (find(find, i) == i);
//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()

//const int mod = 1e9 + 7;
//const int fm = 10000;

//int qpow(int a, int b){
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}
//int chu(int a, int b){
//	return a * qpow(b, mod-2) % mod;
//}
//int jian(int a, int b){
//	a -= b;
//	while(a < 0) a += mod;
//	return a;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), p(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++){
//		cin >> p[i];
//		p[i] = chu(p[i], fm);
//	}

//	vector<vector<int>>f(2, vector<int>(1024));
//	f[0][0] = 1;
//	for(int i = 1;i <= n;i++){
//		for(int j = 0;j < 1024;j++){
//			int k = j^a[i];
//			f[i&1][j] = 0;
//			(f[i&1][j] += f[(i-1)&1][k] * p[i] % mod) %= mod;
//			(f[i&1][j] += f[(i-1)&1][j] * jian(1, p[i]) % mod) %= mod;
//		}
//	}

//	int ans = 0;
//	for(int j = 0;j < 1024;j++){
//		(ans += j*j * f[n&1][j] % mod) %= mod;
//	}

//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()



//void solve(){
//	int a, b;
//	cin >> a >> b;
//	if(a >= b){
//		cout << a << '\n';
//	}else{
//		cout << max(0ll, a-(b-a)) << '\n';
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	sort(all1(a));
//	int t = 0, s = 0;
//	for(int i = 1;i <= n;i++){
//		if(a[i] == t){
//			s++;
//			continue;
//		}
//		int d = (n-i+1) * (a[i]-t);
//		t = a[i];
//		if(d >= k){
//			s += k;
//			k = 0;
//			break;
//		}
//		s += d;
//		k -= d;
//		s++;
//	}
//	cout << s << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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
//	vector<array<int,2>>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i][0] >> a[i][1];
//	}
//	sort(all1(a), [&](array<int,2>i, array<int,2>j) -> int {
//		if(min(i[0], i[1]) == min(j[0], j[1])) return max(i[0], i[1]) < max(j[0], j[1]);
//		return min(i[0], i[1]) < min(j[0], j[1]);
//	});
//	for(int i = 1;i <= n;i++) cout << a[i][0] << ' ' << a[i][1] << ' ';
//	cout << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 1e15;

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), b(n+5), f(n+5, inf), pre(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++) cin >> b[i];
//	for(int i = 1;i <= n;i++) pre[i] = pre[i-1] + a[i];

//	priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>>que;
//	f[1] = 0;
//	que.push({0, 1});
//	for(int i = 1;i <= n;i++){
//		while(que.size() && que.top()[1] < i) que.pop();
//		if(que.empty()) break;
//		f[i] = min(f[i], que.top()[0]);
//		if(b[i] > i) que.push({f[i] + a[i], b[i]});
//	}

//	int ans = 0;
//	for(int i = 1;i <= n;i++) ans = max(ans, pre[i]-f[i]);
//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int l, r, k;
//	cin >> l >> r >> k;
//	cout << max(0ll, r/k-l+1) << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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
//	string s, ss;
//	cin >> s >> ss;
//	int cnt[2] = {0};
//	for(auto c : s) cnt[c-'0']++;
//	for(int i = 0;i < n-1;i++){
//		if(cnt[0] == 0 || cnt[1] == 0){
//			cout << "NO\n";
//			return;
//		}
//		cnt[(ss[i]-'0')^1]--;
//	}
//	cout << "YES\n";
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//map<char, array<int,2>>op;

//void solve(){
//	int n, a, b;
//	cin >> n >> a >> b;
//	string s;
//	cin >> s;
//	int x = 0, y = 0;
//	for(int i = 1;i <= 110;i++)
//	for(auto c : s) {
//		x += op[c][0];
//		y += op[c][1];
//		if(x == a && y == b){
//			cout << "YES\n";
//			return;
//		}
//	}
//	cout << "NO\n";
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	op['N'] = {0, 1};
//	op['E'] = {1, 0};
//	op['S'] = {0, -1};
//	op['W'] = {-1, 0};
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, b, c, ans;
//	cin >> n >> b >> c;
//	if(b == 0){
//		if(c >= n-2){
//			if(c <= n-1) ans = n-1;
//			else ans = n;
//		}else{
//			ans = -1;
//		}
//	}else{
//		ans = n;
//		if(c <= n-1){
//			ans--;
//			ans -= ((n-1-c)/b);
//		}
//	}
//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, m, v;
//	cin >> n >> m >> v;
//	vector<int>a(n+5), pre(n+5), pc(n+5), sc(n+5), suf(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pre[i] = pre[i-1] + a[i];
//	}
//	for(int i = n;i >= 1;i--){
//		suf[i] = suf[i+1] + a[i];
//		//cerr << suf[i] << ' ';
//	}
//	//cerr << '\n';
//	int q = 0, p = 1;
//	while(p <= n){
//		if(pre[p] - pre[q] >= v){
//			pc[p] = pc[q]+1;
//			q = p;
//		}else{
//			pc[p] = pc[q];
//		}
//		p++;
//	}
//	p = n+1, q = n;
//	while(q >= 1){
//		if(suf[q] - suf[p] >= v){
//			sc[q] = sc[p]+1;
//			p = q;
//		}else{
//			sc[q] = sc[p];
//		}
//		q--;
//	}
//	if(pc[n] < m){
//		cout << -1 << '\n';
//		return;
//	}

//	//for(int i = 1;i <= n;i++){
//	//	cerr << sc[i] << ' ';
//	//}

//	int ans = 0;
//	for(int i = 1, j = 0;i <= n+1;i++){
//		while(sc[i] + pc[j] < m && j+1 < i) j++;
//		if(sc[i] + pc[j] >= m) ans = max(ans, pre[i-1] - pre[j]);
//		//cerr << j << ' ' << i << ' ' << pre[i-1] - pre[j] << '\n';
//	}
//	cout << ans << '\n';

//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, m;
//	cin >> n;
//	m = n*4;
//	vector<vector<int>>a(4, vector<int>(n+5));
//	vector<vector<int>>b(4, vector<int>(n+5));
//	vector<vector<int>>g(m+5);
//	auto add = [&](int i, int j) -> void {
//		g[i].push_back(j);
//		g[j].push_back(i);
//	};
//	for(int i = 1;i <= 3;i++){
//		for(int j = 1;j <= n;j++){
//			cin >> a[i][j];
//			add(j, i*n+j);
//		}
//		iota(all(b[i]), 0);
//		sort(all1(b[i]), [&](int x, int y) -> int {
//			return a[i][x] > a[i][y];
//		});
//		stack<int>st;
//		for(int j = n;j >= 1;j--){
//			while(st.size() && st.top() > b[i][j]){
//				g[i*n+b[i][j]].push_back(i*n+st.top());
//				st.pop();
//			}
//			st.push(b[i][j]);
//		}
//	}

//	vector<int>pre(m+5);

//	queue<int>que;
//	que.push(1);
//	pre[1] = -1;
//	int ed = 0;
//	while(que.size()){
//		int u = que.front();
//		que.pop();
//		if(u%n == 0){
//			ed = u;
//			break;
//		}
//		for(auto v : g[u]) if(!pre[v]) {
//			pre[v] = u;
//			que.push(v);
//		}
//	}

//	if(ed == 0){
//		cout << "NO\n";
//		return;
//	}

//	vector<int>op;
//	while(ed != 1){
//		if(ed > n) op.push_back(ed);
//		//cerr << ed << '\n';
//		ed = pre[ed];
//	}
//	reverse(all(op));
//	auto tmp = op;
//	op.clear();
//	int ls = 1;
//	for(auto u : tmp){
//		if(u%n != ls%n) op.push_back(u);
//		ls = u;
//	}
	
//	cout << "YES\n" << op.size() << '\n';
//	for(auto u : op){
//		if(u > 3*n) cout << "j ";
//		else if(u > 2*n) cout << "k ";
//		else cout << "q ";
//		cout << (u-1)%n + 1 << '\n';
//	}
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, m, r, c;
//	cin >> n >> m >> r >> c;
//	int ans = m-c;
//	ans += (n-r)*m;
//	ans += (n-r)*(m-1);
//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

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
//	string s;
//	if(n & 1){
//		if(n < 5){
//			s = "-1";
//		}else{
//			s = string(n-4, '3');
//			s += "6366";
//		}
//	}else{
//		s = string(n-2, '3');
//		s += "66";
//	}
//	cout << s << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//int n;

//int bitcnt(int x){
//	int ret = 0;
//	while(x){
//		ret++;
//		x >>= 1;
//	}
//	return ret;
//}
//int hibit(int x){
//	return 1ull << (63-__builtin_clzll(x));
//}

//vector<int> gen(int x){
//	int y = x;
//	vector<int>a(n+5);
	
//	int p = n;
//	if(p % 2 == 0){
//		p--;
//		x -= hibit(x);
//	}
//	while(x && p >= 1){
//		a[p] = x;
//		x -= hibit(x);
//		p -= 2;
//	}
	
//	p = n;
//	x = y;
//	if(p % 2 == 1) p--;
//	while(x && p >= 1){
//		a[p] = hibit(x);
//		x -= hibit(x);
//		p -= 2;
//	}

//	set<int>st;
//	for(int i = 1;i <= n;i++) st.insert(i);
//	for(int i = 1;i <= n;i++) st.erase(a[i]);
//	if(a[p+2] == a[p+3]){
//		for(auto v : st) if(v&a[p+2]) {
//			a[p+2] = v;
//			break;
//		}
//		st.erase(a[p+2]);
//	}
//	for(int i = 1;i <= n;i++) if(a[i] == 0) {
//		a[i] = *st.begin();
//		st.erase(a[i]);
//	}

//	return a;
//}
//int cal(vector<int>a){
//	int x = 0;
//	for(int i = 1;i <= n;i++){
//		if(a[i] > n) return 0;
//		if(i & 1) x &= a[i];
//		else x |= a[i];
//	}
//	return x;
//}
//void pt(vector<int>a){
//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//}

//void solve(){
//	cin >> n;
//	int l = 1, r = (1<<bitcnt(n))-1;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(cal(gen(mid)) >= mid) l = mid + 1;
//		else r = mid - 1;
//	}

//	auto a = gen(r);
//	cout << cal(a) << '\n';
//	pt(a);
//	cout << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	for(int i = 1;i <= t;i++) solve();

//	return 0;
//}




#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin()+1, (x).begin()+1+n

const int mod = 1e9 + 7;
int qpow(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
array<int,2> fj(int x){
	array<int,2>a = {x, 0};
	while(a[0] % 2 == 0){
		a[0] /= 2;
		a[1]++;
	}
	return a;
}
int val(array<int,2>a){
	return a[0] * qpow(2, a[1]) % mod;
}
int rval(array<int,2>a){
	return a[0] * (1ll<<a[1]);
}
int jian(int a, int b){
	a -= b;
	while(a < 0) a += mod;
	return a;
}
int jia(int a, int b){
	return (a + b) % mod;
}
void pt(stack<array<int,2>>st){
	while(st.size()){
		cerr << st.top()[0] << ' ' << st.top()[1] << '\n';
		st.pop();
	}
}

void solve(){
	int n;
	cin >> n;
	vector<int>a(n+5);
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	stack<array<int,2>>st;
	int ans = 0, sm = 0;
	for(int i = 1;i <= n;i++){
		auto u = fj(a[i]);

		//if(i == 15){
		//	pt(st);
		//	cerr << u[0] << ' ' << u[1] << '\n';
		//}

		while(st.size()) {
			if(u[1] >= 30 || rval(u) >= st.top()[0]){
				auto v = st.top();
				st.pop();
				ans = jian(ans, val(v));
				ans = jia(ans, v[0]);
				u[1] += v[1];
			}else break;
		}


		//if(i == 15){
		//	cerr << '\n';
		//	pt(st);
		//	cerr << u[0] << ' ' << u[1] << '\n';
		//}
		ans = jia(ans, val(u));
		if(u[1]) st.push(u);
		cout << ans << ' ';
	}
	cout << '\n';	
}

signed main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	for(int i = 1;i <= t;i++) solve();

	return 0;
}
