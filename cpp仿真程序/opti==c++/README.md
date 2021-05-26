emoji

# 🍙 功能描述

Linear DDE Solver

最优控制









# 🧂 开发环境

- g++
- eigen3
- nlopt 
- opencv
- cmake 
- make
- openblas







1. sudo *apt*-get install g++ cmake make
2.  sudo *apt*-get install libnlopt-dev
3. sudo apt install libopencv-dev
4. sudo apt-get install libeigen3-dev 
5. sudo apt install libopenblas-dev libopenblas-base







# 🍬 **项目结构**



# 🍼 **DEMO**

采用cmake编译build_by_cmake
opti==c++$ ./*sh "-DUSE_EIGEN=1 -DSMALL_SCALE=1"

opti==c++$ ./*sh "-DUSE_EIGEN=ON -DSMALL_SCALE=ON"

使用EIGEN库，求解小规模问题不优化



opti==c++$ ./*sh "-DUSE_EIGEN=1 -DLARGE_SCALE=1"
使用EIGEN库，求解大规模问题。采用数组保存数据，计算过程中复制数据给MatrixXd，或者可以考虑使用openblas库进行处理。










# 🍺 **作者列表**

conanxu1







# **🍪历史版本**





# ⚽注记

条件编译

https://blog.csdn.net/weixin_42986599/article/details/106569230



```cmake
if(USE_EIGEN)
add_definitions(-DUSE_EIGEN)
include_directories(/usr/include/eigen3 )
endif()
# # # -DLARGE_SCALE=ON

 

if(${SMALL_SCALE})
message("SMALL_SCALE")
add_definitions(-DSMALL_SCALE)
endif(${SMALL_SCALE})
# # # -DLARGE_SCALE=1
```



为了避免同一个头文件被包含（include）多次，C/C++中有两种宏实现方式：一种是#ifndef方式；另一种是#pragma once方式



# stdarg.h这个头文件的作用



```cpp
foo(3, x, y, z);
foo(6, x, y, z, a, b, c);
//不定长参数
```





