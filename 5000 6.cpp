#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
using namespace std;

//int fa[1010];
//void init(int n)
//{
//	for (int i = 0;i <= n;i++)fa[i]=i;
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
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, m, cnt = 0;
//		cin >> n >> m;
//		init(n);
//		while (m--)
//		{
//			int a, b;
//			cin >> a >> b;
//			if (find(a) != find(b))
//				merg(a, b);
//		}
//		for (int i = 1;i <= n;i++)
//			if (i == fa[i])cnt++;
//		cout << cnt << endl;
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//vector<int>fa;
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
//	while (scanf("%d",&n), n)
//	{
//		fa.clear(), fa.resize(n+10);
//		for (int i = 1;i <= n;i++)
//			fa[i] = i;
//		scanf("%d", &m);
//		while (m--)
//		{
//			int a, b;
//			scanf("%d %d", &a, &b);
//			if (find(a) != find(b))
//				merg(a, b);
//		}
//		int cnt = 0;
//		for (int i = 1;i <= n;i++)
//			if (fa[i] == i)cnt++;
//		printf("%d\n", cnt-1);
//
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//struct road
//{
//	int a, b, val;
//	bool operator<(const road e)const
//	{
//		return val > e.val;
//	}
//};
//int fa[110] = { 0 };
//inline void init(int m)
//{
//	for (int i = 0;i <= m;i++)fa[i] = i;
//}
//inline int find(int a)
//{
//	return a == fa[a] ? a : fa[a] = find(fa[a]);
//}
//inline void merg(int a, int b)
//{
//	int af = find(a);
//	int bf = find(b);
//	if (af != bf) fa[af] = bf;
//}
//
//int main()
//{
//	int n, m;
//	while (scanf("%d",&n), n)
//	{
//		m = (n * (n - 1)) / 2;
//		init(n);
//		int sum = 0, cnt = 0;
//		priority_queue<road>que;
//		for (int i = 0;i < m;i++)
//		{
//			int a, b, v, f;
//			scanf("%d %d %d %d", &a, &b, &v, &f);
//			if(f && find(a) != find(b))
//				merg(a, b),cnt++;
//			else
//				que.push({ a,b,v });
//		}
//		while (cnt < n - 1)
//		{
//			if (que.empty())
//			{
//				puts("?");
//				break;
//			}
//			int a = que.top().a, b = que.top().b;
//			if (find(a) != find(b))
//			{
//				merg(a, b);
//				sum += que.top().val;
//				cnt++;
//			}
//			que.pop();
//		}
//		if (cnt == n - 1)
//			printf("%d\n", sum);
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//#include<iostream>
//
//using namespace std;
//
//int mp[105][105] = { 0 }, dis[105] = {0},vis[105] = {0};
//void init()
//{
//	memset(dis, 0, sizeof(dis));
//	memset(vis, 0, sizeof(vis));
//	memset(mp, 0, sizeof(mp));
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		init();
//		int n, m;
//		scanf("%d %d", &n, &m);
//		while (m--)
//		{
//			int a, b, v;
//			scanf("%d %d %d", &a, &b, &v);
//			mp[a][b] = mp[b][a] = v;
//		}
//		dis[1] = 0;
//		vis[1] = 1;
//		for (int i = 2;i <= n;i++)
//			if(mp[i][1])
//				dis[i] = mp[i][1];
//		int cnt = 1,ans = 0;
//		while (cnt < n)
//		{
//			int x = 0;
//			for (int i = 2;i <= n;i++)
//			{
//				if (vis[i])continue;
//				if (dis[i] && (x == 0 || dis[i] < dis[x]))
//					x = i;
//			}
//			vis[x] = 1;
//			cnt++;
//			ans += dis[x];
//			for (int i = 2;i <= n;i++)
//			{
//				if (vis[i] || mp[i][x]==0)continue;
//				if (dis[i] && dis[i] == mp[i][x])
//				{
//					puts("Not Unique!");
//					goto ss;
//				}
//				if (dis[i] == 0 || dis[i] > mp[i][x])
//					dis[i] = mp[i][x];
//			}
//		}
//		printf("%d\n", ans);
//	ss:;
//	}
//	return 0;
//}






