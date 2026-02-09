cmake_minimum_required(VERSION 3.23)

project(PoissonReconProject)

add_library(PoissonRecon
  STATIC
    Src/PoissonReconMoorhen.cpp
)

target_sources(
  PoissonRecon
  PUBLIC
    FILE_SET public_headers
    TYPE HEADERS
    BASE_DIRS "Src"
    FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Allocator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Array.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/BSplineData.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/BinaryNode.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/BlockedVector.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/CmdLineParser.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/DataStream.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/DataStream.imp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Extrapolator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/FEMTree.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Factor.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Geometry.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Image.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/JPEG.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/LinearSolvers.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/MAT.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/MarchingCubes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/MergePlyClientServer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/MultiThreading.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/MyAtomic.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/MyExceptions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/MyMiscellany.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/NestedVector.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/PNG.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/PPolynomial.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/ParameterPack.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Ply.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/PlyFile.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/PointExtent.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/PointPartition.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/PointPartitionClientServer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/PoissonReconClientServer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Polynomial.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/PreProcessor.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Rasterizer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Reconstructors.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Reconstructors.streams.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/RegularGrid.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/RegularTree.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Socket.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/SparseMatrix.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/SparseMatrixInterface.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Streams.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/VertexFactory.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Window.h
)

INSTALL(TARGETS PoissonRecon
        LIBRARY DESTINATION lib
	FILE_SET public_headers DESTINATION include/PoissonRecon
)
