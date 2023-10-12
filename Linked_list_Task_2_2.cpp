#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
typedef struct node Node;
struct node{
    int info;
    Node* next;
};
    Node* head=NULL;
    Node* tail=NULL;

void insert(int value){
   Node* newnode;
   newnode=(Node*)malloc(sizeof(Node));
   newnode->info=value;
   newnode->next=NULL;
   if(head==NULL){
    head=newnode;
   }else{
    tail->next=newnode;
   }
   tail=newnode;
}
void swap_pair(Node* head){
   Node* temp=head;
   while(temp!=NULL&&temp->next!=NULL){
    swap(temp->info,temp->next->info);



    temp=temp->next->next;
   }
}
void show_list(){
 Node* curr=head;
 while(curr!=NULL){
    cout<<curr->info<<"->";
    curr=curr->next;
 }
 cout<<"NULL";
}
int main(){
    int n;
    cout<<"enter the number of value"<<endl;
    cin>>n;
    cout<<"Enter the information of the node"<<endl;
    while(n--){
        int info;
        cin>>info;
        insert(info);
    }
    cout<<"the inserted information are:"<<endl;
    show_list();
    cout<<endl;
    cout<<"After pairwise swap:"<<endl;
    swap_pair(head);
    show_list();

return 0;
}

