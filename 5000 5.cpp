#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
//
//ll a[200010];
//map<ll,ll>m;
//int main()
//{
//	ll n, c,sum = 0;
//	cin >> n >> c;
//	for (ll i = 0;i < n;i++)
//	{
//		cin >> a[i];
//		m[a[i]]++;
//		a[i] -= c;
//	}
//	for (ll i = 0;i < n;i++)
//		sum += m[a[i]];
//	cout << sum;
//
//	return 0;
//}
//
//typedef long long ll;
//ll tre[1000010];
//
//int main()
//{
//	ll n, m, lon = 0;
//	cin >> n >> m;
//	for (ll i = 0;i < n;i++)
//		cin >> tre[i];
//	sort(tre, tre + n);
//	ll f = n-1;
//	for (ll i = tre[n-1];i >= 1 ;i--)
//	{
//		while (tre[f] > i)
//			f--;
//		lon += (n-1-f);
//		if (lon >= m)
//		{
//			cout << i;
//			break;
//		}
//	}
//	return 0;
//}

//double a, b, c, d,l,r,m;
//inline double f(double x)
//{
//	return a * x * x * x + b * x * x + c * x + d;
//}
//
//int main()
//{
//	int count = 0;
//	cin >> a >> b >> c >> d;
//	for (l = -100;l < 100;l++)
//	{
//		r = l + 1;
//		m = (l + r) / 2;
//		if (f(l) == 0)
//		{
//			count++;
//			printf("%.2lf ",l);
//		}
//		else while(f(r) * f(l) < 0)
//		{
//			if (r - l < 0.001)
//			{
//				printf("%.2lf ", r);
//			}
//			if (f(m) == 0)
//			{
//				count++;
//				printf("%.2lf ",m);
//				break;
//			}
//			else if (f(m) * f(r) < 0)
//				l = m;
//			else if (f(m) * f(l) < 0)
//				r = m;
//		}
//		if (count == 3)
//			break;
//	}
//	return 0;
//}


//int school[100010];
//
//int main()
//{
//	int m, n, sum = 0,t;
//	cin >> m >> n;
//	for (int i = 0;i < m;i++)
//		cin >> school[i];
//	sort(school, school + m);
//	while (n--)
//	{
//		cin >> t;
//		int a = *lower_bound(school, school + m, t),
//			b = *(lower_bound(school, school + m, t) - 1);
//		b = b == 0 ? a : b;
//		sum += min(abs(t-a),abs(b-t));
//	}
//	cout << sum;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//inline void m_strcpy(char* a, const char* b)
//{
//	while (*a++ = *b++);
//}
//
//unsigned int m_strlen(const char* a)
//{
//	const char* p = a;
//	while (*++a);
//	return a - p;
//}
//
//int main()
//{
//	char a[] = "holle!";
//	char b[] = "what";
//	m_strcpy(a, b);
//	cout << a << endl;
//
//	cout << m_strlen(a);
//	return 0;
//}


//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	set<int>scho;
//	for (int i = 0;i < m;i++)
//	{
//		int t;
//		cin >> t;
//		scho.insert(t);
//	}
//	int sum = 0;
//	while (n--)
//	{
//		int t,a,b;
//		cin >> t;
//		auto p = scho.lower_bound(t);
//		if (p == scho.end())
//		{
//			p--;
//			b = a = *p;
//		}
//		else if(p == scho.begin())
//		{
//			a = *p;
//			p++;
//			b = *p;
//		}
//		else
//		{
//			a = *p;
//			p--;
//			b = *p;
//		}
//		sum += min(abs(a - t), abs(b - t));
//	}
//	cout << sum;
//	return 0;
//}

