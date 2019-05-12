//This is the C++ program finding a loop in a linked list
//The idea is inspired from Geeks for Geeks
//@author: Saurav Rai
#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct Node
    {
      int data;
      Node *next;
    };

//First way:  using has map O(n)
bool detect_loop(Node *h)
    {
      unordered_set<Node *> s; for
      while(h!=NULL)
          {
           // If this node is already present
           // in hashmap it means there is a cycle
           // (Because you we encountering the
           // node for the second time).
            if(s.find(h)!=s.end())
                return true;
            else //if we are seeing the node for the first time then insert it in the
                s.insert(h);
          }
        return false;
    }

//Second way: using two pointers  //efficient way no reqd to store elements
 Node *detect_loop_remove(Node *head)
    {
      Node *slow_ptr , *fast_ptr;
      slow_ptr = head;
      fast_ptr = head;
      while(slow_ptr && fast_ptr && fast_ptr->next)  //while they are not NULL
        {
         slow_ptr = slow_ptr->next;
         fast_ptr = fast_ptr->next->next;
         if(slow_ptr == fast_ptr)
            break;
        }
      //if loop exists start slow from head and fast from the meeting pointing

       slow_ptr = head;
       while(slow_ptr!=fast_ptr)
         {
          slow_ptr = slow_ptr->next;
          fast_ptr = fast_ptr->next;
         }
      return slow_ptr;
    }

int main()
  {
    Node *head = NULL;
    Node *first = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *four = NULL;

    //allocate three nodes in the heap
    head = new Node();
    first = new Node();
    second = new Node();    //we have pointers to these blocks as head, first and second
    third = new Node();
    four = new Node();

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = four;

    four->data = 5;
    four->next = head;

    //to print all the elements in the list

    Node *temp;
    temp = head;

    Node *node;
    node = NULL;
    /*
    while(temp!= NULL)
       {
        cout<<temp->data;
        cout<<endl;
        temp = temp->next;
      }
     */
    if(detect_loop(head))
        cout<<"First way loop is present "<<endl;
    else
        cout<<"First way loop is not present"<<endl;

    node = detect_loop_remove(head);
    cout<<"The starting node in the loop is"<<node->data<<endl;
    cout<<"Second way loop is present "<<endl;

    Node * temp1;
    temp1 = head;
    /*
    cout<<"After detecting and removing"<<endl;
    while(temp1!= NULL)
       {
        cout<<temp1->data;
        cout<<endl;
        temp1 = temp1->next;
      }
    */
  return 0;
  }

