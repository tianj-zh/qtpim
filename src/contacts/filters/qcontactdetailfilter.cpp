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

#include "qcontactdetailfilter.h"
#include "qcontactdetailfilter_p.h"
#include "qcontactfilter_p.h"
#include "qcontactmanager.h"

QTCONTACTS_BEGIN_NAMESPACE

/*!
  \class QContactDetailFilter
  \brief The QContactDetailFilter class provides a filter based around a detail value criterion


  \inmodule QtContacts

  \ingroup contacts-filters

  It may be used to select contacts which contain a detail of a particular type with a particular value
 */

Q_IMPLEMENT_CONTACTFILTER_PRIVATE(QContactDetailFilter)

/*!
 * \fn QContactDetailFilter::QContactDetailFilter(const QContactFilter& other)
 * Constructs a copy of \a other if possible, otherwise constructs a new detail filter
 */

/*!
 * Constructs a new detail filter
 */
QContactDetailFilter::QContactDetailFilter()
    : QContactFilter(new QContactDetailFilterPrivate)
{
}

/*!
 * Sets the type of the detail type of which details will be matched to \a type, and the name of the field in
 * details of that type which will contain the value criterion to \a field.
 * If \a type is QContactDetail::TypeUndefined, the detail filter will match no contacts.  If \a field
 * is not specified, or equal to -1, the detail filter acts like a "detail exists" filter; if any
 * detail of the specified type is present in a contact, that contact will match the filter, regardless
 * of what values might be stored in that detail.
 * \sa detailType()
 */
void QContactDetailFilter::setDetailType(QContactDetail::DetailType type, int field)
{
    Q_D(QContactDetailFilter);
    d->m_type = type;
    d->m_fieldId = field;
}

/*!
 * Sets the value criterion of the filter to \a value.
 * Note that if the field name criterion (set via setDetailType())
 * of the filter is an empty string, this value will be ignored.
 * \sa value(), setDetailType()
 */
void QContactDetailFilter::setValue(const QVariant& value)
{
    Q_D(QContactDetailFilter);
    d->m_exactValue = value;
}

/*!
 * Sets the semantics of the value matching criterion to those defined in \a flags
 * \sa matchFlags()
 */
void QContactDetailFilter::setMatchFlags(QContactFilter::MatchFlags flags)
{
    Q_D(QContactDetailFilter);
    d->m_flags = flags;
}

/*!
 * Returns the semantics of the value matching criterion
 * \sa setMatchFlags()
 */
QContactFilter::MatchFlags QContactDetailFilter::matchFlags() const
{
    Q_D(const QContactDetailFilter);
    return d->m_flags;
}

/*!
 * Returns the type of the details which will be inspected for matching values
 * \sa setDetailType()
 */
QContactDetail::DetailType QContactDetailFilter::detailType() const
{
    Q_D(const QContactDetailFilter);
    return d->m_type;
}

/*!
 * Returns the detail field containing the value which will be matched against the value criterion
 * \sa setDetailType()
 */
int QContactDetailFilter::detailField() const
{
    Q_D(const QContactDetailFilter);
    return d->m_fieldId;
}

/*!
 * Returns the value criterion of the detail filter
 * \sa setValue()
 */
QVariant QContactDetailFilter::value() const
{
    Q_D(const QContactDetailFilter);
    return d->m_exactValue;
}

QTCONTACTS_END_NAMESPACE
