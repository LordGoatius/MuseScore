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
#ifndef MU_UI_MENUITEM_H
#define MU_UI_MENUITEM_H

#include <QObject>
#include <QString>

#include "../uitypes.h"

namespace mu::ui {
// This must be in sync with QAction::MenuRole
enum class MenuItemRole {
    NoRole = 0,
    TextHeuristicRole,
    ApplicationSpecificRole,
    AboutQtRole,
    AboutRole,
    PreferencesRole,
    QuitRole
};

class MenuItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id NOTIFY idChanged)

    Q_PROPERTY(QString code READ code_property NOTIFY actionChanged)
    Q_PROPERTY(QString shortcuts READ shortcutsTitle NOTIFY actionChanged)
    Q_PROPERTY(QString portableShortcuts READ portableShortcuts NOTIFY actionChanged)

    Q_PROPERTY(QString title READ title_property NOTIFY actionChanged)
    Q_PROPERTY(QString description READ description_property NOTIFY actionChanged)
    Q_PROPERTY(QString section READ section NOTIFY sectionChanged)

    Q_PROPERTY(int icon READ icon_property NOTIFY actionChanged)

    Q_PROPERTY(bool enabled READ enabled_property NOTIFY stateChanged)

    Q_PROPERTY(bool checkable READ checkable_property NOTIFY actionChanged)
    Q_PROPERTY(bool checked READ checked_property NOTIFY stateChanged)

    Q_PROPERTY(bool selectable READ selectable_property NOTIFY selectableChanged)
    Q_PROPERTY(bool selected READ selected_property NOTIFY selectedChanged)

    Q_PROPERTY(int role READ role_property NOTIFY roleChanged)

    Q_PROPERTY(QList<MenuItem*> subitems READ subitems NOTIFY subitemsChanged)

public:
    MenuItem() = default;
    MenuItem(const UiAction& a);

    QString id() const;
    QString section() const;

    bool selectable() const;
    bool selected() const;

    MenuItemRole role() const;

    QList<MenuItem*> subitems() const;

    UiAction action() const;
    UiActionState state() const;
    actions::ActionData args() const;

    bool isValid() const;

    QString shortcutsTitle() const;
    QString portableShortcuts() const;

public slots:
    void setId(const QString& id);
    void setSection(const QString& section);
    void setState(const mu::ui::UiActionState& state);
    void setSelectable(bool selectable);
    void setSelected(bool selected);
    void setRole(mu::ui::MenuItemRole role);
    void setSubitems(const QList<mu::ui::MenuItem*>& subitems);
    void setAction(const mu::ui::UiAction& action);
    void setArgs(const actions::ActionData& args);

signals:
    void idChanged(QString id);

    void sectionChanged(QString section);
    void stateChanged();
    void selectableChanged(bool selectable);
    void selectedChanged(bool selected);
    void roleChanged(int role);
    void subitemsChanged(QList<mu::ui::MenuItem*> subitems);
    void actionChanged();

private:
    QString code_property() const;

    QString title_property() const;
    QString description_property() const;

    int icon_property() const;

    bool enabled_property() const;

    bool checkable_property() const;
    bool checked_property() const;

    bool selectable_property() const;
    bool selected_property() const;

    int role_property() const;

    QString m_id;
    QString m_section;
    UiActionState m_state;
    bool m_selectable = false;
    bool m_selected = false;
    MenuItemRole m_role = MenuItemRole::NoRole;
    actions::ActionData m_args;
    QList<MenuItem*> m_subitems;

    UiAction m_action;
};
using MenuItemList = QList<MenuItem*>;
}

#endif // MU_UI_MENUITEM_H
