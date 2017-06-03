#!/usr/bin/bash

for mode in 0 1 2 3; do
    ./apply-vad --frame-len=10 --mode=$mode t.wav t.vad.$mode.wav
done



