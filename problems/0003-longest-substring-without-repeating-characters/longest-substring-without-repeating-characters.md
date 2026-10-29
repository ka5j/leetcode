---
number: 3
title: Longest Substring Without Repeating Characters
slug: longest-substring-without-repeating-characters
difficulty: Medium
topics: Hash Table, String, Sliding Window
status: Solved
date: 2026-10-28
review: true
review_reason: Sliding window logic - kept the window at a fixed size instead of letting it shrink and grow; out-of-bounds errors
---

# 3. Longest Substring Without Repeating Characters

[LeetCode problem](https://leetcode.com/problems/longest-substring-without-repeating-characters/) · [C++ solution](longest-substring-without-repeating-characters.cpp)

## Problem

Given a string `s`, find the length of the **longest substring** without duplicate characters.

**Example 1:**

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

**Example 2:**

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

**Constraints:**

- 0 <= `s.length` <= 5 * 10<sup>4</sup>
- `s` consists of English letters, digits, symbols and spaces.

## Approach

### 1. Brute force

Check every substring and test whether it has repeated characters, keeping the longest one that doesn't.

- Time: O(n<sup>3</sup>), or O(n<sup>2</sup>) if each starting point extends until its first repeat using a set
- Space: O(min(n, m)), where m is the size of the character set

### 2. Variable-size sliding window with a count map (my solution)

Keep a window `[ptr1, ptr2]` that never contains a repeated character, and a hash map counting the characters inside it.

1. Move `ptr2` forward one character at a time and add that character to the map.
2. If its count goes above 1, the window now has a duplicate. Shrink it from the left: decrement the count of `s[ptr1]` and move `ptr1` forward until the duplicate is gone.
3. The window is now valid, so update the best length with `ptr2 - ptr1 + 1`.

Each pointer only moves forward and visits each character at most once, so the total work is linear.

- Time: O(n)
- Space: O(min(n, m))

### 3. Sliding window with last-seen indices

Store the last index where each character appeared instead of a count. When `s[ptr2]` was last seen inside the current window, jump `ptr1` straight past that index instead of shrinking one step at a time. It has the same complexity, with fewer pointer moves.

- Time: O(n)
- Space: O(min(n, m))

## Complexity

My solution (approach 2):

- Time: O(n)
- Space: O(min(n, m)), where m is the size of the character set

## Notes

- **The window size is not fixed.** My first attempt kept the window at the largest size found so far. That's wrong for this problem: the window grows when the next character is new and shrinks when it creates a duplicate. The answer is the largest size the window ever reaches, so track it separately in `max_len`.
- **Shrink until valid, then measure.** Update `max_len` only after the inner `while` loop has removed the duplicate, so every length you record belongs to a valid substring.
- **Out-of-bounds errors.** Moving two pointers by hand made it easy to read past the end of the string. Driving `ptr2` with the `for` loop and only ever moving `ptr1` forward up to `ptr2` keeps both indices inside the string.
- **Count map vs set.** Counts work, but a character is only ever in the window 0 or 1 times, so an `unordered_set` (or a fixed array of 128 counters for ASCII) would do the same job.
