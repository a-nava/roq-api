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

#include "roq/connection_status.h"
#include "roq/priority.h"
#include "roq/stream_type.h"

namespace roq {

//! Update relating to current stream status
struct ROQ_PUBLIC StreamStatus final {
  uint16_t stream_id = {};       //!< Stream identifier
  std::string_view account;      //!< Account name
  uint64_t supports = {};        //!< Support types (bit mask)
  ConnectionStatus status = {};  //!< Connection status
  StreamType type = {};          //!< Stream type
  Priority priority = {};        //!< Priority
};

}  // namespace roq

template <>
struct fmt::formatter<roq::StreamStatus> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(const roq::StreamStatus &value, Context &context) {
    using namespace roq::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(stream_id={}, )"
        R"(account="{}", )"
        R"(supports={:#x}, )"
        R"(status={}, )"
        R"(type={}, )"
        R"(priority={})"
        R"(}})"_sv,
        value.stream_id,
        value.account,
        value.supports,
        value.status,
        value.type,
        value.priority);
  }
};
template <>
struct fmt::formatter<roq::Event<roq::StreamStatus> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(const roq::Event<roq::StreamStatus> &event, Context &context) {
    using namespace roq::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(stream_status={})"
        R"(}})"_sv,
        event.message_info,
        event.value);
  }
};
