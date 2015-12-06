#include "DoubleSlider.h"

DoubleSlider::DoubleSlider(QWidget *parent) : QSlider(parent)
{
	connect(this, SIGNAL(valueChanged(int)),
			this, SLOT(notifyValueChanged(int)));
}

void DoubleSlider::notifyValueChanged(const int &value)
{
	double doubleValue = (double) value / 10.0;
	emit sigDoubleValueChanged(doubleValue);
}
