//
//          Copyright (c) 2016, Scientific Toolworks, Inc.
//
// This software is licensed under the MIT License. The LICENSE.md file
// describes the conditions under which this software may be distributed.
//
// Author: Jason Haslam
//

#include "RewordDialog.h"
#include "git/Repository.h"
#include "git/TagRef.h"
#include "ui/ExpandButton.h"
#include <QApplication>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

RewordDialog::RewordDialog(
				const git::Repository &repo,
				const QString &currentMessage,
				QWidget *parent)
		: QDialog(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);

	setWindowTitle(tr("Reword commit message"));
	QString text = tr("Enter new commit message:");
	QLabel *label = new QLabel(QString("<b>%1:</b>").arg(text), this);

	mNameField = new QLineEdit(currentMessage, this);

	QDialogButtonBox *buttons =
					new QDialogButtonBox(QDialogButtonBox::Cancel, this);
	connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
	connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);

	QPushButton *reword =
					buttons->addButton(tr("Reword"), QDialogButtonBox::AcceptRole);
	reword->setEnabled(false);

	auto updateButton = [this, repo, reword] {
		QString name = mNameField->text();
		reword->setEnabled(!mNameField->text().isEmpty());
	};

	connect(mNameField, &QLineEdit::textChanged,
		[this, repo, reword] {
			QString name = mNameField->text();
			reword->setEnabled(!mNameField->text().isEmpty());
		}
	);

	QFormLayout *layout = new QFormLayout(this);
	layout->addRow(label);
	layout->addRow(tr("Name"), mNameField);
	layout->addRow(buttons);
}

QString RewordDialog::name() const
{
	return mNameField->text();
}
