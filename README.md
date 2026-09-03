
*This project has been created as part of the 42 curriculum by booz, sradhakr.*

# Push_swap

## Description

Push_swap is an algorithmic project that requires sorting a stack of integers using a strictly limited set of operations and **two stacks** (`a` and `b`), while minimizing the total number of operations used.

The program takes a list of integers as arguments, loads them into stack `a`, and outputs to stdout the smallest sequence of instructions (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) needed to sort them in ascending order.

It implements **four distinct algorithms** of increasing complexity class — O(n²), O(n√n), O(n log n), and an adaptive strategy that selects between them based on a measured *disorder* score of the input.

---

## Instructions

### Compilation

```bash
git clone <repo-url>
cd push_swap
make
```

This produces a `push_swap` executable at the root of the project.

### Cleaning

```bash
make clean   # removes object files
make fclean  # removes object files and binaries
make re      # fclean + recompile
```

### Usage

```bash
./push_swap [STRATEGY] <list of integers>
```


**Benchmark mode:**

```bash
./push_swap --bench <list of integers>
```

Prints sorting statistics to stderr: disorder %, strategy used, total operation count, and per-operation breakdown.

### Examples

```bash
$> ./push_swap --bench 2 1 3 6 8
ra
pb
rra
pb
pa
pa
[bench] disorder:  10.00%
[bench] strategy:  Small / O(1)
[bench] total_ops: 6
[bench] sa: 0  sb: 0  ss: 0  pa: 2  pb: 2
[bench] ra: 1  rb: 0  rr: 0  rra: 1  rrb: 0  rrr: 0
```


### Error handling

In case of invalid input (non-integer arguments, integers out of range, duplicate values), the program prints `Error` to stderr and exits.

```bash
$> ./push_swap 1 2 one
Error
```

---

## Algorithms

### 1. Simple

**Technique used:**

This algorithm uses a selection sort like technique. It repeatedly finds the smallest element in stack a, rotates a until that element is at the top, pushes it to stack b, and finally moves all elements from b back to a.

**How it works:**

1. ft_stack_size() calculates the current number of elements in stack a.
2. find_min_pos() traverses the entire stack and finds the position of the smallest value.
3. simple_sort_to_b() checks whether the smallest element is closer to the top or the bottom of a.
    - If it is in the upper half, ra is used to rotate a upwards.
    - If it is in the lower half, rra is used to rotate a in the opposite direction.
4. Once the smallest element reaches the top of a, pb pushes it onto stack b.
5. Steps 1–4 are repeated until stack a is empty. Here elements are removed from a in increasing order to b.
6. Finally, pa is repeated to move the elements from b back to a. Since the smallest elements were placed into b first, this reverses their order and results in a being sorted from smallest to largest.

**Complexity justification:**

The algorithm repeatedly searches for the smallest element and rotates stack a to bring it to the top. Finding the minimum and rotating the stack can both take O(n) operations, and this process is repeated for each of the n elements.

Therefore:
O(n) × O(n) = O(n²)

---

### 2. Medium

**Technique used:** 

The algorithm uses an optimized chunk-based sorting technique. First, heap sort is used to assign a sorted index to every element. The stack is then divided into approximately √n chunks using chunk_count().

Unlike a basic chunk algorithm, this version searches for valid elements from both the top and bottom of stack a and selects the one requiring the fewest rotations. While transferring elements to stack b, it also calculates the best insertion depth to maintain a partially sorted order. When possible, simultaneous rotations with rr are used to reduce the total number of operations.

**How it works:**

1. Each element in a is assigned a sorted index (heap_utils()), and the number of chunks is set to about √n (chunk_count()).
2. chunk_sort() splits the elements into chunks with defined index ranges, distributing any leftovers across the first few chunks.
3. For each chunk, process_chunk() repeatedly finds the next valid element to move:
	- compute_dist() scans from both the top and bottom of a to find the cheapest valid element to extract.
	- rotate_extraction() brings it to the top of a using ra or rra, whichever is cheaper — using rr for simultaneous rotation when both stacks need to rotate forward.
