/* Minimum Priority Queue Implementation */

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

// pq is the priority queue, pos stores the number of current elements in the priority queue
int pq[10000], pos = 1;


/* Heapify */
void heapify(int i)
{
    if(i>1)
    {
        int j = i/2;
        if(pq[j]>pq[i])
        {
            int temp = pq[j];
            pq[j] = pq[i];
            pq[i] = temp;

            heapify(j);
        }
    }
}

/* Iterative heapify */
void iter_heapify(int i)
{
    while(i>1 && pq[i]<pq[i/2])
    {
        int temp = pq[i];
        pq[i] = pq[i/2];
        pq[i/2] = temp;
        i = i/2;
    }
}

void heapify_down(int i)
{
    if(pos>=2*i)
    {
        int j = 2*i;

        if(pos>2*i && pq[j]>pq[j+1])
            j = j+1;

        if(pq[i]>pq[j])
        {
            int temp = pq[i];
            pq[i] = pq[j];
            pq[j] = temp;

            heapify_down(j);
        }
    }
}

void iter_heapify_down(int i)
{
    while(pos>=2*i)
    {
        int j = 2*i;
        if(pos>j && pq[j]>pq[j+1])
            j++;

        if(pq[i]<pq[j])
            break;
        else
        {
            int temp = pq[i];
            pq[i] = pq[j];
            pq[j] = temp;

            i = j;
        }
    }
}

bool pq_empty()
{
    return pos==1;
}

int extract_min()
{
    if(!pq_empty())
    {
        int minimum = pq[1];
        pq[1] = pq[pos-1];
        heapify_down(1);
        pos--;
        return minimum;
    }
    else
    {
        cout<<"Priority queue is empty. Returnung -1\n";
        return -1;
    }
}

int main()
{
    // n stores the number of elements in the priority queue.
    int n, i;
    cin>>n;

    for(i=0; i<n; i++)
    {
        cin>>pq[pos];
        heapify(pos);
        pos++;
    }
    return 0;
}
