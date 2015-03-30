#!/usr/bin/bash

d=$(date "+%d-%m-%Y-%H-%M-%S") 
a=".$1-$d.backup"

if [ -f "$a" ]
then
    exit 1
else
    cp "$1" "$a"
fi
