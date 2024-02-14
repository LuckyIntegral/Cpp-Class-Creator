
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

	for (( i = 0; i < 51 - file_length; ++i )); do
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
	local tabs=""

	# Capitalize the first letter of the name
	local capitalized_name="$(echo $name | awk '{print toupper(substr($0,1,1)) tolower(substr($0,2))}')"

	for ((t = 0; t <= 12; t += 4)); do
		if (( ${#type} < 4 + $t )); then
			tabs+="\t"
		fi
	done

	echo "	${type}${tabs}	get${capitalized_name}( void ) const;"
	echo "	void				set${capitalized_name}( const ${type} ${name} );"
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
	local filename="${1}.cpp"

	put_header "$filename"
	cat <<EOF >> "$filename"

#include "${1}.hpp"

#include <iostream>

EOF
	printf "${1}::${1}() " >> "$filename"

	if (( $# > 1 )); then
		printf ": " >> "$filename"
		for ((i = 2; i <= $#; i += 2)); do
   			local upper_arg="$(echo "${@[i + 1]}" | sed 's/\([a-z]\)\([A-Z]\)/\1_\2/g; s/\([A-Z]\)\([A-Z][a-z]\)/\1_\2/g' | tr '[:lower:]' '[:upper:]')"

			printf "_${@[i + 1]}(DEFAULT_$upper_arg)" >> "$filename"
			if (( i < $# - 1 )); then
				printf "," >> "$filename"
			fi
			printf " " >> "$filename"
		done
	fi

	echo '{}' >> "$filename"

	if (( $# > 1 )); then
		printf "${1}::${1}(" >> "$filename"
		for ((i = 2; i <= $#; i += 2)); do
			printf " ${@[i]} ${@[i + 1]}" >> "$filename"
			if (( i < $# - 1 )); then
				printf "," >> "$filename"
			fi
		done
		printf " ) " >> "$filename"

		if (( $# > 1 )); then
			printf ": " >> "$filename"
			for ((i = 2; i <= $#; i += 2)); do
				printf "_${@[i + 1]}(${@[i + 1]})" >> "$filename"
				if (( i < $# - 1 )); then
					printf "," >> "$filename"
				fi
				printf " " >> "$filename"
			done
		fi
		echo '{}' >> "$filename"
	fi

	if (( $# > 1 )); then
		printf "${1}::${1}( const ${1} &other ) " >> "$filename"
		printf ": " >> "$filename"
		for ((i = 2; i <= $#; i += 2)); do
			printf "_${@[i + 1]}(other._${@[i + 1]})" >> "$filename"
			if (( i < $# - 1 )); then
				printf "," >> "$filename"
			fi
			printf " " >> "$filename"
		done
	else
		printf "${1}::${1}( const ${1} & ) " >> "$filename"
	fi

	echo '{}' >> "$filename"
	echo "${1}::~${1}() {}" >> "$filename"
	echo '' >> "$filename"

	# Generate getter and setter functions
	for ((i = 2; i <= $#; i += 2)); do
		implement_accessors "${@[i]}" "${@[i + 1]}" "${1}" >> "$filename"
	done

	if (( $# > 1 )); then
		echo "${1} &${1}::operator=( const ${1} &other ) {" >> "$filename"
		for ((i = 2; i <= $#; i += 2)); do
			echo "	this->_${@[i + 1]} = other._${@[i + 1]};" >> "$filename"
		done
	else
		echo "${1} &${1}::operator=( const ${1} & ) {" >> "$filename"
	fi
	echo '	return (*this);' >> "$filename"
	echo "}" >> "$filename"
	echo '' >> "$filename"

	if (( $# > 1 )); then
		echo "std::ostream	&operator<<( std::ostream &stream, const ${1} &instance ) {" >> "$filename"
		echo "	stream << \"{${1}:\"" >> "$filename"
		for ((i = 2; i <= $#; i += 2)); do
			local capitalized_name="$(echo ${@[i + 1]} | awk '{print toupper(substr($0,1,1)) tolower(substr($0,2))}')"
			printf "		<< \"${@[i + 1]}=\" << instance.get${capitalized_name}()" >> "$filename"
			if (( i < $# - 1 )); then
				echo " << ','" >> "$filename"
			else
				echo " << '}';" >> "$filename"
			fi
		done
	else
		echo "std::ostream	&operator<<( std::ostream &stream, const ${1} & ) {" >> "$filename"
		echo "	stream << \"{${1}:{}}\";" >> "$filename"
	fi
	echo "	return (stream);">> "$filename"
	echo "}" >> "$filename"
}

make_hpp() {
	local filename="${1}.hpp"
	local uppercase_param="$(echo "${1}" | sed 's/\([a-z]\)\([A-Z]\)/\1_\2/g; s/\([A-Z]\)\([A-Z][a-z]\)/\1_\2/g' | tr '[:lower:]' '[:upper:]')"

	# Create the .hpp file
	put_header "$filename"
	cat <<EOF >> "$filename"

#pragma once

#ifndef ${uppercase_param}_HPP
# define ${uppercase_param}_HPP


# include <string>

EOF

	if ((2 <= $#)); then
		for ((i = 2; i <= $#; i += 2)); do
   			local upper_arg="$(echo "${@[i + 1]}" | sed 's/\([a-z]\)\([A-Z]\)/\1_\2/g; s/\([A-Z]\)\([A-Z][a-z]\)/\1_\2/g' | tr '[:lower:]' '[:upper:]')"

			echo "# define DEFAULT_$upper_arg" >> "$filename"
		done
		echo '' >> "$filename"
	fi

	echo "class ${1} {" >> "$filename"

	if ((2 <= $#)); then
		echo 'protected:' >> "$filename"
		for ((i = 2; i <= $#; i += 2)); do
			local tabs=""
			for ((t = 0; t <= 12; t += 4)); do
				if (( ${#@[i]} < 4 + $t )); then
					tabs+="\t"
				fi
			done
			echo "	${@[i]}${tabs}	_${@[i + 1]};" >> "$filename"
		done
		echo '' >> "$filename"
	fi

	echo "public:" >> "$filename"
	echo "	${1}();" >> "$filename"
	if ((2 <= $#)); then
		printf "	${1}(" >> "$filename"
		for ((i = 2; i <= $#; i += 2)); do
			printf " ${@[i]} ${@[i + 1]}" >> "$filename"
			if (( i < $# - 1 )); then
				printf "," >> "$filename"
			fi
		done
		echo " );" >> "$filename"
	fi
	echo "	${1}( const ${1} &other );" >> "$filename"
	echo "	~${1}();" >> "$filename"
	echo "" >> "$filename"

	if ((2 <= $#)); then
		for ((i = 2; i <= $#; i += 2)); do
   			declare_accessor "${@[i]}" "${@[i + 1]}" >> "$filename"
   		done
		echo '' >> "$filename"
	fi

	cat <<EOF >> "$filename"
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
