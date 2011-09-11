/****************************************************************************
** Form implementation generated from reading ui file 'MainWin.ui'
**
** Created: Sat Jan 7 02:03:59 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "MainWin.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlistbox.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qtoolbar.h>
#include "MainWin.ui.h"

/*
 *  Constructs a MainWin as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
MainWin::MainWin( QWidget* parent, const char* name, WFlags fl )
    : QMainWindow( parent, name, fl )
{
    (void)statusBar();
    if ( !name )
	setName( "MainWin" );
    setCentralWidget( new QWidget( this, "qt_central_widget" ) );

    btHide = new QPushButton( centralWidget(), "btHide" );
    btHide->setEnabled( FALSE );
    btHide->setGeometry( QRect( 370, 310, 71, 21 ) );

    btNew = new QPushButton( centralWidget(), "btNew" );
    btNew->setGeometry( QRect( 20, 310, 61, 21 ) );
    btNew->setPaletteForegroundColor( QColor( 255, 255, 255 ) );
    btNew->setPaletteBackgroundColor( QColor( 0, 170, 0 ) );

    btDel = new QPushButton( centralWidget(), "btDel" );
    btDel->setGeometry( QRect( 90, 310, 60, 21 ) );
    btDel->setPaletteForegroundColor( QColor( 255, 255, 255 ) );
    btDel->setPaletteBackgroundColor( QColor( 170, 0, 0 ) );

    btSave = new QPushButton( centralWidget(), "btSave" );
    btSave->setGeometry( QRect( 250, 310, 103, 20 ) );
    btSave->setPaletteForegroundColor( QColor( 255, 255, 255 ) );
    btSave->setPaletteBackgroundColor( QColor( 0, 0, 127 ) );

    lsNotes = new QListBox( centralWidget(), "lsNotes" );
    lsNotes->setGeometry( QRect( 10, 20, 160, 280 ) );
    QFont lsNotes_font(  lsNotes->font() );
    lsNotes_font.setFamily( "Bitstream Vera Sans Mono" );
    lsNotes->setFont( lsNotes_font ); 

    txtNote = new QTextEdit( centralWidget(), "txtNote" );
    txtNote->setGeometry( QRect( 181, 20, 260, 280 ) );
    QFont txtNote_font(  txtNote->font() );
    txtNote_font.setFamily( "Luxi Sans" );
    txtNote->setFont( txtNote_font ); 
    txtNote->setAcceptDrops( TRUE );
    txtNote->setTabStopWidth( 18 );

    // toolbars

    languageChange();
    resize( QSize(450, 356).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( btNew, SIGNAL( clicked() ), this, SLOT( btNew_clicked() ) );
    connect( lsNotes, SIGNAL( selected(QListBoxItem*) ), this, SLOT( lsNotes_selected(QListBoxItem*) ) );
    connect( lsNotes, SIGNAL( highlighted(QListBoxItem*) ), this, SLOT( lsNotes_highlighted(QListBoxItem*) ) );
    connect( btSave, SIGNAL( clicked() ), this, SLOT( btSave_clicked() ) );
    connect( txtNote, SIGNAL( textChanged() ), this, SLOT( txtNote_textChanged() ) );
    connect( lsNotes, SIGNAL( onItem(QListBoxItem*) ), this, SLOT( lsNotes_onItem(QListBoxItem*) ) );
    connect( btDel, SIGNAL( clicked() ), this, SLOT( btDel_clicked() ) );
    connect( lsNotes, SIGNAL( clicked(QListBoxItem*) ), this, SLOT( lsNotes_clicked(QListBoxItem*) ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MainWin::~MainWin()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MainWin::languageChange()
{
    setCaption( tr( "QuNoteFort" ) );
    btHide->setText( tr( "Hide" ) );
    btHide->setAccel( QKeySequence( QString::null ) );
    QToolTip::add( btHide, tr( "Hide window." ) );
    btNew->setText( tr( "&New" ) );
    btNew->setAccel( QKeySequence( tr( "Alt+N" ) ) );
    QToolTip::add( btNew, tr( "Create new note." ) );
    btDel->setText( tr( "De&lete" ) );
    btDel->setAccel( QKeySequence( tr( "Alt+L" ) ) );
    QToolTip::add( btDel, tr( "Delete selected note." ) );
    btSave->setText( tr( "S&ave" ) );
    btSave->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    lsNotes->clear();
    lsNotes->insertItem( tr( "New Item" ) );
}

