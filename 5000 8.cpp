#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#define BowTen ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e6 + 5;
//int n, q;
//ll t[N];
//
//int lowbit(int x) {
//	return x & -x;
//}
//
//void add(int i, ll val) {
//	while (i <= n) {
//		t[i] += val;
//		i += lowbit(i);
//	}
//}
//
//ll getsum(int i) {
//	ll ret = 0;
//	while (i >= 1) {
//		ret += t[i];
//		i -= lowbit(i);
//	}
//	return ret;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//
//	cin >> n >> q;
//	for (int i = 1, a[2] = { 0 }; i <= n; i++) {
//		cin >> a[i & 1];
//		add(i, a[i&1] - a[~i&1]);
//	}
//
//	int f, l, r, x;
//	while (q--) {
//		cin >> f >> l;
//		if (f == 1) {
//			cin >> r >> x;
//			add(l, x);
//			add(r + 1, -x);
//		}
//		else
//			cout << getsum(l) << '\n';
//	}
//
//	return 0;
//}



////#include<bits/stdc++.h>
////using namespace std;
////typedef long long ll;
////const int N = 1e6 + 5;
////int n, q;
////ll t1[N], t2[N];
////
////int lowbit(int x) {
////	return x & -x;
////}
////
////void add(int i, ll val) {
////	ll val2 = i * val;
////	while (i <= n) {
////		t1[i] += val;
////		t2[i] += val2;
////		i += lowbit(i);
////	}
////}
////
////ll getsum(int i) {
////	ll s1 = 0, s2 = 0, r = i + 1;
////	while (i >= 1) {
////		s1 += t1[i];
////		s2 += t2[i];
////		i -= lowbit(i);
////	}
////	return r * s1 - s2;
////}
////
////int main()
////{
////	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////
////	cin >> n >> q;
////	for (int i = 1, a[2] = { 0 }; i <= n; i++) {
////		cin >> a[i & 1];
////		add(i, a[i & 1] - a[~i & 1]);
////	}
////
////	int f, l, r, x;
////	while (q--) {
////		cin >> f >> l >> r;
////		if (f == 1) {
////			cin >> x;
////			add(l, x);
////			add(r + 1, -x);
////		}
////		else
////			cout << getsum(r) - getsum(l-1) << '\n';
////	}
////
////	return 0;
////}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		vector<int>vec;
//		map<int, int>mp;
//		int ans;
//		for (int i = 1, t; i <= n; i++) {
//			cin >> t;
//			vec.push_back(t);
//			mp[t]++;
//		}
//		for(int i = 0;i < n;i++)
//			if (mp[vec[i]] == 1)
//				ans = vec[i];
//		for(int i = 0;i < n;i++)
//			if (vec[i] == ans) {
//				cout << i + 1 << '\n';
//				break;
//			}
//
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n, x[3],y[3];
//char s[410][410];
//
//void init() {
//	memset(s, 0, sizeof s);
//	memset(x, 0, sizeof x);
//	memset(y, 0, sizeof y);
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		init();
//		cin >> n;
//		for (int i = 1, id = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++) {
//				cin >> s[i][j];
//				if (s[i][j] == '*') {
//					x[id] = i;
//					y[id] = j;
//					id = 2;
//				}
//			}
//
//		int a1 = x[1], a2 = x[2], b1 = y[1], b2 = y[2];
//		if (x[1] == x[2]) {
//			if (x[1] == 1) {
//				a1++;
//				a2++;
//			}
//			else {
//				a1--;
//				a2--;
//			}
//		}
//		else if (y[1] == y[2]) {
//			if (y[1] == 1) {
//				b1++;
//				b2++;
//			}
//			else {
//				b1--;
//				b2--;
//			}
//		}
//		else {
//			a1 = x[2];
//			b1 = y[1];
//			a2 = x[1];
//			b2 = y[2];
//		}
//		s[a1][b1] = s[a2][b2] = '*';
//
//		for (int i = 1, id = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++)
//				cout << s[i][j];
//			cout << '\n';
//		}
//
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, a, b;
//string s;
//
//void init() {
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> a >> b;
//		int s1 = b, s0 = a;
//		n = a + b;
//		cin >> s;
//		for (int i = 0; i < n; i++)
//			if (s[i] == '1')
//				s1--;
//			else if (s[i] == '0')
//				s0--;
//		s = " " + s;
//
//
//		for (int q = 1, p = n; q <= p; q++, p--) {
//			if ((s[q] != s[p] && s[q] != '?' && s[p] != '?') || (s1 < 0 || s0 < 0)) {
//				cout << "-1\n";
//				goto ss;
//			}
//
//			if (s[q] == s[p] && s[q] == '?') {
//				if (p == q) {
//					if (s1 > 0) {
//						s1--;
//						s[q] = '1';
//					}
//					else if (s0 > 0) {
//						s0--;
//						s[q] = '0';
//					}
//				}
//				else if (s1 >= 2) {
//					s1 -= 2;
//					s[q] = s[p] = '1';
//				}
//				else if (s0 >= 2) {
//					s0 -= 2;
//					s[q] = s[p] = '0';
//				}
//				else {
//					cout << "-1\n";
//					goto ss;
//				}
//
//				continue;
//			}
//
//			if (s[q] == '?') {
//				if (s[p] == '0') {
//					s[q] = '0';
//					s0--;
//				}
//				else {
//					s[q] = '1';
//					s1--;
//				}
//			}
//
//			if (s[p] == '?') {
//				if (s[q] == '0') {
//					s[p] = '0';
//					s0--;
//				}
//				else {
//					s[p] = '1';
//					s1--;
//				}
//			}
//		}
//		for (int i = 1; i <= n; i++)
//			cout << s[i];
//		cout << '\n';
//	ss:;
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, a, b;
//
//void init() {
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int>num(n+2);
//		for (int i = 0; i < n+2; i++)
//			cin >> num[i];
//
//		sort(num.begin(), num.end());
//		ll s = 0;
//		for (int i = 0; i < n; i++)
//			s += num[i];
//		if (s == num[n]) {
//			for (int i = 0; i < n; i++)
//				cout << num[i] << ' ';
//			cout << '\n';
//			continue;
//		}
//
//		s += num[n];
//		int flag = -1;
//		for(int i = 0;i <= n;i++)
//			if (s - num[i] == num[n + 1]) {
//				flag = i;
//				break;
//			}
//
//		if (flag == -1) {
//			cout << "-1\n";
//			continue;
//		}
//		for (int i = 0; i <= n; i++) {
//			if (i == flag) continue;
//			cout << num[i] << ' ';
//		}
//		cout << '\n';
//	}
//	return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n;
//
//void init() {
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		int f[4], f2[4], f3[4] = { 0 };
//		cin >> n;
//		for (int i = 0; i < 4; i++) {
//			cin >> f[i];
//			f2[i] = f[i];
//		}
//
//		for (int i = 0; i < 4; i++) {
//			if (f[i] == n) {
//				f3[i + 1 > 3 ? 0 : i + 1]++;
//				f3[i - 1 < 0 ? 3 : i - 1]++;
//			}
//		}
//		for (int i = 0; i < 4; i++) {
//			if (f[i] == n - 1) {
//				if(f3[(i + 1) % 4] < f[(i + 1) % 4])
//					f3[i + 1 > 3 ? 0 : i + 1]++;
//				else
//					f3[i - 1 < 0 ? 3 : i - 1]++;
//			}
//		}
//
//		for (int i = 0; i < 4; i++) {
//			if (f3[i] > f[i]) {
//				cout << "NO\n";
//				goto ss;
//			}
//		}
//		cout << "YES\n";
//	ss:;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n;
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		char a = 'A', b = 'B', c = 'C';
//		int vis[3] = { 0 };
//		map<char, int>ch;
//		map<char, char>fh;
//		map<char, int>num;
//		string s;
//		cin >> s;
//		n = s.length();
//		for (int i = 0; i < n; i++)
//			ch[s[i]]++;
//
//		if ((ch[a] != ch[b] + ch[c] && ch[b] != ch[a] + ch[c] && ch[c] != ch[a] + ch[b]) || s[0] == s[n - 1]) {
//			cout << "NO\n";
//			continue;
//		}
//		
//		fh[s[0]] = '(';
//		fh[s[n - 1]] = ')';
//		char les = ch[s[0]] < ch[s[n - 1]] ? '(' : ')';
//		vis[s[0] - 'A'] = 1;
//		vis[s[n - 1] - 'A'] = 1;
//		for (int i = 0; i < 3; i++)
//			if (!vis[i])
//				fh['A' + i] = les;
//
//		for (int i = 0; i < n; i++) {
//			num[fh[s[i]]]++;
//			if (num['('] < num[')']) {
//				cout << "NO\n";
//				goto ss;
//			}
//		}
//		cout << "YES\n";
//	ss:;
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, a, b;
//
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> a >> b;
//		n = a + b;
//		string s;
//		cin >> s;
//		for (int i = 0; i < n; i++)
//			if (s[i] == '0')
//				a--;
//			else if (s[i] == '1')
//				b--;
//
//		for (int q = 0, p = n - 1; q <= p; q++, p--) {
//			if (s[q] == '?' && s[p] != '?') {
//				if (s[p] == '0')
//					a--;
//				else
//					b--;
//				s[q] = s[p];
//				continue;
//			}
//
//			if (s[q] != '?' && s[p] == '?') {
//				if (s[q] == '0')
//					a--;
//				else
//					b--;
//				s[p] = s[q];
//			}
//		}
//
//		for (int q = 0, p = n - 1; q <= p; q++, p--) {
//			if (p == q && s[p] == '?') {
//				if (a > 0) {
//					a--;
//					s[p] = '0';
//				}
//				else {
//					b--;
//					s[p] = '1';
//				}
//			}
//			else if (s[q] == s[p] && s[p] == '?') {
//				if (a >= 2) {
//					a -= 2;
//					s[p] = s[q] = '0';
//				}
//				else {
//					b -= 2;
//					s[p] = s[q] = '1';
//				}
//			}
//		}
//		int ans = 1;
//		for (int q = 0, p = n - 1; q <= p && ans; q++, p--) {
//			if (s[q] != s[p])
//				ans = 0;
//		}
//
//		if (ans && a == 0 && b == 0)
//			cout << s << '\n';
//		else
//			cout << "-1\n";
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, a, b;
//
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		unordered_map<char, int>num;
//		unordered_map<char, char>kh;
//		unordered_map<char, int>word;
//		string s;
//		cin >> s;
//		n = s.length();
//		for (int i = 0; i < n; i++)
//			word[s[i]]++;
//
//
//		kh[s[0]] = '(';
//		kh[s[n - 1]] = ')';
//		char les = word[s[0]] < word[s[n - 1]] ? kh[s[0]] : kh[s[n - 1]];
//		for(int i = 0;i < 3;i++)
//			if ('A' + i != s[0] && 'A' + i != s[n - 1]) {
//				kh['A' + i] = les;
//			}
//
//		if (s[0] == s[n - 1]) {
//			cout << "NO\n";
//			goto ss;
//		}
//
//		for (int i = 0; i < n; i++) {
//			num[kh[s[i]]]++;
//			if (num['('] < num[')']) {
//				cout << "NO\n";
//				goto ss;
//			}
//		}
//
//		if (num['('] != num[')'])
//			cout << "NO\n";
//		else
//			cout << "YES\n";
//	ss:;
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, l, r, s, sm, no;
//int sum[500];
//
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	for (int i = 1; i <= 500; i++)
//		sum[i] = sum[i - 1] + i;
//	while (t--) {
//		cin >> n >> l >> r >> s;
//		vector<int>vis(n+1);
//		sm = r - l + 1;
//		for (int i = 1; i <= sm; i++)
//			vis[i] = 1;
//		no = sum[sm];
//		
//		if (no > s) {
//			cout << "-1\n";
//			continue;
//		}
//
//		for (int i = 1; i <= sm; i++) {
//			for (int j = n; j > i; j--) {
//				if (vis[j]) continue;
//				if (no + j - i <= s) {
//					no += j - i;
//					vis[i] = 0;
//					vis[j] = 1;
//					break;
//				}
//			}
//		}
//
//		if (no == s) {
//			int cnt = 1, p = 1;
//			for (p; p <= n; p++)
//				if (!vis[p]) {
//					if (cnt >= l)
//						break;
//					cout << p << ' ';
//					cnt++;
//				}
//			for (int i = 1; i <= n; i++)
//				if (vis[i]) cout << i << ' ';
//			for (p; p <= n; p++)
//				if (!vis[p]) cout << p << ' ';
//			cout << '\n';
//		}
//		else
//			cout << "-1\n";
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//ll n, c, a[N], b[N];
//ll da[N], mo[N], fas[N];
//
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%lld %lld", &n, &c);
//		for (int i = 1; i <= n; i++)
//			scanf("%lld", &a[i]);
//		for (int i = 1; i < n; i++)
//			scanf("%lld", b + i);
//		ll pos = 1, cur = 1, fund = 0;
//		da[1] = mo[1] = 0;
//		fas[pos] = ((c - mo[pos]) / a[pos]) + ((c - mo[pos]) % a[pos] == 0 ? 0 : 1) + da[pos];
//		ll ans = fas[1];
//		for (cur; pos < n; cur++) {
//			if (fund >= b[pos]) {
//				fund -= b[pos];
//				pos++;
//				da[pos] = cur;
//				mo[pos] = fund;
//				fas[pos] = ((c - mo[pos]) / a[pos]) + ((c - mo[pos]) % a[pos] == 0 ? 0 : 1) + da[pos];
//				ans = ans < fas[pos] ? ans : fas[pos];
//			}
//			else {
//				ll t = (b[pos] - fund) / a[pos] + ((b[pos] - fund) % a[pos] == 0 ? 0 : 1);
//				fund += t * a[pos];
//				cur += t - 1;
//			}
//		}
//		printf("%lld\n", ans);
//
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e7 + 5;
//ll c, b[N], ans[N];
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	for (int i = 1; i < N; i++)
//		for (int j = i; j < N; j += i)
//			b[j] += i;
//
//	for (int i = 1; i < N; i++)
//		if (b[i] < N && !ans[b[i]])
//			ans[b[i]] = i;
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> c;
//		if (ans[c])
//			cout << ans[c] << '\n';
//		else
//			cout << "-1\n";
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n, m, c, t;
//
//int main()
//{
//	cin >> n >> m;
//	map<int, pair<int ,int > >mp; 
//	for (int i = 1; i <= n; i++) {
//		cin >> c >> t;
//		if (t > mp[c].second) {
//			mp[c] = { i,t };
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		cout << mp[i].first << ' ';
//	}
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e3 + 5;
//typedef long long ll;
//struct bug {
//	ll x, y, h, id;
//};
//vector<bug>b;
//ll n, ans[N], x, y, atk, h, r, sb, f;
//
//
//void die(int x) {
//	ans[b[x].id] = 1;
//	b.erase(b.begin() + x);
//	sb--;
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> f >> x >> y;
//		if (f == 1) {
//			cin >> h;
//			b.push_back({ x,y,h,i });
//			sb++;
//		}
//		else {
//			cin >> atk >> r;
//			if (!sb)
//				continue;
//			ll m = -1, mn = 0;
//			for (int j = 0, si = b.size(); j < si;j++) {
//				ll dis = (b[j].x - x) * (b[j].x - x) + (b[j].y - y) * (b[j].y - y);
//				if (dis < mn || m == -1) {
//					mn = dis;
//					m = j;
//				}
//			}
//
//			x = b[m].x;
//			y = b[m].y;
//			bool flag = 0;
//			for (int j = 0, si = b.size(); j < si; j++) {
//				ll dis = (b[j].x - x) * (b[j].x - x) + (b[j].y - y) * (b[j].y - y);
//				if (dis <= r*r) {
//					b[j].h -= 3 * atk;
//					if (b[j].h <= 0)
//						die(j), j--, si--;
//					else
//						flag = 1;
//				}
//			}
//			if (flag) {
//				ans[i] = 1;
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//		if (ans[i])
//			cout << "NO\n";
//		else
//			cout << "YES\n";
//	return 0;
//}

