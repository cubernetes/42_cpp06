CXX=c++
NAME=ex02
CXXFLAGS+=-O3 -MD -std=c++98 -Werror -Wall -Wextra -pedantic-errors -Waggregate-return -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wdisabled-optimization -Wdouble-promotion -Weffc++ -Werror -Wfloat-equal -Wformat=2 -Winit-self -Wint-to-pointer-cast -Wmissing-declarations -Wmissing-include-dirs -Wnon-virtual-dtor -Wno-unused -Wnull-dereference -Wold-style-cast -Woverloaded-virtual -Wpedantic -Wpointer-arith -Wredundant-decls -Wsequence-point -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch -Wswitch-default -Wundef -Wunreachable-code -Wunused -Wwrite-strings
SRC=main.cpp Classes.cpp
OBJ=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)
all:$(NAME)
$(NAME):$(OBJ)
	$(CXX) $(LDFLAGS) $(LDLIBS) -o $@ $^
%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<
-include $(DEPS)
clean:
	$(RM) $(OBJ) $(DEPS)
fclean:clean
	$(RM) $(NAME)
re:fclean
	$(MAKE) all
.PHONY:all clean fclean re
