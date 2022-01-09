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








