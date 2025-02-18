#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <list>
#include <cmath>

using namespace std;

class Term
{
	public:
		int coef;
		int pwr;	
		Term();
		Term(int c,int p);
};

Term::Term()
{
	coef = 0;
	pwr = 0;
}

Term::Term(int c,int p)
{
	coef = c;
	pwr = p;
}

list<Term> operator+(list<Term>& List1, list<Term>& List2)
{
	list<Term> ans;
	list<Term>::iterator iter1 = List1.begin();
	list<Term>::iterator iter2 = List2.begin();
	while((iter1 != List1.end()) || (iter2 != List2.end()))
	{
		if((*iter1).pwr == (*iter2).pwr)
		{
			int tmp = (*iter1).coef + (*iter2).coef;
			if(tmp != 0)
				ans.push_back(Term(tmp,(*iter1).pwr));
			iter1++;
			iter2++;
		}
		else if((*iter1).pwr > (*iter2).pwr)
		{
			ans.push_back(Term((*iter1).coef,(*iter1).pwr));
			iter1++;
		} 
		else
		{
			ans.push_back(Term((*iter2).coef,(*iter2).pwr));
			iter2++;
		}
	}
	return ans;
}

int main()
{
	fstream iFile;
	int coef, pwr;
	list<Term> List1, List2, ans;
	iFile.open("poly1.txt");
	while(iFile >> coef >> pwr)
		List1.push_back(Term(coef,pwr));
	iFile.close();
	iFile.open("poly2.txt");
	while(iFile >> coef >> pwr)
		List2.push_back(Term(coef,pwr));
	iFile.close();
	ans = List1 + List2;
	cout << "Poly1: ";
	if(List1.size() == 0)
		cout << "0";
	else
	{
		for(list<Term>::iterator i=List1.begin();i!=List1.end();i++)
		{
			if(i != List1.begin())
			{
				if((*i).coef > 0)
					cout << " + ";
				else if((*i).coef < 0)
					cout << " - ";
			}
			else if((*i).coef < 0)
				cout << "-";
			if((*i).pwr == 0)
				cout << abs((*i).coef);
			else if((*i).pwr == 1)
			{
				if((*i).coef == 1 || (*i).coef == -1)
					cout << "x";
				else	
					cout << abs((*i).coef) << "x";
			}
			else if((*i).coef == 1 || (*i).coef == -1)
				cout << "x^" << (*i).pwr;
			else	
				cout << abs((*i).coef) << "x^" << (*i).pwr;
		}
	}
	cout <<'\n';
	cout << "Poly2: ";
	if(List2.size() == 0)
		cout << "0";
	else
	{
		for(list<Term>::iterator i=List2.begin();i!=List2.end();i++)
		{
			if(i != List2.begin())
			{
				if((*i).coef > 0)
					cout << " + ";
				else if((*i).coef < 0)
					cout << " - ";
			}
			else if((*i).coef < 0)
				cout << "-";
			if((*i).pwr == 0)
				cout << abs((*i).coef);
			else if((*i).pwr == 1)
			{
				if((*i).coef == 1 || (*i).coef == -1)
					cout << "x";
				else	
					cout << abs((*i).coef) << "x";
			}
			else if((*i).coef == 1 || (*i).coef == -1)
				cout << "x^" << (*i).pwr;
			else	
				cout << abs((*i).coef) << "x^" << (*i).pwr;
		}
	}
	cout <<'\n';
	cout << "result: ";
	if(ans.size() == 0)
		cout << "0";
	else
	{
		for(list<Term>::iterator i=ans.begin();i!=ans.end();i++)
		{
			if(i != ans.begin())
			{
				if((*i).coef > 0)
					cout << " + ";
				else if((*i).coef < 0)
					cout << " - ";
			}
			else if((*i).coef < 0)
				cout << "-";
			if((*i).pwr == 0)
				cout << abs((*i).coef);
			else if((*i).pwr == 1)
			{
				if((*i).coef == 1 || (*i).coef == -1)
					cout << "x";
				else	
					cout << abs((*i).coef) << "x";
			}
			else if((*i).coef == 1 || (*i).coef == -1)
				cout << "x^" << (*i).pwr;
			else	
				cout << abs((*i).coef) << "x^" << (*i).pwr;
		}
	}
		
	cout <<'\n';
	return 0;
}
