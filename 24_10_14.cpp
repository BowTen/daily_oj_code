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