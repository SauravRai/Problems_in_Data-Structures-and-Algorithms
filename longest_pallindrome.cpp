#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string isreturnSubstring(string s,int low,int high)
  { int n = s.length();
    while(low>= 0 && high<n && (s[low]==s[high]))
     {
      low = low-1;
      high = high+1;
     }
    return s.substr(low+1,high-low-1);
  }
string isPallindrome(string s)
   {
     int n = s.length();
     int max_length = 0;
     int len_curr;
     string max_substring;
     string current_substring;
     if(n%2 ==0)
     {
      for(int i=0;i<n;i++)
       {
         current_substring  = isreturnSubstring(s,i,i+1); //This is the case for the even length string
         len_curr = current_substring.length();
         if(len_curr>max_length)
           {
             max_length = len_curr;
             max_substring = current_substring;
           }
       }
      return max_substring;
     }
    else
     {
      for(int i=0;i<n;i++)
       {
         current_substring  = isreturnSubstring(s,i,i); //This is the case for the even length string
         len_curr = current_substring.length();
         if(len_curr>max_length)
           {
             max_length = len_curr;
             max_substring = current_substring;
           }

       }
     return max_substring;
    }
  }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin>>s;
    cout<<isPallindrome(s);
    return 0;
}
