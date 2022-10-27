#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>



////Ѱ���������Ƿ���Ҫ�ҵ�����������λ��
//int sch(int n, int a[], int i )
//{
//	int l;
//	int r;
//	l = 0;
//	r = i - 1;
//	do
//	{
//		if (a[(l + r) / 2] < n)
//			l = ((l + r) / 2) + 1;
//		else if (a[(1 + r) / 2] > n)
//			r = ((l + r) / 2) - 1;
//		else
//			return ((l + r) / 2) + 1;
//	}
//	while (l <= r);
//	return 0;
//
//	
//}
//int main()
//{
//	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
//	int n;
//	int i = sizeof(a) / sizeof(a[0]);
//	printf("����Ҫ���ҵ���");
//	scanf_s("%d", &n);
//
//
//	if (sch(n, a, i) != 0)
//	{
//		printf("�ҵ��ˣ���%d��", sch(n, a, i));
//	}
//	else
//		printf("�Ҳ���");
//	return 0;
// }



////��һ������һ�ĺ���
//void add(int* p)
//{
//	(*p) ++;
//}
//int main()
//{
//	int num = 0;
//	add(&num);
//	printf("%d", num);
//
//
//	return 0;
//}



////ģ��strlen��ʵ�֣��ݹ飩
//int my_strlen(char* a)
//{
//	if (*a != '\0')
//	{
//		return 1 + my_strlen(a+1);
//	}
//	else
//		return 0;
//	
//}
//int main()
//{
//	char arr[] = "bowten";
//	printf("%d", my_strlen(arr));
//	return 0;
//}


////�׳˺������ݹ飩
//int fact(int n)
//{
//	if (n != 1)
//		return n * fact(n - 1);
//	else
//		return 1;
//}
//int main()
//{
//	int n = 4;
//	printf("%d", fact(n));
//	return 0;
//}


////����ڼ���쳲�������
//int fb(int n)
//{
//	if (n == 1)
//		return 1;
//	else if (n == 2)
//		return 1;
//	else
//		return fb(n - 1) + fb(n - 2);
//
//}

//
//int fb(int n)
//{
//	if (n == 1)
//		return 1;
//	int a = 0, b = 1, c = 1, i = 1;
//	for (i = 2; i <= n; i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return c;
//
//}
//int main()
//{
//	int n = 3;
//	printf("%d", fb(10));
//	return 0;
//}



////��ת�ַ���
//int my_strlen(char* str)
//{
//	if ((*str) != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//		return 0;
//}
//void reverse(char* str)
//{
//	int left = 0;
//	int right = my_strlen(str) - 1;
//	char tmp;
//	while(left<right)
//	{
//		tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		left++;
//		right--;
//	}
//	
//}
//int main()
//{
//	char arr[20] = "abcdef";
//	reverse(arr);
//	printf("%s", arr);
//	return 0;
//}

////��ת�ַ���
//void reverse(char* str,int a,int b)
//{
//	if (a >= b)
//		return 0;
//	int left = a - 1;
//	int right = b - 1;
//	char tmp = str[left];
//	str[left] = str[right];
//	str[right] = tmp;
//	reverse(str, a + 1, b - 1);
//
//
//}
//int main()
//{
//	char arr[] = "abcde";
//	reverse(arr, 1, 5);
//	printf("%s", arr);
//	return 0;
//}

////����һ��������ÿλ֮��
//int add(int a)
//{
//	int b = a % 10;
//	a = a / 10;
//	if (a != 0)
//		return b + add(a);
//	else
//		return 0;
//}
//int main()
//{
//	int a = 123456;
//	printf("%d", add(a));
//	return 0;
//}

////����n��k�η�
//float power(int n, int k)
//{
//	if (k == 0)
//	{
//		if (n == 0)
//		{
//			printf("error");
//			return 0;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	else if (k > 0)
//	{
//		return n * power(n, (k - 1));
//	}
//	else if(k < 0)
//	{
//		return 1.0 / power(n, -k);
//	}
//}
//int main()
//{
//	int n, k;
//	scanf("%d %d", &n, &k);
//	printf("\n\n%f\n\n", power(n, k));
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 1,2,3,0,4,5,6,7 };
//	printf("%d", strlen(arr));
//	return 0;
//}


//int main()
//{
//	printf("%d", '/0');
//	return 0;
//}


////��ӡ����
//int main()
//{
//	int i, j;
//	scanf("%d %d", &i, &j);
//	for (int n = 0;n < i;n++)
//	{
//		printf("*");
//		for (int m = 0;m < j - 2;m++)
//		{
//			if (n == 0 || n == i - 1)
//				printf("*");
//			else
//				printf(" ");
//		}
//		printf("*");
//		printf("\n");
//	}
//	return 0;
//}


//�漣ůů��ҵ
//int main()
//{
//	int num = 0;
//	while (1)
//	{
//		int i = 0;
//		scanf("%c", &i);
//		if (i != 10)
//		{
//			if(i != 32)
//			num = num + i - 64;
//		}
//		else
//			break;
//	}
//	printf("%d", num);
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	while (1)
//	{
//		int i = _getch();
//		if (i != 13)
//		{
//			if (i != 32)
//				num = num + i - 64;
//		}
//		else
//			break;
//	}
//	printf("%d", num);
//	return 0;
//}


////ģ��ʵ��strlen
//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	if (*str == '\0')
//		return 0;
//	return 1 + my_strlen(str + 1);
//}
//int main()
//{
//	int n = my_strlen("holle");
//	printf("%d", n);
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char arr[20];
//    scanf("%s", arr);
//    if (strlen(arr) > 10)
//        printf("BAD");
//    else
//        printf("GOOD");
//    return 0;
//}


//int main()
//{
//	int zs = 0;//��������
//	int arr[]={0,0,0,0,0,0,0,0,0,0};//���Ture��
//	int* cop = arr;
//	while(1)
//	{
//		int n;
//		n = getchar() - 48;
//		if (n != -38)
//		{
//			for (int i = 0;i < n;i++)
//			{
//				char str[20];
//				scanf("%s", str);
//				if (strcmp(str, "True") == 0)
//				{
//					(*cop)++;
//				}
//			}
//			zs++;
//			cop++;
//			getchar();
//		}
//		else
//			break;
//	}
//	for (int i = 0;i < zs;i++)
//	{
//		printf("%d\n",arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int a;
//	a = getchar() - 48;
//	printf("%d", a);
//	return 0;
//}







////---------------------------------------------------
//void my_scanf(int* a)
//{
//	int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
//	int* parr = arr;
//	int count = 0;
//	while (1)
//	{
//		*parr = _getch() - 48;
//		if (*parr == -35)
//		{
//			printf("\n");
//			break;
//		}
//		printf("%d", *parr);
//		parr++;
//		count++;
//	}
//	for (int i = 1;i <= count;i++)
//	{
//		*a += arr[i - 1] * (int)pow(10, (count - i));
//	}
//	if (count == 0)
//		*a = -1;
//}
//int jud(int a)
//{
//	int i = 1;
//	while (i <= a)
//	{
//		if (i == a)
//			return 1;
//		i *= 2;
//	}
//	if (a % 1024 == 0)
//		return 1;
//	return 0;
//}
//int main()
//{
//	int zs = 0;//��������
//	int ans[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//��
//	int* ansp = ans;//���ƴ�
//	while (1)
//	{
//		int input = 0;
//		my_scanf(&input);
//		if (input == -1)
//			break;
//		if (jud(input))
//			*ansp = 1;
//		ansp++;
//		zs++;
//		
//	}
//	for (int i = 0;i < zs;i++)
//	{
//		if (ans[i])
//			printf("YES");
//		else
//			printf("NO");
//		if (i < zs - 1)
//			printf("\n");
//	}
//	return 0;
//}
////----------------------------------------------




//int main()
//{
//	int a = 0;
//	my_scanf(&a);
//	printf("%d", a);
//	return 0;
//}



//int jud(int a)
//{
//	int i = 1;
//	while (i <= a)
//	{
//		if (i == a)
//			return 1;
//		i *= 2;
//	}
//	if (a % 1024 == 0)
//		return 1;
//	return 0;
//}
//int main()
//{
//	int zs = 0;//��������
//	int ans[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//��
//	int* ansp = ans;//���ƴ�
//	for (int i = 0;i < 8; i++)
//	{
//		int input = 0;
//		scanf("%d", &input);
//		if (jud(input))
//			*ansp = 1;
//		ansp++;
//		zs++;
//	}
//	
//	for (int i = 0;i < zs;i++)
//	{
//		if (ans[i])
//			printf("YES");
//		else
//			printf("NO");
//		if (i < zs - 1)
//			printf("\n");
//	}
//	return 0;
//}





////����Ѱ��
//int bgi(int* arr, int j, int m,int n)
//{
//	int count = m - 1;
//	for (int i = m - 1;i < -1;i--)
//	{
//		if (i != 0)
//		{
//			if (varr(arr, i, j, n) > varr(arr, i - 1, j, n))
//			{
//				varr(arr, i - 1, j, n) = varr(arr, i, j, n);
//			}
//			else
//				count = i - 1;
//		}
//	}
//	return count;
//}
//int isbig(int* arr, int i, int j, int n)
//{
//	for (int r = 0; r < i;r++)
//	{
//
//	}
//}
//int varr(int* arr, int i, int j,int n)
//{
//	arr += (i - 1) * n + j;
//	return *arr;
//}
//int smj(int* arr,int i,int n)
//{
//	int count = n - 1;
//	for (int j = n - 1;j < -1;j--)
//	{
//		if (j != 0)
//		{
//			if (varr(arr, i, j, n) < varr(arr, i, j - 1, n))
//			{
//				varr(arr, i, j - 1, n) = varr(arr, i, j, n);
//			}
//			else
//				count = j - 1;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int x, y;
//	int m = 0, n = 0;
//	scanf("%d %d", &m, &n);
//	int arr[100];
//	for (int a = 0;a < 100;a++)
//	{
//		arr[a] = 0;
//	}
//	int* parr = arr;
//	for (int i = 0;i < m;i++)
//	{
//		for (int j = 0;j < n;j++)
//		{
//			scanf("%d", parr);
//			parr++;
//		}
//	}
//	for (int i = 0;i < m;i++)
//	{
//		int smj = smj(arr, i, n);
//		int bgi = bgi(arr, smj,m,n);
//		if (bgi == i)
//		{
//			x = bgi;
//			y = smj;
//		}
//	}
//	return 0;
//}






//void my_scanf(int* a)
//{
//	int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
//	int* parr = arr;
//	int count = 0;
//	while (1)
//	{
//		*parr = _getch() - 48;
//		if (*parr == -35)
//		{
//			printf("\n");
//			break;
//		}
//		printf("%d", *parr);
//		parr++;
//		count++;
//	}
//	for (int i = 1;i <= count;i++)
//	{
//		*a += arr[i - 1] * (int)pow(10, (count - i));
//	}
//	if (count == 0)
//		*a = -1;
//}
//int jud(int n)
//{
//	if (n % 3 == 0 && n % 2 == 0) {
//		return 11;
//
//	}
//	else {
//		return 10;
//
//	}
//
//	if (n % 3 == 0 || n % 2 == 0) {
//		return 21;
//
//	}
//	else {
//		return 20;
//
//	}
//	if ((n % 3 == 0 || n % 2 == 0) && (n % 6 != 0)) {
//		return 31;
//
//	}
//	else {
//		return 30;
//
//	}
//}
//int main()
//{
//	int zs = 0;//��������
//	int ans[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//��
//	int* ansp = ans;//���ƴ�
//	int anss[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };//��
//	int* ansps = anss;//���ƴ�
//	while (1)
//	{
//		my_scanf(ansps);
//		if (( * ansps) == -1)
//			break;
//		*ansp = jud((*ansps));
//		ansp++;
//		ansps++;
//		zs++;
//		
//	}
//	for (int i = 0;i < zs;i++)
//	{
//		switch (ans[i])
//		{
//		case 11:
//			printf("%d divisible by 2 and 3? 1\n", anss[i]);
//			break;
//		case 10:
//			printf("%d divisible by 2 and 3? 0\n", anss[i]);
//			break;
//		case 21:
//			printf("%d divisible by 2 or 3? 1\n", anss[i]);
//			break;
//		case 20:
//			printf("%d divisible by 2 or 3? 0\n", anss[i]);
//			break;
//		case 31:
//			printf("%d divisible by 2 or 3, but not both? 1", anss[i]);
//			break;
//		case 30:
//			printf("%d divisible by 2 or 3, but not both? 0", anss[i]);
//			break;
//		}
//		if (i < zs - 1)
//			printf("\n");
//	}
//	return 0;
//}



