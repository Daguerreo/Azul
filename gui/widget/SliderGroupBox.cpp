#include "SliderGroupBox.h"

SliderGroupBox::SliderGroupBox(QWidget* parent, const int& min, const int& max, const int& val, const int& step) : QGroupBox()
{
	Q_UNUSED( parent )
	setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
	mGrid = new QGridLayout;

	mSlider = new QSlider(Qt::Horizontal, this);
	mSlider->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
	mGrid->addWidget(mSlider, 0, 1);

	mLabelMinValue = new QLabel(this);
	mLabelMinValue->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	mLabelMinValue->setAlignment(Qt::AlignRight);
	mGrid->addWidget(mLabelMinValue, 0, 0);

	mLabelMaxValue = new QLabel(this);
	mLabelMaxValue->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	mLabelMaxValue->setAlignment( Qt::AlignLeft);
	mGrid->addWidget(mLabelMaxValue, 0, 2);

	mLabelValue = new QLabel(QString::number(val),this);
	mLabelValue->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	mLabelValue->setAlignment(Qt::AlignHCenter);
	mGrid->addWidget(mLabelValue, 1, 1);

	setSlider(min, max, val, step);
	setLayout(mGrid);

	connect( mSlider,	SIGNAL(valueChanged(int)),
			 mLabelValue,	SLOT(setNum(int)) );
}


void SliderGroupBox::setSlider( const int &min, const int &max, const int &val, const int &step)
{
	mSlider->setMinimum( min );
	mLabelMinValue->setNum( min );

	mSlider->setMaximum( max );
	mLabelMaxValue->setNum( max );

	mSlider->setValue( val );
	// signal alligns the label value

	mSlider->setSingleStep( step );
}

int SliderGroupBox::getValue() const
{
	return mSlider->value();
}

int SliderGroupBox::getMinValue() const
{
	return mSlider->minimum();
}

int SliderGroupBox::getMaxValue() const
{
	return mSlider->maximum();
}

void SliderGroupBox::setMinValue(const int &val)
{
	mSlider->setMinimum( val );
	mLabelMinValue->setNum( val );
}

void SliderGroupBox::setMaxValue(const int &val)
{
	mSlider->setMaximum( val );
	mLabelMaxValue->setNum( val );
}

void SliderGroupBox::setValue(const int &val)
{
	mSlider->setValue( val );
	// signal alligns the label value
}

QSlider *SliderGroupBox::getSlider() const
{
	return mSlider;
}
