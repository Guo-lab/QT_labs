#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

#include <QColorDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // textEdit Centered
    this->setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}





// New: Clear what is on the current screen and create a new page
void MainWindow::on_actionNew_triggered()
{
    file_path_="";
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name_ = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(file_name_);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "..", "file not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path_);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "..", "file not saved");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_name_ = QFileDialog::getSaveFileName(this, "Save the file");
    QFile file(file_name_);
    file_path_ = file_name_;
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "..", "file not saved");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}













void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}













void MainWindow::on_actionFind_help_triggered()
{
    QString about_text;

    about_text = "Notepad Help: \n";
    about_text += "\nNew:         Create a new file.\n";
    about_text += "Open:        Open another file.\n";
    about_text += "Save:        Save this file. (After \"Save as\")\n";
    about_text += "Save as:     Save the file as another file.\n";
    about_text += "Copy:        Copy the selected content.\n";
    about_text += "Paste:       Paste the content.\n";
    about_text += "Cut:         Cut the selected content.\n";
    about_text += "Redo:        Redo the last step.\n";
    about_text += "Undo:        Undo the last step.\n";
    about_text += "Color:       Change the color of the selected.\n";
    about_text += "Font:        Change the font of the selected.\n";
    about_text += "Find help:   Find some details.\n";

    about_text += "\n===================================\n";
    about_text += "                                                    Author ---- gsq    \n";
    about_text += "                                                    Date   ---- 22-05-15    \n";
    about_text += "                                  (C) Notepad Version 1.0 (R)      \n";
    about_text += "===================================\n";

    QMessageBox::about(this, "About Notepad", about_text);
}








// Form
void MainWindow::on_actionColor_triggered()
{
    QColor currentColor = QColorDialog::getColor(Qt::black, this);
    if(currentColor.isValid()) {
        ui->textEdit->setTextColor(currentColor);
    }
}


void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont currentFont = QFontDialog::getFont(&ok);
    if(ok) {
        ui->textEdit->setFont(currentFont);
    }
}
