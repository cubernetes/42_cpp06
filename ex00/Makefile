CXX=c++
NAME=ex00
CXXFLAGS+=-O3 -MD -std=c++98 -Werror -Wall -Wextra -pedantic-errors -Waggregate-return -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wdisabled-optimization -Wdouble-promotion -Weffc++ -Werror -Wfloat-equal -Wformat=2 -Winit-self -Wint-to-pointer-cast -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wnon-virtual-dtor -Wno-unused -Wnull-dereference -Wold-style-cast -Woverloaded-virtual -Wpedantic -Wpointer-arith -Wredundant-decls -Wsequence-point -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch -Wswitch-default -Wundef -Wunreachable-code -Wunused -Wunused-but-set-parameter -Wwrite-strings
SRC=main.cpp ScalarConverter.cpp
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
