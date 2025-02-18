#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void swap(long long &a, long long &b);
void quickSort(long long *array,int left,int right);

int main()
{
	clock_t runTime = clock();
	int N;
	fstream iFile;
	iFile.open("input.txt");
	fstream oFile;
	oFile.open("output.txt",ios::out);
	iFile >> N;
	long long *array = new long long[N];
	for(int i=0;i<N;i++)
		iFile >> array[i];
	quickSort(array,0,N-1);
	for(int i=0;i<N;i++)
		oFile << array[i] << '\n'; 
	delete [] array;
	runTime = clock() - runTime;
	cout << ((float)runTime/CLOCKS_PER_SEC) << "s\n";
	return 0;
}

void swap(long long &a, long long &b)
{
	long long t = a;
	a = b;
	b = t;	
}

void quickSort(long long *array,int left,int right)
{
	if(left >= right)
		return;
	long long pivot = array[right];
	int j = left;
	for(int i=left;i<right;i++)
		if(array[i] < pivot)
			swap(array[i],array[j++]);
	swap(array[j],array[right]);
	quickSort(array,left,j-1);
	quickSort(array,j+1,right);
}



