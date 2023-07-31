#include<stdio.h>

void main(){
    int n, i, burst_time[100], priority[100], proc[100];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter the process' burst time and priority in order!\n");
    for(i=0; i<n; i++){
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        printf("Enter priority of process %d: ", i+1);
        scanf("%d", &priority[i]);
        proc[i] = i+1;
    }

    sort(burst_time, priority, proc, n);
    avgtime(proc, burst_time, n);

}

void avgtime(int proc[], int burst_time[], int n){
    int wait_time[n], tat[n], tot_wt = 0, tot_tat = 0, i;

    waitingTime(burst_time, wait_time, n);
    turnaroundtime(burst_time, wait_time, n, tat);

    printf("Process\t\tBurst Time\t\tWait Time\t\tTurnaround Time\n");
    for(i=0; i<n; i++){
        tot_wt += wait_time[i];
        tot_tat += tat[i];
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\n",proc[i], burst_time[i], wait_time[i], tat[i]);
    }

    printf("Average waiting time: %d\n", tot_wt/n);
    printf("Average turn around time: %d\n", tot_tat/n);
}

void sort(int burst_time[], int priority[], int proc[], int n){
    int i, j, min;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(priority[j]<priority[min]){
                min = j;
            }
        }
        swap(&priority[min], &priority[i]);
        swap(&burst_time[min], &burst_time[i]);
        swap(&proc[min], &proc[i]);
    }
}

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void waitingTime(int burst_time[], int wait_time[], int n){
    int i;
    wait_time[0] = 0;

    for(i=0; i<n; i++)
        wait_time[i+1] = wait_time[i] + burst_time[i];

}

void turnaroundtime(int burst_time[], int wait_time[], int n, int tat[]){
    int i;
    for(i=0; i<n; i++)
        tat[i] = burst_time[i] + wait_time[i];
}
