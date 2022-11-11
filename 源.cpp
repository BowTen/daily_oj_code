#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
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



//int main()
//{
//	char arr[] = "holle world!";
//	string str1(arr);
//	string str2(arr, 2);
//	string str3(arr, 2,12);
//	string str4 = str2 + str3;
//	cout << str1 << endl << str2 << endl << str3 << endl << str4;
//	return 0;
//}

//int jud(long long t)
//{
//	long long ret = (long long)sqrt((double)t);
//	for (int i = 2;i <= ret;i++)
//	{
//		if (t % i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		long long t;
//		cin >> t;
//		if (jud(t))
//			puts("YES");
//		else
//			puts("NO");
//	}
//	return 0;
//}

//void fun(int* last, int* mid, int n)
//{
//	if(n > 0)
//		cout << " " << last[n - 1];
//	for (int i = 0;i < n;i++)
//	{
//		if (mid[i] == last[n - 1])
//		{
//			fun(last, mid, i);
//			fun(last + i , mid + 1 + i, n - i - 1);
//			break;
//		}
//	}
//}
//int main()
//{
//	int n, last[31], mid[30];
//	cin >> n;
//	for (int i = 0;i < n;i++)
//		cin >> last[i];
//	for (int i = 0;i < n;i++)
//		cin >> mid[i];
//	cout << "Preorder:";
//	fun(last, mid, n);
//	return 0;
//}

//int a[10], b[10];
//void print(int* a,int n)
//{
//	for (int i = 1;i <= n;i++)
//		cout << a[i];
//	puts("");
//}
//void fun(int n,int t)
//{
//	for (int i = 1;i <= n;i++)
//	{
//		if (b[i] == 0)
//		{
//			a[t] = i;
//			b[i] = 1;
//			if (t == n)
//				print(a,n);
//			else
//				fun(n, t + 1);
//			b[i] = 0;
//		}
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	fun(n,1);
//	return 0;
//}



//typedef struct node
//{
//	char ch;
//	struct node* pl[2];
//}node;
//node* creatn()
//{
//	char tmp = getchar();
//	if (tmp == '#')
//	{
//		return NULL;
//	}
//	else
//	{
//		node* p = new node;
//		p->ch = tmp;
//		p->pl[0] = creatn();
//		p->pl[1] = creatn();
//		return p;
//	}
//}
//void printx(node* head)
//{
//	cout << head->ch;
//	for (int i = 0;i < 2;i++)
//	{
//		if (head->pl[i] != NULL)
//			printx(head->pl[i]);
//	}
//}
//void printz(node* head)
//{
//	if (head->pl[0] != NULL)
//		printz(head->pl[0]);
//	cout << head->ch;
//	if (head->pl[1] != NULL)
//		printz(head->pl[1]);
//}
//void printh(node* head)
//{
//	if (head->pl[0] != NULL)
//		printh(head->pl[0]);
//	if (head->pl[1] != NULL)
//		printh(head->pl[1]);
//	cout << head->ch;
//}
//int fun(node* head)
//{
//	if (head == NULL)
//		return 0;
//	int dep = 1;
//	dep += fun(head->pl[0]) > fun(head->pl[1]) ? fun(head->pl[0]) : fun(head->pl[1]);
//	return dep;
//}
//int count(node* head)
//{
//	int ret = 0;
//	if (head->pl[0] != NULL)
//		ret += count(head->pl[0]);
//	if (head->pl[1] != NULL)
//		ret += count(head->pl[1]);
//	if (ret == 0)
//		return 1;
//	else
//		return ret;
//}
//int main()
//{
//	node* head = new node;
//	head->ch = getchar();
//	head->pl[0] = creatn();
//	head->pl[1] = creatn();
//	cout << "PreOrder:";
//	printx(head);
//	cout << endl << "InOrder:";
//	printz(head);
//	cout << endl << "PostOrder:";
//	printh(head);
//	cout << endl << "Depth:" << fun(head);
//;	cout << endl << "Leaf:" << count(head);
//	return 0;
//}

