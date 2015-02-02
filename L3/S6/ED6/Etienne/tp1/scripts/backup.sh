#!/bin/bash
a=".$1.backup"
if [ -f "$a" ]
  then exit 1
else
  cp $1 $a
fi
