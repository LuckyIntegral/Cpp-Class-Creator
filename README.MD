# C++ Class Generator Script

This script generates C++ class files with getters, setters, and other necessary functions.

## Prerequisites

- Ensure that you have the required utilities installed (e.g., awk, sed, tr).

## Usage

```zsh
./form.sh <class_name> [attribute_type attribute_name ...]
```
### Options

**class_name**: Name of the C++ class. \
**attribute_type**: Type of class attributes (e.g., int, std::string). \
**attribute_name**: Name of class attributes.

## Example

```zsh
./form.sh MyClass int age std::string name
```

## Generated Files

- MyClass.cpp: Contains the implementation of the MyClass class that follows next rules:
	- Default constructor with default init list
	- \<Optional\> All args constructor
	- Copy constructor with apropriate init list
	- Destructor
	- Copy assignment operator '='
	- \<Optional\> Getters and setters for protected atributes
	- Overload of << operator for your class
- MyClass.hpp: Contains the class declaration that has all the necessary stuff for comfort usage

## Features

1. Automatic generation of getter and setter functions.
2. Initialization list for class attributes (optional).
3. Error Handling
4. The script performs basic error checking for the correct number of arguments.

## Contributions

__Contributions are welcome! If you find any issues or havesuggestions for improvements, feel free to submit a pull request.__

