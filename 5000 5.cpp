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


//int n, m, vis[1001] = { 0 };
//set<int>way[1001];
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < m;i++)
//	{
//		int t1, t2;
//		cin >> t1 >> t2;
//		way[t1].insert(t2);
//		way[t2].insert(t1);
//	}
//	for (int i = 1;i <= n;i++)
//	{
//		memset(vis, 0, sizeof(vis));
//		int c = 0,deep = 0,last = 0;
//		queue<int>que;
//		cout << i << ": ";
//		que.push(i);last++;
//		while (!que.empty() && deep < 6)
//		{
//			int now = que.front();
//			for (auto p = way[now].begin();p != way[now].end();p++)
//			{
//				if (!vis[*p])
//				{
//					vis[*p] = 1;
//					que.push(*p);
//					c++;
//				}
//			}
//			que.pop();
//			if (--last == 0)
//			{
//				deep++;
//				last = que.size();
//			}
//		}
//		double f = (double)c*100.0 / (double)n;
//		printf("%.2lf%%\n",f);
//	}
//	return 0;
//}




//int num[1000];
//char a[10000] = { 0 };
//int main()
//{
//	for (int i = 0;1;i++)
//	{
//		a[i] = getchar();
//		if (a[i] != ' ' && a[i] != '-' &&(a[i] > '9' || a[i] < '0' || a[i] == '.'))
//			break;
//	}
//	int j = 0;
//	for (int i = 0;1;i++)
//	{
//		if (a[i] != '-' &&(a[i] > '9' || a[i] < '0' || a[i] == '.'))
//			break;
//		num[j++] = atoi(a+i);
//		while (a[++i] != ' ');
//	}
//	sort(num, num + j);
//	cout << "从标准设备读入数据，直到输入是非整型数据为止\n";
//	for (int i = 0;i < j;i++)
//	{
//		cout << num[i] << " ";
//	}
//	return 0;
//}



//
//typedef struct
//{
//    int a, b;
//    double num;
//}real_m;
//
//int main()
//{
//    real_m x, y;
//    scanf("%d/%d %d/%d", &x.a, &x.b, &y.a, &y.b);
//    x.num = x.a / (double)x.b;
//    y.num = y.a / (double)y.b;
//    printf("%d/%d", x.a, x.b);
//    if (x.num == y.num)
//        printf(" = ");
//    else if (x.num > y.num)
//        printf(" > ");
//    else
//        printf(" < ");
//    printf("%d/%d", y.a, y.b);
//    return 0;
//}



//#include<stdio.h>
//
//typedef struct
//{
//	char name[11], num[20];
//	char birt[10];
//}people;
//people ar[11];
//int cmp(const void* e1, const void* e2)
//{
//	return atoi(((people*)e1)->birt) - atoi(((people*)e2)->birt);
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%s %s %s", ar[i].name, &ar[i].birt, ar[i].num);
//	}
//	qsort(ar, n, sizeof(ar[0]), cmp);
//	for (int i = 0;i < n;i++)
//	{
//		printf("%s %s %s\n", ar[i].name, ar[i].birt, ar[i].num);
//	}
//	return 0;
//}



//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//    char ch[100] = { 0 };
//    cin >> ch;
//    int kg = 0;
//    for (int i = 0;i < strlen(ch);i++)
//    {
//
//        if (ch[i] >= '0' && ch[i] <= '9')
//        {
//            if (ch[i] != '0')
//                kg = 1;
//            if (kg)
//                printf("%c", ch[i]);
//            if (ch[i] == '0')
//                kg = 1;
//
//        }
//    }
//    return 0;
//}



//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//    char c[20];
//    cin >> c;
//    int jud = 1;
//    for (int i = 0, j = strlen(c)-1;i <= j;i++, j--)
//    {
//        if (c[i] != c[j])
//        {
//            jud = 0;
//            break;
//        }
//    }
//    if (jud)
//        printf("Yes");
//    else
//        printf("No");
//    return 0;
//}


//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//    char ch[100];
//    cin >> ch;
//    for (int i = strlen(ch) - 1;i >= 0;i--)
//    {
//        printf("%c", &ch[i]);
//    }
//    return 0;
//}



//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//    char t[100] = { 0 }, max[100] = { 0 };
//    scanf("%s", max);
//    while (t[0] != '.')
//    {
//        scanf("%s", t);
//        if (strlen(t) > strlen(max))
//            strcpy(max, t);
//    }
//    printf("%s", max);
//    return 0;
//}



//int n,maxm = 0,mdoor = 0;
//vector<int>room[10001];
//
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//	{
//		int k;
//		cin >> k;
//		while (k--)
//		{
//			int t;
//			cin >> t;
//			room[i].push_back(t);
//		}
//	}
//	for (int i = 1;i <= n;i++)
//	{
//		int len = 0,last = 0,now = 0,door = 0;
//		queue<int>que;
//		if (!room[i].empty())
//			que.push(i);
//		last++;
//		while (!que.empty())
//		{
//			//if(!room[que.front()].empty())
//			for (auto p = room[que.front()].begin();p != room[que.front()].end();p++)
//			{
//				que.push(*p);
//				now++;
//			}
//			door = que.front();
//			que.pop();
//			last--;
//			if (last == 0)
//			{
//				last = now;
//				now = 0;
//				len++;
//			}
//		}
//		if (len > maxm)
//		{
//			maxm = len;
//			mdoor = door;
//		}
//	}
//	cout << mdoor;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	cout << "fengqibisheng, yingyueerlai!";
//	return 0;
//}






//typedef struct hero
//{
//	int t1, t2;
//};
//hero arr[6];
//int h1, h2, m, have = 0;
//
//int main()
//{
//	for (int i = 0;i < 6;i++)
//	{
//		arr[i].t1 = -1;
//	}
//	cin >> h1 >> h2 >> m;
//	while (m--)
//	{
//		int t1, t2, t3, t4;
//		scanf("%d:%d %d", &t1, &t2, &t3);
//		if (t3 == 3)
//		{
//			cin >> t4;
//			if (have)
//			{
//				if (60 * (t1 - arr[t4].t1) + (t2 - arr[t4].t2) >= 30)
//				{
//					arr[t4].t1 = t1;
//					arr[t4].t2 = t2;
//					double s = (125.0 + 0.06 * h1) * 0.1;
//					h1 += (int)s;
//				}
//			}
//		}
//		else if (t3 == 1)
//		{
//			have = 1;
//			h1 += 800;
//		}
//		else if (t3 == 2)
//			h1 += h2;
//	}
//	cout << h1;
//	return 0;
//}




//typedef long long ll;
//set<ll>s,s1;
//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		ll t;
//		cin >> t;
//		s.insert(t);
//	}
//	for (auto p = s.begin();p != s.end();p++)
//	{
//		if(s.find(*p+9)==s.end())
//		s1.insert(*p + 9);
//	}
//	cout << s1.size();
//	return 0;
//}



//ll n, m, k;
//typedef struct
//{
//	ll a, c;
//}people;
//people vec[200002];
//
//int cmp(const void* e1, const void* e2)
//{
//	return ((people*)e1)->a - ((people*)e2)->a;
//}
//
//int main()
//{
//	cin >> n >> m >> k;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> vec[i].a;
//	}
//	for (int i = 0;i < n;i++)
//	{
//		ll t;
//		cin >> t;
//		vec[i].a -= t*m;
//	}
//	for (int i = 0;i < n;i++)
//	{
//		ll t;
//		cin >> t;
//		vec[i].c = t;
//	}
//	qsort(vec,n,sizeof(vec[0]), cmp);
//	int sum = 0;
//	for (int i = n - 1;i >= 0;i--)
//	{
//		if (vec[i].a > 0)
//			sum--;
//		while (k>0&&vec[i].a <= 0)
//		{
//			k--;
//			vec[i].a += vec[i].c;
//		}
//		if (vec[i].a > 0)
//			sum++;
//	}
//	cout << sum;
//	return 0;
//}



//int main()
//{
//	int n,s = 0;
//	cin >> n;
//	while (n--)
//	{
//		ll t;
//		cin >> t;
//		if (t % 2 == 1)
//			s++;
//	}
//	if (s % 2 == 1)
//		cout << "Alice";
//	else
//		cout << "Bob";
//
//	return 0;
//}



//int n, m, k;
//int a[2002] = { 0 };
//int main()
//{
//	cin >> n >> m >> k;
//	for (int i = 1;i <= 2 * n;i++)
//		a[i] = i;
//	for (int s = 1, i = 1;1;i++, s++)
//	{
//		if (i > n)
//			i = 1;
//		if (s % m == 0)
//		{
//			a[i] = a[i] ^ a[i + n];
//			a[i + n] = a[i] ^ a[i + n];
//			a[i] = a[i] ^ a[i + n];
//		}
//		if (s == k)
//			break;
//	}
//	for (int i = 1;i <= 2 * n;i++)
//		cout << a[i] << " ";
//	return 0;
//}


