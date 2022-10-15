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

int main()
{
	putchar('a');
	return 0;
}