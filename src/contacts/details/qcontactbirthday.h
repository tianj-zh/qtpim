/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtContacts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QCONTACTBIRTHDAY_H
#define QCONTACTBIRTHDAY_H

#include <QString>

#include <qcontactsglobal.h>
#include <qcontactdetail.h>
#include <qcontact.h>

QTCONTACTS_BEGIN_NAMESPACE

/* Leaf class */
class Q_CONTACTS_EXPORT QContactBirthday : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactBirthday)
#else
    static const DetailType Type;
#endif

    enum BirthdayField {
        FieldBirthday = 0,
        FieldCalendarId
    };

    void setDate(const QDate& date) {setValue(FieldBirthday, date);}
    QDate date() const {return value<QDate>(FieldBirthday);}
    void setDateTime(const QDateTime& dateTime) {setValue(FieldBirthday, dateTime);}
    QDateTime dateTime() const {return value<QDateTime>(FieldBirthday);}
    void setCalendarId(const QString& calendarId) {setValue(FieldCalendarId, calendarId);}
    QString calendarId() const {return value(FieldCalendarId).toString();}
};

QTCONTACTS_END_NAMESPACE

#endif

