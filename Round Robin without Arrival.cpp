#include<bits/stdc++.h>
using namespace std;
#define MAX_PROCESS 100
struct process
{
   int pid;
   int cpu_time;
   int total_time;
};
typedef struct process Process;
int main()
{
    Process p[MAX_PROCESS];
    int rem_time[MAX_PROCESS];
    int n,quantum,flag=1,time=0;
    cout<<"Enter the Number of Process: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        cout<<"Enter CPU Time for Process "<<p[i].pid<<": ";
        cin>>p[i].cpu_time;
        rem_time[i]=p[i].cpu_time;
        p[i].total_time=0;
    }
    cout<<"Enter Time Quantum: ";
    cin>>quantum;
    cout<<'\n';
    cout<<"***************************Gantt Chart***************************"<<'\n';
    cout<<"0";
    while(flag)
    {
        flag=0;
        for(int i=0;i<n;i++)
        {
            if(rem_time[i]>0)
            {
                if(rem_time[i]<=quantum)
                {
                    time+=rem_time[i];
                    rem_time[i]=0;
                    p[i].total_time=time;
                    cout<<" -- P"<<p[i].pid<<" -- "<<p[i].total_time;
                }
                else{
                    rem_time[i]-=quantum;
                    time+=quantum;
                    p[i].total_time=time;
                    cout<<" -- P"<<p[i].pid<<" -- "<<p[i].total_time;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(rem_time[i]!=0)
                flag=1;
        }
    }
    return 0;
}
