#! /usr/bin/zsh

declare_accessor() {
    local type="$1"
    local name="$2"

    # Capitalize the first letter of the name
    local capitalized_name="$(echo $name | awk '{print toupper(substr($0,1,1)) tolower(substr($0,2))}')"

    echo "	$type get${capitalized_name}( void ) const;"
    echo "	void set${capitalized_name}( const $type $name );"
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

	cat <<EOF > "$filename"

#include "${1}.hpp"

#include <iostream>

EOF
	echo -n "${1}::${1}() " >> "$filename"

    if (( $# > 1 )); then
        echo -n ": " >> "$filename"
        for ((i = 2; i <= $#; i += 2)); do
   			local upper_arg="$(echo "${@[i + 1]}" | sed 's/\([a-z]\)\([A-Z]\)/\1_\2/g; s/\([A-Z]\)\([A-Z][a-z]\)/\1_\2/g' | tr '[:lower:]' '[:upper:]')"

            echo -n "_${@[i + 1]}(DEFAULT_$upper_arg)" >> "$filename"
            if (( i < $# - 1 )); then
                echo -n "," >> "$filename"
            fi
            echo -n " " >> "$filename"
        done
    fi

	echo '{}' >> "$filename"

    if (( $# > 1 )); then
		echo -n "${1}::${1}(" >> "$filename"
		for ((i = 2; i <= $#; i += 2)); do
    	    echo -n " ${@[i]} ${@[i + 1]}" >> "$filename"
			if (( i < $# - 1 )); then
    	        echo -n "," >> "$filename"
    	    fi
    	done
		echo -n " ) " >> "$filename"

    	if (( $# > 1 )); then
    	    echo -n ": " >> "$filename"
    	    for ((i = 2; i <= $#; i += 2)); do
    	        echo -n "_${@[i + 1]}(${@[i + 1]})" >> "$filename"
    	        if (( i < $# - 1 )); then
    	            echo -n "," >> "$filename"
    	        fi
    	        echo -n " " >> "$filename"
    	    done
    	fi
		echo '{}' >> "$filename"
	fi

    if (( $# > 1 )); then
		echo -n "${1}::${1}( const ${1} &other ) " >> "$filename"
        echo -n ": " >> "$filename"
        for ((i = 2; i <= $#; i += 2)); do
            echo -n "_${@[i + 1]}(other._${@[i + 1]})" >> "$filename"
            if (( i < $# - 1 )); then
                echo -n "," >> "$filename"
            fi
            echo -n " " >> "$filename"
        done
    else
		echo -n "${1}::${1}( const ${1} & ) " >> "$filename"
	fi

	echo '{}' >> "$filename"
	echo "${1}::~${1}() {}\n" >> "$filename"

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
	echo "}\n" >> "$filename"

	if (( $# > 1 )); then
		echo "std::ostream	&operator<<( std::ostream &stream, const ${1} &instance ) {" >> "$filename"
		echo "	stream << \"{${1}:\"" >> "$filename"
		for ((i = 2; i <= $#; i += 2)); do
		    local capitalized_name="$(echo ${@[i + 1]} | awk '{print toupper(substr($0,1,1)) tolower(substr($0,2))}')"
            echo -n "		<< \"${@[i + 1]}=\" << instance.get${capitalized_name}()" >> "$filename"
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
    cat <<EOF > "$filename"

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
        	echo "	${@[i]}	_${@[i + 1]};" >> "$filename"
    	done
		echo '' >> "$filename"
	fi

	echo "public:" >> "$filename"
	echo "	${1}();" >> "$filename"
	if ((2 <= $#)); then
		echo -n "	${1}(" >> "$filename"
		for ((i = 2; i <= $#; i += 2)); do
        	echo -n " ${@[i]} ${@[i + 1]}" >> "$filename"
			if (( i < $# - 1 )); then
                echo -n "," >> "$filename"
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

	make_cpp "$@"
    echo "File '$1.cpp' successfully created."
	make_hpp "$@"
    echo "File '$1.hpp' successfully created."

    git add "$1.cpp" "$1.hpp"
}

form "$@"
