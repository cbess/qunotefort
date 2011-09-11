/***************************************************************************
 *   Copyright (C) 1-5-2006 by Quantum Quinn   *
 *   development@localhost.localdomain   *
 */
#include "ListBoxItem.h"

#include <qstring.h>
#include <qwidget.h>
#include <qpainter.h>

int ListBoxItem::_id = 0;

ListBoxItem::ListBoxItem( QString title, QString noteText )
: QListBoxText( title )
{
	++ListBoxItem::_id;

	this->noteText = noteText;
	this->title = title;
}

void ListBoxItem::NoteText( QString noteText )
{
	this->noteText = noteText;
}

QString ListBoxItem::NoteText( )
{
	//QString tmp( ->ascii() );
	return this->noteText;
}

void ListBoxItem::Title( QString title )
{
	this->title = title;
}

QString ListBoxItem::Title( )
{
	//QString tmp( ascii() );
	return this->title;
}

int ListBoxItem::ID()
{
	return this->_id;
}

void ListBoxItem::repaint( QPainter paint )
{
	this->paint( &paint );
}