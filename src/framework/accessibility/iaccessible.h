/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef MU_ACCESSIBILITY_IACCESSIBLE_H
#define MU_ACCESSIBILITY_IACCESSIBLE_H

#include <QString>
#include <QRect>
#include "async/notification.h"

class QWindow;

namespace mu::accessibility {
class IAccessible
{
public:

    //! NOTE Must be sync with QAccessible::Role values
    enum Role {
        NoRole         = 0x00000000,
        Application    = 0x0000000E,
        Grouping       = 0x00000014,
        Pane           = 0x00000010,
        StaticText     = 0x00000029,
        EditableText   = 0x0000002A,  // Editable, selectable, etc.
        Button         = 0x0000002B,
        CheckBox       = 0x0000002C,
        RadioButton    = 0x0000002D,
        ComboBox       = 0x0000002E,
        ListItem       = 0x00000022,
    };

    enum class State {
        Undefined = 0,
        Enabled,
        Active,
        Focused,
        Selected
    };

    virtual const IAccessible* accessibleParent() const = 0;
    virtual async::Notification accessibleParentChanged() const = 0;
    virtual size_t accessibleChildCount() const = 0;
    virtual const IAccessible* accessibleChild(size_t i) const = 0;

    virtual Role accessibleRole() const = 0;
    virtual QString accessibleName() const = 0;
    virtual bool accessibleState(State st) const = 0;
    virtual QRect accessibleRect() const = 0;
    virtual QWindow* accessibleWindow() const = 0;
};
}

#endif // MU_ACCESSIBILITY_IACCESSIBLE_H
