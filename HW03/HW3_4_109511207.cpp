#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

template <class T>
class Node
{
	public:
		T data;
		Node<T>* next;	
};

template <class T>
class Stack
{
	public:
		int count;
		Node<T>* top;
		Stack(){
			top = NULL;
			count = 0;
		}
		bool pushStack(T data){
			Node<T>* tmp;
			if(!(tmp = new Node<T>))
				return false;
			tmp->data = data;
			tmp->next = top;
			top = tmp;
			count++;
			return true;
		}
		T popStack(){
			Node<T>* delNode;
			T data;
			/*if(count == 0)
				return NULL;*/
			delNode = top;
			data = top->data;
			top = top->next;
			count--;
			delete delNode;
			return data;
		}
		T stackTop(){
			if(count == 0)
				return NULL;
			return top->data;
		}
		bool emptyStack(){
			return (count == 0);
		}
		bool fullStack(){
			Node<T>* tmp;
			if(tmp = new Node<T>)
			{
				delete tmp;
				return false;
			}
			return true;
		}
		int stackCount(){
			return count;
		}
};

int main()
{
	fstream iFile;
	iFile.open("input.txt");
	Stack<int> stack;
	int num;
	cout << "Prints the top 5 entries of the stack\n";
	cout << "when a negative number is entered.\n\n\n";
	while(iFile>>num)
	{
		if(num>=0)
			stack.pushStack(num);
		else
		{
			if(stack.count >= 5)
			{
				cout << "The last 5 items are : ";
				for(int i=0;i<5;i++)
					cout << setw(3) << stack.popStack();
				cout << "\n\n";
			}
			else
			{
				cout << "ERROR\n";
				break;
			}
		}	
	}
	cout << "There are " << stack.count << " numbers left in the stack.\n";
	while(stack.count != 0)
		cout << setw(3) << stack.popStack();
	cout << "\n  === End of Program ===\n";
	
	iFile.close();
	return 0;
}

