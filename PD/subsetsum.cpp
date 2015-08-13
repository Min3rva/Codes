#include <iostream>
#include <cstdio>

using namespace std;

bool subsetsum(int set[], int n, int sum)
{
    bool subset[sum+1][n+1];

    for (int i = 0; i <= n; i++)
      subset[0][i] = true;
 
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
 
     // Fill the subset table in botton up manner
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
 
	 /*// uncomment this code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%d", subset[j][i]);
       printf("\n");
     }*/

	return subset[n][sum];
}


int main()
{

	int sum, n;

	cin >> n >> sum;

	int set[n];

	for(int i=0; i<n; i++)
		cin >> set[i];

	if(subsetsum(set,n,sum))
		cout << "Existe" << endl;
	else 
		cout << "Nao existe" << endl;

	return 0;
}