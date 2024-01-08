#! /bin/zsh

put_header() {
	local login_length=${#USER}
	local file_length=${#1}
	local basename="$(basename $1)"
	local login_spaces=""
	local file_spaces=""
	local formatted_date_time=$(date '+%Y/%m/%d %H:%M:%S')
	for (( i = 0; i < 8 - login_length; ++i )); do
		login_spaces+=" "
	done
	for (( i = 0; i < 55 - file_length; ++i )); do
		file_spaces+=" "
	done
	cat <<EOF > "$1"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   $basename$file_spaces:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: $USER <$USER@student.42.fr>          $login_spaces$login_spaces+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: $formatted_date_time by $USER          $login_spaces#+#    #+#             */
/*   Updated: $formatted_date_time by $USER         $login_spaces###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
EOF
}

declare_accessor() {
	local type="$1"
	local name="$2"
	local tabs

	# Capitalize the first letter of the name
	local capitalized_name="$(echo $name | awk '{print toupper(substr($0,1,1)) tolower(substr($0,2))}')"

	if [ ${#type} -le 4 ]; then
        tabs="			"
    elif [ ${#type} -le 8 ]; then
        tabs="		"
    else
        tabs="	"
    fi

	echo "	$type${tabs}get${capitalized_name}( void ) const;"
	echo "	void		set${capitalized_name}( const $type $name );"
}

implement_accessors() {
	local type="$1"
	local name="$2"
	local namespace="$3"

	# Capitalize the first letter of the name
	local capitalized_name="$(echo $name | awk '{print toupper(substr($0,1,1)) tolower(substr($0,2))}')"

	echo "$type $namespace::get${capitalized_name}( void ) const {"
	echo "	return (this->_${name});"
	echo "}\n"
	echo "void $namespace::set${capitalized_name}( const $type $name ) {"
	echo "	this->_${name} = ${name};"
	echo "}\n"
}

make_cpp() {
	local dirname="src/"
	local filename="${1}.cpp"

	mkdir -p "src"
	put_header "$dirname""$filename"
	cat <<EOF >> "$dirname""$filename"

#include "../inc/${1}.hpp"

#include <iostream>

EOF
	printf "${1}::${1}() " >> "$dirname""$filename"

	if (( $# > 1 )); then
		printf ": " >> "$dirname""$filename"
		for ((i = 2; i <= $#; i += 2)); do
   			local upper_arg="$(echo "${@[i + 1]}" | sed 's/\([a-z]\)\([A-Z]\)/\1_\2/g; s/\([A-Z]\)\([A-Z][a-z]\)/\1_\2/g' | tr '[:lower:]' '[:upper:]')"

			printf "_${@[i + 1]}(DEFAULT_$upper_arg)" >> "$dirname""$filename"
			if (( i < $# - 1 )); then
				printf "," >> "$dirname""$filename"
			fi
			printf " " >> "$dirname""$filename"
		done
	fi

	echo '{}' >> "$dirname""$filename"

	if (( $# > 1 )); then
		printf "${1}::${1}(" >> "$dirname""$filename"
		for ((i = 2; i <= $#; i += 2)); do
			printf " ${@[i]} ${@[i + 1]}" >> "$dirname""$filename"
			if (( i < $# - 1 )); then
				printf "," >> "$dirname""$filename"
			fi
		done
		printf " ) " >> "$dirname""$filename"

		if (( $# > 1 )); then
			printf ": " >> "$dirname""$filename"
			for ((i = 2; i <= $#; i += 2)); do
				printf "_${@[i + 1]}(${@[i + 1]})" >> "$dirname""$filename"
				if (( i < $# - 1 )); then
					printf "," >> "$dirname""$filename"
				fi
				printf " " >> "$dirname""$filename"
			done
		fi
		echo '{}' >> "$dirname""$filename"
	fi

	if (( $# > 1 )); then
		printf "${1}::${1}( const ${1} &other ) " >> "$dirname""$filename"
		printf ": " >> "$dirname""$filename"
		for ((i = 2; i <= $#; i += 2)); do
			printf "_${@[i + 1]}(other._${@[i + 1]})" >> "$dirname""$filename"
			if (( i < $# - 1 )); then
				printf "," >> "$dirname""$filename"
			fi
			printf " " >> "$dirname""$filename"
		done
	else
		printf "${1}::${1}( const ${1} & ) " >> "$dirname""$filename"
	fi

	echo '{}' >> "$dirname""$filename"
	echo "${1}::~${1}() {}\n" >> "$dirname""$filename"

	# Generate getter and setter functions
	for ((i = 2; i <= $#; i += 2)); do
		implement_accessors "${@[i]}" "${@[i + 1]}" "${1}" >> "$dirname""$filename"
	done

	if (( $# > 1 )); then
		echo "${1} &${1}::operator=( const ${1} &other ) {" >> "$dirname""$filename"
		for ((i = 2; i <= $#; i += 2)); do
			echo "	this->_${@[i + 1]} = other._${@[i + 1]};" >> "$dirname""$filename"
		done
	else
		echo "${1} &${1}::operator=( const ${1} & ) {" >> "$dirname""$filename"
	fi
	echo '	return (*this);' >> "$dirname""$filename"
	echo "}\n" >> "$dirname""$filename"

	if (( $# > 1 )); then
		echo "std::ostream	&operator<<( std::ostream &stream, const ${1} &instance ) {" >> "$dirname""$filename"
		echo "	stream << \"{${1}:\"" >> "$dirname""$filename"
		for ((i = 2; i <= $#; i += 2)); do
			local capitalized_name="$(echo ${@[i + 1]} | awk '{print toupper(substr($0,1,1)) tolower(substr($0,2))}')"
			printf "		<< \"${@[i + 1]}=\" << instance.get${capitalized_name}()" >> "$dirname""$filename"
			if (( i < $# - 1 )); then
				echo " << ','" >> "$dirname""$filename"
			else
				echo " << '}';" >> "$dirname""$filename"
			fi
		done
	else
		echo "std::ostream	&operator<<( std::ostream &stream, const ${1} & ) {" >> "$dirname""$filename"
		echo "	stream << \"{${1}:{}}\";" >> "$dirname""$filename"
	fi
	echo "	return (stream);">> "$dirname""$filename"
	echo "}" >> "$dirname""$filename"
}

make_hpp() {
	local filename="${1}.hpp"
	local dirname="inc/"
	local uppercase_param="$(echo "${1}" | sed 's/\([a-z]\)\([A-Z]\)/\1_\2/g; s/\([A-Z]\)\([A-Z][a-z]\)/\1_\2/g' | tr '[:lower:]' '[:upper:]')"

	mkdir -p "inc"
	# Create the .hpp file
	put_header "$dirname""$filename"
	cat <<EOF >> "$dirname""$filename"

#pragma once

#ifndef ${uppercase_param}_HPP
# define ${uppercase_param}_HPP


# include <string>

EOF

	if ((2 <= $#)); then
		for ((i = 2; i <= $#; i += 2)); do
   			local upper_arg="$(echo "${@[i + 1]}" | sed 's/\([a-z]\)\([A-Z]\)/\1_\2/g; s/\([A-Z]\)\([A-Z][a-z]\)/\1_\2/g' | tr '[:lower:]' '[:upper:]')"

			echo "# define DEFAULT_$upper_arg" >> "$dirname""$filename"
		done
		echo '' >> "$dirname""$filename"
	fi

	echo "class ${1} {" >> "$dirname""$filename"

	if ((2 <= $#)); then
		echo 'protected:' >> "$dirname""$filename"
		for ((i = 2; i <= $#; i += 2)); do
			echo "	${@[i]}	_${@[i + 1]};" >> "$dirname""$filename"
		done
		echo '' >> "$dirname""$filename"
	fi

	echo "public:" >> "$dirname""$filename"
	echo "	${1}();" >> "$dirname""$filename"
	if ((2 <= $#)); then
		printf "	${1}(" >> "$dirname""$filename"
		for ((i = 2; i <= $#; i += 2)); do
			printf " ${@[i]} ${@[i + 1]}" >> "$dirname""$filename"
			if (( i < $# - 1 )); then
				printf "," >> "$dirname""$filename"
			fi
		done
		echo " );" >> "$dirname""$filename"
	fi
	echo "	${1}( const ${1} &other );" >> "$dirname""$filename"
	echo "	~${1}();" >> "$dirname""$filename"
	echo "" >> "$dirname""$filename"

	if ((2 <= $#)); then
		for ((i = 2; i <= $#; i += 2)); do
   			declare_accessor "${@[i]}" "${@[i + 1]}" >> "$dirname""$filename"
   		done
		echo '' >> "$dirname""$filename"
	fi

	cat <<EOF >> "$dirname""$filename"
	${1} &operator=( const ${1} &other );
};

std::ostream	&operator<<( std::ostream &stream, const ${1} &instance );


#endif // ${uppercase_param}_HPP
EOF
}

form() {
	if [ -z "$1" ]; then
		echo "Usage: form <filename>"
		return 1
	fi

	if (( $# % 2 == 0 )); then
		echo "Error: The number of arguments must be not even number"
		return 1
	fi

	if [ -f src/$1.cpp ] && ! [ -w src/$1.cpp ]; then
		echo "Error: File '$1.cpp' is not writable."
	else
		make_cpp "$@"
		echo "File '$1.cpp' successfully created."
	fi

	if [ -f src/$1.hpp ] && ! [ -w src/$1.hpp ]; then
		echo "Error: File '$1.hpp' is not writable."
	else
		make_hpp "$@"
		echo "File '$1.hpp' successfully created."
	fi
}

form "$@"