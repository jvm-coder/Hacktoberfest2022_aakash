#include<iostream>
using namespace std;

int allocation[10][3],need[10][3],Max[10][3],available[10][3];
int p,current[3];
bool executed[10];

int main ()
{
	cout<<"Enter No. of processes: ";
	cin>>p;
	cout<<"\n";
	cout<<"Enter the total resources available: ";
	cin>>current[0]>>current[1]>>current[2];
	for (int i = 0; i < p; ++i)
	{
		cout<<"\n\n\t\t\tProcess P"<<i+1<<" Details\n";
		cout<<"Enter Allocation : ";
		cin>>allocation[i][0]>>allocation[i][1]>>allocation[i][2];
		cout<<"Enter Max :";
		cin>>Max[i][0]>>Max[i][1]>>Max[i][2];
		need[i][0]=Max[i][0]-allocation[i][0];
    need[i][1]=Max[i][1]-allocation[i][1];
    need[i][2]=Max[i][2]-allocation[i][2];
	}
	cout<<"\n\n\t\t\tTable for Bankers Algo\n\n";
	cout<<"Initial Resources: "<<current[0]<<" "<<current[1]<<" "<<current[2]<<"\n\n";
	cout<<"Process    Max    Allocation    Need\n";
	for (int i = 0; i < p; ++i)
	{
		cout<<"  P"<<i+1<<"    ";
		cout<<"  "<<Max[i][0]<<" "<<Max[i][1]<<" "<<Max[i][2]<<"     ";
		cout<<" "<<allocation[i][0]<<" "<<allocation[i][1]<<" "<<allocation[i][2]<<"     ";
		cout<<" "<<need[i][0]<<" "<<need[i][1]<<" "<<need[i][2];
		cout<<"\n";
	}
	cout<<"\n\n";
	

  int i,j;
  bool come;
	for (i = 0; i < p; ++i)
	{	
		for (j = 0; j < p; ++j)
		{
			while(executed[j] && j<p-1){
				j++;
			}
			if (need[j][0]<=current[0]&&need[j][1]<=current[1]&&need[j][2]<=current[2])
			{
				if (!executed[j])
				{
					executed[j]=true;
					current[0]+=allocation[j][0];current[1]+=allocation[j][1];current[2]+=allocation[j][2];
					cout<<"\nProcess P"<<j+1;
					cout<<"\nCurrent: "<<current[0]<<" "<<current[1]<<" "<<current[2]<<"\n";
					cout<<"\nProcess executed without deadlock";
          cout << "Following is the SAFE Sequence" << endl; 
          for (int i = 0; i < p - 1; i++) 
              cout << " P" << p << " ->"; 
          cout << " P" << p - 1 <<endl; 
					come=true;

					break;
				}
			}
		}
		if (!come)
		{	
			cout<<"\n\t\t\tDead lock\n\n";
			break;
		}else{
			come=false;
		}
	}

}