/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*************************e******************************************************/
#include <stdio.h>
#include<iostream>
using namespace std;

int countBits(int n)
{
   if(n == 0) //base case
   {
     return 0;
   }
   
else{
      return (n&1) + countBits(n>>1);
    }
}

int main()  
   {
    int input_number, count;    
    cout<<"Enter the number"<<endl;
    cin>>input_number;
    count = countBits(input_number);
    cout<<"The number of set bits is"<<count;
    return 0;  
   }