//int main()
//{
//    int t, n;
//    scanf("%d", &t);
//    while (t --)
//    {
//        scanf("%d", &n);
//        if (n % 3 == 0 && n % 2 == 0) 
//        {
//            printf("%d divisible by 2 and 3? 1\n", n);
//        }
//        else 
//        {
//            printf("%d divisible by 2 and 3? 0\n", n);
//        }
//        if (n % 3 == 0 || n % 2 == 0) 
//        {
//            printf("%d divisible by 2 or 3? 1\n", n);
//        }
//        else 
//        {
//            printf("%d divisible by 2 or 3? 0\n", n);
//        }
//        if ((n % 3 == 0 || n % 2 == 0) && (n % 6 != 0)) 
//        {
//            printf("%d divisible by 2 or 3, but not both? 1\n", n);
//        }
//        else 
//        {
//            printf("%d divisible by 2 or 3, but not both? 0\n", n);
//        }
//    }
//
//    return 0;
//}




//int jud(int a)
//{
//	int i = 1;
//	while (i <= a)
//	{
//		if (i == a)
//			return 1;
//		i *= 2;
//	}
//	if (a % 1024 == 0)
//		return 1;
//	return 0;
//}
//int main()
//{
//	int zs = 0;//��������
//	int ans[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//��
//	int* ansp = ans;//���ƴ�
//	int n;
//	scanf_s("%d", &n);
//	while (n > 0)
//	{
//		int input = 0;
//		scanf("%d", &input);
//		if (jud(input))
//			*ansp = 1;
//		ansp++;
//		zs++;
//		n--;
//	}
//	for (int i = 0;i < zs;i++)
//	{
//		if (ans[i])
//			printf("YES");
//		else
//			printf("NO");
//		if (i < zs - 1)
//			printf("\n");
//	}
//	return 0;
//}



//int main()
//{
//	while (1)
//	{
//		int n;
//		scanf("%d", &n);
//		if (n == 0)
//			break;
//		float h = 100.0;
//		for (int i = 0;i < n; i++)
//		{
//			h *= 0.7;
//		}
//		printf("%.2f\n", h);
//	}
//}


//int main()
//{
//	int arr[10];
//	int max;
//	int i;
//	for (i = 0;i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	max = arr[0];
//	for (i = 1;i < 10; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//	printf("max = %d", max);
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF)
//        printf("%d\n", a + b);
//    return 0;
//}




//int main()
//{
//	char a;
//	scanf("%c" ,& a);
//	printf("DEC:%d\nOCT:%o\nHEX:%x", a,a,a);
//	return 0;
//}


//int main()
//{
//	float a;
//	scanf("%f", &a);
//	printf("%d", (int)a);
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	while (i--)
//	{
//		float n;
//		int m;
//		scanf("%f %d", &n, &m);
//		float a = n / m;
//		printf("%.2f\n", a);
//	}
//	return 0;
//}




//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	while (n--)
//	{
//		int d;
//		int a = 0;
//		scanf("%d", &d);
//		int i = 1;
//		while (i <= d)
//		{
//			if (d == i)
//			{
//				a = 1;
//				break;
//			}
//			i += 3;
//		}
//		if (a == 1)
//			printf("showshowshow\n");
//		else
//			printf("forever love\n");
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
//		scanf("%d", &a);
//		printf("%o\n", a);
//	}
//	return 0;
//}




//int main()
//{
//	float c, f;
//	scanf("%f", &c);
//	f = (9.0 / 5) * c + 32;
//	printf("%.2f", f);
//	return 0;
//}




//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int x,a,b,c,d,y;
//		scanf("%d", &x);
//		a = x / 1000;
//		x %= 1000;
//		b = x / 100;
//		x %= 100;
//		c = x / 10;
//		x %= 10;
//		d = x;
//		x = d * 1000 + c * 100 + b * 10 + a;
//		printf("%d\n", x);
//	}
//	return 0;
//}



//int main()
//{
//	int in;
//	int h, m, s;
//	scanf("%d", &in);
//	s = in % 60;
//	m = ((in - s) / 60) % 60;
//	h = (((in - s) / 60) - m) / 60;
//	printf("%d %d %d", h, m, s);
//	return 0;
//}



//int main()
//{
//	float x, y;
//	scanf("%f %f", &x, &y);
//	float av,sum,dif;
//	sum = x + y;
//	dif = x > y ? x - y : y - x;
//	av = sum / 2.0;
//	printf("%.2f\n%.2f\n%.2f\n", sum, dif, av);
//	return 0;
//}



//int main()
//{
//	
//	int t;
//	while (scanf("%d", &t) != EOF)
//	{
//		int true = 0;
//		while (t--)
//		{
//			char arr[20];
//			scanf("%s", arr);
//			if (strcmp(arr, "True") == 0)
//				true ++;
//		}
//		printf("%d\n", true);
//	}
//	return 0;
//}





//int jud(int a)
//{
//	int i = 1;
//	while (i <= a)
//	{
//		if (i == a)
//			return 1;
//		i *= 2;
//	}
//	if (a % 1024 == 0)
//		return 1;
//	return 0;
//}
//int main()
//{
//	int t;
//	while (scanf("%d", &t) != EOF)
//	{
//		if (jud(t))
//			printf("YES\n");
//		else
//			printf("NO\n");
//	}
//	return 0;
//}


//int main()
//{
//int n = 0;
//scanf("%d", &n);
//while (n--)
//{
//	int d;
//	int a = 0;
//	scanf("%d", &d);
//	if(d == 1)
//		a = 1;
//	else
//	{
//		if ((d - 1) % 3 == 0)
//			a = 1;
//	}
//	if (a == 1)
//		printf("showshowshow\n");
//	else
//		printf("forever love\n");
//}
//return 0;
//}



//int main()
//{
//	printf("%d", 0 % 3);
//	return 0;
//}


//int main()
//{
//	char c;
//	while (1)
//	{
//		if (scanf("%d", &c) == EOF)
//			break;
//		printf("%c", c);
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
//		if (n <= 150)
//		{
//			printf("0\n");
//		}
//		else
//		{
//			if (n < 200)
//				printf("%d\n", n - 150);
//			else if (n < 300)
//				printf("%d\n", n - 200);
//			else
//				printf("%d\n", n % 50);
//		}
//
//	}
//	return 0;
//}



//int main()
//{
//	int  n;
//	while (1)
//	{
//		scanf("%d", &n);
//		if (n == 0)
//			break;
//		float h = 100;
//		while (n--)
//		{
//			h *= 0.7;
//		}
//		printf("%.2f\n", h);
//	}
//	return 0;
//}


//int main()
//{
//	int a, b, c, d, ak, p;
//	float e;
//	while (scanf("%d %d %d %d %f %d %d", &a, &b, &c, &d, &e, &ak, &p) != EOF)
//	{
//		float m = 0;
//		if (a != 0)
//			m += e / a;
//		if (b != 0)
//			m += e / b;
//		if (c != 0)
//			m += e / c;
//		if (d != 0)
//			m += e / d;
//		if (ak == 1)
//			m += 5;
//		if (p == 1)
//			m += 5;
//		if (p == 2)
//			m += 3;
//		if (p == 3)
//			m += 1;
//		printf("%.2f\n", m);
//	}
//	return 0;
//}


//int main()
//{
//	int a, b, c, t;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a > b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a > c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b > c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}


//int main()
//{
//	int n,i = 0;
//	int max, min;
//	float av = 0;
//	int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
//	scanf("%d", &n);
//	while ( i < n)
//	{
//		scanf("%d", &arr[i]);
//		av += arr[i];
//		i++;
//	}
//	av /= n;
//	max = arr[0];
//	min = arr[0];
//	for (i = 1;i < n;i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//		if (arr[i] < min)
//			min = arr[i];
//	}
//	printf("%d %d %.1f", max, min, av);
//	return 0;
//}



//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n,a,b,c,d,e;
//		scanf("%d", &n);
//		a = n / 100;
//		n %= 100;
//		b = n / 50;
//		n %= 50;
//		c = n / 10;
//		n %= 10;
//		d = n / 5;
//		n %= 5;
//		e = n;
//		int sum = a + b + c + d + e;
//		printf("%d\n", sum);
//	}
//	return 0;
//}



//int main()
//{
//	//an = (-1)^(n+1)(1/2n-1)
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		double s = 0,a;
//		for (int i = 1;i <= n;i++)
//		{
//			a = 1.0 / (2 * i - 1);
//			if (i % 2 == 0)
//				a *= -1;
//			s += a;
//		}
//		printf("%.5f\n", s);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
//	while (scanf("%d", &n) != EOF)
//	{
//		int sum = 0;
//		while (n--)
//		{
//			scanf("%d", &arr[n]);
//			if (arr[n] % 2 == 1)
//				sum += arr[n];
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	int arr[100];
//	while (scanf("%d", &n) != EOF)
//	{
//		int sum = 0, psum = 0;
//		double dsum = 0;
//		for(int i = 0;i < n;i ++ )
//		{
//			scanf("%d", &arr[i]);
//			if (arr[i] % 2 == 0)
//			{
//				sum += arr[i];
//				psum += arr[i] * arr[i];
//				dsum += 1.0 / arr[i];
//			}
//		}
//		printf("%d %d %.2f\n", sum,psum,dsum);
//	}
//	return 0;
//}


//int jud(int a)
//{
//	for (int i = 2;i < a; i++)
//	{
//		if (a % i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	for (a;a <= b;a++)
//	{
//		if (jud(a))
//			printf("%d\n", a);
//	}
//	return 0;
//}



//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int a, b, c,com = 0,max = 0,min = 0;
//		scanf("%d %d %d", &a, &b, &c);
//		for (com = 0;com < c;com++)
//		{
//			max += 50 * (com * 2 + 1);
//		}
//		for (com;com < c + b;com++)
//		{
//			max += 100 * (com * 2 + 1);
//		}
//		for (com;com < a + b + c;com++)
//		{
//			max += 300 * (com * 2 + 1);
//		}
//		for (com = 0;com < a; com++)
//		{
//			min += 300 * (com * 2 + 1);
//		}
//		for (com;com < a+b; com++)
//		{
//			min += 100 * (com * 2 + 1);
//		}
//		for (com;com < a+b+c; com++)
//		{
//			min += 50 * (com * 2 + 1);
//		}
//		printf("%d %d\n", min, max);
//	}
//	return 0;
//}



//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		printf("%d", n);
//		if (n >= 100)
//			printf("rd");
//		else
//			printf("ss");
//		if (n % 100 / 10 == 1 || n % 100 / 10 == 5 || n % 100 / 10 == 9)
//			printf("nd");
//		else
//			printf("ss");
//		if (n % 10 == 2 || n % 10 == 3 || n % 10 == 7)
//			printf("st\n");
//		else
//			printf("ss\n");
//	}
//}


