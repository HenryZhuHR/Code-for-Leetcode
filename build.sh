FILE=dynamic-programming/_01背包问题


# clear
rm ${FILE}
g++ "${FILE}.cpp" -o ${FILE} \
    -std=c++11 \
    -Wall \
    -Werror
    
./${FILE}