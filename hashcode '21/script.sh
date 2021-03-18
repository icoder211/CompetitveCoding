#!/bin/bash

g++ -std=c++17 program.cpp -o program

./program.exe < a.txt > a_out.txt
./program.exe < b.txt > b_out.txt
./program.exe < c.txt > c_out.txt
./program.exe < d.txt > d_out.txt
./program.exe < e.txt > e_out.txt
./program.exe < f.txt > f_out.txt