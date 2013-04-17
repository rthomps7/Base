#!/bin/bash

echo "source \$HOME/Base/config/bash/bashrc" >> $HOME/.bashrc
echo "source \$HOME/Base/config/bash/bash_aliases" >> $HOME/.bashrc
echo "source \$HOME/Base/config/vim/vimrc" >> $HOME/.vimrc
cp -r $HOME/Base/config/vim/vimfiles $HOME/.vim
