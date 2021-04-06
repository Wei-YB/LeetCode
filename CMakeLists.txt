# CMakeList.txt: LeetCode 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("LeetCode")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

aux_source_directory(. DIR_SRCS)

message(${DIR_SRCS})

# string(REPLACE "./" " " DIR_SRCS ${DIR_SRCS})


foreach(v ${DIR_SRCS})
	string(REPLACE "./" "" SRCS ${v})
	string(REPLACE ".cpp" "" SRCS ${SRCS})

	add_executable(${SRCS}_test ${v} "util.h")
endforeach()



# 将源代码添加到此项目的可执行文件。
# add_executable (LeetCode "LeetCode.cpp" "LeetCode.h")

# TODO: 如有需要，请添加测试并安装目标。
