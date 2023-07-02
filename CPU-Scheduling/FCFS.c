#include <stdio.h>

int main()
{
    int pid[10], at[10], bt[10], wt[10], tat[10], et[10];
    int temp;

    int proNum;
    printf("Enter the number of processes: ");
    scanf("%d", &proNum);

    for (int i = 0; i < proNum; i++)
    {
        pid[i] = i;
        printf("Please enter the arrival time for process %d: ", i);
        scanf("%d", &at[i]);
        printf("Please enter the burst time for process %d: ", i);
        scanf("%d", &bt[i]);
    }

    for (int i = 0; i < proNum-1; i++)
    {
        for (int j = 0; j < proNum-i-1; j++)
        {
            if (at[j] > at[j+1])
            {
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;
            }
        }
    }

    int sum = at[0];
    for (int i = 0; i < proNum; i++)
    {
        sum = sum + bt[i];
        et[i] = sum;
        tat[i] = et[i] - at[i];
        wt[i] = tat[i] - bt[i];
        if (sum < at[i+1])
        {
            int t = at[i+1] - sum;
            sum = sum + t;
        }
        
    }

    double wtTotal, wtAvg, tatTotal, tatAvg;
    wtTotal = 0;
    tatTotal = 0;
    for (int i = 0; i < proNum; i++)
    {
        wtTotal = wtTotal + wt[i];
        tatTotal = tatTotal + tat[i];
    }
    wtAvg = wtTotal/proNum;
    tatAvg = tatTotal/proNum;    

    for (int i = 0; i < proNum-1; i++)
    {
        for (int j = 0; j < proNum-i-1; j++)
        {
            if (pid[j] > pid[j+1])
            {
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;

                temp = et[j];
                et[j] = et[j+1];
                et[j+1] = temp;

                temp = tat[j];
                tat[j] = tat[j+1];
                tat[j+1] = temp;

                temp = wt[j];
                wt[j] = wt[j+1];
                wt[j+1] = temp;
            }
        }
    }

    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < proNum; i++)
    {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %f\n", wtAvg);
    printf("Average turn around time: %f\n", tatAvg);
    
    return 0;
}