//typedef long long ll;
//typedef struct
//{
//	ll a, c;
//}p;
//int n, m, k;
//p arr[200002] = { 0 };
//
//int cmp(const void* e1, const void* e2)
//{
//	if (((p*)e1)->a > ((p*)e2)->a) return 1;
//	else if (((p*)e1)->a < ((p*)e2)->a) return -1;
//	else if (((p*)e1)->a == ((p*)e2)->a)
//	{
//		if (((p*)e1)->c > ((p*)e2)->c)
//			return 1;
//		else if (((p*)e1)->c < ((p*)e2)->c)
//			return -1;
//		else
//			return 0;
//	}
//}
//int main()
//{
//	cin >> n >> m >> k;
//	for (ll i = 0;i < n;i++)
//	{
//		cin >> arr[i].a;
//	}
//	for (ll i = 0;i < n;i++)
//	{
//		ll t;
//		cin >> t;
//		arr[i].a -= t * m;
//	}
//	for (int i = 0;i < n;i++)
//	{
//		cin >> arr[i].c;
//	}
//	qsort(arr, n, sizeof(arr[0]), cmp);
//	ll sum = 0;
//	for (ll i = n - 1;i >= 0;i--)
//	{
//		while (k > 0 && arr[i].a <= 0)
//		{
//			k--;
//			arr[i].a += arr[i].c;
//		}
//		if (arr[i].a > 0)
//			sum++;
//	}
//	cout << sum;
//	return 0;
//}



//typedef struct
//{
//	ll x, y;
//}node;
//ll n, k;
//vector<node>vec;
//bool cmp(node e1, node e2)
//{
//	if (e1.x == e2.x)
//	{
//		return e1.y < e2.y;
//	}
//	return e1.x < e2.x;
//}
//
//int main()
//{
//	cin >> n >> k;
//	for (int i = 0;i < k;i++)
//	{
//		ll x, y;
//		cin >> x >> y;
//		vec.push_back({ x,y });
//	}
//	sort(vec.begin(), vec.end(), cmp);
//	for (int i = 0;i < k;i++)
//	{
//		if ()
//	}
//	return 0;
//}


//void fun(char* a)
//{
//	if (*a >= 'A' && *a <= 'Z')
//		*a += 'a' - 'A';
//	while (*a++)
//	{
//		if (*a >= 'A' && *a <= 'Z')
//			*a += 'a' - 'A';
//	}
//}
//
//int fun2(char* a, char* b)
//{
//	int s = 0,al = strlen(a),bl = strlen(b);
//	for (int i = 0,j = 0;i <= al;i++)
//	{
//		if (a[i] == b[j])
//		{
//			for (i++, j++;i <= al && j <= bl;i++, j++)
//				if (!b[j]) {
//					s++, j = 0;break;
//				}
//		}
//	}
//	return s;
//}
//
//
//int main()
//{
//	char a[200],b[200];
//	cin.getline(a, 200);
//	cin.getline(b, 200);
//	cout << fun2(a, b);
//	return 0;
//}

//typedef long long ll;
//
//int main()
//{
//	ll t;
//	cin >> t;
//	while (t--)
//	{
//		ll a, b, k;
//		cin >> a >> b >> k;
//		ll t1 = max(a, b), t2 = min(a, b), t3 = t1 % t2;
//		while (t3 = t1 % t2)
//		{
//			t1 = max(t2, t3);
//			t2 = min(t2, t3);
//		}
//		ll s1 = k / a, s2 = k / b;
//		cout << s1 + s2 - k / ((a * b) / t2);
//		if (t)
//			cout << endl;
//	}
//	return 0;
//}



//int main()
//{
//	int n,a = 0,b = 0;
//	cin >> n;
//	while (n--)
//	{
//		long long t;
//		cin >> t;
//		if (t % 2 == 0)
//			a++;
//		else
//			b++;
//	}
//	cout << min(a , b);
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n,s = 0;
//		cin >> n;
//		stack<int>que;
//		while (n--)
//		{
//			int tmp;
//			cin >> tmp;
//			while(!que.empty() && que.top() > tmp)
//			{
//				s++;
//				que.pop();
//			}
//			que.push(tmp);
//		}
//		cout << s << endl;
//	}
//	return 0;
//}


//typedef long long ll;
//int arr[10] = {}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		ll n, m;
//		cin >> n >> m;
//		2+4+6+8+2+4
//	}
//	return 0;
//}



//int a[50];
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	for (int i = 0;i < n;i++)
//		cin >> a[i];
//	sort(a, a + n);
//	int min = -1;
//	for (int i = 0;i <= n-k;i++)
//	{
//		int s = 0,c = 1;【
//		for (int j = i + 1;j < n&&c < k;j++)
//		{
//			int tmp = a[j];
//			while (tmp > a[i])
//			{
//				tmp /= 2;
//				s++;
//			}
//			if (tmp == a[i])
//				c++;
//		}
//		if (s < min || min == -1)
//			min = s;
//	}
//	cout << min;
//	return 0;
//}


// typedef long long ll;
// int t[10] = { 0,10,5,10,5,2,5,10,5,10 };
// int t2[10] = { 0,45,20,45,20,5,20,45,20,45 };
// int main()
// {
// 	int q;
// 	cin >> q;
// 	while (q--)
// 	{
// 		ll n, m;
// 		cin >> n >> m;
// 		ll num = n / m;//满足的页数
// 		m %= 10;
// 		if(!m)
// 			cout << 0 << endl;
// 		else
// 		{
// 			ll sum = t2[m] * (num / t[m]);
// 			num %= t[m];
// 			for (int i = 0,j = 0;i < num;i++)
// 			{
// 				j += m;
// 				sum += j % 10;
// 			}
// 			cout << sum << endl;
// 		}
		
// 	}
// 	cout << "______________________";getchar();getchar();
// 	return 0;
// }




// typedef long long ll;

// int main()
// {
// 	int t;
// 	cin >> t;
// 	while(t--)
// 	{
// 		ll n,m;
// 		cin >> n >> m;

// 	}
// 	return 0;
// }


//typedef struct ndoe
//{
//	int num;
//	vector<int>vec;
//}node;
//node a[200002];
//
//bool cmp(node e1,node e2)
//{
//	return e1.num < e2.num;
//}
//
//int main()
//{
//	int n,k;
//	cin >> n >> k;
//	for(int i = 0;i < n;i++)
//	{
//		cin >> a[i].num;
//		int t = a[i].num;
//		while(t)
//		{
//			a[i].vec.push_back(t);
//			t /= 2;
//		}
//		a[i].vec.push_back(t);
//	}
//	sort(a,a+n,cmp);
//	map<int,pair<int,int> >s;
//	int min = 0x3f3f3f3f;
//	for (int i = 0;1;i++)
//	{
//		for (int j = 0;j < n;j++)
//		{
//			if (a[j].vec.size() > i)
//			{
//				int flag = a[j].vec[i];
//				if (s.find(flag) == s.end())
//					s.insert({ flag,{ 1,i } });
//				else
//				{
//					s[flag].first++;
//					s[flag].second += i;
//				}
//				if (s[flag].first == k && min > s[flag].second)
//					min = s[flag].second;
//				if (j == n - 1 && i == a[j].vec.size() - 1)
//				{
//					cout << min;
//					return 0;
//				}
//			}
//		}
//	}
//	return 0;
//}


//char tmpl[] = { 'a','b','c' };
//deque<char>ch;
//short times[300005] = { 0 };
//
//int main()
//{
//	int n;
//	int num[3];
//	cin >> n;getchar();
//	num[0] = num[1] = num[2] = n;
//	char a, b, c, d;
//	cin >> a >> b;getchar();
//	cin >> c >> d;
//	ch.push_back('c');
//	while (ch.size() < 3 * n)
//	{
//		char last = 0;
//		for (int i = 0;i < 3;i++)
//		{
//			if (num[i]>0 && (last != tmpl[i]||last==0) && (ch.size() == 0 || (ch.back() != a && tmpl[i] != b && ch.back() != c && tmpl[i] != d) || \
//				(ch.back() != a && tmpl[i] != b && ch.back() != c && tmpl[i] == d) || \
//				(ch.back() != a && tmpl[i] != b && ch.back() == c && tmpl[i] != d) || \
//				(ch.back() != a && tmpl[i] == b && ch.back() != c && tmpl[i] != d) || \
//				(ch.back() != a && tmpl[i] == b && ch.back() != c && tmpl[i] == d) || \
//				(ch.back() != a && tmpl[i] == b && ch.back() == c && tmpl[i] != d) || \
//				(ch.back() == a && tmpl[i] != b && ch.back() != c && tmpl[i] != d) || \
//				(ch.back() == a && tmpl[i] != b && ch.back() != c && tmpl[i] == d) || \
//				(ch.back() == a && tmpl[i] != b && ch.back() == c && tmpl[i] != d)))
//			{
//				ch.push_back(tmpl[i]);
//				num[i]--;
//				break;
//			}
//			if (i == 2)
//			{
//				if (ch.size() == 1)
//				{
//					cout << "NO";
//					return 0;
//				}
//				times[ch.size() - 1]++;
//				last = ch.back();
//				ch.pop_back();
//				num[last - 'a']++;
//				i = 0;
//			}
//			if (times[ch.size() - 1] > 2)
//			{
//				if (ch.size() == 1)
//				{
//					cout << "NO";
//					return 0;
//				}
//				times[ch.size() - 1]++;
//				ch.pop_back();
//				last = ch.back();
//				ch.pop_back();
//				num[last - 'a']++;
//				i = 0;
//			}
//		}
//	}
//	cout << "YES" << endl;
//	while (ch.size())
//	{
//		cout << ch.front();
//		ch.pop_front();
//	}
//	return 0;
//}



