#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#define BowTen ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const ll N = 1e5 + 5;
//struct node {
//	ll l, r, min, tag;
//}seg[N << 2];
//ll n, q, rd[N], ans = 0;
//
//struct ques {
//	ll l, r;
//}que[N];
//
//void settag(ll id, ll val) {
//	seg[id].min += val;
//	seg[id].tag += val;
//}
//
//void down(ll id) {
//	if (seg[id].tag == 0) return;
//	settag(id << 1, seg[id].tag);
//	settag(id << 1 | 1, seg[id].tag);
//	seg[id].tag = 0;
//}
//
//void modify(ll id, ll ql, ll qr, ll val) {
//	ll l = seg[id].l, r = seg[id].r;
//	if (r < ql || l > qr) return;
//	if (l >= ql && r <= qr) {
//		settag(id, val);
//		return;
//	}
//	down(id);
//	ll mid = (l + r) >> 1;
//	if (qr <= mid) {
//		modify(id << 1, ql, qr, val);
//	}
//	else if (ql > mid) {
//		modify(id << 1 | 1, ql, qr, val);
//	}
//	else {
//		modify(id << 1, ql, qr, val);
//		modify(id << 1 | 1, ql, qr, val);
//	}
//	seg[id].min = min(seg[id << 1].min, seg[id << 1 | 1].min);
//}
//
//void built(ll id, ll l, ll r) {
//	seg[id].l = l;
//	seg[id].r = r;
//	if (l == r) {
//		seg[id].min = rd[l];
//		return;
//	}
//	ll mid = (l + r) >> 1;
//	built(id << 1, l, mid);
//	built(id << 1 | 1, mid + 1, r);
//	seg[id].min = min(seg[id << 1].min, seg[id << 1 | 1].min);
//}
//
//ll getmin(ll id, ll ql, ll qr) {
//	ll l = seg[id].l, r = seg[id].r;
//	if (l >= ql && r <= qr)
//		return seg[id].min;
//	down(id);
//	ll mid = (l + r) >> 1;
//	if (qr <= mid)
//		return getmin(id << 1, ql, qr);
//	else if (ql > mid)
//		return getmin(id << 1 | 1, ql, qr);
//	else
//		return min(getmin(id << 1, ql, qr), getmin(id << 1 | 1, ql, qr));
//}
//
//ll cmp(ques e1, ques e2) {
//	/*if ((e1.r - e1.l) < (e2.r - e2.l))
//		return 1;
//	else if ((e1.r - e1.l) > (e2.r - e2.l))
//		return 0;
//	return e1.l < e2.l;*/
//
//	if (e1.r == e2.r)
//		return e1.l < e2.l;
//	return e1.r < e2.r;
//}
//
//int main()
//{
//	BowTen;
//
//	cin >> n >> q;
//	for (ll i = 1;i < n;i++)
//		cin >> rd[i];
//
//	built(1, 1, n);
//
//	for (ll i = 0;i < q;i++) {
//		cin >> que[i].l >> que[i].r;
//		if (que[i].l > que[i].r)
//			swap(que[i].l, que[i].r);
//		que[i].l += 1;
//	}
//	sort(que, que + q, cmp);
//
//	for (ll i = 0, m;i < q;i++) {
//		m = getmin(1, que[i].l, que[i].r);
//		if (m == 0)
//			continue;
//		ans += m;
//		modify(1, que[i].l, que[i].r, -m);
//	}
//
//	cout << ans;
//
//	return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//
//	int t, n, x;
//	cin >> t;
//	while (t--) {
//		cin >> n >> x;
//		if (n <= 2) {
//			cout << "1\n";
//		}
//		else {
//			n -= 2;
//			int mod = n % x;
//			int ans = n / x + 2;
//			if (mod == 0) ans--;
//			cout << ans << '\n';
//		}
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//
//int main()
//{
//	int t, n, m, sq[5];
//	cin >> t;
//	while (t--) {
//		int f = 0;
//		cin >> n >> m;
//		while (n--) {
//			for (int i = 1;i <= 4;i++) {
//				cin >> sq[i];
//			}
//			if (sq[2] == sq[3])
//				f = 1;
//		}
//		if (m < 2 || m & 1)
//			f = 0;
//		if (f)puts("YES");
//		else puts("NO");
//	}
//
//	return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//
//
//int main()
//{
//	int a[4], a1[4], b[4], b1[4], n, ans = 0;
//	cin >> n >> a[1] >> a[2] >> a[3] >> b[1] >> b[2] >> b[3];
//	for (int i = 1;i <= 3;i++) {
//		a1[i] = a[i];
//		b1[i] = b[i];
//	}
//
//	int cnt = 3, l[4] = { 0 };
//	while (cnt--) {
//		int m = 1;
//		for (int i = 1;i <= 3;i++) {
//			if (a[i] > a[m])
//				for (int j = 0;j < 4;j++) {
//					if (l[j] == i)
//						break;
//					if (j == 3)
//						m = i;
//				}
//					
//		}
//		for (int i = 1;i <= 3;i++) {
//			if (i != m) continue;
//				for (int j = i - 1, t, c = 0;c < 2;c++, j++) {
//					j = j == 0 ? 3 : j;
//					j = j == 4 ? 1 : j;
//					t = min(a[i], b[j]);
//					ans += t;
//					a[i] -= t;
//					b[j] -= t;
//				}
//		}
//		l[cnt] = m;
//	}
//
//	cout << n - ans << ' ';
//
//	ans = 0;
//
//	for (int i = 1, t;i <= 3;i++) {
//		int j = i + 1;
//		j = j == 0 ? 3 : j;
//		j = j == 4 ? 1 : j;
//		t = min(a1[i], b1[j]);
//		a1[i] -= t;
//		b1[j] -= t;
//		ans += t;
//	}
//
//	cout << ans;
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//
//int main()
//{
//	ll t, n, a;
//	cin >> t;
//	while (t--) {
//		int ans = 0;
//		cin >> n;
//		a = round(sqrt(n));
//		ans += a - 1;
//		if (a * a >= n)
//			ans += a - 1;
//		else
//			ans += a;
//		cout << ans << '\n';
//	}
//	return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//typedef long long ll;
//ll num[N], n, pre = 0, ans = 0;
//map<ll, ll>mp;
//
//int main()
//{
//	cin >> n;
//	mp[0] = 0;
//	for (int i = 1;i <= n;i++) {
//		cin >> num[i];
//		pre += num[i];
//		if (mp.find(pre) != mp.end()) {
//			ans++;
//			mp.clear();
//			mp[0] = i-1;
//			pre = num[i];
//		}
//		mp[pre] = i;
//	}
//
//	cout << ans;
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//
//int main()
//{
//	int a[4], a1[4], b[4], b1[4], n, ans = 0;
//	cin >> n >> a[1] >> a[2] >> a[3] >> b[1] >> b[2] >> b[3];
//	for (int i = 1;i <= 3;i++) {
//		a1[i] = a[i];
//		b1[i] = b[i];
//	}
//	
//	cout << max(0, max(a[1] - b[1] - b[3], max(a[2] - b[2] - b[1], a[3] - b[3] - b[2]))) << ' ';
//
//	ans = 0;
//
//	for (int i = 1, t;i <= 3;i++) {
//		int j = i + 1;
//		j = j == 0 ? 3 : j;
//		j = j == 4 ? 1 : j;
//		t = min(a1[i], b1[j]);
//		a1[i] -= t;
//		b1[j] -= t;
//		ans += t;
//	}
//
//	cout << ans;
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const ll N = 2e5 + 5;
//const ll mod = 1e9 + 7;
//ll n, a[N], b[N], c[N], p = 1, cnt = 0;
//string s;
//
//int main()
//{
//	int t = 1;
//
//	while (t--) {
//		cin >> n;
//		cin >> s;
//		s = ' ' + s;
//		for (int i = 1;i <= n;i++) {
//			a[i] = a[i - 1];
//			b[i] = b[i - 1];
//			c[i] = c[i - 1];
//			if (s[i] == 'a') {
//				a[i] += (ll)pow(3,cnt) % mod;
//			}
//			else if (s[i] == 'b') {
//				b[i] += a[i];
//			}
//			else if (s[i] == 'c') {
//				c[i] += b[i];
//			}
//			else if (s[i] == '?') {
//				a[i] *= 3;
//				b[i] *= 3;
//				c[i] *= 3;
//				a[i] += (ll)pow(3,cnt) % mod;
//				b[i] += a[i - 1];
//				c[i] += b[i - 1];
//				p *= 3;
//				p %= mod;
//				cnt++;
//			}
//			a[i] %= mod;
//			b[i] %= mod;
//			c[i] %= mod;
//		}
//
//		cout << c[n];
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	char s[200];
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> s;
//		cout << strlen(s) << '\n';
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//
//int main()
//{
//	ll t;
//	cin >> t;
//	while (t--) {
//		ll x, n = 0;
//		cin >> x;
//		n = ceil((sqrt(1 + 8 * x) - 1) / 2.0);
//		ll now = (n + n * n) / 2;
//		if (now == x) {
//			cout << n << '\n';
//			continue;
//		}
//		for (int i = n;i >= 1;i--) {
//			if (now - i - 1 >= x) {
//				now -= i + 1;
//			}
//		}
//		n += now - x;
//		cout << n << '\n';
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int a,b,t;
//	cin >> t;
//	while (t--) {
//		cin >> a >> b;
//		cout << a - 1 << ' ' << b << '\n';
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int t, num[550] = { 0 }, n, x;
//	cin >> t;
//	while (t--) {
//		int f = 1, cnt = 0;
//		cin >> n >> x;
//		for (int i = 1;i <= n;i++) {
//			cin >> num[i];
//			if (num[i] < num[i - 1])
//				f = 0;
//		}
//		if (f) {
//			cout << "0\n";
//			continue;
//		}
//		f = 1;
//		for (int i = 1;i < n && f;i++) {
//			if (num[i] <= num[i + 1])
//				continue;
//
//			if (num[i] == num[i - 1] || x >= num[i] || num[i-1] > num[i+1] || x > num[i+1]) {
//				f = 0;
//				break;
//			}
//
//			int j = i - 1, sa = 0;
//			for (j;j >= 0;j--) {
//				if (num[j] <= x)
//					break;
//				if (num[j] == num[j + 1])
//					sa++;
//			}
//
//			cnt += i - j - sa;
//
//			int t = num[i];
//			for (int m = i;m > j + 1;m--) {
//				num[m] = num[m - 1];
//			}
//			num[j + 1] = x;
//			x = t;
//
//		}
//		if (f)
//			cout << cnt << '\n';
//		else
//			cout << "-1\n";
//	}
//	return 0;
//}



