interp: interpd
	lex tchk.lex
	yacc tchk.yacc
	gcc y.tab.c lex.yy.c -o interp

interpd:	tchk.lex tchk.yacc
	lex -d tchk.lex
	yacc -d tchk.yacc
	gcc y.tab.c lex.yy.c -o interpd

clean:
	rm -f y.tab.c y.tab.h lex.yy.c interpd interp

