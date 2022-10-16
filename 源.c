#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//int sum(char* arr, int len)
//{
//	int ret = 0;
//	for(int i = 0;i < len ;i ++)
//	{ 
//		ret += arr[i];
//	}
//	return ret;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		char arr[60][30];
//		scanf("%d", &n);
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%s", arr[i]);
//		}
//		int lon = 0;
//		for (int i = 0;i < n;i++)
//		{
//			if (strlen(arr[i]) == strlen(arr[lon]))
//			{
//				if (sum(arr[i], strlen(arr[i])) > sum(arr[lon], strlen(arr[lon])))
//					lon = i;
//			}
//			else if (strlen(arr[i]) > strlen(arr[lon]))
//				lon = i;
//		}
//		printf("%s", arr[lon]);
//		if (t != 0)
//			printf("\n");
//	}
//	return 0;
//}



//int main()
//{
//	int x, y,arr[][20];
//	char name;
//	scanf("%d%d", &x, &y);
//	for (int i = 0;i < x;i++)
//	{
//		scanf("%d",arr)
//	}
//	return 0;
//}

//int min(int map[100][100], int i, int j, int m)
//{
//	for (int y = 0;y < m;y++)
//	{
//		if (map[i][y] < map[i][j])
//			return 0;
//	}
//	return 1;
//}
//int max(int map[100][100], int i, int j, int n)
//{
//	for (int x = 0;x < n;x++)
//	{
//		if (map[x][j] > map[i][j])
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int n, m;
//	int map[100][100];
//	scanf("%d%d", &n, &m);
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < m;j++)
//		{
//			scanf("%d", &map[i][j]);
//		}
//	}
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < m;j++)
//		{
//			if (min(map, i, j, m) && max(map, i, j, n))
//			{
//				printf("(%d,%d)", i+1, j+1);
//				return 0;
//			}
//		}
//	}
//	return 0;
//}


//int main() {
//    int n, m, row = 1, col = 1;
//    scanf_s("%d %d", &n, &m);
//    printf("*");   for (col = 1; col <= m && row == 1;col++)
//    {
//        if (col == m)
//        {
//            printf("\n"); break;
//        }
//        printf("*");
//    }
//    if (n != 1)
//    {
//        col = 1;
//        printf("*");
//    }
//    while (row < n)
//    {
//        if (col == m - 1)
//        {
//            row++;
//            printf("*\n");
//            if (row == n - 1)break;
//            col = 1;
//            printf("*");
//        }
//        else
//        {
//            printf(" ");
//            col++;
//        }
//    }
//    col = 1;
//    while (row == n - 1 && col <= m)
//    {
//        printf("*");
//        col++;
//    }
//
//    return 0;
//}


//int jud(char ar[100], int len)
//{
//	int a = 0,b = 0;
//	for (int i = 0;i < len - 1;i++)
//	{
//		if (ar[i] == 'A' && ar[i+1] == 'B')
//		{
//			if (a == 0)
//			{
//				a = 1;
//				i++;
//			}
//		}
//		else if (ar[i] == 'B' && ar[i+1] == 'A')
//		{
//			if(b == 0)
//			{
//				b = 1;
//				i++;
//			}
//		}
//	}
//	if (a && b)
//		return 1;
//	return 0;
//}
//int main()
//{
//	char arr[100][100] = { 0 };
//	for (int i = 0;1;i++)
//	{
//		if (scanf("%s", arr[i]) == EOF)
//			return 0;
//		if (jud(arr[i],strlen(arr[i])))
//			printf("yu ye sa wang dai xing\n");
//		else
//			printf("zhen shi ou ba\n");
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
//		scanf("%d", &n);
//		char arr[1000][20] = { 0 };
//		for (int i = 0;i < n;i++)
//		{
//			char a[20] = { 0 };
//			int b;
//			scanf("%s %d", a, &b);
//			strcpy(arr[b], a);
//		}
//		for (int i = 999;i >= 0;i--)
//		{
//			if(arr[i][0] != 0)
//				printf("%s\n", arr[i]);
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int x, y;
//	int stu[20][2];
//	scanf("%d%d", &x, &y);
//	for (int i = 0;i < x;i++)
//	{
//		char name[20];
//		scanf("%d %s %d", &stu[i][0], name, &stu[i][1]);
//	}
//	for (int i = 0;i < y;i++)
//	{
//		int n;
//		scanf("%d", &n);
//		for (int j = 0;j < 20 ;j++)
//		{
//			if (stu[j][0] == n)
//			{
//				switch (stu[j][1] / 10)
//				{
//				case 10:
//				case 9:
//					printf("A\n");
//					break;
//				case 8:
//					printf("B\n");
//					break;
//				case 7:
//					printf("C\n");
//					break;
//				case 6:
//					printf("OK\n");
//					break;
//				default:
//					printf("ARE YOU PIG?\n");
//					break;
//				}
//			}
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int n, t;
//	int stu[30][3001] = {0};
//	scanf("%d%d", &n, &t);
//	for (int i = 1;i <= n;i++)
//	{
//		scanf("%d", &stu[0][i]);
//	}
//	for (int i = 0;i < t;i++)
//	{
//		int a, b;
//		scanf("%d %d", &a, &b);
//		for (int j = 1;j <= 3000; j++)
//		{
//			if (stu[0][j] == b)
//			while(1)
//			{
//				int y = 1;
//				if (stu[y][j] != 0)
//				{
//					y++;
//				}
//				else
//					stu[y][j] = a;
//			}
//		}
//	}
//	for (int i = 1;i <= 3000;i++)
//	{
//		for (int j = 3000;j >= 1;j--)
//		{
//			if (stu[i][j] != 0)
//				printf("%d ", stu[i][j]);
//		}
//	}
//	return 0;
//}

//struct number
//{
//	int a;
//	int b;
//	int c;
//	double ave;
//};
//int main() {
//
//	struct number get[500];
//
//	int n, i;
//
//	scanf("%d", &n);
//
//	for (i = 0; i < n; i++) {
//
//		scanf("%d%d%d", &get[i].a, &get[i].b, &get[i].c);
//
//		get[i].ave = (get[i].a + get[i].b + get[i].c) / 3.0;
//
//	}
//
//	for (i = n - 1; i > 0; i--) {
//
//		printf("%lf ", get[i].ave);
//
//	}
//
//	printf("%lf\n", get[0].ave);
//
//	return 0;


//struct gm
//{
//	char a[20];
//	int b;
//};
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	struct gm arr[100];
//	int max = 0;
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%s %d", arr[i].a, &arr[i].b);
//		if (arr[i].b > max)
//			max = arr[i].b;
//	}
//	for (int x = 0;x < 10;x++)
//	{
//		int min = max;
//		for (int i = 0;i < n;i++)
//		{
//			if (arr[i].b < min && arr[i].b != 0)
//				min = arr[i].b;
//		}
//		for (int i = 0;i < n;i++)
//		{
//			if (arr[i].b == min)
//				arr[i].b = 0;
//		}
//	}
//	int count = 0;
//	for (int i = 0;i < n;i++)
//	{
//		if (arr[i].b != 0)
//		{
//			printf("%s", arr[i].a);
//			count++;
//			if (count != n - 10)
//				printf(" ");
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int n,a,sum = 0;
//	while (1)
//	{
//		sum = 0;
//		scanf("%d", &n);
//		if (n == 0)
//			return 0;
//		while (n--)
//		{
//			scanf("%d", &a);
//			sum += a;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}


//int main()
//{
//	int x, y;
//	while (~scanf("%d%d", &x, &y))
//	{
//		printf("%d\n", x + y);
//	}
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	for (int i = 1;i <= t;i++)
//	{
//		char a[1010] = { 0 }, b[1010] = { 0 }, c[1010] = { 0 };
//		int al, bl;
//		for(int x = 0;x < 1009;x++)
//		{
//			a[x] = getchar() - 48;
//			if (a[x] + 48== ' '||a[x] +48 == '\n')
//			{
//				a[x] = 0;
//				al = x - 1;
//				break;
//			}
//		}
//		for (int x = al;x >= 0;x--)
//		{
//			a[1009 - (al - x)] = a[x];
//			a[x] = 0;
//		}
//		for (int x = 0;x < 1009;x++)
//		{
//			b[x] = getchar() - 48;
//			if (b[x] + 48 == '\n')
//			{
//				b[x] = 0;
//				bl = x - 1;
//				break;
//			}
//		}
//		for (int x = bl;x >= 0;x--)
//		{
//			b[1009 - (bl - x)] = b[x];
//			b[x] = 0;
//		}
//		for (int x = 1009;x > 1;x--)
//		{
//			c[x] += (a[x] + b[x]) % 10;
//			c[x - 1] += (a[x] + b[x]) / 10;
//		}
//		int kg = 0;
//		printf("Case %d:\n", i);
//		for (int x = 0; x < 1010;x++)
//		{
//			if (c[x] != 0)
//				kg = 1;
//			if (kg)
//				printf("%d", c[x]);
//		}
//		printf("\n\n");
//	}
//	return 0;
//}


//int main() {
//	int i, t, T, aLen, bLen, add, sum;
//	char a[1002], b[1002], c[1002], temp;
//	scanf("%d", &T);
//	for (t = 1; t <= T; t++) {
//		scanf("%s %s", a, b);
//		aLen = strlen(a);
//		bLen = strlen(b);
//		for (i = 0; i<aLen / 2; i++) {
//			temp = a[i];
//			a[i] = a[aLen - i - 1];
//			a[aLen - i - 1] = temp;
//		}
//		for (i = 0; i<bLen / 2; i++) {
//			temp = b[i];
//			b[i] = b[bLen - i - 1];
//			b[bLen - i - 1] = temp;
//		}
//		add = 0;
//		for (i = 0; i<aLen || i<bLen; i++) {
//			if (i<aLen && i<bLen)
//				sum = a[i] - 48+ b[i] - 48 + add;
//			else if (i < aLen)
//				sum = a[i] - 48 + add;
//			else if (i < bLen)
//				sum = b[i] - 48 + add;
//			add = 0;
//			if (sum > 9) {
//				add = 1;
//				sum -= 10;
//			}
//			c[i] = sum + 48;
//		}
//		if (add) c[i++] = add + 48;
//		printf("Case %d:\n", t);
//		for (i--; i >= 0; i--)
//			printf("%c", c[i]);
//		printf("\n\n");
//	}
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	while (t--)
//	{
//		char arr[101];
//		int a;
//		for (int i = 0;i < 101;i++)
//		{
//			scanf("%c", &arr[i]);
//			if (arr[i] == '\n')
//			{
//				arr[i] = 0;
//				a = i - 1;
//				break;
//			}
//		}
//		for (int i = a;i >= 0;i--)
//		{
//			printf("%c", arr[i]);
//		}
//		if(t)
//		puts("\n");
//	}
//	return 0;
//}



