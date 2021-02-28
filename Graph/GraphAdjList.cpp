#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;
class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;   // circular queue implementation
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}

//****************Queue class ends here************************

//****************Dynamic ArrayList class based************************
class ArrayList
{
	int * list;
	int length ;
	int listMaxSize ;
	int listInitSize ;
public:
	ArrayList() ;
	~ArrayList() ;
	int searchItem(int item) ;
    void insertItem(int item) ;
	void removeItem(int item) ;
	void removeItemAt(int item);
	int getItem(int position) ;
	int getLength();
	bool empty();
	void printList();
} ;


ArrayList::ArrayList()
{
	listInitSize = 2 ;
	listMaxSize = listInitSize ;
	list = new int[listMaxSize] ;
	length = 0 ;
}

void ArrayList::insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;  // doubling memory when array is full
		tempList = new int[listMaxSize] ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        delete[] list ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};

	list[length] = newitem ; //store new item
	length++ ;
}

int ArrayList::searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

void ArrayList::removeItemAt(int position) //do not preserve order of items
{
	if ( position < 0 || position >= length ) return ; //nothing to remove
	list[position] = list[length-1] ;
	length-- ;
}


void ArrayList::removeItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return ; //nothing to remove
	removeItemAt(position) ;
}


int ArrayList::getItem(int position)
{
	if(position < 0 || position >= length) return NULL_VALUE ;
	return list[position] ;
}

int ArrayList::getLength()
{
	return length ;
}

bool ArrayList::empty()
{
    if(length==0)return true;
    else return false;
}

void ArrayList::printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

ArrayList::~ArrayList()
{
    if(list) delete [] list;
    list = 0 ;
}

//******************ArrayList class ends here*************************

//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	ArrayList  * adjList ;
	int *parent;
	int *color,*d;
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	bool isEdge(int u, int v);
    int getDegree(int u,bool out=false);
    void printAdjVertices(int u);
    bool hasCommonAdjacent(int u, int v);
    int getDist(int u, int v);
    void printGraph();
	void bfs(int source); //will run bfs in the graph

};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	adjList = 0 ;
	directed = dir ;
	 parent=new int[nVertices];
	 color=new int[nVertices];
	 d=new int[nVertices]; //set direction of the graph
	//define other variables to be initialized
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;
	if(adjList!=0) delete[] adjList ; //delete previous list
	adjList = new ArrayList[nVertices] ;
}

void Graph::addEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    this->nEdges++ ;
	adjList[u].insertItem(v) ;
	if(!directed) adjList[v].insertItem(u) ;
}

void Graph::removeEdge(int u, int v)
{
    this->nEdges-- ;
	adjList[u].removeItem(v) ;
	if(!directed) adjList[v].removeItem(u);
}
    //write this function


bool Graph::isEdge(int u, int v)
{

    if(directed)
    {
        if(adjList[u].searchItem(v)==NULL_VALUE)
            return false;
        else
            return true;

    }
    else
    {
        if(adjList[u].searchItem(v)==NULL_VALUE&&adjList[v].searchItem(u)==NULL_VALUE)
            return false;
        else
            return true;

    }

    //returns true if (u,v) is an edge, otherwise should return false
}

int Graph::getDegree(int u,bool out)
{
    if(u<0  || u>=nVertices )
        return 0;
    int count=0;
    if(out)
    {
     for(int i=0;i<nVertices;i++)
     {
         if(isEdge(u,i))
            count++;
     }
    }
    else
    {
        for(int i=0;i<nVertices;i++)
     {
         if(isEdge(i,u))
            count++;
     }

    }
     return count;
}

void Graph::printAdjVertices(int u)
{
     for(int i=0;i<nVertices;i++)
     {
         if(isEdge(u,i))
            cout<<i<<" ";
     }
     cout<<endl;

}

bool Graph::hasCommonAdjacent(int u, int v)
{
    for(int i=0;i<nVertices;i++)
    {
        if(isEdge(u,i)&&isEdge(v,i))
            return true;
    }
    return false;

    //returns true if vertices u and v have common adjacent vertices

}

