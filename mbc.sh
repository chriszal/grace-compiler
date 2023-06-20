file=$(basename -s .mba $1).ll
fileS=$(basename -s .mba $1).s
# out=$(mktemp -p --suffix .c)
out=$file
obj=$(basename -s .mba $1).o
LIB=minibasic.a

./minibasic < $1 > $out
llc $out -o $fileS
clang $fileS $LIB -o a.out
