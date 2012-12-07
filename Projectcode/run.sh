rm cdna1
rm cpna1
rm result
./SAIBIT dna1 cdna
./SAIBIT pna1 cpna
rm test
c++ -o test test.cpp
./test cdna cpna > result
vi result
