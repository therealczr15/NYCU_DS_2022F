#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;

class Data
{
	public:
		int key;
		int qtt;
		Data();
		Data(int k,int q);
};

class Hash
{
	public:
		map<int, vector<Data>> hashTable;
		void insert(Data d);
		void search();
		void print();
		void anal();
};

int main()
{
	fstream iFile;
	iFile.open("input.txt");
	Hash h;
	int partNum, quantity;
	while(iFile >> partNum >> quantity)
		h.insert(Data(partNum,quantity));
	bool quit = false;
	while(!quit)
	{
		char select;
		cout << "a) Search\n";
		cout << "b) Print\n";
		cout << "c) Analyze\n";
		cout << "q) Quit\n";
		cout << "Please select an action: ";
		cin >> select;
		switch(select)
		{
			case 'a':
				h.search();
				break;
			case 'b':
				h.print();
				break;
			case 'c':
				h.anal();
				break;
			case 'q':
				quit = true;
				break;
		}
	}
}

Data::Data()
{
	key = 0;
	qtt = 0;
}

Data::Data(int k,int q)
{
	key = k;
	qtt = q;	
}

void Hash::insert(Data d)
{
	hashTable[(d.key % 10)].push_back(d);
}

void Hash::search()
{
	int schKey, rtnQtt;
	bool find = false;
	cout << "Please enter the part number: ";
	cin >> schKey;
	int address = schKey % 10;
	for(auto i:hashTable)
	{
		if(i.first == address)
		{
			for(vector<Data>::iterator j=i.second.begin();j!=i.second.end();j++)
			{
				if((*j).key == schKey)
				{
					rtnQtt = (*j).qtt;
					find = true;
					break;
				}
			}
		}
	}	
	if(find)
		cout << "Quantity sold: " << rtnQtt << '\n';
	else
		cout << "Not Found\n";
}

void Hash::print()
{
	cout << "Address\tPrime\tOverflow\n";
	for(int i=0;i<10;i++)
	{
		cout << i << "\t";
		int count = 0;
		if(hashTable.find(i) != hashTable.end())
		{
			//find
			for(vector<Data>::iterator j=hashTable[i].begin();j!=hashTable[i].end();j++)
			{
				cout << (*j).key << "/" << (*j).qtt;
				if(count == 0)
				{
					cout << "\t";
					count++;
				}
				else
				{
					cout << " ";
					count++;
				}
			}
		}
		cout << '\n';
	}
}

void Hash::anal()
{
	int maxSize = 0;
	int addr;
	for(auto i:hashTable)
	{
		if(i.second.size() > maxSize)
		{
			maxSize = i.second.size();
			addr = i.first;
		}
	}
	cout << "The percentage of filled prime area: " << hashTable.size() * 10 << "%\n";
	cout << "The address of the longest linked list: " << addr << '\n';
	cout << "The length of the longest linked list: " << maxSize << '\n';	
}

