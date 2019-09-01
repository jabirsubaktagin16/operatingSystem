#include<bits/stdc++.h>
using namespace std;
#define MAXPROCESS 100
struct process
{
    int pid;
    int cpu_time;
    int wait_time;
    int turn_around;
};
typedef struct process Process;
int main()
{
    Process p[MAXPROCESS];
    int n,total_wait=0,total_turn=0;
    cout<<"Enter the Number of Process: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        cout<<"Enter CPU Time for Process "<<p[i].pid<<": ";
        cin>>p[i].cpu_time;
    }
    p[0].wait_time=0;
    p[0].turn_around=p[0].cpu_time;
    for(int i=1;i<n;i++)
    {
        p[i].wait_time=p[i-1].cpu_time+p[i-1].wait_time;
        p[i].turn_around=p[i].wait_time+p[i].cpu_time;
    }
    cout<<"Process"<<'\t'<<"CPU Time"<<'\t'<<"Waiting Time"<<'\t'<<"Turn Around Time"<<'\n';
    for(int i=0;i<n;i++)
    {
        cout<<p[i].pid<<'\t'<<p[i].cpu_time<<'\t'<<'\t'<<p[i].wait_time<<'\t'<<'\t'<<p[i].turn_around<<'\n';
        total_wait+=p[i].wait_time;
        total_turn+=p[i].turn_around;
    }
    cout<<"Average Waiting Time: "<<(float)total_wait/(float)n<<'\n';
    cout<<"Average Turn Around Time: "<<(float)total_turn/(float)n<<'\n';
    return 0;
}
