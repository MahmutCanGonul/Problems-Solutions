#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) 
{
      string result;
      int flag = 0;
      uint64_t mask = 0x0;
    for (int i = 0; i < s.length(); i++)
        mask = mask ^ (1 << (s[i]-'a'));
    if ((!mask) || (((mask & (mask - 1)) == 0)))
        flag = 1;
    if(flag==0)
        result = "NO";
    else
        result = "YES";
       
      return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
