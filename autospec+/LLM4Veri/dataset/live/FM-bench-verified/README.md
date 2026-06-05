---
license: apache-2.0
task_categories:
  - text2text-generation
tags:
  - code
---

<p align="center">
  <img width="20%" src="./figures/logo-fmbench-verified.png">
</p>

## Introduction

This dataset **`FM-Bench-Verified`** is a manual-cleaned and verified benchmark which contains 280 C programs, properties under verification, together with ground-truth ACSL specifications. 

This dataset can be used for:

- **Specification generation task (Code2Proof)**: given program and properties to be verified as input, output program with specification that can pass the prover.


It comes from three sources: 

- [FM-bench](https://huggingface.co/datasets/fm-universe/FM-bench)
- [AutoSpec](https://sites.google.com/view/autospecification)
- Github repositories


## Statistics of FM-Bench-Verified

FM-Bench-Verified contains 280 cases. Each case contains: 

- A program written in C  
- At least one property under verification
- Formal specifications that can verify that the program satisfies the target property

All 280 cases (C program + specification) can be verified through **Frama-C's WP (Weakest Precondition) verification**. 

The table below shows the statistics of the 280 cases in FM-Bench-Verified:

| Source   | Repo Name         | Number | Avg-LoC | Ave-LoS | Max_LoC | Max_LoS |
| -------- | ------------------- | ------ | ------- | ------------ | ------- | ------------ |
| FM-Bench  | ACSL-by-Example     | 45     | 24.4    | 59.6         | 43      | 130          |
|          | FRAMA-C-problems    | 40     | 11.5    | 8.5          | 20      | 25           |
| Github   | evdenis             | 16     | 12.6    | 9.6          | 25      | 25           |
|          | corinnt             | 16     | 11.9    | 14.7         | 21      | 45           |
|          | nabinkrsah          | 12     | 14.8    | 9.9          | 20      | 20           |
|          | 21176               | 9      | 10.7    | 7.2          | 15      | 14           |
|          | arepina             | 9      | 18.4    | 11.4         | 32      | 19           |
|          | frama-c-wp-tutorial | 7      | 11.5    | 7.5          | 22      | 15           |
|          | nikunjjain02        | 6      | 15.6    | 11.5         | 26      | 19           |
|          | suman1406           | 5      | 18.2    | 14.6         | 22      | 25           |
|          | others(number <=3)  | 8      | 13.5    | 12.5         | 20      | 22           |
| AutoSpec | SyGuS               | 102    | 11.8    | 10.8         | 20      | 18           |
|          | X509                | 5      | 40.4    | 16.6         | 55      | 24           |
| All      |                     | 280    | 16.6    | 15.0         | 55      | 130          |


Annotations:
- *Source*: the data source
- *Repo Name*: the repository name
- *Number*: number of programs from the corresponding repository
- *Ave-LoC*: average lines of code
- *Ave-LoS*: average lines of specification
- *Max-LoC*: maximum lines of code
- *Max-LoS*: maximum lines of specification