//int main()
//{
//	for (int a = 1;a <= 9;a++)
//	{
//		for (int b = 1;b <= a;b++)
//		{
//			printf("%d*%d=%d", a, b, a * b);
//			if (a != b)
//				printf(" ");
//		}
//		printf("\n");
//	}
//	return 0;
//}



//int main()
//{
//	int a, count = 0;
//	scanf("%d", &a);
//	while (1)
//	{
//		if (a == 1)
//			break;
//		if (a % 2 == 0)
//			a /= 2;
//		else
//			a = a * 3 + 1;
//		count++;
//	}
//	printf("%d", count);
//	return 0;
//}



//int main()
//{
//	int v, d;
//	while (scanf("%d %d", &v, &d) != EOF)
//	{
//		int t = 0;
//		if (d > v)
//			t = 1;
//		else
//		{
//			t = v / d;
//			if (t * d < v)
//				t++;
//			int c = t;
//			for (int i = 1;i < c;i++)
//			{
//				c -= i;
//				t++;
//			}
//		}
//		printf("%d\n", t);
//	}
//	return 0;
//}




//int main()
//{
//	int h;
//	char a;
//	while (1)
//	{
//		scanf("%c", &a);
//		if (a == '@')
//			break;
//		scanf(" %d", &h);
//		getchar();
//		int p1,p2;
//		p1 = p2 = h;
//		for (int i = 1;i <= h; i++)
//		{
//			for (int j = 1;j <= 2 * h - 1;j++)
//			{
//				if (i == h)
//					printf("%c", a);
//				else
//				{
//					if (j == p1 || j == p2)
//						printf("%c", a);
//					else
//						printf(" ");
//				}
//			}
//			p1++;
//			p2--;
//			printf("\n");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int isrn(int n)
//{
//	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
//		return 1;
//	return 0;
//}
//int isbig(int y)
//{
//	if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)
//		return 1;
//	return 0;
//}
//int main()
//{
//	int n, y, r;
//	scanf("%d %d %d", &n, &y, &r);
//	if (y == 2)//�ж϶��µ����
//	{
//		if (isrn(n))
//		{
//			if (r == 29)
//			{
//				r = 1;
//				y++;
//			}
//			else
//				r++;
//		}
//		else
//		{
//			if (r == 28)
//			{
//				r = 1;
//				y++;
//			}
//			else
//				r++;
//		}
//	}
//	else
//	{
//		if (isbig(y))//�жϴ��µ����
//		{
//			if (r == 31)
//			{
//				r = 1;
//				if (y == 12)
//				{
//					y = 1;
//					n++;
//				}
//				else
//					y++;
//			}
//			else
//			{
//				r++;
//			}
//		}
//		else//С��
//		{
//			if (r == 30)
//			{
//				r = 1;
//				y++;
//			}
//			else
//				r++;
//		}
//	}
//	printf("%d %d %d", n, y, r);
//	return 0;
//}




//int main()
//{
//	int sum;
//	int arr[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//	int* pa = arr;
//	scanf("%d", &sum);
//	while (1)
//	{
//		if (sum >= 7)
//		{
//			sum -= 7;
//			*pa = 7;
//			pa++;
//		}
//		else if (sum < 7)
//		{
//			sum -= 4;
//			*pa = 4;
//			pa++;
//		}
//		else if(sum == 0)
//		{
//			break;
//		}
//	}
//	int i = 20;
//	while (i--)
//	{
//		if (arr[i] == 4)
//			printf("%d", arr[i]);
//	}
//	int j = 20;
//	while (j--)
//	{
//		if (arr[j] == 7)
//			printf("%d", arr[j]);
//	}
//	return 0;
//}



//int isrn(int n)
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
//		int y;
//		int n = 2022;
//		int d = 0;
//		int xq = 7;
//		scanf("%d", &y);
//		if (y > 2022)
//		{
//			while (1)
//			{
//				n ++;
//				if (isrn(n))
//					d += 366;
//				else
//					d += 365;
//				if (n == y)
//					break;
//			}
//			xq = d % 7;
//		}
//		else if (y < 2022)
//		{
//			while (1)
//			{
//				if (isrn(n))
//					d += 366;
//				else
//					d += 365;
//				n--;
//				if (n == y)
//					break;
//			}
//			xq = 7 - d % 7;
//		}
//		if (xq == 3 || xq == 4 || xq == 5 || xq == 6)
//			printf("5\n");
//		else if (xq == 2 || xq == 7)
//			printf("6\n");
//		else
//			printf("9\n");
//	}
//	return 0;
//}




//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int L, K;
//		int arr[5];
//		int kill = 0;
//		scanf("%d %d", &L, &K);
//		scanf("%d", &arr[0]);
//		scanf("%d", &arr[1]);
//		scanf("%d", &arr[2]);
//		scanf("%d", &arr[3]);
//		scanf("%d", &arr[4]);
//		if (L >= 6 && L < 11)
//		{
//			if (K)
//			{
//				int n = 5;
//				while (n--)
//				{
//					arr[kill] -= 300;
//					if (arr[kill] <= 0)
//						kill++;
//					if (kill == 5)
//						break;
//				}
//			}
//			else
//			{
//				int n = 4;
//				while (n--)
//				{
//					arr[kill] -= 300;
//					if (arr[kill] <= 0)
//						kill++;
//					if (kill == 5)
//						break;
//				}
//			}
//		}
//		else if (L >= 11 && L < 16)
//		{
//			if (K)
//			{
//				int n = 8;
//				while (n--)
//				{
//					arr[kill] -= 300;
//					if (arr[kill] <= 0)
//						kill++;
//					if (kill == 5)
//						break;
//				}
//			}
//			else
//			{
//				int n = 7;
//				while (n--)
//				{
//					arr[kill] -= 300;
//					if (arr[kill] <= 0)
//						kill++;
//					if (kill == 5)
//						break;
//				}
//			}
//		}
//		else if (L >= 16)
//		{
//			if (K)
//			{
//				int n = 12;
//				while (n--)
//				{
//					arr[kill] -= 300;
//					if (arr[kill] <= 0)
//						kill++;
//					if (kill == 5)
//						break;
//				}
//			}
//			else
//			{
//				int n = 10;
//				while (n--)
//				{
//					arr[kill] -= 300;
//					if (arr[kill] <= 0)
//						kill++;
//					if (kill == 5)
//						break;
//				}
//			}
//		}
//		switch (kill)
//		{
//		case 0:
//			printf("none\n");
//			break;
//		case 1:
//			printf("first blood\n");
//			break;
//		case 2:
//			printf("double kill\n");
//			break;
//		case 3:
//			printf("triple kill\n");
//			break;
//		case 4:
//			printf("ultra kill\n");
//			break;
//		case 5:
//			printf("rampage\n");
//			break;
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int isxy(int n)
//{
//	if (n == 0)
//		return 0;
//	while (1)
//	{
//		if (n == 0)
//			return 1;
//		int a = n % 10;
//		if (a != 4 && a != 7)
//			return 0;
//		n /= 10;
//	}
//}int count4(int n)
//{
//	int count = 0;
//	while (1)
//	{
//		if (n == 0)
//			break;
//		int a = n % 10;
//		if (a == 4 || a == 7)
//			count++;
//		n /= 10;
//	}if (count == 0)
//		return 4;
//	return count;
//}
//int main()
//{
//	long long n;
//	scanf("%lld", &n);
//	int x4 = count4(n);
//	if (isxy(n) && isxy(x4))
//		printf("YES");
//	else
//		printf("NO");
//	return 0;
//}




//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int x = n;
//		for (int i = 1;i <= 2 * n - 1;i++)
//		{
//			printf(" ");
//			int a = 1;
//			for (int j = 1;j <= 2 * n - 1;j++)
//			{
//				
//				if (j < x)
//					printf(" ");
//				else if (j >= x)
//				{
//					printf("%d", a);
//					if (j < n)
//						a++;
//					else
//						a--;
//				}
//				if (a == 0)
//					break;
//			}
//				printf("\n");
//			if (i < n)
//				x--;
//			else
//				x++;
//		}
//	}
//	return 0;
//}


//int sum(int n)
//{
//	int sum = 0;
//	while (n != 0)
//	{
//		sum += n % 10;
//		n /= 10;
//	}
//	return sum;
//}
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int dr;
//		dr = sum(n);
//		while (dr >= 10)
//		{
//			dr = sum(dr);
//		}
//		printf("%d\n", dr);
//	}
//	return 0;
//}



//int isLeap(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
//		return 29;
//	return 28;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		printf("%d ", isLeap(n));
//	}
//	return 0;
//}





//#include<stdio.h>
//#include<math.h>
//
//double happy(double x, double y, double z, double a, double b, double c, double d);
//double happy(double x, double y, double z, double a, double b, double c, double d)
//{
//    double ret;
//    ret = (x * a + y * b + z * c + d) / pow(a * a + b * b + c * c, 1.0/ 2);
//    if (ret < 0)
//        ret *= -1;
//    return ret;
//}
//int main() 
//{
//
//    double x, y, z, a, b, c, d;
//    while (scanf("%lf%lf%lf%lf%lf%lf%lf", &x, &y, &z, &a, &b, &c, &d) != EOF) {
//        printf("%.2lf ", happy(x, y, z, a, b, c, d));
//    }
//    return 0;
//}




//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//int isPrime[1000011];
//void getprime();
//int main()
//{
//    int t;
//    scanf("%d", &t);
//    getprime();
//    while (t--)
//    {
//        int n;
//        scanf("%d", &n);
//        if (isPrime[n])
//        {
//            printf("YES\n");
//        }
//        else
//        {
//            printf("NO\n");
//        }
//    }
//    return 0;
//}


//int f(int  n);
//int f(int n)
//{
//    if (n == 1 || n == 2)
//        return 1;
//    return f(n - 1) + f(n - 2);
//}
//int main()
//{
//    int t;
//    scanf("%d", &t);
//    while (t--)
//    {
//        int n;
//        scanf("%d", &n);
//        printf("%d\n ", f(n));
//    }
//    return 0;
//}


//int gcd(int x, int y)
//{
//	int tmp;
//	if (x < y)
//	{
//		tmp = y;
//		y = x;
//		x = tmp;
//	}
//	int c;
//	while (1)
//	{
//		c = x - y;
//		if (c == 1 || c == y)
//			return c;
//		if (y > c) {
//			x = y;
//			y = c;
//		}
//		else
//			x = c;
//	}
//}
//int gcd(int x, int y);
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n, m;
//		scanf("%d %d", &n, &m);
//		printf("%d ", gcd(n, m));
//	}
//	return 0;
//}



//int sum(int n)
//{
//	int sum = 0;
//	while (n != 0)
//	{
//		sum += n % 10;
//		n /= 10;
//	}
//	return sum;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", sum(n));
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		long long arr[3] = { 1,0,0 };
//		scanf("%lld", &arr[1]);
//		for (int i = 0;i < 28;i++)
//		{
//			arr[2] = arr[0]*2 + arr[1];
//			arr[0] = arr[1];
//			arr[1] = arr[2];
//		}
//		printf("%lld\n", arr[2]);
//	}
//	return 0;
//}




//int com(int x, int y);
//int com(int x, int y)
//{
//    long long a = x, j = 1;
//    for (long long i = 1;i <= y - 1;i++)
//    {
//        a *= x - i;
//    }
//    for (long long i = 1;i < y;i++)
//    {
//        j *= i + 1;
//    }
//    return a / j;
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


//void nz(char arr[200],int i)
//{
//	char a[200];
//	for (int x = i;x >= 0, x--)
//	{
//
//	}
//}
//int main()
//{
//	char arr[200];
//	for (int i = 0;i < 200;i++)
//	{
//		arr[i] = '\0';
//	}
//	int i = 0;
//	while (arr[i - 1] != '\n')
//	{
//		arr[i] = getchar();
//		i++;
//	}
//	nz(arr,i);
//		printf("%s", arr);
//	return 0;
//}




