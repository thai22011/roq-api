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

//! Enumeration of liquidity type
struct ROQ_PACKED Liquidity final {
  //! helper
  enum type_t : uint8_t {
    UNDEFINED = 0,
    ADDED,
    REMOVED,
  };

  constexpr Liquidity() = default;

  // cppcheck-suppress noExplicitConstructor
  constexpr Liquidity(type_t type)  // NOLINT (allow implicit)
      : type_(type) {}

  explicit constexpr Liquidity(uint8_t type) : type_(validate(type)) {}

  constexpr operator type_t() const { return type_; }

  constexpr std::string_view name() const {
    using namespace roq::literals;
    switch (type_) {
      case type_t::UNDEFINED:
        break;
      case type_t::ADDED:
        return "ADDED"_sv;
      case type_t::REMOVED:
        return "REMOVED"_sv;
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
      case type_t::ADDED:
      case type_t::REMOVED:
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
struct std::is_enum<roq::Liquidity> : std::true_type {};

template <>
struct std::underlying_type<roq::Liquidity> {
  using type = uint8_t;
};

template <>
struct fmt::formatter<roq::Liquidity> : public roq::formatter {
  template <typename Context>
  auto format(const roq::Liquidity &value, Context &context) {
    using namespace roq::literals;
    return roq::format_to(context.out(), "{}"_fmt, value.name());
  }
};
