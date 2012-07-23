#!/bin/bash
make clean
make
./soda soda.config 4 > realout
./soda_64 soda.config 4 > expectedout
