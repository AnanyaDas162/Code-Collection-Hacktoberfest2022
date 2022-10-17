#include<stdio.h>
#define MAX 100

typedef struct Job{
	char id[10];
	int deadline;
	int profit;
}Job;
void jobSequencingWithDeadline(Job jobs[],int n);

int minvalue(int x,int y)
{
	if(x<y)
	return x;
	return y;	
}
int main()
{
	int i,j;
	
	Job jobs[10]={
	{"j1", 4, 25},
	{"j2", 7, 35},
	{"j3", 4, 40},
	{"j4", 7, 30},
	{"j5", 1, 18},
	{"j6", 4, 25},
	{"j7", 6, 33},
	{"j8", 5, 43},
	{"j9", 3, 19},
	{"j10",6, 25},
	};
	
	Job temp;
	int n=10;
	
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(jobs[j+1].profit>jobs[j].profit){
				temp=jobs[j+1];
				jobs[j+1]=jobs[j];
				jobs[j]=temp;
			}
		}
	}
	
	printf("%10s %10s %10s\n","Job","Deadline","Profit");
	for(i=0;i<n;i++)
	{
		printf("%10s %10i %10i\n",jobs[i].id,jobs[i].deadline,jobs[i].profit);
	}
	jobSequencingWithDeadline(jobs,n);
	return 0;
	
}
void jobSequencingWithDeadline(Job jobs[],int n){
	int i,j,k,maxprofit;
	int timeslot[MAX];
	int filledTimeslot=0;
	
	int dmax=0;
	for(i=0;i<n;i++){
		if(jobs[i].deadline>dmax)
		{
			dmax=jobs[i].deadline;
		}
	}
	for(i=0;i<=dmax;i++){
		timeslot[i]=-1;
	}
	printf("dmax: %d\n",dmax);
	for(i=1;i<=n;i++){
		k=minvalue(dmax,jobs[i-1].deadline);
		while(k>=1)
		{
			if(timeslot[k]==-1){
				timeslot[k]=i-1;
				filledTimeslot++;
				break;
			}
			k--;
		}
		if(filledTimeslot==dmax){
			break;
		}
	}
	printf("\nRequired jobs:");
	for(i=1;i<=dmax;i++){
		printf("%s",jobs[timeslot[i]].id);
		if(i<dmax){
			printf("-->");
		}
	}
	maxprofit=0;
	for(i=1;i<=dmax;i++){
		maxprofit+=jobs[timeslot[i]].profit;
	}
	printf("Maxprofit:%d\n",maxprofit);
}
