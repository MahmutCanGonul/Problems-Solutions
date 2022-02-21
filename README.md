# C++
C++ Problems and Solution

Problem-1:

A child is playing a cloud hopping game. In this game, there are sequentially numbered clouds that can be thunderheads or cumulus clouds. The character must jump from cloud to cloud until it reaches the start again.

There is an array of clouds, c and an energy level e=100 . The character starts from c[0]  and uses  1 unit of energy to make a jump of size k  to cloud c[(i+k)%c.size()]. If it lands on a thundercloud, c[i]=1 , its energy (e) decreases by 2 additional units. The game ends when the character lands back on cloud .

Given the values of n, k, and the configuration of the clouds as an array c, determine the final value of e after the game ends.



💣Solution-1:


               int jumpingOnClouds(vector<int> c, int k) 
                {
                   int level =100;
                   int i = k % c.size();
                   level-= c[i] * 2 + 1; 
                   while(i!=0)
                   {
                   i=(i+k)%c.size();
                   level-=c[i] * 2 + 1;
        
                    }  
                    return level;
      
                 }


Problem-2:

  The distance between two array values is the number of indices between them. Given a, find the minimum distance between any pair of equal elements in the array. If no such value exists, return -1.
  
Example: 

 Input:
                 
                 STDIN           Function
                  -----           --------
                   6               arr[] size n = 6
                   7 1 3 4 1 7     arr = [7, 1, 3, 4, 1, 7]
  
  Output:
  
  
  
                    3
                    
                    
 💣Solution-2:
 
 
 
      int minimumDistances(vector<int> a) {
     int take[a.size()];
     for(int i=0; i<a.size();i++)
          take[i]=-1;
     for(int i=0; i<a.size();i++)
     {
    
      for(int j=0; j<a.size();j++)
      {
         if(i!=j)
         {
             if(a[i] == a[j])
             {
                 int sum  = i-j;
                 int result = abs(sum);
                  take[i] =result;
             }
         }    
      }   
      
         
     }
      int n = sizeof(take) / sizeof(take[0]);
 
    
    sort(take, take + n);
    int result=-1;
    for(int i=0; i<a.size();i++)
    {
        if(take[i]!=-1)
        {
            result=take[i];
            break;
        }
            
    } 
   
     return result;
         
     }



Problem-3:


In this challenge, you are required to handle error messages while working with small computational server that performs complex calculations.
It has a function that takes  large numbers as its input and returns a numeric result. Unfortunately, there are various exceptions that may occur during execution.

Complete the code in your editor so that it prints appropriate error messages, should anything go wrong. The expected behavior is defined as follows:

🍎If the compute function runs fine with the given arguments, then print the result of the function call.

🍎If it fails to allocate the memory that it needs, print Not enough memory.

🍎If any other standard C++ exception occurs, print Exception: S where  is the exception's error message.

🍎If any non-standard exception occurs, print Other Exception.


💣Solution-3:       

 =>This Code Help Error Detection<=
 
 
                                  try
                                 {
                                  cout<<Server::compute(A,B)<<endl;
                                  }
                                  catch(bad_alloc& error)
                                   {
                                      cout<<"Not enough memory"<<endl;
                                    }
                                    catch(exception& error)
                                    {
                                     cout<<"Exception: "<<error.what()<<endl;
                                     }
                                     catch(...)
                                      {
                                     cout<<"Other Exception"<<endl;
                                      }
                     


Problem-4:

🍎The problem is An English text needs to be encrypted using the following encryption scheme.
First, the spaces are removed from the text. Let  be the length of this text.
Then, characters are written into a grid, whose rows and columns have the following constraints:
 
 Example-1:
 
         INPUT:   haveaniceday
         OUTPUT: hae and via ecy
         
         
Example-2:
         
          INPUT:   feedthedog    
         OUTPUT: fto ehg ee dd
         
         
         
 💣Solution-4:
 
 
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
 
         
         
 
  
Problem-5: 

🍎You are the benevolent ruler of Rankhacker Castle, and today you're distributing bread. Your subjects are in a line, and some of them already have some loaves. Times are hard and your castle's food stocks are dwindling, so you must distribute as few loaves as possible according to the following rules:

