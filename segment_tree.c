#include<stdio.h>
#include<stdlib.h>

void tree_build(int tree[],int index[],int node,int start,int end)
{
    if(start==end)
    {
        tree[node]=index[start];
        return;
    }

    int mid=(start+end)/2;
    tree_build(tree,index,2*node,start,mid);
    tree_build(tree,index,2*node+1,mid+1,end);

    tree[node]=tree[2*node]+tree[2*node+1];
}


void update (int tree[],int node,int start,int end,int index_no,int cvalue)
{
    if(start==end)
    {
        tree[node]=cvalue;
        return;
    }
    
    else
    {
    int mid=(start+end)/2;
    //printf("mid-%d \nindex_no-%d\n",mid,index_no);
    if(index_no>=start && index_no<=mid)
    {
        update(tree,2*node,start,mid,index_no,cvalue);
    }
    else
    {
        update(tree,2*node+1,mid+1,end,index_no,cvalue);
    }
    }
    tree[node]=tree[2*node]+tree[2*node+1];
}

void display(int tree[],int n)
{
    for (int i=1;i<2*n;i++)
    {
        printf("%d--%d\n",i,tree[i]);
    }
}

int query(int tree[],int node,int start,int end,int p,int q)
{
    //printf("entered l-%d r-%d\n",l,r);
    //printf("node-%d start-%d end-%d\n",node,start,end);
    if(q<start || end<p)
    {
        //printf("invalid");
        return 0;
    }
    if(p<=start && end<=q)
    {
        return tree[node];
    }
    
    int mid=(start+end)/2;
    //printf("Reached");
    int p1=query(tree,2*node,start,mid,p,q);
    int p2=query(tree,2*node+1,mid+1,end,p,q);
    int ans=p1+p2;
    printf("the answer is %d\n",ans);
    return ans;
}

int main()
{
    int n,index_no,cvalue,p,q,option;
    printf("enter the value of n ");
    scanf("%d",&n);
    int tree[4*n-1],index[n];
    printf("Enter the values: ");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&index[i]);
    }

    tree_build(tree,index,1,0,n-1);
    display(tree,n);
    
    while(option!=3)
    {
    printf("Enter\n1-update value\n2-find sum query \n3-quit");
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
            query(tree,1,0,n-1,p,q);
        }
    }
    return 0;
}