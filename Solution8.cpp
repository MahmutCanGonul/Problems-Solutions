#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
 
map<pair<int,int>,int> q;


int dl(int i1,int i2,int n){
    int ret=0;
    while(i1<n && i2>1){
        i1++;
        i2--;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}
int up(int i1,int i2){
    int ret=0;
    while(i1>1){
        i1--;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int dw(int i1,int i2,int n){
    int ret=0;
    while(i1<n){
        i1++;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int lf(int i1,int i2){
    int ret=0;
    while(i2>1){
        i2--;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int rg(int i1,int i2,int n){
    int ret=0;
    while(i2<n){
        i2++;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int ur(int i1,int i2,int n){
    int ret=0;
    while(i1>1 && i2<n){
        i1--;
        i2++;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int ul(int i1,int i2){
    int ret=0;
    while(i1>1 && i2>1){
        i1--;
        i2--;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int dr(int i1,int i2,int n){
    int ret=0;
    while(i1<n && i2<n){
        i1++;
        i2++;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}





/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
     int sum=0;
     for(int i=0; i<k;i++)
     {
        vector<int> get_obs = obstacles[i];
        q[{get_obs[0],get_obs[1]}] =1;
     }
    sum= up(r_q,c_q)+dw(r_q,c_q,n)+lf(r_q,c_q)+rg(r_q,c_q,n)+ur(r_q,c_q,n)+ul(r_q,c_q)+dl(r_q,c_q,n)+dr(r_q,c_q,n);     
         
  return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
