#include<stdio.h>
#include<math.h>

typedef struct process{
    int exc, tp, proc;
    float u; 
}proc;

float calcCPUUtilisation(proc *p, int n){
    float ut = 0.0;
    int i;

    for(i=0; i<n; i++){
        ut += (float)p[i].exc/(float)p[i].tp;
    }
    return ut*100;
}

void main(){
    int i, n;
    float ut, y;
    proc *p;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    p = (proc*)malloc(sizeof(proc));
    
    printf("Enter the execution time of process: ");
    for(i=0; i<n; i++){
        scanf("%d", &p[i].exc);
        p[i].proc = i+1;
    }

    printf("Enter the time periods: ");
    for(i=0; i<n; i++){
        scanf("%d", &p[i].tp);
    }

    //First we have to check whether sum of execution/timeperiod (utilization) is less than n*((pow(2, 1/n))-1)
    y = 100*n*(pow(2, 1/n)-1);

    ut = calcCPUUtilisation(p, n);
    if(ut<y){
        printf("CPU Scheduling possible!");
    }
    else{
        printf("CPU Scheduling NOT Possible!");
    }
}
