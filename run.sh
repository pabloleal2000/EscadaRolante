#!/bin/bash
input_dir="input/"
output_dir="output/"
echo "Compilando arquivo"
gcc main.c
echo "Testando..."
for i in `ls $input_dir`;
do
    saida=$(./a.out < $input_dir$i > out)
    diff out $output_dir$i
done
echo "Removendo executável"
rm a.out