/* Copyright (c) 2017-2021, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/chrono.h>
#include <fmt/format.h>

#include <chrono>
#include <limits>
#include <string_view>

#include "roq/chrono.h"
#include "roq/compat.h"
#include "roq/event.h"
#include "roq/fixed_string.h"
#include "roq/format.h"
#include "roq/literals.h"
#include "roq/message_info.h"
#include "roq/span.h"

namespace roq {

//! Represents a timer update
struct ROQ_PUBLIC Timer final {
  Timer() = default;
  Timer(Timer &&) = default;
  Timer(const Timer &) = delete;

  std::chrono::nanoseconds now = {};  //!< Current time (monotonic clock)
};

}  // namespace roq

template <>
struct fmt::formatter<roq::Timer> : public roq::formatter {
  template <typename Context>
  auto format(const roq::Timer &value, Context &context) {
    using namespace roq::literals;
    return roq::format_to(
        context.out(),
        R"({{)"
        R"(now={})"
        R"(}})"_fmt,
        value.now);
  }
};
template <>
struct fmt::formatter<roq::Event<roq::Timer> > : public roq::formatter {
  template <typename Context>
  auto format(const roq::Event<roq::Timer> &event, Context &context) {
    using namespace roq::literals;
    return roq::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(timer={})"
        R"(}})"_fmt,
        event.message_info,
        event.value);
  }
};
