cmake_minimum_required(VERSION 3.29.6)
project(Algo C)

set(CMAKE_C_STANDARD 23)

include_directories(.)

add_executable(Algo
        functions.c
        h/functions.h
        sort/mergeSort.c
        tree/BiTree.c
        sort/quickSort.c
        sort/bubbleSort.c
        sort/insertionSort.c
        main.c
        h/bs.h
        h/is.h
        h/ms.h
        h/qs.h
        h/bt.h
        sort/heapSort.c
        h/hs.h
        sort/countingSort.c
        h/cs.h
        sort/optimized_countingSort.c
        h/o_cs.h
        sort/selectionSort.c
        BruteForce/bruteForcePoly.c
        h/bp.h
        BruteForce/betterBruteForcePoly.c
        h/bbp.h
        BruteForce/bruteForceInversionCount.c
        h/bc.h
        BruteForce/divideAndConquerInversionCount.c
        h/mb.h
        h/cp.h
        sort/OptimizedMergeSort.c
        h/optms.h
        search/findmedian.c
        mtquestions/isMaxHeap.c
        FinalCalismaAlani/sorucalismaalani.c
        FinalCalismaAlani/final.h
)
