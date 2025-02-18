#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <class T>
class QNode
{
	public:
		T data;
		QNode<T>* next;		
};

template <class T>
class Queue
{
	public:
		QNode<T>* front;
		QNode<T>* rear;
		int count;
		Queue();
		bool enqueue(T data);
		T dequeue();
		T queueFront();
		T queueRear();
		int queueCount();
		bool emptyQueue();
		bool fullQueue();
};

int main()
{
	Queue<string> queueOne;
	Queue<string> queueTwo;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int m;
		string s;
		cin >> m;
		for(int j=0;j<m;j++)
		{
			cin >> s;
			queueOne.enqueue(s);
		}
		while(queueOne.queueCount()!=1)
		{
			while(!queueOne.emptyQueue())
			{
				string a = queueOne.dequeue();
				string b;
				string c;
				if(queueOne.queueCount()>=2)
				{
					b = queueOne.front->data;
					c = queueOne.front->next->data;
				}
				if((a == "+")||(a == "-")||(a == "*")||(a == "/"))
				{
					if(!((b == "+")||(b == "-")||(b == "*")||(b == "/")) && !((c == "+")||(c == "-")||(c == "*")||(c == "/")))
					{
						b = queueOne.dequeue();
						c = queueOne.dequeue();
						int num1 = stoi(b);
						int num2 = stoi(c);
						int num3;
						if(a == "+")
							num3 = num1 + num2;
						else if(a == "-")
							num3 = num1 - num2;
						else if(a == "*")
							num3 = num1 * num2;
						else 
							num3 = num1 / num2;						
						a = to_string(num3);
					}
				}
				queueTwo.enqueue(a);
			}
			if(queueTwo.queueCount() == 1)
				break;
			while(!queueTwo.emptyQueue())
			{
				string a = queueTwo.dequeue();
				string b;
				string c;
				if(queueTwo.queueCount()>=2)
				{
					b = queueTwo.front->data;
					c = queueTwo.front->next->data;
				}
				if((a == "+")||(a == "-")||(a == "*")||(a == "/"))
				{
					if(!((b == "+")||(b == "-")||(b == "*")||(b == "/")) && !((c == "+")||(c == "-")||(c == "*")||(c == "/")))
					{
						b = queueTwo.dequeue();
						c = queueTwo.dequeue();
						int num1 = stoi(b);
						int num2 = stoi(c);
						int num3;
						if(a == "+")
							num3 = num1 + num2;
						else if(a == "-")
							num3 = num1 - num2;
						else if(a == "*")
							num3 = num1 * num2;
						else 
							num3 = num1 / num2;						
						a = to_string(num3);
					}
				}
				queueOne.enqueue(a);
			}
		}
		if(queueOne.queueCount() == 1)
			cout << queueOne.dequeue() << endl;
		else
			cout << queueTwo.dequeue() << endl;
	}
	return 0;
}

template <class T>
Queue<T>::Queue()
{
	front = NULL;
	rear = NULL;
	count = 0;
}

template <class T>
bool Queue<T>::enqueue(T data)
{
	QNode<T>* tmp;
	if(!(tmp = new QNode<T>))
		return false;
	tmp->data = data;
	tmp->next = NULL;
	if(count == 0)
		front = tmp;
	else
		rear->next = tmp;
	rear = tmp;
	count++;
	return true;
}

template <class T>
T Queue<T>::dequeue()
{
	QNode<T>* delNode;
	T data;
	data = front->data;
	delNode = front;
	if(count == 1)
		rear = front = NULL;
	else
		front = front->next;
	count--;
	delete delNode;
	return data;
}

template <class T>
T Queue<T>::queueFront()
{
	return front;
}

template <class T>
T Queue<T>::queueRear()
{
	return rear;
}

template <class T>
int Queue<T>::queueCount()
{
	return count;
}

template <class T>
bool Queue<T>::emptyQueue()
{
	return (count == 0);	
}

template <class T>
bool Queue<T>::fullQueue()
{
	QNode<T>* tmp;
	tmp = new QNode<T>;
	if(tmp)
	{
		delete tmp;
		return true;
	}
	return false;
}