//#include<iostream>
//#include<bits/stdc++.h>
//using namespace std;


//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		string s;
//		cin >> s;
//		s = ' ' + s;
//		char c;
//		cin >> c;
//		int f = 0;
//		for (int i = 1, len = s.size();i <= len && f == 0;i++) {
//			if (s[i] == c && i & 1 == 1)
//				f = 1;
//		}
//		if (f)
//			puts("YES");
//		else
//			puts("NO");
//	}
//	return 0;
//}




//#include<iostream>
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll t, l, r, a, p1, p2;
//ll fun(ll x) {
//	return x / a + x % a;
//}
//
//int main()
//{
//	cin >> t;
//	while (t--) {
//		cin >> l >> r >> a;
//		p2 = r - r % a;
//		p2 = max(l, p2);
//		cout << max(fun(r), max(fun(p2 - 1 >= l ? p2 - 1 : l), fun(p2))) << '\n';
//	}
//
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//struct node {
//	ll pos, pre;
//}a[N];
//ll n, m, min1;
//
//int cmp(node e1, node e2) {
//	return e1.pos < e2.pos;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		vector<pair<ll,ll>>pos;
//		pos.push_back({ 0,-1 });
//		for (int i = 1;i <= n;i++) {
//			cin >> a[i].pos;
//			pos.push_back({ a[i].pos,i });
//		}
//		sort(pos.begin(), pos.end());
//		for (int i = 1, len = pos.size();i < len;i++) {
//			a[pos[i].second].pre = pos[i].first - pos[i - 1].first;
//		}
//		int mi = 1, ma = 1;
//		sort(a + 1, a + 1 + n, cmp);
//		for (int i = 1;i <= n;i++) {
//			if (a[i].pre < a[mi].pre)
//				mi = i;
//			if (a[i].pre > a[ma].pre)
//				ma = i;
//		}
//		min1 = a[mi].pre;
//			
//		if (mi + 1 <= n)
//			a[mi + 1].pre += a[mi].pre + 1;
//
//			min1 = max(min1, max(m - a[n].pos - 1, (a[ma].pre - 1) / 2));
//			cout << min1 << '\n';
//	}
//
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll siz[3] = { 6,8,10 };
//ll tim[3] = { 15,20,25 };
//ll mod[3];
//
////6  8  10
////15 20 250
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		ll n;
//		cin >> n;
//		//ll last = 10;
//		//for (int i = 0;i < 3;i++) {
//		//	mod[i] = n % siz[i];
//		//	if(mod[i])
//		//	for (int j = 0;j < 3;j++) {
//		//		if (siz[j] >= mod[i]) {
//		//			mod[i] = siz[j] - mod[i];
//		//			break;
//		//		}
//		//	}
//		//	if (mod[i] < last)
//		//		last = mod[i];
//		//}
//		//cout << (ll)((n + last) * 2.5) << '\n';
//		if (n <= 6)
//			cout << 15 << '\n';
//		else {
//			if (n % 2 == 1)
//				n += 1;
//			cout << (n * 5ll)/2ll << '\n';
//
//		}
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		int m, n;
//		cin >> m >> n;
//		priority_queue<pair<int ,pair<int,int>>>que;
//		for (int i = 1, x, w;i <= n;i++) {
//			cin >> x >> w;
//			if (que.size() < 2*m)
//				que.push({ w,{x,i} });
//			else if (w < que.top().first) {
//				que.pop();
//				que.push({ w,{x,i} });
//			}
//		}
//		ll sum = 0;
//		vector < pair<int, int> > pos;
//		for (int i = 0;i < 2*m;i++) {
//			sum += que.top().first;
//			pos.push_back(que.top().second);
//			que.pop();
//		}
//		cout << sum << '\n';
//		sort(pos.begin(), pos.end());
//		
//		for (int p = pos.size() - 1, q = 0;p > q;q++, p--) {
//			cout << pos[q].second << ' ' << pos[p].second << '\n';
//		}
//	}
//
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e3 + 5;
//int s[N], ans[N], pos[N];
//int n;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		for (int i = 1;i <= n;i++) {
//			cin >> s[i];
//			pos[s[i]] = i;
//		}
//		for (int i = n, left;i >= 1;i--) {
//			if (pos[i] == i) {
//				ans[i] = 0;
//				continue;
//			}
//			if (pos[i] > i) {
//				left = pos[i] - i;
//			}
//			else {
//				left = pos[i];
//			}
//			for (int j = 1;j <= i;j++) {
//				pos[j] -= left;
//				if (pos[j] < 1) {
//					pos[j] += i;
//				}
//			}
//			ans[i] = left;
//		}
//		for (int i = 1;i <= n;i++) {
//			cout << ans[i] << ' ';
//		}
//		cout << '\n';
//	}
//
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int a;
//	cin >> a;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//const int N = 1e5 + 5;
//int m, a[2][N];
//
//int main() 
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> m;
//		int sum[3] = { 0 };
//		for (int i = 1; i <= 2; i++) {
//			for (int j = 1; j <= m; j++) {
//				cin >> a[i][j];
//				sum[i] += a[i][j];
//			}
//		}
//		sum[2] = 0;
//		int ans = 0x3f3f3f3f;
//		for (int i = 1; i <= m; i++) {
//			sum[1] -= a[1][i];
//			sum[2] += a[2][i - 1];
//			ans = min(ans, max(sum[1], sum[2]));
//		}
//		cout << ans;
//		if (t)
//			cout << '\n';
//
//	}
//
//	return 0;
//}79.21 - 29.4 = 49.81 - 8.9 = 40.91



