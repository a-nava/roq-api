{% include 'copyright' %}

#pragma once

#include <fmt/format.h>

#include <cassert>
#include <string_view>
#include <type_traits>

#include "roq/compat.h"
#include "roq/literals.h"

{% include 'namespace_begin' %}

//! {{ comment }}
struct ROQ_PACKED {{ name }} final {
  //! helper
  enum type_t : uint64_t {
    UNDEFINED = 0x0,
  {% for value in values %}
    {{ value.enum_value }} = {{ "{:#x}".format((1).__lshift__(value.position)) }},{{ '  //!< {}'.format(value.comment) if value.comment|length > 0 else '' }}
  {% endfor %}
  };

  constexpr {{ name }}() = default;

  // cppcheck-suppress noExplicitConstructor
  constexpr {{ name }}(type_t type)  // NOLINT (allow implicit)
      : type_(type) {
  }

  explicit constexpr {{ name }}(uint64_t type)
      : type_(validate(type)) {
  }

  constexpr operator type_t() const {
    return type_;
  }

  constexpr std::string_view name() const {
    using namespace roq::literals;
    switch (type_) {
      case type_t::UNDEFINED:
        break;
  {% for value in values %}
      case type_t::{{ value.enum_value }}:
        return "{{ value.enum_value }}"_sv;
  {% endfor %}
      default:
        assert(false);
    }
    return "UNDEFINED"_sv;
  }

  constexpr operator std::string_view() const {
    return name();
  }

 protected:
  constexpr type_t validate(uint64_t type) {
    auto result = static_cast<type_t>(type);
    switch (result) {
      case type_t::UNDEFINED:
  {% for value in values %}
      case type_t::{{ value.enum_value }}:
  {% endfor %}
        return result;
      default:
        assert(false);
        return type_t::UNDEFINED;
    }
  }

 private:
  type_t type_ = type_t::UNDEFINED;
};

{% include 'namespace_end' %}

template <>
struct std::is_enum<{{ namespaces | join('::') }}::{{ name }}> : std::true_type {};

template <>
struct std::underlying_type<{{ namespaces | join('::') }}::{{ name }}> {
  using type = uint64_t;
};

template <>
struct fmt::formatter<{{ namespaces | join('::') }}::{{ name }}> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(
      const {{ namespaces | join('::') }}::{{ name }}& value,
      Context& context) {
    using namespace roq::literals;
    return fmt::format_to(
        context.out(),
        "{}"_sv,
        value.name());
  }
};
