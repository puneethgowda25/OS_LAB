#include<stdio.h>
#include<conio.h>

void sort(int burst_time[], int n, int proc[]){
    int i, j, a;
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (burst_time[i] > burst_time[j]){
                a = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = a;
                a = proc[i];
                proc[i] = proc[j];
                proc[j] = a;
            }
        }
    }
}

int waitingtime(int wait_time[], int n, int burst_time[]){
    int i;
    int tot_wt = 0;
    for(i=1; i<n; i++){
        wait_time[i] = wait_time[i-1] + burst_time[i-1];
        tot_wt += wait_time[i];
    }
    return tot_wt;
}

int turnaround(int wait_time[], int burst_time[], int n, int turn_around[]){
    int i, tot_tt;
    for(i=0; i<n; i++){
        turn_around[i] = wait_time[i] + burst_time[i];
        tot_tt += turn_around[i];
    }
    return tot_tt;
}

int main(){
    int n, i, tot_wt, tot_tt;
    int proc[100], burst_time[100], wait_time[100], turn_around[100];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        proc[i] = i+1;
        printf("Enter the burst time %d: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    sort(burst_time, n, proc);

    wait_time[0] = 0;

    tot_wt = waitingtime(wait_time, n, burst_time);
    tot_tt = turnaround(wait_time, burst_time, n, turn_around);

    printf("\nProcess\tBurst Time\tWait Time\tTurnaround Time\n");
    for(i=0; i<n; i++){
        printf("%d  \t%d  \t\t%d \t\t\t%d\n",proc[i], burst_time[i], wait_time[i], burst_time[i]+wait_time[i]);
        printf("\n");
    }

    printf("Average waiting time: %d\n", tot_wt/n);
    printf("Average turnaround time: %d\n", tot_tt/n);
}
