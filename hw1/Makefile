L = cn/libcn.a
CC = gcc
IN-DIR = cn/
LS = -L cn/ -l cn



hello:hello/hello.o $(L)
	$(CC) $< -I $(IN-DIR) $(LS) -o hello.out

$(L):cn/cn.o
	ar -crv $@ $^

%.o: %.c
	$(CC) -I $(IN-DIR) -c $< -o $@
