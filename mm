#!/bin/bash

rm -rf build
mkdir -p build  
cd build && 
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Debug -G "Ninja" && ninja &&
rm -rf ../compile_commands.json
ln -s compile_commands.json ../.
valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-leak-kinds=all ./tests/unit_tests/aicpp_unit_tests



