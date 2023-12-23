CPP			= c++
NAME		= hamsters
RM			= rm -rf

CPPFLAGS	= -Wall -Wextra -Werror -MD -MP -std=c++98

SRCS	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJSDIR	= objs
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.d))

all		: $(NAME)

$(NAME)	: ${OBJS}
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

.PHONY: all clean fclean re
