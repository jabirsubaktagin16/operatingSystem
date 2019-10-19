#include<bits/stdc++.h>
using namespace std;

int arr[1000];

int main()
{
    int p,n,F;
    cout<<"Number of pages: ";
    cin>>p;
    cout<<"Number of Page References: ";
    cin>>n;
    cout<<"Reference String: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"Number of Memory Page Frame: ";
    cin>>F;
    int memory[1000];
    for(int i=0; i<F; i++)
        memory[i]=-1;
    int hit=0;
    int fault=0;
    for(int i=0; i<n; i++)
    {
        bool flag=false;
        for(int j=0; j<F; j++)
        {
            if(memory[j]==arr[i])
            {
                flag=true;
                break;
            }
        }
        if(flag)
            hit++;
        else
        {
            fault++;
            bool done=false;
            for(int j=0; j<F; j++)
            {
                if(memory[j]==-1)
                {
                    memory[j]=arr[i];
                    done=true;
                    break;
                }
            }
            if(!done)
            {
                int mi=-1;
                int mx=-1;
                for(int j=0; j<F; j++)
                {
                    int dis=n;
                    for(int k=i+1; k<n; k++)
                    {
                        if(memory[j]==arr[k])
                        {
                            dis=k;
                            break;
                        }
                    }
                    if(dis-i>mx)
                    {
                        mx=dis-i;
                        mi=j;
                    }
                }
                memory[mi]=arr[i];
            }
        }
    }
    cout << "Number of page fault using FIFO Page replacement Algorithm: " << fault << "\n";
    cout << "Page Fault Rate: " << (double)fault / (double)n *100.00 << "%\n";
    return 0;
}