//#include<iostream>
//using namespace std;
//int n, m;
//struct node
//{
//	int x, y;
//};
//node city[755] = { 0 };
//int mp[755][755] = { 0 }, vis[755] = { 0 };
//pair<int, int>dis[755];
//inline void updatedis(int a)
//{
//	for (int i = 1;i <= n;i++)
//	{
//		if (vis[i])continue;
//		if (mp[a][i] && (mp[a][i] < dis[i].first || !dis[i].first))
//		{
//			dis[i].first = mp[a][i], dis[i].second = a;
//		}
//	}
//}
//
//int main()
//{
//	memset(dis, 0, sizeof(dis));
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//		cin >> city[i].x >> city[i].y;
//	for (int i = 1;i <= (n + 1) >> 1;i++)
//		for (int j = 1;j <= n;j++)
//		{
//			int dx = city[i].x - city[j].x, dy = city[i].y - city[j].y;
//			mp[i][j] = mp[j][i] = pow((dx * dx) + (dy * dy), 0.5);
//		}
//	int cnt = 0;
//	cin >> m;
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (!vis[a])vis[a] = 1, updatedis(a), cnt++;
//		if (!vis[b])vis[b] = 1, updatedis(b), cnt++;
//	}
//	while (cnt < n)
//	{
//		int x = 0;
//		for (int i = 1;i <= n;i++)
//		{
//			if (vis[i])continue;
//			if (dis[i].first && (x == 0 || dis[x].first > dis[i].first))
//				x = i;
//		}
//		cout << dis[x].second << " " << x << endl;
//		cnt++;
//		vis[x] = 1;
//		updatedis(x);
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//#include<iostream>
//#include<queue>
//using namespace std;
//struct node
//{
//	int x, y;
//};
//node city[755] = { 0 };
//struct road
//{
//	int a, b, val;
//	bool operator<(const road e)const
//	{
//		return val > e.val;
//	}
//};
//int fa[755] = { 0 };
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
//	cin >> m;
//	for (int i = 1;i <= m;i++)
//	{
//		cin >> city[i].x >> city[i].y;
//	}
//	init(m);
//	int cnt = 0;
//	priority_queue<road>que;
//	for (int i = 1;i <= (m+1)>>1;i++)
//		for (int j = 1;j <= m;j++)
//		{
//			if (i == j)continue;
//			int dx = city[i].x - city[j].x, dy = city[i].y - city[j].y;
//			int v = pow((dx * dx) + (dy * dy), 0.5);
//			que.push({ i,j,v });
//		}
//	cin >> n;
//	while (n--)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (find(a) != find(b))
//		{
//			merg(a, b);
//			cnt++;
//		}
//	}
//	while (cnt < m - 1)
//	{
//		if (que.empty())
//		{
//			puts("?");
//			break;
//		}
//		int a = que.top().a, b = que.top().b;
//		if (find(a) != find(b))
//		{
//			cout << a << " " << b << endl;
//			merg(a, b);
//			cnt++;
//		}
//		que.pop();
//	}
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//char mp[10][10] = { 0 };
//int n, k, sum = 0, vis[10][10] = { 0 }, row[10],col[10];
//void search(int x,int cnt)
//{
//	if (cnt >= k)
//		sum++;
//	else
//	{
//		for (int i = x;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//			{
//				if (mp[i][j] == '#' && !vis[i][j] && !row[i] && !col[j])
//				{
//					row[i] = col[j] = vis[i][j] = 1;
//					search(i+1, cnt+1);
//					row[i] = col[j] = vis[i][j] = 0;
//				}
//			}
//	}
//}
//void init()
//{
//	sum = 0;
//	memset(mp, 0, sizeof(mp));
//	memset(vis, 0, sizeof(vis));
//	memset(row, 0, sizeof(row));
//	memset(col, 0, sizeof(col));
//}
//
//int main()
//{
//	while (cin >> n >> k, (n != -1 && k != -1))
//	{
//		init();
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//				cin >> mp[i][j];
//		search(1,0);
//		cout << sum << endl;
//	}
//	return 0;
//}





