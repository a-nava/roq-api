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

//! Gateway settings
struct ROQ_PUBLIC GatewaySettings final {
  uint64_t supports = {};                      //!< Support types (bit mask)
  uint32_t mbp_max_depth = {};                 //!< MBP max depth
  double mbp_tick_size_multiplier = NaN;       //!< MBP multiplier used to manage prices as integer
  double mbp_min_trade_vol_multiplier = NaN;   //!< MBP multiplier used to manage quantities as integer
  bool mbp_allow_remove_non_existing = false;  //!< MBP allow remove operation on non-existing level?
  bool mbp_allow_price_inversion = false;      //!< MBP allow price inversion?
  bool oms_download_has_state = false;         //!< OMS download includes state information?
  bool oms_download_has_routing_id = false;    //!< OMS download includes routing_id?
};

}  // namespace roq

template <>
struct fmt::formatter<roq::GatewaySettings> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(const roq::GatewaySettings &value, Context &context) {
    using namespace roq::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(supports={:#x}, )"
        R"(mbp_max_depth={}, )"
        R"(mbp_tick_size_multiplier={}, )"
        R"(mbp_min_trade_vol_multiplier={}, )"
        R"(mbp_allow_remove_non_existing={}, )"
        R"(mbp_allow_price_inversion={}, )"
        R"(oms_download_has_state={}, )"
        R"(oms_download_has_routing_id={})"
        R"(}})"_sv,
        value.supports,
        value.mbp_max_depth,
        value.mbp_tick_size_multiplier,
        value.mbp_min_trade_vol_multiplier,
        value.mbp_allow_remove_non_existing,
        value.mbp_allow_price_inversion,
        value.oms_download_has_state,
        value.oms_download_has_routing_id);
  }
};
template <>
struct fmt::formatter<roq::Event<roq::GatewaySettings> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(const roq::Event<roq::GatewaySettings> &event, Context &context) {
    using namespace roq::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(message_info={}, )"
        R"(gateway_settings={})"
        R"(}})"_sv,
        event.message_info,
        event.value);
  }
};