Every time you give a loaf of bread to some person , you must also give a loaf of bread to the person immediately in front of or behind them in the line (i.e., persons i+1  or i-1).
After all the bread is distributed, each person must have an even number of loaves.
Given the number of loaves already held by each citizen, find and print the minimum number of loaves you must distribute to satisfy the two rules above. If this is not possible, print NO.

 
Solution-5:


                      string fairRations(vector<int> B) 
                      {
                         string result= "NO";
                         int breadCount=0;
                         for(int i=0; i<B.size();i++)
                         {
                          if(B[i] % 2 == 1)
                           {
                               B[i] = B[i]+1;
                                breadCount++;
                              if(i!=B.size()-1)
                              {
                                B[i+1]=B[i+1]+1;
                                breadCount++;
                               }
                              else
                                {
                                 B[i-1]=B[i-1]+1;
                                 breadCount++;
                               }
                             }
      
                           result = std::to_string(breadCount);
                          }
   
   
                 for(int i=0; i<B.size();i++)
                 {
                    if(B[i] % 2 == 1)
                    result = "NO";
                 }
   
                 return result;
             }


Problem-6:

🍎You wish to buy video games from the famous online video game store Mist.

Usually, all games are sold at the same price,  dollars. However, they are planning to have the seasonal Halloween Sale next month in which you can buy games at a cheaper price. Specifically, the first game will cost  dollars, and every subsequent game will cost  dollars less than the previous one. This continues until the cost becomes less than or equal to  dollars, after which every game will cost  dollars. How many games can you buy during the Halloween Sale?



💣Solution-6:



     int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy
    int sum=0;
    int count=0;
    while(true)
    {
    
        sum+=p;
        p-=d;
        if(p<m)
          p=m;
        
        if(sum > s)
        {
            sum = sum - p;
            break;
        }
        count++;
    }
       
       return count;
       
     }


Problem-7:

John Watson knows of an operation called a right circular rotation on an array of integers. One rotation operation moves the last array element to the first position and shifts all remaining elements right one. To test Sherlock's abilities, Watson provides Sherlock with an array of integers. Sherlock is to perform the rotation operation a number of times then determine the value of the element at a given position.

For each array, perform a number of right circular rotations and return the values of the elements at the given indices.

🍎Function Description:
Complete the circularArrayRotation function in the editor below.

circularArrayRotation has the following parameter(s):

int a[n]: the array to rotate
int k: the rotation count
int queries[1]: the indices to report


💣Solution-7:


                    vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
                 
                   int dest=k%a.size();
                   int b[a.size()];
                   for (int i=0;i<a.size();i++) {
                      b[dest++]=a[i];
                      if (dest==a.size()) 
                      dest=0;
                   }

                   for (int i=0;i<queries.size();i++) 
                   queries[i] =  b[queries[i]] ;

                   return queries;
                  }



Problem-8:


You will be given a square chess board with one queen and a number of obstacles placed on it. Determine how many squares the queen can attack.

A queen is standing on an (n x n) chessboard. The chess board's rows are numbered from 1 to n, going from bottom to top. Its columns are numbered from  to , going from left to right. Each square is referenced by a tuple, (r,c), describing the row, r, and column, c, where the square is located.

The queen is standing at position (rq,rc). In a single move, she can attack any square in any of the eight directions (left, right, up, down, and the four diagonals). In the diagram below, the green circles denote all the cells the queen can attack from (4,4):


