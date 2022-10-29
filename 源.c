#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//int check(int x);
//int check(int x)
//{
//    int arr[9] = { 0 };
//    int len = 0;
//    for (int i = 0;1;i++)
//    {
//        arr[i] = x % 10;
//        x /= 10;
//        len = i;
//        if (x == 0)
//            break;
//    }
//    for (int i = 0;i <= len/2;i++)
//    {
//        if (arr[i] != arr[len - i])
//            return 0;
//    }
//    return 1;
//}
//int main() {
//    for (int num = 1;num <= 10000;num++) {
//        if (check(num * num))printf("%d %d\n", num, num * num);
//    }
//    return 0;
//}


//int main()
//{
//	int n;
//	int map[1000][1000] = { 0 };
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < n;j++)
//		{
//			scanf("%d", &map[i][j]);
//		}
//	}
//	for (int x = 0;x < n/2;x++)
//	{
//		int i = (n / 2) * (-1) + x;
//		int j = (n / 2) * (-1) + x;
//		for (;j <= (n / 2) - x;j++)
//		{
//			if (map[n / 2][n / 2] - map[(n / 2) + i][(n / 2) + j] != n / 2)
//			{
//				printf("It's too cold.");
//				return 0;
//			}
//		}
//		for (;i <= (n / 2) - x;i++)
//		{
//			if (map[n / 2][n / 2] - map[(n / 2) + i][(n / 2) + j] != n / 2)
//			{
//				printf("It's too cold.");
//				return 0;
//			}
//		}
//		for (;j >= (n / 2) * (-1) + x;j--)
//		{
//			if (map[n / 2][n / 2] - map[(n / 2) + i][(n / 2) + j] != n / 2)
//			{
//				printf("It's too cold.");
//				return 0;
//			}
//		}
//		for (;i <= (n / 2)*(-1) + x;i--)
//		{
//			if (map[n / 2][n / 2] - map[(n / 2) + i][(n / 2) + j] != n / 2)
//			{
//				printf("It's too cold.");
//				return 0;
//			}
//		}
//	}
//	printf("ok, you are a cool guy.");
//	return 0;
//}


//int main()
//{
//	int n,t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d", &n);
//		while (n != 0)
//		{
//			printf("%d", n % 10);
//			n /= 10;
//		}
//		printf("\n");
//	}
//	return 0;
//}



//int main()
//{
//	int n, m;
//	while (~scanf("%d %d", &n, &m))
//	{
//		int arr[1010] = { 0 };
//		for (int i = 0;i < m;i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		for (int i = 0;i < m;i++)
//		{
//			if (n < 640)
//			{
//				break;
//			}
//			else
//			{
//				n += arr[i] - 640;
//			}
//		}
//		printf("%d", n > 0 ? n : 0);
//	}
//	return 0;
//}


//int main()
//{
//	int x;
//	int sum = 0;
//	scanf("%d", &x);
//	if (x >= 100)
//	{
//		sum += x / 100;
//		x %= 100;
//	}
//	if (x >= 50)
//	{
//		sum += x / 50;
//		x %= 50;
//	}
//	if (x >= 20)
//	{
//		sum += x / 20;
//		x %= 20;
//	}
//	if (x >= 10)
//	{
//		sum += x / 10;
//		x %= 10;
//	}
//	if (x >= 5)
//	{
//		sum += x / 5;
//		x %= 5;
//	}
//	if (x >= 2)
//	{
//		sum += x / 2;
//		x %= 2;
//	}
//	sum += x;
//	printf("%d", sum);
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		int n2 = n;
//		int a = 1;
//		int jud = 0;
//		int t1, t2;
//		while (n2--)
//		{
//			scanf("%d", &t2);
//			if (n - n2 != 1)//非第一次输入时
//			{
//				if (jud == 0)//判断数字顺序
//				{
//					if (t2 > t1)
//					{
//						if (t2 - t1 == 1)
//							jud = 1;
//						else if (t2 == n)
//							jud = 2;
//						else
//							a = 0;
//					}
//					else if (t2 < t1)
//					{
//						if (t1 - t2 == 1)
//							jud = 2;//降序
//						else if (t2 == 1)
//							jud = 1;//升序
//						else
//							a = 0;
//					}
//					else
//						a = 0;
//				}
//				else if (jud == 1 && t2 <= t1 && t2 != 1)//升序
//					a = 0;
//				else if (jud == 2 && t2 >= t1 && t2 != n)//降序
//					a = 0;
//			}
//			t1 = t2;
//		}
//		if (a)
//			puts("YES");
//		else
//			puts("NO");
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		double fz = 0, fm = 0;
//		for (int i = 0;i < 3;i++)
//		{
//			int a, b;
//			scanf("%d %d", &a, &b);
//			fz += a * b;
//			fm += a;
//		}
//		printf("%.2lf\n", fz / fm);
//	}
//	return 0;
//}

//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		int sum = 0;
//		int max = (-1) * 0x1fffffff;
//		scanf("%d", &n);
//		for (int i = 0;i < n;i++)
//		{
//			int a;
//			scanf("%d", &a);
//			if (sum < 0)
//				sum = a;
//			else
//				sum += a;
//			max = sum > max ? sum : max;
//		}
//		printf("%d\n", max);
//	}
//	return 0;
//}


//int main()
//{
//	int a;
//	scanf("%d\n", &a);
//	printf("%d", a);
//	return 0;
//}

//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		int arr[10010] = { 0 };
//		int x = 0;
//		for (int i = 0;i < n;i++)
//		{
//			int tmp;
//			scanf("%d", &tmp);
//			int jud = 1;
//			for (int j = 0;j < x;j++)
//			{
//				if (tmp == arr[j])
//				{
//					jud = 0;
//					break;
//				}
//			}
//			if(jud)
//			{
//				arr[x] = tmp;
//				x++;
//			}
//		}
//		qsort(arr, x, sizeof(arr[0]), cmp);
//		printf("%d\n", x);
//		for (int i = 0;i < x;i++)
//		{
//			if (i != 0)
//				printf(" ");
//			printf("%d", arr[i]);
//		}
//		puts("");
//	}
//	return 0;
//}



//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		for (int i = 0;i < n;i++)
//		{
//			char tmp[20] = { 0 };
//			scanf("%s", tmp);
//			if (strcmp(tmp, "bowl") == 0 || strcmp(tmp, "knife") == 0 || strcmp(tmp, "fork") == 0 || strcmp(tmp, "chopsticks") == 0)
//			{
//				printf("%s ",tmp);
//			}
//		}
//		puts("");
//	}
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int a;
//		int min = 0, max = 0;
//		scanf("%d", &a);
//		if (a % 2 == 0)
//		{
//			max = a / 2;
//			min = (a / 4) + (a % 4)/2;
//		}
//		printf("%d %d\n", min, max);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	while (scanf("%d", &n), n)
//	{
//		int count = 0;
//		if (n == 3 || n == 2)
//			count = 1;
//		else if (n == 1)
//			count = 0;
//		else
//		{
//			if (n % 2 == 1)
//				n--;
//			while (1)
//			{
//				n /= 2;
//				count++;
//				if (n == 3 || n == 2)
//				{
//					count++;
//					break;
//				}
//			}
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}



//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	for (int i = 0;i <= n, 2 * i <= m;i++)
//	{
//		for (int j = 0;j <= n, j * 4 <= m;j++)
//		{
//			if (i * 2 + j * 4 == m && i + j == n)
//			{
//				printf("%d %d", i, j);
//				return 0;
//			}
//		}
//	}
//	printf("No answer");
//	return 0;
//}

//int digit(int tmp)
//{
//	int sum = 0;
//	for (int i = tmp;i != 0;i /= 10)
//	{
//		sum += i % 10;
//	}
//	if (sum < 10)
//		return sum;
//	return digit(sum);
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int tmp;
//		int jud = 0;
//		scanf("%d", &tmp);
//		if (tmp % 7 == 0 && tmp)
//			jud = 1;
//		else if (tmp == 0);
//		else
//		{
//			for (int i = tmp;i != 0;i /= 10)
//			{
//				if (i % 10 == 7)
//				{
//					jud = 1;
//					break;
//				}
//			}
//			if (jud == 0)
//			{
//				if (digit(tmp) == 7)
//					jud = 1;
//			}
//		}
//		printf("%d\n", jud);
//	}
//	return 0;
//}



//int main()
//{
//	char arr[1000] = { 0 };
//	while (gets(arr) != 0)
//	{
//		int kg = 1;
//		for (int i = 0;i < strlen(arr);i++)
//		{
//			if (kg)
//				printf("%c", arr[i]);
//			if (arr[i] == '"')
//			{
//				if (kg == 1)
//					kg = 0;
//				else
//				{
//					kg = 1;
//					printf("\"");
//				}
//			}
//		}
//		puts("");
//	}
//	return 0;
//}



//int main()
//{
//	char b[10];
//	int a = gets(b);
//	printf("%d\n", a);
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	while (t--)
//	{
//		char tmp[100000] = { 0 };
//		gets(tmp);
//		int len = strlen(tmp);
//		for (int i = 0;i < len;i++)
//		{
//			if (len - i >= 3 && tmp[i] == 'm' && tmp[i + 1] == 'w' && tmp[i + 2] == 'y')
//			{
//				printf("return my hard-earned money");
//				i += 2;
//			}
//			else
//				printf("%c", tmp[i]);
//		}
//		puts("");
//	}
//	return 0;
//}


