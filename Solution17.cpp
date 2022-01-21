#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   
     int len;
     cin >> len;
     vector<long> arr;
     for(int i=0; i<len;i++)
     {
         int num;
         cin>>num;
         arr.push_back(num);
     } 
      
     sort(arr.begin(), arr.end() );
     
    for (vector<long>::const_iterator it=arr.begin(); it!=arr.end(); ++it) {
      cout << *it << " ";
    } 
       
   
    return 0;
}
