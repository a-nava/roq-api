/* Copyright (c) 2017-2021, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/chrono.h>

#include <chrono>
#include <string_view>

#include "roq/chrono.h"
#include "roq/compat.h"
#include "roq/event.h"
#include "roq/fixed_string.h"
#include "roq/format.h"
#include "roq/literals.h"
#include "roq/message_info.h"
#include "roq/numbers.h"
#include "roq/span.h"

namespace roq {

//! Identifies the beginning of a sequence of related messages
struct ROQ_PUBLIC BatchBegin final {
  BatchBegin() = default;
  BatchBegin(BatchBegin &&) = default;
  BatchBegin(const BatchBegin &) = delete;
};

}  // namespace roq

template <>
struct fmt::formatter<roq::BatchBegin> : public roq::formatter {
  template <typename Context>
  auto format(const roq::BatchBegin &value, Context &context) {
    using namespace roq::literals;
    return roq::format_to(context.out(), R"({{}})"_fmt);
  }
};
template <>
struct fmt::formatter<roq::Event<roq::BatchBegin> > : public roq::formatter {
  template <typename Context>
  auto format(const roq::Event<roq::BatchBegin> &event, Context &context) {
    using namespace roq::literals;
    return roq::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(batch_begin={})"
        R"(}})"_fmt,
        event.message_info,
        event.value);
  }
};