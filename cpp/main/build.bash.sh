build() {
  g++ main.cpp -o main
  if [ $? -eq 0 ]; then
    ./main
  fi
}
