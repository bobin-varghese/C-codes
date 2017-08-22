#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;
struct node{
    int data;
    int key;
    struct node* next;
};
struct list{
  struct node *nhead;
  list(){
    nhead=NULL;
  }
};
struct node *head=NULL;
struct node *current=NULL;

void printnode(){
    struct node *ptr=head;
    printf("[ ");
    while(ptr!=NULL){
        printf("%d->%d->",ptr->key,ptr->data);
        ptr=ptr->next;
    }
    printf("]");
}
struct node insertFirst(int key,int data){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->key=key;
    n->data=data;
    n->next=head;
    head=n;
    return *head;
}
struct node* deleteFirst(){
    struct node *temp=head;
    head=head->next;
    printf("The first node is deleted\n");
    return temp;
}
bool isEmpty(){
    return head==NULL;
}
int lenght(){
    int len;
    current=head;
    while(current!=NULL){
        current=current->next;
        len++;
    }
    return len;
}
struct node* find(int key){
    int flag=0;
    current=head;
    if(head==NULL){
        printf("Empty List\n");
        return NULL;
    }
    while(current!=NULL){
        if(current->key==key)
            return current;
        else
            current=current->next;
    }
    return NULL;
}
void deleten(int key){
    current=head;
    struct node* prev=NULL;
    while(current!=NULL){
        if(current->next->key==key){
            prev=current;
            break;
        }
        else
            current=current->next;
    }
    prev->next=current->next;
}

int main(){
  int n,ch,key,linum,data;
  cout<<"Enter the number of list to create\n";
  cin>>n;
  struct list* LinkList=(struct list*)malloc(n*sizeof(struct list));
  while(1){
    cout<<"Enter\n1.Insert First 2.Print the list 3. Delete First Element 4.Find an node 5.Delete an node 6.Exit\n";
    cin>>ch;
    switch(ch){
      case 1:cout<<"Enter the list number the node key and node data to insert:\n";
             cin>>linum>>key>>data;
             LinkList[linum]->nhead=insertFirst(key,data);
            break;
     case 2:cout<<"Enter the list number to display:\n";
            cin>>linum;
            head=LinkList[linum]->nhead;
            printnode();
            break;
      case 3:cout<<"Enter the list number from which the first node is to be delete:\n";
            cin>>linum;
            head=LinkList[linum]->nhead;
            struct node *temp = deleteFirst();
            printf("\nDeleted value:");
            printf("(%d,%d) \n",temp->key,temp->data);  
            break;
      case 4:cout<<"Enter the list number to search from:\n";
            cin>>linum;
            head=LinkList[linum]->nhead;
            foundLink = find(4);
  
            if(foundLink != NULL) {
            printf("Element found: ");
            printf("(%d,%d) ",foundLink->key,foundLink->data);
            printf("\n");
            }        
            else {
            printf("Element not found.");
            }
            break;
      case 5:cout<<"Enter the list number to search from:\n";
            cin>>linum;
            head=LinkList[linum]->nhead;
            cout<<"Enter the node to delete:\n";
            cin>>key;
            deleten(key);
            break;
      case 6:exit(0);break;
      default:cout<<"Wrong key entered";
    }
    head=NULL;
  }
  free(LinkList);
}

