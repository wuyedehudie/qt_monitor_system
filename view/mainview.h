#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>

namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = nullptr);
    ~MainView();
    void init();

private slots:
    void on_close_btn_clicked();

    void on_minimize_clicked();

private:
    Ui::MainView *ui;
};

#endif // MAINVIEW_H
