*This project has been created as part of the 42 curriculum by dkpg-md-.*

# push_swap

## Description
push_swap is a sorting algorithm project. The goal is to sort a stack of integers using two stacks (a and b) and a limited set of operations, using the lowest possible number of moves. The project implements the Turk algorithm, a greedy cost-based approach that efficiently sorts integers by calculating the cheapest move at each step.

## Instructions

**Compile:**
```bash
make
```

**Run:**
```bash
./push_swap 3 1 2 5 4
```

**Test with random numbers:**
```bash
./push_swap $(python3 -c "import random; nums = random.sample(range(-1000, 1000), 100); print(' '.join(map(str, nums)))") | wc -l
```

**Check for errors:**
```bash
./push_swap 0 one 2      # prints Error
./push_swap              # prints nothing
```

## Benchmarks
- 100 numbers sorted in under 700 operations
- 500 numbers sorted in under 5500 operations

## Resources
- [Turk Algorithm explanation](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Linked lists in C](https://www.learn-c.org/en/Linked_lists)
- [Sorting algorithm complexity](https://www.bigocheatsheet.com/)

**AI usage:** Claude was used as a teaching tool throughout this project — explaining concepts like linked lists, pointer arithmetic, and the Turk algorithm step by step. All code was written and typed manually with guidance, not generated and copied.
