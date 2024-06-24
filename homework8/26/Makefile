target = app
obj = xshell.o m.o
cc = gcc
cflag = -Wall -g

.PHONY:
	clean

$(target): $(obj)
	$(cc) $(cflag) $^ -o $@

%.o: %.c
	$(cc) $(cflag) -c $< -o $@

clean:
	rm -rf *.o $(target)