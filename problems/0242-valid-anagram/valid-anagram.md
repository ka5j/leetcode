---
number: 242
title: Valid Anagram
slug: valid-anagram
difficulty: Easy
topics: Hash Table, String, Sorting
status: Solved
date: 2026-10-22
---

# 242. Valid Anagram

[LeetCode problem](https://leetcode.com/problems/valid-anagram/) · [C++ solution](valid-anagram.cpp)

## Problem

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

**Example 1:**

```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**

```
Input: s = "rat", t = "car"
Output: false
```

**Constraints:**

- 1 <= `s.length`, `t.length` <= 5 * 10<sup>4</sup>
- `s` and `t` consist of lowercase English letters.

**Follow-up:** What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

## Approach

### 1. Hash one string, look up the other (first attempt, incorrect)

Hash the characters of `s`, then loop over `t` and return `false` if a character of `t` is not in the map. This fails because a character can occur more than once. `"aab"` and `"abb"` contain the same set of characters but are not anagrams, so presence alone isn't enough and the counts have to match.

### 2. Two hash maps of counts (my solution)

1. If the lengths differ, return `false`.
2. Build a count map for `s` and a count map for `t`.
3. For each character in `t`, check that it exists in `s`'s map and that both maps hold the same count for it.
4. If every character passes, return `true`.

Since the lengths are equal, matching counts for every character of `t` also guarantees `s` has no leftover characters.

- Time: O(n)
- Space: O(k), where k is the number of distinct characters (at most 26 here)

### 3. One map with increment and decrement

Use a single map. Add 1 for each character of `s` and subtract 1 for each character of `t`. The strings are anagrams if every count ends at 0. This halves the memory and removes the comparison pass.

- Time: O(n)
- Space: O(k)

### 4. Fixed array of 26 counters

The input is lowercase letters only, so a fixed `int[26]` indexed by `c - 'a'` can replace the hash map. The increment-and-decrement idea from approach 3 applies unchanged. This is the fastest in practice, since an array access is a direct memory lookup, and the space is truly O(1).

- Time: O(n)
- Space: O(1)

### 5. Sort both strings

Sort `s` and `t` and compare them. Anagrams become identical after sorting.

- Time: O(n log n)
- Space: O(1) extra with an in-place sort, or O(n) if copies are needed

## Complexity

My solution (approach 2):

- Time: O(n)
- Space: O(k), effectively O(1) for lowercase letters

## Notes

- **Presence is not enough.** My first idea only checked whether characters existed, which fails when a character repeats. Anagrams need the same count of every character, not just the same set of characters.
- **Increment and decrement.** Using `++` for one string and `--` for the other in a single map (or array) is cleaner than two maps, since the strings are anagrams exactly when everything cancels to 0.
- **Fixed array.** The fixed `int[26]` works because the character set is small and known up front. It was not the first thing I thought of, but it is the best fit for the lowercase-only constraint.
- **Unicode follow-up.** The fixed array no longer works, since the character range is far too large. A hash map handles it, because it only stores characters that actually appear. One `char` is also not one Unicode character, since UTF-8 characters can span several bytes, so the counts would need to be over decoded code points.
