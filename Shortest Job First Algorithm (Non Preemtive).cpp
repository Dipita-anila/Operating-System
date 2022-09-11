
#include<stdio.h>

int main()
{
    int burst_time[20],p[20],wait_time[20],turnaround_time[20],i,j,num,total=0,pos,temp;
    float average_waiting_time,average_turnaround_time;

    printf("\nEnter the Total number of process: ");
    scanf("%d",&num);

    printf("\nEnter Burst Time:\n");

    for(i=0; i<num; i++)
    {
        printf("Process%d:   ",i+1);
        scanf("%d",&burst_time[i]);
        p[i]=i+1;
    }


    for(i=0; i<num; i++)
    {
        pos=i;
        for(j=i+1; j<num; j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }

        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;

    }

    wait_time[0]=0;


    for(i=1; i<num; i++)
    {
        wait_time[i]=0;
        for(j=0; j<i; j++)
        {
           wait_time[i]+=burst_time[j];
        }

        total+=wait_time[i];
    }

    average_waiting_time=(float)total/(float)num;
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0; i<num; i++)
    {
        turnaround_time[i]=burst_time[i]+wait_time[i];
        total+=turnaround_time[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],burst_time[i],wait_time[i],turnaround_time[i]);
    }

    average_turnaround_time=(float)total/(float)num;
    printf("\n\nAverage Waiting Time = %f",average_waiting_time);
    printf("\nAverage Turnaround Time = %f\n",average_turnaround_time);

    return 0;
}
