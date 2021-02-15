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

#include "roq/side.h"

namespace roq {

//! Update relating to current position for a symbol/side/account
struct ROQ_PUBLIC PositionUpdate final {
  PositionUpdate() = default;
  PositionUpdate(PositionUpdate &&) = default;
  PositionUpdate(const PositionUpdate &) = delete;

  std::string_view account;     //!< Account name (as known to the gateway)
  std::string_view exchange;    //!< Exchange name
  std::string_view symbol;      //!< Symbol
  Side side = Side::UNDEFINED;  //!< Side
  double position = std::numeric_limits<double>::quiet_NaN();  //!< Current position
  uint32_t last_trade_id = 0;                                  //!< Last processed trade identifier
  double position_cost = std::numeric_limits<double>::quiet_NaN();  //!< Position cost
  double position_yesterday =
      std::numeric_limits<double>::quiet_NaN();  //!< Position as of yesterday
  double position_cost_yesterday =
      std::numeric_limits<double>::quiet_NaN();  //!< Position cost as of yesterday
  std::string_view external_account;  //!< External account name (as known to broker or exchange)
};

}  // namespace roq

template <>
struct fmt::formatter<roq::PositionUpdate> : public roq::formatter {
  template <typename Context>
  auto format(const roq::PositionUpdate &value, Context &context) {
    using namespace roq::literals;
    return roq::format_to(
        context.out(),
        R"({{)"
        R"(account="{}", )"
        R"(exchange="{}", )"
        R"(symbol="{}", )"
        R"(side={}, )"
        R"(position={}, )"
        R"(last_trade_id={}, )"
        R"(position_cost={}, )"
        R"(position_yesterday={}, )"
        R"(position_cost_yesterday={}, )"
        R"(external_account="{}")"
        R"(}})"_fmt,
        value.account,
        value.exchange,
        value.symbol,
        value.side,
        value.position,
        value.last_trade_id,
        value.position_cost,
        value.position_yesterday,
        value.position_cost_yesterday,
        value.external_account);
  }
};
template <>
struct fmt::formatter<roq::Event<roq::PositionUpdate> > : public roq::formatter {
  template <typename Context>
  auto format(const roq::Event<roq::PositionUpdate> &event, Context &context) {
    using namespace roq::literals;
    return roq::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(position_update={})"
        R"(}})"_fmt,
        event.message_info,
        event.value);
  }
};
