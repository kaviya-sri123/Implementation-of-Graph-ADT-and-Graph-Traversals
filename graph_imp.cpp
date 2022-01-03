#include "graph_header.h"
void Queue::enqueue(char v)
{
    if(front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = v;
}
void Queue::dequeue()
{
    if(!queueEmpty())
    {
        char d = queue[front];
        front++;
        cout<<d<<"   ";
    }
}
bool Queue::queueEmpty()
{
    if(front == -1 || front > rear)
        return true;
    return false;
}
void Stack::push(char v)
{
    top++;
    stack[top]=v;
}
void Stack::pop()
{
    if(!stackEmpty())
    {
        char p = stack[top];
        top--;
        cout<<p<<"   ";
    }
}
bool Stack::stackEmpty()
{
    if(top==-1)
        return true;
    return false;
}
void Graph::createGraph()
{
    for(int i=0;i<n;i++)
    {
        cout<<"Enter vertex "<<i+1<<" : ";
        cin>>vertex[i];
    }
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            adj[i][j]=0;
        }
    }
    cout<<"\nEmpty graph with "<<n<<" vertices created.\n\n";
}
void Graph::addEdge(char a,char b)
{
    int x,y;
    for(int i=0;i<n;i++)
    {
        if(vertex[i]==a)
            x=i;
        if(vertex[i]==b)
            y=i;
    }
    if(adj[x][y]==1)
    {
        cout<<"\nEdge already exists.\n\n";
        return;
    }
    if(x>=n || y>=n)
    {
        cout<<"\nInvalid vertex.\n\n";
        return;
    }
    adj[x][y]=1;
    adj[y][x]=1;
    cout<<"\nEdge added.\n\n";
}
void Graph::display()
{
    cout<<"\nAdjacency Matrix\n";
    cout<<"V | "<<vertex[0];
    for(int i=1;i<n;i++)
        cout<<"   "<<vertex[i];
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<vertex[i]<<" | ";
        for(int j=0;j<n;j++)
        {
            cout<<adj[i][j]<<"   ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}
void Graph::BFS()
{
    bool visited[15];
    for(int i=0;i<15;i++)
        visited[i]=false;
    enqueue(vertex[0]);
    visited[0]=true;
    while(!queueEmpty())
    {
        char temp = queue[front];
        dequeue();
        for(int i=0;i<n;i++)
        {
            int index;
            if(vertex[i]==temp)
                index=i;
            if(adj[index][i]==1 && !visited[i])
            {
                enqueue(vertex[i]);
                visited[i]=true;
            }
        }
    }
    cout<<"\n\n";
}
void Graph::DFS()
{
    bool visited[15];
    for(int i=0;i<15;i++)
        visited[i]=false;
    push(vertex[0]);
    visited[0]=true;
    while(!stackEmpty())
    {
        char temp = stack[top];
        pop();
        int index;
        for(int i=0;i<n;i++)
        {
            if(vertex[i]==temp)
            index=i;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(adj[index][i]==1 && !visited[i])
            {
                push(vertex[i]);
                visited[i]=true;
            }
        }
    }
    cout<<"\n\n";
}