//int main()
//{
//	int x;
//	scanf("%d", &x);
//	if (x < 0)
//		printf("%.2f", pow(x + 1, 2) + 2.0 * x + 1.0 / x);
//	else
//		printf("%.2f", pow(x, 1.0 / 2));
//	return 0;
//}

//float cha(float x, float y)
//{
//	float ret = x- y;
//	if (ret < 0)
//		ret *= -1;
//	return ret;
//}
//int main()
//{
//	float a, b, c;
//	scanf("%f %f %f", &a, &b, &c);
//	if (a + b > c && a + c > b && b + c > a && cha(a, b) < c && cha(a, c) < b && cha(b, c) < a)
//		printf("%.2f", a + b + c);
//	else
//		printf("Invalid");
//	return 0;
//}




//int main()
//{
//	float n,m;
//	scanf("%d", &n);
//	if (n > 50)
//		m = 26.5 + (n - 50) * 0.58;
//	else
//		m = n * 0.53;
//	printf("%.2f", m);
//	return 0;
//}


//int main()
//{
//    unsigned float sal, tax, rat;
//    scanf("%f", &sal);
//    if (sal <= 850)
//        rat = 0;
//    else if (sal <= 1350)
//        rat = 0.05;
//    else if (sal <= 2850)
//        rat = 0.1;
//    else if (sal <= 5850)
//        rat = 0.15;
//    else
//        rat = 0.2;
//    tax = rat * (sal - 850);
//    printf("%.2f", tax);
//    return 0;
//}

//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int score = n / 10;
//	switch (score)
//	{
//	case 9:
//	case 10:
//		printf("A");
//		break;
//	case 8:
//		printf("B");
//		break;
//	case 7:
//		printf("C");
//		break;
//	case 6:
//		printf("D");
//		break;
//	default:
//		printf("E");
//		break;
//	}
//		return 0;
//}



//int cha(int x, int y)
//{
//	int ret = x - y;
//	if (ret < 0)
//		ret *= -1;
//	return ret;
//}
//int main()
//{
//	int a, b, c, zc;
//	float s, p;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a + b > c && a + c > b && b + c > a && cha(a, b) < c && cha(a, c) < b && cha(b, c) < a)
//	{
//		p = 1 / 2 * (a + b + c);
//		s = pow(p * (p - a) * (p - b) * (p - c), 1 / 2);
//		zc = a + b + c;
//		printf("area = %.2f; perimeter = %.2f", s, zc);
//	}
//	else
//		printf("These sides do not correspond to a valid triangle");
//	return 0;
//}



//int main()
//{
//	float n, m;
//	scanf("%f,%f", &n, &m);
//	if (n <= m * 1.1)
//		printf("OK");
//	else if (n > m * 1.1 && n <= m * 1.5)
//	{
//		float x = (n/ m - 1) *100.0;
//		printf("Exceed %.0f%%. Ticket 200", x);
//	}
//	else if(n > m*1.5)
//	{
//		float x = (n / m - 1) * 100.0;
//		printf("Exceed %.0f%%. License Revoked", x);
//	}
//	return 0;
//}



//int main()
//{
//	int a,b ;
//	scanf("%d %d", &a, &b);
//	printf("%d + %d = %d\n", a, b, a + b);
//	printf("%d - %d = %d\n", a, b, a - b);
//	printf("%d * %d = %d\n", a, b, a * b);
//	printf("%d / %d = %d\n", a, b, a / b);
//	printf("%d %% %d = %d\n", a, b, a % b);
//	return 0;
//}


//int main()
//{
//	int cm, fot, inc;
//	scanf("%d", &cm);
//	fot = cm / 30.48;
//	inc = (cm / 30.48 - fot) * 12;
//	printf("%d %d", fot, inc);
//	return 0;
//}


//int main()
//{
//	int arr[100];
//	for (int i = 0;i < 100; i++)
//	{
//		arr[i] = 0;
//	}
//	int t;
//	scanf("%d", &t);
//	for (int i = 0;i < t;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int row = (t-1)/3 + (t-1)%3;
//	for (int i = 0;i < row;i++)
//	{
//		for (int j = 0;j < 3;j++)
//		{
//			if (arr[j + i * 3 + 1] != 0)
//			{
//				printf("%d", arr[j + i * 3 + 1] - arr[j + i * 3]);
//				if (j != 2 && arr[j + i * 3 + 2] != 0)
//					printf(" ");
//			}
//		}
//		if(i != row - 1)
//			printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	int team[10000];
//	int man[10000];
//	int scor[10000];
//	int arr[10000];
//	for (int i = 0;i < 10000;i++)
//	{
//		team[i] = 0;
//		man[i] = 0;
//		scor[i] = 0;
//		arr[i] = 0;
//	}
//	scanf("%d", &n);
//	for(int i = 0;i < n;i ++)
//	{
//		scanf("%d-%d %d", &team[i], &man[i], &scor[i]);
//	}
//	for (int i = 0;i < n; i++)
//	{
//		arr[team[i]] += scor[i];
//	}
//	int mt = 0, ms = 0;
//	for (int i = 0;i < 10000;i++)
//	{
//		if (arr[i] > ms)
//		{
//			ms = arr[i];
//			mt = i;
//		}
//	}
//	printf("%d %d", mt, ms);
//	return 0;
//}


//int _jc(int n)
//{
//	if (n == 1)
//		return 1;
//	return n * _jc(n - 1);
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int jc = _jc(a + b);
//	printf("%d", jc);
//	return 0;



//int _max(int* arr, int n)
//{
//	int ret = arr[0];
//	for (int i = 0;i < n;i++)
//	{
//		if (arr[i] > ret)
//			ret = arr[i];
//	}
//	return ret;
//}
//int smal(int* arr, int n, int max)
//{
//	int ret = 0;
//	for (int i = 0;i < n; i++)
//	{
//		if (arr[i] > ret && arr[i] < max)
//			ret = arr[i];
//	}
//	return ret;
//}
//int main()
//{
//	int gra[1000], pat[1000];
//	for (int i = 0;i < 1000;i++)
//	{
//		gra[i] = 0;
//		pat[i] = 0;
//	}
//	int N, K, S;
//	scanf("%d %d %d", &N, &K, &S);
//	for(int i = 0;i < N;i ++)
//	{
//		scanf("%d %d", &gra[i], &pat[i]);
//	}
//	for (int x = 0;x < K;x++)//�ظ�K����
//	{
//		int max;
//		max = _max(gra, N);
//		while(max >= 175)//Ѱ��N��
//		{
//			int kg = 1;
//			for (int i = 0;i < N && kg;i++)
//			{
//				if (gra[i] == max && pat[i] == 0 && kg)
//				{
//					gra[i] = 0;
//					pat[i] = 0;
//					kg = 0;
//				}
//			}
//			if (kg)
//			{
//				for (int i = 0;i < N;i++)
//				{
//					if (gra[i] == max && pat[i] < S && pat[i] != 0 && kg)
//					{
//						gra[i] = 0;
//						pat[i] = 0;
//						kg = 0;
//					}
//				}
//			}
//			if(kg)
//			{
//				for (int i = 0;i < N;i++)
//				{
//					if (gra[i] == max && pat[i] >= S && kg)
//					{
//						gra[i] = 0;
//						pat[i] = 0;
//						kg = 0;
//					}
//				}
//			}
//			for (int j = 0;j < N;j++)
//			{
//				if (gra[j] == max && pat[j] >= S)
//				{
//					gra[j] = 0;
//					pat[j] = 0;
//				}
//			}
//			max = smal(gra, N, max);
//		}
//	}
//	int n = N;
//	for (int j = 0;j < N;j++)
//	{
//		if (gra[j] != 0)
//			n--;
//	}
//	printf("%d", N);
//	return 0;
//}



//int _sma(int* gra, int  n, int max)
//{
//	int ret = 0;
//	for (int i = 0;i < n;i++)
//	{
//		if (gra[i] > ret && gra[i] < max)//ѡ���ϴ��������
//			ret = gra[i];
//	}
//	return ret;
//}
//int _max(int* gra, int n)
//{
//	int ret = 0;
//	for (int i = 0;i < n;i++)
//	{
//		if (gra[i] > ret)
//			ret = gra[i];
//	}
//	return ret;
//}
//int main()
//{
//	int N, K, S;
//	scanf("%d %d %d", &N, &K, &S);
//	int gra[1000], pat[1000];
//	for (int i = 0;i < 1000;i++)
//	{
//		gra[i] = 0;
//		pat[i] = 0;
//	}
//	for (int i = 0;i < N;i++)
//	{
//		scanf("%d %d", &gra[i], &pat[i]);
//	}
//	for (int k = 0;k < K;k++)//ѭ��K����
//	{
//		int max = _max(gra, N);//����߷ֿ�ʼ����
//		while(max >= 175)//����߷ֿ�ʼ���ң�ֱ�������
//		{
//			int swi = 1;//��������
//			for (int i = 0; i < N && swi;i++)
//			{
//				if (gra[i] == max && pat[i] == 0 && swi)//��ѡpat=0��
//				{
//					gra[i] = 0;
//					pat[i] = 0;
//					swi = 0;//�رտ��أ���ʾ��ѡ��һ��ѧ��
//				}
//			}
//			for (int i = 0;i < N && swi;i++)
//			{
//				if (gra[i] == max && pat[i] < S && pat[i] != 0)//���ѡpat�������
//				{
//					gra[i] = 0;
//					pat[i] = 0;
//					swi = 0;
//				}
//			}
//			for (int i = 0;i < N && swi;i++)
//			{
//				if (gra[i] == max && pat[i] >= S)//���ѡpat�����
//				{
//					gra[i] = 0;
//					pat[i] = 0;
//					swi = 0;
//				}
//			}
//			for (int i = 0;i < N;i++)
//			{
//				if (gra[i] == max && pat[i] >= S)//�����ټ�pat�����
//				{
//					gra[i] = 0;
//					pat[i] = 0;
//				}
//			}
//			max = _sma(gra, N, max);//������һ��Ҫѡ�ߵ�ѧ���ķ���
//		}
//	}
//	int n = N;
//	for (int i = 0;i < N;i++)//�����м���ѧ��û��ѡ��
//	{
//		if (gra[i] != 0)
//			n--;
//	}
//	printf("%d", n);
//	return 0;
//}






//int main()
//{
//	int stu[300] = {0};
//	int n, k, s;
//	int sum = 0;
//	int gra , pat;
//	scanf("%d %d %d", &n, &k, &s);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d %d", &gra,&pat);
//		if (gra >= 175 && pat >= s)
//			sum++;
//		else if (gra >= 175)
//			stu[gra]++;
//	}
//	for (int i = 0;i < 291;i++)
//	{
//		if (stu[i] <= k)
//			sum += stu[i];
//		else
//			sum += k;
//	}
//	printf("%d", sum);
//	return 0;
//}


//int main()
//{
//    int num, max, min;
//    int x, y, i;
//    scanf("%d %d %d", &num, &max, &min);//�ֱ�Ϊ�������ϴ����������Կ���Ϊ�����ÿ���ֶο����ϴ�����������������Ժϸ�֡� 
//    int a[291] = { 0 };//��¼��ÿ���ֶ��ж����ˡ� 
//    int sum = 0;//¼ȡ������ 
//    for (i = 0;i < num;i++)
//    {
//        scanf("%d %d", &x, &y);
//        if (x >= 175)
//        {
//            a[x]++;
//            if (y >= min)
//            {
//                a[x]--;//��Ϊy��ֵ��������ͨ������Сֵ��˿����Ƹ�¼�ö���ռ�������Ҫa[x]--;sum++; 
//                sum++;
//            }
//        }
//    }
//    for (i = 0;i <= 290;i++)
//    {
//        if (a[i] <= max)sum += a[i];//�������ֶε������������ֵ��ֱ�Ӽ��ϡ� 
//        else sum += max;//�������ֻ�ܼ��Ͽ��ϴ������ֵҲ����max�� 
//    }
//    printf("%d", sum);
//    return 0;
//}


