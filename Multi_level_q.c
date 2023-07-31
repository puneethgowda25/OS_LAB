#include<stdio.h>
#include<stdlib.h>

typedef struct process{
    int proc, bt, wt, tat;
}proc;

void main(){
    int n1, n2, i;
    proc *p1, *p2;

    printf("Enter the number of system processes: ");
    scanf("%d", &n1);
    printf("Enter the number of user processes: ");
    scanf("%d", &n2);

    p1 = (proc*)malloc(n1*sizeof(proc));
    p2 = (proc*)malloc(n2*sizeof(proc));

    printf("Enter the burst times of System Processes: ");
    for(i=0; i<n1; i++){
        scanf("%d", &p1[i].bt);
        p1[i].proc = i+1;
    }

    printf("Enter the burst times of User Processes: ");
    for(i=0; i<n2; i++){
        scanf("%d", &p2[i].bt);
        p2[i].proc = i+1;
    }

    if(n1==0){
        printf("NO SYSTEM PROCESS EXISTS!\n");
        printf("USER PROCESSES\n");
        userProcesses(p2, n2);
    }
    else{
        printf("SYSTEM PROCESSES\n");
        systemProcesses(p1, n1);
        printf("\nUSER PROCESSES\n");
        userProcesses(p2, n2);
    }
}

void systemProcesses(proc *p, int n){
    int i, tot_wt=0, tat=0, tot_tat = 0;

    for(i=0; i<n; i++){
        tat += p[i].bt;
        p[i].tat = tat;
        p[i].wt = p[i].tat - p[i].bt;
        tot_wt += p[i].wt;
        tot_tat += p[i].tat;
    }
    printSchedule(p, n, tot_tat, tot_wt);
    printf("%d %d", tot_tat, tot_wt);
}

void userProcesses(proc *p, int n){
    int i, tot_wt=0, tat=0, tot_tat = 0;

    for(i=0; i<n; i++){
        tat += p[i].bt;
        p[i].tat = tat;
        p[i].wt = p[i].tat - p[i].bt;
        tot_wt += p[i].wt;
        tot_tat += p[i].tat;
    }
    printSchedule(p, n, tot_tat, tot_wt);
    printf("%d %d", tot_tat, tot_wt);
}

void printSchedule(proc *p, int n, int tot_tat, int tot_wt){
    int i;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].proc, p[i].bt, p[i].wt, p[i].tat);
    }
    printf("Average turnaround time is: %.3f\n", (float)tot_tat/(float)n);
    printf("Average waiting time is: %.3f\n", (float)tot_wt/(float)n);
}
