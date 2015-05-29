#ifndef AZULRADIOBUTTONGROUPBOX_H
#define AZULRADIOBUTTONGROUPBOX_H

#include <QGroupBox>
#include <QGridLayout>
#include <QRadioButton>

class AzulRadioButtonGroupBox : public QGroupBox
{
public:
	AzulRadioButtonGroupBox(const int &numRadio);
	~AzulRadioButtonGroupBox();

public slots:
	void placeRadioButtons(const int &id, const int &row, const int &col);
	QString getText(const int &index);
	void setText(const int &index, const QString &text);

protected:
	QVector<QRadioButton*> mRadioButtons;
	QGridLayout *mGrid;

};

#endif // AZULRADIOBUTTONGROUPBOX_H
