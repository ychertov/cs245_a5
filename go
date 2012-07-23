#!/bin/bash
make clean
make
./soda soda.config 3 > realout
./soda_64 soda.config 3 > expectedout
