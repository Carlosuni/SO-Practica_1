#!/bin/sh
# This is a comment!



# Parametros de entrada
# numAsteroides = 5;
# numIteraciones = 200;
# numPlanetas = 8;
# semilla = 100;

#if [ -f "nasteroids-seq" ]; then
#   rm -f nasteroids-seq
#fi  
#if [ -f "init_conf.txt" ]; then
#    rm -f init_conf.txt
#fi  
#if [ -f "out.txt" ]; then
#    rm -f out.txt
#fi  
#clear
 
#g++ main.cpp -o nasteroids-seq -std=c++14 -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors

#./nasteroids2018-base_v20 5 2 8 100

#valgrind --tool=cachegrind --cachegrind-out-file=vgrind_seq_out --I1=16384,8,32 --LL=131072,8,64 --branch-sim=yes ./nasteroids-seq 5 2 8 100
#cg_annotate vgrind_seq_out --auto=yes
#./nasteroids-seq 10 250 5 2000

clear

#echo "Compilando archivo mycat"
#gcc -Wall -Werror -std=c11 -o mycat mycat.c
#echo "Ejecutando archivo mycat"
#./mycat p1_tests/f1.txt

#echo "Compilando archivo myls"
#gcc -Wall -Werror -std=c11 -o myls myls.c
#echo "Ejecutando archivo myls"
#./myls p1_tests/

echo "Compilando archivo mysize"
gcc -Wall -Werror -std=c11 -o mysize mysize.c
echo "Ejecutando archivo mysize"
./mysize p1_tests/