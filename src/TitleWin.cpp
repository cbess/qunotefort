/****************************************************************************
** Form implementation generated from reading ui file 'TitleWin.ui'
**
** Created: Sat Jan 7 00:10:15 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "TitleWin.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "TitleWin.ui.h"

/*
 *  Constructs a TitleWin as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
TitleWin::TitleWin( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "TitleWin" );
    setSizeGripEnabled( FALSE );
    setModal( TRUE );

    QWidget* privateLayoutWidget = new QWidget( this, "Layout1" );
    privateLayoutWidget->setGeometry( QRect( 10, 50, 240, 33 ) );
    Layout1 = new QHBoxLayout( privateLayoutWidget, 0, 6, "Layout1"); 
    Horizontal_Spacing2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout1->addItem( Horizontal_Spacing2 );

    btOk = new QPushButton( privateLayoutWidget, "btOk" );
    btOk->setAutoDefault( TRUE );
    btOk->setDefault( TRUE );
    Layout1->addWidget( btOk );

    btCancel = new QPushButton( privateLayoutWidget, "btCancel" );
    btCancel->setAutoDefault( TRUE );
    Layout1->addWidget( btCancel );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setGeometry( QRect( 80, 0, 110, 20 ) );
    textLabel1->setAlignment( int( QLabel::AlignCenter ) );

    leTitle = new QLineEdit( this, "leTitle" );
    leTitle->setGeometry( QRect( 10, 20, 240, 23 ) );
    leTitle->setMaxLength( 24 );
    languageChange();
    resize( QSize(254, 91).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( btOk, SIGNAL( clicked() ), this, SLOT( btOk_clicked() ) );
    connect( btCancel, SIGNAL( clicked() ), this, SLOT( btCancel_clicked() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
TitleWin::~TitleWin()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void TitleWin::languageChange()
{
    setCaption( tr( "Title" ) );
    btOk->setText( tr( "&OK" ) );
    btOk->setAccel( QKeySequence( QString::null ) );
    btCancel->setText( tr( "&Cancel" ) );
    btCancel->setAccel( QKeySequence( QString::null ) );
    textLabel1->setText( tr( "Enter a note title." ) );
}

