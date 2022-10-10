#include<stdio.h>
#include<conio.h>
#define MAXSIZE 5
static int stack[MAXSIZE];
int top=0;
void push(int element){
	if(top==(MAXSIZE))
	{
		stack_full();
	}
	else{
		stack[top]=element;
		top=top+1;
	}
}
int pop(){
	int element;
	if(top==0)
	{
		stack_empty();
		return 0;
	}
	else{
		top=top-1;
		element=stack[top];
		stack[top]=0;
		return element;
	}
}
 stack_full(){
	printf("\nSorry!! The stack is full");
}
 stack_empty(){
	printf("\nSorry!! The stack is empty");
}
 display_stack(){
	int i;
	for(i=MAXSIZE-1;i>=0;i--)
	{
		printf("\n %d",stack[i]);
	}
}
main(){
	char c='1';
	int element;
	while(c!='3'){
		printf("\nPresent stack is:");
		display_stack();
		printf("\nPress 1 for PUSH");
		printf("\nPress 2 for POP");
		printf("\nPress 3 for exit");
		printf("\nEnter your choice:");
		fflush(stdin);
		c=getche();
		if(c=='1'){
			printf("\nEnter the element to be pushed in the stack:");
			scanf("%d",&element);
			push(element);
		}
		if(c=='2'){
			element=pop();
			printf("\nThe poped element is: %d",element);
		}
		if(c=='3'){
			printf("\nThank you!!");
			break;
		}
		
	}
}
