#include<bits/stdc++.h>
using namespace std;
#define MAX_PROCESS 100
struct process
{
    int pid;
    int arr_time;
    int cpu_time;
    int wait_time;
    int turn_around;
};
typedef struct process Process;

int main()
{
    Process p[MAX_PROCESS];
    int pos,n,i,j,tmp,temp[MAX_PROCESS],total_wait=0,total_turn=0;
    cout<<"Enter The Number of Process: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        cout<<"Enter Arrival Time and CPU Time for Process "<<p[i].pid<<": ";
        cin>>p[i].arr_time>>p[i].cpu_time;
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if((p[j].arr_time+p[j].cpu_time)<(p[pos].arr_time+p[pos].cpu_time))
                pos=j;
        }
        tmp=p[i].cpu_time;
        p[i].cpu_time=p[pos].cpu_time;
        p[pos].cpu_time=tmp;

        tmp=p[i].pid;
        p[i].pid=p[pos].pid;
        p[pos].pid=tmp;

        tmp=p[i].arr_time;
        p[i].arr_time=p[pos].arr_time;
        p[pos].arr_time=tmp;
    }
    temp[0]=0;

    cout<<"Process\tArrival Time\tCPU Time\tWaiting Time\tTurn Around Time\n";
    for(i=0;i<n;i++)
    {
        p[i].wait_time=0;
        p[i].turn_around=0;
        temp[i+1]=temp[i]+p[i].cpu_time;
        p[i].wait_time=temp[i]-p[i].arr_time;
        p[i].turn_around=p[i].cpu_time+p[i].wait_time;
        total_wait+=p[i].wait_time;
        total_turn+=p[i].turn_around;
        cout<<p[i].pid<<'\t'<<p[i].arr_time<<'\t'<<'\t'<<p[i].cpu_time<<'\t'<<'\t'<<p[i].wait_time<<'\t'<<'\t'<<p[i].turn_around<<'\n';
    }
    cout<<"Average Waiting Time: "<<(float)total_wait/(float)n<<'\n';
    cout<<"Average Turn Around Time: "<<(float)total_turn/(float)n<<'\n';
    return 0;
}
