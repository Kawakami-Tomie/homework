#ifndef CHENGXU_H
#define CHENGXU_H

#include <QDialog>

namespace Ui {
class chengxu;
}

class chengxu : public QDialog
{
    Q_OBJECT

public:
    explicit chengxu(QWidget *parent = nullptr);
    ~chengxu();

private slots:
    void on_radio_2_clicked();

    void on_radio_8_clicked();

private:
    Ui::chengxu *ui;
};

#endif // CHENGXU_H
