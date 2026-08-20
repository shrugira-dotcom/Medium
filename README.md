
*This project has been created as part of the 42 curriculum by booz, sradhakr.*

# Push_swap

## Description

Push_swap is an algorithmic project that requires sorting a stack of integers using a strictly limited set of operations and **two stacks** (`a` and `b`), while minimizing the total number of operations used.

The program takes a list of integers as arguments, loads them into stack `a`, and outputs to stdout the smallest sequence of instructions (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) needed to sort them in ascending order.

This implementation goes beyond a single sorting strategy: it implements **four distinct algorithms** of increasing complexity class — O(n²), O(n√n), O(n log n), and an adaptive strategy that selects between them based on a measured *disorder* score of the input.

<!--
TODO: Add 2-3 sentences here summarizing what makes your specific implementation notable
(e.g. "Our adaptive strategy uses X technique for low disorder and Y for high disorder...")
-->

---

## Instructions

### Compilation

```bash
git clone <repo-url>
cd push_swap
make
```

This produces a `push_swap` executable at the root of the project.

<!-- TODO: confirm/adjust if your Makefile structure differs -->

### Compiling the bonus (checker)

```bash
make bonus
```

This produces a `checker` executable.

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

<!--
TODO: This section is REQUIRED by the subject — fill in once implemented.
For each algorithm: name it, explain the technique, and justify the complexity claim
in terms of number of push_swap operations generated (not classical array complexity).
-->

### 1. Simple — O(n²)

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

### 2. Medium — O(n√n)

**Technique used:** 

The algorithm uses a chunk-based sorting technique. The heap sort is used to assign index to each element. The stack a is then divided into chunks of approximately √n elements. Elements belonging to the current chunk are pushed from a to b. Once a chunk has been transferred, b is partially sorted by repeatedly finding the largest indexed element in the current chunk and moving it back to a with the minimum number of rotations.

**How it works:**

1. The stack is divided into chunks of approximately √n elements for inputs up to 20, and 2.65 * √n for larger inputs.
2. low and up define the range of indexes belonging to the current chunk.
3. find_chunk_pos() finds an element from the current chunk in stack a.
4. The position of that element is compared with the middle of stack a.
    - If it is in the upper half, ra is used to rotate it towards the top.
    - If it is in the lower half, rra is used instead.
5. pb moves the element from a to b.
6. Once a chunk is moved, intermittent_bsort() searches the largest index and uses rb or rrb to bring that element to the top.
7. pa moves the largest element back to a. Repeating this places the elements from the chunk back into a in descending order.
8. next_chunk() updates up and low to select the next range of indexes and repeats the process until all elements have been processed.

**Complexity justification:**

The algorithm processes the elements in chunks of approximately √n elements. For each chunk, it may need to search and rotate the stacks to move the elements into the correct position. There are approximately √n chunks, and processing each chunk can require up to O(n) operations.

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
The derivation of constant (c ~ 2.65) used in Medium algorithm was derived with the help of AI assistant Claude (Anthropic).
---

## Contributors

| Login | Contributions |
|---|---|
| booz | parsing, complex/adaptive algorithms, checker, Makefile|
| sradhakr | stack operations, simple/medium algorithms|

