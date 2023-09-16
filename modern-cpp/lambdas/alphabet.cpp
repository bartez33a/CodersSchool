/*
 * Create lambda that returns consecutive alphabet letters for each call starting from 'a'.
 * When it reaches 'z' it should return capital letters 'A' - 'Z' and then small letters again.
 * Do not use external variables.
*/

#include <iostream>

int main()
{
   auto alphabet = [letter = 'a', shouldBeCapital = 0] () mutable{
      char ret = letter++;
      
      if (letter > 'z' && shouldBeCapital == 0)
      {
         letter = 'A';
         shouldBeCapital = 1;
      }
      else if (letter > 'Z' && shouldBeCapital == 1)
      {
         letter = 'a';
         shouldBeCapital = 0;
      }

      return ret;
   };

   const unsigned int numOfLetters = 'z' - 'a' + 1;
   // print all letters (small or capital) six times
   for(int i = 1; i <= (numOfLetters * 6); ++i)
   {
      std::cout << alphabet() << " ";

      // add new line character after 'z' and 'Z'
      if((i % numOfLetters) == 0)
      {
         std::cout << '\n';
      }
   }

   return 0;
}