//typedef struct
//{
//	short num;
//	char text[101];
//}id;
//id arr[1000];
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d %s", &arr[i].num, arr[i].text);
//	}
//	for (int i = 0;i < m;i++)
//	{
//		int tmp;
//		scanf("%d", &tmp);
//		for (int j = 0;j < n;j++)
//		{
//			if (arr[j].num == tmp)
//				printf("%s ", arr[j].text);
//		}
//	}
//	return 0;
//}


//#undef int
//#undef return
//#undef while
//
//int main()
//{
//	int a, b;
//	while(~scanf("%d %d", &a, &b))
//		printf("%d\n", a + b);
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int t1,t2;
//		scanf("%d:%d", &t1, &t2);
//		int n,m;
//		scanf("%d %d", &n, &m);
//		while (n--)
//		{
//			int a, b;
//			scanf("%d:%d", &a, &b);
//			while (1)
//			{
//				if (a < t1 || (a == t1 && b < t2))
//				{
//					b += m;
//					if (b >= 60)
//					{
//						b -= 60;
//						a++;
//					}
//				}
//				else if (a == t1 && b == t2)
//				{
//					puts("RUNRUNRUN!");
//					break;
//				}
//				else if (a > t1 || (a == t1 && b > t2))
//				{
//					puts("SLEEPSLEEPSLEEP!");
//					break;
//				}
//			}
//		}
//	}
//}

//int main()
//{
//	int a;
//	scanf("%d", &a);
//	printf("%d", a);
//	return 0;
//}


//int main()
//{
//	int n;
//	while (scanf("%d", &n), n)
//	{
//		int arr[220];
//		int sum = 0;
//		int jud = 0;
//		for (int i = 1;i <= 2 * n;i+=2)
//		{
//			scanf("%d", &arr[i]);
//		}
//		for (int i = 2;i <= 2 * n;i+=2)
//		{
//			scanf("%d", &arr[i]);
//		}
//		for (int i = 1;i <= 2 * n;i++)
//		{
//			sum += arr[i];
//			if (sum == 0)
//			{
//				if (i % 2 != 0)
//					jud = 1;
//				else
//					jud = 2;
//				break;
//			}
//		}
//		if (jud == 0)
//		{
//			if (sum % 2 == 0)
//				jud = 2;
//			else
//				jud = 1;
//		}
//		if (jud == 1)
//			puts("G WIN!");
//		else if (jud == 2)
//			puts("N WIN!");
//	}
//	return 0;
//}


//int main()
//{
//	int i, j, n, m, ** a;
//	scanf("%d%d", &n, &m);
//	/*你的代码将会被嵌在这*/
//	a = (int**)malloc(sizeof(int*)*n);
//	for (int i = 0;i < n;i++)
//	{
//		a[i] = (int*)malloc(sizeof(int)*m);
//	}
//	for (i = 0; i < n; ++i)
//	{
//		for (j = 0; j < m; ++j)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	for (i = 0; i < n; ++i)
//	{
//		for (j = 0; j < m; ++j)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int n, m;
//	while (scanf("%d %d", &n, &m), (n || m))
//	{
//		int x = 2 * n - m / 2;
//		int y = m / 2 - n;
//		if (x + y == n && 2 * x + 4 * y == m && m > n && y >= 0 && x >= 0)
//			printf("%d %d\n", x, y);
//		else if(n == 0 || m == 0)
//			puts("Error");
//		else
//			puts("Error");
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	int count = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		count++;
//		printf("%d-->", n);
//		int arr[18];
//		int x = 0;
//		int jud = 0;
//		if (n < 0)
//		{
//			n *= -1;
//			jud = 1;
//		}
//		for (int i = 0;n;i++)
//		{
//			arr[i] = n % 2;
//			n /= 2;
//			x = i;
//		}
//		if (jud)
//			printf("-");
//		for (int i = x;i >= 0;i--)
//		{
//			printf("%d", arr[i]);
//		}
//		puts("");
//		if (count == 5)
//			return 0;
//	}
//	return 0;
//}



//int main()
//{
//    int arr[1010] = { 0 };
//    for (int i = 2;i < 1010;i++)
//    {
//        for (int j = 2 * i;j < 1010;j += i)
//            arr[j] = 1;
//    }
//    int t;
//    scanf("%d", &t);
//    while (t--)
//    {
//        int n;
//        scanf("%d", &n);
//        int sum = 0;
//        for (int i = 2;i <= n;i++)
//        {
//            if (arr[i] == 0)
//                sum++;
//        }
//        printf("%d\n", sum);
//    }
//	return 0;
//}



//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		int len = 7 + 4 * (n - 2);
//		int p = (len + 1) / 2;
//		int q = p;
//		for (int j = 1;j <= n;j++)
//		{
//			for (int i = 1;i <= len;i++)
//			{
//				if (i < q)
//					printf(" ");
//				else if (i == q || i == p)
//					printf("*");
//				else if (i < p)
//					printf(" ");
//			}
//			puts("");
//			q--;
//			p++;
//		}
//		q++;
//		p--;
//		for (int i = 1;i <= n;i++)
//		{
//			for (int j = 1;j <= len;j++)
//			{
//				if (i == 1 || i == n)
//				{
//					if (j > q && j < p)
//						printf(" ");
//					else
//						printf("*");
//				}
//				else if (j == 1 || j == len)
//					printf("*");
//				else
//					printf(" ");
//			
//			}
//			puts("");
//		}
//		for (int i = 1;i <= n;i++)
//		{
//			for (int j = 1;j <= len;j++)
//			{
//				if (i != n)
//				{
//					if (j < q)
//						printf(" ");
//					else if (j == q || j == p)
//						printf("*");
//					else if (j < p)
//						printf(" ");
//				}
//				else
//				{
//					if (j < q)
//						printf(" ");
//					else if (j <= p)
//						printf("*");
//				}
//			}
//			puts("");
//		}
//		if (t)
//			puts("");
//	}
//	return 0;
//}

//int jud(int n)
//{
//	int x = 0, y = 0;
//	n *= 2;
//	while (n /= 2)
//	{
//		int t = n % 2;
//		if (t == 1)
//			x++;
//		else
//			y++;
//	}
//	return x > y ? 1 : 0;
//}
//int main()
//{
//	int a = 0, b = 0;
//	for (int i = 1;i <= 1000;i++)
//	{
//		if (jud(i))
//			a++;
//		else
//			b++;
//	}
//	printf("%d %d", a, b);
//	return 0;
//}


//int main()
//{
//	char a;
//	while (a = getchar(), a != '#')
//	{
//		if (a == 'A')
//			a = 'E';
//		else if (a == 'B')
//			a = 'C';
//		else if (a == 'C')
//			a = 'F';
//		else if (a == 'D')
//			a = 'A';
//		else if (a == 'E')
//			a = 'J';
//		else if (a == 'F')
//			a = 'K';
//		else if (a == 'G')
//			a = 'L';
//		else if (a == 'H')
//			a = 'B';
//		else if (a == 'I')
//			a = 'D';
//		else if (a == 'J')
//			a = 'G';
//		else if (a == 'K')
//			a = 'H';
//		else if (a == 'L')
//			a = 'I';
//		else if (a == 'M')
//			a = 'V';
//		else if (a == 'N')
//			a = 'W';
//		else if (a == 'O')
//			a = 'Z';
//		else if (a == 'P')
//			a = 'Y';
//		else if (a == 'Q')
//			a = 'M';
//		else if (a == 'R')
//			a = 'N';
//		else if (a == 'S')
//			a = 'O';
//		else if (a == 'T')
//			a = 'P';
//		else if (a == 'U')
//			a = 'Q';
//		else if (a == 'V')
//			a = 'R';
//		else if (a == 'W')
//			a = 'S';
//		else if (a == 'X')
//			a = 'T';
//		else if (a == 'Y')
//			a = 'U';
//		else if (a == 'Z')
//			a = 'X';
//		else if (a == 'a')
//			a = 'e';
//		else if (a == 'b')
//			a = 'r';
//		else if (a == 'c')
//			a = 'w';
//		else if (a == 'd')
//			a = 'q';
//		else if (a == 'e')
//			a = 't';
//		else if (a == 'f')
//			a = 'y';
//		else if (a == 'g')
//			a = 'g';
//		else if (a == 'h')
//			a = 'h';
//		else if (a == 'i')
//			a = 'b';
//		else if (a == 'j')
//			a = 'n';
//		else if (a == 'k')
//			a = 'u';
//		else if (a == 'l')
//			a = 'i';
//		else if (a == 'm')
//			a = 'o';
//		else if (a == 'n')
//			a = 'p';
//		else if (a == 'o')
//			a = 's';
//		else if (a == 'p')
//			a = 'j';
//		else if (a == 'q')
//			a = 'k';
//		else if (a == 'r')
//			a = 'd';
//		else if (a == 's')
//			a = 'l';
//		else if (a == 't')
//			a = 'f';
//		else if (a == 'u')
//			a = 'a';
//		else if (a == 'v')
//			a = 'z';
//		else if (a == 'w')
//			a = 'x';
//		else if (a == 'x')
//			a = 'c';
//		else if (a == 'y')
//			a = 'v';
//		else if (a == 'z')
//			a = 'm';
//		printf("%c", a);
//	}
//	return 0;
//



//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//
//int main()
//{
//	int n, k;
//	scanf("%d %d", &n, &k);
//	int sum = 0;
//	for (int a = 1;a <=n;a++)
//	{
//		for (int b = 1;b <= n;b++)
//		{
//			for (int c = 1;c <= n;c++)
//			{
//				if((a+b)%k==0&&(a+c)%k==0&&(b+c)%k==0)
//					sum++;
//			}
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}



