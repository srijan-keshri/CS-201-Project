#include<stdio.h>
#include<stdlib.h>

void tree_build(int tree[],int index[],int node,int start,int end)              //function to build the segment tree through Divide and Conquer approach
{
    if(start==end)                                                              //when no further division is possible
    {
        tree[node]=index[start];                                                //assigning value to the tree
        return 0;
    }

    int mid=(start+end)/2;                                                      //find mid for dividing the index
    tree_build(tree,index,2*node,start,mid);
    tree_build(tree,index,2*node+1,mid+1,end);

    tree[node]=tree[2*node]+tree[2*node+1];                                     //assigning the parent node the sum of their child nodes
}


void update (int tree[],int node,int start,int end,int index_no,int cvalue)     //function to update the value of a particular index
{
    if(start==end)
    {
        tree[node]=cvalue;                                                      //assigning the changed value in the index
        return;
    }
    
    int mid=(start+end)/2;
    if(index_no>=start && index_no<=mid)                                        //searching on the left side of the tree
    {
        update(tree,2*node,start,mid,index_no,cvalue);                          //recursion on left side
    }
    else
    {
        update(tree,2*node+1,mid+1,end,index_no,cvalue);                        //recursion the update on right side of the tree
    }

    tree[node]=tree[2*node]+tree[2*node+1];
}

void display(int tree[],int n)                                                  //function to display the nodes and the values of the tree
{
    for (int i=1;i<2*n;i++)
    {
        printf("%d--%d\n",i,tree[i]);
    }
}

int query(int tree[],int node,int start,int end,int p,int q)                    //function to perform query on the index
{
    if(q<start || end<p)                                                        //if the range is out of the index
    {
        printf("invalid\n");
        return 0;
    }
    if(p<=start && end<=q)
    {
        return tree[node];
    }
    
    int mid=(start+end)/2;
    int p1=query(tree,2*node,start,mid,p,q);                                    //performing the query on left part 
    int p2=query(tree,2*node+1,mid+1,end,p,q);                                  //performing the query on right part 
    int ans=p1+p2;
    return ans;
}

int main()
{
    int n,index_no,cvalue,p,q,option=0;
    printf("enter the value of n ");
    scanf("%d",&n);
    int tree[4*n-1],index[n];                                                   //no. of nodes in the tree can go upto 4 times of index
    printf("Enter the values: ");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&index[i]);
    }

    tree_build(tree,index,1,0,n-1);
    display(tree,n);
    
    while(option!=3)                                                            //performing operation list
    {
    printf("Enter\n1-update value\n2-find sum query \n3-quit\n");
    scanf("%d",&option);
        if(option==1)
        {
            printf("enter index_no in which you want to change and updated value -");
            scanf("%d %d",&index_no,&cvalue);
            update(tree,1,0,n-1,index_no,cvalue);
            display(tree,n);
        }
        else if(option==2)
        {
            printf("enter the values of p and q from where to where you want to add -");
            scanf("%d %d",&p,&q);
            int k=query(tree,1,0,n-1,p,q);
            while(k==0)
            {
                printf("enter the values of p and q from where to where you want to add -");
                scanf("%d %d",&p,&q);
            }
            printf("the sum from index %d to index %d is %d",p,q,k);
        }
    }
    return 0;
}