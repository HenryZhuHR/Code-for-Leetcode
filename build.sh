OUT=test


clear
rm ${OUT}
clang++ main.cpp \
    -o ${OUT} \
    -std=c++11 \
    -Wall 
    # -Werror
    
./test