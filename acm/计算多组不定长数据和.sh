SRC_FILE="acm/计算多组不定长数据和.cpp"
FILE_NAME=$(basename ${SRC_FILE} .cpp)

mkdir -p bin
g++ "${SRC_FILE}" -o bin/${FILE_NAME} \
    -std=c++11 \
    -Wall \
    -Werror
cd bin
echo "===================="
echo "Test ${FILE_NAME}"
ARRAY1="1 2 3\n"
ARRAY2="4 5\n"
ARRAY3="0 0 0 0 0"
echo $ARRAY1 $ARRAY2 $ARRAY3 | ./${FILE_NAME}
 