//int main()
//{
//	int n, m;
//	int count = 1;
//	while (1)
//	{
//		if (count != 1)
//			printf("\n");
//		scanf("%d%d", &n, &m);
//		if (n == 0 && m == 0)
//			return 0;
//		int a ,max = 0;
//		for (int i = 0;i < n;i++)
//		{
//			for (int j = 0;j < m;j++)
//			{
//				scanf("%d", &a);
//				if (a > max)
//					max = a;
//			}
//		}
//		printf("Case %d:\n%d\n", count, max);
//		count++;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int i, j, n, m, a, maxv, t = 1;
//	while (scanf("%d %d", &n, &m), n || m) {
//		maxv = -1;
//		for (i = 0; i < n; i++) {
//			for (j = 0; j < m; j++) {
//				scanf("%d", &a);
//				if (a > maxv) maxv = a;
//			}
//		}
//		if (t != 1) printf("\n");
//		printf("Case %d:\n", t++);
//		printf("%d\n", maxv);
//	}
//	return 0;
//}




//int main()
//{
//	int n, x;
//	while (scanf("%d%d", &n, &x) != EOF)
//	{
//		long long arr[n];
//		
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	long long x;
//	for(int count = 1;scanf("%d %lld", &n, &x) != EOF;count ++)
//	{
//		if (count != 1)
//			puts("");
//			printf("Case %d:\n", count);
//		int tmp = 0;
//		for(int i = 1 ;i <= n;i++)
//		{
//			long long a;
//			scanf("%lld", &a);
//			if (a != x)
//			{
//				if (i != 1)
//					printf(" ");
//				printf("%lld", a);
//				tmp++;
//			}
//		}
//		if (tmp == 0)
//			puts("Empty!");
//		else
//			puts("");
//	}
//	return 0;
//}
//
//int main() {
//	int hasPrinted;
//	int isFirstCase = 1;
//	int n, t = 0;
//	long long a, x;
//	while (~scanf("%d %lld", &n, &x)) {
//		hasPrinted = 0;
//		if (isFirstCase) isFirstCase = 0;
//		else puts("");
//		printf("Case %d:\n", ++t);
//		for (int i = 0; i < n; i++) {
//			scanf("%lld", &a);
//			if (a != x) {
//				if (hasPrinted) printf(" ");
//				printf("%lld", a);
//				hasPrinted = 1;
//			}
//		}
//		if (hasPrinted) puts("");
//		else puts("Empty!");
//	}
//	return 0;
//}


//int main()
//{
//	int sum = 0;
//	char a;
//	while ((a = getchar()) != EOF)
//	{
//		if (a <= 122 && a >= 65)
//			sum++;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//int main()
//{
//	char a = getchar();
//	printf("%d", a);
//	return 0;
//}

//
//int main()
//{
//	int n;
//	int count = 1;
//	while (1)
//	{
//		int arr[100] = { 0 };
//		scanf("%d", &n);
//		if (n == 0)
//			return 0;
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		for (int i = 0;i < n - 1;i++)
//		{
//			for (int j = 0;j < n - 1;j++)
//			{
//				int tmp;
//				if (arr[j] > arr[j + 1])
//				{
//					tmp = arr[j];
//					arr[j] = arr[j + 1];
//					arr[j + 1] = tmp;
//				}
//			}
//		}
//		if (count != 1)
//			puts("");
//		printf("%d\n", n);
//		for (int i = 0;i < n;i++)
//		{
//			if ((arr[i] != arr[i - 1] && i > 0) || i == 0)
//			{
//				if (i != 0)
//				printf(" ");
//				printf("%d", arr[i]);
//			}
//		}
//		puts("");
//		count++;
//	}
//	return 0;
//}




//int main()
//{
//	int n;
//	while (1)
//	{
//		int arr[100] = { 0 };
//		scanf("%d", &n);
//		if (n == 0)
//			return 0;
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		for (int i = 0;i < n - 1;i++)
//		{
//			for (int j = 0;j < n - 1;j++)
//			{
//				int tmp;
//				if (arr[j] > arr[j + 1])
//				{
//					tmp = arr[j];
//					arr[j] = arr[j + 1];
//					arr[j + 1] = tmp;
//				}
//				if (arr[i] == arr[i + 1])
//					arr[i] = 0;
//			}
//		}
//		printf("%d\n", n);
//		for (int i = 0;i < n;i++)
//		{
//			if (arr[i] != 0)
//			{
//				if (i != 0)
//					printf(" ");
//				printf("%d", arr[i]);
//			}
//		}
//		puts("\n");
//	}
//	return 0;
//}
//101


//int main()
//{
//	int arr[33];
//	int n;
//	scanf("%d", &n);
//	getchar();
//	for (int i = 0;i < n;i++)
//	{
//		arr[i] = getchar() - '0';
//	}
//	int sum = 0;
//	int a = 0, b = 0;
//	for (int i = 0;i < n;i++)
//	{
//		if (arr[i] == 1)
//			a++;
//		if (arr[i] == 0)
//			b++;
//	}
//	sum = abs(b - a);
//	printf("%d", sum);
//	return 0;
//}


//int main()
//{
//	int arr[10];
//	int arr2[10];
//	for (int i = 0;i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//		arr2[i] = 1;
//	}
//	for (int i = 0;i < 10;i++)
//	{
//		for (int j = 0;j < i;j++)
//		{
//			if (arr[i] > arr[j] && arr2[i] <= arr2[j])
//				arr2[i] = arr2[j] + 1;
//		}
//	}
//
//	int max = 0;
//	for (int i = 0;i < 10;i++)
//	{
//		if (arr2[i] > max)
//			max = arr2[i];
//	}
//	printf("%d", max);
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	while (t--)
//	{
//		char name[21] = { 0 };
//		char text[1001] = { 0 };
//		gets(name);
//		gets(text);
//		int nl = strlen(name);
//		int tl = strlen(text);
//		for (int i = 0;i < tl;i++)
//		{
//			int tmp = 1;
//			for (int j = 0;j < nl;j++)
//			{
//				if (text[i + j] != name[j])
//					tmp = 0;
//			}
//			if (tmp)
//			{
//				printf("doctorZ");
//				i += nl;
//			}
//			printf("%c", text[i]);
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
//		int n;
//		scanf("%d", &n);
//		char arr[51][21];
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%s", arr[i]);
//		}
//		int tmp = 0;
//		for (int i = 1;i < n ;i++)
//		{
//			if(strlen(arr[i])>strlen(arr[tmp]))
//				tmp = i;
//			else if (strlen(arr[i]) == strlen(arr[tmp]))
//			{
//				for (int j = 0;j < strlen(arr[i]);j++)
//				{
//					if (arr[i][j] > arr[tmp][j])
//						tmp = i;
//					if (arr[i][j] < arr[tmp][j])
//						break;
//				}
//			}
//		}
//		printf("%s\n", arr[tmp]);
//	}
//	return 0;
//}


//struct num
//{
//	int a;
//	int b;
//	int c;
//}arr[100];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
//	}
//	int min = 0;
//	for (int x = 0; x < 10;x++)
//	{
//		for (int i = 0;i < n;i++)
//		{
//			if(arr[i].b != -1)
//			if (arr[i].b < arr[min].b || arr[min].b == -1)
//				min = i;
//		}
//		arr[min].b = -1;
//	}
//	printf("%d ", arr[min].a);
//	int max = 0;
//	for (int x = 0; x < 10;x++)
//	{
//		for (int i = 0;i < n;i++)
//		{
//			if (arr[i].c != -1)
//				if (arr[i].c > arr[max].c || arr[max].c == -1)
//					max = i;
//		}
//		arr[max].c = -1;
//	}
//	printf("%d", arr[max].a);
//	return 0;
//}

//struct door
//{
//	int dist;
//	int time;
//	double t;
//}arr[101];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d %d", &arr[i].dist, &arr[i].time);
//	}
//	int slow, fast;
//	scanf("%d %d", &slow, &fast);
//	for (int i = 0;i < n;i++)
//	{
//		arr[i].t = arr[i].dist / (double)slow;
//		if (arr[i].t > arr[i].time)
//			arr[i].dist = -1;
//	}
//	int min = -1;
//	for (int i = 0;i < n;i++)
//	{
//		if (arr[i].dist >= 0)
//		{
//			min = i;
//			break;
//		}
//	}
//	if (min == -1)
//		printf("let_s_die_together");
//	else
//	{
//		for (int i = 0;i < n;i++)
//		{
//			if (arr[i].dist != -1 && arr[i].dist < arr[min].dist)
//				min = i;
//		}
//		printf("%.2f", arr[min].t);
//	}
//	return 0;
//}


//struct code
//{
//	unsigned int tips;
//	char text[21];
//}arr[10000];
//int main()
//{
//	int t,n;
//	scanf("%d %d", &t, &n);
//	for (int i = 0;i < t;i++)
//	{
//		scanf("%ud", &arr[i].tips);
//		getchar();
//		gets(arr[i].text);
//	}
//	for (int i = 0;i < n;i++)
//	{
//		unsigned int a;
//		scanf("%ud", &a);
//		for (int j = 0;j < t;j++)
//		{
//			if (a == arr[j].tips)
//			{
//				printf("%s", arr[j].text);
//				if (i != n - 1)
//					printf(" ");
//				break;
//			}
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
//		int n;
//		int arr[1000000][2] = { 0 };
//		scanf("%d", &n);
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i][0]);
//			for (int j = 0;j < 1000000;j++)
//			{
//				if (arr[i][0] == arr[j][0])
//				{
//					arr[i][0] = 0
//				}
//			}
//			arr[i][1]++;
//		}
//	}
//	return 0;
//}



