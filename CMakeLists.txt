cmake_minimum_required(VERSION 3.22.1)
project(algorithm_learning)


file(GLOB_RECURSE algorithm_files "algorithm/*.cpp")
file(GLOB_RECURSE data_structure_files "data_structure/*.cpp")


add_library(algorithm ${algorithm_files} ${data_structure_files})