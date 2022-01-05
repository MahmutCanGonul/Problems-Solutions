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



Solution-6:



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





