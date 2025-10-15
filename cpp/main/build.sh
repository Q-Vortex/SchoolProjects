function build
  g++ main.cpp -o main
  if test $status -eq 0
    ./main
  end
end
