CPP			= c++
NAME		= megaphone
RM			= rm -rf
CPPFLAGS	= -Wall -Wextra -Werror -MD -MP -std=c++98

SRCS	=

DEPS		= $(SRCS:%.c=%.d)
OBJS		= $(SRCS:%.c=%.o)

all		: $(NAME)

$(NAME)	: ${OBJS}
		$(CPP) $(CPPFLAGS) -o $@ $^

$(OBJSDIR)/%.o	: %.c
		@mkdir -p $(dir $@)
		${CPP} ${CPPFLAGS} -c $< -o $@

clean	:
		$(RM) $(OBJSDIR)

fclean	:
		$(RM) $(OBJSDIR) $(NAME)

re		: fclean all

-include $(DEPS_B) $(DEPS)

.PHONY: all clean fclean re
