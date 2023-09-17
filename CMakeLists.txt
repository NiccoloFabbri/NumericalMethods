cmake_minimum_required(VERSION 3.26)
project(MTH9821_NumericalMethods)

set(CMAKE_CXX_STANDARD 20)


add_executable(HW3
        HW3.cpp
        Random/LCG.h
        Random/LCG.cpp
        Random/RandomSampling.cpp
        Random/RandomSampling.h
        Trees/BinomialTree.h
        Options/Option.h
        Options/Option.cpp
        Trees/BinomialTree.cpp
        Options/EuropeanOption.cpp
        Options/Payoff.h
        Options/AmericanOption.h
        Options/AmericanOption.cpp
        Trees/AlternativeMethods.cpp
)