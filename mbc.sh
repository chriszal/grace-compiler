file=$(basename -s .mba $1).s
# out=$(mktemp -p --suffix .c)
out=$file
obj=$(basename -s .mba $1).o
LIB=

./minibasic < $1 > $out
as -o $obj $out
ld $obj $LIB

