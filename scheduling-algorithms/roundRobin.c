#include<stdio.h>
#include<stdlib.h>
typedef struct p{
	int x;
	struct p *next;
}queue;
void sort(int arr[][7], int n){
	for(int i=0;i<n;i++){
		int t=i;
		for(int j=i+1;j<n;j++)
			if(arr[t][1]>arr[j][1])
				t=j;
		int temp=arr[t][0];arr[t][0]=arr[i][0];arr[i][0]=temp;
		temp=arr[t][1];arr[t][1]=arr[i][1];arr[i][1]=temp;
		temp=arr[t][2];arr[t][2]=arr[i][2];arr[i][2]=temp;
		temp=arr[t][5];arr[t][5]=arr[i][5];arr[i][5]=temp;
	}
}
int main(){
	int n;
	printf("Enter no. of processes :");scanf("%d",&n);
	printf("Enter the process ID, Arrival, Burst\n");
	int arr[n][7];
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
		arr[i][5]=arr[i][2];arr[i][7]=arr[i][1];

	}
	sort(arr,n);
	printf("Enter Time Quanta : ");int qu;scanf("%d",&qu);
	int x=arr[0][1],f=1;
	queue *top,*rear;
	queue *q=(queue*)malloc(sizeof(queue));
	q->next=NULL;
	q->x=0;top=rear=q;arr[0][6]=-1;
	while(top!=NULL){
		queue *t=top;
//		while(t!=NULL){
//                       printf("%d ",t->x);t=t->next;}
		int i=top->x;
//                printf(" | %d | %d ",x,arr[i][5]);
			if(arr[i][5]>qu){
				arr[i][5]-=qu;
				x+=qu;
			}
			else{
				x+=arr[i][5];
				arr[i][5]=0;
				arr[i][3]=x-arr[i][1];
				arr[i][4]=arr[i][3]-arr[i][2];
			}
			for(int j=i+1;j<n;j++){
				if(arr[j][6]<0)
					continue;
				if(arr[j][1]<=x){
					queue *q=(queue*)malloc(sizeof(queue));
					q->x=j;
					q->next=NULL;
					rear->next=q;
					rear=rear->next;
					arr[j][6]=-1;
				}
				else
					break;
			}
			if(arr[i][5]!=0){
				queue *q=(queue*)malloc(sizeof(queue));
                                q->x=i;
                                q->next=NULL;
				rear->next=q;
				rear=rear->next;
			}
			top=top->next;
//			printf("| %d\n",arr[i][5]);
	}
	printf("ID\t\tARRIVAL\t\tBURST\t\tTURNAROUND\t\tWAITING\n");
	for(int i=0;i<n;i++)
		printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4]);
	return 0;
}
