#ifndef CHOOSECOLORDIALOG_H
#define CHOOSECOLORDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class ChooseColorDialog : public QDialog {
    Q_OBJECT

private:
        QLabel *playerLabel;
public:
    enum Color { BLACK, WHITE, YELLOW };

    ChooseColorDialog(QWidget *parent = nullptr) : QDialog(parent) {
        // 初始化布局和按钮
        QVBoxLayout *layout = new QVBoxLayout(this);
        playerLabel = new QLabel("请选择先手棋色", this);
 //       QPushButton *yellowButton = new QPushButton("黄棋", this);
        QPushButton *blackButton = new QPushButton("黑棋", this);
        QPushButton *whiteButton = new QPushButton("白棋", this);
        layout->addWidget(playerLabel);

        layout->addWidget(blackButton);
        layout->addWidget(whiteButton);
//      layout->addWidget(yellowButton);

        // connect(yellowButton, &QPushButton::clicked, this, [=]() {
        //     setResult(Color::YELLOW);
        //     accept();
        //});
        connect(blackButton, &QPushButton::clicked, this, [=]() {
            setResult(Color::BLACK);
            accept();
        });

        connect(whiteButton, &QPushButton::clicked, this, [=]() {
            setResult(Color::WHITE);
            accept();
        });
    }

    Color getChosenColor() const {
        return static_cast<Color>(result());
    }
};


#endif // CHOOSECOLORDIALOG_H
