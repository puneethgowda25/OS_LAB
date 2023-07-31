#include<stdio.h>

typedef struct process{
    int proc, at, exc, dead, completed;
}task;

float calculateCPUUtilisation(task *p, int n){
    float u = 0.0;
    int i;
    for(i=0; i<n; i++){
        u += (float)p[i].exc/(float)p[i].dead;
    }
    return u*100;
}

void main(){
    int n, i;
    task *p;
    float ut;

    printf("Enter the total numeber of tasks: ");
    scanf("%d", &n);

    p = (task*)malloc(n*sizeof(task));

    printf("Enter the arrival times: ");
    for(i=0; i<n; i++){
        scanf("%d", &p[i].at);
    }

    printf("Enter the execution times: ");
    for(i=0; i<n; i++){
        scanf("%d", &p[i].exc);
    }

    printf("Enter the deadline: ");
    for(i=0; i<n; i++){
        scanf("%d", &p[i].dead);
    }

    ut = calculateCPUUtilisation(p, n);

    printf("CPU Utilisation: %.2f\n", ut);
}