//#include<iostream>
//#include<queue>
//#include<stack>
//using namespace std;
//int mp[7][7] = { 0 }, vis[7][7] = { 0 };
//pair< int, int > fa[7][7];
//queue< pair<int, int> > que;
//
//int main()
//{
//	for (int j = 0;j <= 6;j++)mp[6][j] = mp[j][6] = mp[0][j] = mp[j][0] = 1;
//	for (int i = 1;i <= 5;i++)
//		for (int j = 1;j <= 5;j++)cin >> mp[i][j];
//	que.push({ 1,1 });
//	vis[1][1] = 1;
//	while (que.size())
//	{
//		int x = que.front().first, y = que.front().second;
//		que.pop();
//		for (int i = x - 1, j = y;i <= x + 1;i++)
//		{
//			if (!mp[i][j] && !vis[i][j])
//			{
//				que.push({ i,j });
//				vis[i][j] = 1;
//				fa[i - 1][j - 1] = { x - 1,y - 1 };
//				if (i == 5 && j == 5)
//					goto ss;
//			}
//		}
//		for (int j = y - 1, i = x;j <= y + 1;j++)
//		{
//			if (!mp[i][j] && !vis[i][j])
//			{
//				que.push({ i,j });
//				vis[i][j] = 1;
//				fa[i - 1][j - 1] = { x - 1,y - 1 };
//				if (i == 5 && j == 5)
//					goto ss;
//			}
//		}
//	}
//ss:;
//	int x = 4, y = 4;
//	stack< pair<int, int> > sta;
//	sta.push({ x,y });
//	while (x != 0 || y != 0)
//	{
//		pair<int, int>t = fa[x][y];
//		sta.push(t);
//		x = t.first, y = t.second;
//	}
//	while (sta.size())
//	{
//		printf("(%d, %d)\n", sta.top().first, sta.top().second);
//		sta.pop();
//	}
//	return 0;
//}




//#include<iostream>
//#include<queue>
//#include<stack>
//using namespace std;
//pair<int, int>tmpl[4];
//int mp[6][6] = { 0 };
//int vis[6][6] = { 0 };
//queue< pair<int,int> > que;
//pair<int, int>fa[6][6];
//
//int main()
//{
//	tmpl[0].first = 1, tmpl[0].second = 0;
//	tmpl[1].first = 0, tmpl[1].second = 1;
//	tmpl[2].first = -1, tmpl[2].second = 0;
//	tmpl[3].first = 0, tmpl[3].second = -1;
//	for (int i = 0;i < 5;i++)
//		for (int j = 0;j < 5;j++)
//			cin >> mp[i][j];
//	que.push( pair<int,int>(0,0) );
//	vis[0][0] = 1;
//	while (que.size())
//	{
//		pair<int, int> t = que.front();
//		que.pop();
//		for (int i = 0;i < 4;i++)
//		{
//			int a = t.first + tmpl[i].first, b = t.second + tmpl[i].second;
//			if (a >= 0 && a < 5 && b >= 0 && b < 5 && !vis[a][b] && mp[a][b] == 0)
//			{
//				fa[a][b] = t;
//				que.push(pair<int, int>(a, b));
//				vis[a][b] = 1;
//				if (a == 4 && b == 4)
//					goto ss;
//			}
//		}
//	}
//ss:;
//	stack< pair<int, int> >sta;
//	int x = 4, y = 4;
//	sta.push( pair<int, int>(4, 4) );
//	while (x != 0 || y != 0)
//	{
//		pair<int, int>t = fa[x][y];
//		sta.push(t);
//		x = t.first, y = t.second;
//	}
//	while (sta.size())
//	{
//		printf("(%d, %d)\n", sta.top().first, sta.top().second);
//		sta.pop();
//	}
//	return 0;
//}





