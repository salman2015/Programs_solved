#include <iostream>
#include<string>
#include<cstddef>
#include<stdlib.h>
using namespace std;

 struct node{
        int data;
        node* next;
 };

class linkedlist
{


public:
    node *head=new node();
    linkedlist():head(NULL){}
    linkedlist(int val){
    head->data=val;
    head->next=NULL;
    }
    void print()
    {
        node *temp=head;
        while(temp!=NULL)
        {
        cout<<temp->data;
        temp=temp->next;
        cout<<endl;
    }
    }
    void append(int val)
    {
        node *temp=new node();
        temp->data=val;
        temp->next=head;
        head=temp;
    }
    void delete_element(int val)
    {
        node *temp1=head->next,*prev=head;

        if(head->data==val)
        {
            head=head->next;
            delete prev;
        }

        while(temp1->next!=NULL&&temp1->data!=val)
        {

            temp1=temp1->next;
            prev=prev->next;

        }

         if(temp1->data==val)
         {
        prev->next=temp1->next;
        node *temp=temp1;
        delete temp;
         }


    }
    void del_dup()
    {
     node *ptr1,*ptr2;
     ptr1=head;
     while(ptr1!=NULL)
     {
         ptr2=ptr1;
         while(ptr2->next!=NULL)
         {
             if(ptr1->data==ptr2->next->data)
             {
                 node *del=ptr2->next;
                 ptr2->next=ptr2->next->next;
                 delete del;
             }
             else
                ptr2=ptr2->next;
         }
         ptr1=ptr1->next;
     }

    }
  /*  void partition(int val)
    {
        node bfr,atr;
        node *temp=head;
        while(temp!=NULL)
        {
            if(temp->data<val)
            {
                bfr=*temp;
            }
        }
    }                      */
    void swap()
{
    node *temp;
    temp->next=head;
    head=temp;
    while(temp!=NULL)
    {
        if(temp->next==NULL||temp->next->next==NULL)
           break;
        node *hold2=temp->next;
        node *temp1=hold2->next;
        hold2->next=temp1->next;
        temp1->next=hold2;
        temp->next=temp1;
        temp=hold2;

    }
    head=head->next;
}

bool loopcheck()
{
    node *slow=head;
    node *fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}


};
void reverse(linkedlist *ll)
{
    node *prev=NULL;
    node *curr=ll->head;
    while(curr!=NULL)
    {
        node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    ll->head=prev;
}
linkedlist* add(linkedlist *ll1,linkedlist *ll2)
    {
       node *head1=ll1->head;
       node *head2=ll2->head;
        linkedlist *res=new linkedlist();
       int carry=0;
       while(head1!=NULL||head2!=NULL)
       {
           int val1,val2;
           if(head1==NULL)
             val1=0;
            else
            val1=head1->data;
           if(head2==NULL)
           val2=0;
           else
            val2=head2->data;
           int value=val1+val2+carry;
           int digit=value%10;
           res->append(digit);
           carry=value/10;
           if(head1!=NULL)
           head1=head1->next;
           if(head2!=NULL)
           head2=head2->next;
       }
       return res;
    }

int main()
{
    linkedlist *ll2=new linkedlist(5);
    ll2->append(11);
    for(int i=1;i<12;i++)
    {
        ll2->append(12-i);
    }
    ll2->append(1);
    ll2->append(2);
    ll2->append(5);
    ll2->append(3);
    ll2->append(25);
    ll2->append(4);
    ll2->print();
    ll2->del_dup();
    cout<<"after delete"<<endl;
    ll2->print();
    ll2->swap();
    cout<<"After swap"<<endl;
    ll2->print();
    linkedlist *ll3=new linkedlist(56);
    ll3->append(81);
    ll3->swap();
    ll3->print();
    cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
    linkedlist *ll4=new linkedlist(0);
    ll4->append(9);
    ll4->append(8);
    ll4->append(7);
    ll4->append(0);
    ll4->append(2);
    ll4->append(3);
    ll4->append(4);
    ll4->print();
    cout<<"after reverse"<<endl;
    reverse(ll4);
    cout<<"LIST 1"<<endl;
    ll4->print();
    linkedlist *ll5=new linkedlist(1);
    ll5->append(9);
    ll5->append(8);
    ll5->append(7);
    ll5->append(0);
    ll5->append(2);
    cout<<"LIST 2"<<endl;
    ll5->print();
    // Adding two linked list within main
    linkedlist *result=add(ll4,ll5);
    cout<<"Adding..RESULT"<<endl;
    result->print();
    cout<<"Loop check"<<endl;
    if(ll5->loopcheck())
        cout<<"LOOP"<<endl;
        else
            cout<<"NO LOOP"<<endl;
    node *test=ll5->head;
    node *test1=ll5->head->next->next;
    test1->next=test1;
     if(ll5->loopcheck())
        cout<<"LOOP"<<endl;
        else
            cout<<"NO LOOP"<<endl;
    return 0;
}