//
//#include<math.h>
//int jud(int i)
//{
//	if (i == 2 || i == 3 || i == 5)
//		return 1;
//	for (int t = 2;t * t <= i;t++)
//	{
//		if (i % t == 0)
//			return 0;
//	}
//	return 1;
//}
//int a[1000010], b[1000010], c[1000010];
//void print_s(int n,int* a,int * b)
//{
//	cout << n << "=";
//	while (*a)
//	{
//		cout << *a++;
//		if (*b != 1)
//			cout << "^" << *b++;
//		if (*a)
//			cout << "*";
//	}
//}
//int fun_s(long long n,long long mul,int x)
//{
//	for (int i = 2;mul * i <= n;i++)
//	{
//		if (jud(i) && c[i] == 0)
//		{
//			c[i] = 1;
//			for (int j = 1;1;j++)
//			{
//				a[x] = i;
//				b[x] = j;
//				mul *= pow(i, j);
//				if (mul == n)
//				{
//					print_s(n, a, b);
//					return 0;
//				}
//				else if (mul > n)
//				{
//					a[x] = 0;
//					b[x] = 0;
//					c[i] = 0;
//					mul /= pow(i, j);
//					break;
//				}
//				else
//					fun_s(n, mul, x + 1);
//				a[x] = 0;
//				b[x] = 0;
//				mul /= pow(i, j);
//			}
//		}
//	}
//}
//int main()
//{
//	long long n;
//	
//	cin >> n;
//	if (n == 1)
//		printf("1=1");
//	else
//		fun_s(n,1,0);
//	return 0;
//}



//int a[31], jud = 0;
//void print_s(int n,int* a)
//{
//	jud++;
//	cout << n << "=";
//	while (*a)
//	{
//		cout << *a++;
//		if (*a)
//			cout << "+";
//		else if(jud != 4 && *(a-1) != n)
//			cout << ";";
//	}
//	if (jud == 4)
//	{
//		puts("");
//		jud = 0;
//	}
//}
//void search(int n,int sum,int x)
//{
//	for (int i = 1;i <= n;i++)
//	{
//		if ((x > 0 && i >= a[x-1] && i + sum <= n) || (x == 0 && i + sum <= n))
//		{
//			a[x] = i;
//			sum += i;
//			if (sum == n)
//				print_s(n, a);
//			else
//				search(n, sum, x + 1);
//			a[x] = 0;
//			sum -= i;
//		}
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	search(n,0,0);
//	return 0;
//}



//int main()
//{
//	char arr[10];
//	int t = scanf("%s", arr);
//	cout << t;
//	return 0;
//}


//




//int Digit(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	return Digit(n - 1) + Digit(n - 2);
//}
//int fun(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	int ret = 0;
//	int a = 1, b = 1;
//	for (int i = 3;i <= n;i++)
//	{
//		ret = a + b;
//		a = b;
//		b = ret;
//	}
//	return ret;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	cout << Digit(n);
//	cout << endl << fun(n);
//	return 0;
//}


//void fun(char* arr)
//{
//	int len = strlen(arr);
//	for (int i = 0;i <= (len-1) / 2;i++)
//	{
//		if (i != len - 1 - i)
//		{
//			arr[i] = arr[i] ^ arr[len - 1 - i];
//			arr[len - 1 - i] = arr[i] ^ arr[len - 1 - i];
//			arr[i] = arr[i] ^ arr[len - 1 - i];
//		}
//	}
//}
//int main()
//{
//	char arr[20] = { 0 };
//	cin >> arr;
//	fun(arr);
//	cout << arr;
//	return 0;
//


