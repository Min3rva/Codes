#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int nb, raiz, flag = 0;

	cin >> nb;

	raiz = sqrt(nb) + 1;

	if( (nb % 2 == 0 && nb>2) || nb == 1 ) flag = 1;
	else
	{
		for(int i = 3; i < raiz && !flag; i+=2)
			if(nb % i == 0) flag = 1;
	}

	if (flag) cout << "Not Prime" << endl;
	else cout << "Prime" << endl;

	return 0;
}
