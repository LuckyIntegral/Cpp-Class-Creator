# C++ Class Generator Script

This script generates C++ class files with getters, setters, and other necessary functions.

## Install

``` bash
bash -c "$(curl -fsSL https://raw.github.com/LuckyIntegral/Cpp-Class-Creator/main/installer.sh)"
```

## Prerequisites

- Ensure that you have the required utilities installed (zsh, awk, sed, tr).

## Usage

```zsh
form <ClassName> [attributeType, attributeName] ...
```
### Options

**ClassName**: Name of the C++ class. \
**attributeType**: Type of class attribute (e.g., int, std::stringm unsigned long int). \
**attributeName**: Name of class attribute.

## Example

```zsh
form MyClass int age std::string name 'unsigned long int' bankAccount
```

## Generated Files

- MyClass.cpp: Contains the implementation of the MyClass class that follows next rules:
	- Default constructor
	- \<Optional\> All args constructor
	- Copy constructor
	- Destructor
	- Copy assignment operator '='
	- \<Optional\> Getters and setters for private atributes
	- Overload of << operator for your class
- MyClass.hpp: Contains the class declaration that has all the necessary stuff for comfort usage
	- Declaration of destructor, constructors and overload operators
	- Declaration of all the getters and setters for private atributes
	- Macroses with default values for the atributes

## Contributions

__Contributions are welcome! If you find any issues or havesuggestions for improvements, feel free to submit a pull request.__
