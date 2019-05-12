//This is the C++ program for removing duplicate elements from a linklist using hashmap
#include<iostream>
#include<map>
using namespace std;

struct Node {
             int data;
             Node *next;
            };

void remove_duplicates(Node *head)
    {
      map<int,int> dup_map;
      map<int,int> :: iterator iter;
      Node *prev , *temp;
      prev = head;
      temp = head->next;
      while(temp != NULL)
        {
          iter = dup_map.find(temp->data);
          if(iter != dup_map.end())
             {
              prev->next = temp->next;
              temp = temp->next;
             }
          else
              {
                dup_map.insert(pair<int,int> (temp->data,1));
                //change the prev and temp nodes
                prev = temp;
                temp = temp->next;
              }
        }
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

    third->data = 3;
    third->next = four;

    four->data = 3;
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

    cout<<"After removing duplicates we have: "<<endl;
    remove_duplicates(head);

    Node *temp1;
    temp1 = head;
    while(temp1!= NULL)
       {
        cout<<temp1->data;
        cout<<endl;
        temp1 = temp1->next;
      }

   return 0;
  }

