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

gcc main.c -wall -Werror -o main
-wall = all the warnings enable
-werror = all the errors enable

Debugging techniques :-
        1. printf debugging
            #define DEBUG 0
                #if DEBUG
               #endif
        2. delta debugging
        
 #segementation fault :- 

      int main()
      {
        int *ptr = NULL;
        printf("%d", *ptr);     //segmentaion fault 
        
        int a[10];
        a[10000] = 7;  //segmentaion fault 
        
        a[11] = 7;  //stack smashing detected. core dumped
        
        
        A buffer overflow is dangerous, so the compiler uses various protection mechanisms to guard against it. One such mechanism is a canary. A canary is a randomly generated      value, ​and in the case of a buffer overflow, the canary is overwritten; when, upon comparison with the known value, the compiler detects that the stack was compromised it     throws the stack smashing detected error.
      }
        
     #GDB:-
     
     version - 8.2
     valgrind version - 3.13.0
    
      gdb?-commands :- 
      
      
        gdb ./exe
        (gdb) start
        (gdb) list With no argument, lists ten more lines after or around previous listing. "list -" lists the ten lines before a previous ten-line listing. One argument specifies a          line, and ten lines are listed around that line
        (gdb) next    //next line of source code
         (gdb) n     //next line
         (gdb) step   //step into whats happening a fun at line n
         (gdb) list   //source code of fun
         (gdb) finish
         (gdb) continue
         (gdb) quit
         
         
         gcc -g // -g is enabling debugging symbols 
                // to use gdb -g as argumnet
                
                
 ====================================================================================================================================================         
                
       => printing values and listing source code -
              
              gdb ./exe
        (gdb) start
        (gdb) list 
        (gdb) next    //next line of source code
         (gdb) n     //next line
         (gdb) step   //step into whats happening a fun at line n
         (gdb) list
         (gdb) print value
         (gdb) print newpair->value
                0
          (gdb) next
          (gdb) print newpair->value
               12
          (gdb) print &newpair
          (gdb) print *(newpair).key
          (gdb) print *(newpair).value
          (gdb) print newpair->value
          (gdb) print newpair->key
          
          
  => finding out a variable with whatis
      (gdb) whatis newpair
           type = pair_t
           
           
  => gdb text user interface
      gdb --tui ./exe
      
      
  ====================================================================================================================================================
  
  #breakpoints :-   gdb --tui ./exe
                    (gdb) start
                    (gdb) n
                    (gdb) br 10
                    (gdb) continue
                    (gdb) continue
                    (gdb) br 11
                    (gdb) info breakpoints
                    (gdb) delte 3   //delete br at 3 
                    (gdb) info breakpoints
                    (gdb) br main  // break pt at main fn
                    (gdb) start
                    (gdb) br printf
  
 #Conditional Breakpoints :- br 9 if i > 998. 
    
==============================================================================================================================================================================
# watching variables :- 
    
              (gdb) watch counter
                   hardware watch counter : 3
                   
                   
 # Call Stacks /:- 
            keeps track of execution of funntion in our program.
            
            
            
            int addandsquare(int a, int b)
            {
             return(square(add(a,b)));
            }
            
            int main()
            {
               addandSquare(i,j);
            }
    
# Rerunning and reviwing software :- 
           (gdb) file ./exe
                load new symbols from table"
           (gdb) enable    //enable break points
           (gdb) disable   //disable break point
        
  # calling functions :- 
  
        (gdb) call add(6,7);
        (gdb) call square(6);
        
        
 # attaching the debugger to the running process
    
        list of process running inifintely

       ps aux | grep "infinite"
       sudo gdb -p 1234
       
       
  # core dumped by gdb
    core files : snapshots of a program's memory when it crashed.
    look into the directory for core files. ls -al
    gcore - generates a core files of the running program.
             ./infinte &  //run program in background
              14062
              sudo gcore 14062 //creates core file of the program
              kill 14062
              gdb -c core.14062   //open core file with gdb
              
  # redirecting output to other terminal

     (gdb) run
     (gdb) tty /dev/pts/3
     
     
     
  # writing your own command in gdb

    (gbd) define log
     -> print i
     -> print j
     -> print spc
     ->end
      (gdb) log
       
       
   # gdb scripts:-
    
     vim ~/gdbinit
     (gdb) log
     
     
   # reverse debugging :- 
     (gdb) target record-full
     (gdb) next
     (gdb) next
     (gdb) reverse-next
   
   # set a variable value

   (gdb) set var i = 900; 
   
   
   
   
   
   
   =======================================================================================================================================================================

# valgrind 



valgrind ./exe
valgring --leak-full=check ./exe 
   => has heap summary
   => leak summary
   
   
   
# gdb extra features   
   
g0 produces no debug information

-g1 produces some information, but no line numbers

-g2 is the default level that we have been using (same as -g). We get line numbers, symbols, file information at this level.

-g3 can include further information such as macros

-ggdb produces debug information specific to gdb. This is like -g3, and will try to generate as much information as possible.

This can be very handy if you really have a tough problem to debug.
