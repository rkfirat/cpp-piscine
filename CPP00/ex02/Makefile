CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Account

SRCS = Account.cpp  tests.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all