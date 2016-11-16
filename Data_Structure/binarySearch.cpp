#include <bits/stdc++.h>

using namespace std;

int binarySearch(int num, int len, int v[])
{
	 int left, middle, right;                              
   left = 0; right = len-1;                           
   while (left <= right) {                          
      middle = (left + right)/2; 

      printf("%d\n", v[middle]);

      if (v[middle] == num) return middle;               
      if (v[middle] < num) left = middle + 1;               
      else right = middle - 1;                        
   }   

   return -1;                           
}

int main()
{
	int n, num, vec[100], search;

	scanf("%d %d", &n, &num);

	for(int i=0; i<n; i++)
		scanf("%d", &vec[i]);

	sort(vec, vec+n);

	search = binarySearch(num, n, vec);

	printf("%d\n", search);

	return 0;
}