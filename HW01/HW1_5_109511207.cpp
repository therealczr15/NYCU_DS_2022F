#include <iostream>
#include <fstream>

using namespace std;

struct student
{
	int id;
	int avg;	
};

typedef struct node
{
	student* st;
	struct node* link; 
} NODE;

NODE* createNode(student* itemPtr)
{
	NODE* nodePtr;
	nodePtr = new NODE;
	nodePtr->st = itemPtr;
	nodePtr->link = NULL;
	return nodePtr;
}

int main()
{
	student* st;
	st = new student;
	NODE* node;
	NODE* head; 
	NODE* rear;
	fstream iFile, oFile;
	iFile.open("input.txt");
	iFile >> st->id >> st->avg;
	head = createNode(st);
	rear = head;
	st = new student;
	
	while(iFile >> st->id >> st->avg)
	{
		node = createNode(st);
		rear->link = node;
		rear = rear->link;
		st = new student;		
	}
	
	rear = head;
	int avgMax = (((student*)(head -> st))->avg);
	int idMax = (((student*)(head->st))->id);
	while((rear = rear->link)!= NULL)
	{
		if((((student*)(rear->st))->avg) > avgMax)
		{
			avgMax = (((student*)(rear->st))->avg);
			idMax = (((student*)(rear->st))->id);
		}
		else if((((student*)(rear->st))->avg) == avgMax)
		{
			if((((student*)(rear->st))->id) < idMax)
			{
				avgMax = (((student*)(rear->st))->avg);
				idMax = (((student*)(rear->st))->id);
			}
		}
	}
	cout << "Maximum ID: " << idMax << ", Maximum score: " << avgMax << '\n'; 
	
	return 0;
}
