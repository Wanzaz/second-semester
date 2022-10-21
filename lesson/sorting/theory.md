# Sorting Algorithms

* Definitions
* Features
* Division

---

###### Why do we sort data?
- Sorting efficiency


###### What do we sort?
- Arrays, linked list, files

---

### The characteristic of sorting Algorithms



## Time complexity T(n) and it's estimation O(T(n))
* Example: **T(n)** = 4n**2 - 3n + 80

#### O(1), O(k)
* **Constant** = The enumeration takes same time for any dimension of a task

#### O(log(n)) 
* **Logarithmic** = The number of steps grows with the number of processing elements
	* example - algorithms, which decrease their number of elements on half in each step

#### O(n) 
* **Lineral** = The calculation time is proportional to the number of processed elements
	* example = going through elements of array, matrix, list, etc.

#### O(n log (n)) 
* **Linear** = The calculation time is proportional to the number of processed elements
	* example = going through elements of array, matrix, list, etc.

#### O(n) 
* **Linearithmic** = Usually 2 nested cycles - one with linear and inner with Logarithmic complexity

#### O(n**2) 
* **Quadratic** = The number of steps grows with the second power of processed elements
	* Usually tow nested cycles - each with linear complexity

#### O(n**3) 
* **Cubic** 

#### O(x**n) 
* **Exponetional** 

#### O(n!) 
* **Factorial** 

---


## Spacial complexity S(n), Os(S(n))
* Function depended on task size, which specify the number of memory cells needed for this calculation

#### In Situ
* Program "works on a place"
* Doesn't need copy for all input data
* Auxiliary variables do not matter (if they don't take up similar memory to the input data)

---

## Naturalness
* Sorting algorithm is natural if doesn't already sorted data
	* non-natural algorithm example is Bubble sort
* **T** sorted data (n) < **T** random data (n) < **T** reverse sorted data (n)
* In general the best, average, and the worst case
* Some algorithms are more suitable for partially sorted data

---

## Sequencity
* Sorting algorithm is sequential if accesses the elements sequentially
* Has meaning for algorithms which process files or linked lists

---

## Stability
* Algorithm even after sorting keeps relativ sequence of elements with same key
* Has meaning fof sorting of structural items

---

### Division of Sorting Algorithms
* **Inner sorting methods**
	* Suppose sorted data are all in inner computer memory
	* Access to all data is equally fast
* **Outer sorting methods**
	* Sorted data or their parts are located in outer memory
		* Files on disk, data streams from devices, networks
	* Access to some data is much slower than to some other
