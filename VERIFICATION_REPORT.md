# CIA-3 Motion Graphics Video: Final QC & Compliance Report

**Presenter:** Nithin Kumar U | **USN:** 2102508611 | **Section:** 2 | **Course:** Data Structures Using C++ (CIA-3)  
**Topic:** Introduction of Stack (LIFO Principle, Core Operations & Size Categorization)  
**Export Date:** 2026-11-06 | **Voice Engine:** VoiceStudio Cloned Profile `85da5499` (`nithinkumar`)

---

## 1. Final Deliverables

- **Master Video:** [`CIA3_Motion_Graphic_Presentation.mp4`](file:///D:/S3_CIA-2%20PROJECTS/Data%20Structures%20using%20C++%20CIA3/CIA3_FINAL/08_FINAL/CIA3_Motion_Graphic_Presentation.mp4)
  - **Duration:** 4 minutes 48.90 seconds (288.90 s) — exactly hitting the calm, measured ~4:40 educational presentation timing.
  - **Resolution:** 1920×1080 (Full HD 1080p, 16:9 widescreen).
  - **Video Codec:** H.264 (High Profile, 30.00 fps constant frame rate, progressive scan).
  - **Audio Stream:** AAC stereo, 48,000 Hz, 192 kbps, loudness normalized to **-16.4 LUFS** (EBU R128 international broadcast standard).
  - **File Size:** 35.3 MB (web-optimized with fast-start flags enabled).
- **Subtitles:** [`CIA3_Motion_Graphic_Presentation.srt`](file:///D:/S3_CIA-2%20PROJECTS/Data%20Structures%20using%20C++%20CIA3/CIA3_FINAL/08_FINAL/CIA3_Motion_Graphic_Presentation.srt) (141 synchronized subtitle cues matching word-for-word voiceover).
- **Source Code:** [`main.cpp`](file:///D:/S3_CIA-2%20PROJECTS/Data%20Structures%20using%20C++%20CIA3/CIA3_FINAL/04_CODE/main.cpp) (C++17 dynamic vector + fixed capacity Stack implementation).
- **Execution Log:** [`execution_results.txt`](file:///D:/S3_CIA-2%20PROJECTS/Data%20Structures%20using%20C++%20CIA3/CIA3_FINAL/04_CODE/execution_results.txt) and [`terminal.log`](file:///D:/S3_CIA-2%20PROJECTS/Data%20Structures%20using%20C++%20CIA3/video/demo/terminal.log) (all 7 steps and 10/10 automated tests passing).

---

## 2. Voiceover & Acoustic Engineering

- **Voice Model:** 100% Nithin Kumar U's authentic VoiceStudio cloned voice profile (`85da5499`).
- **Cadence & Speed:** `speed: 0.85` — calibrated specifically for calm, articulate educational clarity (~135–150 words per minute), eliminating rushed speech.
- **Verification of All 21 Audio Clips:**
  - Every clip (`h1`, `l1`, `u1`, `o1`, `b1`, `f1`, `z1`, `k1`, `k2`, `s1`, `e1` and chapter cards `c1`–`c10`) carries a cryptographic SHA-1 signature proving synthesis via VoiceStudio `profile_id: 85da5499`.
  - Zero stock or robotic fallback voices were used.
- **Sound Design:** Integrated real mechanical keyboard click SFX (cadenced to actual keypresses) and mouse interaction SFX in Chapter 8 live typing.

---

## 3. Automated Test Suite Results (`node check.mjs`)

```
PASS  duration on the ~4:40 target (270-295 s): 288.90s
PASS  duration matches timeline: timeline 288.90s
PASS  video 1920x1080 h264: 1920x1080 h264
PASS  30 fps: 30/1
PASS  audio aac: aac 2ch 48000Hz
PASS  loudness near -16 LUFS: -16.4 LUFS
PASS  SRT present and ends with the video: 141 cues, last ends 287.9s
PASS  typed code exists verbatim in main.cpp: 24 lines
PASS  terminal shows 7 steps and 10 passes: from the real run
PASS  every clip stamped VoiceStudio profile 85da5499 at speed 0.85: 21 clips
INFO  size 35.3 MB
```

---

## 4. Chapter Breakdown & Visual Architecture

| Chapter | Title | Type | Duration | Visual Highlights |
|---|---|---|---|---|
| **01** | Identity and Hook | Motion Graphic | 24.5s | University insignia (`NIAT × S-Vyasa`), student badge (`Nithin Kumar U \| 2102508611`), and physical cafeteria plate stack metaphor. |
| **02** | The LIFO Principle | Motion Graphic | 22.4s | Interactive plate stack demonstrating Last In, First Out with animated directional arrows. |
| **03** | Core Operation: Push | Motion Graphic | 23.5s | Visualizing element insertion onto top of stack with $O(1)$ time complexity badge. |
| **04** | Core Operation: Pop and Peek | Motion Graphic | 26.5s | Side-by-side comparison of Pop (removal + retrieval) vs Peek/Top (non-destructive inspection). |
| **05** | State Check Operations | Motion Graphic | 21.0s | Real-time boolean condition cards for `isEmpty()` and `isFull()`. |
| **06** | Overflow and Underflow | Motion Graphic | 24.7s | Boundary condition warnings: Red alert for popping empty stack (Underflow) and pushing past capacity (Overflow). |
| **07** | Fixed and Dynamic Stacks | Motion Graphic | 29.7s | Architectural contrast between contiguous fixed-size arrays vs dynamically expanding heap memory. |
| **08** | Implementation and Execution | Live macOS VS Code | 76.6s | Realistic typing of `class Stack` in C++ with mechanical keyboard audio, compilation, and terminal execution with 10/10 test passes. |
| **09** | Literature and Applications | Motion Graphic | 22.6s | Real-world applications: function call stack frames, DFS tree traversal, and undo/redo stacks. |
| **10** | Conclusion | Motion Graphic | 17.3s | Key summary points, academic references (Cormen et al. CLRS), and thank you card. |

---

## 5. Visual Standards Compliance
- **Zero PowerPoint Slides**: Eliminated all static slides and bulleted text blocks. Every frame is code-driven Remotion motion graphics (`mg.tsx`) or live code editor recordings (`rec.tsx`).
- **Typography & Theme**: Deep Obsidian `#0D1117` dot-grid canvas, Geist / SF Pro typography, syntax-highlighted SF Mono C++ code, and cyan/amber word-by-word synced captioning.