//int com(int x, int y);
//int com(int x, int y)
//{
//    if (x == y)
//        return 1;
//    if (x == 30)
//    {
//        return com(x - 1, y - 1) + com(x - 1, y);
//    }
//    if (y > x / 2)
//        return com(x, x - y);
//    else
//    {
//        unsigned long long a = x, j = 1;
//        for (unsigned long long i = 1;i < y;i++)
//        {
//            a *= (x - i);
//        }
//        for (unsigned long long i = 1;i <= y;i++)
//        {
//            j *= i;
//        }
//        return a / j;
//    }
//}
//int main()
//{
//    int a, b, t;
//    scanf("%d", &t);
//    while (t--)
//    {
//        scanf("%d %d", &a, &b);
//        printf("%d\n", com(a, b));
//    }
//    return 0;
//}


//struct game
//{
//	int num;
//	int a[8];
//	int x;
//}arr[100];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d %d %d %d %d %d %d %d %d", \
//			& arr[i].num,\
//			& arr[i].a[0],\
//			& arr[i].a[1],\
//			& arr[i].a[2],\
//			& arr[i].a[3],\
//			& arr[i].a[4],\
//			& arr[i].a[5],\
//			& arr[i].a[6],\
//			& arr[i].a[7]);
//		arr[i].x = 0;
//	}
//	int max = 0;
//	for(int j = 0;j < n;j++)
//	{
//		for (int i = 0;i < n;i++)
//		{
//			if (arr[i].x == j && arr[i].a[j] > arr[max].a[j])
//				max = i;
//		}
//		int count = 0;
//		for (int i = 0;i < n;i++)
//		{
//			if (arr[i].a[j] == arr[max].a[j])
//			{
//				arr[i].x++;
//				count++;
//			}
//		}
//		if (count == 1)
//		{
//			printf("%d", arr[max].num);
//			break;
//		}
//	}
//	return 0;
//}



//typedef struct
//{
//	double a, b;
//}imag;
//imag x, y;
//imag multi(imag x, imag y)
//{
//	imag c;
//	c.a = (x.a * y.a) - (x.b * y.b);
//	c.b = (x.a * y.b) + (x.b * y.a);
//	return c;
//}
//imag divi(imag x, imag y)
//{
//	imag c;
//	c.a = ((x.a * y.a) + (x.b * y.b)) / (y.b * y.b + y.a * y.a);
//	c.b = ((x.b * y.a) - (x.a * y.b)) / (y.b * y.b + y.a * y.a);
//	return c;
//}
//int main()
//{
//	while (~scanf("%lf %lf %lf %lf", &x.a, &x.b, &y.a, &y.b))
//	{
//		printf("(%.1lf%+.1lfi) + (%.1lf%+.1lfi) = ", x.a, x.b, y.a, y.b);
//		if ((x.a + y.a) == 0 && (x.b + y.b) == 0)
//			printf("0.0\n");
//		else if ((x.a + y.a) != 0 && (x.b + y.b) == 0)
//			printf("%.1lfi\n", x.a + y.a);
//		else if ((x.a + y.a) == 0 && (x.b + y.b) != 0)
//			printf("%+.1lfi\n", x.b + y.b);
//		else
//			printf("%.1lf%+.1lfi\n", x.a + y.a, x.b + y.b);
//
//
//		printf("(%.1lf%+.1lfi) - (%.1lf%+.1lfi) = ", x.a, x.b, y.a, y.b);
//		if ((x.a - y.a) == 0 && (x.b - y.b) == 0)
//			printf("0.0\n");
//		else if ((x.a - y.a) != 0 && (x.b - y.b) == 0)
//			printf("%.1lf\n", x.a - y.a);
//		else if ((x.a - y.a) == 0 && (x.b - y.b) != 0)
//			printf("%+.1lfi\n", x.b - y.b);
//		else
//			printf("%.1lf%+.1lfi\n", x.a - y.a, x.b - y.b);
//
//		printf("(%.1lf%+.1lfi) * (%.1lf%+.1lfi) = ", x.a, x.b, y.a, y.b);
//		if(multi(x, y).a == 0 && multi(x, y).b == 0)
//			printf("0.0\n");
//		else if (multi(x, y).a != 0 && multi(x, y).b == 0)
//			printf("%.1lf\n",multi(x,y).a);
//		else if (multi(x, y).a == 0 && multi(x, y).b != 0)
//			printf("%+.1lfi\n", multi(x, y).b);
//		else
//			printf("%.1lf%+.1lfi\n", multi(x, y).a, multi(x, y).b);
//
//
//		printf("(%.1lf%+.1lfi) / (%.1lf%+.1lfi) = ", x.a, x.b, y.a, y.b);
//		if (divi(x, y).a == 0 && divi(x, y).b == 0)
//			printf("0.0\n");
//		else if(divi(x, y).a != 0 && divi(x, y).b == 0)
//			printf("%.1lf\n", divi(x, y).a);
//		else if (divi(x, y).a == 0 && divi(x, y).b != 0)
//			printf("%+.1lfi\n", divi(x, y).b);
//		else
//			printf("%.1lf%+.1lfi\n", divi(x, y).a, divi(x, y).b);
//	}
//	return 0;
//}


//int main()
//{
//	if (1 + 0 == 0)
//		printf("NO");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    printf("9");
//    return 0;
//}




//typedef struct
//{
//	char name[10];
//	double gra[3];
//	double av;
//}stu;
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	stu arr[100];
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%s", arr[i].name);
//		for (int j = 0;j < 3;j++)
//		{
//			scanf("%lf", &arr[i].gra[j]);
//		}
//		arr[i].av = (arr[i].gra[0] + arr[i].gra[1] + arr[i].gra[2]) / 3.0;
//	}
//	for (int j = 0;j < 3;j++)
//	{
//		int max = 0;
//		for (int i = 0;i < n;i++)
//		{
//			if (arr[i].gra[j] > arr[max].gra[j])
//				max = i;
//		}
//		printf("%s,%.2lf,%.2lf,%.2lf\n", arr[max].name, arr[max].gra[0], arr[max].gra[1], arr[max].gra[2]);
//	}
//	puts("");
//	int m1 = 0, m2 = 0;
//	double max1 = -1, max2 = -1;
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0; j < n;j++)
//		{
//			if (i == 0)
//			{
//				if (arr[j].av > max1)
//				{
//					max1 = arr[j].av;
//					m1 = j;
//				}
//			}
//			else
//			{
//				if (arr[j].av > max2 && arr[j].av <= max1 && j != m1)
//				{
//					max2 = arr[j].av;
//					m2 = j;
//				}
//			}
//		}
//		if(i == 0)
//			printf("%s,%.2lf,%.2lf,%.2lf\n", arr[m1].name, arr[m1].gra[0], arr[m1].gra[1], arr[m1].gra[2]);
//		else
//		{
//			printf("%s,%.2lf,%.2lf,%.2lf\n", arr[m2].name, arr[m2].gra[0], arr[m2].gra[1], arr[m2].gra[2]);
//			max1 = max2;
//			max2 = -1;
//			m1 = m2;
//		}
//	}
//	for (int i = 0;i < n;i++)
//	{
//		if(arr[i].av > 80)
//			printf("\n%s,%.2lf,%.2lf,%.2lf,%.2lf", arr[i].name, arr[i].gra[0], arr[i].gra[1], arr[i].gra[2],arr[i].av);
//	}
//	return 0;
//}





//typedef struct
//{
//	int gra;
//	int stan;
//}stu;
//stu arr[1000];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d", &arr[i].gra);
//		arr[i].stan = 0;
//	}
//	for (int i = 1;i <= n;i++)
//	{
//		int max = 0,m = 0;
//		for (int j = 0;j < n;j++)
//		{
//			if (arr[j].gra > max && arr[j].stan == 0)
//			{
//				max = arr[j].gra;
//				m = j;
//			}
//		}
//		arr[m].stan = i;
//	}
//	for (int i = 0;i < n;i++)
//	{
//		printf("%d", arr[i].stan);
//		if (i != n - 1)
//			printf(" ");
//	}
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n = 0;
//		scanf("%d", &n);
//		for(int j = 0;j < n;j++)
//		{
//			int x;
//			scanf("%d", &x);
//			for (int i = 1;1;i <<= 1)
//			{
//				if (x & i)
//				{
//					if (j != 0)
//						printf(" ");
//					printf("%d", x & i);
//					break;
//				}
//			}
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n = 8;
//	int m = n >>= 1;
//	printf("%d %d ", n, m);
//	return 0;
//}


//typedef struct
//{
//	int end;
//	double fun[10];
//	double time[10];
//}game;
//game arr[100];
//int main()
//{
//	int n;
//	double t;
//	while (1)
//	{
//		scanf("%d %lf", &n, &t);
//		if (n == 0 && t == 0)
//			return 0;
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i].end);
//			for (int j = 0;j < arr[i].end;j++)
//			{
//				scanf("%lf", &arr[i].fun[j]);
//			}
//			for (int j = 0;j < arr[i].end;j++)
//			{
//				scanf("%lf",&arr[i].time[j]);
//			}
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	while (t--)
//	{
//		char name[21] = { 0 };
//		char text[1001] = { 0 };
//		gets(name);
//		gets(text);
//		int nl = strlen(name);
//		int tl = strlen(text);
//		for (int i = 0;i < tl;i++)
//		{
//			if (i <= tl - nl)
//			{
//				int tmp = 1;
//				for (int j = 0;j < nl;j++)
//				{
//					if (text[i + j] != name[j])
//						tmp = 0;
//				}
//				if (tmp)
//				{
//					printf("doctorZ");
//					i += nl;
//				}
//			}
//			printf("%c", text[i]);
//		}
//		puts("");
//	}
//	return 0;
//}



//int jud(char ar[100], int len)
//{
//	int a = 0, b = 0;
//	for (int i = 0;i < len - 1;i++)
//	{
//		if (ar[i] == 'A' && ar[i + 1] == 'B')
//		{
//			if (a == 0)
//			{
//				a = 1;
//				i++;
//			}
//		}
//		else if (ar[i] == 'B' && ar[i + 1] == 'A')
//		{
//			if (b == 0)
//			{
//				b = 1;
//				i++;
//			}
//		}
//	}
//	if (a && b)
//		return 1;
//	return 0;
//}
//int main()
//{
//	char arr[100][100] = { 0 };
//	for (int i = 0;1;i++)
//	{
//		if (scanf("%s", arr[i]) == EOF)
//			return 0;
//		if (jud(arr[i], strlen(arr[i])))
//			printf("yu ye sa wang dai xing\n");
//		else
//			printf("zhen shi ou ba\n");
//	}
//	return 0;
//}



