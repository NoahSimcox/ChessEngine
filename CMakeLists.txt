cmake_minimum_required(VERSION 3.26)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        chessPieces.c
        chessPieces.h
        chessBoard.c
        chessBoard.h
        pieceLogic.c
        pieceLogic.h
        arrayClean.c
        arrayClean.h
        evaluate.c
        evaluate.h
)
