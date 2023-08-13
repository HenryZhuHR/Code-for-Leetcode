SRC_FILE="acm/不固定长度的整型数组输入.cpp"
FILE_NAME=$(basename ${SRC_FILE} .cpp)

mkdir -p bin
g++ "${SRC_FILE}" -o bin/${FILE_NAME} \
    -std=c++11 \
    -Wall \
    -Werror
cd bin
echo "===================="
echo "Test ${FILE_NAME}"
ARRAY="1 2 3 4 5"
echo $ARRAY | ./${FILE_NAME}
