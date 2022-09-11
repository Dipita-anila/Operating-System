
#include <iostream>

using namespace std;

int main(){

	int i,n,time,remain,temp=0,time_quantum;

	float waiting_time=0.00,turn_around_time=0.00;

	cout<<"Enter the total number of process : ";
	cin>>n;

	cout<<endl;

	remain=n;

	int arrival_time[n];
	int burst_time[n];
	int t[n];


	cout<<"Enter the Arrival time and Burst time for all the processes"<<endl<<endl;


	for(i=0;i<n;i++)
	{
        cout<<"Arrival time for process " <<i+1<<" :  " ;
		cin>>arrival_time[i];
		cout<<"Burst time for process " <<i+1<<" :  ";
		cin>>burst_time[i];
		t[i]=burst_time[i];
		cout<<endl;
	}


	cout<<"Enter the value of time Quantum : ";
	cin>>time_quantum;

	cout<<"\n\nProcess\t\tTurnaround Time\t\tWaiting Time\n\n";
	for(time=0,i=0;remain!=0;)
	{
		if(t[i]<=time_quantum && t[i]>0)
		{
			time += t[i];

			t[i]=0;
			temp=1;
		}

		else if(t[i]>0)
		{
			t[i] -= time_quantum;

			time += time_quantum;

		}

		if(t[i]==0 && temp==1)
		{
			remain--;

			printf("Process %d\t\t%d\t\t%d\n",i+1,time-arrival_time[i],time-arrival_time[i]-burst_time[i]);
			cout<<endl;

			waiting_time += time-arrival_time[i]-burst_time[i];
			turn_around_time += time-arrival_time[i];
			temp=0;

		}

		if(i == n-1)
			i=0;
		else if(arrival_time[i+1] <= time)
			i++;
		else
			i=0;
	}

	cout<<"Average waiting time "<<waiting_time*1.00/n<<endl;
	cout<<"Average turn around time "<<turn_around_time*1.00/n<<endl;;

	return 0;
}
