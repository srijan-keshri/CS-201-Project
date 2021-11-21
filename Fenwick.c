#include<stdio.h>
#include<stdlib.h>


int getSum(int BITree[],int position){
    int sum=0;
    //changing it to 1 based indexing
    position ++;

    while(position>0){
        sum+=BITree[position];
        position=position-(position&(-position));
    }
    //printf("sum is %d ",sum);
    return sum;
}
void update(int BITree[],int n,int position,int val){
    //changing it to 1 based indexing
    ++position;
    while(position<=n){
        BITree[position]+=val;
        position+=(position&(-position));
    
    }
}
void display(int BITree[],int n){
    printf("Printing the values\n");
    for(int i=1;i<=n;i++){
        printf("%d " ,BITree[i]);

    }
    printf("\n");
}
int sumInRange(int BITree[],int l,int r){
    return getSum(BITree,r)-getSum(BITree,l-1);
}
int main()
{
    int n;
    printf("enter the value of n ");
    scanf("%d",&n);
    int BITree[n+1];
    int array[n];
    for (int i=1; i<=n; i++){
        BITree[i] = 0;
    }
    printf("Enter the values you want to add in the array");
        

    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Values in the array are");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    for(int i=0;i<n;i++){
        update(BITree,n,i,array[i]);
    }
    printf("\n");
    int option=0;
    int p,q;
   int index_no;
    int cvalue;
    while(option<4)
    {
    printf("Enter\n1-update value\n2-find sum query \n3-to print the tree\n4-to quit\n");
    scanf("%d",&option);
        if(option==1)
        {
            printf("enter index_no in which you want to change and updated value -");
            scanf("%d %d",&index_no,&cvalue);
           update(BITree, n, index_no,cvalue-array[index_no]);
           array[index_no]=cvalue;
            printf("The value is updated\n");
            printf("The new array is \n");
            for(int i=0;i<n;i++){
                printf("%d ",array[i]);
            }
            printf("\n");
        }
        else if(option==2)
        {
            printf("enter the range of p and q for which you want sum");
            scanf("%d %d",&p,&q);
            int sum=sumInRange(BITree,p,q);
            printf("The sum in range %d to %d is %d \n",p,q,sum);
        }
        else if(option==3){
            display(BITree,n);
        }
        
    }
    return 0;
}