//This is the C++ program for removing duplicates present in a linked list
//Remove duplicates using vector and map
#include<iostream>
#include<vector>
#include<map>

using namespace std;

void remove_duplicates(vector<int> &v) //by reference so that the values will change
   {
     map<int,int> dup_map;
     for(int i=0;i<v.size();i++)
       { dup_map[v[i]] = 0;   } //so here element of the vector is the key and the value is 0 or 1.

     for(int j =0;j<v.size();j++)
        {
           if(dup_map[v[j]]==1)
               {
                 //swap(v[j],v[v.size()-1];
                 v[j] = v[v.size()-1]; //copy the last element in the jth position
                 //v[v.size()-1].pop();
                 v.pop_back(); //and pop the last element from the list
                 j--; //to check whether the last copied element is duplicate or not

               }
           else
               {
                 dup_map[v[j]] =1;
               }
        }
   }

 void display(vector<int> v)
   {
     for(int i = 0;i<v.size();i++)
          cout<<v[i]<<" ";
     cout<<endl;
   }

 int main()
   {
     vector<int> v;
     int size;
     int element;
     cout<<"Enter the size of the vector"<<endl;
     cin>>size;
     for(int i =0; i<size;i++)
       {
          cout<<"Enter the elements in the vector"<<endl;
          cin>>element;
          v.push_back(element);
       }
     cout<<"The elements in the vector is: "<<endl;
     display(v);
     remove_duplicates(v);
     cout<<"The elements in the vector after removing duplicates is: "<<endl;
     display(v);
    return 0;
   }
