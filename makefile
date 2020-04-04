all: fooChecker fooCheckerd debug

fooChecker: fooCheckerd
	lex fooChecker.lex
	yacc fooChecker.yacc
	gcc dataStructures/Nodes.c dataStructures/functions.c y.tab.c lex.yy.c -o fooChecker -lm


fooCheckerd: fooChecker.lex fooChecker.yacc
	lex -d fooChecker.lex
	yacc -dv fooChecker.yacc					#-v to create y.output file
	gcc dataStructures/Nodes.c dataStructures/functions.c y.tab.c lex.yy.c -o fooCheckerd -lm


debug: fooChecker 
	cp fooChecker.yacc fooChecker_debug.yacc
	sed -i 's/#define DEBUGTAG 0/#define DEBUGTAG 1/gI' fooChecker_debug.yacc
	lex fooChecker.lex
	yacc fooChecker_debug.yacc
	gcc dataStructures/Nodes.c dataStructures/functions.c y.tab.c lex.yy.c -o fooChecker_debug -lm

.PHONY: clean
clean: ;
	rm -f y.tab.c y.tab.h y.output lex.yy.c fooCheckerd fooChecker \
		fooChecker_debug fooChecker_debug.yacc

