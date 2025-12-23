#include "cplantManager.h"


CPlantManager::CPlantManager(QObject *parent)
    : QObject(parent)
{
}

void CPlantManager::addPlant(const CPlant& plant) {
    // 可选：检查是否已存在同名植物
    for (const auto& p : m_plants) {
        if (p.getName() == plant.getName()) {
            return; // 或抛出警告
        }
    }
    m_plants.append(plant);
    //emit plantsChanged(); // 如果你用了信号机制
}

void CPlantManager::removePlant(const QString& name) {
    m_plants.erase(
        std::remove_if(m_plants.begin(), m_plants.end(),
                       [&name](const CPlant& p) { return p.getName() == name; }),
        m_plants.end()
        );
}

void CPlantManager::updatePlant(const CPlant& plant) {
    for (auto& p : m_plants) {
        if (p.getName() == plant.getName()) {
            p = plant;
            return;
        }
    }
    // 如果没找到，就添加
    addPlant(plant);
}

QList<CPlant> CPlantManager::findPlantsByTag(const QString& tag) const {
    QList<CPlant> result;
    for (const auto& plant : m_plants) {
        if (plant.hasTag(tag))
            result.append(plant);
    }
    return result;
}

// 查找匹配一组标签的植物
QList<CPlant> CPlantManager::findPlantsByTags(const QSet<QString>& tags, bool matchAll) const
{
    QList<CPlant> result;
    for (const auto& plant : m_plants) {
        const auto& plantTags = plant.getTags();

        bool match;
        if (matchAll) {
            // 检查是否 plantTags 包含了 tags 中的所有元素
            // 即：tags ⊆ plantTags
            match = (tags - plantTags).isEmpty();
        } else {
            // 至少有一个标签匹配
            match = !(tags & plantTags).isEmpty();  // 使用 & 求交集
        }

        if (match) {
            result.append(plant);
        }
    }
    return result;
}

QList<CPlant> CPlantManager::getAllPlants() const {
    return m_plants;
}

QSet<QString> CPlantManager::getAllTags() const {
    QSet<QString> allTags;
    for (const auto& plant : m_plants) {
        allTags.unite(plant.getTags());
    }
    return allTags;
}
