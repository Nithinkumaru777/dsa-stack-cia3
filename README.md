# Data Structures Using C++ (CIA-3): Introduction of Stack

> **Student:** NITHIN KUMAR U · **USN:** 2102508611 · **Section:** 2  
> **Course:** Data Structures Using C++ (CIA-3) · **Module:** 3  
> **Topic:** Introduction of Stack (LIFO Principle, Core Primitives, Exception Invariants & Size Categorization)  
> **Faculty Evaluator:** Prof. G. Satya Aparna  
> **Date:** November 2026

---

## 1. Executive Summary

A **Stack** is a linear abstract data structure governed by the **Last In, First Out (LIFO)** access discipline. Mutations and inspections are strictly restricted to a single logical boundary designated as **TOP**. 

This repository delivers the complete, verified academic submission for CIA-3, including:
- **C++17 Implementation:** Robust `class Stack` encapsulating fixed and dynamic size modes, throwing standard exceptions on boundary violations.
- **Automated Verification:** 7 live walkthrough stages and 10/10 automated unit test assertions passing with zero defects.
- **Editorial Presentation Deck:** 10-slide PowerPoint presentation ([`2102508611_NithinKumarU_Stack_CIA3.pptx`](./2102508611_NithinKumarU_Stack_CIA3.pptx)) covering theory, complexity, and systems architecture.
- **Motion Graphics Video:** 4:48 Remotion code-driven presentation with word-by-word highlighted subtitles and VoiceStudio cloned speech.

---

## 2. Core Stack Operations & Time Complexities

| Primitive | Description | Pre-Condition Guard | Post-Condition State | Time Complexity | Space Complexity |
|---|---|---|---|---|---|
| `push(val)` | Inserts `val` at the top of the stack | `!isFull()` (Fixed size) | Size increments by 1; `top == val` | **$O(1)$** | $O(1)$ |
| `pop()` | Extracts and returns topmost element | `!isEmpty()` | Size decrements by 1; removes top | **$O(1)$** | $O(1)$ |
| `peek()` / `top()` | Inspects topmost element non-destructively | `!isEmpty()` | State unchanged | **$O(1)$** | $O(1)$ |
| `isEmpty()` | Evaluates if element count is 0 | None | Returns boolean | **$O(1)$** | $O(1)$ |
| `isFull()` | Evaluates if count equals fixed capacity | None | Returns boolean | **$O(1)$** | $O(1)$ |

---

## 3. Boundary Failure Modes

1. **Stack Overflow:** Attempting to `push()` into a fixed-capacity stack when `size >= capacity`. Guarded by throwing `std::overflow_error`.
2. **Stack Underflow:** Attempting to `pop()` or `peek()` from an empty stack when `size == 0`. Guarded by throwing `std::underflow_error`.

---

## 4. Architectural Comparison: Fixed vs. Dynamic Size Stacks

| Architectural Metric | Fixed-Size Stack (Static Array) | Dynamic-Size Stack (Vector / Heap) |
|---|---|---|
| **Capacity Management** | Predefined constant allocated at initialization | Elastic; grows dynamically as elements are pushed |
| **Memory Allocation** | Contiguous static stack or fixed heap segment | Dynamically reallocated heap buffers |
| **Overflow Vulnerability** | Throws `std::overflow_error` when capacity is reached | Constrained only by physical system RAM |
| **Cache Performance** | Optimal contiguous cache line locality | Excellent amortized locality with vector backing |
| **Reallocation Overhead** | $0$ reallocation overhead | Occasional $O(N)$ geometric doubling (amortized $O(1)$) |

---

## 5. C++ Class Implementation

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>

class Stack {
private:
    std::vector<int> data;
    int capacity; // -1 represents dynamic growth mode

public:
    explicit Stack(int cap = -1) : capacity(cap) {}

    bool isFull() const {
        return capacity > 0 && static_cast<int>(data.size()) >= capacity;
    }

    bool isEmpty() const {
        return data.empty();
    }

    int size() const {
        return static_cast<int>(data.size());
    }

    void push(int val) {
        if (isFull()) {
            throw std::overflow_error("Stack Overflow: capacity exceeded");
        }
        data.push_back(val);
    }

    int pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack Underflow: stack is empty");
        }
        int val = data.back();
        data.pop_back();
        return val;
    }

    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack Underflow: stack is empty");
        }
        return data.back();
    }
};
```

---

## 6. Automated Unit Test Verification (10/10 Passed)

```text
[Step 1] Initializing dynamic stack...
[Step 2] Pushing 10, 20, 30...
[Step 3] Peeking: 30
[Step 4] Popping: 30 -> New top: 20
[Step 5] Popping remaining: 20, 10 -> Is empty: true
[Step 6] Verifying underflow guard... Caught expected underflow_error
[Step 7] Verifying overflow guard on fixed stack (cap=2)... Caught expected overflow_error

--- RUNNING 10 AUTOMATED UNIT TESTS ---
Test 1: isEmpty on new stack ...................... [PASSED]
Test 2: size 0 on new stack ....................... [PASSED]
Test 3: push(10) isEmpty is false ................. [PASSED]
Test 4: peek returns top without removal .......... [PASSED]
Test 5: pop returns top and decrements size ....... [PASSED]
Test 6: LIFO order: push 1,2,3 -> pop 3,2,1 ....... [PASSED]
Test 7: underflow on pop throws exception ......... [PASSED]
Test 8: underflow on peek throws exception ........ [PASSED]
Test 9: fixed capacity isFull is true when full ... [PASSED]
Test 10: overflow throws exception ................ [PASSED]
============================================================
ALL 10 UNIT TESTS PASSED SUCCESSFULLY!
```

---

## 7. Deliverables & Cloud Artifacts

- **GitHub Repository:** [https://github.com/Nithinkumaru777/dsa-stack-cia3](https://github.com/Nithinkumaru777/dsa-stack-cia3)
- **Saved Code Snippet Gist:** [https://gist.github.com/Nithinkumaru777/06ddeedfcb18db237f9dcd728ee6c8fb](https://gist.github.com/Nithinkumaru777/06ddeedfcb18db237f9dcd728ee6c8fb)
- **Presentation Deck (PPTX):** [`2102508611_NithinKumarU_Stack_CIA3.pptx`](./2102508611_NithinKumarU_Stack_CIA3.pptx)
- **Video Presentation (MP4):** Downloadable via [GitHub Releases v1.0.0](https://github.com/Nithinkumaru777/dsa-stack-cia3/releases/tag/v1.0.0)
