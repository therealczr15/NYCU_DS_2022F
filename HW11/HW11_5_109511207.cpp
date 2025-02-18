#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map> 
#include <algorithm> 

using namespace std;

class Edge
{
	public:
		int vertexA;
		int vertexB;
		int cost;
		Edge(int nA,int nB,int money);
		bool operator >(const Edge &e)const;
		bool operator <(const Edge &e)const;
		bool operator ==(const Edge &e)const;
		bool operator >=(const Edge &e)const;
		bool operator <=(const Edge &e)const;
		
}; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fstream iFile;
	iFile.open("input.txt");
	int v, e;
	iFile >> v >> e;
	vector<Edge> edge;
	int *set;
	set = new int [v];
	for(int i=0;i<v;i++)
		set[i] = i;
	vector<int> *setTable;
	setTable = new vector<int> [v];
	for(int i=0;i<v;i++)
		setTable[i].emplace_back(i);
	int count = 0; 
	for(int i=0;i<e;i++)
	{
		int nodeA, nodeB, money;
		iFile >> nodeA >> nodeB >> money;
		edge.push_back(Edge(nodeA,nodeB,money));
	}
	sort(edge.begin(),edge.end());
	int sum = 0;
	for(auto i:edge)
	{
		
		if(set[i.vertexA-1] == set[i.vertexB-1])
			continue;
		int na = set[i.vertexA-1], nb = set[i.vertexB-1];
		if(setTable[na].size() >=  setTable[nb].size())
		{
			for(auto j:setTable[nb])
			{
				setTable[na].emplace_back(j);
				set[j] = na;
			}
		}
		else
		{
			for(auto j:setTable[na])
			{
				setTable[nb].emplace_back(j);
				set[j] = nb;
			}
		}
		sum += i.cost;
		count++;
		if(count == v-1)
			break;
	}
	cout << sum << '\n';
	return 0;
} 

Edge::Edge(int nA,int nB,int money)
{
	vertexA = nA;
	vertexB = nB;
	cost = money;
}

bool Edge::operator >(const Edge &e)const
{
	return (cost > e.cost);
}

bool Edge::operator <(const Edge &e)const
{
	return (cost < e.cost);
}

bool Edge::operator ==(const Edge &e)const
{
	return (cost == e.cost);
}

bool Edge::operator >=(const Edge &e)const
{
	return (cost >= e.cost);
}

bool Edge::operator <=(const Edge &e)const
{
	return (cost <= e.cost);
}