//#include<bits/stdc++.h>
//using namespace std;
//#define int long long 
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define rall(x) (x).rbegin(), (x).rend()

//const int mod = 1e9 + 7;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const double PI = 3.1415926535;

//void solve(){
//	cin >> n >> L;
//	n *= 2;
//	vector<double>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		a[i] *= PI;
//		a[i] /= 2*L;
//	}

//	auto S = [&](int i, int j) -> double {
//		double d = abs(a[i] - a[j]);
//		d = min(d, 2*PI-d);
//		return 0.5 * sin(d);
//	};


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

//const int mod = 1e9 + 7;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1005;
//const int UP = 0;
//const int RI = 1;
//const int DO = 2;
//const int LE = 3;

//int op[4][2] = {
//	-1, 0,
//	0, 1,
//	1, 0,
//	0, -1
//};
//int op8[8][2] = {
//	-1, 0,
//	-1, 1,
//	0, 1,
//	1, 1,
//	1, 0,
//	1, -1,
//	0, -1
//	-1, -1
//};

//int n, m, sr, sc, tr, tc, tot;
//int id[N][N], fa[N*N], mp[N][N];
//vector<int>up(N*N, N), ri(N*N), dow(N*N), le(N*N, N);
//int sp[4] = {N, 0, 0, N};
//int tp[4] = {N, 0, 0, N};

//int find(int x){
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//void merg(int a, int b){
//	a = find(a);
//	b = find(b);
//	fa[a] = b;
//	up[a] = min(up[a], up[b]);
//	le[a] = min(le[a], le[b]);
//	dow[a] = max(dow[a], dow[b]);
//	ri[a] = max(ri[a], ri[b]);
//}

//void solve(){
//	cin >> n >> m >> sr >> sc >> tr >> tc;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			id[i][j] = ++tot;
//			fa[tot] = tot;
//		}
//	}

//	for(int i = 1, x, y;i <= n*m;i++){
//		cin >> x >> y;
//		if(x == sr){
//			if(y == sc) continue;
//			sp[LE] = min(sp[LE], x);
//			sp[RI] = max(sp[RI], x);
//		}
//		if(y == sc){
//			sp[UP] = min(sp[UP], y);
//			sp[DO] = max(sp[DO], y);
//		}

//		if(x == tr){
//			if(y == tc) continue;
//			tp[LE] = min(sp[LE], x);
//			tp[RI] = max(sp[RI], x);
//		}
//		if(y == tc){
//			tp[UP] = min(sp[UP], y);
//			tp[DO] = max(sp[DO], y);
//		}
//		int ls = -1;
//		for(int j = 0;j < 8;j++){
//			int nx = x + op8[j][0];
//			int ny = y + op8[j][0];
//			if(mp[nx][ny]) {
//				if(ls == -1) ls = j;
//				else{

//				}
//			}
//		}
//	}

//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	//while(t--){
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
//const double PI = 3.1415926535;


//void solve(){
//	int n, L;
//	cin >> n >> L;
//	n *= 2;
//	vector<double>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		a[i] *= PI;
//		a[i] /= 2*L;
//	}

//	auto S = [&](int i, int j) -> double {
//		return 0.5 * sin(a[j] - a[i]);
//	};

//	sort(all1(a));
//	vector<vector<double>>f(n+5, vector<double>(n+5, inf));
//	for(int i = 2;i <= n;i += 2){
//		for(int l = 1, r = i;r <= n;l++, r++){
//			for(int k = r-1;k >= l;k -= 2){
//				f[l][r] = min(f[l][r], (k == l ? 0 : f[l][k-1]) + S(k, r) + (k == r-1 ? 0 : f[k+1][r-1]));
//			}
//			//cerr << l << ' ' << r << ' ' << f[l][r] << endl;
//		}
//	}

//	cout << f[1][n] << endl;
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
//#define ls id << 1
//#define rs id << 1 | 1

//const int mod = 39989;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e5+10;
//const int M = 4e4 + 5;
//const int mxn = 4e4;
//const double eps = 1e-9;

//struct line {
//	double k, d;
//	line() : k(0), d(0) {}
//	line(int x0, int y0, int x1, int y1) {
//		if(x0 != x1){
//			k = ((1.0*(y0-y1))/(x0-x1));
//			d = (y0-k*x0);
//		}else{
//			k = 0;
//			d = max(y0, y1);
//		}
//	}
//	double Y(int x){
//		return k*x + d;
//	}
//}e[N];

