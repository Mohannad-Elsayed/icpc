echo "Compiling val.cpp"
g++ val.cpp -o val
echo "_ok"
echo "Compiling gen.cpp"
g++ gen.cpp -o gen
echo "_ok"
echo "Generating..."
./gen > in
echo "_ok"
echo "Validating..."
./val < in
echo "_ok"