//#include<bits/stdc++.h>
//using namespace std;
//const double mi = 0.00001;
//
//int main()
//{
//    double a,b,c,delt;
//    cin >> a >> b >> c;
//    delt = b * b - 4 * a * c;
//    cout << *fixed << setprecision(2);
//    if(a < mi && b < mi){
//        if(c < mi)
//            cout << "Infinitely solution";
//        else
//            cout << "No solution";
//        return 0;
//    }
//    //one root
//    if(a < mi && b > mi){
//        cout << "x=" << (-c / b);
//        return 0;
//    }
//    //two root
//    if(a > mi){
//        if(delt < 0)
//            cout << "Imaginary root";
//        else if(delt < mi)
//            cout << "x1=x2=" << (-b/2*a);
//        else
//            cout << "x1=" << ((-b-sqrt(delt))/(2*a)) << ";x2=" << ((-b+sqrt(delt))/(2*a));
//        return 0;
//    }
//    return 0;
//}
//
//
//
//
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//       float a,b,c;
//       cin>>a>>b>>c;
//       if(a==0&&b==0&&c==0)
//           {
//           cout<<"Infinitely solution"<<endl;
//
//           }else if(a==0&&b==0&&c!=0)
//           {
//           cout<<"No solution"<<endl;
//       }else if((pow(b,2)-4*a*c)<0)
//       {
//           cout<<"Imaginary root"<<endl;
//       }else if(a==0&&b!=0)
//       {
//           cout<<"x="<<setprecision(2)<<fixed<<-b/c<<endl;
//
//       }else if((pow(b,2)-4*a*c)==0)
//       {
//           cout<<"x1=x2="<<setprecision(2)<<fixed<<-b/(2*a)<<endl;
//       }else
//       {
//           cout<<"x1="<<setprecision(2)<<fixed<<(-b+sqrt(pow(b,2)-4*a*c))/(2*a)<<";x2="<<setprecision(2)<<fixed<<(-b-sqrt(pow(b,2)-4*a*c))<<endl;
//       }
//
//
//     return 0;
// }




//#include<bits/stdc++.h>
//using namespace std;
//const double mi = 0.00005;
//
//int main()
//{
//	double a, b, c;
//	cin >> a >> b >> c;
//	//负数
//	if (a < 0 || b < 0 || c < 0) {
//		cout << "Don`t make a triangle";
//		return 0;
//	}
//	//能构成
//	if (abs(a - b) < c && abs(a - c) < b && abs(b - c) < a && a + b > c && b + c > a && a + c > b) {
//
//	}
//	else {
//		cout << "Don`t make a triangle";
//		return 0;
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const double prc = 0.0000001;
//
//int main()
//{
//	double W, H, x1, x2, y1, y2, w, h, w1, h1, mw, mh;
//	int t;
//	cin >> t;
//	cout << fixed;
//	while (t--) {
//		cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
//		w1 = x2 - x1;
//		h1 = y2 - y1;
//		double ans = -1;
//		mw = max(W - x2, x1);
//		mh = max(H - y2, y1);
//		if (w1 + w - W > prc && h1 + h - H > prc) {
//			cout << "-1\n";
//			continue;
//		}
//		int f1 = 0, f2 = 0;
//
//		//if(w1 + w - W > prc)
//		//mw = max(W - x2, x1);
//		//mh = max(H - y2, y1);
//		//cout << min(w - mw, h - mh) << '\n';
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const double prc = 0.000001;
//
//int main()
//{
//	cout << fixed;
//	double W, H, w, h, x1, x2, y1, y2;
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
//		double w1 = x2 - x1, h1 = y2 - y1;
//		double a1, a2;
//		int f1 = 0, f2 = 0;
//		if (w1 + w <= W) {
//			f1 = 1;
//			double mw = max(W - x2, x1);
//			if (mw >= w)
//				a1 = 0;
//			else
//				a1 = w - mw;
//		}
//		if (h1 + h <= H) {
//			f2 = 1;
//			double mh = max(H - y2, y1);
//			if (mh >= h)
//				a2 = 0;
//			else
//				a2 = h - mh;
//		}
//		if (f1 && f2)
//			cout << min(a1, a2) << '\n';
//		else if (f1)
//			cout << a1 << '\n';
//		else if (f2)
//			cout << a2 << '\n';
//		else
//			cout << "-1\n";
//	}
//
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, d, a[N], pos[N], pre[N];
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> d;
//		memset(pos, 0, sizeof pos);
//		memset(pre, 0, sizeof pre);
//		memset(a, 0, sizeof a);
//		int mi = 0, ma = 0;
//		for (int i = 1, t, las = 0; i <= n; i++) {
//			cin >> t;
//			a[t] = i;
//			pos[i] = t;
//			pre[i] = i - 1 - pos[i - 1];
//			las = t;
//			if (mi == 0 || pre[i] < pre[mi])
//				mi = i;
//			if (ma == 0 || pre[i] > pre[ma])
//				ma = i;
//		}
//		a[pos[mi]] = 0;
//		int a1 = 0, a2 = 0;
//		if(pos)
//	}
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, d, sed[N], pos[N], pre[N];
//
//void init()
//{
//	memset(sed, 0, sizeof sed);
//	memset(pos, 0, sizeof pos);
//	memset(pre, 0, sizeof pre);
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		init();
//		cin >> n >> d;
//		int mi = 0, ma = 0;
//		for (int i = 1; i <= n; i++) {
//			cin >> pos[i];
//			sed[pos[i]] = i;
//			pre[i] = pos[i] - pos[i - 1];
//			if (!mi || pre[i] < pre[mi])
//				mi = i;
//			if (!ma || pre[i] > pre[ma])
//				ma = i;
//		}
//		int a1 = -1, a2 = -1;
//		//放最后
//		if (sed[d] == 0) {
//			fun();
//			sed[pos[mi]] = 0;
//			sed[d] = mi;
//			if (mi != n) {
//				pre[mi + 1] += 1 + pre[mi];
//			}
//			pre[mi] = 
//			for (int i = 1; i <= n; i++) {
//				if (pre[i] < pre[mi])
//					mi = i;
//				if (pre[i] > pre[ma])
//					ma = i;
//			}
//		}
//		//放最大中间
//
//	}
//	return 0;
//}





//#include<iostream>
//using namespace std;
//const int N = 2e5 + 5;
//int n, q, l, r;
//char s[N];
//char tpl[6][4] = {"abc","acb","bac","bca","cab","cba"};
//
//int main()
//{
//	scanf("%d %d", &n, &q);
//	scanf("%s", s);
//	while (q--) {
//		scanf("%d %d",&l,&r);
//		int ans = -1;
//		for (int i = 0, t = 0; i < 6; i++) {
//			t = 0;
//			for (int j = l - 1, f = 0; j < r; j++, f++) {
//				if (f >= 3)
//					f = 0;
//				if (s[j] != tpl[i][f])
//					t++;
//			}
//			if (ans == -1 || t < ans)
//				ans = t;
//			if (!ans)
//				break;
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//char s[N], tpl[6][5] = { "abc","acb","bac","bca","cab","cba"};
//int n, q, l, r, pre[6][N] = { 0 };
//
//int main()
//{
//	scanf("%d %d", &n, &q);
//	scanf("%s", s);
//	for (int i = 0; i < 6; i++) {
//		for (int j = 1; j <= n; j++) {
//			pre[i][j] = pre[i][j - 1] + (s[j-1] != tpl[i][(j - 1) % 3]);
//		}
//	}
//	while (q--) {
//		scanf("%d %d", &l, &r);
//		int ans = INT_MAX;
//		for (int i = 0; i < 6; i++) {
//			ans = min(ans, (pre[i][r] - pre[i][l - 1]));
//		}
//		printf("%d\n",ans);
//	}
//	return 0;
//}