//5
//2 1 0 1 1
//2 1 0 1 1
//2 1 0 1 1
//1 0 0 4
//1 0 1 8




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e3 + 5;
//ll n,x,y,h,ak,f,r,ans[N];
//struct bug {
//	ll x, y, h, id;
//};
//vector<bug>b;
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> f >> x >> y;
//		if (f == 1) {
//			cin >> h;
//			b.push_back({ x,y,h,i });
//		}
//		else {
//			cin >> ak >> r;
//			if (!b.size())
//				continue;
//
//			ll m = -1, mn = 0;
//			for (int j = 0, si = b.size(); j < si; j++) {
//				ll dis = (b[j].x - x) * (b[j].x - x) + (b[j].y - y) * (b[j].y - y);
//				if (dis < mn || m == -1)
//					mn = dis, m = j;
//			}
//
//			x = b[m].x;
//			y = b[m].y;
//
//			int flag = 0;
//			for (int j = 0, si = b.size(); j < si; j++) {
//				ll dis = (b[j].x - x) * (b[j].x - x) + (b[j].y - y) * (b[j].y - y);
//				if (dis <= r * r) {
//					b[j].h -= ak * 3;
//					if (b[j].h <= 0) {
//						ans[b[j].id] = 1;
//						b.erase(b.begin() + j);
//						j--;
//						si--;
//					}
//					else
//						flag = 1;
//				}
//			}
//			if (flag)
//				ans[i] = 1;
//		}
//	}
//	for (int i = 1; i <= n; i++)
//		if (ans[i])
//			cout << "NO\n";
//		else
//			cout << "YES\n";
//
//	return 0;
//}

