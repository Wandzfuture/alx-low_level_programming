#!/bin/bash
wget -p .. https://raw.githubusercontent.com/Wandzfuture/alx-low_level_programming/master/0x18-dynamic_libraries/libcrack.so
export LD PRELOAD="$PWD/../libcrack.so"
