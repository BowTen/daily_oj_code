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