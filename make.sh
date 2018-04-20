#!/bin/bash
cd build/
rm -r * # usuwanie wszystkiego w build
cmake ..
make
./randBench
