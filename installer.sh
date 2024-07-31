#!/bin/bash

gcc src/tsukifetch.c -o tsukifetch

sudo cp tsukifetch /usr/local/bin/
sudo chmod +x /usr/local/bin/tsukifetch


echo "tsukifetch installed successfully!"
