#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

template <class T>
class QNode
{
    public:
        T data;
        QNode<T>* next;     
};

template <class T>
class Queue
{
    public:
        QNode<T>* front;
        QNode<T>* rear;
        int count;
        Queue();
        bool enqueue(T data);
        T dequeue();
        T queueFront();
        T queueRear();
        int queueCount();
        bool emptyQueue();
        bool fullQueue();
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Queue<int> queue;
    fstream iFile;
    iFile.open("input.txt");
    int n, t, l;
    int totalWaitTime = 0;
    iFile >> n;
    for(int i=0;i<n;i++)
    {
        iFile >> t >> l;
        if((queue.count) && queue.front->data <= t)
            queue.dequeue();
        if(queue.count)
        {
            totalWaitTime += (queue.rear->data - t);
            cout <<  queue.rear->data << ' ' << queue.queueCount() << '\n';
            queue.enqueue(queue.rear->data+l);
        }
        else
        {
            cout <<  t << " 0" << '\n';
            queue.enqueue(t+l);
        }       
    }
    cout << totalWaitTime << '\n';
    return 0;
}

template <class T>
Queue<T>::Queue()
{
    front = NULL;
    rear = NULL;
    count = 0;
}

template <class T>
bool Queue<T>::enqueue(T data)
{
    QNode<T>* tmp;
    if(!(tmp = new QNode<T>))
        return false;
    tmp->data = data;
    tmp->next = NULL;
    if(count == 0)
        front = tmp;
    else
        rear->next = tmp;
    rear = tmp;
    count++;
    return true;
}

template <class T>
T Queue<T>::dequeue()
{
    QNode<T>* delNode;
    T data;
    data = front->data;
    delNode = front;
    if(count == 1)
        rear = front = NULL;
    else
        front = front->next;
    count--;
    delete delNode;
    return data;
}

template <class T>
T Queue<T>::queueFront()
{
    return front;
}

template <class T>
T Queue<T>::queueRear()
{
    return rear;
}

template <class T>
int Queue<T>::queueCount()
{
    return count;
}

template <class T>
bool Queue<T>::emptyQueue()
{
    return (count == 0);    
}

template <class T>
bool Queue<T>::fullQueue()
{
    QNode<T>* tmp;
    tmp = new QNode<T>;
    if(tmp)
    {
        delete tmp;
        return true;
    }
    return false;
}
