#include "azulradiobuttongroupbox.h"

AzulRadioButtonGroupBox::AzulRadioButtonGroupBox( const int &numRadio=2 )
{
	setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
	mGrid = new QGridLayout;

	for( int i=0; i<numRadio; i++ )
	{
		QString str = QString("Radio button %1").arg(i+1);
		mRadioButtons.push_back( new QRadioButton( str ) );
		//mGrid->addWidget( mRadioButtons.at(i), 0, i );
	}

	mRadioButtons.at(0)->setChecked(true);
	setLayout(mGrid);
}

AzulRadioButtonGroupBox::~AzulRadioButtonGroupBox()
{

}

void AzulRadioButtonGroupBox::placeRadioButtons( const int &index, const int& row, const int &col )
{
	if( mRadioButtons.size() <= index )
	{
		qWarning( "Warning, placeRadioButtons index exceed size of vector");
		return;
	}

	mGrid->addWidget( mRadioButtons.at(index), row, col );
}

QString AzulRadioButtonGroupBox::getText( const int &index )
{
	if( mRadioButtons.size() <= index )
	{
		qWarning( "Warning, getText index exceed size of vector");
		return "Error";
	}

	return mRadioButtons.at(index)->text();
}

void AzulRadioButtonGroupBox::setText( const int &index, const QString &text )
{
	if( mRadioButtons.size() <= index )
	{
		qWarning( "Warning, setText index exceed size of vector");
		return;
	}

	mRadioButtons.at(index)->setText( text );
}
