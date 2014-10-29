/***************************************************************************
 *   Copyright (C) 2014 by Peter Komar                                     *
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

#include "responsewidget.h"
#include "qjsonview.h"

#include <QTextEdit>

ResponseWidget::ResponseWidget(QWidget *parent) :
    QStackedWidget(parent)
{
    m_textView = new QTextEdit;
    m_textView->setAcceptRichText(false);
    m_textView->setReadOnly(true);
    addWidget(m_textView);

    m_jsonView = new QJsonView;
    addWidget(m_jsonView);

    setCurrentIndex(0);
}

void ResponseWidget::setText(const QString& text)
{   
    m_textView->setText(text);
}

void ResponseWidget::append(const QString& text)
{
    m_textView->append(text);
}

ResponseWidget::type ResponseWidget::render(type typeResponse)
{
    type index = TYPE_TEXT;
    try{

        switch( typeResponse ) {

            case TYPE_JSON : m_jsonView->setJson(toText());
                             index = TYPE_JSON;
                             break;

            case TYPE_TEXT: index = TYPE_TEXT;
                            break;

        }

    } catch( ... ) {
        index = TYPE_TEXT;
    }

    setCurrentIndex(index);

    return index;
}

QString ResponseWidget::toText()
{
    return m_textView->toPlainText();
}

void ResponseWidget::clear()
{
    m_textView->clear();
    m_jsonView->clear();
}

