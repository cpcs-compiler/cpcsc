CPCSC	= ../cpcsc
LD	?= ld
RM	= rm -rf

all: helloworld window

helloworld: helloworld.o
	$(LD) -o $@ $^ -lcpsc_runtime

helloworld.o: helloworld.cpc
	$(CPCSC) -o $@ $^

window: window.o
	$(LD) -o $@ $^ -lcpsc_runtime

window.o: window.cpc
	$(CPCSC) -o $@ $^

clean:
	$(RM) *.o

fclean: clean
	$(RM) helloworld loop window

re: fclean all

.PHONY: all clean fclean re
