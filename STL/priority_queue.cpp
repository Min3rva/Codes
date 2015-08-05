/*
*	Criado por: Talita Valéria
*	Data: 05/08/2015
*	Descrição: Exemplo de uso da priority_queue
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{

	/***
	**			COMPARADORES
	**		greater<int> menor->maior
	** 		less<int> 	 maior->maior (default)
	***/

	priority_queue<int, vector<int>, greater<int> > fila;

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