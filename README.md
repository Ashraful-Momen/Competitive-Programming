# Competitive-Programming

How to compline with g++ with input.txt and output.txt file : 
-------------------------------------------------------------
hello.cpp: 
----------
#include <bits/stdc++.h>
using namespace std;

int main (){

    int number; 
    cin>> number;
    cout<<"The Number is : " << number;
}

input: 
------
5

output.txt: 
-----------
The Number is : 5

┌──(ashraful㉿kali)-[~/Instasure/MicroService_4_OCT_25/DSA]
└─$ g++ hello.cpp -o hello && ./hello < input.txt > output.txt