//int arr[100010];
//int n, k;
//int f(int m)
//{
//	int s = 0;
//	for (int i = 0;i < n;i++)
//		s += arr[i] / m;
//	return s - k;
//}
//int main()
//{
//	cin >> n >> k;
//	int max  = 0;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> arr[i];
//		max = max > arr[i] ? max : arr[i];
//	}
//	int l = 0, r = 100000001, m = 0, flag;
//	while (r-1 > l)
//	{
//		m = (l + r) >> 1;
//		flag = f(m);
//		if (flag >= 0)
//			l = m;
//		else
//			r = m;
//	}
//	cout << l;
//	return 0;
//}




//int node[1010] = { 0 };
//int way[1001][1001] = { 0 };
//int been[1001] = { 0 };
//	int n, m,t1,t2;
//void dfs(int x)
//{
//	been[x] = 1;
//	for (int i = 1;i <= n;i++)
//		if (way[x][i] && !been[i])
//			dfs(i);
//}
//
//
//int main()
//{
//	if (n == 2 && m % 2 == 0)
//	{
//		cout << 1;
//		return 0;
//	}
//	cin >> n >> m;
//	while (m--)
//	{
//		cin >> t1 >> t2;
//		way[t1][t2] = way[t2][t1] = 1;
//		node[t1]++;
//		node[t2]++;
//	}
//	for (int i = 1;i <= n;i++)
//		if (node[i] % 2 == 1)
//		{
//			cout << 0;
//			return 0;
//		}
//	dfs(1);
//	for(int i = 1;i <= n;i++)
//		if(!been[i])
//		{
//			cout << 0;
//			return 0;
//		}
//	cout << 1;
//	return 0;
//}


//int n, m, k;
//int way[10001][10001] = { 0 };
//void f(int np)
//{
//	int v;
//	cin >> v;
//	for (int i = 1;i <= n;i++)
//	{
//		if (way[i][v] == 1)
//			way[i][v]++;
//		if (way[v][i] == 1)
//			way[v][i]++;
//	}
//	if(np != 1)
//	f(np - 1);
//	else
//	{
//		for (int i = 1;i <= n;i++)
//		{
//			for(int j = 1;j <= n;j++)
//				if (way[i][j] == 1)
//				{
//					cout << "NO" << endl;
//					goto ss;
//				}
//		}
//		cout << "YES" << endl;
//	ss:;
//	}
//	for (int i = 1;i <= n;i++)
//	{
//		if (way[i][v] == 2)
//			way[i][v]--;
//		if (way[v][i] == 2)
//			way[v][i]--;
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	while (m--)
//	{
//		int t1, t2;
//		cin >> t1 >> t2;
//		way[t1][t2] = way[t2][t1] = 1;
//	}
//	cin >> k;
//	while (k--)
//	{
//		int np;
//		cin >> np;
//		f(np);
//	}
//	return 0;
//}


//int way[1001][2] = { 0 };
//int main()
//{
//	int n, m,m2;
//	cin >> n >> m;
//	m2 = m;
//	while (m--)
//		cin >> way[m][0] >> way[m][1];
//	int k;
//	cin >> k;
//	while (k--)
//	{
//		int q;
//		cin >> q;
//		set<int>se;
//		while (q--)
//		{
//			int t;
//			cin >> t;
//			se.insert(t);
//		}
//		for(int i = 0;i < m2;i++)
//			if (se.find(way[i][0]) == se.end() && se.find(way[i][1]) == se.end())
//			{
//				cout << "NO" << endl;
//				goto ss;
//			}
//		cout << "YES" << endl;
//	ss:;
//	}
//	return 0;
//}



