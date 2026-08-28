
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

**Strategy flags (optional):**

| Flag | Forces |
|------|--------|
| `--simple` | O(n²) algorithm |
| `--medium` | O(n√n) algorithm |
| `--complex` | O(n log n) algorithm |
| `--adaptive` | Adaptive strategy (default if no flag given) |

**Benchmark mode:**

```bash
./push_swap --bench <list of integers>
```

Prints sorting statistics to stderr: disorder %, strategy used, total operation count, and per-operation breakdown.

### Examples

```bash
$> ./push_swap 2 1 3 6 5 8
ra
pb
rra
pb
pb
ra
pb
ra
pb
pb
pa
pa
pa
pa
pa
pa

$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG
OK
```

<!-- TODO: replace/add real examples from your own program once tested -->

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

1. medium_algo() first checks whether sorting is necessary. If there is more than one element, heap_utils() assigns a sorted index to each element.
2. chunk_count() calculates the number of chunks based on approximately √n:
    - It first finds the integer square root of n then multiplied by approximately 1.16 to determine the number of chunks.
3. chunk_sort() divides the total number of elements into chunks.
    - base determines the minimum number of elements per chunk.
    - extra_chunks distributes any remaining elements among the first chunks.
    - low and up define the index range of the current chunk.
4. process_chunk() repeatedly moves elements belonging to the current chunk from stack a to stack b.
5. compute_dist() searches for a valid element from both directions:
    - scan_front() searches from the top of stack a.
    - scan_back() searches from the bottom using the stored tail pointer.
    - The algorithm compares both positions and selects the element requiring the fewest rotations.
6. move_one() calculates the rotation cost for stack a and determines where the selected element should be inserted into stack b.
7. insertion_depth() finds the appropriate position in b by comparing the selected element's index with the elements already placed in the current chunk.
8. rotate_extraction() moves the selected element to the top of stack a.
    - If rotating forward is cheaper, ra is used.
    - If rotating backward is cheaper, rra is used.
9. When both stacks need forward rotations, merge_forward() combines them using rr. This performs rotations on both stacks simultaneously and reduces the total number of operations.
10. The element is moved from a to b using pb. Stack b is then restored with rrb rotations so that its partial ordering is preserved.
11. Once all chunks have been processed, stack b contains the elements in the required order, allowing pa to repeatedly move every element back to stack a.

**Complexity justification:**

The algorithm processes the elements in chunks of approximately √n elements. For each chunk, it searches stack a (from both ends) to find each element belonging to that chunk, rotates it to the top, then moves it onto stack b in its correct position. There are approximately √n chunks, and moving all the elements within one chunk can require uo to O(n) operations in total.

Therefore:
O(n)×O(√n) = O(n√n)

---

### 3. Complex — O(n log n)

**Technique used:** <!-- e.g. radix sort (LSD) -->

**How it works:** <!-- TODO -->

**Complexity justification:** <!-- TODO -->

---

### 4. Adaptive (custom)

**Disorder metric:** Calculated as the ratio of "mistakes" (pairs where a larger number precedes a smaller one) to total possible pairs, measured before any operations.

**Thresholds and rationale:**

| Disorder range | Strategy used | Why |
|---|---|---|
| < 0.2 | Simple (O(n²)) | <!-- TODO: justify --> |
| 0.2 – 0.5 | Medium (O(n√n)) | <!-- TODO: justify --> |
| ≥ 0.5 | Complex (O(n log n)) | <!-- TODO: justify --> |

**Complexity argument (time & space, within the Push_swap operation model):** <!-- TODO -->

---

## Performance

<!-- TODO: fill in actual benchmark results -->

| Input size | Operations used | Target (pass / good / excellent) |
|---|---|---|
| 100 random numbers | TBD | < 2000 / < 1500 / < 700 |
| 500 random numbers | TBD | < 12000 / < 8000 / < 5500 |

---

## Resources

### Documentation & references

- [Visualgo - sorting algorithm animations](https://visualgo.net/en/sorting)
- [Abdul Bari - Youtube Tutorial](https://www.youtube.com/@abdul_bari)
- [Bro Code - Youtube Tutorial](https://www.youtube.com/@BroCodez)
- 
### AI usage disclosure

AI was used through out the project to understand different algorithm, complexity calculation, debugging and to structure Readme file.

---

## Contributors

| Login | Contributions |
|---|---|
| booz | parsing, complex/adaptive algorithms, checker, Makefile|
| sradhakr | stack operations, simple/medium algorithms|

