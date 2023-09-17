cmake_minimum_required(VERSION 3.24)
set(project_name test) ## rename your project here
project(${project_name})

set(CMAKE_OSX_DEPLOYMENT_TARGET "14.0" CACHE STRING "Minimum OS X deployment version")
set(CMAKE_CXX_STANDARD 20)
#add_compile_options(-O0)

## link libs
find_package(oatpp 1.3.0 REQUIRED)
find_package(oatpp-websocket 1.3.0 REQUIRED)

find_library(CORE_FOUNDATION_FRAMEWORK CoreFoundation)

add_library(${project_name}-lib
        websocket/WSListener.cpp
        websocket/WSListener.hpp
        StaticController.hpp
        AppComponent.hpp
        GameEvent.cpp
        GameSession.cpp
        GameEvent.hpp
        GameSession.hpp
        dto/WSMessage.hpp
        quic_toy_server.cc
        main2.cpp
)

include_directories(
        "/Users/naararouter/CLionProjects/google-quiche"
        "/Users/naararouter/CLionProjects/google-quiche/quiche/common/platform/default"
        "/Users/naararouter/DockerShare/google-quiche/external/com_google_absl"
        "/Users/naararouter/DockerShare/google-quiche/external/boringssl/src/include"
        "/Users/naararouter/DockerShare/google-quiche/external/com_google_protobuf/src"
        "/Users/naararouter/DockerShare/google-quiche/execroot/com_google_quiche/bazel-out/aarch64-fastbuild/bin"
        "/Users/naararouter/Downloads/googleurl_9cdb1f4d1a365ebdbcbf179dadf7f8aa5ee802e7"
        "/opt/homebrew/Cellar/icu4c/73.2/include"
)


