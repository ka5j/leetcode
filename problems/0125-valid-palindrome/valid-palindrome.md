---
number: 125
title: Valid Palindrome
slug: valid-palindrome
difficulty: Easy
topics: Two Pointers, String
status: Solved
date: 2026-10-26
---

# 125. Valid Palindrome

[LeetCode problem](https://leetcode.com/problems/valid-palindrome/) · [C++ solution](valid-palindrome.cpp)

## Problem

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.

**Example 1:**

```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

**Example 2:**

```
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```

**Example 3:**

```
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
```

**Constraints:**

- 1 <= `s.length` <= 2 * 10<sup>5</sup>
- `s` consists only of printable ASCII characters.

## Approach

### 1. Clean and compare (my solution)

Create a new string by filtering out non-alphanumeric characters and converting to lowercase. Then use two pointers from both ends to check if it reads the same forward and backward.

- Time: O(n)
- Space: O(n) for the new string

### 2. Two pointers in place (optimized)

Use two pointers on the original string. Skip non-alphanumeric characters as you go, comparing lowercase versions of the characters that matter. No new string needed.

- Time: O(n)
- Space: O(1)

## Complexity

My solution (approach 1):

- Time: O(n)
- Space: O(n)

## Notes

- **Filtering approach is cleaner.** Creating a new string makes the logic simpler to read and debug, at the cost of O(n) extra space. For most inputs, this trade-off is worth it.
- **In-place two pointers is more efficient.** Skipping non-alphanumeric on the fly saves space, but the nested while loops and index management are harder to follow. Choose this for space-constrained problems.
- **Edge cases matter.** A single space or all non-alphanumeric characters become an empty string, which is a valid palindrome. Handle these before the main logic.
- Related: [Valid Anagram](../0242-valid-anagram/valid-anagram.md) also compares character sets, but with a different structure.
