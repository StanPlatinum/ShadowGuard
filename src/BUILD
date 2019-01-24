
cc_binary(
    name = "cfi",
    srcs = [
        "cfi.cc",
	"instrument.cc",
	"instrument.h",
        "jit.cc",
	"jit.h",
	"jit_avx2.cc",
	"jit_internal.h",
        "register_usage.cc",
        "register_usage.h",
    ],
    deps = [
       	"@asmjit//:asmjit",
        "@com_github_gflags_gflags//:gflags",
       	"@dyninst//:dyninst",
        "@glog//:glog",
    ],
)

cc_binary(
    name = "sizeof",
    srcs = [
        "sizeof.cc",
    ],
    deps = [
        "@asmjit//:asmjit",
        "@com_github_gflags_gflags//:gflags",
        "@dyninst//:dyninst",
        "@glog//:glog",
    ],
)