#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'workbook' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY arr
 */

int workbook(int n, int k, vector<int> arr) 
{
    int result=0;
    vector<vector<int>> blocks;
    vector<int> block;
    for(int i=0; i<arr.size();i++)
    {
        int problems = arr[i];
        int index=0;
        while(problems >= k)
        {
            problems-=k;
            for(int j=0; j<k;j++)
            {
                block.push_back(index);
                index++;
            }
            blocks.push_back(block);
            block.clear();
        }
        for(int x =0; x<problems;x++)
        {
            block.push_back(index);
            index++;
            if(x == problems-1)
                 blocks.push_back(block);
        }
        //blocks.push_back(block);
        block.clear();   
    }
    
    
    for(int i=0; i<blocks.size();i++)
    {
         
        for(int j=0; j<blocks[i].size();j++)
        {
            cout<<" "<<blocks[i][j];
            if(blocks[i][j] == i)
            {
                result++;
            }
        }
        cout<<"////////////////////////"<<endl;
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = workbook(n, k, arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