//int cmp(int i, int j, int x) {
//	if(i > j) swap(i, j);
//	if(e[j].Y(x) - e[i].Y(x) > eps) return j;
//	return i;
//}
//int tr[M<<2];
//void modify(int id, int l, int r, int ql, int qr, int x) {
//	int mid = l + r >> 1;
//	if(ql <= l && r <= qr){
//		if(cmp(x, tr[id], mid) == x) swap(tr[id], x);
//		if(cmp(x, tr[id], l) == x) modify(ls, l, mid, ql, qr, x);
//		if(cmp(x, tr[id], r) == x) modify(rs, mid+1, r, ql, qr, x);
//		return;
//	}
//	if(ql <= mid) modify(ls, l, mid, ql, qr, x);
//	if(qr > mid) modify(rs, mid + 1, r, ql, qr, x);
//}
//int query(int id, int l, int r, int x) {
//	if(l == r) return tr[id];
//	int mid = l + r >> 1;
//	if(x <= mid) return cmp(tr[id], query(ls, l, mid, x), x);
//	else return cmp(tr[id], query(rs, mid + 1, r, x), x);
//}

//void solve(){
//	int n, op, k, x0, x1, y0, y1, ans = 0, tot = 0;
//	cin >> n;
//	while(n--){
//		cin >> op;
//		if(op == 0){
//			cin >> k;
//			k = ((k + ans - 1) % mod) + 1;
//			ans = query(1, 1, mxn, k);
//			cout << ans << endl;
//		}else{
//			cin >> x0 >> y0 >> x1 >> y1;
//			x0 = ((x0 + ans - 1) % mod) + 1;
//			x1 = ((x1 + ans - 1) % mod) + 1;
//			y0 = ((y0 + ans - 1) % 1000000000) + 1;
//			y1 = ((y1 + ans - 1) % 1000000000) + 1;
//			if(x0 > x1) {
//				swap(x0, x1);
//				swap(y0, y1);
//			}
//			e[++tot] = line(x0, y0, x1, y1);
//			modify(1, 1, mxn, x0, x1, tot);
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

//const int mod = 39989;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e5+10;


//void solve(){
//	int n, mn = inf, mx = -inf;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		mn = min(mn, a[i]);
//		mx = max(mx, a[i]);
//	}
//	int st = 1;
//	while(st <= n && a[st] == 0) st++;

//	int d = 0;
//	vector<int>op;
//	if(a[st] > 0 && mn <= 0){
//		d = (-mn) / a[st] + 2;
//	}else if(a[st] < 0 && mx >= 0) {
//		d = mx / (-a[st]) + 2;
//	}
//	for(int i = 1;i <= d;i++) op.push_back(st);
//	d *= a[st];

//	for(int i = st+1;i <= n;i++) a[i] += d;

//	for(int i = n-1;i > st;i--){
//		if(a[st] > 0){
//			if(a[i] > a[i+1]) op.push_back(i);
//		}else{
//			if(a[i] < a[i+1]) op.push_back(i);
//		}
//	}

//	cout << op.size() << endl;
//	for(auto e : op) cout << e << ' ';
//	cout << endl;
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
////#define int long long 
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1


////const int inf = 0x3f3f3f3f3f3f3f3f;
//const int inf = 0x3f3f3f3f;
//const int V = 1e7 + 10;
//const int N = 1e5 + 10;

//vector<int>fac[N];

//int hf;
//const int K = 16;
//struct node{
//	array<array<int,2>,K>vec;
//}tr[N<<2];
//node operator+(const node& l, const node& r) {
//	node ret(l);
//	for(int i = 0;i < K;i++) if(r.vec[i][1]) {
//		int f = 1;
//		for(int j = 0;j < K;j++) if(ret.vec[j][1]) {
//			if(r.vec[i][0] == ret.vec[j][0]){
//				ret.vec[j][1] += r.vec[i][1];
//				f = 0;
//				break;
//			}
//		}
//		if(!f) continue;
//		for(int j = 0;j < K;j++) if(!ret.vec[j][1]) {
//			ret.vec[j][0] = r.vec[i][0];
//			ret.vec[j][1] = r.vec[i][1];
//			f = 0;
//			break;
//		}
//		if(!f) continue;
//		int mn = 0;
//		for(int j = 1;j < K;j++) if(ret.vec[j][1] < ret.vec[mn][1]) mn = j;
//		int d = min(ret.vec[mn][1], r.vec[i][1]);
//		for(int j = 1;j < K;j++) ret.vec[j][1] -= d;
//		if(r.vec[i][1]-d > 0) {
//			ret.vec[mn][0] = r.vec[i][0];
//			ret.vec[mn][1] = r.vec[i][1]-d;
//		}
//	}
//	return ret;
//}
 