//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		long long n, m, a, b, e;
//		scanf("%lld%lld", &n, &m);
//		long long sum = 0;
//		for (int i = 1;i <= 2;i++)
//		{
//			scanf("%lld%lld", &a, &b);
//			long long top = 0;
//			if(a)
//				top = (long long)round(-1.0 * b / (2 * a));
//			long long t1, t2, t3;
//			t2 = a * top * top + b * top;
//			if (i == 1)
//			{
//				t1 = a * (n-1) * (n-1) - b * (n - 1);
//				t3 = a * (n-1) * (n-1) + b * (n - 1);
//			}
//			else
//			{
//				t1 = a * (m - 1) * (m - 1) - b * (m - 1);
//				t3 = a * (m - 1) * (m - 1) + b * (m - 1);
//			}
//			if (t2 > t3)
//				t2 = t3;
//			if(i == 1)
//			if (top > -1 * n && top < n)
//			{
//				if (t2 > t1)
//					t2 = t1;
//			}
//			else
//			{
//				if (top > -1 * m && top < m)
//				{
//					if (t2 > t1)
//						t2 = t1;
//				}
//			}
//			sum += t2;
//		}
//		scanf("%lld", &e);
//		sum += e;
//		printf("%lld\n", sum);
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		long long a, b, c, d, e,n,m;
//		scanf("%lld%lld", &n, &m);
//		scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e);
//		long long sum = 0xffffffffffffff,tmp = 0;
//		for (int i = 1 - n;i < n;i++)
//		{
//			for (int j = 1 - m;j < m;j++)
//			{
//				tmp = a * i * i + b * i + c * j * j + d * j;
//				if (tmp < sum)
//					sum = tmp;
//			}
//		}
//		printf("%lld\n", sum + e);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int a = 0, b = 1, c = a + b;
//	int s, m;
//	while (1)
//	{
//		c = a + b;
//		if (c >= n)
//		{
//			if (c == n)
//			{
//				s = c;
//			}
//			else
//			{
//				s = b;
//			}
//			m = c;
//			break;
//		}
//		a = b;
//		b = c;
//	}
//	printf("%d\n%d", s, m);
//	return 0;
//}

//typedef struct p
//{
//	char name[51];
//	char b;
//	int c;
//}p;
//p arr[10010];
//int cmp(const void* e1, const void* e2)
//{
//	if (((p*)e1)->c != ((p*)e2)->c)
//		return ((p*)e2)->c - ((p*)e1)->c;
//	else if (((p*)e2)->b != ((p*)e1)->b)
//		return ((p*)e2)->b - ((p*)e1)->b;
//	else
//		return strcmp(((p*)e1)->name, ((p*)e2)->name);
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%s %d %d", arr[i].name, &arr[i].b, &arr[i].c);
//		}
//		qsort(arr, n, sizeof(p), cmp);
//		for (int i = 0;i < n;i++)
//		{
//			printf("%s %d %d\n", arr[i].name, arr[i].b, arr[i].c);
//		}
//		puts("");
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	int sum = 0;
//	scanf("%d", &n);
//	getchar();
//	for (int i = 0;i < n;i++)
//	{
//		int t;
//		t = getchar() - '0';
//		if (t == 0 || t == 6 || t == 9)
//			sum++;
//		else if (t == 8)
//			sum += 2;
//	}
//	printf("%d", sum);
//	return 0;
//}

//
//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		printf("%d-->", n);
//		int jud = 0;
//		int arr[100] = { 0 };
//		if (n < 0)
//		{
//			n *= -1;
//			jud = 1;
//		}
//		if (jud)
//			printf("-");
//		int len = 0;
//		for (int i = 0;n;i++)
//		{
//			arr[i] = n % 2;
//			n /= 2;
//			len = i;
//		}
//		for (int i = len;i >= 0;i--)
//		{
//			printf("%d", arr[i]);
//		}
//		puts("");
//	}
//	return 0;
//}


//void f(int n)
//{
//    if (n)
//        f(n / 2);
//    else
//        return;
//    printf("%d", abs(n) % 2);
//}
//
//int main(void)
//{
//    int x;
//    while (scanf("%d", &x) != EOF) {
//        printf("%d-->", x);
//        if (x < 0) {
//            printf("-");
//        }
//        if (x == 0) {
//            printf("0\n");
//            continue;
//        }
//        f(x);
//        printf("\n");
//    }
//    return 0;
//}



//int main()
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	while (t--)
//	{
//		char c1, c2;
//		int d1, d2;
//		int sum = 0;//总伤害
//		char c = 0;//附着元素
//		char C = 0;//第二附着
//		scanf("%c %c %d %d", &c1, &c2, &d1, &d2);
//		getchar();
//		if (c1 == c2)//无特殊反应
//		{
//			if (c2 != 'E' && c1 >= 'A' && c1 <= 'Z')//仅不为风元素且为强元素时附着
//				c = c1;
//			sum += d1 + d2;//伤害计算公式一致
//		}
//		else//元素反应
//		{
//			if (c2 == 'E')//扩散
//			{
//				if (c1 >= 'A' && c1 <= 'Z')//强扩散
//				{
//					sum = (d1 * 2 + d2) * 2;
//					c = c1;
//				}
//				else//弱扩散
//				{
//					sum = (d1 + d2) + 2;
//				}
//			}
//			else//元素反应
//			{
//				if (abs(c1 - c2) > 10)//强弱
//				{
//					sum = d1 + d2 + 2 * d1 * d2;
//					c = c1 < c2 ? c1 : c2;
//				}
//				else if (abs(c1 - c2) < 10 && c1 >= 'A' && c1 <= 'Z')//强强
//				{
//					sum = d1 + d2 + 3 * d1 * d2;
//					c = c1 + ('a' - 'A');//附着弱元素
//					C = c2 + ('a' - 'A');
//				}
//				else if (abs(c1 - c2) < 10 && c1 >= 'a' && c1 <= 'z')//弱弱
//				{
//					sum = d1 + d2 + d1 * d2;
//				}
//			}
//		}
//		printf("%d\n", sum);
//		if (c)
//			printf("%c", c);
//		if (C)
//			printf(" %c", C);
//		puts("");
//	}
//	return 0;
//}





//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	if (a > 0)
//		b *= -1;
//	else
//		b *= 2;
//	if (abs(b) % 2 == 1)
//	{
//		if (a * b < 0)
//			a *= b / abs(b);
//	}
//	else
//	{
//		if (a * b > 0)
//			a *= b / abs(b);
//	}
//	printf("%d", a - b);
//	return 0;
//}



//int main()
//{
//	char t;
//	while (t = getchar(), ~t)
//	{
//		if (t >= 'a' && t <= 'z')
//		{
//			if (t >= 'a' && t <= 'c')
//				printf("2");
//			else if (t >= 'd' && t <= 'f')
//				printf("3");
//			else if (t >= 'g' && t <= 'i')
//				printf("4");
//			else if (t >= 'j' && t <= 'l')
//				printf("5");
//			else if (t >= 'm' && t <= 'o')
//				printf("6");
//			else if (t >= 'p' && t <= 's')
//				printf("7");
//			else if (t >= 't' && t <= 'v')
//				printf("8");
//			else if (t >= 'w' && t <= 'z')
//				printf("9");
//		}
//		else if (t >= 'A' && t <= 'Z')
//		{
//			t += ('a' - 'A') + 1;
//			if (t > 'z')
//				t -= ('z' - 'a') + 1;
//			printf("%c", t);
//		}
//		else
//			printf("%c", t);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int a[8] = { 0 };
//	while (n--)
//	{
//		int t;
//		char arr[50];
//		scanf("%d-%s", &t, arr);
//		if (t >= 1 && t <= 25)
//			a[0]++;
//		else if (t >= 26 && t <= 55)
//			a[1]++;
//		else if (t >= 56 && t <= 69)
//			a[2]++;
//		else if (t >= 70 && t <= 103)
//			a[3]++;
//		else if (t >= 104 && t <= 125)
//			a[4]++;
//		else if (t >= 200 && t <= 230)
//			a[5]++;
//		else if (t >= 231 && t <= 250)
//			a[6]++;
//		else
//			a[7]++;
//		
//	}
//	for (int i = 0;i < 8;i++)
//	{
//		if (i)
//			printf(" ");
//		printf("%d", a[i]);
//	}
//	return 0;
//}

//typedef struct
//{
//	char name[10];
//	struct node* next;
//}node;
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	node* head = (node*)malloc(sizeof(node));
//	head->next = NULL;
//	node* p = head->next;
//	node* q = head;
//	while (t--)
//	{
//		char tmp[10] = { 0 };
//		scanf("%s", tmp);
//		for (p = head->next,q = head;p != NULL;p = p->next,q = q->next)
//		{
//			if (strcmp(p->name, tmp) == 0)
//			{
//				if (q == head)
//					break;
//				q->next = p->next;
//				p->next = head->next;
//				head->next = p;
//				break;
//			}
//		}
//		if (p == NULL)
//		{
//			p = (node*)malloc(sizeof(node));
//			strcpy(p->name, tmp);
//			p->next = head->next;
//			head->next = p;
//		}
//	}
//	for (p = head->next;p != NULL;p = p->next)
//	{
//		printf("%s\n", p->name);
//	}
//	return 0;
//}

//#include<stdio.h>
//int  main()
//{
//    int n, m;
//    while (~scanf("%d %d", &n, &m))
//        printf("%d\n", m);
//    return 0;
//}

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int sum = 0;
//	for (int i = 1;i < n;i++)
//		for (int j = 1;j < n / 2;j++)
//			for (int x = 1;x < n / 5;x++)
//				if (i + 2 * j + 5 * x == n)
//					sum++;
//	printf("%d", sum);
//	return 0;
//}