//int Digit(int n)
//{
//	if (n == 1)
//		return 1;
//	return Digit(n - 1) * n;
//}
//int fun(int n)
//{
//	if (n == 1)
//		return 1;
//	int ret = 1;
//	for (int i = 2;i <= n;i++)
//		ret *= i;
//	return ret;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	cout << Digit(n);
//	cout << endl << fun(n);
//	return 0;
//}


//int main()
//{
//	int arr[1010] = { 0 }, ans[1010] = { 0 }, n, len;
//	for (int i = 0;1;i++)
//	{
//		char tmp = getchar();
//		if (tmp != ' ')
//		{
//			arr[i] = tmp - '0';
//		}
//		else
//		{
//			len = i;
//			break;
//		}
//	}
//	cin >> n;
//	for (int i = 0;i < len;i++)
//	{
//		if (arr[i - 1] && i)
//		{
//			arr[i] += arr[i - 1] * 10;
//			arr[i - 1] = 0;
//		}
//		ans[i] = arr[i] / n;
//		arr[i] %= n;
//	}
//	int kg = 0;
//	for (int i = 0;i < len;i++)
//	{
//		if (kg == 0 && ans[i] != 0)
//			kg = 1;
//		if (kg)
//			cout << ans[i];
//	}
//	if (kg == 0)
//		cout << 0;
//	cout << ' ' << arr[len - 1];
//	return 0;
//}



//class m_obj
//{
//public:
//	m_obj();
//	m_obj(m_obj& a);
//	~m_obj();
//};
//m_obj::m_obj()
//{
//	cout << "无参构造" << endl;
//}
//m_obj::m_obj(m_obj& a)
//{
//	cout << "拷贝构造" << endl;
//}
//m_obj::~m_obj()
//{
//	cout << "析构" << endl;
//}
//int main()
//{
//	m_obj ab;
//	m_obj ac = ab;
//	return 0;
//}


//int arr[100];
//int map[10][10];
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e2 - *(int*)e1;
//}
//int main()
//{
//	int a,m,n;
//	cin >> a;
//	for (int i = a;i > 0;i--)
//	{
//		int j = a / i;
//		if (i * j == a)
//		{
//			m = i;
//			n = j;
//		}
//		if (m <= n)
//		{
//			m = m ^ n;
//			n = m ^ n;
//			m = m ^ n;
//			break;
//		}
//	}
//	for (int i = 0;i < a;i++)
//		cin >> arr[i];
//	qsort(arr, a, sizeof(arr[0]), cmp);
//	int x = 0,j = 0, i = 0,count = 0;
//	while(1)
//	{
//		for (j;j < n;)
//		{
//			map[i][j] = arr[x];
//			x++;
//			count++;
//			if (count == a)
//				goto ss;
//			if (j == n-1)
//			{
//				i++;
//				break;
//			}
//			if (map[i][j + 1] == 0)
//				j++;
//			else
//			{
//				i++;
//				break;
//			}
//		}
//		for (i;i < m;)
//		{
//			map[i][j] = arr[x];
//			x++;
//			count++;
//			if (count == a)
//				goto ss;
//			if (i == m-1)
//			{
//				j--;
//				break;
//			}
//			if (map[i + 1][j] == 0)
//				i++;
//			else
//			{
//				j--;
//				break;
//			}
//		}
//		for (j;j >= 0;)
//		{
//			map[i][j] = arr[x];
//			x++;
//			count++;
//			if (count == a)
//				goto ss;
//			if (j == 0)
//			{
//				i--;
//				break;
//			}
//			if (map[i][j-1] == 0)
//				j--;
//			else
//			{
//				i--;
//				break;
//			}
//		}
//		for (i;i >= 0;)
//		{
//			map[i][j] = arr[x];
//			x++;
//			count++;
//			if (count == a)
//				goto ss;
//			if (map[i - 1][j] == 0)
//				i--;
//			else
//			{
//				j++;
//				break;
//			}
//		}
//	}
//ss:;
//	for (i = 0;i < m;i++)
//	{
//		for (j = 0;j < n;j++)
//		{
//			if (j)
//				cout << " ";
//			cout << map[i][j];
//		}
//		if(i != m-1)
//			puts("");
//	}
//	return 0;
//}



