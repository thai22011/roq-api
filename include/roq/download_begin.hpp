/* Copyright (c) 2017-2022, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/chrono.h>
#include <fmt/format.h>

#include <chrono>
#include <string_view>

#include "roq/compat.hpp"
#include "roq/event.hpp"
#include "roq/mask.hpp"
#include "roq/message_info.hpp"
#include "roq/name.hpp"
#include "roq/numbers.hpp"
#include "roq/span.hpp"
#include "roq/string_types.hpp"
#include "roq/trace.hpp"

namespace roq {

//! Identifies the beginning of a download sequence
struct ROQ_PUBLIC DownloadBegin final {
  std::string_view account;  //!< Account name
};

template <>
inline constexpr std::string_view get_name<DownloadBegin>() {
  using namespace std::literals;
  return "download_begin"sv;
}

}  // namespace roq

template <>
struct fmt::formatter<roq::DownloadBegin> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::DownloadBegin &value, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(account="{}")"
        R"(}})"sv,
        value.account);
  }
};

template <>
struct fmt::formatter<roq::Event<roq::DownloadBegin> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::Event<roq::DownloadBegin> &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(download_begin={})"
        R"(}})"sv,
        event.message_info,
        event.value);
  }
};

template <>
struct fmt::formatter<roq::Trace<roq::DownloadBegin const> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::Trace<roq::DownloadBegin const> &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(trace_info={}, )"
        R"(download_begin={})"
        R"(}})"sv,
        event.trace_info,
        event.value);
  }
};
