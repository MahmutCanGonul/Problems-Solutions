#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int sorting_vector(vector<int> v)
{
    sort(v.begin(), v.end());
    return v[0];
}

vector<int> serviceLane(int n, vector<vector<int>> cases,vector<int> width) 
{
       vector<int> result;
       for(int i=0; i<cases.size();i++)
       {
             vector<int> insideCases = cases[i];
             int width1,width2;
             width1 = insideCases[0];
             width2 = insideCases[insideCases.size()-1];
             //int currentDifference = width2 - width1;
             vector<int> currentVec;
             while(width1 <= width2)
             {
                 currentVec.push_back(width[width1]);
                 width1++;
             }
             result.push_back(sorting_vector(currentVec));
             currentVec.clear();
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

    int t = stoi(first_multiple_input[1]);

    string width_temp_temp;
    getline(cin, width_temp_temp);

    vector<string> width_temp = split(rtrim(width_temp_temp));

    vector<int> width(n);

    for (int i = 0; i < n; i++) {
        int width_item = stoi(width_temp[i]);

        width[i] = width_item;
    }

    vector<vector<int>> cases(t);

    for (int i = 0; i < t; i++) {
        cases[i].resize(2);

        string cases_row_temp_temp;
        getline(cin, cases_row_temp_temp);

        vector<string> cases_row_temp = split(rtrim(cases_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int cases_row_item = stoi(cases_row_temp[j]);

            cases[i][j] = cases_row_item;
        }
    }

    vector<int> result = serviceLane(n, cases,width);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
