---
number: 36
title: Valid Sudoku
slug: valid-sudoku
difficulty: Medium
topics: Array, Hash Table, Matrix
status: Solved
date: 2026-11-04
review: true
review_reason: Works but uses 81 hardcoded branches; re-solve with a short, general version
---

# 36. Valid Sudoku

[LeetCode problem](https://leetcode.com/problems/valid-sudoku/) · [C++ solution](valid-sudoku.cpp)

## Problem

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits `1-9` without repetition.

**Note:**

- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

**Example 1:**

```
Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
```

**Example 2:**

```
Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
```

**Constraints:**

- `board.length` == 9
- `board[i].length` == 9
- `board[i][j]` is a digit `1-9` or `'.'`.

## Approach

### 1. One pass with sets (my solution)

Walk the board once. Keep one `unordered_set<char>` for each of the 9 rows, 9 columns and 9 blocks. For each filled cell:

1. If its digit is already in that cell's row, column or block set, the board is invalid, so return `false`.
2. Otherwise, add the digit to all three sets.

If every filled cell passes, return `true`. This version picks the right three sets with one hardcoded branch per cell, 81 in total.

- Time: O(1), since the board is always 9 x 9 (O(n<sup>2</sup>) for an n x n board)
- Space: O(1) for the same reason (O(n<sup>2</sup>) for an n x n board)

### To revisit: a short, general version

Not solved yet. Hints for the re-solve:

- `row0` through `row8` are nine separate variables. What could hold all nine, so the right one can be reached using the `row` variable directly?
- The branches really only decide which block a cell is in. Rows 0-2 with columns 3-5 are always `block1`, and rows 3-5 with columns 6-8 are always `block5`. Can the block number be calculated from `row` and `column`?

## Complexity

My solution (approach 1):

- Time: O(1)
- Space: O(1)

## Notes

- **Check all three rules in one pass.** A cell belongs to exactly one row, one column and one block, so a single walk over the board can check all three rules at once. Separate passes aren't needed.
- **Only filled cells count.** Empty `.` cells are skipped, and the board doesn't need to be solvable.
- **Writing out every case.** The logic is correct, but 81 near-identical branches are long to write and hard to check. A wrong block number in one branch would be easy to miss. Repetition like this usually means there's a rule to find, so that's the goal of the re-solve.
- **State between calls.** The sets are class members, so they keep their contents after a call. Calling `isValidSudoku` twice on the same object would see digits from the earlier board, so that's worth fixing in the re-solve too.
- Related: [Contains Duplicate](../0217-contains-duplicate/contains-duplicate.md) uses the same "seen this before?" set check.
