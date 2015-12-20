#ifndef ENTRYGROUPBOX_H
#define ENTRYGROUPBOX_H
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

class EntryGroupBox : public QGroupBox
{
	Q_OBJECT
public:
	EntryGroupBox(QWidget *parent=0, const int &numEntry=1);
	~EntryGroupBox();

	void placeEntry(const int &index, const int &row, const int &col, const QString &text, const int &value);
	void placeEntry(const int &index, const int &row, const int &col);
	void placeSpacer(QSpacerItem *spacer, const int &row, const int &col);
	void setEntryEnabled(const int &index, const bool &enabled);

	/*
	 * Getters and Setters
	 */
	int getValue(const int &index);
	void setValue(const int &index, QString text);

private:
	QVector<QLabel*> mLabelEntries;
	QVector<QLineEdit*> mLineEditEntries;
	QGridLayout* mGrid;
};

#endif // ENTRYGROUPBOX_H
