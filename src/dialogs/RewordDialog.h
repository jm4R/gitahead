//
//          Copyright (c) 2019, Scientific Toolworks, Inc.
//
// This software is licensed under the MIT License. The LICENSE.md file
// describes the conditions under which this software may be distributed.
//
// Author: Mariusz Jaskolka
//

#ifndef REWORDDIALOG_H
#define REWORDDIALOG_H

#include <QDialog>

class QCheckBox;
class QLineEdit;
class QTextEdit;

namespace git {
class Repository;
}

class RewordDialog : public QDialog
{
	Q_OBJECT

public:
	RewordDialog(
					const git::Repository &repo,
					const QString &currentMessage,
					QWidget *parent = nullptr);

	QString name() const;

private:
	QLineEdit *mNameField;
};

#endif