//int com(int k, int n)
//{
//	if (k == 0 || n == 0 || k == n)
//		return 1;
//	else if ((k & n) == k)
//		return 1;
//	else if((k & n) != k)
//		return 0;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int k, n;
//		scanf("%d %d", &k, &n);
//		printf("%d\n", com(k, n));
//	}
//	return 0;
//}

//int main(void)
//{
//	int t, n, k;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d %d", &k, &n);
//		if (n == 0 || k == 0 || n == k) printf("1\n");
//		else if ((n & k) == k) printf("1\n");
//		else if ((n & k) != k) printf("0\n");
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int x = 1;
//	int a = 1;
//	int m = n;
//	while (m--)
//	{
//		int tmp = x;
//		for (int i = a + 1;i < (n + 2);i++)
//		{
//			if (i == a + 1)
//				printf("%d", tmp);
//			else
//				printf(" %d", tmp);
//				tmp += i;
//		}
//		if(m)
//			puts("");
//		x += a++;
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	getchar();
//	char arr[1010];
//	while(n--)
//	{
//		gets(arr);
//		printf("%s\n\n", arr);
//	}
//	char arr2[1000];
//	for (int i = 0;1;i++)
//	{
//		if (gets(arr2) == 0)
//			return 0;
//		for (int j = 0;1;j++)
//		{
//			if (arr2[j] == 0)
//				break;
//			if (arr2[j] == ' ')
//				puts("\n");
//			else
//				printf("%c", arr2[j]);
//		}
//		puts("\n");
//	}
//	return 0;
//}

//int main()
//{
//	char arr[10];
//	int a = gets(&arr[0]);
//	printf("%d", a);
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//char qs[1000];
//int flg[1000];
//char* pnt;
//char name[1000];
//char tmp[1000];
//char uu;
//int i, j, t, k;
//
//int main(void)
//{
//    scanf("%d", &t);
//    while (t--)
//    {
//        memset(tmp, 0, sizeof(tmp));
//        memset(qs, 0, sizeof(qs));
//        memset(name, 0, sizeof(name));
//        scanf("%s", name);
//        getchar();
//        gets(qs);
//        for (i = 0; i < strlen(qs); i++)
//        {
//            k = 0;
//            for (j = i; j < strlen(name) + i; j++)
//            {
//                tmp[k] = qs[j];
//                k++;
//            }
//            if (strcmp(tmp, name) == 0)
//            {
//                printf("doctorZ");
//                for (int q = 1; q < strlen(name); q++)
//                {
//                    i++;
//                }
//            }
//            else
//                printf("%c", qs[i]);
//        }
//        puts("");
//    }
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	while (t--)
//	{
//		char name[30] = { 0 };
//		char text[1010] = { 0 };
//		scanf("%s", name);
//		getchar();
//		gets(text);
//		int nl = strlen(name);
//		int tl = strlen(text);
//		for (int i = 0;i < tl;i++)
//		{
//			if (i <= tl - nl)
//			{
//				int tmp = 1;
//				for (int j = 0;j < nl;j++)
//				{
//					if (text[i + j] != name[j])
//						tmp = 0;
//				}
//				if (tmp)
//				{
//					printf("doctorZ");
//					i += nl;
//				}
//			}
//			printf("%c", text[i]);
//		}
//		puts("");
//	}
//	return 0;
//}



//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	while (t--)
//	{
//		char name[40] = { 0 };
//		char text[1500] = { 0 };
//		gets(name);
//		gets(text);
//		int nl = strlen(name);
//		int tl = strlen(text);
//		for (int i = 0;i < tl;i++)
//		{
//			if (i <= tl - nl)
//			{
//				int tmp = 1;
//				for (int j = 0;j < nl;j++)
//				{
//					if (text[i + j] != name[j])
//						tmp = 0;
//				}
//				if (tmp)
//				{
//					printf("doctorZ");
//					i += nl;
//				}
//			}
//			if(i < tl)
//				printf("%c", text[i]);
//		}
//		puts("");
//	}
//	return 0;
//}

//int main()
//{
//	printf("%c",0);
//	return 0;
//}



//int main()
//{
//	char arr[1010];
//	while (gets(arr) != NULL)
//	{
//		BBBABBBBBA
//	}
//	return 0;
//}

//int jud(char ar[1000], int len)
//{
//	int a = 0, b = 0;
//	for (int i = 0;i < len - 1;i++)
//	{
//		if (ar[i] == 'A' && ar[i + 1] == 'B' && a == 0)
//		{
//				a = 1;
//				i++;
//		}
//		else if (ar[i] == 'B' && ar[i + 1] == 'A' && b == 0)
//		{
//				b = 1;
//				i++;
//
//		}
//	}
//	if (a && b)
//		return 1;
//	return 0;
//}
//int jud2(char ar[1000], int len)
//{
//	int a = 0, b = 0;
//	for (int i = len - 1;i >= 0;i--)
//	{
//		if (ar[i] == 'A' && ar[i - 1] == 'B' && a == 0)
//		{
//			a = 1;
//			i--;
//		}
//		else if (ar[i] == 'B' && ar[i - 1] == 'A' && b == 0)
//		{
//			b = 1;
//			i--;
//
//		}
//	}
//	if (a && b)
//		return 1;
//	return 0;
//}
//int main()
//{
//	char arr[1000][1000] = { 0 };
//	for (int i = 0;1;i++)
//	{
//		if (scanf("%s", arr[i]) == EOF)
//			return 0;
//		if (jud(arr[i], strlen(arr[i])) || jud2(arr[i], strlen(arr[i])))
//			printf("yu ye sa wang dai xing\n");
//		else
//			printf("zhen shi ou ba\n");
//	}
//	return 0;
//}

//int jud(char ar[1010], int len)
//{
//	int a = 0, b = 0;
//	for (int i = 0;i < len - 1;i++)
//	{
//		if (ar[i] == 'A' && ar[i + 1] == 'B' && a == 0)
//		{
//			a = 1;
//			i++;
//		}
//		else if (ar[i] == 'B' && ar[i + 1] == 'A' && b == 0)
//		{
//			b = 1;
//			i++;
//		}
//	}
//	if (a && b)
//		return 1;
//	return 0;
//}
//int jud2(char ar[1010], int len)
//{
//	int a = 0, b = 0;
//	for (int i = len - 1;i > 0;i--)
//	{
//		if (ar[i] == 'A' && ar[i - 1] == 'B' && a == 0)
//		{
//			a = 1;
//			i--;
//		}
//		else if (ar[i] == 'B' && ar[i - 1] == 'A' && b == 0)
//		{
//			b = 1;
//			i--;
//		}
//	}
//	if (a && b)
//		return 1;
//	return 0;
//}
//int main()
//{
//	char arr[1010] = { 0 };
//	while(scanf("%s", arr) != EOF)
//	{
//		if (jud(arr, strlen(arr)) || jud2(arr, strlen(arr)))
//			printf("yu ye sa wang dai xing\n");
//		else
//			printf("zhen shi ou ba\n");
//	}
//	return 0;
//}


//struct door
//{
//	double dist;
//	double time;
//	double t1,t2,t;
//}arr[110];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%lf %lf", &arr[i].dist, &arr[i].time);
//	}
//	double slow, fast;
//	scanf("%lf %lf", &slow, &fast);
//	for (int i = 0;i < n;i++)
//	{
//		arr[i].t1 = arr[i].dist / fast;
//		arr[i].t2 = arr[i].dist / slow - arr[i].t1;
//		arr[i].t = arr[i].t1 + arr[i].t2;
//		if (arr[i].t2 > arr[i].time)
//			arr[i].dist = -1;
//	}
//	int min = -1;
//	for (int i = 0;i < n;i++)
//	{
//		if (arr[i].dist >= 0)
//		{
//			min = i;
//			break;
//		}
//	}
//	if (min == -1)
//		printf("let_s_die_together");
//	else
//	{
//		for (int i = 0;i < n;i++)
//		{
//			if (arr[i].dist != -1 && arr[i].dist < arr[min].dist)
//				min = i;
//		}
//		printf("%.2f", arr[min].t);
//	}
//	return 0;
//}


//typedef struct
//{
//	int end;
//	double happy[10], time[10], effi[10];
//}game;
//typedef struct
//{
//	double happy, time;
//}chose;
//chose ch;
//game arr[100];
//int main()
//{
//	int n, t;
//	while (scanf("%d %d", &n, &t))
//	{
//		ch.happy = 0;
//		ch.time = 0;
//		if (n == 0 && t == 0)
//			return 0;
//		for (int i = 0;i < n; i++)
//		{
//			scanf("%d", &arr[i].end);
//			for (int j = 0;j < arr[i].end;j++)
//			{
//				scanf("%lf", &arr[i].happy[j]);
//			}
//			for (int j = 0;j < arr[i].end;j++)
//			{
//				scanf("%lf", &arr[i].time[j]);
//			}
//			for (int j = 0;j < arr[i].end;j++)
//			{
//				arr[i].effi[j] = arr[i].happy[j] / arr[i].time[j];
//			}
//		}
//		double max = 0;
//		while (1)
//		{
//			max = 0;
//			int x = 0, y = 0;
//			for (int i = 0;i < n;i++)
//			{
//				for (int j = 0;j < arr[i].end;j++)
//				{
//					if (arr[i].effi[j] > max)
//					{
//						max = arr[i].effi[j];
//						x = i;
//						y = j;
//					}
//				}
//			}
//			if (max == 0)
//				break;
//			if (ch.time == t)
//				break;
//			if (ch.time + arr[x].time[y] <= t)
//			{
//				ch.happy += arr[x].happy[y];
//				ch.time += arr[x].time[y];
//				arr[x].effi[y] = -1;
//			}
//			else
//			{
//				arr[x].effi[y] = -1;
//			}
//		}
//		if (max == 0)
//		{
//			printf("%.0lf\n", ch.happy);
//			continue;
//		}
//		if (ch.time == t)
//		{
//			printf("%.0lf\n", ch.happy);
//			continue;
//		}
//	}
//	return 0;
//}


