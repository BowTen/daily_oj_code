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



int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		char c1, c2;
		int d1, d2;
		int sum = 0;//总伤害
		char c = 0;//附着元素
		char C = 0;//第二附着
		scanf("%c %c %d %d", &c1, &c2, &d1, &d2);
		getchar();
		if (c1 == c2)//无特殊反应
		{
			if (c2 != 'E' && c1 >= 'A' && c1 <= 'Z')//仅不为风元素且为强元素时附着
				c = c1;
			sum += d1 + d2;//伤害计算公式一致
		}
		else//元素反应
		{
			if (c2 == 'E')//扩散
			{
				if (c1 >= 'A' && c1 <= 'Z')//强扩散
				{
					sum = (d1 * 2 + d2) * 2;
					c = c1;
				}
				else//弱扩散
				{
					sum = (d1 + d2) + 2;
				}
			}
			else//元素反应
			{
				if (abs(c1 - c2) > 10)//强弱
				{
					sum = d1 + d2 + 2 * d1 * d2;
					c = c1 < c2 ? c1 : c2;
				}
				else if (abs(c1 - c2) < 10 && c1 >= 'A' && c1 <= 'Z')//强强
				{
					sum = d1 + d2 + 3 * d1 * d2;
					c = c1 + ('a' - 'A');//附着弱元素
					C = c2 + ('a' - 'A');
				}
				else if (abs(c1 - c2) < 10 && c1 >= 'a' && c1 <= 'z')//弱弱
				{
					sum = d1 + d2 + d1 * d2;
				}
			}
		}
		printf("%d\n", sum);
		if (c)
			printf("%c", c);
		if (C)
			printf(" %c", C);
		puts("");
	}
	return 0;
}