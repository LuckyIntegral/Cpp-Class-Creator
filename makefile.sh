
make_makefile() {
	local filename="Makefile"
	local srcs=($(find . -type f -name "*.cpp" | awk '{print substr($0, 3)}'))

	if (( $# != 1 )); then
		echo "Usage: makegen <name_of_executable>"
		return 1
	fi

	# Create the .hpp file
	cat << EOF > "$filename"
CXX			= c++
NAME		= ${1}
RM			= rm -rf

OBJS_DIR	= obj

CXXFLAGS	= -Wall -Wextra -Werror -MP -MD -std=c++98 -g
MAKEFLAGS	= -j\$(nproc)

EOF
	echo 'SRCS    = \' >> $filename

    for ((i = 1; i <= ${#srcs}; ++i)); do
        printf "\t\t${srcs[i]}" >> $filename
        if (( i != ${#srcs} )); then
            printf " \\" >> $filename
        fi
        printf "\\n" >> $filename
    done

	cat << EOF >> $filename

OBJS	= \$(SRCS:%.cpp=\${OBJS_DIR}/%.o)
DEPS	= \$(OBJS:%.o=%.d)

all		: \$(NAME)

run		:
		\$(RM) \$(OBJS_DIR) \$(NAME)
		@make --no-print-directory all
		@clear
		@./\${NAME};
		@\$(RM) \$(OBJS_DIR) \$(NAME)

test	:
		\$(RM) \$(OBJS_DIR) \$(NAME)
		@make --no-print-directory all
		@clear
		@valgrind -s ./\${NAME};
		@\$(RM) \$(OBJS_DIR) \$(NAME)

\$(NAME)	: \$(OBJS)
		\$(CXX) -o \$@ \$^

\${OBJS_DIR}/%.o: %.cpp
		@mkdir -p \$(dir \$@)
		\${CXX} \${CXXFLAGS} -c \$< -o \$@

clean	:
		\$(RM) \$(OBJS_DIR)

fclean	:
		\$(RM) \$(OBJS_DIR) \$(NAME)

re		:
		\$(RM) \$(OBJS_DIR) \$(NAME)
		@make --no-print-directory all


-include \$(DEPS)

.PHONY: all clean fclean re run test
EOF
}

make_makefile "$@"
