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