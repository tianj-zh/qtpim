/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt Mobility Components.
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
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qcontactidfetchrequest.h"
#include "qcontactrequests_p.h"

QTCONTACTS_BEGIN_NAMESPACE

/*!
  \class QContactIdFetchRequest
  \brief The QContactIdFetchRequest class allows a client to asynchronously
    request a list of contact ids from a contacts store manager.


  For a QContactIdFetchRequest, the resultsAvailable() signal will be emitted when the resultant
  contact ids (which may be retrieved by calling ids()), are updated, as well as if
  the overall operation error (which may be retrieved by calling error()) is updated.

  Please see the class documentation of QContactAbstractRequest for more information about
  the usage of request classes and ownership semantics.


  \inmodule QtContacts

  \ingroup contacts-requests
 */

/*! Constructs a new contact id fetch request whose parent is the specified \a parent */
QContactIdFetchRequest::QContactIdFetchRequest(QObject* parent)
    : QContactAbstractRequest(new QContactIdFetchRequestPrivate, parent)
{
}

/*! Frees any memory used by this request */
QContactIdFetchRequest::~QContactIdFetchRequest()
{
    QContactAbstractRequestPrivate::notifyEngine(this);
}

/*! Sets the filter which will be used to select the contacts whose ids will be returned to \a filter
*/
void QContactIdFetchRequest::setFilter(const QContactFilter& filter)
{
    Q_D(QContactIdFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_filter = filter;
}

/*! Sets the future sort ordering of the result of the request to \a sorting.  This function only has
    effect on the result if called prior to calling \c start()
*/
void QContactIdFetchRequest::setSorting(const QList<QContactSortOrder>& sorting)
{
    Q_D(QContactIdFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_sorting = sorting;
}

/*! Returns the filter which will be used to select the contacts whose ids will be returned
*/
QContactFilter QContactIdFetchRequest::filter() const
{
    Q_D(const QContactIdFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_filter;
}

/*! Returns the sort ordering which will be used to sort the result
*/
QList<QContactSortOrder> QContactIdFetchRequest::sorting() const
{
    Q_D(const QContactIdFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_sorting;
}

/*! Returns the list of ids of contacts which matched the request
*/
QList<QContactId> QContactIdFetchRequest::ids() const
{
    Q_D(const QContactIdFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_ids;
}

#include "moc_qcontactidfetchrequest.cpp"

QTCONTACTS_END_NAMESPACE