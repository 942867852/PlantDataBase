#include <QCoreApplication>
#include <QDebug>
#include "cplant.h"
#include "cplantManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CPlantManager manager;

    CPlant rose("玫瑰", "美丽的开花植物");
    rose.addTag("A");
    rose.addTag("B");
    rose.addTag("C");
    rose.addTag("D");

    CPlant fern("蕨类", "喜欢阴湿环境");
    fern.addTag("B");
    fern.addTag("D");

    CPlant cactus("仙人掌", "沙漠植物");
    cactus.addTag("A");
    cactus.addTag("C");
    cactus.addTag("D");

    manager.addPlant(rose);
    manager.addPlant(fern);
    manager.addPlant(cactus);

    // 查找喜欢阳光的植物
    qDebug() << "D:";
    auto sunPlants = manager.findPlantsByTag("D");
    for (const auto& p : sunPlants) {
        qDebug() << "-" << p.getName();
    }

    // 查找同时耐阴且喜湿的植物
    QSet<QString> required = {"A", "B"};
    auto filtered = manager.findPlantsByTags(required, true);
    qDebug() << "A,B的植物:";
    for (const auto& p : filtered) {
        qDebug() << "-" << p.getName();
    }

    //使用第二种方式查找单一标签植物
    QSet<QString> required2 = {"A"};
    auto filtered2 = manager.findPlantsByTags(required2, true);
    qDebug() << "A的植物:";
    for (const auto& p : filtered2) {
        qDebug() << "-" << p.getName();
    }

    return a.exec();
}
