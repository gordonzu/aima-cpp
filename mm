#!/bin/bash

rm -rf build compile_commands.json
mkdir -p build  
cd build && 
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -G "Ninja" && ninja 
rm -rf ../compile_commands.json
ln -s compile_commands.json ../.
valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-leak-kinds=all ./tests/unit_tests/aima-cpp_unit_tests



