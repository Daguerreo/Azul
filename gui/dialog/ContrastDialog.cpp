#include "ContrastDialog.h"

ContrastDialog::ContrastDialog(QWidget* parent, Mediator* mediator) : BaseDialog(parent, mediator)
{
	setWindowTitle(tr("Contrast/Brightness Regolation"));
	connect( this,	SIGNAL( sigApplyClicked() ),
			 this,	SLOT( processImage()) );

	mContrastSlider = new DoubleSliderGroupBox( this, 0.0, 3.0, 1.0 );
	mContrastSlider->setTitle("Contrast");

	mBrightnesSlider = new SliderGroupBox( this, 0, 100, 0 );
	mBrightnesSlider->setTitle("Brightness");

	setOptions();
}

ContrastDialog::~ContrastDialog()
{
	delete mContrastSlider;
	delete mBrightnesSlider;
}

void ContrastDialog::setOptions()
{
	addComponent(mContrastSlider);
	addComponent(mBrightnesSlider);
	BaseDialog::setOptions();
}

void ContrastDialog::processImage()
{
	double contrast = mContrastSlider->getValue();
	int brightness = mBrightnesSlider->getValue();

	mMediator->contrast( contrast, brightness );

	QImage image = mMediator->requestWCQImage();
	displayImage( image );
}
