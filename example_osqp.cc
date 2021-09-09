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