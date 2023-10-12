#include<bits/stdc++.h>
using namespace std;


struct node{
    int info;
    struct node *next;
};

struct node *head = NULL;
struct node*tail = NULL;
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

void display()
{
    struct node* ptr = head;
    while(ptr != NULL){
        cout<<ptr->info<<" -> ";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
    return;
}
void remove_duplicate(){
struct node* preptr=head;
struct node* ptr;
struct node* midptr;
while(preptr!=NULL){
    ptr=preptr->next;
    midptr=preptr;
    while(ptr!=NULL){

        if(ptr->info==preptr->info){
            midptr->next=ptr->next;
           // free(ptr);
        }
        else{
           midptr=ptr;
        }
        ptr=ptr->next;
    }
    preptr=preptr->next;
}

}

int main()
{
    int n;
    cout<<"How many number do you want to enter: ";
    cin>>n;
    cout<<"Enter numbers: ";
    while(n--){
        int x;
        cin>>x;
        insert(x);
    }
    cout<<"You have entered:\n";
    display();
    remove_duplicate();
    cout<<"duplicate element succesfully removed"<<endl;
    display();
    return 0;
}

