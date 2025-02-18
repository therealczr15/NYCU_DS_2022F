#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

class Node
{
	public:
		int weight;
		char ltr;
		Node* left;
		Node* right;
		Node();	
		Node(int w,char l);
		void sorted(string s,string *sortTree);
};

bool compare(Node* a, Node* b)
{
	return (a->weight < b->weight);
}

int main()
{
	Node* tmpNode;
	vector<Node*> huffmanTree;
	tmpNode = new Node(7,'A');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(2,'B');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(2,'C');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(3,'D');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(11,'E');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(2,'F');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(2,'G');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(6,'H');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(6,'I');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(1,'J');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(1,'K');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(4,'L');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(3,'M');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(7,'N');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(9,'O');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(2,'P');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(1,'Q');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(6,'R');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(6,'S');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(8,'T');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(4,'U');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(1,'V');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(2,'W');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(1,'X');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(2,'Y');
	huffmanTree.push_back(tmpNode);
	tmpNode = new Node(1,'Z');
	huffmanTree.push_back(tmpNode);
	while(huffmanTree.size() > 1)
	{
		sort(huffmanTree.begin(),huffmanTree.end(),compare);
		Node* a;
		Node* b;
		Node* c;
		a = huffmanTree.front();
		huffmanTree.erase(huffmanTree.begin());
		b = huffmanTree.front();
		huffmanTree.erase(huffmanTree.begin());
		c = new Node;
		c->weight = a->weight + b->weight;
		c->ltr = '\0';
		c->left = a;
		c->right = b;
		huffmanTree.push_back(c);
	}
	Node* root;
	string s;
	root = huffmanTree.front();
	string sortTree[26];
	root->sorted(s,sortTree);
	for(int i=0;i<26;i++)
		cout << (char) (i+65) << " = " << sortTree[i] << '\n';
	cout << "Encode: ";
	string encode;
	cin >> encode;
	cout << "Encode result: ";
	for(int i=0;i<encode.size();i++)
		cout << sortTree[(int) encode[i] - 65];
	cout << "\n\nDecode: ";
	string decode;
	cin >> decode;
	root = huffmanTree.front();
	for(int j=0;j<decode.size();j++)
	{
		if(decode[j] == '0')
			root = root->left;
		else
			root = root->right;
		if(root->ltr != '\0')
		{
			cout << root->ltr;
			root = huffmanTree.front();
		}
	}
	cout << '\n';
	return 0;
} 

Node::Node()
{
	weight = 0;
	ltr = '\0';
	left = NULL;
	right = NULL;
}

Node::Node(int w, char l)
{
	weight = w;
	ltr = l;
	left = NULL;
	right = NULL;
}

void Node::sorted(string s,string *sortTree)
{
	if(ltr == '\0')
	{
		left->sorted(s + "0",sortTree);
		right->sorted(s + "1",sortTree);	
	}	
	else
		sortTree[(int)ltr - 65] = s;
}