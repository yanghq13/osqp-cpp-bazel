cc_binary(
  name = "hello_world",
  deps = [
    "@com_google_absl//absl/strings",
    "@eigen",
    "@osqp_cpp_lib//:osqp_cpp",
  ],
  srcs = ["hello_world.cc"],
)

cc_binary(
  name = "my_osqp",
  deps = [
    "@osqp_cpp_lib//:osqp_cpp",
  ],
  srcs = ["my_osqp.cc"],
  copts = [
    "-std=c++17",
  ],
  # linkopts = ["--cxxopt=-std=c++17"],
)