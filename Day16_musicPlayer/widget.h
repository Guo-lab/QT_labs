#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QStringList>
#include <QDir>
#include <QPushButton>
#include <QSlider>
#include <QListView>
#include <QStandardItemModel>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    bool isPlay = false;
    QString MusicPath = ":/mp3";

    QStringList fileList;            //路径链表
    QMediaPlaylist *PlayerList;      //播放列表
    QMediaPlayer *Player;            //播放音乐类
    QStandardItemModel *model;       //列表模型
    //QPushButton * selectBtn; //搜索按钮
    //QSlider *seekSlider;//音量控制进度条
    //QSlider *seekSlider1;//进度控制进度条
    //QPushButton *PlayorpauseMusic;//播放暂停按钮
    //QPushButton *NextMusic;//下一曲播放按钮
    //QPushButton *LastMusic;//上一曲
    //QListView *listView ;   //播放列表


private slots:
    void slider_vilume_changed();  //音量控制
    void  updatePosition(qint64 position);  //播放音乐更新滑块

    //void init();
    //void addItem(QString name);		//添加tableWidget
    //QStringList getFileNames(const QString &path);	//获取路径下所有需要的文件类型文件
    //void SlotShowCurrentMedia();
    //void SlotButtonStart();
    //void SlotButtonPrevious();
    //void SlotButtonNext();

    //void on_pushButton_clicked();
    //void  openFile();  //打开文件添加歌曲
    //void  openDir();  //打开目录添加歌曲
    //void  on_doubleClicked_list(QModelIndex index); //双击播放

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