//#include<iostream>
//#include<queue>
//using namespace std;
//struct node
//{
//	int z, x, y;
//	node(int a, int b, int c)
//	{
//		z = a, x = b, y = c;
//	}
//};
//char mp[31][31][31] = { 0 };
//char vis[31][31][31] = { 0 };
//
//void init()
//{
//	memset(mp, 0, sizeof(mp));
//	memset(vis, 0, sizeof(vis));
//}
//
//int main()
//{
//	int l, r, c;
//	while (cin >> l >> r >> c, l && r && c)
//	{
//		init();
//		int Z = 0, X = 0, Y = 0;
//		for (int i = 0;i < l;i++)
//		{
//			for (int x = 0;x < r;x++)
//				for (int y = 0;y < c;y++)
//				{
//					cin >> mp[i][x][y];
//					if (mp[i][x][y] == 'S')
//					{
//						Z = i, X = x, Y = y;
//					}
//				}
//			getchar();
//		}
//		int ans = -2;
//		queue< pair<node,int> >que;
//		que.push(make_pair(node(Z, X, Y), 0) );
//		vis[Z][X][Y] = 1;
//		while (que.size())
//		{
//			node tmp = que.front().first;
//			int cnt = que.front().second;
//			ans = cnt + 1;
//			que.pop();
//			for (int x = tmp.x - 1;x <= tmp.x + 1;x++)
//			{
//				if (x < 0 || x >= r)continue;
//				if (mp[tmp.z][x][tmp.y] == 'E')
//					goto ss;
//				if (mp[tmp.z][x][tmp.y] == '.' && !vis[tmp.z][x][tmp.y])
//				{
//					vis[tmp.z][x][tmp.y] = 1;
//					que.push( make_pair( node( tmp.z, x, tmp.y ),cnt+1) );
//				}
//			}
//			for (int y = tmp.y - 1;y <= tmp.y + 1;y++)
//			{
//				if (y < 0 || y >= c)continue;
//				if (mp[tmp.z][tmp.x][y] == 'E')
//					goto ss;
//				if (mp[tmp.z][tmp.x][y] == '.' && !vis[tmp.z][tmp.x][y])
//				{
//					vis[tmp.z][tmp.x][y] = 1;
//					que.push( make_pair( node( tmp.z, tmp.x, y ),cnt+1) );
//				}
//			}
//			for (int z = tmp.z - 1;z <= tmp.z + 1;z++)
//			{
//				if (z < 0 || z >= l)continue;
//				if (mp[z][tmp.x][tmp.y] == 'E')
//					goto ss;
//				if (mp[z][tmp.x][tmp.y] == '.' && !vis[z][tmp.x][tmp.y])
//				{
//					vis[z][tmp.x][tmp.y] = 1;
//					que.push( make_pair( node( z, tmp.x, tmp.y ),cnt+1) );
//				}
//			}
//		}
//		cout << "Trapped!\n";
//		continue;
//	ss:;
//		cout << "Escaped in " << ans << " minute(s).\n";
//
//	}
//	return 0;
//}




//#include<iostream>
//using namespace std;
//int fa[110] = { 0 };
//int find(int a)
//{
//	return a == fa[a] ? a : fa[a] = find(fa[a]);
//}
//void merg(int a, int b)
//{
//	int af = find(a);
//	int bf = find(b);
//	fa[af] = bf;
//}
//
//int main()
//{
//	for (int i = 1;i < 110;i++)fa[i] = i;
//	int n, m;
//	cin >> n >> m;
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (find(a) != find(b))
//			merg(a, b);
//	}
//	int ans = 0;
//	for (int i = 1;i <= n;i++)
//		if (fa[i] == i)ans++;
//	cout << ans;
//	return 0;
//}




#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
vector<int>sub[110];
int du[110] = {0},vis[110] = {0};
struct node
{
	int id, ti;
};
node tim[110] = { 0 };
bool cmp(node e1, node e2)
{
	return e1.ti < e2.ti;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		tim[i].id = i;
		int t;
		while (cin >> t, t)
		{
			sub[i].push_back(t);
			du[t]++;
		}
	}
	queue<int>que;
	for (int i = 1;i <= n;i++)
	{
		if (!du[i])
		{
			que.push(i);
			vis[i] = 1;
			tim[i].ti = 0;
		}
	}
	while (que.size())
	{
		int x = que.front();
		que.pop();
		for (int i = 0;i < sub[x].size();i++)
			du[sub[x][i]]--;
		for (int i = 0;i < sub[x].size();i++)
		{
			int t = sub[x][i];
			if (du[t] == 0 && vis[t] == 0)
			{
				que.push(t);
				vis[t] = 1;
				tim[t].ti = tim[x].ti + 1;
			}
		}
	}
	sort(tim + 1, tim + 1 + n,cmp);
	for (int i = 1;i <= n;i++)
		cout << tim[i].id << " ";
	return 0;
}