//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int arr[100010];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int len;
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d", &arr[i]);
//		len = i;
//	}
//	qsort(arr, len + 1, sizeof(arr[0]), cmp);
//	for (int i = 0;i <= len;i++)
//		printf("%d ", arr[i]);
//	return 0;
//}


//int main()
//{
//	int n,sum = 0,x,tmp;
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%d", &x);
//		tmp = x % 10;
//		for (x /= 10;x;x /= 10)
//			tmp -= x % 10;
//		if (tmp > 0)
//			sum++;
//	}
//	printf("%d", sum);
//	return 0;
//}


//int main()
//{
//	int t,d;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d", &d);
//		for (int x = 1;x<=1000;x++)
//			for (int y = 1;y<=1000;y++)
//				if (x * x - d * y * y == 1)
//				{
//					printf("%d %d\n", x, y);
//					goto ss;
//				}
//	ss:;
//	}
//	return 0;
//}


//int main()
//{
//	int arr[10];
//		
//	return 0;
//}


//int main()
//{
//	int t, n, sum = 0,tmp;
//	scanf("%d", &t);
//	while (t--)
//	{
//		sum = 0;
//		scanf("%d", &n);
//		while (n--)
//		{
//			scanf("%d", &tmp);
//			if (tmp % 2 != 0)
//				sum += tmp;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	while (n--)
//	{
//		double tmp;
//		scanf("%lf", &tmp);
//		if (tmp/1.2 == tmp / 3.0 + 50)
//			puts("All");
//		else if (tmp/1.2 > tmp / 3.0 + 50)
//			puts("Bike");
//		else
//			puts("Walk");
//	}
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n, ask, arr[1010] = { 0 };
//		scanf("%d", &n);
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		scanf("%d", &ask);
//		while (ask--)
//		{
//			int tmp;
//			scanf("%d", &tmp);
//			for (int i = 0;i < n;i++)
//			{
//				if (arr[i] == tmp)
//				{
//					puts("Yes");
//					break;
//				}
//				if (i == n - 1)
//					puts("No");
//			}
//		}
//	}
//	return 0;
//}

//int arr[10010];
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n,a,b,s;
//		scanf("%d", &n);
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		scanf("%d %d %d", &a, &b, &s);
//		for (int i = a;i <= b;i++)
//		{
//			s += arr[i];
//		}
//		printf("%d\n", s);
//	}
//	return 0;
//}


//#include <stdio.h>
//void bubble_sort(int arr[], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz - 1; i++)
//    {
//        int j = 0;
//        for (j = 0; j < sz - i - 1; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//            }
//        }
//    }
//}
//int main()
//{
//    int i = 1;
//    int arr[1010];
//    int t, n, k, m, x, y = 0, w = 1;
//    scanf("%d", &t);
//    for (t; t >= 1; t--)
//    {
//        scanf("%d%d%d", &n, &k, &m);
//        int sz = m;
//        for (i; i <= m; i++)
//        {
//            scanf("%d", &arr[i]);
//        }
//        bubble_sort(arr, sz);
//        for (w; w <= k; w++)
//        {
//            y += (arr[w]);
//        }
//        if (y >= n)
//        {
//            int x;
//            x = y - n;
//            printf("%d", x);
//        }
//        else
//        {
//            printf("%", 0);
//        }
//        y = 0;
//        x = 0;
//    }
//    return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	while (t--)
//	{
//		int sum = 0;
//		char tmp;
//		while (scanf("%c", &tmp), tmp != '\n')
//			if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u')
//				sum++;
//		printf("%d\n", sum);
//	}
//	return 0;
//}


//typedef struct
//{
//	char name[31];
//	int a, b, sum;
//}stu;
//stu arr[101];
//int cmp(const void* e1, const void* e2)
//{
//	return ((stu*)e2)->sum - ((stu*)e1)->sum;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%s %d %d", arr[i].name, &arr[i].a, &arr[i].b);
//			arr[i].sum = arr[i].a + arr[i].b;
//		}
//		qsort(arr, n, sizeof(stu), cmp);
//		for (int i = 0;i < n;i++)
//		{
//			printf("%s\n", arr[i].name);
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n1, n2, n3;
//		char a, b;
//		scanf("%d %c %d %c %d", &n1, &a, &n2, &b, &n3);
//		if (a == '+' && b == '+')
//			printf("%d\n", n1 + n2 + n3);
//		else if (a == '+' && b == '-')
//			printf("%d\n", n1 + n2 - n3);
//		else if (a == '+' && b == '*')
//			printf("%d\n", n1 + n2 * n3);
//		else if (a == '+' && b == '/')
//			printf("%d\n", n1 + n2 / n3);
//		else if (a == '-' && b == '+')
//			printf("%d\n", n1 - n2 + n3);
//		else if (a == '-' && b == '-')
//			printf("%d\n", n1 - n2 - n3);
//		else if (a == '-' && b == '*')
//			printf("%d\n", n1 - n2 * n3);
//		else if (a == '-' && b == '/')
//			printf("%d\n", n1 - n2 / n3);
//		else if (a == '*' && b == '+')
//			printf("%d\n", n1 * n2 + n3);
//		else if (a == '*' && b == '-')
//			printf("%d\n", n1 * n2 - n3);
//		else if (a == '*' && b == '*')
//			printf("%d\n", n1 * n2 * n3);
//		else if (a == '*' && b == '/')
//			printf("%d\n", n1 * n2 / n3);
//		else if (a == '/' && b == '+')
//			printf("%d\n", n1 / n2 + n3);
//		else if (a == '/' && b == '-')
//			printf("%d\n", n1 / n2 - n3);
//		else if (a == '/' && b == '*')
//			printf("%d\n", n1 / n2 * n3);
//		else if (a == '/' && b == '/')
//			printf("%d\n", n1 / n2 / n3);
//		else if (a == '%' && b == '+')
//			printf("%d\n", n1 % n2 + n3);
//		else if (a == '%' && b == '%')
//			printf("%d\n", n1 % n2 % n3);
//		else if (a == '%' && b == '-')
//			printf("%d\n", n1 % n2 - n3);
//		else if (a == '%' && b == '*')
//			printf("%d\n", n1 % n2 * n3);
//		else if (a == '%' && b == '/')
//			printf("%d\n", n1 % n2 / n3);
//		else if (a == '+' && b == '%')
//			printf("%d\n", n1 + n2 % n3);
//		else if (a == '-' && b == '%')
//			printf("%d\n", n1 - n2 % n3);
//		else if (a == '*' && b == '%')
//			printf("%d\n", n1 * n2 % n3);
//		else if (a == '/' && b == '%')
//			printf("%d\n", n1 / n2 % n3);
//	}
//	return 0;
//}



//int main()
//{
//	int n, sum[2] = { 0 },a,b;
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%d/%d", &a, &b);
//		if (sum[1] == 0)//第一个数时
//		{
//			sum[0] += a;
//			sum[1] += b;
//		}
//		else//多个数时
//		{
//			if (sum[1] > b)//前面分母大
//			{
//				if (sum[1] % b == 0)//两个分母成倍
//				{
//					int tmp = sum[1] / b;
//					b = sum[1];
//					a *= tmp;
//				}
//				else//不成倍
//				{
//					sum[1] *= b;
//					sum[0] *= b;
//					b *= sum[1];
//					a *= sum[1];
//				}
//			}
//			if (sum[1] < b)//后面分母大
//			{
//				if (b % sum[1] == 0)//两个分母成倍
//				{
//					int tmp = b / sum[1];
//					sum[1] = b;
//					sum[0] *= tmp;
//				}
//				else//不成倍
//				{
//					int t1 = sum[1];
//					sum[1] *= b;
//					sum[0] *= b;
//					b *= t1;
//					a *= t1;
//				}
//			}
//			sum[0] += a;
//		}
//	}
//	int zs;
//	if (sum[0] || sum[1])
//	{
//		zs = sum[0] / sum[1];
//		sum[0] -= zs * sum[1];
//		if (zs < 0)
//			sum[0] = abs(sum[0]);
//		int i = 1;
//		while (i)
//		{
//			i = 0;
//			if (sum[0] % 2 == 0 && sum[1] % 2 == 0)
//			{
//				sum[0] /= 2;
//				sum[1] /= 2;
//				i = 1;
//			}
//			if (sum[0] % 3 == 0 && sum[1] % 3 == 0)
//			{
//				sum[0] /= 3;
//				sum[1] /= 3;
//				i = 1;
//			}
//			if (sum[0] % 5 == 0 && sum[1] % 5 == 0)
//			{
//				sum[0] /= 5;
//				sum[1] /= 5;
//				i = 1;
//			}
//			if (sum[0] % 7 == 0 && sum[1] % 7 == 0)
//			{
//				sum[0] /= 7;
//				sum[1] /= 7;
//				i = 1;
//			}
//		}
//	}
//	else
//		zs = 0;
//	if (zs)
//		printf("%d ", zs);
//	if (sum[0])
//		printf("%d/%d", sum[0], sum[1]);
//	if (zs == 0 && sum[0] == 0)
//		printf("0");
//	return 0;
//}

//int fun(int n)
//{
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 2;
//	if (n == 3)
//		return 4;
//	return fun(n - 1) + fun(n - 2) + fun(n - 3);
//}
//int main()
//{
//	int n;
//	while (scanf("%d", &n), n)
//	{
//		printf("%d\n", fun(n));
//	}
//	return 0;
//}


