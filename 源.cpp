#include<iostream>
using namespace std;

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


//int fun(int n, int k);
//int main()
//{
//	int n,k;
//	cin >> n >> k;
//	printf("%d", fun(n, k));
//	return 0;
//}
//int fun(int n,int k)
//{
//	if (k == 1)
//		return n;
//	return n * fun(n, k - 1);
//}



//int DigitSum(int n);
//int main()
//{
//	int n;
//	cin >> n;
//	cout << DigitSum(n);
//	return 0;
//}
//int DigitSum(int n)
//{
//	if (n < 10)
//		return n;
//	return DigitSum(n / 10) + n % 10;
//}


//int fun(char* arr)
//{
//	int ret = 0;
//	while (*arr++)
//		ret++;
//	return ret;
//}
//int dfun(char* arr)
//{
//	if (*arr++)
//		return 1 + dfun(arr);
//}
//int main()
//{
//	char arr[20] = { 0 };
//	cin >> arr;
//	cout << "非递归：" << fun(arr) << endl;
//	cout << "递归：" << dfun(arr) << endl;
//	return 0;
//}


//void fun(int n)
//{
//	if (n)
//	{
//		fun(n / 10);
//		cout << n % 10 << " ";
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	fun(n);
//	return 0;
//}


//
//void printmune()
//{
//	system("cls");
//	cout << " ***************************" << endl;
//	cout << " ********* 1.Play **********" << endl;
//	cout << " ***************************" << endl;
//	cout << " ********* 0.Exit **********" << endl;
//	cout << " ***************************" << endl;
//}
//void game()
//{
//	int n = rand() % 10;
//	cout << "猜猜0到9的数字 >>";
//	int t;
//	while (cin >> t)
//	{
//		if (t == n)
//		{
//			cout << "恭喜你，猜对了！" << endl;
//			getchar();getchar();
//			break;
//		}
//		else if (t > n)
//			cout << "猜大了，再来 >>" << endl;
//		else
//			cout << "猜小了，再来 >>" << endl;
//	}
//}
//int main()
//{
//	srand((unsigned int)time);
//	while (1)
//	{
//		printmune();
//		int n;
//		while (cin >> n)
//		{
//			if (n == 1)
//			{
//				system("cls");
//				game();
//				break;
//			}
//			else if (n == 0)
//				return 0;
//			else
//				cout << "Errow" << endl;
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n,sum = 0;
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//	{
//		sum += i;
//	}
//	cout << sum;
//	return 0;
//}



//int main()
//{
//	long long n;
//	cin >> n;
//	cout << 4 * (n / 12) + 2;
//	return 0;
//}


//int main()
//{
//	for (int i = 1;i < 10;i++)
//	{
//		for (int j = 1;j <= i; j++)
//			cout << i << "*" << j << "=" << i * j << "  ";
//		puts("");
//	}
//	return 0;
//}



//int main()
//{
//	double a = 1.7777;
//	printf("%3lf", a);
//	return 0;
//}


//int main()
//{
//	cout << "请输入十个整数 >>";
//	int t, max = 0;
//	for (int i = 0;i < 10;i++)
//	{
//		cin >> t;
//		if (max < t || i == 0)
//			max = t;
//	}
//	cout << "最大的是 ->" << max;
//	return 0;
//}


//int main()
//{
//	double sum = 0;
//	for (int i = 1;i <= 100;i++)
//	{
//		if (i % 2 == 1)
//			sum += 1.0 / (double)i;
//		else
//			sum -= 1.0 / (double)i;
//	}
//	cout << sum;
//	return 0;
//}


//inline int count(int i)
//{
//	int ret = 0;
//	while (i)
//	{
//		if (i % 10 == 9)
//			ret++;
//		i /= 10;
//	}
//	return ret;
//}
//int main()
//{
//	int sum = 0;
//	for (int i = 1;i <= 100;i++)
//	{
//		sum += count(i);
//	}
//	cout << sum;
//	return 0;
//}



//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n;
//	cin >> n;
//	int q = 0, p = sizeof(arr) / sizeof(arr[0]) - 1;
//	int m;
//	for (m = (p + q) / 2;1; m = (p + q) / 2)
//	{
//		if (arr[m] > n)
//			p = m - 1;
//		else if (arr[m] < n)
//			q = m + 1;
//		else if(arr[m] == n)
//			break;
//		if (p < q)
//		{
//			m = -1;
//			break;
//		}
//	}
//	if (m != -1)
//		cout << m;
//	else
//		cout << "找不到";
//	return 0;
//}


//int main()
//{
//	double a = 0;
//	switch (1)
//	{
//	default:
//		break;
//	case 1:;
//	}
//	return 0;
//}



//int main()
//{
//	for (int i = 1;i <= 100;i++)
//	{
//		if (i % 3 == 0)
//			cout << i << endl;
//	}
//	return 0;
//}


//int main()
//{
//	int arr[3];
//	for (int i = 0;i < 3;i++)
//	{
//		cin >> arr[i];
//	}
//	for (int i = 0;i < 2;i++)
//	{
//		for (int j = 0;j < 2 - i;j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				arr[j] = arr[j] ^ arr[j + 1];
//				arr[j + 1] = arr[j] ^ arr[j + 1];
//				arr[j] = arr[j] ^ arr[j + 1];
//			}
//		}
//	}
//	for (int i = 0;i < 3;i++)
//		cout << arr[i] << " ";
//	return 0;
//}


//int jud(int i)
//{
//	int t = (int)sqrt((double)i);
//	for (int j = 2;j <= t;j++)
//	{
//		if (i % j == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	for (int i = 100;i <= 200;i++)
//	{
//		if (jud(i))
//			cout << i << endl;
//	}
//	return 0;
//}


//int main()
//{
//	for (int i = 1000;i <= 2000;i += 4)
//	{
//		if (i % 100 != 0 || i % 400 == 0)
//			cout << i << endl;
//	}
//	return 0;
//}



//int main()
//{
//	int a, b, c;
//	cin >> a >> b;
//	if (b > a)
//	{
//		b = a ^ b;
//		a = a ^ b;
//		b = a ^ b;
//	}
//	while (1)
//	{
//		if (a == b)
//		{
//			cout << a;
//			return 0;
//		}
//		c = a - b;
//		a = c > b ? c : b;
//		b = c < b ? c : b;
//	}
//}