//int main()
//{
//	double r, h;
//	scanf("%lf %lf", &r, &h);
//	double s = 3.14159 * r * r;
//	double v = s * h;
//	printf("%lf", v);
//	return 0;
//}


//int main()
//{
//	int a, b, c, d, e;
//	scanf("%d", &a);
//	scanf("%d", &b);
//	scanf("%d", &c);
//	scanf("%d", &d);
//	scanf("%d", &e);
//	int a2 = a - 2 * e;
//	int b2 = b - 2 * e;
//	int c2 = c - 2 * e;
//	int s, v;
//	s = a * c * 2 +a*b*2+ b * c * 2 + 8 * d * (a2 + b2 + c2);
//	v = a * b * c - a2 * c2 * d * 2 - c2 * b2 * d * 2 - a2 * b2 * d * 2;
//	printf("%d %d", s, v);
//	return 0;
//}


//int main()
//{
//	float side;
//	scanf("%f", &side);
//	float s = (3.0*pow(3,1.0/2)/2.0)*side*side;
//	printf("%.2f", s);
//	return 0;
//}

//int main()
//{
//	int h, r;
//	scanf("%d %d", &h, &r);
//	float v = h * 3.14159 * r * r;
//	int n = 20000 / v;
//	if (20000 % (int)v != 0)
//		n++;
//	printf("%d", n);
//	return 0;
//}

//int main()
//{
//	while (1)
//	{
//		float n;
//		scanf("%f", &n);
//		printf("%d\n", (int)n);
//	}
//	return 0;
//}


//int main()
//{
//	float x,res;
//	scanf("%f", &x);
//	if (x == 10)
//		res = 1.0 / x;
//	else
//		res = x;
//	printf("f(%.1f) = %.1f", x, res);
//	return 0;
//}

//int main()
//{
//	int n, res;
//	scanf("%d", &n);
//	if (n < 0)
//		res = -1;
//	else if (n == 0)
//		res = 0;
//	else
//		res = 1;
//	printf("sign(%d) = %d", n, res);
//	return 0;
//}

//int main()
//{
//	int h, m,h2;
//	scanf("%d:%d", &h, &m);
//	if (h > 12 && h != 24)
//		h2 = h - 12;
//	else if (h == 24)
//		h2 = 0;
//	else
//		h2 = h;
//	printf("%d:%d ", h2, m);
//	if (h >= 12 && h < 24)
//		printf("PM");
//	else
//		printf("AM");
//	return 0;
//}

//int main()
//{
//	float tax, rat, sal;
//	scanf("%f", &sal);
//	if (sal <= 1600)
//		rat = 0;
//	else if (sal <= 2500)
//		rat = 0.05;
//	else if (sal <= 3500)
//		rat = 0.10;
//	else if (sal <= 4500)
//		rat = 0.15;
//	else if (sal > 4500)
//		rat = 0.2;
//	tax = (sal - 1600) * rat;
//	if (sal < 1600)
//		tax = 0;
//	printf("%.2f", tax);
//	return 0;
//}

//int main()
//{
//	double a, b, c,s,x,x2;
//	scanf("%lf %lf %lf", &a, &b, &c);
//	if (a == 0 && b == 0 && c == 0)
//		printf("Zero Equation");
//	else if (a == 0 && b == 0 && c != 0)
//		printf("Not An Equation");
//	else if (b * b - 4 * a * c == 0)
//		printf("%.2lf", -b / (2 * a));
//	else if (b * b - 4 * a * c > 0)
//		printf("%.2lf\n%.2lf", ( - b + pow((b * b - 4 * a * c), 1.0 / 2)) / (2 * a), ( - b - pow((b * b - 4 * a * c), 1.0 / 2))/ (2 * a));
//	else if (b * b - 4 * a * c < 0)
//	{
//		s = ( -b ) / (2 * a);
//		x = (pow((4 * a * c - b * b), 1.0 / 2)) / (2 * a);
//		x2 = -(pow((4 * a * c - b * b), 1.0 / 2)) / (2 * a);
//		printf("%.2lf + %.2lfi\n%.2lf + %.2lfi", s, x, s, x2);
//	}
//	return 0;
//}




//int isPrime[1000011];
//void getprime();
//void getprime()
//{
//    for (int i = 0;i < 1000011;i++)
//    {
//        isPrime[i] = 1;
//    }
//    isPrime[1] = 0;
//    for (int i = 2;2*i <= 1000011 ;i++)
//    {
//        isPrime[2 * i] = 0;
//    }
//    for (int i =2;3 * i <= 1000011;i++)
//    {
//        isPrime[3 * i] = 0;
//    }
//    for (int i = 2;5 * i <= 1000011;i++)
//    {
//        isPrime[5 * i] = 0;
//    }
//    for (int i = 2;7 * i <= 1000011;i++)
//    {
//        isPrime[7 * i] = 0;
//    }
//}
//int main()
//{
//    int t;
//    scanf("%d", &t);
//    getprime();
//    while (t--)
//    {
//        int n;
//        scanf("%d", &n);
//        if (isPrime[n])
//        {
//            printf("YES\n");
//        }
//        else
//        {
//            printf("NO\n");
//        }
//    }
//    return 0;
//}


//int main()
//{
//	int a=1, \
//		b\
//		=2, c\
//		=3;
//	printf("%d%d\
//%d \
//",\
//a,b,c);
//	return 0;
//


//void happy(int row);
//void happy(int row)
//{
//    if(row != 1)
//        happy(row - 1);
//    for (int i = 1;i <= row; i++)
//    {
//        printf("%d*%d=%d", i, row, i * row);
//        if (i != row)
//            printf(" ");
//    }
//    printf("\n");
//}
//int main() 
//{
//    happy(9);
//    return 0;
//}

//
//int isrn(int year)
//{
//    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//        return 1;
//    return 0;
//}
//int happy(int year, int month, int day);
//int happy(int year, int month, int day)
//{
//    if (month > 0 && month < 13)
//    {
//        if (isrn(year))
//        {
//            if (month == 2)
//            {
//                if (day > 0 && day < 30)
//                    return 1;
//                else
//                    return -2;
//            }
//            else if (month == 4 || month == 6 || month == 9 || month == 11)
//            {
//                if (day < 31 && day>0)
//                    return 1;
//                else
//                    return -2;
//            }
//            else
//            {
//                if (day < 32 && day>0)
//                    return 1;
//                else
//                    return -2;
//            }
//        }
//        else
//        {
//            if (month == 2)
//            {
//                if (day > 0 && day < 29)
//                    return 1;
//                else
//                    return -2;
//            }
//            else if (month == 4 || month == 6 || month == 9 || month == 11)
//            {
//                if (day < 31 && day>0)
//                    return 1;
//                else
//                    return -2;
//            }
//            else
//            {
//                if (day < 32 && day>0)
//                    return 1;
//                else
//                    return -2;
//            }
//        }
//    }
//    else
//        return -1;
//}
//int main() 
//{
//
//    char ch;
//
//    int year, month, day;
//
//    while (scanf("%d%c%d%c%d", &year, &ch, &month, &ch, &day) != EOF) {
//
//        printf("%d ", happy(year, month, day));
//
//    }
//
//    return 0;
//
//}


//double happy(double a);
//double a;
//double happy(double a)
//{
//    double x0 = 1, x1 = 0;
//    while (1)
//    {
//        x1 = 0.5 * (x0 + a / x0);
//        if ((x1 > x0?x1-x0:x0-x1)<0.0000001)
//            return x1;
//        x0 = x1;
//    }
//    return x1;
//}
//int main() {
//    while (scanf("%lf", &a) != EOF) {
//        printf("%.6lf ", happy(a));
//    }
//    return 0;
//}


//int jos(int n);
//int jos(int n)
//{
//    int arr[1000],a=0;
//    for (int i = 0;i < 1000;i++)
//    {
//        arr[i] = 1;
//    }
//    int i = 0;
//    int count = 0 , kg =1;
//    while(1)
//    {
//        while (1)
//        {
//            if (i == 0)
//                kg = 1;
//            if (i == n - 1)
//                kg = 0;
//            if (kg)
//            {
//                i++;
//                if(arr[i] == 1)
//                     count++;
//                if (count == 7)
//                    break;
//            }
//            else
//            {
//                i--;
//                if(arr[i] == 1)
//                    count++;
//                if (count == 7)
//                    break;
//            }
//        }
//        count = 0;
//        arr[i] = 0;
//        a++;
//        if (a == (n - 1))
//            break;
//    }
//    for (int x = 0;x < n;x++)
//    {
//        if (arr[x] == 1)
//            return x+1;
//    }
//}
//int main()
//{
//    int n, s, t;
//    scanf("%d", &t);
//    while (t--)
//    {
//        scanf("%d", &n);
//        s = jos(n);
//        printf("%d ", s);
//    }
//    return 0;
//}


//int main()
//{
//	double x, y;
//	scanf("%lf %lf", &x, &y);
//	double av, sum, dif;
//	sum = x + y;
//	dif = x-y;
//	av = sum / 2.0;
//	printf("%.2lf\n%.2lf\n%.2lf\n", sum, dif, av);
//	return 0;
//}


//int main()
//{
//	float x, y;
//	scanf("%f %f", &x, &y);
//	printf("%.2f\n%.2f\n%.2f\n", x + y, x - y, (x + y) / 2.0);
//	return 0;
//}


//int main()
//{
//	char arr[302];
//	int i = 1;
//	while (1)
//	{
//		scanf("%c", &arr[i]);
//		if (arr[i] == '\n')
//			break;
//		i++;
//	}
//	arr[0] = ' ';
//	arr[i+1] = 0;
//	int j = 1;
//	for (int i = 0;i < 302; i++)
//	{
//		if (arr[i - 1] == ' ' && (arr[i] == 'q' || arr[i] == 'Q'))
//		{
//			if(j != 1)
//				printf("\n");
//			while (1)
//			{
//				printf("%c", arr[i]);
//				i++;
//				if (arr[i] == ' '||arr[i] == '\n')
//					break;
//			}
//			j++;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	char arr[300];
//	scanf("%s", arr);
//	printf("%s %s %s %s ", arr);
//	return 0;
//}


//int main() {
//    void* p;
//    int cnt = 0;
//    while ((p = malloc(1024 * 1024 * 1024))) {
//        cnt++;
//    }
//    printf("������%d G\n", cnt);
//}



//int main()
//{
//	char arr[201] = {0};
//	int i = 1;
//	while (1)
//	{
//		scanf("%c", &arr[i]);
//		if (arr[i] == '\n')
//			break;
//		i++;
//	}
//	arr[0] = ' ';
//	int kg = 1;
//	for (int i = 1;i < 201; i++)
//	{
//		if (arr[i + 1] == ' '||arr[i+1] == '\n')
//		{
//			if (kg != 1)
//				printf(" ");
//			int j = i;
//			while (1)
//			{
//				printf("%c", arr[j]);
//				j--;
//				if (arr[j] == ' ')
//					break;
//			}
//			kg = 2;
//		}
//	}
//	return 0;
//}


//void move(int n, char c1, char c2, char c3);
//void move(int n, char c1, char c2, char c3)
//{
//
//    if (n == 1)
//        printf("%c->%c\n", c1, c3);
//    else
//    {
//        move(n - 1, c1, c3, c2);
//        move(1, c1, c2, c3);
//        move(n - 1, c2, c1, c3);
//    }
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    move(n, 'a', 'b', 'c');
//}


