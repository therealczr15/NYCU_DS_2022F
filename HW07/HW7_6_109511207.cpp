#include <iostream>
#include <stack>

using namespace std;

template <class T>
class Node
{
	public:
		T data;
		Node<T>* left;
		Node<T>* right;	
		bool thread;
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
		void insertNode(T data);
		Node<T>* toThreaded(Node<T>* n);
		void printByStack();
		void printByThreaded();
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
	int num;
	BST<int> bst;
	while(1)
	{
		cin >> num;
		bst.insertNode(num);
		if(cin.get() == '\n')
			break;	
	}
	bst.toThreaded(bst.root);
	bst.printByStack();
	bst.printByThreaded();
	return 0;
}

template <class T>
Node<T>::Node()
{
	left = NULL;
	right = NULL;
	thread = false;
}

template <class T>
Node<T>::Node(T d)
{
	data = d;
	left = NULL;
	right = NULL;
	thread = false;
}

template <class T>
BST<T>::BST()
{
	root = NULL;
	count = 0;
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
					find->right = tmpNode;
					break;
				}
				else
					find = find->right;
			}
			else if(compare(data,find->data) == -1)
			{
				if(!find->left)
				{
					find->left = tmpNode;
					break;
				}
				else
					find = find->left;
			}
		}
	}
	count++;
}

template <class T>
Node<T>* BST<T>::toThreaded(Node<T>* n)
{
	if(!n)
		return NULL;
	if(!n->left && !n->right)
		return n;
	if(n->left)
	{
		Node<T>* tmpNode = toThreaded(n->left);
		tmpNode->right = n;
		tmpNode->thread = true;
	}
	if(!n->right)
		return n;
	return toThreaded(n->right);
}

template <class T>
void BST<T>::printByStack()
{
	Node<T>* r = root;
	stack<Node<T>*> Stack;
	while(r || Stack.size() > 0)
	{
		if(r)
		{
			Stack.push(r);
			r = r->left;
		}
		else
		{
			Node<T>* tmp = Stack.top();
			Stack.pop();
			cout << tmp->data << ' ';
			if(!tmp->thread)
				r = tmp->right;
			else 
				tmp = NULL;
		}
	}
	cout << '\n';
}

template <class T>
void BST<T>::printByThreaded()
{
	Node<T>* r = root;
	Node<T>* maxNode = root;
	while(r->left)
		r = r->left;
	while(maxNode->right)
		maxNode = maxNode->right;
	while(r)
	{
		cout << r->data << " ";
		if(r->data == maxNode->data)
			break;
		if(r->thread)
			r = r->right;
		else 
		{
			r = r->right;
			while(r->left)
				r = r->left;
		}
	}
	cout << '\n'; 
}

