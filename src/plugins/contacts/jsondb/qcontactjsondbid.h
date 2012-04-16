/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt Pim Module
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

#ifndef QCONTACTJSONDBID_H
#define QCONTACTJSONDBID_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <qcontactengineid.h>
#include <qcontactid.h>
#include <qcontactabstractrequest.h>

#include <QtCore/qdebug.h>
#include <QtCore/quuid.h>

QTCONTACTS_BEGIN_NAMESPACE

class QContactJsonDbId : public QContactEngineId
{
public:
    explicit QContactJsonDbId(const QString &engineId);
    QContactJsonDbId(const QUuid &uuid, const QContactAbstractRequest::StorageLocation &storageLocation);
    QContactJsonDbId(const QContactJsonDbId &other);
    ~QContactJsonDbId();

    bool isEqualTo(const QContactEngineId *other) const;
    bool isLessThan(const QContactEngineId *other) const;

    QString managerUri() const;

    QContactEngineId *clone() const;

    QString toString() const;

#ifndef QT_NO_DEBUG_STREAM
    QDebug &debugStreamOut(QDebug &dbg) const;
#endif

    uint hash() const;

    QUuid uuid() const;
    QContactAbstractRequest::StorageLocation storageLocation() const;

private:
    QUuid m_uuid;
    QContactAbstractRequest::StorageLocation m_storageLocation;
};

QTCONTACTS_END_NAMESPACE

#endif