//typedef struct
//{
//	int num;
//	char id[10];
//}stu;
//int main()
//{
//	int n, t;
//	while (scanf("%d %d", &n, &t) != EOF)
//	{
//		stu arr[10000];
//		for (int i = 1;i <= n;i++)
//		{
//			scanf("%s", arr[i].id);
//			arr[i].num = i;
//		}
//		for (int j = n + 1;j <= n + t;j++)
//		{
//			char tmp[10] = { 0 };
//			scanf("%s %s", arr[j].id, tmp);
//			int kg = 0;
//			for (int x = 1;x <= n + t;x++)
//			{
//				if (strcmp(arr[x].id, tmp) == 0 && kg == 0)
//				{
//					kg = 1;
//					arr[j].num = arr[x].num;
//					x = 1;
//				}
//				if (kg && x != j && arr[x].num >= arr[j].num)
//					arr[x].num++;
//			}
//		}
//		for (int i = 1;i < 10000;i++)
//		{
//			for (int j = 1;j < 10000;j++)
//			{
//				if (arr[j].num == i)
//				{
//					if (i != 1)
//						printf(" ");
//					printf("%s", arr[j].id);
//					break;
//				}
//			}
//		}
//		puts("");
//	}
//	return 0;
//}



//int main()
//{
//	int arr[5][5];
//	int a = 50;
//	for (int i = 0;i < 5;i++)
//	{
//		for (int j = 0;j < 5;j++)
//		{
//			scanf("%d", &arr[i][j]);
//			if (i == j || i + j == 4)
//				a += arr[i][j];
//		}
//	}
//	printf("%d\n", a);
//	if (a > 100)
//		printf("wo de tian!");
//	else
//		printf("make monkey!");
//	return 0;
//}

//typedef struct
//{
//	char name[50];
//	int gra;
//}stu;
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		stu arr[n];
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%s %d", arr[i].name, &arr[i].gra);
//		}
//		int q;
//		scanf("%d", &q);
//		while (q--)
//		{
//			char tmp[50] = { 0 };
//			scanf("%s", tmp);
//			for (int i = 0;i < n;i++)
//			{
//				if (strcmp(tmp, arr[i].name) == 0)
//				{
//					printf("%d\n",arr[i].gra);
//					break;
//				}
//				if (i == n - 1)
//				{
//					puts("error");
//					break;
//				}
//			}
//		}
//	}
//	return 0;
//}

//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		int arr[100][2] = {0};
//		int count = 0;
//		int x = 0;
//		for (int i = 0;count < n;x = i)
//		{
//			int tmp;
//			scanf("%d", &tmp);
//			if (tmp == 0)
//				i++;
//			count++;
//			int kg = 0;
//			for (int j = 0;j <= i;j++)
//			{
//				if (tmp == arr[j][0])
//				{
//					kg = 1;
//					arr[j][1] ^= -1;
//					break;
//				}
//			}
//			if(kg == 0)
//			{
//				arr[i][0] = arr[i][1] = tmp;
//				i++;
//			}
//		}
//		for (int i = 0;i < x;i++)
//		{
//			if ((arr[i][0] == arr[i][1] && arr[i][0] != 0) || (arr[i][0] == 0 && arr[i][1] == -1))
//			{
//				printf("%d\n", arr[i][0]);
//				break;
//			}
//		}
//	}
//	return 0;
//}


//typedef struct
//{
//	int times;
//	char word[5];
//}word;
//word arr[100];
//int main()
//{
//	int t = 0;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		int count = 0;
//		int x;
//		for (int i = 0;count < n;)
//		{
//			char tmp[6] = { 0 };
//			scanf("%s",tmp);
//			count++;
//			int kg = 0;
//			for (int j = 0;j < i;j++)
//			{
//				if (strcmp(arr[j].word, tmp) == 0)
//				{
//					arr[j].times++;
//					kg = 1;
//					break;
//				}
//			}
//			if (kg == 0)
//			{
//				strcpy(arr[i].word, tmp);
//				arr[i].times = 1;
//				i++;
//				x = i;
//			}
//		}
//		int y = x;
//		while (y--)
//		{
//			int m = 0;
//			for (int i = 0;i < x;i++)
//			{
//				if ((strcmp(arr[m].word,arr[i].word) > 0 && arr[i].times != -1) || arr[m].times == -1)
//				{
//					m = i;
//				}
//			}
//			printf("%s:%d\n", arr[m].word, arr[m].times);
//			arr[m].times = -1;
//		}
//		puts("");
//	}
//	return 0;
//}


//typedef struct 
//{
//	int num;
//	struct node *next;
//}node;
//void print_link(const node* head)
//{
//	while (head != NULL)
//	{
//		printf("%d\n", head->num);
//		head = head->next;
//	}
//}
//node* inilink(void)
//{
//	node *head = NULL, *p = NULL, *t = NULL;
//	int tmp;
//	t = (node*)malloc(sizeof(node));
//	head = t;
//	t->next = NULL;
//	while (scanf("%d", &tmp))
//	{
//		if (tmp == -1)
//			break;
//		t->num = tmp;
//		p = t;
//		t = (node*)malloc(sizeof(node));
//		t->next = NULL;
//		p->next = t;
//	}
//	if (p != NULL)
//	{
//		p->next = NULL;
//		free(t);
//	}
//	return head;
//}
//int main()
//{
//	node* head = NULL;
//	head = inilink();
//	print_link(head);
//	return 0;
//}


//#include <stdio.h>
//#include <math.h>
//#define PI 3.14159
//double computeArea(double a, double b, double c, double d, double alpha)
//{
//    double area,p = (1.0/2) * (a+b+c+d);
//    area = (p - a)*(p - b)*(p - c)*(p - d) - a * b * c * d * cos(alpha) * cos(alpha);
//    return pow(area, 1.0 / 2);
//}
//int main(void) {
//    double a, b, c, d, alpha;
//    a = 3;
//    b = 4;
//    c = d = 5;
//    alpha = 145 * PI / 360;
//    printf("%.2f\n", computeArea(a, b, c, d, alpha));
//    return 0;
//}



//int reverse(int n)
//{
//    int ret[10] = {0};
//    int kg = 0;
//    int a;
//    int re = 0;
//    int b = n;
//    for (int i = 0;i < 10;)
//    {
//        if(n == 0)
//            break;
//        if (n % 10 != 0 || kg)
//        {
//            ret[i] = n % 10;
//            kg = 1;
//            i++;
//            a = i;
//        }
//        n /= 10;
//    }
//    for (int i = 0;i < a;i++)
//    {
//        re += ret[i] * pow(10, a - 1 - i);
//    }
//    return re;
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    printf("%d\n", reverse(n));
//    return 0;
//}


//int jud(int n)
//{
//	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
//		return 1;
//	return 0;
//}
//int main()
//{
//	int n, y, r, sum = 0;
//	scanf("%d/%d/%d", &n, &y, &r);
//	sum += r;
//	for (int i = y - 1;i > 0;i--)
//	{
//		if (i == 2 && jud(n) == 1)
//			sum += 29;
//		else if (i == 2 && jud(n) != 1)
//			sum += 28;
//		else if (i == 4 || i == 6 || i == 9 || i == 11)
//			sum += 30;
//		else
//			sum += 31;
//	}
//	printf("%d", sum);
//	return 0;
//}


//int main()
//{
//	int arr[4] = {0};
//	while (1)
//	{
//		char tmp = getchar();
//		if (tmp == '\n')
//			break;
//		if (tmp == 'G' || tmp == 'g')
//			arr[0]++;
//		if (tmp == 'P' || tmp == 'p')
//			arr[1]++;
//		if (tmp == 'L' || tmp == 'l')
//			arr[2]++;
//		if (tmp == 't' || tmp == 'T')
//			arr[3]++;
//	}
//	while (1)
//	{
//		int count = 0;
//		for (int i = 0;i < 4;i++)
//		{
//			switch (i)
//			{
//			case 0:
//				if (arr[i] > 0)
//				{
//					printf("G");
//					count++;
//					arr[i]--;
//				}
//				break;
//			case 1:
//				if (arr[i] > 0)
//				{
//					printf("P");
//					count++;
//					arr[i]--;
//				}
//				break;
//			case 2:
//				if (arr[i] > 0)
//				{
//					printf("L");
//					count++;
//					arr[i]--;
//				}
//				break;
//			case 3:
//				if (arr[i] > 0)
//				{
//					printf("T");
//					count++;
//					arr[i]--;
//				}
//				break;
//			default:
//				break;
//			}
//		}
//		if (count == 0)
//			break;
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i <= n;i++)
//	{
//		printf("pow(3,%d) = %.0lf\n", i, pow(3, i));
//	}
//	return 0;
//}

//1 7 17

//int main()
//{
//	int n;
//	char a;
//	scanf("%d %c", &n, &a);
//	int n2 = n - 1;
//	int n3;
//	for (int i = 3;1;i += 2)
//	{
//		if (n2 - 2 * i >= 0)
//		{
//			n2 -= 2 * i;
//			n3 = i;
//		}
//		else
//			break;
//	}
//	int col = n3;
//	int kg = 0;
//	for (int i = 0;1;i++)
//	{
//		for (int j = 1;j <= n3;j++)
//		{
//			if (j <= (n3 - col) / 2)
//				printf(" ");
//			else if(j <= n3 - ((n3 - col) / 2))
//				printf("%c", a);
//		}
//		puts("");
//		if (col == n3 && i != 0)
//			break;
//		if (kg == 0)
//			col -= 2;
//		else
//			col += 2;
//		if (col == 1)
//			kg = 1;
//	}
//	if(n2 != 0)
//		printf("%d", n2);
//	return 0;
//}


//typedef  struct
//{
//	int abili;
//	int sum;
//}stu;
//stu arr[20005];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int count = 0;
//	int last;
//	for (int i = 0;count < n;)
//	{
//		int tmp;
//		scanf("%d", &tmp);
//		count++;
//		int a = 1;
//		for (int j = 0;j < 20005;j++)
//		{
//			if (tmp == arr[j].abili)
//			{
//				arr[j].sum++;
//				a = 0;
//				break;
//			}
//		}
//		if (a)
//		{
//			arr[i].abili = tmp;
//			arr[i].sum++;
//			i++;
//			last = i;
//		}
//	}
//	for (int i = 0;i < last;i++)
//	{
//		for (int j = 0;j < last-1;j++)
//		{
//			if (arr[j].abili > arr[j + 1].abili)
//			{
//				int m1 = arr[j].abili;
//				int m2 = arr[j].sum;
//				arr[j].abili = arr[j + 1].abili;
//				arr[j + 1].abili = m1;
//				arr[j].sum = arr[j + 1].sum;
//				arr[j + 1].sum = m2;
//			}
//		}
//	}
//	printf("%d %d", arr[0].abili, arr[0].sum);
//	printf("\n%d %d", arr[last - 1].abili, arr[last - 1].sum);
//	return 0;
//}