//int isc,c,v;
//int main()
//
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		string str;
//		cin >> str;
//		if (str == "CTRL")
//			isc = 1;
//		else if (str == "UNCTRL")
//			isc = 0;
//		else if (isc && str[0] == 'C')
//			c = 1;
//		else if (c == 1 && isc && str[0] == 'V')
//			v = 1;
//	}
//	if (v)
//		cout << "Yes";
//	else
//		cout << "No";
//	return 0;
//}

//int tim[121] = { 0 };
//inline void fun(int x, int y)
//{
//	for (x;x <= y;x++)
//		tim[x]++;
//}
//
//int main()
//{
//	int t, k;
//	cin >> t >> k;
//	while (t--)
//	{
//		int x, y;
//		cin >> x >> y;
//		fun(x, y);
//	}
//	int sum = 0,f = 0,a,b;
//	queue<pair<int, int>>que;
//	for (int i = 0;i <= 120;i++)
//	{
//		if (!f&&tim[i] < k)
//		{
//			f = 1;
//			a = i;
//		}
//		if (f && (tim[i] >= k||i==120))
//		{
//			f = 0;
//			sum++;
//			if (tim[i] >= k)
//				b = i-1;
//			else
//				b = i;
//			que.push({ a,b });
//		}
//	}
//	cout << sum << endl;
//	while (!que.empty())
//	{
//		a = que.front().first;
//		b = que.front().second;
//		cout << a << "-" << b << endl;
//		que.pop();
//	}
//	return 0;
//}




//	int a, b, c,sum = 0;
//int main()
//{
//	int s, t;
//	cin >> s >> t;
//	for (a; a + b + c <= s && a * b * c <= t;a++)
//		sum++;
//	a = 0;b = 0;c = 0;
//	for (a = 1;a<=s;a++)
//		for (b = a;a + b + c <= s && a * b * c <= t;b++)
//			sum++;
//	a = 0;b = 0;c = 0;
//	for (a = 1;a<=s;a++)
//		for (b = a;b<=s;b++)
//			for (c = b;a + b + c <= s && a * b * c <= t;c++)
//				sum++;
//	cout << sum;
//	return 0;
//}


//typedef long long ll;
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		ll n, k;cin >> n >> k;
//		cout << (ll)pow(n, (ll)pow(9, k)) % 10;
//	}
//	return 0;
//}



//typedef struct ndoe
//{
//	int num;
//	vector<int>vec;
//}node;
//node a[200002];
//
//bool cmp(node e1,node e2)
//{
//	return e1.num < e2.num;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for(int i = 0;i < n;i++)
//	{
//		cin >> a[i].num;
//		int t = a[i].num;
//		while(1)
//		{
//			a[i].vec.push_back(t);
//			if (t < 3)
//				break;
//			t /= 3;
//		}
//	}
//	sort(a,a+n,cmp);
//	map<int,pair<int,int> >s;
//	int min = 0x3f3f3f3f;
//	for (int i = 0;1;i++)
//	{
//		for (int j = 0;j < n;j++)
//		{
//			if (a[j].vec.size() > i)
//			{
//				int flag = a[j].vec[i];
//				if (s.find(flag) == s.end())
//					s.insert({ flag,{ 1,i } });
//				else
//				{
//					s[flag].first++;
//					s[flag].second += i;
//				}
//				if (s[flag].first == n && min > s[flag].second)
//					min = s[flag].second;
//				if (j == n - 1 && i == a[j].vec.size() - 1)
//				{
//					if (min == 0x3f3f3f3f)
//						cout << "Lose";
//					else
//						cout << min;
//					return 0;
//				}
//			}
//		}
//	}
//	return 0;
//}







//typedef long long ll;
//vector<ll>vec;
//
//int main()
//{
//	int n;
//	cin >> n;
//	ll sum = n;
//	while (n--)
//	{
//		ll t;
//		cin >> t;
//		vec.push_back(t);
//	}
//	sort(vec.begin(), vec.end());
//	map<double, int>mp;
//	for (int i = 1;i < vec.size();i++)
//	{
//		double q = vec[i] / vec[i - 1];
//		if (mp.find(q) == mp.end())
//			mp.insert({ q,1 });
//		else
//			mp[q]++;
//	}
//	double min = mp.begin()->first;
//	for (auto p = ++mp.begin();p != mp.end();p++)
//	{
//		double tmp = min;
//		int ci = 0;
//		for (tmp;tmp < p->first;tmp *= min)
//			ci++;
//		sum += ci * p->second;
//	}
//	cout << sum;
//	return 0;
//}




//int main()
//{
//	int n;
//	cin >> n;
//	switch (n%4)
//	{
//	case 0 : 
//	case 3:
//		cout << 0;
//		break;
//	default:
//		cout << 1;
//		break;
//	}
//	return 0;
//}


//int main()
//{
//	int n, x, y, s = 0;
//	cin >> n >> x >> y;
//	for (int i = 0;i < n;i++)
//	{
//		int t;
//		cin >> t;
//		if (t <= x)
//			s++;
//	}
//	if (s % 2 == 1)
//		s++;
//	if (x > y)
//		cout << n;
//	else
//		cout << s / 2;
//	return 0;
//}

//int num[3] = { 0 };
//int need[3] = { 0 };
//int main()
//{
//	int n,d;
//	cin >> n;
//	d = n / 3;
//	string str;
//	cin >> str;
//	for (int i = 0;i < n;i++)
//		num[str[i] - '0']++;
//	for (int i = 0;i < 3;i++)
//		need[i] = d - num[i];
//	for (int i = n-1;i >= 0;i--)
//	{
//		if (need[str[i] - '0'] < 0)
//		{
//				if (need[2] > 0)
//				{
//					need[str[i] - '0']++;
//					need[2]--;
//					str[i] = '2';
//				}
//		}
//	}
//	for (int i = 0;i < n;i++)
//	{
//		if (need[str[i] - '0'] < 0)
//		{
//				if (need[0] > 0)
//				{
//					need[str[i] - '0']++;
//					need[0]--;
//					str[i] = '0';
//				}
//		}
//	}
//	if (need[1] > 0)
//	{
//		for (int i = 0;i < n;i++)
//		{
//			if(str[i]=='2')
//			if (need[2] < 0)
//			{
//				if (need[1] > 0)
//				{
//					need[str[i] - '0']++;
//					need[1]--;
//					str[i] = '1';
//				}
//			}
//		}
//		for (int i = n - 1;i >= 0;i--)
//		{
//			if(str[i]=='0')
//			if (need[0] < 0)
//			{
//				if (need[1] > 0)
//				{
//					need[str[i] - '0']++;
//					need[1]--;
//					str[i] = '1';
//				}
//			}
//		}
//	}
//	cout << str;
//	return 0;
//}


//typedef struct
//{
//	int sum = 0;
//	set<int>color;
//}node;
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	map<int, int>mp;
//	map<int, set<int> >flag;
//	vector<int>num;
//	vector<int>col;
//	int maxtimes = 0;
//	for (int i = 0;i < n;i++)
//	{
//		int t;
//		cin >> t;
//		flag[t];
//		num.push_back(t);
//		if (mp.find(t) == mp.end())
//			mp[t] = 0;
//		mp[t]++;
//		if (mp[t] > maxtimes)
//			maxtimes = mp[t];
//	}
//	if (maxtimes > k)
//		cout << "NO";
//	else
//	{
//		//所有颜色先上一遍
//		for (int i = 1;i <= k;i++)
//		{
//			col.push_back(i);
//			flag[num[i - 1]].insert(i);
//		}
//
//		for (int i = k;i < n;i++)
//		{
//			for (int j = 1;j <= k;j++)
//			{
//				if (flag[num[i]].find(j)==flag[num[i]].end())
//				{
//					flag[num[i]].insert(j);
//					col.push_back(j);
//					break;
//				}
//			}
//		}
//
//		if (col.size() == n)
//		{
//			cout << "YES\n";
//			for (int i = 0;i < n;i++)
//			{
//				if (i)
//					cout << " ";
//				cout << col[i];
//			}
//		}
//		else
//			cout << "NO";
//	}
//	return 0;
//}


