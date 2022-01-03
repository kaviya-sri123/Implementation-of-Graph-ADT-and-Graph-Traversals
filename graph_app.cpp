#include "graph_header.h"
int main()
{
    int ch,n;
    cout<<"Enter the number of vertices in the graph : ";
    cin>>n;
    Graph g(n);
    g.createGraph();
    do
    {
        cout<<"\t=============MENU=============\n";
    	cout<<"\t  1.Add Edge\n";
        cout<<"\t  2.Display Adjacency Matrix\n";
    	cout<<"\t  3.BFS\n";
    	cout<<"\t  4.DFS\n";
    	cout<<"\t  5.Exit\n";
    	cout<<"\t==============================\n";
    	cout<<"\nEnter your choice : ";
    	cin>>ch;
        switch(ch)
        {
            case 1:
                char src,des;
                cout<<"Enter the source vertex : ";
                cin>>src;
                cout<<"Enter the destination vertex : ";
                cin>>des;
                g.addEdge(src,des);
                break;
            case 2:
                g.display();
                break;
            case 3:
                cout<<"\nBFS Traversal : ";
                g.BFS();
                break;
            case 4:
                cout<<"\nDFS Traversal : ";
                g.DFS();
                break;
            case 5:
                break;
            default:
                cout<<"\n\nEnter a valid choice.\n";
                break;
        }
    }while(ch!=5);
}