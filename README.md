test1.cpp is very suboptimal, uses Bubblesort with an array we have to manually input.  
Bubblesort goes through the array and swaps unordered pairs ONE AT A TIME(!)

  

stdsort.cpp is better, uses `std::sort` and imports data from a csv file (randbw50000.csv in this case).  
`std::sort` combines 3 methods to reach a time complexity of O(nlogn):
- **Quick Sort**: Uses a pivot to sort to either side.
- **Heap Sort**: Sorts into tree-like structures (MIN HEAP or MAX HEAP).
- **Insertion Sort**: Skips known organized numbers and inserts incorrects back into the known.

  

Both `test1.cpp` and `stdsort.cpp` were created with the help of ChatGPT.
