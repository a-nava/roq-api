/* Copyright (c) 2017-2021, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/chrono.h>
#include <fmt/format.h>

#include <chrono>
#include <string_view>

#include "roq/chrono.h"
#include "roq/compat.h"
#include "roq/event.h"
#include "roq/literals.h"
#include "roq/message_info.h"
#include "roq/numbers.h"
#include "roq/span.h"
#include "roq/string_buffer.h"

namespace roq {

//! Update relating to external latency
struct ROQ_PUBLIC ExternalLatency final {
  uint16_t stream_id = {};                //!< Stream identifier
  std::chrono::nanoseconds latency = {};  //!< latency measurement (1-way)
};

}  // namespace roq

template <>
struct fmt::formatter<roq::ExternalLatency> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(const roq::ExternalLatency &value, Context &context) {
    using namespace roq::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(stream_id={}, )"
        R"(latency={})"
        R"(}})"_sv,
        value.stream_id,
        value.latency);
  }
};
template <>
struct fmt::formatter<roq::Event<roq::ExternalLatency> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(const roq::Event<roq::ExternalLatency> &event, Context &context) {
    using namespace roq::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(external_latency={})"
        R"(}})"_sv,
        event.message_info,
        event.value);
  }
};
