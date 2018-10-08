#!/bin/bash
# -*- ENCODING: UTF-8 -*-
gcc modulall.c maintest.c -o modulall -Wall
echo "*********************************************************"
echo "./modulall -a Hola parametro.c -b chau definiciones.c"
echo "*********************************************************"
./modulall -a Hola parametro.c -b chau definiciones.c
echo "*********************************************************"
echo "./modulall modulo.c saludo.c chua.c -def1 nada -def2 todo"
echo "*********************************************************"
./modulall modulo.c saludo.c chua.c -def1 nada -def2 todo
gcc modulall.c maintest.c -o otronombre -Wall
echo "*********************************************************"
echo "./otronombre -a Hola parametro.c -path file1/file2 def.c"
echo "*********************************************************"
./otronombre -a Hola parametro.c -path file1/file2 def.c
exit
