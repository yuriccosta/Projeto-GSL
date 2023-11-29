#gcc -Wall -I/usr/local/include -c -o output/main.o main.c
#gcc -L/usr/local/lib -o output/main output/main.o -lgsl -lgslcblas -lm
# Aparentemente pode ser substituido por:
gcc -o output/main main.c -lgsl -lgslcblas -lm
./output/main
