SRC_FILE="acm/二维数组读取.cpp"
FILE_NAME=$(basename ${SRC_FILE} .cpp)

mkdir -p bin
g++ "${SRC_FILE}" -o bin/${FILE_NAME} \
    -std=c++11 \
    -Wall \
    -Werror
cd bin
echo "===================="
echo "Test ${FILE_NAME}"
MN="2 3"
row1="1 2 3"
row2="4 5 6"
row3="7 8 9"
echo $MN $row1 $row2 $row3 | ./${FILE_NAME}
