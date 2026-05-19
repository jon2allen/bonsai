# Bonsai vs Mistral AI - Comparison Tests

A collection of test comparisons between Bonsai and Mistral AI across various programming and system tasks.

**Author:** Jon Allen  
**Date:** May 2026  
**License:** [MIT](LICENSE)

---

## Overview

This repository contains the results of five comparative tests evaluating Bonsai against Mistral AI models on different types of tasks:

| Test | Description | Files |
|------|-------------|-------|
| **#1** | Linux Commands | `linux_cmd_testing.chatdsl`, `linux_cmd_testing_actual/` |
| **#2** | Bash Scripting | `bash_testing.chatdsl`, `bash_testing_actual/` |
| **#3** | C++ Code Generation | `cpp_algorithms.chatdsl`, `cpp_algorithms_actual/` |
| **#4a** | Needle in Haystack (Hard) | `haystack_test.chatdsl`, `haystack_test_actual/` |
| **#4b** | Needle in Haystack (Easy) | `easy_haystack.chatdsl` |
| **#5** | Tokens Per Second | `tps+20260519_*.csv` |

---

## Test Details

### Test #1: Linux Commands
Evaluates the ability to generate and execute correct Linux shell commands for common system operations.

- **Prompt/Input:** `linux_cmd_testing.chatdsl`
- **Results:** `linux_cmd_testing_actual/`
  - `mistral_1_linux_commands.txt` - Mistral AI output
  - `prism_bonsai_linux_commands.txt` - Bonsai output
  - `comparison_report.txt` - Side-by-side comparison
  - `final_scores.txt` - Test scores
  - `final_verdict.txt` - Evaluation summary

### Test #2: Bash Scripting
Evaluates the ability to write functional bash scripts for various automation tasks.

- **Prompt/Input:** `bash_testing.chatdsl`
- **Results:** `bash_testing_actual/`
  - `mistral_1_bash_scripts.txt` - Mistral AI output
  - `prism_bonsai_bash_scripts.txt` - Bonsai output
  - `comparison_report.txt` - Side-by-side comparison
  - `final_scores.txt` - Test scores
  - `final_verdict.txt` - Evaluation summary

### Test #3: C++ Code Generation
Evaluates the ability to generate correct, compilable C++ code for algorithmic problems.

- **Prompt/Input:** `cpp_algorithms.chatdsl`
- **Results:** `cpp_algorithms_actual/`
  - `mistral_1_cpp_algorithms.txt` - Mistral AI output
  - `prism_bonsai_cpp_algorithms.txt` - Bonsai output
  - `prismml/` - Generated C++ programs (1-10)
  - `compilation_results.md` - Build status for each program
  - `comparison_report.txt` - Side-by-side comparison
  - `final_scores.txt` - Test scores
  - `final_verdict.txt` - Evaluation summary

### Test #4a: Needle in Haystack (Hard)
Evaluates the ability to find specific information within large blocks of text with **multiple distractor UUIDs** (contextual retrieval). The hard version contains 5 identical decoy UUIDs and 1 unique `hay_key:` target, where the unique UUID is off by one character from the others.

- **Prompt/Input:** `haystack_test.chatdsl`
- **Results:** `haystack_test_actual/`
  - `mistral_1_haystack_result.txt` - Mistral AI output
  - `prism_bonsai_haystack_result.txt` - Bonsai output
  - `comparison_report.txt` - Side-by-side comparison
  - `final_scores.txt` - Test scores
  - `final_verdict.txt` - Evaluation summary

### Test #4b: Needle in Haystack (Easy)
Simplified version with **exactly one UUID** in the text. The `easy_key:` appears only once, making it easier to locate.

- **Prompt/Input:** `easy_haystack.chatdsl`
- **Key:** `easy_key: 8081C452-F5C9-4938-A00A-EB91A0DA71D4`
- **Results:** `easy_haystack_test_actual/` (to be generated on run)
  - `prism_bonsai_easy_haystack_result.txt` - Bonsai output
  - `mistral_1_easy_haystack_result.txt` - Mistral AI output
  - `comparison_report.txt` - Side-by-side comparison
  - `final_scores.txt` - Test scores
  - `final_verdict.txt` - Evaluation summary

### Test #5: Tokens Per Second (TPS)
Performance benchmark measuring token generation speed.

- **First CSV:** `tps+20260519_105105.csv` - **Bonsai** performance data
- **Remaining CSVs:** Mistral AI performance data
  - `tps+20260519_105151.csv`
  - `tps+20260519_105220.csv`
  - `tps+20260519_105227.csv`
  - `tps+20260519_105258.csv`

---

## Repository Structure

```
bonsai/
├── README.md           # This file
├── LICENSE            # MIT License
├── .gitignore         # Excludes object files and build artifacts
├── linux_cmd_testing.chatdsl
├── linux_cmd_testing_actual/
├── bash_testing.chatdsl
├── bash_testing_actual/
├── cpp_algorithms.chatdsl
├── cpp_algorithms_actual/
│   └── prismml/
│       ├── program_1.cpp ... program_10.cpp
│       └── compilation_results.md
├── haystack_test.chatdsl
├── haystack_test_actual/
├── easy_haystack.chatdsl
├── logic_problems.chatdsl
├── pascal_algorithms.chatdsl
├── pascal_test2.chatdsl
├── test_vortex_dsl.chatdsl
├── test_vortex_dsl_advanced.chatdsl
└── tps+20260519_*.csv # TPS benchmark files (Bonsai + Mistral AI)
```

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