//#include<iostream>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//using namespace std;
//#define INF 0x3f3f3f3f
//typedef pair<int, int> PII;
//#define rep(i, n) for (int i = 1; i <= (n); ++i)
//#define rrep(i, n) for (int i = m; i >= (1); --i)
//typedef long long ll;
//
//const int N = 200010;
//int s[6][N];
//char c[6][3] = { {'a', 'b', 'c'}, {'a', 'c', 'b'}, {'b', 'a', 'c'}, {'b', 'c', 'a'}, {'c', 'b', 'a'}, {'c', 'a', 'b'} };
//char s0[N];
//
//int main() {
//	int n, m;
//	scanf("%d %d", &n, &m);
//	scanf("%s", s0);
//	for (int i = 0; i < 6; i++) {
//		for (int j = 1; j <= n; j++) s[i][j] = s[i][j - 1] + (s0[j - 1] != c[i][(j - 1) % 3]);
//	}
//	while (m--) {
//		int l, r;
//		scanf("%d %d", &l, &r);
//		int ans = INF;
//		for (int i = 0; i < 6; i++) {
//			int sum = s[i][r] - s[i][l - 1];
//			ans = min(ans, sum);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, d, pos[N], pre[N];
//
//void init()
//{
//	memset(pos, 0, sizeof pos);
//	memset(pre, 0, sizeof pre);
//}
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		init();
//		cin >> n >> d;
//		int mi = 0, fn = 0;
//		for (int i = 1; i <= n; i++) {
//			cin >> pos[i];
//			if (pos[i] == d)
//				fn = 1;
//			pre[i] = pos[i] - pos[i - 1] - 1;
//			if (mi == 0 || pre[i] < pre[mi])
//				mi = i;
//		}
//
//		int a1 = INT_MAX, ma = 0;
//		if (fn == 0) {
//			if (mi == n) {
//				pre[mi] += d - pos[mi];
//			}
//			else {
//				pre[mi + 1] += 1 + pre[mi];
//				pre[mi] = d - pos[n] - 1;
//			}
//			pos[mi] = n;
//		}
//		for (int i = 1; i <= n; i++) {
//			a1 = min(a1, pre[i]);
//			if (ma == 0 || pre[i] > pre[ma])
//				ma = i;
//		}
//
//		pre[ma] = (pre[ma] - 1) / 2;
//		pre[mi] = pre[ma];
//		int a2 = INT_MAX;
//		for (int i = 1; i <= n; i++) {
//			a2 = min(a2, pre[i]);
//		}
//		if (a1 == INT_MAX)
//			a1 = 0;
//		cout << max(a1, a2) << '\n';
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, d;
//
//int fun(vector<int> &vec) {
//	int mn = INT_MAX, mx = 0;
//	for (int i = 1; i < n; i++) {
//		mn = min(vec[i] - vec[i - 1] - 1, mn);
//		mx = max(vec[i] - vec[i - 1] - 1, mx);
//	}
//	return min(mn, max(d - vec.back() - 1, (mx - 1) / 2));
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> d;
//		vector<int>a(n+1);
//		int mn = d, mn_id = 0;
//		for (int i = 1; i <= n; ++i) {
//			cin >> a[i];
//			if (a[i] - a[i - 1] - 1 < mn) {
//				mn = a[i] - a[i - 1] - 1;
//				mn_id = i;
//			}
//		}
//
//		vector<int>sche;
//		for (int i = 0; i <= n; i++) {
//			if (i != mn_id)
//				sche.push_back(a[i]);
//		}
//		int ans = fun(sche);
//
//		if (mn_id > 1) {
//			sche[mn_id - 1] = a[mn_id];
//		}
//		cout << max(ans,fun(sche)) << '\n';
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 105;
//int n, m, mp[N][N], dis[N], vis[N], ans;
//void init() {
//	memset(mp, 0, sizeof mp);
//	memset(vis, 0, sizeof vis);
//	memset(dis, 0, sizeof dis);
//	ans = 0;
//}
//
//int prim() {
//	vis[1] = 1;
//	dis[1] = 0;
//	for (int i = 2; i <= n; i++) {
//		dis[i] = mp[1][i];
//	}
//	int cnt = 1;
//	while (cnt < n) {
//		int x = 0;
//		for (int i = 2; i <= n; i++) {
//			if (vis[i] || !dis[i]) continue;
//			if (x == 0 || dis[i] < dis[x])
//				x = i;
//		}
//		cnt++;
//		ans += dis[x];
//		dis[x] = 0;
//		vis[x] = 1;
//		for (int i = 2; i <= n; i++) {
//			if (vis[i] || !mp[x][i]) continue;
//			if (dis[i] == mp[x][i])
//				return 0;
//			if (dis[i] == 0 || mp[x][i] < dis[i])
//				dis[i] = mp[x][i];
//		}
//	}
//
//	return 1;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		init();
//		cin >> n >> m;
//		for (int i = 0,u,v,w; i < m; i++) {
//			cin >> u >> v >> w;
//			mp[u][v] = mp[v][u] = w;
//		}
//
//		if (prim())
//			cout << ans << '\n';
//		else
//			cout << "Not Unique!\n";
//
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 760;
//struct node {
//	int x, y;
//}city[N];
//int n, m, far[N], dis[N], dica[N][N], fa[N], vis[N];
//
//int find(int x) {
//	return far[x] == x ? x : far[x] = find(far[x]);
//}
//
//void merg(int a, int b) {
//	a = find(a);
//	b = find(b);
//	far[a] = b;
//}
//
//int mp(int u, int v) {
//	return dica[u][v] ? dica[u][v] : dica[u][v] = (city[u].x - city[v].x) * (city[u].x - city[v].x) + (city[u].y - city[v].y) * (city[u].y - city[v].y);
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> city[i].x >> city[i].y;
//		far[i] = i;
//	}
//	
//	cin >> m;
//	int cnt = 0;
//	for (int i = 0,u,v; i < m; i++) {
//		cin >> u >> v;
//		if (find(u) != find(v)) {
//			merg(u, v);
//		}
//		for (int i = 1, w; i <= n; i++) {
//			if (find(u) == find(i)) continue;
//			w = mp(u, i);
//			if (dis[i] == 0 || dis[i] > w)
//				dis[i] = w, fa[i] = u;
//		}
//		for (int i = 1, w; i <= n; i++) {
//			if (find(v) == find(i)) continue;
//			w = mp(v, i);
//			if (dis[i] == 0 || dis[i] > w)
//				dis[i] = w, fa[i] = v;
//		}
//	}
//
//	int n2 = 0, rt;
//	for (int i = 1; i <= n; i++) {
//		if (far[i] == i)
//			n2++, rt = i;
//	}
//
//	vis[rt] = 1;
//	for (int i = 1; i <= n; i++) {
//		if (vis[find(rt)]) continue;
//		int w = mp(rt, i);
//		if (dis[i] == 0 || dis[i] > w)
//			dis[i] = w;
//	}
//
//	while (cnt < n2) {
//		int x = 0;
//		for (int i = 1; i <= n; i++) {
//			if (vis[find(i)] || !dis[find(i)]) continue;
//			if (x == 0 || dis[find(i)] < dis[x])
//				x = find(i);
//		}
//		vis[find(x)] = 1;
//		cnt++;
//		cout << x << ' ' << fa[x] << '\n';
//		for (int i = 1; i <= n; i++) {
//			if (vis[find(i)]) continue;
//			int w = mp(find(x), i);
//			if (!dis[i] || dis[i] > w)
//				dis[i] = w, fa[i] = x;
//		}
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 760;
//struct node {
//	int x, y;
//}city[N];
//int n, m, far[N], dis[N], dica[N][N], fa[N], vis[N];
//
//int find(int x) {
//	return far[x] == x ? x : far[x] = find(far[x]);
//}
//
//void merg(int a, int b) {
//	a = find(a);
//	b = find(b);
//	far[a] = b;
//}
//
//int mp(int u, int v) {
//	return dica[u][v] ? dica[u][v] : dica[u][v] = dica[u][v] = (city[u].x - city[v].x) * (city[u].x - city[v].x) + (city[u].y - city[v].y) * (city[u].y - city[v].y);
//}
//
//void prim() {
//
//	int cnt = 1;
//	vis[1] = 1;
//	far[far[1]] = 1;
//	for (int i = 2; i <= n; i++) {
//		dis[i] = mp(1, i);
//		fa[i] = 1;
//	}
//
//	while (cnt < n) {
//		int x = 0;
//		for (int i = 2; i <= n; i++) {
//			if (vis[find(i)]) {
//				if (!vis[i])
//					cnt++;
//				continue;
//			}
//			if (!dis[i]) continue;
//			if (x == 0 || dis[i] < dis[x])
//				x = i;
//		}
//		vis[far[x]] = vis[x] = 1;
//		cnt++;
//		if (x != far[x]) cnt++;
//		cout << x << ' ' << fa[x] << '\n';
//
//	}
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> city[i].x >> city[i].y;
//		far[i] = i;
//	}
//
//	cin >> m;
//	int cnt = 0;
//	for (int i = 0, u, v; i < m; i++) {
//		cin >> u >> v;
//		if (find(u) != find(v)) {
//			merg(u, v);
//		}
//	}
//
//	prim();
//
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//char s[2] = { 'a', 'b'};
//
//int main()
//{
//	int a[2] = {0}, t, sa[2] = {0}, b;
//	cin >> a[0] >> a[1];
//	b = (a[0] + a[1]) / 2;
//	for (int i = 0; i < 3; i++) {
//		cin >> t;
//		if (t)
//			sa[1]++;
//		else
//			sa[0]++;
//	}
//	for (int i = 0; i < 2; i++) {
//		if (a[i] > b && sa[i] > 0) {
//			printf("The winner is %c: %d + %d", s[i], a[i], sa[i]);
//			return 0;
//		}
//		if (a[i] < b && sa[i] == 3) {
//			printf("The winner is %c: %d + %d", s[i], a[i], sa[i]);
//			return 0;
//		}
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//char s[110][110] = { 0 }, t, s2[110][110] = { 0 };
//int n;
//
//int main()
//{
//	cin >> t >> n;
//	for (int i = 1; i <= n; i++) {
//		getchar();
//		for (int j = 1; j <= n; j++) {
//			s[i][j] = getchar();
//			s2[n + 1 - i][n + 1 - j] = s[i][j];
//		}
//	}
//
//	int f = 1;
//	for (int i = 1; i <= n && f; i++)
//		for (int j = 1; j <= n && f; j++) {
//			if (s[i][j] != s2[i][j])
//				f = 0;
//		}
//
//	if (f)
//		cout << "bu yong dao le\n";
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (s2[i][j] != ' ')
//				cout << t;
//			else
//				cout << ' ';
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll l, n, sum = 1, num, cnt = 0;
//
//void fun(ll n2) {
//	if(++cnt < l)
//	fun(n2 / 26);
//	//cout << n2 % 26 << '\n';
//	printf("%c", 'a' + n2 % 26);
//}
//
//int main()
//{
//	cin >> l >> n;
//	int t = l;
//	while (t--)
//		sum *= 26;
//	num = sum - n;
//	fun(num);
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//int n, num[11];
//
//int main()
//{
//	cin >> n;
//	vector<int>sc(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> sc[i];
//		for (int j = 1; j <= sc[i]; j++)
//			num[j]++;
//	}
//	for (int i = 0; i < 11; i++)if (num[i] == 1) num[i] = 2;
//
//	for (int i = 1; i <= n; i++) {
//		cout << "#" << i << '\n';
//		int id = i;
//		for (int j = 1; j <= sc[i]; j++) {
//			for (int x = 1; x <= 10; x++) {
//				cout << id;
//				if (x < 10)
//					cout << ' ';
//				id += num[j];
//			}
//			if(i != n || j != sc[i])
//			cout << '\n';
//		}
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e4 + 5;
//int n;
//double sum = 0;
//struct node {
//	double num;
//	char name[10];
//}a[N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i].name >> a[i].num;
//		sum += a[i].num;
//	}
//	double av = (sum / n) / 2.0;
//	int mi = 0;
//	double mn = DBL_MAX;
//	for (int i = 1; i <= n; i++) {
//		if (abs(a[i].num - av) < mn) {
//			mn = abs(a[i].num - av);
//			mi = i;
//		}
//	}
//	cout << 
//	cout << (ll)a[mi].num << ' ' << a[mi].name;
//	return 0;
//




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e4 + 5;
//int n, m, k;
//pair<int, int>way[N];
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 0, u, v; i < m; i++) {
//		scanf("%d %d", &u, &v);
//		way[i] = { u,v };
//	}
//	scanf("%d", &k);
//	int np;
//	while (k--) {
//		scanf("%d", &np);
//
//	}
//	return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 5;
//int n, a[N], vis[N], rt, dep[N], hi = 0;
//vector<int>mn;
//vector<int>mp[N];
//
//void dfs(int fa) {
//	for (auto son : mp[fa]) {
//		dep[son] = dep[fa] + 1;
//		dfs(son);
//		hi = max(hi, dep[son]);
//	}
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] == -1)
//			rt = i;
//		else
//			mp[a[i]].push_back(i);
//	}
//
//	dep[rt] = 1;
//	dfs(rt);
//
//	if (hi == 0)
//		hi = 1;
//	cout << hi << '\n';
//
//
//	for (int i = 1; i <= n; i++) {
//		if (dep[i] == hi) {
//			mn.push_back(i);
//		}
//	}
//
//	int len = mn.size();
//	for (int i = 0; i < len; i++)
//	{
//		cout << mn[i];
//		if (i < len - 1)
//			cout << ' ';
//	}
//
//
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e4 + 5;
//vector<int>mp[N];
//int k, n, m, np;
//
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0, a, b; i < m; i++) {
//		cin >> a >> b;
//		mp[a].push_back(b);
//		mp[b].push_back(a);
//	}
//
//	cin >> k;
//	while (k--) {
//		cin >> np;
//		set<int>st;
//		int t;
//		while (np--) {
//			cin >> t;
//			st.insert(t);
//		}
//		for (int i = 1; i <= n; i++) {
//			if (st.find(i) != st.end()) continue;
//			int len = mp[i].size();
//			for (int j = 0; j < len; j++) {
//				if (st.find(mp[i][j]) != st.end()) continue;
//				cout << "NO\n";
//				goto ss;
//			}
//		}
//		cout << "YES\n";
//	ss:;
//	}
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e4 + 5;
//int k, n, g, sum = 0;
//struct node {
//	int gra, num;
//	string id;
//}stu[N];
//
//int cmp(node e1, node e2) {
//	if (e1.gra == e2.gra)
//		return e1.id < e2.id;
//	return e1.gra > e2.gra;
//}
//
//int main()
//{
//	cin >> n >> g >> k;
//	for (int i = 1; i <= n; i++) {
//		cin >> stu[i].id >> stu[i].gra;
//		if (stu[i].gra >= g)
//			sum += 50;
//		else if (stu[i].gra >= 60)
//			sum += 20;
//	}
//
//	sort(stu+1, stu +1+ n,cmp);
//
//	cout << sum << '\n';
//	for (int i = 1; i <= n; i++) {
//		if (stu[i].gra != stu[i - 1].gra)
//			stu[i].num = i;
//		else
//			stu[i].num = stu[i - 1].num;
//		if (stu[i].num > k)
//			break;
//		cout << stu[i].num << ' ' << stu[i].id << ' ' << stu[i].gra << '\n';
//	}
//
//
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e4 + 5;
//ll n;
//ll sum = 0;
//struct node {
//	ll num;
//	char name[10];
//}a[N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i].name >> a[i].num;
//		sum += a[i].num;
//		a[i].num *= n;
//	}
//	sum /= 2;
//	int mi = 0;
//	ll mn = LLONG_MAX;
//	for (int i = 1; i <= n; i++) {
//		if (abs(a[i].num - sum) < mn) {
//			mn = abs(a[i].num - sum);
//			mi = i;
//		}
//	}
//	cout << a[mi].num / n << ' ' << a[mi].name;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//int n, num[11];
//
//int main()
//{
//	cin >> n;
//	vector<int>sc(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> sc[i];
//		for (int j = 1; j <= sc[i]; j++)
//			num[j]++;
//	}
//	for (int i = 0; i < 11; i++)if (num[i] == 1) num[i] = 2;
//
//	for (int i = 1; i <= n; i++) {
//		cout << "#" << i << '\n';
//		int id = i;
//		for (int j = 1; j <= sc[i]; j++) {
//			for (int x = 1; x <= 10; x++) {
//				cout << id;
//				if (x < 10)
//					cout << ' ';
//				id += num[j];
//			}
//			if (i != n || j != sc[i])
//				cout << '\n';
//		}
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 760;
//int n, m, way[N][N], fa[N];
//pair<int, int>a[N];
//struct node{
//	int u, v, w;
//}edge[N*N];
//
//void init() {
//	memset(edge, 0x3f, sizeof edge);
//}
//
//int find(int x) {
//	return x == fa[x] ? x : fa[x] = find(fa[x]);
//}
//
//void merg(int a, int b) {
//	a = find(a);
//	b = find(b);
//	fa[a] = b;
//}
//
//int cmp(node e1, node e2) {
//	return e1.w < e2.w;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	init();
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i].first >> a[i].second;
//		fa[i] = i;
//	}
//
//	int cnt = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			edge[cnt].w = (a[i].second - a[j].second) * (a[i].second - a[j].second) + (a[i].first - a[j].first) * (a[i].first - a[j].first);
//			edge[cnt].u = i;
//			edge[cnt].v = j;
//			++cnt;
//		}
//	}
//	sort(edge + 1, edge + 1 + cnt, cmp);
//
//	cnt = 0;
//	cin >> m;
//	for (int i = 0,a,b; i < m; i++) {
//		cin >> a >> b;
//		if (find(a) != find(b)) {
//			++cnt;
//			merg(a, b);
//		}
//	}
//
//	for (int i = 1; cnt < n - 1 && i < (n * n) / 2; i++) {
//		int u = edge[i].u, v = edge[i].v;
//		if (find(u) != find(v)) {
//			cnt++;
//			merg(u, v);
//			cout << u << ' ' << v << '\n';
//		}
//	}
//
//
//
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 5;
//const ll mod = 1e9 + 7;
//int n, a[N], b[N], c[N], fa[N], vis[N];
//ll sum = 1;
//
//
//int find(int a) {
//	return a == fa[a] ? fa[a] : fa[a] = find(fa[a]);
//}
//
//void merg(int a, int b) {
//	a = find(a);
//	b = find(b);
//	if (a != b)
//		fa[a] = b;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		sum = 1;
//		cin >> n;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			fa[i] = i;
//			vis[i] = 0;
//		}
//		for (int i = 1; i <= n; i++) {
//			cin >> b[i];
//			merg(a[i], b[i]);
//		}
//		for (int i = 1; i <= n; i++) {
//			cin >> c[i];
//			if (c[i] || a[i] == b[i])
//				vis[find(a[i])] = 1;
//		}
//		for (int i = 1; i <= n; i++) {
//			if (fa[i] == i && !vis[i])
//				sum *= 2, sum %= mod;
//		}
//		cout << sum << '\n';
//	}
//
//	return 0;
//}



