#! /bin/bash

cd $HOME
rm -rf cpp_class_creator

mkdir cpp_class_creator_tmp
cd cpp_class_creator_tmp

git clone https://github.com/LuckyIntegral/Cpp-Class-Creator.git cpp_class_creator

cp -r cpp_class_creator $HOME

cd $HOME
rm -rf cpp_class_creator_tmp

cd $HOME/cpp_class_creator
chmod +x $HOME/cpp_class_creator/form.sh
chmod +x $HOME/cpp_class_creator/makefile.sh

RC_FILE=$HOME/.zshrc

if [[ "$SHELL" == *"bash"* ]]; then
    RC_FILE="$HOME/.bashrc"
elif [[ "$SHELL" == *"zsh"* ]]; then
    RC_FILE="$HOME/.zshrc"
fi

if ! grep "form=" $RC_FILE &> /dev/null; then
	echo "form alias not present"
	echo "Adding alias in file: $RC_FILE"
	echo -e "\nalias form=\"bash $HOME/cpp_class_creator/form.sh\"\n" >> $RC_FILE
fi

if ! grep "makegen=" $RC_FILE &> /dev/null; then
	echo "makegen alias not present"
	echo "Adding alias in file: $RC_FILE"
	echo -e "\nalias makegen=\"bash $HOME/cpp_class_creator/makefile.sh\"\n" >> $RC_FILE
fi

exec $SHELL
