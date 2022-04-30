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

//! Update relating to external latency
struct ROQ_PUBLIC ExternalLatency final {
  uint16_t stream_id = {};                //!< Stream identifier
  std::string_view account;               //!< Account name
  std::chrono::nanoseconds latency = {};  //!< latency measurement (1-way)
};

template <>
inline constexpr std::string_view get_name<ExternalLatency>() {
  using namespace std::literals;
  return "external_latency"sv;
}

}  // namespace roq

template <>
struct fmt::formatter<roq::ExternalLatency> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::ExternalLatency &value, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(stream_id={}, )"
        R"(account="{}", )"
        R"(latency={})"
        R"(}})"sv,
        value.stream_id,
        value.account,
        value.latency);
  }
};

template <>
struct fmt::formatter<roq::Event<roq::ExternalLatency> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::Event<roq::ExternalLatency> &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(external_latency={})"
        R"(}})"sv,
        event.message_info,
        event.value);
  }
};

template <>
struct fmt::formatter<roq::Trace<roq::ExternalLatency const> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return std::begin(context);
  }
  template <typename Context>
  auto format(const roq::Trace<roq::ExternalLatency const> &event, Context &context) {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(trace_info={}, )"
        R"(external_latency={})"
        R"(}})"sv,
        event.trace_info,
        event.value);
  }
};
