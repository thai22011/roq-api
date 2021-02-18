/* Copyright (c) 2017-2021, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <cassert>
#include <string_view>
#include <type_traits>

#include "roq/compat.h"
#include "roq/format.h"
#include "roq/literals.h"

namespace roq {

//! Enumeration of order types
struct ROQ_PACKED OrderType final {
  //! helper
  enum type_t : uint8_t {
    UNDEFINED = 0,
    MARKET,
    LIMIT,
  };

  constexpr OrderType() = default;

  // cppcheck-suppress noExplicitConstructor
  constexpr OrderType(type_t type)  // NOLINT (allow implicit)
      : type_(type) {}

  explicit constexpr OrderType(uint8_t type) : type_(validate(type)) {}

  constexpr operator type_t() const { return type_; }

  constexpr std::string_view name() const {
    using namespace roq::literals;
    switch (type_) {
      case type_t::UNDEFINED:
        break;
      case type_t::MARKET:
        return "MARKET"_sv;
      case type_t::LIMIT:
        return "LIMIT"_sv;
      default:
        assert(false);
    }
    return "UNDEFINED"_sv;
  }

  constexpr operator std::string_view() const { return name(); }

 protected:
  constexpr type_t validate(uint8_t type) {
    auto result = static_cast<type_t>(type);
    switch (result) {
      case type_t::UNDEFINED:
      case type_t::MARKET:
      case type_t::LIMIT:
        return result;
      default:
        assert(false);
        return type_t::UNDEFINED;
    }
  }

 private:
  type_t type_ = type_t::UNDEFINED;
};

}  // namespace roq

template <>
struct std::is_enum<roq::OrderType> : std::true_type {};

template <>
struct std::underlying_type<roq::OrderType> {
  using type = uint8_t;
};

template <>
struct fmt::formatter<roq::OrderType> : public roq::formatter {
  template <typename Context>
  auto format(const roq::OrderType &value, Context &context) {
    using namespace roq::literals;
    return roq::format_to(context.out(), "{}"_fmt, value.name());
  }
};
