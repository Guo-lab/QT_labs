#include "widget.h"
#include "ui_widget.h"

#include <QIcon>
#include <QPalette>
#include <QtWidgets>
#include <QString>
#include <QtWidgets>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QStandardItemModel>
#include <QString>
#include <QAction>
#include<QMenu>
#include <QString>
#include  <QModelIndex>
#include <QMessageBox>




// https://github.dev/zhibai123/music-player
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    fileList.clear();




    ui->PlayProgress->setToolTip("Playing Progress");
    ui->PlayProgress->setCursor(QCursor(Qt::PointingHandCursor));
    // Change the slider, in order to change the position
    connect(ui->PlayProgress, &QSlider::sliderMoved, this, [=](int position) {  //手动拖进度条
        qDebug() << "Change the Playing Progress to" << position;
        Player->setPosition(position *1000);  //设置播放进度
    });

    ui->Voice->setToolTip("Voice Control");
    ui->Voice->setCursor(QCursor(Qt::PointingHandCursor));
    //第一首歌曲音量
    ui->Voice->setValue(99);
    connect(ui->Voice, &QSlider::sliderPressed, this, &Widget::slider_vilume_changed);
    connect(ui->Voice, &QSlider::sliderMoved, this, &Widget::slider_vilume_changed);





    Player = new QMediaPlayer(this);
    // While changing the position, update it and reset the Player !
    connect(Player, &QMediaPlayer::positionChanged, this, &Widget::updatePosition);
    //Player->setMedia(QUrl("qrc:/mp3/Qian.mp3"));
    //Player->setMedia(QUrl("qrc:/mp3/Nancy.mp3"));
    
    PlayerList = new  QMediaPlaylist;  //播放列表
    PlayerList->setCurrentIndex(0);  //设置播放第几个
    PlayerList->setPlaybackMode(QMediaPlaylist::Random);  //设置播放类型
         PlayerList->addMedia(QUrl("qrc:/mp3/Qian.mp3"));
         PlayerList->addMedia(QUrl("qrc:/mp3/MessageSound.mp3"));
         PlayerList->addMedia(QUrl("qrc:/mp3/Nancy.mp3"));
         Player->setPlaylist(PlayerList);  //设置播放列表

    //Player->play();






    //上一曲按钮
    ui->last->setToolTip("Last Song");
    ui->last->setIcon(QIcon(":/icon/last.png"));
    ui->last->setFlat(true);  //窗口透明不显示边框
    connect(ui->last, &QPushButton::clicked, this, [=]() {
        PlayerList->previous();
    });
    //下一曲按钮
    ui->next->setToolTip("Next Song");
    ui->next->setIcon(QIcon(":/icon/next.png"));
    ui->next->setFlat(true);
    connect(ui->next, &QPushButton::clicked, this, [=]() {
        PlayerList->next();
    });

    //播放暂停按钮按钮
    isPlay = false;
    ui->goOrpause->setToolTip("Play/Stop");
    ui->goOrpause->setIcon(QIcon(":/icon/go.png"));
    ui->goOrpause->setFlat(true);
    connect(ui->goOrpause, &QPushButton::clicked, this, [=]() {
        isPlay = !isPlay;
        if(isPlay) {
            Player->play();
            ui->goOrpause->setIcon(QIcon(":/icon/pause.png"));
        } else {
            Player->pause();
            ui->goOrpause->setIcon(QIcon(":/icon/go.png"));
        }
    });



    ui->comboBox->clear();
    QStringList strlist;
    strlist << "Random" << "Sequential" << "Loop";
    ui->comboBox->addItems(strlist);











    //播放列表
    ui->Songs->setEditTriggers(QAbstractItemView::NoEditTriggers);  //控制不能输入
    ui->Songs->setContextMenuPolicy(Qt::CustomContextMenu);  //没有就右键点击事件不会产生

    ui->Songs->setSpacing(10);
    //ui->Songs->setViewMode(QListView::IconMode);
    ui->Songs->setDragEnabled(false);
    ui->Songs->setStyleSheet( "QListView::item{ height: 60px; }");


    model = new QStandardItemModel(this);
    // Without the above sentence
    //00:23:15: 程序异常结束。
    //00:23:15: The process was ended forcefully.
    QStringList strList;
    strList.append("QianQianQueGe.mp3");
    strList.append("Nancy Mulligan.mp3");
    strList.append("MessageSound.mp3");


    int nCount = strList.size();
    for(int i = 0; i < nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        QFont a;
        a.setFamily("Times New Roman");
        a.setPointSize(30);
        item->setFont(a);
        item->setIcon(QIcon(QPixmap(":/icon/RC.png").scaled(QSize(200,200))));


        model->appendRow(item);
    }

    ui->Songs->setModel(model);


}


// When it comes to the Voice Control : slider_vilume_changed()
void Widget::slider_vilume_changed() {
    qDebug() << "Change the Voice to " << ui->Voice->value();
    Player->setVolume(ui->Voice->value()*1.5);
}

// Update Player
void  Widget::updatePosition(qint64 position) {
    ui->PlayProgress->setMaximum(Player->duration()/1000);
    ui->PlayProgress->setValue(position/1000);
    //qDebug() << position;
}






Widget::~Widget()
{
    delete ui;
}
