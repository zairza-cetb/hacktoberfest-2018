#include<stdio.h>

void selectSort(int arr[][5], int m,int n, int in){
        for(int i=m;i<n;i++){
                int tem=i;
                for(int j=i+1;j<n;j++)
                        if(arr[tem][in]>arr[j][in])
                                tem=j;
                int x=arr[tem][0];arr[tem][0]=arr[i][0];arr[i][0]=x;
                x=arr[tem][1];arr[tem][1]=arr[i][1];arr[i][1]=x;
                x=arr[tem][2];arr[tem][2]=arr[i][2];arr[i][2]=x;
        }
}
int main(){
        int n;
        printf("Enter the number of Processes : ");
        scanf("%d",&n);
        int arr[n][5];
        printf("Enter the PID, Arrival Time and Burst Time\n");
        for(int i=0;i<n;i++)
                scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
        selectSort(arr,0,n,1); //sort on arrival time [1]
	int t_exec=arr[0][1],t_turn=0,t_wait=0;
        printf("PID\t\tArrival\t\tBurst\t\tTurnaround\t\tWait\n");
        for(int i=0;i<n;i++){
		int j;
		for(j=i;j<n;j++)
			if(arr[j][1]>t_exec)
				break;
		selectSort(arr,i,j,2);
                t_exec+=arr[i][2];
                t_turn+=arr[i][3]=t_exec-arr[i][1];
                t_wait+=arr[i][4]=arr[i][3]-arr[i][2];
                printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4]);
	}
	float avg_turn=t_turn*1.0/n,avg_wait=t_wait*1.0/n;
        printf("Average Turnaround Time : %f\nAverage Wait Time : %f\n",avg_turn,avg_wait);
        return 0;
}