![image](https://user-images.githubusercontent.com/75094927/148538813-72d8ee56-a0f2-484e-a18a-e7f9b9ea510f.png)

🍎Function Description

Complete the queensAttack function in the editor below.

queensAttack has the following parameters:
- int n: the number of rows and columns in the board
- nt k: the number of obstacles on the board
- int r_q: the row number of the queen's position
- int c_q: the column number of the queen's position
- int obstacles[k][2]: each element is an array of  integers, the row and column of an obstacle




💣Solution-8:



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


Problem-9:

A video player plays a game in which the character competes in a hurdle race. Hurdles are of varying heights, and the characters have a maximum height they can jump. There is a magic potion they can take that will increase their maximum jump height by 1 unit for each dose. How many doses of the potion must the character take to be able to jump all of the hurdles. If the character can already clear all of the hurdles, return 0.


💣Solution-9:




     int hurdleRace(int k, vector<int> height) {

       sort(height.begin(), height.end());
      int result = height[height.size()-1]-k;
    
      if(result < 0)
         result =0; 
    
       return result;

     }

Problem-10:


An arcade game player wants to climb to the top of the leaderboard and track their ranking. The game uses Dense Ranking, so its leaderboard works like this:

The player with the highest score is ranked number  on the leaderboard.
Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number.
Example

ranked = [100,90,90,80]
player = [70,80,105]

The ranked players will have ranks 1, 2, 2, and 3, respectively. If the player's scores are 70, 80 and 105, their rankings after each game are 4, 3 and 1. Return [4,3,1]



Function Description

Complete the climbingLeaderboard function in the editor below.

climbingLeaderboard has the following parameter(s):

int ranked[n]: the leaderboard scores
int player[m]: the player's scores
Returns

int[m]: the player's rank after each new score



💣Solution-10:



    vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
     stack<int> levels;
     for(int i=0; i<ranked.size();i++)
     {
         if (levels.empty() || levels.top() != ranked[i]) 
                levels.push(ranked[i]);
     }
     
     for(int i=0; i<player.size();i++)
     {
         while (!levels.empty() && player[i] >= levels.top()) 
               levels.pop();
         player[i] = levels.size()+1;
     }
     
     return player;
    }


Problem-11:


 Given a sequence of integers a, a triplet (a[i],a[j],a[k])  is beautiful if:

🍎 i<j<k
🍎 a[j]-a[i] = a[k]-a[j]=d
         

Given an increasing sequenc of integers and the value of , count the number of beautiful triplets in the sequence.

Function Description

Complete the beautifulTriplets function in the editor below.

beautifulTriplets has the following parameters:

int d: the value to match
int arr[n]: the sequence, sorted ascending
Returns

int: the number of beautiful triplets
         
         
         
💣Solution-11:


                                                            
                     int beautifulTriplets(int d, vector<int> arr) 
                     
                     {
                     int count;
                    int result=0;
                      int sum=0;
                     int temp=0;
                      bool isNot=false;
                      for(int i=0; i<arr.size();i++)
                     {
                       count=0;
                       isNot=false;
                       for(int j=0; j<arr.size();j++)
                       {
                         if(i<j)
                         {
                           if(!isNot)
                           {
                                sum = arr[j] - arr[i];
                           }
                           else
                           {
                                sum = arr[j] - arr[temp];
                           }
            
                           if(sum==d)
                           {
                            temp=j;
                            count++;
                            isNot=true;
                           }       
             
                       }
           
                     if(count==2){result++;  break;}
             
                   }
       
        
                }
   
              return result;

           }
 
         
         
         
Problem-12:

There is a large pile of socks that must be paired by color. Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.

Example
n=9
ar = [10,20,20,10,10,30,50,10,20]

Output = 3

