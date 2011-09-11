/***************************************************************************
 *   Copyright (C) 1-5-2006 by Quantum Quinn   *
 *   development@localhost.localdomain   *
 */
#include "main.h"
#include "ListBoxItem.h"
#include <qmessagebox.h>
#include "TitleWin.h"
#include <qdatetime.h>
#include <qevent.h>
#include <qfile.h>
#include <qdatastream.h>
//#include "Thread.h"
#include <qstatusbar.h>

#define NOTE_FILE "noteFort.qu"
#define APP_TITLE "QuNoteFort"

Main::Main(QWidget *parent, const char *name)
    :MainWin(parent, name)
{
	lsNotes->clear();
	prevLbi = new ListBoxItem("","");
	delNote = false;

	this->setFixedSize( this->width(), this->height()+7 );

	connect( this->lsNotes, SIGNAL( onItem(QListBoxItem*) ), 
	this, SLOT( lsNotes_onItem(QListBoxItem*) ) );
	
	this->show();

	if ( QFile( NOTE_FILE ).exists() )
		this->loadNotes();
	
}

void Main::btNew_clicked()
{
	QString body = "";
	QString title = body = QDateTime::currentDateTime().toString();

	// ask for title
	lsNotes->insertItem( new ListBoxItem( 
	(new TitleWin())->ShowDia( title ), "-"+body+"-\n" ) );

}

void Main::lsNotes_selected( QListBoxItem* lbi )
{ // lsNotes -> double click	
	ListBoxItem * li = ((ListBoxItem*)lbi);

	li->Title( // below
	 	(new TitleWin())->ShowDia( // below
	 		((ListBoxItem*)lbi)->Title() ) );
	
}

void Main::lsNotes_highlighted(QListBoxItem* lbi)
{ // shows target note
	ListBoxItem *_lbi = ((ListBoxItem*)lbi);
	
	txtNote->setText( _lbi->NoteText() );
	prevLbi = _lbi;
	
	statusBar()->message( "Note: "+_lbi->Title() );
}

void Main::btSave_clicked()
{ // explicitly stores note in memory and data file
	SaveNote();
	saveNotes();
}

void Main::txtNote_textChanged()
{ }

void Main::lsNotes_onItem( QListBoxItem * )
{ // lsNote -> mouse enter lsNotes // 1 - 6 - 06
	SaveNote();
}

void Main::SaveNote()
{	
	prevLbi->NoteText( txtNote->text() );
}

void Main::closeEvent( QCloseEvent * e )
{
	this->saveNotes();
		
	if ( QMessageBox::question( this, APP_TITLE,
		"Exit "APP_TITLE"?",
		QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton )
	== QMessageBox::No
	) { this->setCaption(APP_TITLE); return; }

	e->accept();
}

void Main::saveNotes()
{ // 1-7-06
	statusBar()->message( "Saving Notes..." );

	int count = lsNotes->count();
	
	if ( count > 0 )
	{	
			QFile file( NOTE_FILE );
			file.open( IO_WriteOnly );
		
			QDataStream stream( &file ); // we will serialize the data into the file
	
		for ( int i = 0; i < count; ++i )
		{
			statusBar()->message( "Saving note "+ QString::number( i+1 ) +"..." );
	
			ListBoxItem *li = (ListBoxItem*)lsNotes->item( i );
		
			stream << li->Title();   // serialize a string
			stream << li->NoteText();
			
		} // end FOR
		
		stream.unsetDevice();
		file.close();
	} // end IF

	statusBar()->message( "Saved all notes.", 800 );
}

void Main::loadNotes()
{ // 1 - 7 - 06
	statusBar()->message( "Loading Notes..." );
	
	QFile file( NOTE_FILE );
	file.open( IO_ReadOnly );

	QDataStream stream( &file );  // read the data serialized from the file
	
	int count = 0;
	while ( !stream.atEnd() )
	{
		statusBar()->message( "Loading note "+ QString::number( (++count) ) +"..." );
		
		QString title = QString::null;
		QString text = QString::null;

		stream >> title >> text;
				
		lsNotes->insertItem( new ListBoxItem( title, text ) );
	} // end WHILE
		
	stream.unsetDevice();
	file.close();

	this->setCaption( APP_TITLE );

	statusBar()->message( "Loaded "+ QString::number(count) +" notes.", 2700 );
}

void Main::btDel_clicked()
{ // 1 - 7 - 06	
	lsNotes->clearSelection();
	delNote = true;
}

void Main::lsNotes_clicked( QListBoxItem * lbi )
{ // 1 -7 -06
	if ( delNote && QMessageBox::question( this, APP_TITLE,
	"Delete selected note? ["+ ((ListBoxItem*)lbi)->Title() +"]",
	QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton )
	== QMessageBox::Yes 	
	) lsNotes->removeItem( lsNotes->index(lbi) );
	
	delNote = false;
}