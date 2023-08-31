#include <iostream>
#include <complex>

template <typename T1, typename T2>
std::complex<T1> makeComplex(T1 first, T2 second)
{
   return std::complex<T1>{first, static_cast<T1>(second)};
}

int main()
{
   std::cout << "Hello CMake!\n";

   std::complex<int> a = makeComplex(4, 5);
   std::cout << a.real() << ", " << a.imag() << '\n';

   std::complex<double> b = makeComplex(3.1, 2.2);
   std::cout << b.real() << ", " << b.imag() << '\n';

   std::complex<int> c = makeComplex(1, 5.1);
   std::cout << c.real() << ", " << c.imag() << '\n';

   std::cout << 1 << " " << double(1.1) << '\n';

   return 0;
}