/*
 Single linked list implementation in C++
 @author: Saurav Rai
*/
#include <iostream>
#include <string>
using namespace std;

//NOTE: The indexing of the Linked List starts from 0

class Node
    {
     public:
     int data;
     Node * next;
    };

Node * insert(Node*, int);
Node * delete_element(Node*,int);
Node *reverse(Node*);
Node *addafterNNodes(Node *, int); 
Node *deleteafterNNodes(Node *, int);

int lenLL(Node * head)
    {
     Node * temp = head;
     int count=0;
     while(temp!=NULL)
         {
            temp = temp->next; 
            count = count + 1;  
         }
       return count;
    }


void display(Node *head)
  {
    Node *temp;
    temp = head;
   while(temp!= NULL)
       {
        cout<<temp->data;
        cout<<endl;
        temp = temp->next; 
      }
  }

int main()
  {
    int opt; 
    cout<<"************SINGLE LINKED LIST PROGRAM**************"<<endl;
    cout<<"Do you wish to create a linked list"<<endl;
    cout<<"Enter 1 for creating a Linked List or 0 for discontinue"<<endl; 
    cin>>opt;
    if(opt == 0)
       {
         exit(0);
       }
       
    Node *head = NULL;
    head = new Node();    
    int element,n,i;   
    Node *newNode, *temp;
    
    if(head == NULL) 
    {
        cout<<" Memory can not be allocated."<<endl;
    }
    
    else
    {
        cout<<" Input the first element for the Linked List: "<<endl;
        cin>>element;
        head->data = element;      
        head->next = NULL; 
        temp = head;
        cout<<"Enter how many nodes you want in the Linked List"<<endl;
        cin>>n;
        for(i=1; i<n; i++)
        {
            newNode = new Node();
            if(newNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                cout<<" Input element for node: "<<i<<": ";
                cin>>element;
 
                newNode->data = element;      
                newNode->next = NULL; 
   
                temp->next = newNode; 
                temp = temp->next; 
            }
        }
    }
    int a,d;
    int option;
    cout<<"*******************************************************************"<<endl;
    do{
          cout<<"Enter your choice in the following"<<endl;
          cout<<"1.Display elements"<<endl;
          cout<<"2.Insert element in the Linked list"<<endl;
          cout<<"3.Delete an element in the list"<<endl;
          cout<<"4.Reverse the linked list"<<endl;
          cout<<"5.Add after n nodes in LL"<<endl;
          cout<<"6.Delete after n nodes in LL"<<endl;

          cin>>a;
          switch(a)
         { 

         case 1:cout<<"The elements in the list are: "<<endl;
                cout<<"Sairam"<<endl;
                display(head);
                break;
 
         case 2:cout<<"Inserting at the list: "<<endl;
                cout<<"Enter the element you wish to put in the beg of the list"<<endl; 
                cin>>d;
                head = insert(head,d);
                cout<<"The list after inserting the element in the begining"<<endl;
                display(head);
                break;  
         
         case 3:cout<<"Deleting an element in the list: "<<endl;
                cout<<"Enter the element you wish to delete in the list"<<endl;
                cin>>d;
                head = delete_element(head,d);
                cout<<"The list after deleting element in the list"<<endl;
                display(head);
                break;
         case 4: cout<<"The reverse of the linked list is"<<endl;            
                head = reverse(head);
                cout<<"The list after reversing element in the list"<<endl;
                display(head);
                break;
         
         case 5: cout<<"Enter the number after which you want to insert in the linked list"<<endl;            
                cin>>d;
                head = addafterNNodes(head,d);
                cout<<"The list after insserting element in the list"<<endl;
                display(head);    
                break;
         case 6: cout<<"Enter the number after which you want to delete in the linked list"<<endl;            
                cin>>d;
                head = deleteafterNNodes(head,d);
                cout<<"The list after deleting element in the list"<<endl;
                display(head);    
                break;
         default: cout<<"Please enter the correct option"<<endl;
                 break;        
          } 
         cout<<"Enter 1 for continue and 0 for discontinue"<<endl; 
         cin>>option;
      }while(option);     
   return 0;
  }

 

 Node * insert(Node *h,int d)
   {
    Node * p; //Node to be addded in the list 
    p = new Node();
    p->data = d; 
    if(h==NULL)     
      {
       return p;
      }
    else
     {
      p->next = h;
      return p;
     } 
   }


  Node * delete_element(Node *h , int d)
   { 
    Node *cur , *prev;
    cur =h;

    if(h ==NULL)
      {
       cout<<"The list is empty"<<endl; 
      }
    else if(h->data == d)
       {
         cur = h;
         h = cur->next;
         free(cur);       
       }
    //traverse the list to find the element to be deleted
    prev = cur;
    while(cur->next != NULL)
       {
         if(cur->data != d)
           {
             prev = cur;
             cur = cur->next;  
           }
         else
           {
             prev->next = cur->next;
             free(cur); 
           }        
       }       
     return h;
   }   
     
Node *reverse(Node *head)
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
   
   
Node *addafterNNodes(Node *Head, int number)
    {
       int value, count=0;
       cout<<"Enter the value you want to insert in the LL"<<endl;
       cin>>value;
       Node *P = new Node();
       P->data = value;
       
       int len = lenLL(Head);
       Node *temp =Head;
       int m = len-1;
       if(m < number)
           {
              cout<<"Not possible"<<endl;
              exit(0);
           }
       else
         {
            while(temp->next!=NULL &&  count <  number)
                  {
                     temp = temp->next; 
                     count = count + 1;  
                   }
              P->next = temp->next;
              temp->next = P;
        }   
    return Head;
    }
    
Node * deleteafterNNodes(Node *Head, int number)
    {
       int count=0;
       int len = lenLL(Head);
       int m = len-1;
       Node *temp = Head;
       if(m < number)
           {
              cout<<"Not possible"<<endl;
              exit(0);
         }
       else
         {
              while(temp->next !=NULL &&  count <  number)
                  {
                     temp = temp->next; 
                     count = count + 1;  
                  }
             Node * prev = temp;
             Node * Curr = temp->next;
             prev->next = Curr->next;
             free(Curr);
        }   
    return Head;
    }
    
