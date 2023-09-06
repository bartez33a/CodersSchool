/*
   EXERCISE 2 - VectorMap
   Create class template VectorMap, which represents std::map.
   It should consist of two std::vector with the same size.
   First vector should store keys and second values.

   Elements at the same position in both vectors create a pair.

   Implement methods: insert(), operator[], at().

   Duplicates are allowed.

   Example of usage:
   VectorMap<int, char> map;
   map.insert(1, 'c');
   map[1] = 'e';        // replaces value under 1
   std::cout << map[i]; // prints 'e'
   map.at(2);           // throw std::out_of_range
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename KeyType, typename ValueType>
class VectorMap
{
   public:
      // default constructor
      VectorMap() {};

      void insert(KeyType key, ValueType value);
      ValueType& operator[](const KeyType key);
      ValueType& at(KeyType key);

   private:
      std::vector<KeyType> keys;
      std::vector<ValueType> values;
};

template <typename KeyType, typename ValueType>
void VectorMap<KeyType, ValueType>::insert(KeyType key, ValueType value)
{
   keys.push_back(key);
   values.push_back(value);
}

template <typename KeyType, typename ValueType>
ValueType& VectorMap<KeyType, ValueType>::operator[](const KeyType key)
{
   // find first occurence
   auto iter = std::find(keys.begin(), keys.end(), key);

   // if key is not found
   if(iter == keys.end())
   {
      this->insert(key, ValueType{});
      iter = keys.end() - 1;
   }
   
   ptrdiff_t index = iter - keys.begin();

   return values[index];
}

template <typename KeyType, typename ValueType>
ValueType& VectorMap<KeyType, ValueType>::at(KeyType key)
{
   // find first occurence
   auto iter = std::find(keys.begin(), keys.end(), key);

   if(iter == keys.end())
   {
      throw std::out_of_range("VectorMap out of range");
   }

   ptrdiff_t index = iter - keys.begin();

   return values[index];
}



int main()
{
   std::cout << "Templates - basics - exercise 2.\n";

   // create instance of VectorMap<int, char>
   VectorMap<int, char> map;  
   
   map.insert(1, 'c');
   std::cout << map[1] << '\n';     // prints 'c'

   map[1] = 'e';                    // replaces value under 1
   std::cout << map[1] << '\n';     // prints 'e'
   
   map[2] = 'g';                    // add new element of key 2 and value 'g'
   std::cout << map[2] << '\n';     // prints 'g'
   std::cout << map.at(2) << '\n';  // prints 'g'

   map[99] = 'h';                    // add new element of key 99 and value 'h'
   std::cout << map.at(99) << '\n';  // prints 'h'

   try
   {
      map.at(100) = 'x';            // throws std::out_of_range
   }
   catch(std::out_of_range)
   {
      std::cout << "std::out_of_range catched!\n";
   }

   return 0;
}