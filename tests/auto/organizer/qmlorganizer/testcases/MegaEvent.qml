/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtPim Addon Module.
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

import QtOrganizer 5.0

Event {

    startDateTime: new Date("2012-01-01 12:00:00 GMT+0000")
    endDateTime: new Date("2012-01-01 13:00:00 GMT+0000")
    allDay: false

    Comment {
        comment: "Comment"
    }

    Description {
        description: "Description"
    }

    DisplayLabel {
        label: "Display label"
    }

    Location {
        latitude: 1.1
        longitude: 1.2
        label: "Location"
    }

    Priority {
        priority: Priority.Lowest
    }

    Tag {
        tag: "Tag"
    }

    Timestamp {
        created: new Date("2012-01-01 12:00:00 GMT+0000")
        lastModified: new Date("2012-01-01 12:00:00 GMT+0000")
    }

    Reminder {
        repetitionCount: 1
        repetitionDelay: 1
        secondsBeforeStart: 0
    }

    AudibleReminder {
        repetitionCount: 1
        repetitionDelay: 1
        secondsBeforeStart: 0
        dataUrl: "Audible reminder data url"
    }

    EmailReminder {
        repetitionCount: 1
        repetitionDelay: 1
        secondsBeforeStart: 0
        body: "Email reminder body"
        subject: "Email reminder subject"
        recipients: ["Recipient 1", "Recipient 2"]
        attachments: ["Attachment 1", "Attachment 2"]
    }

    VisualReminder {
        repetitionCount: 1
        repetitionDelay: 1
        secondsBeforeStart: 0
        message: "Visual reminder message"
        dataUrl: "Visual reminder data url"
    }

    ExtendedDetail {
        name: "extended detail"
        data: "extended detail data"
    }

    EventAttendee {
        name: "Event attendee"
        emailAddress: "new.attendee@qt.com"
        attendeeId: "123444455555"
        participationStatus: EventAttendee.StatusAccepted
        participationRole: EventAttendee.RoleRequiredParticipant
    }

    EventRsvp {
        organizerName: "Organizer name"
        organizerEmail: "Organizer email"
        responseDate: new Date("2012-01-01 12:00:00 GMT+0000")
        responseDeadline: new Date("2012-01-01 12:00:00 GMT+0000")
        participationStatus: EventAttendee.StatusAccepted
        participationRole: EventAttendee.RoleOrganizer
        responseRequirement: EventRsvp.ResponseRequired
    }

    Classification {
        classification: Classification.AccessConfidential
    }

    Version {
        version: 1
        extendedVersion: "1234"
    }

}