//typedef struct node
//{
//	int a;
//	struct node* p;
//}*        NODE;
//NODE p;
//
//int main()
//{
//	p = mal);
//	p->a = 1;
//	cout << p->a;
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char str[202] = { 0 };
//	scanf("%s", str);
//	int len = strlen(str);
//	for (int i = 0;i < len;i++)
//	{
//		if (str[i] == '-' && str[i + 1] > str[i - 1] && \
//			((str[i - 1] >= '0' && str[i + 1] >= '0' && str[i - 1] <= '9' && str[i + 1] <= '9') || \
//				(str[i - 1] >= 'a' && str[i + 1] >= 'a' && str[i - 1] <= 'z' && str[i + 1] <= 'z')))
//		{
//			for (char ch = str[i - 1] + 1;ch <= str[i + 1];ch++)
//				printf("%c",ch);
//			i++;
//		}
//		else
//			printf("%c",str[i]);
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, x;
//		cin >> n >> x;
//		if (n > 2)
//		{
//			int t;
//			n -= 2;
//			if (n % x == 0)
//				t = 1;
//			else
//				t = 2;
//			cout << t + (n / x) << endl;;
//		}
//		else
//			cout << 1 << endl;
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, m;
//		cin >> n >> m;
//		int jud = 0;
//		while (n--)
//		{
//			int a, b, c, d;
//			cin >> a >> b >> c >> d;
//			if (b == c)
//				jud = 1;
//		}
//		if (m % 2 != 0)
//			jud = 0;
//		if (jud)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int s = 0;
//		long long n;
//		cin >> n;
//		double t = round(sqrtl(n));
//		s += t - 1;
//		s += ceil(n / t)-1;
//		cout << s << endl;
//	}
//	return 0;
//}


//long long num[200002];
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> num[i];
//	}
//	long long sum = 0;
//	int q = -2, p = -1;
//	for (int i = 0;i < n - 1;i++)
//	{
//		long long tmp = num[i];
//		for (int j = i + 1;j < n;j++)
//		{
//			tmp += num[j];
//			if (!tmp)
//			{
//					sum++;
//				if (i >= p && p != -1)
//				{
//					sum--;
//					q = i;
//					p = j;
//				}
//				break;
//			}
//		}
//	}
//	cout << sum;
//	return 0;
//}

//1 -1 1




//typedef long long ll;
//ll a[200005] = {0};
//int main()
//{
//	int n;
//	cin >> n;
//	map<ll, ll>mp;
//	mp[0]++;
//	int sum = 0;
//	for (int i = 1;i <= n;i++)
//	{
//		cin >> a[i];
//		a[i] += a[i - 1];
//		if (mp[a[i]])
//		{
//			sum++;
//			mp.clear();
//		}
//		mp[a[i]]++;
//		mp[a[i - 1]]++;
//	}
//	cout << sum;
//	return 0;
//}


//char str[200005];
//int main()
//{
//	int len;
//	cin >> len;
//	cin >> str;
//	int sum = 0,a=0,b=0;
//	for (int i = 0;i < len;i++)
//	{
//		if (str[i] == 'a')
//			a++;
//		else
//			b++;
//		if ((i + 1) % 2 == 0)
//		{
//			if (a == 2)
//			{
//				sum++;
//				str[i] = 'b';
//			}
//			else if (b == 2)
//			{
//				sum++;
//				str[i] = 'a';
//			}
//			a = b = 0;
//		}
//	}
//	cout << sum << endl << str;
//	return 0;
//}

//
//multimap<int,int>arr;
//vector<int>b;
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//	{
//		int t;
//		cin >> t;
//		arr.insert({t,i});
//	}
//	long long sum = 0;
//	int x = 0;
//	for (auto p = arr.rbegin();p != arr.rend();p++, x++)
//	{
//		sum += (p->first * x) + 1;
//		b.push_back(p->second);
//	}
//	cout << sum << endl;
//	for (int i = 0;i < b.size();i++)
//		cout << b[i] << " ";
//	return 0;
//}


//int main()
//{
//	int x1, x2, y1, y2;
//	cin >> x1 >> y1 >> x2 >> y2;
//	int x3, x4, y3, y4;
//	cin >> x3 >> y3 >> x4 >> y4;
//	if ((y3 <= y1 && y4 >= y2) || (x3 <= x1 && x4 >= x2))
//	{
//		if (y3 <= y1 && y4 >= y2)
//		{
//			if (x3 <= x1 && x4 > x1)
//			{
//				x1 = min(x4,x2);
//			}
//			else if (x3 > x1 &&x3 < x2&& x4 >= x2)
//			{
//				x2 = x3;
//			}
//		}
//
//		if (x3 <= x1 && x4 >= x2)
//		{
//			if (y3 <= y1 && y4 > y1)
//			{
//				y1 = min(y4,y2);
//			}
//			else if (y3 > y1 && y3 < y2 && y4 >= y2)
//			{
//				y2 = y3;
//			}
//		}
//	}
//
//	cin >> x3 >> y3 >> x4 >> y4;
//	if ((y3 <= y1 && y4 >= y2) || (x3 <= x1 && x4 >= x2))
//	{
//		if (y3 <= y1 && y4 >= y2)
//		{
//			if (x3 <= x1 && x4 > x1)
//			{
//				x1 = min(x4, x2);
//			}
//			else if (x3 > x1 && x3 < x2 && x4 >= x2)
//			{
//				x2 = x3;
//			}
//		}
//
//		if (x3 <= x1 && x4 >= x2)
//		{
//			if (y3 <= y1 && y4 > y1)
//			{
//				y1 = min(y4, y2);
//			}
//			else if (y3 > y1 && y3 < y2 && y4 >= y2)
//			{
//				y2 = y3;
//			}
//		}
//	}
//
//	if (x1 == x2 || y1 == y2)
//		cout << "NO";
//	else
//		cout << "YES";
//	return 0;
//}


//typedef long long ll;
//map<ll, int>mp;
//map<ll, int>cha;
//int main()
//{
//	int n;
//	cin >> n;
//		ll t;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> t;
//		mp[t]++;
//	}
//	ll max = (--mp.end())->first;
//	for (auto p = mp.begin();p != mp.end();p++)
//	{
//		cha[max - p->first] = p->second;
//	}
//	ll flag= -1,flag2 = -1;
//	for (auto p = cha.begin();p != cha.end();p++)
//	{
//		if (p->first != 0)
//		{
//			flag = p->first;
//			if (p != --cha.end())
//				flag2 = (++p)->first;
//			break;
//		}
//	}
//	if (flag != -1)
//	{
//		if (flag2 != -1)
//		{
//			/*int jud = 0;
//			while (!jud)
//			{
//				auto p = cha.begin();
//				for (p = cha.begin();p != cha.end();p++)
//				{
//					if (p->first % flag != 0)
//						break;
//				}
//				if (p == cha.end())
//					jud = 1;
//				for (ll t = 2;!jud && t <= flag;t++)
//				{
//					if (flag % t == 0)
//					{
//						flag /= t;
//						break;
//					}
//				}
//			}*/
//			auto p = cha.find(flag2);
//			while (p != cha.end())
//			{
//				flag2 = p->first;
//				ll c = flag2 % flag;
//				while (c)
//				{
//					flag2 = flag > c ? flag : c;
//					flag = flag < c ? flag : c;
//					c = flag2 % flag;
//				}
//				p++;
//			}
//		}
//		ll sum = 0;
//		for (auto p = mp.begin();p != mp.end();p++)
//		{
//			sum += p->second * (max - p->first) / flag;
//		}
//		cout << sum << " " << flag;
//	}
//	else
//		cout << "0 0";
//	return 0;
//}



//typedef long long ll;
//int main()
//{
//	int q;
//	cin >> q;
//	while (q--)
//	{
//		ll s;
//		cin >> s;
//		double t = (pow((1 + 8 * s), 0.5) - 1.0) / 2.0, t1 = ceil(t), t2 = floor(t);
//		if (t1 == t)
//			cout << t << endl;
//		else
//		{
//			ll tmp = t2,st2 = t2 + (t2*t2-t2)/2.0,delt = s-st2;
//			cout << delt << endl;;
//		}
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		getchar();
//		int x1, x2, x3, y1, y2, y3;
//		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
//		int sum = 0;
//		sum += abs(x1 - x2) + abs(y1 - y2);
//		if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3))
//		{
//			if (((y3 > y1 && y3 < y2) || (y3 > y2 && y3 < y1)) || ((x3 > x1 && x3 < x2) || (x3 > x2 && x3 < x1)))
//				sum += 2;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int ret = 1;
//		char str[30] = { 0 };
//		cin >> str;
//		char tmpl = 'a' + strlen(str) - 1;
//		for (int q = 0, p = strlen(str)-1;ret&&tmpl>='a';tmpl--)
//		{
//			if (str[q] == tmpl)
//				q++;
//			else if (str[p] == tmpl)
//				p--;
//			else
//				ret = 0;
//		}
//		if (ret)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//	return 0;
//}
//int main()
//{
//	int a = 1e2;
//	int x = 3;
//	cout << (3 <= x < 10 < 2);
//	return 0;
// }



