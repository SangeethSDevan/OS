#include <stdio.h>
#define MAX 10
void getSafeSequence(int process, int resource, int max[][MAX], int allocated[][MAX], int available[MAX])
{
    int work[MAX], safeSequence[MAX], finish[MAX] = {0};
    int count = 0;
    for (int i = 0; i < resource; i++)
    {
        work[i] = available[i];
    }
    while (count < process)
    {
        int found = 0;
        for (int i = 0; i < process; i++)
        {
            if(!finish[i]){
                int canBeAlloacted = 1;
            for (int j = 0; j < resource; j++)
            {
                if (max[i][j] - allocated[i][j] > work[j])
                {
                    canBeAlloacted = 0;
                    break;
                }
            }
            if (canBeAlloacted)
            {
                for (int j = 0; j < resource; j++)
                {
                    work[j] += allocated[i][j];
                }
                safeSequence[count++] = i;
                finish[i] = 1;
                found = 1;
            }
            }
        }
        if (!found)
        {
            printf("The system is in unsafe state!\n");
            return;
        }
    }
    for(int i=0;i<process;i++){
        printf("P%d\t",safeSequence[i]);
    }
}
int main()
{
    int process, resource;
    int max[MAX][MAX], allocated[MAX][MAX], available[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &process);

    printf("Enter the number of resources: ");
    scanf("%d", &resource);

    printf("Enter the Max matrix:\n");
    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < resource; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Allocated matrix:\n");
    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < resource; j++)
        {
            scanf("%d", &allocated[i][j]);
        }
    }

    printf("Enter the Available resources:\n");
    for (int i = 0; i < resource; i++)
    {
        scanf("%d", &available[i]);
    }

    getSafeSequence(process, resource, max, allocated, available);
}