4. insertion_depth() finds where the element belongs in b (relative to already-placed elements), and pb + rrb move it there while keeping b's partial order intact.
5. Once every chunk is processed, b holds all elements in order, so pa moves them back into a, fully sorted.

**Complexity justification:**

The algorithm processes the elements in chunks of approximately √n elements. For each chunk, it searches stack a (from both ends) to find each element belonging to that chunk, rotates it to the top, then moves it onto stack b in its correct position. There are approximately √n chunks, and moving all the elements within one chunk can require uo to O(n) operations in total.

Therefore:
O(n)×O(√n) = O(n√n)

---

### 3. Complex — O(n log n)

**Technique used:** 

This algorithm uses a quicksort like technique. It picks a pivot value (the median of the current stack), partitions the stack around that pivot by splitting elements between stack a and stack b, and recursively repeats this on each partition until everything is sorted.

**How it works:** 

1. get_pivot() copies the current segment of values into an array, sorts a copy of it with pivot_loop() (insertion sort), and returns the middle (median) value to use as the pivot.
2. quick_sort_a() partitions stack a using loop_a(): values smaller than the pivot are pushed to b, values larger stay in a and are rotated with ra. After the pass, rra restores the larger elements to their original relative order.
3. This leaves b holding the "smaller" partition and a holding the "bigger" partition (already rotated back in place).
4. quick_sort_a() then recurses on the bigger partition left in a, and calls quick_sort_b() on the smaller partition sitting in b.
5. quick_sort_b() does the mirrored job on stack b using loop_b(): values bigger than the pivot are pushed back to a, values smaller stay in b and are rotated with rb, then rrb restores order.
6. Base cases (size 0, 1, or 2) are handled directly with sa/sb or simple pa/pb moves instead of recursing further.
7. Recursion keeps halving each side (approximately) until every partition is fully sorted back into a.

**Complexity justification:** 

Each partitioning pass (loop_a/loop_b) touches every element in that segment once, so it costs O(n) for a segment of size n. Because the pivot is chosen as the median, each partition splits the stack roughly in half, giving log(n) levels of recursion.

Therefore:
O(n) × O(log n) = O(n log n)

---

### 4. Adaptive (custom)

**Disorder metric:** 

This algorithm doesn't sort directly — it first measures how "disordered" stack a is, then picks whichever sorting algorithm (simple, medium, or quicksort) best fits that level of disorder.

**Thresholds and rationale:**

1. ft_disorder() counts the number of "inversions" (pairs where a smaller value appears after a larger one) and divides by the total possible pairs, giving a disorder score between 0.0 (already sorted) and 1.0 (fully reversed/random).
2. ft_adaptive() checks this score:
	- If it's 0.0, the stack is already sorted, nothing to do.
	- If it's below 0.2 (mostly sorted), it uses ft_simple_algo() (the O(n²) selection-based approach), since few elements are out of place.
	- If it's between 0.2 and 0.5 (moderately disordered), it uses medium_algo() (the chunk-based O(n√n) approach).
	- If it's 0.5 or higher (heavily disordered), it uses quick_sort_a() (the O(n log n) approach), since it scales best for messy input.
4. counts[11] records which strategy was chosen (1 = simple, 2 = medium, 3 = quicksort).



## Resources

### Documentation & references

- [Visualgo - sorting algorithm animations](https://visualgo.net/en/sorting)
- [Abdul Bari - Youtube Tutorial](https://www.youtube.com/@abdul_bari)
- [Bro Code - Youtube Tutorial](https://www.youtube.com/@BroCodez)

### AI usage disclosure

AI was used through out the project to understand different algorithm, complexity calculation, debugging and to structure Readme file.

---

## Contributors

| Login | Contributions |
|---|---|
| booz | parsing, complex/adaptive algorithms, checker, Makefile|
| sradhakr | stack operations, simple/medium algorithms|
