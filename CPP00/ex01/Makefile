CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PhoneBook

SRCS = Contact.cpp  PhoneBook.cpp  main.cpp  String.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all