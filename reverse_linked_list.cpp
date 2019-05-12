//This C++ program will reverse a given linked list
//The idea is taken from the geeks for geeks
#include<iostream>
#include<map>
using namespace std;

struct Node {
             int data;
             Node *next;
            };

Node *reverse_list(Node *head)
    {
     Node *prev, *current, *next;
     current = head;
     prev = NULL;
     next = NULL;
     if(current==NULL)
        {
         cout<<"The current node is NULL "<<endl;
         return current;
        }
     else if(current->next ==NULL)
        {
         cout<<"There is only one element: "<<endl;
         return current;
        }
     while(current!= NULL)
        {
          next  = current->next;
          current->next = prev;
          prev = current;
          current = next;
       }
      return prev; //prev is the head node
   }

 int main()
  {
    Node *head = NULL;
    Node *first = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *four = NULL;
    Node *h = NULL;
    //allocate three nodes in the heap
    head = new Node();
    first = new Node();
    second = new Node();    //we have pointers to these blocks as head, first and second
    third = new Node();
    four = new Node();
    h = new Node();

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 3;
    third->next = four;

    four->data = 5;
    four->next = NULL;

    //to print all the elements in the list

    Node *temp;
    temp = head;

    while(temp!= NULL)
       {
        cout<<temp->data;
        cout<<endl;
        temp = temp->next;
      }

    h = reverse_list(head);
    cout<<"head in the linked list is: "<<h->data<<endl;
    cout<<"The reverse of the linked list is : "<<endl;
    Node *temp1;
    temp1 = h;
    while(temp1!= NULL)
       {
        cout<<temp1->data;
        cout<<endl;
        temp1 = temp1->next;
      }

   return 0;
  }