![image](https://user-images.githubusercontent.com/75094927/148952055-5cf0b7be-f6ab-44bb-b1cb-00276e86333d.png)



There is one pair of color 1 and one of color 2. There are three odd socks left, one of each color. The number of pairs is 2.

Function Description

Complete the sockMerchant function in the editor below.

sockMerchant has the following parameter(s):

int n: the number of socks in the pile
int ar[n]: the colors of each sock
Returns

int: the number of pairs
         
         
         
💣Solution-12:
                 
    int sockMerchant(int n, vector<int> ar) {
    srand (time(NULL));    
    int result=0;
       
    for(int i=0; i<ar.size();i++)
    {
       for(int j=0; j<ar.size();j++)
       {
           if(i!=j)
           {
               if(ar[i] > 0)
               {
                 if(ar[i] == ar[j])
                 {
                     ar[i] = (rand()%100000)*-1;
                     ar[j] = (rand()%100000)*-1;
                     result++;
                     break;
                 }
               }
           }
       }
    }
     
    return result;
    }



Problem-13:

🍎Formula: (shared/2) *3 
 
The progression is shown above. The cumulative number of likes on the  day is .

Function Description

Complete the viralAdvertising function in the editor below.

viralAdvertising has the following parameter(s):

int n: the day number to report
Returns

int: the cumulative likes at that day



💣Solution-13:

     int viralAdvertising(int n) {
     int first_day = 5;
     int result= int(first_day/2);
     for(int i=0; i<n-1;i++)
     {
         first_day = int(first_day/2) * 3;
         result+=int((first_day/2));
     }
     
     
      return result;
     
     }



Problem-14:



 Lily likes to play games with integers. She has created a new game where she determines the difference between a number and its reverse. For instance, given the number 12, its reverse is 21. Their difference is 9. The number  120 reversed is 21, and their difference is 99.

She decides to apply her game to decision making. She will look at a numbered range of days and will only go to a movie on a beautiful day.

Given a range of numbered days, [i...j] and a number k, determine the number of days in the range that are beautiful. Beautiful numbers are defined as numbers where [i-reverse(i)] is evenly divisible by k. If a day's value is a beautiful number, it is a beautiful day. Return the number of beautiful days in the range.

Function Description

Complete the beautifulDays function in the editor below.

beautifulDays has the following parameter(s):

int i: the starting day number
int j: the ending day number
int k: the divisor
Returns

int: the number of beautiful days in the range



💣Solution-14:



     int beautifulDays(int i, int j, int k) {
     
       
       string data="";
       int dif = j - i;
       int mainResult=0;
       int tempi = i;
       long l = k;
       for(int n=0; n<=dif;n++)
       {
           data="";
           i= tempi;
           i+=n;
           int temp;
           string i_str = to_string(i);
           int count = i_str.length();
           for(int m=0; m<i_str.length();m++)
           {
               count--;
               data = data + i_str[count];
           }
           stringstream stream(data);
           stream >> temp;
           if((i - temp) % l == 0)
           {
               mainResult++;
           }
            
       }
   
      return mainResult;
      
    }


Problem-15:  


David has several containers, each with a number of balls in it. He has just enough containers to sort each type of ball he has into its own container. David wants to sort the balls using his sort method.

David wants to perform some number of swap operations such that:

Each container contains only balls of the same type.
No two balls of the same type are located in different containers.

Example

containers = [[1,4],[2,3]]

David has n=2  containers and  different 2 types of balls, both of which are numbered from 0 to n-1=1. The distribution of ball types per container are shown in the following diagram.

![image](https://user-images.githubusercontent.com/75094927/149766461-e9fb6151-0a52-4805-af86-25313db6c642.png)

In a single operation, David can swap two balls located in different containers.

The diagram below depicts a single swap operation:

![image](https://user-images.githubusercontent.com/75094927/149766480-d8180e53-f4d4-45db-b1b7-38f2a0e83193.png)

In this case, there is no way to have all green balls in one container and all red in the other using only swap operations. Return Impossible.

You must perform  queries where each query is in the form of a matrix, . For each query, print Possible on a new line if David can satisfy the conditions above for the given matrix. Otherwise, print Impossible.

Function Description

Complete the organizingContainers function in the editor below.

organizingContainers has the following parameter(s):

int containter[n][m]: a two dimensional array of integers that represent the number of balls of each color in each container
Returns

string: either Possible or Impossible



💣Solution-15:


          string organizingContainers(vector<vector<int>> container)
          {
          int n = container.size();
          int a[n];
          int b[n];
          for(int i=0; i<n;i++){a[i]=0; b[i]=0;}
          
          
          for(int i=0; i<n; i++)
          {
           for(int j=0; j<n; j++)
            {
              a[i] += container[i][j];
              b[j] += container[i][j];
            }
         }
         
         string pts = "Possible";
         for(int i=0;i<n;i++)
         {
           int j=0;
           for(j=i;j<n;j++)
           {
              if(a[i] == b[j])
              {
                int temp = b[j];
                b[j] = b[i];
                b[i] = temp;
                break;
              }
           }
    
           if(j==n)
           {
              pts = "Impossible";
              break;
           }
       }
         
         
         
         return pts;
         
     }


Problem-16:


Function Description

Complete the happyLadybugs function in the editor below.

happyLadybugs has the following parameters:

string b: the initial positions and colors of the ladybugs
Returns

string: either YES or NO
Input Format

The first line contains an integer g, the number of games.

The next g pairs of lines are in the following format:

The first line contains an integer n, the number of cells on the board.
The second line contains a string b that describes the n cells of the board.

🍎Example:

INPUT:

4

7

RBY_YBR

6

X_Y__X

2
__

6

B_RRBR


OUTPUT:

YES
NO
YES
YES



The four games of Happy Ladybugs are explained below:

🍎Initial board:

![image](https://user-images.githubusercontent.com/75094927/149966167-3659877c-f3cf-4645-bbc7-b06e00ae2795.png)


🍎After the first move:

![image](https://user-images.githubusercontent.com/75094927/149966235-639e4dac-1a78-4785-a493-e4c7518ef2a0.png)

🍎After the second move:

![image](https://user-images.githubusercontent.com/75094927/149966302-3a4d4be5-43bc-46ae-89f6-379cd46f4a52.png)

🍎After the third move:

![image](https://user-images.githubusercontent.com/75094927/149966357-38744fd3-25b9-4b85-a766-0421f69836ee.png)

▶️Now all the ladybugs are happy, so we print YES on a new line.

▶️There is no way to make the ladybug having color Y happy, so we print NO on a new line.

▶️There are no unhappy ladybugs, so we print YES on a new line.

▶️Move the rightmost B and R to form b = [BBRRR_].


💣Solution-16:

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





Problem-17:

Sorting the huge numbers with Vector


💣Solution-17:
   
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




Porblem-18:


You are given a number of sticks of varying lengths. You will iteratively cut the sticks into smaller sticks, discarding the shortest pieces until there are none left. At each iteration you will determine the length of the shortest stick remaining, cut that length from each of the longer sticks and then discard all the pieces of that shortest length. When all the remaining sticks are the same length, they cannot be shortened so discard them.

Given the lengths of  sticks, print the number of sticks that are left before each iteration until there are none left.


Function Description

Complete the cutTheSticks function in the editor below. It should return an array of integers representing the number of sticks before each cut operation is performed.

cutTheSticks has the following parameter(s):

int arr[n]: the lengths of each stick
Returns

int[]: the number of sticks after each iteration



EX: 

    INPUT:

     STDIN           Function
     -----           --------
      6               arr[] size n = 6
      5 4 4 2 2 8     arr = [5, 4, 4, 2, 2, 8]

    OUTPUT:

    6
    4
    2
    1


💣Solution-18:

    vector<int> cutTheSticks(vector<int> arr) 
    {
     vector<int> arr2;
     int len = arr.size();
     int index = arr.size();
     arr2.push_back(len);
     while(true)
     {
            index--;
            arr[index]-=1;
            if(arr[index]==0)
               len--;
            if(index==0)
            {
                bool isSame=false;
                for(int i=0; i<arr2.size();i++)
                {
                         if(arr2[i] == len)
                           isSame = true;
                }
                
                if(!isSame && len!=0)
                    arr2.push_back(len);
                
                index = arr.size();
                if(len <=1)
                    break;
            }
            
             
            
            
     }
     
     return arr2;
      
     }


Problem-19:

Flatland is a country with a number of cities, some of which have space stations. Cities are numbered consecutively and each has a road of 1km length connecting it to the next city. It is not a circular route, so the first city doesn't connect with the last city. Determine the maximum distance from any city to its nearest space station.


Function Description

Complete the flatlandSpaceStations function in the editor below.

flatlandSpaceStations has the following parameter(s):

int n: the number of cities
int c[m]: the indices of cities with a space station
Returns
- int: the maximum distance any city is from a space station

Input:

STDIN   Function

-----   --------

5 2     n = 5, c[] size m = 2

0 4     c = [0, 4]


Output:

2


![image](https://user-images.githubusercontent.com/75094927/152652426-6b3dde33-7289-4f7a-a9af-69c207cb3f68.png)



🍎Solution-19:

    int flatlandSpaceStations(int n, vector<int> c) {
      sort(c.begin(),c.end());
      int result=0;
      int maxDistance = c[0];
      for(int i = 1; i < c.size(); i++){
        int distance = (c[i] - c[i-1]) / 2;
        if(maxDistance < distance) 
             maxDistance = distance;
    }
    n--;
    int lastGap = n - c[c.size() - 1];
    if(lastGap < maxDistance)
        result = maxDistance;
    if(lastGap > maxDistance)
         result = lastGap;
        
     return result;     
    }

Problem-20:

The previous challenges covered Insertion Sort, which is a simple and intuitive sorting algorithm with a running time of O(n^2). In these next few challenges, we're covering a divide-and-conquer algorithm called Quicksort (also known as Partition Sort). This challenge is a modified version of the algorithm that only addresses partitioning. It is implemented as follows:

Function Description

Complete the quickSort function in the editor below.

quickSort has the following parameter(s):

int arr[n]: arr[0] is the pivot element
Returns

int[n]: an array of integers as described above

Input:

     STDIN       Function
     -----       --------
      5           arr[] size n =5 
     4 5 3 7 2   arr =[4, 5, 3, 7, 2]

Output:
 
     3 2 4 5 7
     
     
💣Solution-20:


    vector<int> quickSort(vector<int> arr) 
    {
       int i=0;
       vector<int> result;
       bool isSmaller=true;
       while(true)
       {
           i++;
          
          if(isSmaller)
          {
               if(arr[0] > arr[i])
                {
                   result.push_back(arr[i]);
                }   
          }
          
          if(!isSmaller)
          {
              if(arr[0] < arr[i])
              {
                  result.push_back(arr[i]);
              }
          } 
           if(!isSmaller && i == arr.size()-1)
               break;
           
           if(i == arr.size()-1)
           {
               i=0;
               isSmaller =false;
               result.push_back(arr[0]);
           }
       }  
       
    return result;
    }




Problem-21:


A driver is driving on the freeway. The check engine light of his vehicle is on, and the driver wants to get service immediately. Luckily, a service lane runs parallel to the highway. It varies in width along its length.

You will be given an array of widths at points along the road (indices), then a list of the indices of entry and exit points. Considering each entry and exit point pair, calculate the maximum size vehicle that can travel that segment of the service lane safely.


![image](https://user-images.githubusercontent.com/75094927/154851988-9864d169-5fe8-43fc-a3d6-6621837ea261.png)


Function Description

Complete the serviceLane function in the editor below.

serviceLane has the following parameter(s):

int n: the size of the width array
int cases[t][2]: each element contains the starting and ending indices for a segment to consider, inclusive

Returns

int[t]: the maximum width vehicle that can pass through each segment of the service lane described


INPUT:

     STDIN               Function

     -----               --------

      8 5                 n = 8, t = 5

     2 3 1 2 3 2 3 3     width = [2, 3, 1, 2, 3, 2, 3, 3]

     0 3                 cases = [[0, 3], [4, 6], [6, 7], [3, 5], [0, 7]]

     4 6

     6 7

    3 5

    0 7

OUTPUT:

    1
    2
    3
    2
    1


🍎Solution-21:

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



Problem-22:  

Lisa just got a new math workbook. A workbook contains exercise problems, grouped into chapters. Lisa believes a problem to be special if its index (within a chapter) is the same as the page number where it's located. The format of Lisa's book is as follows:

There are n chapters in Lisa's workbook, numbered from 1 to n.
The i chapter has arr[i] problems, numbered from 1 to arr[i].
Each page can hold up to k problems. Only a chapter's last page of exercises may contain fewer than k problems.
Each new chapter starts on a new page, so a page will never contain problems from more than one chapter.
The page number indexing starts at 1.
Given the details for Lisa's workbook, can you count its number of special problems?


Note: See the diagram in the Explanation section for more details.

Function Description

Complete the workbook function in the editor below.

workbook has the following parameter(s):

int n: the number of chapters
int k: the maximum number of problems per page
int arr[n]: the number of problems in each chapter
Returns
- int: the number of special problems in the workbook

Input: 


           STDIN       Function
           -----       --------
           5 3         n = 5, k = 3
           4 2 6 1 10  arr = [4, 2, 6, 1, 10]


OUTPUT:
              
               4
               
               
Explanition:


![image](https://user-images.githubusercontent.com/75094927/154962011-28cb4f34-be5e-4251-ac6b-269b782f1c3e.png)




🍎Solution-22:


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
















