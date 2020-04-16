all: fooChecker fooChecker_debug fooChecker_debug_full fooCheckerd 

fooChecker: fooCheckerd
	lex fooChecker.lex
	yacc fooChecker.yacc
	gcc dataStructures/Nodes.c dataStructures/functions.c y.tab.c lex.yy.c -o fooChecker -lm


fooCheckerd: fooChecker.lex fooChecker.yacc dataStructures/Nodes.c dataStructures/functions.c 
	lex -d fooChecker.lex
	yacc -dv fooChecker.yacc					#-v to create y.output file
	gcc dataStructures/Nodes.c dataStructures/functions.c y.tab.c lex.yy.c -o fooCheckerd -lm

#Create full debug file file with both custom and yacc debug output
fooChecker_debug_full: fooChecker_debug
	lex -d fooChecker.lex
	yacc -d fooChecker_debug.yacc
	gcc dataStructures/Nodes.c dataStructures/functions_debug.c y.tab.c lex.yy.c -o fooChecker_debug_full -lm

#Create debug file with custom debug info (ie: rules used)
fooChecker_debug: fooChecker.lex fooChecker_debug.yacc dataStructures/Nodes.c dataStructures/functions.c 
	lex fooChecker.lex
	yacc fooChecker_debug.yacc
	gcc dataStructures/Nodes.c dataStructures/functions_debug.c y.tab.c lex.yy.c -o fooChecker_debug -lm


#Copy yacc file and switch DEBUGTAG to 1 
fooChecker_debug.yacc: fooChecker.yacc dataStructures/functions.c
	cp fooChecker.yacc fooChecker_debug.yacc
	cp dataStructures/functions.c dataStructures/functions_debug.c
	sed -i 's/#define DEBUGTAG 0/#define DEBUGTAG 1/gI' fooChecker_debug.yacc
	sed -i 's/#define FUNCDEBUG 0/#define FUNCDEBUG 1/gI' dataStructures/functions_debug.c
	

.PHONY: clean
clean: ;
	rm -f y.tab.c y.tab.h y.output lex.yy.c fooCheckerd fooChecker  \
		fooChecker_debug fooChecker_debug_full fooChecker_debug.yacc \
		dataStructures/functions_debug.c

