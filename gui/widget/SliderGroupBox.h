#ifndef SLIDERGROUPBOX_H
#define SLIDERGROUPBOX_H

#include <QGroupBox>
#include <QGridLayout>
#include <QSlider>
#include <QLabel>

class SliderGroupBox : public QGroupBox
{
	Q_OBJECT

public:
    SliderGroupBox(QWidget *parent = 0, const int &min=0, const int &max=10, const int &val=0, const int &step=2);

    /*
     *  Getter and Setter
    */
    QSlider* getSlider() const;
    int getValue() const;
    int getMinValue() const;
    int getMaxValue() const;

    void setSlider(const int &min, const int &max, const int &val, const int &step=2);
    void setMinValue(const int &val);
    void setMaxValue(const int &val);
    void setValue(const int &val);


protected:
    QSlider* mSlider;
    QGridLayout* mGrid;
    QLabel* mLabelMinValue;
    QLabel* mLabelMaxValue;
    QLabel* mLabelValue;
};

#endif // SLIDERGROUPBOX_H