void Graph::bfs(int s)
{
    int m;
    for(int u=0;u<nVertices;u++)
    {
      color[u]=WHITE;
      d[u]=INFINITY;
      parent[u]=NULL_VALUE;
    }
    color[s]=GRAY;
    d[s]=0;
    parent[s]=NULL_VALUE;
    Queue q;
    q.enqueue(s);
    while(!q.empty())
    {
        m=q.dequeue();
        for(int i=0;i<nVertices;i++)
        {
            if(isEdge(m,i))
            {
                if(color[i]==WHITE)
                {
                    color[i]=GRAY;
                    d[i]=d[m]+1;
                    parent[i]=m;
                    q.enqueue(i);
                }
            }
        }
        color[m]=BLACK;

    }

    //complete this function
    //initialize BFS variables for all n vertices first

}

int Graph::getDist(int u, int v)
{
    bfs(u);
    return d[v];
    //returns the shortest path distance from u to v
    //must call bfs using u as the source vertex, then use distance array to find the distance
    return INFINITY ;
}

void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<adjList[i].getLength();j++)
        {
            printf(" %d", adjList[i].getItem(j));
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    delete[] color;
   delete[] d;
   delete[] parent;
   delete adjList;

    //write your destructor here
}


//**********************Graph class ends here******************************


//******main function to test your code*************************
int main(void)
{
    int n;
    int choice;
    bool dir;
    printf("Enter your choice:\n");
    printf("1. directed graph   2. undirected graph\n");
    scanf("%d",&choice);
    if(choice == 1)dir = true;
    else if(choice == 2)dir = false;

    Graph g(dir);
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
        printf("1. Add edge. \n");
        printf("2. Remove edge. \n");
        printf("3. Get degree. \n");
        printf("4. adjacent vertices. \n");
        printf("5. hasCommonAdjacent. \n");
        printf("6. edge present check. \n");
        printf("7. BFS . \n");
        printf("8. Get distance. \n");
        printf("9. Print Graph. \n");
        printf("10. Exit. \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v;
            printf("Add edge between: \n");
            scanf("%d%d", &u, &v);
            g.addEdge(u, v);
        }
        else if(ch==2)
        {
            int u, v;
            printf("Remove the edge between: \n");
            scanf("%d%d", &u, &v);
            g.removeEdge(u, v);
        }
        else if(ch==3)
        {
            int u;
            printf("the degree of the vertex: ");
            cin >> u;
            int dg = g.getDegree(u, true);
            cout << dg;
        }
        else if(ch==4)
        {
            int u;
            cout << "the adjacent vertices  of vertex: " << endl;
            cin >> u;
            g.printAdjVertices(u);
        }
        else if(ch==5)
        {
            int u, v;
            cout << "common adjacent between two vertexs" << endl;
            cout << "the two vertexes are: ";
            scanf("%d%d", &u, &v);
            if(g.hasCommonAdjacent(u, v))
           {
               cout << "is present" << endl;
           }
           else
           {
               cout << "isn't present" << endl;
           }

        }
        else if(ch==6)
        {
            int u, v;
            printf("the edge present check between vertex: ");
            scanf("%d%d", &u, &v);
            if(g.isEdge(u, v))
            {
                cout << "is present" << endl;
            }
            else
            {
                cout << "isn't present" << endl;
            }

        }
        else if(ch==7)
        {
            int u;
            cout << "Source: ";
            cin >> u;
            g.bfs(u);
        }
        else if(ch==8)
        {
            int u, v;
            printf("the shortest path distance between two vertexes and the vertexes are: ");
            cin >> u >> v;
            int d = g.getDist(u, v);
            cout << "the distance is : " << d << endl;
        }
        else if(ch==9)
        {
           g.printGraph();
        }
        else if(ch==10)
        {
           break;
        }
        cout << endl;
    }

}
