#include<bits/stdc++.h>

using namespace std;
struct node{
  int info;
  struct node *next;

};
struct node *head=NULL;
struct node *tail=NULL;
void insert(int value){
   struct node *newnode;
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->info=value;
   newnode->next=NULL;
   if(head==NULL){
    head= newnode;
   }else{
     tail->next=newnode;
   }
   tail=newnode;
   return;
}
void show_list(){
   struct node *curr=head;
   while(curr!=NULL){
    cout<<curr->info<<"->";
    curr=curr->next;
   }
   cout<<"NULL"<<endl;

}
void prepend(int val){
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->info=val;

  newnode->next=head;
  head=newnode;
}
void insertAtend(int val){
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->info=val;
  newnode->next=NULL;
  tail->next=newnode;
  tail=newnode;
}
void isertAtindex(int val,int pos){
  struct node* newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->info=val;
  newnode->next=NULL;
  struct node* ptr=head;
  struct node* preptr=NULL;
  int i=1;
  while(ptr!=NULL){
    if(i==pos){
      if(ptr==head){
        newnode->next=head;
        head=newnode;
      }else{
        preptr->next=newnode;
        newnode->next=ptr;
      }
      return;
    }
    i++;
    preptr=ptr;
    ptr=ptr->next;
  }
}
void deletebyValue(int val){
struct node* preptr=head;
struct node* ptr=preptr->next;
if(preptr->info==val){
    head=ptr;
    free(preptr);
    return;
}
while(ptr!=NULL){
    if(ptr->info==val&&ptr==tail){
       tail=preptr;
       tail->next=NULL;
       free(ptr);
       return;
    }
    else if(ptr->info==val&&ptr!=tail){
        preptr->next=ptr->next;
        free(ptr);
        return;
    }
    preptr=ptr;
    ptr=ptr->next;
}
return;
}
void free_memory(){
  while(head!=NULL){
    struct node *temp=head->next;
    free(head);
    head=temp;
  }
  return;
}
int lengthofLinkList(){
int i;
struct node* ptr=head;
while(ptr!=NULL){
    i++;
    ptr=ptr->next;
}
cout<<i;
return i;
}

int main(){
int n;
cout<<"Enter the number of node"<<endl;
cin>>n;
cout<<"Enter the information of node"<<endl;
while(n--){
    int info;
    cin>>info;
    insert(info);
}
 show_list();
 cout <<"enter the value at the begining"<<endl;
 int val;
 cin>>val;
 prepend(val);
 show_list();
 cout<<"enter the value at the end"<<endl;
 cin>>val;
 insertAtend(val);
 show_list();
 int pos;
 cout<<"enter value and position to insert"<<endl;
 cin>>val>>pos;

 isertAtindex(val,pos);
 show_list();
 cout<<"enter a value for delete"<<endl;
 cin>>val;
 deletebyValue(val);
 show_list();
 cout<<"length of a linklist"<<endl;
 lengthofLinkList();
 cout<<endl;
 cout<<"enter multiple data at the end"<<endl;
 cout<<"how many data do you want to enter"<<endl;
 cin>>n;
 cout<<"enter data"<<endl;
 while(n--){
    int info;
    cin>>info;
    insert(info);
}
show_list();
 return 0;
}
