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
#ifndef MU_INSPECTOR_PLAYBACKPROXYMODEL_H
#define MU_INSPECTOR_PLAYBACKPROXYMODEL_H

#include "models/abstractinspectorproxymodel.h"

namespace mu::inspector {
class PlaybackProxyModel : public AbstractInspectorProxyModel
{
    Q_OBJECT

    Q_PROPERTY(bool hasDynamicsSettings READ hasDynamicsSettings NOTIFY isEmptyChanged)
    Q_PROPERTY(bool hasGeneralSettings READ hasGeneralSettings NOTIFY isEmptyChanged)

public:
    explicit PlaybackProxyModel(QObject* parent, IElementRepositoryService* repository);

    bool hasGeneralSettings() const;
    bool hasDynamicsSettings() const;

private:
    bool isGropEmpty(const QList<InspectorModelType>& group) const;
};
}

#endif // MU_INSPECTOR_PLAYBACKPROXYMODEL_H