//int way[201][201] = { 0 };
//
//int main()
//{
//	int n, m,k;
//	cin >> n >> m;
//	for (int i = 0;i < m;i++)
//	{
//		int t1, t2;
//		cin >> t1 >> t2;
//		way[t1][t2] = way[t2][t1] = 1;
//	}
//	cin >> k;
//	while (k--)
//	{
//		int t,jud = 1;
//		cin >> t;
//		if (t != n + 1)
//			jud = 0;
//		queue<int>que;
//		int tmp,first;
//		cin >> first;
//		que.push(first);
//		while (--t)
//		{
//			cin >> tmp;
//			way[tmp][0]++;
//			que.push(tmp);
//			if (!way[que.front()][que.back()])
//				jud = 0;
//			que.pop();
//		}
//		for (int i = 1;i <= n;i++)
//		{
//			if (way[i][0] != 1)
//				jud = 0;
//			way[i][0]=0;
//		}
//		if (first != que.back())
//			jud = 0;
//		if (jud)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}





		
//int n, m, t1, t2, t3;
//int way[201][201] = { 0 }, been[201] = { 0 };
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < m;i++)
//	{
//		cin >> t1 >> t2 >> t3;
//		way[t1][t2] = way[t2][t1] = t3;
//	}
//	int k,np,mp = 0x0f3f3f3f,max = 0x0f3f3f3f,sum = 0,t;
//	cin >> k;
//	for(int x = 1;x <= k;x++)
//	{
//		int jud = 1, money = 0;
//		cin >> np;
//		if (np != n)
//			jud = 0;
//		queue<int>que;
//		cin >> t;
//		been[t]++;
//		if (way[0][t])
//			money += way[0][t];
//		else
//			jud = 0;
//		que.push(t);
//		while (--np)
//		{
//			cin >> t;
//			been[t]++;
//			que.push(t);
//			if (way[que.front()][que.back()])
//				money += way[que.front()][que.back()];
//			else
//				jud = 0;
//			que.pop();
//		}
//		if (way[t][0])
//			money += way[t][0];
//		else
//			jud = 0;
//		for (int i = 1;i <= n;i++)
//		{
//			if (been[i] != 1)
//				jud = 0;
//			been[i] = 0;
//		}
//		if (jud)
//		{
//			sum++;
//			if (money < max)
//			{
//				mp = x;
//				max = money;
//			}
//		}
//	}
//	cout << sum << endl << mp << " " << max;
//	return 0;
//}




//bool way[1001][1001] = { 0 };
//bool been[1001] = { 0 };
//int road[3001] = { 0 };
//int n, m, t1, t2, s,c = 0;
//void search(int s,int x)
//{
//	road[x] = s;
//	been[s]++;
//	if (been[s] == 1)
//		c++;
//	if (c == n)
//	{
//		int i = 0;
//		for (i = 0;road[i];i++)
//			cout << road[i] << " ";
//		for (i--;i >= 0;i--)
//			cout << road[i] << " ";
//	}
//	else
//	{
//		for (int i = 1;i <= n;i++)
//		{
//			if (way[s][i])
//				search(i,x+1);
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m >> s;
//	for (int i = 0;i < m;i++)
//	{
//		cin >> t1 >> t2;
//		way[t1][t2] = way[t2][t1] = 1;
//	}
//	search(s,0);
//	return 0;
//}



//
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	int n;
//	int min = 0, max = 0;
//	while (scanf("%d",&n) != EOF)
//	{
//		if (n % 2 == 0 && (min == 0 || n < min))
//			min = n;
//		else if (n % 2 == 1 && n > max)
//			max = n;
//	}
//	if (min && max)
//		cout << max - min;
//	else
//		cout << "None";
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int arr[100010] = { 0 };
//int main()
//{
//	int n,t,min = 0;
//	cin >> n;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> arr[i];
//		min = (arr[i] < min || min == 0) ? arr[i] : min;
//	}
//	int sum = 0;
//	for (int i = 0;i < n;i++)
//	{
//		sum += (arr[i] - min);
//	}
//	cout << sum;
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	queue<int>que;
//	int t1,t2,sum = 0;
//	for (int i = 0;i < k;i++)
//	{
//		cin >> t1 >> t2;
//		que.push(t1*t2);
//		sum += que.back();
//	}
//	int max = sum;
//	for (int i = 0;i < n - k;i++)
//	{
//		cin >> t1 >> t2;
//		que.push(t1 * t2);
//		sum -= que.front();
//		sum += que.back();
//		que.pop();
//		max = max < sum ? sum : max;
//	}
//	cout << max;
//	return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//inline int f(int a, int b)
//{
//	int t1 = min(a, b), t2 = max(a, b);
//	int t = t1;
//	for (t1;t1 <= t * t2;t1 += t)
//	{
//		if (t1 % t2 == 0)
//		{
//			return t1;
//		}
//	}
//}
//int main()
//{
//	int n,a,sum = 0,cut = 1;
//	cin >> n;
//	while (n--)
//	{
//		cin >> a;
//		sum += a;
//		cut = f(cut, sum);
//	}
//	cout << cut;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//int main()
//{
//	ll n, sum = 0, cut = 1, a,k = 1;
//	cin >> n;
//	while (n--)
//	{
//		cin >> a;
//		sum += a;
//		for (k = 1;1;k++)
//		{
//			if (cut * k % sum == 0)
//			{
//				cut *= k;
//				break;
//			}
//		}
//	}
//	cout << cut;
//	return 0;
//}



