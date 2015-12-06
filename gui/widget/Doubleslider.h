#ifndef DOUBLESLIDER_H
#define DOUBLESLIDER_H

#include <QObject>
#include <QSlider>

class DoubleSlider : public QSlider
{
	Q_OBJECT

public:
	DoubleSlider(QWidget *parent = 0);

signals:
	void sigDoubleValueChanged(const double& value);

protected slots:
	void notifyValueChanged(const int& value);
};

#endif // DOUBLESLIDER_H
