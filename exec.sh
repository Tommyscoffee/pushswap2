#!/bin/bash

ARGS=$(jot -s " " -r $1 -100 500)
echo $ARGS | pbcopy
# ARGS=$((RANDOM%+10000) | head $1)

./pushswap ${ARGS}
echo $ARGS