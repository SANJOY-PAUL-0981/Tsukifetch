#!/bin/bash

gcc -Isrc src/tsuki.c src/ASCII_art/ascii_art.c src/sys_info/system_info.c -o tsukifetch
sudo mkdir -p /usr/local/share/tsukifetch/logos/
sudo cp src/logo/* /usr/local/share/tsukifetch/logos/

sudo cp tsukifetch /usr/local/bin/
sudo chmod +x /usr/local/bin/tsukifetch

echo "tsukifetch installed successfully!"
