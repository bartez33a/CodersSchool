/*
   Create function makeComplex(), that creates complex number from two numbers. 
   If their types are different, it should create complex number which type 
   is the same as first parameter of function. 
*/


#include <iostream>
#include <complex>

template <typename T1, typename T2>
std::complex<T1> makeComplex(T1 first, T2 second)
{
   return std::complex<T1>{first, static_cast<T1>(second)};
}

int main()
{
   std::cout << "Templates - basics - exercise 1.\n";

   std::complex<int> a = makeComplex(4, 5);
   std::cout << "std::complex of type integer: " << a.real() << ", " << a.imag() << '\n';

   std::complex<double> b = makeComplex(3.1, 2.2);
   std::cout << "std::complex of type double: " << b.real() << ", " << b.imag() << '\n';

   std::complex<int> c = makeComplex(1, 5.1);
   std::cout << "std::complex of type integer: " << c.real() << ", " << c.imag() << '\n';

   return 0;
}