/*
*	Criado por: Talita Valéria
*	Data: 05/08/2015
*	Descrição: Menor caminho dijkstra
*/
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <stack>
#define INF 100

using namespace std;

struct Node
{
	int V, custo;

	bool operator>(const Node &a)
	{
		return (custo > a.custo);
	}

	bool operator<(const Node &a)
	{
		return (custo < a.custo);
	}
};

class cmp
{
  bool reverse;
public:
  cmp(const bool& revparam=true)
    {reverse=revparam;}
  bool operator() (Node left, Node right)
  {
    if (reverse) return (left>right);
    else return (left<right);
  }
};

struct Grafo
{
	int qV;
	list<Node> *adj;
	vector<int> parent;
	vector<int> peso;
	vector<bool> visit;

	Grafo(int V): qV(V)
	{
		adj = new list<Node>[qV];
	}

	void addEdge(int v1, int v2, int custo)
	{
		Node no;

		no.V = v2;
		no.custo = custo;
		
		adj[v1].push_back(no);
	}

	stack<int> djk(int src, int dst)
	{
		Node no_src;
		
		priority_queue<Node, vector<Node>, cmp > fila;

		parent.assign(qV,-1);
		peso.assign(qV, INF);
		visit.assign(qV, false);

		peso[src] = 0;

		no_src.V = 0;
		no_src.custo = 0;

		fila.push(no_src);

		while(!fila.empty())
		{
			no_src = fila.top();

			cout << "V-> " << no_src.V << " Custo-> " << no_src.custo << endl;

			fila.pop();

			int u = no_src.V;

			visit[u] = true;

			for(list<Node>::iterator it = adj[u].begin(); it != adj[u].end(); it++)
			{
				if(!visit[(*it).V])
				{
					fila.push(*it);
					if(peso[u] + (*it).custo < peso[(*it).V])
					{
						peso[(*it).V] = peso[u] + (*it).custo;
						parent[(*it).V] = u;
					}
				}
			}

		}

		stack<int> pilha;
		int flag = dst;

		pilha.push(flag);

		while(flag != src)
		{
			flag = parent[flag];
			pilha.push(flag);
		}

		return pilha;
	}

	~Grafo()
	{
		adj->erase(adj->begin(), adj->end());
	}
};

int main()
{
	int qV, qE , v1, v2, custo;

	cin >> qV >> qE;

	Grafo graph(qV);

	for(int i=0; i<qE; i++)
	{
		cin >> v1 >> v2 >> custo;
		graph.addEdge(v1,v2, custo);
	}

	//cout << "Qnt vertices: " << graph.qV << "\nTamanho da lista: " << graph.adj->size() << endl;

	stack<int> path = graph.djk(0, 4);

	cout << "\n**** Menor caminho ****\n" << endl;

	while(!path.empty())
	{
		int vert = path.top();
		cout << "Vertice: " << vert << " Peso: " << graph.peso[vert] << endl;
		path.pop();
	}

	cout << endl;

	return 0;
}