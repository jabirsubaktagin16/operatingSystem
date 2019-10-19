#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,n,i,j=0,memory[1000],arr[1000],fault=0,cnt=0,flag=0,value,F;
    cout<<"Number of pages: ";
    cin>>p;
    cout<<"Number of Page References: ";
    cin>>n;
    cout<<"Reference String: ";
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<"Number of Memory Page Frame: ";
    cin>>F;
    for(i=0; i<F; i++)
        memory[i]=-1;
    j=0;
    while(cnt!=n)
    {
        for(i=0; i<F; i++)
        {
            if(memory[i] == arr[cnt])
                flag=1;
        }
        if(flag==0)
        {
            value=arr[cnt];
            memory[j]=value;
            j++;
            fault++;
        }
        if(j==F)
            j=0;
        cnt++;
        flag=0;
    }
    cout<<"Number of page fault using FIFO Page replacement Algorithm: "<<fault<<'\n';
    cout<<"Page Fault Rate: "<<(double)fault/(double)n * 100.0<<"%\n";
    return 0;
}
