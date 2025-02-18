#include <iostream>
#include <cstdlib>
#include <fstream>
#include <list>

using namespace std;

int main()
{
	fstream iFile, oFile;
	iFile.open("input.txt");
	list<int> num1, num2, ans;
	string n1, n2;
	int carry = 0, sum;
	iFile >> n1 >> n2;
	for(int i=0;n1[i]!='\0';i++)
		num1.push_front(((int)n1[i])-48);
	for(int i=0;n2[i]!='\0';i++)
		num2.push_front(((int)n2[i])-48);	
	list<int>::iterator iter1, iter2;
	iter1 = num1.begin(); 
	iter2 = num2.begin();
	while((iter1 != num1.end()) || (iter2 != num2.end()))
	{
		if(iter1 == num1.end())
		{
			sum = *iter2 + carry;
			iter2++;
		}
		else if(iter2 == num2.end())
		{
			sum = *iter1 + carry;
			iter1++;
		}
		else
		{
			sum = *iter1 + *iter2 + carry;			
			iter1++;
			iter2++;
		}
		if(sum >= 10)
		{
			carry = 1;
			sum %= 10; 
		}
		else
			carry = 0;
		ans.push_back(sum);
	}
	if(carry > 0)
		ans.push_back(carry);
	for(list<int>::reverse_iterator iterAns = ans.rbegin();iterAns != ans.rend();iterAns++)
		cout << *iterAns;
	cout << '\n';
	return 0;
}
