# LeetCode Solutions in C++

Solutions to LeetCode problems in C++, each with a write-up of the approach, time and space complexity, and lessons learned. Updated as I go.

## Progress

<!-- PROBLEMS:START -->
| Solved | Easy | Medium | Hard |
|:------:|:----:|:------:|:----:|
| **6** | 4 | 2 | 0 |

**Topics:** Hash Table (4) · Array (3) · String (3) · Sorting (3) · Linked List (1) · Math (1) · Recursion (1) · Two Pointers (1)

| # | Problem | Difficulty | Topics | Solution | Solved |
|--:|---------|------------|--------|----------|--------|
| 1 | [Two Sum](problems/0001-two-sum/two-sum.md) | Easy | Array, Hash Table | [C++](problems/0001-two-sum/two-sum.cpp) | 2026-10-20 |
| 2 | [Add Two Numbers](problems/0002-add-two-numbers/add-two-numbers.md) | Medium | Linked List, Math, Recursion | [C++](problems/0002-add-two-numbers/add-two-numbers.cpp) | 2026-10-20 |
| 49 | [Group Anagrams](problems/0049-group-anagrams/group-anagrams.md) | Medium | Array, Hash Table, String, Sorting | [C++](problems/0049-group-anagrams/group-anagrams.cpp) | 2026-10-28 |
| 125 | [Valid Palindrome](problems/0125-valid-palindrome/valid-palindrome.md) | Easy | Two Pointers, String | [C++](problems/0125-valid-palindrome/valid-palindrome.cpp) | 2026-10-26 |
| 217 | [Contains Duplicate](problems/0217-contains-duplicate/contains-duplicate.md) | Easy | Array, Hash Table, Sorting | [C++](problems/0217-contains-duplicate/contains-duplicate.cpp) | 2026-10-22 |
| 242 | [Valid Anagram](problems/0242-valid-anagram/valid-anagram.md) | Easy | Hash Table, String, Sorting | [C++](problems/0242-valid-anagram/valid-anagram.cpp) | 2026-10-22 |
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
