/* Copyright (c) 2017-2021, Hans Erik Thrane */

#pragma once

#include <absl/container/flat_hash_map.h>

#include <array>
#include <limits>
#include <string>
#include <string_view>
#include <vector>

#include "roq/api.h"

namespace roq {
namespace cache {

struct CustomMetrics final {
  explicit CustomMetrics(const CustomMetricsUpdate &custom_metrics_update)
      : user(custom_metrics_update.user), label(custom_metrics_update.label), account(custom_metrics_update.account),
        exchange(custom_metrics_update.exchange), symbol(custom_metrics_update.symbol) {}

  CustomMetrics(const CustomMetrics &) = delete;
  CustomMetrics(CustomMetrics &&) = default;

  [[nodiscard]] bool operator()(const CustomMetricsUpdate &custom_metrics_update) {
    for (auto &measurement : custom_metrics_update.measurements) {
      auto &[key, value] = measurement;
      auto iter = lookup_.find(key);
      if (iter == lookup_.end()) {
        auto res = lookup_.emplace(key, std::size(measurements));
        iter = res.first;
        measurements.emplace_back(measurement);
      } else {
        measurements[(*iter).second].value = value;
      }
    }
    return true;  // XXX need dirty flag
  }

  [[nodiscard]] operator CustomMetricsUpdate() {
    return {
        .user = user,
        .label = label,
        .account = account,
        .exchange = exchange,
        .symbol = symbol,
        .measurements = measurements,  // XXX reason for non-const method
    };
  }

  uint16_t stream_id = {};
  const string_buffer<MAX_LENGTH_USER> user;
  const string_buffer<MAX_LENGTH_LABEL> label;
  const string_buffer<MAX_LENGTH_ACCOUNT> account;
  const string_buffer<MAX_LENGTH_EXCHANGE> exchange;
  const string_buffer<MAX_LENGTH_SYMBOL> symbol;
  std::vector<Measurement> measurements;

 private:
  // XXX using key_t = roq::string_buffer<8>;
  absl::flat_hash_map<std::string, size_t> lookup_;
};

}  // namespace cache
}  // namespace roq
