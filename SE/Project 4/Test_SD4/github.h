#ifndef GITHUB_H
#define GITHUB_H

#include <QWidget>

namespace Ui {
class github;
}

class github : public QWidget
{
    Q_OBJECT

public:
    explicit github(QWidget *parent = 0);
    ~github();

private:
    Ui::github *ui;
};

#endif // GITHUB_H