//class MyClass
//{
//public:
//	int num;
//	~MyClass();
//	static MyClass* creatc();
//private:
//	MyClass();
//	MyClass(const MyClass& a);
//	static MyClass* cp;
//};
//MyClass* MyClass::cp = NULL;
//MyClass::MyClass(){}
//MyClass::~MyClass(){}
//MyClass* MyClass::creatc()
//{
//	if (cp == NULL)
//	{
//		cp = new MyClass;
//	}
//	return cp;
//}
//
//class MyClass2
//{
//public:
//	MyClass2(int n,int x,int y,int z);
//	int num;
//private:
//	int a;
//	int b;
//	int c;
//};
//MyClass2::MyClass2(int n,int x,int y,int z): num(n),a(x),b(y),c(z) {}
//
//
//int main()
//{
//	MyClass* obj = MyClass::creatc();
//	obj->num = 666;
//	cout << obj->num;
//	MyClass2 obj2(999,1,2,3);
//	cout << endl << obj2.num << " ";
//	return 0;
//}



//int n, a, b, c, a2, b2, c2, m[4],m2[4];
//int main()
//{
//	cin >> n;
//	getchar();
//	while (n--)
//	{
//		char x, y;
//		scanf("%c %c", &x, &y);
//		getchar();
//		if (x == 'J')
//			x = 3;
//		else if (x == 'B')
//			x = 1;
//		else if (x == 'C')
//			x = 2;
//		if (y == 'J')
//			y = 3;
//		else if (y == 'B')
//			y = 1;
//		else if (y == 'C')
//			y = 2;
//		if (x == y)
//		{
//			b++;
//			b2++;
//		}
//		else if (x - y == -1 || x - y == 2)
//		{
//			a++;
//			c2++;
//			m[x]++;
//		}
//		else if (x - y == 1 || x - y == -2)
//		{
//			c++;
//			a2++;
//			m2[y]++;
//		}
//	}
//	cout << a << " " << b << " " << c << endl;
//	cout << a2 << " " << b2 << " " << c2 << endl;
//	int t = 1, y = 1;
//	for (int i = 1;i <= 3;i++)
//	{
//		if (m[i] > m[t])
//			t = i;
//		if (m2[i] > m2[y])
//			y = i;
//	}
//	if (t == 1)
//		cout << "B ";
//	else if (t == 2)
//		cout << "C ";
//	else
//		cout << "J ";
//	if (y == 1)
//		cout << "B";
//	else if (y == 2)
//		cout << "C";
//	else
//		cout << "J";
//	return 0;
//}



//class fa
//{
//public:
//	int pub;
//private:
//	int pri = 0;
//protected:
//	int pro;
//};
//class son : public fa
//{
//public:
//	void setpri()
//	{
//		this->pro = 0;
//		pub = 0;
//	}
//};
//int main()
//{
//	cout << sizeof(fa) << " " << sizeof(son);
//	son a;
//	a.setpri();
//	fa b;
//	return 0;
//}


//int main()
//{
//	int arr[11] = { 0 };
//	for (int i = 0;i < 10;i++)
//	{
//		cin >> arr[i];
//	}
//	if(arr[0] != 0)
//		for (int i = 1;i < 10;i++)
//		{
//			if (arr[i] != 0)
//			{
//				arr[i]--;
//				cout << i;
//				break;
//			}
//		}
//	for (int i = 0;i < 10;i++)
//	{
//		if (arr[i] != 0)
//			for (arr[i];arr[i] > 0;arr[i]--)
//				cout << i;
//	}
//	return 0;
//}



