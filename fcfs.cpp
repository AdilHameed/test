#include<iostream>
using namespace std;
int main()
{
	float totalwt=0;
	float totaltat=0;
	float avgtat,avgwt=0;
	int x;
	cout<<"Enter the number of processes\n";
	cin>>x;
	int bt[x];
	int wt[x];
	int tat[x];
	int ct[x];
	int at[x];
	int pr[x];
	cout<<"Enter processes\n";
		for(int i=0;i<x;i++)
	{
		cin>>pr[i];
	}
	cout<<"Enter burst time \n";
	for(int i=0;i<x;i++)
	{
		cin>>bt[i];
	}
		cout<<"Enter arrival time \n";
	for(int i=0;i<x;i++)
	{
		cin>>at[i];
	}
	for(int i=0;i<x-1;i++)
	{
		for(int j=0;j<x-i-1;j++)
		{
			if(at[j]>at[j+1])
			{
				int temp=at[j+1];
				at[j+1]=at[j];
				at[j]=temp;
				temp=bt[j+1];
				bt[j+1]=bt[j];
				bt[j]=temp;
				temp=pr[j+1];
				pr[j+1]=pr[j];
				pr[j]=temp;
			}
		}
	}
		cout<<"\n";
		for(int i=0;i<x;i++)
		{
			cout<<"Process:"<<pr[i];
			cout<<"\n";
		}
			cout<<"Completion time\n";
//			ct[0]=bt[0];
//				cout<<ct[0];
				for(int i=0;i<x;i++)
				{
					ct[i]=ct[i-1]+bt[i];
						cout<<ct[i];
							cout<<"\n";
				}
					cout<<"Turn Around Time\n";
					for(int i=0;i<x;i++)
					{
						tat[i]=ct[i]-at[i];
							cout<<tat[i];
							totaltat=totaltat+tat[i];
								cout<<"\n";
					}
					avgtat=totaltat/x;
						
						cout<<"\n";
						cout<<"Waiting Time\n";
						for(int i=0;i<x;i++)
						{
							wt[i]=tat[i]-bt[i];
							cout<<wt[i];
							totalwt=totalwt+wt[i];
								cout<<"\n";
						}
						avgwt=totalwt/x;
						int count=at[0];
						for(int i=0;i<x;i++)
						{
							cout<<endl<<count<<"-"<<(count+bt[i])<<":pr"<<pr[i];
							ct[i]=count+bt[i];
							count=ct[i];
						}
						cout<<"\n";
						cout<<"Average Turn Around Time:";
						cout<<avgtat;
						cout<<"Average Waiting Time:";
						cout<<avgwt;
					//	cout<<"PTAT\TBT"
	
}