//int fun(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	int a = 1, b = 1, c = 0;
//	for (int i = 3;i <= n;i++)
//	{
//		c = a + b;
//		if (c >= 26)
//			c %= 26;
//		a = b;
//		b = c;
//	}
//	if (c == 0)
//		c = 26;
//	return c;
//}
//
//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		printf("%c\n", fun(n)+'a'-1);
//	}
//	return 0;
//}

//int fun(int n)
//{
//	int sum = 0;
//	for (int i = 1;i <= n;i++)
//	{
//		if (n % i == 0)
//			sum++;
//	}
//	return sum;
//}
//int  main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int k, sum = 0;
//		scanf("%d", &k);
//		for (int x = 1;x <= 1001;x++)
//		{
//			if (x == 1001)
//			{
//				printf("-1\n");
//				break;
//			}
//			if (fun(x) == k)
//			{
//				printf("%d\n", x);
//				break;
//			}
//		}
//	}
//	return 0;
//}


//int main()
//{
//	double x1, x2, h1, h2, m1, m2;
//	scanf("%lf %lf %lf %lf %lf %lf", &x1, &h1, &m1, &x2, &h2, &m2);
//	if (x2 < x1)
//		x2 += 7;
//	if (x2 - x1 == 0)
//		puts("Y e s");
//	else if (x2 - x1 == 1 && h2 + (24 - h1) + (m2 - m1) / 60 <= 24)
//		puts("Y e s");
//	else
//		puts("N o");
//	return 0;
//}



//int main()
//{
//	char arr[100] = { 0 };
//	while (gets(arr), strcmp(arr, "END"))
//	{
//		for (int i = 0;i < strlen(arr);i++)
//		{
//			if (arr[i] == 'A' || arr[i] == 'F' || arr[i] == 'W')
//				printf("I");
//			else if (arr[i] == 'C')
//				printf("L");
//			else if (arr[i] == 'M')
//				printf("o");
//			else if (arr[i] == 'S')
//				printf("v");
//			else if (arr[i] == 'D' || arr[i] == 'P' || arr[i] == 'G' || arr[i] == 'B')
//				printf("e");
//			else if (arr[i] == 'L')
//				printf("Y");
//			else if (arr[i] == 'X')
//				printf("u");
//			else
//				printf("%c", arr[i]);
//		}
//		puts("");
//	}
//	return 0;
//}


//int main()
//{
//	int n, arr[1010] = { 0 },det = 0;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = n - 2;i >= 0;i--)
//	{
//		for (int j = n - 1;j > i;j--)
//		{
//			if (arr[i] > arr[j])
//			{
//				det = arr[i] - arr[j];
//				arr[i] -= det;
//				arr[j] += det;
//			}
//		}
//	}
//	for (int i = 0;i < n;i++)
//	{
//		if (i)
//			printf(" ");
//		printf("%d", arr[i]);
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int arr[1025] = { 0 };
//		int n;
//		scanf("%d", &n);
//		for (int i = 0;i < n;i++)
//		{
//			for (int j = 0;j < n;j++)
//			{
//				if (j)
//					printf(" ");
//				int tmp;
//				scanf("%d", &tmp);
//				if (arr[tmp] == 0)
//				{
//					arr[tmp] = 1;
//					printf("%d", tmp);
//				}
//				else
//					printf("X");
//			}
//			puts("");
//		}
//		puts("");
//	}
//	return 0;
//}



//int main()
//{
//	char arr[15] = { 0 };
//	while (~scanf("%s", arr))
//	{
//		int sum = 0;
//		int count = 1;
//		for (int i = 0;i < 11;i++)
//		{
//			if (i != 1 && i != 5)
//			{
//				sum += (arr[i] - '0')*count;
//				count++;
//			}
//		}
//		if (arr[12] == 'X')
//			arr[12] = '0' + 10;
//		if (sum%11 + '0' == arr[12])
//			puts("Right");
//		else
//		{
//			if (sum % 11 == 10)
//				arr[12] = 'X';
//			else
//				arr[12] = sum%11 + '0';
//			printf("%s\n", arr);
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int n,kk = 3,dup = 0;
//	scanf("%d", &n);
//	while (n--)
//	{
//		char t1[10], t2[10];
//		int k = 0, d = 0;
//		scanf("%s %s", t1, t2);
//		if (strcmp(t1, "Metal") == 0)
//			k = 1;
//		else if (strcmp(t1, "Wood") == 0)
//			k = 2;
//		else if (strcmp(t1, "Earth") == 0)
//			k = 3;
//		else if (strcmp(t1, "Water") == 0)
//			k = 4;
//		else if (strcmp(t1, "Fire") == 0)
//			k = 5;
//		if (strcmp(t2, "Metal") == 0)
//			d = 1;
//		else if (strcmp(t2, "Wood") == 0)
//			d = 2;
//		else if (strcmp(t2, "Earth") == 0)
//			d = 3;
//		else if (strcmp(t2, "Water") == 0)
//			d = 4;
//		else if (strcmp(t2, "Fire") == 0)
//			d = 5;
//		if (k - d == -1 || k - d == 4)
//			kk++;
//		else if (d - k == -1 || d - k == 4)
//			dup++;
//	}
//	if (kk > dup)
//		printf("KK");
//	else if (dup > kk)
//		printf("Dup4");
//	else
//		printf("Draw");
//	return 0;
//}

//typedef enum{met,wod,wat,fir,ear}ele;
//int main()
//{
//	ele tmp;
//	scanf("%s", &tmp);
//	printf("%s", tmp);
//	/*char t[4] = "wod";
//	tmp = wat;
//	tmp = t;*/
//	return 0;
//}

//int main()
//{
//	int n, m;
//	double h;
//	while (~scanf("%d %d %lf", &n, &m, &h))
//	{
//		double v = 0;
//		for (int i = 0;i < n;i++)
//		{
//			for (int j = 0;j < m;j++)
//			{
//				double sea;
//				scanf("%lf", &sea);
//				if (sea <= h)
//					sea = h - sea;
//				else
//					sea = 0;
//				v += 100 * sea;
//			}
//		}
//		printf("%d\n", (int)v);
//	}
//	return 0;
//}



//int main()
//{
//	int t,;
//	scanf("%d", &t);
//	while (t--)
//	{
//
//	}
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n, m;
//		double x, a, b;
//		int sum = 0;
//		scanf("%lf %d %d %lf %lf", &x, &n, &m, &a, &b);
//		if (a >= b)//男生抬得多
//		{
//			if (n * a + m * b < x)//抬不完
//				sum = -1;
//			else if (n * a >= x)//男生能抬完
//				sum = ceil(x / a);
//			else//男生 抬不完
//				sum = ceil((x - n * a) / b) + n;
//		}
//		else//女生抬得多
//		{
//			if (n * a + m * b < x)//抬不完
//				sum = -1;
//			else if (m * b >= x)//女生能抬完
//				sum = ceil(x / b);
//			else//女生 抬不完
//				sum = ceil((x - m * b) / a) + m;
//		}
//		if (sum == -1)
//			puts("you are too heavy to move!");
//		else
//			printf("%d\n", sum);
//	}
//	return 0;
//}

//int arr[25][4];
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int t1, t2, t3;
//		scanf("%d %d %d", &t1, &t2, &t3);
//		arr[t1][t2] += t3;
//	}
//	int a, b;
//	while (scanf("%d %d", &a, &b), a && b)
//	{
//		printf("%d\n", arr[a][b]);
//	}
//	return 0;
//}

//int cmp(const void* e1, const void* e2)
//{
//	int a = *(int*)e1, b = *(int*)e2;
//	if ((a / 10) % 10 > (b / 10) % 10)
//		return 1;
//	else if ((a / 10) % 10 < (b / 10) % 10)
//		return -1;
//	else if ((a / 100) > (b / 100))
//		return 1;
//	else if ((a / 100) < (b / 100))
//		return -1;
//	else if (a % 10 > b % 10)
//		return 1;
//	else return -1;
//}
//int main()
//{
//	int t, n, k;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int arr[101] = { 0 };
//		scanf("%d %d", &n, &k);
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		qsort(arr, n, sizeof(int), cmp);
//		printf("%d\n", arr[k]);
//	}
//	return 0;
//}


//int main()
//{
//	long long n, f = 0,z = 0,fmin = -1*0xffffffffff, zm = 0xffffffffff,fmax = 0;
//	scanf("%lld", &n);
//	while (n--)
//	{
//		long long t;
//		scanf("%lld",&t);
//		if (t > 0)
//		{
//			z++;
//			if (t < zm)
//				zm = t;
//		}
//		else
//		{
//			f++;
//			if (t > fmin)
//				fmin = t;
//			if(t < fmax)
//				fmax = t;
//		}
//	}
//	if (z != 0)
//	{
//		if (f % 2 == 0)
//			printf("%lld", zm);
//		else
//			printf("%lld", fmin);
//	}
//	else
//	{
//		if (f % 2 == 0)
//			printf("%lld", fmax);
//		else
//			printf("%lld", fmin);
//	}
//	return 0;
//}