//void up(int id){
//	tr[id] = tr[ls] + tr[rs];
//}
//void build(int id, int l, int r){
//	if(l == r){
//		for(int i = 0;i < fac[l].size();i++){
//			//tr[id].vec.push_back({fac[l][i], 1});
//			tr[id].vec[i] = {fac[l][i], 1};
//		}
//		return;
//	}
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//	up(id);
//}
//node query(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return tr[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls, l, mid, ql, qr);
//	else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//	else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
//}

//vector<int>mp[V];

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	vector<int>a(n+5), pre(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++){
//        int ta=a[i];
//        for(int j=2; j*j<=a[i]; j++) {
//            if(ta%j!=0) continue;
//            int cnt=0;
//            while(ta%j==0) {
//                cnt++;
//                ta/=j;
//            }
//            if(cnt%2==1) fac[i].push_back(j);
//        }
//        if(ta!=1) fac[i].push_back(ta);
//		pre[i] = pre[i-1] + fac[i].size();
//		for(auto f : fac[i]) mp[f].push_back(i);
//	}
//	build(1, 1, n);

//	int ans = 0, l, r, len;
//	while(q--){
//		cin >> l >> r;
//		l ^= ans;
//		r ^= ans;
//		ans = pre[r] - pre[l-1];
//		len = r-l+1;
//		hf = len/2;
//		auto vec = query(1, 1, n, l, r).vec;
//		for(auto [f, ct] : vec){
//			auto lp = lower_bound(all(mp[f]), l);
//			auto rp = upper_bound(all(mp[f]), r);
//			int cnt = rp - lp;
//			if(cnt > hf) {
//				ans -= cnt;
//				ans += len - cnt;
//			}
//		}
//		cout << ans << endl;
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n
//#define ls id << 1
//#define rs id << 1 | 1

////const int inf = 0x3f3f3f3f3f3f3f3f;
//const int inf = 0x3f3f3f3f;
//const int N = 1e5 + 10;


//void solve(){
//	int n;
//	cin >> n;
//	int x, s = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> x;
//		s += x > 1;
//	}
//	if(n & 1){
//		cout << "Yes\n";
//	}else{
//		if(s & 1) cout << "Yes\n";
//		else cout << "No\n";
//	}
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
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e5 + 10;

//struct line{
//	int k, b;
//	line() {}
//	line(int k, int b) : k(k), b(b) {}
//	int Y(int x){
//		return x*k + b;
//	}
//}e[N];

//line* tr[N<<2];
//void build(int id, int l, int r) {
//	tr[id] = e;
//	if(l == r) return;
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//}
//void insert(int id, int l, int r, int ql, int qr, line *x) {
//	int mid = l + r >> 1;
//	if(ql <= l && r <= qr){
//		if(x->Y(mid) > tr[id]->Y(mid)) swap(x, tr[id]);
//		if(x->Y(l) > tr[id]->Y(l)) insert(ls, l, mid, ql, qr, x);
//		if(x->Y(r) > tr[id]->Y(r)) insert(rs, mid + 1, r, ql, qr, x);
//		return;
//	}
//	if(ql <= mid) insert(ls, l, mid, ql, qr, x);
//	if(qr > mid) insert(rs, mid + 1, r, ql, qr, x);
//}
//int query(int id, int l, int r, int x) {
//	if(l == r) return tr[id]->Y(x);
//	int mid = l + r >> 1;
//	if(x <= mid) return max(tr[id]->Y(x), query(ls, l, mid, x));
//	else return max(tr[id]->Y(x), query(rs, mid + 1, r, x));
//}

//void solve(){
//	int n, tot = 0;
//	cin >> n;
//	vector<int>a(n+5), r(n+5, n), f(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 0, j = 2;i < n;i++){
//		while(j <= n && 2*a[i+1]*a[i+1] > a[j]*a[j]) j++;
//		r[i] = j-1;
//	}
//	build(1, 1, n);

//	e[++tot] = line(0, 0);
//	insert(1, 1, n, 1, r[0], &e[tot]);
//	for(int i = 1;i <= n;i++){
//		f[i] = query(1, 1, n, i) + (i*i - i)/2;
//		e[++tot] = line(-i, f[i] + (i*i + i)/2);
//		insert(1, 1, n, i, r[i], &e[tot]);
//	}

//	cout << f[n] << endl;
//}

//signed main(){

//	IO;
//	e[0] = line(0, -inf);
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
//#define ls id << 1
//#define rs id << 1 | 1

////const int inf = 0x3f3f3f3f3f3f3f3f;
//const int inf = 0x3f3f3f3f;
//const int N = 1e5 + 10;
//const int RI = 0;
//const int UP = 1;

//void solve(){
//	int n, m;
//	int a[3], len[3] = {999, 1000, 1001};
//	cin >> n >> m;
//	swap(n, m);
//	for(int i = 0;i < 3;i++) cin >> a[i];

//	int mx = 0, my = 0;
//	vector<array<int,4>>ans;
//	auto push = [&](int k, int x, int y, int d) {
//		a[k]--;
//		if(d == UP) ans.push_back({x, y, x+1, y+len[k]});
//		else ans.push_back({x, y, x+len[k], y+1});
//	};
//	if(a[2] >= 2){
//		push(2, 0, 0, UP);
//		push(2, 1000, 0, UP);
//		push(0, 1, 0, RI);
//		push(0, 1, 1000, RI);
//	}else if(a[2] >= 1){
//		push(1, 0, 0, UP);
//		push(1, 1, 0, RI);
//		push(2, 0, 1000, RI);
//		push(0, 1000, 1, UP);
//	}else{
//		//cerr << "DEBUG\n";
//		push(1, 0, 0, UP);
//		push(1, 0, 1000, RI);
//		push(1, 1, 0, RI);
//		push(1, 1000, 1, UP);
//	}

//	for(int y = 1001, i = 1;i < n;i++, y += 1000){
//		if(a[2]){
//			push(2, 0, y+999, RI);
//			push(0, 0, y, UP);
//			push(0, 1000, y, UP); 
//		}else{
//			push(0, 1, y+999, RI);
//			push(1, 0, y, UP); 
//			push(1, 1000, y, UP); 
//		}
//	}

//	for(int x = 1001, i = 1;i < m;i++, x += 1000){
//		if(a[2]){
//			push(2, x+999, 0, UP);
//			push(0, x, 0, RI); 
//			push(0, x, 1000, RI); 
//		}else{
//			push(0, x+999, 1, UP);
//			push(1, x, 0, RI); 
//			push(1, x, 1000, RI); 
//		}
//		for(int y = 1001, j = 1;j < n;j++, y += 1000){
//			push(0, x, y+999, RI);
//			push(1, x+999, y, UP);
//		}
//	}

//	//for(int i = 0;i < 3;i++) cerr << a[i] << endl;
//	if(a[0] || a[1] || a[2]) {
//		while(1);;
//	}
//	for(auto [x1, y1, x2, y2] : ans) {
//		mx = max({mx, x1, x2});
//		my = max({my, y1, y2});
//	}
//	for(auto [x1, y1, x2, y2] : ans) cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

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
//#define ls id << 1
//#define rs id << 1 | 1

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e5 + 10;
//const double eps = 1e-8;

//struct point{
//	double x, y;
//	int operator<(const point& e) {
//		if(x == e.x) return y < e.y;
//		return x < e.x;
//	}
//};
//struct line{
//	double k, b;
//	line() {}
//	line(double k, point p) : k(k) {
//		b = p.y - k*p.x;
//	}
//	line(point a, point c) {
//		k = a.x == c.x ? inf : (1.0*a.y-c.y) / (a.x-c.x);
//		b = a.y - k*a.x;
//	}
//};

//int cross(point a, point b, point c) {
//	int x1 = b.x - a.x, y1 = b.y - a.y;
//	int x2 = c.x - a.x, y2 = c.y - a.y;
//	return x1*y2 - y1*x2;
//}
//double dis(line l1, line l2) {
//	return fabs(l1.b - l2.b) / sqrt(l1.k*l1.k + 1);
//}


//void solve(){
//	int n, top = 0;
//	double v0, v1, v2;
//	cin >> n >> v0 >> v1 >> v2;
//	vector<point>a(n+5), st(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i].x >> a[i].y;
//	}

//	if(n == 1){
//		printf("%.10lf\n", 0);
//		return;
//	}

//	sort(all1(a));
//	for(int i = 1;i <= n;i++){
//		while(top >= 2 && cross(st[top-1], st[top], a[i]) <= 0) top--;
//		st[++top] = a[i];
//	}
//	int t = top;
//	for(int i = n-1;i >= 1;i--){
//		while(top > t && cross(st[top-1], st[top], a[i]) <= 0) top--;
//		st[++top] = a[i];
//	}
//	top--;

//	//for(int i = 1;i <= top;i++) cerr << st[i].x << ' ' << st[i].y << endl;
	
//	double k = inf, k1 = v0/v2, k2 = v0/v1, ans = inf;
//	//cerr << k1 << ' ' << k2 << endl;

//	for(int i = 1, j = 2;i <= top;i++){
//		while(cross(st[i], st[i+1], st[j]) < cross(st[i], st[i+1], st[j+1])) j = (j % top) + 1;
//		line l1(st[i], st[i+1]);
//		line l2(l1.k, st[j]);
//		k = l1.k;
//		if((k >= k1 && k <= k2)) ans = min(ans, dis(l1, l2)); 
//		//cerr << st[i].x << ' ' << st[i].y << "  " << st[i+1].x << ' ' << st[i+1].y << "  ";
//		//cerr << st[j].x << ' ' << st[j].y << "  ";
//		//cerr << k << "  ";
//		//cerr << ans << endl;
//	}

//	int p1, p2, l, r;
//	l = 2, r = t;
//	while(l <= r){
//		int mid = l + r >> 1;
//		line le(st[mid-1], st[mid]);
//		if(le.k <= k1) l = mid + 1;
//		else r = mid - 1;
//	}
//	p1 = r;
//	l = t+1, r = top+1;
//	while(l <= r){
//		int mid = l + r >> 1;
//		line le(st[mid-1], st[mid]);
//		if(le.k <= k1) l = mid + 1;
//		else r = mid - 1;
//	}
//	p2 = r;
//	ans = min(ans, dis(line(k1, st[p1]), line(k1, st[p2])));
	
//	l = 2, r = t;
//	while(l <= r){
//		int mid = l + r >> 1;
//		line le(st[mid-1], st[mid]);
//		if(le.k <= k2) l = mid + 1;
//		else r = mid - 1;
//	}
//	p1 = r;
//	l = t+1, r = top+1;
//	while(l <= r){
//		int mid = l + r >> 1;
//		line le(st[mid-1], st[mid]);
//		if(le.k <= k2) l = mid + 1;
//		else r = mid - 1;
//	}
//	p2 = r;
//	ans = min(ans, dis(line(k2, st[p1]), line(k2, st[p2])));

//	printf("%.10lf\n", ans);
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
//#define endl '\n'

//const int N = 1e5 + 10;
//const int M = N*40;
//const int mxn = 1e10;

//int sum[M], ls[M], rs[M], rt, tot;
//void up(int id){
//	sum[id] = sum[ls[id]] + sum[rs[id]];
//}
//void add(int &id, int l, int r, int x) {
//	if(!id) id = ++tot;
//	if(l == r){
//		sum[id]++;
//		return;
//	}
//	int mid = l + r >> 1;
//	if(x <= mid) add(ls[id], l, mid, x);
//	else add(rs[id], mid + 1, r, x);
//	up(id);
//}
//int query(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return sum[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls[id], l, mid, ql, qr);
//	else if(ql > mid) return query(rs[id], mid + 1, r, ql, qr);
//	else return query(ls[id], l, mid, ql, qr) + query(rs[id], mid + 1, r, ql, qr);
//}


//void solve(){
//	int n, L, R;
//	cin >> n >> L >> R;
//	vector<int>a(n+5), pre(n+5);
//	add(rt, -mxn, mxn, 0);
//	int ans = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pre[i] = pre[i-1] + a[i];
//		int l = pre[i] - R, r = pre[i] - L;
//		ans += query(rt, -mxn, mxn, l, r);
//		add(rt, -mxn, mxn, pre[i]);
//	}
//	cout << ans << endl;
//}

//signed main(){
	
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
//#define endl '\n'

//const int N = 1e5 + 10;
//const int M = N*20;

//char ch[M];
//int ls[M], rs[M], tot, rt[N];

//void insert(int pre, int &id, int l, int r, int x, char c){
//	id = ++tot;
//	ls[id] = ls[pre], rs[id] = rs[pre];
//	if(l == r){
//		ch[id] = c;
//		return;
//	}
//	int mid = l + r >> 1;
//	if(x <= mid) insert(ls[pre], ls[id], l, mid, x, c);
//	else insert(rs[pre], rs[id], mid + 1, r, x, c);
//}
//char query(int id, int l, int r, int x){
//	if(l == r) return ch[id];
//	int mid = l + r >> 1;
//	if(x <= mid) return query(ls[id], l, mid, x);
//	else return query(rs[id], mid + 1, r, x);
//}

//void solve(){
//	int n, p = 0, x;
//	char op, c;
//	cin >> n;
//	vector<int>siz(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> op;
//		if(op == 'T'){
//			cin >> c;
//			p++;
//			siz[p] = siz[p-1] + 1;
//			insert(rt[p-1], rt[p], 1, n, siz[p], c);
//		}else if(op == 'U'){
//			cin >> x;
//			rt[p+1] = rt[p-x];
//			siz[p+1] = siz[p-x];
//			p++;
//		}else{
//			cin >> x;
//			cout << query(rt[p], 1, n, x) << endl;
//		}
//	}
//}

//signed main(){
	
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--){
//		solve();
//	}


//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
////#define int long long 
//#define endl '\n'

//const int N = 3e5 + 10;
//const int M = N*50;
//const int mxn = 1e9;

//int rt, tr[M], ls[M], rs[M], tag[M], tot;
//int getnode(int l, int r){
//	tot++;
//	tag[tot] = -1;
//	return tot;
//}
//void up(int id){
//	tr[id] = tr[ls[id]] + tr[rs[id]];
//}
//void settag(int id, int x, int l, int r){
//	tag[id] = x;
//	tr[id] = (r-l+1) * x;
//}
//void down(int id, int l, int r){
//	int mid = l + r >> 1;
//	if(!ls[id]) ls[id] = getnode(l, mid);
//	if(!rs[id]) rs[id] = getnode(mid+1, r);
//	settag(ls[id], tag[id], l, mid);
//	settag(rs[id], tag[id], mid+1, r);
//	tag[id] = -1;
//}
//void modify(int &id, int l, int r, int ql, int qr, int v){
//	if(!id) id = getnode(l, r);
//	if(ql <= l && r <= qr){
//		settag(id, v, l, r);
//		return;
//	}
//	if(~tag[id]) down(id, l, r);
//	int mid = l + r >> 1;
//	if(qr <= mid) modify(ls[id], l, mid, ql, qr, v);
//	else if(ql > mid) modify(rs[id], mid + 1, r, ql, qr, v);
//	else modify(ls[id], l, mid, ql, qr, v), modify(rs[id], mid + 1, r, ql, qr, v);
//	up(id);
//}

//void solve(){
//	int n, q, op, l, r;
//	cin >> n >> q;
//	while(q--){
//		cin >> l >> r >> op;
//		if(op == 1){
//			modify(rt, 1, mxn, l, r, 1);
//			cout << n-tr[rt] << endl;
//		}else{
//			modify(rt, 1, mxn, l, r, 0);
//			cout << n-tr[rt] << endl;
//		}
//	}
//}

//signed main(){
	
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--){
//		solve();
//	}

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
////#define int long long 
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define ls id << 1
//#define rs id << 1 | 1


//const int N = 3e5 + 10;

//int tr[N<<3], tag[N<<3], len[N<<3], m;
//vector<int>idx;
//void build(int id, int l, int r){
//	tag[id] = -1;
//	if(l == r){
//		len[id] = idx[l] - idx[l-1];
//		return;
//	}
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//	len[id] = len[ls] + len[rs];
//}
//void settag(int id, int x){
//	tag[id] = x;
//	tr[id] = len[id] * x;
//}
//void down(int id){
//	settag(ls, tag[id]);
//	settag(rs, tag[id]);
//	tag[id] = -1;
//}
//void up(int id){
//	tr[id] = tr[ls] + tr[rs];
//}
//void modify(int id, int l, int r, int ql, int qr, int v) {
//	if(ql <= l && r <= qr) {
//		settag(id, v);
//		return;
//	}
//	if(~tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(qr <= mid) modify(ls, l, mid, ql, qr, v);
//	else if(ql > mid) modify(rs, mid + 1, r, ql, qr, v);
//	else modify(ls, l, mid, ql, qr, v), modify(rs, mid + 1, r, ql, qr, v);
//	up(id);
//}

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	vector<array<int,3>>qur(q+5);
//	for(int i = 1;i <= q;i++){
//		cin >> qur[i][0] >> qur[i][1] >> qur[i][2];
//		qur[i][2] %= 2;
//		qur[i][1]++;
//		idx.push_back(qur[i][0]);
//		idx.push_back(qur[i][1]);
//	}
//	sort(all(idx));
//	idx.erase(unique(all(idx)), idx.end());
//	for(int i = 1;i <= q;i++){
//		qur[i][0] = lower_bound(all(idx), qur[i][0]) - idx.begin() + 1;
//		qur[i][1] = lower_bound(all(idx), qur[i][1]) - idx.begin();
//	}

//	m = idx.size()-1;
//	build(1, 1, m);

//	for(int i = 1;i <= q;i++){
//		auto [l, r, op] = qur[i];
//		modify(1, 1, m, l, r, op);
//		cout << n - tr[1] << endl;
//	}
//}

//signed main(){
	
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	//cin >> t;
//	while(t--){
//		solve();
//	}

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
////#define int long long 
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 1e5 + 10;
//const int M = N*20;

//unordered_map<int,int>rt;
//int tr[M], ls[M], rs[M], tot;
//void up(int id){
//	tr[id] = tr[ls[id]] + tr[rs[id]];
//}
//void change(int &id, int l, int r, int x, int v){
//	if(!id) id = ++tot;
//	if(l == r){
//		tr[id] = v;
//		return;
//	}
//	int mid = l + r >> 1;
//	if(x <= mid) change(ls[id], l, mid, x, v);
//	else change(rs[id], mid + 1, r, x, v);
//	up(id);
//}
//int query(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return tr[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls[id], l, mid, ql, qr);
//	else if(ql > mid) return query(rs[id], mid + 1, r, ql, qr);
//	else return query(ls[id], l, mid, ql, qr) + query(rs[id], mid + 1, r, ql, qr);
//}

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		change(rt[a[i]], 1, n, i, 1);
//	}

//	char op;
//	int x, y, p;
//	while(m--){
//		cin >> op;
//		if(op == 'C'){
//			cin >> x >> p;
//			change(rt[a[x]], 1, n, x, 0);
//			a[x] = p;
//			change(rt[a[x]], 1, n, x, 1);
//		}else{
//			cin >> x >> y >> p;
//			cout << query(rt[p], 1, n, x, y) << endl;
//		}
//	}
//}

//signed main(){
	
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//void solve(){
//	int n, m, q, k;
//	cin >> n >> m >> q >> k;
//	vector<int>gd(n+5), cnt(n+5), vis(n+5);

//	queue<int>que;
//	for(int i = 1, x;i <= q;i++){
//		cin >> x;
//		gd[x] = 1;
//		que.push(x);
//	}

//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		g[v].push_back(u);
//	}

//	while(que.size()){
//		int u = que.front();
//		que.pop();
//		for(auto v : g[u]) if(!gd[v]) {
//			cnt[v]++;
//			if(cnt[v] == k+1) {
//				gd[v] = 1;
//				que.push(v);
//			}
//		}
//	}

//	for(int i = 1;i <= n;i++) {
//		if(gd[i]) cout << 'S';
//		else cout << 'B';
//	}
//}

//signed main(){
	
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, m, nn;
//	cin >> n >> m;
//	nn = 2*n;
//	vector<int>l(nn+5), r(nn+5), dis(nn+5, inf);
//	vector<vector<array<int, 2>>>g(nn+5);
//	for(int i = 1, x, y;i <= n;i++){
//		cin >> x >> y;
//		l[i] = 0; r[i] = x;
//		l[i+n] = y; r[i+n] = inf;
//	}
//	for(int i = 1, u, v, w;i <= m;i++){
//		cin >> u >> v >> w;
//		g[u].push_back({v, w});
//		g[u].push_back({v+n, w});
//		g[u+n].push_back({v, w});
//		g[u+n].push_back({v+n, w});
//	}

//	auto nxd = [&](int u, int v, int w) -> int {
//		if(dis[u]+w > r[v] || r[u]+w < l[v]) return inf;
//		return max(dis[u]+w, l[v]);
//	};
//	dis[1] = 0;

//	//cerr << nxd(1, 2, 3) << endl;

//	priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>>que;
//	que.push({0, 1});
//	while(que.size()){
//		auto [d, u] = que.top();
//		que.pop();
//		//cerr << u << ' ' << d << endl;
//		if(d > dis[u]) continue;
//		for(auto [v, w] : g[u]) {
//			int tmp = nxd(u, v, w);
//			if(tmp >= dis[v]) continue;
//			dis[v] = tmp;
//			que.push({dis[v], v});
//		}
//	}

//	//cerr << nxd(3, 9, 3) << endl;

//	//cerr << endl;

//	//for(int i = 1;i <= nn;i++) cerr << i << ' ' << dis[i] << endl;

//	if(min(dis[n], dis[nn]) == inf) cout << -1 << endl;
//	else cout << min(dis[n], dis[nn]) << endl;
//}

//signed main(){
	
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 10;
//const int M = N*20;

//int rt[N], tr[M], ls[M], rs[M], a[N], tot;
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
//void change(int pre, int &id, int l, int r, int x, int v){
//	id = ++tot;
//	ls[id] = ls[pre]; rs[id] = rs[pre];
//	if(l == r){
//		tr[id] = v;
//		return;
//	}
//	int mid = l + r >> 1;
//	if(x <= mid) change(ls[pre], ls[id], l, mid, x, v);
//	else change(rs[pre], rs[id], mid + 1, r, x, v);
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

//	int v, op, loc, val;
//	for(int i = 1;i <= m;i++){
//		cin >> v >> op >> loc;
//		if(op == 1){
//			cin >> val;
//			change(rt[v], rt[i], 1, n, loc, val);
//		}else{
//			cout << query(rt[v], 1, n, loc) << endl;
//			rt[i] = rt[v];
//		}
//	}
//}

//signed main(){
	
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 10;


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	if(n == 1) {
//		cout << 0 << endl;
//		return;
//	}
//	if(k == 2){
//		cout << n-1 << endl;
//		return;
//	}
//	int ans = n / (k-1);
//	if((n%(k-1)) > 1) ans++;
//	cout << ans << endl;
//}

//signed main(){
	
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 10;


//void solve(){
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	int cnt = 0, ze = 0;
//	char pre = '1';
//	for(auto c : s){
//		cnt += (c == '1');
//		if(c == '0' && pre == '1') ze++;
//		pre = c; 
//	}
//	if(cnt > ze) cout << "Yes\n";
//	else cout << "No\n";
//}

//signed main(){
	
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int inf = 0x3f3f3f3f3f3f3f3f;
//const int N = 1e6 + 10;

//int bitcnt(int x){
//	int ret = 0;
//	while(x){
//		ret += (x & 1);
//		x >>= 1;
//	}
//	return ret;
//}

//void solve(){
//	int n;
//	cin >> n;
//	int m = bitcnt(n);
//	//cerr << m << endl;

//	if(m == 1){
//		cout << 1 << endl << n << endl;
//		return;
//	}

//	vector<int>v(m+5);
//	int p = 1, t = n;
//	for(int i = 0;t;i++) if((1ll<<i) & t){
//		v[p++] = (1ll<<i);
//		t -= (1ll<<i);
//	}

//	vector<int>a(m+5);
//	auto dfs = [&](auto self, int l, int r, int p) -> void {
//		if(l == r) return;
//		for(int i = 1;i < p;i++) a[l] += v[i];
//		for(int i = l+1;i <= r;i++) a[i] += v[p];
//		self(self, l+1, r, p-1);
//	};

//	dfs(dfs, 1, m+1, m);

//	cout << m+1 << endl;
//	for(int i = 1;i <= m+1;i++) cout << a[i] << ' ';
//	cout << endl;
//}

//signed main(){
	
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;


void solve(){
	int n;
	cin >> n;
	vector<int>a(n+5);
	vector<array<int,20>>f(n+5);
	vector<vector<int>>g(n+5);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1, u, v;i < n;i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	auto dfs = [&](auto self, int u, int fa) -> void {
		for(int i = 1;i < 20;i++) f[u][i] = a[u]*i;
		for(auto v : g[u]) if(v != fa){
			self(self, v, u);
			for(int i = 1;i < 20;i++){
				int mn = inf;
				for(int j = 1;j < 20;j++) if(i != j) {
					mn = min(mn, f[v][j]);
				}
				f[u][i] += mn;
			}
		}
	};

	dfs(dfs, 1, 0);

	int ans = inf;
	for(int i = 1;i < 20;i++) ans = min(ans, f[1][i]);
	cout << ans << endl;
}

signed main(){
	
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}