//typedef struct
//{
//	char id[6];
//	char name[11];
//	int gra[4];
//	int sum;
//}stu;
//stu arr[11];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int max = 0;
//	int m;
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%s %s %d %d %d", arr[i].id, arr[i].name, &arr[i].gra[0], &arr[i].gra[1], &arr[i].gra[2]);
//		arr[i].sum = arr[i].gra[0] + arr[i].gra[1] + arr[i].gra[2];
//		if (arr[i].sum > max)
//		{
//			max = arr[i].sum;
//			m = i;
//		}
//	}
//	printf("%s %s %d", arr[m].name, arr[m].id, arr[m].sum);
//	return 0;
//}


//int main()
//{
//	char t[205] = { 0 };
//	char a[2] = { 0 };
//	char b[2] = {0};
//	char c[2] = {0};
//	char d[2] = {0};
//		for (int i = 0;i < 200;i++)
//		{
//			t[i] = getchar();
//			if (t[i] == '\n' && t[i - 1] == '.' && i > 0)
//				break;
//		}
//		for (int i = 0;i < 200;i++)
//		{
//			if (t[i] == '/' && t[i + 1] == '*')
//			{
//				a[0]++;
//				i++;
//			}
//			else if (t[i] == '*' && t[i + 1] == '/')
//			{
//				a[1]++;
//				i++;
//			}
//			if (t[i] == '(')
//				b[0]++;
//			if (t[i] == ')')
//				b[1]++;
//			if (t[i] == '[')
//				c[0]++;
//			if (t[i] == ']')
//				c[1]++;
//			if (t[i] == '{')
//				d[0]++;
//			if (t[i] == '}')
//				d[1]++;
//		}
//		if (a[0] == a[1] && b[0] == b[1] && c[0] == c[1] && d[0] == d[1])
//			printf("YES");
//		else
//		{
//			printf("NO\n");
//			if (a[0] > a[1])
//				puts("/*-?");
//			else if (a[0] < a[1])
//				puts("?-*/");
//			else if (b[0] > b[1])
//				puts("(-?");
//			else if (b[0] < b[1])
//				puts("?-)");
//			else if (c[0] > c[1])
//				puts("[-?");
//			else if (c[0] < c[1])
//				puts("?-]");
//			else if (d[0] > d[1])
//				puts("{-?");
//			else if (d[0] < d[1])
//				puts("?-}");
//		}
//	return 0;
//}
//int main()
//{
//	int n;
//	char a;
//	scanf("%d %c", &n, &a);
//	if (n == 0)
//		return 0;
//	int n2 = n - 1;
//	int n3 = 1;
//	for (int i = 3;1;i += 2)
//	{
//		if (n2 - 2 * i >= 0)
//		{
//			n2 -= 2 * i;
//			n3 = i;
//		}
//		else
//			break;
//	}
//	int col = n3;
//	int kg = 0;
//	if (n3 == 1)
//		printf("%c\n", a);
//	else
//
//	{
//		for (int i = 0;1;i++)
//		{
//			for (int j = 1;j <= n3;j++)
//			{
//				if (j <= (n3 - col) / 2)
//					printf(" ");
//				else if (j <= n3 - ((n3 - col) / 2))
//					printf("%c", a);
//			}
//			puts("");
//			if (col == n3 && i != 0)
//				break;
//			if (kg == 0)
//				col -= 2;
//			else
//				col += 2;
//			if (col == 1)
//				kg = 1;
//		}
//	}
//		if (n2 != 0)
//			printf("%d", n2);
//	return 0;
//}
//
//int main()
//{
//	int n;
//	char ch;
//	scanf("%d %c", &n,&ch);
//	int n2 = n;
//	int col;
//	for (int i = 1;1;i+=2)
//	{
//		if (i == 1)
//			n2 -= 1;
//		else
//		{
//			if (n2 - 2 * i >= 0)
//				n2 -= 2 * i;
//			else
//			{
//				col = i - 2;
//				break;
//			}
//		}
//	}
//	int q = 0, p = col + 1;
//	while (1)
//	{
//		for (int i = 1;i <= col;i++)
//		{
//			if (i <= q)
//				printf(" ");
//			else if (i < p)
//				printf("%c", ch);
//		}
//		puts("");
//		if (p - q == 2)
//			break;
//		q++;
//		p--;
//	}
//	while (1)
//	{
//		if (col == 1)
//			break;
//		q--;
//		p++;
//		for (int i = 1;i <= col;i++)
//		{
//			if (i <= q)
//				printf(" ");
//			else if (i < p)
//				printf("%c", ch);
//		}
//		puts("");
//		if (q == 0 && p == col + 1)
//			break;
//	}
//	if (n2 != 0)
//		printf("%d", n2);
//	return 0;
//}


//int main()
//{
//	char t[200];
//	int len = 199;
//	for (int i = 0;i < 200;i++)
//	{
//		t[i] = getchar();
//		if (i > 1 && t[i - 2] == '\n' && t[i - 1] == '.' && t[i] == '\n')
//		{
//			t[i - 1] = 0;
//			len = i;
//			break;
//		}
//	}
//	char copy[200];
//	strcpy(copy, t);
//	while (1)
//	{
//		int ser = 0;
//		int q;
//		int jud = 0;
//		for (int i = 0;i < len;i++)
//		{
//			if (t[i] == '(')
//			{
//				q = i;
//				int kg = 1;
//				int p = 0;
//				for (int j = i + 1;1;j++)
//				{
//					if (t[j] == '/' && t[j + 1] == '*')
//					{
//						kg = 0;
//						p = j;
//					}
//					if (t[j] == '*' && t[j + 1] == '/' && j - p > 1)
//						kg = 1;
//					if (t[j] == ')' && kg)
//					{
//						t[q] = 0;
//						t[j] = 0;
//						i++;
//						break;
//					}
//					if (t[j] == '\n')
//					{
//						t[q] = -1;
//						i++;
//						break;
//					}
//				}
//			}
//			if (t[i] == '[')
//			{
//				int kg = 1;
//				int p = 0;
//				q = i;
//				for (int j = i + 1;1;j++)
//				{
//					if (t[j] == '/' && t[j + 1] == '*')
//					{
//						kg = 0;
//						p = j;
//					}
//					if (t[j] == '*' && t[j + 1] == '/' && j - p > 1)
//						kg = 1;
//					if (t[j] == ']')
//					{
//						t[q] = 0;
//						t[j] = 0;
//						i++;
//						break;
//					}
//					if (t[j] == '\n')
//					{
//						t[q] = -1;
//						i++;
//						break;
//					}
//				}
//			}
//			if (t[i] == '{')
//			{
//				jud = 1;
//				q = i;
//				int kg = 1;
//				int p = 0;
//				for (int j = i + 1;j < len;j++)
//				{
//					if (t[j] == '/' && t[j + 1] == '*')
//					{
//						kg = 0;
//						p = j;
//					}
//					if (t[j] == '*' && t[j + 1] == '/' && j - p > 1)
//						kg = 1;
//					if (t[j] == '{' && kg)
//					{
//						q = j;
//					}
//					if (t[j] == '}' && kg)
//					{
//						t[q] = 0;
//						t[j] = 0;
//						i++;
//						break;
//					}
//					if (j == len - 1)
//					{
//						t[q] = 0;
//						i++;
//						break;
//					}
//				}
//			}
//			if (t[i] == '/' && t[i + 1] =='*')
//			{
//				q = i;
//				for (int j = len - 1;j > 0;j--)
//				{
//					if (t[j] == '/' && t[j - 1] == '*' &&j - q > 2)
//					{
//						t[j] = 0;
//						t[q] = 0;
//						break;
//					}
//					if (j == q)
//					{
//						t[q] = -1;
//						break;
//					}
//				}
//			}
//		}
//		if (jud == 0)
//		{
//			break;
//		}
//	}
//	for (int i = 0;i < len;i++)
//	{
//		if (t[i] == ')' || t[i] == ']' || t[i] == '}')
//		{
//			printf("NO\n?-%c", t[i]);
//			return 0;
//		}
//		else if(t[i] == '*' && t[i + 1] == '/')
//		{
//			printf("NO\n?-*/");
//			return 0;
//		}
//		else if (t[i] == -1)
//		{
//			if (copy[i] == '/' && copy[i + 1] == '*')
//				printf("NO\n/*-?");
//			else
//				printf("NO\n%c-?", copy[i]);
//			return 0;
//		}
//	}
//	puts("YES");
//	return 0;
//}

//
//int main()
//{
//
//	{{
//	return 0;
//}


//int main()
//{
//	int n;
//	char ch;
//	scanf("%d %c", &n, &ch);
//	int n2 = n;
//	int col;
//	for (int i = 1;1;i += 2)
//	{
//		if (i == 1)
//			n2 -= 1;
//		else
//		{
//			if (n2 - 2 * i >= 0)
//				n2 -= 2 * i;
//			else
//			{
//				col = i - 2;
//				break;
//			}
//		}
//	}
//	int q = 0, p = col + 1;
//	while (1)
//	{
//		for (int i = 1;i <= col;i++)
//		{
//			if (i <= q)
//				printf(" ");
//			else if (i < p)
//				printf("%c", ch);
//		}
//		puts("");
//		if (p - q == 2)
//			break;
//		q++;
//		p--;
//	}
//	while (1)
//	{
//		if (col == 1)
//			break;
//		q--;
//		p++;
//		for (int i = 1;i <= col;i++)
//		{
//			if (i <= q)
//				printf(" ");
//			else if (i < p)
//				printf("%c", ch);
//		}
//		puts("");
//		if (q == 0 && p == col + 1)
//			break;
//	}
//	if (n2 != 0)
//		printf("%d", n2);
//	return 0;
//}


//int main()
//{
//
//	return 0; {/*/

