CC=clang
CFLAGS=-g -Wall
BIN=Nepse 
all: ${BIN}
%: %.c
	${CC} ${CFLAGS} $< -o $@ -lcurl
clean:
	${RM} -rf ${BIN} *.dSYM