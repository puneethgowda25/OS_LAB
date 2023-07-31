#include<stdio.h>

typedef struct process{
    int bt;
    int arr;
    int wt;
    int tat;
    int proc;
}process;

void main(){
    int n, i, tot_tat = 0, tot_wt = 0;
    process p[100];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time of processes: ");
    for(i=0; i<n; i++)
        scanf("%d", &p[i].arr);
    printf("Enter burst time of processes: ");
    for(i=0; i<n; i++){
        scanf("%d", &p[i].bt);
        p[i].proc = i+1;
    }

    sort(p, n);

    tot_tat = p[0].arr;
    for(i=0; i<n; i++){
        tot_tat += p[i].bt;
        p[i].tat = tot_tat - p[i].arr;
        p[i].wt = p[i].tat - p[i].bt;
        tot_wt += p[i].wt;
    }

    printSchedule(p, n, tot_tat, tot_wt);
}

void sort(process p[], int n){
    int i, j, min_idx;
    for (i=0; i<n-1; i++)
    {
        min_idx = i;
        for (j=i+1; j<n; j++)
            if (p[j].arr < p[min_idx].arr)
                min_idx = j;
        swap(&p[min_idx], &p[i]);
    }
}

void swap(process *p1, process *p2){
    process t;
    t = *p1;
    *p1 = *p2;
    *p2 = t;
}

void printSchedule(process p[], int n, int tot_tat, int tot_wt){
    int i;

    printf("Process Number\tArrival Time\tBurst Time\tWaiting Time\tTurnAroundTime\n");
    for(i=0; i<n; i++){
        printf("\t%d        \t%d          \t%d\t          %d\t       %d\n", p[i].proc, p[i].arr, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("Avg turnaround time = %.3f\n", (float)tot_tat/(float)n);
    printf("Avg waiting time = %.3f\n", (float)tot_wt/(float)n);
}