//#include<iostream>
//#include<vector>
//using namespace std;
//char arr[17][34] = { 0 };
//const char col[] = "+-a-+-b-+-c-+-d-+-e-+-f-+-g-+-h-+";
//const int row[] = { 0,8,0,7,0,6,0,5,0,4,0,3,0,2,0,1 };
//typedef struct
//{
//	int x, y;
//}node;
//vector<node> q,r,b,n,p;
//vector<node> q2, r2, b2, n2, p2;
//int main()
//{
//	for (int i = 0;i < 17;i++)
//	{
//		for (int j = 0;j < 34;j++)
//			scanf("%c", &arr[i][j]);
//	}
//	cout << "White:";
//
//
//	for (int i = 0;i < 17;i++)
//		for (int j = 0;j < 34;j++)
//		{
//			if (arr[i][j] == 'K')
//			{
//				cout << 'K' << col[j] << row[i];
//			}
//			else if (arr[i][j] == 'Q')
//				q.push_back({ i,j });
//			else if (arr[i][j] == 'R')
//				r.push_back({ i,j });
//			else if (arr[i][j] == 'B')
//				b.push_back({ i,j });
//			else if (arr[i][j] == 'N')
//				n.push_back({ i,j });
//			else if (arr[i][j] == 'P')
//				p.push_back({ i,j });
//		}
//	for(auto p = q.begin();p != q.end();p++)
//		cout << "," << 'Q' << col[p->y] << row[p->x];
//	for (auto p = r.begin();p != r.end();p++)
//		cout << "," << 'R' << col[p->y] << row[p->x];
//	for (auto p = b.begin();p != b.end();p++)
//		cout << "," << 'B' << col[p->y] << row[p->x];
//	for (auto p = n.begin();p != n.end();p++)
//		cout << "," << 'N' << col[p->y] << row[p->x];
//	for (auto pt = p.begin();pt != p.end();pt++)
//		cout << "," << col[pt->y] << row[pt->x];
//
//
//	cout << "\nBlack:";
//
//
//	for (int i = 0;i < 17;i++)
//		for (int j = 0;j < 34;j++)
//		{
//			if (arr[i][j] == 'k')
//			{
//				cout << 'K' << col[j] << row[i];
//			}
//			else if (arr[i][j] == 'q')
//				q2.push_back({ i,j });
//			else if (arr[i][j] == 'r')
//				r2.push_back({ i,j });
//			else if (arr[i][j] == 'b')
//				b2.push_back({ i,j });
//			else if (arr[i][j] == 'n')
//				n2.push_back({ i,j });
//			else if (arr[i][j] == 'p')
//				p2.push_back({ i,j });
//		}
//	for (auto p = q2.begin();p != q2.end();p++)
//		cout << "," << 'Q' << col[p->y] << row[p->x];
//	for (auto p = r2.begin();p != r2.end();p++)
//		cout << "," << 'R' << col[p->y] << row[p->x];
//	for (auto p = b2.begin();p != b2.end();p++)
//		cout << "," << 'B' << col[p->y] << row[p->x];
//	for (auto p = n2.begin();p != n2.end();p++)
//		cout << "," << 'N' << col[p->y] << row[p->x];
//	for (auto pt = p2.begin();pt != p2.end();pt++)
//		cout << "," << col[pt->y] << row[pt->x];
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    char s[110] = { 0 };
//    cin.getline(s, 101);
//    int len = strlen(s);
//    for (int i = len;i >= 0;i--)
//    {
//        if (s[i] == ' ' || i == 0)
//        {
//            for (int j = i == 0 ? i : i + 1;j <= len;j++)
//            {
//                if (s[j] == ' ')
//                    break;
//                cout << s[j];
//            }
//            cout << " ";
//        }
//    }
//    return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	char s[] = "sdasda";
//	char* p = s;
//	cout << *p++;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int n, m, s;
//bool isfirst = 0;
//bool been[1001] = { 0 };
//int cnt = 0;
//vector<int>node[1001];
//void search(int s)
//{
//	if (!isfirst)
//		isfirst = true;
//	else
//		cout << " ";
//	cout << s;
//	if (!been[s])
//		cnt++;
//	been[s] = true;
//	if(cnt!=n)
//	for (int i = 0;i < node[s].size();i++)
//	{
//		if (!been[node[s][i]])
//		{
//			search(node[s][i]);
//			cout << " " << s;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m >> s;
//	int t1, t2;
//	for (int i = 0;i < m;i++)
//	{
//		cin >> t1 >> t2;
//		node[t1].push_back(t2);
//		node[t2].push_back(t1);
//	}
//	search(s);
//	if (cnt != n)
//		cout << " 0";
//	return 0;
//}




