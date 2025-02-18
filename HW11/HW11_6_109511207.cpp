#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <limits.h>

using namespace std;

class Distance
{
	public:
		string city;
		int dis;
		Distance();
		Distance(string c,int d);
		bool operator >(const Distance &d)const;
		bool operator <(const Distance &d)const;
		bool operator ==(const Distance &d)const;
		bool operator >=(const Distance &d)const;
		bool operator <=(const Distance &d)const;
};

class Map
{
	public:
		map<string, vector<Distance>> cityMap;
		void buildMap();
		int Dijkstra(string start,string end);
};

int main()
{
	fstream iFile;
	iFile.open("input.txt");
	fstream oFile;
	oFile.open("answer.txt",ios::out);
	int num;
	Map myMap;
	myMap.buildMap();
	string startCity, endCity;
	iFile >> num;
	for(int i=0;i<num;i++)
	{
		iFile >> startCity >> endCity;
		oFile << myMap.Dijkstra(startCity,endCity) << '\n';
	}
	return 0;
}

Distance::Distance()
{
	city = "";	
	dis = 0;
} 
 
Distance::Distance(string c,int d)
{
	city = c;	
	dis = d;
} 

bool Distance::operator >(const Distance &d)const
{
	return (dis > d.dis);
}

bool Distance::operator <(const Distance &d)const
{
	return (dis < d.dis);
}

bool Distance::operator ==(const Distance &d)const
{
	return (dis == d.dis);
}

bool Distance::operator >=(const Distance &d)const
{
	return (dis >= d.dis);
}

bool Distance::operator <=(const Distance &d)const
{
	return (dis <= d.dis);
}

void Map::buildMap()
{
	cityMap["SanRafael"].push_back(Distance("a",12));
	cityMap["a"].push_back(Distance("SanRafael",12));
	cityMap["SanRafael"].push_back(Distance("Oakland",18));
	cityMap["Oakland"].push_back(Distance("SanRafael",18));
	cityMap["a"].push_back(Distance("SanFrancisco",3));
	cityMap["SanFrancisco"].push_back(Distance("a",3));
	cityMap["a"].push_back(Distance("DalyCity",3));
	cityMap["DalyCity"].push_back(Distance("a",3));
	cityMap["DalyCity"].push_back(Distance("b",19));
	cityMap["b"].push_back(Distance("DalyCity",19));
	cityMap["DalyCity"].push_back(Distance("SanFrancisco",4));
	cityMap["SanFrancisco"].push_back(Distance("DalyCity",4));
	cityMap["SanFrancisco"].push_back(Distance("SanMateo",21));
	cityMap["SanMateo"].push_back(Distance("SanFrancisco",21));
	cityMap["SanMateo"].push_back(Distance("b",4));
	cityMap["b"].push_back(Distance("SanMateo",4));
	cityMap["b"].push_back(Distance("c",7));
	cityMap["c"].push_back(Distance("b",7));
	cityMap["SanMateo"].push_back(Distance("RedwoodCity",6));
	cityMap["RedwoodCity"].push_back(Distance("SanMateo",6));
	cityMap["SanMateo"].push_back(Distance("Hayward",13));
	cityMap["Hayward"].push_back(Distance("SanMateo",13));
	cityMap["c"].push_back(Distance("RedwoodCity",5));
	cityMap["RedwoodCity"].push_back(Distance("c",5));
	cityMap["c"].push_back(Distance("Cupertino",14));
	cityMap["Cupertino"].push_back(Distance("c",14));
	cityMap["RedwoodCity"].push_back(Distance("PaloAlto",6));
	cityMap["PaloAlto"].push_back(Distance("RedwoodCity",6));
	cityMap["PaloAlto"].push_back(Distance("MountainView",6));
	cityMap["MountainView"].push_back(Distance("PaloAlto",6));
	cityMap["PaloAlto"].push_back(Distance("Fremont",9));
	cityMap["Fremont"].push_back(Distance("PaloAlto",9));
	cityMap["MountainView"].push_back(Distance("Cupertino",6));
	cityMap["Cupertino"].push_back(Distance("MountainView",6));
	cityMap["MountainView"].push_back(Distance("SanJose",8));
	cityMap["SanJose"].push_back(Distance("MountainView",8));
	cityMap["Cupertino"].push_back(Distance("SanJose",7));
	cityMap["SanJose"].push_back(Distance("Cupertino",7));
	cityMap["Fremont"].push_back(Distance("SanJose",24));
	cityMap["SanJose"].push_back(Distance("Fremont",24));
	cityMap["Dublin"].push_back(Distance("SanJose",35));
	cityMap["SanJose"].push_back(Distance("Dublin",35));
	cityMap["Fremont"].push_back(Distance("Hayward",9));
	cityMap["Hayward"].push_back(Distance("Fremont",9));
	cityMap["SanLorenzo"].push_back(Distance("Hayward",3));
	cityMap["Hayward"].push_back(Distance("SanLorenzo",3));
	cityMap["SanLorenzo"].push_back(Distance("Dublin",12));
	cityMap["Dublin"].push_back(Distance("SanLorenzo",12));
	cityMap["SanLorenzo"].push_back(Distance("Oakland",18));
	cityMap["Oakland"].push_back(Distance("SanLorenzo",18));
	cityMap["Dublin"].push_back(Distance("Oakland",31));
	cityMap["Oakland"].push_back(Distance("Dublin",31));
	cityMap["SanFrancisco"].push_back(Distance("Oakland",7));
	cityMap["Oakland"].push_back(Distance("SanFrancisco",7));
}

int Map::Dijkstra(string start,string end)
{
	map<string,int> distance;
	priority_queue<Distance, vector<Distance>, greater<Distance>> Queue;
	set<string> select;
	for(auto i:cityMap)
		distance[i.first] = INT_MAX;
	distance[start] = 0;
	Queue.push(Distance(start,distance[start]));
	Distance tmp = Distance(start,distance[start]);
	while(!Queue.empty())
	{
		tmp = Queue.top();
		Queue.pop();
		if(select.count(tmp.city))
			continue;
		select.insert(tmp.city);
		for(auto i:cityMap[tmp.city])
		{
			if(distance[i.city] > tmp.dis + i.dis)
			{
				distance[i.city] = tmp.dis + i.dis;
				Queue.push(Distance(i.city,distance[i.city]));
			}
		}
	}	
	return distance[end];
} 
