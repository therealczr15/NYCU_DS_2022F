#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

class stkNode
{
	public:
		int code;
		string name;
		double amount;
		int held;
		double price;
		double gain;
		stkNode* nxtCode;
		stkNode* preCode;
		stkNode* nxtGain;
		stkNode* preGain;
		stkNode();
		stkNode(int,string,double,int,double,double);
};

class dbList
{
	public:
		int count;
		stkNode* headCode;
		stkNode* rearCode;
		stkNode* headGain;
		stkNode* rearGain;
		stkNode* pPre;
		stkNode* pLoc;
		dbList();
		void push(stkNode);
		bool searchCode(int);
		bool searchGain(double);
		void print(fstream& oFile);
		void rprint(fstream& oFile);
};

int main()
{
	fstream iFile, oFile;
	iFile.open("input.txt");
	oFile.open("answer.txt",ios::out);
	int sort;
	int num;
	int code;
	string name;
	double amount;
	int held;
	double price;
	iFile >> sort >> num;
	dbList list;
	for(int i=0;i<num;i++)
	{	
		iFile >> code >> name >> amount >> held >> price;
		list.push(stkNode(code,name,amount,held,price,double (held*price-amount)));
	}
	if(sort == 1)
		list.print(oFile);
	else if(sort == 2)
		list.rprint(oFile);
	return 0;
} 

stkNode::stkNode()
{
	code = 0;
	name = "\0";
	amount = 0;
	held = 0;
	price = 0;
	gain = 0;
	nxtCode = NULL;
	preCode = NULL;
	nxtGain = NULL;
	preGain = NULL;	
}

stkNode::stkNode(int c,string n,double a,int h,double p,double g)
{
	code = c;
	name = n;
	amount = a;
	held = h;
	price = p;
	gain = g;
	nxtCode = NULL;
	preCode = NULL;
	nxtGain = NULL;
	preGain = NULL;	
}

dbList::dbList()
{
	count = 0;
	headCode = NULL;
	rearCode = NULL;
	headGain = NULL;
	rearGain = NULL;
	pPre = NULL;
	pLoc = NULL;
}

void dbList::push(stkNode node)
{
	stkNode* tmpNode;
	tmpNode = new stkNode;
	tmpNode->code = node.code;
	tmpNode->name = node.name;
	tmpNode->amount = node.amount;
	tmpNode->held = node.held;
	tmpNode->price = node.price;
	tmpNode->gain = node.gain;
	tmpNode->nxtCode = NULL;
	tmpNode->preCode = NULL;
	tmpNode->nxtGain = NULL;
	tmpNode->preGain = NULL;
	searchCode(node.code);
	if(pPre == NULL)
	{
		tmpNode->nxtCode = headCode;
		headCode = tmpNode;
		if(count == 0)
			rearCode = tmpNode;
		else
			tmpNode->nxtCode->preCode = tmpNode;
	}
	else
	{
		tmpNode->nxtCode = pPre->nxtCode;
		tmpNode->preCode = pPre;
		pPre->nxtCode = tmpNode;
		if(pLoc != NULL)
			pLoc->preCode = tmpNode;
		else
			rearCode = tmpNode;
	}
	tmpNode = new stkNode;
	tmpNode->code = node.code;
	tmpNode->name = node.name;
	tmpNode->amount = node.amount;
	tmpNode->held = node.held;
	tmpNode->price = node.price;
	tmpNode->gain = node.gain;
	tmpNode->nxtCode = NULL;
	tmpNode->preCode = NULL;
	tmpNode->nxtGain = NULL;
	tmpNode->preGain = NULL;
	searchGain(node.gain);
	if(pPre == NULL)
	{
		tmpNode->nxtGain = headGain;
		headGain = tmpNode;
		if(count == 0)
			rearGain = tmpNode;
		else
			tmpNode->nxtGain->preGain = tmpNode;
	}
	else
	{
		tmpNode->nxtGain = pPre->nxtGain;
		tmpNode->preGain = pPre;
		pPre->nxtGain = tmpNode;
		if(pLoc != NULL)
			pLoc->preGain = tmpNode;
		else
			rearGain = tmpNode;
	}
	count++;
}

bool dbList::searchCode(int c)
{
	pPre = NULL;
	pLoc = headCode;
	if(count == 0)
		return false;
	while(c > pLoc->code)
	{
		pPre = pLoc;
		pLoc = pLoc->nxtCode;
		if(pLoc == NULL)
			break;
	}
	if(pPre != NULL)
	{
		if(c == pPre->code)
			return true;
	}
	return false;
}

bool dbList::searchGain(double g)
{
	pPre = NULL;
	pLoc = headGain;
	if(count == 0)
		return false;
	while(g > pLoc->gain)
	{
		pPre = pLoc;
		pLoc = pLoc->nxtGain;
		if(pLoc == NULL)
			break;
	}
	if(pPre != NULL)
	{
		if(g == pPre->gain)
			return true;
	}
	return false;
}

void dbList::print(fstream& oFile)
{
	stkNode* tmpNode;
	tmpNode = new stkNode;
	tmpNode = headCode;
	while(tmpNode != NULL)
	{
		oFile << tmpNode->code << " " << tmpNode->name << " " << tmpNode->amount << " " << tmpNode->held << " " << tmpNode->price << '\n';
		tmpNode = tmpNode->nxtCode;
	}
	tmpNode = headGain;
	oFile << '\n';
	while(tmpNode != NULL)
	{
		oFile << tmpNode->code << " " << tmpNode->name << " " << tmpNode->amount << " " << tmpNode->held << " " << tmpNode->price << '\n';
		tmpNode = tmpNode->nxtGain;
	}
}

void dbList::rprint(fstream& oFile)
{
	stkNode* tmpNode;
	tmpNode = new stkNode;
	tmpNode = rearCode;
	while(tmpNode != NULL)
	{
		oFile << tmpNode->code << " " << tmpNode->name << " " << tmpNode->amount << " " << tmpNode->held << " " << tmpNode->price << '\n';
		tmpNode = tmpNode->preCode;
	}
	tmpNode = rearGain;
	oFile << '\n';
	while(tmpNode != NULL)
	{
		oFile << tmpNode->code << " " << tmpNode->name << " " << tmpNode->amount << " " << tmpNode->held << " " << tmpNode->price << '\n';
		tmpNode = tmpNode->preGain;
	}
}