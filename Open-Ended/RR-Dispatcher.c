#include <stdio.h>
#include <stdlib.h>

struct process {
    char name[2];
    int burst_time;
};

int main() {

    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct process processes[num_processes];
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the name and burst time for process %d: ", i + 1);
        scanf("%s %d", processes[i].name, &processes[i].burst_time);
    }

    int quantum;
    printf("Enter the time slice (quantum) for each process: ");
    scanf("%d", &quantum);

    int time = 0;
    int current_process = 0;

    while (num_processes > 0) {

        struct process *process = &processes[current_process];

        if (process->burst_time > quantum) {

            process->burst_time -= quantum;

            time += quantum;

            printf("Process %s is running at time %d with burst time %d\n", process->name, time, process->burst_time);

            current_process = (current_process + 1) % num_processes;

        } else {

            time += process->burst_time;

            printf("Process %s is finished at time %d\n", process->name, time);

            for (int i = current_process; i < num_processes - 1; i++) {
                processes[i] = processes[i + 1];
            }

            num_processes--;

            if (num_processes > 0) {
                current_process = current_process % num_processes;
            }

        }

    }
    
    return 0;
}
