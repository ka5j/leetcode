---
number: 271
title: Encode and Decode Strings
slug: encode-and-decode-strings
difficulty: Medium
topics: Array, String, Design
status: Solved
date: 2026-11-01
solves: 1
review: true
review_reason: Designing the format (lengths need an end marker) and handling empty strings
link: https://neetcode.io/problems/string-encode-and-decode
---

# 271. Encode and Decode Strings

[NeetCode problem](https://neetcode.io/problems/string-encode-and-decode) · [C++ solution](encode-and-decode-strings.cpp)

## Problem

Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

```
String encode(List<String> strs) {
    // ... your code
    return encoded_string;
}
```

Machine 2 (receiver) has the function:

```
List<String> decode(String encoded_string) {
    // ... your code
    return decoded_strs;
}
```

So Machine 1 does:

```
String encoded_string = encode(strs);
```

and Machine 2 does:

```
List<String> decoded_strs = decode(encoded_string);
```

`decoded_strs` in Machine 2 should be the same as the input `strs` in Machine 1.

Implement the `encode` and `decode` methods.

**Example 1:**

```
Input: strs = ["Hello","World"]
Output: ["Hello","World"]
Explanation:
Solution solution = new Solution();
String encoded_string = solution.encode(strs);

// Machine 1 ---encoded_string---> Machine 2

List<String> decoded_strs = solution.decode(encoded_string);
```

**Example 2:**

```
Input: strs = [""]
Output: [""]
```

**Constraints:**

- 0 <= `strs.length` < 100
- 0 <= `strs[i].length` < 200
- `strs[i]` contains any possible characters out of 256 valid ASCII characters.

**Follow-up:** Could you write a generalized algorithm to work on any possible set of characters?

## Approach

### 1. Shift each character by 1 (first idea, incorrect)

Add 1 to each character's ASCII value in `encode` and subtract 1 in `decode`. The shift is reversible, but it doesn't record where one string ends and the next begins. `["ab", "c"]` and `["a", "bc"]` both encode to `"bcd"`, and `[]` and `[""]` both encode to an empty string.

### 2. Length prefix with no separator (second attempt, incorrect)

Write each string's length in front of it. This solves the boundary problem, but only while lengths are one digit. Once lengths can reach 199, `"12abc..."` could mean a string of length 12, or a string of length 1 (`"2"`) followed by something else, since a string's content can start with digits.

### 3. Length prefix with a separator (my solution)

Encode each string as its length, then `|`, then the string itself, so `["a,b", "", "#", "12"]` becomes `"3|a,b0|1|#2|12"`.

To decode, repeat for each string:

1. Read digits up to the first `|` to get the length.
2. Read exactly that many characters as the string, without inspecting them.
3. If the length is 0, the string is already complete, so add `""` straight away.

The `|` only ever ends a length. Content is counted rather than searched, so strings can safely contain `|` or digits: `["|"]` encodes to `"1||"` and decodes correctly.

- Time: O(m + n), where m is the total number of characters and n is the number of strings
- Space: O(m + n) for the encoded string and the decoded list

## Complexity

My solution (approach 3):

- Time: O(m + n)
- Space: O(m + n)

## Notes

- **The real problem is boundaries.** Changing the characters doesn't help. The encoded string has to tell the decoder where each string stops, for every possible input.
- **A separator alone can't work.** Strings can contain any of the 256 ASCII characters, so any marker could also appear inside a string. Counting characters avoids this, and it's why the format also answers the follow-up: it never depends on which characters a string contains, as long as both sides count lengths the same way.
- **Empty strings.** I only checked for a finished string after pushing a character, and an empty string has no characters to push. `[""]` came back as `[]`. The check has to happen as soon as the length is read. Hardcoding the `"0|"` input passed Example 2 but still failed `["", ""]` and `["a", ""]`.
- **Reset state for the next string.** Not resetting `numRuns` broke every string after the first, and clearing `outStr` before saving it made every string come out empty.
- **To try on the re-solve:** make `decode` shorter. Once the length is known, do the characters need to be read one at a time, and are the flags and counters needed at all?
