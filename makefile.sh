#!/bin/zsh

make_makefile(){
	local filename="Makefile"
	local srcs=($(find src -type f -name '*.cpp'))

	if (( $# != 1 )); then
		echo "Usage: makegen <name_of_executable>"
		return 1
	fi

	# Create the .hpp file
	cat << EOF > "$filename"
################################################################################
######                             PROPERTIES                             ######
################################################################################

CXX			= c++
NAME		= ${1}
RM			= rm -rf

SRCS_DIR	= src
OBJS_DIR	= obj

CXXFLAGS	= -Wall -Wextra -Werror -MP -MD -std=c++98

EOF
	echo 'SRCS    = \' >> $filename

    for ((i = 0; i < ${#srcs[@]}; ++i)); do
        printf "\t\t\t${srcs[i]}" >> $filename
        if (( i < ${#srcs[@]} - 1 )); then
            printf " \\" >> $filename
        fi
        printf "\\n" >> $filename
    done

	cat << EOF >> $filename

OBJS	= \$(SRCS:\${SRCS_DIR}/%.cpp=\${OBJS_DIR}/%.o)
DEPS	= \$(OBJS:%.o=%.d)

################################################################################
######                               RULES                                ######
################################################################################

all		: \$(NAME)

run		: re
		@clear
		@./\${NAME};
		@\$(RM) \$(OBJS_DIR) \$(NAME)

test	: re
		@clear
		@.valgrind -s /\${NAME};
		@\$(RM) \$(OBJS_DIR) \$(NAME)

\$(NAME)	: \$(OBJS)
		\$(CXX) -o $@ \$^

\${OBJS_DIR}/%.o: \${SRCS_DIR}/%.cpp
		@mkdir -p \$(dir \$@)
		\${CXX} \${CXXFLAGS} -c \$< -o \$@

clean	:
		\$(RM) \$(OBJS_DIR)

fclean	:
		\$(RM) \$(OBJS_DIR) \$(NAME)

re		: fclean all

-include \$(DEPS)

.PHONY: all clean fclean re run
EOF
}

make_makefile "$@"