//int main()
//{
//	printf(" ");
//	putchar('a');
//	return 0;
//}


//int n, m, k, c = 0;
//bool been[500] = { 0 };
//int city[500][500] = { 0 };
//bool fir = true;
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < m;i++)
//	{
//		int t1, t2;
//		cin >> t1 >> t2;
//		city[t1][t2] = city[t2][t1] = 1;
//	}
//	cin >> k;
//	while (k--)
//	{
//		int t;
//		cin >> t;
//		if (!been[t])
//		{
//			been[t] = true;
//			c++;
//		}
//		for (int i = 0;i < n;i++)
//			city[i][t] = city[t][i] = 0;
//		for (int i = 0;i < n;i++)
//		{
//			for (int j = 0;j < n;j++)
//			{
//				if (city[i][j] || city[j][i])
//				{
//					cout << "City " << t << " is lost.";
//					if (k)
//						cout << endl;
//					goto ss;
//				}
//			}
//		}
//		if (fir)
//		{
//			cout << "Red Alert: City " << t << " is lost.";
//			if (k)
//				cout << endl;
//			fir = false;
//		}
//		else
//		{
//			cout << "City " << t << " is lost.";
//			if (k)
//				cout << endl;
//		}
//	ss:;
//		if (c == n)
//		{
//			if (!k)
//				cout << endl;
//			cout << "Game Over.";
//			if (k)
//				cout << endl;
//		}
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int n, m, k, jud = 0, s,coun = 0,c = 0;
//vector<int>vec[500];
//set<int>down;
//bool been[500] = { 0 };
//int last;
//void search(int t)
//{
//	for (int i = 0;i < vec[t].size();i++)
//	{
//		if (!been[vec[t][i]] && down.find(vec[t][i]) == down.end() && last != vec[t][i])
//		{
//			if (t == s)
//				c++;
//			coun++;
//			been[vec[t][i]] = true;
//			if (vec[t][i] == s)
//			{
//				jud = 1;
//				break;
//			}
//			else
//			{
//				last = t;
//				search(vec[t][i]);
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	while (m--)
//	{
//		int t1, t2;
//		cin >> t1 >> t2;
//		vec[t1].push_back(t2);
//		vec[t2].push_back(t1);
//	}
//	cin >> k;
//	while (k--)
//	{
//		coun = 0;
//		c = 0;
//		memset(been, 0, sizeof(been));
//		cin >> s;
//		jud = 0;
//		last = -1;
//		search(s);
//		down.insert(s);
//		if (c>1&&(!jud && coun))
//			cout << "Red Alert: ";
//		cout << "City " << s << " is lost.\n";
//		if (down.size() == n)
//			cout << "Game Over.\n";
//	}
//	return 0;
//}


