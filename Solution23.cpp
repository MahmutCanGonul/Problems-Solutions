#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'funnyString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string funnyString(string s) {
    vector<int> asciiValues;
    //vector<int> reAsciiValues;
    int reAsciiValues[s.length()];
    int len = s.length();
    for(int i=0; i<s.length();i++)
    {
        asciiValues.push_back(int(s[i]));
        len--;
        reAsciiValues[len] = asciiValues[i];
    }
    
    vector<int> differences1;
    vector<int> differences2;
    for(int i=0; i<asciiValues.size();i++)
    {
        if(i!=asciiValues.size()-1)
        {
            int result = abs(asciiValues[i]-asciiValues[i+1]);
            differences1.push_back(result);
            /////////
             int result2 = abs(reAsciiValues[i]-reAsciiValues[i+1]);
             differences2.push_back(result2);
        }
       
    }
    
    
    string result = "Funny";
    int index=0;
    while(index!=differences1.size())
    {
        
        if(differences1[index]!=differences2[index])
        {
            result = "Not Funny";
            break;
        }
        index++;
    }
    
    return result;
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = funnyString(s);

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
