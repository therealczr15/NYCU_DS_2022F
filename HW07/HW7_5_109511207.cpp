#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class People
{
	public:
		string name;
		string phone;
		People();
		People(string,string);
		bool operator >(const People &p)const;
		bool operator <(const People &p)const;
		bool operator ==(const People &p)const;
};

template <class T>
class Node
{
	public:
		T data;
		Node<T>* left;
		Node<T>* right;	
		Node();
		Node(T d);
};

template <class T>
class BST
{
	public:
		Node<T>* root;
		int count;
		BST();
		bool search(T dataIn,T& dataOut);
		void insertNode(T data);
		bool deleteNode(T dataDel,T& dataOut);	
		void print(Node<People>* n);
};

template <class T>
int compare(T a,T b)
{
	if (a > b)
		return 1;
	if (a < b)
		return -1;
	return 0; 
}

int main()
{
	fstream iFile, oFile;
	iFile.open("input.txt");
	BST<People> bst;
	string name, phone;
	while(iFile >> name >> phone)
	{
		People tmpPeople(name,phone);
		bst.insertNode(tmpPeople);
	} 
	int mode = 0;
	while(1)
	{
		cin >> mode;
		if(mode == 5)
			break;
		People tmpPeople;
		People outPeople;
		switch(mode)
		{
			case 1:
				cin >> name;
				tmpPeople.name = name;
				if(bst.search(tmpPeople,outPeople))
					cout << outPeople.name << " " << outPeople.phone << "\n";
				else
					cout << "None\n";
				break;
			case 2:
				cin >> name >> phone;
				bst.insertNode(People(name,phone));
				break;
			case 3:
				cin >> name;
				tmpPeople.name = name;
				if(!bst.deleteNode(tmpPeople,outPeople))
					cout << "None\n";
				break;
			case 4:
				bst.print(bst.root);
				break;
		}
	}
	return 0;
}

template <class T>
Node<T>::Node()
{
	left = NULL;
	right = NULL;
}

template <class T>
Node<T>::Node(T d)
{
	data = d;
	left = NULL;
	right = NULL;
}

template <class T>
BST<T>::BST()
{
	root = NULL;
	count = 0;
}

template <class T>
bool BST<T>::search(T dataIn,T& dataOut)
{
	Node<T>* find = root;
	while(find)
	{
		if(compare(dataIn,find->data) == 1)
			find = find->right;
		else if(compare(dataIn,find->data) == -1)
			find = find->left;
		else
		{
			dataOut = find->data;
			return true;
		}
	}
	return false;
}

template <class T>
void BST<T>::insertNode(T data)
{
	Node<T>* tmpNode;
	tmpNode = new Node<T>(data);
	if(count == 0)
		root = tmpNode;
	else
	{
		Node<T>* find = root;
		while(find)
		{
			if(compare(data,find->data) == 1)
			{
				if(!find->right)
				{
					Node<T>* tNode;
					tNode = new Node<T>(data);
					find->right = tNode;
					break;
				}
				else
					find = find->right;
			}
			else if(compare(data,find->data) == -1)
			{
				if(!find->left)
				{
					Node<T>* tNode;
					tNode = new Node<T>(data);
					find->left = tNode;
					break;
				}
				else
					find = find->left;
			}
			else
			{
				find->data = data;
				break;
			}
		}
	}
	count++;
}

template <class T>
bool BST<T>::deleteNode(T dataDel,T& dataOut)
{
	Node<T>* find = root;
	Node<T>* lastFind = root;
	Node<T>* maxNode;
	while(find)
	{
		if(compare(dataDel,find->data) == 1)
		{
			lastFind = find;
			find = find->right;
		}
		else if(compare(dataDel,find->data) == -1)
		{
			lastFind = find;
			find = find->left;
		}
		else
		{
			dataOut = find->data;
			if(find == root)
			{
				if(!find->left)
					root = find->right;
				else if(!find->right)
					root = find->left;
				else
				{
					Node<T>* lastMaxNode = find;
					maxNode = find->left;
					while(maxNode->right)
					{
						lastMaxNode = maxNode;
						maxNode = maxNode->right;
					}
					if(lastMaxNode == find)
						maxNode->right = find->right;
					else 
					{
						if(maxNode->left)
							lastMaxNode->right = maxNode->left;
						maxNode->right = find->right;
						maxNode->left = find->left;
					}
					root = maxNode;
				}
				delete find;
			}
			else if(!find->left)
			{
				if(compare(lastFind->data,find->data) == 1)
					lastFind->left = find->right;
				else
					lastFind->right = find->right;
				delete find;
				
			}
			else if(!find->right)
			{
				if(compare(lastFind->data,find->data) == 1)
					lastFind->left = find->left;
				else
					lastFind->right = find->left;
				delete find;
			}
			else
			{
				Node<T>* lastMaxNode = find;
				maxNode = find->left;
				while(maxNode->right)
				{
					lastMaxNode = maxNode;
					maxNode = maxNode->right;
				}
				if(lastMaxNode == find)
					maxNode->right = find->right;
				else 
				{
					if(maxNode->left)
						lastMaxNode->right = maxNode->left;
					maxNode->right = find->right;
					maxNode->left = find->left;
				}
				if(compare(lastFind->data,find->data) == 1)
					lastFind->left = maxNode;
				else
					lastFind->right = maxNode;
				delete find;
			}
			count--;
			return true;
		}
	}
	return false;
}

template <class T>
void BST<T>::print(Node<People>* n)
{
	if(n)
	{
		print(n->left);
		cout << n->data.name << ' ' << n->data.phone << '\n';
		print(n->right);	
	}  
}

People::People()
{
	name = "\0";
	phone = "\0";
}

People::People(string n, string p)
{
	name = n;
	phone = p;
}

bool People::operator >(const People& p)const
{
	return (name > p.name);
}

bool People::operator <(const People& p)const
{
	return (name < p.name);
}

bool People::operator ==(const People& p)const
{
	return (name == p.name);
}