//int main()
//{
//	/*FILE* fp = fopen("new文件", "w");
//	if (fp == NULL)
//	{
//		perror("new文件");
//		return 1;
//	}
//
//	fclose(fp);
//	fp = NULL;*/
//
//
//
//
//	int ret = fgetc(stdin);
//	fputc(ret, stdout);
//	printf("ccscasda");
//	ret = fgetc(stdout);
//	printf("\n\n%c", ret);
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int a, b, c, d, e, f;
//		getchar();
//		cin >> a >> b >> c >> d >> e >> f;
//		if ((b == d || b == f || d == f) && (a == c || a == e || c == e))
//			cout << "NO\n";
//		else
//			cout << "YES\n";
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int jud = 0;
//		vector<int>vec;
//		while (n--)
//		{
//			int tmp;
//			cin >> tmp;
//			vec.push_back(tmp);
//		}
//		sort(vec.begin(), vec.end());
//		if (vec.size() == 1 && vec[0] == 1)
//			cout << "YES\n";
//		else if (vec.size() == 1)
//			cout << "NO\n";
//		else if (vec[vec.size() - 1] - vec[vec.size() - 2] <= 1)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//	return 0;
//}


//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		vector<int>vec;
//		int q0 = -1, p0 = -1, f1 = -1, f2 = -1, fs = 0, zs = 0;
//		for (int i = 1;i <= n;i++)
//		{
//			int tmp;
//			cin >> tmp;
//			vec.push_back(tmp);
//			if (tmp == 0)
//			{
//				if (q0 == -1)
//					q0 = i;
//				else
//					p0 = i;
//			}
//			else if (tmp < 0)
//			{
//				fs++;
//				if (f1 == -1)
//					f1 = i;
//				else
//					f2 = i;
//			}
//			else if (tmp > 0)
//				zs++;
//		}
//		if (n == 1 && vec[0] <= 0)
//			cout << "1 0\n";
//		else if (n == 1)
//			cout << "0 0\n";
//		else
//		{
//			int x = 0, y = 0;
//
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	getchar();
//	while (t--)
//	{
//		char tmp;
//		int sum = 0;
//		set<char>s;
//		while (tmp = getchar())
//		{
//			if (tmp == '\n')
//				break;
//			if (s.find(tmp) != s.end())
//			{
//				sum += s.size() - 1;
//				s.clear();
//			}
//			else
//				s.insert(tmp);
//		}
//		sum += s.size();
//		cout << sum << endl;
//	}
//	return 0;
//}


//typedef struct
//{
//	int q, p, j,x,y;
//}node;
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n,tmp;
//		cin >> n;
//		vector<int>vec;
//		vector<node>vec2;
//		int q = -1, p = -1;
//		for(int i = 0;i < n;i++)
//		{
//			cin >> tmp;
//			vec.push_back(tmp);
//			if (q == -1 && tmp != 0)
//				q = i;
//			if (q!=-1&&(tmp == 0||i == n-1))
//			{
//				p = i - 1;
//				if (tmp != 0)
//					p++;
//				vec2.push_back({ q,p,1,q,n - 1 - p });
//				q = -1;
//			}
//		}
//		if (vec2.size() == 0)
//			cout << n << " " << 0 << endl;
//		else
//		{
//			int m = 0;
//			for (int i = 0;i < vec2.size();i++)
//			{
//				int j1 = 1;
//				for (int j = vec2[i].q;j <= vec2[i].p;j++)
//				{
//					j1 *= vec[j];
//				}
//				if (j1 > 0)
//					vec2[i].j = j1;
//				else
//				{
//					int j2 = j1, j3 = j1, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
//					for (int j = vec2[i].q;j <= vec2[i].p;j++)
//					{
//						j2 /= vec[j];
//						if (j2 > 0)
//						{
//							x1 = j + 1;
//							y1 = n - 1 - vec2[i].p;
//							break;
//						}
//					}
//					for (int j = vec2[i].p;j >= vec2[i].q;j--)
//					{
//						j3 /= vec[j];
//						if (j3 > 0)
//						{
//							y2 = n - j;
//							x2 = vec2[i].q;
//							break;
//						}
//					}
//					if (j2 > j3)
//						vec2[i].j = j2, vec2[i].x = x1, vec2[i].y = y1;
//					else
//						vec2[i].j = j3, vec2[i].x = x2, vec2[i].y = y2;
//				}
//
//				if (vec2[i].j > vec2[m].j)
//					m = i;
//			}
//
//			cout << vec2[m].x << " " << vec2[m].y << endl;
//		}
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, m;
//		cin >> n >> m;
//		if (n > 1)
//		{
//			if (n > 2)
//				cout << 2 * m << endl;
//			else
//				cout << m << endl;
//		}
//		else
//			cout << "0\n";
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, k;
//		cin >> n >> k;
//		vector<int>a;
//		vector<int>b;
//		a.resize(n);
//		b.resize(n);
//		for (int i = 0;i < n;i++)
//			cin >> a[i];
//		for (int i = 0;i < n;i++)
//			cin >> b[i];
//		sort(a.begin(), a.end());
//		sort(b.begin(), b.end());
//		for (int i = 0, j = n - 1, c = 0;c < k;c++)
//		{
//			if (b[j] > a[i])
//			{
//				a[i] = b[j];
//				i++, j--;
//			}
//		}
//		int sum = 0;
//		for (int i = 0;i < n;i++)
//		{
//			sum += a[i];
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}

//typedef unsigned long long ll;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		ll sum = 0;
//		ll n;
//		cin >> n;
//		ll m = (1+n) / 2;
//		for (ll i = n;i > m;i--)
//		{
//			ll l1 = (i - m) * 2 + 1, l2 = l1 - 2;
//			sum += ((l1 * 2) + (l2 * 2)) * (i - m);
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}



//int main()
//{
//	int sum = 0;
//	for (int i = 0;i < 2e10;i++)
//		sum++;
//	cout << sum;
//	return 0;
//}



//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, k, sum = 0;
//		char tmp;
//		cin >> n >> k;
//		queue<pair<int,int>>que;
//		int f = 0;
//		getchar();
//		while (n--)
//		{
//			tmp = getchar();
//			que.push({ tmp - '0',0 });
//			if (que.size() < k+1)
//			{
//				if (que.back().first == 1)
//				{
//					if (f)
//					{
//						que.back().first = 0;
//						sum++;
//					}
//					else
//						f = 1;
//				}
//			}
//			else
//			{
//				if (que.front().first == 1)
//				{
//					if(que.back().first == 1)
//						que.front().second = que.back().second = 1;
//					else if(que.front().second == 0)
//						sum++;
//				}
//				if (que.back().first == 1)
//				{
//					if(que.f)
//				}
//				que.pop();
//			}
//		}
//		
//		cout << sum << endl;
//	}
//	return 0;
//}



//int main()
//{
//	priority_queue<int>q;
//	q.push(2);
//	q.push(5);
//	q.push(3);
//	q.push(5);
//	while (!q.empty())
//	{
//		cout << q.top() << endl;
//		q.pop();
//	}
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//typedef struct
//{
//	char name[22];
//	int sum;
//	int jud;
//}stu;
//
//int cmp(stu e1, stu e2)
//{
//	if (e1.sum == e2.sum)
//	{
//		return strcmp(e1.name, e2.name) < 0 ? 1 : 0;
//	}
//	return e1.sum > e2.sum;
//}
//
//int main()
//{
//	int n, m, g;
//	while (cin >> n)
//	{
//		if (!n)
//			return 0;
//		cin >> m >> g;
//		int sum = 0;
//		int fs[11] = {0};
//		for (int i = 1;i <= m;i++)
//			cin >> fs[i];
//		vector<stu>s(n);
//		for (int i = 0;i < n;i++)
//		{
//			int cnt;
//			cin >> s[i].name >> cnt;
//			for (int j = 0;j < cnt;j++)
//			{
//				int t;
//				cin >> t;
//				s[i].sum += fs[t];
//				if (s[i].sum >= g)
//					s[i].jud = 1;
//			}
//			if (!s[i].jud)
//				s.erase(s.begin() + i), i--, n--;
//			else
//				sum++;
//		}
//		cout << sum << endl;
//		sort(s.begin(), s.end(), cmp);
//		for (int i = 0;i < s.size(); i++)
//			cout << s[i].name << " " << s[i].sum << endl;
//	}
//	return 0;
//}


