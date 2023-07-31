#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int time;
} Task;

// Function to perform proportional scheduling
void proportionalScheduling(Task *tasks, int numTasks) {
    int total_time = 0, i;
    float proportion, time_slice;

    // Calculate total time required by all tasks
    for (i=0; i<numTasks; i++) {
        total_time += tasks[i].time;
    }

    // Calculate time slice for each task based on proportional allocation
    for (i=0; i<numTasks; i++) {
        proportion = (float)tasks[i].time / total_time;
        time_slice = (float)(proportion * 100); // Assuming time slices as integer values
        printf("Task %s will run for %f%% of the time.\n", tasks[i].name, time_slice);
    }
}

void main() {
    int numTasks, i;

    printf("Enter the number of tasks: ");
    scanf("%d", &numTasks);

    // Allocate memory for tasks dynamically
    Task *tasks = (Task *)malloc(numTasks * sizeof(Task));

    if (tasks == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get task information from the user
    for (i = 0; i < numTasks; i++) {
        printf("Enter the name of task %d: ", i + 1);
        scanf("%s", tasks[i].name);
        printf("Enter the time required for task %d: ", i + 1);
        scanf("%d", &tasks[i].time);
    }

    // Perform proportional scheduling and display results
    printf("\n\nProportional Scheduling:\n");
    proportionalScheduling(tasks, numTasks);

    // Free dynamically allocated memory
    free(tasks);
}
