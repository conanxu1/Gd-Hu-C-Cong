cmake_minimum_required(VERSION 2.6)
project(QOP)
message("二次优化")

aux_source_directory(. SRC_LIST)
add_executable(QOP ok.c)






# add_definitions("-g -O3 -mavx -lm -lnlopt  -W       -lpthread -lgfortran   -std=c99 -O3        -L /usr/lib/x86_64-linux-gnu/ -lopenblas    -L /usr/lib/x86_64-linux-gnu/ -lfftw3            -I /usr/include/x86_64-linux-gnu      ")
 
 
link_directories("/usr/lib/x86_64-linux-gnu/")
link_libraries(fftw3)



add_definitions(-DUSE_FFTW=on)



# add_executable(QOP ${SRC_LIST})




# gcc -g qxtdemo.c myfun.c ofun.c kongzhi.c -o ookk -L /usr/lib/x86_64-linux-gnu/ -lfftw3      -lpthread -lgfortran    -std=c99 -O3