//int main()
//{
//	cout << (int)strcmp("cs0001", "cs0008") > 0?1:0;
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		string mod;
//		int n;
//		cin >> n >> mod;
//		if (mod == "FIFO")
//		{
//			queue<int>que;
//			while (n--)
//			{
//				int tmp;
//				string mov;
//				cin >> mov;
//				if (mov == "IN")
//				{
//					cin >> tmp;
//					que.push(tmp);
//				}
//				else
//				{
//					if (que.empty())
//						cout << "None\n";
//					else
//					{
//						cout << que.front() << endl;
//						que.pop();
//					}
//				}
//			}
//		}
//		else
//		{
//			stack<int>que;
//			while (n--)
//			{
//				int tmp;
//				string mov;
//				cin >> mov;
//				if (mov == "IN")
//				{
//					cin >> tmp;
//					que.push(tmp);
//				}
//				else
//				{
//					if (que.empty())
//						cout << "None\n";
//					else
//					{
//						cout << que.top() << endl;
//						que.pop();
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	map<string,int>s;
//	while (n--)
//	{
//		string t;
//		cin >> t;
//		if (!s[t])
//		{
//			cout << "OK\n";
//			s[t]++;
//		}
//		else
//		{
//			cout << t << s[t] << endl;
//			s[t]++;
//		}
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int n, cnt = 0;
//	long long sum = 0;
//	cin >> n;
//	multiset<int>s;
//	while (n--)
//	{
//		int t;
//		cin >> t;
//		if (t >= 0)
//			sum += t, cnt++;
//		else
//			s.insert(-t);
//	}
//	auto p = s.begin();
//	while (!s.empty())
//	{
//		if (sum - *p >= 0)
//		{
//			sum -= *p, cnt++;
//			p++;
//		}
//		else
//			break;
//		if (p == s.end())
//			break;
//	}
//	cout << cnt;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int n, cnt = 0, sum = 0;
//	vector<int>num;
//	cin >> n;
//	while (n--)
//	{
//		int t;
//		cin >> t;
//		if (sum + t >= 0)
//		{
//			sum += t;
//			cnt++;
//		}
//	}
//	cout << cnt;
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//struct stu
//{
//	int sum;
//	string id;
//};
//int cmp(stu e1, stu e2)
//{
//	if (e1.sum == e2.sum)
//		return e1.id < e2.id;
//	return e1.sum > e2.sum;
//}
//
//int main()
//{
//	int n,m,g,fs[11];
//	while (cin >> n, n)
//	{
//		int ret = 0;
//		cin >> m >> g;
//		for (int i = 1;i <= m;i++)
//			cin >> fs[i];
//		vector<stu>s(n);
//		for (int i = 0;i < n;i++)
//		{
//			cin >> s[i].id;
//			int cnt;
//			cin >> cnt;
//			while (cnt--)
//			{
//				int tmp;
//				cin >> tmp;
//				s[i].sum += fs[tmp];
//			}
//			if (s[i].sum >= g)
//				ret++;
//			else
//				s.erase(s.begin() + i), i--, n--;
//		}
//		sort(s.begin(), s.end(),cmp);
//		cout << ret << endl;
//		for (int i = 0;i < n;i++)
//			cout << s[i].id << " " << s[i].sum << endl;
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	long long s = 0;
//	int n,cnt = 0;
//	cin >> n;
//	cnt = n;
//	priority_queue<int>que;
//	while (n--)
//	{
//		int t;
//		cin >> t;
//		s += t;
//		if (t < 0)
//			que.push(-t);
//		while (s < 0)
//		{
//			s += que.top();
//			que.pop();
//			cnt--;
//		}
//	}
//	cout << cnt;
//	return 0;
//}


//int main()
//{
//	priority_queue<int>que;
//	que.push(-3);
//	que.push(1);
//	que.push(-8);
//	que.push(4);
//	cout << que.top();
//	que.pop();
//	cout << endl << que.top();
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	string str;
//	cin >> str;
//	for (int i = 0;i < str.size()-1;i++)
//	{
//		if (str[i] == str[i + 1])
//		{
//			str.erase(str.begin() + i);
//			str.erase(str.begin() + i);
//		}
//	}
//	return 0;
//}


//typedef long long ll;
//ll fast_pow(ll a, ll b, ll c)
//{
//	ll ret = 1;
//	while (b)
//	{
//		if (b & 1) ret *= a % c;
//		a *= a % c;
//		b >>= 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	ll a, b , c;
//	cin >> a >> b >> c;
//	cout << fast_pow(a, b, c);
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int pre[500010] = { 0 };
//
//int main()
//{
//	int t,n;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d", &n);
//		map<int, int>num;
//		num[0]++;
//		for (int i = 1;i <= n;i++)
//		{
//			scanf("%d", &pre[i]);
//			pre[i] += pre[i - 1];
//			num[pre[i]]++;
//		}
//		int sum = 0;
//		int i = 0,len = num.size();
//		int tmp;
//		for (auto p = num.begin();i < len;p++,i++)
//		{
//			tmp = p->first - 7777;
//			sum += num[tmp]*p->second;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}







//#include<bits/stdc++.h>
//using namespace std;
//typedef unsigned long long ll;
//ll fastpow(double a, ll b, ll c)
//{
//	ll ans = 1;
//	while (b)
//	{
//		while (a >= c)
//			a -= c;
//		if (b & 1) ans *= a;
//		a *= a;
//		b >>= 1;
//	}
//	ans %= c;
//	return ans;
//}
//
//int main()
//{
//	ll n, a, b, c, k;
//	bool mod;
//	cin >> n;
//	while (n--)
//	{
//		cin >> a >> b >> c >> k;
//		if (a - b == b - c)
//			mod = true;
//		else
//			mod = false;
//		if (mod)
//		{
//			ll d = b - a;
//			a %= 200907;
//			a += (k - 1) * (d % 200907);
//			a %= 200907;
//			cout << a << endl;
//		}
//		else
//		{
//			double q = (double)b / (double)a;
//			a %= 200907;
//			cout << (a * fastpow(q, (k - 1), 200907)) % 200907 << endl;
//		}
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef unsigned long long ll;
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		ll n, m,s = 0,tmp;
//		map<ll, int>num;
//		ll one;
//		cin >> n >> m;
//		for (int i = 0;i < m;i++)
//		{
//			cin >> t;
//			if (t & 1)
//				one++;
//			else
//				num[t]++;
//			s += t;
//		}
//		if (s < n)
//			cout << -1 << endl;
//		else if (s == n)
//			cout << 0 << endl;
//		else
//		{
//			for (auto p = num.begin();p != num.end();)
//			{
//				if (p->first <= n)
//				{
//					n -= p->first;
//					p->second--;
//					if (!p->second)
//						num.erase(p);
//				}
//				else
//					break;
//			}
//			for(auto p = num.begin();p != num.end)
//		}
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int jud = 1;
//		int n,a = 0;
//		cin >> n;getchar();
//		while (n--)
//		{
//			char c;
//			c = getchar();
//			if (c == '(')
//				a++;
//			else if (c == ')')
//				a--;
//			if (a < 0)
//				jud = 0;
//		}
//		if (a)
//			jud = 0;
//		if (jud)
//			cout << "Yes\n";
//		else
//			cout << "No\n";
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef unsigned long long ll;
//
//int main()
//{
//	int t,one;
//	ll n, m,tmp,sum;
//	scanf("%d", &t);
//	while (t--)
//	{
//		sum = one = 0;
//		scanf("%llu %llu", &n, &m);
//		vector<ll>que;
//		while (m--)
//		{
//			scanf("%llu", &tmp);
//			sum += tmp;
//			if (tmp == 1)
//				one++;
//			else
//				que.push_back(tmp);
//		}
//		if (sum < n)
//			puts("-1");
//		else if (sum == n)
//			puts("0");
//		else
//		{
//			sort(que.begin(), que.end(),greater<ll>());
//			if (n & 1 && one)
//				n--, one--;
//			for (int i = 0;i < que.size();i++)
//			{
//				if (que[i] <= n)
//					n -= que[i], que.erase(que.begin()+i),i--;
//			}
//			if (n <= one)
//				puts("0");
//			else
//			{
//				ll cnt = 0;
//				if (n & 1)
//				{
//					while (que.back() != 1)
//					{
//						que.back() >>= 1;
//						cnt++;
//					}
//					printf("%llu\n", cnt);
//				}
//				else
//				{
//					while (n)
//					{
//						que.back() >>= 1;
//						cnt++;
//						if (que.back() <= n)
//							n -= que.back();
//						if (n <= one)
//							n = 0;
//					}
//					printf("%llu\n", cnt);
//				}
//			}
//		}
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll cnt(ll tmp)
//{
//	ll ret = 0;
//	while (tmp>0)
//	{
//		if (tmp & 1)
//			ret++;
//		tmp >>= 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	ll n, p;
//	cin >> n >> p;
//	for (ll i = 1;i <= 64;i++)
//	{
//		ll tmp = n - p * i;
//		if (tmp >= i && cnt(tmp) <= i && cnt(tmp))
//		{
//			cout << i;
//			return 0;
//		}
//	}
//	cout << -1;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//unsigned int rmq[100010][30] = { 0 };
//unsigned int num[100001] = { 0 };
////int lg[]
//inline int Fun(int a)
//{
//	int ret = -1;
//	while (a)
//	{
//		a >>= 1;
//		ret++;
//	}
//	return ret;
//}
//int main()
//{
//	int n, m, ma = 0;
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++)
//	{
//		cin >> num[i];
//		rmq[i - 1][0] = max(num[i], num[i - 1]);
//		for (int j = i-2;j > 0;j--)
//		{
//			rmq[j][Fun(i - j)] = ;
//		}
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//struct store
//{
//	double j,f,s;
//};
//store sto[1010];
//int cmp(store e1, store e2)
//{
//	return e1.s > e2.s;
//}
//int main()
//{
//	double n, m;
//	int n2;
//	while (scanf("%lf %lf", &m, &n), (m != -1 || n != -1))
//	{
//		n2 = n;
//		for (int i = 0;i < n2;i++)
//		{
//			scanf("%lf %lf", &sto[i].j, &sto[i].f);
//			sto[i].s = sto[i].j / sto[i].f;
//		}
//		sort(sto, sto + n2, cmp);
//		double sum = 0;
//		for (int i = 0;i < n;i++)
//		{
//			double tmp = min(m , sto[i].f)*sto[i].s;
//			sum += tmp;
//			m -= tmp / sto[i].s;
//			if (m <= 0)
//				break;
//		}
//		printf("%.3lf\n", sum);
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//int s[10010] = { 0 };
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> s[i];
//	}
//	sort(s, s + n);
//	int sum = n;
//	for (int i = 0,j = n-1;i < n;i++)
//	{
//
//			int delt = m - s[i];
//			for (j;j > i;j--)
//			{
//				if (s[j] <= delt)
//				{
//					sum--;
//					j--;
//					break;
//				}
//			}
//		
//	}
//	cout << sum;
//	return 0;
//}




