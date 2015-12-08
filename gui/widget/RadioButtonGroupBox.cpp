#include "RadioButtonGroupBox.h"

RadioButtonGroupBox::RadioButtonGroupBox(QWidget *parent, const int &numRadio ) : QGroupBox(parent)
{
	setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
	mGrid = new QGridLayout(this);

	for( int i=0; i<numRadio; i++ )
	{
		QString str = QString("Radio button %1").arg(i+1);
		mRadioButtons.push_back( new QRadioButton( str, this ) );
		mGrid->addWidget( mRadioButtons.at(i), i, 0 );
		connect( mRadioButtons.at(i),	SIGNAL( clicked(bool) ),
				 this,					SLOT( valueToggled(bool) ) );
	}

	mRadioButtons.at(0)->setChecked(true);
	setLayout(mGrid);

}

RadioButtonGroupBox::~RadioButtonGroupBox()
{
	delete mGrid;
	qDeleteAll(mRadioButtons);
}

void RadioButtonGroupBox::placeRadioButtons(const int &index, const int &row, const int& col, const QString& text)
{
	if( mRadioButtons.size() <= index )
	{
		qWarning("Warning, placeRadioButtons index exceed size of vector");
		return;
	}

	mGrid->addWidget( mRadioButtons.at(index), row, col );

	if( text != "")
		mRadioButtons.at(index)->setText( text );
}

int RadioButtonGroupBox::checkedRadio()
{
	for( int i=0; i<mRadioButtons.size(); i++ )
	{
		if( mRadioButtons.at(i)->isChecked() )
			return i;
	}
	return -1;
	qWarning("Warning, checkedRadio returned wrong value");
}

QString RadioButtonGroupBox::getText( const int &index )
{
	if( mRadioButtons.size() <= index )
	{
		qWarning("Warning, getText index exceed size of vector");
		return "Error";
	}

	return mRadioButtons.at(index)->text();
}

void RadioButtonGroupBox::setText( const int &index, const QString &text )
{
	if( mRadioButtons.size() <= index )
	{
		qWarning("Warning, setText index exceed size of vector");
		return;
	}

	mRadioButtons.at(index)->setText( text );
}

QRadioButton* RadioButtonGroupBox::getRadio(const int& index)
{
	return mRadioButtons.at(index);
}

void RadioButtonGroupBox::valueToggled( bool toggled )
{
	Q_UNUSED( toggled )

	for(int i=0; i<mRadioButtons.size(); i++)
	{
		if( mRadioButtons.at(i)->isChecked() )
			emit( sigRadioButtonChanged( i ) );
	}
}

