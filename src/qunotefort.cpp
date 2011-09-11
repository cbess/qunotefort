/***************************************************************************
 *   Copyright (C) 2006 by Quantum Quinn   *
 *   development@localhost.localdomain   *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <qapplication.h>

int main(int argc, char *argv[])
{
  printf("QuNoteFort executed...\n");
	
	QApplication app( argc, argv );

	Main *m = new Main();

	app.setMainWidget( m );

  return app.exec();
}
