//
//          Copyright (c) 2019
//
// This software is licensed under the MIT License. The LICENSE.md file
// describes the conditions under which this software may be distributed.
//
// Author: Mariusz Jaskolka
//

#ifndef DIFFLISTWIDGET_H
#define DIFFLISTWIDGET_H

#include "DetailView.h"

class FileList;
class BlameEditor;
class QModelIndex;

namespace git
{
class Diff;
class Repository;
} // namespace git

class DiffListWidget : public ContentWidget
{
	Q_OBJECT

public:
	DiffListWidget(const git::Repository &repo, QWidget *parent = nullptr);

	QString selectedFile() const override;

	void setDiff(const git::Diff &diff, const QString &file = QString(),
							 const QString &pathspec = QString()) override;

private:
	FileList *mFiles;
	BlameEditor *mEditor;

	git::Diff mDiff;
};

#endif