//int k, n, m;
//int pre[500] = { 0 };
//pair<int, int>way[5001];
//void init()
//{
//	for (int i = 0;i < n;i++)
//		pre[i] = i;
//}
//int find_pre(int s)
//{
//	if (pre[s] == s)
//		return s;
//	return find_pre(pre[s]);
//}
//void unite(int x, int y)
//{
//	int rx = find_pre(x);
//	int ry = find_pre(y);
//	if (rx != ry)
//	{
//		pre[rx] = ry;
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	init();
//	while (m--)
//	{
//		int x, y;
//		cin >> x >> y;
//		unite(x, y);
//	}
//	cin >> k;
//	int a = 0, b = 0;
//	for (int i = 0;i < n;i++)
//	{
//		if (pre[i] == i)
//			a++;
//	}
//	while (k--)
//	{
//		b = 0;
//		int s;
//		cin >> s;
//		for (int i = 0;i < n;i++)
//		{
//			if (pre[i] == s)
//				pre[i] = i;
//		}
//		for (int i = 0;i < n;i++)
//		{
//			if (pre[i] == i)
//				b++;
//		}
//		if (b > a)
//			cout << "Red Alert: ";
//		cout << "City " << s << " is lost.\n";
//		if (b == 0)
//			cout << "Game Over.\n";
//		a = b;
//	}
//	return 0;
//}


//typedef struct
//{
//	int a, b;
//}node;
//node way[5001];
//int n, m, k,cnt;
//int merg[501];
//bool live[501];
//int find_pre(int s) // find����
//{
//	return s == merg[s] ? s : find_pre(merg[s]);
//}
//void unite(int a, int b)   // join����
//{
//	int ra = find_pre(a), rb = find_pre(b);
//	if (ra != rb)
//		merg[ra] = rb;
//}
//void makemerg()   //���첢�鼯
//{
//	for (int i = 0;i < n;i++)
//		merg[i] = i;
//	for (int i = 0;i < m;i++)
//		if(live[way[i].a] && live[way[i].b])
//			unite(way[i].a, way[i].b);
//}
//int cntall()  // ������ͨ����
//{
//	cnt = 0;
//	for (int i = 0;i < n;i++)
//		if (live[i]&&merg[i] == i)
//			cnt++;
//	return cnt;
//}
//
//
//int main()
//{
//	memset(live, 1, sizeof(live));
//	cin >> n >> m;
//	for (int i = 0;i < m;i++)
//	{
//		cin >> way[i].a >> way[i].b;
//	}
//	makemerg();
//	cin >> k;
//	int last = cntall(), now;
//	while (k--)
//	{
//		int t;
//		cin >> t;
//		live[t] = 0;
//		makemerg();
//		now = cntall();
//		if (now > last)
//			cout << "Red Alert: ";
//		cout << "City " << t << " is lost.\n";
//		last = now;
//	}
//	if (!cntall())
//		cout << "Game Over.\n";
//	return 0;
//}


