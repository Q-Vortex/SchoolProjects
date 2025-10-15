
build() {
  make
  if [ $? -eq 0 ]; then
    ./main
  fi
}

run() {
  ./main
}
