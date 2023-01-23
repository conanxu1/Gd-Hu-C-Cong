




cmake_minimum_required(VERSION 2.6)
project(QOP)
message("二次优化")

add_definitions("-g -O3 -mavx   -lnlopt  -W")

add_definitions("-lpthread -lgfortran   -std=c99 -O3")


include_directories(/usr/include/x86_64-linux-gnu)
link_directories("/usr/lib/x86_64-linux-gnu/")
link_libraries(fftw3)
link_libraries(openblas)
link_libraries(m)
link_libraries(lapacke)
 


 


add_definitions(-DUSE_FFTW=on)


aux_source_directory(. SRC_LIST)
# add_executable(QOP ${SRC_LIST})
add_executable(QOP ${SRC_LIST})

