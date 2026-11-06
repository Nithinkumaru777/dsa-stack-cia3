/**
 * CIA-3: Data Structures Using C++
 * Student: Nithin Kumar U | USN: 2102508611 | Section 2 | Semester 3
 * Institution: NIAT x S-Vyasa University
 * Faculty: Prof. G. Satya Aparna
 *
 * Topic: Introduction to Stack (LIFO, core operations, fixed and dynamic stacks)
 * Build: g++ -std=c++17 main.cpp -o main
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>

class Stack {
private:
    std::vector<int> data;
    int capacity; // -1 for dynamic, >0 for fixed

public:
    explicit Stack(int maxCap = -1) : capacity(maxCap) {}

    bool isEmpty() const { return data.empty(); }
    bool isFull() const { return (capacity > 0) && (data.size() >= static_cast<size_t>(capacity)); }

    void push(int val) {
        if (isFull()) throw std::overflow_error("Stack Overflow");
        data.push_back(val);
    }

    int pop() {
        if (isEmpty()) throw std::underflow_error("Stack Underflow");
        int topVal = data.back();
        data.pop_back();
        return topVal;
    }

    int peek() const {
        if (isEmpty()) throw std::underflow_error("Stack is Empty");
        return data.back();
    }

    size_t size() const { return data.size(); }
};

static int passed = 0;

static void report(const char* name, bool ok) {
    std::cout << "Test " << (passed + 1) << ": " << name << (ok ? " [PASSED]\n" : " [FAILED]\n");
    assert(ok);
    if (ok) passed++;
}

// True only if calling fn throws exactly the exception type E.
template <typename E, typename F>
static bool throwsExactly(F fn) {
    try { fn(); } catch (const E&) { return true; } catch (...) { return false; }
    return false;
}

int main() {
    std::cout << "=== CIA-3: Stack Demonstration ===\n";
    std::cout << "Nithin Kumar U (USN: 2102508611)\n\n";

    std::cout << "--- Walkthrough: fixed stack, capacity 4 ---\n";
    Stack demo(4);
    for (int v : {10, 20, 30}) {
        demo.push(v);
        std::cout << "[Step] push(" << v << ") -> size " << demo.size() << "\n";
    }
    std::cout << "[Step] peek() -> " << demo.peek() << ", size " << demo.size() << "\n";
    for (int i = 0; i < 3; i++) {
        int v = demo.pop();
        std::cout << "[Step] pop() -> " << v << ", size " << demo.size() << "\n";
    }

    std::cout << "\n--- Automated Test Suite ---\n";
    {
        Stack s;
        report("new stack is empty", s.isEmpty() && s.size() == 0);
    }
    {
        Stack s;
        s.push(10); s.push(20); s.push(30);
        int a = s.pop(), b = s.pop(), c = s.pop();
        report("pop order is LIFO", a == 30 && b == 20 && c == 10 && s.isEmpty());
    }
    {
        Stack s;
        s.push(7);
        int a = s.peek(), b = s.peek();
        report("peek does not remove", a == 7 && b == 7 && s.size() == 1);
    }
    {
        Stack s;
        s.push(1); s.push(2); s.push(3); s.pop();
        report("push 1 2 3, pop, peek gives 2", s.peek() == 2);
    }
    {
        Stack s(2);
        bool before = s.isFull();
        s.push(1);
        bool mid = s.isFull();
        s.push(2);
        report("isFull only at capacity", !before && !mid && s.isFull());
    }
    {
        Stack s(1);
        s.push(1);
        bool threw = throwsExactly<std::overflow_error>([&] { s.push(2); });
        report("push on full throws overflow", threw && s.size() == 1 && s.peek() == 1);
    }
    {
        Stack s;
        report("pop on empty throws underflow", throwsExactly<std::underflow_error>([&] { s.pop(); }));
    }
    {
        Stack s;
        report("peek on empty throws underflow", throwsExactly<std::underflow_error>([&] { s.peek(); }));
    }
    {
        Stack s(1);
        s.push(5); s.pop();
        report("slot is reusable after pop", !s.isFull() && s.isEmpty());
    }
    {
        Stack s;
        bool everFull = false, order = true;
        for (int i = 0; i < 10000; i++) { s.push(i); everFull = everFull || s.isFull(); }
        for (int i = 9999; i >= 0; i--) order = order && s.pop() == i;
        report("dynamic stack holds 10000 values", !everFull && order && s.isEmpty());
    }

    std::cout << "\nAll " << passed << " tests passed\n";
    return 0;
}
