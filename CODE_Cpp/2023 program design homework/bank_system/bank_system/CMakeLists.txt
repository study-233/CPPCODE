cmake_minimum_required(VERSION 3.0.0)
project(bank7 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(bank7 date.cpp date.h
account.h account.cpp
accountrecord.h accountrecord.cpp
savingaccount.cpp savingaccount.h
accumulator.cpp accumulator.h
creditaccount.cpp creditaccount.h
accoutexception.h accoutexception.cpp
commands.txt
main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
