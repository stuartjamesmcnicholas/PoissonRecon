cmake_minimum_required(VERSION 3.23)

project(PoissonReconProject)

add_library(PoissonRecon
  STATIC
    Src/PoissonReconMoorhen.cpp
)
