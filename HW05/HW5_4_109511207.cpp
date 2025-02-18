#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

template <class T>
class Node
{
	public:
		T data;
		Node<T>* nxtLink;
};

template <class T>
class List
{
	public:
		int count;
		Node<T>* pos;
		Node<T>* head;	
		Node<T>* rear;
		List();
		void push(T data);
};

class Student
{
	public:
		string name;
		double avg;	
		Student();
		Student(string,double);
};

int main()
{
	fstream iFile;
	iFile.open("input.txt");
	int n, k;
	string name;
	int num;
	double sum = 0;
	double avg;
	iFile >> n;
	List<Student> list;
	//cin.ignore();
	getline(iFile,name);
	for(int i=0;i<n;i++)
	{
		getline(iFile,name);
		list.push(Student(name,0));
	}
	for(int i=0;i<n;i++)
	{
		iFile >> k;
		sum = 0;
		for(int j=0;j<k;j++)
		{
			iFile >> num;
			sum += num;
		}
		avg = sum/k;
		list.pos->data.avg = avg;
		list.pos = list.pos->nxtLink; 
	}
	list.pos = list.head;
	cout << fixed << setprecision(2);
	for(int i=0;i<n;i++)
	{
		cout << list.pos->data.name << " " << list.pos->data.avg << '\n';
		list.pos = list.pos->nxtLink;
	}
	return 0;
} 

template <class T>
List<T>::List()
{
	count = 0;
	head = NULL;
	rear = NULL;
	pos = head;
}

template <class T>
void List<T>::push(T data)
{
	Node<T>* tmp;
	tmp = new Node<T>;
	tmp->data = data;
	tmp->nxtLink = NULL;
	if(count == 0)
		head = tmp;
	else
		rear->nxtLink = tmp;
	rear = tmp;
	pos = head;
	count++;
}

Student::Student()
{
	name = '\0';
	avg = 0;
}

Student::Student(string n,double a)
{
	name = n;
	avg = a;
}