//typedef struct
//{
//    int x,y;
//}nodes;
//nodes node[101];
//int n,d;
//bool flag = 0;
//bool vis[101]={0};
//bool last(int i)
//{
//    if(abs(node[i].x)>=50-d||abs(node[i].y)>=50-d)
//    return true;
//    return false;
//}
//bool first()
//{
//    for(int i = 1;i <= n;i++)
//    {
//        double a = node[i].x*node[i].x,b = node[i].y*node[i].y;
//        if(a+b>=(d+7.5)*(d+7.5))
//        return true;
//    }
//    return false;
//}
//void search(int s)
//{
//    if(!s)
//    {
//        for(int i = 1;i <= n&&!flag;i++)
//        {
//            double a = node[i].x*node[i].x,b = node[i].y*node[i].y;
//            if(!vis[i]&& a + b >= (d + 7.5) * (d + 7.5))
//            {
//                vis[i]=1;
//                if(last(i))
//                flag = 1;
//                else
//                search(i);
//                vis[i]=0;
//            }
//        }
//    }
//    else
//    {
//        for(int i = 1;i <= n&&!flag;i++)
//        {
//            double a = pow(node[i].x-node[s].x,2),b = pow(node[i].y-node[s].y,2);
//            if(!vis[i]&&a+b>=d*d)
//            {
//                vis[i]=1;
//                if(last(i))
//                flag = 1;
//                else
//                search(i);
//                vis[i]=0;
//            }
//        }
//    }
//}
//
//int main()
//{
//    cin >> n >> d;
//    for(int i = 1;i <= n;i++)
//        cin >> node[i].x >> node[i].y;
//    
//    if(d >= 42.5)
//        cout << "Yes";
//    else
//    {
//        if (first())
//            search(0);
//        if(flag)
//        cout << "Yes";
//        else
//        cout << "No";
//    }
//    return 9;
//}





//typedef struct
//{
//	int x, y;
//}node;
//node fish[101];
//bool vis[101] = { 0 };
//int n, d, jud = 0;
//int search(int s)
//{
//	for (int i = 0;!jud&&i < n;i++)
//	{
//		int len2 = pow(fish[i].x - fish[s].x, 2) + pow(fish[i].y - fish[s].y, 2);
//		if (!vis[i] && len2 <= d * d)
//		{
//			vis[i] = 1;
//			if (abs(fish[i].x) >= 50 - d || abs(fish[i].x >= 50 - d))
//				jud = 1;
//			else
//				search(i);
//			vis[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> d;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> fish[i].x >> fish[i].y;
//	}
//
//	if (d >= 42.5)
//		cout << "Yes";
//	else
//	{
//		for (int i = 0;!jud && i < n;i++)
//		{
//			int len2 = pow(fish[i].x, 2) + pow(fish[i].y, 2);
//			if (!vis[i] && len2 <= pow(7.5 + d, 2))
//			{
//				vis[i] = 1;
//				search(i);
//				vis[i] = 0;
//			}
//		}
//		if (jud)
//			cout << "Yes";
//		else
//			cout << "No";
//	}
//	return 0;
//}


//int way[10][10] = { 0 }, n, e;
//int vis[10] = { 0 },c = 0;
//queue<int>que;
//void dfs(int s)
//{
//	cout << " " << s;
//	vis[s] = 1;
//	c++;
//	for (int i = 0;i < n;i++)
//	{
//		if (!vis[i] && way[s][i])
//			dfs(i);
//	}
//}
//
//
//int main()
//{
//	cin >> n >> e;
//	for (int i = 0;i < e;i++)
//	{
//		int t1, t2;
//		cin >> t1 >> t2;
//		way[t1][t2] = way[t2][t1] = 1;
//	}
//	while (c < n)
//	{
//		cout << "{";
//		for (int i = 0;i < n;i++)
//		{
//			if (!vis[i])
//			{
//				dfs(i);
//				break;
//			}
//		}
//		cout << " }\n";
//	}
//	memset(vis, 0, sizeof(vis));
//	c = 0;
//	while (c < n)
//	{
//		cout << "{";
//		for (int i = 0;i < n;i++)
//		{
//			if (!vis[i])
//			{
//				que.push(i);
//				vis[i] = 1;
//				while (!que.empty())
//				{
//					int t = que.front();
//					for (int i = 0;i < n;i++)
//					{
//						if (!vis[i] && way[i][t])
//						{
//							que.push(i);
//							vis[i] = 1;
//						}
//					}
//					cout << " " << t;
//					c++;
//					que.pop();
//				}
//				break;
//			}
//		}
//		cout << " }\n";
//	}
//	return 0;
//}