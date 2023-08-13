SRC_FILE="acm/字符串输入.cpp"
FILE_NAME=$(basename ${SRC_FILE} .cpp)

mkdir -p bin
g++ "${SRC_FILE}" -o bin/${FILE_NAME} \
    -std=c++11 \
    -Wall \
    -Werror
cd bin
echo "===================="
echo "Test ${FILE_NAME}"
STR1="hello world"
STR2="world hello"
echo $STR1 $STR2 | ./${FILE_NAME}