//class father
//{
//public:
//	father();
//	virtual ~father();
//
//private:
//
//};
//
//father::father()
//{
//	cout << "father::father()" << endl;
//}
//
//father::~father()
//{
//	cout << "father::~father()" << endl;
//}
//
//class son : public father
//{
//public:
//	son();
//	~son();
//
//private:
//
//};
//
//son::son()
//{
//	cout << "son::son()" << endl;
//}
//
//son::~son()
//{
//	cout << "son::~son()" << endl;
//}
//int main()
//{
//	
//	//son objs;
//	//father objf;
//	/*father* fp = new son;
//	delete fp;*/
//	new son;
//	return 0;
//}




//class fa
//{
//public:
//	fa();
//	~fa();
//
//	int num;
//};
//
//fa::fa()
//{
//}
//
//fa::~fa()
//{
//}
//
//class son
//{
//public:
//	int num;
//};
//int main()
//{
//	fa obj1;
//	obj1.num = 6;
//	return 0;
//	son obj;
//	obj.num = 9;
//}

//class son
//{
//public:
//	son()
//	{
//		cout << "默认构造" << endl;
//	}
//	son(const son& a)
//	{
//		cout << "拷贝构造" << endl;
//	}
//	int num;
//};
//int main()
//{
//	son a;
//	a.num = 6;
//	son b(a);
//	cout << b.num;
//	return 0;
//}


//class real
//{
//public:
//	int fz;
//	int fm;
//	int zs;
//	void fun()
//	{
//		if (fm < 0)
//		{
//			fz *= -1;
//			fm *= -1;
//		}
//		int max = 1;
//		int a = abs(this->fz) > abs(this->fm) ? abs(this->fz) : abs(this->fm);
//		int b = abs(this->fz) < abs(this->fm) ? abs(this->fz) : abs(this->fm);
//		int c;
//		if (this->fz != 0 && fm != 0)
//		{
//			while (1)
//			{
//				if (a == b)
//				{
//					max = a;
//					break;
//				}
//				c = a - b;
//				a = b > c ? b : c;
//				b = b < c ? b : c;
//			}
//			this->fz /= max;
//			this->fm /= max;
//			if (abs(this->fz) > abs(this->fm))
//			{
//				this->zs = this->fz / this->fm;
//				this->fz = abs(fz) % this->fm;
//			}
//		}
//	}
//	void print()
//	{
//		if (fm == 0)
//			cout << "Inf";
//		else
//		{
//			if (this->zs != 0)
//			{
//				if (zs < 0)
//					cout << "(";
//				cout << this->zs;
//				if (this->fz != 0)
//				{
//					cout << " ";
//					if (this->fm == 1)
//						cout << this->fz;
//					else
//						cout << fz << "/" << fm;
//				}
//				if (zs < 0)
//					cout << ")";
//			}
//			else if (zs == 0)
//			{
//				if (this->fz == 0)
//					cout << "0";
//				else if (this->fm == 1)
//				{
//					if (this->fz < 0)
//						cout << "(" << this->fz << ")";
//					else
//						cout << this->fz;
//				}
//				else
//				{
//					if (fz < 0)
//						cout << "(" << fz << "/" << fm << ")";
//					else
//						cout << fz << "/" << fm;
//				}
//			}
//		}
//	}
//};
//real a, b, c;
//int main()
//{
//	int e, d, f, g;
//	scanf("%d/%d %d/%d", &e, &d, &f, &g);
//	e *= g;
//	f *= d;
//	d *= g;
//	g  = d;
//	a.fz = e;
//	a.fm = d;
//	b.fz = f;
//	b.fm = g;
//	a.fun();
//	b.fun();
//
//	a.print();cout << " + ";b.print();cout << " = ";
//	c.zs = 0;
//	c.fz = e + f;
//	c.fm = d;
//	c.fun(); c.print();
//	puts("");
//
//	a.print();cout << " - ";b.print();cout << " = ";
//	c.zs = 0;
//	c.fz = e - f;
//	c.fm = d;
//	c.fun(); c.print();
//	puts("");
//
//	a.print();cout << " * ";b.print();cout << " = ";
//	c.zs = 0;
//	c.fz = e * f;
//	c.fm = d * g;
//	c.fun(); c.print();
//	puts("");
//
//	a.print();cout << " / ";b.print();cout << " = ";
//	c.zs = 0;
//	c.fz = e;
//	c.fm = f;
//	c.fun(); c.print();
//	return 0;
//}

