#include "DoubleSliderGroupBox.h"

DoubleSliderGroupBox::DoubleSliderGroupBox(QWidget *parent, const double &min, const double &max, const double &val, const int &step) : QGroupBox(parent)
{
	setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
	mGrid = new QGridLayout(this);
	mValue = val;

	mSlider = new DoubleSlider(this);
	mSlider->setOrientation(Qt::Horizontal);
	mSlider->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
	mGrid->addWidget( mSlider, 0, 1 );

	mLabelMinValue = new QLabel(this);
	mLabelMinValue->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed);
	mLabelMinValue->setAlignment(Qt::AlignRight);
	mGrid->addWidget( mLabelMinValue, 0, 0 );

	mLabelMaxValue = new QLabel(this);
	mLabelMaxValue->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed);
	mLabelMaxValue->setAlignment( Qt::AlignLeft);
	mGrid->addWidget( mLabelMaxValue, 0, 2 );

	mLabelValue = new QLabel(this);
	mLabelValue->setText(QString::number(val, 'f', 1));
	mLabelValue->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed);
	mLabelValue->setAlignment( Qt::AlignHCenter);
	mGrid->addWidget( mLabelValue, 1, 1 );

	setSlider(min,max,val,step);
	setLayout(mGrid);

	connect(mSlider, SIGNAL(sigDoubleValueChanged(double)),
			   this, SLOT(updateDoubleValue(double)));
}


void DoubleSliderGroupBox::setSlider(const double &min, const double &max, const double &val, const int &step)
{
	mSlider->setMinimum( (int)min*10 );
	mLabelMinValue->setText(QString::number(min, 'f', 1));

	mSlider->setMaximum( (int)max*10 );
	mLabelMaxValue->setText(QString::number(max, 'f', 1));

	mSlider->setValue( (int)val*10 );
	// signal alligns the label value

	mSlider->setSingleStep( step );
}

double DoubleSliderGroupBox::getValue() const
{
	return mValue;
}

int DoubleSliderGroupBox::getMinValue() const
{
	return mSlider->minimum();
}

int DoubleSliderGroupBox::getMaxValue() const
{
	return mSlider->maximum();
}

void DoubleSliderGroupBox::setMinValue(const int &val)
{
	mSlider->setMinimum( val );
	mLabelMinValue->setNum( val );
}

void DoubleSliderGroupBox::setMaxValue(const int &val)
{
	mSlider->setMaximum( val );
	mLabelMaxValue->setNum( val );
}

void DoubleSliderGroupBox::setValue(const int &val)
{
	mSlider->setValue( val );
}

void DoubleSliderGroupBox::updateDoubleValue(const double &value)
{
	mLabelValue->setText(QString::number(value, 'f', 1));
	mValue = value;
}

DoubleSlider *DoubleSliderGroupBox::getSlider() const
{
	return mSlider;
}

