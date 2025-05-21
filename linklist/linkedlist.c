#include<stdio.h>
#include<stdlib.h>
struct node{
 int info;
 struct node* next;
};
struct node *create(struct node *,int);
void traverse(struct node *);
struct node *insert_begin(struct node *);
void insert_end(struct node *);
struct node *insert_any(struct node *, int);
struct node *delete_begin(struct node *);
struct node *delete_end(struct node *);
void count(struct node *);
int main(){
 struct node* head = NULL;
 int ch, n, p = 1;
 do
 {
 printf("Enter 0 for exit\nEnter 1 for create\nEnter 2 for print\nEnter 3 for insert begin");
 printf("\nEnter 4 for insert end\nEnter 5 for insert at any\nEnter 6 for count\nEnter 7 to del_end");
 printf("\nenter 8 to del_first\nEnter your choice: ");
 scanf("%d", &ch);
 switch(ch){
 case 0:
 p = 0;
 break;
 case 1:
 printf("Enter the number of node: ");
 scanf("%d", &n);
 head = create(head,n);
 break;
 case 2:
 traverse(head);
 break;
 case 3:
 head = insert_begin(head);
 break;
 case 4:
 insert_end(head);
 break;
 case 5:
 printf("Enter position and value of element :");
 scanf("%d", &p);
 insert_any(head,p);
 break;
 case 6:
 count(head);
 break;
 case 7:
 delete_end(head);
 break;
 case 8:
 head = delete_begin(head);
 break;
 default:
 printf("\n invalid choice");
 break;
 }
 } while (p > 0);
 
 return 0;
 /*
 on create 
 */
}
struct node *create(struct node *head, int num){
 struct node *newNode, *temp;
 if(head != NULL){
 printf("Already created");
 return(head);
 }
 int i, item;
 for(i = 1; i <= num; i++){
 printf("enter element %d: ",i);//getInfo
 scanf("%d", &item);// ||
 newNode = (struct node *)malloc(sizeof(struct node));//getNode
 newNode->info = item;
 newNode->next = NULL;
 if(head == NULL){
 head = newNode;
 }else{
 temp->next = newNode;
 }
 temp = newNode;
 }//
 return(head);
 
}
void traverse(struct node *head){
 struct node* loc = head;
 
 if(head == NULL){
 printf("Empty list");
 }
 while(loc != NULL){
 printf("%d -> ", loc->info);
 loc = loc->next;
 }
}
struct node* insert_begin(struct node* head){
 struct node *newNode;
 // if(head == NULL){
 // printf("Empty list");
 // return(head);
 // }
 int item;
 printf("Enter element to insert at begin: ");
 scanf("%d", &item);
 newNode = (struct node*)malloc(sizeof(struct node));
 newNode->info = item;
 newNode->next = head;
 head = newNode;
 return(head);
}
void insert_end(struct node *head){
 struct node *newNode, *loc;
 if(head == NULL){
 printf("empty list");
 //return(head);
 }">"
 int item;
 printf("\nEnter element to insert at end: ");
 scanf("%d", &item);
 newNode = (struct node *)malloc(sizeof(struct node));
 loc = head;
 while(loc->next != NULL){
 loc = loc->next;
 }
 newNode->info = item;
 newNode->next = NULL;
 loc->next = newNode;
 
 
}
struct node *insert_any(struct node *head, int pos){
 
 struct node *newNode, *temp;
 int i, item;
 if(head == NULL){
 printf("Empty list");
 return(head);
 }
 i = 1;
 printf("Enter element to insert at specified position: ");
 scanf("%d", &item);
 newNode = (struct node *)malloc(sizeof(struct node));
 newNode->info = item;
 if(pos == 1){
 newNode->next = head;
 head = newNode;
 }else{
 temp = head;
 while (i < pos-1 && temp != NULL)
 {
 temp = temp->next;
 i = i+1;
 }
 newNode->next = temp->next;
 temp->next = newNode;
 }
 return(head);
}
struct node* delete_begin(struct node* head){
 struct node* temp;
 if(head == NULL){
 printf("Empty list");
 return(head);
 }else{
 temp = head;
 head = head->next;
 free(temp);// for removing from memory
 return(head);
 }
} 
struct node *delete_end(struct node *head){
 struct node *newNode, *temp;
 if(head == NULL){
 printf("Empty list");
 return(head);
 }
 temp = head;
 while(temp->next != NULL){
 newNode = temp;
 temp = temp->next;
 }
 newNode->next = NULL;
 free(temp);
 return(head);
}
void count(struct node *head){
 struct node *current = head;
 int c = 0;
 if(head == NULL){
 printf("Empty list");
 }
 while(current != NULL){
 c++;
 current = current->next;
 }
 printf("length of list is: %d\n",c);
}