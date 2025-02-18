#include <iostream>
#include <fstream>

using namespace std;

void swap(long long &a, long long &b);
void shellSort(int *array,int size, int &count);

int main()
{
	int c = 0;
	fstream iFile;
	iFile.open("input.txt");
	int N;
	iFile >> N;
	int *array = new int [N];
	for(int i=0;i<N;i++)
		iFile >> array[i];
	shellSort(array,N,c);
	for(int i=0;i<N;i++)
		cout << array[i] << " ";
	cout << '\n' << c << '\n';
	return 0;
}

void swap(long long &a, long long &b)
{
	long long t = a;
	a = b;
	b = t;	
}

void shellSort(int *array,int size,int &count)
{
	int k = size/2;
	while(k>0)
	{
		for(int i=0;i<k;i++)
		{
			for(int j=i+k;j<size;j+=k)
			{
				int key = array[j];
				int l = j-k;
				while(key < array[l] && l >= 0)
				{
					array[l+k] = array[l];
					l -= k;
					count++;
				}
				array[l+k] = key;
			}
		}
		k /= 2;
	}
}



