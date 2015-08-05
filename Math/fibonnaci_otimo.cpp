#include <stdio.h>
#include <cmath>

double fib(int x)
{
	double mult = 1/sqrt(5);
	double termo = pow((1+sqrt(5))/2,x) - pow((1-sqrt(5))/2,x);

	return mult*termo;
}

int main()
{
	int qnt, x;

	scanf("%d",&qnt);
	

	for(int i=0; i<qnt; i++)
	{
		scanf("%d", &x);
		printf("Fib(%d) = %.lf\n", x, fib(x));
	}
	return 0;
}
