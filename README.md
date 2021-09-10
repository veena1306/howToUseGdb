# howToUseGdb

Debugging :- 

  Compile Time Debugging :-                                                  Run Time Debugging 
          1. before our program runs.                                                    1. while our program runs.
          2. static assert                                                               2. memory leaks        
          3. compiler                                                                    3. segmentation faults
          4. conservative                                                                4. exceptions
                            

Compile Erros :-
  1. Syntax erros
  2. uninitialized variables.
  3. accesiing a varible out of scope.
  4. lvalue required as left operand of assignment
  5. assert checked at compile time.
  6. static_assert checked at run time.
  
  
  using namespace std;


int main()
{
   assert(1 == 2 && "yes, maths is working"); //      a.out: main.cpp:17: int main(): Assertion `1 == 2 && "yes, maths is working"' failed.(core dumped)
   static_assert(1 == 2 && "yes, maths is working");   // main.cpp:17:3: error: static assertion failed
                                                         static_assert(1 == 2 && "yes, maths is working");
  
}
