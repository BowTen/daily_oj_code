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