#include <stdio.h>
#include <stdlib.h>
struct process
{
    int pid;
    int at;
    int bt;
    int t_bt;
    int prior;
    int tat;
    int wt;
    int comp;
    int in_queue;
};
typedef struct process process;

int *pop_queue(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        A[i] = A[i + 1];
    }
    return (A);
}
int *add_queue(int A[], int n, int prc)
{
    A[n] = prc;
    return (A);
}
void print_queue(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    process p_array[n];
    for (int i = 0; i < n; i++)
    {
        p_array[i].pid = i;
        printf("Please enter the arrival time for process %d: ", i);
        scanf("%d",&p_array[i].at);
        printf("Please enter the burst time for process %d: ", i);
        scanf("%d",&p_array[i].bt);
        printf("Enter process priority: ");
        scanf("%d",&p_array[i].prior);
        p_array[i].t_bt = p_array[i].bt;
        p_array[i].tat = 0;
        p_array[i].wt = 0;
        p_array[i].comp = 0;
        p_array[i].in_queue = 0;
    }

    int cpu_time = 0;
    int t_n = n;
    int *process_queue = (int *)malloc(sizeof(int) * n);
    int in_process = 0;
    int prev_process = -1;
    while (t_n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (p_array[i].at <= cpu_time && p_array[i].comp == 0 && p_array[i].in_queue == 0)
            {
                process_queue = add_queue(process_queue, in_process, i);
                in_process += 1;
                p_array[i].in_queue = 1;
            }
        }
        print_queue(process_queue, in_process);
        if (prev_process != -1)
        {
            process_queue = add_queue(process_queue, in_process, prev_process);
            in_process += 1;
        }

        if (in_process > 0)
        {
            int current_process = process_queue[0];
            if(p_array[current_process].bt>=quantum)
            {
                cpu_time += quantum;
                p_array[current_process].bt -= quantum;
            }
            else
            {
                cpu_time+=p_array[current_process].bt;
                p_array[current_process].bt=0;
            }
            if (p_array[current_process].bt == 0)
            {
                process_queue = pop_queue(process_queue, in_process);
                in_process -= 1;
                p_array[current_process].comp = 1;
                p_array[current_process].tat = cpu_time - p_array[current_process].at;
                p_array[current_process].wt = p_array[current_process].tat - p_array[current_process].t_bt;
                t_n -= 1;
                prev_process = -1;
            }
            else
            {
                prev_process = process_queue[0];
                process_queue = pop_queue(process_queue, in_process);
                in_process -= 1;
            }
        }
        else
        {
            cpu_time += 1;
        }
    }

    float t_wt = 0;
    float t_tat = 0;
    
    printf("Process ID\t  Priority\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i =0;i<n;i++)
    {
        t_wt += p_array[i].wt;
        t_tat += p_array[i].tat;
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p_array[i].pid,p_array[i].prior,p_array[i].at,p_array[i].t_bt,p_array[i].wt,p_array[i].tat);
    }

    printf("Average waiting time: %f\n",t_wt/n);
    printf("Average turn around time: %f\n",t_tat/n);
    return 0;
}