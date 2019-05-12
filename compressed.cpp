//This is the C++ problem to compress a string
//example: if the input is aabbabacc the output is: a4a4b3b3a4b3a4c2c2
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

void compressed_string(string str)
   {
     unordered_map<char,int> map1;
     unordered_map<char,int>::iterator itr;
     unordered_map<char,int>::iterator itr1;
     for(int i = 0;i<str.length();i++)
        {
        //for(auto itr  = map1.begin(); itr != map1.end(); itr++)
        // {
        //   cout<<"itr->first"<<itr->first;
          itr = map1.find(str[i]);
          if(itr != map1.end())
             {
              itr->second++;

             }
          else
             {
              map1.insert(pair<char,int> (str[i],1));
            }
        }


     //for(auto itr1 = map1.begin(); itr1!= map1.end(); itr1++)
     //  {

     for(int i = 0;i<str.length();i++)
        {
         itr1 = map1.find(str[i]);
         if(itr1 != map1.end() )
            {
              cout<<itr1->first<<itr1->second;
            }
       }
     cout<<endl;
 }

 int main()
    {
     string s;
     cout<<"Enter your string"<<endl;
     cin>>s;
     compressed_string(s);
     return 0;
    }

