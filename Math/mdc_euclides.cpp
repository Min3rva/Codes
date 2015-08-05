#include <iostream>

using namespace std;

int mdc(int , int);

int main()
{
	int a, b, divisor;


	cin >> a >> b;

	int menor = ( a<b ? a : b );
	int maior = ( a>b ? a : b );

	divisor = mdc(maior,menor);

	cout << divisor << endl;


	return 0;
}

int mdc(int maior, int menor)
{
	if (menor == 0) return maior;
	else return mdc(menor, maior%menor);
}