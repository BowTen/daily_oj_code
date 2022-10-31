//#include<iostream>
//using namespace std;
//int jud(int n)
//{
//	int t = (int)sqrt((double)n);
//	for (int i = 2;i <= t;i++)
//		if (n % i == 0)
//			return 0;
//	return 1;
//}
//int main()
//{
//	for (int i = 100;i <= 200;i++)
//		if (jud(i))
//			cout << i << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
//		puts("YES");
//	else
//		puts("NO");
//	return 0;
//}



//#include<iostream>
//using namespace std;
//void fun(int* a, int* b)
//{
//	*a = *a ^ *b;
//	*b = *a ^ *b;
//	*a = *a ^ *b;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	fun(&a, &b);
//	cout << a << " " << b;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	while(cin >> n)
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1;j <= i;j++)
//			cout << i << "*" << j << "=" << i * j << " ";
//		puts("");
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//		if (n > 0)
//			puts("1");
//		else if (n == 0)
//			puts("0.5");
//		else
//			puts("0");
//	return 0;
//}



//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	cout << n / 3600 << " " << n % 3600 / 60 << " " << n % 60;
//	return 0;
//}




//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		while (n--)
//			cout << "*";
//		puts("");
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	for (int i = 0;i < 5;i++)
//	{
//		double a, b, c, d, e;
//		cin >> a >> b >> c >> d >> e;
//		cout << a << " " << b << " " << c << " " << d << " " << e;
//		printf(" %.1lf\n", (a + b + c + d + e));
//	}
//	return 0;
//}



//#include<iostream>
//#include<math.h>
//using namespace std;
//typedef long long lint;
//int main()
//{
//	lint a, da = 0, b, db = 0,i = 0,j = 0,sa = 0,sb = 0;
//	cin >> a >> da >> b >> db;
//	while (a)
//	{
//		if (a % 10 == da)
//		{
//			sa += (a % 10) * pow(10, i);
//			i++;
//		}
//		a /= 10;
//	}
//	while (b)
//	{
//		if (b % 10 == db)
//		{
//			sb += (b % 10) * pow(10, j);
//			j++;
//		}
//		b /= 10;
//	}
//	cout << sa + sb;
//	return 0;
//}



//#include<iostream>
//using namespace std;
//typedef struct stu
//{
//	char id[9];
//	int d, c, cla;
//}stu;
//stu arr[100010];
//int cmp(const void* e1, const void* e2)
//{
//	if ((*(stu*)e1).cla != (*(stu*)e2).cla)
//	{
//		return (*(stu*)e1).cla - (*(stu*)e2).cla;
//	}
//	else
//	{
//		if ((*(stu*)e2).c + (*(stu*)e2).d != (*(stu*)e1).c + (*(stu*)e1).d)
//			return (*(stu*)e2).c + (*(stu*)e2).d - (*(stu*)e1).c - (*(stu*)e1).d;
//		else if ((*(stu*)e2).d != (*(stu*)e1).d)
//			return (*(stu*)e2).d - (*(stu*)e1).d;
//		else
//			return atol((*(stu*)e1).id) - atol((*(stu*)e2).id);
//	}
//}
//int main()
//{
//	int n, l, h, count = 0;;
//	cin >> n >> l >> h;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> arr[i].id >> arr[i].d >> arr[i].c;
//		if (arr[i].c < l || arr[i].d < l)
//		{
//			arr[i].cla = 0;
//			count++;
//		}
//		else if (arr[i].c >= h && arr[i].d >= h)
//			arr[i].cla = 1;
//		else if (arr[i].d >= h && arr[i].c < h)
//			arr[i].cla = 2;
//		else if (arr[i].c < h && arr[i].d < h && arr[i].d >= arr[i].c)
//			arr[i].cla = 3;
//		else
//			arr[i].cla = 4;
//	}
//	cout << n - count << endl;
//	qsort(arr, n, sizeof(arr[0]), cmp);
//	for (int i = count;i < n;i++)
//	{
//		cout << arr[i].id << " " << arr[i].d << " " << arr[i].c << " " << arr[i].cla << endl;
//	}
//	return 0;
//}