//int main()
//{
//	int n;
//	char ch;
//	while (~scanf("%d %c", &n, &ch))
//	{
//		int len = 7 + n * 4, hi = 4 + n,Z= 2 + 2 * n,N = 6 + 2*n;
//		for (int i = 1;i <= hi;i++)
//		{
//			int i2 = 0;
//			for (int j = 1;j <= len;j++)
//			{
//				if (i == 1 || i == hi)
//					printf("-");
//				else if (i == 2 || i == hi - 1)
//					if (j == 1 || j == len)
//						printf("|");
//					else
//						printf(" ");
//				else
//				{
//					if (j == 1 || j == len)
//						printf("|");
//					else if (j == 3 || j == 2 + n || j == 5 + 2 * n || j == 4 + 3 * n || j == 6 + 3 * n || j == 5 + 4 * n)//打印所有竖线
//						printf("%c", ch);
//					else if(j > 3 && j < 2 + n && i == (hi+1)/2)//H的横线
//						printf("%c", ch);
//					else if ((i == 3 || i == hi-2) && j >= 4 + n && j <= 3 + 2 * n)//打印Z的横线
//						printf("%c", ch);
//					else if (i > 3 && i < hi - 2 && j == Z)
//					{
//						printf("%c", ch);
//						Z--;
//					}
//					else if (i > 3 && i < hi - 2 && j == N && (i2 == 0 || i2 != i))
//					{
//						printf("%c", ch);
//						N++;
//						i2 = i;
//					}
//					else if(j > 6 + 3 * n && j < 5 + 4 * n && i == hi - 2)//U的横线
//						printf("%c", ch);
//					else printf(" ");
//				}
//			}
//			puts("");
//
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int t,n;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d",&n);
//		for (int x = 0;x <= n / 2;x++)
//		{
//			for (int y = 0;y <= n / 3;y++)
//			{
//				if (x * 2 + 3 * y == n)
//				{
//					printf("%d %d\n", x, y);
//					goto ss;
//				}
//			}
//		}
//		puts("WA");
//	ss:;
//	}
//	return 0;
//}


//int main()
//{
//	int k;
//	scanf("%d", &k);
//	double sum = 0;
//	for (long long n = 1;1;n++)
//	{
//		sum += 1.0/ n;
//		if (sum > k)
//		{
//			printf("%lld", n);
//			return 0;
//		}
//	}
//	return 0;
//}

//int tree[30], a[30];
//void gettree(int n)
//{
//	printf("%d-", n);
//	if()
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	gettree(t);
//	return 0;
//}




//int main()
//{
//	for (int n = 1988;n <= 1989;n++)
//	{
//		for (int y = 1;y <= 12;y++)
//		{
//			for (int r = 1;1;r++)
//			{
//				if ((y == 4 || y == 6 || y == 9 || y == 11) && r == 31)
//					break;
//				else if (y == 2)
//				{
//					if (r == 30 && n == 1988)
//						break;
//					else if (r == 29 && n == 1989)
//					{
//						break;
//					}
//				}
//				else if (r == 32)
//					break;
//				long long tmp = (n * 10000 + y * 100 + r);
//				long long t = (long long)sqrt((double)(n * 10000 + y * 100 + r));
//				int jud = 1;
//				for (int i = 2;i < t;i++)
//				{
//					if (tmp % i == 0)
//					{
//						jud = 0;break;
//					}
//				}
//				if (jud)
//					printf("%lld\n",tmp);
//			}
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n, k;
//	scanf("%d %d", &n, &k);
//	int arr[110] = { 0 };
//	int t = k % n;
//	int count = 0;
//	for (int i = n-t;count < n;i++)
//	{
//		if (i == n)
//			i = 0;
//		scanf("%d", &arr[i]);
//		count++;
//	}
//	for (int i = 0;i < n;i++)
//	{
//		if (i)
//			printf(" ");
//		printf("%d", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	while (1)
//	{
//		puts("1-Ball");
//		puts("2-Cylinder");
//		puts("3-Cone");
//		puts("other-Exit");
//		puts("Please enter your command:");
//		int input;
//		scanf("%d", &input);
//		if (input == 1)
//		{
//			puts("Please enter the radius:");
//			double r;
//			scanf("%lf", &r);
//			printf("%.2lf\n", (4.0 / 3) * 3.14159 * r * r * r);
//		}
//		else if (input == 2)
//		{
//			puts("Please enter the radius and the height:");
//			double r,h;
//			scanf("%lf %lf", &r,&h);
//			printf("%.2lf\n", 3.14159 * r * r * h);
//		}
//		else if (input == 3)
//		{
//			puts("Please enter the radius and the height:");
//			double r,h;
//			scanf("%lf %lf", &r,&h);
//			printf("%.2lf\n", (1.0 / 3) * 3.14159 * r * r * h);
//		}
//		else return 0;
//	}
//	return 0;
//}



//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int a = 0;
//	while (n--)
//	{
//		getchar();
//		int jud = 1;
//		int sum = 0;
//		char arr[20] = { 0 };
//		for (int i = 0;i < 17;i++)
//		{
//			scanf("%c", &arr[i]);
//			if (arr[i] >= '0' && arr[i] <= '9')
//			{
//				if (i == 0)
//					sum += (arr[i] - '0') * 7;
//				else if (i == 1)
//					sum += (arr[i] - '0') * 9;
//				else if (i == 2)
//					sum += (arr[i] - '0') * 10;
//				else if (i == 3)
//					sum += (arr[i] - '0') * 5;
//				else if (i == 4)
//					sum += (arr[i] - '0') * 8;
//				else if (i == 5)
//					sum += (arr[i] - '0') * 4;
//				else if (i == 6)
//					sum += (arr[i] - '0') * 2;
//				else if (i == 7)
//					sum += (arr[i] - '0') * 1;
//				else if (i == 8)
//					sum += (arr[i] - '0') * 6;
//				else if (i == 9)
//					sum += (arr[i] - '0') * 3;
//				else if (i == 10)
//					sum += (arr[i] - '0') * 7;
//				else if (i == 11)
//					sum += (arr[i] - '0') * 9;
//				else if (i == 12)
//					sum += (arr[i] - '0') * 10;
//				else if (i == 13)
//					sum += (arr[i] - '0') * 5;
//				else if (i == 14)
//					sum += (arr[i] - '0') * 8;
//				else if (i == 15)
//					sum += (arr[i] - '0') * 4;
//				else if (i == 16)
//					sum += (arr[i] - '0') * 2;
//			}
//			else
//				jud = 0;
//		}
//		scanf("%c", &arr[17]);
//		if (jud == 0)
//		{
//			printf("%s\n", arr);
//			a++;;
//		}
//		else if ((sum % 11 == 0 && arr[17] != '1') || \
//			(sum % 11 == 1 && arr[17] != '0') || \
//			(sum % 11 == 2 && arr[17] != 'X') || \
//			(sum % 11 == 3 && arr[17] != '9') || \
//			(sum % 11 == 4 && arr[17] != '8') || \
//			(sum % 11 == 5 && arr[17] != '7') || \
//			(sum % 11 == 6 && arr[17] != '6') || \
//			(sum % 11 == 7 && arr[17] != '5') || \
//			(sum % 11 == 8 && arr[17] != '4') || \
//			(sum % 11 == 9 && arr[17] != '3') || \
//			(sum % 11 == 10 && arr[17] != '2'))
//		{
//			printf("%s\n", arr);
//			a++;
//		}
//	}
//	if (a == 0)
//		puts("All passed");
//	return 0;
//}



//int isPrime(int n)
//{
//	int i;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)    // 如果不为素数返回0 
//		{
//			return 0;
//		}
//	}
//	return 1;    // 反之则返回1 
//
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	while (n--)
//	{
//		long long t;
//		scanf("%lld", &t);
//		if (isPrime(t))
//			puts("Yes");
//		else
//			puts("No");
//	}
//	return 0;
//}


//int main()
//{
//	int i = 1;
//	char tmp[11],a[11] = {0}, b[11] = {0};
//	while (scanf("%s", tmp), strcmp(tmp, ".") != 0)
//	{
//		if (i == 2)
//			strcpy(a, tmp);
//		else if (i == 14)
//			strcpy(b, tmp);
//		i++;
//	}
//	if (a[0] && b[0])
//		printf("%s and %s are inviting you to dinner...", a, b);
//	else if (a[0])
//		printf("%s is the only one for you...", a);
//	else
//		printf("Momo... No one is for you ...");
//	return 0;
//}


//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		for (int a = 0;2 * a <= n;a++)
//			for (int b = 0;3 * b <= n;b++)
//				for (int c = 0;5 * c <= n;c++)
//					for (int d = 0;7 * d <= n;d++)
//						if (a * 2 + 3 * b + 5 * c + 7 * d == n)
//						{
//							printf("%d\n", a + b + c + d);
//							goto ss;
//						}
//	ss:;
//	}
//	return 0;
//}



//int main()
//{
//	int n, sum = 1, arr[60] = { 0 };
//	arr[1] = 1;
//	scanf("%d", &n);
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1;j <= i - 3;j++)
//		{
//			sum += arr[j];
//			arr[i] += arr[j];
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int arr[1010] = { 0 },n;
//		scanf("%d", &n);
//		for (int i = 1;i <= n;i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		arr[0] = 0;arr[n + 1] = 0;
//		int m[500];int j = 0;
//		for (int i = 1;i <= n;i++)
//		{
//			if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
//			{
//				m[j] = arr[i];
//				j++;
//			}
//		}
//		int max = 0, min = 0x7fffffff;
//		for (int i = 0;i < j;i++)
//		{
//			if (m[i] > max)
//				max = m[i];
//			if (m[i] < min)
//				min = m[i];
//		}
//		printf("%d %d\n", min, max);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	while (n--)
//	{
//		int a, b;
//		scanf("%d %d", &a, &b);
//		for(int x = 0;x < b;x++)
//		{
//			if(x == 0)
//			for (int i = 1;i <= a;i++)
//			{
//				for (int j = 1;j <= a;j++)
//				{
//					if (i + j == a + 1 || i == j)
//						printf("X");
//					else
//						printf(" ");
//				}
//				puts("");
//			}
//			else
//				for (int i = 2;i <= a;i++)
//				{
//					for (int j = 1;j <= a;j++)
//					{
//						if (i + j == a + 1 || i == j)
//							printf("X");
//						else
//							printf(" ");
//					}
//					puts("");
//				}
//		}
//		puts("");
//	}
//	return 0;
//}