//class a
//{
//public:
//	int num = 9;
//	void print()
//	{
//		cout << this->num;
//	}
//};
//int main()
//{
//	a obj;
//	obj.print();
//	return 0;
//}



//#include<algorithm>
//bool issame(int a[], int t[],int n)
//{
//	for (int i = 0;i < n;i++)
//		if (a[i] != t[i])
//			return 0;
//	return 1;
//}
//void m_print(int a[], int n)
//{
//	for (int i = 0;i < n;i++)
//	{
//		if (i != 0)
//			cout << " ";
//		cout << a[i];
//	}
//}
//bool isisort(int a[], int t[], int n)
//{
//	for (int i = 2;i < n;i++)
//	{
//		sort(a, a + i);
//		if (issame(a, t, n))
//		{
//			sort(a, a + i + 1);
//			return 1;
//		}
//	}
//	return 0;
//}
//bool ismsort(int b[], int t[], int n)
//{
//	for (int i = 2;i <= 2 * n;i++)
//	{
//		for (int j = 0;j <= n;j += i)
//		{
//			sort(b + j, b + min(j + i,n));
//		}
//		if (issame(b, t, n))
//		{
//			i *= 2;
//			for (int j = 0;j <= n;j += i)
//			{
//				sort(b + j, b + min(j + i, n));
//			}
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int a[110] = { 0 }, b[110] = { 0 }, t[110] = { 0 },n;
//	cin >> n;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> a[i];
//		b[i] = a[i];
//	}
//	for (int i = 0;i < n;i++)
//		cin >> t[i];
//	if (isisort(a,t,n))
//	{
//		puts("Insertion Sort");
//		m_print(a,n);
//	}
//	else if (ismsort(b, t, n))
//	{
//		puts("Merge Sort");
//		m_print(b,n);
//	}
//	return 0;
//}



//#include<algorithm>
//int main()
//{
//	int a[10] = { 5,8,6,1,9,7,3,4,2,0 };
//	nth_element(a, a + 2, a + 10);
//	for (int i = 0;i < 10;i++)
//		cout << a[i] << " ";
//	return 0;
//}

