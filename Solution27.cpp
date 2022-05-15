#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternate(string s) {
 vector<char> chars;
  vector<vector<char>> options;
  if(s == "a")
      return 0;
      
 for(int i=0; i<s.length();i++){
     bool isHas=false;
     for(int j=0;j<chars.size();j++){
         if(s[i] == chars[j])
           isHas=true;
     }
     if(!isHas)
        chars.push_back(s[i]);
 }

 for(int i=0; i<chars.size();i++){
     for(int j=0; j<chars.size();j++){
      vector<char> get_chars;
      get_chars.push_back(chars[i]);
      get_chars.push_back(chars[j]);
      options.push_back(get_chars);   
     }
 }
 vector<string> words;
 for(int i=0; i<options.size();i++){
     //cout<<options[i][0]<<options[i][1]<<endl;
     string constant="";
     vector<char> get_data = options[i];
        for(int j=0; j<s.length();j++){
            if(s[j] == get_data[0] || s[j] == get_data[1])
                 constant = constant + s[j];
        }
     words.push_back(constant);
 }
   for(int i=0; i<words.size();i++){
       cout<<words[i]<<endl;
   }
 int result=0;
 vector<string> mainWords;
 vector<int> mainWordsLen;
 for(int i=0; i<words.size();i++){
     string word = words[i];
     bool isRepaet=false;
     for(int j=0; j<word.length();j++){
         if(j!=word.length()-1){
             if(word[j] == word[j+1]){
                 isRepaet=true;
                 break;
             }
         }
     }
     if(!isRepaet){
         mainWords.push_back(word);
         mainWordsLen.push_back(word.length());
     }
 }
 sort(mainWordsLen.begin(),mainWordsLen.end());
 for(int i=0; i<mainWords.size();i++){
     if(mainWords[i].length() == mainWordsLen[mainWordsLen.size()-1]){
         result = mainWords[i].length();
         break;
     }
 }
 
 

   return result;
  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

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
