/***************************************************************************
 *   Copyright (C) 2015 by peter komar                                     *
 *   udldevel@gmail.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef REQUESTDETAILSDLG_H
#define REQUESTDETAILSDLG_H

#include <QDialog>

class QPlainTextEdit;

class RequestDetailsDlg : public QDialog
{
    Q_OBJECT
public:
    explicit RequestDetailsDlg(QWidget *parent = 0);
    void setRequest(const QString& text);

signals:

public slots:
    void slotSendToBuffer();

private:
    QPlainTextEdit *m_view;
};

#endif // REQUESTDETAILSDLG_H