//int main()
//{
//	int n, m;
//	while (~scanf("%d %d", &n, &m))
//	{
//		int* arr = (int*)malloc(sizeof(int) * (n + 1));
//		memset(arr, 0, sizeof(int) * (n + 1));
//		//int arr[100] = { 0 };
//		int count = 0;
//			int x = 0;
//			for (int i = 1;i <= n;i++)
//			{
//				if (arr[i] == 0)
//				{
//					x++;
//					if (x == m)
//					{
//						arr[i] = -1;
//						x = 0;
//						count++;
//					}
//					if (count == n-1)
//						break;
//				}
//				if (i == n)
//					i = 0;
//			}
//		for (int i = 1;i <= n;i++)
//		{
//			if (arr[i] != -1)
//				printf("%d\n", i);
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		int sum = 1;
//		for (int i = 1;i < n;i++)
//		{
//			sum = (sum + 1) * 2;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}
//
//
//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		for (int i = 1; i <= n;i++)
//		{
//			for (int j = 1;j <= n;j++)
//			{
//				if (j < i)
//					printf(" ");
//				else if(j == i || j == n - i + 1)
//					ptintf("1")
//			}
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n, arr[110][110] = { 0 };
//	scanf("%d", &n);
//	for(int i = )
//	return 0;
//}


//int main()
//{
//	int n, jud = 0;;
//	scanf("%d", &n);
//	while (n--)
//	{
//		int t;
//		scanf("%d", &t);
//		if (t == 1)
//			jud = 1;
//	}
//	if (jud)
//		printf("YES");
//	else
//		printf("NO");
//	return 0;
//}


//int main()
//{
//	int t, a;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d", &a);
//		if (a < 15)
//			printf("-1\n");
//		else
//			printf("%d\n", a - 7);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0;n != 1;i++)
//	{
//		if (n % 2 == 0)
//			n /= 2;
//		else
//			n = (3 * n + 1) / 2;
//	}
//	printf("%d", i);
//	return 0;
//}


//int main()
//{
//	char arr[110] = { 0 };
//	int sum = 0;
//	for (int i = 0;scanf("%c", &arr[i]), arr[i] != '\n';i++)
//		sum += arr[i] - '0';
//	int x = 0;
//	for(int i = 0;sum;i++)
//	{
//		arr[i] = sum % 10;
//		x = i;
//		sum /= 10;
//	}
//	for (int i = x;i >= 0;i--)
//	{
//		if (i != x)
//			printf(" ");
//		if (arr[i] == 1)
//			printf("yi");
//		else if (arr[i] == 2)
//			printf("er");
//		else if (arr[i] == 3)
//			printf("san");
//		else if (arr[i] == 4)
//			printf("si");
//		else if (arr[i] == 5)
//			printf("wu");
//		else if (arr[i] == 6)
//			printf("liu");
//		else if (arr[i] == 7)
//			printf("qi");
//		else if (arr[i] == 8)
//			printf("ba");
//		else if (arr[i] == 9)
//			printf("jiu");
//		else if (arr[i] == 0)
//			printf("ling");
//	}
//	return 0;
//}



//int main()
//{
//	int n,max = 0,min = 101,t;
//	char name[110] = { 0 }, id[110] = { 0 }, t1[110] = { 0 }, t2[110] = { 0 }, name2[110] = { 0 }, id2[110] = { 0 };
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%s %s %d", t1, t2, &t);
//		if (t > max)
//		{
//			max = t;
//			strcpy(name, t1);
//			strcpy(id, t2);
//		}
//		if (t < min)
//		{
//			min = t;
//			strcpy(name2, t1);
//			strcpy(id2, t2);
//		}
//	}
//	printf("%s %s\n%s %s", name, id, name2, id2);
//	return 0;
//}

//int arr[110][2];
//int arr2[110];
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e2 - *(int*)e1;
//}
//int main()
//{
//	int k,x = 0;
//	scanf("%d", &k);
//	for (int i = 0;i < k;i++)
//	{
//		scanf("%d", &arr[i][0]);
//	}
//	for (int i = 0;i < k;i++)
//	{
//		int tmp = arr[i][0];
//		while (tmp != 1)
//		{
//			if (tmp % 2 == 0)
//				tmp /= 2;
//			else
//				tmp = (3 * tmp + 1) / 2;
//			for (int j = 0;j < k;j++)
//			{
//				if (tmp == arr[j][0])
//					arr[j][1] = 1;
//			}
//		}
//	}
//	for (int i = 0;i < k;i++)
//	{
//		if (arr[i][1] == 0)
//		{
//			arr2[x] = arr[i][0];
//			x++;
//		}
//	}
//	for (int i = 0;i < x - 1;i++)
//	{
//		for (int j = i;j < x - 1;j++)
//		{
//			if (arr2[j] < arr2[j + 1])
//			{
//				arr2[j] = arr2[j] ^ arr2[j + 1];
//				arr2[j + 1] = arr2[j] ^ arr2[j + 1];
//				arr2[j] = arr2[j] ^ arr2[j + 1];
//			}
//		}
//	}
//	for (int i = 0;i < x;i++)
//	{
//		if (i)
//			printf(" ");
//		printf("%d", arr2[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int b = n / 100;
//	int s = (n % 100) / 10;
//	int g = n % 10;
//	while (b--)
//		printf("B");
//	while (s--)
//		printf("S");
//	for (int i = 1;i <= g;i++)
//		printf("%d", i);
//	return 0;
//}

//int jud(int n)
//{
//	int tmp = (int)sqrt((double)n);
//	for (int i = 2;i <= tmp;i++)
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;
//}
//int arr[1000];
//int main()
//{
//	int n,sum = 0,x = 0;
//	scanf("%d", &n);
//	for (int i = 2;i < n;i++)
//	{
//		if (jud(i))
//		{
//			arr[x] = i;
//			x++;
//		}
//	}
//	for (int i = 1;i < x;i++)
//	{
//		if (arr[i] - arr[i - 1] == 2)
//			sum++;
//	}
//	printf("%d", sum);
//	return 0;
//}


//int main()
//{
//	int n, m, arr[110] = { 0 };
//	scanf("%d %d", &n,&m);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int count = 0;
//	for (int i = n - (m % n);count < n;i++)
//	{
//		if (i == n)
//			i = 0;
//		if (count)
//			printf(" ");
//		printf("%d",arr[i]);
//		count++;
//		if (i == n - 1)
//			i = -1;
//	}
//	return 0;
//}


//int main()
//{
//	char arr[100] = { 0 };
//	gets(arr);
//	for (int i = strlen(arr) - 1;i >= 0;i--)
//	{
//		for (;(arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z') && i >= 0;i--);
//		for (int j = i + 1;arr[j] != 0 && arr[j] != ' ';j++)
//			printf("%c", arr[j]);
//		if (arr[i] == ' ')
//			printf(" ");
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int t, a = 0, b = 0, c = 0;
//    scanf("%d", &t);
//    for (int i = 1;i <= t;i++)
//    {
//        scanf("%d %d %d", &a, &b, &c);
//        printf("Case #%d: ", i);
//        if (a + b > c)
//            puts("true");
//        else
//            puts("false");
//    }
//    return 0;
//}


//int main()
//{
//	char a[110] = { 0 }, b[110] = { 0 };
//	scanf("%s %s", a, b);
//	int la = strlen(a), lb = strlen(b);
//	for (int i = 0;i < la / 2;i++)
//	{
//		a[i] = a[i] ^ a[la - 1 - i];
//		a[la - 1 - i] = a[i] ^ a[la - 1 - i];
//		a[i] = a[i] ^ a[la - 1 - i];
//	}
//	for (int i = 0;i < lb / 2;i++)
//	{
//		b[i] = b[i] ^ b[lb - 1 - i];
//		b[lb - 1 - i] = b[i] ^ b[lb - 1 - i];
//		b[i] = b[i] ^ b[lb - 1 - i];
//	}
//	for (int i = 0;i < lb;i++)
//	{
//		if (a[i] != 0)
//		{
//			if ((i + 1) % 2 != 0)
//				b[i] = (a[i] + b[i] - 2 * '0') % 13;
//			else
//				b[i] = b[i] - a[i] >= 0 ? b[i] - a[i] : b[i] - a[i] + 10;
//		}
//		else
//			b[i] -= '0';
//	}
//	for (int i = lb - 1;i >= 0;i--)
//	{
//		if (b[i] == 10)
//			printf("J");
//		else if (b[i] == 11)
//			printf("Q");
//		else if (b[i] == 12)
//			printf("K");
//		else
//			printf("%d", b[i]);
//	}
//	return 0;