//
//#include<vector>
//void print_v(vector<int>vec)
//{
//	for (int i = 0;i < vec.size();i++) { cout << vec[i] << " "; }
//}
//void recity(string& s,int n)
//{
//	s.resize(n);
//	string tmp = s;
//	s.swap(tmp);
//}
//int main()
//{
//	/*vector<int>a1;
//	cout << "初始：";print_v(a1);cout << endl;
//
//	vector<int>a2(5);
//	cout << "设置大小为5：";print_v(a2);cout << endl;
//
//	vector<int>a3(5, 6);
//	cout << "设置大小为5并初始化为6：";print_v(a3);cout << endl;
//
//	vector<int>a4(a3);
//	cout << "复制上一个：";print_v(a4);cout << endl;
//
//	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	vector<int>a5(a + 1, a + 9);
//	cout << "从数组中输入（a+1,a+9）：";print_v(a5);cout << endl;
//
//	vector<int>a6(a5.begin(), a5.begin() + 5);
//	cout << "从上一个复制5个：";print_v(a6);cout << endl;
//
//	cout << endl;a6.assign(4, 2);print_v(a6);cout << endl;
//
//	a6.assign(a5.begin(), a5.begin() + 5);print_v(a6);cout << endl;
//
//	cout << "a6最后一个元素：" << a6.back() << endl
//		<< "a6第一个元素：" << a6.front() << endl
//		<< "a6第一个元素后3个元素：" << a6.front() + 3 << endl << endl << endl;
//
//	vector<int>ax(a6);
//	cout << "用a6初始化ax：";print_v(ax);cout << endl;
//	cout << "empty(ax) = ";cout << empty(ax);cout << endl << endl;
//	cout << "ax clear 后：" << endl;ax.clear();
//	cout << "empty(ax) = ";cout << empty(ax) << endl << endl;
//
//	ax = a6;print_v(ax);cout << endl;
//	ax.erase(ax.begin()+2, ax.begin() + 4);print_v(ax);cout << endl << endl;
//
//	ax = a6;ax.push_back(12);print_v(ax);
//	ax.insert(ax.begin() + 2, 3, 0);cout << endl; print_v(ax);cout << endl;
//
//	ax = a6;ax.insert(ax.begin() + 2, a, a + 3);;print_v(ax);cout << endl;
//	cout << ax.size() << endl;
//	cout << ax.capacity() << endl;
//	ax.push_back(66);ax.push_back(67);ax.push_back(68);cout << ax.capacity() << endl;
//	ax.resize(15,6);print_v(ax);cout << endl;
//	cout << ax.capacity() << endl;
//	ax.resize(16);print_v(ax);cout << endl;
//	cout << ax.capacity();cout << endl;
//	ax.reserve(30);cout << ax.capacity() << endl;
//	cout << "___________________" << endl;
//	ax.reserve(10);
//	print_v(ax);
//	cout << endl << ax.capacity() << endl;
//	cout << "______________________" << endl;
//	ax.resize(10, 2);
//	print_v(ax);cout << endl << ax.capacity() << endl;
//	cout << "_______________" << endl;
//	ax.resize(31, 2);
//	print_v(ax);
//	cout << ax.capacity() << endl;
//	cout << "_________________" << endl;
//
//	ax.resize(7, 7);ax.reserve(7);
//	print_v(ax);cout << endl << ax.capacity() << endl;
//	cout << "_________________" << endl;
//
//	ax.clear();
//	cout << ax.capacity() << endl;*/
//	
//	/*vector<int>tmp(ax);
//	delete(&ax);
//	vector<int>ax(tmp);
//	delete(&tmp);
//	print_v(ax);cout << endl;
//	cout << ax.capacity() << endl;*/
//
//	//cout << tmp.capacity() << endl;
//	//print_v(tmp);cout << endl;
//	//delete(&ax);
//	//print_v(ax);
//
//	//vector<int>obj;
//	//cout << obj.capacity() << endl;
//
//	/*vector<int>a = { 1,2,3,4,50 };
//	vector<int>b = { 6,6,6 };
//	print_v(a);cout << endl;
//	print_v(b);cout << endl << endl;
//	a.swap(b);
//	print_v(a);cout << endl;
//	print_v(b);cout << endl;
//
//	vector<int>().swap(a);
//	print_v(a);*/
//
//	//string s1 = "holle!";
//	//string s2 = "world!";
//	//string s3 = s1 + " " + s2;
//	//cout << s1 << " " << s2 << endl << s3;
//
//	//s1 += "add";
//	//cout << endl << s1;
//
//	//cout << endl << "_________________" << endl;
//	//s1.resize(100,'6');
//	//recity(s1, 7);
//	////cout << s1 << endl;
//	////s1.resize(7);
//	////cout << s1 << endl;
//	//////s1.reserve(7);
//	////cout << s1;
//	////{
//	////	string tmp = s1;
//	////	s1.swap(tmp);
//	////}
//	//cout << s1;
//
//	return 0;
//}


//int main()
//{
//	int a, b, cd;
//	cin >> a>>b >> cd;
//	cout << a << " " << b << " " << cd << endl;
//	return 0;
//}

