#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

struct Spot
{
	int r;
	int c;	
};

enum spotClass{Continuing, Intersection, DeadEnd, Exit};
spotClass judgeRoad(Spot,Spot,int**,int,int);

int main()
{
	fstream iFile, oFile;
	iFile.open("input.txt");
	oFile.open("answer.txt",ios::out);
	int row, col;
	iFile>>row>>col;
	int **maze = new int*[row];
	for(int i=0;i<row;i++)
		maze[i] = new int[col];
	int x, y;
	int type;
	Spot currentSpot, finalSpot, markSpot={-1,-1};
	iFile>>x>>y;
	currentSpot={x,y};
	iFile>>x>>y;
	finalSpot={x,y};
	stack<Spot> firstStack, secondStack;
	firstStack.push(currentSpot);
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			iFile>>maze[i][j];
	bool end = false;
	while(!end)
	{
		maze[currentSpot.r][currentSpot.c] = 2;
		switch(judgeRoad(currentSpot,finalSpot,maze,row,col))
		{
			case Continuing:
				if(currentSpot.r<row-1)
					if(maze[currentSpot.r+1][currentSpot.c]==0)
						firstStack.push({currentSpot.r+1,currentSpot.c});
				if(currentSpot.r>0)
					if(maze[currentSpot.r-1][currentSpot.c]==0)
						firstStack.push({currentSpot.r-1,currentSpot.c});
				if(currentSpot.c<col-1)
					if(maze[currentSpot.r][currentSpot.c+1]==0) 
						firstStack.push({currentSpot.r,currentSpot.c+1});
				if(currentSpot.c>0)
					if(maze[currentSpot.r][currentSpot.c-1]==0) 
						firstStack.push({currentSpot.r,currentSpot.c-1});	
				currentSpot = firstStack.top();
				type = 0;
				break;
			case Intersection:	
				if(currentSpot.c<col-1)	
					if(maze[currentSpot.r][currentSpot.c+1] == 0)
					{
						firstStack.push(markSpot);
						secondStack.push({currentSpot.r,currentSpot.c+1});
					}
				if(currentSpot.c>0)
					if(maze[currentSpot.r][currentSpot.c-1] == 0)
					{
						firstStack.push(markSpot);
						secondStack.push({currentSpot.r,currentSpot.c-1});
					}
				if(currentSpot.r<row-1)
					if(maze[currentSpot.r+1][currentSpot.c] == 0)
					{
						firstStack.push(markSpot);
						secondStack.push({currentSpot.r+1,currentSpot.c});
					}
				if(currentSpot.r>0)
					if(maze[currentSpot.r-1][currentSpot.c] == 0)
					{
						firstStack.push(markSpot);
						secondStack.push({currentSpot.r-1,currentSpot.c});
					}
				firstStack.pop();
				currentSpot = secondStack.top();
				secondStack.pop();
				firstStack.push(currentSpot);
				type = 1;
				break;
			case DeadEnd:
				while(currentSpot.r!=-1)
				{
					firstStack.pop();
					if(firstStack.empty())
					{
						end = true;
						break;
					} 
					currentSpot = firstStack.top();
				}
				if(!end)
				{
					firstStack.pop();
					currentSpot=secondStack.top();
					firstStack.push(currentSpot);
					secondStack.pop();
				}
				type = 2;
				break;
			case Exit:
				end = true;
				type = 3;
				break;
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			oFile << maze[i][j] << " ";
		oFile << endl;
	}
	return 0;
}

spotClass judgeRoad(Spot curSpot,Spot finSpot,int** maze,int row, int col)
{
	int path = 0;
	if((curSpot.r==finSpot.r)&&(curSpot.c==finSpot.c))
		return Exit;
	if(curSpot.r<row-1)
		if(maze[curSpot.r+1][curSpot.c]==0)
			path++;
	if(curSpot.r>0)
		if(maze[curSpot.r-1][curSpot.c]==0)
			path++;
	if(curSpot.c<col-1)
		if(maze[curSpot.r][curSpot.c+1]==0)
			path++;
	if(curSpot.c>0)
		if(maze[curSpot.r][curSpot.c-1]==0)
			path++;
	if(path == 1)
		return Continuing;
	if(path == 0)
		return DeadEnd;
	return Intersection;
}
