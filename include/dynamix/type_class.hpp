// DynaMix
// Copyright (c) 2013-2020 Borislav Stanimirov, Zahary Karadjov
//
// Distributed under the MIT Software License
// See accompanying file LICENSE.txt or copy at
// https://opensource.org/licenses/MIT
//
#pragma once

#include "config.hpp"

#include "type_class_id.hpp"
#include "mixin_id.hpp"
#include "feature.hpp"

#include <vector>

namespace dynamix
{

static constexpr type_class_id INVALID_TYPE_CLASS_ID = ~type_class_id(0);

class object_type_info;

namespace internal
{
class domain;
}

/// A type class is a desciption of an object type info which may or may not match an existing one
/// An object may belong to multiple type classes (or none)
class DYNAMIX_API type_class
{
public:
    typedef bool (*match_func)(const object_type_info&);
    type_class(match_func func, bool register_globally = false);
    ~type_class();

    // do not copy or move
    type_class(const type_class&) = delete;
    type_class& operator=(const type_class&) = delete;
    type_class(type_class&&) = delete;
    type_class& operator=(type_class&&) = delete;

    type_class_id id() const { return _id; }
    bool is_registered() const { return _id != INVALID_TYPE_CLASS_ID; }

    bool matches(const object_type_info& ti) const { return _match_func(ti); }

private:
    friend class internal::domain;
    type_class_id _id = INVALID_TYPE_CLASS_ID;
    match_func _match_func;
};

}

#define DYNAMIX_TYPE_CLASS(tc) struct tc { static const dynamix::type_class _dynamix_type_class; }

#define DYNAMIX_DEFINE_TYPE_CLASS(tc) \
    static bool _impl##tc(const dynamix::object_type_info&); \
    const dynamix::type_class tc::_dynamix_type_class(_impl##tc, true); \
    bool _impl##tc(const dynamix::object_type_info& type)
