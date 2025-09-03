#include <stdio.h>
#include <stdlib.h>

 typedef struct slink
 {
 	int info;
 	struct slink *next;
 }node;
 
 node *head;
 void empty()
 {
 	head=NULL;
 	return;
 }
 void Add_Node_At_beg(int ele)
 {
 	node *ptr;
 	ptr=(node *)malloc(sizeof(node));
 	ptr->info=ele;
 	if(head==NULL)
 	{
 		ptr->next=NULL;
 		head=ptr;
 		return;
	 }
	 ptr->next=head;
	 head=ptr;
	 return;
	 
 }
 void Add_Node_At_last(int ele)
 {
 	node *ptr,*ptr1;
 	ptr=(node *)malloc(sizeof(node));
 	ptr->info=ele;
 	ptr->next=NULL;
 	if(head==NULL)
 	{
 		
 		head=ptr;
 		return;
	 }
	
 ptr1=head;
 while(ptr1->next!=NULL)
 {
 	ptr1=ptr1->next;
 	
 }

 ptr1->next=ptr;
 return;
}
 void display()
 {
 	node *temp=head;
 	if(head==NULL)
 	{
 		printf("linked list is empty");
 		return;
 		
 	
	 }
	 printf("Linked list \n");
	 while(temp!=NULL)
	 {
	 	printf("%d->",temp->info);
	 	temp=temp->next;
	 }

	 return;
 }
 
void Deletion_Node_From_Last()
{
	node *ptr,*ptr1;
	if(head==NULL)
	{
		printf("\n Their is no element for deletion");
		return;
	}
	ptr1=head;
	if(ptr1->next==NULL)
	{
		head=NULL;
		printf("\n %d element is deleted",ptr1->info);
		free(ptr1);
		return;
	}
	while(ptr1->next->next!=NULL)
	{
		ptr1=ptr1->next;
	}
	ptr=ptr1->next;
	ptr1->next=NULL;
	printf("\n %d element is deleted",ptr->info);
	free(ptr);
	
	return;

}
void Deletion_Node_From_Beg()
{
	node *ptr;
	if(head==NULL)
	{
		printf("Their is no element for deletion");
		return;
		
	}
	ptr=head;
	if(ptr->next==NULL)
	{
		head=NULL;
		printf("\n%d element is deleted\n",ptr->info);
		free(ptr);
		return;
	}
	else
	{
		head=ptr->next;
	}
	printf("%d element is deleted\n",ptr->info);
	free(ptr);
		return;
}
void Count()
{
	int i=0;
	node *ptr;
	if(head==NULL)
	{
		printf("\n linked list is empty");
		return;
	}
	ptr=head;
	while(ptr!=NULL)
	{
		++i;
		ptr=ptr->next;
	}
	printf("\n Total no of nodes=%d\n",i);
	return;
}
void Delete_Particular_Node(int ele)
{
	node *ptr,*ptr1;
	if(head==NULL)
	{
		printf("\n Their is no element for deletion \n");
		return;
	}
	ptr=head;
	
	if(ptr->next==NULL)
	{
		if(ptr->info==ele)
		{
		
		head=NULL;
		printf("\n %d element is deleted",ptr->info);
		free(ptr);
		return;
	}
}
	while(ptr->next->next!=NULL)
	{
		if(ptr->next->info==ele)
		{
			ptr1=ptr->next;
			ptr->next=ptr1->next;
			printf("\n %d element is deleted",ptr1->info);
			free(ptr1);
			return;
		}
	
		
		ptr=ptr->next;
	}
	
	if(ptr->next->info==ele)
		{
			ptr1=ptr->next;
			ptr->next=ptr1->next;
			printf("\n %d element is deleted",ptr1->info);
			free(ptr1);
			return;
		}
		
	
printf("\n Element %d is not found\n",ele);
}


int main(int argc, char *argv[]) {
	
		int ch;
	int ele;
	while(1)
	{
		printf("\n 1.Add_Node_At_beg \n");
		printf("2.Add_Node_At_last \n");		 
		printf("3.Deletion_Node_From_beg \n");
		printf("4.Deletion_Node_From_last \n");
		printf("5.Deletion_Node_From_Particular_Node \n");
		printf("6.Display \n");
		printf("7.Count \n");
		printf("8.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{

			 case 1:
			 	printf("Enter element: ");
			 	scanf("%d",&ele);
			 	Add_Node_At_beg(ele);
			 	break;
			 case 2:
			 	printf("Enter element: ");
			 	scanf("%d",&ele);
			 	Add_Node_At_last(ele);
			 	break;
			 case 3:
			 	Deletion_Node_From_Beg ();
			 	break;
			case 4:
			 	Deletion_Node_From_Last();
			 	break;
			case 5:
				printf("Enter element: ");
				scanf("%d",&ele);
				Delete_Particular_Node(ele);
				break;
			case 6: 
			 	display();
			 	break;
			case 7:
			 	Count();
			 	break;
			case 8: 
			 	exit(0);
			 	break;
			 	default:
			 		printf("\n Enter correct choice\n");
	
	}
	}
	
	
	return 0;
}