#1 Which lambdas are correct?
1 []() -> int {return 4;};	OK
2 int []() {return 4;};		NOK
3 auto [](){ return4;};		NOK
4 []() -> auto {return 4;};	OK
5 [](){return 4;};		NOK
6 [] {return 4;};		??
7 [] mutable {return 4;};	??
8 [] -> int { return 4;};	??
9 int []{ return 4;};		??



#2 Which capture lists are correct?
1 [=, this]		NOK
2 [&, this]		NOK
3 [this, *this]		NOK
4 [&, &a]		OK
5 [&, a]		OK
6 [&, a, &b]		OK
7 [=, a, &b] 		OK
8 [=, &a]		OK
9 [=, *a]		NOK

 



