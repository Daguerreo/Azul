#ifndef MYGROUPBOX_H
#define MYGROUPBOX_H
#include <QGroupBox>
#include <QGridLayout>
#include <QRadioButton>

class RadioButtonGroupBox : public QGroupBox
{
	Q_OBJECT

public:
	RadioButtonGroupBox(QWidget *parent=0, const int &numRadio=2);
	~RadioButtonGroupBox();

	void placeRadioButtons(const int& id, const int& row, const int& col, const QString& text="");
	int checkedRadio();

	/*
	 * Getters and Setters
	*/
	QString getText(const int &index);
	void setText(const int &index, const QString &text);

	QRadioButton *getRadio(const int &index);

protected slots:
	void valueToggled(bool toggled);

signals:
	void sigRadioButtonChanged(const int& index);

protected:
	QVector<QRadioButton*> mRadioButtons;
	QGridLayout* mGrid;

};

#endif // MYGROUPBOX_H
