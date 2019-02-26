#if [ -f "nasteroids-seq" ]; then
#   rm -f nasteroids-seq
#fi  

#clear
echo "Compilando archivo"  
g++ file_copier.cpp -o file_copier -std=c++14 -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors

#./nasteroids2018-base_v20 5 2 8 100

#valgrind --tool=cachegrind --cachegrind-out-file=vgrind_seq_out --I1=16384,8,32 --LL=131072,8,64 --branch-sim=yes ./nasteroids-seq 5 2 8 100
#cg_annotate vgrind_seq_out --auto=yes
#./nasteroids-seq 10 250 5 2000