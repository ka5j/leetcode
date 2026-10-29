---
number: 49
title: Group Anagrams
slug: group-anagrams
difficulty: Medium
topics: Array, Hash Table, String, Sorting
status: Solved
date: 2026-10-28
review: true
review_reason: C++ syntax (sorting a string, iterating a map, nested vectors); took a brute-force detour first
---

# 49. Group Anagrams

[LeetCode problem](https://leetcode.com/problems/group-anagrams/) · [C++ solution](group-anagrams.cpp)

## Problem

Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

**Example 1:**

```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

Explanation:

- There is no string in `strs` that can be rearranged to form `"bat"`.
- The strings `"nat"` and `"tan"` are anagrams as they can be rearranged to form each other.
- The strings `"ate"`, `"eat"`, and `"tea"` are anagrams as they can be rearranged to form each other.

**Example 2:**

```
Input: strs = [""]
Output: [[""]]
```

**Example 3:**

```
Input: strs = ["a"]
Output: [["a"]]
```

**Constraints:**

- 1 <= `strs.length` <= 10<sup>4</sup>
- 0 <= `strs[i].length` <= 100
- `strs[i]` consists of lowercase English letters.

## Approach

### 1. Brute force with pairwise anagram checks (first idea)

Take the first string, compare it against every remaining string using the [Valid Anagram](../0242-valid-anagram/valid-anagram.md) check, move all its anagrams into a group, and repeat on what's left. This is correct but slow: up to about n<sup>2</sup>/2 comparisons, each costing O(k), plus the cost of erasing from the middle of a vector.

- Time: O(n<sup>2</sup> · k)
- Space: O(n · k) for the output

### 2. Sorted string as a hash key (my solution)

All anagrams contain the same letters in the same quantities, so sorting any of them gives the same string (`"eat"`, `"tea"` and `"ate"` all become `"aet"`). Use that sorted string as a key in a hash map:

1. Copy the input and sort each copied string.
2. Map each sorted key to the list of indices of the strings that produced it.
3. For each key, collect the original strings at those indices into one group.

No two strings are ever compared directly, so one pass is enough.

- Time: O(n · k log k)
- Space: O(n · k)

### 3. Letter counts as a hash key

Instead of sorting, count the 26 letters of each string and turn the counts into a key string. This avoids the sort, so the time drops to O(n · k). The key needs separators or fixed-width counts, so that different counts like `1, 11` and `11, 1` can't produce the same key.

- Time: O(n · k)
- Space: O(n · k)

## Complexity

My solution (approach 2), where n is the number of strings and k is the length of the longest string:

- Time: O(n · k log k)
- Space: O(n · k)

## Notes

- **Turn comparisons into a label.** My first idea compared strings pair by pair. The breakthrough was computing a label for each string on its own, so that anagrams share a label, then grouping by label in a hash map.
- **Summing character values doesn't work as a label.** `"ad"` and `"bc"` both sum to 197 but aren't anagrams. The label has to keep exactly which letters appear and how many times.
- **Simpler version.** Storing the original strings directly in an `unordered_map<string, vector<string>>` (sorting a temporary copy for the key) would remove the input copy and the index indirection.
- **C++ I learned here:**
  - Sorting a string in place with `sort(s.begin(), s.end())`.
  - Iterating an `unordered_map` with an iterator, where `it->first` is the key and `it->second` is the value.
  - Building a `vector<vector<string>>` by filling an inner vector and pushing it into the outer one.
- Related: [Valid Anagram](../0242-valid-anagram/valid-anagram.md) (the same anagram check, for two strings).