//long long arr[1010];
//int main()
//{
//	long long n, a = 0, b = 0,c = 0,e = 0,dn = 0;
//	double ds = 0;
//	scanf("%lld", &n);
//	int j = 1;
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%lld", &arr[i]);
//		if (arr[i] % 10 == 0)
//			a += arr[i];
//		else if (arr[i] % 5 == 1)
//		{
//			if (j % 2 == 0)
//				b -= arr[i];
//			else
//				b += arr[i];
//			j++;
//		}
//		else if (arr[i] % 5 == 2)
//			c++;
//		else if (arr[i] % 5 == 3)
//		{
//			dn++;
//			ds += arr[i];
//		}
//		else if (arr[i] % 5 == 4 && arr[i] > e)
//			e = arr[i];
//	}
//	if (a == 0)
//		printf("N");
//	else
//		printf("%lld", a);
//	if (j == 1)
//		printf(" N");
//	else
//		printf(" %lld", b);
//	if (c == 0)
//		printf(" N");
//	else
//		printf(" %lld", c);
//	if (dn == 0)
//		printf(" N");
//	else
//		printf(" %.1lf", ds/dn);
//	if (e == 0)
//		printf(" N");
//	else
//		printf(" %lld", e);
//	return 0;
//}

//int arr[10010];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		int t1, t2, t3;
//		scanf("%d-%d %d", &t1,&t2,&t3);
//		arr[t1] += t3;
//	}
//	int max = 0,m;
//	for (int i = 0;i < 10010;i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//			m = i;
//		}
//	}
//	printf("%d %d", m, max);
//	return 0;
//}


//int main()
//{
//	int n, a = 0,b = 0;
//	scanf("%d", &n);
//	while (n--)
//	{
//		int t1, t2, t3, t4;
//		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
//		if (t2 == t1 + t3 && t4 != t1 + t3)
//			b++;
//		else if (t2 != t1 + t3 && t4 == t1 + t3)
//			a++;
//	}
//	printf("%d %d", a, b);
//	return 0;
//}


//typedef long long lint;
//lint arr[10010];
//lint a2[10010];//存放可能是主元的数
//int cmp(const void* e1, const void* e2)
//{
//	return *(lint*)e1 - *(lint*)e2;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)//输入所有数据
//	{
//		scanf("%lld", &arr[i]);
//	}
//	lint x = 0;
//	for (int i = 0;i < n;i++)//检查每个数据
//	{
//		int jud = 0;
//		for (int j = 0;j < n;j++)
//		{
//			if (j < i && arr[j] > arr[i])
//				break;
//			else if (j > i && arr[j] < arr[i])
//				break;
//			jud = j;
//		}
//		if (jud == n - 1)
//		{
//			a2[x] = arr[i];
//			x++;
//		}
//	}
//	printf("%lld\n", x);
//	qsort(a2, x, sizeof(lint), cmp);
//	for (int i = 0;i < x;i++)
//	{
//		if (i)
//			printf(" ");
//		printf("%lld", a2[i]);
//	}
//	return 0;
//}

//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[10];
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, n, sizeof(int), cmp);
//	for (int i = 0;i < n;i++)
//	{
//		if (i)
//			printf(" ");
//		printf("%d", arr[i]);
//	}
//	return 0;
//}

//typedef long long lint;
//lint arr[100010];
//lint my_abs(lint n)
//{
//	return n > 0 ? n : n * -1;
//}
//int cmp(const void* e1, const void* e2)
//{
//	return *(lint*)e1 - *(lint*)e2;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int count = 0;
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < n;j++)
//		{
//			if (j < i && my_abs(arr[j]) > arr[i])
//			{
//				arr[i] *= -1;
//				count++;
//				break;
//			}
//			else if (j > i && arr[j] < arr[i])
//			{
//				arr[i] *= -1;
//				count++;
//				break;
//			}
//		}
//	}
//	qsort(arr, n, sizeof(arr[0]), cmp);
//	printf("%d", n - count);
//	for (int i = count;i < n;i++)
//	{
//		if (i != count)
//			printf(" ");
//		else
//			puts("");
//		printf("%lld", arr[i]);
//	}
//	return 0;
//}

//typedef long long lint;
//int jud(lint n)
//{
//	lint a = (lint)sqrt((double)n);
//	for (lint i = 2;i <= a;i++)
//		if (n % i == 0)
//			return 0;
//	return 1;
//}
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int count = 0,c = 0;
//	for (lint i = 2;count <= m;i++)
//	{
//		if (jud(i))
//		{
//			count++;
//			if (count >= n && count <= m)
//			{
//				if (c)
//					printf(" ");
//				printf("%lld", i);
//				c++;
//				if (c == 10)
//				{
//					puts("");
//					c = 0;
//				}
//			}
//		}
//		if (count == m)
//			break;
//	}
//	return 0;
//}


//int main()
//{
//	char s1[70] = { 0 };
//	char s2[70] = { 0 };
//	scanf("%s %s", s1, s2);
//	int len = strlen(s1) > strlen(s2) ? strlen(s2) : strlen(s1);
//	int c = 0;
//	for (int i = 0;i < len;i++)
//	{
//		if (c == 0 && s1[i] >= 'A' && s1[i] <= 'Z' && s1[i] == s2[i])
//		{
//			int tmp = s1[i] - 'A' + 1;
//			if (tmp == 1)
//				printf("MON ");
//			else if (tmp == 2)
//				printf("TUE ");
//			else if (tmp == 3)
//				printf("WED ");
//			else if (tmp == 4)
//				printf("THU ");
//			else if (tmp == 5)
//				printf("FRI ");
//			else if (tmp == 6)
//				printf("SAT ");
//			else if (tmp == 7)
//				printf("SUN ");
//			c++;
//		}
//		else if (c == 1 && s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N') || (s1[i] >= '0' && s1[i] <= '9')))
//		{
//			int tmp = 0;
//			if (s1[i] >= '0' && s1[i] <= '9')
//				tmp = s1[i] - '0';
//			else
//				tmp = 10 + s1[i] - 'A';
//			printf("%d:", tmp);
//			c++;
//		}
//		if (c == 2)
//			break;
//	}
//	scanf("%s %s", s1, s2);
//	len = strlen(s1) > strlen(s2) ? strlen(s2) : strlen(s1);
//	for (int i = 0;i < len;i++)
//	{
//		if (s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'Z') || (s1[i] >= 'a' && s1[i] <= 'z')))
//		{
//			if (i < 10)
//				printf("0");
//			printf("%d", i);
//		}
//	}
//	return 0;
//}

//int arr[100100];
//int main()
//{
//	for (int i = 0;i < 100100;i++)
//	{
//		arr[i] = 1;
//	}
//	arr[1] = 0;
//	for (int i = 2;i < 100100;i++)
//	{
//		for (int j = 2 * i;j < 100100;j += i)
//			arr[j] = 0;
//	}
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		for (int i = 2;i < 10010;i++)
//		{
//			if (arr[i] == 1 && arr[i + n] == 0)
//			{
//				printf("%d\n", i);
//				break;
//			}
//		}
//	}
//	return 0;
//}

//typedef long long lint;
////lint arr[200010][2];
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		lint max = 0;
//		lint m = 0;
//		lint sum = 0;
//		for (int i = 0;i < n;i++)
//		{
//			lint a, b;
//			scanf("%lld %lld", &a,&b);
//			if (a > max)
//				max = a;
//			if (b > max)
//				max = b;
//			sum += 2 * (a >= b ? b : a);
//		}
//		sum += max * 2;
//		printf("%lld\n", sum);
//	}
//	return 0;
//}



//typedef long long lint;
//lint arr[200010];
//int cmp(const void* e1, const void* e2)
//{
//	return *(lint*)e1 - *(lint*)e2;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		memset(arr, 0, sizeof(arr));
//		int n;
//		scanf("%d", &n);
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%lld", &arr[i]);
//		}
//		qsort(arr, n, sizeof(arr[0]), cmp);
//		lint sum = 0;
//		sum += 2*arr[n - 1] - arr[0] - arr[n - 2];
//		printf("%lld\n", sum);
//	}
//	return 0;
//}


//int main()
//{
//	int n,a,b;
//	scanf("%d", &n);
//	int sum = 0;
//	int arr[110] = { 0 };
//	for (int i = 0;i < n - 1;i++)
//	{
//		int t;
//		scanf("%d", &arr[i]);
//	}
//	scanf("%d %d", &a, &b);
//	for (int i = 0;i < n - 1;i++)
//	{
//		if (i + 1 >= a && i + 1 <= b-1)
//		{
//			sum += arr[i];
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}

//typedef struct kid
//{
//	char name[11];
//	char id[11];
//}kid;
//int main()
//{
//	int n;
//	kid arr[110];
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%s %s", &arr[i].name, &arr[i].id);
//	}
//	for (int i = 0;i < n;i++)
//	{
//		if (strcmp(arr[i].id, "rat") == 0)
//			printf("%s\n", arr[i].name);
//	}
//	for (int i = 0;i < n;i++)
//	{
//		if (strcmp(arr[i].id, "woman") == 0 || strcmp(arr[i].id, "child") == 0)
//			printf("%s\n", arr[i].name);
//	}
//	for (int i = 0;i < n;i++)
//	{
//		if (strcmp(arr[i].id, "man") == 0)
//			printf("%s\n", arr[i].name);
//	}
//	for (int i = 0;i < n;i++)
//	{
//		if (strcmp(arr[i].id, "captain") == 0)
//			printf("%s\n", arr[i].name);
//	}
//	return 0;
//}


int tree[50010];
void fun(int r2)
{
	if (tree[r2] != 0)
		fun(tree[r2]);
	tree[tree[r2]] = r2;	
}
int main()
{
	int n, r1, r2;
	scanf("%d %d %d", &n, &r1, &r2);
	for (int i = 1;i <= n;i++)
	{
		if (i != r1)
			scanf("%d", &tree[i]);
	}
	fun(r2);
	for (int i = 1;i <= n;i++)
	{
		if(i!=r2)
			printf("%d ", tree[i]);
	}
	return 0;
}