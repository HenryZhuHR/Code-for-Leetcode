SRC_FILE="acm/字符串转整数数组.cpp"
FILE_NAME=$(basename ${SRC_FILE} .cpp)

mkdir -p bin
g++ "${SRC_FILE}" -o bin/${FILE_NAME} \
    -std=c++11 \
    -Wall \
    -Werror
cd bin
echo "===================="
echo "Test ${FILE_NAME}"
STRS="1,2,3,4,5"
echo $STRS | ./${FILE_NAME}
