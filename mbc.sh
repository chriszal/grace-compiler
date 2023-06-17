file=$(basename -s .mba $1).s
out=$file
obj=$(basename -s .mba $1).o
LIB=libio/lib/x86/libio.a

./minibasic < $1 > $out

# Assemble LLVM IR code to object file
llc -filetype=obj $out -o $obj

# Link object file with the IO library and create the executable
clang $obj $LIB -o output

rm $out $obj
