echo "make"
make

echo "cp bin/release/examples/example-dsm ."
cp bin/release/examples/example-dsm .

echo "mkdir input"
mkdir input

echo "mkdir result"
mkdir result

echo "tail -n 5105039 doc/web-Google.txt > input/part0"
tail -n 5105039 doc/web-Google.txt > input/part0
