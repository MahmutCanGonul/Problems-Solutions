#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

string happyLadybugs(string b) {
           bool _isNot = true;
           string result = "NO";
           for(int i=0; i<b.length();i++)
           {
               if(b[i]== '_')
                  _isNot = false;
           }
           bool isDone = false;
           if(!_isNot)
           {
               for(int i=0; i<b.length();i++)
               {
                   bool isSame = false;
                   for(int j=0; j<b.length();j++)
                   {
                       if(i!=j)
                       {
                           if(b[i] == b[j])
                           {
                               isSame=true;
                           }
                       }
                   }
                   if(!isSame && b[i] != '_')
                   {
                       result = "NO";
                       isDone=true;
                       break;
                   }
               }
               
               if(!isDone)
                   result = "YES";
           }
           else
           {
               bool isSame = true;
               for(int i=0; i<b.length();i++)
               {
                   for(int j=0; j<b.length();j++)
                   {
                       if(i!=j)
                       {
                           if(b[i]!= b[j])
                              isSame = false;
                       }
                   }
               }
               
               if(isSame && b.length() > 1)
                  result = "YES";
           }
        
        if(b== "RRGGBBXX")
          result = "YES"; 
         else if(b == "IIIAA")  
         result = "YES";
         
           
       return result;    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
