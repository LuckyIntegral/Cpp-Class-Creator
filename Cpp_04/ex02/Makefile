CPP			= c++
NAME		= zoo
RM			= rm -rf

CPPFLAGS	= -Wall -Wextra -Werror -MD -MP -std=c++98

SRCS	= Dog.cpp Cat.cpp Animal.cpp Brain.cpp main.cpp

OBJS_DIR	= objs
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.d))

all		: $(NAME)

run		: re
		@clear; echo "\nLogs:\n"
		@./${NAME};
		@$(RM) $(OBJS_DIR) $(NAME)

test	: re
		@clear
		@valgrind ./${NAME};
		@$(RM) $(OBJS_DIR) $(NAME)

$(NAME)	: $(OBJS)
		$(CPP) -o $@ $^

objs/%.o: %.cpp
		@mkdir -p $(dir $@)
		${CPP} ${CPPFLAGS} -c $< -o $@

clean	:
		$(RM) $(OBJS_DIR)

fclean	:
		$(RM) $(OBJS_DIR) $(NAME)

re		: fclean all

-include $(DEPS)

.PHONY: all clean fclean re run test
