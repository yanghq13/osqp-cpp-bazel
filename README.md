# **osqp-cpp-bazel**
The `osqp-cpp` is built by `bazel`, which is easy to use `osqp` for rookies.

[![LICENSE](https://img.shields.io/badge/license-Apache%202-blue)](./LICENSE "LICENSE")  [![Build Status](https://travis-ci.com/JoeyBling/yilia-plus-demo.svg?branch=master)](https://travis-ci.com/JoeyBling/yilia-plus-demo)

## Demo

> reference：[osqp.org/example/demo](https://osqp.org/docs/examples/setup-and-solve.html)

Consider the following QP
$$
\begin{aligned}
minimize \quad 
&\frac{1}{2} x^T 
\begin{bmatrix}
 4 & 1\\
 1 & 2
\end{bmatrix}
x + 
\begin{bmatrix}
1 \\1
\end{bmatrix}^T
x \\
subject \quad to \quad 
&\begin{bmatrix}
1 \\0 \\0
\end{bmatrix}
\le \begin{bmatrix}
 1 & 1\\
 1 & 0\\
 0 & 1
\end{bmatrix}
\le \begin{bmatrix}
1 \\0.7 \\0.7
\end{bmatrix}
\end{aligned}
$$
We show below how to solve the problem in C++.

```c++
// osqp-cpp
#include "ThirdParty/osqp_cpp/osqp++.h"

using namespace Eigen;
using namespace osqp;

int main()
{
    /*
     * @min_x 0.5 * x'Px + q'x
     * @s.t.  l <= Ax <= u
     * @objective_matrix: p
     * @objective_vector: q
     * @constraint_matrix: A
     * @lower_bounds: l
     * @upper_bounds: u
     */

    // Create an OSQP Instance
    osqp::OsqpInstance instance;
    // P
    const Eigen::Triplet<double> p[] = {{0, 0, 4},
                                        {0, 1, 1},
                                        {1, 0, 1},
                                        {1, 1, 2}};
    instance.objective_matrix.resize(2, 2);
    instance.objective_matrix.setFromTriplets(std::begin(p),
                                              std::end(p));

    // q
    instance.objective_vector.resize(2);
    instance.objective_vector << 1, 1;

    // A
    const Eigen::Triplet<double> A[] = {{0, 0, 1},
                                        {0, 1, 1},
                                        {1, 0, 1},
                                        {1, 1, 0},
                                        {2, 0, 0},
                                        {2, 1, 1}};
    instance.constraint_matrix.resize(3, 2);
    instance.constraint_matrix.setFromTriplets(std::begin(A),
                                               std::end(A));

    // l and u
    instance.lower_bounds.resize(3);
    instance.upper_bounds.resize(3);
    instance.lower_bounds << 1, 0, 0;
    instance.upper_bounds << 1, 0.7, 0.7;

    // std::cout << instance.objective_vector << std::endl;

    // Create an OSQP Setting
    osqp::OsqpSettings settings;
    settings.eps_abs = 1e-04;

    // Create an OSQP Solver
    osqp::OsqpSolver solver;

    // Setup workspace and change parameter
    auto status = solver.Init(instance, settings);

    // Solve problem
    osqp::OsqpExitCode exit_code = solver.Solve();
    double optimal_objective = solver.objective_value();
    Eigen::VectorXd optimal_solution = solver.primal_solution();

    // std::cout << optimal_solution << std::endl;

    return 0;
}
```

## Tutorial

1. Set `bazel` sync.(Need to install `bazel` before)

```bash
bazel sync
```

2. Build the code.

```bash
bazel build //:example_osqp
```

3. Run the code.

```bash
bazel run //:example_osqp
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

## 

## Link

- [osqp](https://github.com/osqp/osqp)
- [osqp-cpp](https://github.com/google/osqp-cpp)
- [abseil-cpp](https://github.com/abseil/abseil-cpp)
- [eigen](https://gitlab.com/libeigen/eigen)
