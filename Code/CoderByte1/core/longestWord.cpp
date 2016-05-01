/* Using the C++ language, have the function  LongestWord(sen) 
 * take the sen parameter being passed and return the largest
 * word in the string. If there are two or more words that are 
 * the same length, return the first word from the string with 
 * that length. Ignore punctuation and assume sen will not be empty. 
*/

#include <iostream>
#include <string>

using namespace std;

string BiggestWord( string words)
{
   string biggest("");
   words.insert(words.begin(),' ');
   string::size_type pos = words.rfind(' ');
   while( pos != string::npos )
   {
      string smallest;
      smallest = words.substr(pos);
      smallest.erase(smallest.begin());
      for( int it = 0; it <= smallest.size(); it++ )
         if( ispunct(smallest[it]) )
               smallest.erase(it--,1);
      if( biggest.size() <= smallest.size() )
         biggest = smallest;
      words = words.substr(0,pos);
      pos = words.rfind(' ');
   }
   return biggest;
}

int main()
{
   string words("!!!This is the test!@#%% word for the code!!!!");
   cout << BiggestWord(words) << endl;
   return 1;
}