//
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 110;
//int n, sc[N], tea[12];
//
//void init() {
//	memset(tea, 0, sizeof tea);
//	memset(sc, 0, sizeof sc);
//}
//
//int main()
//{
//	int t;
//	t = 1;
//	while (t--) {
//		init();
//		cin >> n;
//		for (int i = 1; i <= n; i++) {
//			cin >> sc[i];
//			for (int j = 0; j <= sc[i]; j++)
//				tea[j]++;
//		}
//		for (int i = 0; i <= 10; i++)
//			if (tea[i] == 1)
//				tea[i] = 2;
//
//		for (int i = 1; i <= n; i++) {
//			cout << "#" << i << '\n';
//			int id = i;
//			for (int j = 1; j <= sc[i]; j++) {
//				for (int x = 1; x <= 10; x++) {
//					cout << id;
//					if (x != 10)
//						cout << ' ';
//					id += tea[j];
//				}
//				cout << '\n';
//			}
//		}
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 110;
//int n, sc[N];
//
//
//int main()
//{
//	cin >> n;
//	vector<vector<int>>vec[N];
//	for (int i = 1; i <= n; i++) {
//		cin >> sc[i];
//		vec[i].resize(sc[i]+2);
//		for (int j = 0; j <= sc[i]; j++)
//			vec[i][j].resize(12);
//
//	}
//	int id = 1;
//	for (int i = 1; i <= 10; i++) {//队
//		for (int j = 1; j <= 10; j++) {//位
//			for (int x = 1;x <= n; x++) {//校
//				if (sc[x] < i) continue;
//				if ((id - 1 == vec[x][i-1][10] || id - 1 == vec[x][i][j - 1]) && id != 1)
//					++id;
//				vec[x][i][j] = id++;
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++) {
//		cout << "#" << i << '\n';
//		for (int j = 1; j <= sc[i]; j++) {
//			for (int x = 1; x <= 10; x++) {
//				cout << vec[i][j][x];
//				if (x < 10)
//					cout << ' ';
//			}
//			cout << '\n';
//		}
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 110;
//int n, sc[N], tea[12];
//
//void init() {
//	memset(tea, 0, sizeof tea);
//	memset(sc, 0, sizeof sc);
//}
//
//int main()
//{
//	int t;
//	t = 1;
//	while (t--) {
//		init();
//		cin >> n;
//		for (int i = 1; i <= n; i++) {
//			cin >> sc[i];
//			for (int j = 0; j <= sc[i]; j++)
//				tea[j]++;
//		}
//		for (int i = 0; i <= 10; i++)
//			if (tea[i] == 1)
//				tea[i] = 2;
//
//		for (int i = 1; i <= n; i++) {
//			cout << "#" << i << '\n';
//			int id = i;
//			for (int j = 1; j <= sc[i]; j++) {
//				for (int x = 1; x <= 10; x++) {
//					cout << id;
//					if (x != 10)
//						cout << ' ';
//					id += tea[j];
//				}
//				cout << '\n';
//			}
//		}
//	}
//
//	return 0;
//}




#include<bits/stdc++.h>
using namespace std;

//int main() {
//
//	vector<int>vec;
//	map<int, int>mp;
//	for (auto a : mp) {
//		cout << a.second;
//	}
//	return 0;
//}

//int n, m, a, b;
//
//int cmp(pair<int, double>e1, pair<int, double> e2) {
//	if (abs(e1.second - e2.second) < 0.000001)
//		return abs(e1.first) < abs(e2.first);
//	return e1.second > e2.second;
//}
//
//int main()
//{
//	cin >> n >> m;
//	vector<vector<int>>pic(m+1);
//	for (int i = 1, k; i <= m; i++) {
//		cin >> k;
//		pic[i].resize(k);
//		string s;
//		getline(cin, s);
//		for (int j = 0, len = s.size(), p = 0; p < len; p++, j++) {
//			if (s[p] == ' ') ++p;
//			int f = 0;
//			if (s[p] == '-') {
//				f = 1;
//				++p;
//			}
//			if (s[p] == '0') {
//				pic[i][j] = n;
//				if (f)
//					pic[i][j] *= -1;
//				continue;
//			}
//			while (s[p] != ' ' && p < len) {
//				pic[i][j] *= 10;
//				pic[i][j] += s[p] - '0';
//				++p;
//			}
//			if (f)
//				pic[i][j] *= -1;
//
//		}
//	}
//
//	cin >> a >> b;
//	map<int, double>ma, mb;
//	for (int i = 1, f1, f2; i <= m; i++) {
//		f1 = 0;
//		f2 = 0;
//		for (int j = 0, len = pic[i].size(); j < len && (!f1 || !f2); j++) {
//			if (!f1 && pic[i][j] == a) f1 = 1;
//			else if (!f2 && pic[i][j] == b) f2 = 1;
//		}
//		if(f1)
//			for (auto& t : pic[i]) {
//				if (a * t < 0)
//					ma[t] += 1.0 / pic[i].size();
//			}
//		if (f2)
//			for (auto& t : pic[i]) {
//				if (b * t < 0)
//					mb[t] += 1.0 / pic[i].size();
//			}
//	}
//	vector<pair<int, double>>va, vb;
//	for (auto p : ma) {
//		va.push_back(p);
//	}
//	for (auto p : mb) {
//		vb.push_back(p);
//	}
//	sort(va.begin(), va.end(), cmp);
//	sort(vb.begin(), vb.end(), cmp);
//	double mxa = va.size()>0 ? va[0].second : 0, mxb = vb.size() > 0 ? vb[0].second : 0;
//	if (ma[b] >= mxa && mb[a] >= mxb) {
//		cout << a << ' ' << b;
//		return 0;
//	}
//	for (auto [x, y] : va) {
//		if (y < mxa)
//			break;
//		if (x == n)
//			x = 0;
//		cout << a << ' ';
//		if (a > 0)
//			cout << '-';
//		cout << abs(x) << '\n';
//	}
//	for (auto [x, y] : vb) {
//		if (y < mxb)
//			break;
//		if (x == n)
//			x = 0;
//		cout << b << ' ';
//		if (b > 0)
//			cout << '-';
//		cout << abs(x) << '\n';
//	}
//
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int n, m;


//int main()
//{
//	/*cin >> n >> m;
//	vector<vector<int>>pic(m);
//	for (int k, i = 0; i < m; i++) {
//		cin >> k;
//		pic[i].resize(k);
//		string s;
//		cin >> s;
//		for (int i = 0, len = s.size(); i < len; i++) {
//
//		}
//	}*/
//	printf("%.0f", 1.5);
//
//	return 0;
//}


//printf("%.0f + %.0f = %.0f\n%.0f - %.0f = %.0f\n", a, b, a + b, a, b, a - b);


//
//#include<bits/stdc++.h>
//using namespace std;
//const double perc = 1e-4;
//
//int main()
//{
//	double a, b, c;
//	cin >> a >> b >> c;
//	if (a + b<=c || a + c<=b || b + c<=a || abs(a - b)>=c || abs(a - c)>=b || abs(b - c)>=a)
//		cout << "Don`t make a triangle";
//	else if (abs(a - b) <= perc && abs(a - c) <= perc)
//		cout << "Equilateral truangle";
//	else if (abs(a - b) <= perc || abs(b - c) <= perc || abs(a - c) <= perc) {
//		if (a * a + b * b - c * c <= perc || a * a + c * c - b * b <= perc || b * b + c * c - a * a <= perc)
//			cout << "Isosceles Right triangle";
//		else
//			cout << "Isosceles triangle";
//	}
//	else if (abs(a * a + b * b - c * c) <= perc || abs(a * a + c * c - b * b) <= perc || abs(b * b + c * c - a * a) <= perc)
//		cout << "Right triangle";
//	else
//		cout << "General triangle";
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int a;
//    cin >> a;
//    switch (a / 10) {
//    case 10:
//    case 9:
//        cout << "A";
//        break;
//    case 8:
//        cout << "B";
//        break;
//    case 7:
//        cout << "C";
//        break;
//    case 6:
//        cout << "D";
//        break;
//    default:
//        cout << "E";
//        break;
//    }
//    return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int a, b, s;
//	cin >> a >> b;
//	s = 60 * (b/100 - a/100) + (b%100 - a%100);
//	cout << s / 60 << ':' << s % 60;
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1010;
//int n, m, a, b;
//vector<vector<int>>pic;
//
//struct node {
//	double val;
//	int id, f;
//}ma[N], mb[N];
//
//void print_pic() {
//	for (int i = 0; i < m; i++) {
//		cout << "|  ";
//		for (int j = 0; j < pic[i].size(); j++) {
//			cout << pic[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}
//
//int cmp(node e1, node e2) {
//	if (e1.val == e2.val)
//		return e1.id < e2.id;
//	return e1.val > e2.val;
//}
//
//int main()
//{
//	cin >> n >> m;
//	pic.resize(m);
//	for (int i = 0, k; i < m; i++) {
//		cin >> k;
//		pic[i].resize(k);
//		string s;
//		getline(cin, s);
//		for (int j = 0, p = 0, len = s.length();j < k && p < len;++j, p++) {
//			if (s[p] == ' ') ++p;
//			int f = 0;
//			if (s[p] == '-') f = 1, ++p;
//			while (p < len && s[p] != ' ') {
//				pic[i][j] *= 10;
//				pic[i][j] += (s[p] - '0');
//				++p;
//			}
//			if (pic[i][j] == 0)
//				pic[i][j] = n;
//			if (f)
//				pic[i][j] *= -1;
//		}
//	}
//	//print_pic();
//
//	string ab;
//	getline(cin, ab);
//	for (int i = 0, len = ab.length(), f = 0; i < len; i++) {
//		if (ab[i] != '-' && (ab[i] > '9' || ab[i] < '0')) continue;
//		int fh = 0;
//		if (ab[i] == '-') fh = 1, ++i;
//		while (i < len && ab[i] >= '0' && ab[i] <= '9') {
//			if (f) {
//				b *= 10;
//				b += ab[i] - '0';
//			}
//			else {
//				a *= 10;
//				a += ab[i] - '0';
//			}
//			++i;
//		}
//		if (!f && !a) a = n;
//		if (f && !b) b = n;
//		if (fh) {
//			if (f) b *= -1;
//			else a *= -1;
//		}
//		f = 1;
//	}
//	for (int i = 0; i < m; i++) {
//		int fa = 0, fb = 0;
//		for (int j = 0, len = pic[i].size();(!fa || !fb)&&j < len; j++) {
//			if (pic[i][j] == a)
//				fa = 1;
//			else if (pic[i][j] == b)
//				fb = 1;
//		}
//		for (int j = 0, len = pic[i].size(), t; (fa || fb) && j < len; j++) {
//			t = abs(pic[i][j]) == n ? 0 : abs(pic[i][j]);
//			if (fa && pic[i][j] * a < 0) {
//				ma[t].val += 1.0 / (double)len;
//				ma[t].id = t;
//				if (pic[i][j] < 0)
//					ma[t].f = 1;
//			}
//			else if (fb && pic[i][j] * b < 0) {
//				mb[t].val += 1.0 / (double)len;
//				mb[t].id = t;
//				if (pic[i][j] < 0)
//					mb[t].f = 1;
//			}
//		}
//	}
//	double aa = ma[abs(b)==n?0:abs(b)].val, bb = mb[abs(a) == n ? 0 : abs(a)].val;
//	sort(ma, ma + n, cmp);
//	sort(mb, mb + n, cmp);
//	if (aa >= ma[0].val && bb >= mb[0].val) {
//		if (a < 0) cout << '-';
//		if (abs(a) == n) a = 0;
//		cout << abs(a) << " ";
//		if (b < 0) cout << '-';
//		if (abs(b) == n) b = 0;
//		cout << abs(b);
//	}
//	else {
//		double mxa = ma[0].val;
//		for (int i = 0; i < n; i++) {
//			if (ma[i].val < mxa)
//				break;
//			if (a < 0) cout << '-';
//			if (abs(a) == n) a = 0;
//			cout << abs(a) << " ";
//			if (ma[i].f)
//				cout << '-';
//			cout << ma[i].id << '\n';
//		}
//		double mxb = mb[0].val;
//		for (int i = 0; i < n; i++) {
//			if (mb[i].val < mxb)
//				break;
//			if (b < 0) cout << '-';
//			if (abs(b) == n) b = 0;
//			cout << abs(b) << " ";
//			if (mb[i].f)
//				cout << '-';
//			cout << mb[i].id << '\n';
//		}
//	}
//
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//string s;
//int len;
//
//
//int main()
//{
//	cin.getline(s, 333);
//	len = s.lenght();
//	for (int x = 0; x < len; x++) {
//
//	}
//
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef unsigned long long ll;
//const int N = 1e6 + 5;
//int len;
//ll dp[N][4];
//
//
//int main()
//{
//	string s;
//	cin >> s;
//	len = s.length();
//	s = " " + s;
//	for (int i = 0; i <= len; i++) {
//		dp[i][0] = 1;
//		for (int j = 1;j <= 3 && j <= i; j++) {
//			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
//			for (int p = i-1; p >= i - j && p >= 1; p--) {
//				if (s[i] == s[p]) {
//					dp[i][j] -= dp[p - 1][j - (i - p)];
//					break;
//				}
//			}
//		}
//	}
//	cout << dp[len][3] + dp[len][2] + dp[len][1] + dp[len][0];
//
//	return 0;
//}

//#include<bits/stdc++.h> 
//using namespace std;
//const int N = 1e6 + 10;
//typedef long long ll;
//char s[N];
//ll f[N][4];
//int main()
//{
//	scanf("%s", s + 1);
//	int n = strlen(s + 1);
//	for (int i = 0; i <= n; i++)// j=0的情况初始好，避免下面j-1越界
//		f[i][0] = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= 3; j++)
//		{
//			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
//			for (int k = i - 1; k >= 1 && k >= i - j; k--)
//			{
//				if (s[k] == s[i])
//				{
//					f[i][j] -= f[k - 1][j - i + k];
//					break;
//				}
//			}
//		}
//	}
//	printf("%lld\n", f[n][0] + f[n][1] + f[n][2] + f[n][3]);
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//
//int main()
//{
//	double a, b;
//	atan(a);
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 5005;
//struct node {
//	ll x, y;
//}a[N], b[N];
//int n;
//
//int cmp(node e1, node e2) {
//	return abs(e1.y * e2.x) < abs(e1.x * e2.y);
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> a[i].x >> a[i].y;
//	ll ans = 1e18;
//	for (int i = 0; i < n; i++) {
//		int x = 0;
//		for (int j = 0; j < n; j++) {
//			if (j == i) continue;
//			b[x].x = a[j].x - a[i].x;
//			b[x].y = a[j].y - a[i].y;
//			++x;
//		}
//		sort(b, b + x, cmp);
//		for (int j = 0; j < x - 1; j++) {
//			ans = min(ans, abs(b[j].x * b[j + 1].y - b[j].y *b[j + 1].x));
//		}
//	}
//	printf("%.3lf",ans/2.0);
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//const int N = 5005;
//int n;
//struct T
//{
//    ll x, y;
//} p[N], c[N];
//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> p[i].x >> p[i].y;
//    }
//    ll ans = 1e18;
//    for (int i = 0; i < n; i++)
//    {
//        int k = 0;
//        for (int j = 0; j < n; j++)
//            if (i != j)
//                c[k].x = p[j].x - p[i].x, c[k++].y = p[j].y - p[i].y;
//        //			b[x].x = a[j].x - a[i].x;
////			        b[x].y = a[j].y - a[i].x;
//        sort(c, c + k,
//            [](T a, T b)
//            {
//                return abs(b.y * a.x) > abs(b.x * a.y);
//            });
//
//        for (int j = 1; j < k; j++)
//        {
//            ans = min(ans, abs(c[j].y * c[j - 1].x - c[j].x * c[j - 1].y));
//        }
//
//    }
//    printf("%.3f\n", ans / 2.);
//    return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	map<char, int>mp;
//	mp['L'] = 3;
//	mp['M'] = 2;
//	mp['S'] = 1;
//	while (t--) {
//		string a, b;
//		cin >> a >> b;
//		if (a == b)
//			cout << "=\n";
//		else {
//			int al = a.size(), bl = b.size();
//			if (a[al - 1] == b[bl - 1]) {
//				if(a[al-1] == 'L')
//					cout << (al > bl ? '>' : '<') << '\n';
//				else
//					cout << (al < bl ? '>' : '<') << '\n';
//			}
//			else {
//				cout << (mp[a[al - 1]] > mp[b[bl - 1]] ? '>' : '<') << '\n';
//			}
//		}
//	}
//
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n;
//
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		if (n % 2 == 0) {
//			for (int i = n / 2 + 1; i <= n; i++)
//				cout << i << ' ';
//			for (int i = 1; i < n / 2 + 1; i++)
//				cout << i << ' ';
//		}
//		else if (n == 3)
//			cout << "-1";
//		else {
//			for (int i = 3; i <= n; i++)
//				cout << i << ' ';
//			for (int i = 1; i <= 2; i++) 
//				cout << i << ' ';
//		}
//		cout << '\n';
//	}
//
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int M = 3e5 + 5;
//int m, p[M];
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> m;
//		int f = 1;
//		for (int i = 1, last; i <= m; i++) {
//			cin >> p[i];
//			if (i % 2 == 0 && abs(last - p[i]) != 1)
//				f = 0;
//			last = p[i];
//		}
//		int cnt = 0;
//		if (!f)
//			cout << "-1\n";
//		else {
//			for (int x = 1; x < m; x *= 2) {
//				for (int i = 1; i <= m; i += 2 * x) {
//					if (p[i] > p[i + x]) {
//						for (int j = i; j <= i + x - 1; j++) {
//							swap(p[j], p[j + x]);
//						}
//						cnt++;
//					}
//				}
//			}
//
//			f = 1;
//			for (int i = 1; i < m && f; i++) {
//				if (p[i] > p[i + 1])
//					f = 0;
//			}
//			if (f)
//				cout << cnt << '\n';
//			else
//				cout << "-1\n";
//		}
//	}
//
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, a[N], di[N];
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			di[i] = 0;
//			//di[i] = a[i] - a[i - 1];
//		}
//		for (int i = 1; i <= n; i++) {
//			if (a[i] < i)
//				++di[i - a[i]], --di[i+1];
//			if (a[i] + i <= n)
//				++di[i], --di[i + a[i] + 1];
//		}
//		int f = 1;
//		for (int i = 1, sum = 0;f && i <= n; i++) {
//			sum += di[i];
//			if (sum == 0)
//				f = 0;
//		}
//		if (f)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int x, a[4];
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		for (int i = 0; i < 4; i++)a[i] = 0;
//		cin >> x >> a[1] >> a[2] >> a[3];
//		while (x) {
//			int t = x;
//			x = a[x];
//			a[t] = 0;
//		}
//		int f = 1;
//		for (int i = 1; i < 4; i++)
//			if (a[i])
//				f = 0;
//		if (f)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//
//	return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//ll n, m, a[N], s, e, d1[N], d2[N], s1[N], s2[N];
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	/*for (int i = n; i > 1; i--) {
//		if (a[i] > a[i - 1]) {
//			d2[i] = a[i] - a[i - 1];
//		}
//	}
//	for (int i = 1; i < n; i++) {
//		if (a[i] > a[i + 1]) {
//			d1[i] = a[i] - a[i + 1];
//		}
//		s1[i] += s1[i-1]+d1[i];
//		s2[i] += s2[i-1]+d2[i];
//	}
//	s1[n] += s1[n - 1]+d1[n];
//	s2[n] += s2[n - 1]+d2[n];*/
//
//
//	for (int i = 1; i < n; i++) {
//		if (a[i] > a[i + 1]) {
//			d1[i] = a[i] - a[i + 1];
//		}
//	}
//
//	for (int i = n; i > 1; i--) {
//		if (a[i] > a[i - 1]) {
//			d2[i] = a[i] - a[i - 1];
//		}
//	}
//
//	for (int i = 1; i <= n; i++) {
//		s1[i] += s1[i - 1] + d1[i];
//	}
//
//	for (int i = n; i > 1; i--) {
//		s2[i] += s2[i + 1] + d2[i];
//	}
//	while (m--) {
//		cin >> s >> e;
//		if (s < e)
//			cout << s1[e-1] - s1[s-1] << '\n';
//		else
//			cout << s2[e+1] - s2[s+1] << '\n';
//	}
//
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2010;
//ll n, a[N], sum = 0;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		sum = 0;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//			cin >> a[i], sum += a[i];
//		ll ans = n;
//
//		for (ll i = n; i >= 1;i--) {
//			if (sum % i) continue;
//			ll s = sum / i;
//			ll len = 0;
//			ll st = 0;
//			for (ll i = 1, tl = 0; i <= n; i++) {
//				st += a[i];
//				tl++;
//				if (st == s) {
//					len = max(len, tl);
//					tl = st = 0;
//				}
//				else if (st > s) {
//					len = n;
//					break;
//				}
//			}
//			ans = min(ans, len);
//		}
//		cout << ans << '\n';
//	}
//
//
//	return 0;
//}



//
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5;
//int len, sum, lk, rk, we, ls, rs, ppr[N], ppl[N];
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		string s;
//		cin >> s;
//		sum = len = s.length();
//		s = " " + s;
//		for (int i = 1; i <= len; i++) {
//			if (s[i] == '(')
//				++lk;
//			else if (s[i] == ')')
//				++rk;
//			else
//				++we;
//		}
//		ls = (sum / 2) - lk;
//		rs = (sum / 2) - rk;
//
//		if (!ls || !rs) {
//			cout << "YES\n";
//			continue;
//		}
//
//		for (int i = len; i > 1; i--) {
//			ppr[i] = ppr[i + 1];
//			if (s[i] == ')')
//				++ppr[i];
//		}
//		for (int i = 1; i <= len; i++) {
//			ppl[i] = ppl[i - 1];
//			if (s[i] == '(')
//				++ppl[i];
//		}
//
//		int f = 1;
//		int divr = 0, divl = 0;
//		for (int i = 1; i <= len; i++) {
//			if (s[i] != '?') continue;
//			int nl = ppl[i] - divl, nr = ppr[i] - divr;
//			/*if ((ppr[i]-divr == ppl[i] - divl) || (ppr[i]-divr && ppl[i]-divl)) {
//				f = 0;
//				break;
//			}*/
//			if ((!nl && nr) || (!nr && nl)) {
//				if (nr)
//					divr++;
//				else
//					divl++;
//			}
//			else {
//				f = 0;
//				break;
//			}
//
//
//		}
//
//		if (f)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, a[N];
//bool dp[N];
//
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		memset(dp, 0, sizeof dp);
//		dp[0] = true;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			if (a[i] == i - 1 || (i-a[i]-1 >= 0 && dp[i-a[i]-1]))
//				dp[i] = true;
//			if (i + a[i] <= n && dp[i - 1])
//				dp[i + a[i]] = true;
//		}
//		if (dp[n])
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5;
//int len, sum, ls, rs;
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		string s;
//		cin >> s;
//		sum = len = s.length();
//		ls = rs = sum / 2;
//		s = " " + s;
//		for (int i = 1; i <= len; i++) {
//			if (s[i] == '(')
//				--ls;
//			else if (s[i] == ')')
//				--rs;
//		}
//
//		if (!ls || !rs) {
//			cout << "YES\n";
//			continue;
//		}
//
//		int f = 1;
//		for (int i = 1, t = 0; i <= len; i++) {
//			if (s[i] == '(')
//				++t;
//			else if (s[i] == ')')
//				--t;
//			else if (s[i] == '?') {
//				if (t) {
//					if (ls > 0) {
//						f = 0;
//						break;
//					}
//					else {
//						f = 1;
//						break;
//					}
//				}
//				else {
//					++t;
//					--ls;
//				}
//			}
//		}
//
//		if (f)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//
//	return 0;
//}





#include<bits/stdc++.h>
using namespace std;
int len, ls, rs;


int main()
{
	int t;
	cin >> t;
	while (t--) {
		string s;
		vector<int>pos;
		cin >> s;
		len = s.length();
		ls = rs = len / 2;
		for (int i = 0; i < len; i++) {
			if (s[i] == '(')
				ls--;
			else if (s[i] == ')')
				rs--;
			else
				pos.push_back(i);
		}

		if (!ls || !rs) {
			cout << "YES\n";
			continue;
		}

		for (int i = 0, siz = pos.size(); i < siz; i++) {
			if (i < ls)
				s[pos[i]] = '(';
			else
				s[pos[i]] = ')';
		}

		auto check = [](const string& s) {
			int t = 0;
			for (char c : s) {
				if (c == '(') ++t;
				if (c == ')') --t;
				if (t < 0) return true;
			}
			return false;
		};

		swap(s[pos[ls - 1]], s[pos[ls]]);
		if (check(s))
			cout << "YES\n";
		else
			cout << "NO\n";

	}

	return 0;
}