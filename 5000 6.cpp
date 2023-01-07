#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
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