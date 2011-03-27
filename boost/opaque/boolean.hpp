//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Vicente J. Botet Escriba 2010.
// Distributed under the Boost
// Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or
// copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/opaque for documentation.
//
//////////////////////////////////////////////////////////////////////////////

/**
 * @File Defines an opaque boolean class.
 */

#ifndef BOOST_OPAQUE_BOOLEAN_HPP
#define BOOST_OPAQUE_BOOLEAN_HPP


namespace boost {
namespace opaque {

    class boolean {
        bool val_;
        typedef bool boolean::*unspecified_bool_type;
    public:
        explicit boolean(const bool b) : val_(b) {}

        operator unspecified_bool_type() const
        { return val_ ? &boolean::val_ : 0; }

        boolean operator!() const {
            return boolean(!val_);
        }

        boolean operator&&(boolean rhs) const {
            return boolean(val_&&rhs.val_);
        }

        boolean operator||(boolean rhs) const {
            return boolean(val_||rhs.val_);
        }
    };
    const boolean true_=boolean(true);
    const boolean false_=boolean(false);
}
}

#endif