//#include<vector>
//void recity(vector<int>& a,int n)
//{
//	a.resize(n);
//	vector<int>tmp(a);
//	a.swap(tmp);
//}
//int main()
//{
//	vector<int>a = {1,2,3,4,5,6,7,8,9,10,11};
//	a.resize(100);
//	//a.resize(6);
//	//a.reserve(7);
//	recity(a, 7);
//	cout << a.capacity();
//	cout << endl;
//
//	return 0;
//}

//
//int main()
//{
//	string a = "abcdeabcde";
//	cout << a.find_last_of('a');
//	return 0;
//}


//#include<bits/stdc++.h>
//int main()
//{
//	int n,k;
//	cin >> n;
//	vector<int>stu(n,0);
//	for (int i = 0;i < n;i++)
//		cin >> stu[i];
//	cin >> k;
//	while (k--)
//	{
//		int sum = 0, tmp;
//		cin >> tmp;
//		for (int i = 0;i < n;i++)
//		{
//			if (tmp == stu[i])
//				sum++;
//		}
//		cout << sum;
//		if (k)
//			cout << " ";
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	int n, a[101] = { 0 };
//	cin >> n;
//	while (n--)
//	{
//		int tmp;
//		cin >> tmp;
//		a[tmp] ++;
//	}
//	int k;
//	cin >> k;
//	while (k--)
//	{
//		int tmp;
//		cin >> tmp;
//		cout << a[tmp];
//		if (k)
//			cout << " ";
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	string str;
//	long long sum = 0;
//	cin >> str;
//	for (int i = 0;i < str.size();i++)
//		if (str[i] == 'P')
//			for (int j = i + 1;j < str.size();j++)
//				if (str[j] == 'A')
//					for (int x = j + 1;x < str.size();x++)
//						if (str[x] == 'T')
//							sum++;
//	cout << sum % 1000000007;
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace  std;
//int main()
//{
//	char a[100010];
//	cin >> a;
//	long long p = 0, sum = 0, pa = 0;
//	for (int i = 0;a[i] != 0;i++)
//	{
//		if (a[i] == 'P')
//			p++;
//		else if (a[i] == 'A')
//			pa += p;
//		else if (a[i] == 'T')
//			sum += pa;
//	}
//	cout << sum % 1000000007;
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//typedef struct
//{
//public:
//	char id[17];
//	int b;
//}stu;
//stu arr[1001];
//int main()
//{
//	int n,m;
//	cin >> n;
//	while (n--)
//	{
//		char tmp[17] = { 0 };
//		int t = 0;
//		cin >> tmp >> t;
//		strcpy(arr[t].id, tmp);
//		cin >> arr[t].b;
//	}
//	cin >> m;
//	while (m--)
//	{
//		int t;
//		cin >> t;
//		cout << arr[t].id << " " << arr[t].b << endl;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	char str[1001];int arr[200] = { 0 };
//	for (int i = 0;str[i] = getchar(), str[i] != '\n';i++)
//	{
//		if (str[i] >= 'A' && str[i] <= 'Z')
//			str[i] = str[i] - 'A' + 'a';
//		if (str[i] >= 'a' && str[i] <= 'z')
//			arr[str[i]] ++;
//	}
//	int m = 'a', max = 0;
//	for (int i = 'a'; i <= 'z';i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//			m = i;
//		}
//	}
//	printf("%c %d", m, max);
//	return 0;
//}


#include<bits/stdc++.h>
using namespace std;
char text[] = "PATest";
int main()
{
	char tmp;
	int arr[200] = { 0 };
	while (tmp = getchar(), tmp != '\n')
	{
		if (tmp == 'P' || tmp == 'A' || tmp == 'T' || tmp == 'e' || tmp == 's' || tmp == 't')
			arr[tmp]++;
	}
	return 0;
}