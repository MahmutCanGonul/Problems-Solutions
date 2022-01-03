#include <bits/stdc++.h>
#include <math.h>  

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
   double result = sqrt(s.length());
   
   int row = int(result);
   int column = int(result)+1;
   
   
   if((row*column)<s.length())
   {
       row++;
   }
   
   if(result == int(result))
   {
      row = int(result);
      column = int(result);
   }
   
   
   
   cout<<row<<endl;
   cout<<column<<endl;
   string words[row];
   string word="";
   int count=0;
   int count_column=0;
   for(int i=0; i<s.length();i++)
   {
       word = word+s[i];
       count_column++;
       words[count] = word;
       if(count_column == column)
       {
           words[count]=word;
           word="";
           count++;
           count_column=0;
       }
       
       if(count == row)
          break;
        
   }
   string mainResult="";
   int n=0;
   int n2=0;
   for(int i=0; i<row;i++)
       cout<<words[i]<<endl;
   
   while(true)
   {
      mainResult = mainResult + words[n][n2];
      n++;
      if(n ==row)
      {
          n=0;
          n2++; 
          mainResult = mainResult + " ";
      }
      
      if(n2==column)
         break;    
   }
   string mainResult2="";
   for(int i=0; i<mainResult.length();i++)
   {
       if((mainResult[i]>='a' && mainResult[i]<='z') || (mainResult[i]>='A' && mainResult[i]<='Z') || mainResult[i] == ' ')
       {
           mainResult2 = mainResult2 + mainResult[i];
       }
   }
   
  
   return mainResult2;   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
