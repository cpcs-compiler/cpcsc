CC	?= clang
CXX	?= clang++
LEX	= flex
YACC	= bison
RM	= rm -rf

CFLAGS	+= -Wall -Werror -Wextra -std=c11 `llvm-config --cflags`
LDFLAGS	+= `llvm-config --cxxflags --ldflags --libs core executionengine interpreter analysis native bitwriter --system-libs` -lfl

SRCS	= main.c \
	  utils.c \
	  color.c \
	  error.c \
	  parser.c \
	  scanner.c \
	  codegen.c
OBJS	= $(addprefix src/, $(SRCS:.c=.o))

COV_MESS = $(addprefix src/, $(SRCS:.c=.gcda)) \
			$(addprefix src/, $(SRCS:.c=.gcno))

TARGET	= cpcsc

all: $(TARGET)

debug: CFLAGS += -g -ggdb -O0 -coverage
debug: LDFLAGS += -coverage
debug: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

src/scanner.c: src/scanner.l
	$(LEX) -o $@ $^

src/parser.c: src/parser.y
	$(YACC) -o $@ -d $^

clean:
	$(RM) $(OBJS) $(COV_MESS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all debug clean fclean re
