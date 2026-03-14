# String Search

Three string search algorithms — **KMP**, **Boyer-Moore**, and a **Trie** for prefix-based key lookup.

---

## Knuth-Morris-Pratt (KMP)

Linear-time substring search. Avoids redundant comparisons by precomputing a **failure function** that tells the algorithm how far to shift the pattern when a mismatch occurs.

- `failureFunction(pattern)` — builds the shift table in O(m)
- `kmp(text, pattern, F)` — searches text in O(n), returns index of first match or -1

### Run

```bash
make KMP && ./KMP
```

```
Enter text: abcabcabd
Enter pattern: abcabd

Match found at position 3
```

---

## Trie

A prefix tree that maps string keys to integer items. Each node holds an array of 26 child pointers (one per lowercase letter). Inserting a key character-by-character means all words sharing a prefix share the same path.

- Supports: `TrieInsert`, `showTrie`, `freeTrie`
- `showTrie` prints each stored word branch-by-branch with dashes indicating depth

### Run

```bash
make trieTester && ./trieTester
```

---

## Boyer-Moore

Right-to-left pattern matching using a **last-occurrence function**. When a mismatch occurs, the pattern is shifted by the maximum of two heuristics — often skipping large sections of text.

- `lastOccurance(pattern, alphabet)` — builds the last-occurrence table (indexed by ASCII)
- Search loop matches right-to-left, shifts by `m - min(j, 1 + L[text[i]])`

### Run

```bash
make boyer-moore && ./boyer-moore
```

```
Enter alphabet: abcde
Enter text: abacaabadcabacabadc
Enter pattern: abacab

L[a] = 4
L[b] = 5
L[c] = 3
L[d] = -1
L[e] = -1

Match found at position 10.
```

---

## Files

| File | Purpose |
|------|---------|
| `src/KMP.c` | KMP failure function + search + interactive demo |
| `src/boyer_moore.c` | Boyer-Moore last-occurrence search + interactive demo |
| `include/Trie.h` | Trie ADT interface |
| `src/Trie.c` | Trie implementation (26-way branching, lowercase letters) |
| `src/trieTester.c` | Inserts a set of words and displays the resulting trie |
