gcc -o addition operations.c
rm ./division
rm ./multiplication
ln addition division
ln addition multiplication
./addition -.cygu12 5
./addition -2 7
./addition 1 3 5 13
./multiplication 1 3 5 13
./multiplication 1 3 5 -13
./multiplication 1 -3 -5 13
./division 1 3 5 13
