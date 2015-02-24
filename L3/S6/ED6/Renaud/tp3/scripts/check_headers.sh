#! /usr/bin/bash

check(){
    for i in `find $1 -name "*.c"`; do
        name=${i%.c}
        nn=`basename "$name.h"`
        if [[ ! -e "$name.h" ]]; then
            echo -e "le fichier $name.c n'a pas de header"
            touch $name.h
            cat "$name.c" > $name.h.tmp
            echo -e "#include \"$nn\"" > "$name.c"
            cat "$name.h.tmp" >> $name.c
            rm $name.h.tmp
        else
            r=`cat "$name.c" | grep "#include \"$nn\""`

            if [ "$r" == "" ]; then
                echo -e "le fichier $name.c n'a pas de ligne #include \"$nn\""
            fi
        fi
    done
}

check $*
