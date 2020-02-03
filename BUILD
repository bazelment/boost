licenses(["notice"])

load(":boost.bzl", "boost_library")

boost_library(
    name = "algorithm",
    deps = [
        ":assert",
        ":config",
        ":function",
        ":integer",
        ":iterator",
        ":mpl",
        ":range",
        ":throw_exception",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "align",
)

boost_library(
    name = "any",
    deps = [
        ":type_index",
    ],
)

boost_library(
    name = "asio",
    deps = [
        ":bind",
        ":config",
        ":date_time",
        ":filesystem",
        ":mpl",
        ":regex",
        ":smart_ptr",
        ":static_assert",
        ":throw_exception",
        ":type_traits",
        ":version",
    ],
)

boost_library(
    name = "array",
)

boost_library(
    name = "assert",
)

boost_library(
    name = "atomic",
)

boost_library(
    name = "bind",
)

boost_library(
    name = "chrono",
    deps = [
        ":ratio",
    ],
)

boost_library(
    name = "concept_check",
)

boost_library(
    name = "config",
)

boost_library(
    name = "container",
)

boost_library(
    name = "container_hash",
)

CONTEXT_K8_LINUX_ASM = [
    "context/src/asm/jump_x86_64_sysv_elf_gas.S",
    "context/src/asm/make_x86_64_sysv_elf_gas.S",
]

boost_library(
    name = "context",
    srcs = [
        # "context/src/fiber.cpp",
    ] + CONTEXT_K8_LINUX_ASM,
    copts = [
        "-fsplit-stack",
        "-DBOOST_USE_SEGMENTED_STACKS",
    ],
    deps = [
        ":config",
    ],
)

boost_library(
    name = "conversion",
)

boost_library(
    name = "core",
    deps = [
        ":config",
    ],
)

boost_library(
    name = "crc",
    deps = [
        ":core",
    ],
)

boost_library(
    name = "date_time",
    deps = [
        ":smart_ptr",
    ],
)

boost_library(
    name = "detail",
)

boost_library(
    name = "exception",
    defines = [
        "BOOST_NO_CXX11_RVALUE_REFERENCES",
    ],
)

boost_library(
    name = "filesystem",
    srcs = glob([
        "filesystem/src/*.cpp",
    ]),
    copts = [
        "-Ifilesystem/src",
    ],
    hdrs = [
        "filesystem/src/error_handling.hpp",
    ],
    deps = [
        ":config",
	":container_hash",
        ":functional",
        ":io",
        ":iterator",
        ":range",
        ":smart_ptr",
        ":system",
        ":type_traits",
    ],
)

boost_library(
    name = "foreach",
)

boost_library(
    name = "function",
    deps = [
        ":bind",
        ":integer",
        ":throw_exception",
    ],
)

boost_library(
    name = "function_types",
)

boost_library(
    name = "functional",
    deps = [
        ":detail",
    ],
)

boost_library(
    name = "fusion",
    deps = [
        ":config",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "heap",
    deps = [
        ":parameter",
    ],
)

boost_library(
    name = "integer",
    deps = [
        ":static_assert",
    ],
)

boost_library(
    name = "interprocess",
    deps = [
        ":config",
        ":container",
        ":core",
        ":date_time",
        ":intrusive",
        ":iterator",
        ":move",
        ":type_traits",
    ],
)

boost_library(
    name = "iterator",
    deps = [
        ":detail",
        ":static_assert",
    ],
)

boost_library(
    name = "intrusive",
    deps = [
        ":assert",
        ":static_assert",
    ],
)

boost_library(
    name = "io",
)

boost_library(
    name = "move",
    deps = [
        ":static_assert",
    ],
)

boost_library(
    name = "mpl",
    deps = [
        ":move",
        ":preprocessor",
        ":predef",
        # If any target depending on mpl need to use
        # boost/type_traits/is_same.hpp, it should depend on
        # type_traits directly.
    ],
)

boost_library(
    name = "msm",
    deps = [
        ":any",
        ":assert",
        ":bind",
        ":config",
        ":core",
        ":function",
        ":fusion",
        ":mpl",
        ":parameter",
        ":proto",
        ":serialization",
        ":tuple",
        ":type_traits",
    ],
)

boost_library(
    name = "multi_index",
    deps = [
        ":foreach",
        ":serialization",
        ":static_assert",
        ":tuple",
    ],
)

boost_library(
    name = "optional",
)

boost_library(
    name = "parameter",
)

boost_library(
    name = "predef",
)

boost_library(
    name = "preprocessor",
)

boost_library(
    name = "proto",
    deps = [
        ":typeof",
    ],
)

boost_library(
    name = "range",
    deps = [
        ":concept_check",
        ":optional",
    ],
)

boost_library(
    name = "ratio",
)

boost_library(
    name = "regex",
    srcs = glob([
        "regex/src/*.cpp",
        "regex/src/*.hpp",
    ]),
    defines = [
        "BOOST_FALLTHROUGH",
    ],
    deps = [
        ":assert",
        ":config",
	":container_hash",
        ":functional",
        ":integer",
        ":mpl",
        ":smart_ptr",
        ":throw_exception",
        ":type_traits",
    ],
)

boost_library(
    name = "serialization",
)

boost_library(
    name = "smart_ptr",
    deps = [
        ":align",
        ":core",
        ":predef",
        ":throw_exception",
        ":utility",
    ],
)

boost_library(
    name = "static_assert",
)

boost_library(
    name = "system",
    srcs = glob([
        "system/src/*.cpp",
    ]),
    deps = [
        ":assert",
        ":config",
        ":core",
        ":predef",
    ],
)

boost_library(
    name = "thread",
    defines = [
        "BOOST_NO_CXX11_RVALUE_REFERENCES",
        "BOOST_NO_CXX11_SMART_PTR",
    ],
    deps = [
        ":atomic",
        ":chrono",
        ":core",
        ":date_time",
        ":exception",
        ":io",
        ":system",
    ],
)

boost_library(
    name = "throw_exception",
)

boost_library(
    name = "typeof",
    deps = [
        ":core",
    ],
)

boost_library(
    name = "type_index",
    deps = [
        ":core",
        ":functional",
    ],
)

boost_library(
    name = "type_traits",
    deps = [
        ":core",
        ":mpl",
        ":static_assert",
    ],
)

boost_library(
    name = "tuple",
)

boost_library(
    name = "tr1",
    defines = [
        "BOOST_FALLTHROUGH",
    ],
    deps = [
        ":config",
    ],
)

boost_library(
    name = "utility",
)

boost_library(
    name = "version",
)

cc_test(
    name = "filesystem_test_quick",
    srcs = [
        "filesystem/test/quick.cpp",
    ],
    deps = [
        ":filesystem",
    ]
)

cc_test(
    name = "regex_test_quick",
    srcs = [
        "regex/test/quick.cpp",
    ],
    deps = [
        ":regex",
        ":core",
    ]
)

cc_test(
    name = "system_test_error_code_test",
    srcs =[
        "system/test/error_code_test.cpp",
    ],
    deps = [
        ":system",
    ]
)
