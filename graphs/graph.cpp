#include<iostream>
#include<stack>

using std::stack;

struct Node{
    int vertex;
    Node* next;
};
typedef Node* List;

List cons(int v, List list)
{
    List p = new Node;
    p->vertex = v;
    p->next = list;
    return p;
}

List readGraph(int n){
    int i, j;
    List* G = new List[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {

        }
    }
    return *G;
}

//DETERMINE IF ITS INSIDE THE LIST
bool member(int v, List p)
{
    while(p!= nullptr)
    {
        if(p->vertex == v)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

void insertEdge(int i, int j, List* G, int n)
{
    //check if not loop and exist
    if(i != j && i >= 0 && i <n && j >= 0 && j < n)
    {
        if((!member(i,G[j])) && (!member(j, G[i])))
        {
            G[j] = cons(i, G[j]);
            G[i] = cons(j, G[i]);
        }
    }
}

//Depth Search First
//NOT FINISHED
bool isConnected(List*G, int n)
{
    if(n < 2)
    {
        return true;
    }
    bool* M = new bool[n];
    for(int i = 0; i < n; i++)
    {
        M[i] = false;
    }
    int v0 = 0;
    visit(G, M, v0);
    for(int i = 0; i < n; i++)
    {
        if(!M[i])
        {
            delete[] M;
            return false;
        }
    }
    delete[] M;
    return true;
}

//Taken From Lecture
void visit(List*G, bool* M, int v)
{
    M[v] = true;
    for(Node* p = G[v]; p != nullptr; p = p->next)
    {
        int u = p->vertex;
        if(!M[u])
        {
            visit(G, M, u);
        }
    }
}

bool innefficentisConnectedStack(List* G, int n) //O(n^2)
{
    if(n == 1)
    {
        return true;
    }
    bool *M = new bool[n];
    for(int i = 0; i < n; i++)
    {
        M[i] = false;
    }
    stack<int> s;
    int v0 = 0;
    M[v0] = true;
    Node* p;
    while(!s.empty())
    {
        int v = s.top();
        //look for an unmarked neighbour of v
        for(p = G[v]; p !=nullptr && M[p->vertex]; p = p->next)
        {
            if(p == nullptr)
            {
                s.pop();
            }
            else
            {
                s.push(p->vertex);
                M[p->vertex] = true;
            }//else
        }
    }
    //check if there were verices that were not visited
    for(int i = 0; i < n; i++)
    {
        if(!M[i])
        {
            delete[] M;
            return false;
        }
    }
    delete[] M;
    return true;
}

bool isConnectedStack(List* G, int n) //O(n^2)
{
    if(n == 1)
    {
        return true;
    }
    bool *M = new bool[n];
    for(int i = 0; i < n; i++)
    {
        M[i] = false;
    }
    stack<int> s;
    int v0 = 0;
    M[v0] = true;
    s.push(v0);
    int marked_n = 1;
    while(!s.empty())
    {
        if(marked_n == n)
        {
            delete[] M;
            return true;
        }
        int v = s.top();
        s.pop();
        for(Node* p = G[v]; p!=nullptr; p = p->next)
        {
            int u = p->vertex;
            if(!M[u])
            {
                M[u] = true;
                s.push(u);
                marked_n++;
            }
        }
    }
    delete[] M;
    return false;
}



int main()
{
    return 0;
}
