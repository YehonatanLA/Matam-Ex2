cmake_minimum_required(VERSION 3.19)
project(untitled2)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled2 autoGameTester.cpp Character.h Character.cpp Soldier.h Soldier.cpp Medic.h Medic.cpp Sniper.cpp Sniper.h
        Game.cpp Game.h Exceptions.cpp Exceptions.h Point.cpp Point.h Auxiliaries.h Auxiliaries.cpp)
#add_executable(untitled2 SortedList.h part_a_test.cpp testClass.h Node.h ExamDetails.cpp
#        ExamDetails.h)