//int main()
//{
//	priority_queue<int,vector<int>,less<int> >que;
//	que.push(1);
//	que.push(2);
//	que.push(-5);
//	while (!que.empty())
//	{
//		cout << que.top() << endl;
//		que.pop();
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//
//struct tim
//{
//	int l,r;
//	bool operator <(const tim e)
//	{
//		return r < e.r;
//	}
//};
//tim ti[1010] = { 0 };
//int main()
//{
//	int  n;
//	while (cin >> n, n)
//	{
//		for(int i = 0;i < n;i++)
//		{
//			cin >> ti[i].l >> ti[i].r;
//		}
//		sort(ti, ti + n);
//		int cnt = 0;
//		priority_queue<int/*,vector<int>,greater<int> */>que;
//		for (int i = 0;i < n;i++)
//		{
//			if (que.empty() || ti[i].l >= que.top())
//			{
//				que.push(ti[i].r);
//				cnt++;
//			}
//		}
//		cout << cnt << endl;
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	priority_queue<int,vector<int>,greater<int>>que;
//	while (n--)
//	{
//		int m;
//		cin >> m;
//		que.push(m);
//	}
//	long long sum = 0;
//	while (que.size()!=1)
//	{
//		int tmp = que.top();
//		que.pop();
//		tmp += que.top();
//		que.pop();
//		que.push(tmp);
//		sum += que.top();
//	}
//	cout << sum;
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//struct node
//{
//	ll d, v;
//	bool operator <(const node e)
//	{
//		return d < e.d;
//	}
//};
//int main()
//{
//	int n;
//	ll sum = 0;
//	cin >> n;
//	map<ll, ll>mp;
//	priority_queue<node>que;
//	while (n--)
//	{
//		ll a, b;
//		cin >> a >> b;
//		if (que.empty())
//		{
//			que.push({ a,b });
//			sum += b;
//		}
//		else if (que.top().d > que.size() || b > que.top().d)
//		{
//			que.push({ a,b });
//			sum += b;
//		}
//		else
//	}
//	//set < ll >flag;
//	//multimap<ll, ll>mp2;
//	//for (auto p = mp.begin();p != mp.end();p++)
//	//{
//	//	if (flag.find(p->second) == flag.end())
//	//	{
//	//		sum -= p->first;
//	//		flag.insert(p->second);
//	//		mp2.insert({ p->first,p->second });
//	//	}
//	//	else if()
//	//}
//	cout << sum;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//struct node
//{
//	ll d, v;
//	bool operator<(const node e) const
//	{
//		return this->v > e.v;
//	}
//};
//int cmp(node e1, node e2)
//{
//	return e1.d < e2.d;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<node>vec;
//	for(int i = 0;i < n;i++)
//	{
//		ll a, b;
//		cin >> a >> b;
//		vec.push_back({ a,b });
//	}
//	sort(vec.begin(), vec.end(), cmp);
//	priority_queue<node> que;
//	ll sum = 0;
//	for (int i = 0;i < n;i++)
//	{
//		if (vec[i].d > que.size())
//		{
//			sum += vec[i].v;
//			que.push(vec[i]);
//		}
//		else if(vec[i].v > que.top().v)
//		{
//			sum -= que.top().v;
//			sum += vec[i].v;
//			que.pop();
//			que.push(vec[i]);
//		}
//	}
//	cout << sum;
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//int count(int a)
//{
//	int ret = 0;
//	while (a)
//	{
//		ret++;
//		a >>= 1;
//	}
//	return ret;
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n,tmp;
//		long long sum = 0;
//		cin >> n;
//		map<int, int>m;
//		while (n--)
//		{
//			cin >> tmp;
//			sum += m[count(tmp)]++;
//		}
//		/*for (auto p = m.begin();p != m.end();p++)
//			if(p->second>1)sum += p->second * (p->second - 1) / 2;*/
//		cout << sum << endl;
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//
//int main()
//{
//	priority_queue<ll, vector<ll>, greater<ll>>que;
//	int n,tmp;
//	cin >> n;
//	while (n--)
//	{
//		cin >> tmp;
//		que.push(tmp);
//	}
//	ll sum = 0;
//	while (que.size() != 1)
//	{
//		ll now = que.top();
//		que.pop();
//		now += que.top();
//		que.pop();
//		sum += now;
//		que.push(now);
//	}
//	cout << sum;
//	return 0;
//}




//int main()
//{
//	long long sum = 0;
//	int n,t;
//	cin >> n;
//	priority_queue<int, vector<int>, greater<int>>que;
//	priority_queue<int>buy;
//	while (n--)
//	{
//		cin >> t;
//		if (que.empty() != 1 && t > que.top())
//			que.pop(), sum += t;
//		else
//			que.push(t), buy.push(t), sum -= t;
//	}
//	while (!que.empty())
//	{
//		sum += buy.top() - que.top();
//		buy.pop(), que.pop();
//	}
//	cout << sum;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;

//int main()
//{
//	long long sum = 0;
//	int n;
//	cin >> n;
//	vector<int>vec(n);
//	for (int i = 0;i < n;i++)
//		cin >> vec[i];
//	for (int i = 0;i < n-1;i++)
//	{
//		if (i < 0)i = 0;
//		if (vec[i] < vec[i + 1])
//		{
//			int j = i + 1;
//			while (j + 1 < n && vec[j + 1] > vec[j])j++;
//			sum += vec[j] - vec[i];
//			vec.erase(vec.begin() + i);
//			vec.erase(vec.begin() + j - 1);
//			i -= 2, n -= 2;
//			/*if (vec[j - 1] > vec[j])j--;
//			sum += vec[j] - vec[i];
//			vec.erase(vec.begin() + i);
//			vec.erase(vec.begin() + j - 1), n -= 2, i -= 2;*/
//		}
//	}
//	cout << sum;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//struct node
//{
//	int val, day;
//	bool operator<(const node e)const
//	{
//		return val < e.val;
//	}
//};
////int min
//vector<int>m(300010);
//int main()
//{
//	long long sum = 0;
//	int n;
//	cin >> n;
//	multimap<int, int>mp;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> m[i];
//		mp.insert({ m[i],i });
//	}
//	for (auto p = mp.rbegin();p != mp.rend();p++)
//	{
//		int min = 0;
//		for (int i = 0;i < p->second;i++)
//		{
//			if (m[i] < m[min])
//				min = i;
//		}
//		sum += p->first - m[min];
//		m.erase(m.begin()+min);
//		m.erase(m.begin() + (p->second - 1));
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;

