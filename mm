#!/usr/bin/env bash
set -u -o pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$ROOT_DIR/build"

mkdir -p "$BUILD_DIR"

cmake -S "$ROOT_DIR" -B "$BUILD_DIR" \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
  -DCMAKE_BUILD_TYPE=Debug \
  -G Ninja

ninja -C "$BUILD_DIR"

# Create/update symlink atomically-ish; do not rm the file first every time
ln -sfn "$BUILD_DIR/compile_commands.json" "$ROOT_DIR/compile_commands.json"

valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-leak-kinds=all \
  "$BUILD_DIR/tests/unit_tests/aima-cpp_unit_tests"













#rm -rf build compile_commands.json
#mkdir -p build  
#cd build && 
#cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -G "Ninja" && ninja 
#rm -rf ../compile_commands.json
#ln -s compile_commands.json ../.
#valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-leak-kinds=all ./tests/unit_tests/aima-cpp_unit_tests



