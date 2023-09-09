/*
   EXERCISE 2 - VectorMap
   Create class template VectorMap, which represents std::map.
   It should consist of two std::vector with the same size.
   First vector should store keys and second values.

   Elements at the same position in both vectors create a pair.

   If <ValueType> has not default constructor do not allow to create object.

   Implement methods: insert(), operator[], at(), isIntKey().

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
#include<type_traits>

template <typename KeyType, typename ValueType>
class VectorMap
{
   public:
      // default constructor
      VectorMap() 
      {
         static_assert(std::is_constructible<ValueType>::value, "Value type must contain default constructor!");
      };

      void insert(KeyType key, ValueType value);
      bool isIntKey();
      ValueType& at(KeyType key);
      ValueType& operator[](const KeyType key);
      

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

template <typename KeyType, typename ValueType>
bool VectorMap<KeyType, ValueType>::isIntKey()
{
   return std::is_same<int, KeyType>::value;
}



struct noDefaultConstructor
{
   noDefaultConstructor() = delete;

   int a;
};



int main()
{
   std::cout << "Templates - basics - exercise 2.\n";

   // create instance of VectorMap<int, char>
   VectorMap<int, char> mapIntChar;  
   
   mapIntChar.insert(1, 'c');
   std::cout << mapIntChar[1] << '\n';     // prints 'c'

   mapIntChar[1] = 'e';                    // replaces value under 1
   std::cout << mapIntChar[1] << '\n';     // prints 'e'
   
   mapIntChar[2] = 'g';                    // add new element of key 2 and value 'g'
   std::cout << mapIntChar[2] << '\n';     // prints 'g'
   std::cout << mapIntChar.at(2) << '\n';  // prints 'g'

   mapIntChar[99] = 'h';                    // add new element of key 99 and value 'h'
   std::cout << mapIntChar.at(99) << '\n';  // prints 'h'

   try
   {
      mapIntChar.at(100) = 'x';            // throws std::out_of_range
   }
   catch(std::out_of_range)
   {
      std::cout << "std::out_of_range catched!\n";
   }

   //VectorMap<int, noDefaultConstructor> map2;
   
   // check whether key of mapIntChar is int
   std::cout << "key of mapIntChar is integer: " << mapIntChar.isIntKey() << '\n';

   VectorMap<char, int> mapCharInt;
   // check whether key of mapCharInt is int
   std::cout << "key of mapCharInt is integer: " << mapCharInt.isIntKey() << '\n';
   

   return 0;
}