//typedef struct
//{
//	int id;
//	struct node* next;
//}node;
//int main()
//{
//	int n,m;
//	while (~scanf("%d %d", &n, &m))
//	{
//		node* head = NULL;
//		node* t = NULL;
//		node* p = NULL;
//		for (int i = 1;i <= n;i++)
//		{
//			int tmp = 0;
//			scanf("%d", &tmp);
//			t = (node*)malloc(sizeof(node));
//			t->id = tmp;
//			if (i == 1)
//			{
//				head = t;
//				p = t;
//			}
//			else if (i != n)
//			{
//				p->next = t;
//				p = t;
//			}
//			else if (i == n)
//			{
//				t->next = NULL;
//				p->next = t;
//			}
//		}
//		t = (node*)malloc(sizeof(node));
//		t->next = head;
//		t->id = -1;
//		head = t;
//		for (int i = 0;i < m;i++)
//		{
//			int a, b;
//			node* q = head;
//			p = head->next;
//			scanf("%d %d", &a, &b);
//			t = (node*)malloc(sizeof(node));
//			t->id = a;
//			t->next = NULL;
//			while (1)
//			{
//				if (b == p->id)
//				{
//					q->next = t;
//					t->next = p;
//					break;
//				}
//				if (p->next == NULL)
//					break;
//				p = p->next;
//				q = q->next;
//			}
//		}
//		p = head->next;
//		while (1)
//		{
//			printf("%d ", p->id);
//			if (p->next == NULL)
//				break;
//			p = p->next;
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
//		int n, c, k;
//		scanf("%d %d %d", &n, &c, &k);
//		for (int i = 1;i < n;i++)
//		{
//			int tmp;
//			char ch;
//			scanf("%d %c", &tmp, &ch);
//			if (tmp < k)
//				c--;
//			if (tmp > k && ch == 'Y')
//				c -= 2;
//		}
//		if (c <= 0)
//			puts("awsl");
//		else
//			puts("heihei");
//	}
//	return 0;
//}


//typedef struct
//{
//	int num;
//	int jud;
//	struct node* next;
//}node;
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		node* t = (node*)malloc(sizeof(node));
//		t->next = NULL;
//		node* head = t;
//		node* p = head;
//		scanf("%d", &head->num);
//		head->jud = -1;
//		for (int i = 1;i < n;i++)
//		{
//			int tmp = 0;
//			scanf("%d", &tmp);
//			p = head;
//			while (1)
//			{
//				if (p->num == tmp)
//				{
//					p->jud *= -1;
//					break;
//				}
//				if (p->next == NULL)
//				{
//					t = (node*)malloc(sizeof(node));
//					t->next = NULL;
//					t->num = tmp;
//					t->jud = -1;
//					p->next = t;
//					break;
//				}
//				p = p->next;
//			}
//		}
//		p = head;
//		while (1)
//		{
//			if (p->jud == -1)
//			{
//				printf("%d\n", p->num);
//				break;
//			}
//			if (p->next == NULL)
//				break;
//			p = p->next;
//		}
//	}
//	return 0;
//}

//typedef struct
//{
//	int num;
//	int jud;
//	struct node* next;
//}node;
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		n = 30000;
//		node* t = (node*)malloc(sizeof(node));
//		t->next = NULL;
//		node* head = t;
//		node* p = head;
//		scanf("%d", &head->num);
//		head->jud = -1;
//		for (int i = 1;i <= n/2;i++)
//		{
//			int tmp = 0;
//			tmp = i;
//			p = head;
//			while (1)
//			{
//				if (p->num == tmp)
//				{
//					p->jud *= -1;
//					break;
//				}
//				if (p->next == NULL)
//				{
//					t = (node*)malloc(sizeof(node));
//					t->next = NULL;
//					t->num = tmp;
//					t->jud = -1;
//					p->next = t;
//					break;
//				}
//				p = p->next;
//			}
//		}
//		for (int i = 1;i <= n / 2;i++)
//		{
//			int tmp = 0;
//			tmp = i;
//			p = head;
//			while (1)
//			{
//				if (p->num == tmp)
//				{
//					p->jud *= -1;
//					break;
//				}
//				if (p->next == NULL)
//				{
//					t = (node*)malloc(sizeof(node));
//					t->next = NULL;
//					t->num = tmp;
//					t->jud = -1;
//					p->next = t;
//					break;
//				}
//				p = p->next;
//			}
//		}
//		p = head;
//		while (1)
//		{
//			if (p->jud == -1)
//			{
//				printf("%d\n", p->num);
//				break;
//			}
//			if (p->next == NULL)
//				break;
//			p = p->next;
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
//		int tmp = 0;
//		int n;
//		scanf("%d", &n);
//		while (n--)
//		{
//			int a;
//			scanf("%d", &a);
//			tmp = tmp ^ a;
//		}
//		printf("%d\n", tmp);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	while (1)
//	{
//		scanf("%d", &n);
//		if (n == 0)
//			return 0;
//		int arr[101] = { 0 };
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		int a = 0;
//		for (int i = 0;i < n;i++)
//		{
//			for (int j = 0;j < n - i - 1;j++)
//			{
//				if (arr[j] > arr[j + 1])
//				{
//					arr[j] = arr[j] ^ arr[j + 1];
//					arr[j + 1] = arr[j] ^ arr[j + 1];
//					arr[j] = arr[j] ^ arr[j + 1];
//				}
//				else if (arr[j] == arr[j + 1] && arr[j] != 0)
//				{
//					arr[j] = 0;
//					a++;
//				}
//			}
//		}
//		printf("%d\n", n - a);
//		for (int i = a;i < n;i++)
//		{
//			printf("%d ", arr[i]);
//		}
//		puts("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int count = 1;
//	while (1)
//	{
//		int n, m;
//		char map[102][102] = { 0 };
//		scanf("%d %d", &n, &m);
//		getchar();
//		if (n == 0 && m == 0)
//			return 0;
//		for (int i = 1;i <= n;i++)
//		{
//			for (int j = 1;j <= m;j++)
//			{
//				scanf("%c", &map[i][j]);
//			}
//			getchar();
//		}
//		printf("Field #%d:\n", count);
//		count++;
//		for (int i = 1;i <= n;i++)
//		{
//			for (int j = 1;j <= m;j++)
//			{
//				if (map[i][j] == '.')
//				{
//					map[i][j] = 0;
//					for (int x = i - 1;x <= i + 1;x++)
//					{
//						for (int y = j - 1;y <= j + 1;y++)
//						{
//							if (map[x][y] == '*')
//								map[i][j]++;
//						}
//					}
//				}
//				if (map[i][j] == '*')
//					printf("%c", map[i][j]);
//				else
//					printf("%d", map[i][j]);
//			}
//			puts("");
//		}
//		puts("");
//	}
//	return 0;
//}


//int jud(int a)
//{
//	if (a % 7 == 0)
//		return 1;
//	while (1)
//	{
//		if (a % 10 == 7)
//			return 1;
//		a /= 10;
//		if (a == 0)
//			return 0;
//	}
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int a;
//		scanf("%d", &a);
//		if (jud(a))
//			puts("pa");
//		else
//			printf("%d\n", a);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	while (scanf("%d", &n), n)
//	{
//		int arr[30][30] = { 0 };
//		for (int i = 0;i < n;i++)
//		{
//			for (int j = 0; j < n;j++)
//			{
//				scanf("%d", &arr[i][j]);
//			}
//		}
//		for (int i = 0;i < n;i++)
//		{
//			for (int j = 0; j < n;j++)
//			{
//				for (int k = 0;k < n - 1 - j;k++)
//				{
//					if (arr[i][k] > arr[i][k + 1])
//					{
//						arr[i][k] = arr[i][k] ^ arr[i][k + 1];
//						arr[i][k + 1] = arr[i][k] ^ arr[i][k + 1];
//						arr[i][k] = arr[i][k] ^ arr[i][k + 1];
//					}
//				}
//			}
//			for (int j = 0;j < n;j++)
//			{
//				printf("%d ", arr[i][j]);
//			}
//			puts("");
//		}
//	}
//	return 0;
//}


//int main()
//{
//	while (1)
//	{
//		char arr[100] = { 0 };
//		int a = 0, b = 0;
//		for (int i = 0;i < 100;i++)
//		{
//			arr[i] = getchar();
//			if (arr[i] == '{')
//				a++;
//			else if (arr[i] == '}')
//				b++;
//			else if (arr[i] == '#')
//				break;
//			else if (arr[i] == 'p')
//				return 0;
//		}
//		if (a != b)
//			puts("unpaired");
//		else
//			puts("paired");
//	}
//	return 0;
//}


//int main()
//{
//	char n[100],m[33];
//	while (~scanf("%s %s", n, m))
//	{
//		int jud = 1;
//		for (int i = 0;i <= strlen(n) - strlen(m);i++)
//		{
//			jud = 1;
//			for (int j = i;j < strlen(m) + i;j++)
//			{
//				if (n[j] != m[j - i])
//				{
//					jud = 0;
//					break;
//				}
//			}
//			if (jud == 1)
//			{
//				printf("%d\n", i);
//				break;
//			}
//		}
//		if (jud == 0)
//			puts("-1");
//	}
//	return 0;
//}

//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int x;
//	int last = n + 1024 + 512 - 1534 - 1;
//	if (last <= 0)
//		printf("0");
//	else
//		printf("%d", last / m);
//	return 0;
//

//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		int jud = 0;
//		int n2 = n;
//		while (1)
//		{
//			if (n2 == 0)
//				break;
//			int tmp = n2 % 10;
//			if (tmp == 0)
//			{
//				jud = 1;
//				puts("AC");
//				break;
//			}
//			n2 /= 10;
//		}
//		if (jud == 0)
//		{
//			if (n % 6 == 0 && n % 9 == 0 && n % 7 != 0 && n % 8 != 0)
//				puts("AC");
//			else if (n % 6 != 0 && n % 9 != 0 && (n % 7 == 0 || n % 8 == 0))
//				puts("WA");
//			else
//				puts("TLE");
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		if (n == 0)
//		{
//			puts("AC");
//			return 0;
//		}
//		int jud = 0;
//		int n2 = n;
//		while (1)
//		{
//			if (n2 == 0)
//				break;
//			int tmp = n2 % 10;
//			if (tmp == 0)
//			{
//				jud = 1;
//				puts("AC");
//				break;
//			}
//			n2 /= 10;
//		}
//		if (jud == 0)
//		{
//			if (n % 6 == 0 && n % 9 == 0 && n % 7 != 0 && n % 8 != 0)
//				puts("AC");
//			else if (n % 6 != 0 && n % 9 != 0 && (n % 7 == 0 || n % 8 == 0))
//				puts("WA");
//			else
//				puts("TLE");
//		}
//	}
//	return 0;
//}