//int jos(int n);
//int jos(int n)
//{
//    int arr[1001];
//    int sum = 0;
//    int out = 0;
//    for (int i = 1;i <= n;i++)
//    {
//        arr[i] = 1;
//    }
//    while (1)
//    {
//        for (int i = 1;i <= n;i++)
//        {
//            if (arr[i] == 1)
//            {
//                sum++;
//                if (sum % 7 == 0)
//                {
//                    arr[i] = 0;
//                    out++;
//                }
//            }
//            if (out == n-1)
//            {
//                for (int j = 1;j <= n;j++)
//                {
//                    if (arr[j] == 1)
//                        return j;
//                }
//            }
//        }
//    }
//}
//int main()
//{
//    int n, s, t;
//    scanf("%d", &t);
//    while (t--)
//    {
//        scanf("%d", &n);
//        s = jos(n);
//        printf("%d ", s);
//    }
//    return 0;
//}



//int main()
//{
//	char arr[10000] = {0};
//	for (int i = 0;i < 10000;i++)
//	{
//		scanf("%d", &arr[i]);
//		if (arr[i] == '\n')
//			break;
//	}
//	printf("%s", arr);
//	return 0;
//}


//int main(void) {
//	int a, b, c, d, e, biao, ti;
//	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
//	biao = 2 * (a * b + b * c + a * c) + 8 * d * (a + b + c - 6 * e);
//	ti = a * b * c - 2 * d * ((a - 2 * e) * (b - 2 * e) + (a - 2 * e) * (c - 2 * e) + (b - 2 * e) * (c - 2 * e));
//	printf("%d %d", biao, ti);
//	return 0;
//}


//int main()
//{
//	int m;
//	char* p[13];
//	p[1] = "January";
//	p[2] = "February";
//	p[3] = "March";
//	p[4] = "April";
//	p[5] = "May";
//	p[6] = "June";
//	p[7] = "July";
//	p[8] = "August";
//	p[9] = "September";
//	p[10] = "October";
//	p[11] = "November";
//	p[12] = "December";
//	while (scanf("%d", & m) != EOF)
//	{
//		if (m > 12)
//			printf("Oh my God!\n");
//		else
//			printf("%s\n",p[m]);
//	}
//	return 0;
//}


//int main()
//{
//	int n,y;
//	while (scanf("%d", &y) != EOF)
//	{
//		n = y - 1996;
//		if (y < 0)
//			n++;
//		n = n % 12;
//		switch (n >= 0 ? n : 12 + n)
//		{
//		case 0:
//			printf("��\n");
//			break;
//		case 1:
//			printf("ţ\n");
//			break;
//		case 2:
//			printf("��\n");
//			break;
//		case 3:
//			printf("��\n");
//			break;
//		case 4:
//			printf("��\n");
//			break;
//		case 5:
//			printf("��\n");
//			break;
//		case 6:
//			printf("��\n");
//			break;
//		case 7:
//			printf("��\n");
//			break;
//		case 8:
//			printf("��\n");
//			break;
//		case 9:
//			printf("��\n");
//			break;
//		case 10:
//			printf("��\n");
//			break;
//		case 11:
//			printf("��\n");
//			break;
//		default:
//			break;
//		}
//	}
//	return 0;
//}



//int main()
//{
//	float* p[3];
//	float a, b, c;
//	p[0] = &a;
//	p[1] = &b;
//	p[2] = &c;
//	while ((scanf("%f %f %f", p[0], p[1], p[2])) != EOF)
//	{
//		if (*p[0] < *p[1])
//		{
//			float tmp = *p[0];
//			*p[0] = *p[1];
//			*p[1] = tmp;
//		}
//		if (*p[0] < *p[2])
//		{
//			float tmp = *p[0];
//			*p[0] = *p[2];
//			*p[2] = tmp;
//		}
//		if (*p[1] < *p[2])
//		{
//			float tmp = *p[1];
//			*p[1] = *p[2];
//			*p[2] = tmp;
//		}
//		printf("%.1f %.1f %.1f\n", *p[2], *p[1], *p[0]);
//	}
//	return 0;
//}



//int main()
//{
//	double a[10];
//	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]) != EOF)
//	{
//		double av,sum = 0;
//		for (int i = 0;i < 10;i++)
//		{
//			sum += a[i];
//		}
//		av = sum / 10;
//		printf("%.2lf\n", av);
//	}
//	return 0;
//}


//int main()
//{
//	int a[10] = {0};
//	scanf("%d %d %d %d %d %d %d %d %d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);
//	int min = a[0], max = a[0];
//	float av,sum = 0;
//	for (int i = 0;i < 10;i++)
//	{
//		sum += a[i];
//		if (a[i] > max)
//			max = a[i];
//		if (a[i] < min)
//			min = a[i];
//	}
//	av = sum / 10;
//	printf("%d %d %.2f\n", max, min, av);
//	return 0;
//}


//int main()
//{
//	int n;
//	int arr[10001];
//	while (scanf("%d", &n) != EOF)
//	{
//		int h = 0, ph = 0;
//		double dh = 0;
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i]);
//			if (arr[i] % 2 == 0)
//			{
//				h += arr[i];
//				ph += arr[i] * arr[i];
//				dh += (1.0 / arr[i]);
//			}
//		}
//		printf("%d %d %.2f\n", h, ph, dh);
//	}
//	return 0;
//}



//int isPrime[1000011];
//void getprime();
//void getprime()						
//{
//    for (int i = 0;i < 1000011;i++)
//    {
//        isPrime[i] = 1;
//    }
//    isPrime[1] = 0;
//    for (int i = 2;i < 100010;i++)
//    {
//        for (int j = 2 * i;j < 100010;j += i)
//            isPrime[j] = 0;					
//    }
//}
//int main()
//{
//    int t;
//    scanf("%d", &t);
//    getprime();
//    while (t--)
//    {
//        int n;
//        scanf("%d", &n);
//        getprime();
//        if (isPrime[n])
//        {
//            printf("YES\n");
//        }
//        else
//        {
//            printf("NO\n");
//        }
//    }
//    return 0;
//}


//int main()
//{
//	int a, b;
//	while (scanf("%d %d", &a, &b) != EOF)
//	{
//		printf("%d\n", a > b ? a : b);
//	}
//	return 0;
//}


//void fun0(int x)
//{
//	printf("����1�ź����Ĵ�ӡ�����\n");
//}
//void fun1(int x)
//{
//	printf("����2�ź����Ĵ�ӡ�����\n");
//}
//void fun2(int x)
//{
//	printf("����3�ź����Ĵ�ӡ�����\n");
//}
//int main()
//{
//	int a;
//	while (scanf("%d", &a) != EOF)
//	{
//		void (*p[3])(int) = {fun0,fun1,fun2};
//		(*p[a - 1])(1);
//	}
//	return 0;
//}


//void fun(int x)
//{
//	printf("%d", x);
//}
//int main()
//{
//	void (*p)(int) = &fun;
//	(*p)(2);
//}


//
//int main()
//{
//	while (1)
//	{
//		char arr[10010] = { 0 };
//		for (int i = 0;i < 10010;i++)
//		{
//			if (scanf("%c", &arr[i]) == EOF)
//				return 0;
//			if (arr[i] == '\n')
//			{
//				break;
//			}
//		}
//		for (int i = 0;i < 10010;i++)
//		{
//			if (i == 0 || arr[i] != arr[i - 1])
//				printf("%c", arr[i]);
//		}
//	}
//	return 0;
//}

//int stremp(char* s1, char* s2)
//{
//	for (int i = 0;i < 100;i++)
//	{
//		if (s1[i] != s2[i])
//		{
//			return s1[i] - s2[i];
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char s1[100] = { 0 }, s2[100] = { 0 };
//	while (scanf("%s%s", s1, s2) != EOF)
//	{
//		printf("%d\n", stremp(s1, s2));
//	}
//	return 0;
//}


//int main()
//{
//	while (1)
//	{
//		int arr[3][3];
//		int(*p)[3][3] = arr;
//		for (int i = 0;i < 3;i++)
//		{
//			for (int j = 0;j < 3;j++)
//			{
//				if (scanf("%d", &arr[i][j]) == EOF)
//					return 0;
//			}
//		}
//		for (int i = 0;i < 3;i++)
//		{
//			for (int j = 0;j < 3;j++)
//			{
//				printf("%d", (*p)[j][i]);
//				if (j != 2)
//					printf(" ");
//			}
//			printf("\n");
//			if (i == 2)
//				printf("\n");
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		int arr[100];
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		for (int i = n - 1;i >= 0;i--)
//		{
//			printf("%d ", arr[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	int n = strlen(arr);
//	if (arr[n - 1] == 'c')
//		printf("Word");
//	if (arr[n - 1] == 's')
//		printf("Excel");
//	if (arr[n - 1] == 't')
//		printf("PowerPoint");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	double g, n, s;
//	scanf_s("%lf", &g);
//	if (g <= 1600)
//	{
//		s = 0;
//		n = s * (g - 1600);
//		printf("%.2lf", n);
//	}
//	else if (g <= 2500)
//	{
//		s = 0.05;
//		n = s * (g - 1600);
//		printf("%.2lf", n);
//	}
//	else if (g <= 3500)
//	{
//		s = 0.1;
//		n = s * (g - 1600);
//		printf("%.2lf", n);
//	}
//	else if (g <= 4500)
//	{
//		s = 0.15;
//		n = s * (g - 1600);
//		printf("%.2lf", n);
//	}
//	else if (g > 4500)
//	{
//		s = 0.2;
//		n = s * (g - 1600);
//		printf("%.2lf", n);
//	}
//	return 0;
//}



//int main()
//{
//	int n, m, k;
//	int a[22][22], b[22][22], c[22][22] = {0};
//	scanf("%d%d%d", &n, &m, &k);
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < m;j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	for (int i = 0;i < m;i++)
//	{
//		for (int j = 0;j < k;j++)
//		{
//			scanf("%d", &b[i][j]);
//		}
//	}
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < k;j++)
//		{
//			for (int z = 0; z < m;z++)
//			{
//				c[i][j] += a[i][z] * b[z][j];
//			}
//		}
//	}
//	for (int i = 0;i < n; i++)
//	{
//		for (int j = 0;j < k;j++)
//		{
//			printf("%d", c[i][j]);
//			if (j < k - 1)
//				printf(" ");
//		}
//		if (i < n - 1)
//			printf("\n");
//	}
//	return 0;
//}



//int isPrime(int x);
//int isPrime(int x)
//{
//    if (x == 1)
//        return 0;
//    for (int i = 2;i < x;i++)
//    {
//        if (x % i == 0)
//            return 0;
//    }
//    return 1;
//}
//int main()
//{
//    int t;
//    scanf("%d", &t);
//    while (t--)
//    {
//        int n;
//        scanf("%d", &n);
//        if (isPrime(n))
//        {
//            printf("YES ");
//        }
//        else
//        {
//            printf("NO ");
//        }
//    }
//    return 0;
//}


//int map[40];
//int cli(int n)
//{
//	if (n == 1 || n == 2)
//		return n;
//	if (n == 3)
//		return 4;
//	if(map[n] == 0)
//		map[n] = cli(n - 1) + cli(n - 2) + cli(n - 3);
//	return map[n];
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		printf("%d\n", cli(n));
//	}
//	return 0;
//}


//int cli(int n)
//{
//	if (n == 1 || n == 2)
//		return n;
//	if (n == 3)
//		return 4;
//	int n1 = 1,n2 = 2,n3 = 4;
//	int n4;
//	for (int i = 4;i <= n;i++)
//	{
//		n4 = n1 + n2 + n3;
//		n1 = n2;
//		n2 = n3;
//		n3 = n4;
//	}
//	return n4;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n;
//		scanf("%d", &n);
//		printf("%d\n", cli(n));
//	}
//	return 0;
//}


