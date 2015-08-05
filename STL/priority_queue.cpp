/*
*	Criado por: Talita Valéria
*	Data: 05/08/2015
*	Descrição: Exemplo de uso da priority_queue
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


/* Essa clase pode ser utilizada para tratar de estruturas em lista prioritária
*  Por default ela ela funciona como o less<T>
*  Passando cmp(true) irá funcionar como greater<T>
*/

class cmp
{
  bool reverse;
public:
  cmp(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (int left, int right)
  {
    if (reverse) return (left>right);
    else return (left<right);
  }
};


int main()
{

	/***
	**			COMPARADORES
	**		greater<int> menor->maior
	** 		less<int> 	 maior->maior (default)
	***/

	priority_queue<int, vector<int>, cmp > fila;

	fila.push(10);
	fila.push(1);
	fila.push(5);
	fila.push(9);

	cout << "Size-> " << fila.size() << endl;

	while(!fila.empty())
	{
		cout << fila.top() << " ";
		fila.pop();
	}	

	cout << endl;

	return 0;
}
