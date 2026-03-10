// SJF Scheduling (Non Preemptive)

#include <stdio.h>

int main()
{
    int n, i, j, pos;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter AT & BT for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    for(i = 0; i < n-1; i++)
    {
        pos = i;

        for(j = i+1; j < n; j++)
        {
            if(bt[j] < bt[pos])
            {
                pos = j;
            }
        }

        int temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;
    }

    // Completion Time
    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++)
    {
        ct[i] = ct[i-1] + bt[i];
    }

    float avg_tat = 0, avg_wt = 0;

    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", avg_tat/n);
    printf("\nAverage WT = %.2f", avg_wt/n);

    return 0;
}
