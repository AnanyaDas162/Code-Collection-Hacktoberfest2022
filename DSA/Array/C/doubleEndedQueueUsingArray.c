#include<stdio.h>
#include<conio.h>
#define MAXSIZE 5
int rear=MAXSIZE/2,front=MAXSIZE/2;
static int dq[MAXSIZE];
void add_at_rear(int data);
void add_at_front(int data);
int del_from_front();
int del_from_rear();
void cannot_add_at_rear();
void cannot_add_at_front();
void cannot_del_from_front();
void cannot_del_from_rear();
void display_dequeue();
void add_at_rear(int data){
	if(rear==(MAXSIZE-1)){
		cannot_add_at_rear();
	}
	else{
		rear=rear+1;
		dq[rear]=data;
	}
}
void add_at_front(int data){
	if(front==-1){
		cannot_add_at_front();
	}
	else{
		dq[front]=data;
		front=front-1;
	}
}
int del_from_front(){
	int data;
	if(rear==front){
		cannot_del_from_front();
		return 0;
	}
	else{
		front=front+1;
		data=dq[front];
		dq[front]=0;
		return data;
	}
}
int del_from_rear(){
	int data;
	if(rear==front){
		cannot_del_from_rear();
		return 0;
	}
	else{
		data=dq[rear];
		dq[rear]=0;
		rear=rear-1;
		return data;
	}
}
void cannot_add_at_rear(){
	printf("\nSorry the dequeue is full!!Cannot add more at rear");
}
void cannot_add_at_front(){
	printf("\nSorry the dequeue is full!!Cannot add more at front");
}
void cannot_del_from_front(){
	printf("\nSorry the dequeue is empty!!Cannot delete more from front");
}
void cannot_del_from_rear(){
	printf("\nSorry the dequeue is empty!!Cannot delete more from rear");
}
void display_dequeue(){
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		printf("%3d",dq[i]);
	}
}
main(){
	int element;
	char c='1';
	while(c!='5'){
		printf("\nPresent dequeue elements are:");
		display_dequeue();
		printf("\nPress 1 for ADD AT REAR");
		printf("\nPress 2 for ADD AT FRONT");
		printf("\nPress 3 for DEL AT FRONT");
		printf("\nPress 4 for DEL AT REAR");
		printf("\nEnter your choice: ");
		fflush(stdin);
		c=getche();
		if(c=='1'){
			printf("\nEnter the element which we want to add at rear:");
			scanf("%d",&element);
			add_at_rear(element);
			
		}
		if(c=='2'){
			printf("\nEnter the element which we want to add at front:");
			scanf("%d",&element);
			add_at_front(element);
			
		}
		if(c=='3'){
			element=del_from_front();
			printf("\nThe deleted element is %d",element);
			
		}
		if(c=='4'){
			element=del_from_rear();
			printf("\nThe deleted element is %d",element);
			
		}
		if(c=='5'){
			printf("\nThank you!!");
			break;
		}
	}
}

