#!/usr/bin/env bash

mkdir -p ../bin

g++ -std=c++20 -O2 -Wall ../src/DefenceOrchestrator.cpp ../src/MegumiDaemon.cpp ../src/main.cpp -o ../bin/megumid

chmod +x ../bin/megumid
