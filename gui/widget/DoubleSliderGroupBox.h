#ifndef DOUBLESLIDERGROUPBOX_H
#define DOUBLESLIDERGROUPBOX_H

#include <QGroupBox>
#include <QGridLayout>
#include <QSlider>
#include <QLabel>

#include "SliderGroupBox.h"
#include "DoubleSlider.h"

class DoubleSliderGroupBox : public QGroupBox
{
	Q_OBJECT

public:
	DoubleSliderGroupBox(QWidget *parent = 0, const double &min=0.0, const double &max=10.0, const double &val=0.0, const int &step=1);

	/*
	 *  Getter and Setter
	*/
	DoubleSlider *getSlider() const;
	double getValue() const;
	int getMinValue() const;
	int getMaxValue() const;

	void setSlider(const double &min, const double &max, const double &val, const int &step=1);
	void setValue(const int &val);
	void setMinValue(const int &val);
	void setMaxValue(const int &val);

public slots:
	void updateDoubleValue(const double& value);

protected:
	DoubleSlider* mSlider;
	QGridLayout* mGrid;
	QLabel* mLabelMinValue;
	QLabel* mLabelMaxValue;
	QLabel* mLabelValue;
	double mValue;
};

#endif // DOUBLESLIDERGROUPBOX_H
