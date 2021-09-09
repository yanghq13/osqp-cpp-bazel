# **osqp-cpp-bazel**
The `osqp-cpp` is built by `bazel`, which is easy to use `osqp` for rookies.

[![LICENSE](https://img.shields.io/badge/license-Apache%202-blue)](./LICENSE "LICENSE")  [![Build Status](https://travis-ci.com/JoeyBling/yilia-plus-demo.svg?branch=master)](https://travis-ci.com/JoeyBling/yilia-plus-demo)

## Tutorial

1. Set `bazel` sync.(Need to install `bazel` before)

   ```bash
   bazel sync
   ```

2. Build the code.

   ```bash
   bazel build //:my_osqp
   ```

3. Run the code.

   ```bash
   bazel run //:my_osqp
   ```

Terminal print like this

```bash
-----------------------------------------------------------------
           OSQP v0.0.0  -  Operator Splitting QP Solver
              (c) Bartolomeo Stellato,  Goran Banjac
        University of Oxford  -  Stanford University 2021
-----------------------------------------------------------------
problem:  variables n = 2, constraints m = 1
          nnz(P) + nnz(A) = 4
settings: linear system solver = qdldl,
          eps_abs = 1.0e-03, eps_rel = 1.0e-03,
          eps_prim_inf = 1.0e-04, eps_dual_inf = 1.0e-04,
          rho = 1.00e-01 (adaptive),
          sigma = 1.00e-06, alpha = 1.60, max_iter = 4000
          check_termination: on (interval 25),
          scaling: on, scaled_termination: off
          warm start: on, polish: off, time_limit: off

iter   objective    pri res    dua res    rho        time
   1  -2.1363e-01   1.77e+00   8.00e-01   1.00e-01   1.99e-05s
  50   1.9375e+00   5.86e-10   8.82e-12   1.35e+01   3.67e-05s

status:               solved
number of iterations: 50
optimal objective:    1.9375
run time:             4.27e-05s
optimal rho estimate: 1.86e+02
```

## Link

- [osqp](https://github.com/osqp/osqp)
- [osqp-cpp](https://github.com/google/osqp-cpp)
- [abseil-cpp](https://github.com/abseil/abseil-cpp)
- [eigen](https://gitlab.com/libeigen/eigen)
