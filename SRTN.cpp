#include<bits/stdc++.h>
using namespace std;
#define MAX_PROCESS 100

int n,i,j,k,small,minimum,total_cpu=0,total_wait=0,total_turn=0;

struct process
{
    int pid;
    int arr_time;
    int cpu_time;
    int wait_time;
    int turn_around;
    int real_burst;
};
typedef struct process Process;
int main()
{
    Process p[MAX_PROCESS];
    cout<<"Enter Number of Process: ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        p[i].pid=i;
        cout<<"Enter Arrival Time and CPU Time for Process "<<p[i].pid<<": ";
        cin>>p[i].arr_time>>p[i].cpu_time;
        total_cpu+=p[i].cpu_time;
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(p[i].arr_time>p[j].arr_time)
            {
                swap(p[i].arr_time,p[j].arr_time);
                swap(p[i].cpu_time,p[j].cpu_time);
                swap(p[i].pid,p[j].pid);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        p[i].real_burst=p[i].cpu_time;
    }
    int t=0;
    i=1;
    while(t<=total_cpu)
    {
        if(p[i].arr_time<=t && i<=n)
        {
            k=i;
            i++;
        }
        minimum=INT_MAX;
        for(j=1;j<=k;j++)
        {
            if(p[j].cpu_time<minimum && p[j].cpu_time!=0)
            {
                minimum=p[j].cpu_time;
                small=j;
            }
        }
        p[small].cpu_time--;
        t++;
        if(p[small].cpu_time==0)
        {
            p[small].wait_time=t-p[small].arr_time-p[small].real_burst;
            p[small].turn_around=p[small].real_burst+p[small].wait_time;
        }
    }
    cout<<"Process\tWaitingTime\tTurn Around Time\n";
    for(i=1;i<=n;i++)
    {
        cout<<p[i].pid<<'\t'<<p[i].wait_time<<'\t'<<'\t'<<p[i].turn_around<<'\n';
        total_wait+=p[i].wait_time;
        total_turn+=p[i].turn_around;
    }
    cout<<"Average Waiting Time: "<<(float)total_wait/(float)n<<'\n';
    cout<<"Average Turn Around Time: "<<(float)total_turn/(float)n<<'\n';
    return 0;
}
