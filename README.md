# LeetCode Solutions in C++

Solutions to LeetCode problems in C++, each with a write-up of the approach, time and space complexity, and lessons learned. Updated as I go.

## Progress

<!-- PROBLEMS:START -->
| Solved | Easy | Medium | Hard |
|:------:|:----:|:------:|:----:|
| **12** | 4 | 8 | 0 |

**Topics:** Array (8) · Hash Table (8) · String (5) · Sorting (4) · Linked List (1) · Math (1) · Recursion (1) · Sliding Window (1) · Matrix (1) · Two Pointers (1) · Union Find (1) · Prefix Sum (1) · Design (1) · Divide and Conquer (1) · Heap (Priority Queue) (1) · Bucket Sort (1) · Counting (1) · Quickselect (1)

| # | Problem | Difficulty | Topics | Solution | Solved | Times solved |
|--:|---------|------------|--------|----------|--------|:------------:|
| 1 | [Two Sum](problems/0001-two-sum/two-sum.md) | Easy | Array, Hash Table | [C++](problems/0001-two-sum/two-sum.cpp) | 2026-10-20 | 1 |
| 2 | [Add Two Numbers](problems/0002-add-two-numbers/add-two-numbers.md) | Medium | Linked List, Math, Recursion | [C++](problems/0002-add-two-numbers/add-two-numbers.cpp) | 2026-10-20 | 1 |
| 3 | [Longest Substring Without Repeating Characters](problems/0003-longest-substring-without-repeating-characters/longest-substring-without-repeating-characters.md) | Medium | Hash Table, String, Sliding Window | [C++](problems/0003-longest-substring-without-repeating-characters/longest-substring-without-repeating-characters.cpp) | 2026-10-28 | 1 |
| 36 | [Valid Sudoku](problems/0036-valid-sudoku/valid-sudoku.md) | Medium | Array, Hash Table, Matrix | [C++](problems/0036-valid-sudoku/valid-sudoku.cpp) | 2026-11-04 | 1 |
| 49 | [Group Anagrams](problems/0049-group-anagrams/group-anagrams.md) | Medium | Array, Hash Table, String, Sorting | [C++](problems/0049-group-anagrams/group-anagrams.cpp) | 2026-10-28 | 1 |
| 125 | [Valid Palindrome](problems/0125-valid-palindrome/valid-palindrome.md) | Easy | Two Pointers, String | [C++](problems/0125-valid-palindrome/valid-palindrome.cpp) | 2026-10-26 | 1 |
| 128 | [Longest Consecutive Sequence](problems/0128-longest-consecutive-sequence/longest-consecutive-sequence.md) | Medium | Array, Hash Table, Union Find | [C++](problems/0128-longest-consecutive-sequence/longest-consecutive-sequence.cpp) | 2026-11-05 | 1 |
| 217 | [Contains Duplicate](problems/0217-contains-duplicate/contains-duplicate.md) | Easy | Array, Hash Table, Sorting | [C++](problems/0217-contains-duplicate/contains-duplicate.cpp) | 2026-10-22 | 1 |
| 238 | [Product of Array Except Self](problems/0238-product-of-array-except-self/product-of-array-except-self.md) | Medium | Array, Prefix Sum | [C++](problems/0238-product-of-array-except-self/product-of-array-except-self.cpp) | 2026-11-02 | 1 |
| 242 | [Valid Anagram](problems/0242-valid-anagram/valid-anagram.md) | Easy | Hash Table, String, Sorting | [C++](problems/0242-valid-anagram/valid-anagram.cpp) | 2026-10-22 | 1 |
| 271 | [Encode and Decode Strings](problems/0271-encode-and-decode-strings/encode-and-decode-strings.md) | Medium | Array, String, Design | [C++](problems/0271-encode-and-decode-strings/encode-and-decode-strings.cpp) | 2026-11-01 | 1 |
| 347 | [Top K Frequent Elements](problems/0347-top-k-frequent-elements/top-k-frequent-elements.md) | Medium | Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect | [C++](problems/0347-top-k-frequent-elements/top-k-frequent-elements.cpp) | 2026-10-29 | 1 |
<!-- PROBLEMS:END -->

## How each problem is documented

Every problem lives in its own folder, `problems/NNNN-title/`:

- `<slug>.md` (for example `two-sum.md`): link to the problem, the statement, my approach, complexity analysis and notes
- `<slug>.cpp` (for example `two-sum.cpp`): the accepted C++ solution

Topic-level summaries of recurring techniques (sliding window, two pointers, DP and so on) are in [`notes/`](notes). Problems I want to re-solve from scratch are listed in [`REVIEW.md`](REVIEW.md).

## Repository layout

```
problems/    one folder per problem
notes/       pattern and technique write-ups
templates/   README template for new problems
scripts/     helpers that scaffold problems and rebuild the table above
```

<sub>Problem statements are © LeetCode and are reproduced for personal study. Solutions and notes are my own.</sub>
