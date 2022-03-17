#!/bin/bash

for i in {1..100}
do  
    ./push_swap `ruby -e "puts (1..3).to_a.shuffle.join(' ')"` | wc -l
done