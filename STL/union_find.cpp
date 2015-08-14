#include <iostream>
#include <vector>
#include <cstdio>
 
using namespace std;
 
struct union_find{
	vector<int> id, sz;

	union_find(int N)
	{
		id.assign(N,0);
		sz.assign(N,1);

		for(int i=1; i<=N; i++)
			id[i]=i;
	}

	int raiz(int i)
	{
		while(i != id[i])
    	{
        	id[i] = id[id[i]];
        	i = id[i];
    	}

    	return i;
	}

	void union_set(int p, int q)
	{
		int rootp = raiz(p);
        int rootq = raiz(q);

        if(rootp != rootq)
        {
            if(sz[rootp] < sz[rootq])
            {
                sz[rootq] += sz[rootp];
                id[rootp] = rootq;
            }
            else{
                sz[rootp] += sz[rootq];
                id[rootq] = rootp;          
            }
        }
	}

	~union_find()
	{
		id.erase(id.begin(), id.end());
		sz.erase(sz.begin(), sz.end());
	}

};
 
int main()
{
    int N, qnt;

    cin >> N >> qnt;
	
	union_find UF(N);

	for(int i=0; i<qnt; i++){
		int x, y;
		cin >> x >> y;

		UF.union_set(x, y);
	}

	/*for(int i=1; i<=N; i++){
		cout << UF.raiz(UF.id[i]) << " ";
	}
	cout << endl;*/

    return 0;
}