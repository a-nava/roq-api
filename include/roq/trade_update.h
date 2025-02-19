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

#include "roq/fill.h"
#include "roq/position_effect.h"
#include "roq/side.h"

namespace roq {

//! Update relating to order being partially or fully filled
struct ROQ_PUBLIC TradeUpdate final {
  uint16_t stream_id = {};                        //!< Stream identifier
  std::string_view account;                       //!< Account name
  uint32_t order_id = {};                         //!< Order identifier
  std::string_view exchange;                      //!< Exchange
  std::string_view symbol;                        //!< Symbol
  Side side = {};                                 //!< Side
  PositionEffect position_effect = {};            //!< Position effect
  std::chrono::nanoseconds create_time_utc = {};  //!< Created timestamp (UTC)
  std::chrono::nanoseconds update_time_utc = {};  //!< Updated timestamp (UTC)
  std::string_view external_account;              //!< External account name
  std::string_view external_order_id;             //!< External order identifier
  roq::span<Fill> fills;                          //!< List of fills
  std::string_view routing_id;                    //!< Routing identifier
};

}  // namespace roq

template <>
struct fmt::formatter<roq::TradeUpdate> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(const roq::TradeUpdate &value, Context &context) {
    using namespace roq::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(stream_id={}, )"
        R"(account="{}", )"
        R"(order_id={}, )"
        R"(exchange="{}", )"
        R"(symbol="{}", )"
        R"(side={}, )"
        R"(position_effect={}, )"
        R"(create_time_utc={}, )"
        R"(update_time_utc={}, )"
        R"(external_account="{}", )"
        R"(external_order_id="{}", )"
        R"(fills=[{}], )"
        R"(routing_id="{}")"
        R"(}})"_sv,
        value.stream_id,
        value.account,
        value.order_id,
        value.exchange,
        value.symbol,
        value.side,
        value.position_effect,
        value.create_time_utc,
        value.update_time_utc,
        value.external_account,
        value.external_order_id,
        fmt::join(value.fills, ", "_sv),
        value.routing_id);
  }
};
template <>
struct fmt::formatter<roq::Event<roq::TradeUpdate> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(const roq::Event<roq::TradeUpdate> &event, Context &context) {
    using namespace roq::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(trade_update={})"
        R"(}})"_sv,
        event.message_info,
        event.value);
  }
};
