#include "GrayscaleFilterDialog.h"

GrayscaleFilterDialog::GrayscaleFilterDialog(QWidget* parent, Controller* controller) : BaseDialog(parent, controller)
{
	setWindowTitle(tr("Grayscale Filter Dialog"));
	connect( this,	SIGNAL( sigApplyClicked() ),
			 this,	SLOT( processImage()) );

	mAlgoRadio = new RadioButtonGroupBox(this, 5);
	mAlgoRadio->setTitle("Algorithm");
	mAlgoRadio->placeRadioButtons(0,0,0,"Average");
	mAlgoRadio->placeRadioButtons(1,1,0,"Luma");
	mAlgoRadio->placeRadioButtons(2,2,0,"Desaturation");
	mAlgoRadio->placeRadioButtons(3,0,1,"Min");
	mAlgoRadio->placeRadioButtons(4,1,1,"Max");

	connect( mAlgoRadio,	SIGNAL(sigRadioButtonChanged(int)),
			 this,			SLOT(enableSlider (int)));

	mGraySlider = new SliderGroupBox(this, 2, 256, 32);
	mGraySlider->setTitle("Gray Levels");

	setOptions();
}

GrayscaleFilterDialog::~GrayscaleFilterDialog()
{
	delete mAlgoRadio;
	delete mGraySlider;
}

void GrayscaleFilterDialog::setOptions()
{
	addComponent(mAlgoRadio);
	addComponent(mGraySlider);
	BaseDialog::setOptions();
}

void GrayscaleFilterDialog::processImage()
{
	switch( mAlgoRadio->checkedRadio() )
	{
	case 0: // Average
		mController->grayscaleAverage( mGraySlider->getValue() );
		break;

	case 1: // Luma
		mController->grayscaleLuma();
		break;

	case 2: // Desaturation
		mController->grayscaleDesaturation();
		break;

	case 3: // Min
		mController->grayscaleMin();
		break;

	case 4: // Max
		mController->grayscaleMax();
		break;

	default: // Averate
		mController->grayscaleAverage( mGraySlider->getValue() );
		break;
	}

	QImage image = mController->requestWCQImage();
	displayImage( image );
}

void GrayscaleFilterDialog::enableSlider( int index )
{

	if( index != 0)
		mGraySlider->setEnabled( false );
	else
		mGraySlider->setEnabled( true );
}
