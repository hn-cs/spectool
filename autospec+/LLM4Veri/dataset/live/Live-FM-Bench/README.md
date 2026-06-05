---
license: apache-2.0
task_categories:
  - text2text-generation
tags:
  - code
---

<p align="center">
  <img width="20%" src="figures/logo-livefmbench.png">
</p>

## Introduction

This dataset **`Live-FM-bench`** is continuously updated and contamination-free evaluation benchmark of LLMs for program verification (a.k.a., formal specification generation). Currently, it contains 360 C programs under verification together with the properties to be verified. 

This dataset can be used for:

- **Specification generation task (Code2Proof)**: given program and properties to be verified as input, output program with specification that can pass the prover.


Its source: 
- [SV-COMP 2025](https://sv-comp.sosy-lab.org/2025/) which released in May 5, 2025. LLMs whose cut-off date was earlier than that are free of data contamination to this dataset. 


## Statistics of Live-FM-Bench

Live-FM-Bench contains 360 cases. Each case contains: 

- A program written in C  
- At least one property under verification

| Source    | Folder Name                 | Number | Avg-LoC | Max-LoC | Avg-assert |
|-----------|-----------------------------|--------|---------|---------|------------|
| sv-comp25 | array-cav19                 | 11     | 21      | 28      | 1.6        |
|           | array-crafted               | 30     | 43.8    | 64      | 1          |
|           | array-examples              | 31     | 31.8    | 56      | 1.3        |
|           | array-fpi                   | 67     | 36.4    | 47      | 1.9        |
|           | array-industry-pattern      | 11     | 36.5    | 51      | 1          |
|           | array-lopstr16              | 9      | 32.6    | 51      | 1          |
|           | array-multidimensional      | 13     | 52.9    | 78      | 1.2        |
|           | array-programs              | 13     | 22.5    | 36      | 1.2        |
|           | array-tiling                | 19     | 41.3    | 66      | 1.5        |
|           | heap-data                   | 10     | 44.7    | 67      | 1.3        |
|           | loop-acceleration           | 16     | 14.8    | 33      | 1          |
|           | loop-crafted                | 14     | 14.2    | 17      | 1.2        |
|           | loop-invariants             | 7      | 16.1    | 21      | 1          |
|           | loop-invgen                 | 4      | 34.2    | 54      | 4.2        |
|           | loop-lit                    | 24     | 21      | 38      | 2.3        |
|           | loop-new                    | 2      | 20      | 22      | 1          |
|           | loop-zilu                   | 51     | 18.7    | 25      | 1          |
|           | loops:                      | 4      | 28.5    | 46      | 1          |
|           | loops-crafted-1             | 22     | 22.2    | 66      | 1.2        |
|           | recursified_loop-crafted    | 2      | 24      | 24      | 2          |
|           | recursified_loop-invariants | 5      | 28.4    | 38      | 1          |
|           | reducercommutativity:       | 5      | 41.4    | 43      | 1          |
| ALL       |                             | 360    | 30.3    | 78      | 1.4        |

Annotations:
- *Source*: the data source
- *Folder Name*: the repository name
- *Number*: number of programs from the corresponding repository
- *Ave-LoC*: average lines of code
- *Max-LoC*: maximum lines of code
- *Avg-assert*: average lines of assertions