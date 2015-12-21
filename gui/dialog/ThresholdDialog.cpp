#include "ThresholdDialog.h"

ThresholdDialog::ThresholdDialog(QWidget *parent, Controller *controller) : BaseDialog(parent, controller)
{
	setWindowTitle(tr("Threshold Dialog"));
	connect( this,	SIGNAL( sigApplyClicked() ),
			 this,	SLOT( processImage()) );

	mTypeRadio = new RadioButtonGroupBox( this, 3 );
	mTypeRadio->setTitle("Threshold Type");
	mTypeRadio->placeRadioButtons( 0, 0, 0, "Global" );
	mTypeRadio->placeRadioButtons( 1, 1, 0, "Global Inverted" );
	mTypeRadio->placeRadioButtons( 2, 2, 0, "Otsu" );

	connect( mTypeRadio,	SIGNAL( sigRadioButtonChanged(int) ),
			 this,			SLOT( enableSlider(int) ) );

	mThresholdSlider = new SliderGroupBox( this, 1, 254, 128, 5 );
	mThresholdSlider->setTitle("Threshold Value");

	setOptions();
}

ThresholdDialog::~ThresholdDialog()
{
	delete mTypeRadio;
	delete mThresholdSlider;
}

void ThresholdDialog::setOptions()
{
	addComponent( mTypeRadio );
	addComponent( mThresholdSlider );
	BaseDialog::setOptions();
}

void ThresholdDialog::processImage()
{
	int value = mThresholdSlider->getValue();

	switch( mTypeRadio->checkedRadio() )
	{
		case 0: // Binary
		mController->threshold( value, 0 );
		break;

		case 1: // Binary Inverted
		mController->threshold( value, 1 );
		break;

		case 2: // Otsu
		mController->threshold( value, 8 );
		break;

		default: // Binary
		mController->threshold( value, 0);
		break;
	}

	QImage image = mController->requestWCQImage();
	displayImage( image );
}

void ThresholdDialog::enableSlider(int index)
{
	if( index == 2 )
		mThresholdSlider->setEnabled( false );
	else
		mThresholdSlider->setEnabled( true );
}
