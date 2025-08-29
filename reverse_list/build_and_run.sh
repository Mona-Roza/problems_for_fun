if ! [ -d ./build ]; then
  mkdir build
fi

cd build
cmake ..
cmake --build .

./reverse_list

cd ..