//int main()
//{
//	long long sum = 0;
//	int n;
//	cin >> n;
//	priority_queue<int, vector<int>, greater<int>>que;
//	while (n--)
//	{
//		int num;
//		cin >> num;
//		if (que.empty() != 1 && que.top() < num)
//		{
//			sum += num - que.top();
//			que.pop();
//			que.push(num);
//		}
//		que.push(num);
//	}
//	cout << sum;
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//struct wall
//{
//	int l, r;
//};
//
//int main()
//{
//	int n,d;
//	cin >> n >> d;
//	multimap<int, int>mp;
//	while (n--)
//	{
//		int a, b;
//		cin >> a >> b;
//		mp.insert({ b,a });
//	}
//	int cnt = 0,p = 0;
//	for (auto pm = mp.begin();pm != mp.end();pm++)
//	{
//		if (p < pm->second)
//		{
//			cnt++;
//			p = pm->first + d - 1;
//		}
//	}
//	cout << cnt;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int stoe[50010] = { 0 };
//int L, N, M;
//bool check(int delt)
//{
//	int q = 0, p = 1, cnt = 0;
//	for (;q < p && p <= N;)
//	{
//		if (stoe[p] - stoe[q] < delt)
//			p++, cnt++;
//		else
//			q = p++;
//	}
//	if (L - stoe[q] < delt)
//		return false;
//	if (cnt <= M) return true;
//	return false;
//}
//
//int main()
//{
//	cin >> L >> N >> M;
//	int l = 1,r = L;
//	for (int i = 1;i <= N;i++)
//	{
//		cin >> stoe[i];
//		int d = stoe[i] - stoe[i - 1];
//		if (d < l || i == 1)
//			l = d;
//	}
//	int ans = l;
//	while (l <= r)
//	{
//		int mid = (l + r) / 2;
//		if (check(mid))
//		{
//			ans = mid;
//			l = mid+1;
//		}
//		else r = mid - 1;
//	}
//	cout << ans;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int n;
//double num[15] = { 0 };
//double f(double x)
//{
//	double ans = 0, tmp = 1;
//	for (int i = n;i >= 0;i--)
//	{
//		ans += tmp*num[i];
//		tmp *= x;
//	}
//	return ans;
//}
//int main()
//{
//	double r, l;
//	cin >> n >> l >> r;
//	for (int i = 0;i <= n;i++)
//		cin >> num[i];
//	int cnt = 1000;
//	while (cnt--)
//	{
//		double mid1 = (l + r) / 2,mid2 = mid1+1e-6;
//		if (f(mid1) < f(mid2)) l = mid2;
//		else  r = mid1;
//	}
//	cout << l;
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
////struct quest
////{
////	int v, t;
////	bool operator<(const quest e)const
////	{
////		if (t == e.t) return v > e.v;
////		return t < e.t;
////	}
////};
////vector<quest>que(200010);
//ll n,c,d;
//inline bool check(int mid)
//{
//	ll gain = 0;
//	int wind = mid - n + 1;
//	if (wind <= 0)
//	{
//		int cnt = 0;
//		for (int i = 0;cnt < d;cnt++, i++)
//		{
//			if (i > mid) i = 0;
//			gain += que[i].v;
//		}
//	}
//	else
//	{
//		int cnt = 0;
//		for (int i = 0;cnt < d;cnt++, i++)
//		{
//			if (i > wind+n-1) i = 0;
//			gain += que[i].v;
//		}
//	}
//	/*for (int i = 1;i <= d;i++)
//	{
//		if (i - que[0].t > mid)
//		{
//			int tmp = que[0].v;
//			gain += tmp;
//			que.pop();
//			que.push({ tmp,i });
//		}
//	}*/
//	if (gain >= c)return true;
//	return false;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> c >> d;
//		que.clear();
//		que.resize(200010);
//		for(int i = 0;i < n;i++)
//		{
//			cin >> que[i].v;
//			que[i].t = -d;
//		}
//		sort(que.begin(), que.end());
//		if (que[0].v > c)puts("Infinity");
//		else if (que[0].v * d < c)puts("Impossible");
//		else
//		{
//			int l = 0, r = d - 1,ans = -1,mid;
//			while (l <= r)
//			{
//				mid = (r + l) / 2;
//				if (check(mid)) ans = mid, l = mid + 1;
//				else r = mid - 1;
//			}
//			if (ans == -1) puts("Impossible");
//			else	cout << ans << '\n';
//		}
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll n, c, d;
//ll pre[200010] = { 0 };
//ll num[200010] = { 0 };
//inline bool check(ll mid)
//{
//	ll gain = 0;
//	ll delt = mid + (ll)1;
//	ll a = d / (delt), b = d - a * (delt);
//	if (delt > n) delt = n;
//	gain += pre[delt] * a + pre[b];
//	if (gain >= c)return true;
//	return false;
//}
//
//int main()
//{
//	ll t;
//	cin >> t;
//	while (t--)
//	{
//		memset(pre, 0, 200010 * sizeof(pre[0]));
//		memset(num, 0, 200010 * sizeof(num[0]));
//		cin >> n >> c >> d;
//		for (int i = 1;i <= n;i++) cin >> num[i];
//		sort(num+1,num+1+n,greater<ll>());
//		for (int i = 1;i <= n;i++) pre[i] = num[i] + pre[i - 1];
//		
//		if (num[1] >= c)puts("Infinity");
//		else if (num[1] * d < c)puts("Impossible");
//		else
//		{
//			ll l = 0, r = d - 1, ans = 0, mid;
//			while (l <= r)
//			{
//				mid = (r + l) / 2;
//				if (check(mid)) ans = mid, l = mid + 1;
//				else r = mid - 1;
//			}
//			cout << ans << '\n';
//		}
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll n, c, d;
//ll num[200010] = { 0 };
//ll pre[200010] = { 0 };
//bool check(ll mid);
//
//void solve()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> c >> d;
//		for (int i = 1;i <= n;i++)
//			cin >> num[i];
//		sort(num + 1, num + 1 + n,greater<ll>());
//		for (int i = 1;i <= n;i++)
//			pre[i] = num[i] + pre[i - 1];
//
//		if (num[1] * d < c)puts("Impossible");
//		else if (num[1] >= c) puts("Infinity");
//		else
//		{
//			ll l = 0, r = d - 1, ans = 0, mid = 0;
//			while (l <= r)
//			{
//				mid = (l + r) / 2;
//				if (check(mid)) ans = mid, l = mid + 1;
//				else r = mid - 1;
//			}
//			cout << ans << '\n';
//		}
//	}
//}
//
//bool check(ll mid)
//{
//	ll gain = 0,delt = mid +1,a = d / delt,b = d - a * delt;
//	delt = delt > n ? n : delt;
//	b = b > n ? n : b;
//	gain += a * pre[delt] + pre[b];
//	return gain >= c;
//}
//
//int main()
//{
//	solve();
//	return 0;
//}



//struct road
//{
//	int a, b, val;
//	bool operator<(const road e)const
//	{
//		return val > e.val;
//	}
//};
//int fa[110] = { 0 };
//void init(int m)
//{
//	for (int i = 0;i <= m;i++)fa[i] = i;
//}
//int find(int a)
//{
//	return a == fa[a] ? a : fa[a] = find(fa[a]);
//}
//void merg(int a, int b)
//{
//	int af = find(a);
//	int bf = find(b);
//	if (af != bf) fa[af] = bf;
//}
//
//int main()
//{
//	int n, m;
//	while (cin >> n >> m, n)
//	{
//			init(m);
//			int sum = 0, cnt = 0;
//			priority_queue<road>que;
//			for (int i = 0;i < n;i++)
//			{
//				int a, b, v;
//				cin >> a >> b >> v;
//				que.push({ a,b,v });
//			}
//			while (cnt < m - 1)
//			{
//				if (que.empty())
//				{
//					puts("?");
//					break;
//				}
//				int a = que.top().a, b = que.top().b;
//				if (find(a) != find(b))
//				{
//					merg(a, b);
//					sum += que.top().val;
//					cnt++;
//				}
//				que.pop();
//			}
//			if(cnt == m-1)
//				cout << sum << endl;
//	}
//	return 0;
//}




//int mp[110][110] = { 0 }, dis[110] = { 0 }, vis[110] = { 0 };
//void init()
//{
//	memset(dis, 0, sizeof(dis));
//	memset(vis, 0, sizeof(vis));
//	memset(mp, 0, sizeof(mp));
//}
//
//int main()
//{
//	int n, m;
//	while (cin >> n >> m, n)
//	{
//		init();
//		for (int i = 0, a, b, v;i < n;i++)
//		{
//			cin >> a >> b >> v;
//			mp[a][b] = mp[b][a] = v;
//		}
//		int ans = 0, cnt = 1;
//		dis[1] = 0, vis[1] = 1;
//		for (int i = 2;i <= m;i++)
//			if(mp[1][i])
//				dis[i] = mp[1][i];
//		while (cnt < m)
//		{
//			int mi = 0;
//			for (int i = 1;i <= m;i++)
//			{
//				if (vis[i])continue;
//				if (dis[i] && (mi == 0 || dis[i] < dis[mi]))
//					mi = i;
//			}
//			if (!mi)
//				break;
//			cnt++;
//			ans += dis[mi];
//			vis[mi] = 1;
//			for (int i = 1;i <= m;i++)
//			{
//				if (vis[i])continue;
//				if (!dis[i] || dis[i] > mp[mi][i])
//					dis[i] = mp[mi][i];
//			}
//		}
//		if (cnt == m)
//			cout << ans << endl;
//		else
//			puts("?");
//	}
//	return 0;
//}

//chemin