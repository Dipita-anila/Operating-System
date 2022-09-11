
#include <iostream>
using namespace std;


int main()
{
    int n = 3;
    int arrivalTime[n] = {4,0,2};
    int burstTime[n] = {5,7,9};
    int priority[n + 1] = {0,2,1};
    int temp[n];

    int waitingTime[n], turnaroundTime[n], completionTime[n];
    int i, j, smallest, count = 0, time;
    double avg = 0, tt = 0, end;

    for (i = 0; i < n; i++)
        temp[i] = burstTime[i];

    priority[n] = 10000;

    for (time = 0; count != n; time++)
    {
        smallest = n;
        for (i = 0; i < n; i++)
        {
            if (arrivalTime[i] <= time && priority[i] < priority[smallest] && burstTime[i] > 0)
                smallest = i;
        }
        burstTime[smallest]--;
        if (burstTime[smallest] == 0)
        {
            count++;
            end = time + 1;
            completionTime[smallest] = end;
            waitingTime[smallest] = end - arrivalTime[smallest] - temp[smallest];
            turnaroundTime[smallest] = end - arrivalTime[smallest];
        }
    }

   cout << "Process"<< "\t  "<< "burst-time"<< "\t "<< "arrival-time"<< "\t "<< "waiting-time"<< "\t"<< "turnaround-time"<< "\t "<< "completion-time"<< "\t"<< "Priority" << endl;

    for (i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << "\t\t" << temp[i] << "\t\t" << arrivalTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\t\t" << completionTime[i] << "\t\t" << priority[i] << endl;
        avg = avg + waitingTime[i];
        tt = tt + turnaroundTime[i];
    }

    cout << "\n\nAverage waiting time time = " << avg / n << endl;
    cout << "Average turnaround time time = " << tt / n << endl;
}