//int main()
//{
//	for (int i = 4;i < 6;i++)
//	{
//		printf("YES");
//	}
//	return 0;
//}


//int main()
//{
//	char s1[100010] = {0}, s2[100010] = {0};
//	int n;
//	while (scanf("%s",s1) != EOF)
//	{
//		scanf("%s %d", s2,&n);
//		int len2 = strlen(s2);
//		for (int i = 0;i < len2;i++)
//		{
//			if (i == n)
//				printf("%s", s1);
//			printf("%c", s2[i]);
//		}
//		if (n == len2)
//			printf("%s", s1);
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	char s1[30] = { 0 }, s2[30] = { 0 };
//	while (scanf("%s", s1) != EOF)
//	{
//		scanf("%s", s2);
//		s2[0] += 32;
//		int len1 = strlen(s1);
//		int len2 = strlen(s2);
//		int len = len1 > len2 ? len2 : len1;
//		for (int i = 0;i < len;i++)
//		{
//			printf("%c%c", s1[i], s2[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}



//2n-1
//int main()
//{
//	double sum = 0;
//	int n;
//	scanf("%d", &n);
//	for (int i = 1;i <= n;i++)
//	{
//		sum += 1.0 / (2.0 * i - 1);
//	}
//	printf("%.2lf", sum);
//	return 0;
//}


//int main()
//{
//	double sum = 0;
//	for (int i = 1;1;i++)
//	{
//		double n = fabs(1.0 / ((3.0 * i) - 2));
//		if (n <= 0.000001)
//			break;
//		if (i % 2 != 0)
//			sum += n;
//		else
//			sum -= n;
//	}
//	printf("%.6lf", sum);
//	return 0;
//}



//int main()
//{
//	while (1)
//	{
//		char arr[10000] = {0};
//		for (int i = 0;i < 10000;i++)
//		{
//			if (scanf("%c", &arr[i]) == EOF)
//				return 0;;
//			if (arr[i] == '\n')
//				break;
//		}
//		for (int i = 0;i < strlen(arr);i++)
//		{
//			if (arr[i] == ' ')
//				arr[i] = '\n';
//				printf("%c", arr[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int a, b, c;
//	for (int i = 0;i <= 15;i++)
//	{
//		a = i;
//		for (int j = 0;3*i + 2*j <= 45;j++)
//		{
//			b = j;
//			c = 2*(45 - a * 3 - b * 2);
//			if(a + b + c ==45)
//				printf("men=%d, women=%d, child=%d\n", a, b, c);
//		}
//	}
//	return 0;
//}


//int main()
//{
//	double m, n,sum = 0;
//	scanf("%lf%lf", &m, &n);
//	while (m <= n)
//	{
//		sum += m * m + 1.0 / m;
//		m++;
//	}
//	printf("%lf", sum);
//	return 0;
//}



//int main()
//{
//	int a[100],sum =0;
//	for (int i = 0;i < 100;i++)
//	{
//		scanf("%d", &a[i]);
//		if (a[i] <= 0)
//			break;
//		if (a[i] % 2 != 0)
//			sum += a[i];
//	}
//	printf("%d", sum);
//	return 0;
//}


//int main()
//{
//	int arr[100],n,min = 0;
//	scanf("%d",&n);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	min = arr[0];
//	for (int i = 0; i < n;i++)
//	{
//		if (arr[i] < min)
//			min = arr[i];
//	}
//	printf("%d", min);
//	return 0;
//}

////int main()
////{
////	int n = 0;
////	scanf("%d", &n);
////	
////	return 0;
////}


//int main()
//{
//	char arr[5] = { 'C','h','i','n','a' };
//	for (int i = 0;i < 5;i++)
//	{
//		arr[i] += 4;
//		putchar(arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	double r, h,yzc,ymj,qmj,qtj,ztj;
//	scanf("%lf%lf", &r, &h);
//	yzc = 2 * 3.14159 * r;
//	ymj = 3.14159 * r * r;
//	qmj = 4 * ymj;
//	qtj = (4.0 / 3) * 3.14159 * r * r * r;
//	ztj = ymj * h;
//	printf("Բ�ܳ�=%.2lf\n\
//Բ���=%.2lf\n\
//�����=%.2lf\n\
//�����=%.2lf\n\
//�����=%.2lf",yzc,ymj,qmj,qtj,ztj);
//	return 0;
//}


//int main()
//{
//	char c1 = getchar(), c2 = getchar();
//	putchar(c1);
//	putchar(c2);
//	printf("\n%c%c", c1, c2);
//	return 0;
//}


//int main()
//{
//	long long arr[100],n,count = 0;
//	scanf("%lld", &n);
//	for(long long i = 0 ;i< 100;i++)
//	{
//		if (n == 0)
//			break;
//		arr[i] = n % 10;
//		n /= 10;
//		count++;
//	}
//	for (long long i = count - 1;i >= 0;i--)
//	{
//		printf("%lld", arr[i]);
//			printf(" ");
//	}
//}


//int main()
//{
//	int arr[50];
//	for(int i = 0;1;i++)
//	{
//		arr[i] = getchar() - 48;
//		if (arr[i] + 48 == 10)
//			break;
//	}
//	for (int i = 0;1;i++)
//	{
//		if (arr[i] + 48 == 10)
//			break;
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	for (int i = 0;1;i++)
//	{
//		if (i % 5 == 1 && i % 6 == 5 && i % 7 == 4 && i % 11 == 10)
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int h1, m1, h2, m2, n1, n2;
//	while (1)
//	{
//		scanf("%d", &n1);
//		h1 = n1 / 100;
//		//h2 = n2 / 100;
//		m1 = n1 % 100;
//		//m2 = n2 % 100;
//		//int h = h2 - h1;
//		//int m = m2 - m1;
//		int a = h1 / 10;
//		int b = h1 % 10;
//		int c = m1 / 10;
//		int d = m1 % 10;
//		printf("%d%d:%d%d\n", a, b, c, d);
//	}return 0;
//}

//int main()
//{
//	int h1, m1, h2, m2, n1, n2;
//	scanf("%d%d", &n1, &n2);
//	h1 = n1 / 100;
//	h2 = n2 / 100;
//	m1 = n1 % 100;
//	m2 = n2 % 100;
//	int h = h2 - h1;
//	int m = m2 - m1;
//	if (m < 0)
//	{
//		m += 60;
//		h--;
//	}
//	int a = h / 10;
//	int b = h % 10;
//	int c = m / 10;
//	int d = m % 10;
//	printf("%d%d:%d%d", a, b, c, d);
//	return 0;
//}

//int main()
//{
//	struct peo
//	{
//		char name[10];
//		char birth[20];
//		char gen;
//		char num[20];
//		char pho[20];
//	}arr[10];
//	int n;
//	scanf("%d", &n);
//	for(int i = 0;i < n;i ++)
//	{
//		scanf("%s %s %c %s %s", \
//			& arr[i].name, \
//			& arr[i].birth, \
//			& arr[i].gen, \
//			& arr[i].num, \
//			& arr[i].pho);
//	}
//	int k, a;
//	scanf("%d", &k);
//	for (int i = 0; i < k;i++)
//	{
//		scanf("%d", &a);
//		if (a >= 0 && a <= n)
//			printf("%s %s %s %c %s\n", \
//				arr[a].name, \
//				arr[a].num, \
//				arr[a].pho, \
//				arr[a].gen, \
//				arr[a].birth);
//		else
//			printf("Not Found\n");
//	}
//
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("0%d", n);
//	return 0;
//}


//int main()
//{
//	int n,tmp;
//	int a[10010] = { 0 };
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 0;i < n; i++)
//		{
//			scanf("%d", &a[i]);
//		}
//		for (int i = 0;i < n; i++)
//		{
//			for (int j = 0;j < n-1;j++)
//			{
//				if (abs(a[j]) > abs(a[j + 1]))
//				{
//					tmp = a[j];
//					a[j] = a[j + 1];
//					a[j + 1] = tmp;
//				}
//			}
//		}
//		for (int i = 0;i < n;i++)
//		{
//			printf("%d", a[i]);
//			if (i != n - 1)
//				printf(" ");
//		}
//		printf("\n\n");
//	}
//	return 0;
//}



//int main()
//{
//	while (1)
//	{
//		char arr[10010] = {0};
//		for (int i = 0;i < 10010;i++)
//		{
//			if (scanf("%c", &arr[i]) == EOF)
//				return 0;
//			if (arr[i] == '\n')
//				break;
//		}
//		for (int i = 0;1;i++)
//		{
//			if (i == 0)
//				printf("%c", arr[0]);
//			else
//			{
//				if(arr[i] != arr[i - 1])
//					printf("%c", arr[i]);
//			}
//			if(arr[i] == '\n')
//				break;
//		}
//	}
//	return 0;
//}



//int stremp(char* s1, char* s2)
//{
//	for (int i = 0;1;i++)
//	{
//		if (s1[i] - s2[i] != 0)
//			return s1[i] - s2[i];
//		if (s1[i] == '\n')
//			return 0;
//	}
//}
//int main()
//{
//	while(1)
//	{
//		char s1[1000] = {0}, s2[1000] = {0};
//		for (int i = 0;i < 1000;i++)
//		{
//			if (scanf("%c", &s1[i]) == EOF)
//				return 0;
//			if (s1[i] == '\n')
//				break;
//		}
//		for (int i = 0;i < 1000;i++)
//		{
//			if (scanf("%c", &s2[i]) == EOF)
//				return 0;
//			if (s2[i] == '\n')
//				break;
//		}
//		printf("%d\n", stremp(s1, s2));
//	}
//}



//int main()
//{
//	char arr[1000][1000] = {0};
//	int n, m, q;
//	scanf("%d%d%d", &n, &m, &q);
//	for (int i = 0;i < q;i++)
//	{
//		int a, b;
//		scanf("%d%d", &a, &b);
//		if (a == 0)
//		{
//			for (int y = 0;y < m;y++)
//			{
//				arr[b-1][y] = 1;
//			}
//		}
//		if (a == 1)
//		{
//			for (int x = 0;x < n;x++)
//			{
//				arr[x][b-1] = 1;
//			}
//		}
//	}
//	int count = 0;
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < m;j++)
//		{
//			if (arr[i][j] == 0)
//				count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}



//int main()
//{
//	int row = 0,col = 0;
//	int n, m, q,sum;
//	char arr[2][100000] = { 0 };
//	scanf("%d%d%d", &n, &m, &q);
//	sum = m * n;
//	for (int i = 0;i < q;i++)
//	{
//		int a, b;
//		scanf("%d%d", &a, &b);
//		if (arr[a][b] == 0)
//		{
//			if (a == 0)
//			{
//				sum = sum - m + col;
//				row++;
//			}
//			if (a == 1)
//			{
//				sum = sum - n + row;
//				col++;
//			}
//		}
//		arr[a][b] = 1;
//	}
//	printf("%d", sum);
//	return 0;
//}



//int main()
//{
//	int n, k, x,arr[100][100] = {0};
//	scanf("%d%d%d", &n, &k, &x);
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < n;j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int k2 = 1;
//	int kg = 1;
//	for (int j = 1;j < n;j += 2)
//	{
//		for (int i = n - 1;i >= 0;i--)
//		{
//			if ((i - k2) >= 0)
//				arr[i][j] = arr[i - k2][j];
//			else
//				arr[i][j] = x;
//		}
//		if (k > 1)
//		{
//			if (k2 == 1)
//				kg = 1;
//			if (k2 == k)
//				kg = 0;
//			if (kg)
//				k2++;
//			else
//				k2--;
//		}
//	}
//	for (int i = 0;i < n;i++)
//	{
//		int sum = 0;
//		for (int j = 0;j < n;j++)
//		{
//			sum += arr[i][j];
//		}
//		printf("%d", sum);
//		if (i != n - 1)
//			printf(" ");
//	}
//	return 0;
//}



