## Qapla'

A first stab at creating a programming language interpreter, using lexical analyze LEX, YACC parser and C.  

*April 16: Already 18 clones in 1 day, wow thanks for the love! Please fork and/or leave a star!*
______________________________

![Foo demo gif](https://github.com/bringbackthedog/Qapla/blob/master/foodemo.gif)



### Program description:  
This is an interactive interpreter for the fooish language.

Check out a quick demo [here](https://youtu.be/WjKr9tP_h-o) 

INSTALLATION
--------------------
- run `makefile`, located in `src/` 
- execute program by running `./src/fooChecker` 
- the grammar is detailed in `src/y.output` (auto generated) 
- To exit the interpreter, type: `exit`

[optional] 
   I've added the following files for different levels of debugging and
   informative messages. 

   - fooCheckerd
   - fooChecker_debug
   - fooChecker_debug_full


FEATURES
-----------

- Working features

   - comments
   - assignment statements
   - variables
   - I/O : typechecked. reads, readi, readr, print
   - string expressions
      -  including syntax, literals, escape sequences for " and \,
         comparison operators, concatenation
   - arithmetic expressions : + - * / , correct precedence and associativity,
      typechecking  
   - boolean expressions
      - syntax, literals T and F, the comparison operators, 
         compound operators (AND OR NOT), typechecking
   - selection 
      - syntax, the use of if, else-if, else, the boolean test 
          expressions, local block scope
   - function handling 
      - syntax, function definitions and calls, local variables/scope, 
         proper handling of parameters and return values


- Non working features [ To be developed  ]  
   - string expressions
      - substring operators
   - arithmetic expressions
      -  MOD, and ^ 
   - iteration 
      - while loops are not implemented 
      
      
      
