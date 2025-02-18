#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

template <class T>
class Heap
{
	public:
		long long size;
		long long last;
		long long maxSize;
		T* array;
		Heap(int mS);
		bool insert(T data);
		bool dlt(T &data);
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

int main(int argc, char* argv[])
{
	clock_t runTime = clock();
	fstream iFile;
	iFile.open("input.txt");
	fstream oFile;
	oFile.open("output.txt",ios::out);
	int n;
	long long x;
	iFile >> n;
	Heap<long long> heap(n);
	for(int i=0;i<n;i++)
	{
		iFile >> x;
		heap.insert(x);
	}
	for(int i=0;i<n;i++)
	{
		long long data;
		heap.dlt(data);
		oFile << data << '\n';
	}
	runTime = clock() - runTime;
	cout << ((float)runTime/CLOCKS_PER_SEC) << "s\n";
	return 0;
} 

template <class T>
Heap<T>::Heap(int mS)
{
	size = 0;
	maxSize = mS;
	last = -1;
	array = new T[mS];
}

template <class T>
bool Heap<T>::insert(T data)
{
	last = size - 1;
	if(last == maxSize - 1)
		return false;
	size++;
	last++;
	array[last] = data;
	if(last == 0)
		return true;
	int parent = (last-1) / 2;
	while(1)
	{
		if(compare(array[last],array[parent]) < 0)
		{
			T tmp = array[last];
			array[last] = array[parent];
			array[parent] = tmp;
			last = parent;
			parent = (last-1)/2;
		}
		else
			break;
	}
	return true;
}

template <class T>
bool Heap<T>::dlt(T &data)
{
	last = size - 1;
	if(size == 0)
		return false;
	int parent = 0;
	data = array[parent];
	array[parent] = array[last];
	last--;
	size--;
	int child = parent * 2 + 1;
	while(child <= last)
	{
		if((child + 1 <= last) && compare(array[child],array[child+1]) > 0)
			child++;
		if(compare(array[child],array[parent]) < 0)
		{
			T tmp = array[child];
			array[child] = array[parent];
			array[parent] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else 
			break;
	}
	return true;
}

