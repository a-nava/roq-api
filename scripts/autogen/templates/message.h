{% include 'copyright' %}

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

{% include 'includes' %}

{% include 'namespace_begin' %}

//! {{ comment }}
struct ROQ_PUBLIC {{ name }} final {
{% include 'variables' %}
};

{% include 'namespace_end' %}

{% include 'format' %}

template <>
struct fmt::formatter<{{ namespaces | join('::') }}::Event<{{ namespaces | join('::') }}::{{ name }}> > {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(
      const {{ namespaces | join('::') }}::Event<{{ namespaces | join('::') }}::{{ name }}>& event,
      Context& context) {
    using namespace roq::literals;
    return fmt::format_to(
        context.out(),
{%- raw %}
        R"({{)"
{%- endraw %}
        R"(message_info={}, )"
        R"({{ filename }}={})"
{%- raw %}
        R"(}})"_sv,
{%- endraw %}
        event.message_info,
        event.value);
  }
};