//5
//2 1 0 1 1
//2 1 0 1 1
//1 0 0 3
//2 1 0 1 1
//1 0 1 8



//#include<bits/stdc++.h>
//using namespace std;
//#define endl '\n'
//#define Acode ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//typedef long long ll;
//const int inf = 0x3f3f3f3f;
//const int N = 1e6 + 20;
//ll n, m;
//ll p[N], d[N];
//ll dp[N];
//int main()
//{
//	scanf("%lld %lld", &n, &m);
//	for (int i = 1; i <= n; ++i)
//		scanf("%lld", p+i);
//	for (int i = 1; i <= n; ++i)
//		scanf("%lld", d + i);
//	for (int i = 1; i <= n; i++)
//		for (int j = 0; j <= m; j++)
//			dp[j] = max(dp[j*d[i]]+j*d[i]*p[i], dp[j]);
//	printf("%lld\n", dp[m]);
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//typedef long long ll;
//ll n, k, s = 1, a[N], b[N], w[N], sub[N << 1], pre[N << 1], len, val[N<<1];
//struct node {
//	ll val, id, f;
//};
//
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> k;
//	vector<node>num(n << 1);
//	for (int i = 1,j = 0; i <= n; i++) {
//		cin >> a[i] >> b[i] >> w[i];
//		num[j++] = { a[i],i,1 };
//		num[j++] = { b[i],i,2 };
//	}
//	sort(num.begin(), num.end(), [](node e1, node e2)->int {return e1.val < e2.val; });
//	ll s = 1;
//	for (int i = 0, si = num.size(); i < si; i++) {
//		if (i < si - 1 && num[i].val == num[i + 1].val)
//			num[i].val = s;
//		else
//			num[i].val = s++;
//		if (num[i].f == 1) a[num[i].id] = num[i].val;
//		else b[num[i].id] = num[i].val;
//	}
//	len = s;
//	for (int i = 1; i <= n; i++) {
//		sub[a[i]]++;
//		sub[b[i] + 1]--;
//		for (int j = a[i]; j <= b[i]; j++)
//			val[j] ^= w[i];
//	}
//	for (int i = 1; i <= len; i++) {
//		sub[i] += sub[i-1];
//	}
//	int ans = -1;
//	for (int i = 1; i <= len; i++) {
//		if (sub[i] >= k && (ans == -1 || val[i] > ans))
//			ans = val[i];
//	}
//
//	cout << ans;
//
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//int a,b;
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> a >> b;
//		if (abs(a) == abs(b))
//			cout << max(abs(a), abs(b))*2 << '\n';
//		else
//			cout << max(abs(a), abs(b))*2 - 1 << '\n';
//	}
//
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//typedef long long ll;
//ll n, k, s = 1, a[N], b[N], w[N], sub[N << 1], pre[N << 1], len, val[N << 1];
//struct node {
//	ll val, id, f;
//};
//
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> k;
//	vector<node>num(n << 1);
//	for (int i = 1, j = 0; i <= n; i++) {
//		cin >> a[i] >> b[i] >> w[i];
//		num[j++] = { a[i],i,1 };
//		num[j++] = { b[i],i,2 };
//	}
//	sort(num.begin(), num.end(), [](node e1, node e2)->int {return e1.val < e2.val; });
//	ll s = 1;
//	for (int i = 0, si = num.size(); i < si; i++) {
//		if (i < si - 1 && num[i].val == num[i + 1].val)
//			num[i].val = s;
//		else
//			num[i].val = s++;
//		if (num[i].f == 1) val[num[i].val] ^= w[num[i].id], sub[num[i].val]++;
//		else val[num[i].val + 1] ^= w[num[i].id], sub[num[i].val + 1]--;
//	}
//	len = s;
//	for (int i = 1; i <= len; i++) {
//		sub[i] += sub[i - 1];
//		val[i] ^= val[i - 1];
//	}
//	int ans = -1;
//	for (int i = 1; i <= len; i++) {
//		if (sub[i] >= k && (ans == -1 || val[i] > ans))
//			ans = val[i];
//	}
//
//	cout << ans;
//
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//typedef long long ll;
//ll n, k, s = 1, a[N], b[N], w[N], sub[N << 1], len, val[N << 1];
//vector<ll>num;
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i] >> b[i] >> w[i];
//		num.push_back(a[i]);
//		num.push_back(b[i]+1);
//	}
//	sort(num.begin(), num.end());
//	num.erase(unique(num.begin(), num.end()), num.end());
//	for (int i = 1; i <= n; i++) {
//		ll ai = lower_bound(num.begin(), num.end(), a[i]) - num.begin() + 1;
//		ll bi = lower_bound(num.begin(), num.end(), b[i]+1) - num.begin() + 1;
//		sub[ai]++;
//		sub[bi]--;
//		val[ai] ^= w[i];
//		val[bi] ^= w[i];
//	}
//	len = num.size();
//	ll s = 0, v = 0, ans = -1;
//	for (int i = 1; i <= len; i++) {
//		sub[i] += sub[i-1];
//		val[i] ^= val[i-1];
//		if (sub[i] >= k && (val[i] > ans || ans == -1))
//			ans = val[i];
//	}
//	cout << ans;
//	
//	return 0;
//}


