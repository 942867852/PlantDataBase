#ifndef CPLANTMANAGER_H
#define CPLANTMANAGER_H

#include <QObject>
#include <QList>
#include <QSet>
#include "cplant.h"

class CPlantManager : public QObject
{
    Q_OBJECT

public:
    explicit CPlantManager(QObject *parent = nullptr);

    void addPlant(const CPlant& plant);
    void removePlant(const QString& name);
    void updatePlant(const CPlant& plant); // 更新已有植物

    // 查找功能
    QList<CPlant> findPlantsByTag(const QString& tag) const;
    QList<CPlant> findPlantsByTags(const QSet<QString>& tags, bool matchAll) const;
    QList<CPlant> getAllPlants() const;

    // 获取所有存在的标签（用于下拉菜单或筛选）
    QSet<QString> getAllTags() const;

private:
    QList<CPlant> m_plants;
};

#endif // PLANTMANAGER_H