target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-websocket
        ${CORE_FOUNDATION_FRAMEWORK}
        ## QUICHE DEPS
        /private/var/tmp/_bazel_naararouter/dd46eed37c0b0443482c9e63bf832e51/execroot/com_google_quiche/bazel-out/darwin_arm64-fastbuild/bin/quiche/libquiche_core.a
        /private/var/tmp/_bazel_naararouter/dd46eed37c0b0443482c9e63bf832e51/execroot/com_google_quiche/bazel-out/darwin_arm64-fastbuild/bin/quiche/libquiche_platform_default.a
        /private/var/tmp/_bazel_naararouter/dd46eed37c0b0443482c9e63bf832e51/execroot/com_google_quiche/bazel-out/darwin_arm64-fastbuild/bin/quiche/libquiche_platform_default_tools.a
        /private/var/tmp/_bazel_naararouter/dd46eed37c0b0443482c9e63bf832e51/execroot/com_google_quiche/bazel-out/darwin_arm64-fastbuild/bin/quiche/libquiche_tool_support.a
        /private/var/tmp/_bazel_naararouter/dd46eed37c0b0443482c9e63bf832e51/execroot/com_google_quiche/bazel-out/darwin_arm64-fastbuild/bin/quiche/libquiche_protobufs.a
        ## -- BoringSSL
        /private/var/tmp/_bazel_naararouter/8269f6acb7850a0a1b3e038ba118d2bc/execroot/boringssl/bazel-out/darwin_arm64-fastbuild/bin/libcrypto.a
        /private/var/tmp/_bazel_naararouter/8269f6acb7850a0a1b3e038ba118d2bc/execroot/boringssl/bazel-out/darwin_arm64-fastbuild/bin/libssl.a
        ## -- ABSL STARTS
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/strings/libcordz_sample_token.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/strings/libstr_format_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/strings/libcordz_functions.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/strings/libcordz_handle.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/strings/libcord.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/strings/libinternal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/strings/libstrings.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/strings/libcord_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/strings/libcordz_info.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/strings/libpow10_helper.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/types/libbad_any_cast_impl.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/types/libbad_variant_access.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/types/libbad_optional_access.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libparse.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libcommandlineflag.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libusage_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libflag.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libflag_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libconfig.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libprivate_handle_accessor.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libmarshalling.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libreflection.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libprogram_name.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libusage.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/flags/libcommandlineflag_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/synchronization/libkernel_timeout_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/synchronization/libgraphcycles_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/synchronization/libsynchronization.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/hash/libhash.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/hash/liblow_level_hash.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/hash/libcity.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/debugging/libexamine_stack.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/debugging/libstack_consumption.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/debugging/libleak_check.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/debugging/libstacktrace.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/debugging/libdebugging_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/debugging/libfailure_signal_handler.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/debugging/libdemangle_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/debugging/libsymbolize.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/crc/libcrc_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/crc/libcpu_detect.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/crc/libcrc32c.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/crc/libcrc_cord_state.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/status/libstatus.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/status/libstatusor.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/time/libtest_util.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/time/internal/cctz/libcivil_time.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/time/internal/cctz/libtime_zone.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/time/libtime.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/container/libhash_generator_testing.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/container/libhashtablez_sampler.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/container/libtest_instance_tracker.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/container/libraw_hash_set.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/numeric/libint128.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/profiling/libexponential_biased.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/profiling/libperiodic_sampler.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/libdie_if_null.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/libglobals.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/libscoped_mock_log.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/internal/libnullguard.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/internal/libglobals.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/internal/libtest_actions.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/internal/libtest_matchers.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/internal/libproto.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/internal/libtest_helpers.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/internal/libconditions.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/internal/libformat.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/internal/libcheck_op.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/internal/liblog_sink_set.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/internal/liblog_message.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/liblog_entry.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/libinitialize.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/log/liblog_sink.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/libseed_gen_exception.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/libdistributions.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/libseed_sequences.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/internal/libpool_urbg.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/internal/libnanobenchmark.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/internal/libranden_hwaes_impl.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/internal/libplatform.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/internal/libranden_hwaes.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/internal/libranden.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/internal/libdistribution_test_util.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/internal/libseed_material.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/random/internal/libranden_slow.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/base/libthrow_delegate.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/base/libatomic_hook_test_helper.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/base/liblog_severity.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/base/libstrerror.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/base/libbase.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/base/libexception_safety_testing.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/base/libmalloc_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/base/libraw_logging_internal.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/base/libspinlock_wait.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/absl/base/libscoped_set_env.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/external/com_github_google_benchmark/libbenchmark.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/external/com_github_google_benchmark/libbenchmark_main.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/external/com_google_googletest/libgtest_main.a
        /private/var/tmp/_bazel_naararouter/5c3ee73569d847cae201ce2d89936dcf/execroot/com_google_absl/bazel-out/darwin_arm64-fastbuild/bin/external/com_google_googletest/libgtest.a
        ### ABSL ENDS

        ### -- googleurl
        /private/var/tmp/_bazel_naararouter/3a53306b527712a26264b3476e11ec65/execroot/com_google_googleurl/bazel-out/darwin_arm64-fastbuild/bin/url/liburl.a
        /private/var/tmp/_bazel_naararouter/3a53306b527712a26264b3476e11ec65/execroot/com_google_googleurl/bazel-out/darwin_arm64-fastbuild/bin/base/libbase.a

        ## -- protobuf
        /private/var/tmp/_bazel_naararouter/53aabb5576fa746b6ad75b717bfa6a25/execroot/com_google_protobuf/bazel-out/darwin_arm64-fastbuild/bin/libprotobuf.a
        /private/var/tmp/_bazel_naararouter/53aabb5576fa746b6ad75b717bfa6a25/execroot/com_google_protobuf/bazel-out/darwin_arm64-fastbuild/bin/libprotobuf_lite.a

        ## -- icu
        #/opt/homebrew/Cellar/icu4c/73.2/lib/libicui18n.a
        #/opt/homebrew/Cellar/icu4c/73.2/lib/libicutest.a
        #/opt/homebrew/Cellar/icu4c/73.2/lib/libicuio.a
        #/opt/homebrew/Cellar/icu4c/73.2/lib/libicudata.a
        #/opt/homebrew/Cellar/icu4c/73.2/lib/libicutu.a
        /opt/homebrew/Cellar/icu4c/73.2/lib/libicuuc.a
)

## add executables

add_executable(${project_name}-exe quic_server_bin.cc)
#add_executable(${project_name}-exe main2.cpp)
target_link_libraries(${project_name}-exe ${project_name}-lib)