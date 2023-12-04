CPP			= c++
NAME		= phonebook
RM			= rm -rf

CPPFLAGS	= -Wall -Wextra -Werror -MD -MP -std=c++98

SRCS	= Contact.cpp PhoneBook.cpp main.cpp

OBJSDIR	= objs
OBJS	= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
DEPS	= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.d))

all		: $(NAME)

$(NAME)	: ${OBJS}
		$(CPP) -o $@ $^

objs/%.o: %.cpp
		@mkdir -p $(dir $@)
		${CPP} ${CPPFLAGS} -c $< -o $@

clean	:
		$(RM) $(OBJSDIR)

fclean	:
		$(RM) $(OBJSDIR) $(NAME)

re		: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
