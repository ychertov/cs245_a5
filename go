#!/bin/bash
make clean
make
./soda soda.config ${1} > realout
./soda_64 soda.config ${1} > expectedout
