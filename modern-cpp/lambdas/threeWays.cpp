/* threeWays.cpp
 *
 * Check if all elements of vector
 * std::vector numbers = {18, 21, 36, 90, 27, 14, 103} 
 * are dividable by 3.
 * 
 * Use apprioprate STL algorithm.
 *
 * Implement 3 versions:
 * - lambda
 * - function
 * - functor
 */

#include <iostream>
#include <vector>
#include <algorithm>

bool isDividableBy3(const int& elem) {
   return (elem % 3) == 0;
}

struct DividableBy3
{
   bool operator()(const int& elem) {
      return (elem % 3) == 0;
   }
};

int main()
{
   std::vector numbers = {18, 21, 36, 90, 27, 14, 103};

   // first way - lambda
   // e.g. named lambda
   auto dividableBy3 = [](const auto& elem) {
      return (elem % 3) == 0;
   };

   if(std::find_if_not(numbers.begin(), numbers.end(), dividableBy3) == numbers.end()) {
      std::cout << "first way - lambda --> all elements are dividable by 3\n";
   }
   else {
      std::cout << "first way - lambda --> some element is not dividable by 3\n";
   }


   // second way - functor
   if(std::find_if_not(numbers.begin(), numbers.end(), DividableBy3()) == numbers.end()) {
      std::cout << "second way - functor --> all elements are dividable by 3\n";
   } 
   else {
      std::cout << "second way - functor --> some element is not dividable by 3\n";
   }


   // third way - function
   if(std::find_if_not(numbers.begin(), numbers.end(), isDividableBy3) == numbers.end()) {
      std::cout << "third way - function --> all elements are dividable by 3\n";
   }
   else {
      std::cout << "third way - function --> some element is not dividable by 3\n";
   }

   return 0;
}
