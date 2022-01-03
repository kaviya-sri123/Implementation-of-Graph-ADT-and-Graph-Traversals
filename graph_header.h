#include <iostream>
using namespace std;
class Queue
{
    public:
        char queue[15];
        int front,rear;
        Queue()
        {
            front=rear=-1;
        }
        void enqueue(char v);
        void dequeue();
        bool queueEmpty();
};
class Stack
{
    public:
        char stack[15];
        int top;
        Stack()
        {
            top=-1;
        }
        void push(char v);
        void pop();
        bool stackEmpty();
};
class Graph : public Queue, public Stack
{
    int n;
    char vertex[15];
    int adj[15][15];
    public:
        Graph(int n)
        {
            this->n = n;
        }
        void createGraph();
        void addEdge(char a,char b);
        void display();
        void BFS();
        void DFS();
};