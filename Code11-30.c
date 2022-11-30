//#include<stdio.h>
//#include<math.h>
//#pragma warning (disable:4996)
//#define p1 7.8e3
//#define p2 0.95e3
//#define g 9.8
//#define D 2e-2
//#define h 0.2
//#define d 1.496e-3
//int main()
//{
//	double t = 0.0;
//	double sum = 0.0;
//	for (int i = 0; i < 5; i++)
//	{
//		scanf("%lf", &sum);
//		 t+= sum;
//	}
//	t /= 5;
//	printf("t=%lf\n",t);
//	printf("v=%lf\n",h/t);
//	double n = (p1 - p2) * g * pow(d,2) / (18 * (h / t) * (1 + 2.4 * d / D));
//	printf("n=%lf\n",n);
//	double Re = 0.0;
//	Re = (h / t) * d * p2 / n;
//	printf("Re=%lf\n",Re);
//	if (Re >= 0.1)
//	{
//		printf("需要进行修正:");
//		printf("n1=%lf\n",n*(1/(1+3*Re/16)));
//	}
//	return 0;
//}