//int main()
//{
//	int arr[10010] = { 0 },count = 0;
//	for (int i = 0;i < 100;i++)
//	{
//		int tmp[100],w;
//		for (int j = 0;j < 100;j++)
//		{
//			tmp[j] = getchar() - 48;
//			if (tmp[j] != -3 && (tmp[j] > 9 || tmp[j] < 0))
//			{
//				w = j;
//				break;
//			}
//		}
//		if (tmp[w] != -16 && tmp[w] != 3 && (tmp[w - 1] > 9 || tmp[w - 1] < 0))
//			break;
//		int a = 0;
//		for (int x = w - 1;x >= 0 ;x--)
//		{
//			if (tmp[x] != -3)
//			{
//				arr[i] += tmp[x] * pow(10, a);
//				a++;
//			}
//			else
//				arr[i] *= -1;
//		}
//		count++;
//	}
//	printf("�ӱ�׼�豸�������ݣ�ֱ�������Ƿ���������Ϊֹ\n");
//	for (int i = 0;i < count - 1;i++)
//	{
//		for (int j = 0;j < count - 1;j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tm = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tm;
//			}
//		}
//	}
//	for (int i = 0;i < count;i++)
//	{
//		printf("%d", arr[i]);
//		if (i != count - 1)
//			printf(" ");
//	}
//	return 0;
//}



//int main()
//{
//	int n,f,s,arr[300][300] = {0};
//	scanf("%d", &n);
//	for (int i = 0; i * 7 <= n;i++)
//	{
//		s = i;
//		for (int j = 0; j * 4 + 7 * i <= n;j++)
//		{
//			f = j;
//			if (7 * s + 4 * f == n)
//				arr[s][f] = 1;
//		}
//	}
//	int tmp = 0;
//	for (int i = 0;i < 300;i++)
//	{
//		for (int j = 0;j < 300;j++)
//		{
//			if (arr[i][j] == 1)
//			{
//				s = i;
//				f = j;
//				tmp = 1;
//			}
//		}
//	}
//	if (tmp)
//	{
//		for (int i = 0;i < f;i++)
//		{
//			printf("4");
//		}
//		for (int i = 0;i < s;i++)
//		{
//			printf("7");
//		}
//	}
//	else
//		printf("-1");
//	return 0;
//}



//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n, k,arr[10010] = {0}, a;
//		scanf("%d%d", &n, &k);
//		for (int i = 0;i < n; i++)
//		{
//			scanf("%d", &arr[i]);
//			if (arr[i] == k)
//				a = i;
//		}
//		printf("%d\n", a + 1);
//	}
//	return 0;
//}


//int main()
//{
//	int t, n, k;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d%d", &n, &k);
//		int a,kg = 0;
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &a);
//			if (a == k)
//				kg = 1;
//		}
//		if (kg)
//			printf("madan");
//		else
//			printf("why am I so diao");
//	}
//	return 0;
//}



//int main()
//{
//	int t, n, k, arr[100][100] = {0};
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d%d", &n, &k);
//		int sum = 0;
//		for (int i = 0;i < n;i++)
//		{
//			for (int j = 0;j < n;j++)
//			{
//				scanf("%d", &arr[i][j]);
//				if (i != j && arr[i][j] > k)
//					sum++;
//			}
//		}
//		printf("%d\n", sum / 2);
//	}
//	return 0;
//}


//int main()
//{
//	int t, n, k, m,arr[1000];
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d%d%d", &n, &k, &m);
//		for (int i = 0;i < m;i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		for (int i = 0;i < m - 1;i++)
//		{
//			for (int i = 0; i < m - 1;i++)
//			{
//				if (arr[i] > arr[i + 1])
//				{
//					int tmp = arr[i];
//					arr[i] = arr[i + 1];
//					arr[i + 1] = tmp;
//				}
//			}
//		}
//		int sum = 0;
//		for (int i = 0;i < k;i++)
//		{
//			sum += arr[i];
//		}
//		printf("%d\n", sum > n ? sum - n : 0);
//	}
//	return 0;
//}


//int main()
//{
//	int n, arr[100] = { 0 };
//	while (scanf("%d", &n) != EOF)
//	{
//		float sum = 0;
//		for (int i = 0;i < n;i++)
//		{
//			scanf("%d", &arr[i]);
//			sum += arr[i];
//		}
//		printf("%.2f\n", sum / n);
//	}
//	return 0;
//}



//int main()
//{
//	int t,n;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int birth[20] = {0}, sum = 1;
//		birth[1] = 1;
//		scanf("%d", &n);
//		for (int i = 1;i <= n;i++)
//		{
//			if (i > 1)
//			{
//				birth[i] = sum;
//				sum += birth[i];
//				if (i >= 3)
//				{
//					sum -= birth[i - 2];
//				}
//			}
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}

//
//int main()
//{
//	int n;
//	char* a[100];
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		a[i] = (char*)mall
//	}
//	for(int )
//	return 0;
//}


//int main()
//{
//	int a[10] = { 1 };
//}


//float fun(int n)
//{
//	float ret = 0;
//	if (n % 2 == 0)
//	{
//		for (int i = 2;i <= n;i += 2)
//		{
//			ret += 1.0 / i;
//		}
//	}
//	else
//	{
//		for (int i = 1;i <= n;i += 2)
//		{
//			ret += 1.0 / i;
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%.2f", fun(n));
//	return 0;
//}


//int main()
//{
//	int n;
//	char stu[30][30] = {0};
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%s", &stu[i]);
//	}
//	int a = 0;
//	for (int j = 0;j < strlen(stu[0]);j++)
//	{
//		for (int i = 0;i < n;i++)
//		{
//			if (stu[i][j] != stu[0][j])
//			{
//				printf("%d", a);
//				return 0;
//			}
//		}
//		a++;
//	}
//	printf("%d", a);
//	return 0;
//}


//int main()
//{
//	int arr[4][4],min;
//	for (int i = 0;i < 4;i++)
//	{
//		for (int j = 0;j < 4;j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	min = arr[0][0];
//	int x, y;
//	for (int i = 0;i < 4;i++)
//	{
//		for (int j = 0;j < 4;j++)
//		{
//			if (arr[i][j] < min)
//			{
//				min = arr[i][j];
//				x = i;
//				y = j;
//			}
//		}
//	}
//	printf("%d %d", x, y);
//	return 0;
//}


//int main()
//{
//	char a[100] = { 0 };
//	int n = 0;
//	scanf("%s %d", a,&n);
//	char* p = &a[n];
//	printf("%s", p);
//	return 0;
//}



//int main()
//{
//	int  n,x,y;
//	char map[4][4] = {0}, z;
//	scanf("%d", &n);;
//	while (n--)
//	{
//		scanf("%d %d %c", &x, &y,&z);
//		map[x][y] = z;
//	}
//	for (int i = 0;i < 4;i++)
//	{
//		for (int j = 0;j < 4; j++)
//		{
//			if (map[i][j] == 0)
//				printf("0");
//			else
//				printf("%c", map[i][j]);
//			if (j != 3)
//				printf(" ");
//		}
//		if (i != 3)
//			printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int cjc[10], loy[10],c = 0,l = 0;
//	for (int i = 0;i < 10;i++)
//	{
//		scanf("%d", &cjc[i]);
//		c += cjc[i];
//	}
//	for (int i = 0;i < 10;i++)
//	{
//		scanf("%d", &loy[i]);
//		l += loy[i];
//	}
//	if (c > l)
//		printf("why am i so diao?");
//	else
//		printf("cjc died!");
//	return 0;
//}



//int main()
//{
//	int t, n, m;
//	scanf("%d", &t);
//	while (t--)
//	{
//		char arr[100][1000] = { 0 };
//		scanf("%d%d", &n, &m);
//		getchar();
//		for (int i = 0;i < n;i++)
//		{
//			for (int j = 0;1;j++)
//			{
//				arr[i][j] = getchar();
//				if (arr[i][j] == '\n')
//				{
//					arr[i][j] = 0;
//					break;
//				}
//			}
//		}
//		char tmp;
//		int a, b;
//		while (m--)
//		{
//			scanf("%c %d %d", &tmp, &a, &b);
//			getchar();
//			a--;b--;
//			int la = strlen(arr[a]), lb = strlen(arr[b]);
//			if (tmp == 'A')
//			{
//				for (int i = 0; i < lb + 1;i++)
//				{
//					arr[a][la + i] = arr[b][i];
//				}
//			}
//			else
//			{
//				for (int i = 0; i < lb + 1;i++)
//				{
//					arr[a][i] = arr[b][i];
//				}
//			}
//		}
//		printf("%s\n", arr[0]);
//	}
//	return 0;
//}


//int main()
//{
//	char arr[100];
//	char* p = &arr[3];
//	arr[0] = 'a';
//	arr[1] = 'b';
//	arr[2] = 'c';
//	p = "holle";
//	printf("%s\n", arr);
//	char a[10] = "youar";
//	p = a;
//	printf("%s\n", p);
//	return 0;
//}

//int main()
//{
//	int t;
//	scanf("%d", &t);
//	getchar();
//	while (t--)
//	{
//		char arr[21] = {0};
//		int n;
//		for (int i = 0;i < 21;i++)
//		{
//			arr[i] = getchar();
//			if (arr[i] == '\n')
//			{
//				n = i;
//				break;
//			}
//		}
//		for (int i = 0;i < n;i++)
//		{
//			switch (arr[i] - 48)
//			{
//			case 1:
//				printf("one");
//				break;
//			case 2:
//				printf("two");
//				break;
//			case 3:
//				printf("three");
//				break;
//			case 4:
//				printf("four");
//				break;
//			case 5:
//				printf("five");
//				break;
//			case 6:
//				printf("six");
//				break;
//			case 7:
//				printf("seven");
//				break;
//			case 8:
//				printf("eight");
//				break;
//			case 9:
//				printf("nine");
//				break;
//			case 0:
//				printf("zero");
//				break;
//			default:
//				break;
//			}
//			if (i == n - 1)
//				printf("\n");
//			else if(arr[i] != ' ')
//				printf(" ");
//		}
//	}
//	return 0;
//}


//int main()
//{
//	char a = _getch();
//	return 0;
//}


//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		printf("1\n");
//	}
//	return 0;
//
//}



//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n, m,a[24] = {0},b[24] = {0};
//		scanf("%d%d", &n, &m);
//		while (n--)
//		{
//			int t1, t2;
//			scanf("%d%d", &t1, &t2);
//			for (int i = t1;i <= t2;i++)
//			{
//				a[i] = 1;
//			}
//		}
//		while (m--)
//		{
//			int t1, t2;
//			scanf("%d%d", &t1, &t2);
//			for (int i = t1;i <= t2;i++)
//			{
//				b[i] = 1;
//			}
//		}
//		int sum = 0;
//		for (int i = 0;i < 24;i++)
//		{
//			if (a[i] == 1 && b[i] == 1)
//				sum++;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}


//int isname(char* name, int n,char*rev,int i)
//{
//	int ret = 1;
//	for (int j = 0;j < n;j++)
//	{
//		if (name[j] != rev[i])
//			ret = 0;
//		i++;
//	}
//	return ret;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		char name[20] = { 0 },rev[1030] = {0};
//		scanf("%s", name);
//		getchar();
//		for (int i = 0;i < 1030;i++)
//		{
//			rev[i] = getchar();
//			if (rev[i] == '\n')
//			{
//				rev[i] = 0;
//				break;
//			}
//		}
//		int r = strlen(rev);
//		int n = strlen(name);
//		for (int i = 0;i < r;i++)
//		{
//			if (isname(name, n, rev, i))
//			{
//				printf("doctorZ");
//				i += n - 1;
//			}
//			else
//				printf("%c", rev[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}