//int main()
//{
//	double a, b, mj, xygg, hxjj, lily;
//	scanf("%lf %lf", &a, &b);
//	double s = ((a - 2 * b) / 2.0) * ((a - 2 * b) / 2.0) * 3.14159;
//	scanf("%lf %lf %lf %lf", &mj, &xygg, &hxjj, &lily);
//	int n = 0;
//	if (mj > s)
//	{
//		printf("mj ");
//		n++;
//	}
//	if (xygg > s)
//	{
//		n++;
//		printf("xygg ");
//	}
//	if (hxjj > s)
//	{
//		printf("hxgg ");
//		n++;
//	}
//	if (lily > s)
//	{
//		printf("Lily ");
//		n++;
//	}
//	if (n == 0)
//		printf("None");
//	return 0;
//}

//int main()
//{
//	putchar('a');
//	return 0;
//}

//int main()
//{
//    int n;
//    while (~scanf("%d", &n))
//    {
//        if (n == 0)
//        {
//            printf("AC");
//            continue;
//        }
//        int n2 = n;
//        int jud = 0;
//        while (1)
//        {
//
//            if (n2 == 0)
//                break;
//            int  s = n2 % 10;
//            if (s == 0)
//            {
//                jud = 1;
//                printf("AC");
//                break;
//            }
//            n2 /= 10;
//        }
//
//        if (jud == 0)
//        {
//            if (n % 6 == 0 && n % 9 == 0 && n % 7 != 0 && n % 8 != 0)
//            {
//                printf("AC");
//            }
//            else
//                if (n % 7 == 0 || n % 8 == 0 && n % 6 != 0 && n % 9 != 0)
//                {
//                    printf("WA");
//                }
//                else
//                    printf("TIE");
//        }
//    }
//    return 0;
//}

//int main()
//{
//    int n;
//    while (~scanf("%d", &n))
//    {
//        if (n == 0)
//        {
//            printf("AC");
//            continue;
//        }
//        int n2 = n;
//        int jud = 0;
//        while (1)
//        {
//
//            if (n2 == 0)
//                break;
//            int  s = n2 % 10;
//            if (s == 0)
//            {
//                jud = 1;
//                printf("AC");
//                break;
//            }
//            n2 /= 10;
//        }
//
//        if (jud == 0)
//        {
//            if (n % 6 == 0 && n % 9 == 0 && n % 7 != 0 && n % 8 != 0)
//            {
//                printf("AC");
//            }
//            else
//                if (n % 7 == 0 || n % 8 == 0 && n % 6 != 0 && n % 9 != 0)
//                {
//                    printf("WA");
//                }
//                else
//                    printf("TIE");
//        }
//    }
//    return 0;
//}

//int main()
//{
//	int m, k;
//	double n;
//	scanf("%d %lf %d", &m, &n, &k);
//	while (k--)
//	{
//		int ask;
//		int jud = 1;
//		scanf("%d", &ask);
//		if (ask == 1)
//			puts("No");
//		else
//		{
//			for (int i = 2;i < n && jud;i++)
//			{
//				for (int j = 1; pow(i, j) <= ask;j++)
//				{
//					if (pow(i, j) == ask)
//					{
//						puts("No");
//						jud = 0;
//						break;
//					}
//				}
//			}
//			if (jud)
//				puts("Yes");
//		}
//	}
//	return 0;
//}


//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n,p,sum = 0;
//		int arr[1010] = { 0 };
//		scanf("%d", &n);
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		qsort(arr, n, sizeof(arr[0]), cmp);
//		if (n == 1)
//		{
//			printf("%d 0\n", arr[0]);
//			continue;
//		}
//		if (n % 2 == 0)
//		{
//			p = arr[n / 2];
//			for (int i = 0;i < n;i++)
//			{
//				sum += abs(p - arr[i]);
//			}
//		}
//		else
//		{
//			p = arr[(n - 1) / 2];
//			for (int i = 0;i < n;i++)
//			{
//				sum += abs(p - arr[i]);
//			}
//		}
//		printf("%d %d\n", p, sum);
//	}
//	return 0;
//}


//unsigned long long arr[67] = { 0 };
//unsigned long long fun(int n)
//{
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 2;
//	if (n == 3)
//		return 4;
//	if (n == 4)
//		return 8;
//	else
//	{
//		if (arr[n] != 0)
//			return arr[n];
//		else
//		{
//			arr[n] = fun(n - 1) + fun(n - 2) + fun(n - 3) + fun(n - 4);
//			return arr[n];
//		}
//	}
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		printf("%llu\n", fun(n));
//	}
//	return 0;
//}


//#define PI 3.1415
//int main()
//{
//	double x1, x2, y1, y2, r1, r2;
//	while (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2), x1 || x2 || y1 || y2)
//	{
//		scanf("%lf %lf", &r1, &r2);
//		double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
//		double sum = r1 + r2, div = fabs(r1 - r2);
//		double s = 0;
//		if (d >= sum)//相切或相离
//			s = 0;
//		else if (d <= div)//相容
//			s = PI * r1 * r1 <= PI* r2* r2 ? PI * r1 * r1 : PI * r2 * r2;
//		else//相交
//		{
//			double a1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
//			double a2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
//			double sin1 = sqrt(1 - cos(a1) * cos(a1));
//			double s1 = (a1 / 2) * r1 * r1;
//			double s2 = (a2 / 2) * r2 * r2;
//			s = (s1 + s2 - (1.0 / 2) * r1 * d * sin1) * 2;
//		}
//		printf("%.2lf\n", s);
//	}
//	puts("Over!");
//	return 0;
//}

//int main()
//{
//	char a1[202] = { 0 };
//	char a2[202] = { 0 };
//	while (~scanf("%s%s", a1, a2))
//	{
//		char b[205] = { 0 };
//		int len1 = strlen(a1);
//		int len2 = strlen(a2);
//		int len = strlen(a1) > strlen(a2) ? strlen(a1) : strlen(a2);
//		for (int i = 0;i < len;i++)
//		{
//			if (a1[i])
//				a1[i] -= '0';
//			if (a2[i])
//				a2[i] -= '0';
//		}
//		for (int i = len1 - 1;i >= 0;i--)
//		{
//			b[len1 - 1 - i] += a1[i];
//		}
//		for (int i = len2 - 1;i >= 0;i--)
//		{
//			b[len2 - 1 - i] += a2[i];
//		}
//		for (int i = 0;i <= len;i++)
//		{
//			if (b[i] > 1)
//			{
//				do
//				{
//					b[i] -= 2;
//					b[i + 1]++;
//				} while (b[i] > 1);
//			}
//		}
//		int jud = 0;
//		for (int i = len;i >= 0;i--)
//		{
//			if (b[i])
//			{
//				if (jud)
//					printf(" ");
//				printf("%d", i + 1);
//				if (jud == 0)
//					jud = 1;
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
//		int a, b, c;
//		int combo = 0, max = 0, min = 0;
//		scanf("%d %d %d", &a, &b, &c);
//		while (1)
//		{
//			while (combo < c)
//			{
//				max += 50 * (combo * 2 + 1);
//				combo++;
//				while (combo < b + c)
//				{
//					max += 100 * (combo * 2 + 1);
//					combo++;
//
//					while (combo < a + b + c)
//					{
//						max += 300 * (combo * 2 + 1);
//						combo++;
//					}
//				}
//			}
//			if (combo >= (a + b + c))
//				break;
//		}
//		combo = 0;
//		while (1)
//		{
//			if (combo > (a + b + c))
//				break;
//			while (combo < a)
//			{
//				min += 300 * (combo * 2 + 1);
//				combo++;
//				while (combo < a + b)
//				{
//					min += 100 * (combo * 2 + 1);
//					combo++;
//					while (combo < a + b + c)
//					{
//						min += 50 * (combo * 2 + 1);
//						combo++;
//					}
//				}
//			}
//			if (combo >= (a + b + c))
//				break;
//		}
//		printf("%d %d", min, max);
//	}
//
//	return 0;
//}


//int jud(int n)
//{
//	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
//		return 1;
//	return 0;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n, y, r;
//		int x = 0;
//		scanf("%d-%d-%d",&n,&y,&r);
//		x += r;
//		for (int i = y - 1;i > 0;i--)
//		{
//			if (i == 2)
//			{
//				if (jud(n))
//					x += 29;
//				else
//					x += 28;
//			}
//			else if (i == 4 || i == 6 || i == 9 || i == 11)
//			{
//				x += 30;
//			}
//			else
//				x += 31;
//		}
//		printf("%d ", x);
//		int xq = 0;
//		for (int n2 = 2014;n2 != n;)
//		{
//			if (n2 > n)
//			{
//				n2--;
//				xq--;
//				if (jud(n2))
//					xq--;
//			}
//			if (n2 < n)
//			{
//				n2++;
//				xq++;
//				if (jud(n2 - 1))
//					xq++;
//			}
//		}
//		int tmp = 3 + (xq + x - 1) % 7;
//		if (tmp > 7)
//			tmp -= 7;
//		else if (tmp < 1)
//			tmp += 7;
//		switch (tmp)
//		{
//		case 1:
//			printf("Monday\n", tmp);
//			break;
//		case 2:
//			printf("Tuesday\n", tmp);
//			break;
//		case 3:
//			printf("Wednesday\n", tmp);
//			break;
//		case 4:
//			printf("Thursday\n", tmp);
//			break;
//		case 5:
//			printf("Friday\n", tmp);
//			break;
//		case 6:
//			printf("Saturday\n", tmp);
//			break;
//		case 7:
//			printf("Sunday\n", tmp);
//			break;
//		default:
//			break;
//		}
//	}
//	return 0;
//}



int main()
{
	int n, m;
	while (~scanf("%d %d", &n, &m))
	{
		int city[20][21] = { 0 };
		while(m--)
		{
			int t1, t2, dis;
			scanf("%d %d %d", &t1, &t2, &dis);
			city[t1][t2] = dis;
			city[t2][t1] = dis;
		}
		int t1, t2;
		int d = 0, min = 0;
		scanf("%d %d", &t1, &t2);
		for (int i = 1;i <= n;i++)
		{

		}
	}
	return 0;
}