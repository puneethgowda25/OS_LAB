#include<stdio.h>

int main(){
    int i, j, np, nr;
    int *mark, **alloc,**request,*avail,*r,*w;


    printf ("\nEnter the no of the process: ");
    scanf("%d",&np);
    printf ("\nEnter the no of resources: ");
    scanf("%d",&nr);

    //BEGINNING OF OPTIONAL CODE
    //INSTEAD OF DYNAMICALLY ALLOCATING, STATICALLY ALLOCATE IT DURING DECLARATION

    r = (int*)malloc(nr*sizeof(int));
    avail = (int*)malloc(nr*sizeof(int));
    w = (int*)malloc(nr*sizeof(int));
    mark = (int*)malloc(np*sizeof(int));

    request = (int**)malloc(np*sizeof(int*));
    for(i=0; i<np; i++){
        request[i] = (int*)malloc(nr*sizeof(int));
    }

    alloc = (int**)malloc(np*sizeof(int*));
    for(i=0; i<np; i++){
        alloc[i] = (int*)malloc(nr*sizeof(int));
    }

    //END OF OPTIONAL CODE

    printf("\nTotal Amount of the Resources: ");
    for(i=0;i<nr; i++)
        scanf("%d", &r[i]);

    printf("\nEnter the request matrix:\n");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++)
            scanf("%d",&request[i][j]);
    }

    printf("\nEnter the allocation matrix:");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++)
            scanf("%d",&alloc[i][j]);
    }

    for(j=0;j<nr;j++){
        avail[j]=r[j];
        for(i=0;i<np;i++){
            avail[j]-=alloc[i][j];
        }
    }

    for(i=0;i<np;i++){
        int count=0;
        for(j=0;j<nr;j++){
            if(alloc[i][j]==0)
                count++;
            else
                break;
        }
        if(count==nr)
            mark[i]=1;
    }

    for(j=0;j<nr; j++)
        w[j]=avail[j];

    for(i=0;i<np; i++){
        int canbeprocessed= 0;
        if(mark[i]!=1){
            for(j=0;j<nr;j++){
                if(request[i][j]<=w[j])
                    canbeprocessed=1;
                else{
                    canbeprocessed=0;
                    break;
                }
            }
            if(canbeprocessed){
                mark[i]=1;
                for(j=0;j<nr;j++)
                    w[j]+=alloc[i][j];
            }
        }
    }

    int deadlock=0;
    for(i=0;i<np;i++)
        if(mark[i]!=1)
            deadlock=1;
    if(deadlock)
        printf("\n Deadlock detected");
    else
        printf("\n No Deadlock possible");
}
