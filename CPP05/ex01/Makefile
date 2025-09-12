CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex01

SRCS = Bureaucrat.cpp Form.cpp  main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all