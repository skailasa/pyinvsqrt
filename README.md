<h1 align='center'> Fast Inverse Square Root in Python </h1>

[![Anaconda-Server Badge](https://img.shields.io/conda/v/skailasa/pyinvsqrt.svg)](https://anaconda.org/skailasa/pyinvsqrt) [![Anaconda-Server Badge](https://anaconda.org/skailasa/pyinvsqrt/badges/platforms.svg)](https://anaconda.org/skailasa/pyinvsqrt) [![Anaconda-Server Badge](https://anaconda.org/skailasa/pyinvsqrt/badges/latest_release_date.svg)](https://anaconda.org/skailasa/pyinvsqrt)

Made (in)famous by the original implementation in the Quake 3 Arena source code, where fast inverse square roots are vital for perfoming vector operations for game physics, the Fast Inverse Square Root is an extremely clever bit/memory hack, that avoids using slow division instructions, and replaces everything with rapid bit-shifts to calculate an approximation to, f(x) =  \frac{1}/{\sqrt{x}}.

## Requirements

- gcc
- conda/miniconda

## Install

```bash
conda install -c skailasa pyinvsqrt
```

## Usage

```python
import numpy as np

from pyinvsqrt import invsqrt

# Only 32 Bit compatible
x = np.float32(10)

# Compute inverse square root
y = invsqrt(x)
```

## Benchmark

Compared with a pure Numpy (BLAS backend) inverse square root, pyinvqrt is almost 400% faster, and almost 25% compared to a Numba-fied implementation.

![](static/benchmark.png)