//2 2
//1 1 8
//1 1 4




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 5;
//int T[N], n, q;
//
//int lowbit(int x) {
//	return x & -x;
//}
//
//void add(int i, int val) {
//	while (i <= n) {
//		T[i] += val;
//		i += lowbit(i);
//	}
//}
//
//ll getsum(int i) {
//	ll ret = 0;
//	while (i >= 1) {
//		ret += T[i];
//		i -= lowbit(i);
//	}
//	return ret;
//}
//
//void init() {
//	memset(T, 0, sizeof T);
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	for (int i = 1; i <= t;i++) {
//		cout << "Case " << i << ":\n";
//		init();
//		cin >> n >> q;
//		for (int j = 1, val; j <= n; j++) {
//			cin >> val;
//			add(j, val);
//		}
//		int f, a, b;
//		while (q--) {
//			cin >> f;
//			if (f == 1) {
//				cin >> a;
//				a++;
//				ll sum = getsum(a) - getsum(a - 1);
//				add(a, -sum);
//				cout << sum << '\n';
//			}
//			else if (f == 2) {
//				cin >> a >> b;
//				a++;
//				add(a, b);
//			}
//			else {
//				cin >> a >> b;
//				a++;
//				b++;
//				cout << getsum(b) - getsum(a - 1) << '\n';
//			}
//		}
//		//for (int j = 1; j <= n; j++)
//		//	cout << getsum(j) << " ";
//	}
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//struct node {
//	ll sum;
//	int l, r;
//};
//const int N = 1e5 + 5;
//int n, q, a[N];
//node T[N << 2];
//
//void up(int id) {
//	T[id].sum = T[id << 1].sum + T[id << 1 | 1].sum;
//}
//
//void build(int id, int ql, int qr) {
//	T[id].l = ql;
//	T[id].r = qr;
//	if (ql == qr) {
//		T[id].sum = a[ql];
//		return;
//	}
//	int mid = (ql + qr) >> 1;
//	build(id << 1, ql, mid);
//	build(id << 1 | 1, mid + 1, qr);
//	up(id);
//}
//
//void change(int id, int x, int val) {
//	int l = T[id].l;
//	int r = T[id].r;
//	if (l == r) {
//		T[id].sum += val;
//		return;
//	}
//	int mid = (l+r) >> 1;
//	if (x <= mid)
//		change(id << 1, x, val);
//	else
//		change(id << 1 | 1, x, val);
//	up(id);
//}
//
//ll query(int id, int ql, int qr) {
//	int l = T[id].l;
//	int r = T[id].r;
//	if (ql <= l && qr >= r)
//		return T[id].sum;
//	int mid = (l + r) >> 1;
//	if (qr <= mid)
//		return query(id << 1, ql, qr);
//	else if (ql > mid)
//		return query(id << 1 | 1, ql, qr);
//	else
//		return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
//}
//
//void init() {
//	memset(T, 0, sizeof T);
//	memset(a, 0, sizeof a);
//}
//
//int main()
//{
//	int t, cnt = 1;;
//	cin >> t;
//	while (t--) {
//		init();
//		cout << "Case " << cnt++ << ":\n";
//		cin >> n >> q;
//		for (int i = 0; i < n; i++)
//			cin >> a[i];
//		build(1, 0, n - 1);
//
//		int f, t1, t2;
//		while (q--) {
//			cin >> f;
//			if (f == 1) {
//				cin >> t1;
//				ll sm = query(1, t1, t1);
//				cout << sm << "\n";
//				change(1, t1, -sm);
//			}
//			else if(f == 2) {
//				cin >> t1 >> t2;
//				change(1, t1, t2);
//			}
//			else {
//				cin >> t1 >> t2;
//				cout << query(1, t1, t2) << '\n';
//			}
//		}
//	}
//
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 5e4 + 5;
//int n, q, a[N];
//struct node {
//	int max, l, r;
//};
//node seg[N << 2];
//
//void up(int id) {
//	seg[id].max = max(seg[id << 1].max, seg[id << 1 | 1].max);
//}
//
//void build(int id, int ql, int  qr) {
//	seg[id].l = ql;
//	seg[id].r = qr;
//	if (ql == qr) {
//		seg[id].max = a[ql];
//		return;
//	}
//	int mid = (ql + qr) >> 1;
//	build(id << 1, ql, mid);
//	build(id << 1 | 1, mid + 1, qr);
//	up(id);
//}
//
//void change(int id, int x, int val) {
//	int l = seg[id].l;
//	int r = seg[id].r;
//	if (l == r) {
//		seg[id].max = val;
//		return;
//	}
//	int mid = (l + r) >> 1;
//	if (x <= mid)
//		change(id << 1, x, val);
//	else if (x > mid)
//		change(id << 1 | 1, x, val);
//	up(id);
//}
//
//int getmax(int id, int ql, int qr) {
//	int l = seg[id].l;
//	int r = seg[id].r;
//	if (ql <= l && qr >= r)
//		return seg[id].max;
//	int mid = (l + r) >> 1;
//	if (qr <= mid)
//		return getmax(id << 1, ql, qr);
//	else if (ql > mid)
//		return getmax(id << 1 | 1, ql, qr);
//	else
//		return max(getmax(id << 1, ql, qr), getmax(id << 1 | 1, ql, qr));
//}
//
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	build(1, 1, n);
//
//	int f, x, y;
//	cin >> q;
//	while (q--) {
//		cin >> f >> x >> y;
//		if (f) {
//			cout << getmax(1, x, y) << '\n';
//		}
//		else {
//			change(1, x, y);
//		}
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//typedef long long ll;
//ll n, q, a[N];
//ll getans(ll x) {
//	return x * (x + 1) / 2;
//}
//struct node {
//	ll l, r, ans, fi, la, pre, end, isa;
//	node operator+(const node& e2) {
//		node ret;
//		ret.l = l;
//		ret.r = e2.r;
//		ret.isa = 0;
//		ret.fi = fi;
//		ret.la = e2.la;
//		ret.pre = pre;
//		ret.end = e2.end;
//		ret.ans = ans + e2.ans;
//		if (la <= e2.fi) {
//			ret.ans -= getans(end) + getans(e2.pre);
//			ret.ans += getans(end + e2.pre);
//			if (isa && e2.isa) {
//				ret.isa = 1;
//				ret.pre = ret.end = pre + e2.pre;
//			}
//			else if (isa) {
//				ret.pre = pre + e2.pre;
//			}
//			else if (e2.isa) {
//				ret.end = e2.end + end;
//			}
//		}
//		return ret;
//	}
//};
//node t[N << 2];
//
//
//
//void up(ll id) {
//	t[id] = t[id << 1] + t[id << 1 | 1];
//}
//
//void build(ll id, ll ql, ll qr) {
//	t[id].l = ql;
//	t[id].r = qr;
//	if (ql == qr) {
//		t[id].fi = t[id].la = a[ql];
//		t[id].ans = t[id].pre = t[id].end = t[id].isa = 1;
//		return;
//	}
//	int mid = (ql + qr) >> 1;
//	build(id << 1, ql, mid);
//	build(id << 1 | 1, mid + 1, qr);
//	up(id);
//}
//
//void change(ll id, ll x, ll val) {
//	ll l = t[id].l;
//	ll r = t[id].r;
//	if (l == r) {
//		t[id].la = val;
//		t[id].fi = val;
//		return;
//	}
//	ll mid = (l + r) >> 1;
//	if (x <= mid)
//		change(id << 1, x, val);
//	else if(x > mid)
//		change(id << 1 | 1, x, val);
//	up(id);
//}
//
//node query(ll id, ll ql, ll qr) {
//	ll l = t[id].l;
//	ll r = t[id].r;
//	if (ql <= l && r <= qr)
//		return t[id];
//	ll mid = l + r >> 1;
//	if (qr <= mid)
//		return query(id << 1, ql, qr);
//	else if (ql > mid)
//		return query(id << 1 | 1, ql, qr);
//	else
//		return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> q;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	build(1, 1, n);
//
//
//	ll f, x, y;
//	while (q--) {
//		cin >> f >> x >> y;
//		if (f == 1) {
//			change(1, x, y);
//		}
//		else {
//			cout << query(1, x, y).ans << "\n";
//		}
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 5;
//struct node {
//	ll l, r, lazy, sum, son;
//};
//node t[N << 2];
//ll n, q, a[N], sta[N];
//
//void up(int id) {
//	t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
//	t[id].son = t[id << 1].son + t[id << 1 | 1].son;
//}
//
//void settag(int id, ll val) {
//	t[id].sum += t[id].son * val;
//	t[id].lazy += val;
//}
//
//void down(int id) {
//	settag(id << 1, t[id].lazy);
//	settag(id << 1 | 1, t[id].lazy);
//	t[id].lazy = 0;
//}
//
//void build(int id, int ql, int qr) {
//	t[id].l = ql;
//	t[id].r = qr;
//	if (ql == qr) {
//		t[id].sum = a[ql];
//		t[id].son = sta[ql];
//		return;
//	}
//	int mid = ql + qr >> 1;
//	build(id << 1, ql, mid);
//	build(id << 1 | 1, mid + 1, qr);
//	up(id);
//}
//
//void changesta(int id, int x, ll s) {
//	int l = t[id].l;
//	int r = t[id].r;
//	if (l == r) {
//		t[id].son = s;
//		return;
//	}
//	down(id);
//	int mid = r + l >> 1;
//	if (x <= mid)
//		changesta(id << 1, x, s);
//	else
//		changesta(id << 1 | 1, x, s);
//	up(id);
//}
//
//void modify(int id, int ql, int qr, ll val) {
//	ll l = t[id].l;
//	ll r = t[id].r;
//	if (ql <= l && qr >= r) {
//		settag(id, val);
//		return;
//	}
//	down(id);
//	int mid = l + r >> 1;
//	if (qr <= mid)
//		modify(id << 1, ql, qr, val);
//	else if (ql > mid)
//		modify(id << 1 | 1, ql, qr, val);
//	else {
//		modify(id << 1, ql, qr, val);
//		modify(id << 1 | 1, ql, qr, val);
//	}
//	up(id);
//}
//
//ll query(int id, int ql, int qr) {
//	int l = t[id].l;
//	int r = t[id].r;
//	if (ql <= l && qr >= r)
//		return t[id].sum;
//	down(id);
//	int mid = l + r >> 1;
//	if (qr <= mid)
//		return query(id << 1, ql, qr);
//	else if (ql > mid)
//		return query(id << 1 | 1, ql, qr);
//	else
//		return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> q;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	for (int i = 1; i <= n; i++)
//		cin >> sta[i];
//
//	build(1, 1, n);
//
//	ll f, l, r, x;
//	while (q--) {
//		cin >> f;
//		if (f == 1) {
//			cin >> x;
//			changesta(1, x, 0);
//		}
//		else if (f == 2) {
//			cin >> x;
//			changesta(1, x, 1);
//		}
//		else if (f == 3) {
//			cin >> l >> r >> x;
//			modify(1, l, r, x);
//		}
//		else {
//			cin >> l >> r;
//			cout << query(1, l, r) << '\n';
//		}
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define BowTen ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define mp make_pair
//typedef long long ll;
//typedef pair<int, int> hashv;
//const int mod1 = 1e9 + 7;
//const int mod2 = 1e9 + 9;
//const int N = 4e5 + 5;
//hashv pw[N], h[N];
//hashv base = mp(131, 29);
//string s;
//
//
//hashv operator+ (hashv a, hashv b) {
//	return mp((a.first + b.first) % mod1, (a.second + b.second) % mod2);
//}
//hashv operator- (hashv a, hashv b) {
//	return mp((a.first - b.first) < 0 ? (a.first - b.first) + mod1 : (a.first - b.first), \
//		     (a.second - b.second) < 0 ? (a.second - b.second)+mod2 : (a.second - b.second));
//}
//hashv operator* (hashv a, hashv b) {
//	return mp((1ll * a.first * b.first) % mod1, (1ll * a.second * b.second) % mod2);
//}
//hashv getsub(int l, int r) {
//	return h[r] - h[l - 1] * pw[r - l + 1];
//}
//void init() {
//	memset(pw, 0, sizeof pw);
//	memset(h, 0, sizeof h);
//	pw[0] = mp(1, 1);
//}
//
//int main()
//{
//	BowTen;
//	while (cin >> s) {
//		init();
//		int n = s.length();
//		s = ' ' + s;
//		for (int i = 1; i <= n; i++) {
//			pw[i] = pw[i - 1] * base;
//			h[i] = h[i - 1] * base + mp(s[i], s[i]);
//		}
//		for (int i = 1; i <= n; i++) {
//			if (h[i] == getsub(n-i+1,n))
//				cout << i << ' ';
//		}
//		cout << '\n';
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//
//
//int main()
//{
//
//	int t;
//	cin >> t;
//	while (t--) {
//		cout << 22;
//	}
//	return 0;
//}



//#include<iostream>
//using namespace std;
//#define BowTen ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define mp make_pair
//typedef long long ll;
//typedef pair<int, int> hashv;
//const int N = 5e4 + 5;
//const int mod1 = 1e9 + 9;
//const int mod2 = 1e9 + 7;
//hashv pw[N], h[N], base = mp(33,131);
//string s;
//
//hashv operator+(hashv a, hashv b) {
//	return mp((a.first + b.first) % mod1, (a.second + b.second) % mod2);
//}
//hashv operator-(hashv a, hashv b) {
//	return mp((a.first - b.first) < 0 ? (a.first - b.first) + mod1 : (a.first - b.first), \
//		(a.second - b.second) < 0 ? (a.second - b.second) + mod2 : (a.second - b.second));
//}
//hashv operator*(hashv a, hashv b) {
//	return mp((1ll * a.first * b.first) % mod1, (1ll * a.second * b.second) % mod2);
//}
//hashv getsub(int l, int r) {
//	return h[r] - h[l - 1] * pw[r - l + 1];
//}
//void init() {
//	memset(pw, 0, sizeof pw);
//	memset(h, 0, sizeof h);
//	pw[0] = mp(1, 1);
//}
//
//
//int main() {
//	BowTen;
//	while (cin >> s) {
//		init();
//		int n = s.length();
//		s = ' ' + s;
//		for (int i = 1; i <= n; i++) {
//			pw[i] = pw[i-1] * base;
//			h[i] = h[i - 1] *base + mp(s[i], s[i]);
//		}
//		for (int i = 1; i <= n; i++)
//			if (h[i] == getsub(n - i + 1, n))
//				cout << i << ' ';
//		cout << '\n';
//	}
//
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//string s;
//
//
//int main()
//{
//	while (cin >> s) {
//		int n = s.length();
//		s = ' ' + s;
//		vector<int>ne(n+1);
//		for (int i = 2, j = 0; i <= n; i++) {
//			while (j && s[j + 1] != s[i]) j = ne[j];
//			if (s[j + 1] == s[i]) j++;
//			ne[i] = j;
//		}
//		sort(ne.begin(), ne.end());
//		cout << ne[0] << ' ';
//		for (int i = 1; i <= n; i++) {
//			if (ne[i] == ne[i - 1]) continue;
//			cout << ne[i] << ' ';
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef unsigned long long ull;
//const int N = 4e5 + 5;
//const int mod = 1e9 + 9;
//string s;
//ull h[N], pw[N], base = 131;
//
//ull getson(int l, int r) {
//	return h[r] - h[l - 1] * pw[r - l + 1];
//}
//
//
//int main()
//{
//	pw[0] = 1;
//	while (cin >> s) {
//		int n = s.length();
//		s = ' ' + s;
//		for (int i = 1; i <= n; i++) {
//			pw[i] = (pw[i - 1] * base);
//			h[i] = (h[i - 1] * base + s[i]);
//		}
//		for (int i = 1; i <= n; i++) {
//			if (h[i] == getson(n - i + 1, n))
//				cout << i << ' ';
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef unsigned long long ull;
//const int N = 1e6 + 5;
//const int mod = 1e9 + 9;
//string s1, s2;
//ull h1, h2[N], pw[N], base = 131;
//
//ull getson(int l, int r) {
//	return h2[r] - h2[l - 1] * pw[r - l + 1];
//}
//
//void init() {
//	h1 = 0;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	pw[0] = 1;
//	while (t--) {
//		init();
//		cin >> s1 >> s2;
//		int n1 = s1.length();
//		int n2 = s2.length();
//		s1 = ' ' + s1;
//		s2 = ' ' + s2;
//		for (int i = 1; i <= n1; i++)
//			h1 = h1 * base + s1[i];
//		for (int i = 1; i <= n2; i++) {
//			pw[i] = pw[i - 1] * base;
//			h2[i] = h2[i - 1] * base + s2[i];
//		}
//		int ans = 0;
//		for (int i = n1;i <= n2; i++) {
//			if (h1 == getson(i - n1 + 1, i))
//				ans++;
//		}
//		cout << ans << '\n';
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define mp make_pair
//typedef pair<int, int> hashv;
//typedef unsigned long long ull;
//const int N = 1e6 + 5;
//const int mod1 = 1e9 + 9, mod2 = 1e9+7;
//string s1, s2;
//hashv h1, h2[N], pw[N], base = mp(33, 131);
//
//hashv operator+(const hashv a, const hashv b) {
//	return mp((a.first + b.first) % mod1, (a.second + b.second) % mod2);
//}
//hashv operator-(const hashv a, const hashv b) {
//	return mp((a.first - b.first) < 0 ? (a.first - b.first) + mod1 : (a.first - b.first),\
//		  (a.second - b.second) < 0 ? (a.second - b.second) + mod2 : (a.second - b.second));
//}
//hashv operator*(const hashv a, const hashv b) {
//	return mp((1ull * a.first * b.first) % mod1, (1ull * a.second * b.second) % mod2);
//}
//hashv getson(int l, int r) {
//	return h2[r] - h2[l - 1] * pw[r - l + 1];
//}
//
//void init() {
//	h1 = mp(0, 0);
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	pw[0] = mp(1, 1);
//	while (t--) {
//		init();
//		cin >> s1 >> s2;
//		int n1 = s1.length();
//		int n2 = s2.length();
//		s1 = ' ' + s1;
//		s2 = ' ' + s2;
//		for (int i = 1; i <= n1; i++)
//			h1 = h1 * base + mp(s1[i], s1[i]);
//		for (int i = 1; i <= n2; i++) {
//			pw[i] = pw[i - 1] * base;
//			h2[i] = h2[i - 1] * base + mp(s2[i], s2[i]);
//		}
//		int ans = 0;
//		for (int i = n1; i <= n2; i++) {
//			if (h1 == getson(i - n1 + 1, i))
//				ans++;
//		}
//		cout << ans << '\n';
//	}
//
//	return 0;
//}



//#include<iostream>
//using namespace std;
//typedef unsigned long long ull;
//const int N = 1e6 + 5, N2 = 1e4 + 5;;
//string s1, s2;
//int ne[N2];
//
//void init() {
//	memset(ne, 0, sizeof ne);
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		init();
//		cin >> s1 >> s2;
//		int n1 = s1.length();
//		int n2 = s2.length();
//		s1 = ' ' + s1;
//		s2 = ' ' + s2;
//		for (int i = 2, j = 0; i <= n1; i++) {
//			while (j && s1[j + 1] != s1[i]) j = ne[j];
//			if (s1[j + 1] == s1[i]) j++;
//			ne[i] = j;
//		}
//		int ans = 0;
//		for (int i = 1, j = 0; i <= n2; i++) {
//			while (j && s1[j + 1] != s2[i]) j = ne[j];
//			if (s1[j + 1] == s2[i]) j++;
//			if (j == n1) {
//				ans++;
//				j = ne[j];
//			}
//		}
//		cout << ans << '\n';
//	}
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//typedef unsigned long long ull;
//const int N = 1e6 + 5, N2 = 1e4 + 5;;
//string s1, s2;
//int ne[N2];
//
//void init() {
//	memset(ne, 0, sizeof ne);
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//string s1, s2;
//int ne[N], n, m;
//
//int main() {
//
//	cin >> s1 >> s2;
//	n = s1.length();
//	m = s2.length();
//	s1 = ' ' + s1;
//	s2 = ' ' + s2;
//	for (int i = 2, j = 0; i <= m; i++) {
//		while (j && s2[j + 1] != s2[i]) j = ne[j];
//		if (s2[j + 1] == s2[i]) j++;
//		ne[i] = j;
//	}
//	for (int i = 1, j = 0; i <= n; i++) {
//		while (j && s1[i] != s2[j + 1]) j = ne[j];
//		if (s2[j + 1] == s1[i]) j++;
//		if (j == m) {
//			cout << i - m + 1 << '\n';
//			j = ne[j];
//		}
//	}
//	for (int i = 1; i <= m; i++)
//		cout << ne[i] << ' ';
//
// 	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//int a[110], n ,d ;
//
//int main() {
//
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> d;
//		for (int i = 0; i < n; i++)
//			cin >> a[i];
//		sort(a, a + n);
//		if (a[0] + a[1] <= d || a[n-1] <= d)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//string s1, s2;
//
//int main() {
//
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> s1 >> s2;
//		int n1 = s1.length(), n2 = s2.length();
//		if (gcd(n1,n2) <= 1) {
//			for (int i = 0; i < n1; i++)
//				if (s1[i] != s2[0]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			for (int i = 0; i < n2; i++)
//				if (s2[i] != s2[0]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			for (int i = 0; i < n1 * n2; i++)
//				cout << s1[0];
//			cout << '\n';
//		}
//		else {
//			int f = 1;
//			for (int i = 0, j = 0; i <= n1, j <= n2; i++, j++) {
//				if (i == n1)
//					if (f)
//						i = f = 0;
//					else
//						break;
//				if (j == n2)
//					if (f)
//						j = f = 0;
//					else
//						break;
//				if (s1[i] != s2[j]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			}
//			int cnt = ((n1 * n2) / gcd(n1, n2))/max(n1,n2);
//			for (int i = 0; i < cnt; i++)
//				cout << (n1 > n2 ? s1 : s2);
//			cout << '\n';
//		}
//
//	ss:;
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//int a, b, c;
//
//int main() {
//
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		b = (n + 3) / 3;
//		if ((n + 3) % 3)
//			b++;
//		a = (n - b) / 2;
//			a++;
//		c = n-a-b;
//		cout << a << ' ' << b << ' ' << c << '\n';
//	}
//
//	return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5e4 + 5;
//int a[N], b[N];
//
//int main() {
//
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		int m1 = 0, m2 = 0, mx;
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//			m1 = max(m1, a[i]);
//		}
//		for (int i = 0; i < n; i++) {
//			cin >> b[i];
//			m2 = max(m2, b[i]);
//		}
//		int ans = 1;
//		mx = m1 - m2;
//		for (int i = 0; i < n; i++) {
//			a[i] -= min(mx, a[i]);
//			if (a[i] != b[i])
//				ans = 0;
//		}
//		if (ans && mx >= 0)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//string s1, s2;
//
//int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> s1 >> s2;
//		int n1 = s1.length(), n2 = s2.length();
//		if (gcd(n1, n2) <= 1) {
//			for (int i = 0; i < n1; i++)
//				if (s1[i] != s2[0]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			for (int i = 0; i < n2; i++)
//				if (s2[i] != s2[0]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			for (int i = 0; i < n1 * n2; i++)
//				cout << s1[0];
//			cout << '\n';
//		}
//		else {
//			int mx = max(n1, n2);
//			for (int i = 0; i < mx; i++) {
//				if (s1[i % n1] != s2[i % n2]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			}
//			int cnt = ((n1 * n2) / gcd(n1, n2)) / max(n1, n2);
//			for (int i = 0; i < cnt; i++)
//				cout << (n1 > n2 ? s1 : s2);
//			cout << '\n';
//		}
//
//	ss:;
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, a[N], b[N], ans[N], st[N], ed[N];
//
//int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		/*int cur = 0, fini = 0, tim;
//		queue<pair<int,int> >task;
//		for (int i = 0, tmp; i < n; i++) {
//			cin >> tmp;
//			task.push({tmp,i});
//		}
//		for (int i = 0; i < n; i++)
//			cin >> ed[i];
//
//		while (!task.empty()) {
//			while ((!cur && task.front().first >= fini) {
//				cur = task.front().second
//			}
//		}*/
//
//		for (int i = 1; i <= n; i++)
//			cin >> a[i];
//		for (int i = 1; i <= n; i++)
//			cin >> ed[i];
//		int cur = 1, tim = a[1];
//		st[1] = a[1];
//		while (cur <= n) {
//			ans[cur] = ed[cur] - st[cur];
//			tim = max(ed[cur], a[cur + 1]);
//			st[++cur] = tim;
//		}
//		for (int i = 1; i <= n; i++)
//			cout << ans[i] << ' ';
//		cout << '\n';
//	}
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, k;
//
//int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		string s;
//		cin >> n >> k >> s;
//		int ans = k;
//		int p = 0, q = 0, w = 0;
//		for (p = 0; p <= k - 1; p++) {
//			if (s[p] == 'W')
//				w++;
//		}
//		ans = min(ans, w);
//		for (p = k,q = 1; p < n; p++, q++) {
//			if (s[q - 1] == 'W')
//				w--;
//			if (s[p] == 'W')
//				w++;
//			ans = min(ans, w);
//		}
//		cout << ans << '\n';
//	}
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, k;
//
//int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		ll sum = 0;
//		for (ll i = 0, t = 0; i < n; i++) {
//			cin >> t;
//			sum += t;
//		}
//		cout << sum / k << '\n';
//	}
//
//	return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, k;
//
//int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		int f = 2 * k - n;
//		for (int i = 1; i < f; i++)
//			cout << i << ' ';
//		for (int i = k; i >= f; i--)
//			cout << i << ' ';
//		cout << '\n';
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, k;
//
//int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		vector<int>a(n);
//		ll sum = 0;
//		for (int i = 0, tmp; i < n; i++) {
//			cin >> tmp;
//			sum += tmp / k;
//			a[i] = tmp % k;
//		}
//		sort(a.begin(), a.end());
//		for (int q = 0, p = n - 1; p > q; p--, q++) {
//			while (a[q] + a[p] < k && q < p) q++;
//			if (q >= p)
//				break;
//			sum++;
//		}
//		cout << sum << '\n';
//	}
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, m;
//string s;
//struct val {
//	int l = 0, r = 0, x = 0;
//	const val operator+(const val& e) {
//		val ret;
//		ret.l = min(l, e.l + x);
//		ret.r = max(r, e.r + x);
//		ret.x = x + e.x;
//		return ret;
//	}
//};
//struct node {
//	int l, r;
//	val v;
//
//};
//node seg[N << 2];
//
//void up(int id) {
//	seg[id].v = seg[id << 1].v + seg[id << 1 | 1].v;
//}
//
//void build(int id, int ql, int qr) {
//	seg[id].l = ql;
//	seg[id].r = qr;
//	if (ql == qr) {
//		seg[id].v.l = seg[id].v.r = 0;
//		if (s[ql] == '-')
//			seg[id].v.l = seg[id].v.x = -1;
//		else
//			seg[id].v.r = seg[id].v.x = 1;
//		return;
//	}
//	int mid = ql + qr >> 1;
//	build(id << 1, ql, mid);
//	build(id << 1 | 1, mid + 1, qr);
//	up(id);
//}
//
//val query(int id, int ql, int qr) {
//	if (ql > qr)
//		return {0,0,0};
//	int l = seg[id].l;
//	int r = seg[id].r;
//	if (ql <= l && qr >= r)
//		return seg[id].v;
//	int mid = l + r >> 1;
//	if (qr <= mid)
//		return query(id << 1, ql, qr);
//	else if (ql > mid)
//		return query(id << 1 | 1, ql, qr);
//	else
//		return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
//}
//
//int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m >> s;
//		s = ' ' + s;
//		build(1, 1, n);
//		int l, r;
//		while (m--) {
//			cin >> l >> r;
//			val ans = (query(1, 1, l-1) + query(1, r+1, n));
//			cout << ans.r - ans.l + 1 << '\n';
//		}
//	}
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef unsigned long long ll;
//const int N = 210;
//int n, a[N];
//string s;
//
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> s;
//		vector<bool>vis(n + 1);
//		vector<vector<char>>ss(1);
//		for (int i = 1; i <= n; i++)
//			cin >> a[i];
//		int siz = 1;
//		for (int cnt = 0, p = 1; cnt < n;) {
//			if (!vis[p]) {
//				vis[p] = true;
//				ss[siz-1].push_back(s[a[p]-1]);
//				p = a[p];
//				cnt++;
//			}
//			else {
//				ss.resize(++siz);
//				while (vis[++p]);
//			}
//		}
//		vector<ll>ans(siz);
//		for (int x = 0, si; x < siz; x++) {
//			si = ss[x].size();
//			vector<int>ne(si+1);
//			for (int i = 2, j = 0; i <= si; i++) {
//				while (j && ss[x][j] != ss[x][i - 1]) j = ne[j];
//				if (ss[x][j] == ss[x][i - 1]) j++;
//				ne[i] = j;
//			}
//			if (si % (si - ne[si]) == 0)
//				ans[x] = si - ne[si];
//			else
//				ans[x] = si;
//		}
//		for (int i = 1; i < siz; i++) {
//			ans[i] = (ans[i] * ans[i - 1]) / gcd(ans[i], ans[i - 1]);
//		}
//		cout << ans[siz - 1] << '\n';
//	}
//
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef unsigned long long ll;
//const int N = 1e5+5;
//int n, m, a[N], k, d;
//
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		map<int, int>head;
//		int cur = INT_MAX;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			if (a[i] < cur)
//				head[i] = a[i], cur = a[i];
//		}
//		while (m--) {
//			cin >> k >> d;
//			if (head.find(k) != head.end()) {
//				head[k] -= d;
//				vector<int>delet;
//				for (auto p = ++head.find(k), ed = head.end(); p != ed; p++) {
//					if (p->second >= head[k]) {
//						delet.push_back(p->first);
//					}
//				}
//				for (auto p : delet)
//					head.erase(p);
//			}
//			else {
//				a[k] -= d;
//				head[k] = a[k];
//				if ((--head.find(k))->second <= a[k]) {
//					head.erase(k);
//					cout << head.size() << ' ';
//					continue;
//				}
//				vector<int>delet;
//				for (auto p = ++head.find(k), ed = head.end(); p != ed; p++) {
//					if (p->second >= head[k]) {
//						delet.push_back(p->first);
//					}
//				}
//				for (auto p : delet)
//					head.erase(p);
//			}
//		cout << head.size() << ' ';
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//typedef unsigned long long ll;
//const int N = 1e5 + 5;
//int n, m, a[N], k, d;
//
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		map<int, int>head;
//		int last = INT_MAX;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			head[i] = a[i];
//			auto p = head.find(i);
//			if (p != head.begin() && prev(p)->second <= head[i])
//				head.erase(p);
//			else while (next(p) != head.end() && next(p)->second >= head[i])
//				head.erase(next(p));
//		}
//		while (m--) {
//			cin >> k >> d;
//			a[k] -= d;
//			head[k] = a[k];
//			auto p = head.find(k);
//			if (p != head.begin() && prev(p)->second <= head[k])
//				head.erase(p);
//			else while (next(p) != head.end() && next(p)->second >= head[k])
//				head.erase(next(p));
//			cout << head.size() << ' ';
//		}
//		cout << '\n';
//
//	}
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef unsigned long long ll;
//const int N = 1e5 + 5;
//int n, m, a[N], k, d;
//
//bool isPrime(int n) {
//	for (int i = 2; i < n; i++)
//		if (n % i == 0)
//			return false;
//	return true;
//}
//
//template<typename t1, typename t2>
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	while (cin >> n) {
//		cout << isPrime(n) << '\n';
//	}
//
//	return 0;
//}



//
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, dep[N], par[N][20], mn[N][20], mx[N][20], q;
//vector<vector<pair<int,int>>>mp;
//
//void dfs(int u, int fa, int val) {
//	dep[u] = dep[fa] + 1;
//	par[u][0] = fa;
//	mn[u][0] = val;
//	mx[u][0] = val;
//	for (int i = 1; i < 20; i++) {
//		par[u][i] = par[par[u][i - 1]][i - 1];
//		mn[u][i] = min(mn[u][i - 1], mn[par[u][i - 1]][i - 1]);
//		mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
//	}
//	for (auto& [v, w] : mp[u]) if (v != fa) {
//		dfs(v, u, w);
//	}
//}
//
//pair<int, int> query(int u, int v) {
//	if (dep[u] < dep[v]) swap(u, v);
//	int r1 = mn[u][0], r2 = mx[u][0];
//	for (int i = 19; i >= 0; i--) if (dep[par[u][i]] >= dep[v]) {
//		r1 = min(r1, mn[u][i]);
//		r2 = max(r2, mx[u][i]);
//		u = par[u][i];
//	}
//	if (u == v)
//		return make_pair(r1, r2);
//	for (int i = 19; i >= 0; i--) if (par[u][i] != par[v][i]) {
//		r1 = min({ r1, mn[u][i], mn[v][i] });
//		r2 = max({ r2, mx[u][i], mx[v][i] });
//		u = par[u][i];
//		v = par[v][i];
//	}
//	r1 = min({ r1, mn[u][0], mn[v][0] });
//	r2 = max({ r2, mx[u][0], mx[v][0] });
//	return make_pair(r1, r2);
//}
//
//void init() {
//	mp.clear();
//	mp.resize(n+1);
//	memset(dep, 0, sizeof dep);
//	memset(par, 0, sizeof par);
//	memset(mn, 0, sizeof mn);
//	memset(mx, 0, sizeof mx);
//}
//
//int main()
//{
//	int  t;
//	cin >> t;
//	for (int x = 1; x <= t;x++) {
//		cout << "Case " << x << ":\n";
//		cin >> n;
//		init();
//		
//		for (int i = 1, u, v, w; i < n; i++) {
//			cin >> u >> v >> w;
//			mp[u].push_back({ v,w });
//			mp[v].push_back({ u,w });
//		}
//		dfs(1, 0, 0);
//
//		cin >> q;
//		int q1, q2;
//		while (q--) {
//			cin >> q1 >> q2;
//			pair<int, int>ans = query(q1, q2);
//			cout << ans.first << ' ' << ans.second << '\n';
//		}
//	}
//
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 5e4 + 5;
//int n, k, a[N], dep[N], par[N][20], ans;
//vector<int>mp[N];
//
//void dfs(int u, int fa) {
//	for (auto& v : mp[u]) if (v != fa)
//		dfs(v, u);
//	a[fa] += a[u];
//	ans = max(ans, a[u]);
//}
//
//void pre_dfs(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	par[u][0] = fa;
//	for (int i = 1; i < 20; i++)
//		par[u][i] = par[par[u][i - 1]][i - 1];
//	for (auto& v : mp[u]) if (v != fa)
//		pre_dfs(v, u);
//}
//
//int getlca(int u, int v) {
//	if (dep[u] < dep[v]) swap(u, v);
//	for (int i = 19; i >= 0; i--) if (dep[par[u][i]] >= dep[v])
//		u = par[u][i];
//	if (u == v)
//		return u;
//	for (int i = 19; i >= 0; i--) if (par[u][i] != par[v][i]) {
//		u = par[u][i];
//		v = par[v][i];
//	}
//	return par[u][0];
//}
//
//int main()
//{
//	cin >> n >> k;
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		mp[u].push_back(v);
//		mp[v].push_back(u);
//	}
//
//	pre_dfs(1, 0);
//
//	int s, e, f;
//	while (k--) {
//		cin >> s >> e;
//		a[s]++;
//		a[e]++;
//		f = getlca(s, e);
//		a[f]--;
//		a[par[f][0]];
//	}
//	dfs(1, 0);
//	cout << ans;
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e6 + 5;
//ll n, m, r, a[N], tot, L[N], R[N], t[N];
//vector<int>mp[N];
//
//void pre_dfs(int u, int fa) {
//	L[u] = ++tot;
//	for (auto& v : mp[u]) if (v != fa)
//		pre_dfs(v, u);
//	R[u] = tot;
//}
//
//int lowbit(int x) {
//	return x & -x;
//}
//
//void add(int i, int val) {
//	while (i <= n) {
//		t[i] += val;
//		i += lowbit(i);
//	}
//}
//
//ll getsum(int i) {
//	ll ret = 0;
//	while (i > 0) {
//		ret += t[i];
//		i -= lowbit(i);
//	}
//	return ret;
//}
//
//
//int main()
//{
//	cin >> n >> m >> r;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		mp[u].push_back(v);
//		mp[v].push_back(u);
//	}
//	pre_dfs(r, 0);
//	for (int i = 1; i <= n; i++)
//		add(L[i], a[i]);
//	int f, q1, q2;
//	while (m--) {
//		cin >> f;
//		if (f == 1) {
//			cin >> q1 >> q2;
//			add(L[q1], q2);
//		}
//		else {
//			cin >> q1;
//			cout << getsum(R[q1]) - getsum(L[q1] - 1) << '\n';
//		}
//	}
//
//	return 0;
//}




//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//const int N = 110;
//char num[N][N];
//int n;
//
//int cmp(const void* s1, const void* s2) {
//	return -strcmp((char*)s1, (char*)s2);
//}
//
//int main() {
//
//	scanf("%d",&n);
//	getchar();
//	for (int i = 1; i <= n; i++)
//		scanf("%s", num[i]);
//	qsort(num + 1, n, sizeof(num[0]), cmp);
//	for (int i = 1; i <= n; i++)
//		printf("%s", num[i]);
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5+5;
//int n, ne[N], k;
//string m = " mihoyo";
//string s;
//
//
//int main()
//{
//	cin >> n >> k >> s;
//	s = ' ' + s;
//	for (int i = 2, j = 0; i <= 6; i++) {
//		while (j && m[i] != m[j + 1]) j = ne[j];
//		if (m[i] == m[j + 1]) j++;
//		ne[j] = i;
//	}
//	int cnt = 0;
//	vector<int>left;
//	vector<pair<int, int>>ans;
//	for (int i = 1, j = 0; i <= n; i++) {
//		while (j && s[i] != m[j + 1]) j = ne[j];
//		if (s[i] == m[j + 1]) j++;
//		if (j == 6) {
//			left.push_back(i - 6);
//			cnt++;
//			j = ne[j];
//			if (cnt >= k) {
//				ans.push_back({ left[ans.size()],i - 1});
//			}
//		}
//	}
//	sort(ans.begin(), ans.end(), [](pair<int, int>e1, pair<int, int>e2)->int {
//		return e1.second - e1.first < e2.second - e2.first;
//		});
//	if (!ans.size())
//		cout << 0;
//	else
//		cout << ans[0].first << ' ' << ans[0].second;
//
//
//
//	return 0;
//}0 1 2 2 3 3 4 4 1 9 10 10 9 13 13




//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 2e5 + 5;
//int n, fa[N];
//vector<vector<int>>mp;
//
//void init() {
//	mp.clear();
//	mp.resize(n+1);
//}
//
//int dfs(int u, int fa) {
//	int ret = 1;
//	if (mp[u].size() >= 3)
//		ret = 2;
//	else if (mp[u].size() == 1)
//		return 1;
//	int cnt = 0;
//	for (auto v : mp[u]) if (v != fa) {
//		int delt = dfs(v, u);
//		if (cnt && delt >= ret)
//			ret++;
//		if (delt >= ret)
//			ret = delt;
//		cnt++;
//	}
//	return ret;
//}
//
//signed main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		init();
//		int rt;
//		for (int i = 1; i <= n; i++) {
//			cin >> fa[i];
//			if (!fa[i])
//				rt = i;
//			mp[i].push_back(fa[i]);
//			mp[fa[i]].push_back(i);
//		}
//		cout << dfs(rt, 0) << '\n';
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 2e5 + 5;
//int n, fa[N], ans, ned, s[N];
//vector<vector<int>>mp;
//
//void init() {
//	memset(s, 0, sizeof s);
//	mp.clear();
//	mp.resize(n + 1);
//	ned = 1;
//}
//
//int dfs(int u, int fa) {
//	if (u && mp[u].size() == 1)
//		return 1;
//	s[u] = 1;
//	int ret = 1;
//	for (auto v : mp[u]) if (v != fa) {
//		int delt = dfs(v, u);
//		if (s[u] == 0 && delt >= ret)
//			ret++;
//		if (delt >= ret) {
//			ret = delt;
//			s[u] = 0;
//		}
//	}
//	return ret;
//}
//
//signed main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		init();
//		int rt;
//		for (int i = 1; i <= n; i++) {
//			cin >> fa[i];
//			if (!fa[i])
//				rt = i;
//			mp[i].push_back(fa[i]);
//			mp[fa[i]].push_back(i);
//		}
//		cout << dfs(rt, 0) << '\n';
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5+5;
//ll n;
//vector<vector<int>>mp;
//
//ll dfs(ll u, ll fa) {
//	if (mp[u].size() <= 1)
//		return 1;
//	map<ll, ll>ump;
//	for (auto v : mp[u]) if (v != fa) {
//		ump[dfs(v, u)]++;
//	}
//	ll ret = prev(ump.end())->first;
//	if (ump[ret] > 1)
//		return ret + 1;
//	return ret;
//}
//
//
//void init() {
//	mp.clear();
//	mp.resize(n + 1);
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		init();
//		ll rt;
//		for (ll i = 1, tmp; i <= n; i++) {
//			cin >> tmp;
//			if (tmp == 0)
//				rt = i;
//			mp[i].push_back(tmp);
//			mp[tmp].push_back(i);
//		}
//		cout << dfs(rt, 0) << '\n';
//	}
//
//	return 0;
//}






//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, k;
//string s;
//
//int main() {
//	int t;
//	cin >> t;
//	int a, b, c;
//	while (t--) {
//		cin >> a >> b >> c;
//		if (a + b == c)
//			cout << "+\n";
//		else
//			cout << "-\n";
//	}
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n;
//string s;
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		int a = 0, b = 0;
//		for (int i = 0, t; i < n; i++) {
//			cin >> t;
//			if (t % 2)
//				b += t;
//			else
//				a += t;
//		}
//		if (a > b)
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
//const int N = 2e5 + 5;
//int n;
//string s;
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		cin >> s;
//		unordered_map<char, int>mp;
//		for (int i = 0; i < n; i++)
//			if (!mp[s[i]])
//				mp[s[i]] = i & 1;
//		for (auto [c, v] : mp) {
//			for (int i = 0; i < n; i++) if (s[i] == c && (i & 1) != v) {
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
//typedef long long ll;
//const int N = 2e5 + 5;
//ll n, q, pre[N];
//string s;
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> n >> q;
//		for (int i = 1; i <= n; i++) {
//			cin >> pre[i];
//			pre[i] += pre[i - 1];
//		}
//		ll l, r, k, sum = pre[n];
//		while (q--) {
//			cin >> l >> r >> k;
//			if ((sum - pre[r] + pre[l - 1] + (r - l + 1) * k) % 2)
//				cout << "YES\n";
//			else
//				cout << "NO\n";
//		}
//	}
//
//	return 0;
//}



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n, q, a[N];
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n, greater());
		if (a[n - 1] != 1) {
			cout << "NO\n";
			goto ss;
		}
		for (int i = 0, mx, sum; i < n - 1; i++) {
			mx = a[i];
			sum = 0;
			for (int j = i + 1; j < n; j++) {
				if (sum + a[j] <= mx)
					sum += a[j];
			}
			if (sum != mx) {
				cout << "NO\n";
				goto ss;
			}
		}
		cout << "YES\n";
	ss:;
	}

	return 0;
}
