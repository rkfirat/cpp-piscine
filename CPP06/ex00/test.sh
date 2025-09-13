#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[1;33m"
NC="\033[0m"

EXE_NAME="convert"
CXX="c++"
CXXFLAGS="-Wall -Wextra -Werror -std=c++98"

PASSED_COUNT=0
FAILED_COUNT=0

run_test() {
    local description="$1"
    local expected_output="$2"
    shift 2
    local args=("$@")

    echo -e "${YELLOW}Testing: ${description} (Input: ${args[*]})${NC}"

    local actual_output
    actual_output=$(./$EXE_NAME "${args[@]}" 2>&1)

    echo "--- OUTPUT ---"
    echo "$actual_output"
    echo "--------------"

    if [ "$actual_output" == "$expected_output" ]; then
        echo -e "${GREEN}PASS${NC}"
        ((PASSED_COUNT++))
    else
        echo -e "${RED}FAIL${NC}"
        echo "--- EXPECTED ---"
        echo "$expected_output"
        echo "----------------"
        ((FAILED_COUNT++))
    fi
    echo
}

echo "Compiling the program..."
$CXX $CXXFLAGS -o $EXE_NAME main.cpp
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed. Exiting.${NC}"
    exit 1
fi
echo "Compilation successful."
echo "======================================="


run_test "Sıfır" "$(cat <<'EOF'
char: Non displayable
int: 0
float: 0.0f
double: 0.0
EOF
)" "0"

run_test "Pozitif Tamsayı" "$(cat <<'EOF'
char: '*'
int: 42
float: 42.0f
double: 42.0
EOF
)" "42"

run_test "Pozitif Ondalıklı" "$(cat <<'EOF'
char: '*'
int: 42
float: 42.42f
double: 42.42
EOF
)" "42.42"

run_test "Yazdırılabilir Karakter" "$(cat <<'EOF'
char: 'a'
int: 97
float: 97.0f
double: 97.0
EOF
)" "a"

run_test "Yazdırılamayan Karakter" "$(cat <<'EOF'
char: Non displayable
int: 9
float: 9.0f
double: 9.0
EOF
)" "$(printf '\t')"

run_test "Özel Değer: nan" "$(cat <<'EOF'
char: impossible
int: impossible
float: nanf
double: nan
EOF
)" "nan"

run_test "Özel Değer: +inf" "$(cat <<'EOF'
char: impossible
int: impossible
float: inff
double: inf
EOF
)" "+inf"

run_test "Özel Değer: -inf" "$(cat <<'EOF'
char: impossible
int: impossible
float: -inff
double: -inf
EOF
)" "-inf"

run_test "INT_MAX" "$(cat <<'EOF'
char: impossible
int: 2147483647
float: 2147483648.0f
double: 2147483647.0
EOF
)" "2147483647"

run_test "INT_MIN" "$(cat <<'EOF'
char: impossible
int: -2147483648
float: -2147483648.0f
double: -2147483648.0
EOF
)" "-2147483648"

run_test "INT Taşması (Pozitif)" "$(cat <<'EOF'
char: impossible
int: impossible
float: 2147483648.0f
double: 2147483648.0
EOF
)" "2147483648"

run_test "Hatalı Argüman Sayısı (0)" "Usage: ./convert <arg>"
run_test "Hatalı Argüman Sayısı (2)" "Usage: ./convert <arg>" "42" "21"
run_test "Geçersiz Girdi" "Error: invalid input" "hello"

echo "======================================="
echo "Test Summary:"
echo -e "${GREEN}Passed: $PASSED_COUNT${NC}"
echo -e "${RED}Failed: $FAILED_COUNT${NC}"
echo "======================================="

rm -f $EXE_NAME

if [ $FAILED_COUNT -ne 0 ]; then
    exit 1