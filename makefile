
fooChecker: fooCheckerd
	lex fooChecker.lex
	yacc fooChecker.yacc
	gcc y.tab.c lex.yy.c -o fooChecker


fooCheckerd: fooChecker.lex fooChecker.yacc
	lex -d fooChecker.lex
	yacc -d fooChecker.yacc
	gcc y.tab.c lex.yy.c -o fooCheckerd

.PHONY: clean
clean: ;
	rm -f y.tab.c y.tab.h lex.yy.c fooCheckerd fooChecker

